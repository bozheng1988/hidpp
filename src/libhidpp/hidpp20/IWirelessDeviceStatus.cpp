#include <hidpp20/IWirelessDeviceStatus.h>

#include <cassert>

using namespace HIDPP20;

IWirelessDeviceStatus::Status IWirelessDeviceStatus::statusBroadcastEvent (const HIDPP::Report &event)
{
	assert (event.function () == StatusBroadcast);
	Status status = {};
	auto params = event.parameterBegin();
	status.Reconnection = params[0];
	status.ReconfNeeded = params[1];
	status.PowerSwitch = params[2];
	return status;
}

IWirelessDeviceStatus::IWirelessDeviceStatus (Device *dev) :
	FeatureInterface (dev, ID, "WirelessDeviceStatus")
{
}
