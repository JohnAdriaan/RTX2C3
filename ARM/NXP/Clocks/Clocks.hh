// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Clocks/Clocks.hh
///

#ifndef ARM_NXP_Clocks_Clocks_hh
#define ARM_NXP_Clocks_Clocks_hh

#include "../NXP.hh"

namespace ARM::NXP::Clocks {

	class _Clocks_ : private _NXP_ {
	}; // _Clocks_

	struct CCM;

	struct Analog;

	struct XTALOSC;

	extern CCM ccm;

	extern Analog analog;

	extern XTALOSC xtalOsc;

} // namespace ARM::NXP::Clocks

#endif // ARM_NXP_Clocks_Clocks_hh
