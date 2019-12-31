// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Array/Update.hh
///

#ifndef General_Bit_Array_Update_hh
#define General_Bit_Array_Update_hh

// \class Bit::Array::Update<> Bit.hh <General/Bit.hh>
template <class    S,                                    // The bitfield struct
		  typename E,                                    // Element to be accessed as
		  unsigned Width,                                // The width of (sub)fields (treat as array)
		  int      Shift /*= 0*/,                        // Shift within (sub)field (<0 for 1-based)
		  typename Index /*= unsigned*/,                 // Index type
		  unsigned Num   /*= 8*sizeof(unsigned)/Width*/, // Number of Fields per unsigned
		  unsigned Mask  /*= Mask(Width)*/>              // Mask to isolate (sub)field
class Bit::Array::Update : public Read<S,E,Width,Shift,Index,Num,Mask> {

private: // Proxy

	template <typename Update>
	class Proxy : private _Array_ {
	friend Update;
	private: // Constructor
		inline Proxy(Update &update, Index pos) :
			   update(update),
			   pos(pos) {
		} // Proxy(update, pos)
	public: // Methods
		/// \returns CURRENT value
		inline operator E() const {
			return update.read(pos);
		} // operator T()
		/// \returns OLD value
		inline E operator =(E value) { // @suppress("Missing reference return value in assignment operator")
			return update.update(pos, value);
		} // operator =(E)
	private: // Variables
		Update &update;
		Index pos;
	}; // Proxy<>

public: // Methods

	using Read<S,E,Width,Shift,Index,Num,Mask>::operator [];

	/// Isolate bitfield
	inline Proxy<Update> operator[](Index pos) {
		return Proxy<Update>(*this, pos);
	} // operator[](pos)

	/// Isolate bitfield
	inline Proxy<volatile Update> operator[](Index pos) volatile {
		return Proxy<volatile Update>(*this, pos);
	} // operator[](pos)

	/// Toggle field, maintaining all other bits
	inline void Toggle(Index pos) {
		((unsigned *)this)[INDEX(pos)] ^= Mask << SHIFT(pos);
	} // Toggle(pos)

	/// Toggle field, maintaining all other bits
	inline void Toggle(Index pos) volatile {
		((volatile unsigned *)this)[INDEX(pos)] ^= Mask << SHIFT(pos);
	} // Toggle(pos)

	/// Update value, maintaining all other bits.
	/// \returns OLD value
	inline E update(Index pos, E value);

	/// Update value, maintaining all other bits.
	/// \returns OLD value
	inline E update(Index pos, E value) volatile;

protected: // Static methods

	using Read<S,E,Width,Shift,Index,Num,Mask>::BITS;

	using Read<S,E,Width,Shift,Index,Num,Mask>::INDEX;

	using Read<S,E,Width,Shift,Index,Num,Mask>::SHIFT;

}; // Array::Update<S, E, Width, Shift, Index, Num, Mask>

template <class S, typename E, unsigned Width, int Shift, typename Index, unsigned Num, unsigned Mask>
inline E Bit::Array::Update<S,E,Width,Shift,Index,Num,Mask>::update(Index pos, E value) {
	unsigned index = INDEX(pos);
	unsigned shift = SHIFT(pos);
	unsigned old = ((unsigned *)this)[index];
	((unsigned *)this)[index] = ((old & ~(Mask << shift)) | (value << shift));
	return (E)((old >> shift) & Mask);
} // Update::update(pos, value)

template <class S, typename E, unsigned Width, int Shift, typename Index, unsigned Num, unsigned Mask>
inline E Bit::Array::Update<S,E,Width,Shift,Index,Num,Mask>::update(Index pos, E value) volatile {
	unsigned index = INDEX(pos);
	unsigned shift = SHIFT(pos);
	unsigned old = ((volatile unsigned *)this)[index];
	((volatile unsigned *)this)[index] = ((old & ~(Mask << shift)) | (value << shift));
	return (E)((old >> shift) & Mask);
} // Update::update(pos, value)

#endif // General_Bit_Array_Update_hh
