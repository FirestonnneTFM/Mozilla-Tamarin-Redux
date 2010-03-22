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

#include "MMgc.h"

#define kBlockHeadSize offsetof(MMgc::FixedAlloc::FixedBlock, items)

namespace MMgc
{
	FixedAlloc::FixedAlloc(uint32_t itemSize, GCHeap* heap, bool isFixedAllocSafe)
		: m_isFixedAllocSafe(isFixedAllocSafe)
	{
		Init(itemSize, heap);
	}

	FixedAlloc::FixedAlloc() 
		: m_isFixedAllocSafe(true)
	{
	}
	
	void FixedAlloc::Init(uint32_t itemSize, GCHeap* heap)
	{
		m_heap = heap;
		m_firstBlock    = NULL;
		m_lastBlock     = NULL;
		m_firstFree     = NULL;
		m_maxAlloc      = 0;

#ifdef MMGC_MEMORY_INFO
		itemSize += (int)DebugSize();
#endif

		m_itemSize      = itemSize;

#ifdef MMGC_MEMORY_PROFILER
		m_totalAskSize = 0;
#endif

		// The number of items per block is kBlockSize minus
		// the # of pointers at the base of each page.
		size_t usableSpace = GCHeap::kBlockSize - kBlockHeadSize;
		m_itemsPerBlock = (int)(usableSpace / m_itemSize);
	}

	FixedAlloc::~FixedAlloc()
	{   
		Destroy();
	}

	bool FixedAlloc::IsOnFreelist(FixedBlock *b, void *item)
	{
		void *fl = b->firstFree;
		while(fl) {
			if(item == fl)
				return true;
			fl = *(void**)fl;
		}
		return false;
	}
	
	bool FixedAlloc::IsInUse(FixedBlock *b, void *item)
	{
		if(b->nextItem && item >= b->nextItem)
			return false;
		return !IsOnFreelist(b, item);
	}

	void FixedAlloc::Destroy()
	{
		// Free all of the blocks
 		while (m_firstBlock) {
#ifdef MMGC_MEMORY_PROFILER
			if(m_firstBlock->numAlloc > 0 && m_heap->GetStatus() != kMemAbort) {
				union {
					char* mem_c;
					uint32_t* mem;
				};
				mem_c = m_firstBlock->items;
				unsigned int itemNum = 0;
				while(itemNum++ < m_itemsPerBlock) {
					if(IsInUse(m_firstBlock, mem)) {
						// supress output in release build UNLESS the profiler is on
#ifndef DEBUG
						if(m_heap->GetProfiler() != NULL)
#endif
						{
							GCLog("Leaked %d byte item.  Addr: 0x%p\n", GetItemSize(), GetUserPointer(mem));
							PrintAllocStackTrace(GetUserPointer(mem));
						}
					}
					mem_c += m_itemSize;
				}
			}

#ifdef MMGC_MEMORY_INFO
			//check for writes on deleted memory
			VerifyFreeBlockIntegrity(m_firstBlock->firstFree, m_firstBlock->size);
#endif

#endif
			FreeChunk(m_firstBlock);
		}
		m_firstBlock = NULL;
	}

	void* FixedAlloc::Alloc(size_t size, FixedMallocOpts flags)
	{
		void *item = InlineAllocSansHook(size, flags); 
#ifdef MMGC_HOOKS
		InlineAllocHook(size, item);
#endif
		return item;
	}

	void FixedAlloc::Free(void *ptr)
	{	
#ifdef MMGC_MEMORY_PROFILER
		size_t askSize = 0;
#endif
#ifdef MMGC_HOOKS
		InlineFreeHook(ptr MMGC_MEMORY_PROFILER_ARG(askSize));
#endif
		FixedAlloc::InlineFreeSansHook(ptr MMGC_MEMORY_PROFILER_ARG(askSize));
	}

	void FixedAlloc::GetUsageInfo(size_t& totalAsk, size_t& totalAllocated)
	{
		totalAsk = totalAllocated = 0;

		FixedBlock *b = m_firstBlock;
		while(b)
		{
			totalAllocated += b->numAlloc * b->size;
			b = b->next;
		}
	
#ifdef MMGC_MEMORY_PROFILER
		totalAsk  = m_totalAskSize;
#endif
	}

	void FixedAlloc::CreateChunk(bool canFail)
	{
		// Allocate a new block
		m_maxAlloc += m_itemsPerBlock;

		vmpi_spin_lock_t *lock = NULL;
		if(m_isFixedAllocSafe) {
			lock = &((FixedAllocSafe*)this)->m_spinlock;
			VMPI_lockRelease(lock);
		}

		FixedBlock* b = (FixedBlock*) m_heap->Alloc(1, GCHeap::kExpand | (canFail ? GCHeap::kCanFail : 0));

		if(lock != NULL)
			VMPI_lockAcquire(lock);
		
		GCAssert(m_itemSize <= 0xffff);

		if(!b)
			return;
		
		b->numAlloc = 0;
		b->size = (uint16_t)m_itemSize;
		b->firstFree = 0;
		b->nextItem = b->items;
		b->alloc = this;

#ifdef _DEBUG
		// deleted and unused memory is 0xed'd, this is important for leak diagnostics
		VMPI_memset(b->items, 0xed, m_itemSize * m_itemsPerBlock);
#endif

		// Link the block at the end of the list
		b->prev = m_lastBlock;
		b->next = 0;
		if (m_lastBlock) {
			m_lastBlock->next = b;
		}
		if (!m_firstBlock) {
			m_firstBlock = b;
		}
		m_lastBlock = b;

		// Add our new ChunkBlock to the firstFree list (which should
		// be empty but might not because we let go of the lock above)
		if (m_firstFree)
		{
			GCAssert(m_firstFree->prevFree == 0);
			m_firstFree->prevFree = b;
		}
		b->nextFree = m_firstFree;
		b->prevFree = 0;
		m_firstFree = b;

		return;
	}
	
	void FixedAlloc::FreeChunk(FixedBlock* b)
	{
		m_maxAlloc -= m_itemsPerBlock;

		// Unlink the block from the list
		if (b == m_firstBlock) {
			m_firstBlock = b->next;
		} else {
			b->prev->next = b->next;
		}
		
		if (b == m_lastBlock) {
			m_lastBlock = b->prev;
		} else {
			b->next->prev = b->prev;
		}

		// If this is the first free block, pick a new one...
		if ( m_firstFree == b )
			m_firstFree = b->nextFree;
		else if (b->prevFree)
			b->prevFree->nextFree = b->nextFree;

		if (b->nextFree)
			b->nextFree->prevFree = b->prevFree;

		// Free the memory
		m_heap->FreeNoProfile(b);
	}

	size_t FixedAlloc::GetItemSize() const
	{
		return m_itemSize - DebugSize();
	}

#ifdef _DEBUG
	bool FixedAlloc::QueryOwnsObject(const void* item)
	{
		const char* ci = (const char*) item;
		for ( FixedBlock* fb=m_firstBlock ; fb != NULL ; fb=fb->next )
			if (ci >= (const char*)fb->items && ci < (const char*)fb->items + m_itemsPerBlock*m_itemSize)
				return true;
		return false;
	}
#endif
	
#ifdef MMGC_MEMORY_INFO
	/* static */
	void FixedAlloc::VerifyFreeBlockIntegrity(const void* item, uint32_t size)
	{
		// go through every item on the free list and make sure it wasn't written to
		// after being poisoned.
		while(item) 
		{
#ifdef MMGC_64BIT
			int n = (size >> 2) - 3;
#else
			int n = (size >> 2) - 1;
#endif

			int startIndex = (int)((uint32_t*)item - (uint32_t*)GetRealPointer(item));
			for(int i=startIndex; i<n; i++)
			{
				uint32_t data = ((uint32_t*)item)[i];
				if(data != 0xedededed)
				{
					ReportDeletedMemoryWrite(item);
					break;
				}
			}
			// next free item
			item = *((const void**)item);
		}
	}
#endif //MMGC_MEMORY_INFO

	// FixedAllocSafe

	FixedAllocSafe::FixedAllocSafe(int itemSize, GCHeap* heap) 
		: FixedAlloc(itemSize, heap, true)
	{
		VMPI_lockInit(&m_spinlock);
	}
	
	FixedAllocSafe::FixedAllocSafe()
	{
		VMPI_lockInit(&m_spinlock);
	}
	
	FixedAllocSafe::~FixedAllocSafe()
	{
        // Don't call Destroy, because it calls FixedAlloc::Destroy, which is also
        // called from FixedAlloc::~FixedAlloc, which we just called. 
        VMPI_lockDestroy(&m_spinlock);
	}

    void FixedAllocSafe::Destroy()
    {
        FixedAlloc::Destroy();
        VMPI_lockDestroy(&m_spinlock);
    }

	// FastAllocator
	
	void *FastAllocator::operator new[](size_t size)
	{
		return FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size);
	}
	
	void FastAllocator::operator delete [](void *item)
	{
		FixedMalloc::GetFixedMalloc()->OutOfLineFree(item);
	}

#ifdef MMGC_HEAP_GRAPH
	/*static*/
	const void *FixedAlloc::FindBeginning(const void *addr)
	{
		FixedBlock *b = GetFixedBlock(addr);
		uint32_t itemNum = 0;
		char *mem = b->items;
		while(itemNum++ < b->alloc->m_itemsPerBlock) {
			char *next = mem + b->alloc->m_itemSize;
			if(addr >= mem && addr < next)
				return mem;
			mem = next;
		}
		return NULL;
	}
#endif
}
