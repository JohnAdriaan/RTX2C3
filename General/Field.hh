// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Field.hh
///
/// \brief This template allows a bitfield structure, especially a volatile one,
/// to be treated in many ways like its underlying 8-, 16- or 32-bit value
///

#ifndef General_Field_hh
#define General_Field_hh

template <class S, typename T>
class Field : public S {

	static_assert(sizeof(S)==sizeof(T), "Invalid Field template parameters");

public: // Methods

	/// Allow read as `T`
	inline operator T() const;

	/// Allow read of `volatile` as `T`
	inline operator T() const volatile;

	inline Field &operator =(T value);

	inline void operator =(T value) volatile;

	inline Field &operator =(const S &value);

	inline void operator =(const S &value) volatile;

}; // Field

template <class S, typename T>
Field<S,T>::operator T() const {
	return *(T *)this;
} // Field::operator const T()

template <class S, typename T>
Field<S,T>::operator T() const volatile {
	return *(T *)this;
} // Field::operator const T() volatile

template <class S, typename T>
inline Field<S,T> &Field<S,T>::operator =(T value) {
	*(T *)this = value;
	return *this;
} // Field::operator =(T)

template <class S, typename T>
inline void Field<S,T>::operator =(T value) volatile { // @suppress("Missing reference return value in assignment operator")
	*(volatile T *)this = value;
} // Field::operator =(T) volatile

template <class S, typename T>
inline Field<S,T> &Field<S,T>::operator =(const S &value) {
	*(T *)this = *(T *)&value;
	return *this;
} // Field::operator =(S)

template <class S, typename T>
inline void Field<S,T>::operator =(const S &value) volatile { // @suppress("Missing reference return value in assignment operator")
	*(volatile T *)this = *(T *)&value;
} // Field::operator =(S) volatile

#endif // General_Field_hh
