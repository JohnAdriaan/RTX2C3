// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PLLs/Sys.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PLLs_Sys_hh
#define ARM_NXP_CCMs_Analogs_PLLs_Sys_hh

#include <General/Field.hh>

#include "PLLs.hh"

namespace ARM::NXP::CCMs::Analogs::PLLs {

	/// Fields of the `Sys` registers.
	struct SysFields {
	      unsigned DIV_SELECT     :  1; ///< Controls PLL loop divider
	      unsigned                :  6;
	      unsigned                :  5;
	      unsigned POWER          :  1; ///< Power up the PLL
	      unsigned ENABLE         :  1; ///< Enable PLL output
	      unsigned BYPASS_CLK_SRC :  2; ///< {Bypasses} Determine the bypass source
	      unsigned BYPASS         :  1; ///< Bypass the PLL
	      unsigned                : 14;
	const unsigned LOCK           :  1; ///< PLL is currently locked
	      unsigned                :  0;
	}; // SysFields
	typedef Field<SysFields, unsigned> FieldSys;

	/// Spread Spectrum register
	struct SS {
		unsigned STEP   : 15; ///< Frequency change Step
		unsigned ENABLE :  1; ///< Enable
		unsigned STOP   : 16; ///< Frequency change Stop
		unsigned        :  0;
	}; // SS
	typedef Field<SS, unsigned> FieldSS;

	/// \brief Sys registers definition
	/// Inherits from `FieldSys` to implement the main register fields as `sys.X`,
	/// then has sub-registers to allow the `sys.set.X` (etc.) paradigm
	struct Sys : public FieldSys {
	    FieldSys   set;
	    FieldSys   clr;
	    FieldSys   tog;
	    FieldSS    ss;
	    unsigned   x44[3];
	    FieldNum   num;
	    unsigned   x54[3];
	    FieldDenom denom;
	}; // Sys
	static_assert(sizeof(Sys)==13*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::PLLs::Sys size");

} // namespace ARM::NXP::CCMs::Analogs::PLLs

static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldSys   &CCM_ANALOG_PLL_SYS       = ARM::NXP::CCMs::Analogs::PLLs::sys;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldSys   &CCM_ANALOG_PLL_SYS_SET   = ARM::NXP::CCMs::Analogs::PLLs::sys.set;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldSys   &CCM_ANALOG_PLL_SYS_CLR   = ARM::NXP::CCMs::Analogs::PLLs::sys.clr;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldSys   &CCM_ANALOG_PLL_SYS_TOG   = ARM::NXP::CCMs::Analogs::PLLs::sys.tog;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldSS    &CCM_ANALOG_PLL_SYS_SS    = ARM::NXP::CCMs::Analogs::PLLs::sys.ss;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldNum   &CCM_ANALOG_PLL_SYS_NUM   = ARM::NXP::CCMs::Analogs::PLLs::sys.num;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldDenom &CCM_ANALOG_PLL_SYS_DENOM = ARM::NXP::CCMs::Analogs::PLLs::sys.denom;

#endif // ARM_NXP_CCMs_Analogs_PLLs_Sys_hh
