// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/Misc2.hh
///

#ifndef ARM_NXP_CCMs_Analogs_Misc2_hh
#define ARM_NXP_CCMs_Analogs_Misc2_hh

#include <General/Field.hh>

#include "Analogs.hh"

namespace ARM::NXP::CCMs::Analogs {

	/// \brief These are the fields of the `Misc2` registers.
	/// Note that Misc2 serves multiple peripherals. The
	/// definitions here are only those applicable to the CCM
	struct Misc2Fields {
		unsigned               : 7;
		unsigned PLL3_DISABLE  : 1; ///< PLL3 not being used for other than USB
		unsigned               : 7;
		unsigned AUDIO_DIV_LSB : 1; ///< LSb of Post0divider for Audio PLL
		unsigned               : 7;
		unsigned AUDIO_DIV_MSB : 1; ///< MSb of Post-divider for Audio PLL
		unsigned               : 8;
	    unsigned               : 0;
	}; // Misc2Fields
	typedef Field<Misc2Fields, unsigned> FieldMisc2;

	/// \brief Misc2 registers definition
	/// Inherits from `Misc2_Fields` to implement the main register fields as `misc2.X`,
	/// then has sub-registers to allow the `misc2.set.X` (etc.) paradigm
	struct Misc2 : public FieldMisc2 {
		FieldMisc2 set;
		FieldMisc2 clr;
		FieldMisc2 tog;
	}; // Misc2
	static_assert(sizeof(Misc2)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::Misc2 size");

} // namespace ARM::NXP::CCMs::Analogs

static volatile ARM::NXP::CCMs::Analogs::FieldMisc2 &CCM_ANALOG_MISC2     = ARM::NXP::CCMs::Analogs::misc2;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc2 &CCM_ANALOG_MISC2_SET = ARM::NXP::CCMs::Analogs::misc2.set;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc2 &CCM_ANALOG_MISC2_CLR = ARM::NXP::CCMs::Analogs::misc2.clr;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc2 &CCM_ANALOG_MISC2_TOG = ARM::NXP::CCMs::Analogs::misc2.tog;

#endif // ARM_NXP_CCMs_Analogs_Misc2_hh
