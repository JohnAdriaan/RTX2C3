/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/Heap.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for the heap.
 */

SECTIONS
{
  .Heap :
  {
    . = ALIGN(8);
    . += 4;           /* Mis-align heap to allow allocs to be ALIGN(8) */
    _Heap = .;        /* Beginning of _Heap */

	_Heap_End = ORIGIN(SRAM) + LENGTH(SRAM) - _Stack_Size;
  
  } >SRAM

} /* SECTIONS */

