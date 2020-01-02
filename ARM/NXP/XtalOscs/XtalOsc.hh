// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/XtalOscs/XtalOsc.hh
///

#ifndef ARM_NXP_XtalOscs_XtalOsc_hh
#define ARM_NXP_XtalOscs_XtalOsc_hh

#include <General/Field.hh>

#include "XtalOscs.hh"

namespace ARM::NXP::XtalOscs {

	/// Bias current options for `OSC_I`
	enum Osc_Is {
		NOMINAL            = 0b00,
		MINUS_12_5_PERCENT = 0b01,
		MINUS_25_PERCENT   = 0b10,
		MINUS_37_5_PERCENT = 0b11
	}; // Osc_Is

	/// Clock Gate Delays
	enum GateDelays {
		GateDelay_0_5ms = 0b000, ///< 0.5 ms
		GateDelay_1_0ms = 0b001, ///< 1.0 ms
		GateDelay_2_0ms = 0b001, ///< 2.0 ms
		GateDelay_3_0ms = 0b001, ///< 3.0 ms
		GateDelay_4_0ms = 0b001, ///< 4.0 ms
		GateDelay_5_0ms = 0b001, ///< 5.0 ms
		GateDelay_6_0ms = 0b001, ///< 6.0 ms
		GateDelay_7_0ms = 0b001  ///< 7.0 ms
	}; // GateDelays

	/// Chips sources for RTC clock
	enum RTCSources {
		RTC_Internal = 0b0,
		RTC_XTAL     = 0b1
	}; // RTCSources

	/// \brief These are the fields of the `Misc0` registers.
	/// Note that Misc0 serves multiple peripherals. The
	/// definitions here are only those applicable to the XtalOsc
	struct Misc0Fields {
		      unsigned                  : 12;
		      unsigned DISCON_HIGH_SNVS :  1; ///< Disconnect VDD_HIGH_IN-to-VDD_SNVS_IN switch
		      unsigned OSC_I            :  2; ///< {Osc_Is} Bias current
		const unsigned OSC_XTALKOK      :  1; ///< Signals output of oscillator is stable
		      unsigned OSC_XTALOK_EN    :  1; ///< Enables detector for `OSC_XTALKOK`
		      unsigned                  :  8;
		      unsigned CLKGATE_CTRL     :  1; ///< Prevent clock ever being gated off
		      unsigned CLKGATE_DELAY    :  3; ///< {GateDelays} Delay between power up and releasing clock
		const unsigned RTC_XTAL_SOURCE  :  1; ///< {RTCSources} Chip source for RTS clock
		      unsigned XTAL_24M_PWD     :  1; ///< Power down 24M crystal
		      unsigned                  :  1;
		      unsigned                  :  0;
	}; // Misc0Fields
	typedef Field<Misc0Fields, unsigned> FieldMisc0;

	/// \brief Miscellaneous register 0
	/// Inherits from `FieldMisc0` to implement the main register fields as `misc0.X`,
	/// then has sub-registers to allow the `misc0.set.X` (etc.) paradigm
	struct Misc0 : public FieldMisc0 {
		FieldMisc0 set;
		FieldMisc0 clr;
		FieldMisc0 tog;
	}; // Misc0

	/// PowerUp Delay options
	enum PowerUpDelays {
		PowerDelay_0_25_ms = 0b00,
		PowerDelay_0_50_ms = 0b01,
		PowerDelay_1_00_ms = 0b10,
		PowerDelay_2_00_ms = 0b11
	}; // PowerUpDelays

	/// \brief These are the fields of the `LowPwr` registers.
	/// Note that LowPwr serves multiple peripherals. The
	/// definitions here are only those applicable to the XtalOsc
	struct LowPwrFields {
		      unsigned RC_OSC_EN           :  1; ///< "Use RC OSC, not XTAL OSC, for 24MHz clock"? Enable `OSC_SEL`?
		      unsigned                     :  3;
		      unsigned OSC_SEL             :  1; ///< Use RC OSC, not XTAL OSC, for 24MHz clock
		      unsigned                     :  8;
		      unsigned RCOSC_CG_OVERRIDE   :  1; ///< For debug purposes
		      unsigned XTALOSC_PWRUP_DELAY :  2; ///< {PowerUpDelays} Time delay between power up and ready for use
		const unsigned XTALOSC_PWRUP_STAT  :  1; ///< Status of 24MHz xtal oscillator
		      unsigned MIX_PWRGATE         :  1; ///< Display power gate control
		      unsigned GPU_PWRGATE         :  1; ///< GPU power gate control
		      unsigned                     : 13;
		      unsigned                     :  0;
	}; // LowPwrFields
	typedef Field<LowPwrFields, unsigned> FieldLowPwr;

	/// \brief XTAL OSC (LP) control register
	/// Inherits from `FieldLowPwr` to implement the main register fields as `lowPwr.X`,
	/// then has sub-registers to allow the `lowPwr.set.X` (etc.) paradigm
	struct LowPwr : public FieldLowPwr {
		FieldLowPwr set;
		FieldLowPwr clr;
		FieldLowPwr tog;
	}; // LowPwr

	/// \brief Fields of the `Config0` registers.
	struct Config0Fields {
		unsigned START           : 1; ///< Start RC tuning calculator logic
		unsigned ENABLE          : 1; ///< Enable tuning logic
		unsigned BYPASS          : 1; ///< Bypass calculated RC tuning value
		unsigned INVERT          : 1; ///< Invert stepping of calculated RC tuning value
		unsigned RC_OSC_PROG     : 8; ///< RC oscillator tuning values
		unsigned HYST_PLUS       : 4; ///< Positive hysteresis value
		unsigned HYST_MINUS      : 4; ///< Negative hysteresis value
		unsigned                 : 4;
		unsigned RC_OSC_PROG_CUR : 8; ///< Current tuning value in use
		unsigned                 : 0;
	}; // Config0Fields
	typedef Field<Config0Fields, unsigned> FieldConfig0;

	/// \brief XTAL OSC Configuration 0 register
	/// Inherits from `FieldConfig0` to implement the main register fields as `config0.X`,
	/// then has sub-registers to allow the `config0.set.X` (etc.) paradigm
	struct Config0 : public FieldConfig0 {
		FieldConfig0 set;
		FieldConfig0 clr;
		FieldConfig0 tog;
	}; // Config0

	/// \brief Fields of the `Config1` registers.
	struct Config1Fields {
		unsigned COUNT_RC_TRG : 12; ///< Target count used to tune RC OSC frequency
		unsigned              :  8;
		unsigned COUNT_RC_CUR : 12; ///< Current tuning value in use
		unsigned              :  0;
	}; // Config1Fields
	typedef Field<Config1Fields, unsigned> FieldConfig1;

	/// \brief XTAL OSC Configuration 1 register
	/// Inherits from `FieldConfig1` to implement the main register fields as `config1.X`,
	/// then has sub-registers to allow the `config1.set.X` (etc.) paradigm
	struct Config1 : public FieldConfig1 {
		FieldConfig1 set;
		FieldConfig1 clr;
		FieldConfig1 tog;
	}; // Config1

	/// \brief Fields of the `Config2` registers.
	struct Config2Fields {
		unsigned COUNT_1M_TRG  : 12; ///< Target count used to tune 1MHz frequency
		unsigned               :  4;
		unsigned ENABLE_1M     :  1; ///< Enable 1MHz clock output
		unsigned MUX_1M        :  1; ///< Mux corrected (not uncorrected) 1MHz to output
		unsigned               : 13;
		unsigned CLK_1M_ERR_FL :  1; ///< Flag that `COUNT_1M_TRG` wasn't reached within 1x 32kHz period
		unsigned               :  0;
	}; // Config2Fields
	typedef Field<Config2Fields, unsigned> FieldConfig2;

	/// \brief XTAL OSC Configuration 2 register
	/// Inherits from `FieldConfig2` to implement the main register fields as `config2.X`,
	/// then has sub-registers to allow the `config2.set.X` (etc.) paradigm
	struct Config2 : public FieldConfig2 {
		FieldConfig2 set;
		FieldConfig2 clr;
		FieldConfig2 tog;
	}; // Config2

	struct XtalOsc {
		Misc0    misc0;
		unsigned x160[68];
		LowPwr   lowPwr;
		unsigned x280[8];
		Config0  config0;
		Config1  config1;
		Config2  config2;
	}; // XtalOsc
	static_assert(sizeof(XtalOsc)==96*sizeof(unsigned), "Incorrect ARM::NXP::XtalOscs::XtalOsc size");

} // namespace ARM::NXP::XtalOscs

static volatile ARM::NXP::XtalOscs::FieldMisc0 &XTALOSC24M_MISC0     = ARM::NXP::XtalOscs::xtalOsc.misc0;
static volatile ARM::NXP::XtalOscs::FieldMisc0 &XTALOSC24M_MISC0_SET = ARM::NXP::XtalOscs::xtalOsc.misc0.set;
static volatile ARM::NXP::XtalOscs::FieldMisc0 &XTALOSC24M_MISC0_CLR = ARM::NXP::XtalOscs::xtalOsc.misc0.clr;
static volatile ARM::NXP::XtalOscs::FieldMisc0 &XTALOSC24M_MISC0_TOG = ARM::NXP::XtalOscs::xtalOsc.misc0.tog;

static volatile ARM::NXP::XtalOscs::FieldLowPwr &XTALOSC24M_LOWPWR_CTRL      = ARM::NXP::XtalOscs::xtalOsc.lowPwr;
static volatile ARM::NXP::XtalOscs::FieldLowPwr &XTALOSC24M_LOWPWR_CTRL_SET  = ARM::NXP::XtalOscs::xtalOsc.lowPwr.set;
static volatile ARM::NXP::XtalOscs::FieldLowPwr &XTALOSC24M_LOWPWR_CTRL_CLR  = ARM::NXP::XtalOscs::xtalOsc.lowPwr.clr;
static volatile ARM::NXP::XtalOscs::FieldLowPwr &XTALOSC24M_LOWPWR_CTRL_TOG  = ARM::NXP::XtalOscs::xtalOsc.lowPwr.tog;

static volatile ARM::NXP::XtalOscs::FieldConfig0 &XTALOSC24M_OSC_CONFIG0     = ARM::NXP::XtalOscs::xtalOsc.config0;
static volatile ARM::NXP::XtalOscs::FieldConfig0 &XTALOSC24M_OSC_CONFIG0_SET = ARM::NXP::XtalOscs::xtalOsc.config0.set;
static volatile ARM::NXP::XtalOscs::FieldConfig0 &XTALOSC24M_OSC_CONFIG0_CLR = ARM::NXP::XtalOscs::xtalOsc.config0.clr;
static volatile ARM::NXP::XtalOscs::FieldConfig0 &XTALOSC24M_OSC_CONFIG0_TOG = ARM::NXP::XtalOscs::xtalOsc.config0.tog;

static volatile ARM::NXP::XtalOscs::FieldConfig1 &XTALOSC24M_OSC_CONFIG1     = ARM::NXP::XtalOscs::xtalOsc.config1;
static volatile ARM::NXP::XtalOscs::FieldConfig1 &XTALOSC24M_OSC_CONFIG1_SET = ARM::NXP::XtalOscs::xtalOsc.config1.set;
static volatile ARM::NXP::XtalOscs::FieldConfig1 &XTALOSC24M_OSC_CONFIG1_CLR = ARM::NXP::XtalOscs::xtalOsc.config1.clr;
static volatile ARM::NXP::XtalOscs::FieldConfig1 &XTALOSC24M_OSC_CONFIG1_TOG = ARM::NXP::XtalOscs::xtalOsc.config1.tog;

static volatile ARM::NXP::XtalOscs::FieldConfig2 &XTALOSC24M_OSC_CONFIG2     = ARM::NXP::XtalOscs::xtalOsc.config2;
static volatile ARM::NXP::XtalOscs::FieldConfig2 &XTALOSC24M_OSC_CONFIG2_SET = ARM::NXP::XtalOscs::xtalOsc.config2.set;
static volatile ARM::NXP::XtalOscs::FieldConfig2 &XTALOSC24M_OSC_CONFIG2_CLR = ARM::NXP::XtalOscs::xtalOsc.config2.clr;
static volatile ARM::NXP::XtalOscs::FieldConfig2 &XTALOSC24M_OSC_CONFIG2_TOG = ARM::NXP::XtalOscs::xtalOsc.config2.tog;

#endif // ARM_NXP_XtalOscs_XtalOsc_hh
