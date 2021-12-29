/*
 * Copyright 2021 Clément Vuchener
 * Created by Noah Nuebling
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string.h>
#include "../RawDevice.h"

extern "C" {
    #include <IOKit/IOKitLib.h>
    #include <IOKit/hid/IOHIDDevice.h>
    #include <CoreFoundation/CFNumber.h>
}

class Utility_macos {

public:
    static void stringToIOString(std::string string, io_string_t &ioString);
    static CFStringRef stringToCFString(std::string string);

    static long CFNumberToInt(CFNumberRef cfNumber);
    static std::string CFStringToString(CFStringRef cfString);
    static std::vector<uint8_t> CFDataToByteVector(CFDataRef cfData);

    static long IOHIDDeviceGetIntProperty(IOHIDDeviceRef device, CFStringRef key);
    static std::string IOHIDDeviceGetStringProperty(IOHIDDeviceRef device, CFStringRef key);
    static HID::ReportDescriptor IOHIDDeviceGetReportDescriptor(IOHIDDeviceRef device);

    static const char * IOHIDDeviceGetPath(IOHIDDeviceRef device);
    static void stopListeningToInputReports(IOHIDDeviceRef device, CFRunLoopRef &runLoop);

    static double timestamp();

    static const char * IOHIDDeviceGetUniqueIdentifier(IOHIDDeviceRef device);
    static const char * IOHIDDeviceGetDebugIdentifier(IOHIDDeviceRef device);
};