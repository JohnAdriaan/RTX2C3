// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/Bit/Band.hh
///

#ifndef General_Bit_Band_hh
#define General_Bit_Band_hh

/// \class Bit::Band<> Bit.hh <General/Bit.hh>
template <class    S,                    // The bitfield struct
		  int      Shift /*= 0*/,        // Shift within (sub)field (<0 for 1-based)
		  typename Index /*= unsigned*/> // Index type
class Bit::Band : public Field<S,unsigned,1,Shift,Index> {

private: // Enums

	enum {
		REGION = 0xF000'0000, ///< RAM or Peripheral?
		ALIAS  = 0x0200'0000, ///< Offset to BitBand Alias
		MASK   = 0x000F'FFFF  ///< Mask for BitBand significance
	}; // enum

private: // Methods

	inline unsigned &Bit(Index pos) {
		return *(unsigned *)(
					((unsigned)this & REGION) |
					ALIAS | (
						(
							(((unsigned)this & MASK) << 3) +
							SHIFT(pos)
						)*sizeof(unsigned)
					)
				);
	} // Bit(pos)

	inline unsigned &Bit(Index pos) volatile {
		return ((Band *)this)->Bit(pos);
	} // Bit(pos)

public: // Methods

	/// Isolate bit
	inline unsigned &operator[](Index pos) {
		return Bit(pos);
	} // operator[](pos)

	/// Isolate bit
	inline unsigned &operator[](Index pos) volatile {
		return Bit(pos);
	} // operator[](pos)

	/// Read from bit
	inline bit read(Index pos) const {
		return Bit(pos);
	} // Read(pos)

	/// Read from bit
	inline bit read(Index pos) const volatile {
		return Bit(pos);
	} // Read(pos)

	/// Toggle bit
	inline void Toggle(Index pos) {
		Bit(pos) ^= 0b1;
	} // Toggle(pos)

	/// Toggle bit
	inline void Toggle(Index pos) volatile {
		Bit(pos) ^= 0b1;
	} // Toggle(pos)

	/// Write to bit
	/// \returns NEW value
	inline bit write(Index pos, bit value) {
		return (Bit(pos) = value);
	} // Write(pos, value)

	/// Write to bit
	/// \returns NEW value
	inline bit write(Index pos, bit value) volatile {
		return (Bit(pos) = value);
	} // Write(pos, value)

protected: // Static methods

	using Field<S,unsigned,1,Shift,Index>::SHIFT;

}; // Bit::Band<S, Shift, Index>

#endif // General_Bit_Field_hh
