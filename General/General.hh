// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/General.hh
///

#ifndef General_General_hh
#define General_General_hh

#include <CRT.hh>

#define pure = 0  ///< Pure virtual functions can be declared leterally as such
#define implicit  ///< The opposite of `explicit`, to document intended usage

#define DIM(A)    (sizeof(A) / sizeof((A)[0]))    ///< Number of elements in array `A`
#define OFFSET(m) ((unsigned)&m - (unsigned)this) ///< Offset of `m` within `this`

typedef bool                bit;   ///< A single bit in a field
typedef unsigned char       byte;  ///< A traditional  8-bit unsigned number
typedef unsigned short      word;  ///< A traditional 16-bit unsigned number
typedef unsigned int        dword; ///< A traditional 32-bit unsigned number
typedef unsigned long long  qword; ///< A traditional 64-bit unsigned number
static_assert(sizeof( word)==2*sizeof( byte), "Incorrect word size");
static_assert(sizeof(dword)==2*sizeof( word), "Incorrect dword size");
static_assert(sizeof(qword)==2*sizeof(dword), "Incorrect qword size");

/// Other common names for `bool`'s `true` and `false`
enum Bits : bit {
	No  = false,
	Yes = true,

	Off = false,
	On  = true,

	Zero = false,
	One  = true,

	Low  = false,
	High = true,

	Down = false,
	Up   = true
}; // Bits

constexpr  byte Rsvd8  = 0xFF;                              /// 0xFF;
constexpr  word Rsvd16 = 0x7652;             /// "Rv"       /// 0xFFFF;
constexpr dword Rsvd32 = 0x64767352;         /// "Rsvd"     /// ~0u;
constexpr qword Rsvd64 = 0x6465767265736552; /// "Reserved" /// ~0ull;

/// The canonical `Min(left, right)`
template <typename T>
constexpr inline const T &Min(const T &l, const T &r) { return l<r ? l : r; }

/// The canonical `Max(left, right)`
template <typename T>
constexpr inline const T &Max(const T &l, const T &r) { return l>r ? l : r; }

/// A (right-justified) bit-mask with `width` bits
template <typename T>
constexpr inline T Mask(unsigned width) {
	return (T)((1 << width) - 1);
} // Mask<>(width)

/// Helper function for most common usage of above `Mask<>()`
constexpr inline unsigned Mask(unsigned width) {
	return Mask<unsigned>(width);
} // Mask(width)

/// This "basest" class is _purely_ for documentation purposes.
/// Classes deriving from this will do so `private`ly
/// ...and will often be for a similar purpose!
class _General_ {
}; // _General_

#endif // General_General_hh
