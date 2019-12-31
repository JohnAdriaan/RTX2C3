/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/Data.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for pre-initialised data
 */

SECTIONS
{

  /* Put initialized data here. Note originally stored in FLASH, then AT> copied */
  .data : 
  {
    . = ALIGN(4);

    /* Used by _start() to initialize data */
    _Data_Source = LOADADDR(.data);
    _Data        = .;
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _Data_End    = .;
  } >SRAM AT> FLASH
  
} /* SECTIONS */
 