// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file CRT/Heap.cc
///

#include "../CRT.hh"

typedef unsigned short Size;
typedef unsigned short Index;

using namespace CRT;

struct Heap::Node : private _CRT_ {

#ifndef NDEBUG
	// When debugging, this value (and its NOT) is used to check for overflows.
	// On `Alloc()`, this value is placed both before and after the Node.
	// On `Free()`, those values are NOTted; a second `Free()` call will `assert()`.
	enum : Size { Canary = 0x5AA5 };

	Size  canary;    // Canary in a mineshaft
	Size  size;      // Number of Nodes in block - whether free or in use
	Label label;
#else // !NDEBUG
	union {
		Size size;   // Number of Nodes in block - whether free or in use
		Label label; // Take advantage of (necessary) padding bytes
	}; // union
#endif // NDEBUG
	union {
		Index next;    // On freeList: Next free block
		char  data[0]; // Otherwise  : The actual data
	}; // union
	static const unsigned Delta; // Delta between `data` and beginning of Node

}; // Heap::Node
const unsigned Heap::Node::Delta = OffsetOf(Node, data);

// Linker symbols
extern Heap::Node _Heap[];
extern char       _Heap_End; // `_Heap_End` may not be an integral number of `Nodes`

// Initialise variables - and the freeList in the heap (_Heap[0])
static const Size  HeapSize = (Size)((&_Heap_End-(char *)_Heap)/sizeof(Heap::Node));
static const Index null     = (_Heap[0].next = (Index)~0u); // Maximum size as end
static Size     numNodes    = (_Heap[0].size = HeapSize);
static Index    freeList    = 0;    // _Heap[0]
static Size     freeNodes   = 1;    // Start with one free Node - the whole heap!
static Size     allocs      = 0;    // Number of allocated blocks (rather than Nodes)
static unsigned fulls       = 0;    // Number of times `Alloc()` returned `nullptr`

bool Heap::full = false; // `true` on `Alloc()==nullptr`, `false` on any `Free()`

bool Heap::OnHeap(void *ptr) {
	return (_Heap < ptr) && (ptr < &_Heap_End);
} // Heap::OnHeap(ptr)

unsigned Heap::Used() {
	return (HeapSize - numNodes) * sizeof(Node);
} // Heap::Used()

unsigned Heap::Available() {
	return numNodes * sizeof(Node);
} // Heap::Available()

unsigned Heap::Fragmentation() {
	return freeNodes;
} // Heap::Fragmentation()

unsigned Heap::Allocs() {
	return allocs;
} // Heap::Allocs()

unsigned Heap::Fulls() {
	return fulls;
} // Heap::Fulls()

void *Heap::Alloc(const CRT::Label &label, unsigned size) {
	// Round size up to next multiple of sizeof(Node) - in Nodes.
	// Note that when debugging, a Canary is placed before _and_ after the block.
#ifndef NDEBUG
	size = (Node::Delta+size+sizeof(Node::Canary) + sizeof(Node)-1) / sizeof(Node);
#else // !NDEBUG
	size = (Node::Delta+size                      + sizeof(Node)-1) / sizeof(Node);
#endif // NDEBUG

	Node *ptr; // Save array indexing all the time
	// Look through freeList
	for (Index *index = &freeList;
		 *index<HeapSize;
		 index = &ptr->next) {
		ptr = &_Heap[*index];

		int space = ptr->size - size;
		// Too small to fit?
		if (space<0) {
			// Yes; keep looking
			continue;
		} // if

		// Found!
		++allocs;
		// Just big enough?
		if (space==0) {
			// Yes; return whole block
			*index = ptr->next;
			--freeNodes; // One less free Node
			assert(freeNodes < HeapSize/2); // Check for underflow
		} // if
		else {
			// No; too big! Carve `size` Nodes off end
			ptr->size = (Size)(ptr->size - size);
			ptr      += ptr->size;
		} // else
		// Used `size` more Nodes
		numNodes = (Size)(numNodes - size);
		assert(numNodes < HeapSize); // Check for underflow

#ifndef NDEBUG
		Size *end = (Size *)(ptr + size) - 1;
		ptr->canary = *end = Node::Canary;
#endif // NDEBUG
		ptr->label.value = label.value;
		ptr->size = (Size)size;

		return &ptr->data; // Return pointer to data
	} // for

	// No free blocks of required size
	++fulls;
	full = true;
	return nullptr;
} // Heap::Alloc(label, size)

void Heap::Free(void *ptr) {
	if (ptr==nullptr) {
		return;
	} // if
	assert(OnHeap(ptr)); // Sanity check `ptr`

	full = false;
	--allocs;
	// Point back to beginning of Node
	Node *freed = (Node *)((char *)ptr - Node::Delta);
	Index free = (Index)(freed - _Heap);

#ifndef NDEBUG
	Size *end = (Size *)(freed + freed->size) - 1;
	assert(freed->canary==Node::Canary);
	assert(*end==Node::Canary);
	freed->canary = *end = ~Node::Canary;
#endif // !NDEBUG

	// Give `size` Nodes back
	numNodes = (Size)(numNodes + freed->size);
	assert(numNodes <= HeapSize); // Check for overflow

	// Find where to insert `freed` - possibly merging with existing Nodes
	Index *index = &freeList;   // (Need `index` after `while`)
	while (*index<HeapSize) {
		Node &node = _Heap[*index]; // Save array indexing all the time
		// Get difference between end of `node` and `freed`
		int diff = (*index) + node.size - free;

		// Is `node` well before `freed`?
		if (diff<0) {
			// Yes; keep looking
			index = &node.next;
			continue;
		} // if

		// Is `node` immediately before `freed`?
		if (diff==0) {
			// Yes; merge `freed` into `node`, and back up
			node.size = (Size)(node.size + freed->size);
			freed = &node;
//			free = (Index)(freed - _Heap); // Not used again
		} // if
		else {
			// No; insert `freed` into list
			assert(*index >= free+freed->size); // First, check doesn't overlap
			freed->next = *index;
			*index = free;
			++freeNodes; // One more free Node
		} // else
		// `freed` is now on `freeList`

		// Is `freed` immediately before the next node?
		Node &next = _Heap[freed->next];
		if (freed + freed->size == &next) { // So `next` is not `null`
			// Yes; merge `next` into `freed`
			freed->size = (Size)(freed->size + next.size);
			freed->next = next.next;
			--freeNodes; // One less free Node - regardless of `diff`
			assert(freeNodes < HeapSize/2); // Check for underflow
		} // if
		return; // Everything's done!
	} // while

	// After every other node, so needs to be last node
	freed->next = null;
	*index = free;
	++freeNodes; // One more free Node
} // Heap::Free(ptr)

bool Heap::Walk(unsigned &pos, Label &label) {
	struct Pack {
		Index index;
		Index free;
	} &pack = *(Pack *)&pos;
	static_assert(sizeof(Pack)==sizeof(pos), "Incorrect Pack size");

	unsigned free = pack.index==0 ? // Start of `Walk`?
					freeList :      // Yes, so use `freeList`
					pack.free;
	unsigned node = pack.index;
	if (node==free) {
		node += _Heap[free].size;
	} // if
	if (node>=HeapSize) {
		return false;
	} // if
	if (free<node) {
		free = _Heap[free].next;
	} // if
#ifndef NDEBUG
	assert(_Heap[node].canary==Node::Canary);
#endif // !NDEBUG
	label.value = _Heap[node].label.value;
#ifndef NDEBUG
#else // !NDEBUG
	label.label[0] = label.label[1] = '?'; // Overwrite copied `size` in `union`
#endif // NDEBUG
	pack.free  = (Index)free;
	pack.index = (Index)(node + _Heap[node].size);
	return true;
} // Heap::Walk(pos, label)

extern const CRT::Label New0; // Don't define! That way, forces all `new`s to be Labelled

/// Default C++ `operator new()`.
/// Calls `Heap::Alloc()` with generic `Label`
void *operator new(unsigned size) {
	return Heap::Alloc(New0, size);
} // operator new(size)

/// Default C++ `operator new[]()`
/// Calls `Heap::Alloc()` with generic `Label`
void *operator new [](unsigned size) {
	return Heap::Alloc(New0, size);
} // operator new [](size)

void operator delete(void *ptr) {
	Heap::Free(ptr);
} // operator delete(ptr)

void operator delete(void *ptr, unsigned /*size*/) {
	Heap::Free(ptr);
} // operator delete(ptr, size)

void operator delete [](void *ptr) {
	Heap::Free(ptr);
} // operator delete [](ptr)

void operator delete [](void *ptr, unsigned /*size*/) {
	Heap::Free(ptr);
} // operator delete [](ptr, size)
