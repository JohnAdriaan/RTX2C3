/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/Stack.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for the stack.
 */

_Stack_Size = DEFINED(StackSize) ? StackSize : 0x0400;

SECTIONS
{

/* Note bottom of .Stack is end of .Heap */
  .Stack ORIGIN(SRAM) + LENGTH(SRAM) - _Stack_Size :
  {
    _Stack     = .;   /* Start of Stack */
    . = _Stack_Size;
    _Stack_Top = .;   /* Top of Stack */
  } >SRAM = 0xDEADBEEF /* This won't actually happen, since not in Flash */

} /* SECTIONS */
