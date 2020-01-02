// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Timers/WDOGs/WDOG.hh
///

#ifndef ARM_NXP_Timers_WDOGs_WDOG_hh
#define ARM_NXP_Timers_WDOGs_WDOG_hh

#include <General/Field.hh>

#include "../Timers.hh"

namespace ARM::NXP::Timers::WDOGs {

	/// Watchdog Control Register
	struct WCR {
		bit  WDZST : 1; ///< Watchdog low power (Suspend Timer)
		bit  WDBG  : 1; ///< Watchdog Debug enable
		bit  WDE   : 1; ///< Watchdog Enable
		bit  WDT   : 1; ///< WDOG_B Timeout assertion
		bit  SRS   : 1; ///< Software Reset Signal
		bit  WDA   : 1; ///< WDOG_B Assertion
		bit  SRE   : 1; ///< Software Reset Extension
		bit  WDW   : 1; ///< Watchdog Disable for Wait
		byte WT    : 8; ///< Watchdog Timeout - in ½ seconds
		word       : 0;
	}; // WCR
	typedef Field<WCR, word> FieldWCR;

	/// These are the Watchdog Service Register (WSR) write sequence values
	enum WSRs : word {
		WSR1 = 0b0101010101010101,
		WSR2 = 0b1010101010101010
	}; // WSRs

	/// Watchdog Reset Status Register
	struct WRSR {
		bit SFTW :  1; ///< Software Reset
		bit TOUT :  1; ///< Timeout
		word     :  2;
		bit POR  :  1; ///< Power On Reset
		word     : 11;
		word     :  0;
	}; // WRSR
	typedef Field<WRSR, word> FieldWRSR;

	/// Watchdog Interrupt Control Register
	struct WICR {
		byte WICT : 8; ///< Watchdog Interrupt Count Timeout
		word      : 6;
		bit  WITS : 1; ///< Watchdog Timer Interrupt Status
		bit  WIE  : 1; ///< Watchdog timer Interrupt Enable
		word      : 0;
	}; // WICR
	typedef Field<WICR, word> FieldWICR;

	/// Watchdog Miscellaneous Control Register
	struct WMCR {
		bit  PDE :  1; ///< Power Down Enable
		word     : 15;
		word     :  0;
	}; // WMCR
	typedef Field<WMCR, word> FieldWMCR;

	struct WDOG {
		FieldWCR  WCR;  ///< Watchdog Control Register
		WSRs      WSR;  ///< Watchdog Service Register
		FieldWRSR WRSR; ///< Watchdog Reset Status Register
		FieldWICR WICR; ///< Watchdog Interrupt Control Register
		FieldWMCR WMCR; ///< Watchdog Miscellaneous Control Register
		word      xA;   // Padding
	}; // WDOG
	static_assert(sizeof(WDOG)==6*sizeof(word), "Incorrect ARM::NXP::Timers::WDOGs::WDOG size");

} // namespace ARM::NXP::Timers::WDOGs

static volatile ARM::NXP::Timers::WDOGs::FieldWCR  &WDOG1_WCR  = ARM::NXP::Timers::WDOGs::wDog1.WCR;
static volatile ARM::NXP::Timers::WDOGs::WSRs      &WDOG1_WSR  = ARM::NXP::Timers::WDOGs::wDog1.WSR;
static volatile ARM::NXP::Timers::WDOGs::FieldWRSR &WDOG1_WRSR = ARM::NXP::Timers::WDOGs::wDog1.WRSR;
static volatile ARM::NXP::Timers::WDOGs::FieldWICR &WDOG1_WICR = ARM::NXP::Timers::WDOGs::wDog1.WICR;
static volatile ARM::NXP::Timers::WDOGs::FieldWMCR &WDOG1_WMCR = ARM::NXP::Timers::WDOGs::wDog1.WMCR;

static volatile ARM::NXP::Timers::WDOGs::FieldWCR  &WDOG2_WCR  = ARM::NXP::Timers::WDOGs::wDog2.WCR;
static volatile ARM::NXP::Timers::WDOGs::WSRs      &WDOG2_WSR  = ARM::NXP::Timers::WDOGs::wDog2.WSR;
static volatile ARM::NXP::Timers::WDOGs::FieldWRSR &WDOG2_WRSR = ARM::NXP::Timers::WDOGs::wDog2.WRSR;
static volatile ARM::NXP::Timers::WDOGs::FieldWICR &WDOG2_WICR = ARM::NXP::Timers::WDOGs::wDog2.WICR;
static volatile ARM::NXP::Timers::WDOGs::FieldWMCR &WDOG2_WMCR = ARM::NXP::Timers::WDOGs::wDog2.WMCR;

#endif // ARM_NXP_Timers_WDOGs_WDOG_hh
