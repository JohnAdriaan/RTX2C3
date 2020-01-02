// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/Misc0.hh
///

#ifndef ARM_NXP_CCMs_Analogs_Misc0_hh
#define ARM_NXP_CCMs_Analogs_Misc0_hh

#include <General/Field.hh>

#include "Analogs.hh"

namespace ARM::NXP::CCMs::Analogs {

	/// \brief Stop Modes used by `STOP_MODE_CONFIG`.
	/// `LPBG` and `AnBG` are Low Power and Analog Band Gaps
	enum StopModes {
		StopMode__RTC_On__LPBG_AnBG_1p1_2p5_Off = 0b00,
		StopMode__RTC_AnBG_1p1_2p5_On__LPBG_Off = 0b01,
		StopMode__RTC_LPBG_1p1_2p5_On__AnBG_Off = 0b10,
		StopMode__RTC_LPBG_On__AnBG_1p1_2p5_Off = 0b11
	}; // StopModes

	/// \brief These are the fields of the `Misc0` registers.
	/// Note that Misc0 serves multiple peripherals. The
	/// definitions here are only those applicable to the CCM
	struct Misc0Fields {
		unsigned                  : 10;
		unsigned STOP_MODE_CONFIG :  2; ///< {StopModes} Which Analog peripherals are on during STOP
		unsigned DISCON_HIGH_SNVS :  1; ///< Disconnect VDD_HIGH_IN-to-VDD_SNVS_IN switch
		unsigned                  : 19;
	    unsigned                  :  0;
	}; // Misc0Fields
	typedef Field<Misc0Fields, unsigned> FieldMisc0;

	/// \brief Misc0 registers definition
	/// Inherits from `FieldMisc0` to implement the main register fields as `misc0.X`,
	/// then has sub-registers to allow the `misc0.set.X` (etc.) paradigm
	struct Misc0 : public FieldMisc0 {
		FieldMisc0 set;
		FieldMisc0 clr;
		FieldMisc0 tog;
	}; // Misc0
	static_assert(sizeof(Misc0)==4*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::Misc0 size");

} // namespace ARM::NXP::CCMs::Analogs

static volatile ARM::NXP::CCMs::Analogs::FieldMisc0 &CCM_ANALOG_MISC0     = ARM::NXP::CCMs::Analogs::misc0;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc0 &CCM_ANALOG_MISC0_SET = ARM::NXP::CCMs::Analogs::misc0.set;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc0 &CCM_ANALOG_MISC0_CLR = ARM::NXP::CCMs::Analogs::misc0.clr;
static volatile ARM::NXP::CCMs::Analogs::FieldMisc0 &CCM_ANALOG_MISC0_TOG = ARM::NXP::CCMs::Analogs::misc0.tog;

#endif // ARM_NXP_CCMs_Analogs_Misc0_hh
