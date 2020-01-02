// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Clocks/Analog.hh
///

#ifndef ARM_NXP_Clocks_Analog_hh
#define ARM_NXP_Clocks_Analog_hh

#include "Clocks.hh"

namespace ARM::NXP::Clocks {

	namespace Analog {

		namespace PLLs {

			struct USB1;

			struct Sys;

			struct Audio;

			struct ENet;

		    struct PFD_480;

		    struct PFD_528;

		} // namespace PLLs

		namespace Miscs {
		} // namespace Miscs

	} // namespace Analog

	struct Analog {
		         unsigned           x000[4];
		volatile FieldPLL_USB1      PLL_USB1;     ///< Analog USB1 480MHz PLL Control Register
		volatile FieldPLL_USB1      PLL_USB1_SET; ///< Analog USB1 480MHz PLL Control Register
		volatile FieldPLL_USB1      PLL_USB1_CLR; ///< Analog USB1 480MHz PLL Control Register
		volatile FieldPLL_USB1      PLL_USB1_TOG; ///< Analog USB1 480MHz PLL Control Register
		         unsigned           x020[4];
		volatile FieldPLL_SYS       PLL_SYS;      ///< Analog System PLL Control Register
		volatile FieldPLL_SYS       PLL_SYS_SET;  ///< Analog System PLL Control Register
		volatile FieldPLL_SYS       PLL_SYS_CLR;  ///< Analog System PLL Control Register
		volatile FieldPLL_SYS       PLL_SYS_TOG;  ///< Analog System PLL Control Register
		volatile FiledPLL_SYS_SS    PLL_SYS_SS;    ///< 528MHz System PLL Spread Spectrum register
                 unsigned           x044[3];
		volatile FieldPLL_SYS_NUM   PLL_SYS_NUM;   ///< Numerator of 528MHz System PLL fractional loop Divider
		         unsigned           x054[3];
		volatile FieldPLL_SYS_DENOM PLL_SYS_DENOM; ///< Denominator of 528MHz System PLL fractional loop
                 unsigned           x064[3];
	}; // Analog
	static_assert(sizeof(Analog)==66*sizeof(unsigned), "Incorrect ARM::NXP::Clocks::Analog size"):

} // namespace ARM::NXP::Clocks

#endif // ARM_NXP_Clocks_Analog_hh
