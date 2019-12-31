// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Array/Write.hh
///

#ifndef General_Bit_Array_Write_hh
#define General_Bit_Array_Write_hh

// \class Bit::Array::Write<> Bit.hh <General/Bit.hh>
template <class    S,                                    // The bitfield struct
		  typename E,                                    // Element to be accessed as
		  unsigned Width,                                // The width of (sub)fields (treat as array)
		  int      Shift /*= 0*/,                        // Shift within (sub)field (<0 for 1-based)
		  typename Index /*= unsigned*/,                 // Index type
		  unsigned Num   /*= 8*sizeof(unsigned)/Width*/, // Number of Fields per T
		  unsigned Mask  /*= Mask(Width)*/>              // Mask to isolate (sub)field
class Bit::Array::Write : public Update<S,E,Width,Shift,Index,Num,Mask> {

private: // Proxy

	template <typename Write>
	class Proxy : private _Array_ {
	friend Write;
	private: // Constructor
		inline Proxy(Write &write, Index pos) :
			   write(write),
			   pos(pos) {
		} // Proxy(write, pos)
	public: // Methods
		/// \returns CURRENT value
		inline operator E() const {
			return write.read(pos);
		} // operator T()
		/// \returns NEW value
		inline E operator =(E value) { // @suppress("Missing reference return value in assignment operator")
			return write.write(pos, value);
		} // operator =(E)
	private: // Variables
		Write &write;
		Index pos;
	}; // Proxy<>

public: // Methods

	using Read<S,E,Width,Shift,Index,Num,Mask>::operator [];

	/// Isolate bitfield
	inline Proxy<Write> operator[](Index pos) {
		return Proxy<Write>(*this, pos);
	} // operator[](pos)

	/// Isolate bitfield
	inline Proxy<volatile Write> operator[](Index pos) volatile {
		return Proxy<volatile Write>(*this, pos);
	} // operator[](pos)

	/// Write to field (assumes writes of zero have no effect)
	/// \returns NEW value
	inline E write(Index pos, E value) {
		((unsigned *)this)[INDEX(pos)] = (value << SHIFT(pos));
		return value;
	} // Write(pos, value)

	/// Write to field (assumes writes of zero have no effect)
	/// \returns NEW value
	inline E write(Index pos, E value) volatile {
		((volatile unsigned *)this)[INDEX(pos)] = (value << SHIFT(pos));
		return value;
	} // Write(pos, value)

protected: // Static methods

	using Update<S,E,Width,Shift,Index,Num,Mask>::BITS;

	using Update<S,E,Width,Shift,Index,Num,Mask>::INDEX;

	using Update<S,E,Width,Shift,Index,Num,Mask>::SHIFT;

}; // Array::Write<S, E, Width, Shift, Index, Num, Mask>

#endif // General_Bit_Array_Write_hh
