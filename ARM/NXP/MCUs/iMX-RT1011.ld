/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT1011.ld
 *
 * Main linker script for the iMX RT1011 MCU.
 */

_FLASH      = 0x60000000; /* Start of Flash on this board */
_FLASH_Size = 16M;        /* Size of Flash on this board */

/* Include i.MX RT10xx generic definitions */
INCLUDE ARM/NXP/MCUs/iMX-RT10xx/iMX-RT10xx.ld

/* OTFAD is not offered on the whole RT10xx range */
_OTFAD_Key  = 0x0000;        /* On-The-Fly AES Decryption Key offset */

SECTIONS
{
  .OTFAD (ORIGIN(FLASH) + _OTFAD_Key) :
  {
    KEEP(*(.OTFAD));
    . = ALIGN(16);
    
    FILL(0x5265736572766564); /* _Reserved */
    . = _FCB - _OTFAD_Key;
  } >FLASH

} /* SECTIONS */
