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

$(call inherit-product, device/kido/sub_v8/full_sub_v8.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/cm/config/common_mini_phone.mk)

PRODUCT_NAME := lineage_sub_v8
BOARD_VENDOR := qcom

PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT="kido/sub_v8/sub_v8:7.1.1/V8XXCN00X1000DPX1812140/buildf12141528:user/test-keys" \
    PRIVATE_BUILD_DESC="sub_v8-user 7.1.1 V8XXCN00X1000DPX1812140 eng.buildf.20181214.152838 test-keys"

# Default open adb
PRODUCT_PROPERTY_OVERRIDES += \
    persist.sys.usb.config=mtp,adb \
    ro.adb.secure=0 \
    ro.secure=0 \
    ro.debuggable=1
