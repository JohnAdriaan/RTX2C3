// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PLLs/Audio.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PLLs_Audio_hh
#define ARM_NXP_CCMs_Analogs_PLLs_Audio_hh

#include <General/Field.hh>

#include "PLLs.hh"

namespace ARM::NXP::CCMs::Analogs::PLLs {

	/// Post-divider selections
	enum PostDivs {
		Post_Div4 = 0b00,
		Post_Div2 = 0b01,
		Post_Div1 = 0b10
	}; // PostDivs

	/// Fields of the `Audio` registers.
	struct AudioFields {
	      unsigned DIV_SELECT      :  7; ///< Controls PLL loop divider (valid: 27-54)
	      unsigned                 :  5;
	      unsigned POWERDOWN       :  1; ///< Power down the PLL
	      unsigned ENABLE          :  1; ///< Enable PLL output
	      Bypasses BYPASS_CLK_SRC  :  2; ///< Determine the bypass source
	      unsigned BYPASS          :  1; ///< Bypass the PLL
	      unsigned                 :  2;
	      PostDivs POST_DIV_SELECT :  2;
	      unsigned                 :  1;
	      unsigned                 :  9;
	const unsigned LOCK            :  1; ///< PLL is currently locked
	      unsigned                 :  0;
	}; // AudioFields
	typedef Field<AudioFields, unsigned> FieldAudio;

	/// \brief Audio registers definition
	/// Inherits from `FieldAudio` to implement the main register fields as `audio.X`,
	/// then has sub-registers to allow the `audio.set.X` (etc.) paradigm
	struct Audio : public FieldAudio {
	    FieldAudio set;
	    FieldAudio clr;
	    FieldAudio tog;
	    FieldNum   num;
	    unsigned   x84[3];
	    FieldDenom denom;
	}; // Audio
	static_assert(sizeof(Audio)==9*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::Analogs::PLLs::Audio size");

} // namespace ARM::NXP::CCMs::Analogs::PLLs

static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldAudio &CCM_ANALOG_PLL_AUDIO       = ARM::NXP::CCMs::Analogs::PLLs::audio;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldAudio &CCM_ANALOG_PLL_AUDIO_SET   = ARM::NXP::CCMs::Analogs::PLLs::audio.set;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldAudio &CCM_ANALOG_PLL_AUDIO_CLR   = ARM::NXP::CCMs::Analogs::PLLs::audio.clr;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldAudio &CCM_ANALOG_PLL_AUDIO_TOG   = ARM::NXP::CCMs::Analogs::PLLs::audio.tog;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldNum   &CCM_ANALOG_PLL_AUDIO_NUM   = ARM::NXP::CCMs::Analogs::PLLs::audio.num;
static volatile ARM::NXP::CCMs::Analogs::PLLs::FieldDenom &CCM_ANALOG_PLL_AUDIO_DENOM = ARM::NXP::CCMs::Analogs::PLLs::audio.denom;

#endif // ARM_NXP_CCMs_Analogs_PLLs_Audio_hh
