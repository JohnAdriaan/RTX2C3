// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Debug.hh
///

#ifndef General_Debug_hh
#define General_Debug_hh

#include "General.hh"

/// \namespace Debug
/// To aid debugging, these classes are provided.
namespace Debug {

	// This accumulates number of changes to a value, and its `min` and `max`
	class MinMax;

	// This is used to generate an ASCII representation of a `struct` instance
	class Regs;

} // namespace Debug

#include "Debug/Number.hh"
#include "Debug/MinMax.hh"
#include "Debug/Regs.hh"

#ifdef EVIL

//inline constexpr void Return() { }
//#define return for (Return(); ;) return

//#define X0(n) do_something(A[n]);
//#define X1(n) X0(n) X0(n+1)
//#define X2(n) X1(n) X1(n+2)
//#define X3(n) X2(n) X2(n+4)
//#define X4(n) X3(n) X3(n+8)
//#define X5(n) X4(n) X4(n+16)
//#define X6(n) X5(n) X5(n+32)
//#define X7(n) X6(n) X6(n+64)
//#define X8(n) X7(n) X7(n+128)
//X8(0)

#endif // EVIL

#endif // General_Debug_hh
