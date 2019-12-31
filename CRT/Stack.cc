// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Stack.cc
///

#include "../CRT.hh"

// Linker variables
extern unsigned _Stack[];
extern unsigned _Stack_Top;

using namespace CRT;

static const Label stackLabel = { 'S','t','a','k' };

void Stack::Fill() {
	CRT::Fill(_Stack, &_Stack_Top-16, stackLabel.value); // Avoid stack contents
} // Stack::Fill()

unsigned Stack::Min() {
	unsigned count = 0;
	for (unsigned *ptr = _Stack; ptr<&_Stack_Top; ++ptr) {
		if (*ptr!=stackLabel.value) {
			break;
		} // if
		++count;
	} // for
	return count * sizeof(_Stack[0]);
} // Stack::Min()
