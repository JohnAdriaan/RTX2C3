// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Stack.hh
///

#ifndef CRT_Stack_hh
#define CRT_Stack_hh

/// \namespace CRT::Stack
/// \headerfile /CRT.hh
/// Functions and variables to monitor the `Stack`
namespace CRT::Stack {

	/// Call `Stack::Fill()` during board initialisation
	void Fill();

	/// `Stack::Min()` reports the smallest that `Stack` ever reached
	unsigned Min();

} // namespace CRT::Stack

#endif // CRT_Stack_hh
