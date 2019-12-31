// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NXP/Security/OTFAD.cc
///
/// \brief On-The-Fly AES Decryption
///
/// The FlexSPI Flash can be encrypted with AES-128 Counter Mode, and yet
/// still decrypted on-the-fly with the OTFAD module. All that's needed is
/// the Key stored in a known place in the Flash.
///

#include <General/General.hh>

enum {
	OTFADKeySize = 0x100
}; // enum

struct Key {
	const char key[8] { 'O', 'T', 'F', 'A', 'D', 'K', 'e', 'y' };
}; // Key

/// OTFAD Key
SECTION(".OTFAD")
const Key OTFADKey[OTFADKeySize/sizeof(Key)] { };
