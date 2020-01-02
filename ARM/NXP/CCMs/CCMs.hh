// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/CCMs.hh
///

#ifndef ARM_NXP_CCMs_CCMs_hh
#define ARM_NXP_CCMs_CCMs_hh

#include "../NXP.hh"

namespace ARM::NXP::CCMs {

	class _CCMs_ : private _NXP_ {
	}; // _CCMs_

	namespace Analogs {

		class _Analogs_ : private _CCMs_ {
		}; // _Analogs_

	} // namespace Analogs

	struct CCM;

	struct XTALOSC;

	extern volatile CCM ccm;

	extern volatile XTALOSC xtalOsc;

} // namespace ARM::NXP::CCMs

#include "Analogs.hh"

#endif // ARM_NXP_CCMs_CCMs_hh
