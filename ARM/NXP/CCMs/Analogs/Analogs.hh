// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs/Analogs.hh
///

#ifndef ARM_NXP_CCMs_Analogs_Analogs_hh
#define ARM_NXP_CCMs_Analogs_Analogs_hh

namespace ARM::NXP::CCMs {

	namespace Analogs {

		namespace PLLs {
		
		} // namespace PLLs
		
		struct PFD;

		struct Misc0;

		struct Misc1;

		struct Misc2;

		extern volatile PFD   pfd480;

		extern volatile PFD   pfd528;

		extern volatile Misc0 misc0;

		extern volatile Misc1 misc1;

		extern volatile Misc2 misc2;

	} // namespace Analogs

} // namespace ARM::NXP::CCMs

#endif // ARM_NXP_CCMs_Analogs_Analogs_hh
