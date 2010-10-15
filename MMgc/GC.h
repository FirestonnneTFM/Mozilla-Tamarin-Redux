/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *   leon.sha@sun.com
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __GC__
#define __GC__

#define MMGC_GCENTER(_gc)  MMgc::GCAutoEnter __mmgc_auto_enter(_gc);

// MMGC_GC_ROOT_THREAD is obsolete; the mechanism is not safe.
//
// Instead you must use a pattern like this:
//
//    gc->CreateRootFromCurrentStack(fn, arg)
//
// where 'fn' takes a single void* and will be passed 'arg'.  While 'fn' is active the
// stack and registers active at the time CreateRootFromCurrentStack was called will
// be a GC root.

// Enable our own alloca() replacement that always allocates in the heap, this is good on
// systems with limited memory or limited stack
#define AVMPLUS_PARAM_ALLOCA_CUTOFF     4000    // Don't make real alloca() blow the stack; this limit is heuristic
#define AVMPLUS_PARAM_ALLOCA_DEFSIZE    1000    // Default number of bytes in a stack segment for heap-based alloca()
#ifdef AVMPLUS_HEAP_ALLOCA
#  define VMPI_alloca(core, autoptr, nbytes)    core->gc->allocaPush(nbytes, autoptr)
#  define VMPI_alloca_gc(gc, autoptr, nbytes)   gc->allocaPush(nbytes, autoptr)
#else
#  define VMPI_alloca(core, autoptr, nbytes)  (nbytes > AVMPLUS_PARAM_ALLOCA_CUTOFF ? core->gc->allocaPush(nbytes, autoptr) : alloca(nbytes))
#  define VMPI_alloca_gc(gc, autoptr, nbytes)  (nbytes > AVMPLUS_PARAM_ALLOCA_CUTOFF ? gc->allocaPush(nbytes, autoptr) : alloca(nbytes))
#endif

namespace avmplus
{
    class AvmCore;
#ifdef VMCFG_SELFTEST
    class ST_mmgc_basics;
#endif
}

namespace MMgc
{
    class GCAutoEnter;

    /**
     * GCRoot is root in the reachability graph, it contains a pointer a size
     * and will be searched for things.
     */
    class GCRoot
    {
        friend class GC;
#ifdef VMCFG_SELFTEST
        friend class avmplus::ST_mmgc_basics;
#endif
        GCRoot();
        void init(GC*gc, const void *object, size_t size);
    public:
        /** subclassing constructor */
        GCRoot(GC *gc);
        /** general constructor */
        GCRoot(GC *gc, const void *object, size_t size);
        virtual ~GCRoot();

        // override new and delete so we can know the objects extents (via FixedMalloc::Size())
        void *operator new(size_t size);

        void operator delete (void *object);

        const void *Get() const { return object; }
        const void *End() const { return (char*)object + size; }
        void Set(const void *object, size_t size);

        GC *GetGC() const { return gc; }
        /** if your object goes away after the GC is deleted this can be useful */
        void Destroy();

    private:
        GC * gc;

        GCRoot *next;
        GCRoot *prev;
        const void *object;
        size_t size;
        GCWorkItem *markStackSentinel;

        GCWorkItem GetWorkItem() const;

        GCWorkItem *GetMarkStackSentinelPointer();

        // SetMarkStackSentinelPointer stores the pointer and clears
        // the existing one if it exists.  Since all the roots are
        // pushed in StartIncrementalMark and FinishIncrementalMark
        // the root can be on the stack twice.
        void SetMarkStackSentinelPointer(GCWorkItem *wi);

        // ClearMarkStackSentinelPointer just sets the pointer to
        // NULL, use SetMarkStackSentinelPointer(NULL) to also clear
        // the work item off the mark stack.
        void ClearMarkStackSentinelPointer();
    };

    /**
     * GCCallback is an interface that allows the application to get
     * callbacks at interesting GC points.
     */
    class GCCallback
    {
        friend class GC;
        friend class ZCT;
    public:
        GCCallback(GC *gc);
        virtual ~GCCallback();

        GC *GetGC() const { return gc; }
        /** if your object goes away after the GC is deleted this can be useful */
        void Destroy();

        /**
         * This method is invoked after all marking and before any
         * sweeping, useful for bookkeeping based on whether things
         * got marked
         */
        virtual void presweep();

        /**
         * This method is invoked after all sweeping
         */
        virtual void postsweep();

        // called before a ZCT reap begins
        virtual void prereap();

        // called after a ZCT reap completes
        virtual void postreap();

        /**
         * This method is called before an RC object is reaped
         */
        virtual void prereap(void* /*rcobj*/);

    private:
        GC *gc;
        GCCallback *nextCB;
        GCCallback *prevCB;
    };

    #ifdef MMGC_64BIT
    #define HIDDENPTRMASK (uintptr_t(0x1L)<<63)
    #else
    #define HIDDENPTRMASK (uintptr_t(0x1L)<<31)
    #endif

    template <class T>
    class GCHiddenPointer
    {
    public:
        GCHiddenPointer(T obj=NULL) { set(obj); }
        operator T() const { return (T) (val^HIDDENPTRMASK);     }
        T operator=(T tNew)
        {
            set(tNew);
            return (T)this;
        }
        T operator->() const { return (T) (val^HIDDENPTRMASK); }

    private:
        // private to prevent its use and someone adding it, GCC creates
        // WriteBarrier's on the stack with it
        GCHiddenPointer(const GCHiddenPointer<T>& toCopy) { GCAssert(false); }

        void set(T obj)
        {
            uintptr_t p = (uintptr_t)obj;
            val = p ^ HIDDENPTRMASK;
        }
        uintptr_t val;
    };

    /**
     * This is a general-purpose garbage collector used by the Flash Player.
     * Application code must implement the GCRoot interface to mark all
     * reachable data.  Unreachable data is automatically destroyed.
     * Objects may optionally be finalized by subclassing the GCObject
     * interface.
     *
     * This garbage collector is intended to be modular, such that
     * it can be used in other products or replaced with a different
     * collector in the future.
     *
     * Memory allocation and garbage collection strategy:
     * Mark and sweep garbage collector using fixed size classes
     * implemented by the GCAlloc class.  Memory blocks are obtained
     * from the OS via the GCHeap heap manager class.
     *
     * When an allocation fails because a suitable memory block is
     * not available, the garbage collector decides either to garbage
     * collect to free up space, or to expand the heap.  The heuristic
     * used to make the decision to collect or expand is taken from the
     * Boehm-Demers-Weiser (BDW) garbage collector and memory allocator.
     * The BDW algorithm is (pseudo-code):
     *
     *    if (allocs since collect >= heap size / FSD)
     *      collect
     *    else
     *      expand(request size + heap size / FSD)
     *
     * The FSD is the "Free Space Divisor."  For the first cut, I'm trying
     * 4.  TODO: Try various FSD values against real Player workloads
     * to find the optimum value.
     *
     */
    class GC : public OOMCallback
    {
        friend class GCRoot;
        friend class GCHeap;
        friend class GCCallback;
        friend class GCAlloc;
        friend class GCLargeAlloc;
        friend class GCMarkStack;
        friend class GCWeakRef;
        friend class RCObject;
        friend class ZCT;
        friend class AutoRCRootSegment;
        friend class GCPolicyManager;
#ifdef VMCFG_SELFTEST
        friend class avmplus::ST_mmgc_basics;
#endif
    public:

        /**
         * If you need context vars use this!
         * FIXME: document context variables.
         */
        enum
        {
            GCV_COREPLAYER,
            GCV_AVMCORE,
            GCV_COUNT
        };

        void *GetGCContextVariable(int var) const;

        void SetGCContextVariable(int var, void *val);

        /**
         * @return the AvmCore instance associated with this GC.
         */
        avmplus::AvmCore *core() const;

        /**
        * Convenience to access the GC instance associated with the current
        * execution context.
        */
       static GC* current();

       /**
        * Convenience to access the GC instance associated with the current
        * execution context.
        */
       static GC* GetActiveGC();

       /**
         * greedy is a debugging flag.  When set, every allocation will cause
         * a garbage collection.  This makes code run abysmally slow, but can
         * be useful for detecting mark bugs or computing true peak live size.
         * (The flag is effective in both debug and release builds.)
         */
        const bool greedy;

        /**
         * nogc is a debugging flag.  When set, garbage collection never happens.
         * (The flag is effective in both debug and release builds.)
         */
        const bool nogc;

        /**
         * incremental controls the behavior of the garbage collection.  If true,
         * collection is incremental (and pause times are more or less controlled);
         * if false, collection is stop-the-world.
         */
        const bool incremental;

        /**
         * findUnmarkedPointers is a debugging flag.  If true, the GC will scan the
         * heap at the end of garbage collection, asserting that every word that
         * looks like it conservatively points to an object points to an object that
         * was marked by the collector.  The flag is available in release builds but
         * effective in debug builds only.)
         */
        bool findUnmarkedPointers;

        /**
         * validateDefRef is a debugging flag.  It turns on code that does a
         * trace before reaping zero count object and asserting on any objects
         * that get marked.  Significant space cost.  (The flag is available
         * in release builds but effective in debug builds only.)
         */
        bool validateDefRef;

        /**
         * keepDRCHistory is a debugging flag.  It turns on code that keeps the call
         * stacks of all IncrementRef and DecrementRef operations on each RC object,
         * and prints this history when the reference count is already zero
         * on entry to DecrementRef.  Significant space cost.  (The flag is available
         * in release builds but effective in debug builds only.)
         */
        bool keepDRCHistory;

        bool dontAddToZCTDuringCollection;
        bool incrementalValidation;

#ifdef _DEBUG
        bool incrementalValidationPedantic;
#endif

        /**
         * Garbage collection mode.  The GC is configured at creation in one of
         * these (it would be pointlessly hairy to allow the mode to be changed
         * at run-time).
         */
        enum GCMode
        {
            kDisableGC=1,       // never collect
            kGreedyGC,          // stop-the-world collection at every allocation
            kIncrementalGC,     // incremental collection
            kNonincrementalGC   // nonincremental collection
        };

        GC(GCHeap *heap, GCMode mode);

        virtual ~GC();

        /**
         * Causes an immediate stop-the-world garbage collection (or finishes any
         * incremental collection underway).
         */
        void Collect(bool scanStack=true);

        /**
         * Do a full collection at the next MMGC_GCENTER macro site
         */
        void QueueCollection();

        /**
         * flags to be passed as second argument to alloc
         */
        enum AllocFlags
        {
            kZero=1,
            kContainsPointers=2,
            kFinalize=4,
            kRCObject=8,
            kCanFail=16
        };

        /**
         * Main interface for allocating memory.  Default flags are
         * no finalization, not containing pointers, not zero'd, and not ref-counted.
         *
         * This function returns NULL only if kCanFail is passed in 'flags'.
         * Note that kContainsPointers implies kZero, pointer containing memory is
         * always zeroed (see bug 594533).
         */
        void *Alloc(size_t size, int flags=0);

        /**
         * Specialized implementations of Alloc().  Flags are omitted, each function is annotated
         * with the flags they assume.   Additionally, 'size' is usually known statically in the
         * calling context (typically a 'new' operator).  Finally, these are always inlined.
         * The result is that most computation boils away and we're left with just a call to the
         * underlying primitive operator.
         */
        void *AllocPtrZero(size_t size);            // Flags: GC::kContainsPointers|GC::kZero
        void *AllocPtrZeroFinalized(size_t size);   // Flags: GC::kContainsPointers|GC::kZero|GC::kFinalize
        void *AllocRCObject(size_t size);           // Flags: GC::kContainsPointers|GC::kZero|GC::kRCObject|GC::kFinalize

        /**
         * Like Alloc but optimized for the case of allocating one 8-byte non-pointer-containing
         * non-finalizable non-rc non-zeroed object (a box for an IEEE double).
         */
        void* AllocDouble();

        /**
         * Like Alloc but allocating a little extra memory; factored out as a
         * separate function in order to allow for a fast object overflow check.
         */
        void *AllocExtra(size_t size, size_t extra, int flags=0);

        /**
         * Specialized implementations of Alloc().  See above for explanations.
         */
        void *AllocExtraPtrZero(size_t size, size_t extra);             // Flags: GC::kContainsPointers|GC::kZero
        void *AllocExtraPtrZeroFinalized(size_t size, size_t extra);    // Flags: GC::kContainsPointers|GC::kZero|GC::kFinalize
        void *AllocExtraRCObject(size_t size, size_t extra);            // Flags: GC::kContainsPointers|GC::kZero|GC::kRCObject|GC::kFinalize

        /**
         * Out-of-line version of AllocExtra, used by the specialized versions
         */
        void *OutOfLineAllocExtra(size_t size, size_t extra, int flags);

        /**
         * Just like Alloc but can return NULL
         */
        void *PleaseAlloc(size_t size, int flags=0);

        /**
         * Signal that client code has performed an allocation from memory known not to be
         * controlled by this GC, and wants this memory accounted for because its lifetime
         * is tied to objects that this GC controls.  (A typical case is when fixed or system
         * memory is tied to a host object, eg BitmapData in Flash Player.)
         *
         * The GC may use this information to drive garbage collection, and may perform
         * GC activity during this call.
         */
        void SignalDependentAllocation(size_t nbytes);

        /**
         * Signal that client code has performed a deallocation of memory known not to be
         * controlled by this GC, and wants this memory accounted for.
         *
         * The GC may use this information to drive garbage collection, and may perform
         * GC activity during this call.
         *
         * It is crucial that SignalDependentDeallocation is called only to account for
         * objects previously accounted for by SignalDependentAllocation, and that it is
         * called for all objects accounted for by SignalDependentAllocation as those
         * objects are being destroyed.  The GC verifies neither of those conditions.
         *
         * @see SignalDependentAllocation
         */
        void SignalDependentDeallocation(size_t nbytes);

        /**
         * Replacement for VMPI_memmove for arrays of GC pointers that
         * will properly account for mark state (since the GC now
         * splits up large objects on the mark stack a memmove from the mutator
         * can occur while an objection is partially marked).  Start must be
         * a GC object and src and dst must be pointers in start.
         */
        void movePointers(void **dstArray, uint32_t dstOffset, const void **srcArray, uint32_t srcOffset, size_t numPointers);

        /**
         * Optimized version for moving within a single block of memory. Note that the 
         * offsets are in bytes, not in void* indices, to allow for an array that is
         * offset from the start of a block. If zeroEmptied is true, then the area "moved out of"
         * will be zeroed (generally a good idea, to avoid phantom GC references or possible RC naughtiness)
         */
        void movePointersWithinBlock(void** array, uint32_t dstOffsetInBytes, uint32_t srcOffsetInBytes, size_t numPointers, bool zeroEmptied = true);

    private:
        /**
         * Signal that we've allocated some memory and that collection can be triggered
         * if necessary.
         */
        void SignalAllocWork(size_t size);

        /**
         * Signal that we've freed some memory.  This should not have any side effects,
         * ie, it should not trigger collection.
         */
        void SignalFreeWork(size_t size);

        const static size_t kLargestAlloc = 1968;

        // See comments for HandleLargeMarkItem.
        const static size_t kMarkItemSplitThreshold = kLargestAlloc;

        class RCRootSegment : public GCRoot
        {
        public:
            RCRootSegment(GC* gc, void* mem, size_t size);
            void*           mem;
            size_t          size;
            RCRootSegment*  prev;
            RCRootSegment*  next;
        };

        RCRootSegment* rcRootSegments;

        void AddRCRootSegment(RCRootSegment *segment);

        void RemoveRCRootSegment(RCRootSegment *segment);

    public:

        class AutoRCRootSegment : public RCRootSegment
        {
        public:
            AutoRCRootSegment(GC* gc, void* mem, size_t size);
            ~AutoRCRootSegment();
        };


        /**
         * Allocate memory that will be scanned for pointers to GC memory
         * and from which pointers to RC objects will pin those objects.
         */
        void* AllocRCRoot(size_t size);

        /**
         * Free memory allocated with AllocRCRoot.
         */
        void FreeRCRoot(void* mem);

        /**
         * Save the processor context on the stack, make a GC root from the stack, and call 'fn'
         * with 'arg' as the only argument.  The GC root is active during the invocation of 'fn'.
         *
         * There are two main uses for this:
         *
         * 1) the main thread is halting to let another thread run doing
         *    possible GC activity (debugger use case)
         *
         * 2) the stack is moving to another area of memory (stack switching)
         *    but the old stack must still get scanned
         */
        void CreateRootFromCurrentStack(void (*fn)(void* arg), void* arg);

        /**
         * overflow checking way to call Alloc for a # of n size'd items,
         * all instance of Alloc(num*sizeof(thing)) should be replaced with:
         * Calloc(num, sizeof(thing))
         */
        void *Calloc(size_t num, size_t elsize, int flags=0);

        /**
         * One can free a GC allocated pointer.  The pointer may be NULL.
         */
        void Free(const void *ptr);

        /**
         * One can free a GC allocated pointer.  The pointer must not be NULL.
         */
        void FreeNotNull(const void *ptr);

        /**
         * @return the size of a managed object given a user or real pointer to its
         * beginning.  The returned value may be bigger than what was asked for.
         */
        static size_t Size(const void *ptr);

        /**
         * @return the GC object associated with a managed object.
         * this item must be a small item (<1968) or the first page of a large allocation,
         * it won't work on secondary pages of a large allocation,
         */
        static GC* GetGC(const void *item);

        /**
         * @return the mark (live) bit for the given object: zero if not set,
         * nonzero if set.
         */
        static int GetMark(const void *userptr);

        /**
         * Mark the given object as live.
         */
        static int SetMark(const void *userptr);

        /**
         * @return the queued bit for the given object: zero if not set, nonzero if set.
         */
        static int GetQueued(const void *userptr);
        
        // Not a hot method
        void ClearQueued(const void *userptr);

        // not a hot method
        static void ClearFinalized(const void *userptr);

        // not a hot method
        static void SetFinalize(const void *userptr);

        // not a hot method
        static int IsFinalized(const void *userptr);

        // not a hot method
        static int HasWeakRef(const void *userptr);

        /**
         * Mark the given object as having (flag==true) or not having (flag==false)
         * a weak reference.
         */
        static void SetHasWeakRef(const void *userptr, bool flag);

        /**
         * Used by sub-allocators to obtain memory.
         */
        void* AllocBlock(int size, PageMap::PageType pageType, bool zero=true, bool canFail=false);

        void FreeBlock(void *ptr, uint32_t size);

        // Host API: this should go away but Player code is currently using it.  VM code should not use it.
        GCHeap *GetGCHeap() const;

        void ReapZCT(bool scanStack=true);

        bool Reaping();

#ifdef _DEBUG
        // Test whether the RCObject cleaned itself properly by zeroing everything.
        void RCObjectZeroCheck(RCObject *);

        // Test whether 'item' points into a non-free object in the gc'd heap.
        bool IsPointerIntoGCObject(const void* item);
#endif

        /**
         * Do as much marking as possible in the allotted time slice
         */
        void IncrementalMark();

        /**
         * Perform some garbage collection work: the allocation budget has been exhausted.
         */
        void CollectionWork();

        /**
         * Are we currently marking?
         */
        bool IncrementalMarking();

    private:
        void AbortFree(const void* item);

        //////////////////////////////////////////////////////////////////////////
        //
        // Write barrier.  Those that are REALLY_INLINE are defined in WriteBarrier.h.

    private:
        /**
         * Perform the actual store of value into *address, adjusting reference counts.
         */
        /*REALLY_INLINE*/ void WriteBarrierWriteRC(const void *address, const void *value);

        /*
         * Streamlined versions to be used from the ctor/dtor of containers.
         */
        /*REALLY_INLINE*/ void WriteBarrierWriteRC_ctor(const void *address, const void *value);
        /*REALLY_INLINE*/ void WriteBarrierWriteRC_dtor(const void *address);

        /**
         * Perform the actual store of value into *address.  (This is just a store, but there
         * is additional error checking in debug builds.)
         */
        /*REALLY_INLINE*/ void WriteBarrierWrite(const void *address, const void *value);

        /**
         * The marker is running and the container object has just been transitioned from
         * 'marked' to 'queued'.
         */
        void WriteBarrierHit(const void* container);

    private:
        /**
         * Implementation of privateWriteBarrier; too large to be inlined everywhere.
         */
        /*REALLY_INLINE*/ void privateInlineWriteBarrier(const void *container, const void *address, const void *value);

        /**
         * Like the preceding but computes 'container' only if 'marking' is true (important optimization).
         */
        /*REALLY_INLINE*/ void privateInlineWriteBarrier(const void *address, const void *value);

        /**
         * Implementation of privateWriteBarrierRC; too large to be inlined everywhere.
         */
        /*REALLY_INLINE*/ void privateInlineWriteBarrierRC(const void *container, const void *address, const void *value);

        /**
         * Like the preceding but computes 'container' only if 'marking' is true (important optimization).
         */
        /*REALLY_INLINE*/ void privateInlineWriteBarrierRC(const void *address, const void *value);

        /**
         * Out-of-line implementation of ConservativeWriteBarrierNoSubstitute, called only
         * when 'marking' is true.
         */
        void privateConservativeWriteBarrierNoSubstitute(const void *address);

    public:
        /**
         * General, conditional write barrier trap.  Tests that incremental marking is in fact ongoing
         * and that the container is black (marked, not queued); if so, it makes the container gray
         * by scheduling it for rescanning at some appropriate time.
         *
         * Container must be a non-NULL untagged pointer to the beginning of an object on a page
         * owned by this GC.
         */
        void WriteBarrierTrap(const void *container);

        /**
         * Inline implementation of WriteBarrierTrap; probably too large to be inlined everywhere
         * so use sparingly.  AvmCore::atomWriteBarrier benefits substantially from inlining it.
         *
         * PRECONDITION: 'marking' must be true when this is called.
         */
        /*REALLY_INLINE*/ void InlineWriteBarrierTrap(const void *container);

        /**
         * Standard write barrier write for non-RC values.  If marking is ongoing, and the 'container'
         * is black (ie marked and not queued) and the 'value' is white (ie unmarked and not queued)
         * then make sure to queue value for marking.
         *
         * Finally stores value into *address.
         *
         * 'container' may be NULL, in which case this is just a store and 'address' can be arbitrary.
         *
         * If 'container' is not NULL then it is constrained as for WriteBarrierTrap, and 'address'
         * must point into the object referenced by 'container'.
         *
         * Value can be anything except a reference to an RCObject.
         *
         * This is called by the WB macro in WriteBarrier.h - not an API to be used otherwise.
         */
        void privateWriteBarrier(const void *container, const void *address, const void *value);

        /**
         * A write barrier that finds the container's address and the container's
         * GC and then performs a standard write barrier operation (see privateWriteBarrier).
         * Finally stores value into *address.
         */
        static void WriteBarrier(const void *address, const void *value);

        /**
         * Standard write barrier write for RC values.  If marking is ongoing, and the 'container'
         * is black (ie marked and not queued) and the 'value' is white (ie unmarked and not queued)
         * then make sure to queue value for marking.
         *
         * Finally stores value into *address, adjusting the reference counts of both the old value
         * and the new value.
         *
         * 'container' is constrained as for WriteBarrierTrap.
         *
         * 'address' must point into the object referenced by 'container'.  The value there, if not
         * NULL, must be a (possibly tagged) pointer to an RC object.
         *
         * 'value', if not NULL, must point to an RC object owned by this GC.
         *
         * This is called by the WBRC macro in WriteBarrier.h - not an API to be used otherwise.
         */
        void privateWriteBarrierRC(const void *container, const void *address, const void *value);

        /**
         * A write barrier that finds the container's address and the container's GC
         * and then performs a standard RC write barrier operation (see privateWriteBarrierRC).
         */
        static void FASTCALL WriteBarrierRC(const void *address, const void *value);

        /**
         * Like WriteBarrierRC, but used when calling from a container's ctor/dtor.
         * We can avoid some unnecessary work in each case.
         */
        static void FASTCALL WriteBarrierRC_ctor(const void *address, const void *value);
        static void FASTCALL WriteBarrierRC_dtor(const void *address);

        /**
         * Host API: if 'address' points to a GC page (it can point into an object, not just
         * to the start of one), and 'value' points to a GC page as well, record that 'value'
         * has been stored into the object containing 'address'.
         *
         * The function does /not/ perform the store (this is what NoSubstitute means).
         *
         * The function works for both RCObjects and GCObjects.
         */
        void ConservativeWriteBarrierNoSubstitute(const void *address, const void *value);

        /**
         * Host API: 'container' must be a non-NULL untagged pointer to the beginning of an
         * object on a page owned by this GC.  Record that 'value' has been stored into
         * 'container'.
         *
         * The function does /not/ perform the store (this is what NoSubstitute means).
         *
         * The function works for both RCObjects and GCObjects.
         */
        void WriteBarrierNoSubstitute(const void *container, const void *value);

    public:
        GCPolicyManager policy;

    public:

        /**
         * @return true if the gc item contains pointers.  Item must be valid GC pointer.
         */
        bool ContainsPointers(const void *item);

        /**
         * Will reliably return NULL if gcItem does not point into
         * managed memory (and _DEBUG code will also assert if that
         * happens - it should not unless allowGarbage is true).  Note
         * that this function is for pointers to bytes inside GC items,
         * pointers to GC block headers (ie before the first object on
         * the page) will return NULL.
         */
        void *FindBeginningGuarded(const void *gcItem, bool allowGarbage=false);

        // Legacy public API.  DO NOT USE from within AVM code.
        void *FindBeginning(const void *gcItem);

        // Used on the critical path of the write barrier path.  gcItem must point into
        // managed memory, and NULL is never returned.  Don't use this for GCAssert and
        // similar purposes, but use it when speed is key.
        void *FindBeginningFast(const void *gcItem);

        /**
         * @return true if the useritem is an RCObject.  Item must be valid GC pointer.
         */
        static bool IsRCObject(const void *userptr);

        /**
         * True during Sweep phase.  Application code can use this to
         * determine if it's being called (directly or indirectly) from a
         * finalizer.
         */
        bool Collecting();

        /**
         * True during the Sweep phase, while the GC is calling presweep callbacks.
         */
        bool Presweeping();

        /**
         * @return true if the item points to a page containing managed objects.
         * Any pointer can be passed in here.
         */
        bool IsPointerToGCPage(const void *item);

        /**
         * @return true is realptr points to the beginning of a GC object.
         */
        bool IsPointerToGCObject(const void *realptr);

        /**
         * GC initialization time, in ticks.  Used for logging.
         * FIXME: why is this public?
         */
        const uint64_t t0;

        // FIXME: these three static methods could be lifted out of the GC class to the global level,
        // they're simple utilities.
        static double duration(uint64_t start);

        // a tick is the unit of VMPI_getPerformanceFrequency()
        static uint64_t ticksToMicros(uint64_t ticks);

        static uint64_t ticksToMillis(uint64_t ticks);

        /**
         * Total number of bytes of pointer-containing memory scanned by this
         * GC.  Used to measure marking rate, which is
         * <code>bytesMarked()/ticksToMillis(markTicks())</code>.
         */
        uint64_t bytesMarked();

        /**
         * Total time spent doing incremental marking, in ticks.  See
         * bytesMarked.
         */
        uint64_t markTicks();

        // calls to mark item
        uint32_t lastStartMarkIncrementCount;
        uint32_t markIncrements();

        /**
         * Number of calls to Sweep().
         */
        uint32_t sweeps;

        /**
         * Time of the latest FinishIncrementalMark() call, in ticks.
         */
        uint64_t sweepStart;

        // called at some apropos moment from the mututor, ideally at a point
        // where all possible GC references will be below the current stack pointer
        // (ie in memory we can safely zero).  This will return right away if
        // called more than once between collections so it can safely be called
        // a lot without impacting performance
        void CleanStack(bool force=false);

        bool Destroying();

        /**
         * @return a reference to the mark bits for the given realptr.
         * The realptr must point to the beginning of an object owned 
         * by this GC.
         */
        static gcbits_t& GetGCBits(const void* realptr);

        /**
         * @return a GCWeakRef object whose get method will return userptr
         * until its collected at which point NULL will be returned.
         * userptr must be a valid live GC object.
         */
        static GCWeakRef *GetWeakRef(const void *userptr);

        // a WeakRef that always refers to null. useful if you need one.
        GCWeakRef* emptyWeakRef;

        // The allowRehash argument should not be 'false' willy-nilly.
        void ClearWeakRef(const void *obj, bool allowRehash=true);

        // @return The highest stack address, ie the stack 'base' in common parlance.
        // @fixme This is misnamed, 'GetStackBase' would be better.  We can't
        // rename the function now (== 8 January 2010) because it's used externally
        // by performance code and we don't want the churn, but it should be renamed
        // and post-Flash10.1 we will do so.
        uintptr_t GetStackTop() const;

        uintptr_t GetStackEnter() const;

        // for deciding a tree of things should be scanned from presweep
        void PushWorkItem_MayFail(GCWorkItem &item);
        bool GetMarkStackOverflow() const { return m_markStackOverflow; }

#ifdef DEBUG
        // Check that invariants for an inactive GC hold
        void ShouldBeInactive();
#endif

        bool onThread();

    private:

        // Take any pointer and determine if its an rc object,
        // specifically that its on a GC page marked for RC objects
        // and points to the beginning of that object.  Basically
        // shorthand for IsPointerToGCObject && IsRCObject.  Any input
        // is safe, this never crashes or asserts.
        bool IsRCObjectSafe(const void *anyptr);

        // heapAlloc is like heap->Alloc except that it also calls policy.signalBlockAllocation
        // if the allocation succeeded.
        void *heapAlloc(size_t size, int flags=GCHeap::flags_Alloc);

        // heapFree is like heap->Free except that it also calls policy.signalBlockDeallocation.
        void heapFree(void *ptr, size_t siz=0, bool profile=true);

        friend class GCAutoEnter;
        friend class GCAutoEnterPause;
        bool ThreadEnter(GCAutoEnter *enter, bool doCollectionWork, bool tryEnter);
        void ThreadLeave(bool doCollectionWork, GC *prevGC);
        void ThreadEdgeWork();

        GCAutoEnter *GetAutoEnter();

        vmpi_spin_lock_t m_gcLock;

        // store a handle to the thread that create the GC to ensure thread safety
        vmpi_thread_t m_gcThread;

        // Will be called from GCHeap::AbortCleanup before a longjmp that jumps past the
        // GC (effectively aborting an operation, be it allocation or GC).  This function
        // must be aware of the internal state of the GC and must take
        // care to make that state consistent.
        void SignalImminentAbort();

        void gclog(const char *format, ...);
        void log_mem(const char *name, size_t s, size_t comp );

        const static int kNumSizeClasses = 40;

        uint32_t *AllocBits(int numBytes, int sizeClass);

        void FreeBits(uint32_t *bits, int sizeClass);

        uint32_t *m_bitsFreelists[kNumSizeClasses];
        uint32_t *m_bitsNext;

        GCHashtable weakRefs;

        // Remove all weak references whose non-NULL objects are unmarked from the table.
        void ClearUnmarkedWeakRefs();

        // BEGIN FLAGS
        // The flags are hot, group them and hope they end up in the same cache line

        // True when the GC is being destroyed
        bool destroying;

        /**
         * True if incremental marking is on and some objects have been marked.
         * This means write barriers are enabled.
         *
         * The GC thread may read and write this flag.  Application threads in
         * requests have read-only access.
         *
         * It is possible for marking==true and collecting==false but not vice versa.
         */
        bool marking;

        /**
         * True during the sweep phase of collection.  Several things have to
         * behave a little differently during this phase.  For example,
         * GC::Free() does nothing during sweep phase; otherwise finalizers
         * could be called twice.
         *
         * Also, Collect() uses this to protect itself from recursive calls
         * (from badly behaved finalizers).
         *
         * It is possible for marking==true and collecting==false but not vice versa.
         */
        bool collecting;

        /**
         * True during the sweep phase of collection, while we're calling presweep
         * callbacks.  We use this to implement the read barrier in GCWeakRef::get,
         * when a presweep resurrects an unmarked object.
         */
        bool presweeping;

        /**
         * Nonzero if IncrementalMark is currently active.  This is more specific than 'marking';
         * Collect() uses this to protect itself from recursive calls during OOM handling.
         * (Those calls should not happen because the only allocation to happen during marking
         * is the mark stack and it should be careful not to invoke OOM handling, but debugging
         * code and other ad-hoc code may interfere.  This state variable is cheap insurance.)
         *
         * The flag is a counter because some functions call both Mark and MarkItem, and then
         * Mark also calls MarkItem, so the flag may needs to be set and reset on several levels.
         * The counter takes care of this naturally.
         */
        uint32_t markerActive;

        // END FLAGS


        // we track the top and bottom of the stack for cleaning purposes.
        // the top tells us how far up the stack as been dirtied.
        // the bottom is also tracked so we can ensure we're on the same
        // stack that the GC responsible for cleaning.  necessary if multiple
        // threads use the GC.  only thread that creates the GC will have its stack
        // tracked and cleaned.
        bool stackCleaned;
        const void *rememberedStackTop;
        GCAutoEnter* stackEnter;
        uint32_t enterCount;

        GCRoot* emptyWeakRefRoot;

        GCMarkStack m_incrementalWork;
        void StartIncrementalMark();
        void FinishIncrementalMark(bool scanStack);

        bool m_markStackOverflow;
        void HandleMarkStackOverflow();
        void SignalMarkStackOverflow(GCWorkItem& item);

        GCMarkStack m_barrierWork;
        void CheckBarrierWork();
        void FlushBarrierWork();

        // Set at initialization to the deepest recursion level MarkItem is allowed to
        // reach.  Managed entirely within MarkItem.
        uint32_t mark_item_recursion_control;

#ifdef _DEBUG
        // Works on any address
        bool IsWhite(const void *item);
#endif

        // Used heavily by the write barrier.
        bool IsMarkedThenMakeQueued(const void* userptr);

        // Used heavily by GC::Free.
        bool IsQueued(const void* userptr);

        const static int16_t kSizeClasses[kNumSizeClasses];
        const static uint8_t kSizeClassIndex[246];

        // These two members help optimize GC::Alloc: by keeping a pointer in the GC instance
        // for the kSizeClassIndex table we avoid code generation SNAFUs when compiling with -fPIC,
        // which is the default on Mac at least.  (GCC generates a call-to-next-instruction-and-pop
        // to obtain the PC address, from which it can compute the table address.  Keeping the
        // member here effectively hoists that computation out of the allocator.)  And by keeping
        // a lookup table of allocators indexed by the flag bits of interest we avoid a decision
        // tree inside GC::Alloc.

        const uint8_t* const sizeClassIndex;
        GCAlloc** allocsTable[(kRCObject|kContainsPointers)+1];

        void *m_contextVars[GCV_COUNT];

        /**
         * Tracks pages in use; 2 bits per page (see PageType enum).
         */
#ifdef MMGC_USE_UNIFORM_PAGEMAP
        PageMap::Uniform pageMap;
#else
#ifdef MMGC_64BIT
        PageMap::DelayT4 pageMap;
#else
        PageMap::Tiered2 pageMap;
#endif // MMGC_64BIT
#endif // MMGC_USE_UNIFORM_PAGEMAP

        // This is very hot
        PageMap::PageType GetPageMapValue(uintptr_t addr) const;

        // This is warm - used in IsPointerToGCPage and in FindBeginningGuarded
        PageMap::PageType GetPageMapValueGuarded(uintptr_t addr);

        /**
         * Set the pageMap bits for numpages starting from given address.
         * Those bits must be zero beforehand.
         */
        void MarkGCPages(void *item, uint32_t numpages, PageMap::PageType val);

        /**
         * Zero out the pageMap bits for numpages starting from given address.
         */
        void UnmarkGCPages(void *item, uint32_t numpages);

        /**
         * Mark a region of memory, this will search all memory pointed to recursively
         * and mark any GC Objects it finds
         */
        void ConservativeMarkRegion(const void *base, size_t bytes);

        GCAlloc *containsPointersAllocs[kNumSizeClasses];
        GCAlloc *containsPointersRCAllocs[kNumSizeClasses];
        GCAlloc *noPointersAllocs[kNumSizeClasses];
        GCLargeAlloc *largeAlloc;
        GCHeap *heap;

#ifdef _DEBUG
    public:
#else
    private:
#endif
        void ClearMarks();

#ifdef _DEBUG
    public:
        /**
         * Kill any incremental mark in progress, then trace from roots and stack.  If
         * stackStart/stackSize are NULL/0 then the thread stack is obtained and used.
         *
         * It's sometimes useful for mutator to call this; the ZCT reaper uses it for
         * validating the heap.
         *
         * @return   true if it succeeded, false if there was a mark stack overflow.
         */
        bool Trace(const void *stackStart=NULL, uint32_t stackSize=0);
#endif

    private:
        void Finalize();
        void Sweep();
        void ForceSweepAtShutdown();
        void MarkAllRoots(bool deep=false);
        void Mark();
        void MarkQueueAndStack(bool scanStack=true);
        void MarkItem(GCWorkItem &wi);
        bool HandleLargeMarkItem(GCWorkItem &wi, size_t &size);
        void EstablishSweepInvariants();
        void ClearMarkStack();

        static void DoCleanStack(void* stackPointer, void* arg);
        static void DoMarkFromStack(void* stackPointer, void* arg);

    public:
        // Sweep all small-block pages that need sweeping
        void SweepNeedsSweeping();

    private:
        bool finalizedValue;

        void AddToSmallEmptyBlockList(GCAlloc::GCBlock *b);

        /**
         * List of pages to be swept, built up in Finalize.
         */
        GCAlloc::GCBlock *smallEmptyPageList;

        void AddToLargeEmptyBlockList(GCLargeAlloc::LargeBlock *lb);

        /**
         * List of pages to be swept, built up in Finalize.
         */
        GCLargeAlloc::LargeBlock *largeEmptyPageList;

        /**
         * Free list budget management for small-block allocators
         */
        void ObtainQuickListBudget(size_t nbytes);
        void RelinquishQuickListBudget(size_t nbytes);

        size_t remainingQuickListBudget;
        uint32_t victimIterator;

        vmpi_spin_lock_t m_rootListLock;

        GCRoot *m_roots;
        void AddRoot(GCRoot *root);
        void RemoveRoot(GCRoot *root);

        /**
         * Points to the head of a linked list of callback objects.
         */
        GCCallback *m_callbacks;
        void AddCallback(GCCallback *cb);
        void RemoveCallback(GCCallback *cb);

        // Deferred ref counting implementation
        ZCT zct;
#ifdef MMGC_REFCOUNT_PROFILING
        void AddToZCT(RCObject *obj, bool initial=false);
#else
        void AddToZCT(RCObject *obj);
#endif

#ifdef MMGC_REFCOUNT_PROFILING
        REALLY_INLINE void RemoveFromZCT(RCObject *obj, bool final=false);
#else
        REALLY_INLINE void RemoveFromZCT(RCObject *obj);
#endif

    public:
        // PreventImmediateReaping is used by Flash Player for older content: it means to flag
        // the object so that it won't be reaped until it goes through a 1 -> 0 reference count
        // transition.  Also see the 'dontAddToZCTDuringCollection' configuration variable.
        void PreventImmediateReaping(RCObject* obj);

        static const void *Pointer(const void *p);

public:
        void DumpMemoryInfo();
#ifdef MMGC_MEMORY_PROFILER
        void DumpPauseInfo();
#endif

private:

        // PushWorkItem is defined in GC.cpp, always inlined in callers there.
        // item.ptr must not be NULL.
        void PushWorkItem(GCWorkItem item);

#ifdef _DEBUG
        /**
         * Check the consistency of the free lists for all the allocators.
         */
        void CheckFreelists();

        /**
         * Conservatively find pointers in the entire heap referencing unmarked objects,
         * triggering assertions when one is found.  This is a sanity check on the GC
         * marking algorithm.
         */
        void FindUnmarkedPointers();

        /**
         * Conservatively find pointers in an address range referencing unmarked objects,
         * triggering assertions when one is found.
         */
        void UnmarkedScan(const void *mem, size_t size);

        // methods for incremental verification

        /**
         * Scan a region of memory for white pointers. Used by
         * FindMissingWriteBarriers.
         */
        void WhitePointerScan(const void *mem, size_t size);

        /**
         * Scan all GC memory (skipping roots). If a GC object is black make sure
         * it has no pointers to white objects.
         */
        void FindMissingWriteBarriers();

#endif

public:

#ifdef _DEBUG
        // Dump a list of objects that have pointers to the given location.
        void WhosPointingAtMe(void* me, int recurseDepth=0, int currentDepth=0);

        /**
         * Used by WhosPointingAtMe.
         */
        void ProbeForMatch(const void *mem, size_t size, uintptr_t value, int recurseDepth, int currentDepth);
#endif

        void DumpAlloc(GCAlloc *a, size_t& internal_waste, size_t& overhead);

        //This method returns the number bytes allocated for GC objects
        size_t GetBytesInUse();

        //This method is for more fine grained allocation details
        //It reports the total number of bytes requested (i.e. ask size) and
        //the number of bytes actually allocated.  The latter is the same
        //number as reported by GetBytesInUse()
        void GetUsageInfo(size_t& totalAskSize, size_t& totalAllocated);

        size_t GetNumBlocks();

        virtual void memoryStatusChange(MemoryStatus oldStatus, MemoryStatus newStatus);

        /* A portable replacement for alloca().
         *
         * Memory is allocated from the heap and not from the stack.  It is freed in
         * one of two ways: If the function returns normally then an auto_ptr like
         * mechanism frees the memory.  If the function leaves by throwing an exception
         * (or if one of its callees throws an exception) then the exception
         * handling mechanism in Exception.{h,cpp} frees the memory by releasing
         * everything that is still allocated that was allocated since the exception
         * handler was erected.
         *
         * The auto_ptr mechanism, based on the class MMgc::GC::AllocaAutoPtr, cannot be
         * circumvented, as allocaPush() takes a reference to such an object as an argument.
         *
         * Typical usage:
         *
         *    MMgc::GC::AllocaAutoPtr _ptr;                      // by convention prefixed by "_"
         *    int* ptr = (int*)core->allocaPush(_ptr, nbytes);  // by convention same name, no "_"
         *
         * In practice the VMPI_alloca() macro, defined in avmbuild.h, should be used so that
         * real alloca() can be used on platforms where that makes sense.
         *
         * Benchmarks suggest that the performance differences from using this mechanism
         * instead of real alloca() are slight to nonexistent, and that the heap allocation
         * sometimes provides a performance improvement.
         */
    public:
        struct AllocaStackSegment
        {
            void* start;                // first address; also, the RCRoot pointer
            void* limit;                // address past data
            void* top;                  // address past live if this segment is not the top
            AllocaStackSegment* prev;   // segments further from the top
        };

        void allocaInit();
        void allocaShutdown();
        void allocaUnwind();            // restore to initial state
        void allocaPopToSlow(void* top);
        void* allocaPushSlow(size_t nbytes);
        void pushAllocaSegment(size_t nbytes);
        void popAllocaSegment();

        AllocaStackSegment* top_segment;// segment at the stack top
        void* stacktop;                 // current first free word in top_segment
#ifdef _DEBUG
        size_t stackdepth;              // useful to have for debugging
#endif

    public:
        /* See documentation above */

        class AllocaAutoPtr
        {
            friend class GC;
        public:
            AllocaAutoPtr();
            ~AllocaAutoPtr();
        private:
            GC* gc;
            void* unwindPtr;
        };

        void* allocaTop();

        void allocaPopTo(void* top);

        void* allocaPush(size_t nbytes, AllocaAutoPtr& x);

#ifdef DEBUGGER
    public:
        // Attach an opaque sampler to this GC, overriding any previous sampler
        void* GetAttachedSampler();

        // Retrieve the opaque sampler from this GC, NULL if none has been attached
        void SetAttachedSampler(void *sampler);

    private:
        // An attached sampler, or NULL.  We need to attach the sampler to the GC
        // because it moves with the GC/AvmCore pair, it is not attached to a
        // particular thread.
        void* m_sampler;
#endif

#ifdef MMGC_HEAP_GRAPH

    public:

        void addToBlacklist(const void *gcptr);
        void removeFromBlacklist(const void *gcptr);

    private:

        GCHashtable blacklist;

        void printBlacklist();
        void pruneBlacklist();

        const void *findGCGraphBeginning(const void *addr, bool &wasDeletedGCRoot);
        void dumpBackPointerChain(const void *obj, HeapGraph &g);
        void dumpBackPointerChainHelper(const void *p, HeapGraph& g);
        HeapGraph mutatorGraph;
        HeapGraph markerGraph;
#endif
    };

    // helper class to wipe out vtable pointer of members for DRC
    class Cleaner
    {
    public:
        Cleaner();
        ~Cleaner();
        // don't let myself move between objects
        Cleaner& operator=(const Cleaner& /*rhs*/);
        void set(const void * _v, size_t _size);

        int *v;
        size_t size;
    };

    /**
     * Stack object that takes care of many things including defining stack
     * boundaries, doing low stack queued collections/ZCT reaps and stack cleaning
     */
    class GCAutoEnter : public AbortUnwindObject
    {
    public:
        enum EnterType {
            kNormal=0,
            kTryEnter=1
        };
        GCAutoEnter(GC *gc, EnterType type=kNormal);
        ~GCAutoEnter();
        bool Entered();
        void Destroy(bool doCollectionWork);
        virtual void Unwind();
    private:
        GC* m_gc;
        GC* m_prevgc;
    };

    /**
     * Undoes the affects of GCAutoEnter on entry and reapplies them upon exit
     */
    class GCAutoEnterPause
    {
    public:
        GCAutoEnterPause(GC *gc);
        ~GCAutoEnterPause();
    private:
        GC* gc;
        GCAutoEnter *enterSave;
    };
}

#endif /* __GC__ */
