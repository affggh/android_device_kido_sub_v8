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

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_n.mk)

# Device
$(call inherit-product, device/qihoo/w701/device.mk)

#
# This device goes by various names, but we are keeping consistent with build.prop
#

# Device identifiers
PRODUCT_CHARACTERISTICS := watch,nosdcard
PRODUCT_DEVICE := w701
PRODUCT_NAME := full_w701
PRODUCT_BRAND := qcom
PRODUCT_MODEL := w701
PRODUCT_MANUFACTURER := Qibao
