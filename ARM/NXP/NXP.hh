// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/NXP.hh
///

#ifndef ARM_NXP_NXP_hh
#define ARM_NXP_NXP_hh

#include <ARM/ARM.hh>

namespace ARM {

	namespace NXP {

		namespace ISRs {
		} // namespace ISRs

		namespace Flash {
		} // namespace Flash

		namespace CCMs {
		} // namespace CCMs

		namespace XtalOscs {
		} // namespace XtalOscs

		namespace Timers {
		} // namespace Timers

		class _NXP_ : private _ARM_ {
		}; // _NXP_

		/// `NXP` entry point
		void Start();

		/// Board initialisation routine
		void Init();

	} // namespace NXP

} // namespace ARM

#endif // ARM_NXP_NXP_hh
