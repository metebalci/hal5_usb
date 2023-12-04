
# HAL5 USB Support

*This is still a work-in-progress.*

USB Host mode is not supported.

USB Device mode is supported as follows.

# Descriptors

Descriptors are defined in python, in `descriptors.py` file. This is a human-friendly form, because:

- fields like `bLength` is calculated automatically
- bit fields like `self-powered` attribute is specified as a boolean value
- additional attributes like `append-version` can be given

Most of the fields have similar names to USB descriptor fields. For an example and documentation, check `descriptors.py` in the repository. Optional USB descriptors that depend on other fields (such as endpoint transfer type) are checked and expected to be explicitly provided or not provided, no defaults assumed to prevent errors.

String descriptors are automatically created if given in `descriptors.py`, they are not explicitly created. Only supported language is US English (0x0409), this is defined implicitly in HAL5. However, Unicode can be used in provided strings, they are encoded properly as UTF-16 in generated string descriptors.

During a build, `descriptor.py` is used by `create_descriptor.py` to generate a C source file (`hal5_usb_device_descriptors.c`) which is compiled together with the application. The descriptors are created and initialized in this C source file.

## Append Version to Product String

All fields in `descriptor.py` are used as it is except the product string value if it is not `None` and `append_version` is `True`. In this case, the return values of `hal5_usb_device_version_major_ex() and _minor_ex()` are used to create a product name like `<product>_vXX.YY`. XX and YY can be between 0 and 99, and they are shown as single digit (not 0 left-padded) if they are less than 10. I have seen this in a few devices that makes it possible to observe the firmware version without any extra tool since Device Manager in Windows, System Report in macOS, or `lsusb` in Linux shows the product string.

# Endpoint 0 / Default Control Pipe

Endpoint 0, thus default control pipe, is abstracted and implemented by `hal5_usb_device_ep0.c`. USB 2.0 FS device enumeration completes successfully.

## Default Control Pipe Status

All (standard) USB device requests (USB 2.0 9.4) are implemented.

No-data device requests:

- `Clear Feature`
- `Set Feature`
- `Set Address`
- `Set Configuration`
- `Set Interface`

are implemented with complete parameter and state checks according to USB 2.0 spec.

All features in USB 2.0 (`Endpoint Halt`, `Device Remote Wakeup`, `Test Mode`) is passed to the USB device implementation. Test mode is not implemented.

`Set Address` and `Set Configuration` correctly handles state changes to/from address and from/to configured depending on the current state, the value of device address and configuration value.

`Set Interface` is passed to the USB device implementation.

Control write request:

- `Set Descriptor` 

is optional and it is implemented as always returning a Request Error (STALL). Thus, it cannot be used by a USB Device.

Control read requests:

- `Get Status`
- `Get Descriptor`
- `Get Configuration`
- `Get Interface`
- `Synch Frame`

are implemented with complete parameter and state checks according to USB 2.0 spec.

# USB Compliance

The code with the example USB device implementation in the repository passes USB3CV Chapter 9 Tests - USB 2. The test is performed on Windows 11 with a Renesas UPD720201 XHCI controller ([Delock 89363](https://www.delock.com/produkt/89363/merkmale.html?setLanguage=en)).

# USB Transaction vs. Pipe

Since a SETUP transaction is always 3 packets (SETUP, DATA0, ACK) and DATA0 payload is always 8 bytes, SETUP transaction is always processed as it is by the default control endpoint / endpoint 0. Since this works outside of USB device implementation, it is not very important for the user.

OUT and IN transactions can be two (DATA0/1, ACK) or multiples of these two packages, until a DATA0/1 payload with less than max packet size arrives. In effect, the data that is sent or received is the combination of all the payloads. This combination is done automatically, so IN and OUT transactions are not sent to the device implementation as it is but as `_in_stage_completed` and `_out_stage_completed` callbacks. The device implementation can read the combined data from the endpoint structure easily.

This implementation might not be ideal for some cases.

# USB Device

A device implementation should only provide descriptors and implement a few functions given in `hal5_usb_device.h` with `_ex` suffix.

An example USB Device is given in `example_usb_device.c`.

# License

SPDX-FileCopyrightText: 2023 Mete Balci

SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
