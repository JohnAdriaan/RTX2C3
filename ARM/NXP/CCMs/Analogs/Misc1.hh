// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/Misc1.hh
///

#ifndef ARM_NXP_CCMs_Analogs_Misc1_hh
#define ARM_NXP_CCMs_Analogs_Misc1_hh

#include <General/Field.hh>

#include "Analogs.hh"

namespace ARM::NXP::CCMs::Analogs {

	/// \brief These are the fields of the `Misc1` registers.
	/// Note that Misc1 serves multiple peripherals. The
	/// definitions here are only those applicable to the CCM
	struct Misc1Fields {
		unsigned                     : 16;
		unsigned PFD_480_AUTOGATE_EN :  1; ///< Enable "clkgate (reset)" of all PFD_480 clocks when PLL unlocked / turned off
		unsigned PFD_528_AUTOGATE_EN :  1; ///< Enable "clkgate (reset)" of all PFD_528 clocks when PLL unlocked / turned off
		unsigned                     : 14;
	    unsigned                     :  0;
	}; // Misc1Fields
	typedef Field<Misc1Fields, unsigned> FieldMisc1;

	/// \brief Misc1 registers definition
	/// Inherits from `FieldMisc1` to implement the main register fields as `misc1.X`,
	/// then has sub-registers to allow the `misc1.set.X` (etc.) paradigm
	struct Misc1 : public FieldMisc1 {
		FieldMisc1 set;
		FieldMisc1 clr;
		FieldMisc1 tog;
	}; // Misc1
	static_assert(sizeof(Misc1)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::Misc1 size");

} // namespace ARM::NXP::CCMs::Analogs

static volatile ARM::NXP::CCMs::Analogs::FieldMisc1 &CCM_ANALOG_MISC1     = ARM::NXP::CCMs::Analogs::misc1;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc1 &CCM_ANALOG_MISC1_SET = ARM::NXP::CCMs::Analogs::misc1.set;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc1 &CCM_ANALOG_MISC1_CLR = ARM::NXP::CCMs::Analogs::misc1.clr;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc1 &CCM_ANALOG_MISC1_TOG = ARM::NXP::CCMs::Analogs::misc1.tog;

#endif // ARM_NXP_CCMs_Analogs_Misc1_hh
