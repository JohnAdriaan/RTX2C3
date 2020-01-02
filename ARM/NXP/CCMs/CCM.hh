// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/CCM.hh
///

#ifndef ARM_NXP_CCMs_CCM_hh
#define ARM_NXP_CCMs_CCM_hh

#include <General/Bit.hh>

#include "CCMs.hh"

namespace ARM::NXP::CCMs {

	/// CCM Control Register
	struct CCR {
		unsigned OSCNT            : 8; ///< Oscillator ready Counter value
		unsigned                  : 4;
		unsigned COSC_EN          : 1; ///< On-chip Oscillator enable
		unsigned                  : 8;
		unsigned REG_BYPASS_COUNT : 6; ///< Counter for analog_reg_bypass signal assertion
		unsigned RBC_EN           : 1; ///< Enable for `REG_BYPASS_COUNTER`
		unsigned                  : 4;
		unsigned                  : 0;
	}; // CCR
	typedef Field<CCR, unsigned> FieldCCR;

	/// CCM Status Register
	struct CSR {
		const unsigned REF_EN_B    :  1; ///< Status of `CCM_REF_EN_B` output of ccm
		const unsigned             :  2;
		const unsigned CAMP2_READY :  1; ///< Status indication of `CAMP2`
		const unsigned             :  1;
		const unsigned COSC_READY  :  1; ///< On-Chip Oscillator Ready
		const unsigned             : 26;
		      unsigned             :  0;
	}; // CSR
	typedef Field<CSR, unsigned> FieldCSR;

	/// CCM Clock Switcher Register
	struct CCSR {
		      unsigned PLL3_SW_CLK_SEL :  1; ///< Select source to generate pll3_sw_clk
		      unsigned                 :  1;
		const unsigned                 :  1;
		const unsigned                 :  5;
		      unsigned                 :  1;
		const unsigned                 : 23;
		      unsigned                 :  0;
	}; // CCSR
	typedef Field<CCSR, unsigned> FieldCCSR;

	/// CCM Bus Clock Divider Register
	struct CBCDR {
		unsigned                : 3;
		unsigned                : 3;
		unsigned                : 2;
		unsigned IPG_PODF       : 2; ///< Divider for ipg podf
		unsigned AHB_PODF       : 3; ///< Divider for AHB PODF
		unsigned                : 3;
		unsigned                : 3;
		unsigned                : 6;
		unsigned PERIPH_CLK_SEL : 1;
		unsigned                : 1;
		unsigned                : 3;
		unsigned                : 2;
		unsigned                : 0;
	}; // CBCDR
	typedef Field<CBCDR, unsigned> FieldCBCDR;

	/// CCMs for `LPSPI_CLK_SEL`
	enum LPSPI_CCMs {
		LPSPI_PLL3_PFD1 = 0b00,
		LPSPI_PLL3_PFD0 = 0b01,
		LPSPI_PLL2      = 0b10,
		LPSPI_PLL2_PFD2 = 0b11
	}; // LPSPI_CCMs

	/// CCMs for `PERIPH_CLK2_SEL`
	enum PeriphClk2_CCMs {
		PeriphClk2_pll3_sw_clk    = 0b00,
		PeriphClk2_osc_clk        = 0b01,
		PeriphClk2_pll2_bypass_clk = 0b10
	}; // PeriphClk2_CCMs

	/// CCMs for `TRACE_CLK_SEL`
	enum Trace_CCMs {
		Trace_PLL2      = 0b00,
		Trace_PLL2_PFD2 = 0b01,
		Trace_PLL2_PFD0 = 0b10,
		Trace_PLL2_PFD1 = 0b11
	}; // Trace_CCMs

	/// CCMs for `PRE_PERIPH_CLK_SEL`
	enum PrePeriph_CCMs {
		PrePeriph_PLL2      = 0b00,
		PrePeriph_PLL3_PFD3 = 0b01,
		PrePeriph_PLL2_PFD3 = 0b10,
		PrePeriph_PLL6      = 0b11
	}; // PrePeriph_CCMs

	/// CCM Bus Clock Multiplexer Register
	struct CBCMR {
		unsigned                    : 4;
		unsigned LPSPI_CLK_SEL      : 2; ///< {LPSPI_CCMs} Selector for LPSPI clock multipleser
		unsigned                    : 6;
		unsigned PERIPH_CLK2_SEL    : 2; ///< {PeriphClk2_CCMs} Selector for Peripheral Clk2 clock multiplexer
		unsigned TRACE_CLK_SEL      : 2; ///< {Trace_CCMs} Selector for Trace clock multiplexer
		unsigned                    : 2;
		unsigned PRE_PERIPH_CLK_SEL : 2; ///< {PrePeriph_CCMs} Selector for pre_periph clock multiplexer
		unsigned                    : 3;
		unsigned                    : 3;
		unsigned LPSPI_PODF         : 4; ///< Divider for LPSPI
		unsigned                    : 2;
		unsigned                    : 0;
	}; // CBCMR
	typedef Field<CBCMR, unsigned> FieldCBCMR;

	/// PERCLK CCMs for `PERCLK_CLK_SEL`
	enum PERCLK_CCMs {
		PERCLK_ipg_clk_root = 0b0,
		PERCLK_osc_clk      = 0b1
	}; // PERCLK_CCMs

	/// SAI CCMs for `SAI1_CLK_SEL` and `SAI3_CLK_SEL`
	enum SAI_CCMs {
		SAI_PLL3_PFD2   = 0b00,
		SAI_pll3_sw_clk = 0b01,
		SAI_PLL4        = 0b10
	}; // SAI_CCMs

	/// FlexSPI CCMs for `FLEXSPI_CLK_SEL`
	enum FlexSPI_CCMs {
		FlexSPI_PLL2        = 0b00,
		FlexSPI_pll3_sw_clk = 0b01,
		FlexSPI_PLL2_PFD2   = 0b10,
		FlexSPI_PLL3_PFD0   = 0b11
	}; // FlexSPI_CCMs

	/// FlexSPI Clock Sources for `FLEXSPI_CLK_SRC`
	enum FlexSPI_Sources {
		FlexSPI_CCM_CSCMR1 = 0b0,
		FlexSPI_CCM_CBCMR  = 0b1
	}; // FlexSPI_Sources

	/// CCM Serial Clock Multiplexer Register 1
	struct CSCMR1 {
		unsigned PERCLK_PODF     : 6; ///< Divider for perclk podf
		unsigned PERCLK_CLK_SEL  : 1; ///< {PERCLK_CCMs} Selector for the perclk clock multiplexer
		unsigned                 : 3;
		unsigned SAI1_CLK_SEL    : 2; ///< {SAI_CCMs} Selector for sai1 clock multiplexer
		unsigned                 : 2;
		unsigned SAI3_CLK_SEL    : 2; ///< {SAI_CCMs} Selector for sai3 clock multiplexer
		unsigned                 : 2;
		unsigned                 : 5;
		unsigned FLEXSPI_PODF    : 3; ///< Divider for slexspi clock root
		unsigned                 : 3;
		unsigned FLEXSPI_CLK_SEL : 2; ///< {FlexSPI_CCMs} Selector for slexspi clock multiplexer
		unsigned FLEXSPI_CLK_SRC : 1; ///< {FlexSPI_Sources} Select source of flexspi_clk_root
		unsigned                 : 0;
	}; // CSCMR1
	typedef Field<CSCMR1, unsigned> FieldCSCMR1;

	/// FlexIO CCMs for `FLEXIO1_CLK_SEL`
	enum FlexIO_CCMs {
		FlexIO_PLL4        = 0b00,
		FlexIO_PLL3_PFD2   = 0b01,
		FlexIO_PLL2        = 0b10,
		FlexIO_pll3_sw_clk = 0b11
	}; // FlexIO_CCMs

	/// Valid dividers for `ADC_ACLK_PODF`
	enum ADC_PODFs {
		ADC_pll3_sw_clk_DIV8  = 0b0111,
		ADC_pll3_sw_clk_DIV12 = 0b1011,
		ADC_pll3_sw_clk_DIV16 = 0b1111
	}; // ADC_PODFs

	/// CCM Serial Clock Multiplexer Register 2
	struct CSCMR2 {
		unsigned                 : 2;
		unsigned                 : 8;
		unsigned                 : 9;
		unsigned FLEXIO1_CLK_SEL : 2; ///< {FlexIO_CCMs} Selector for FlexIO1 clock multiplexer
		unsigned                 : 6;
		unsigned ADC_ACLK_PODF   : 4; ///< {ADC_PODFs} Divider for ADC alt_clk
		unsigned ADC_ACLK_EN     : 1; ///< Enable ADC alt_clk
		unsigned                 : 0;
	}; // CSCMR2
	typedef Field<CSCMR2, unsigned> FieldCSCMR2;

	/// UART CCMs for `UART_CLK_SEL`
	enum UART_CCMs {
		UART_pll3_80m     = 0b00,
		UART_osc_clk      = 0b01,
		UART_per_clk_root = 0b10
	}; // UART_CCMs

	/// CCM Serial Clock Divider Register 1
	struct CSCDR1 {
		      unsigned UART_CLK_PODF : 6; ///< Divider for uart clock podf
		      unsigned UART_CLK_SEL  : 2; ///< {UART_CCMs} Selector for UART clock multiplexer
		      unsigned               : 3;
		      unsigned               : 3;
		      unsigned               : 2;
		      unsigned               : 3;
		      unsigned               : 6;
		      unsigned TRACE_PODF    : 4; ///< Divider for Trace clock
		const unsigned               : 3;
		      unsigned               : 0;
	}; // CSCDR1
	typedef Field<CSCDR1, unsigned> FieldCSCDR1;

	/// CCM Clock Divider Register
	struct CS1CDR {
		      unsigned SAI1_CLK_PODF    : 6; ///< Divider for sai1 clock podf
		      unsigned SAI1_CLK_PRED    : 3; ///< Divider for sai1 clock pred
		      unsigned FLEXIO1_CLK_PRED : 3; ///< Divider for flexio1 clock
		const unsigned                  : 4;
		      unsigned SAI3_CLK_PODF    : 6; ///< Divider for sai3 clock podf
		      unsigned SAI3_CLK_PRED    : 3; ///< Divider for sai3 clock pred
		      unsigned FLEXIO1_CLK_PODF : 4; ///< Divider for flexio1 clock
		const unsigned                  : 3;
		      unsigned                  : 0;
	}; // CS1CDR
	typedef Field<CS1CDR, unsigned> FieldCS1CDR;

	/// SPDIF CCMs for `SPDIF0_CLK_SEL`
	enum SPDIF_CCMs {
		SPDIF_PLL4        = 0b00,
		SPDIF_PLL3_PFD2   = 0b01,
		SPDIF_pll3_sw_clk = 0b11
	}; // SPDIF_CCMs

	/// CCM D1 Clock Divider Register
	struct CDCDR {
		unsigned                 : 7;
		unsigned                 : 8;
		unsigned                 : 5;
		unsigned SPDIF0_CLK_SEL  : 2; ///< {SPDIF_CCMs} Selector for spdif0 clock multiplexer
		unsigned SPIDF0_CLK_PODF : 3; ///< Divider for spdif0 clock podf
		unsigned SPDIF0_CLK_PRED : 3; ///< Divider for spdif0 clock pred
		unsigned                 : 4;
		unsigned                 : 0;
	}; // CDCDR
	typedef Field<CDCDR, unsigned> FieldCDCDR;

	/// LPI2C CCMs for `LPI2C_CLK_SEL`
	enum LPI2C_CCMs {
		LPI2C_pll3_60m = 0b0,
		LPI2C_osc_clk  = 0b1
	}; // LPI2C_CCMs

	/// CCM Serial Clock Divider Register 2
	struct CSCDR2 {
		unsigned                : 9;
		unsigned                : 9;
		unsigned LPI2C_CLK_SEL  : 1; ///< {LPI2C_CCMs} Selector for the LPI2C clock multiplexor
		unsigned LPI2C_CLK_PODF : 6; ///< Divider for lpi2c clock podf
		unsigned                : 7;
		unsigned                : 0;
	}; // CSCDR2
	typedef Field<CSCDR2, unsigned> FieldCSCDR2;

	/// CCM Divider Handshake In-Process Register
	struct CDHIPR {
		      unsigned                     :  1;
		const unsigned AHB_PODF_BUSY       :  1; ///< Busy indicator for ahb_podf
		      unsigned                     :  1;
		const unsigned FLEXSPI_PODF_BUSY   :  1; ///< Busy indicator for flexspi_podf
		const unsigned PERCLK_PODF_BUSY    :  1; ///< Busy indicator for perclk_podf
		const unsigned PERIPH_CLK_SEL_BUSY :  1; ///< Busy indicator for periph_clk_sel mux control
		      unsigned                     : 10;
		      unsigned                     :  1;
		const unsigned                     : 15;
		      unsigned                     :  0;
	}; // CDHIPR
	typedef Field<CDHIPR, unsigned> FieldCDHIPR;

	/// Low Power Modes used by `LPM`
	enum LPMs {
		LPM_Remain_Run    = 0b00,
		LPM_Transfer_Wait = 0b01,
		LPM_Transfer_Stop = 0b10
	}; // LPMs

	/// Standby Count values for `STBY_COUNT`
	enum STBY_Counts {
		STBY_PMIC_1  = 0b00,
		STBY_PMIC_3  = 0b01,
		STBY_PMIC_7  = 0b10,
		STBY_PMIC_15 = 0b11
	}; // STBY_Counts

	/// CCM Low Power Control Register
	struct CLPCR {
		unsigned LPM                : 2; ///< {LPMs} Low Power Mode on dsm_request
		unsigned                    : 1;
		unsigned                    : 2;
		unsigned ARM_CLK_DIS_ON_LPM : 1; ///< ARM CCMs Disabled On Wait mode
		unsigned SBYOS              : 1; ///< Standby Clock Oscillator
		unsigned DIS_REF_OSC        : 1; ///< Disable Reference Oscillator
		unsigned VSTBY              : 1; ///< Voltage Standby request
		unsigned STBY_COUNT         : 2; ///< {STBY_Counts} Standby Counter definition
		unsigned COSC_PWRDOWN       : 1; ///< On-chip Oscillator Power Down
		unsigned                    : 7;
		unsigned                    : 3;
		unsigned MASK_CORE0_WFI     : 1; ///< Mask WFI of Core0 for entering low power mode
		unsigned                    : 3;
		unsigned MASK_SCU_IDLE      : 1; ///< Mask SCU IDLE for entering low power mode
		unsigned MASK_L2CC_IDLE     : 1; ///< Mask L2CC IDLE for entering low power mode
		unsigned                    : 4;
		unsigned                    : 0;
	}; // CLPCR
	typedef Field<CLPCR, unsigned> FieldCLPCR;

	/// CCM Interrupt Status Register
	struct CISR {
		      unsigned LRF_PLL               : 1; ///< CCM interrupt request 2 generated due to lock of all enabled PLLs
		const unsigned                       : 5;
		      unsigned COSC_READY            : 1; ///< CCM interrupt request 2 generated due to on board oscillator ready
		const unsigned                       : 9;
		      unsigned FLEXSPI_PODF_LOADED   : 1; ///< CCM interrupt request 1 generated due to frequency change of flexspi_podf
		      unsigned                       : 1;
		      unsigned PERCLK_PODF_LOADED    : 1; ///< CCM interrupt request 1 generated due to frequency change of perclk_podf
		      unsigned                       : 1;
		      unsigned AHB_PODF_LOADED       : 1; ///< CCM interrupt request 1 generated due to frequency change of ahb_podf
		      unsigned                       : 1;
		      unsigned PERIPH_CLK_SEL_LOADED : 1; ///< CCM interrupt request 1 generated due to update of periph_clk_sel
		      unsigned                       : 1;
		const unsigned                       : 2;
		      unsigned                       : 1;
		const unsigned                       : 5;
		      unsigned                       : 0;
	}; // CISR
	typedef Field<CISR, unsigned> FieldCISR;

	/// CCM Interrupt Mask Register
	struct CIMR {
	      unsigned MASK_LRF_PLL               : 1; ///< Mask `LRF_PLL` interrupt
	const unsigned                            : 5;
	      unsigned MASK_COSC_READY            : 1; ///< Mask `COSC_READY` interrupt
	const unsigned                            : 9;
	      unsigned MASK_FLEXSPI_PODF_LOADED   : 1; ///< Mask `FLEXSPI_PODF_LOADED` interrupt
	      unsigned                            : 1;
	      unsigned MASK_PERCLK_PODF_LOADED    : 1; ///< Mask `PERCLK_PODF_LOADED` interrupt
	      unsigned                            : 1;
	      unsigned MASK_AHB_PODF_LOADED       : 1; ///< Mask `AHB_PODF_LOADED` interrupt
	      unsigned                            : 1;
	      unsigned MASK_PERIPH_CLK_SEL_LOADED : 1; ///< Mask `PERIPH_CLK_SEL_LOADED` interrupt
	      unsigned                            : 3;
	      unsigned                            : 1;
	const unsigned                            : 5;
	      unsigned                            : 0;
	}; // CIMR
	typedef Field<CIMR, unsigned> FieldCIMR;

	/// CCMs for `CLKO1_SEL`
	enum CLKO1_CCMs {
		CLKO1_pll3_sw_clk_Div2 = 0b0000,
		CLKO1_PLL2_Div2        = 0b0001,
		CLKO1_ENET_PLL_Div2    = 0b0010,
		CLKO1_core_clk_root    = 0b1011,
		CLKO1_ipg_clk_root     = 0b1100,
		CLKO1_perclk_root      = 0b1101,
		CLKO1_pll4_main_clk    = 0b1111
	}; // CLKO1_CCMs

	/// Outputs for `CLKO1_OUT_SEL`
	enum CLKO1_Outputs {
		CLKO1_Output_from_CLKO1 = 0b0,
		CLKO1_Output_from_CLKO2 = 0b1
	}; // CLKO1_Outputs

	/// CCMs for `CLKO2_SEL`
	enum CLKO2_CCMs {
		CLKO2_lpi2c_clk_root   = 0b00110,
		CLKO2_osc_clk          = 0b01110,
		CLKO2_lpspi_clk_root   = 0b10000,
		CLKO2_sai1_clk_root    = 0b10010,
		CLKO2_sai3_clk_root    = 0b10100,
		CLKO2_trace_clk_root   = 0b10110,
		CLKO2_flexspi_clk_root = 0b11011,
		CLKO2_uart_clk_root    = 0b11100,
		CLKO2_spidf0_clk_root  = 0b11101
	}; // CLKO2_CCMs

	/// CCM Clock Output Source Register
	struct CCOSR {
		      unsigned CLKO1_SEL     : 4; ///< {CLKO1_CCMs} Selection of clock to be generated on CCM_CLKO1
		      unsigned CLKO1_DIV     : 3; ///< Divider for CCM_CLKO1
		      unsigned CLKO1_EN      : 1; ///< Enable CCM_CLKO1
		      unsigned CLKO1_OUT_SEL : 1; ///< {CLKO1_Outputs} CCM_CLKO1 output reflects which CCM_CLKO#
		const unsigned               : 7;
		      unsigned CLKO2_SEL     : 5; ///< {CLKO2_CCMs} Selection of clock to be generated on CCM_CLKO2
		      unsigned CLKO2_DIV     : 3; ///< Divider for CCM_CLKO2
		      unsigned CLKO2_EN      : 1; ///< Enable CCM_CLKO2
		const unsigned               : 7;
		      unsigned               : 0;
	}; // CCOSR
	typedef Field<CCOSR, unsigned> FieldCCOSR;

	/// System Memory DS Controls for `SYS_MEM_DS_CTRL`
	enum SysMemDSCtrls {
		SysMemDS_Disable_Always           = 0b00,
		SysMemDS_Enable_STOP_PLL_Disabled = 0b01,
		SysMemDS_Enable_STOP              = 0b10,
//		SysMemDS_Enable_STOP              = 0b11  ///< Either or
	}; // SysMemDSCtrls

	/// CCM General Purpose Register
	struct CGPR {
		      unsigned PMIC_DELAY_SCALER      :  1; ///< Define clock division for STBY_COUNT
		      unsigned SET_TO_1               :  1; ///< Reserved. Keep as `1` for proper operation
		      unsigned                        :  2;
		      unsigned EFUSE_PROG_SUPPLY_GATE :  1; ///< Value of output signal `cgpr_dout[4]`
		const unsigned                        :  2;
		const unsigned                        :  2;
		const unsigned                        :  5;
		      unsigned SYS_MEM_DS_CTRL        :  2; ///< System Memory DS Control {SysMemDSCtrls}
		      unsigned FPL                    :  1; ///< Fast PLL enable
		      unsigned INT_MEM_CLK_LPM        :  1; ///< Keep Memory CCMs on if Int pending and entering Low Power Mode
		const unsigned                        : 14;
		      unsigned                        :  0;
	}; // CGPR
	typedef Field<CGPR, unsigned> FieldCGPR;

	/// Clock Gating Register values
	enum CGRs {
		CGR_ClockOn_Never    = 0b00, ///< Clock disabled
		CGR_ClockOn_Run      = 0b01, ///< Clock off during WAIT and STOP
		CGR_ClockOn_Run_Wait = 0b11  ///< Clock off during STOP
	}; // CGRs

	/// CCM Clock Gating Register
	struct CCGR {
		unsigned CG0  : 2; ///< {CGRs}
		unsigned CG1  : 2; ///< {CGRs}
		unsigned CG2  : 2; ///< {CGRs}
		unsigned CG3  : 2; ///< {CGRs}
		unsigned CG4  : 2; ///< {CGRs}
		unsigned CG5  : 2; ///< {CGRs}
		unsigned CG6  : 2; ///< {CGRs}
		unsigned CG7  : 2; ///< {CGRs}
		unsigned CG8  : 2; ///< {CGRs}
		unsigned CG9  : 2; ///< {CGRs}
		unsigned CG10 : 2; ///< {CGRs}
		unsigned CG11 : 2; ///< {CGRs}
		unsigned CG12 : 2; ///< {CGRs}
		unsigned CG13 : 2; ///< {CGRs}
		unsigned CG14 : 2; ///< {CGRs}
		unsigned CG15 : 2; ///< {CGRs}
		unsigned      : 0;
	}; // CCGR
	typedef Bit::Update<CCGR, unsigned, 2> FieldCCGR;

	/// CCM Module Enable Override Register
	struct CMEOR {
		const unsigned                :  5;
		      unsigned MOD_EN_OV_GPT  :  1; ///< Override clock Enable from GPT Module
		      unsigned MOD_EN_OV_PIT  :  1; ///< Override clock Enable from PIT Module
		const unsigned                :  2;
		      unsigned MOD_EN_OV_TRNG :  1; ///< Override clock Enable from TRNG Module
		const unsigned                :  1;
		const unsigned                : 17;
		const unsigned                :  1;
		const unsigned                :  1;
		const unsigned                :  1;
		const unsigned                :  1;
		      unsigned                :  0;
	}; // CMEOR
	typedef Field<CMEOR, unsigned> FieldCMEOR;

	/// Clock Controller Module
	struct CCM {
		FieldCCR    CCR;    ///< CCM Control Register
		unsigned    x04;
		FieldCSR    CSR;    ///< CCM Status Register
		FieldCCSR   CCSR;   ///< CCM Clock Switcher Register
		unsigned    x10;
		FieldCBCDR  CBCDR;  ///< CCM Bus Clock Divider Register
		FieldCBCMR  CBCMR;  ///< CCM Bus Clock Multiplexer Register
		FieldCSCMR1 CSCMR1; ///< CCM Serial Clock Multiplexer Register 1
		FieldCSCMR2 CSCMR2; ///< CCM Serial Clock Multiplexer Register 2
		FieldCSCDR1 CSCDR1; ///< CCM Serial Clock Divider Register 1
		FieldCS1CDR CS1CDR; ///< CCM Clock Divider Register
		unsigned    x2C;
		FieldCDCDR  CDCDR;  ///< CCM D1 Clock Divider Register
		unsigned    x34;
		FieldCSCDR2 CSCDR2; ///< CCM Serial Clock Divider Register 2
		unsigned    x3C;
		unsigned    x40;
		unsigned    x44;
		FieldCDHIPR CDHIPR; ///< CCM Divider Handshake In-Process Register
		unsigned    x4C;
		unsigned    x50;
		FieldCLPCR  CLPCR;  ///< CCM Low Power Control Register
		FieldCISR   CISR;   ///< CCM Interrupt Status Register
		FieldCIMR   CIMR;   ///< CCM Interrupt Mask Register
		FieldCCOSR  CCOSR;  ///< CCM Clock Output Source Register
		FieldCGPR   CGPR;   ///< CCM General Purpose Register

#define CCGR_Regs(CCGR_Regs)          \
		struct CCGR_Regs {            \
			FieldCCGR CCGR0; \
			FieldCCGR CCGR1; \
			FieldCCGR CCGR2; \
			FieldCCGR CCGR3; \
			FieldCCGR CCGR4; \
			FieldCCGR CCGR5; \
			FieldCCGR CCGR6; \
		} // struct
        CCGR_Regs(CCGR_Regs); ///< Declare a `struct` called "CCGR_Regs" as `#define`d by `CCGR_Regs()`
        union {
        	CCGR_Regs();      ///< Define an anonymous `struct` as `#define`d by `CCGR_Regs()`
        	/// Now define an overlay for array access to all CCGRs
        	Bit::Array::Update<CCGR_Regs, unsigned, 2, 0, CCGRs> CCGR;
        }; // union
#undef CCGR_Regs // Don't leave this lying around

		unsigned    x84;
		FieldCMEOR  CMEOR;  ///< CCM Module Enable Override Register
	}; // CCM
	static_assert(sizeof(CCM)==35*sizeof(unsigned), "Incorrect ARM::NXP::CCMs::CCM size");

} // namespace ARM::NXP::CCMs

#define CCM_CCGR ARM::NXP::CCMs::ccm.CCGR ///< Allow direct access to `Bit::Array::Update<>` `ccm.CCGR`

static volatile ARM::NXP::CCMs::FieldCCR    &CCM_CCR    = ARM::NXP::CCMs::ccm.CCR;
static volatile ARM::NXP::CCMs::FieldCSR    &CCM_CSR    = ARM::NXP::CCMs::ccm.CSR;
static volatile ARM::NXP::CCMs::FieldCCSR   &CCM_CCSR   = ARM::NXP::CCMs::ccm.CCSR;
static volatile ARM::NXP::CCMs::FieldCBCDR  &CCM_CBCDR  = ARM::NXP::CCMs::ccm.CBCDR;
static volatile ARM::NXP::CCMs::FieldCBCMR  &CCM_CBCMR  = ARM::NXP::CCMs::ccm.CBCMR;
static volatile ARM::NXP::CCMs::FieldCSCMR1 &CCM_CSCMR1 = ARM::NXP::CCMs::ccm.CSCMR1;
static volatile ARM::NXP::CCMs::FieldCSCMR2 &CCM_CSCMR2 = ARM::NXP::CCMs::ccm.CSCMR2;
static volatile ARM::NXP::CCMs::FieldCS1CDR &CCM_CS1CDR = ARM::NXP::CCMs::ccm.CS1CDR;
static volatile ARM::NXP::CCMs::FieldCDCDR  &CCM_CDCDR  = ARM::NXP::CCMs::ccm.CDCDR;
static volatile ARM::NXP::CCMs::FieldCSCDR2 &CCM_CSCDR2 = ARM::NXP::CCMs::ccm.CSCDR2;
static volatile ARM::NXP::CCMs::FieldCDHIPR &CCM_CDHIPR = ARM::NXP::CCMs::ccm.CDHIPR;
static volatile ARM::NXP::CCMs::FieldCLPCR  &CCM_CLPCR  = ARM::NXP::CCMs::ccm.CLPCR;
static volatile ARM::NXP::CCMs::FieldCISR   &CCM_CISR   = ARM::NXP::CCMs::ccm.CISR;
static volatile ARM::NXP::CCMs::FieldCIMR   &CCM_CIMR   = ARM::NXP::CCMs::ccm.CIMR;
static volatile ARM::NXP::CCMs::FieldCCOSR  &CCM_CCOSR  = ARM::NXP::CCMs::ccm.CCOSR;
static volatile ARM::NXP::CCMs::FieldCGPR   &CCM_CGPR   = ARM::NXP::CCMs::ccm.CGPR;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR0  = ARM::NXP::CCMs::ccm.CCGR0;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR1  = ARM::NXP::CCMs::ccm.CCGR1;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR2  = ARM::NXP::CCMs::ccm.CCGR2;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR3  = ARM::NXP::CCMs::ccm.CCGR3;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR4  = ARM::NXP::CCMs::ccm.CCGR4;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR5  = ARM::NXP::CCMs::ccm.CCGR5;
static volatile ARM::NXP::CCMs::FieldCCGR   &CCM_CCGR6  = ARM::NXP::CCMs::ccm.CCGR6;
static volatile ARM::NXP::CCMs::FieldCMEOR  &CCM_CMEOR  = ARM::NXP::CCMs::ccm.CMEOR;

#endif // ARM_NXP_CCMs_CCM_hh
