// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/SCBs/ACTLR.hh
///
/// This provides all the registers and definitions associated with the
/// ARM Auxiliary Control Register of the System Control Block
///

#ifndef ARM_SCBs_ACTLR_hh
#define ARM_SCBs_ACTLR_hh

#include <General/General.hh>
#include <General/Field.hh>

#include "../SCBs.hh"

namespace ARM {
namespace SCBs {

	/// Disable Issue Channel 1 bits
	struct DisIssCh1 {
		unsigned          : 20;
		unsigned direct   :  1; ///< Direct branches
		unsigned indirect :  1; ///< Indirect branches
		unsigned loadPC   :  1; ///< PC loads
		unsigned mulAcc   :  1; ///< Integer MUL and MulAcc
		unsigned vfp      :  1; ///< Vector Floating Point
		unsigned          :  7;
		unsigned          :  0;
	}; // DisIssCh1

	/// Disable Dual Issue
	struct DisDI {
		unsigned          : 15;
		unsigned direct   :  1; ///< Direct branches
		unsigned indirect :  1; ///< Indirect branches
		unsigned loadPC   :  1; ///< PC loads
		unsigned mulAcc   :  1; ///< Integer MUL and MulAcc
		unsigned vfp      :  1; ///< Vector Floating Point
		unsigned          : 12;
		unsigned          :  0;
	}; // DisDI

    /// Auxiliary Control Register
	union ACTLR {
		struct {
			unsigned                : 2;
			unsigned DISFOLD        : 1; ///< Disable If-Then (IT) Fold
			unsigned                : 7;
			unsigned FPEXCODIS      : 1; ///< Disable FPU exception outputs
			unsigned DISRAMODE      : 1; ///< Disable dynamic Read Allocate mode
			unsigned DISITMATBFLUSH : 1; ///< Disable ITM and DWT ATB flush (always On)
			unsigned DISBTACREAD    : 1; ///< Disable Branch Target Address Cache
			unsigned DISBTACALLOC   : 1; ///< Disable Alloc in Branch Target Address Cache
			unsigned DISCRITAXIRUR  : 1; ///< Disable Critical AXI read-under-read
			unsigned DISDI          : 5; ///< Disable Dual Issue
			unsigned DISISSCH1      : 5; ///< Disable Issue Channel 1
			unsigned DISDYNADD      : 1; ///< Disable dynamic allocation of ADD and SUB instructions
			unsigned DISCRITAXIRUW  : 1; ///< Disable Critical AXI read-under-write
			unsigned DISFPUISSOPT   : 1; ///< "0=Normal operation"
			unsigned                : 3;
			unsigned                : 0;
		}; // struct
		DisDI     disDI;                 ///< Access `DISDI` bits through this sub-variable
		DisIssCh1 disIssCh1;             ///< Access `DISISSCH1` bits through this sub-variable
	}; // ACTLR
	static_assert(sizeof(ACTLR)==sizeof(unsigned), "Incorrect ARM::SCBs::ACTLR size");

} // namespace SCBs
} // namespace ARM

static volatile ARM::SCBs::ACTLR &ACTLR = ARM::SCBs::actlr;

#endif // ARM_SCBs_ACTLR_hh
