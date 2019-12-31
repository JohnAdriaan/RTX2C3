// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Init.cc
///

#include "../CRT.hh"

static inline void ZeroBSS() {
	extern unsigned _BSS[];
	extern unsigned _BSS_End;

	CRT::Fill(_BSS, &_BSS_End, 0);
} // ZeroBSS()

static inline void CopyData() {
	extern const unsigned _Data_Source[];
	extern       unsigned _Data[];
	extern       unsigned _Data_End;

	const unsigned *source = _Data_Source;
	unsigned *dest = _Data;
	while (dest < &_Data_End) {
		*dest++ = *source++;
	} // while
} // CopyData()

typedef void VoidFn();

static inline void CallConstructors() {
	extern VoidFn *_InitArray[];
	extern VoidFn *_InitArray_End;
	/// Call constructors in forward order
	for (VoidFn **fn = _InitArray; fn < &_InitArray_End; ++fn) {
		(*fn)();
	} // for
} // CallConstructors()

static inline void CallDestructors() {
	extern VoidFn *_FiniArray[];
	extern VoidFn *_FiniArray_End;
	/// Call destructors in reverse order
	for (VoidFn **fn = &_FiniArray_End-1; fn >= _FiniArray; --fn) {
		(*fn)();
	} // for
} // CallDestructors()

void CRT::Init() {
	ZeroBSS();          /// Zero uninitialised .data
	CRT::Stack::Fill(); /// Fill .Stack with tag to help debugging
	CopyData();         /// Copy initialised .data from .text
	CallConstructors(); /// Call all constructors
} // CRT::Init()

void CRT::Done() {
	CallDestructors();  /// Call all destructors
} // CRT::Done()
