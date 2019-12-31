/*
 * © 2019 John Adriaan. Licensed under the "3-clause BSD License"
 *
 * \file ARM/NXP/NXP.ld
 * 
 * Included by main linker script to PROVIDE (literally!) C++ implementations
 * for generic entry points.
 */

PROVIDE ( _ZN3ARM4ISRs5ResetEv = _ZN3ARM3NXP5StartEv ); /* ARM::ISRs::Reset() => ARM::NXP::Start() */
PROVIDE ( _ZN3CRT4MainEv       = main  );               /* CRT::Main()        => main()  */