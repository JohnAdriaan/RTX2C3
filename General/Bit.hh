// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit.hh
///
/// \brief The `Bit::Field<>` set of templates extends the `Field<>` template to allow
/// for indexed accesses to the bitfields, similar to an array.
///
/// You can `Read()`, `Update()` or `Write()` fields by number rather than name,
/// using explicit function calls or the `[]` operator.
///
/// \namespace Bit
/// There are five templates defined, all based (linearly) off `Bit::Field<>`:
///
/// Template       | Description
/// -------:       | :----------
/// `Bit::Field<>` | Holds the basic definition, but has no (public) methods
/// `Bit::Read<>`  | Adds `Read()` methods to `Bit::Field<>`
/// `Bit::Update<>`| Adds `Update()` (Read/Modify/Write) methods to `Bit::Read<>`
/// `Bit::Write<>` | Adds `Write()` methods to `Bit::Update<>`, assuming that writing `0` has no effect
/// `Bit::Band<>`  | Similar to `Bit::Write<>`, but using the BitBand region to access single bits atomically. Hence only suitable for `Width=1`
///
/// \namespace Bit::Array
/// There's also the `Bit::Array` sub-namespace, covered in `Bit/Array.hh`.

#ifndef General_Bit_hh
#define General_Bit_hh

#include "General.hh"
#include "Field.hh"

namespace Bit {

	/// This is used for documentation purposes _only_
	class _Bit_ : private _General_ {
	}; // _Bit_

	template <class    S,     // The bitfield struct
			  typename T,     // The overlaid Plain Ol' Data type
			  unsigned Width, // The width of (sub)fields (treat as array)
			  int      Shift, // Shift within (sub)field (<0 for 1-based)
			  typename Index> // Index type
	class Field;

	template <class    S,                      // The bitfield struct
			  typename T,                      // The overlaid Plain Ol' Data type
			  unsigned Width,                  // The width of (sub)fields (treat as array)
			  int      Shift = 0,              // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,       // Index type
			  T        Mask  = Mask<T>(Width)> // Mask to isolate (sub)field
	class Read;

	template <class    S,                      // The bitfield struct
			  typename T,                      // The overlaid Plain Ol' Data type
			  unsigned Width,                  // The width of (sub)fields (treat as array)
			  int      Shift = 0,              // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,       // Index type
			  T        Mask  = Mask<T>(Width)> // Mask to isolate (sub)field
	class Update;

	template <class    S,                      // The bitfield struct
			  typename T,                      // The overlaid Plain Ol' Data type
			  unsigned Width,                  // The width of (sub)fields (treat as array)
			  int      Shift = 0,              // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned,       // Index type
			  T        Mask  = Mask<T>(Width)> // Mask to isolate (sub)field
	class Write;

	template <class    S,                // The bitfield struct
			  int      Shift = 0,        // Shift within (sub)field (<0 for 1-based)
			  typename Index = unsigned> // Index type
	class Band;

	namespace Array {
	} // namespace Array

} // namespace Bit

#include "Bit/Field.hh"
#include "Bit/Read.hh"
#include "Bit/Update.hh"
#include "Bit/Write.hh"
#include "Bit/Band.hh"
#include "Bit/Array.hh"

#endif // General_Bit_hh
