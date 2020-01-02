// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PLLs/USB.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PLLs_USB_hh
#define ARM_NXP_CCMs_Analogs_PLLs_USB_hh

#include <General/Field.hh>

#include "PLLs.hh"

namespace ARM::NXP::CCMs::Analogs::PLLs {

	/// Fields of the `USB` registers.
	struct USBFields {
		      unsigned                :  1;
		      unsigned DIV_SELECT     :  1; ///< Controls PLL loop divider
		      unsigned                :  4;
		      unsigned EN_USB_CLOCKS  :  1; ///< Power 9-phase PLL outputs
		      unsigned                :  5;
		      unsigned POWER          :  1; ///< Power up the PLL
		      unsigned ENABLE         :  1; ///< Enable PLL output
		      Bypasses BYPASS_CLK_SRC :  2; ///< Determine the bypass source
		      unsigned BYPASS         :  1; ///< Bypass the PLL
		      unsigned                : 14;
		const unsigned LOCK           :  1; ///< PLL is currently locked
		      unsigned                :  0;
	}; // USBFields
	typedef Field<USBFields, unsigned> FieldUSB;

	/// \brief USB registers definition
	/// Inherits from `FieldUSB` to implement the main register fields as `usb1.X`,
	/// then has sub-registers to allow the `usb1.set.X` (etc.) paradigm
	struct USB : public FieldUSB {
		FieldUSB set;
		FieldUSB clr;
		FieldUSB tog;
	}; // USB
	static_assert(sizeof(USB)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::PLLs::USB size");

} // namespace ARM::NXP::CCMs::Analogs::PLLs

static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldUSB &CCM_ANALOG_PLL_USB1     = ARM::NXP::CCMs::Analogs::PLLs::usb1;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldUSB &CCM_ANALOG_PLL_USB1_SET = ARM::NXP::CCMs::Analogs::PLLs::usb1.set;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldUSB &CCM_ANALOG_PLL_USB1_CLR = ARM::NXP::CCMs::Analogs::PLLs::usb1.clr;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldUSB &CCM_ANALOG_PLL_USB1_TOG = ARM::NXP::CCMs::Analogs::PLLs::usb1.tog;

#endif // ARM_NXP_CCMs_Analogs_PLLs_USB_hh
