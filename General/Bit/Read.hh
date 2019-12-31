// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Read.hh
///

#ifndef General_Bit_Read_hh
#define General_Bit_Read_hh

// \class Bit::Read<> Bit.hh <General/Bit.hh>
template <class    S,                          // The bitfield struct
		  typename T,                          // The overlaid Plain Ol' Data type
		  unsigned Width,                      // The width of (sub)fields (treat as array)
		  int      Shift/* = 0*/,              // Shift within (sub)field (<0 for 1-based)
		  typename Index/* = unsigned*/,       // Index type
		  T        Mask /* = Mask<T>(Width)*/> // Mask to isolate (sub)field
class Bit::Read : public Field<S,T,Width,Shift,Index> {

public: // Methods

	/// Read field
	inline T operator[](Index pos) const {
		return read(pos);
	} // operator [](pos)

	/// Read field
	inline T operator[](Index pos) const volatile {
		return read(pos);
	} // operator [](pos)

	/// Read field
	inline T read(Index pos) const {
		return (*(T *)this >> SHIFT(pos)) & Mask;
	} // read(pos)

	/// Read field
	inline T read(Index pos) const volatile {
		return (*(T *)this >> SHIFT(pos)) & Mask;
	} // read(pos)

protected: // Static methods

	using Field<S,T,Width,Shift,Index>::SHIFT;

}; // Bit::Read<S, T, Width, Shift, Index, Mask>

#endif // General_Bit_Read_hh
