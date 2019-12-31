// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Start.cc
///

#include <CRT.hh>

#include <ARM/ISRs.hh>
#include <ARM/SCBs.hh>

#include "NXP.hh"

/// Entry point, so no prologue/epilogue required
NAKED
void ARM::NXP::Start() {
	// Initialise Vector Table Offset Register
	VTOR = &ARM::ISRs::vectors;

	// Initialise Stack Pointer
	asm("      ldr sp, %0" : : "m" (ARM::ISRs::vectors.stack) );

	CRT::Init();
	ARM::NXP::Init();
	CRT::Main();
	CRT::Done();

	// `main()` returned? Go to minimal power idle
	asm("      cpsid if\n" // Disable interrupts
		"Wait: wfi     \n" // Then wait for one
		"      b.n Wait"); // Forever
} // ARM::NXP::Start()
