// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/CRT.hh
///

#ifndef CRT_CRT_hh
#define CRT_CRT_hh

/// \namespace CRT
/// \headerfile /CRT.hh
namespace CRT {

	/// Called when an `Assert()` fires - potentially repeatedly
	void Asserted();

	inline void Assert(bool b, const char * /*file*/, unsigned /*line*/) {
		while (not b) {
			Asserted();
		} // while
	} // Assert(b, file, line)

	class _CRT_ {
	}; // _CRT_

	/// Used to label memory
	union Label {
		char label[4];
		unsigned value;
	}; // Label

	/// Fill a `section` of memory with `value`
	void Fill(unsigned section[], unsigned *end, unsigned value);

	/// \return the passed-in `char`, with bytes swapped (effectively a no-op)
	inline char Swap(char value) {
		return value;
	} // Swap(char)

	/// \return the passed-in `byte`, with bytes swapped (effectively a no-op)
	inline unsigned char Swap(unsigned char value) {
		return value;
	} // Swap(unsigned char)

	/// \return the passed-in `short`, with bytes swapped
	inline short Swap(short value) {
		return __builtin_bswap16(value);
	} // Swap(short)

	/// \return the passed-in `word`, with bytes swapped
	inline unsigned short Swap(unsigned short value) {
		return __builtin_bswap16(value);
	} // Swap(unsigned short)

	/// \return the passed-in `int`, with bytes swapped
	inline int Swap(int value) {
		return __builtin_bswap32(value);
	} // Swap(int)

	/// \return the passed-in `unsigned`, with bytes swapped
	inline unsigned Swap(unsigned value) {
		return __builtin_bswap32(value);
	} // Swap(unsigned int)

	/// C/C++ Run Time `Init`
	void Init();

	/// Main executable
	int Main();

	/// C/C++ Run Time `Done`
	void Done();

	namespace Heap {
	} // namespace Heap

	namespace Stack {
	} // namespace Stack

} // namespace CRT

#endif // CRT_CRT_hh
