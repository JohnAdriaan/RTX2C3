// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/CRT.cc
///

#include "../CRT.hh"

void CRT::Fill(unsigned section[], unsigned *end, unsigned value) {
	unsigned *ptr = section;
	while (ptr < end) {
		*ptr++ = value;
	} // for
} // CRT::Fill(section, end, value)
