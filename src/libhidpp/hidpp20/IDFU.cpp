/*
 * Copyright 2022 Bo Zheng
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

#include <hidpp20/IDFU.h>

#include <misc/Endian.h>

#include <cassert>

using namespace HIDPP20;

constexpr uint16_t IDFU::ID;

IDFU::IDFU (Device *dev):
	FeatureInterface (dev, ID, "DFU")
{
}

void IDFU::write (unsigned int index, std::vector<uint8_t>::const_iterator begin, std::vector<uint8_t>::const_iterator end)
{
	assert (std::distance (begin, end) <= LineSize);
	assert ( index >= 0 && index <= 4 );

	call (index, begin, end);
}
