// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Array/Array.hh
///

#ifndef General_Bit_Array_Array_hh
#define General_Bit_Array_Array_hh

// \class Bit::Array::Array<> Bit.hh <General/Bit.hh>
template <class    S,     // The bitfield struct
		  unsigned Width, // The width of (sub)fields (treat as array)
		  int      Shift, // Shift within (sub)field (<0 for 1-based)
		  typename Index, // Index type
		  unsigned Num>   // Number of Fields per unsigned
class Bit::Array::Array : public S { // By deriving off S, can still use bitfields

	static_assert((sizeof(S) % sizeof(unsigned))==0, "Invalid Array S parameter");

protected: // Static methods

	static constexpr inline unsigned BITS() {
		return 8 * sizeof(unsigned);
	} // BITS()

	static constexpr inline unsigned INDEX(Index pos) {
		return (unsigned)pos/Num*Width/Min(Width,BITS()/Num) + Shift/BITS();
	} // INDEX(pos)

	static constexpr inline unsigned SHIFT(Index pos) {
		return (((unsigned)pos*Min(Width,BITS()/Num)) % (Width*Num) + Shift) % BITS();
	} // SHIFT(pos)

}; // Array::Array<S, Width, Shift, Index, Num>

#endif // General_Bit_Array_Array_hh
