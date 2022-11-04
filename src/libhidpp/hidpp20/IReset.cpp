#include <hidpp20/IReset.h>

using namespace HIDPP20;

uint16_t IReset::getProfile()
{
	auto results = call(GetProfile);
	return (results[0] << 8) | results[1];
}

void IReset::reset (uint16_t profile)
{
	std::vector<uint8_t> params;

	params.push_back((uint8_t)(profile >> 8));
	params.push_back((uint8_t)(profile & 0xFF));

	call(Reset, params);
}

IReset::IReset (Device *dev) :
	FeatureInterface (dev, ID, "Reset")
{
}
