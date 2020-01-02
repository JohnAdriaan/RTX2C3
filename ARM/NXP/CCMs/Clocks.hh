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

	namespace Analog {
	} // namespace Analog

	struct CCM;

	struct XTALOSC;

	extern CCM ccm;

	extern XTALOSC xtalOsc;

} // namespace ARM::NXP::Clocks

#include "Analog.hh"

#endif // ARM_NXP_Clocks_Clocks_hh
