// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Array/Read.hh
///

#ifndef General_Bit_Array_Read_hh
#define General_Bit_Array_Read_hh

// \class Bit::Array::Read<> Bit.hh <General/Bit.hh>
template <class    S,                                    // The bitfield struct
		  typename E,                                    // Element to be accessed as
		  unsigned Width,                                // The width of (sub)fields (treat as array)
		  int      Shift /*= 0*/,                        // Shift within (sub)field (<0 for 1-based)
		  typename Index /*= unsigned*/,                 // Index type
		  unsigned Num   /*= 8*sizeof(unsigned)/Width*/, // Number of Fields per unsigned
		  unsigned Mask  /*= Mask(Width)*/>              // Mask to isolate (sub)field
class Bit::Array::Read : public Array<S,Width,Shift,Index,Num> {

public: // Methods

	/// Read field
	inline E operator[](Index pos) const {
		return read(pos);
	} // operator [](pos)

	/// Read field
	inline E operator[](Index pos) const volatile {
		return read(pos);
	} // operator [](pos)

	/// Read field
	inline E read(Index pos) const {
		return (E)((((unsigned *)this)[INDEX(pos)] >> SHIFT(pos)) & Mask);
	} // read(pos)

	/// Read field
	inline E read(Index pos) const volatile {
		return (E)((((volatile unsigned *)this)[INDEX(pos)] >> SHIFT(pos)) & Mask);
	} // read(pos)

protected: // Static methods

	using Array<S,Width,Shift,Index,Num>::BITS;

	using Array<S,Width,Shift,Index,Num>::INDEX;

	using Array<S,Width,Shift,Index,Num>::SHIFT;

}; // Array::Read<S, E, Width, Shift, Index, Num, Mask>

#endif // General_Bit_Array_Read_hh
