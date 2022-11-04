#ifndef LIBHIDPP_HIDPP20_IRESET_H
#define LIBHIDPP_HIDPP20_IRESET_H

#include <hidpp20/FeatureInterface.h>

namespace HIDPP20
{

class IReset : public FeatureInterface
{
public:
	static constexpr uint16_t ID = 0x0020;

	enum Function : uint8_t {
		GetProfile = 0,
		Reset = 1
	};

	IReset(Device *dev);

	uint16_t getProfile();

	void reset(uint16_t profile = 0);
};

}

#endif
