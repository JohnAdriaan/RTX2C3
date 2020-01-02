// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/CCMs.hh
///

#ifndef ARM_NXP_CCMs_CCMs_hh
#define ARM_NXP_CCMs_CCMs_hh

#include "../NXP.hh"

namespace ARM::NXP::CCMs {

	namespace Analogs {

	} // namespace Analogs

	struct CCM;

	struct XTALOSC;

	extern volatile CCM ccm;

	extern volatile XTALOSC xtalOsc;

} // namespace ARM::NXP::CCMs

#endif // ARM_NXP_CCMs_CCMs_hh
