/*
 * Copyright 2017 Clément Vuchener
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

#include "DeviceMonitor.h"

#include <misc/Log.h>

#include <string>

extern "C" {
// #include <IOKit/hidsystem/>
}

using namespace HID;

// Private

struct DeviceMonitor::PrivateImpl
{
};

// Constructor & Destructor

DeviceMonitor::DeviceMonitor ():
	_p (std::make_unique<PrivateImpl> ())
{
}

DeviceMonitor::~DeviceMonitor ()
{
}

// Interface

void DeviceMonitor::enumerate ()
{

}

void DeviceMonitor::run ()
{
}

void DeviceMonitor::stop ()
{
}
