// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Update.hh
///

#ifndef General_Bit_Update_hh
#define General_Bit_Update_hh

// \class Bit::Update<> Bit.hh <General/Bit.hh>
template <class    S,                          // The bitfield struct
		  typename T,                          // The overlaid Plain Ol' Data type
		  unsigned Width,                      // The width of (sub)fields (treat as array)
		  int      Shift/* = 0*/,              // Shift within (sub)field (<0 for 1-based)
		  typename Index/* = unsigned*/,       // Index type
		  T        Mask /* = Mask<T>(Width)*/> // Mask to isolate (sub)field
class Bit::Update : public Read<S,T,Width,Shift,Index,Mask> {

private: // Proxy

	template <typename Update>
	class Proxy : private _Bit_ {
	friend Update;
	private: // Constructor
		inline Proxy(Update &update, Index pos) :
			   update(update),
			   pos(pos) {
		} // Proxy(update, pos)
	public: // Methods
		/// \returns CURRENT value
		inline operator T() const {
			return update.read(pos);
		} // operator T()
		/// \returns OLD value
		inline T operator =(T value) { // @suppress("Missing reference return value in assignment operator")
			return update.update(pos, value);
		} // operator =(T)
	private: // Variables
		Update &update;
		Index pos;
	}; // Proxy<>

public: // Methods

	/// Allow assignment to whole fundamental type
	using ::Field<S,T>::operator =;

	using Read<S,T,Width,Shift,Index,Mask>::operator [];

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
		*(T *)this ^= Mask << SHIFT(pos);
	} // Toggle(pos)

	/// Toggle field, maintaining all other bits
	inline void Toggle(Index pos) volatile {
		*(volatile T *)this ^= Mask << SHIFT(pos);
	} // Toggle(pos)

	/// Update value, maintaining all other bits.
	/// \returns OLD value
	inline T update(Index pos, T value);

	/// Update value, maintaining all other bits.
	/// \returns OLD value
	inline T update(Index pos, T value) volatile;

protected: // Static methods

	using Read<S,T,Width,Shift,Index,Mask>::SHIFT;

}; // Bit::Update<S, T, Width, Shift, Index, Mask>

template <class S, typename T, unsigned Width, int Shift, typename Index, T Mask>
inline T Bit::Update<S, T, Width, Shift, Index, Mask>::update(Index pos, T value) {
	unsigned shift = SHIFT(pos);
	T old = *(T *)this;
	*(T *)this = (T)((old & ~(Mask << shift)) | (value << shift));
	return (old >> shift) & Mask;
} // Update::update(pos, value)

template <class S, typename T, unsigned Width, int Shift, typename Index, T Mask>
inline T Bit::Update<S, T, Width, Shift, Index, Mask>::update(Index pos, T value) volatile {
	unsigned shift = SHIFT(pos);
	T old = *(volatile T *)this;
	*(volatile T *)this = (T)((old & ~(Mask << shift)) | (value << shift));
	return (old >> shift) & Mask;
} // Update::update(pos, value)

#endif // General_Bit_Field_hh
