// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PLLs/ENet.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PLLs_ENet_hh
#define ARM_NXP_CCMs_Analogs_PLLs_ENet_hh

#include <General/Field.hh>

#include "PLLs.hh"

namespace ARM::NXP::CCMs::Analogs::PLLs {

	/// Fields of the `ENet` registers.
	struct ENetFields {
		      unsigned                  : 2;
		      unsigned DIV_SELECT       : 5; ///< Controls PLL loop divider
		      unsigned                  : 5;
		      unsigned POWERDOWN        : 1; ///< Power down the PLL
		      unsigned                  : 1;
		      Bypasses BYPASS_CLK_SRC   : 2; ///< Determine the bypass source
		      unsigned BYPASS           : 1; ///< Bypass the PLL
		      unsigned                  : 2;
		      unsigned                  : 2;
		      unsigned                  : 1;
		      unsigned ENUM_500M_REF_EN : 1; ///< Enable PLL providing ENET 500 MHz reference clock
		      unsigned                  : 8;
		const unsigned LOCK             : 1; ///< PLL is currently locked
		      unsigned                  : 0;
	}; // ENetFields
	typedef Field<ENetFields, unsigned> FieldENet;

	/// \brief ENet registers definition
	/// Inherits from `FieldENet` to implement the main register fields as `eNet.X`,
	/// then has sub-registers to allow the `eNet.set.X` (etc.) paradigm
	struct ENet : public FieldENet {
		FieldENet set;
		FieldENet clr;
		FieldENet tog;
	}; // ENet
	static_assert(sizeof(ENet)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::PLLs::ENet size");

} // namespace ARM::NXP::CCMs::Analogs::PLLs

static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldENet &CCM_ANALOG_PLL_ENet1     = ARM::NXP::CCMs::Analogs::PLLs::eNet;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldENet &CCM_ANALOG_PLL_ENet1_SET = ARM::NXP::CCMs::Analogs::PLLs::eNet.set;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldENet &CCM_ANALOG_PLL_ENet1_CLR = ARM::NXP::CCMs::Analogs::PLLs::eNet.clr;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldENet &CCM_ANALOG_PLL_ENet1_TOG = ARM::NXP::CCMs::Analogs::PLLs::eNet.tog;

#endif // ARM_NXP_CCMs_Analogs_PLLs_ENet_hh
