// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PFD.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PFD_hh
#define ARM_NXP_CCMs_Analogs_PFD_hh

#include <General/Field.hh>

#include "Analogs.hh"

namespace ARM::NXP::CCMs::Analogs {

	/// Fields of the `PFD` registers.
	struct PFDFields {
	      unsigned PFD0_FRAC    : 6; ///< Fractional divider value (12-35)
	const unsigned PFD0_STABLE  : 1; ///< Value inverts on stable
	      unsigned PFD0_CLKGATE : 1; ///< Turn off PFD0 clock
	      unsigned PFD1_FRAC    : 6; ///< Fractional divider value (12-35)
	const unsigned PFD1_STABLE  : 1; ///< Value inverts on stable
	      unsigned PFD1_CLKGATE : 1; ///< Turn off PFD0 clock
	      unsigned PFD2_FRAC    : 6; ///< Fractional divider value (12-35)
	const unsigned PFD2_STABLE  : 1; ///< Value inverts on stable
	      unsigned PFD2_CLKGATE : 1; ///< Turn off PFD0 clock
	      unsigned PFD3_FRAC    : 6; ///< Fractional divider value (12-35)
	const unsigned PFD3_STABLE  : 1; ///< Value inverts on stable
	      unsigned PFD3_CLKGATE : 1; ///< Turn off PFD0 clock
	      unsigned              : 0;
	}; // PFDFields
	typedef Field<PFDFields, unsigned> FieldPFD;

	/// \brief PFD registers definition
	/// Inherits from `FieldPFD` to implement the main register fields as `pfd###.X`,
	/// then has sub-registers to allow the `pfd###.set.X` (etc.) paradigm
	struct PFD : public FieldPFD {
		FieldPFD set;
		FieldPFD clr;
		FieldPFD tog;
	}; // PFD
	static_assert(sizeof(PFD)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::PFD size");

} // namespace ARM::NXP::CCMs::Analogs

static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_480     = ARM::NXP::CCMs::Analogs::pfd480;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_480_SET = ARM::NXP::CCMs::Analogs::pfd480.set;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_480_CLR = ARM::NXP::CCMs::Analogs::pfd480.clr;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_480_TOG = ARM::NXP::CCMs::Analogs::pfd480.tog;

static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_528     = ARM::NXP::CCMs::Analogs::pfd528;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_528_SET = ARM::NXP::CCMs::Analogs::pfd528.set;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_528_CLR = ARM::NXP::CCMs::Analogs::pfd528.clr;
static volatile ARM::NXP::CCMs::Analogs::FieldPFD &CCM_ANALOG_PFD_528_TOG = ARM::NXP::CCMs::Analogs::pfd528.tog;

#endif // ARM_NXP_CCMs_Analogs_PFD_hh
