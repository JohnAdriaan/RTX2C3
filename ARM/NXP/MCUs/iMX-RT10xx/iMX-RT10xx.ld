/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/MCUs/iMX-RT10xx/iMX-10xx.ld
 *
 * Included by main linker script to describe the common parts of the iMX RT10xx series.
 */

_Reserved       = 0x5265736572766564;           /* Literally, "Reserved" */

_FCB            = 0x0400;                       /* Offset of Flash Configuration Block in Flash */
_IVT            = 0x1000;                       /* Offset of Image Vector Table in Flash */
_User_Data      = _IVT + 0x0400;                /* Beginning of User Data in Flash */
_ISR_Table      = _User_Data;                   /* Offset of Interrupt Service Routine Table in Flash */
												/* (Note VTOR requires 0x400-byte alignment) */
MEMORY
{
    ITCM         : ORIGIN = 0x00000000,  LENGTH = 32K          /* Instruction Tightly Coupled Memory */

    ROMCP        : ORIGIN = 0x00200000,  LENGTH = 64K          /* ROM Controller (with Patch) */
    
    DTCM         : ORIGIN = 0x20000000,  LENGTH = 32K          /* Data Tightly Coupled Memory */
	OCRAM        : ORIGIN = 0x20200000,  LENGTH = 128K         /* On-Chip RAM */

    SRAM   (!rx) : ORIGIN = 0x20000000,  LENGTH = 32K          /* Alias of DTCM */

    AIPS1        : ORIGIN = 0x40000000,  LENGTH = 1M           /* ARM IP Bus 1 */
    AIPS2        : ORIGIN = 0x40100000,  LENGTH = 1M           /* ARM IP Bus 2 */

    GPIO2        : ORIGIN = 0x42000000,  LENGTH = 32M          /* General Purpose Input/Output #2 */

    FLASH  (irx) : ORIGIN = _FLASH,      LENGTH = _FLASH_Size

    BOOT         : ORIGIN = _FLASH,      LENGTH = _FLASH_Size  /* Alias of FLASH */

    PPB          : ORIGIN = 0xE0000000,  LENGTH = 1M           /* Private Peripheral Bus */
    
} /* MEMORY */

/* Define the following before the default implementations in `ARM/ISRs/ISRs.ld` (in `ARM/ARM.ld`) */
INCLUDE ARM/NXP/MCUs/iMX-RT10xx/ISRs.ld

/* Define the following before any other FLASH-based symbols */
INCLUDE ARM/NXP/MCUs/iMX-RT10xx/FLASH.ld

/* Define the following before the default implementations in `ARM/ISRs/ISRs.ld` (in `ARM/ARM.ld`) */
INCLUDE ARM/NXP/NXP.ld

INCLUDE ARM/ARM.ld

INCLUDE CRT/CRT.ld

INCLUDE ARM/NXP/MCUs/iMX-RT10xx/SRAM.ld

INCLUDE ARM/NXP/MCUs/iMX-RT10xx/AIPS1.ld

INCLUDE ARM/NXP/MCUs/iMX-RT10xx/AIPS2.ld

INCLUDE ARM/NXP/MCUs/iMX-RT10xx/GPIO2.ld
