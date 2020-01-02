// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/MCUs/iMX-RT10xx/Init.cc
///

#include <ARM/NXP/MCUs/iMX-RT1011.hh>

#include <ARM/NXP/Timers/WDogs/RTWDog.hh>

using namespace ARM::NXP::Timers;
using namespace ARM::NXP::Timers::WDogs;

#ifdef NXP_iMXRT10xx

static void DisableWatchdogs() {
	// Disable RTWDOG
	WDogs::FieldCS cs = (FieldCS &)rtwDog.CS; // Copy for multiple accesses

	// Allowed to unlock RTWDOG?
    if (cs.UPDATE) {
    	// Unlock according to current `CMD32EN` requirements
		if (cs.CMD32EN) {
		   rtwDog.CNT = CNTs::Unlock;        // Full 32-bit unlock required
		} // if
		else {
		   cs.CMD32EN = true;                // Enable for next time
		   rtwDog.CNT.CNT16 = CNTs::Unlock1; // 16-bit Low followed
		   rtwDog.CNT.CNT16 = CNTs::Unlock2; // by 16-bit high
		} // else
		rtwDog.TOVAL.TOVAL16 = ~0; // Longest timeout
		cs.EN = false;             // Disable!
		rtwDog.CS = cs;            // Write back
    } // if
} // DisableWatchdogs()

void ARM::NXP::Init() {
	// Initialise OCRAM?

	DisableWatchdogs();
} // ARM::NXP::Init()

#endif // NXP_iMXRT10xx
