/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/ISRs.ld
 *
 * Included by `ARM/ARM.ld` linker script to:
 * - Indicate where the ISR Vector Table needs to go
 * - PROVIDE (literally!) default implementations for all ARM-based ISRs.
 */

/*
 * Function name mangling is of the form:
 * "_Z" : Mangled name
 * "N"  : (optional) Nested (used for namespace or sub-definitions)
 * <#>  : Number of characters
 * <$>  : String
 * [#$] : (if Nested) More of the same
 * "E"  : (if Nested) End of Nesting
 * "v"  : void parameters 
 */

SECTIONS
{
  .ISR_Vectors (ORIGIN(FLASH) + _ISR_Table) :
  {
    KEEP(*(.ISR_Vectors));
  } >FLASH

} /* SECTIONS */

/* Default `ARM::ISRs::Invalid()` to `ARM::ISRs::Default()` */
PROVIDE ( _ZN3ARM4ISRs7InvalidEv = _ZN3ARM4ISRs7DefaultEv );

/* Default all ISRs to `ARM::ISRs::Default()` */
PROVIDE ( _ZN3ARM4ISRs5ResetEv       = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::Reset() */
PROVIDE ( _ZN3ARM4ISRs3NMIEv         = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::NMI() */
PROVIDE ( _ZN3ARM4ISRs9HardFaultEv   = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::HardFault() */
PROVIDE ( _ZN3ARM4ISRs9MemManageEv   = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::MemManage() */
PROVIDE ( _ZN3ARM4ISRs8BusFaultEv    = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::BusFault() */
PROVIDE ( _ZN3ARM4ISRs10UsageFaultEv = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::UsageFault() */
PROVIDE ( _ZN3ARM4ISRs6SVCallEv      = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::SVCall() */
PROVIDE ( _ZN3ARM4ISRs5DebugEv       = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::Debug() */
PROVIDE ( _ZN3ARM4ISRs6PendSVEv      = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::PendSV() */
PROVIDE ( _ZN3ARM4ISRs7SysTickEv     = _ZN3ARM4ISRs7DefaultEv ); /* ARM::ISRs::SysTick() */
