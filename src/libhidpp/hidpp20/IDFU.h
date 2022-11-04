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

#ifndef LIBHIDPP_HIDPP20_IDFU_H
#define LIBHIDPP_HIDPP20_IDFU_H

#include <hidpp20/FeatureInterface.h>

#include <vector>
#include <array>

namespace HIDPP20
{

/**
 * Manage on-board profiles
 *
 * There is two type of memory. The ROM contains safe profiles that the mouse
 * can default to if there is no valid profiles. The Writeable memory is where
 * normal user profiles are written.
 *
 * When invalid profile data is found in Writeable memory. Data from ROM is used instead.
 *
 * Each memory is divided in sectors or pages. Thus, an Address is given by the
 * memory type, the page index and an offset counting bytes from the beginning
 * of the page.
 *
 * Memory reads and writes are done by lines of \ref LineSize bytes (16 bytes:
 * the size of a long HID++ payload).
 *
 * Writing memory start with one call to \ref memoryAddrWrite specifying the
 * start address of the new data and its length. Then, \ref memoryWrite must
 * be called several times, writing LineSize bytes each time (except the last
 * that can be smaller). Finally, \ref memoryWriteEnd must be called.
 * \ref memoryWriteEnd may throw errors if the data was not valid, but the data
 * is written anyway.
 */
class IDFU: public FeatureInterface
{
public:
	static constexpr uint16_t ID = 0x00D0;

	IDFU (Device *dev);

	/**
	 * Size of the maximum size for write().
	 */
	static constexpr unsigned int LineSize = 16;
	/**
	 * Append \ref LineSize bytes of data.
	 *
	 * \ref memoryAddrWrite must have been called before.
	 *
	 * If the data between \p begin and \p end is smaller than \ref LineSize, padding is
	 * added.
	 *
	 * If the \p length passed to \ref memoryAddrWrite is not a multiple of \ref LineSize,
	 * the extra data at the end of the last write call is ignored.
	 */
	void write (unsigned int index, std::vector<uint8_t>::const_iterator begin, std::vector<uint8_t>::const_iterator end);
};

}

#endif
