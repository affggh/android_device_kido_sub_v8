#
# Copyright (C) 2022 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

ifneq ($(filter w701, $(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))

include $(CLEAR_VARS)

# Create a link for kernel headers
$(shell mkdir -p $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include; \
    ln -sf $(ANDROID_BUILD_TOP)/device/qihoo/w701/kernel-headers \
	    $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include)

# Create a link for the WCNSS config files
$(shell mkdir -p $(TARGET_OUT)/etc/firmware/wlan/prima; \
    ln -sf /data/misc/wifi/WCNSS_qcom_cfg.ini \
	    $(TARGET_OUT)/etc/firmware/wlan/prima/WCNSS_qcom_cfg.ini; \
	ln -sf /persist/WCNSS_qcom_wlan_nv.bin \
	    $(TARGET_OUT)/etc/firmware/wlan/prima/WCNSS_qcom_wlan_nv.bin; \
	ln -sf /persist/WCNSS_wlan_dictionary.dat \
	    $(TARGET_OUT)/etc/firmware/wlan/prima/WCNSS_wlan_dictionary.dat)

endif
