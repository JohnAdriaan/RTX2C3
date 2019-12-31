/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/ROData.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for read-only data
 */

SECTIONS
{

  /* Put constant data into FLASH */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

} /* SECTIONS */
