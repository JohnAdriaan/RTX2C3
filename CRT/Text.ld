/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/Text.ld
 *
 * Included by `CRT.ld` to define `SECTIONS` used for code
 */


SECTIONS
{

  /* Put code into FLASH */
  .text :
  {
    . = ALIGN(4);
    _Text = .;

    *(.text)    /* .text sections (code) */
    *(.text*)   /* .text* sections (code) */

	*(.init)    /* These are the code for static variable initialisation */
	*(.fini)    /* These are the code for static variable finalisation */

    . = ALIGN(4);

    _Text_End = .;     /* define global symbols at end of code */
  } >FLASH
  
} /* SECTIONS */
