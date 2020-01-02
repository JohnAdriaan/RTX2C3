// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Timers/Timers.hh
///

#ifndef ARM_NXP_Timers_Timers_hh
#define ARM_NXP_Timers_Timers_hh

#include "../NXP.hh"

namespace ARM::NXP::Timers {

	class _Timers_ : private _NXP_ {
	}; // _Timers_

	namespace WDOGs {

		struct WDOG;

		struct RTWDOG;

		extern volatile WDOG wDog1;

		extern volatile WDOG wDog2;

		extern volatile RTWDOG wDog3;

		extern volatile RTWDOG rtwDog; ///< Alias for `wDog3`

	} // namespace WDOGs

} // namespace ARM::NXP::Timers

#endif // ARM_NXP_Timers_Timers_hh
