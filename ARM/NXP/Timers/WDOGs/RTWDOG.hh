// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Timers/WDOGs/RTWDOG.hh
///

#ifndef ARM_NXP_Timers_WDOGs_RTWDOG_hh
#define ARM_NXP_Timers_WDOGs_RTWDOG_hh

#include <General/Field.hh>

#include "../Timers.hh"

namespace ARM::NXP::Timers::WDOGs {

	/// Watchdog Test modes
	enum TSTs {
		TestDisable = 0b00,
		TestUser    = 0b01,
		TestLow     = 0b10,
		TestHigh    = 0b11
	}; // TSTs

	/// Watchdog Clock sources
	enum Clocks {
		ClockBus    = 0b00, ///< Bus clock
		ClockLPO    = 0b01, ///< LPO clock
		ClockINTCLK = 0b10, ///< Internal clock
		ClockERCLK  = 0b11  ///< External Reference clock
	}; // Clocks

	/// Control and Status
	struct CS {
		      unsigned STOP    :  1; ///< Stop enable
		      unsigned WAIT    :  1; ///< Wait enable
		      unsigned DBG     :  1; ///< Debug enable
		      unsigned TST     :  2; ///< {TSTs} Watchdog Test
		      unsigned UPDATE  :  1; ///< Allow Updates
		      unsigned INT     :  1; ///< Watchdog Interrupt
		      unsigned EN      :  1; ///< Watchdog Enable
		const unsigned RCS     :  1; ///< Reconfiguration success
		const unsigned ULK     :  1; ///< Watchdog is unlocked
		      unsigned PRES    :  1; ///< Watchdog Prescaler
		      unsigned CMD32EN :  1; ///< Switch to 32-bit CNT writes
		      unsigned FLG     :  1; ///< Watchdog interrupt Flag
		      unsigned WIN     :  1; ///< Watchdog Window
		      unsigned         : 16;
		      unsigned         :  0;
	}; // CS
	typedef Field<CS, unsigned> FieldCS;

	enum CNTs {
		Unlock1 = 0xC520,                   ///< 16-bit Unlock1 code
		Unlock2 = 0xD928,                   ///< 16-bit Unlock2 code
		Unlock = (Unlock2 << 16) | Unlock1, ///< 32-bit Unlock code (CMD32EN)

		Refresh1 = 0xA602,                    ///< 16-bit Refresh1 code
		Refresh2 = 0xB480,                    ///< 16-bit Refresh2 code
		Refresh = (Refresh2 << 16) | Refresh1 ///< 32-bit Refresh code
	}; // CNTs

	/// Counter
	struct CNT {
		union {
			struct {
				byte CNTLOW;
				byte CNTHIGH;
			}; // struct
			word     CNT16;
			unsigned CNT32;
		}; // union
	}; // CNT
	typedef Field<CNT, unsigned> FieldCNT;

	/// TimeOut Value
	struct TOVAL {
		union {
			struct {
				byte TOVALLOW;
				byte TOVALHIGH;
			}; // struct
			word     TOVAL16;
			unsigned TOVAL32;
		}; // union
	}; // TOVAL
	typedef Field<TOVAL, unsigned> FieldTOVAL;

	/// Watchdog Window
	struct WIN {
		union {
			struct {
				byte WINLOW;
				byte WINHIGH;
			}; // struct
			word     WIN16;
			unsigned WIN32;
		}; // union
	}; // WIN
	typedef Field<WIN, unsigned> FieldWIN;

	struct RTWDOG {
		volatile FieldCS    CS;
		volatile FieldCNT   CNT;
		volatile FieldTOVAL TOVAL;
		volatile FieldWIN   WIN;
	}; // RTWDOG
	static_assert(sizeof(RTWDOG)==4*sizeof(unsigned), "Incorrect ARM::NXP::Timers::WDOGs::RTWDOG size");

} // namespace ARM::NXP::Timers::WDOGs

static volatile ARM::NXP::Timers::WDOGs::FieldCS    &CS    = ARM::NXP::Timers::WDOGs::rtwDog.CS;
static volatile ARM::NXP::Timers::WDOGs::FieldCNT   &CNT   = ARM::NXP::Timers::WDOGs::rtwDog.CNT;
static volatile ARM::NXP::Timers::WDOGs::FieldTOVAL &TOVAL = ARM::NXP::Timers::WDOGs::rtwDog.TOVAL;
static volatile ARM::NXP::Timers::WDOGs::FieldWIN   &WIN   = ARM::NXP::Timers::WDOGs::rtwDog.WIN;

#endif // ARM_NXP_Timers_WDOGs_RTWDOG_hh
