// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file General/AtomicQueue.hh
///
/// \brief A Queue that can be accessed atomically.
///
/// ## Description:
///   This Queue is designed to be used between the main thread and an ISR. That is,
/// it is NOT designed for use between multiple threads. Thus, an `Add()` could be
/// interrupted by `Remove()`s, or vice versa, but not itself.
///
///   With many Queue implementations, the consumers de-queue the next item and then
/// use it. This single-consumer implementation prefers if the next item remains on
/// the queue while it is being used, and then de-queued when finished.
///
///   This has the decided advantage that `Add()` can advise whether there's already
/// something still on the Queue - so no need to e.g. initiate transmission.
///
/// ## Implementation:
///   Note that the `next` pointer within `NODE` needs to be passed in to the
/// constructor. It's probably called "next", so that is the default parameter.
/// If it is called something else, pass that in instead - and then it doesn't even
/// matter if `NODE` doesn't have a member called "next"!
///
///   Also note that `Add()` needs to know that the previous `last` is still at the
/// end of the Queue. _This_ Queue. Just having `nullptr` means that it might be at
/// the end of a _different_ Queue, thus it'd still get modified. To prevent that,
/// each Queue has its own, unique, end-of-queue marker called `null`, which, like
/// `nullptr`, never gets dereferenced. How is it unique? It's `this`!
/// <br />And for reference: if `next` is indeed `nullptr`, it's not on _any_ Queue.
///

#ifndef AtomicQueue_hh
#define AtomicQueue_hh

#include <atomic>

#include <General/General.hh>

class _AtomicQueue_ : private _General_ {
}; // _AtomicQueue_

/// A template for a Queue that can be accessed Atomically
template <class NODE>
class AtomicQueue : private _AtomicQueue_ {

public: // Enums, typedefs and classes

	enum Firsts : bool { NotFirst=false, First=true };

	typedef std::atomic<NODE *> Next;

public: // Methods

	/// Assumes `next` is called "next" - if it isn't, doesn't matter
	explicit AtomicQueue(Next NODE::*next=&NODE::next);

	/// Get the number of entries in the Queue
	inline unsigned Num() const;

	/// Get the current Head of the Queue - note could be `nullptr`
	inline NODE *Head() const;

	/// Add `node` to end of Queue - this will always succeed
	/// \returns Whether this is now the first `node` on Queue
	Firsts Add(NODE &node);

	/// Remove `node` - but only if currently `head`
	/// \returns `false` only if `node` is `nullptr`
	bool Remove(NODE *node);

private: // Variables

	Next NODE::* const next;

	Next head;

	Next tail;

	NODE *last;

	std::atomic<unsigned> num;

}; // AtomicQueue<>

// Only for this module
#define null   (NODE *)this               ///< Unique "nullptr" - never dereferenced!
#define Weak   compare_exchange_weak      ///< Sorry: I don't like the unwieldy name!
#define Strong compare_exchange_strong    ///< Sorry: I don't like the unwieldy name!

template <class NODE>
AtomicQueue<NODE>::AtomicQueue(Next NODE::*next) :
				   next(next),
				   head(null),
				   tail(null),
				   last(null),
				   num(0) {
} // AtomicQueue::AtomicQueue(next)

template <class NODE>
inline unsigned AtomicQueue<NODE>::Num() const {
	return num.load();
} // AtomicQueue::Num()

template <class NODE>
inline NODE *AtomicQueue<NODE>::Head() const {
	NODE *ptr = head.load();
	return ptr==null ?
		   nullptr :
		   ptr;
} // AtomicQueue::Head()

template <class NODE>
enum AtomicQueue<NODE>::Firsts AtomicQueue<NODE>::Add(NODE &node) {
	(node.*next).store(null);     // `node` is now mine! (This is whyfor `null`)
	++num;                        // One more `NODE`

	while (not tail.Weak(last, &node)) { // `tail` is a moving target...
	} // while

	NODE *expected = null;        // Since at `tail`, `last->next` should be `null`
	// Note `last`, if not `null`, cannot have yet been `Free()`ed.
	if ((last==null) ||                              // Already noticed it was empty?
		not (last->*next).Strong(expected, &node)) { // Or did `last` move just now?
		head.store(last = &node); // Yes, so queue is empty. Start again.
		return First;             // And return First
	} // if
	last = &node;                 // `node` is new `last`
	return NotFirst;
} // AtomicQueue::Add(node)

template <class NODE>
bool AtomicQueue<NODE>::Remove(NODE *node) {
	if (node==nullptr) {
		return false;
	} // if
	--num;                                   // One fewer `NODE`s
	NODE *temp = node;                       // (Don't modify `node`!)
	tail.Strong(temp, null);                 // Fix `tail` first - may get new `head`!
	temp = node;                             // (Don't modify `node`!)
	head.Strong(temp, (node->*next).load()); // `head` might now be `null`
	(node->*next).store(nullptr);            // `node` is no longer mine
	return true;
} // AtomicQueue::Remove(node)

#undef Strong
#undef Weak
#undef null

#endif // AtomicQueue_hh
