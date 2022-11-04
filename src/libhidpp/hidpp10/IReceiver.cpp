/*
 * Copyright 2015 Clément Vuchener
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

#include <hidpp10/IReceiver.h>

#include <hidpp/Dispatcher.h>

#include <hidpp10/defs.h>
#include <hidpp10/Device.h>

#include <misc/Endian.h>
#include <stdexcept>
#include <cassert>

using namespace HIDPP10;

const std::vector<uint8_t> IReceiver::Events
({
	IReceiver::DeviceUnpaired,
	IReceiver::DevicePaired,
	IReceiver::ConnectionStatus,
	IReceiver::Error
});

IReceiver::IReceiver (Device *dev):
	_dev (dev)
{
}

void IReceiver::getDeviceInformation (unsigned int device,
				      uint8_t *destination_id,
				      uint8_t *report_interval,
				      uint16_t *wpid,
				      DeviceType *type)
{
	if (device >= 16)
		throw std::out_of_range ("Device index too big");

	std::vector<uint8_t> params (HIDPP::ShortParamLength),
			     results (HIDPP::LongParamLength);

	params[0] = DeviceInformation | (device & 0x0F);

	_dev->getRegister (DevicePairingInfo, &params, results);

	if (params[0] != results[0])
		throw std::runtime_error ("Invalid DevicePairingInfo type");

	if (destination_id)
		*destination_id = results[1];
	if (report_interval)
		*report_interval = results[2];
	if (wpid)
		*wpid = readBE<uint16_t> (results, 3);
	if (type)
		*type = static_cast<DeviceType> (results[7]);
}

void IReceiver::getDeviceExtendedInformation (unsigned int device,
					      uint32_t *serial,
					      uint32_t *report_types,
					      PowerSwitchLocation *ps_loc)
{
	if (device >= 16)
		throw std::out_of_range ("Device index too big");

	std::vector<uint8_t> params (HIDPP::ShortParamLength),
			     results (HIDPP::LongParamLength);

	params[0] = ExtendedDeviceInformation | (device & 0x0F);

	_dev->getRegister (DevicePairingInfo, &params, results);

	if (params[0] != results[0])
		throw std::runtime_error ("Invalid DevicePairingInfo type");

	if (serial)
		*serial = readBE<uint32_t> (results, 1);
	if (report_types)
		*report_types = readBE<uint32_t> (results, 5);
	if (ps_loc)
		*ps_loc = static_cast<PowerSwitchLocation> (results[9] & 0x0F);
}

void IReceiver::getPairedDevices ()
{
	HIDPP::Report report (HIDPP::Report::ShortDJ, HIDPP::DefaultDevice, GetPairedDevices, 0);
	_dev->dispatcher()->sendCommandWithoutResponse(report);
}

std::string IReceiver::getDeviceName (unsigned int device)
{
	if (device >= 16)
		throw std::out_of_range ("Device index too big");

	std::vector<uint8_t> params (HIDPP::ShortParamLength),
			     results (HIDPP::LongParamLength);

	params[0] = DeviceName | (device & 0x0F);

	_dev->getRegister (DevicePairingInfo, &params, results);

	if (params[0] != results[0])
		throw std::runtime_error ("Invalid DevicePairingInfo type");

	std::size_t length = results[1];
	return std::string (reinterpret_cast<char *> (&results[2]), std::min (length, std::size_t {14}));
}

IReceiver::DevicePairedEvent IReceiver::devicePairedEvent (const HIDPP::Report &event)
{
	assert (event.featureIndex() == DevicePaired);
	DevicePairedEvent dpe {};

	auto params = event.parameterBegin();
	dpe.moreEvents = params[0] & 1;
	dpe.empty = params[0] & 2;
	dpe.pid = params[1] << 8 | params[2];

	uint32_t bitfield = params[3] << 24 | params[4] << 16 | params[5] << 8 | params[6];
	for(int i = 0; i < 32; i++)
		if(bitfield & (1 << i))
			dpe.reportBitfield.push_back(i);

	return dpe;
}

uint8_t IReceiver::connectionStatusEvent (const HIDPP::Report &event)
{
	assert (event.featureIndex() == ConnectionStatus);
	auto params = event.parameterBegin();
	return params[0];
}

uint8_t IReceiver::errorEvent (const HIDPP::Report &event)
{
	assert (event.featureIndex() == Error);
	auto params = event.parameterBegin();
	return params[0];
}
