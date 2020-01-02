// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/PLLs/PLLs.hh
///

#ifndef ARM_NXP_CCMs_Analogs_PLLs_PLLs_hh
#define ARM_NXP_CCMs_Analogs_PLLs_PLLs_hh

namespace ARM::NXP::CCMs::Analogs {

	namespace PLLs {

		/// Bypass sources for `BYPASS_CLK_SRC`
		enum Bypasses {
			REF_CLK_24M = 0b00
		}; // Bypasses

		/// Numerator of PLL fractional loop divider (note signed)
		struct Num {
			signed A : 30;
			signed   :  2;
			signed   :  0;
		}; // Num
		typedef Field<Num, signed> FieldNum;

		/// Denominator PLL fractional loop divider
		struct Denom {
			unsigned B : 30;
			unsigned   :  2;
			unsigned   :  0;
		}; // Denom
		typedef Field<Denom, unsigned> FieldDenom;

		struct USB;

		struct Sys;

		struct Audio;
		
		struct ENet;
		
		extern volatile USB   usb1;

		extern volatile Sys   sys;

		extern volatile Audio audio;

		extern volatile ENet  eNet;

	} // namespace PLLs

} // namespace ARM::NXP::CCMs::Analogs

#endif // ARM_NXP_CCMs_Analogs_PLLs_PLLs_hh
