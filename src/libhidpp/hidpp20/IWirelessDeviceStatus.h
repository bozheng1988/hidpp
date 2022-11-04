#ifndef LIBHIDPP_HIDPP20_IWIRELESSDEVICESTATUS_H
#define LIBHIDPP_HIDPP20_IWIRELESSDEVICESTATUS_H

#include <hidpp20/FeatureInterface.h>

namespace HIDPP20
{

class IWirelessDeviceStatus : public FeatureInterface
{
public:
	static constexpr uint16_t ID = 0x1d4b;

	enum Event : uint8_t {
		StatusBroadcast = 0
	};

	struct Status {
		bool Reconnection;
		bool ReconfNeeded;
		bool PowerSwitch;
	};

	static Status statusBroadcastEvent (const HIDPP::Report &event);

	IWirelessDeviceStatus(Device* dev);
};

}

#endif
