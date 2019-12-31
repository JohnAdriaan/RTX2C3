// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/SCBs.hh
///

#ifndef ARM_SCBs_hh
#define ARM_SCBs_hh

#include "ARM.hh"

/// \namespace ARM::SCBs
/// ARM have defined the System Control Block (SCB).
/// These are its definitions.
namespace ARM::SCBs {

	class _SCB_ : private _ARM_ {
	}; // _SCB_

	/// See `SCBs/ACTLR.hh` for definitions
	union ACTLR;

	extern volatile ACTLR actlr;

	/// See `SCBs/SCB.hh` for definitions
	struct SCB;

	extern SCB scb;

} // namespace ARM::SCBs

#include "SCBs/ACTLR.hh"
#include "SCBs/SCB.hh"

#endif // ARM_NVICs_hh
