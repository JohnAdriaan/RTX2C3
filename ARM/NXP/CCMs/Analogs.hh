// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/CCMs/Analogs.hh
///

#ifndef ARM_NXP_CCMs_Analogs_hh
#define ARM_NXP_CCMs_Analogs_hh

namespace ARM::NXP::CCMs {

	namespace Analogs {

		namespace PLLs {
		
			struct USB1;
			
			struct Sys;
			
			struct Audio;
			
			struct ENet;
			
			extern volatile USB1 usb1;

			extern volatile Sys sys;

			extern volatile Audio audio;

			extern volatile ENet eNet;

		} // namespace PLLs

		namespace PFDs {
		
		    struct PFD480;
		    
		    struct PFD528;
		    
		    extern volatile PFD480 pfd480;

		    extern volatile PFD528 pfd528;

		} // namespace PFDs

		struct Misc0;

		struct Misc1;

		struct Misc2;

		extern volatile Misc0 misc0;

		extern volatile Misc1 misc1;

		extern volatile Misc2 misc2;

	} // namespace Analogs

} // namespace ARM::NXP::CCMs

#endif // ARM_NXP_CCMs_Analogs_hh
