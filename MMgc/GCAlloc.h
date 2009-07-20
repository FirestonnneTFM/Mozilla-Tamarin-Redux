/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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
	// Some common functionality for GCAlloc and GCLargeAlloc follows.  (Could be
	// in a separate header file.)
	
	/**
	 * Common block header for GCAlloc and GCLargeAlloc.
	 */
	struct GCBlockHeader
	{
		GC*				gc;		// The GC that owns this block
		GCBlockHeader*	next;	// The next block in the list of blocks for the allocator
		uint32_t		size;	// Size of objects stored in this block
	};
	
	REALLY_INLINE GCBlockHeader* GetBlockHeader(const void* item)
	{
		return (GCBlockHeader*)(uintptr_t(item) & ~0xFFF);
	}

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
	class GCAlloc : public GCAllocObject
	{
		friend class GC;
		friend class GCAllocIterator;
	public:
		enum ItemBit { kMark=1, kQueued=2, kFinalize=4, kHasWeakRef=8, kFreelist=kMark|kQueued };

		GCAlloc(GC* gc, int itemSize, bool containsPointers, bool isRC, int sizeClassIndex);
		~GCAlloc();
		
		void* Alloc(size_t size, int flags);
		static void Free(const void *ptr);
		void Finalize();
		uint32_t GetItemSize() { return m_itemSize; }
		void ClearMarks();
#ifdef _DEBUG
		void CheckMarks();
#endif

		REALLY_INLINE static int SetMark(const void *item)
		{
			GCBlock *block = GetBlock(item);
			int index = GetIndex(block, item);
			int mask = kMark << ((index&7)<<2);
			uint32_t *bits = &block->GetBits()[index>>3];
			int set = *bits & mask;
			*bits |= mask;
			*bits &= ~(kQueued << ((index&7)<<2));
			return set;
		}

		// Not a hot method
		static int SetFinalize(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return SetBit(block, GetIndex(block, item), kFinalize);
		}
		
#ifdef _DEBUG
		static bool IsWhite(const void *item)
		{
			GCBlock *block = GetBlock(item);
			// not a real item
			if(item < block->items)
				return false;

			if(FindBeginning(item) != item)
				return false;

			return IsWhite(block, GetIndex(block, item));
		}
#endif // _DEBUG

		REALLY_INLINE static int GetMark(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return GetBit(block, GetIndex(block, item), kMark);
		}

		REALLY_INLINE static void *FindBeginning(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return block->items + block->size * GetIndex(block, item);
		}

		REALLY_INLINE static bool IsMarkedThenMakeQueued(const void *item)
		{
			GCBlock *block = GetBlock(item);
			int index = GetIndex(block, item);
			uint32_t* bits = block->GetBits() + (index >> 3);
			if (*bits & (kMark << ((index&7)<<2))) {
				*bits ^= (kMark|kQueued) << ((index&7)<<2);
				return true;
			}
			return false;
		}

		REALLY_INLINE static bool IsQueued(const void *item)
		{
			GCBlock *block = GetBlock(item);
			int index = GetIndex(block, item);
			uint32_t* bits = block->GetBits() + (index >> 3);
			return (*bits & (kQueued << ((index&7)<<2))) != 0;
		}

		// not a hot method
		static void ClearFinalized(const void *item)
		{
			GCBlock *block = GetBlock(item);
			ClearBits(block, GetIndex(block, item), kFinalize);
		}		

		// not a hot method
		static int IsFinalized(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return GetBit(block, GetIndex(block, item), kFinalize);
		}

		// not a hot method
		static int HasWeakRef(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return GetBit(block, GetIndex(block, item), kHasWeakRef);
		}		
		
		// Very hot: called in the inner loop of GC::MarkItem
		REALLY_INLINE static bool ContainsPointers(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return block->alloc->ContainsPointers();
		}

		// Can be hot - used by PinStackObjects
		REALLY_INLINE static bool IsRCObject(const void *item)
		{
			GCBlock *block = GetBlock(item);
			return item >= block->items && block->alloc->ContainsRCObjects();
		}

		static bool IsUnmarkedPointer(const void *val);
		
		int GetNumAlloc() const { return m_numAlloc; }
		int GetMaxAlloc() const { return m_maxAlloc; }
		int GetNumBlocks() const { return m_numBlocks; }

		bool ContainsPointers() const { return containsPointers; }
		bool ContainsRCObjects() const { return containsRCObjects; }

		void GetBitsPages(void **pages);

		// not a hot method
		static void SetHasWeakRef(const void *item, bool to)
		{
			GCBlock *block = GetBlock(item);
			if(to) {
				SetBit(block, GetIndex(block, item), kHasWeakRef);
			} else {
				ClearBits(block, GetIndex(block, item), kHasWeakRef);
			}
		}

		//This method returns the number bytes allocated for GC objects
		size_t GetBytesInUse();
		
		//This method is for more fine grained allocation details
		//It reports the total number of bytes requested (i.e. ask size) and
		//the number of bytes actually allocated.  The latter is the same
		//number as reported by GetBytesInUse()
		void GetUsageInfo(size_t& totalAskSize, size_t& totalAllocated);
		
#ifdef MMGC_MEMORY_PROFILER	
		size_t GetTotalAskSize()
		{
			return m_totalAskSize;
		}
#endif

	private:
		const static int kBlockSize = 4096;

		struct GCBlock : GCBlockHeader
		{
			GCAlloc *alloc;			
			GCBlock* prev;
			char*  nextItem;
			void*  firstFree;        // first item on free list
			GCBlock *prevFree;
			GCBlock *nextFree;
			uint32_t* bits;
			short numItems;
			bool needsSweeping:1; 
			bool finalizeState:1;  // whether we've been visited during the Finalize stage
			char   *items;

			REALLY_INLINE int GetCount() const
			{
				if (nextItem) {
					return GCAlloc::GetIndex(this, nextItem);
				} else {
					return alloc->m_itemsPerBlock;
				}
			}

			REALLY_INLINE uint32_t *GetBits() const
			{
				return bits;
			}
			
			void FreeItem(const void *item, int index);

			REALLY_INLINE bool IsFull()
			{
				bool full = (nextItem == firstFree);
				// the only time nextItem and firstFree should be equal is when they
				// are both zero which is also when we are full, assert to be sure
				GCAssert(!full || nextItem==0);
				GCAssert(!full || numItems == alloc->m_itemsPerBlock);
				return full;
			}
		};
		
		REALLY_INLINE static GCBlock *GetBlock(const void *item)
		{ 
			return (GCBlock*)GetBlockHeader(item);
		}
		
#ifdef MMGC_MEMORY_INFO
		static void VerifyFreeBlockIntegrity(const void* item, uint32_t size);
#endif

		// The list of chunk blocks
		GCBlock* m_firstBlock; 
		GCBlock* m_lastBlock;

		// The lowest priority block that has free items		
		GCBlock* m_firstFree;

		// List of blocks that need sweeping
		GCBlock* m_needsSweeping;

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

		// fast divide numbers
		uint16_t multiple;
		uint16_t shift;

		bool containsPointers;
		bool containsRCObjects;
		bool m_finalized;
		
#ifdef _DEBUG
		bool IsOnEitherList(GCBlock *b)
		{
			return b->nextFree != NULL || b->prevFree != NULL || b == m_firstFree || b == m_needsSweeping;
		}
#endif

		GCBlock* CreateChunk(int flags);
		void UnlinkChunk(GCBlock *b);
		void FreeChunk(GCBlock* b);
		
		// not a hot method
		void AddToFreeList(GCBlock *b)
		{
			GCAssert(!IsOnEitherList(b) && !b->needsSweeping);
			b->prevFree = NULL;
			b->nextFree = m_firstFree;
			if (m_firstFree) {
				GCAssert(m_firstFree->prevFree == 0 && m_firstFree != b);
				m_firstFree->prevFree = b;
			}
			m_firstFree = b;			
		}

		// not a hot method
		void RemoveFromFreeList(GCBlock *b)
		{
			GCAssert(m_firstFree == b || b->prevFree != NULL);
			if ( m_firstFree == b )
				m_firstFree = b->nextFree;
			else
				b->prevFree->nextFree = b->nextFree;
			
			if (b->nextFree)
				b->nextFree->prevFree = b->prevFree;
			b->nextFree = b->prevFree = NULL;
		}

		// not a hot method
		void AddToSweepList(GCBlock *b)
		{
			GCAssert(!IsOnEitherList(b) && !b->needsSweeping);
			b->prevFree = NULL;
			b->nextFree = m_needsSweeping;
			if (m_needsSweeping) {
				GCAssert(m_needsSweeping->prevFree == 0);
				m_needsSweeping->prevFree = b;
			}
			m_needsSweeping = b;
			b->needsSweeping = true;
		}

		// not a hot method
		void RemoveFromSweepList(GCBlock *b)
		{
			GCAssert(m_needsSweeping == b || b->prevFree != NULL);
			if ( m_needsSweeping == b )
				m_needsSweeping = b->nextFree;
			else
				b->prevFree->nextFree = b->nextFree;
			
			if (b->nextFree)
				b->nextFree->prevFree = b->prevFree;
			b->needsSweeping = false;
			b->nextFree = b->prevFree = NULL;
		}

		bool Sweep(GCBlock *b);
		void SweepGuts(GCBlock *b);

		void ClearMarks(GCAlloc::GCBlock* block);
		void SweepNeedsSweeping();

#ifdef _DEBUG
		static int ConservativeGetMark(const void *item, bool bogusPointerReturnValue);
#endif

		// very hot
		REALLY_INLINE static int GetIndex(const GCBlock *block, const void *item)
		{
			int index = (int)((((char*) item - block->items) * block->alloc->multiple) >> block->alloc->shift);
#ifdef _DEBUG
			GCAssert(((char*) item - block->items) / block->size == (uint32_t) index);
#endif
			return index;
		}			

		REALLY_INLINE static int SetBit(GCBlock *block, int index, int bit)
		{
			int mask = bit << ((index&7)<<2);
			int set = (block->GetBits()[index>>3] & mask);
			block->GetBits()[index>>3] |= mask;
			return set;
		}

		REALLY_INLINE static int GetBit(GCBlock *block, int index, int bit)
		{
			int mask = bit << ((index&7)<<2);
			return block->GetBits()[index>>3] & mask;
		}

		// not a hot method
		static void ClearBits(GCBlock *block, int index, int bits)
		{
			int mask = bits << ((index&7)<<2);
			block->GetBits()[index>>3] &= ~mask;
		}

		// not a hot method
		static void ClearQueued(const void *item)
		{
			GCBlock *block = GetBlock(item);
			ClearBits(block, GetIndex(block, item), kQueued);
		}
		
#ifdef _DEBUG
		static bool IsPointerIntoGCObject(const void *item)
		{
			GCBlock *block = GetBlock(item);
			if(item < block->items)
				return false;
			return GetBit(block, GetIndex(block, item), kFreelist) != kFreelist;
		}

		static int IsWhite(GCBlock *block, int index)
		{
			return (block->GetBits()[index>>3] & ((kMark|kQueued)<<((index&7)<<2))) == 0;
		}
#endif

		void ComputeMultiplyShift(uint16_t d, uint16_t &muli, uint16_t &shft);

	protected:
		GC *m_gc;

	public:
		REALLY_INLINE static GCBlock* Next(GCBlock* b)
		{
			return (GCBlock*)b->next;
		}
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
		GCAllocIterator(MMgc::GCAlloc* alloc) 
			: alloc(alloc)
			, block(alloc->m_firstBlock)
			, idx(0)
			, limit(alloc->m_itemsPerBlock)
			, size(alloc->m_itemSize)
		{
		}
		
		bool GetNextMarkedObject(void*& out_ptr, uint32_t& out_size)
		{
			for (;;) {
				if (idx == limit) {
					idx = 0;
					block = GCAlloc::Next(block);
				}
				if (block == NULL)
					return false;
				uint32_t i = idx++;
				if (GCAlloc::GetBit(block, i, MMgc::GCAlloc::kMark) && !GCAlloc::GetBit(block, i, MMgc::GCAlloc::kQueued)) {
					out_ptr = GetUserPointer(block->items + i*size);
					out_size = size - (uint32_t)DebugSize();
					return true;
				}
			}
		}
		
	private:
		GCAlloc* const alloc;
		GCAlloc::GCBlock* block;
		uint32_t idx;
		uint32_t limit;
		uint32_t size;
	};
}

#endif /* __GCAlloc__ */
