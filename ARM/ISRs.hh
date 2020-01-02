// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/ISRs.hh
///

#ifndef ARM_ISRs_hh
#define ARM_ISRs_hh

#include "ARM.hh"

/// \namespace ARM::ISRs
/// ARM have defined a number of Interrupt Service Routines (ISRs).
/// These are their definitions.
///
/// Also defined are some "grouping" ISRs: default implementations for categories of
/// ISRs that can be easily overridden, either individually or en masse.
/// For example:
///
/// * `Default()` is set up as the ultimate handler for EVERY `ISR`.
/// * `Invalid()` is linked to undefined entries in the Interrupt Vector Table:
///   - By default, it's linked to `Default()`.
/// * `IRQ()` is linked to all the CPU-specific Interrupt ReQuests:
///   - By default, it's linked to `Default()`.
/// * Individual Exceptions, by default, are linked to `Default()`.
namespace ARM::ISRs {

	/// Generic ISR entry
	typedef void ISR();

	/// Default implementation used for every (defined) handler.
	/// Define this one to catch 'em all.
	/// Define specific ones individually
	void Default();

	/// Specified for architecturally undefined interrupts.
	/// By default, uses `Default()` above.
	/// Define this to catch these ones specifically
	void Invalid();

	/// Default implementation used for all IRQs.
	/// By default, uses `Default()` above.
	/// Define specific ones individually
	void IRQ();

	//
	// Exceptions
	//
	void Reset(); // Entered upon Reset

	void NMI();

	void HardFault();

	void MemManage();

	void BusFault();

	void UsageFault();

	void SVCall();

	void Debug();

	void PendSV();

	void SysTick();

	/// List of exceptions - in strict architecture order!
	struct Exceptions {
		ISR *reset        = &Reset;
		ISR *nmi          = &NMI;
		ISR *hardFault    = &HardFault;
		ISR *memManage    = &MemManage;
		ISR *busFault     = &BusFault;
		ISR *usageFault   = &UsageFault;
		ISR *exception6   = &Invalid;
		ISR *exception7   = &Invalid;
		ISR *exception8   = &Invalid;
		ISR *exception9   = &Invalid;
		ISR *svCall       = &SVCall;
		ISR *debug        = &Debug;
		ISR *exception12  = &Invalid;
		ISR *pendSV       = &PendSV;
		ISR *sysTick      = &SysTick;
	}; // Exceptions
	static_assert(sizeof(Exceptions)==sizeof(ISR*)*15, "Incorrect ARM::ISRs::Exceptions size");

	/// ISR Vector table
	struct Vectors {
		void       *stack;         ///< Top of stack
		Exceptions  exception;     ///< ARM exceptions
		ISR        *irq[NUM_IRQS]; ///< IRQs from NVIC
	}; // Vectors
	static_assert(sizeof(Vectors)==sizeof(void*)*(1+15+NUM_IRQS), "Incorrect ARM::ISRs::Vectors size");

	extern Vectors vectors;

} // namespace ARM::ISRs

#endif // ARM_ISRs_hh
