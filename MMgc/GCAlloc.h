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

#ifndef __GCAlloc__
#define __GCAlloc__


namespace MMgc
{
    class GCAllocBase {
    public:
        virtual ~GCAllocBase();
        virtual void Free(const void* item) = 0;
    };

    // Some common functionality for GCAlloc and GCLargeAlloc follows.  (Could be
    // in a separate header file.)

    // Mark bit item.
    typedef uint8_t gcbits_t;

    /**
     * Common block header for GCAlloc and GCLargeAlloc.
     */
    struct GCBlockHeader
    {
        GC*             gc;     // The GC that owns this block
        GCAllocBase*    alloc;  // the allocator that owns this block
        GCBlockHeader*  next;   // The next block in the list of blocks for the allocator
        gcbits_t*       bits;   // Variable length table of mark bit entries
        uint32_t        size;   // Size of objects stored in this block
#ifdef MMGC_FASTBITS
        uint32_t        bitsShift;  // Right shift for lower 12 bits of a pointer into the block to obtain the mark bit item for that pointer
#endif
    };

    GCBlockHeader* GetBlockHeader(const void* item);

    // These are common to small and large objects.  Large objects have additional bits,
    // but those bits are stored elsewhere.

    enum {
        kMark=1,
        kQueued=2,
        kFinalizable=4,
        kHasWeakRef=8
        // free: 16
        // free: 32
        // free: 64
        // free: 128
    };

    /**
     *
     * This is a fast, fixed-size memory allocator for garbage-collected
     * objects.
     *
     * Memory is allocated from the system on 4096-byte aligned boundaries,
     * which corresponds to the size of an OS page in Windows XP.  Allocation
     * of pages is performed via the GCPageAlloc class.
     *
     * In each 4096-byte block, there is a block header with marked bits,
     * finalize bits, the pointer to the next free item and "recycling"
     * free item linked list.
     *
     * The bits of the "marked" bitmap are controlled by the SetMark method.
     *
     * The bits of the "finalize" bitmap are set when an item is
     * allocated.  The value for the finalize bit is passed in as a
     * parameter to the allocation call.
     *
     * When the Sweep method is invoked, all objects that are not marked
     * with the specified mark flag are disposed of.  If the corresponding
     * finalize bit is set, the GCObject destructor is invoked on that
     * item.
     *
     * When an allocation is requested and there are no more free
     * entries, GCAlloc will request that a garbage collection take
     * place.  It will allocate new blocks if more than 20% of its
     * blocks are used after the collection, targeting a 5:1
     * heap size / minimim heap size ratio.
     *
     */
    class GCAlloc : public GCAllocBase
    {
        friend class GC;
        friend class GCAllocIterator;
        friend class ZCT;

    public:
        // The destructor needs to be public because it is called explicitly by
        // the implementation of one of the mmfx_delete macros.
        ~GCAlloc();

    private:
        struct GCBlock;

        enum { kFreelist=kMark|kQueued };

        GCAlloc(GC* gc, int itemSize, bool containsPointers, bool isRC, int sizeClassIndex);

#if defined DEBUG || defined MMGC_MEMORY_PROFILER
        void* Alloc(size_t size, int flags);
#else
        void* Alloc(int flags);
#endif
        virtual void Free(const void* item);

        void Finalize();
        void ClearMarks();
#ifdef _DEBUG
        void CheckMarks();
        void CheckFreelist();
        static bool IsWhite(const void *item);
#endif // _DEBUG

        static void *FindBeginning(const void *item);
        static bool ContainsPointers(const void *item);
        static bool IsRCObject(const void *item);
        static bool IsUnmarkedPointer(const void *val);
        static void SetBlockHasWeakRef(const void *userptr);

        REALLY_INLINE uint32_t GetItemSize() { return m_itemSize; }
        REALLY_INLINE int GetNumAlloc() const { return m_numAlloc; }
        REALLY_INLINE int GetMaxAlloc() const { return m_maxAlloc; }
        REALLY_INLINE int GetNumBlocks() const { return m_numBlocks; }

        REALLY_INLINE bool ContainsPointers() const { return containsPointers; }
        REALLY_INLINE bool ContainsRCObjects() const { return containsRCObjects; }

        void GetBitsPages(void **pages);

        //This method returns the number bytes allocated for GC objects
        size_t GetBytesInUse();

        //This method is for more fine grained allocation details
        //It reports the total number of bytes requested (i.e. ask size) and
        //the number of bytes actually allocated.  The latter is the same
        //number as reported by GetBytesInUse()
        void GetUsageInfo(size_t& totalAskSize, size_t& totalAllocated);

#ifdef MMGC_MEMORY_PROFILER
        size_t GetTotalAskSize() { return m_totalAskSize; }
#endif

    private:
        const static int kBlockSize = 4096;         // This must be the same as GCHeap::kBlockSize, we check it in GCAlloc::GCAlloc

        const static short kFlagNeedsSweeping = 1;  // set if the block had finalized objects and needs to be swept
        const static short kFlagWeakRefs = 2;       // set if the block may have weak refs and we should check during free

        // Objects on the free list all have a next pointer in the first word and
        // the object index within its block as the second word.  Only the low 16 bits
        // of the second word are significant: the reference counter messes around
        // with the high 16 bits during pinning; it may pin dead objects.  Those that
        // use the index must be careful to mask off the high bits.

        struct GCBlock : public GCBlockHeader
        {
            GCBlock* prev;          // the previous block on the list of all blocks ('next' is in the block header)
            void*  firstFree;       // first item on free list
            GCBlock *prevFree;      // the previous block on the lists of blocks with free or sweepable objects
            GCBlock *nextFree;      // the next block on the lists of blocks with free or sweepable objects
            short numFree;          // the number of free objects in this block
            uint8_t slowFlags;      // flags for special circumstances: kFlagNeedsSweeping, etc
            bool finalizeState:1;   // whether we've been visited during the Finalize stage
            char   *items;          // pointer to the array of objects in the block

            int GetCount() const;
            void FreeSweptItem(const void *item, int index);
            int needsSweeping();
            void setNeedsSweeping(int v);
        };

        static GCBlock *GetBlock(const void *item);

#ifdef MMGC_MEMORY_INFO
        static void VerifyFreeBlockIntegrity(void* item, uint32_t size, uint32_t limit=~0U);
#endif

        // The list of chunk blocks
        GCBlock* m_firstBlock;
        GCBlock* m_lastBlock;

        // The lowest priority block that has free items
        GCBlock* m_firstFree;

        // List of blocks that need sweeping
        GCBlock* m_needsSweeping;

        // Quick list of free objects.  See comment in GCAlloc.cpp for general information.

        void *m_qList;              // Linked list of some free objects for this allocator
        int   m_qBudget;            // Number of items we can yet free before obtaining a larger budget
        int   m_qBudgetObtained;    // Quick list budget actually obtained from the GC for this allocator

        int    m_itemsPerBlock;
        uint32_t    m_itemSize;
        int m_numBitmapBytes;
        int m_sizeClassIndex;

#ifdef MMGC_MEMORY_PROFILER
        size_t m_totalAskSize;
#endif

        bool m_bitsInPage;

        int    m_maxAlloc;
        int    m_numAlloc;
        int    m_numBlocks;

#ifdef MMGC_FASTBITS
        // Right shift for lower 12 bits of a pointer into the block to obtain
        // the gcbits_t item for that pointer.  Is copied into the block header.
        uint32_t m_bitsShift;
#endif

        // fast divide numbers for GetObjectIndex
        uint16_t multiple;
        uint16_t shift;

        bool containsPointers;
        bool containsRCObjects;
        bool m_finalized;

#ifdef _DEBUG
        bool IsOnEitherList(GCBlock *b);
        void VerifyNotFree(GCBlock* b, const void *item);
#endif

        GCBlock* CreateChunk(int flags);
        void UnlinkChunk(GCBlock *b);
        void FreeChunk(GCBlock* b);

        // not a hot method
        void AddToFreeList(GCBlock *b);

        // not a hot method
        void RemoveFromFreeList(GCBlock *b);

        // not a hot method
        void AddToSweepList(GCBlock *b);

        // not a hot method
        void RemoveFromSweepList(GCBlock *b);

#if defined DEBUG || defined MMGC_MEMORY_PROFILER
        void* AllocSlow(size_t askSize, int flags);
        void* AllocFromQuickList(size_t askSize, int flags);
#else
        void* AllocSlow(int flags);
        void* AllocFromQuickList(int flags);
#endif
        void FillQuickList(GCBlock* b);
        void CoalesceQuickList();
        void QuickListBudgetExhausted();
        void FreeSlow(GCBlock* b, int index, const void* item);
        void ClearNonRCObject(void* item, size_t size);

        bool Sweep(GCBlock *b);
        void SweepGuts(GCBlock *b);

        void ClearMarks(GCAlloc::GCBlock* block);
        void SweepNeedsSweeping();

#ifdef _DEBUG
        static bool IsPointerIntoGCObject(const void *item);
        static int ConservativeGetMark(const void *item, bool bogusPointerReturnValue);
#endif

        // NOTE that GetObjectIndex and GetBitsIndex are not the same if MMGC_FASTBITS
        // is defined.  That is an efficiency concern; the representation of the bits 
        // table allows the bits index to be computed more quickly, and that shortens 
        // the hot control paths.  Both functions are very hot.

        // Compute the offset within the block of the given object.
        static uint32_t GetObjectIndex(const GCBlock *block, const void *item);

        // Compute the offset within the bits table of the given object.
        static uint32_t GetBitsIndex(const GCBlock *block, const void *item);
        
#ifndef MMGC_FASTBITS
        static gcbits_t& GetGCBits(const void* realptr);
#endif

        static void ClearBits(GCBlock *block, int index, int bits);

        // not a hot method
        static void ClearQueued(const void *userptr);

        void ComputeMultiplyShift(uint16_t d, uint16_t &muli, uint16_t &shft);

    protected:
        GC *m_gc;

    public:
        static GCBlock* Next(GCBlock* b);
    };

    /**
     * A utility class used by the marker to handle mark stack overflow: it abstracts
     * iterating across marked, non-free objects in one allocator instance.
     *
     * No blocks must be added or removed during the iteration.  If an object's
     * bits are changed, those changes will visible to the iterator if the object has
     * not yet been reached by the iteration.
     */
    class GCAllocIterator
    {
    public:
        GCAllocIterator(MMgc::GCAlloc* alloc);

        bool GetNextMarkedObject(void*& out_ptr, uint32_t& out_size);

    private:
        GCAlloc* const alloc;
        GCAlloc::GCBlock* block;
        uint32_t idx;
        uint32_t limit;
        uint32_t size;
    };
}

#endif /* __GCAlloc__ */
