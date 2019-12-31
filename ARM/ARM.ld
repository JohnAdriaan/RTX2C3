/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/ARM.ld
 *
 * Included by main linker script to define SECTIONS used for ARM-specific purposes.
 * Also provides ISR handlers for all ISRs - including the default IRQ handlers
 */

/* Entry point ARM::ISRs::Reset() - not that it matters! */
ENTRY(_ZN3ARM4ISRs5ResetEv)

SECTIONS
{
  .ARM.attributes 0 : { *(.ARM.attributes) }
} /* SECTIONS */

INCLUDE ARM/ISRs/ISRs.ld

INCLUDE ARM/NVICs/NVIC.ld

INCLUDE ARM/PPB.ld
