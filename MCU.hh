// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file MCU.hh
///

#ifndef MCU_hh
#define MCU_hh

/// \namespace MCU
/// This is used to scope MCU-agnostic - yet MCU-specific - identifiers
namespace MCU {

	/// Current sysClock rate in Hz
	extern const unsigned &sysClock;

} // namespace MCU

#endif // MCU_hh
