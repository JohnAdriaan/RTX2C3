// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT.hh
///
/// The C/C++ RunTime is invoked by the compiler as needed, or as explicitly called
/// on by the code. To help make this code more compiler-agnostic, compiler-specific
/// services have been wrapped up here.
///

#ifndef CRT_hh
#define CRT_hh

#define WEAK          __attribute__((__weak__))          ///< Tell Linker this is a weak definition
#define USED          __attribute__((__used__))          ///< Tell Linker not to delete this
#define NAKED         __attribute__((__naked__))         ///< Tell Compiler not to emit prologue/epilogue code
#define UNUSED        __attribute__((__unused__))        ///< Tell Compiler this could be unreferenced
#define PACKED        __attribute__((__packed__))        ///< Tell Compiler to not insert padding
#define INTERRUPT     __attribute__((__interrupt__))     ///< Tell Compiler to use interrupt prologue/epilogue code
#define CONSTRUCTOR   __attribute__((__constructor__))   ///< Tell Compiler to add this function to init table
#define SECTION(name) __attribute__((__section__(name))) ///< Tell Compiler to tell Linker which SECTION to use

#ifndef   NDEBUG
#define assert(b) CRT::Assert(b, __FILE__, __LINE__)
#else // !NDEBUG
#define assert(b) if (not (b)) CRT::Asserted()
#endif // NDEBUG

#define OffsetOf(S, m) __builtin_offsetof(S, m)

extern "C"
unsigned strlen(const char *string);

/// \namespace CRT
/// This is used to scope CRT-specific identifiers into the `CRT` namespace.
///
/// Reference `#include` files below
namespace CRT {
} // namespace CRT

#include "CRT/CRT.hh"
#include "CRT/Heap.hh"
#include "CRT/Stack.hh"

#endif // CRT_hh
