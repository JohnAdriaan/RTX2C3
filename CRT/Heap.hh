// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Heap.hh
///

#ifndef CRT_Heap_hh
#define CRT_Heap_hh

/// \namespace CRT::Heap
/// \headerfile /CRT.hh
/// Functions and variables to use and monitor the `Heap`
namespace CRT::Heap {

	class _Heap_ : private _CRT_ {
	}; // _Heap_

	/// `Node` stores metadata about `Alloc()`s (and free blocks)
	struct Node;

	/// Allocate `size` bytes on `Heap`, using `label` as a diagnostic.
	/// \returns `nullptr` if a block of sufficient size is not available
	void *Alloc(const Label &label, unsigned size);

	/// Free previously `Alloc()`ed `ptr`
	void Free(void *ptr);

	/// \return if `ptr`'s address is inside the `Heap`
	bool OnHeap(void *ptr);

	/// \return number of bytes used
	unsigned Used();

	/// \return number of bytes available - not necessarily contiguous!
	unsigned Available();

	/// \return number of separate blocks in Free list. If `0`, then definitely full!
	unsigned Fragmentation();

	/// \return number of `Alloc()`s minus number of `Free()`s
	unsigned Allocs();

	/// \return number of times `Alloc()` failed
	unsigned Fulls();

	/// "Walk" the used Heap. Pass in `pos` of `0` initially.
	/// \returns `false` when `Walk()` has ended.
	bool Walk(unsigned &pos, Label &label);

	/// Set `true` if `Alloc()` cannot fulfill a request.
	/// Set `false` on every `Free()`.
	extern bool full;

} // namespace CRT::Heap

inline void *operator new(unsigned size, const CRT::Label &label) {
	return CRT::Heap::Alloc(label, size);
} // operator new(size, label)

inline void *operator new [](unsigned size, const CRT::Label &label) {
	return CRT::Heap::Alloc(label, size);
} // operator new [](size, label)

#endif // CRT_Heap_hh
