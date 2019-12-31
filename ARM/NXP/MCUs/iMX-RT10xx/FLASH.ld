/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT10xx/FLASH.ld
 *
 * Included by main linker script to describe the common parts of the iMX RT10xx Flash.
 */

SECTIONS
{
  .FCB (ORIGIN(FLASH) + _FCB) :
  {
    KEEP(*(.FCB));
    . = ALIGN(16);

    FILL(0x5265736572766564); /* _Reserved */
  	. = _IVT - _FCB;
  } >FLASH
  
  .IVT (ORIGIN(FLASH) + _IVT) :
  {
    KEEP(*(.IVT));
    FILL(0x52737664);         /* "Rsvd" */
    . = ALIGN(16);

    FILL(0x5265736572766564); /* _Reserved */
  	. = _User_Data - _IVT;
  } >FLASH
  
  _User_Base = ABSOLUTE(.);

} /* SECTIONS */
