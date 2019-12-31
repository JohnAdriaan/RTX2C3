// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/MCUs/iMX-RT10xx/ISRs.hh
///

#ifndef ARM_NXP_MCUs_iMX_RT10xx_ISRs_hh
#define ARM_NXP_MCUs_iMX_RT10xx_ISRs_hh

#define NUM_IRQS 80 ///< IRQ0() - IRQ79()

namespace ARM::NXP::ISRs {

	void eDMA_Ch0();
	void eDMA_Ch1();
	void eDMA_Ch2();
	void eDMA_Ch3();
	void eDMA_Ch4();
	void eDMA_Ch5();
	void eDMA_Ch6();
	void eDMA_Ch7();
	void eDMA_Ch8();
	void eDMA_Ch9();
	void eDMA_Ch10();
	void eDMA_Ch11();
	void eDMA_Ch12();
	void eDMA_Ch13();
	void eDMA_Ch14();
	void eDMA_Ch15();
	void eDMA_Error();

	void CTI_IRQ0();
	void CTI_IRQ1();
	void CM7_Exception();

	void LPUART1();
	void LPUART2();
	void LPUART3();
	void LPUART4();

	void PIT();

	void USB();
	void USB_PHY();

	void FlexSPI();

	void FlexRAM();

	void LPI2C1();
	void LPI2C2();

	void GPT1();
	void GPT2();

	void LPSPI1();
	void LPSPI2();

	void PWM0();
	void PWM1();
	void PWM2();
	void PWM3();
	void PWM_Error();

	void KPP();

	void SRC();

	void GPR();

	void CCM1();
	void CCM2();

	void EWM();

	void WDOG1();
	void WDOG2();
	void RTWDOG();

	void SNVS_HP();
	void SNVS_HP_Security();
	void SNVS_Short();

	void CSU();

	void DCP_CRC();
	void DCP_Ch0();

	void TRNG();

	void SAI1();
	void SAI3_RX();
	void SAI3_TX();

	void SPDIF();

	void PMU();

	void XBAR1();

	void Temp();
	void Temp_Panic();

	void GPC();

	void ADC1();

	void FlexIO1();

	void DCDC();

	void GPIO1_Lo();
	void GPIO1_Hi();
	void GPIO2();
	void GPIO5();

	void ADC_ETC_0();
	void ADC_ETC_1();
	void ADC_ETC_2();
	void ADC_ETC_3();
	void ADC_ETC_Error();

} // namespace ARM::NXP::ISRs

#endif // ARM_NXP_MCUs_iMX_RT10xx_ISRs_hh
