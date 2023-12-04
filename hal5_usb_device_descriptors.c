/*
 * SPDX-FileCopyrightText: 2023 Mete Balci
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2023 Mete Balci
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdbool.h>
#include "hal5_usb.h"
static const hal5_usb_endpoint_descriptor_t hal5_usb_endpoint_descriptor_1 = 
{
    7, // bLength
    0x05, // bDescriptorType
    0x01, // bEndpointAddress
    0x00, // bmAttributes
    64, // wMaxPacketSize
};
static const hal5_usb_interface_descriptor_t hal5_usb_interface_descriptor_0 = 
{
    9, // bLength
    0x04, // bDescriptorType
    0, // bInterfaceNumber
    0, // bAlternateSetting
    1, // bNumEndpoints
    0xFF, // bInterfaceClass
    0xFF, // bInterfaceSubClass
    0xFF, // bInterfaceProtocol
    1, // iInterface
    {
        &hal5_usb_endpoint_descriptor_1, 
    },
};
static const hal5_usb_configuration_descriptor_t hal5_usb_configuration_descriptor_0 = 
{
    9, // bLength
    0x02, // bDescriptorType
    25, // wTotalLength
    1, // bNumInterfaces
    1, // bConfigurationValue
    2, // iConfiguration
    0xC0, // bmAttributes
    0x00, // bMaxPower
    {
        &hal5_usb_interface_descriptor_0, 
    },
};
static const hal5_usb_device_descriptor_t hal5_usb_device_descriptor_0 =
{
    18, // bLength
    0x01, // bDescriptorType
    0x0200, // bcdUSB
    0x00, // bDeviceClass
    0x00, // bDeviceSubClass
    0x00, // bDeviceProtocol
    64, // bMaxPacketSize0
    0x1209, // idVendor
    0x0001, // idProduct
    0x0100, // bcdDevice
    3, // iManufacturer
    4, // iProduct
    0, // iSerialNumber
    1, // bNumConfigurations
    {
        &hal5_usb_configuration_descriptor_0, 
    },
};
const hal5_usb_device_descriptor_t* const hal5_usb_device_descriptor = &hal5_usb_device_descriptor_0;
const bool hal5_usb_product_string_append_version = true;
static hal5_usb_string_descriptor_t hal5_usb_string_descriptor_0 = 
{
    4,
    0x03,
    // "LANGID en-US"
    {0x09, 0x04},
};
static hal5_usb_string_descriptor_t hal5_usb_string_descriptor_1 = 
{
    24,
    0x03,
    // "interface 0"
    {0x69, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x65, 0x00, 0x72, 0x00, 0x66, 0x00, 0x61, 0x00, 0x63, 0x00, 0x65, 0x00, 0x20, 0x00, 0x30, 0x00},
};
static hal5_usb_string_descriptor_t hal5_usb_string_descriptor_2 = 
{
    32,
    0x03,
    // "configuration 1"
    {0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x66, 0x00, 0x69, 0x00, 0x67, 0x00, 0x75, 0x00, 0x72, 0x00, 0x61, 0x00, 0x74, 0x00, 0x69, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x20, 0x00, 0x31, 0x00},
};
static hal5_usb_string_descriptor_t hal5_usb_string_descriptor_3 = 
{
    20,
    0x03,
    // "metebalci"
    {0x6D, 0x00, 0x65, 0x00, 0x74, 0x00, 0x65, 0x00, 0x62, 0x00, 0x61, 0x00, 0x6C, 0x00, 0x63, 0x00, 0x69, 0x00},
};
static hal5_usb_string_descriptor_t hal5_usb_string_descriptor_4 = 
{
    24,
    0x03,
    // "hal5       "
    {0x68, 0x00, 0x61, 0x00, 0x6C, 0x00, 0x35, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00},
};
const uint32_t hal5_usb_number_of_string_descriptors = 5;
const hal5_usb_string_descriptor_t* const hal5_usb_string_descriptors[] = 
{
    &hal5_usb_string_descriptor_0,
    &hal5_usb_string_descriptor_1,
    &hal5_usb_string_descriptor_2,
    &hal5_usb_string_descriptor_3,
    &hal5_usb_string_descriptor_4,
};
