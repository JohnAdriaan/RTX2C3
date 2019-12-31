// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/ARM.hh
///

#ifndef ARM_ARM_hh
#define ARM_ARM_hh

#include <General/General.hh>

/// \namespace ARM
/// All ARM-specific identifiers are scoped within this `namespace`
namespace ARM {

	namespace ISRs {
	} // namespace ISRs

	namespace NVICs {
	} // namespace NVICs

	namespace SCBs {
	} // namespace SCBs

	class _ARM_ : private _General_ {
	}; // _ARM_

} // namespace ARM

// Computed `#include`
#include MCU_HH

#endif // ARM_ARM_hh
