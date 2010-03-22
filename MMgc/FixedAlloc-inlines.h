/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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

#ifndef __FixedAlloc_inlines__
#define __FixedAlloc_inlines__

// Inline methods for FixedAlloc, FixedAllocSafe, and FastAllocator

namespace MMgc
{
	REALLY_INLINE size_t FixedAlloc::GetBytesInUse()
	{
		size_t totalAskSize, totalAllocated;  
		GetUsageInfo(totalAskSize, totalAllocated);
		return totalAllocated;			
	}
		
	REALLY_INLINE size_t FixedAlloc::GetMaxAlloc() const
	{
		return m_maxAlloc;
	}

	REALLY_INLINE size_t FixedAlloc::GetNumChunks()
	{
		return m_maxAlloc / m_itemsPerBlock;
	}

	/*static*/
	REALLY_INLINE FixedAlloc *FixedAlloc::GetFixedAlloc(void *item)
	{
		return GetFixedBlock(item)->alloc;
	}

	REALLY_INLINE bool FixedAlloc::IsFull(FixedBlock *b) const
	{
		return b->numAlloc == m_itemsPerBlock;
	}

	/*static*/
	REALLY_INLINE FixedAlloc::FixedBlock* FixedAlloc::GetFixedBlock(const void *item)
	{
		return (FixedBlock*) ((uintptr_t)item & ~0xFFF);
	}

	/*static*/
	REALLY_INLINE size_t FixedAlloc::Size(const void *item)
	{
		return GetFixedBlock(item)->size;
	}

#ifdef MMGC_HOOKS

	REALLY_INLINE void FixedAlloc::InlineAllocHook(size_t size, void *item)
	{
		FixedBlock *b = (FixedBlock*) ((uintptr_t)item & ~0xFFF);
		if(m_heap->HooksEnabled()) {
			m_heap->AllocHook(item, size, b->size - DebugSize());
		}
	}

	/*static*/
	REALLY_INLINE void FixedAlloc::InlineFreeHook(void *item MMGC_MEMORY_PROFILER_ARG(size_t& askSize))
	{
		FixedBlock *b = (FixedBlock*) ((uintptr_t)item & ~0xFFF);
		GCHeap *heap = b->alloc->m_heap;
		if(heap->HooksEnabled()) {
#ifdef MMGC_MEMORY_PROFILER
			if(heap->GetProfiler())
				askSize = heap->GetProfiler()->GetAskSize(item);
#endif			
			heap->FinalizeHook(item, b->size - DebugSize());
			heap->FreeHook(item, b->size - DebugSize(), 0xed);
		}
	}

#endif // MMGC_HOOKS

	REALLY_INLINE void* FixedAllocSafe::Alloc(size_t size, FixedMallocOpts flags)
	{
		void *item;
		{
			MMGC_LOCK(m_spinlock);
			item = FixedAlloc::InlineAllocSansHook(size, flags); 
		}
#ifdef MMGC_HOOKS
		InlineAllocHook(size, item);
#endif
		return item;
	}

	REALLY_INLINE void FixedAllocSafe::Free(void *ptr)
	{
#ifdef MMGC_MEMORY_PROFILER
		size_t askSize = 0;
#endif
#ifdef MMGC_HOOKS
		InlineFreeHook(ptr MMGC_MEMORY_PROFILER_ARG(askSize));
#endif
		{
			MMGC_LOCK(m_spinlock);
			FixedAlloc::InlineFreeSansHook(ptr MMGC_MEMORY_PROFILER_ARG(askSize));
		}
	}

	REALLY_INLINE void* FixedAlloc::InlineAllocSansHook(size_t size, FixedMallocOpts opts)
	{ 
		(void)size;
		GCAssertMsg(m_heap->IsStackEntered() || (opts&kCanFail) != 0, "MMGC_ENTER must be on the stack");
		GCAssertMsg(((size_t)m_itemSize >= size), "allocator itemsize too small");

		if(!m_firstFree) {
			bool canFail = (opts & kCanFail) != 0;
			CreateChunk(canFail);
			if(!m_firstFree) {
				if (!canFail) {
					GCAssertMsg(0, "Memory allocation failed to abort properly");
					GCHeap::SignalInconsistentHeapState("Failed to abort");
					/*NOTREACHED*/
				}
				return NULL;
			}
		}

		FixedBlock* b = m_firstFree;
		GCAssert(b && !IsFull(b));

		b->numAlloc++;

		// Consume the free list if available
		void *item = NULL;
		if (b->firstFree) {
			item = b->firstFree;
			b->firstFree = *((void**)item);
			// assert that the freelist hasn't been tampered with (by writing to the first 4 bytes)
			GCAssert(b->firstFree == NULL || 
					(b->firstFree >= b->items && 
					(((uintptr_t)b->firstFree - (uintptr_t)b->items) % b->size) == 0 && 
					(uintptr_t) b->firstFree < ((uintptr_t)b & ~0xfff) + GCHeap::kBlockSize));
#ifdef MMGC_MEMORY_INFO				
			//check for writes on deleted memory
			VerifyFreeBlockIntegrity(item, b->size);
#endif
		} else {
			// Take next item from end of block
			item = b->nextItem;
			GCAssert(item != 0);
			if(!IsFull(b)) {
				// There are more items at the end of the block
				b->nextItem = (void *) ((uintptr_t)item+m_itemSize);
			} else {
				b->nextItem = 0;
			}
		}

		// If we're out of free items, be sure to remove ourselves from the
		// list of blocks with free items.  
		if (IsFull(b)) {
			m_firstFree = b->nextFree;
			b->nextFree = NULL;
			GCAssert(b->prevFree == NULL);

			if (m_firstFree)
				m_firstFree->prevFree = 0;
		}

		item = GetUserPointer(item);

#ifdef _DEBUG
		// fresh memory poisoning
		if((opts & kZero) == 0)
			memset(item, 0xfa, b->size - DebugSize());
#endif

		if((opts & kZero) != 0)
			memset(item, 0, b->size - DebugSize());

#ifdef MMGC_MEMORY_PROFILER
		if(m_heap->HooksEnabled()) 
			m_totalAskSize += size;
#endif

		return item;
	}

	/*static*/
	REALLY_INLINE void FixedAlloc::InlineFreeSansHook(void *item MMGC_MEMORY_PROFILER_ARG(size_t askSize))
	{
		FixedBlock *b = (FixedBlock*) ((uintptr_t)item & ~0xFFF);
		GCAssertMsg(b->alloc->m_heap->IsAddressInHeap(item), "Bogus pointer passed to free");

#ifdef MMGC_MEMORY_PROFILER
		GCHeap *heap = b->alloc->m_heap;
		if(heap->GetProfiler())
			b->alloc->m_totalAskSize -= askSize;
#endif
		
		item = GetRealPointer(item);

		// Add this item to the free list
		*((void**)item) = b->firstFree;
		b->firstFree = item;

		// We were full but now we have a free spot, add us to the free block list.
		if (b->numAlloc == b->alloc->m_itemsPerBlock)
		{
			GCAssert(!b->nextFree && !b->prevFree);
			b->nextFree = b->alloc->m_firstFree;
			if (b->alloc->m_firstFree)
				b->alloc->m_firstFree->prevFree = b;
			b->alloc->m_firstFree = b;
		}
#ifdef _DEBUG
		else // we should already be on the free list
		{
			GCAssert ((b == b->alloc->m_firstFree) || b->prevFree);
		}
#endif

		b->numAlloc--;

		if(b->numAlloc == 0) {
			b->alloc->FreeChunk(b);
		}
	}

#ifdef _DEBUG
	REALLY_INLINE bool FixedAllocSafe::QueryOwnsObject(const void* item)
	{
		MMGC_LOCK(m_spinlock);
		return FixedAlloc::QueryOwnsObject(item);
	}
#endif
	
	/*static*/
	REALLY_INLINE FixedAllocSafe* FixedAllocSafe::GetFixedAllocSafe(void *item)
	{
		return (FixedAllocSafe*) FixedAlloc::GetFixedAlloc(item);
	}

	/*static*/
	REALLY_INLINE void* FastAllocator::operator new(size_t size, FixedAlloc *alloc)
	{
		return alloc->Alloc(size);
	}
	
	/*static*/
	REALLY_INLINE void FastAllocator::operator delete(void *item)
	{
		FixedAlloc::Free(item);
	}

}

#endif /* __FixedAlloc_inlines__ */
