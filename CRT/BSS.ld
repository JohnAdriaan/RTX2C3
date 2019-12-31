/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/BSS.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for pre-zeroed data
 */

SECTIONS
{
  
  /* Put zeroed data here */
  .bss :
  {
    . = ALIGN(4);

    /* Used by _start() to initialize .bss */
   _BSS = .;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _BSS_End = .;
    _end     = .;     /* End of all data */
  } >SRAM
  
} /* SECTIONS */
