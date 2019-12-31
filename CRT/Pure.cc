// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Pure.cc
///

#include "../CRT.hh"

/// This function is used by `gcc` to populate `pure` entries in virtual method tables
extern "C"
void __cxa_pure_virtual() {
	assert(false); // Whoops!
} // __cxa_pure_virtual()
