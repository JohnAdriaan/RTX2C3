// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Rand.hh
///

#ifndef CRT_Rand_hh
#define CRT_Rand_hh

#define RAND_MAX 65'535

extern "C"
void srand(unsigned seed);

extern "C"
unsigned rand();

#endif // CRT_Rand_hh
