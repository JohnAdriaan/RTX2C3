// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Field.hh
///

#ifndef General_Bit_Field_hh
#define General_Bit_Field_hh

/// \class Bit::Field<> Bit.hh <General/Bit.hh>
template <class    S,     // The bitfield struct
		  typename T,     // The overlaid Plain Ol' Data type
		  unsigned Width, // The width of (sub)fields (treat as array)
		  int      Shift, // Shift within (sub)field (<0 for 1-based)
		  typename Index> // Index type
class Bit::Field : public ::Field<S, T> { // By deriving off S, can still use bitfields

	static_assert(sizeof(S)==sizeof(T), "Invalid Bit::Field template parameters");

protected: // Static methods

	static inline unsigned SHIFT(Index pos) {
		return (unsigned)pos * Width + Shift;
	} // SHIFT(pos)

}; // Bit::Field<S, T, Width, Shift, Index>

#endif // General_Bit_Field_hh
