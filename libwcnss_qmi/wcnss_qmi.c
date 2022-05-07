/*--------------------------------------------------------------------------
Copyright (c) 2013, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of The Linux Foundation nor
      the names of its contributors may be used to endorse or promote
      products derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
--------------------------------------------------------------------------*/

#define LOG_TAG "libwcnss_qmi"
#include <cutils/log.h>
#include <dlfcn.h>
#include <string.h>
#include "missing-qmi-client-api.h"

#define SUCCESS 0
#define FAILED -1

#define WLAN_ADDR_SIZE   6
#define DMS_QMI_TIMEOUT (2000)

static void *dms_qmi_client;
static int qmi_handle;
static int dms_init_done = FAILED;

void *libqcci_legacy_handle;
void *libqmiservices_handle;
void *libqmi_handle;

#define QCCI_LEGACY_LIB "libqcci_legacy.so"
#define QMISERVICES_LIB "libqmiservices.so"
#define QMI_LIB "libqmi.so"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))

int wcnss_init_qmi()
{
	void *dms_service;
	const char *qmi_modem_port;
	const char *tries[] = { QMI_PORT_RMNET_0, QMI_PORT_RMNET_1 };
	int rc = SUCCESS;
	size_t i;

	libqcci_legacy_handle = dlopen(QCCI_LEGACY_LIB, RTLD_NOW);
	if (!libqcci_legacy_handle) {
		ALOGE("%s: Failed to open %s: %s", __func__, QCCI_LEGACY_LIB, dlerror());
		return FAILED;
	}

	qmi_client_init = dlsym(libqcci_legacy_handle, "qmi_client_init");
	if (!qmi_client_init) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "qmi_client_init", dlerror());
		return FAILED;
	}

	qmi_client_send_msg_sync = dlsym(libqcci_legacy_handle, "qmi_client_send_msg_sync");
	if (!qmi_client_send_msg_sync) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "qmi_client_send_msg_sync", dlerror());
		return FAILED;
	}

	qmi_client_release = dlsym(libqcci_legacy_handle, "qmi_client_release");
	if (!qmi_client_release) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "qmi_client_release", dlerror());
		return FAILED;
	}

	libqmiservices_handle = dlopen(QMISERVICES_LIB, RTLD_NOW);
	if (!libqmiservices_handle) {
		ALOGE("%s: Failed to open %s: %s", __func__, QMISERVICES_LIB, dlerror());
		return FAILED;
	}

	dms_get_service_object_internal_v01 = dlsym(libqmiservices_handle, "dms_get_service_object_internal_v01");
	if (!dms_get_service_object_internal_v01) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "dms_get_service_object_internal_v01", dlerror());
		return FAILED;
	}

	libqmi_handle = dlopen(QMI_LIB, RTLD_NOW);
	if (!libqmi_handle) {
		ALOGE("%s: Failed to open %s: %s", __func__, QMI_LIB, dlerror());
		return FAILED;
	}

	qmi_init = dlsym(libqmi_handle, "qmi_init");
	if (!qmi_init) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "qmi_init", dlerror());
		return FAILED;
	}

	qmi_release = dlsym(libqmi_handle, "qmi_release");
	if (!qmi_release) {
		ALOGE("%s: Failed to resolve function: %s: %s", __func__, "qmi_release", dlerror());
		return FAILED;
	}

	ALOGE("%s: Initialize wcnss QMI Interface", __func__);

	/* Get a handle to the QMI services
	 */
	qmi_handle = qmi_init(NULL, NULL);
	if (qmi_handle < 0) {
		ALOGE("%s: Error while initializing qmi", __func__);
		return FAILED;
	}

	/* Get a handle to the Device Management Services.
	 * Some magic constants involved, don't ask.
	 */
	dms_service = dms_get_service_object_internal_v01(1, 55, 6);
	if (dms_service == NULL) {
		ALOGE("%s: Not able to get a handle to the device management service",
			  __func__);
		qmi_release(qmi_handle);
	}

	/* Get a handle to a QMI modem port (trying multiple ports)
	 */
	for (i = 0; i < ARRAY_SIZE(tries); i++) {
		qmi_modem_port = tries[i];

		rc = qmi_client_init(qmi_modem_port, dms_service,
			                 NULL, dms_service, &dms_qmi_client);
		if (rc == 0) {
			break;
		}
	}
	if (rc < 0) {
		ALOGE("%s: Error while Initializing QMI Client: %d",
			  __func__, rc);
		qmi_release(qmi_handle);
	}
	dms_init_done = SUCCESS;
	return SUCCESS;
}

static int retrieve_wlan_mac_from_qmi(unsigned char *mac_addr)
{
	struct dms_get_mac_address_req_msg_v01  addr_req;
	struct dms_get_mac_address_resp_msg_v01 addr_resp;
	int i = 0;
	int rc;

	/* Clear the request content */
	memset(&addr_req, 0, sizeof(addr_req));

	/* Request to get the WLAN MAC address */
	addr_req.device = DMS_DEVICE_MAC_WLAN_V01;

	rc = qmi_client_send_msg_sync(dms_qmi_client,
	                              QMI_DMS_GET_MAC_ADDRESS_REQ_V01,
	                              &addr_req,  sizeof(addr_req),
	                              &addr_resp, sizeof(addr_resp),
	                              DMS_QMI_TIMEOUT);
	if (rc) {
		ALOGE("%s: Failed to get response from modem (error %d)",
		      __func__, rc);
		return FAILED;
	}

	ALOGE("%s: Mac Address_valid: %d Mac Address Len: %d",
	      __func__, addr_resp.mac_address_valid,
	      addr_resp.mac_address_len);

	if (addr_resp.mac_address_valid == 0 ||
	   (addr_resp.mac_address_len != WLAN_ADDR_SIZE)) {
		ALOGE("%s: Failed to Read WLAN MAC Address", __func__);
		return FAILED;
	}
	/* MAC address comes byte-swapped from the QMI gods */
	for (i = 0; i < WLAN_ADDR_SIZE; i++) {
		mac_addr[WLAN_ADDR_SIZE - i - 1] = addr_resp.mac_address[i];
	}
	ALOGE("%s: Succesfully Read WLAN MAC Address", __func__);

	return SUCCESS;
}

int wcnss_qmi_get_wlan_address(unsigned char *mac_addr)
{
	int rc = FAILED;

	if (mac_addr == NULL) {
		ALOGE("%s: Will not write into a NULL pointer!", __func__);
		return FAILED;
	}
	if (dms_init_done == SUCCESS) {
		rc = retrieve_wlan_mac_from_qmi(mac_addr);
	}
	return rc;
}

void wcnss_qmi_deinit()
{
	int rc;

	ALOGI("%s: Deinitialize wcnss QMI interface", __func__);

	if (dms_init_done == FAILED) {
		ALOGE("%s: DMS Service was not Initialized", __func__);
		return;
	}

	rc = qmi_client_release(dms_qmi_client);
	if (rc) {
		ALOGE("%s: Error while releasing qmi_client: %d",
		      __func__, rc);
	}

	qmi_handle = qmi_release(qmi_handle);
	if (qmi_handle < 0) {
		ALOGE("%s: Error while releasing qmi %d",
		      __func__, qmi_handle);
	}
	dms_init_done = FAILED;
}
