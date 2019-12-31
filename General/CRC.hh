// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/CRC.hh
///

#ifndef General_CRC_hh
#define General_CRC_hh

#include "General.hh"

/// \namespace CRCs
/// Different CRC algorithms mostly just use different initial and final parameters.
/// The core algorithm is the same.
///
/// To calculate a CRC efficiently, first pre-generate a table with `Generate()`.
/// Then, to calculate the CRC for a block, start `crc` with the initial value.
/// Call `Calc()` repeatedly, assigning the result to `crc` until the whole block
/// has been processed.
namespace CRCs {

	class _CRC_ : private _General_ {
	}; // _CRC_

	template <typename T>
	class CRC : private _CRC_ {

	public: // Typedefs

		typedef T Table[256];

	public: // Static methods

		static void Generate(Table &table, T poly);

	public: // Constructor

		explicit CRC(const Table &table);

	public: // Methods

		T Calc(const byte *array, unsigned len, T crc);

		inline T Calc(const char *string, unsigned len, T crc);

	private: // Variables

		const Table &table;

	}; // CRC

	extern const CRC<word>::Table CCITT;

} // namespace CRCs

template <typename T>
void CRCs::CRC<T>::Generate(Table &table, T poly) {
	for (unsigned i=0;i<DIM(table);++i) {
		unsigned value = i;
		for (unsigned b=8;b>0;--b) {
			value = value & 0b1 ?
					(value>>1) ^ poly :
					(value>>1);
		} // for
		table[i] = (T)value;
	} // for
} // CRC::Generate(Table, poly)

template <typename T>
CRCs::CRC<T>::CRC(const Table &table) :
			  table(table) {
} // CRC::CRC(Table)

template <typename T>
T CRCs::CRC<T>::Calc(const byte *array, unsigned len, T crc) {
	while (len-->0) {
		crc = (T)((crc >> 8) ^ table[(crc ^ *array++) & 0xFF]);
	} // while
	return crc;
} // CRC::Calc(array, len, crc)

template <typename T>
inline T CRCs::CRC<T>::Calc(const char *string, unsigned len, T crc) {
	return Calc((const byte *)string, crc);
} // CRC::Calc(string, len, crc)

#endif // General_CRC_hh
