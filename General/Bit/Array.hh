// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Array.hh
///
/// \brief The `Bit::Array::Array<>` set of templates is similar to the `Bit::Field<>`
/// templates, in that they allow indexed accesses to bitfields as for arrays.
///
/// But instead of assuming that there's a single fundamental type underlying them,
/// they allow an array of them - and that array can even be discontinuous, as long
/// as the discontinuity is regular.
///
/// You can `Read()`, `Update()` or `Write()` fields by number rather than name,
/// using explicit function calls or the `[]` operator.
///
/// \namespace Bit::Array
/// There are four templates defined, all based (linearly) off `Array::Array<>`:
///
/// Template          | Description
/// -------:          | :----------
/// `Array::Array<>`  | Holds the basic definition, but has no (public) methods
/// `Array::Read<>`   | Adds `Read()` methods to `Bit::Array<>`
/// `Array::Update<>` | Adds `Update()` (Read/Modify/Write) methods to `Bit::Read<>`
/// `Array::Write<>`  | Adds `Write()` methods to `Bit::Update<>`, assuming that writing `0` has no effect

#ifndef General_Bit_Array_hh
#define General_Bit_Array_hh

/// \namespace Bit::Array
namespace Bit::Array {

	class _Array_ : private _Bit_ {
	}; // _Array_

	template <class    S,     // The bitfield struct
			  unsigned Width, // The width of (sub)fields (treat as array)
			  int      Shift, // Shift within (sub)field (<0 for 1-based)
			  typename Index, // Index type
			  unsigned Num>   // Number of Fields per unsigned
	class Array;

	template <class    S,                                // The bitfield struct
			  typename E,                                // Element to be accessed as
			  unsigned Width,                            // The width of (sub)fields (treat as array)
			  int      Shift = 0,                        // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,                 // Index type
			  unsigned Num   = 8*sizeof(unsigned)/Width, // Number of Fields per unsigned
			  unsigned Mask  = Mask(Width)>              // Mask to isolate (sub)field
	class Read;

	template <class    S,                                // The bitfield struct
			  typename E,                                // Element to be accessed as
			  unsigned Width,                            // The width of (sub)fields (treat as array)
			  int      Shift = 0,                        // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,                 // Index type
			  unsigned Num   = 8*sizeof(unsigned)/Width, // Number of Fields per unsigned
			  unsigned Mask  = Mask(Width)>              // Mask to isolate (sub)field
	class Update;

	template <class    S,                                // The bitfield struct
			  typename E,                                // Element to be accessed as
			  unsigned Width,                            // The width of (sub)fields (treat as array)
			  int      Shift = 0,                        // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,                 // Index type
			  unsigned Num   = 8*sizeof(unsigned)/Width, // Number of Fields per T
			  unsigned Mask  = Mask(Width)>              // Mask to isolate (sub)field
	class Write;

} // namespace Bit::Array

#include "Array/Array.hh"
#include "Array/Read.hh"
#include "Array/Update.hh"
#include "Array/Write.hh"

#endif // General_Bit_Array_hh
