// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/MCUs/iMX-RT1011.hh
///
/// This file is `#include`d by a "computed include" in `ARM/ARM.hh`.
/// The compiler needs to be told which exact MCU to target.
///

#ifndef ARM_NXP_MCUs_iMX_RT1011_hh
#define ARM_NXP_MCUs_iMX_RT1011_hh

/// Include definitions for the i.MX RT10xx range
#include <ARM/NXP/MCUs/iMX-RT10xx/iMX-RT10xx.hh>

#define NXP_iMXRT1011        ///< The specific processor for this build

#define NXP_iMXRTxxxx 0x1011 ///< The variant of processor
#define NXP_iMXRT1xxx  0x011 ///< The variant of processor
#define NXP_iMXRT10xx   0x11 ///< The variant of processor
#define NXP_iMXRT101x    0x1 ///< The variant of processor

namespace ARM::NXP::Clocks {

	/// This is the MCU-specific array of CCM Clock Gating Registers.
	/// It is used to index the `Bit::Array<>` `ARM::NXP::Clocks::CCM::ccm.CCGR[]`.
	/// This overlays the actual set of `CCM_CCGR0` through `CCM_CCGR6` registers.
	///
	/// Without these definitions, if you wanted to enable the KPP Clock, you'd first need
	/// to find out that it was on CG4 of CCGR5. Then, the code would read something like:
	///
	///     `*CCM_CCGR5 = (*CCM_CCGR5 & ~(0b11 << 8)) | (CGR_ClockOn_Run << 8);`
	///
	/// With these definitions, you can write either:
	///
	///     `CCM_CCGR5.CG4 = CGR_ClockOn_Run;` using CG4 sub-field, or
	///
	///     `CCM_CCGR5[4]  = CGR_ClockOn_Run;` using array indexing
	///
	/// But even better, with the below array you can write (don't need to know _which_ CCGR!):
	///
	///     `CCM_CCGR[kpp_clk] = CGR_ClockOn_Run;`
	///
	/// And best of all? ALL of the above code gets compiled to the same opcodes!
	enum CCGRs {

		// CCGR0
		aips_tz1_clk        =   0,
		aips_tz2_clk        =   1,
		mqs_hmclk_clock     =   2,
		flexspi_exsc_clk    =   3,
		sim_m_clk_r_clk     =   4,
		dcp_clk             =   5,
		lpuart3_clk         =   6,
		trace_clk           =  11,
		gpt2_bus_clk        =  12,
		gpt2_serial_clk     =  13,
		lpuart2_clk         =  14,
		gpio2_clk           =  15,

		// CCGR1
		lpspi1_clk          =  16,
		lpspi2_clk          =  17,
		pit_clk             =  22,
		adc1_clk            =  24,
		gpt_clk             =  26,
		gpt_serial_clk      =  27,
		lpuart4_clk         =  28,
		gpio1_clk           =  29,
		csu_clk             =  30,
		gpio5_clk           =  31,

		// CCGR2
		ocram_exsc_clk      =  32,
		iomuxc_snvs_clk     =  34,
		lpi2c1_clk          =  35,
		lpi2c2_clk          =  36,
		iim_clk             =  38,
		xbar1_clk           =  43,

		// CCGR3
		aoi1_clk            =  52,
		ewm_clk             =  55,
		wdog1_clk           =  56,
		flexram_clk         =  57,
		iomuxc_snvs_gpr_clk =  63,

		// CCGR4
		sim_m7_clk_r        =  64,
		iomuxc_clk          =  65,
		iomuxc_gpr_clk      =  66,
		sim_m7_clk          =  68,
		sim_m_clk           =  70,
		sim_ems_clk         =  71,
		pwm1_clk            =  72,
		dma_ps_clk          =  79,

		// CCGR5
		rom_clk             =  80,
		flexio1_clk         =  81,
		wdog3_clk           =  82,
		dma_clk             =  83,
		kpp_clk             =  84,
		wdog2_clk           =  85,
		spdif_clk           =  87,
		sai1_clk            =  89,
		sai3_clk            =  91,
		lpuart1_clk         =  92,
		snvs_hp_clk         =  94,
		snvs_lp_clk         =  95,

		// CCGR6
		usboh3_clk          =  96,
		dcdc_clk            =  99,
		flexspi_clk         = 101,
		trng_clk            = 102,
		sim_per_clk         = 106,
		anadig_clk          = 107
	}; // CCGRs

} // namespace ARM::NXP::Clocks

#endif // ARM_NXP_MCUs_iMX_RT1011_hh
