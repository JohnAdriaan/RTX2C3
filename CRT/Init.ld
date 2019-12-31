/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/Init.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for initialisation
 * of C/C++ variables
 */

SECTIONS
{

  .init_array :
  {
    . = ALIGN(4);
    _InitArray = .;
    *(SORT(.init_array.*))
    *(.init_array*)
    _InitArray_End = .;
    . = ALIGN(4);
  } >FLASH
  
  .fini_array :
  {
    . = ALIGN(4);
    _FiniArray = .;
    *(SORT(.fini_array.*))
    *(.fini_array*)
    _FiniArray_End = .;
    . = ALIGN(4);
  } >FLASH

} /* SECTIONS */

