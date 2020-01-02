// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Timers/Timers.hh
///

#ifndef ARM_NXP_Timers_Timers_hh
#define ARM_NXP_Timers_Timers_hh

#include "../NXP.hh"

namespace ARM::NXP::Timers {

	namespace WDogs {

		struct WDog;

		struct RTWDog;

		extern volatile WDog wDog1;

		extern volatile WDog wDog2;

		extern volatile RTWDog wDog3;

		extern volatile RTWDog rtwDog; ///< Alias for `wDog3`

	} // namespace WDogs

} // namespace ARM::NXP::Timers

#endif // ARM_NXP_Timers_Timers_hh
