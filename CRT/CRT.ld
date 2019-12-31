/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file CRT/CRT.ld
 *
 * Included by main linker script to define `SECTIONS` used for C/C++ Run Time based mechanisms
 */

INCLUDE CRT/Text.ld

INCLUDE CRT/ROData.ld

INCLUDE CRT/Init.ld

INCLUDE CRT/Data.ld

INCLUDE CRT/BSS.ld

INCLUDE CRT/Heap.ld

INCLUDE CRT/Stack.ld
