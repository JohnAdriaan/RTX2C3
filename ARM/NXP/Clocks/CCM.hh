// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Clocks/CCM.hh
///

#ifndef ARM_NXP_Clocks_CCM_hh
#define ARM_NXP_Clocks_CCM_hh

#include "../NXP.hh"

namespace ARM::NXP::Clocks {

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

	/// Clocks for `PRE_PERIPH_CLK_SEL`
	enum PrePeriph_Clocks {
		PrePeriph_PLL2      = 0b00,
		PrePeriph_PLL3_PFD3 = 0b01,
		PrePeriph_PLL2_PFD3 = 0b10,
		PrePeriph_PLL6      = 0b11
	}; // PrePeriph_Clocks

	/// Clocks for `TRACE_CLK_SEL`
	enum Trace_Clocks {
		Trace_PLL2      = 0b00,
		Trace_PLL2_PFD2 = 0b01,
		Trace_PLL2_PFD0 = 0b10,
		Trace_PLL2_PFD1 = 0b11
	}; // Trace_Clocks

	/// Clocks for `PERIPH_CLK2_SEL`
	enum PeriphClk2_Clocks {
		PeriphClk2_pll3_sw_clk    = 0b00,
		PeriphClk2_osc_clk        = 0b01,
		PeriphClk2_pll2_bypass_clk = 0b10
	}; // PeriphClk2_Clocks

	/// Clocks for `LPSPI_CLK2_SEL`
	enum LPSPI_Clocks {
		LPSPI_PLL3_PFD1 = 0b00,
		LPSPI_PLL3_PFD0 = 0b01,
		LPSPI_PLL2      = 0b10,
		LPSPI_PLL2_PFD2 = 0b11
	}; // LPSPI_Clocks

	/// CCM Bus Clock Multiplexer Register
	struct CBCMR {
		unsigned                             : 4;
		LPSPI_Clocks      LPSPI_CLK_SEL      : 2; ///< Selector for LPSPI clock multipleser
		unsigned                             : 6;
		PeriphClk2_Clocks PERIPH_CLK2_SEL    : 2; ///< Selector for Peripheral Clk2 clock multiplexer
		Trace_Clocks      TRACE_CLK_SEL      : 2; ///< Selector for Trace clock multiplexer
		unsigned                             : 2;
		PrePeriph_Clocks  PRE_PERIPH_CLK_SEL : 2; ///< Selector for pre_periph clock multiplexer
		unsigned                             : 3;
		unsigned                             : 3;
		unsigned          LPSPI_PODF         : 4; ///< Divider for LPSPI
		unsigned                             : 2;
		unsigned                             : 0;
	}; // CBCMR
	typedef Field<CBCMR, unsigned> FieldCBCMR;

	/// PERCLK Clocks for `PERCLK_CLK_SEL`
	enum PERCLK_Clocks {
		PERCLK_ipg_clk_root = 0b0,
		PERCLK_osc_clk      = 0b1
	}; // PERCLK_Clocks

	/// SAI Clocks for `SAI1_CLK_SEL` and `SAI3_CLK_SEL`
	enum SAI_Clocks {
		SAI_PLL3_PFD2   = 0b00,
		SAI_pll3_sw_clk = 0b01,
		SAI_PLL4        = 0b10
	}; // SAI_Clocks

	/// FlexSPI Clocks for `FLEXSPI_CLK_SEL`
	enum FlexSPI_Clocks {
		FlexSPI_PLL2        = 0b00,
		FlexSPI_pll3_sw_clk = 0b01,
		FlexSPI_PLL2_PFD2   = 0b10,
		FlexSPI_PLL3_PFD0   = 0b11
	}; // FlexSPI_Clocks

	/// FlexSPI Clock Sources for `FLEXSPI_CLK_SRC`
	enum FlexSPI_Sources {
		FlexSPI_CCM_CSCMR1 = 0b0,
		FlexSPI_CCM_CBCMR  = 0b1
	}; // FlexSPI_Sources

	/// CCM Serial Clock Multiplexer Register 1
	struct CSCMR1 {
		unsigned        PERCLK_PODF     : 6; ///< Divider for perclk podf
		PERCLK_Clocks   PERCLK_CLK_SEL  : 1; ///< Selector for the perclk clock multiplexer
		unsigned                        : 3;
		SAI_Clocks      SAI1_CLK_SEL    : 2;
		unsigned                        : 2;
		SAI_Clocks      SAI3_CLK_SEL    : 2; ///< Selector for sai3 clock multiplexer
		unsigned                        : 2;
		unsigned                        : 5;
		unsigned        FLEXSPI_PODF    : 3; ///< Divider for slexspi clock root
		unsigned                        : 3;
		FlexSPI_Clocks  FLEXSPI_CLK_SEL : 2; ///< Selector for slexspi clock multiplexer
		FlexSPI_Sources FLEXSPI_CLK_SRC : 1; ///< Select source of flexspi_clk_root
		unsigned                        : 0;
	}; // CSCMR1
	typedef Field<CSCMR1, unsigned> FieldCSCMR1;

	/// FlexIO Clocks for `FLEXIO1_CLK_SEL`
	enum FlexIO_Clocks {
		FlexIO_PLL4        = 0b00,
		FlexIO_PLL3_PFD2   = 0b01,
		FlexIO_PLL2        = 0b10,
		FlexIO_pll3_sw_clk = 0b11
	}; // FlexIO_Clocks

	/// Valid dividers for `ADC_ACLK_PODF`
	enum ADC_PODFs {
		ADC_pll3_sw_clk_DIV8  = 0b0111,
		ADC_pll3_sw_clk_DIV12 = 0b1011,
		ADC_pll3_sw_clk_DIV16 = 0b1111
	}; // ADC_PODFs

	/// CCM Serial Clock Multiplexer Register 2
	struct CSCMR2 {
		unsigned                      : 2;
		unsigned                      : 8;
		unsigned                      : 9;
		FlexIO_Clocks FLEXIO1_CLK_SEL : 2; ///< Selector for FlexIO1 clock multiplexer
		unsigned                      : 6;
		ADC_PODFs     ADC_ACLK_PODF   : 4; ///< Divider for ADC alt_clk
		unsigned      ADC_ACLK_EN     : 1; ///< Enable ADC alt_clk
		unsigned                      : 0;
	}; // CSCMR2
	typedef Field<CSCMR2, unsigned> FieldCSCMR2;

	/// UART Clocks for `UART_CLK_SEL`
	enum UART_Clocks {
		UART_pll3_80m     = 0b00,
		UART_osc_clk      = 0b01,
		UART_per_clk_root = 0b10
	}; // UART_Clocks

	/// CCM Clock Divider Register
	struct CS1CDR {
		      unsigned    UART_CLK_PODF : 6; ///< Divider for uart clock podf
		      UART_Clocks UART_CLK_SEL  : 2; ///< Selector for UART clock multiplexer
		      unsigned                  : 3;
		      unsigned                  : 3;
		      unsigned                  : 2;
		      unsigned                  : 3;
		      unsigned                  : 6;
		      unsigned    TRACE_PODF    : 4; ///< Divider for Trace clock
		const unsigned                  : 3;
		      unsigned                  : 0;
	}; // CS1CDR
	typedef Field<CS1CDR, unsigned> FieldCS1CDR;

	/// SPDIF Clocks for `SPDIF0_CLK_SEL`
	enum SPDIF_Clocks {
		SPDIF_PLL4        = 0b00,
		SPDIF_PLL3_PFD2   = 0b01,
		SPDIF_pll3_sw_clk = 0b11
	}; // SPDIF_Clocks

	/// CCM D1 Clock Divider Register
	struct CDCDR {
		unsigned                     : 7;
		unsigned                     : 8;
		unsigned                     : 5;
		SPDIF_Clocks SPDIF0_CLK_SEL  : 2;
		unsigned     SPIDF0_CLK_PODF : 3;
		unsigned     SPDIF0_CLK_PRED : 3;
		unsigned                     : 4;
		unsigned                     : 0;
	}; // CDCDR
	typedef Field<CDCDR, unsigned> FieldCDCDR;

	/// LPI2C Clocks for `LPI2C_CLK_SEL`
	enum LPI2C_Clocks {
		LPI2C_pll3_60m = 0b0,
		LPI2C_osc_clk  = 0b1
	}; // LPI2C_Clocks

	/// CCM Serial Clock Divider Register 2
	struct CSCDR2 {
		unsigned                    : 9;
		unsigned                    : 9;
		LPI2C_Clocks LPI2C_CLK_SEL  : 1; ///< Selector for the LPI2C clock multiplexor
		unsigned     LPI2C_CLK_PODF : 6; ///< Divider for lpi2c clock podf
		unsigned                    : 7;
		unsigned                    : 0;
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
		const unsigned                     : 16;
		      unsigned                     :  0;
	}; // CDHIPR
	typedef Field<CDHIPR, unsigned> FieldCDHIPR;

	/// CCM Low Power Control Register
	struct CLPCR {
		unsigned : 0;
	}; // CLPCR
	typedef Field<CLPCR, unsigned> FieldCLPCR;

	/// CCM Interrupt Status Register
	struct CISR {
		unsigned : 0;
	}; // CISR
	typedef Field<CISR, unsigned> FieldCISR;

	/// CCM Interrupt Mask Register
	struct CIMR {
		unsigned : 0;
	}; // CIMR
	typedef Field<CIMR, unsigned> FieldCIMR;

	/// CCM Clock Output Source Register
	struct CCOSR {
		unsigned : 0;
	}; // CCOSR
	typedef Field<CCOSR, unsigned> FieldCCOSR;

	/// CCM General Purpose Register
	struct CGPR {
		unsigned : 0;
	}; // CGPR
	typedef Field<CGPR, unsigned> FieldCGPR;

	/// CCM Clock Gating Register 0
	struct CCGR0 {
		unsigned : 0;
	}; // CCGR0
	typedef Field<CCGR0, unsigned> FieldCCGR0;

	/// CCM Clock Gating Register 1
	struct CCGR1 {
		unsigned : 0;
	}; // CCGR1
	typedef Field<CCGR1, unsigned> FieldCCGR1;

	/// CCM Clock Gating Register 2
	struct CCGR2 {
		unsigned : 0;
	}; // CCGR2
	typedef Field<CCGR2, unsigned> FieldCCGR2;

	/// CCM Clock Gating Register 3
	struct CCGR3 {
		unsigned : 0;
	}; // CCGR3
	typedef Field<CCGR3, unsigned> FieldCCGR3;

	/// CCM Clock Gating Register 4
	struct CCGR4 {
		unsigned : 0;
	}; // CCGR4
	typedef Field<CCGR4, unsigned> FieldCCGR4;

	/// CCM Clock Gating Register 5
	struct CCGR5 {
		unsigned : 0;
	}; // CCGR5
	typedef Field<CCGR5, unsigned> FieldCCGR5;

	/// CCM Clock Gating Register 6
	struct CCGR6 {
		unsigned : 0;
	}; // CCGR6
	typedef Field<CCGR6, unsigned> FieldCCGR6;

	/// CCM Module Enable Override Register
	struct CMEOR {
		unsigned : 0;
	}; // CMEOR
	typedef Field<CMEOR, unsigned> FieldCMEOR;

	/// Clock Controller Module
	struct CCM {
		volatile FieldCCR    CCR;    ///< CCM Control Register
				 unsigned    x04;
		volatile FieldCSR    CSR;    ///< CCM Status Register
		volatile FieldCCSR   CCSR;   ///< CCM Clock Switcher Register
				 unsigned    x10;
		volatile FieldCBCDR  CBCDR;  ///< CCM Bus Clock Divider Register
		volatile FieldCBCMR  CBCMR;  ///< CCM Bus Clock Multiplexer Register
		volatile FieldCSCMR1 CSCMR1; ///< CCM Serial Clock Multiplexer Register 1
		volatile FieldCSCMR2 CSCMR2; ///< CCM Serial Clock Multiplexer Register 2
		volatile FieldCS1CDR CS1CDR; ///< CCM Clock Divider Register
				 unsigned    x2C;
		volatile FieldCDCDR  CDCDR;  ///< CCM D1 Clock Divider Register
				 unsigned    x34;
		volatile FieldCSCDR2 CSCDR2; ///< CCM Serial Clock Divider Register 2
				 unsigned    x3C;
				 unsigned    x40;
				 unsigned    x44;
		volatile FieldCDHIPR CDHIPR; ///< CCM Divider Handshake In-Process Register
				 unsigned    x4C;
				 unsigned    x50;
		volatile FieldCLPCR  CLPCR;  ///< CCM Low Power Control Register
		volatile FieldCISR   CISR;   ///< CCM Interrupt Status Register
		volatile FieldCIMR   CIMR;   ///< CCM Interrupt Mask Register
		volatile FieldCCOSR  CCOSR;  ///< CCM Clock Output Source Register
		volatile FieldCGPR   CGPR;   ///< CCM General Purpose Register
		volatile FieldCCGR0  CCGR0;  ///< CCM Clock Gating Register 0
		volatile FieldCCGR1  CCGR1;  ///< CCM Clock Gating Register 1
		volatile FieldCCGR2  CCGR2;  ///< CCM Clock Gating Register 2
		volatile FieldCCGR3  CCGR3;  ///< CCM Clock Gating Register 3
		volatile FieldCCGR4  CCGR4;  ///< CCM Clock Gating Register 4
		volatile FieldCCGR5  CCGR5;  ///< CCM Clock Gating Register 5
		volatile FieldCCGR6  CCGR6;  ///< CCM Clock Gating Register 6
				 unsigned    x84;
		volatile FieldCMEOR  CMEOR;  ///< CCM Module Enable Override Register
	}; // CCM
	static_assert(sizeof(CCM)==35*sizeof(unsigned), "Incorrect ARM::NXP::Clocks::CCM size");

} // namespace ARM::NXP::Clocks

static volatile ARM::NXP::Clocks::FieldCCR    &CCR    = ARM::NXP::Clocks::ccm.CCR;
static volatile ARM::NXP::Clocks::FieldCSR    &CSR    = ARM::NXP::Clocks::ccm.CSR;
static volatile ARM::NXP::Clocks::FieldCCSR   &CCSR   = ARM::NXP::Clocks::ccm.CCSR;
static volatile ARM::NXP::Clocks::FieldCBCDR  &CBCDR  = ARM::NXP::Clocks::ccm.CBCDR;
static volatile ARM::NXP::Clocks::FieldCBCMR  &CBCMR  = ARM::NXP::Clocks::ccm.CBCMR;
static volatile ARM::NXP::Clocks::FieldCSCMR1 &CSCMR1 = ARM::NXP::Clocks::ccm.SCSMR1;
static volatile ARM::NXP::Clocks::FieldCSCMR2 &CSCMR2 = ARM::NXP::Clocks::ccm.CSCMR2;
static volatile ARM::NXP::Clocks::FieldCS1CDR &CS1CDR = ARM::NXP::Clocks::ccm.CS1CDR;
static volatile ARM::NXP::Clocks::FieldCDCDR  &CDCDR  = ARM::NXP::Clocks::ccm.CDCDR;
static volatile ARM::NXP::Clocks::FieldCSCDR2 &CSCDR2 = ARM::NXP::Clocks::ccm.CSCDR2;
static volatile ARM::NXP::Clocks::FieldCDHIPR &CDHIPR = ARM::NXP::Clocks::ccm.CDHIPR;
static volatile ARM::NXP::Clocks::FieldCLPCR  &CLPCR  = ARM::NXP::Clocks::ccm.CLPCR;
static volatile ARM::NXP::Clocks::FieldCISR   &CISR   = ARM::NXP::Clocks::ccm.CISR;
static volatile ARM::NXP::Clocks::FieldCIMR   &CIMR   = ARM::NXP::Clocks::ccm.CIMR;
static volatile ARM::NXP::Clocks::FieldCCOSR  &CCOSR  = ARM::NXP::Clocks::ccm.CCOSR;
static volatile ARM::NXP::Clocks::FieldCGPR   &CGPR   = ARM::NXP::Clocks::ccm.CGPR;
static volatile ARM::NXP::Clocks::FieldCCGR0  &CCGR0  = ARM::NXP::Clocks::ccm.CCGR0;
static volatile ARM::NXP::Clocks::FieldCCGR1  &CCGR1  = ARM::NXP::Clocks::ccm.CCGR1;
static volatile ARM::NXP::Clocks::FieldCCGR2  &CCGR2  = ARM::NXP::Clocks::ccm.CCGR2;
static volatile ARM::NXP::Clocks::FieldCCGR3  &CCGR3  = ARM::NXP::Clocks::ccm.CCGR3;
static volatile ARM::NXP::Clocks::FieldCCGR4  &CCGR4  = ARM::NXP::Clocks::ccm.CCGR4;
static volatile ARM::NXP::Clocks::FieldCCGR5  &CCGR5  = ARM::NXP::Clocks::ccm.CCGR5;
static volatile ARM::NXP::Clocks::FieldCCGR6  &CCGR6  = ARM::NXP::Clocks::ccm.CCGR6;
static volatile ARM::NXP::Clocks::FieldCMEOR  &CMEOR  = ARM::NXP::Clocks::ccm.CMEOR;

#endif // ARM_NXP_Clocks_CCM_hh
