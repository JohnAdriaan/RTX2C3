// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Write.hh
///

#ifndef General_Bit_Write_hh
#define General_Bit_Write_hh

// \class Bit::Write<> Bit.hh <General/Bit.hh>
template <class    S,                          // The bitfield struct
		  typename T,                          // The overlaid Plain Ol' Data type
		  unsigned Width,                      // The width of (sub)fields (treat as array)
		  int      Shift /*= 0*/,              // Shift within (sub)field (<0 for 1-based)
		  typename Index /*= unsigned*/,       // Index type
		  T        Mask  /*= Mask<T>(Width)*/> // Mask to isolate (sub)field
class Bit::Write : public Update<S,T,Width,Shift,Index,Mask> {

private: // Proxy

	template <typename Write>
	class Proxy : private _Bit_ {
	friend Write;
	private: // Constructor
		inline Proxy(Write &write, Index pos) :
			   write(write),
			   pos(pos) {
		} // Proxy(write, pos)
	public: // Methods
		/// \returns CURRENT value
		inline operator T() const {
			return write.read(pos);
		} // operator T()
		/// \returns NEW value
		inline T operator =(T value) { // @suppress("Missing reference return value in assignment operator")
			return write.write(pos, value);
		} // operator =(T)
	private: // Variables
		Write &write;
		Index pos;
	}; // Proxy<>

public: // Methods

	using Read<S,T,Width,Shift,Index,Mask>::operator [];

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
	inline T write(Index pos, T value) {
		*(T *)this = (T)(value << SHIFT(pos));
		return value;
	} // write(pos, value)

	// Write to field (assumes writes of zero have no effect)
	// \returns NEW value
	inline T write(Index pos, T value) volatile {
		*(volatile T *)this = (T)(value << SHIFT(pos));
		return value;
	} // write(pos, value)

protected: // Static methods

	using Update<S,T,Width,Shift,Index,Mask>::SHIFT;

}; // Bit::Write<S, T, Width, Shift, Index, Mask>

#endif // General_Bit_Write_hh
