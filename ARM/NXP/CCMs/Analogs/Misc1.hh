// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/Misc1.hh
///

#ifndef ARM_NXP_CCMs_Analogs_Misc1_hh
#define ARM_NXP_CCMs_Analogs_Misc1_hh

#include "../Analogs.hh"

namespace ARM::NXP::CCMs::Analogs {

	/// \brief These are the fields of the `Misc1` registers.
	/// Note that Misc1 serves multiple peripherals. These
	/// definitions are only those applicable to the CCM
	struct Fields1 {
		unsigned                     : 16;
		unsigned PFD_480_AUTOGATE_EN :  1; ///< Enable "clkgate (reset)" of all PFD_480 clocks when PLL unlocked / turned off
		unsigned PFD_528_AUTOGATE_EN :  1; ///< Enable "clkgate (reset)" of all PFD_528 clocks when PLL unlocked / turned off
		unsigned                     : 14;
	    unsigned                     :  0;
	}; // Fields1

	/// \brief Misc1 registers definition
	/// Inherit from `Fields1` to implement the main register fields as `misc1.X`,
	/// then have sub-registers to allow the `misc1.set.X` (etc.) paradigm
	struct Misc1 : public Fields1 {
	    Fields1 set;
	    Fields1 clr;
	    Fields1 tog;
	}; // Misc1
	static_assert(sizeof(Misc1)==4*sizeof(unsigned), "Incorrect Misc1 size");

} // namespace ARM::NXP::CCMs::Analogs

static volatile ARM::NXP::CCMs::Analogs::Fields1 &CCM_ANALOG_MISC1     = ARM::NXP::CCMs::Analogs::misc1;
static volatile ARM::NXP::CCMs::Analogs::Fields1 &CCM_ANALOG_MISC1_SET = ARM::NXP::CCMs::Analogs::misc1.set;
static volatile ARM::NXP::CCMs::Analogs::Fields1 &CCM_ANALOG_MISC1_CLR = ARM::NXP::CCMs::Analogs::misc1.clr;
static volatile ARM::NXP::CCMs::Analogs::Fields1 &CCM_ANALOG_MISC1_TOG = ARM::NXP::CCMs::Analogs::misc1.tog;

#endif // ARM_NXP_CCMs_Analogs_Misc1_hh
