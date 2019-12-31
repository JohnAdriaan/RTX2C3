// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Rand.cc
///
/// This is straight out of K&R's "The C Programming Language", although that
/// implementation returns an `int`, so can only return up to 32'767.
/// The existing library implementation does a `malloc()`!

#include "Rand.hh"

static unsigned next = 1;

extern "C"
void srand(unsigned seed) {
    next = seed;
} // srand(seed)

extern "C"
unsigned rand() {
    next = next * 1'103'515'245u + 12'345u;
    return next >> 16;
} // rand()
