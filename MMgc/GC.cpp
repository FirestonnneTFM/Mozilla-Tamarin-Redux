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

#include "MMgc.h"
#include "StaticAssert.h"

#undef AVMPLUS_SAMPLER // Bugzilla 614529
#undef SAMPLE_FRAME
#undef SAMPLE_CHECK

#ifdef AVMPLUS_SAMPLER
 //sampling support
#include "avmplus.h"
#else
#define SAMPLE_FRAME(_x, _s)
#define SAMPLE_CHECK()
#endif

namespace MMgc
{
#ifdef MMGC_MEMORY_PROFILER
    // get detailed info on each size class allocators
    const bool dumpSizeClassState = false;
#endif

    /*virtual*/
    void GCCallback::presweep() {}

    /*virtual*/
    void GCCallback::postsweep() {}

    /*virtual*/
    void GCCallback::prereap() {}

    /*virtual*/
    void GCCallback::postreap() {}

    /*virtual*/
    void GCCallback::prereap(void* /*rcobj*/) {}

    ////////////// GC //////////////////////////////////////////////////////////

    // Size classes for our GC.  From 8 to 128, size classes are spaced
    // evenly 8 bytes apart.  The finest granularity we can achieve is
    // 8 bytes, as pointers must be 8-byte aligned thanks to our use
    // of the bottom 3 bits of 32-bit atoms for Special Purposes.
    // Above that, the size classes have been chosen to maximize the
    // number of items that fit in a 4096-byte block, given our block
    // header information.
    const int16_t GC::kSizeClasses[kNumSizeClasses] = {
        8, 16, 24, 32, 40, 48, 56, 64, 72, 80, //0-9
        88, 96, 104, 112, 120, 128, 144, 160, 168, 176,  //10-19
        184, 192, 200, 216, 224, 240, 256, 280, 296, 328, //20-29
        352, 392, 432, 488, 560, 656, 784, 984, 1312, 1968 //30-39
    };

    /* kSizeClassIndex[] generated with this code:
        kSizeClassIndex[0] = 0;
        for (var i:int = 1; i < kNumSizeClasses; i++)
            for (var j:int = (kSizeClasses[i-1]>>3), n=(kSizeClasses[i]>>3); j < n; j++)
                kSizeClassIndex[j] = i;
    */

    // index'd by size>>3 - 1
    const uint8_t GC::kSizeClassIndex[246] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 16, 17, 17,
        18, 19, 20, 21, 22, 23, 23, 24, 25, 25,
        26, 26, 27, 27, 27, 28, 28, 29, 29, 29,
        29, 30, 30, 30, 31, 31, 31, 31, 31, 32,
        32, 32, 32, 32, 33, 33, 33, 33, 33, 33,
        33, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
        35, 35, 36, 36, 36, 36, 36, 36, 36, 36,
        36, 36, 36, 36, 36, 36, 36, 36, 37, 37,
        37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
        37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
        37, 37, 37, 38, 38, 38, 38, 38, 38, 38,
        38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
        38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
        38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
        38, 38, 38, 38, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
        39, 39, 39, 39, 39, 39
    };

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable:4355) // 'this': used in base member initializer list
#endif

    GC::GC(GCHeap *gcheap, GCMode mode, GCConfig *config/*=NULL*/)
        :
        greedy(mode == kGreedyGC),
        nogc(mode == kDisableGC),
        incremental(mode == kIncrementalGC),
        findUnmarkedPointers(false),
        validateDefRef(false),
        keepDRCHistory(false),
        dontAddToZCTDuringCollection(false),
        incrementalValidation(false),
#ifdef _DEBUG
        // check for missing write barriers at every Alloc
        incrementalValidationPedantic(false),
#endif
        rcRootSegments(NULL),
        policy(this, gcheap, config),
        t0(VMPI_getPerformanceCounter()),
        lastStartMarkIncrementCount(0),
        sweeps(0),
        sweepStart(0),
        emptyWeakRef(0),

        m_gcThread(NULL),
        destroying(false),
        marking(false),
        collecting(false),
        presweeping(false),
        markerActive(0),
        stackCleaned(true),
        rememberedStackTop(0),
        stackEnter(0),
        enterCount(0),
        emptyWeakRefRoot(0),
        m_markStackOverflow(false),
        mark_item_recursion_control(20),    // About 3KB as measured with GCC 4.1 on MacOS X (144 bytes / frame), May 2009
        sizeClassIndex(kSizeClassIndex),    // see comment in GC.h
        pageMap(),
        heap(gcheap),
        finalizedValue(true),
        smallEmptyPageList(NULL),
        largeEmptyPageList(NULL),
        remainingQuickListBudget(0),
        victimIterator(0),
        m_roots(0),
        m_callbacks(0),
        zct()
#ifdef MMGC_CONSERVATIVE_PROFILER
        , demos(0)
#endif
#ifdef DEBUGGER
        , m_sampler(NULL)
#endif
    {
        // sanity check for all our types
        MMGC_STATIC_ASSERT(sizeof(int8_t) == 1);
        MMGC_STATIC_ASSERT(sizeof(uint8_t) == 1);
        MMGC_STATIC_ASSERT(sizeof(int16_t) == 2);
        MMGC_STATIC_ASSERT(sizeof(uint16_t) == 2);
        MMGC_STATIC_ASSERT(sizeof(int32_t) == 4);
        MMGC_STATIC_ASSERT(sizeof(uint32_t) == 4);
        MMGC_STATIC_ASSERT(sizeof(int64_t) == 8);
        MMGC_STATIC_ASSERT(sizeof(uint64_t) == 8);
        MMGC_STATIC_ASSERT(sizeof(intptr_t) == sizeof(void *));
        MMGC_STATIC_ASSERT(sizeof(uintptr_t) == sizeof(void *));
        #ifdef MMGC_64BIT
        MMGC_STATIC_ASSERT(sizeof(intptr_t) == 8);
        MMGC_STATIC_ASSERT(sizeof(uintptr_t) == 8);
        #else
        MMGC_STATIC_ASSERT(sizeof(intptr_t) == 4);
        MMGC_STATIC_ASSERT(sizeof(uintptr_t) == 4);
        #endif
        MMGC_STATIC_ASSERT(sizeof(GCLargeAlloc::LargeBlock) % 8 == 0);
        MMGC_STATIC_ASSERT(sizeof(gcbits_t) == 1);

        // The size tables above are derived based on a block size of 4096; this
        // assert keeps us honest.  Talk to Lars if you get into trouble here.
        //
        // Also it appears that some DEBUG-mode guards in SetPageMapValue,
        // GetPageMapValue, ClearPageMapValue know that the block size is 4096.
        GCAssert(GCHeap::kBlockSize == 4096);
        
        GCAssert(!(greedy && incremental));
        zct.SetGC(this);

        VMPI_lockInit(&m_gcLock);
        VMPI_lockInit(&m_rootListLock);

        // Global budget for blocks on the quick lists of small-object allocators.  This
        // budget serves as a throttle on the free lists during times when the GC is not
        // running; when the GC is running the periodic flushing of the quick lists
        // makes the budget irrelevant.  The budget is global so that very active allocators
        // can have long free lists at the expense of inactive allocators, which must have
        // short ones.
        //
        // This is somewhat arbitrary: 4 blocks per allocator.  Must initialize this before we
        // create allocators because they will request a budget when they're created.  The
        // total budget /must/ accomodate at least one block per alloc, and makes very little
        // sense if it is not at least two blocks per alloc.  (Note no memory is allocated, it's
        // just a budget.)
        //
        // See comment in GCAlloc.cpp for more about the quick lists.

        remainingQuickListBudget = (3*kNumSizeClasses) * 4 * GCHeap::kBlockSize;

        // Create all the allocators up front (not lazy)
        // so that we don't have to check the pointers for
        // NULL on every allocation.
        for (int i=0; i<kNumSizeClasses; i++) {
            containsPointersAllocs[i] = mmfx_new(GCAlloc(this, kSizeClasses[i], true, false, i));
            containsPointersRCAllocs[i] = mmfx_new(GCAlloc(this, kSizeClasses[i], true, true, i));
            noPointersAllocs[i] = mmfx_new(GCAlloc(this, kSizeClasses[i], false, false, i));
        }

        largeAlloc = mmfx_new(GCLargeAlloc(this));

        // See comment in GC.h
        allocsTable[kRCObject] = containsPointersRCAllocs;
        allocsTable[kContainsPointers] = containsPointersAllocs;
        allocsTable[kRCObject|kContainsPointers] = containsPointersRCAllocs;
        allocsTable[0] = noPointersAllocs;

        VMPI_memset(m_bitsFreelists, 0, sizeof(uint32_t*) * kNumSizeClasses);
        m_bitsNext = (uint32_t*)heapAlloc(1);

        // precondition for emptyPageList
        GCAssert(offsetof(GCLargeAlloc::LargeBlock, next) == offsetof(GCAlloc::GCBlock, next));


        for(int i=0; i<GCV_COUNT; i++)
        {
            SetGCContextVariable(i, NULL);
        }

        allocaInit();

        emptyWeakRefRoot = new GCRoot(this, &this->emptyWeakRef, sizeof(this->emptyWeakRef));
        MMGC_GCENTER(this);
        emptyWeakRef = new (this) GCWeakRef(NULL);

        Alloc(2048);

#ifdef MMGC_CONSERVATIVE_PROFILER
        if (demos == NULL && heap->profiler != NULL)
            demos = new ObjectPopulationProfiler(this, "Conservative scanning volume incurred by allocation site");
#endif

        gcheap->AddGC(this);
        gcheap->AddOOMCallback(this);

    }

#ifdef _MSC_VER
#  pragma warning(pop)
#endif

    GC::~GC()
    {
#ifdef MMGC_CONSERVATIVE_PROFILER
        if (demos != NULL)
        {
            demos->dumpTopBacktraces(30, ObjectPopulationProfiler::BY_COUNT);
            delete demos;
            demos = NULL;
        }
#endif
        policy.shutdown();
        allocaShutdown();

        // Do this before calling GCHeap::RemoveGC as GCAutoEnter::Destroy
        // expect this GC to still be the active GC and GCHeap::RemoveGC clears
        // the active GC.
        if(stackEnter != NULL) {
            stackEnter->Destroy(false);
        }

        heap->RemoveGC(this);
        heap->RemoveOOMCallback(this);

        // Force all objects to be destroyed
        destroying = true;

        {
            MMGC_GCENTER(this);
            ForceSweepAtShutdown();
        }

        for (int i=0; i < kNumSizeClasses; i++) {
            mmfx_delete( containsPointersAllocs[i]);
            mmfx_delete(containsPointersRCAllocs[i]);
            mmfx_delete(noPointersAllocs[i]);
        }

        if (largeAlloc) {
            mmfx_delete(largeAlloc);
        }

        // Go through m_bitsFreelist and collect list of all pointers
        // that are on page boundaries into new list, pageList
        void **pageList = NULL;
        for(int i=0, n=kNumSizeClasses; i<n; i++) {
            uint32_t* bitsFreelist = m_bitsFreelists[i];
            while(bitsFreelist) {
                uint32_t *next = *(uint32_t**)bitsFreelist;
                if((uintptr_t(bitsFreelist) & GCHeap::kOffsetMask) == 0) {
                    *((void**)bitsFreelist) = pageList;
                    pageList = (void**)bitsFreelist;
                }
                bitsFreelist = next;
            }
        }

        // Go through page list and free all pages on it
        while (pageList) {
            void **next = (void**) *pageList;
            heapFree((void*)pageList);
            pageList = next;
        }

        pageMap.DestroyPageMapVia(heap);

        delete emptyWeakRefRoot;
        GCAssert(!m_roots);
        GCAssert(!m_callbacks);

        // apparently the player can't be made to clean up so keep it from crashing at least
        while(m_roots) {
            m_roots->Destroy();
        }

        while(m_callbacks) {
            m_callbacks->Destroy();
        }

        zct.Destroy();

        GCAssertMsg(GetNumBlocks() == 0, "GC accounting off");

        GCAssertMsg(enterCount == 0, "GC enter/exit paths broken");

        VMPI_lockDestroy(&m_gcLock);
        VMPI_lockDestroy(&m_rootListLock);
    }

    void GC::Collect(bool scanStack)
    {
        GCAssertMsg(!scanStack || onThread(), "Full collection with stack scan requested however the GC isn't associated with a thread, missing MMGC_GCENTER macro.");

        if (nogc || markerActive || collecting || Reaping()) {
            return;
        }

        ReapZCT(scanStack);

        if(!marking)
            StartIncrementalMark();
        if(marking)
            FinishIncrementalMark(scanStack);

#ifdef _DEBUG
        // Dumping the stack trace at GC time can be very helpful with stack walk bugs
        // where something was created, stored away in untraced, unmanaged memory and not
        // reachable by the conservative stack walk
        //DumpStackTrace();
        FindUnmarkedPointers();
#endif

        policy.fullCollectionComplete();
    }

#ifdef RECURSIVE_MARK
    REALLY_INLINE void GC::PushWorkItem(GCWorkItem item)
    {
        GCAssert(item.ptr != NULL);
        markerActive++;
        MarkItem(item);
        markerActive--;
    }

    REALLY_INLINE void GC::PushWorkItem_Unsafe(GCWorkItem item)
    {
        PushWorkItem(item);
    }
#else
    REALLY_INLINE void GC::PushWorkItem(GCWorkItem item)
    {
#ifdef _DEBUG
        WorkItemInvariants(item);
#endif
        PushWorkItem_Unsafe(item);
    }

    REALLY_INLINE void GC::PushWorkItem_Unsafe(GCWorkItem item)
    {
        if (!m_incrementalWork.Push(item))
            SignalMarkStackOverflow(item);
    }
#endif

#ifdef _DEBUG
    void GC::WorkItemInvariants(GCWorkItem item)
    {
        GCAssert(item.ptr != NULL);
        if (item.IsGCItem())
        {
            GCAssert(IsPointerToGCObject(GetRealPointer(item.ptr)));
            GCAssert(ContainsPointers(item.ptr));
            GCAssert(!IsRCObject(item.ptr) || ((RCObject*)item.ptr)->composite != 0);
            GCAssert((GetGCBits(GetRealPointer(item.ptr)) & (kQueued|kMark)) == kQueued);
        }
        else
        {
            // Some roots are on GC pages - a little unclear why, as of yet.  So for
            // now just require non-GCItems not to point to GC objects.
            GCAssert(!IsPointerToGCPage(GetRealPointer(item.ptr)) || !IsPointerToGCObject(GetRealPointer(item.ptr)));
        }
    }
#endif
    
    void GC::PushWorkItem_MayFail(GCWorkItem &item)
    {
        if (item.ptr)
            PushWorkItem(item);
    }

#ifdef _DEBUG
    bool GC::Trace(const void *stackStart/*=NULL*/, uint32_t stackSize/*=0*/)
    {
        SAMPLE_FRAME("[mark]", core());

        // Kill incremental mark since we're gonna wipe the marks.
        marking = false;
        ClearMarkStack();
        m_barrierWork.Clear();

        // Clear all mark bits.
        ClearMarks();

        SAMPLE_CHECK();

        MarkAllRoots();

        SAMPLE_CHECK();

        if(stackStart == NULL) {
            // grab the stack, push it, and
            MarkQueueAndStack();
        } else {
            GCWorkItem item(stackStart, stackSize, GCWorkItem::kNonGCObject);
            PushWorkItem(item);
            Mark();
        }

        SAMPLE_CHECK();

        bool failure = m_markStackOverflow;

        ClearMarks();

        return !failure;
    }
#endif

    GC::RCRootSegment::RCRootSegment(GC* gc, void* mem, size_t size)
        : GCRoot(gc, mem, size)
        , mem(mem)
        , size(size)
        , prev(NULL)
        , next(NULL)
    {}

    void* GC::AllocRCRoot(size_t size)
    {
        const int hdr_size = (sizeof(void*) + 7) & ~7;

        GCHeap::CheckForAllocSizeOverflow(size, hdr_size);

        union {
            char* block;
            uintptr_t* block_u;
        };
        block = mmfx_new_array_opt(char, size + hdr_size, MMgc::kZero);
        void* mem = (void*)(block + hdr_size);
        RCRootSegment *segment = new RCRootSegment(this, mem, size);
        *block_u = (uintptr_t)segment;
        AddRCRootSegment(segment);
        return mem;
    }

    void GC::FreeRCRoot(void* mem)
    {
        const int hdr_size = (sizeof(void*) + 7) & ~7;
        union {
            char* block;
            RCRootSegment** segmentp;
        };
        block = (char*)mem - hdr_size;
        RCRootSegment* segment = *segmentp;
        RemoveRCRootSegment(segment);
        delete segment;
        mmfx_delete_array(block);
    }

    void GC::CollectionWork()
    {
        if (nogc)
            return;

        if (incremental) {
            // If we're reaping don't do any work, this simplifies policy event timing and improves
            // incrementality.
            if (!collecting && !Reaping()) {
                if (!marking) {
                    StartIncrementalMark();
                }
                else if (policy.queryEndOfCollectionCycle()) {
                    FinishIncrementalMark(true);
                }
                else {
                    IncrementalMark();
                }
            }
        }
        else {
            // non-incremental collection
            Collect();
        }
    }

    // Note, the interaction with the policy manager in Alloc() should
    // be the same as in AllocDouble(), which is defined in GC.h.

    // In Alloc we have separate cases for large and small objects.  We want
    // small-object allocation to be as fast as possible.  Hence the relative
    // mess of #ifdefs below, and the following explanation.
    //
    // Normally we round up size to 8 bytes and add DebugSize and that sum is
    // the size that determines whether we use the small-object allocator or
    // the large-object one:
    //
    //   requestSize = ((size + 7) & ~7) + DebugSize()
    //
    // Then we shift that three places and subtract 1 to obtain the allocator
    // index:
    //
    //   index = (requestSize >> 3) - 1
    //         = ((((size + 7) & ~7) + DebugSize()) >> 3) - 1
    //
    // We want to optimize this.  Consider the case of a Release build where
    // DebugSize() == 0:
    //
    //         = (((size + 7) & ~7) >> 3) - 1
    //
    // Observe that the & ~7 is redundant because those bits will be lost,
    // and that 1 = (8 >> 3)
    //
    //         = ((size + 7) >> 3) - (8 >> 3)
    //         = (size + 7 - 8) >> 3
    //   index = (size - 1) >> 3
    //
    // In Release builds, the guard for small object allocation is
    //
    //   guard = requestSize <= kLargestAlloc
    //         = ((size + 7) & ~7) <= kLargestAlloc
    //
    // Yet the /effective/ guard, given that not all the bits of size are used
    // subsequently, is simply
    //
    //   guard = size <= kLargestAlloc
    //
    // To see this, consider that if size < kLargestAlloc then requestSize <= kLargestAlloc
    // and if size > kLargestAlloc then requestSize > kLargestAlloc, because requestSize
    // is rounded up to an 8-byte boundary and kLargestAlloc is already rounded to an 8-byte
    // boundary.
    //
    // So in the small-object case in Release builds we use the simpler guard, and defer
    // the rounding and allocation overflow checking to the large-object case.

#ifdef MMGC_MEMORY_INFO
    #ifndef _DEBUG
        #error "Really need MMGC_MEMORY_INFO to imply _DEBUG"
    #endif
#endif
#ifdef MMGC_MEMORY_PROFILER
    #ifndef MMGC_HOOKS
        #error "Really need MMGC_MEMORY_PROFILER to imply MMGC_HOOKS"
    #endif
#endif

    void *GC::Alloc(size_t size, int flags/*0*/)
    {
#ifdef _DEBUG
        GCAssertMsg(size > 0, "cannot allocate a 0 sized block");
        GCAssertMsg(onThread(), "GC called from different thread!");

        if(!nogc && stackEnter == NULL) {
            GCAssertMsg(false, "A MMGC_GCENTER macro must exist on the stack");
            GCHeap::SignalInconsistentHeapState("MMGC_GCENTER missing");
            /*NOTREACHED*/
            return NULL;
        }

        // always be marking in pedantic mode
        if(incrementalValidationPedantic) {
            if(!marking) {
                if (!Reaping()) {
                    StartIncrementalMark();
                }
            }
        }
#endif
#ifdef AVMPLUS_SAMPLER
        avmplus::AvmCore *core = (avmplus::AvmCore*)GetGCContextVariable(GCV_AVMCORE);
        if(core)
            core->sampleCheck();
#endif

#if defined _DEBUG || defined MMGC_MEMORY_PROFILER
        const size_t askSize = size;    // preserve this for statistics gathering and profiling
#endif
#if defined _DEBUG
        GCHeap::CheckForAllocSizeOverflow(size, 7+DebugSize());
        size = (size+7)&~7;             // round up to multiple of 8
        size += DebugSize();            // add in some (possibly zero) multiple of 8 bytes for debug information
#endif

        void *item;                     // the allocated object (a user pointer!), or NULL

        // In Release builds the calls to the underlying Allocs should end up being compiled
        // as tail calls with reasonable compilers.  Try to keep it that way.

        if (size <= kLargestAlloc)
        {
            // This is the fast lookup table implementation to find the right allocator.
            // The table has been lifted into an instance variable because the Player is
            // compiled with PIC and GCC generates somewhat gnarly code for that.
#ifdef _DEBUG
            const unsigned index = sizeClassIndex[(size>>3)-1];
#else
            const unsigned index = sizeClassIndex[(size-1)>>3];
#endif

            // The table avoids a thre-way decision tree.
            GCAlloc **allocs = allocsTable[flags & (kRCObject|kContainsPointers)];

            // assert that I fit
            GCAssert(size <= allocs[index]->GetItemSize());

            // assert that I don't fit (makes sure we don't waste space)
            GCAssert( (index==0) || (size > allocs[index-1]->GetItemSize()));

#if defined _DEBUG || defined MMGC_MEMORY_PROFILER
            item = allocs[index]->Alloc(askSize, flags);
#else
            item = allocs[index]->Alloc(flags);
#endif
        }
        else
        {
#ifndef _DEBUG
            GCHeap::CheckForAllocSizeOverflow(size, 7+DebugSize());
            size = (size+7)&~7; // round up to multiple of 8
            size += DebugSize();
#endif
#if defined _DEBUG || defined MMGC_MEMORY_PROFILER
            item = largeAlloc->Alloc(askSize, size, flags);
#else
            item = largeAlloc->Alloc(size, flags);
#endif
        }

        // Hooks are run by the lower-level allocators, which also signal
        // allocation work and trigger GC.

        GCAssert(item != NULL || (flags & kCanFail) != 0);

#ifdef _DEBUG
        // Note GetUserPointer(item) only required for DEBUG builds and for non-NULL pointers.

        if(item != NULL) {
            item = GetUserPointer(item);
            bool shouldZero = (flags & kZero) || incrementalValidationPedantic;

            // in debug mode memory is poisoned so we have to clear it here
            // in release builds memory is zero'd to start and on free/sweep
            // in pedantic mode uninitialized data can trip the write barrier
            // detector, only do it for pedantic because otherwise we want the
            // mutator to get the poisoned data so it crashes if it relies on
            // uninitialized values
            if(shouldZero) {
                VMPI_memset(item, 0, Size(item));
            }
        }
#endif

        return item;
    }

    // Mmmm.... gcc -O3 inlines Alloc into this in Release builds :-)

    void *GC::OutOfLineAllocExtra(size_t size, size_t extra, int flags)
    {
        return AllocExtra(size, extra, flags);
    }

    void GC::AbortFree(const void* item)
    {
        // Always clear the contents to avoid false retention of data: the
        // object will henceforth be scanned conservatively, and it may be
        // reachable from the stack or from other objects (dangling pointers
        // caused by improper use of Free(), or non-pointers interpreted
        // as pointers by the conservative scanner).
        Zero(item);

        // FIXME - https://bugzilla.mozilla.org/show_bug.cgi?id=589102.
        // The following actions presume we got here via delete, but that may not
        // always be true, and if we didn't then it isn't right to clear the
        // finalized bit, the weak ref bit, and possibly not the exactly traced bit.
        
        // Perform all cleanup actions
        if(IsFinalized(item))
            ClearFinalized(item);
        if(HasWeakRef(item))
            ClearWeakRef(item);
        
        // This is necessary if the destructor has been run because the destructor snaps
        // the vtable back to GCTraceableBase, which has illegal-to-call base methods for
        // gcTrace and gcTraceLarge.  Those base methods are there to ensure that we
        // do not try to exactly trace destructed objects.
        if(IsExactlyTraced(item))
            ClearExactlyTraced(item);
    }

    void GC::Zero(const void* userptr)
    {
        if (IsFinalized(userptr)) {
            GCFinalizedObject* obj = (GCFinalizedObject*)userptr;
            VMPI_memset((char*)obj + sizeof(GCFinalizedObject), 0, GC::Size(obj) - sizeof(GCFinalizedObject));
        }
        else if (IsExactlyTraced(userptr)) {
            GCTraceableObject* obj = (GCTraceableObject*)userptr;
            VMPI_memset((char*)obj + sizeof(GCTraceableObject), 0, GC::Size(obj) - sizeof(GCTraceableObject));
        }
        else {
            GCObject* obj = (GCObject*)userptr;
            VMPI_memset((char*)obj + sizeof(GCObject), 0, GC::Size(obj) - sizeof(GCObject));
        }
    }
    
    // Observe that nbytes is never more than kBlockSize, and the budget applies only to
    // objects tied up in quick lists, not in on-block free lists.  So given that the
    // total budget for the GC is at least kBlockSize, the loop is guaranteed to terminate.

    void GC::ObtainQuickListBudget(size_t nbytes)
    {
        // Flush quick lists until we have enough for the requested budget.  We
        // pick victims in round-robin fashion: there's a major iterator that
        // selects the allocator pool, and a minor iterator that selects an
        // allocator in that pool.

        while (remainingQuickListBudget <= nbytes) {
            GCAlloc** allocs = NULL;
            switch (victimIterator % 3) {
                case 0: allocs = containsPointersAllocs; break;
                case 1: allocs = containsPointersRCAllocs; break;
                case 2: allocs = noPointersAllocs; break;
            }
            allocs[victimIterator / 3]->CoalesceQuickList();
            victimIterator = (victimIterator + 1) % (3*kNumSizeClasses);
        }

        remainingQuickListBudget -= nbytes;
    }

    void GC::RelinquishQuickListBudget(size_t nbytes)
    {
        remainingQuickListBudget += nbytes;
    }

    // I can think of two alternative policies for handling dependent allocations.
    //
    // One is to treat all memory the same: external code calls SignalDependentAllocation
    // and SignalDependentDeallocation to account for the volume of data that are
    // dependent on but not allocated by the GC, and the GC incorporates these data
    // into policy decisions, heap target computation, and so on.
    //
    //   (Benefits: few surprises policy-wise.
    //
    //   Problems: If the volume (in bytes) of dependent data swamps the normal data
    //   then the collection policy may not work all that well -- collection cost may be
    //   too high, and memory usage may also be too high because the budget is L times
    //   the live memory, which may include a lot of bitmap data.)
    //
    // The other is to treat dependent memory differently.  SignalDependentAllocation
    // and SignalDependentDeallocation will account for the external memory, and if
    // the volume of dependent memory is high relative to the budget (which is
    // computed without regard for the volume of dependent memory) then those two
    // methods will drive the collector forward one step.
    //
    //   (Benefits: not overly sensitive to the volume of bitmap data, especially in
    //   computing the budget, yet a sufficient number of allocations will force the gc
    //   cycle to complete.
    //
    //   Problems: It is a bit ad-hoc and it may fail to reclaim a large volume of
    //   bitmap data quickly enough.)
    //
    // I'm guessing the former is better, for now.

    void GC::SignalDependentAllocation(size_t nbytes)
    {
        policy.signalDependentAllocation(nbytes);
        SignalAllocWork(nbytes);
    }

    void GC::SignalDependentDeallocation(size_t nbytes)
    {
        policy.signalDependentDeallocation(nbytes);
        SignalFreeWork(nbytes);
    }

    void GC::ClearMarks()
    {
        // ClearMarks may sweep, although I'm far from sure that that's a good idea,
        // as SignalImminentAbort calls ClearMarks.

        EstablishSweepInvariants();

        for (int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->ClearMarks();
            containsPointersAllocs[i]->ClearMarks();
            noPointersAllocs[i]->ClearMarks();
        }
        largeAlloc->ClearMarks();
        m_markStackOverflow = false;
    }

    void GC::Finalize()
    {
        ClearUnmarkedWeakRefs();

        for(int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->Finalize();
            containsPointersAllocs[i]->Finalize();
            noPointersAllocs[i]->Finalize();
        }
        largeAlloc->Finalize();
        finalizedValue = !finalizedValue;


        for(int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->m_finalized = false;
            containsPointersAllocs[i]->m_finalized = false;
            noPointersAllocs[i]->m_finalized = false;
        }
    }

    void GC::SweepNeedsSweeping()
    {
        EstablishSweepInvariants();

        // clean up any pages that need sweeping
        for(int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->SweepNeedsSweeping();
            containsPointersAllocs[i]->SweepNeedsSweeping();
            noPointersAllocs[i]->SweepNeedsSweeping();
        }
    }

    void GC::EstablishSweepInvariants()
    {
        for(int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->CoalesceQuickList();
            containsPointersAllocs[i]->CoalesceQuickList();
            noPointersAllocs[i]->CoalesceQuickList();
        }
    }

    void GC::ClearMarkStack()
    {
        // GCRoot have pointers into the mark stack, clear them.
        {
            MMGC_LOCK(m_rootListLock);
            GCRoot *r = m_roots;
            while(r) {
                r->ClearMarkStackSentinelPointer();
                r = r->next;
            }
        }
        m_incrementalWork.Clear();
    }

    /*static*/
    void GC::SetHasWeakRef(const void *userptr, bool flag)
    {
        const void *realptr = GetRealPointer(userptr);
        GCAssert(GetGC(realptr)->IsPointerToGCObject(realptr));
        if (flag) {
            GetGCBits(realptr) |= kHasWeakRef;
            // Small-object allocators maintain an extra flag
            // about weak objects in a block, need to set that
            // flag here.
            if (!GCLargeAlloc::IsLargeBlock(realptr))
                GCAlloc::SetBlockHasWeakRef(userptr);
        }
        else
            GetGCBits(realptr) &= ~kHasWeakRef;
    }
    
    void GC::ClearUnmarkedWeakRefs()
    {
        GCHashtable::Iterator it(&weakRefs);

        while (it.nextKey() != NULL) {
            GCWeakRef* w = (GCWeakRef*)it.value();
            GCObject* o = w->peek();
            if (o != NULL && !GC::GetMark(o))
                ClearWeakRef(o, false);
        }
        weakRefs.prune();
    }

    void GC::ForceSweepAtShutdown()
    {
        // There are two preconditions for Sweep: the mark stacks must be empty, and
        // the queued bits must all be clear (except as part of kFreelist).
        //
        // We are doing this at shutdown, so don't bother with pushing the marking through
        // to the end; just clear the stacks, clear the mark bits, and sweep.  The objects
        // will be finalized and deallocated and the blocks will be returned to the block
        // manager.

        ClearMarkStack();
        m_barrierWork.Clear();

        ClearMarks();

        // System invariant: collecting == false || marking == true
        marking = true;
        Sweep();
        marking = false;
    }

    void GC::Sweep()
    {
        // Applications using -memstats for peak heap measurements need info printed before the sweep

        if(heap->Config().gcstats) {
            gclog("[mem] sweep-start\n");
        }
        
        // 'collecting' must be true because it indicates allocations should
        // start out marked and the write barrier should short-circuit (not
        // record any hits).  We can't rely on write barriers to mark objects
        // during finalization below since presweep or finalization could write
        // a new GC object to a root.

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

        // This clears the quick lists in the small-block allocators.  It's crucial
        // that we do that before we set 'collecting' and call any callbacks, because
        // the cleared quick lists make sure that the slow allocation path that
        // checks m_gc->collecting is taken, and that is required in order to
        // allocate objects as marked under some circumstances.

        EstablishSweepInvariants();

        collecting = true;
        zct.StartCollecting();

        SAMPLE_FRAME("[sweep]", core());
        sweeps++;

        size_t heapSize = heap->GetUsedHeapSize();

#ifdef MMGC_MEMORY_PROFILER
        if(heap->Config().autoGCStats) {
            GCLog("Before sweep memory info:\n");
            DumpMemoryInfo();
        }
#endif

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

        presweeping = true;
        // invoke presweep on all callbacks
        for ( GCCallback *cb = m_callbacks; cb ; cb = cb->nextCB )
            cb->presweep();
        presweeping = false;

        SAMPLE_CHECK();

        // The presweep callbacks can't drive marking or trigger write barriers as the barrier is disabled,
        // but they can cause elements to be pushed onto the mark stack explicitly and it's necessary to call mark.
        // One example of callback that pushes work items is the Sampler::presweep().  Another is the read
        // barrier in GCWeakRef::get() - see Bugzilla 572331.
        do {
            if (m_markStackOverflow) {
                m_markStackOverflow = false;
                HandleMarkStackOverflow();
            }
            Mark();
        } while (m_markStackOverflow);

        SAMPLE_CHECK();

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

#ifdef MMGC_HEAP_GRAPH
        pruneBlacklist();
#endif

        Finalize();

        SAMPLE_CHECK();

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

        int sweepResults = 0;

        // ISSUE: this could be done lazily at the expense other GC's potentially expanding
        // unnecessarily, not sure its worth it as this should be pretty fast
        GCAlloc::GCBlock *b = smallEmptyPageList;
        while(b) {
            GCAlloc::GCBlock *next = GCAlloc::Next(b);
            GCAlloc* alloc = (GCAlloc*)b->alloc;
#ifdef _DEBUG
            alloc->SweepGuts(b);
#endif
            alloc->FreeChunk(b);

            sweepResults++;
            b = next;
        }
        smallEmptyPageList = NULL;

        SAMPLE_CHECK();

        GCLargeAlloc::LargeBlock *lb = largeEmptyPageList;
        while(lb) {
            GCLargeAlloc::LargeBlock *next = GCLargeAlloc::Next(lb);
#ifdef MMGC_HOOKS
            if(heap->HooksEnabled())
                heap->FreeHook(GetUserPointer(lb->GetObject()), lb->size - DebugSize(), uint8_t(GCHeap::GCSweptPoison));
#endif
            int numBlocks = lb->GetNumBlocks();
            sweepResults += numBlocks;
            VALGRIND_MEMPOOL_FREE(lb, lb);
            VALGRIND_MEMPOOL_FREE(lb, lb->GetObject());
            VALGRIND_DESTROY_MEMPOOL(lb);
            FreeBlock(lb, numBlocks);
            lb = next;
        }
        largeEmptyPageList = NULL;

        if (heap->Config().eagerSweeping)
            SweepNeedsSweeping();

        // we potentially freed a lot of memory, tell heap to regulate
        heap->Decommit();

        SAMPLE_CHECK();

#ifdef MMGC_MEMORY_PROFILER
        if(heap->Config().autoGCStats) {
            GCLog("After sweep memory info:\n");
            DumpMemoryInfo();
        }
#endif

        // don't want postsweep to fire WB's
        collecting = false;
        marking = false;
        zct.EndCollecting();

        // invoke postsweep callback
        for ( GCCallback *cb = m_callbacks; cb ; cb = cb->nextCB )
            cb->postsweep();

        SAMPLE_CHECK();

        if(heap->Config().gcstats) {
            // include large pages given back
            sweepResults += int(heapSize - heap->GetUsedHeapSize());
            double millis = duration(sweepStart);
            gclog("[mem] sweep(%d) reclaimed %d whole pages (%d kb) in %.2f millis (%.4f s)\n",
                sweeps, sweepResults, sweepResults*GCHeap::kBlockSize / 1024, millis,
                duration(t0)/1000);
        }

#ifdef MMGC_HEAP_GRAPH
        printBlacklist();
#endif

    }

    void* GC::AllocBlock(int size, PageMap::PageType pageType, bool zero, bool canFail)
    {
        GCAssert(size > 0);

        void *item = heapAlloc(size, GCHeap::kExpand| (zero ? GCHeap::kZero : 0) | (canFail ? GCHeap::kCanFail : 0));

        // mark GC pages in page map, small pages get marked one,
        // the first page of large pages is 3 and the rest are 2
        if(item) {
            MarkGCPages(item, 1, pageType);
            if(pageType == PageMap::kGCLargeAllocPageFirst) {
                MarkGCPages((char*)item+GCHeap::kBlockSize, size - 1, PageMap::kGCLargeAllocPageRest);
            }
        }

        return item;
    }

    void GC::FreeBlock(void *ptr, uint32_t size)
    {
        // Bugzilla 551833:  Unmark first so that any OOM or other action triggered
        // by heapFree does not examine bits representing pages that are gone.
        UnmarkGCPages(ptr, size);
        heapFree(ptr, size, false);
    }

    void *GC::FindBeginningGuarded(const void *gcItem, bool allowGarbage)
    {
        (void)allowGarbage;
        void *realItem = NULL;
        int bits = GetPageMapValueGuarded((uintptr_t)gcItem);
        switch(bits)
        {
            case PageMap::kGCAllocPage:
            {
                GCAlloc::GCBlock* b = GCAlloc::GetBlock(gcItem);
                if(gcItem < b->items)
                    return NULL;
                realItem = GCAlloc::FindBeginning(gcItem);
                break;
            }
            case PageMap::kGCLargeAllocPageFirst:
            {
                realItem = GCLargeAlloc::GetLargeBlock(gcItem)->GetObject();
                if(gcItem < realItem)
                    return NULL;
                break;
            }
            case PageMap::kGCLargeAllocPageRest:
                while(bits == PageMap::kGCLargeAllocPageRest)
                {
                    gcItem = (void*) ((uintptr_t)gcItem - GCHeap::kBlockSize);
                    bits = GetPageMapValue((uintptr_t)gcItem);
                }
                // can't use GCLargeAlloc::FindBeginning it asserts on header pointers
                realItem = GCLargeAlloc::GetLargeBlock(gcItem)->GetObject();
                break;
            default:
                GCAssertMsg(allowGarbage, "FindBeginningGuarded must not be called on non-managed addresses");
                // The NULL return is a documented effect of this function, and is desired, despite
                // the assert above.
                return NULL;
        }
        return GetUserPointer(realItem);
    }

    void GC::Mark()
    {
        markerActive++;
        while(m_incrementalWork.Count()) {
            GCWorkItem item = m_incrementalWork.Pop();
            MarkItem(item);
        }
        markerActive--;
    }

    // This must not trigger OOM handling.  It is /possible/ to restructure the
    // function to allow the use of heapAlloc() and heapFree() but the contortions
    // and resulting fragility really do not seem worth it.  (Consider that
    // heapAlloc can trigger OOM which can invoke GC which can run finalizers
    // which can perform allocation that can cause MarkGCPages to be reentered.)
    //
    // The use of non-OOM functions may of course lead to worse OOM behavior, but
    // if the allocation of large page maps cause OOM events as a result of
    // increased fragmentation then the proper fix would be to restructure the page
    // map to be less monolithic.
    //
    // (See Bugzilla 551833.)

    void GC::MarkGCPages(void *item, uint32_t numPages, PageMap::PageType to)
    {
        pageMap.ExpandSetAll(heap, item, numPages, to);
    }

    void GC::UnmarkGCPages(void *item, uint32_t numpages)
    {
        pageMap.ClearAddrs(item, numpages);
    }

    void GC::CleanStack(bool force)
    {
        if(!force && (stackCleaned || rememberedStackTop == 0))
            return;
        stackCleaned = true;
        VMPI_callWithRegistersSaved(GC::DoCleanStack, this);
    }

    /*static*/
    void GC::DoCleanStack(void* stackPointer, void* arg)
    {
        GC* gc = (GC*)arg;
        if( ((char*) stackPointer > (char*)gc->rememberedStackTop) && ((char *)gc->stackEnter > (char*)stackPointer)) {
            size_t amount = (char*)stackPointer - (char*)gc->rememberedStackTop;
            VMPI_cleanStack(amount);
        }
    }

    void GC::MarkQueueAndStack(bool scanStack)
    {
        if(scanStack)
            VMPI_callWithRegistersSaved(GC::DoMarkFromStack, this);
        else
            Mark();
    }

    /*static*/
    void GC::DoMarkFromStack(void* stackPointer, void* arg)
    {
        GC* gc = (GC*)arg;
        char* stackBase = (char*)gc->GetStackTop();

        // this is where we will clear to when CleanStack is called
        if(gc->rememberedStackTop < stackPointer)
            gc->rememberedStackTop = stackPointer;

        // Push the stack onto the mark stack and then mark synchronously until
        // everything reachable from the stack has been marked.

        GCWorkItem item(stackPointer, uint32_t(stackBase - (char*)stackPointer), GCWorkItem::kStackMemory);
        gc->PushWorkItem(item);
        gc->Mark();
    }

    struct CreateRootFromCurrentStackArgs
    {
        GC* gc;
        void (*fn)(void* arg);
        void *arg;
    };

    static void DoCreateRootFromCurrentStack(void* stackPointer, void* arg)
    {
        CreateRootFromCurrentStackArgs* context = (CreateRootFromCurrentStackArgs*)arg;
        MMgc::GC::AutoRCRootSegment root(context->gc, stackPointer, uint32_t((char*)context->gc->GetStackTop() - (char*)stackPointer));
        MMgc::GCAutoEnterPause mmgc_enter_pause(context->gc);
        context->fn(context->arg);                      // Should not be a tail call as those stack variables have destructors
    }

    void GC::CreateRootFromCurrentStack(void (*fn)(void* arg), void* arg)
    {
        CreateRootFromCurrentStackArgs arg2;
        arg2.gc = this;
        arg2.fn = fn;
        arg2.arg = arg;
        VMPI_callWithRegistersSaved(DoCreateRootFromCurrentStack, &arg2);
    }

    void GCRoot::init(GC* _gc, const void *_object, size_t _size)
    {
        gc = _gc;
        object = _object;
        size = _size;
        markStackSentinel = NULL;
        GCAssert(size % 2 == 0);
        gc->AddRoot(this);
    }

    GCRoot::GCRoot(GC * _gc)
    {
        init(_gc, this, FixedMalloc::GetFixedMalloc()->Size(this));
    }

    GCRoot::GCRoot(GC * _gc, const void * _object, size_t _size)
    {
        init(_gc, _object, _size);
    }

    GCRoot::~GCRoot()
    {
        Destroy();
    }

    void GCRoot::Set(const void * _object, size_t _size)
    {
        SetMarkStackSentinelPointer(NULL);
        this->object = _object;
        this->size = _size;
    }

    void GCRoot::SetMarkStackSentinelPointer(GCWorkItem *wi)
    {
        if(markStackSentinel != NULL) {
            // There is already a sentinel for this item and above
            // will be a fragment of the root, clear them both since
            // we need to rescan the whole thing.
            GCAssert(markStackSentinel->GetSentinelPointer() == this);
            GCWorkItem *markStackItem = gc->m_incrementalWork.GetItemAbove(markStackSentinel);

            // markStackItem can be NULL if the sentinel was on the top of the stack.
            // Its also possible we popped the last fragment and haven't popped the sentinel yet,
            // check that the markStackItem is for this root before clearing.
            if(markStackItem && markStackItem->iptr + markStackItem->GetSize() == uintptr_t(End())) {
                markStackItem->Clear();
            }
            markStackSentinel->Clear();
        }
        markStackSentinel = wi;
    }

    void GCRoot::Destroy()
    {
        Set(NULL, 0);
        if(gc) {
            gc->RemoveRoot(this);
        }
        gc = NULL;
    }

    GCCallback::GCCallback(GC * _gc) : gc(_gc)
    {
        gc->AddCallback(this);
    }

    GCCallback::~GCCallback()
    {
        if(gc) {
            gc->RemoveCallback(this);
        }
    }

    void GCCallback::Destroy()
    {
        if(gc) {
            gc->RemoveCallback(this);
        }
        gc = NULL;
    }

#ifdef _DEBUG
    bool GC::IsPointerIntoGCObject(const void *item)
    {
        int bits = GetPageMapValueGuarded((uintptr_t)item);
        switch(bits) {
            case PageMap::kGCAllocPage:
                return GCAlloc::IsPointerIntoGCObject(item);
            case PageMap::kGCLargeAllocPageFirst:
                return item >= GCLargeAlloc::FindBeginning(item);
            case PageMap::kGCLargeAllocPageRest:
                return true;
            default:
                return false;
        }
    }
#endif

    bool GC::IsRCObjectSafe(const void *userptr)
    {
        return userptr != NULL && IsPointerToGCObject(GetRealPointer(userptr)) && GC::IsRCObject(userptr);
    }

#if 0
    // this is a release ready tool for hunting down freelist corruption
    void GC::CheckFreelists()
    {
        GCAlloc **allocs = containsPointersAllocs;
        for (int l=0; l < GC::kNumSizeClasses; l++) {
            GCAlloc *a = allocs[l];
            GCAlloc::GCBlock *_b = a->m_firstBlock;
            while(_b) {
                void *fitem = _b->firstFree;
                void *prev = 0;
                while(fitem) {
                    if((uintptr_t(fitem) & 7) != 0) {
                        _asm int 3;
                        break;
                    }
                    if((uintptr_t(fitem) & GCHeap::kBlockMask) != uintptr_t(_b))
                        _asm int 3;
                    prev = fitem;
                    fitem = *(void**)fitem;
                }
                _b = _b->next;
            }
        }
    }
#endif

#ifdef _DEBUG

    void GC::RCObjectZeroCheck(RCObject *item)
    {
        size_t size = Size(item)/sizeof(uint32_t);
        uint32_t *p = (uint32_t*)item;
        uint32_t *limit = p+size;
        // skip vtable, first 4 bytes are cleared in Alloc
        p++;
#ifdef MMGC_64BIT
        p++; // vtable is 8-bytes
        size--;
#endif
        // in incrementalValidation mode manually deleted items
        // aren't put on the freelist so skip them
        if(incrementalValidation) {
            if(*p == uint32_t(GCHeap::FXFreedPoison))
                return;
        }
        for ( ; p < limit ; p++ )
        {
            if(*p)
            {
                PrintAllocStackTrace(item);
                GCAssertMsg(false, "RCObject didn't clean up itself.");
                // If you hit this assert, use the debugger to cast 'item' to the type indicated by the call stack
                // in the output (you'll have to qualify the scope - (coreplayer::View*) rather than (View*)
                // and check to see that all fields are 0 (even boolean members). This Is a
                // performance optimization that lets the GC avoid zero'ing the whole thing itself.
            }
        }
    }

#endif

    void GC::gclog(const char *format, ...)
    {
        char buf[4096];
        va_list argptr;

        va_start(argptr, format);
        VMPI_vsnprintf(buf, ARRAY_SIZE(buf), format, argptr);
        va_end(argptr);

        VMPI_log(buf);

        // log gross stats any time anything interesting happens
        static bool g_in_gclog = false;

        bool was_in_gclog;
        {
            MMGC_LOCK(heap->gclog_spinlock);
            was_in_gclog = g_in_gclog;
            g_in_gclog = true;
        }

        if(!was_in_gclog && !destroying)
            heap->DumpMemoryInfo();

        {
            MMGC_LOCK(heap->gclog_spinlock);
            g_in_gclog = was_in_gclog;
        }
    }

    void GC::DumpAlloc(GCAlloc *a, size_t& internal_waste, size_t& overhead)
    {
        int inUse =  a->GetNumAlloc() * a->GetItemSize();
        int maxAlloc =  a->GetMaxAlloc()* a->GetItemSize();

        overhead = maxAlloc-inUse;
        internal_waste = 0;

        int efficiency = maxAlloc > 0 ? inUse * 100 / maxAlloc : 100;
        if(inUse) {
            const char *name = a->ContainsPointers() ? a->ContainsRCObjects() ? "rc" : "gc" : "opaque";
            if(heap->config.verbose)
                GCLog("[mem] gc[%d] %s allocator:   %d%% efficiency %d bytes (%d kb) in use out of %d bytes (%d kb)\n", a->GetItemSize(), name, efficiency, inUse, inUse>>10, maxAlloc, maxAlloc>>10);
#ifdef MMGC_MEMORY_PROFILER
            if(heap->HooksEnabled())
            {
                size_t askSize = a->GetTotalAskSize();
                internal_waste = inUse - askSize;
                size_t internal_efficiency = askSize * 100 / inUse;
                if(heap->config.verbose)
                    GCLog("\t\t\t\t %u%% internal efficiency %u bytes (%u kb) actually requested out of %d bytes(%d kb)\n", internal_efficiency, (uint32_t) askSize, (uint32_t)(askSize>>10), inUse, inUse>>10);
            }
#endif
        }
    }

    void GC::DumpMemoryInfo()
    {
        size_t total = GetNumBlocks() * GCHeap::kBlockSize;

        size_t ask;
        size_t allocated;
        GetUsageInfo(ask, allocated);

        heap->log_percentage("[mem] \tmanaged overhead ", total-allocated, total);
#ifdef MMGC_MEMORY_PROFILER
        if(heap->HooksEnabled())
            heap->log_percentage("[mem] \tmanaged internal wastage", allocated-ask, allocated);
#endif

        if(ticksToMillis(markTicks()) != 0 && bytesMarked() != 0) {
            uint32_t markRate = (uint32_t) (bytesMarked() / (1024 * ticksToMillis(markTicks()))); // kb/ms == mb/s
            GCLog("[mem] \tmark rate %u mb/s\n", markRate);
        }
        GCLog("[mem] \tmark increments %d\n", markIncrements());
        GCLog("[mem] \tsweeps %d \n", sweeps);

        size_t total_overhead = 0;
        size_t total_internal_waste = 0;
        GCAlloc** allocators[] = {containsPointersRCAllocs, containsPointersAllocs, noPointersAllocs};
        for(int j = 0;j<3;j++)
        {
            GCAlloc** gc_alloc = allocators[j];

            for(int i=0; i < kNumSizeClasses; i++)
            {
                size_t internal_waste;
                size_t overhead;
                DumpAlloc(gc_alloc[i], internal_waste, overhead);
                total_internal_waste += internal_waste;
                total_overhead += overhead;
            }
        }
        GCLog("Overhead %u bytes (%u kb)\n", (uint32_t)total_overhead, (uint32_t)(total_overhead>>10));
#ifdef MMGC_MEMORY_PROFILER
        if(heap->HooksEnabled())
            GCLog("Internal Wastage %u bytes (%u kb)\n", (uint32_t)total_internal_waste, (uint32_t)(total_internal_waste>>10));
#endif
    }

#ifdef MMGC_MEMORY_PROFILER
    // It only makes sense to call this after a END_FinalizeAndSweep event and
    // before the next START_StartIncrementalMark event.
    void GC::DumpPauseInfo()
    {
        if (!nogc && incremental) {
            GCLog("[mem] \tpauses in GC, most recent (ms): startmark=%.2f incrementalmark=%.2f finalscan=%.2f finishmark=%.2f reap=%.2f\n",
                  double(ticksToMicros(policy.timeMaxStartIncrementalMarkLastCollection)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxIncrementalMarkLastCollection)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxFinalRootAndStackScanLastCollection)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxFinalizeAndSweepLastCollection)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxReapZCTLastCollection)) / 1000.0);
            GCLog("[mem] \tpauses in GC, entire run (ms): startmark=%.2f incrementalmark=%.2f finalscan=%.2f finishmark=%.2f reap=%.2f\n",
                  double(ticksToMicros(policy.timeMaxStartIncrementalMark)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxIncrementalMark)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxFinalRootAndStackScan)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxFinalizeAndSweep)) / 1000.0,
                  double(ticksToMicros(policy.timeMaxReapZCT)) / 1000.0);
            GCLog("[mem] \tpause clustering in GC, most recent: gctime=%.2fms end-to-end=%.2fms;  mutator efficacy: %.2f%%\n",
                  double(ticksToMicros(policy.timeInLastCollection)) / 1000.0,
                  double(ticksToMicros(policy.timeEndToEndLastCollection)) / 1000.0,
                  policy.timeInLastCollection == 0 ? // Sometimes there are no collections
                  100.0 :
                  double(policy.timeEndToEndLastCollection - policy.timeInLastCollection) * 100.0 / double(policy.timeEndToEndLastCollection));
        }
    }
#endif // MMGC_MEMORY_PROFILER

#ifdef _DEBUG

    void GC::CheckFreelists()
    {
        for(int i=0; i < kNumSizeClasses; i++)
        {
            containsPointersAllocs[i]->CheckFreelist();
            containsPointersRCAllocs[i]->CheckFreelist();
            noPointersAllocs[i]->CheckFreelist();
        }
    }

    void GC::UnmarkedScan(const void *mem, size_t size)
    {
        uintptr_t lowerBound = pageMap.MemStart();
        uintptr_t upperBound = pageMap.MemEnd();

        uintptr_t *p = (uintptr_t *) mem;
        uintptr_t *end = p + (size / sizeof(void*));

        while(p < end)
        {
            uintptr_t val = *p++;

            if(val < lowerBound || val >= upperBound)
                continue;

            // normalize and divide by 4K to get index
            int bits = GetPageMapValue(val);
            switch(bits)
            {
            case PageMap::kNonGC:
                continue;
            case PageMap::kGCAllocPage:
                GCAssert(GCAlloc::ConservativeGetMark((const void*) (val&~7), true));
                break;
            case PageMap::kGCLargeAllocPageFirst:
                GCAssert(GCLargeAlloc::ConservativeGetMark((const void*) (val&~7), true));
                break;
            default:
                GCAssertMsg(false, "Invalid pageMap value");
                break;
            }
        }
    }

    // For every page in the address range known to this GC, scan the page conservatively
    // for pointers and assert that anything that looks like a pointer to an object
    // points to an object that's marked.
    //
    // FIXME: This looks like it could be prone to signaling false positives and crashes:
    // it scans memory that's marked kNonGC, and some of that memory could even be
    // unmapped at the VM level?

    void GC::FindUnmarkedPointers()
    {
        if(findUnmarkedPointers)
        {
            uintptr_t m = pageMap.MemStart();

            while(m < pageMap.MemEnd())
            {
                // divide by 4K to get index
                int bits = GetPageMapValue(m);
                if(bits == PageMap::kNonGC) {
                    UnmarkedScan((const void*)m, GCHeap::kBlockSize);
                    m += GCHeap::kBlockSize;
                } else if(bits == PageMap::kGCLargeAllocPageFirst) {
                    GCLargeAlloc::LargeBlock *lb = (GCLargeAlloc::LargeBlock*)m;
                    const void *item = GetUserPointer(lb->GetObject());
                    if(GetMark(item) && lb->containsPointers) {
                        UnmarkedScan(item, Size(item));
                    }
                    m += lb->GetNumBlocks() * GCHeap::kBlockSize;
                } else if(bits == PageMap::kGCAllocPage) {
                    // go through all marked objects
                    GCAlloc::GCBlock *b = (GCAlloc::GCBlock *) m;
                    GCAlloc* alloc = (GCAlloc*)b->alloc;
                    for (int i=0; i < alloc->m_itemsPerBlock; i++) {
                        // If the mark is 0, delete it.
                        void* item = (char*)b->items + alloc->m_itemSize*i;
                        if (!GetMark(item) && b->containsPointers) {
                            UnmarkedScan(GetUserPointer(item), alloc->m_itemSize - DebugSize());
                        }
                    }

                    m += GCHeap::kBlockSize;
                }
            }
        }
    }

    void GC::ProbeForMatch(const void *mem, size_t size, uintptr_t value, int recurseDepth, int currentDepth)
    {
        uintptr_t lowerBound = pageMap.MemStart();
        uintptr_t upperBound = pageMap.MemEnd();

        uintptr_t *p = (uintptr_t *) mem;
        uintptr_t *end = p + (size / sizeof(void*));

        int bits = GetPageMapValue((uintptr_t)mem);

        while(p < end)
        {
            uintptr_t val = *p++;

            if(val < lowerBound || val >= upperBound)
                continue;

            // did we hit ?
            if (val == value)
            {
                // ok so let's see where we are
                uintptr_t* where = p-1;
                GCHeap::HeapBlock* block = heap->AddrToBlock(where);
                //GCAssertMsg(block->inUse(), "Not sure how we got here if the block is not in use?");
                GCAssertMsg(block->committed, "Means we are probing uncommitted memory. not good");
                int* ptr;

                switch(bits)
                {
                case PageMap::kNonGC:
                    {
                        if (block->size == 1)
                        {
                            // fixed sized entries find out the size of the block
                            union {
                                char* fixed_c;
                                FixedAlloc::FixedBlock* fixed;
                            };
                            fixed_c = block->baseAddr;
                            int fixedsize = fixed->size;

                            // now compute which element we are
                            uintptr_t startAt = (uintptr_t) &(fixed->items[0]);
                            uintptr_t item = ((uintptr_t)where-startAt) / fixedsize;

                            ptr = (int*) ( startAt + (item*fixedsize) );
                        }
                        else
                        {
                            // fixed large allocs ; start is after the block
                            union {
                                char* ptr_c;
                                int* ptr_i;
                            };
                            ptr_c = block->baseAddr;
                            ptr = ptr_i;
                        }
                    }
                    break;

                default:
                    ptr = ((int*)FindBeginningGuarded(where)) - 2;
                    break;
                }

                int  taggedSize = *ptr;
                int* real = (ptr+2);

                GCDebugIndent(currentDepth*3);
                GCDebugMsg(false, "Location: 0x%08x  Object: 0x%08x (size %d)\n", where, real, taggedSize);
                GCDebugIndent(currentDepth*3);
                PrintAllocStackTrace(real);

                if (recurseDepth > 0)
                    WhosPointingAtMe(real, recurseDepth-1, currentDepth+1);
            }
        }
    }

    /**
     * This routine searches through all of GC memory looking for references to 'me'
     * It ignores already claimed memory thus locating active references only.
     * recurseDepth can be set to a +ve value in order to follow the chain of
     * pointers arbitrarily deep.  Watch out when setting it since you may see
     * an exponential blow-up (usu. 1 or 2 is enough).  'currentDepth' is for
     * indenting purposes and should be left alone.
     */
    void GC::WhosPointingAtMe(void* me, int recurseDepth, int currentDepth)
    {
        uintptr_t val = (uintptr_t)me;
        uintptr_t m = pageMap.MemStart();

        GCDebugIndent(currentDepth*3);
        GCDebugMsg(false, "[%d] Probing for pointers to : 0x%08x\n", currentDepth, me);
        while(m < pageMap.MemEnd())
        {
            int bits = GetPageMapValue(m);
            if(bits == PageMap::kNonGC)
            {
                ProbeForMatch((const void*)m, GCHeap::kBlockSize, val, recurseDepth, currentDepth);
                m += GCHeap::kBlockSize;
            }
            else if(bits == PageMap::kGCLargeAllocPageFirst)
            {
                GCLargeAlloc::LargeBlock *lb = (GCLargeAlloc::LargeBlock*)m;
                const void *item = GetUserPointer(lb->GetObject());
                if (GetMark(item) && lb->containsPointers)
                {
                    ProbeForMatch(item, Size(item), val, recurseDepth, currentDepth);
                }
                m += lb->GetNumBlocks() * GCHeap::kBlockSize;
            }
            else if(bits == PageMap::kGCAllocPage)
            {
                // go through all marked objects
                GCAlloc::GCBlock *b = (GCAlloc::GCBlock *) m;
                GCAlloc* alloc = (GCAlloc*)b->alloc;
                for (int i=0; i < alloc->m_itemsPerBlock; i++)
                {
                    void *item = (char*)b->items + alloc->m_itemSize*i;
                    if (GetMark(item) && b->containsPointers)
                    {
                        ProbeForMatch(GetUserPointer(item), alloc->m_itemSize - DebugSize(), val, recurseDepth, currentDepth);
                    }
                }
                m += GCHeap::kBlockSize;
            }
            else
            {
                GCAssertMsg(false, "Oh seems we missed a case...Tom any ideas here?");

            }
        }
    }
#undef ALLOCA_AND_FILL_WITH_SPACES
#endif


    void GC::StartIncrementalMark()
    {
        policy.signal(GCPolicyManager::START_StartIncrementalMark);     // garbage collection starts

        GCAssert(!marking);
        GCAssert(!collecting);
        GCAssert(!Reaping());       // bugzilla 564800

        lastStartMarkIncrementCount = markIncrements();

        // set the stack cleaning trigger
        stackCleaned = false;

        marking = true;

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

        SweepNeedsSweeping();

        // at this point every object should have no marks or be marked kFreelist
#ifdef _DEBUG
        for(int i=0; i < kNumSizeClasses; i++) {
            containsPointersRCAllocs[i]->CheckMarks();
            containsPointersAllocs[i]->CheckMarks();
            noPointersAllocs[i]->CheckMarks();
        }
#endif

#ifdef MMGC_HEAP_GRAPH
        markerGraph.clear();
#endif

        if (incremental)
            MarkAllRoots();

        policy.signal(GCPolicyManager::END_StartIncrementalMark);

        // FIXME (policy): arguably a bug to do this here if StartIncrementalMark has exhausted its quantum
        // doing eager sweeping.

        if (incremental)
            IncrementalMark();
    }

    // The mark stack overflow logic depends on this calling MarkItem directly
    // for each of the roots.

    void GC::MarkAllRoots(bool deep)
    {
        // Need to do this while holding the root lock so we don't end
        // up trying to scan a deleted item later, another reason to keep
        // the root set small.

        MMGC_LOCK(m_rootListLock);
        markerActive++;
        GCRoot *r = m_roots;
        while(r) {
            GCWorkItem item = r->GetWorkItem();
            if(item.ptr) {
                // If this root will be split push a sentinel item and store
                // a pointer to it in the root.   This will allow us to clean
                // the stack if the root is deleted.  See GCRoot::Destroy and
                // GC::HandleLargeMarkItem
                if(item.GetSize() > kMarkItemSplitThreshold) {
                    PushWorkItem(GCWorkItem(r, GCWorkItem::kGCRoot));
                    GCWorkItem *item = m_incrementalWork.Peek();
                    // test for mark stack overflow
                    if(item->GetSentinelPointer() == r)
                        r->SetMarkStackSentinelPointer(item);
                }
#ifdef MMGC_CONSERVATIVE_PROFILER
                MarkItem(item, true);
#else
                MarkItem(item);
#endif
                if (deep)
                    Mark();
            }
            r = r->next;
        }
        markerActive--;
    }

    // Recover from a mark stack overflow.
    //
    // Mark stack overflow occurs when an item cannot be pushed onto the mark stack because
    // the top mark stack segment is full and a new segment can't be allocated.  In
    // practice, any call to GC::PushWorkItem (or its callers, such as GC::Mark, GC::MarkItem,
    // GC::MarkAllRoots, GC::MarkQueueAndStack, and not least the write barrier GC::TrapWrite)
    // can cause a mark stack overflow.
    //
    // Since garbage collection cannot be allowed to abort the program as a result of
    // the allocation failure, but must run to completion, overflow is handled specially.
    // The mark stack Push method returns an error code, which is detected in GC::PushWorkItem,
    // which in turn calls GC::SignalMarkStackOverflow to handle the overflow.  Overflow
    // is handled by discarding some elements and setting the global m_markStackOverflow flag.
    //
    // Any code that needs to drive marking to completion - FinishIncrementalMark and Sweep
    // do, as they depend on the heap having been marked before running finalizers and
    // clearing out empty blocks - must test m_markStackOverflow: if it is set then it must
    // be cleared and the present method, GC::HandleMarkStackOverflow, is called to mop up.
    // The caller must perform this test repeatedly until the flag is no longer set.
    //
    // The job of HandleMarkStackOverflow is to find marked heap objects that point to
    // unmarked objects, and to mark those objects.  Effectively it uses the heap as a
    // queue of candidate objects, thus minimizing the use of the mark stack.  Since marking
    // uses the mark stack the marking performed by HandleMarkStackOverflow may also
    // overflow the mark stack, but once a marked object has been visited by
    // HandleMarkStackOverflow it will not point to any unmarked objects.  There are object
    // graphs containing pointers from objects visited later to objects skipped earlier
    // that may require recovery to be run multiple times, if marking overflows the mark
    // stack, but each recovery pass will mark all objects where the reference is from
    // an earlier object to a later object, and all non-overflowing subgraphs of those
    // objects in either direction.
    //
    // Performance might be an issue as the restart may happen several times and the
    // scanning performed by HandleMarkStackOverflow covers the entire heap every time.  It could
    // be more efficient to interleave restarting and marking (eg, never fill the mark stack
    // during restarting, but mark after filling it partly, and remember the place in the heap
    // where scanning left off, and then iterate), but we should cross that bridge if and when
    // restarting turns out to be a problem in practice.  (If it does, caching more mark stack
    // segments may be a better first fix, too.)

    void GC::HandleMarkStackOverflow()
    {
        // Crucial for completion that we do not push marked items.  MarkItem handles this
        // for us: it pushes referenced objects that are not marked.  (MarkAllRoots calls
        // MarkItem on each root.)

        MarkAllRoots(true);

        // For all iterator types, GetNextMarkedObject returns true if 'item' has been
        // updated to reference a marked, non-free object to mark, false if the allocator
        // instance has been exhausted.

        void* ptr;

        markerActive++;

        for(int i=0; i < kNumSizeClasses; i++) {
            GCAllocIterator iter1(containsPointersRCAllocs[i]);
            while (iter1.GetNextMarkedObject(ptr)) {
                GCWorkItem item(ptr, 0, GCWorkItem::kGCObject);
                MarkItem(item);
                Mark();
            }
            GCAllocIterator iter2(containsPointersAllocs[i]);
            while (iter2.GetNextMarkedObject(ptr)) {
                GCWorkItem item(ptr, 0, GCWorkItem::kGCObject);
                MarkItem(item);
                Mark();
            }
        }

        GCLargeAllocIterator iter3(largeAlloc);
        while (iter3.GetNextMarkedObject(ptr)) {
            GCWorkItem item(ptr, 0, GCWorkItem::kGCObject);
            MarkItem(item);
            Mark();
        }

        markerActive--;
    }

    // Signal that attempting to push 'item' onto 'stack' overflowed 'stack'.
    //
    // Either 'item' must be pushed onto the stack, replacing some other item there,
    // or any state information in the item that indicates that it is stacked must
    // be cleared, since it will not be pushed onto the stack.  What to do?
    //
    // The literature (Jones & Lins) does not provide a lot of guidance.  Intuitively it
    // seems that we want to maximize the number of items that remain on the stack so
    // that the marker will finish processing the maximal number of objects before we
    // enter the stack overflow recovery code (in HandleMarkStackOverflow, above).  Ergo
    // we drop 'item' on the floor.

    void GC::SignalMarkStackOverflow(GCWorkItem& item)
    {
        GCAssert(item.ptr != NULL);
        if (item.IsGCItem())
            ClearQueued(item.ptr);
        m_markStackOverflow = true;
    }

    // HandleLargeMarkItem handles work items that are too big to be
    // marked atomically.  It does so by splitting the work into chunks;
    // the incremental marker then gets an opportunity to stop marking 
    // after processing each chunk.
    //
    // An object is "too large" if its size is larger than kLargestAlloc.
    // There is an older technical reason for that having to do with
    // additional state space only being available in large objects,
    // as detailed in the following.
    //
    // Conceptually we split a large work item into two chunks: a
    // small head (which we mark now) and a large tail (which we push
    // onto the stack).  THE HEAD MUST BE MARKED FIRST because this
    // ensures that the mark on the object is set immediately; that
    // is necessary for write barrier correctness.
    //
    // Why use kLargestAlloc as the split value?
    //
    // Unfortunately for correctness THE HEAD MUST ALSO BE MARKED LAST,
    // because the queued bit is traditionally used to prevent the object
    // from being deleted explicitly by GC::Free while the object is
    // on the mark stack.  We can't have it both ways, so split objects
    // are protected against being freed by carrying another bit that
    // prevents deletion when it is set.  We only have this extra bit on
    // large objects (where there's plenty of space).  Thus the cutoff for 
    // splitting is exactly kLargestObject: only large objects that can
    // carry this bit are split.  (That reason predates the expansion
    // of per-object bits from four to eight.  Now that we have more header
    // bits we could carry the bit everywhere and choose a different
    // threshold.)
    //
    // In addition, the queued flag still prevents the object from
    // being deleted.
    //
    // The free-protection flags are reset by a special GCWorkItem sentinel
    // that is pushed on the stack below the two parts of the object that
    // is being split; when the sentinel is later popped, it resets the flag
    // and returns.
    //
    // The complexity with the free-protection flags may go away if we
    // move to a write barrier that does not depend on the queued bit,
    // for example, a card-marking barrier.
    //
    // If a mark stack overflow occurs the large tail may be popped
    // and discarded.  This is not a problem: the object as a whole
    // is marked, but points to unmarked storage, and the latter
    // objects will be picked up as per normal.  Discarding the
    // tail is entirely equivalent to discarding the work items that
    // would result from scanning the tail.
    //
    // Large GCRoots are also split here.  MarkAllRoots pushes a
    // sentinel item on the stack that will be right below the GCRoot.
    // If the GCRoot is deleted it uses the sentinel pointer to clear
    // the tail work item from GCRoot::Destroy along with the sentinel
    // itself.
    //
    // Conservatively marked objects are split so that the tail is a
    // non-gcobject regardless of whether the head is a gcobject.
    //
    // Exactly marked objects are not split per se, but state is kept on
    // the mark stack to allow the gcTraceLarge method to be called
    // repeatedly.
    //
    // When a large object is first encountered it is marked as visited, and
    // that's necessary for the write barrier.  However, it remains on the queue
    // without being marked as queued (since marked+queued == free) and anyway
    // that would prevent it from being added to the write barrier's queue.
    // Thus it is possible for an object, or part of it, to be on both
    // queues at the same time.  That's not incorrect, and it's not even
    // particularly inefficient, as the best we could do would be to pop
    // the object off the mark stack when it is pushed onto the barrier queue.
    //
    // Given partial marking of large objects it's not obvious that marking
    // will terminate (an object could be moved off the barrier stack by
    // IncrementalMark, then copied back onto the barrier stack by the write
    // barrier), but it does: mark work is driven by allocation, and when
    // allocation has reached a limit the final phase of GC is run which marks
    // whatever remains to be marked nonincrementally.

    bool GC::HandleLargeMarkItem(GCWorkItem &wi, size_t& size)
    {
        GCTraceableBase* exactlyTraced = NULL;
        size_t cursor = 0;

        if (wi.IsSentinel1Item())
        {
            if(wi.GetSentinel1Type() == GCWorkItem::kGCLargeAlloc)
            {
                // Unprotect an item that was protected earlier, see comment block above.
                GCLargeAlloc::UnprotectAgainstFree(wi.GetSentinelPointer());
            }

            if(wi.GetSentinel1Type() == GCWorkItem::kGCRoot)
            {
                // The GCRoot is no longer on the stack, clear the pointers into the stack.
                GCRoot *sentinelRoot = (GCRoot*)wi.GetSentinelPointer();
                sentinelRoot->ClearMarkStackSentinelPointer();
            }
            return true;
        }

        if (wi.IsGCItem())
        {
            // An ounce of prevention...
            GCAssert(ContainsPointers(wi.ptr));

            // Need to protect it against 'Free': push a magic item representing this object
            // that will prevent this split item from being freed, see comment block above.

            GCLargeAlloc::ProtectAgainstFree(wi.ptr);
            PushWorkItem(GCWorkItem(wi.ptr, GCWorkItem::kGCLargeAlloc));

            // Is it a large, exactly traced item?

            void *userptr = (void*)wi.ptr;
            void *realptr = GetRealPointer(userptr);

            gcbits_t& bits = GetGCBits(realptr);

            if ((bits & kVirtualGCTrace) == kVirtualGCTrace)
            {
                // Create a mark state for the large, exactly traced object.
                //
                // We have two words of information to store: the pointer to the object
                // (which we need in order to get the vtable) and the cursor value.  The
                // cursor value is not really very well bounded, and we don't want the
                // sentinel value to have too many insignificant low-order bits, so we
                // need to use two items here.
                //
                // It's important that the top item triggers action in the marker and that
                // the bottom item is inert and is just discarded if it appears by itself,
                // which is possible in the presence of mark stack overflows.

                // Set up large exactly traced object.  The cursor is zero and already set.
                exactlyTraced = (GCTraceableBase*)wi.ptr;

                // Mark the object though it remains on the queue, this means it may also
                // end up on the barrier stack while still on the mark stack but that's
                // fine, and inevitable.
                SetMark(exactlyTraced);

                policy.signalExactMarkWork(size);
                
                // Save the state: cursor underneath and object on top.
                PushWorkItem(GCWorkItem((void*)(cursor + 4), GCWorkItem::kInertPayload));
                PushWorkItem(GCWorkItem(wi.ptr, GCWorkItem::kLargeExactlyTracedTail));
            }
        }
        else if (wi.IsSentinel2Item())
        {
            if (wi.GetSentinel2Type() == GCWorkItem::kLargeExactlyTracedTail)
            {
                // The cursor is in the second item.
                GCWorkItem payload = m_incrementalWork.Pop();
                
                GCAssert(payload.GetSentinel2Type() == GCWorkItem::kInertPayload);
                
                // Set up for some more tracing.
                exactlyTraced = (GCTraceableBase*)wi.GetSentinelPointer();
                cursor = (size_t)payload.GetSentinelPointer();

                // Save the new state.
                PushWorkItem(GCWorkItem((void*)(cursor + 4), GCWorkItem::kInertPayload));
                PushWorkItem(GCWorkItem(wi.ptr, GCWorkItem::kLargeExactlyTracedTail));
            }
            else if (wi.GetSentinel2Type() == GCWorkItem::kInertPayload) {
                // Discard it - we're seeing this because of some arbitrary popping during
                // overflow handling.
                return true;
            }
            else {
                GCAssert(!"Unexpected sentinel value.");
            }
        }

        if (exactlyTraced != NULL)
        {
            if (!exactlyTraced->gcTraceLarge(this, cursor>>2))
            {
                // No items were pushed, so clean up.
                m_incrementalWork.Pop();        // Object
                m_incrementalWork.Pop();        // cursor
            }

            return true;    // Do not fall through to conservative tracing in MarkItem
        }

        PushWorkItem(GCWorkItem((void*)(wi.iptr + kLargestAlloc),
                                uint32_t(size - kLargestAlloc),
                                wi.HasInteriorPtrs() ? GCWorkItem::kStackMemory : GCWorkItem::kNonGCObject));
        
        size = kMarkItemSplitThreshold;
        return false;
    }

    // This will mark the item whether the item was previously marked or not.
    // The mark stack overflow logic depends on that.
    //
    // The common case is a small and exactly traced gc-item, and the marker
    // biases in favor of that, as well as large exactly traced gc-items.
    //
    // Large gc-items are recognizable by a header bit designating the object
    // as large, the bit is set in the large-object allocator.

    void GC::MarkItem(GCWorkItem &wi
#ifdef MMGC_CONSERVATIVE_PROFILER
                      , bool isRoot
#endif
                      )
    {
        GCAssert(markerActive);

        // Can't assert the general WorkItemInvariants here - some objects on the mark
        // stack may have been cleared out through explicit deletion or such objects
        // may have been transfered from the barrier stack, and there's nothing we
        // can do about it now.  (Explicit deletion needs to be removed from the API.)
        // The exact marker still works because the mark-exactly bit is cleared in
        // AbortFree.  However, explicitly deleted objects that are queued 
        // will be marked conservatively and will sometimes show up as false positive 
        // in the profiling of conservatively marked objects.

        size_t size = wi.GetSize();
        
        // The common case is a small and exactly traced gc item.
        
        // EXACTGC OPTIMIZEME: It's doubtful that it's cost-effective to have the
        // IsGCItem test on the hot path if we could instead have two mark stacks 
        // or a split mark stack.  That way the test could be lifted out into the
        // caller of MarkItem, where we can frequently hoist it out of a loop.

        if (wi.IsGCItem())
        {
            void *userptr = (void*)wi.ptr;
            void *realptr = GetRealPointer(userptr);
            GCAssert(GetGC(realptr) == this);
            GCAssert(IsPointerToGCObject(realptr));

            gcbits_t& bits = GetGCBits(realptr);

            if ((bits & (kVirtualGCTrace|kLargeObject)) == kVirtualGCTrace)
            {
                // Inlined and merged SetMark, since we have the bits anyway. 
                bits = (bits & ~kQueued) | kMark;
                ((GCTraceableBase*)userptr)->gcTrace(this);
                policy.signalExactMarkWork(size);
                return;
            }
        }

        // Control mark stack growth and ensure incrementality:
        //
        // Here we consider whether to split the object into multiple pieces.
        // A cutoff of kLargestAlloc is imposed on us by external factors, see
        // discussion below.  Ideally we'd choose a limit that isn't "too small"
        // A cutoff of kLargestAlloc is imposed on us by external factors.  
        // Ideally we'd choose a limit that isn't "too small"
        // because then we'll split too many objects, and isn't "too large"
        // because then the mark stack growth won't be throttled properly.
        //
        // See bugzilla #495049 for a discussion of this problem.
        //
        // See comments above HandleLargeMarkItem for the mechanics of how this
        // is done and why kMarkItemSplitThreshold == kLargestAlloc.

        if (size > kMarkItemSplitThreshold)
        {
            if(HandleLargeMarkItem(wi, size))
                return;
        }
        
        // Conservative tracing - what we know & love.
        
        if(wi.IsGCItem())
        {
            SetMark(wi.ptr);
        }

        policy.signalConservativeMarkWork(size);
#ifdef MMGC_CONSERVATIVE_PROFILER
        MemoryProfiler* profiler = heap->GetProfiler();
        if (profiler != NULL)
        {
            // There isn't really information to decisively tell roots and stacks apart,
            // but since we only recognize interior pointers from the stack at present
            // we make use of that fact for the time being.
            
            // Note for roots and stack we must use 'size', which is the amount we're
            // marking at this increment.  Using it means we don't get a good idea of
            // how large the roots and stacks actually are.  FIXME.

            if (wi.IsGCItem())
            {
                GCAssert(!(GetGCBits(GetRealPointer(wi.ptr)) & kVirtualGCTrace));
                demos->accountForObject(wi.ptr);
            }
            else if (wi.HasInteriorPtrs())
                demos->accountForStack(size);
            else if (isRoot)
                demos->accountForRoot(size);
            else {
                /* skip it - it's a chunk of a large object that's been split, it has already
                 * been accounted for because the accounting for the header piece will
                 * account for the entire object
                 */
            }
        }
#endif
        
        uintptr_t *p = (uintptr_t*) wi.ptr;
        uintptr_t *end = p + (size / sizeof(void*));
        while(p < end)
        {
            TraceConservativePointer(uintptr_t(*p), wi.HasInteriorPtrs() != 0 HEAP_GRAPH_ARG(p));
            p++;
        }
    }

    void GC::TraceConservativePointer(uintptr_t val, bool handleInteriorPtrs HEAP_GRAPH_ARG(uintptr_t* loc))
    {
        uintptr_t thisPage = val & GCHeap::kBlockMask;
#ifdef MMGC_POINTINESS_PROFILING
        uint32_t could_be_pointer = 0;
        uint32_t actually_is_pointer = 0;
#endif
        int bits;
#ifdef MMGC_VALGRIND
        if (handleInteriorPtrs) {
            VALGRIND_MAKE_MEM_DEFINED(&val, sizeof(val));
        }
#endif // MMGC_VALGRIND

        if(val < pageMap.MemStart() || val >= pageMap.MemEnd())
            goto end;

#ifdef MMGC_POINTINESS_PROFILING
        could_be_pointer++;
#endif

        // normalize and divide by 4K to get index
        bits = GetPageMapValue(val);

        if (bits == PageMap::kGCAllocPage)
        {
            const void *item;
            int itemNum;
            GCAlloc::GCBlock *block = (GCAlloc::GCBlock*) (val & GCHeap::kBlockMask);

            if (handleInteriorPtrs)
            {
                item = (void*) val;
                
                // guard against bogus pointers to the block header
                if(item < block->items)
                    goto end;

                itemNum = GCAlloc::GetObjectIndex(block, item);

                // adjust |item| to the beginning of the allocation
                item = block->items + itemNum * block->size;
            }
            else
            {
                // back up to real beginning
                item = GetRealPointer((const void*) (val & ~7));

                // guard against bogus pointers to the block header
                if(item < block->items)
                    goto end;

                itemNum = GCAlloc::GetObjectIndex(block, item);

                // if |item| doesn't point to the beginning of an allocation,
                // it's not considered a pointer.
                if (block->items + itemNum * block->size != item)
                {
#ifdef MMGC_64BIT
                    // Doubly-inherited classes have two vtables so are offset 8 more bytes than normal.
                    // Handle that here (shows up with PlayerScriptBufferImpl object in the Flash player)
                    if ((block->items + itemNum * block->size + sizeof(void *)) == item)
                        item = block->items + itemNum * block->size;
                    else
#endif // MMGC_64BIT
                        goto end;
                }
            }

#ifdef MMGC_POINTINESS_PROFILING
            actually_is_pointer++;
#endif

            gcbits_t& bits2 = block->bits[GCAlloc::GetBitsIndex(block, item)];
            if ((bits2 & (kMark|kQueued)) == 0)
            {
                uint32_t itemSize = block->size - (uint32_t)DebugSize();
                if(block->containsPointers)
                {
                    const void *realItem = GetUserPointer(item);
                    GCWorkItem newItem(realItem, 0, GCWorkItem::kGCObject);
                    // EXACTGC INVESTIGATEME - is recursive marking still a good idea?  Note that we
                    // expect the bulk of the marking to be exact, and exact marking is not recursive,
                    // it always uses the mark stack.  (On the other hand it's type-aware and can
                    // avoid pushing leaf objects onto the mark stack.)  If conservative marking is
                    // merely a last-ditch mechanism then there's little reason to assume that
                    // recursive marking will buy us much here.
                    if(((uintptr_t)realItem & GCHeap::kBlockMask) != thisPage || mark_item_recursion_control == 0)
                    {
                        bits2 |= kQueued;
                        PushWorkItem(newItem);
                    }
                    else
                    {
                        mark_item_recursion_control--;
                        MarkItem(newItem);
                        mark_item_recursion_control++;
                    }
                }
                else
                {
                    bits2 |= kMark;
                    policy.signalPointerfreeMarkWork(itemSize);
                }
#ifdef MMGC_HEAP_GRAPH
                markerGraph.edge(loc, GetUserPointer(item));
#endif
            }
        }
        else if (bits == PageMap::kGCLargeAllocPageFirst || (handleInteriorPtrs && bits == PageMap::kGCLargeAllocPageRest))
        {
            const void* item;
            
            if (handleInteriorPtrs)
            {
                if (bits == PageMap::kGCLargeAllocPageFirst)
                {
                    // guard against bogus pointers to the block header
                    if ((val & GCHeap::kOffsetMask) < sizeof(GCLargeAlloc::LargeBlock))
                        goto end;
                    
                    item = (void *) ((val & GCHeap::kBlockMask) | sizeof(GCLargeAlloc::LargeBlock));
                }
                else
                {
                    item = GetRealPointer(FindBeginning((void *) val));
                }
            }
            else
            {
                // back up to real beginning
                item = GetRealPointer((const void*) (val & ~7));
                
                // If |item| doesn't point to the start of the page, it's not
                // really a pointer.
                if(((uintptr_t) item & GCHeap::kOffsetMask) != sizeof(GCLargeAlloc::LargeBlock))
                    goto end;
            }
            
#ifdef MMGC_POINTINESS_PROFILING
            actually_is_pointer++;
#endif

            GCLargeAlloc::LargeBlock *b = GCLargeAlloc::GetLargeBlock(item);
            if((b->flags[0] & (kQueued|kMark)) == 0)
            {
                uint32_t itemSize = b->size - (uint32_t)DebugSize();
                if(b->containsPointers)
                {
                    b->flags[0] |= kQueued;
                    PushWorkItem(GCWorkItem(GetUserPointer(item), 0, GCWorkItem::kGCObject));
                }
                else
                {
                    // doesn't need marking go right to black
                    b->flags[0] |= kMark;
                    policy.signalPointerfreeMarkWork(itemSize);
                }
#ifdef MMGC_HEAP_GRAPH
                markerGraph.edge(loc, GetUserPointer(item));
#endif
            }
        }
    end: ;
#ifdef MMGC_POINTINESS_PROFILING
        policy.signalDemographics(size/sizeof(void*), could_be_pointer, actually_is_pointer);
#endif
    }

    void GC::TracePointer(void* obj /* user pointer */ HEAP_GRAPH_ARG(const uintptr_t *loc))
    {
        GCAssert(((uintptr_t)obj & 7) == 0);
        
        if (obj == NULL)
            return;
        
        gcbits_t& bits2 = GetGCBits(GetRealPointer(obj));

        // We cannot yet assert the following.  The reason is an interaction between
        // exact tracing, stack pinning, and reference counting.  Reference counts
        // must reflect at least the number of references from exactly traced objects.
        // But code that maintains arrays of reference counts and cleverly "transfers"
        // the counts from one copy of the array to the other without resetting the
        // exact-trace bit or clearing the object or freeing it will end up in a
        // situation where, if the dead array copy is reached during tracing, the
        // reference counts will be wrong and the assert will hit.  The object can be
        // reached even if the C++ code is correct since we trace the stack and some
        // objects conservatively.  The problem will disappear when we remove
        // reference counting.
        //
        // Another problem here is that explicit deletion of objects can create
        // dangling pointers that will also hit the assert, but in that case there are
        // other, more insidious bugs, so explicit deletion has to be dealt with in
        // any case.
        // GCAssert((bits2 & (kMark|kQueued)) != (kMark|kQueued));
        
        GCAssert(ContainsPointers(obj) || (bits2 & kQueued) == 0);

        // EXACTGC OPTMIZEME: Here we can fold the ContainsPointers test into
        // the marked test if there's a bit in the header indicating pointerfulness.

        if ((bits2 & (kMark|kQueued)) == 0)
        {
            if (ContainsPointers(obj)) {
                bits2 |= kQueued;
                GCWorkItem newItem(obj, 0, GCWorkItem::kGCObject);
                PushWorkItem(newItem);
            }
            else {
                bits2 |= kMark;
                policy.signalPointerfreeMarkWork(Size(obj));
            }
#ifdef MMGC_HEAP_GRAPH
            markerGraph.edge(loc, obj);
#endif
        }
    }

    void GC::TraceAtomValue(avmplus::Atom a HEAP_GRAPH_ARG(avmplus::Atom *loc))
    {
        switch (a & 7)
        {
#ifdef DEBUG
            case avmplus::AtomConstants::kUnusedAtomTag:
                // Tracing is not necessary here.  Generic GCObjects should have been laundered
                // through the genericObjectToAtom API and will be tagged kDoubleType (see comments
                // below for why that is a botch).  Anything tagged with kUnusedAtomTag is non-GC
                // storage.
                break;
#endif
            case avmplus::AtomConstants::kObjectType:
            case avmplus::AtomConstants::kStringType:
            case avmplus::AtomConstants::kNamespaceType:
                TracePointer((GCTraceableBase*)(a & ~7) HEAP_GRAPH_ARG((uintptr_t*)loc));
                break;
            case avmplus::AtomConstants::kDoubleType:
                // Bugzilla 594870: Must trace semi-conservatively because of the genericObjectToAtom API:
                // the object we're looking at may or may not contain pointers, and we don't know.
                TracePointer((void*)(a & ~7) HEAP_GRAPH_ARG((uintptr_t*)loc));
                break;
        }
    }

    void GC::IncrementalMark()
    {
        GCAssert(!markerActive);

        uint32_t time = incrementalValidation ? 1 : policy.incrementalMarkMilliseconds();
#ifdef _DEBUG
        time = 1;
#endif

        SAMPLE_FRAME("[mark]", core());

        // Don't force collections to finish if the mark stack is empty;
        // let the allocation budget be used up.

        if(m_incrementalWork.Count() == 0) {
            CheckBarrierWork();
            if (m_incrementalWork.Count() == 0) {
                // Policy triggers off these signals, so we still need to send them.
                policy.signal(GCPolicyManager::START_IncrementalMark);
                policy.signal(GCPolicyManager::END_IncrementalMark);
                return;
            }
        }

        markerActive++;

        policy.signal(GCPolicyManager::START_IncrementalMark);

        // FIXME: tune this so that getPerformanceCounter() overhead is noise
        //
        // *** NOTE ON THREAD SAFETY ***
        //
        // If anyone feels like writing code that updates checkTimeIncrements (it
        // used to be 'static' instead of 'const'), beware that using a static var
        // here requires a lock.  It may also be wrong to have one shared global for
        // the value, and in any case it may belong in the policy manager.

        const unsigned int checkTimeIncrements = 100;
        uint64_t start = VMPI_getPerformanceCounter();

        uint64_t numObjects=policy.objectsMarked();
        uint64_t objSize=policy.bytesMarked();

        uint64_t ticks = start + time * VMPI_getPerformanceFrequency() / 1000;
        do {
            // EXACTGC OPTIMIZEME: Count can overestimate the amount of work on the stack
            // because exactly traced large split items occupy two slots on the
            // mark stack.  Thus the loop must also test for whether the stack
            // is empty.
            unsigned int count = m_incrementalWork.Count();
            if (count == 0) {
                CheckBarrierWork();
                count = m_incrementalWork.Count();
                if (count == 0)
                    break;
            }
            if (count > checkTimeIncrements) {
                count = checkTimeIncrements;
            }
            for(unsigned int i=0; i<count && !m_incrementalWork.IsEmpty() ; i++)
            {
                GCWorkItem item = m_incrementalWork.Pop();
                MarkItem(item);
            }
            SAMPLE_CHECK();
        } while(VMPI_getPerformanceCounter() < ticks);

        policy.signal(GCPolicyManager::END_IncrementalMark);

        markerActive--;

        if(heap->Config().gcstats) {
            numObjects = policy.objectsMarked() - numObjects;
            objSize = policy.bytesMarked() - objSize;
            double millis = duration(start);
            size_t kb = size_t(objSize)>>10;
            gclog("[mem] mark(%d) %d objects (%d kb %d mb/s) in %.2f millis (%.4f s)\n",
                  markIncrements() - lastStartMarkIncrementCount, int(numObjects), kb,
                  uint32_t(double(kb)/millis), millis, duration(t0)/1000);
        }
    }

    void GC::FinishIncrementalMark(bool scanStack)
    {
        // Don't finish an incremental mark (i.e., sweep) if we
        // are in the midst of a ZCT reap.
        if (Reaping())
        {
            return;
        }

        // Force repeated restarts and marking until we're done.  For discussion
        // of completion, see the comments above HandleMarkStackOverflow.

        while (m_markStackOverflow) {
            m_markStackOverflow = false;
            HandleMarkStackOverflow();      // may set
            FlushBarrierWork();             //    m_markStackOverflow
            Mark();                         //       to true again
        }

        // finished in Sweep
        sweepStart = VMPI_getPerformanceCounter();

        // mark roots again, could have changed (alternative is to put WB's on the roots
        // which we may need to do if we find FinishIncrementalMark taking too long)

        policy.signal(GCPolicyManager::START_FinalRootAndStackScan);

        GCAssert(!m_markStackOverflow);

        FlushBarrierWork();
        MarkAllRoots();
        MarkQueueAndStack(scanStack);

        // Force repeated restarts and marking until we're done.  For discussion
        // of completion, see the comments above HandleMarkStackOverflow.  Note
        // that we must use MarkQueueAndStack rather than plain Mark because there
        // is no guarantee that the stack was actually pushed onto the mark stack.
        // If we iterate several times there may be a performance penalty as a
        // consequence of that, but it's not likely that that will in fact happen,
        // and it's not obvious how to fix it.

        while (m_markStackOverflow) {
            m_markStackOverflow = false;
            HandleMarkStackOverflow();                          // may set
            FlushBarrierWork();                                 //    m_markStackOverflow
            MarkQueueAndStack(scanStack);                       //       to true again
        }
        ClearMarkStack();               // Frees any cached resources
        m_barrierWork.Clear();
        zct.Prune();                            // Frees unused memory

        policy.signal(GCPolicyManager::END_FinalRootAndStackScan);

#ifdef _DEBUG
        // need to traverse all marked objects and make sure they don't contain
        // pointers to unmarked objects
        FindMissingWriteBarriers();
#endif

        policy.signal(GCPolicyManager::START_FinalizeAndSweep);
        GCAssert(!collecting);

        // Sweep is responsible for setting and clearing GC::collecting.
        // It also clears GC::marking.

        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);
        Sweep();
        GCAssert(m_incrementalWork.Count() == 0);
        GCAssert(m_barrierWork.Count() == 0);

        policy.signal(GCPolicyManager::END_FinalizeAndSweep);   // garbage collection is finished
#ifdef MMGC_MEMORY_PROFILER
        if(heap->Config().autoGCStats)
            DumpPauseInfo();
#endif
    }

#ifdef _DEBUG
    bool GC::IsWhite(const void *item)
    {
        // back up to real beginning
        item = GetRealPointer((const void*) item);

        int bits = GetPageMapValueGuarded((uintptr_t)item);
        switch(bits) {
        case PageMap::kGCAllocPage:
            return GCAlloc::IsWhite(item);
        case PageMap::kGCLargeAllocPageFirst:
            return GCLargeAlloc::IsWhite(item);
        }
        return false;
    }
#endif // _DEBUG

    // Here the purpose is to shift some work from the barrier mark stack to the regular
    // mark stack /provided/ the barrier mark stack seems very full.  The regular mark stack
    // is normally empty.
    //
    // To avoid copying data, we will only move entire (full) segments, because they can
    // be moved by changing some pointers and counters.  We will never move a non-full
    // segment.

    void GC::CheckBarrierWork()
    {
        if (m_barrierWork.EntirelyFullSegments() < 9)   // 9 is pretty arbitrary
            return;
        m_incrementalWork.TransferOneFullSegmentFrom(m_barrierWork);
    }

    // Here the purpose is to shift all the work from the barrier mark stack to the regular
    // mark stack, unconditionally.  This may mean copying mark work from one stack to
    // the other (for work that's in a non-full segment), but full segments can just be
    // moved by changing some pointers and counters.
    //
    // Note it's possible for this to cause a mark stack overflow, and the caller must
    // deal with that.

    void GC::FlushBarrierWork()
    {
        for ( uint32_t numfull = m_barrierWork.EntirelyFullSegments() ; numfull > 0 ; --numfull )
            if (!m_incrementalWork.TransferOneFullSegmentFrom(m_barrierWork))
                break;
        while (m_barrierWork.Count() > 0) {
            GCWorkItem item = m_barrierWork.Pop();
            // The general invariants may be violated here - see comment block at the
            // beginning of MarkItem() for how deleted objects can foul up the works.
            // So use the invariant-unaware API.
            PushWorkItem_Unsafe(item);
        }
    }

    void GC::WriteBarrierTrap(const void *container)
    {
        if (marking)
            InlineWriteBarrierTrap(container);
    }

    void GC::privateWriteBarrier(const void *container, const void *address, const void *value)
    {
        privateInlineWriteBarrier(container, address, value);
    }

    void GC::privateWriteBarrierRC(const void *container, const void *address, const void *value)
    {
        privateInlineWriteBarrierRC(container, address, value);
    }

    /* static */ void GC::WriteBarrierRC(const void *address, const void *value)
    {
        GC* gc = GC::GetGC(address);
        gc->privateInlineWriteBarrierRC(address, value);
    }

    /* static */ void GC::WriteBarrierRC_ctor(const void *address, const void *value)
    {
        GC* gc = GC::GetGC(address);
        if (gc->marking)
            gc->InlineWriteBarrierTrap(gc->FindBeginningFast(address));
        gc->WriteBarrierWriteRC_ctor(address, value);
    }

    /* static */ void GC::WriteBarrierRC_dtor(const void *address)
    {
        GC* gc = GC::GetGC(address);
        gc->WriteBarrierWriteRC_dtor(address);
    }

    /* static */ void GC::WriteBarrier(const void *address, const void *value)
    {
        GC* gc = GC::GetGC(address);
        gc->privateInlineWriteBarrier(address, value);
    }

    // It might appear that this can be optimized easily, but not so - there's a
    // lot of logic hiding here, and little to gain from hand-inlining.

    void GC::privateConservativeWriteBarrierNoSubstitute(const void *address)
    {
        GCAssert(marking);
        if(IsPointerToGCPage(address))
           InlineWriteBarrierTrap(FindBeginningFast(address));
    }

    void GC::WriteBarrierNoSubstitute(const void *container, const void *value)
    {
        (void)value;  // Can't get rid of this parameter now; part of an existing API

        GCAssert(container != NULL);
        GCAssert(IsPointerToGCPage(container));
        GCAssert(FindBeginningGuarded(container) == container);
        if (marking)
            InlineWriteBarrierTrap(container);
    }

    // Add 'container' to the remembered set.
    //
    // IncrementalMark may move a segment off the remembered set;
    // FinishIncrementalMark will take care of what remains.
    //
    // Observe that if adding the item to the remembered set (a secondary mark stack)
    // fails, then the item is just pushed onto the regular mark stack; if that too
    // fails then normal stack overflow handling takes over.  That is what we want,
    // as it guarantees that the item will be traced again.

    void GC::WriteBarrierHit(const void* container)
    {
        GCAssert(IsPointerToGCObject(GetRealPointer(container)));
        if (collecting)
        {
            // It's the job of the allocators to make sure the rhs is marked if
            // it is allocated on a page that's not yet swept.  In particular,
            // the barrier is not needed to make sure that that object is kept
            // alive.
            //
            // Ergo all we need to do here is revert the lhs to marked and return.
            SetMark(container);
            return;
        }
        GCWorkItem item(container, 0, GCWorkItem::kGCObject);
        // Note, pushing directly here works right now because PushWorkItem never
        // performs any processing (breaking up a large object into shorter
        // segments, for example).  If that changes, we must probably introduce
        // PushBarrierItem to do the same thing for m_barrierWork.
#ifdef _DEBUG
        // If this fails it's because the write barrier hits on an already-deleted
        // object - which is a bug to be sure, but we don't know if we may have to
        // support it anyway.
        WorkItemInvariants(item);
#endif
        if (!m_barrierWork.Push(item))
            PushWorkItem(item);
    }

    void GC::movePointers(void* dstObject, void **dstArray, uint32_t dstOffset, const void **srcArray, uint32_t srcOffset, size_t numPointers)
    {
        if(marking && GetMark(dstObject) && ContainsPointers(dstObject) &&
           // don't push small items that are moving pointers inside the same array
           (dstArray != srcArray || Size(dstObject) > kMarkItemSplitThreshold)) {
            // this could be optimized to just re-scan the dirty region
            InlineWriteBarrierTrap(dstObject);
        }
        VMPI_memmove(dstArray + dstOffset, srcArray + srcOffset, numPointers * sizeof(void*));
    }

    void GC::movePointersWithinBlock(void** array, uint32_t dstOffsetInBytes, uint32_t srcOffsetInBytes, size_t numPointers, bool zeroEmptied)
    {
        if (srcOffsetInBytes == dstOffsetInBytes || numPointers == 0)
            return;
       
        if (marking && 
            GetMark(array) && 
            ContainsPointers(array) &&
            // don't push small items that are moving pointers inside the same array
            Size(array) > kMarkItemSplitThreshold) 
        {
            // this could be optimized to just re-scan the dirty region
            InlineWriteBarrierTrap(array);
        }
        
        size_t const bytesToMove = numPointers * sizeof(void*);
        VMPI_memmove((char*)array + dstOffsetInBytes, (char*)array + srcOffsetInBytes, bytesToMove);
        
        if (zeroEmptied)
        {
            size_t zeroOffsetInBytes, bytesToZero;
            if (srcOffsetInBytes > dstOffsetInBytes)
            {
                // moving down, zero the end
                bytesToZero = srcOffsetInBytes - dstOffsetInBytes;
                zeroOffsetInBytes = dstOffsetInBytes + bytesToMove;
            }
            else
            {
                // moving up, zero the start
                bytesToZero = dstOffsetInBytes - srcOffsetInBytes;
                zeroOffsetInBytes = srcOffsetInBytes;
            }
            VMPI_memset((char*)array + zeroOffsetInBytes, 0, bytesToZero);
        }
    }

    void GC::reversePointersWithinBlock(void* mem, size_t offsetInBytes, size_t numPointers)
    {
        if (mem == NULL || numPointers <= 1)
            return;
       
        if (marking && 
            GetMark(mem) && 
            ContainsPointers(mem) &&
            // don't push small items that are moving pointers inside the same mem
            Size(mem) > kMarkItemSplitThreshold) 
        {
            // this could be optimized to just re-scan the dirty region
            InlineWriteBarrierTrap(mem);
        }
        
        void** array = (void**)((char*)mem + offsetInBytes);
        for (size_t i = 0, n = numPointers/2; i < n; i++)
        {
            size_t const i2 = numPointers - i - 1;
            void* const v  = array[i];
            void* const v2 = array[i2];
            array[i] = v2;
            array[i2] = v;
        }
    }

    uint32_t *GC::AllocBits(int numBytes, int sizeClass)
    {
        uint32_t *bits;

        GCAssert(numBytes % 4 == 0);

        #ifdef MMGC_64BIT // we use first 8-byte slot for the free list
        if (numBytes == 4)
            numBytes = 8;
        #endif

        // hit freelists first
        if(m_bitsFreelists[sizeClass]) {
            bits = m_bitsFreelists[sizeClass];
            m_bitsFreelists[sizeClass] = *(uint32_t**)bits;
            VMPI_memset(bits, 0, sizeof(uint32_t*));
            return bits;
        }

        if(!m_bitsNext) {
            // Bugzilla 551833: It's OK to use heapAlloc here (as opposed to
            // heap->AllocNoOOM, say) because the caller knows AllocBits()
            // can trigger OOM.
            m_bitsNext = (uint32_t*)heapAlloc(1);
        }

        int leftOver = GCHeap::kBlockSize - ((uintptr_t)m_bitsNext & GCHeap::kOffsetMask);
        if(leftOver >= numBytes) {
            bits = m_bitsNext;
            if(leftOver == numBytes)
                m_bitsNext = 0;
            else
                m_bitsNext += numBytes/sizeof(uint32_t);
        } else {
            if(leftOver>=int(sizeof(void*))) {
                // put waste in freelist
                for(int i=0, n=kNumSizeClasses; i<n; i++) {
                    GCAlloc *a = noPointersAllocs[i];
                    if(!a->m_bitsInPage && a->m_numBitmapBytes <= leftOver) {
                        FreeBits(m_bitsNext, a->m_sizeClassIndex);
                        break;
                    }
                }
            }
            m_bitsNext = 0;
            // recurse rather than duplicating code
            return AllocBits(numBytes, sizeClass);
        }
        return bits;
    }

    void GC::AddRoot(GCRoot *root)
    {
        MMGC_LOCK(m_rootListLock);
        root->prev = NULL;
        root->next = m_roots;
        if(m_roots)
            m_roots->prev = root;
        m_roots = root;
    }

    void GC::RemoveRoot(GCRoot *root)
    {
        MMGC_LOCK(m_rootListLock);
        if( m_roots == root )
            m_roots = root->next;
        else
            root->prev->next = root->next;

        if(root->next)
            root->next->prev = root->prev;
    }

    void GC::AddCallback(GCCallback *cb)
    {
        cb->prevCB = NULL;
        cb->nextCB = m_callbacks;
        if(m_callbacks)
            m_callbacks->prevCB = cb;
        m_callbacks = cb;
    }

    void GC::RemoveCallback(GCCallback *cb)
    {
        if( m_callbacks == cb )
            m_callbacks = cb->nextCB;
        else
            cb->prevCB->nextCB = cb->nextCB;

        if(cb->nextCB)
            cb->nextCB->prevCB = cb->prevCB;
    }

    GCObject *GCWeakRef::get()
    {
        // Bugzilla 572331.
        // It is possible for presweep handlers to extract pointers to unmarked objects
        // from weakrefs and store them into marked objects.  Since the write barrier is
        // disabled during collecting we must ensure that the unmarked object becomes
        // marked by some other means in that situation, and we do that here by introducing
        // a local read barrier that resurrects those objects.
        //
        // The read barrier just pushes the to-be-resurrected object onto the mark
        // stack; the marker will be run in Sweep() after the presweep calls are done.

        if (m_obj != 0) {
            GC *gc = GC::GetGC(m_obj);
            if (gc->Collecting() && !GC::GetMark(m_obj)) {
                // If this assertion fails then we have a finalizer (C++ destructor on a
                // GCFinalizableObject) resurrecting an object.  That should not happen,
                // because we clear all GCWeakRefs pointing to unmarked objects before
                // running finalizers.
 
                // Bugzilla 575631 (explanation below)
                // GCAssert(gc->Presweeping());

                // Bugzilla 575631: GCAlloc::Finalize's interleaving
                // of mark-bit resets and finalizer invocations means
                // that the conditions above don't imply we're in
                // Presweep.  Nonetheless, marking an object with
                // cleared mark bits isn't legal in GCAlloc::Finalize,
                // so instead of asserting that we are presweeping, we
                // use that condition as a guard.
                if (gc->Presweeping()) {
                    // Bugzilla 615511:
                    // PushWorkItem does not set the queued bit, but every object on
                    // the mark stack must have the queued bit set.
                    GC::GetGCBits(GetRealPointer(m_obj)) |= kQueued;
                    gc->PushWorkItem(GCWorkItem(m_obj, 0, GCWorkItem::kGCObject));
                }
            }
        }

        return (GCObject*)m_obj;
    }

    /*static*/
    GCWeakRef* GC::GetWeakRef(const void *userptr)
    {
        GC *gc = GetGC(userptr);
        GCWeakRef *ref = (GCWeakRef*) gc->weakRefs.get(userptr);

        GCAssert(gc->IsPointerToGCPage(userptr));
        GCAssert(gc->IsPointerToGCObject(GetRealPointer(userptr)));
        GCAssert((gc->GetGCBits(GetRealPointer(userptr)) & GCAlloc::kFreelist) != GCAlloc::kFreelist);

        if(ref == NULL) {
            ref = new (gc) GCWeakRef(userptr);
            gc->weakRefs.put(userptr, ref);
            SetHasWeakRef(userptr, true);
        } else {
            GCAssert(ref->get() == userptr);
        }
        return ref;
    }

    void GC::ClearWeakRef(const void *item, bool allowRehash)
    {
        GCWeakRef *ref = (GCWeakRef*) weakRefs.remove(item, allowRehash);
        GCAssert(weakRefs.get(item) == NULL);
        GCAssert(ref != NULL || heap->GetStatus() == kMemAbort);
        if(ref) {
            GCAssert(ref->isNull() || ref->peek() == item);
            ref->m_obj = NULL;
            SetHasWeakRef(item, false);
        }
    }

#ifdef _DEBUG
    void GC::WhitePointerScan(const void *mem, size_t size)
    {
        uintptr_t *p = (uintptr_t *) mem;
        // the minus 8 skips the GCEndOfObjectPoison and back pointer
        uintptr_t *end = p + ((size) / sizeof(void*));

        while(p < end)
        {
            uintptr_t val = *p;
            if(val == GCHeap::GCEndOfObjectPoison)
                break;
            if(IsWhite((const void*) (val&~7)) &&
               *(((int32_t*)(val&~7))+1) != int32_t(GCHeap::GCFreedPoison) &&
               *(((int32_t*)(val&~7))+1) != int32_t(GCHeap::GCSweptPoison))
            {
                GCDebugMsg(false, "Object %p allocated here:\n", mem);
                PrintAllocStackTrace(mem);
                GCDebugMsg(false, "Didn't mark pointer at %p, object %p allocated here:\n", p, (void*)val);
                PrintAllocStackTrace((const void*)(val&~7));
                GCAssert(false);
            }
            p++;
        }
    }

    void GC::FindMissingWriteBarriers()
    {
        if(!incrementalValidation)
            return;

        uintptr_t m = pageMap.MemStart();
        while(m < pageMap.MemEnd())
        {
            // divide by 4K to get index
            int bits = GetPageMapValue(m);
            switch(bits)
            {
            case PageMap::kNonGC:
                m += GCHeap::kBlockSize;
                break;
            case PageMap::kGCLargeAllocPageFirst:
                {
                    GCLargeAlloc::LargeBlock *lb = (GCLargeAlloc::LargeBlock*)m;
                    const void *item = GetUserPointer(lb->GetObject());
                    if(GetMark(item) && lb->containsPointers) {
                        WhitePointerScan(item, lb->size - DebugSize());
                    }
                    m += lb->GetNumBlocks() * GCHeap::kBlockSize;
                }
                break;
            case PageMap::kGCAllocPage:
                {
                    // go through all marked objects in this page
                    GCAlloc::GCBlock *b = (GCAlloc::GCBlock *) m;
                    GCAlloc* alloc = (GCAlloc*)b->alloc;
                    if(alloc->ContainsPointers()) {
                        for (int i=0; i< alloc->m_itemsPerBlock; i++) {

                            // find all marked (but not kFreelist) objects and search them
                            void *item = (char*)b->items + alloc->m_itemSize*i;
                            if(!GetMark(item) || GetQueued(item))
                                continue;

                            WhitePointerScan(GetUserPointer(item), alloc->m_itemSize - DebugSize());
                        }
                    }
                    m += GCHeap::kBlockSize;
                }
                break;
            default:
                GCAssert(false);
                break;
            }
        }
    }
#endif //_DEBUG

    void *GC::heapAlloc(size_t siz, int flags)
    {
        void *ptr = heap->Alloc((int)siz, flags);
        if(ptr)
            policy.signalBlockAllocation(siz);
        return ptr;
    }

    void GC::heapFree(void *ptr, size_t siz, bool profile)
    {
        if(!siz)
            siz = heap->Size(ptr);
        policy.signalBlockDeallocation(siz);
        heap->FreeInternal(ptr, profile, true);
    }

    size_t GC::GetBytesInUse()
    {
        size_t ask;
        size_t allocated;
        GetUsageInfo(ask, allocated);
        (void)ask;
        return allocated;
    }

    void GC::GetUsageInfo(size_t& totalAskSize, size_t& totalAllocated)
    {
        totalAskSize = 0;
        totalAllocated = 0;

        size_t ask;
        size_t allocated;

        GCAlloc** allocators[] = {containsPointersRCAllocs, containsPointersAllocs, noPointersAllocs};
        for(int j = 0;j<3;j++)
        {
            GCAlloc** gc_alloc = allocators[j];

            for(int i=0; i < kNumSizeClasses; i++)
            {
                gc_alloc[i]->GetUsageInfo(ask, allocated);
                totalAskSize += ask;
                totalAllocated += allocated;
            }
        }

        largeAlloc->GetUsageInfo(ask, allocated);
        totalAskSize += ask;
        totalAllocated += allocated;
    }

    void GC::allocaInit()
    {
        top_segment = NULL;
        stacktop = NULL;
 #ifdef _DEBUG
        stackdepth = 0;
 #endif
        pushAllocaSegment(AVMPLUS_PARAM_ALLOCA_DEFSIZE);
    }

    void GC::allocaShutdown()
    {
        while (top_segment != NULL)
            popAllocaSegment();
        top_segment = NULL;
        stacktop = NULL;
    }

    void GC::allocaUnwind()
    {
        allocaShutdown();
        allocaInit();
    }

    void* GC::allocaPush(size_t nbytes, AllocaAutoPtr& x)
    {
        GCAssert(x.unwindPtr == NULL);
        x.gc = this;
        x.unwindPtr = stacktop;
        nbytes = GCHeap::CheckForAllocSizeOverflow(nbytes, 7) & ~7;
        if ((char*)stacktop + nbytes <= top_segment->limit) {
            stacktop = (char*)stacktop + nbytes;
            return x.unwindPtr;
        }
        return allocaPushSlow(nbytes);
    }

    void GC::allocaPopToSlow(void* top)
    {
        GCAssert(top_segment != NULL);
        GCAssert(!(top >= top_segment->start && top <= top_segment->limit));
        while (!(top >= top_segment->start && top <= top_segment->limit))
            popAllocaSegment();
        GCAssert(top_segment != NULL);
    }

    void* GC::allocaPushSlow(size_t nbytes)
    {
        size_t alloc_nbytes = nbytes;
        if (alloc_nbytes < AVMPLUS_PARAM_ALLOCA_DEFSIZE)
            alloc_nbytes = AVMPLUS_PARAM_ALLOCA_DEFSIZE;
        pushAllocaSegment(alloc_nbytes);
        void *p = stacktop;
        stacktop = (char*)stacktop + nbytes;
        return p;
    }

    void GC::pushAllocaSegment(size_t nbytes)
    {
        GCAssert(nbytes % 8 == 0);
 #ifdef _DEBUG
        stackdepth += nbytes;
 #endif
        void* memory = AllocRCRoot(nbytes);
        AllocaStackSegment* seg = mmfx_new(AllocaStackSegment);
        seg->start = memory;
        seg->limit = (void*)((char*)memory + nbytes);
        seg->top = NULL;
        seg->prev = top_segment;
        if (top_segment != NULL)
            top_segment->top = stacktop;
        top_segment = seg;
        stacktop = memory;
    }

    void GC::popAllocaSegment()
    {
 #ifdef _DEBUG
        stackdepth -= (char*)top_segment->limit - (char*)top_segment->start;
 #endif
        FreeRCRoot(top_segment->start);
        AllocaStackSegment* seg = top_segment;
        top_segment = top_segment->prev;
        if (top_segment != NULL)
            stacktop = top_segment->top;
        mmfx_delete(seg);
    }

    GCAutoEnter::GCAutoEnter(GC *gc, EnterType type) : m_gc(NULL), m_prevgc(NULL)
    {
        if(gc) {
            GC *prevGC = gc->heap->GetEnterFrame()->GetActiveGC();
            if(prevGC != gc) {
                // must enter first as it acquires the gc lock
                if(gc->ThreadEnter(this, /*doCollectionWork=*/true, type == kTryEnter)) {
                    m_gc = gc;
                    m_prevgc = prevGC;
                }
            }
        }
    }

    GCAutoEnter::~GCAutoEnter()
    {
        Destroy(true);
    }

    /*virtual*/
    void GCAutoEnter::Unwind()
    {
        if(m_gc) {
            GC *gc = m_gc;
            gc->SignalImminentAbort();
        }
    }

    void GCAutoEnter::Destroy(bool doCollectionWork)
    {
        if(m_gc) {
            m_gc->ThreadLeave(doCollectionWork, m_prevgc);
            m_gc = m_prevgc = NULL;
        }
    }

    GCAutoEnterPause::GCAutoEnterPause(GC *gc) : gc(gc), enterSave(gc->GetAutoEnter())
    {
        GCAssertMsg(gc->GetStackEnter() != 0, "Invalid MMGC_GC_ROOT_THREAD usage, GC not already entered, random crashes will ensue");
        gc->ThreadLeave(/*doCollectionWork=*/false, gc);
    }

    GCAutoEnterPause::~GCAutoEnterPause()
    {
        GCAssertMsg(gc->GetStackEnter() == 0, "Invalid MMGC_GC_ROOT_THREAD usage, GC not exitted properly, random crashes will ensue");
        gc->ThreadEnter(enterSave, false, false);
    }

    bool GC::ThreadEnter(GCAutoEnter *enter, bool doCollectionWork, bool tryEnter)
    {
        if(!VMPI_lockTestAndAcquire(&m_gcLock)) {
            if(tryEnter)
                return false;
            if(m_gcThread != VMPI_currentThread())
                VMPI_lockAcquire(&m_gcLock);
        }

        heap->SetActiveGC(this);

        if(enterCount++ == 0) {
            heap->GetEnterFrame()->AddAbortUnwindObject(enter);
            stackEnter = enter;
            m_gcThread = VMPI_currentThread();
            if(doCollectionWork) {
                ThreadEdgeWork();
            }
        }
        return true;
    }

    void GC::ThreadLeave( bool doCollectionWork, GC *prevGC)
    {

        if(enterCount-1 == 0) {
            if(doCollectionWork) {
                ThreadEdgeWork();
            }
            heap->GetEnterFrame()->RemoveAbortUnwindObject(stackEnter);
        }

        // We always pop the active GC but have to do so before releasing the lock
#ifdef DEBUG
        GC* curgc =
#endif
            heap->SetActiveGC(prevGC);
        GCAssert(curgc == this);

        if(--enterCount == 0) {
            stackEnter = NULL;
            // cleared so we remain thread ambivalent
            rememberedStackTop = NULL;
            m_gcThread = NULL;
            VMPI_lockRelease(&m_gcLock);
        }
    }

    void GC::ThreadEdgeWork()
    {
        if(destroying)
            return;

        if(policy.queryFullCollectionQueued())
            Collect(false);
        else
            ReapZCT(false);

        if(!stackCleaned)
            CleanStack();
    }

    void GC::memoryStatusChange(MemoryStatus, MemoryStatus to)
    {
        // ZCT blockage: what if we get here from zct growth?

        // Mark/sweep blockage: what about mark stack,
        // presweep,post-sweep,finalize allocations?

        // if ZCT or GC can't complete we can't free memory! currently
        // we do nothing, which means we rely on reserve or other
        // listeners to free memory or head straight to abort

        if(to == kFreeMemoryIfPossible) {
            if(onThread()) {
                Collect();
            } else {
                //  If we're not already in the middle of collecting from another thread's GC, then try to...
                GCAutoEnter enter(this, GCAutoEnter::kTryEnter);
                if(enter.Entered()) {
                    Collect(false);
                }
                // else nothing can be done
            }
        }
    }

#ifdef DEBUG
    void GC::ShouldBeInactive()
    {
        GCAssert(m_gcThread == NULL);
        GCAssert(stackEnter == NULL);
        GCAssert(top_segment != NULL && top_segment->prev == NULL && top_segment->start == stacktop);
        GCAssert(VMPI_lockTestAndAcquire(&m_gcLock) && VMPI_lockRelease(&m_gcLock));
    }
#endif

    void GC::SignalImminentAbort()
    {
        policy.SignalImminentAbort();
        zct.SignalImminentAbort();

        if (collecting || marking)
        {
            ClearMarkStack();
            m_barrierWork.Clear();
            ClearMarks();
            m_markStackOverflow = false;
            collecting = false;
            marking = false;
            markerActive = 0;
        }

        if(GetAutoEnter() != NULL) {
            GetAutoEnter()->Destroy(false);
        }
    }

    GC::AutoRCRootSegment::AutoRCRootSegment(GC* gc, void* mem, size_t size)
        : RCRootSegment(gc, mem, size)
    {
        gc->AddRCRootSegment(this);
    }

    GC::AutoRCRootSegment::~AutoRCRootSegment()
    {
        GetGC()->RemoveRCRootSegment(this);
    }

#ifdef MMGC_HEAP_GRAPH

    void GC::addToBlacklist(const void *gcptr)
    {
        blacklist.add(gcptr, gcptr);
    }

    void GC::removeFromBlacklist(const void *gcptr)
    {
        blacklist.remove(gcptr);
    }

    const void *GC::findGCGraphBeginning(const void *addr, bool &wasDeletedGCRoot)
    {
        /* These are all the possibilities
           1) GC small object
           2) GC large object
           3) GCRoot
           4) OS stack
        */
        if(!IsPointerToGCPage(addr)) {
            GCRoot *r = m_roots;
            while(r)  {
                if(addr >= r->Get() && addr < r->End())
                    return r->Get();
                r = r->next;
            }

            // could be a deleted GCRoot
            GCHeap::HeapBlock *b = heap->AddrToBlock(addr);
            if(b) {
                wasDeletedGCRoot = true;
                if(b->size == 1) {
                    return FixedAlloc::FindBeginning(addr);
                } else {
                    return GetUserPointer(b->baseAddr);
                }
            }
        }
        return FindBeginningGuarded(addr, true); // will return NULL for OS stack
    }

    void GC::dumpBackPointerChain(const void *p, HeapGraph& g)
    {
        GCLog("Dumping back pointer chain for 0x%p\n", p);
        PrintAllocStackTrace(p);
        dumpBackPointerChainHelper(p, g);
        GCLog("End back pointer chain for 0x%p\n", p);
    }

    void GC::dumpBackPointerChainHelper(const void *p, HeapGraph& g)
    {
        GCHashtable *pointers = g.getPointers(p);
        if(pointers) {
            GCHashtable::Iterator iter(pointers);
            const void *addr = iter.nextKey();
            if(addr) {
                bool wasDeletedGCRoot=false;
                const void *container = findGCGraphBeginning(addr, wasDeletedGCRoot);
                const void *displayContainer =  container ? container : addr;
                uint32_t offset = container ? (char*)addr - (char*)container : 0;
                const char *containerDescription = IsPointerToGCPage(container) ? "gc" : (container ? "gcroot" : "stack");
                if(wasDeletedGCRoot)
                    containerDescription = "gcroot-deleted";
                GCLog("0x%p(%x)(%s) -> 0x%p\n", displayContainer, offset, containerDescription, p);
                if(container) {
                    PrintAllocStackTrace(container);
                    dumpBackPointerChainHelper(container, g);
                }
            }
        }
    }

    void HeapGraph::edge(const void *addr, const void *newValue)
    {
        const void *oldValue = GC::Pointer(*(void**)addr);
        newValue = GC::Pointer(newValue);
        GCHashtable *addresses;
        if(oldValue) {
            addresses = (GCHashtable*)backEdges.get(oldValue);
            if(addresses) {
                addresses->remove(addr);
            }
        }
        if(newValue) {
            addresses = (GCHashtable*)backEdges.get(newValue);
            if(!addresses) {
                addresses = mmfx_new(GCHashtable());
                backEdges.put(newValue, addresses);
            }
            addresses->add(addr, addr);
        }
    }

    void HeapGraph::clear()
    {
        GCHashtable_VMPI::Iterator iter(&backEdges);
        const void *key;
        while((key = iter.nextKey()) != NULL) {
            GCHashtable *addresses = (GCHashtable*)iter.value();
            mmfx_delete(addresses);
        }
        backEdges.clear();
    }

    GCHashtable *HeapGraph::getPointers(const void *obj)
    {
        return (GCHashtable*)backEdges.get(obj);
    }

    void GC::pruneBlacklist()
    {
        if(blacklist.count() > 0) {
            GCHashtable::Iterator iter(&blacklist);
            const void *p;
            while((p = iter.nextKey()) != NULL) {
                if(!GetMark(p)) {
                    removeFromBlacklist(p);
                }
            }
        }
    }

    void GC::printBlacklist()
    {
        if(blacklist.count() > 0) {
            GCHashtable::Iterator iter(&blacklist);
            const void *p;
            while((p = iter.nextKey()) != NULL) {
                GCLog("Blacklist item 0x%p %s found in marker graph\n", p, markerGraph.getPointers(p) ? "was" : "wasn't");
                GCLog("Blacklist item 0x%p %s found in mutator graph\n", p, mutatorGraph.getPointers(p) ? "was" : "wasn't");
                dumpBackPointerChain(p, markerGraph);
            }
        }
    }
#endif
}

