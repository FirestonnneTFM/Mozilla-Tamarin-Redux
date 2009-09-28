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

#ifdef AVMPLUS_SAMPLER
namespace avmplus
{
	void recordAllocationSample(const void* item, size_t size);
	void recordDeallocationSample(const void* item, size_t size);	
}
#endif

#if defined MMGC_POLICY_PROFILING && !defined AVMSHELL_BUILD
extern void RedirectLogOutput(void (*)(const char*));
static FILE* fp = NULL;

void logToFile(const char* s)
{
	fprintf(fp, "%s", s);
	fflush(fp);
}

static void startGCLogToFile()
{
	fp = fopen("gcbehavior.txt", "w");
	if (fp != NULL)
		RedirectLogOutput(logToFile);
}

static void endGCLogToFile()
{
	RedirectLogOutput(NULL);
	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}
}
#endif // MMGC_POLICY_PROFILING && !AVMSHELL_BUILD

namespace MMgc
{
	GCHeap *GCHeap::instance = NULL;
	// GCHeap instance has the C++ runtime call dtor which causes problems
	uint8_t heapSpace[sizeof(GCHeap)];

	size_t GCHeap::leakedBytes;

#ifdef MMGC_MEMORY_PROFILER
	MemoryProfiler* GCHeap::profiler = (MemoryProfiler*)-1;
#endif

	/** The native VM page size (in bytes) for the current architecture */
	const size_t GCHeap::kNativePageSize = VMPI_getVMPageSize();


	GCHeapConfig::GCHeapConfig() : 
		initialSize(512), 
		heapLimit(kDefaultHeapLimit), 
		heapSoftLimit(0),
		OOMExitCode(0),
		useVirtualMemory(VMPI_useVirtualMemory()),
		trimVirtualMemory(true),
		mergeContiguousRegions(VMPI_canMergeContiguousRegions()),
		verbose(false),
		returnMemory(true),
		gcstats(false), // tracking
		autoGCStats(false), // auto printing
#ifdef AVMSHELL_BUILD
		gcbehavior(false),	// controlled by command line switch
#else
		gcbehavior(true),	// unconditional, if MMGC_POLICY_PROFILING is on
#endif
		gcLoad(2.0),
		gcLoadCeiling(3.0),
		gcEfficiency(0.25)
	{
#ifdef MMGC_64BIT
		trimVirtualMemory = false; // no need
#endif
		const char *envValue = VMPI_getenv("MMGC_HEAP_LIMIT");
		if(envValue)
			heapLimit = VMPI_strtol(envValue, 0, 10);
		envValue = VMPI_getenv("MMGC_HEAP_SOFT_LIMIT");
		if(envValue)
			heapSoftLimit = VMPI_strtol(envValue, 0, 10);
	}

	void GCHeap::Init(const GCHeapConfig& config)
	{
		GCAssert(instance == NULL);
		void *p = (void*)heapSpace;
		instance = new (p) GCHeap(config);
	}

	size_t GCHeap::Destroy()
	{
		GCAssert(instance != NULL);
		instance->DestroyInstance();
		instance = NULL;
		return leakedBytes;
	}

	GCHeap::GCHeap(const GCHeapConfig& c)
		: lastRegion(NULL),
		  blocks(NULL),
		  blocksLen(0),
		  numDecommitted(0),
		  numAlloc(0),
		  config(c),
 		  status(kMemNormal),
		  statusNotificationBeingSent(false),
		  enterCount(0),
		  primordialThread(VMPI_currentThread()),
	#ifdef MMGC_MEMORY_PROFILER
		  hasSpy(false),
	#endif
		  maxTotalHeapSize(0),
	#ifdef MMGC_POLICY_PROFILING
 		  maxPrivateMemory(0),
	#endif
    #ifdef MMGC_HOOKS
		  hooksEnabled(false),
    #endif
		  entryChecksEnabled(true),
		  abortStatusNotificationSent(false)
	{		
		VMPI_lockInit(&m_spinlock);
		VMPI_lockInit(&list_lock);
		VMPI_lockInit(&gclog_spinlock);

		// Initialize free lists
		HeapBlock *block = freelists;
		for (int i=0; i<kNumFreeLists; i++) {
			block->FreelistInit();
			block++;
		}
		
		// Create the initial heap
		{
			MMGC_LOCK(m_spinlock);
			ExpandHeap((int)config.initialSize);
		}

		fixedMalloc.InitInstance(this);

		instance = this;

#ifdef MMGC_MEMORY_PROFILER
		//create profiler if turned on and if it is not already created
		if(!IsProfilerInitialized())
		{
			InitProfiler();
		}

		if(profiler)
		{
			hooksEnabled = true; // set only after creating profiler
			hasSpy = VMPI_spySetup();
		}
#endif
		
#ifdef MMGC_MEMORY_INFO
		hooksEnabled = true; // always track allocs in DEBUG builds
#endif

#if defined MMGC_POLICY_PROFILING && !defined AVMSHELL_BUILD
		startGCLogToFile();
#endif
	}

	void GCHeap::DestroyInstance()
	{
#if defined MMGC_POLICY_PROFILING && !defined AVMSHELL_BUILD
		endGCLogToFile();
#endif

		gcManager.destroy();
		callbacks.Destroy();

		leakedBytes = GetFixedMalloc()->GetBytesInUse();
		fixedMalloc.DestroyInstance();

		instance = NULL;

		if(numAlloc != 0 && status != kMemAbort)
		{
			for (unsigned int i=0; i<blocksLen; i++) 
			{
				HeapBlock *block = &blocks[i];
				if(block->inUse() && block->baseAddr)
				{
#ifndef DEBUG
					if (config.verbose)
#endif
					{
						GCLog("Block 0x%x not freed\n", block->baseAddr);
					}
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
					if(block->allocTrace)
						PrintStackTrace(block->allocTrace);
#endif
				}
			}	
			GCAssert(false);
		}
		
#ifdef MMGC_MEMORY_PROFILER
		hooksEnabled = false;
		if(profiler)
			delete profiler;
		if(hasSpy)
			VMPI_spyTeardown();
		profiler = NULL;
#endif

		FreeAll();

		VMPI_lockDestroy(&gclog_spinlock);
		VMPI_lockDestroy(&m_spinlock);
		VMPI_lockDestroy(&list_lock);
		
		if(enterFrame)
			enterFrame->Destroy();
	}

	void* GCHeap::Alloc(int size, int flags)
	{
		GCAssert(size > 0);

		char *baseAddr = 0;
		bool zero = (flags & kZero) != 0;
		// nested block to keep memset/memory commit out of critical section
		{
			MMGC_LOCK(m_spinlock);

			HeapBlock *block = AllocBlock(size, zero);

			if(!block) {
				if((flags & kExpand) == 0)
					return NULL;

				ExpandHeap(size, (flags & kCanFail) != 0);
				block = AllocBlock(size, zero);
				if(!block) {
					GCAssertMsg(flags & kCanFail, "Internal error: ExpandHeap should have aborted if it can't satisfy the request");
					return NULL;
				}
			}

			GCAssert(block->size == size);
			
			numAlloc += size;
			
			// copy baseAddr to a stack variable to fix :
			// http://flashqa.macromedia.com/bugapp/detail.asp?ID=125938
			baseAddr = block->baseAddr;
			
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
			if(profiler)
				block->allocTrace = profiler->GetStackTrace();
#endif
			
#ifdef MMGC_MEMORY_PROFILER
			if((flags & kProfile) && HooksEnabled() && profiler) {
				profiler->RecordAllocation(baseAddr, size * kBlockSize, size * kBlockSize);
			}
#endif
		}

		// Zero out the memory, if requested to do so
		if (zero) {
			VMPI_memset(baseAddr, 0, size * kBlockSize);
		}
		
		return baseAddr;
	}

	void GCHeap::FreeInternal(const void *item, bool profile)
	{
		(void)profile;
		MMGC_LOCK(m_spinlock);

		HeapBlock *block = AddrToBlock(item);
		GCAssertMsg(block != NULL, "Bogus item");

		// Update metrics
		GCAssert(numAlloc >= (unsigned int)block->size);
		numAlloc -= block->size;
		
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
		if(profiler)
			block->freeTrace = profiler->GetStackTrace();
#endif
	
#ifdef MMGC_MEMORY_PROFILER
		if(profile && HooksEnabled() && profiler) {
			profiler->RecordDeallocation(item, block->size * kBlockSize);
		}
#endif

		FreeBlock(block);
	}

	
	size_t GCHeap::Size(const void *item)
	{
		MMGC_LOCK(m_spinlock);
		HeapBlock *block = AddrToBlock(item);
		return block->size;
	}

	void GCHeap::Decommit()
	{
		// keep at least initialSize free 
		if(!config.returnMemory)
			return;
		
		size_t heapSize = GetTotalHeapSize();
		size_t freeSize = GetFreeHeapSize();
		
		size_t decommitSize;
		// commit if > kDecommitThresholdPercentage is free
		if(freeSize * 100 > heapSize * kDecommitThresholdPercentage)
			decommitSize = int((freeSize * 100 - heapSize * kDecommitThresholdPercentage) / 100);
		else
			return;
				
		//  Don't decommit more than our initial config size.
		if (heapSize - decommitSize < config.initialSize)
		{
			decommitSize = heapSize - config.initialSize;
		}

		// don't trifle
		if(decommitSize < (size_t)kMinHeapIncrement)
			return;

		MMGC_LOCK(m_spinlock);

	restart:

		// search from the end of the free list so we decommit big blocks
		HeapBlock *freelist = freelists+kNumFreeLists-1;

		HeapBlock *endOfBigFreelists = &freelists[GetFreeListIndex(1)];

		for (; freelist >= endOfBigFreelists && decommitSize > 0; freelist--)
		{
			HeapBlock *block = freelist;
			while ((block = block->prev) != freelist && decommitSize > 0)
			{
				// decommitting already decommitted blocks doesn't help
				// temporary replacement for commented out conditional below
				GCAssert(block->size != 0);
				if(!block->committed /*|| block->size == 0*/)
					continue;

				if(config.useVirtualMemory)
				{
					RemoveFromList(block);
					if((size_t)block->size > decommitSize)
					{
						HeapBlock *newBlock = Split(block, (int)decommitSize);
						AddToFreeList(newBlock);
					}
					
					Region *region = AddrToRegion(block->baseAddr);
					if(config.trimVirtualMemory &&
					   freeSize * 100 > heapSize * kReleaseThresholdPercentage &&
					   // if block is as big or bigger than a region, free the whole region
					   block->baseAddr <= region->baseAddr && 
					   region->reserveTop <= block->endAddr() )
	   				{

						if(block->baseAddr < region->baseAddr)
						{
							HeapBlock *newBlock = Split(block, int((region->baseAddr - block->baseAddr) / kBlockSize));
							AddToFreeList(block);
							block = newBlock;
						}
						if(block->endAddr() > region->reserveTop)
						{
							HeapBlock *newBlock = Split(block, int((region->reserveTop - block->baseAddr) / kBlockSize));
							AddToFreeList(newBlock);
						}

						decommitSize -= block->size;
						RemoveBlock(block);
						goto restart;
					}
					else if(VMPI_decommitMemory(block->baseAddr, block->size * kBlockSize))
					{
						block->committed = false;
						block->dirty = false;
						decommitSize -= block->size;
						if(config.verbose) {
							GCLog("decommitted %d page block from %p\n", block->size, block->baseAddr);
						}
					}
					else
					{
#ifdef _MAC
						// this can happen on mac where we release and re-reserve the memory and another thread may steal it from us
						RemoveBlock(block);
						goto restart;
#else
						// if the VM API's fail us bail
						VMPI_abort(); 
#endif
					}
					
					numDecommitted += block->size;
					
					// merge with previous/next if not in use and not committed
					HeapBlock *prev = block - block->sizePrevious;
					if(block->sizePrevious != 0 && !prev->committed && !prev->inUse()) {
						RemoveFromList(prev);
						
						prev->size += block->size;
						
						block->size = 0;
						block->sizePrevious = 0;
						block->baseAddr = 0;
						
						block = prev;
					}
					
					HeapBlock *next = block + block->size;
					if(next->size != 0 && !next->committed && !next->inUse()) {
						RemoveFromList(next);
						
						block->size += next->size;
						
						next->size = 0;
						next->sizePrevious = 0;
						next->baseAddr = 0;
					}
					
					next = block + block->size;
					next->sizePrevious = block->size;
					
					// add this block to the back of the bus to make sure we consume committed memory
					// first
					HeapBlock *backOfTheBus = &freelists[kNumFreeLists-1];
					HeapBlock *pointToInsert = backOfTheBus;
					while ((pointToInsert = pointToInsert->next) !=  backOfTheBus) {
						if (pointToInsert->size >= block->size && !pointToInsert->committed) {
							break;
						}
					}
					AddToFreeList(block, pointToInsert);
					
					// so we keep going through freelist properly
					block = freelist;

				} else { // not using virtual memory

					// if we aren't using mmap we can only do something if the block maps to a region
					// that is completely empty
					Region *region = AddrToRegion(block->baseAddr);
					if(block->baseAddr == region->baseAddr && // beginnings match
					   region->commitTop == block->baseAddr + block->size*kBlockSize) {
						
						RemoveFromList(block);
						
						RemoveBlock(block);
						
						goto restart;
					}
				}
			}
		}

		if(config.verbose)
			DumpHeapRep();
		CheckForStatusReturnToNormal();
	}

	void GCHeap::CheckForStatusReturnToNormal()
	{
		if(!statusNotificationBeingSent && statusNotNormalOrAbort())
		{
			size_t total = GetTotalHeapSize();
			// return to normal if we drop below heapSoftLimit
			if(config.heapSoftLimit != 0 )
			{
				if (total < config.heapSoftLimit)
				{
					GCDebugMsg(false, "### Alloc dropped below softlimit: usedheapsize =%d, totalHeap =%d\n",  GetUsedHeapSize(), total );
					StatusChangeNotify(kMemNormal);
				}
			}
			// or if we shrink to below %10 of the max
			else if(maxTotalHeapSize / kBlockSize * 9 > total * 10)
				StatusChangeNotify(kMemNormal);
		}
	}

	void GCHeap::RemoveBlock(HeapBlock *block)
	{	
		Region *region = AddrToRegion(block->baseAddr);
		
		GCAssert(region->baseAddr == block->baseAddr);
		GCAssert(region->reserveTop == block->endAddr());
		

		int newBlocksLen = blocksLen - block->size;

		HeapBlock *nextBlock = block + block->size;

		bool need_sentinel = false;
		bool remove_sentinel = false;

		if( block->sizePrevious && nextBlock->size ) {
			// This block is contiguous with the blocks before and after it
			// so we need to add a sentinel
			need_sentinel = true;
		}
		else if ( !block->sizePrevious && !nextBlock->size ) {
			// the block is not contigous with the block before or after it - we need to remove a sentinel
			// since there would already be one on each side.
			remove_sentinel = true;
		}

		// update nextblock's sizePrevious
		nextBlock->sizePrevious = need_sentinel ? 0 : block->sizePrevious;
		
		// Add space for the sentinel - the remaining blocks won't be contiguous
		if(need_sentinel)
			++newBlocksLen;
		else if(remove_sentinel)
			--newBlocksLen;

		// we're removing a region so re-allocate the blocks w/o the blocks for this region
		HeapBlock *newBlocks = new HeapBlock[newBlocksLen];
		
		// copy blocks before this block
		GCAssert(block - blocks <= newBlocksLen);
		memcpy(newBlocks, blocks, (block - blocks) * sizeof(HeapBlock));
		
		int offset = int(block-blocks);
		int sen_offset = 0;
		HeapBlock *src = block + block->size;

		if( need_sentinel ) {
			offset = int(block-blocks)+1;
			sen_offset = 1;
			HeapBlock* sentinel = newBlocks + (block-blocks);
			sentinel->baseAddr = NULL;
			sentinel->size = 0;
			sentinel->sizePrevious = block->sizePrevious;
			sentinel->prev = NULL;
			sentinel->next = NULL;
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
			sentinel->allocTrace = 0;
#endif
		}
		else if( remove_sentinel ) {
			// skip trailing sentinel
			src++;
			sen_offset = -1;
		}
		
		// copy blocks after
		int lastChunkSize = int((blocks + blocksLen) - src);
		GCAssert(lastChunkSize + offset == newBlocksLen);
		memcpy(newBlocks + offset, src, lastChunkSize * sizeof(HeapBlock));

		// Fix up the prev/next pointers of each freelist.  This is a little more complicated
		// than the similiar code in ExpandHeap because blocks after the one we are free'ing
		// are sliding down by block->size
		HeapBlock *fl = freelists;
		for (int i=0; i<kNumFreeLists; i++) {
			HeapBlock *temp = fl;
			do {
				if (temp->prev != fl) {
					if(temp->prev > block) {
						temp->prev = newBlocks + (temp->prev-blocks-block->size) + sen_offset;
					} else {
						temp->prev = newBlocks + (temp->prev-blocks);
					}
				}
				if (temp->next != fl) {
					if(temp->next > block) {
						temp->next = newBlocks + (temp->next-blocks-block->size) + sen_offset;
					} else {
						temp->next = newBlocks + (temp->next-blocks);
					}
				}
			} while ((temp = temp->next) != fl);
			fl++;
		}
		
		// Need to decrement blockId for regions in blocks after block
		Region *r = lastRegion;
		while(r) {
			if(r->blockId > region->blockId) {
				r->blockId -= (block->size-sen_offset);
			}
			r = r->prev;
		}

		delete [] blocks;
		blocks = newBlocks;
		blocksLen = newBlocksLen;
		RemoveRegion(region);

		// make sure we did everything correctly
		CheckFreelist();
		ValidateHeapBlocks();
	}

	void GCHeap::ValidateHeapBlocks()
	{
#ifdef _DEBUG
		// iterate through HeapBlocks making sure:
		// non-contiguous regions have a sentinel
		HeapBlock *block = blocks;
		while(block - blocks < (intptr_t)blocksLen) {
			Region *r = AddrToRegion(block->baseAddr);
			if(r && r->baseAddr == block->baseAddr)
				GCAssert(r->blockId == block-blocks);

			HeapBlock *next = NULL;
			if(block->size) {
				next = block + block->size;
				GCAssert(next->sizePrevious == block->size);
			}
			HeapBlock *prev = NULL;
			if(block->sizePrevious) {
				prev = block - block->sizePrevious;
				GCAssert(prev->size == block->sizePrevious);
			} else if(block != blocks) {
				// I have no prev and I'm not the first, check sentinel
				HeapBlock *sentinel = block-1;
				GCAssert(sentinel->baseAddr == NULL);
				GCAssert(sentinel->size == 0);
				GCAssert(sentinel->sizePrevious != 0);
			}
			if(block->baseAddr) {
				if(prev)
					GCAssert(block->baseAddr == prev->baseAddr + (kBlockSize * prev->size));
				block = next;
				// we should always end on a sentinel
				GCAssert(next - blocks < (int)blocksLen);
			} else {
				// block is a sentinel
				GCAssert(block->size == 0);
				// FIXME: the following asserts are firing and we need to understand why, could be bugs
				// make sure last block ends at commitTop
				Region *prevRegion = AddrToRegion(prev->baseAddr + (prev->size*kBlockSize) - 1);
				GCAssert(prev->baseAddr + (prev->size*kBlockSize) == prevRegion->commitTop);
				block++;
				// either we've reached the end or the next isn't a sentinel
				GCAssert(block - blocks == (intptr_t)blocksLen || block->size != 0);
			}
		}
		GCAssert(block - blocks == (intptr_t)blocksLen);
#endif
	}

	GCHeap::Region *GCHeap::AddrToRegion(const void *item) const
	{
		// Linear search of regions list to find this address.
		// The regions list should usually be pretty short.
		for (Region *region = lastRegion;
			 region != NULL;
			 region = region->prev)
		{
			if (item >= region->baseAddr && item < region->reserveTop) {
				return region;
			}
		}
		return NULL;
	}

	GCHeap::HeapBlock* GCHeap::AddrToBlock(const void *item) const
	{
		Region *region = AddrToRegion(item);
		if(region) {
			size_t index = ((char*)item - region->baseAddr) / kBlockSize;
			HeapBlock *b = blocks + region->blockId + index;
			GCAssert(item >= b->baseAddr && item < b->baseAddr + b->size * GCHeap::kBlockSize);
			return b;
		}
		return NULL;
	}
	
	GCHeap::HeapBlock* GCHeap::AllocBlock(int size, bool& zero)
	{
		int startList = GetFreeListIndex(size);
		HeapBlock *freelist = &freelists[startList];

		HeapBlock *decommittedSuitableBlock = NULL;
		HeapBlock *blockToUse = NULL;

		for (int i = startList; i < kNumFreeLists; i++)
		{
			// Search for a big enough block in free list
			HeapBlock *block = freelist;
			while ((block = block->next) != freelist)
			{
				if (block->size >= size && block->committed) 
				{
					blockToUse = block;
					goto foundone;
				}

				if(config.useVirtualMemory)
				{
					// if the block isn't committed see if this request can be met with by committing
					// it and combining it with its neighbors
					if(!block->committed && !decommittedSuitableBlock)
					{
						int totalSize = block->size;
						
						// first try predecessors
						HeapBlock *firstFree = block;
						
						// loop because we could have interleaved committed/non-committed blocks
						while(totalSize < size && firstFree->sizePrevious != 0)
						{	
							HeapBlock *prevBlock = firstFree - firstFree->sizePrevious;
							if(!prevBlock->inUse() && prevBlock->size > 0) {
								totalSize += prevBlock->size;
								firstFree = prevBlock;
							} else {
								break;
							}
						}
						
						if(totalSize > size) {
							decommittedSuitableBlock = firstFree;
						} else {
							// now try successors
							HeapBlock *nextBlock = block + block->size;
							while(nextBlock->size > 0 && !nextBlock->inUse() && totalSize < size) {
								totalSize += nextBlock->size;
								nextBlock = nextBlock + nextBlock->size;
							}
							
							if(totalSize > size) {
								decommittedSuitableBlock = firstFree;
							}
						}
					}
				}
			}
			freelist++;
		}	
		
	foundone:

		if(blockToUse)
		{				
			RemoveFromList(blockToUse);

			if(blockToUse->size > size)
			{
				HeapBlock *newBlock = Split(blockToUse, size);
							
				// Add the newly created block to the free list
				AddToFreeList(newBlock);
			}
							
			CheckFreelist();
			
			zero = blockToUse->dirty && zero;
			
			#ifdef _DEBUG
			if (!blockToUse->dirty)
			{
				union {
					const char* base_c;
					const uint32_t* base_u;
				};
				base_c = blockToUse->baseAddr;
				GCAssert(*base_u == 0);
			}
			#endif
			return blockToUse;
		}

		if(config.useVirtualMemory && decommittedSuitableBlock)
		{
			// first handle case where its too big
			if(decommittedSuitableBlock->size > size)
			{				
				int toCommit = size > kMinHeapIncrement ? size : kMinHeapIncrement;

				if(toCommit > decommittedSuitableBlock->size)
					toCommit = decommittedSuitableBlock->size;

				RemoveFromList(decommittedSuitableBlock);
				
				// first split off part we're gonna commit
				if(decommittedSuitableBlock->size > toCommit) {
					HeapBlock *newBlock = Split(decommittedSuitableBlock, toCommit);

					// put the still uncommitted part back on freelist
					AddToFreeList(newBlock);
				}
				
				Commit(decommittedSuitableBlock);

				if(toCommit > size) {
					HeapBlock *newBlock = Split(decommittedSuitableBlock, size);
					AddToFreeList(newBlock);
				}
			}
			else // too small
			{
				// need to stitch blocks together committing uncommitted blocks
				HeapBlock *block = decommittedSuitableBlock;
				RemoveFromList(block);

				int amountRecommitted = block->committed ? 0 : block->size;
					
				while(block->size < size)
				{
					HeapBlock *nextBlock = block + block->size;

					RemoveFromList(nextBlock);
						
					// Increase size of current block
					block->size += nextBlock->size;
					amountRecommitted += nextBlock->committed ? 0 : nextBlock->size;

					nextBlock->size = 0;
					nextBlock->baseAddr = 0;
					nextBlock->sizePrevious = 0;

					block->dirty |= nextBlock->dirty;
				}

				GCAssert(amountRecommitted > 0);

				if(!VMPI_commitMemory(block->baseAddr, block->size * kBlockSize)) 
				{
					GCAssert(false);
				}
				if(config.verbose)
					GCLog("recommitted %d pages\n", amountRecommitted);
				numDecommitted -= amountRecommitted;
				block->committed = true;

				GCAssert(decommittedSuitableBlock->size >= size);

				// split last block
				if(block->size > size)
				{
					HeapBlock *newBlock = Split(block, size);
					AddToFreeList(newBlock);
				}
			}

			GCAssert(decommittedSuitableBlock->size == size);

			// update sizePrevious in next block
			HeapBlock *nextBlock = decommittedSuitableBlock + size;
			nextBlock->sizePrevious = size;

			CheckFreelist();

			return decommittedSuitableBlock;
		}
	
		CheckFreelist();
		return 0;
	}

	GCHeap::HeapBlock *GCHeap::Split(HeapBlock *block, int size)
	{
		GCAssert(block->size > size);
		HeapBlock *newBlock = block + size;
		newBlock->baseAddr = block->baseAddr + kBlockSize * size;

		newBlock->size = block->size - size;
		newBlock->sizePrevious = size;
		newBlock->committed = block->committed;
		newBlock->dirty = block->dirty;
		block->size = size;

		// Update sizePrevious in block after that
		HeapBlock *nextBlock = newBlock + newBlock->size;
		nextBlock->sizePrevious = newBlock->size;
	
		return newBlock;
	}

	void GCHeap::Commit(HeapBlock *block)
	{
		if(!block->committed)
		{
			if(!VMPI_commitMemory(block->baseAddr, block->size * kBlockSize)) 
			{
				GCAssert(false);
			}
			if(config.verbose) {
				GCLog("recommitted %d pages\n", block->size);
				DumpHeapRep();
			}
			numDecommitted -= block->size;
			block->committed = true;
			block->dirty = false;
		}
	}

	void GCHeap::CheckFreelist()
	{
#ifdef _DEBUG
		HeapBlock *freelist = freelists;
		for (int i = 0; i < kNumFreeLists; i++)
		{
			HeapBlock *block = freelist;
			while((block = block->next) != freelist)
			{
				GCAssert(block != block->next);
				GCAssert(block != block->next->next || block->next == freelist);
				if(block->sizePrevious)
				{
					HeapBlock *prev = block - block->sizePrevious;
					GCAssert(block->sizePrevious == prev->size);
				}
			}
			freelist++;
		}
#endif
#if 0
// Debugging code to find problems with block/region layout
// This code is slow, but can be useful for tracking down issues
// It verifies that the memory for each block corresponds to one or more regions
// and that each region points to a valid starting block
  		Region* r = lastRegion;

		int block_idx = 0;
		bool errors =false;
		for(block_idx = 0; block_idx < blocksLen; ++block_idx){
			HeapBlock* b = blocks + block_idx;
			
			if( !b->size )
				continue;

			int contig_size = 0;
			r = lastRegion;

			while( r ){
				if(b->baseAddr >= r->baseAddr && b->baseAddr < r->reserveTop ) {
					// starts in this region
					char* end = b->baseAddr + b->size*kBlockSize;
					if(end > (r->reserveTop + contig_size) ){
						GCLog("error, block %d %p %d did not find a matching region\n", block_idx, b->baseAddr, b->size);
						GCLog("Started in region %p - %p, contig size: %d\n", r->baseAddr, r->reserveTop, contig_size);
						errors = true;
						break;
					}
				}
				else if( r->prev && r->prev->reserveTop==r->baseAddr){
					contig_size +=r->reserveTop - r->baseAddr;
				}
				else{
					contig_size = 0;
				}
						
				r = r->prev;
			}
		}

		while(r)
			{
				if(!blocks[r->blockId].size){
                    for( int i = r->blockId-1; i >= 0 ; --i )
                        if( blocks[i].size){
							//Look for spanning blocks
                            if( ((blocks[i].baseAddr + blocks[i].size*kBlockSize) <= r->baseAddr) ) {
                                GCLog("Invalid block id for region %p-%p %d\n", r->baseAddr, r->reserveTop, i);
								errors =true;
								break;
							}
                            else
                                break;
                        }
				}
				r = r->prev;
		   }
		if( errors ){
			r = lastRegion;
			while(r) {
				GCLog("%p - %p\n", r->baseAddr, r->reserveTop);
				r = r->prev;
			}
			for(int b = 0; b < blocksLen; ++b ){
				if(!blocks[b].size)
					continue;
				GCLog("%d %p %d\n", b, blocks[b].baseAddr, blocks[b].size); 
			}
			asm("int3");
		}
#endif	
	}

	bool GCHeap::BlocksAreContiguous(void *item1, void *item2)
	{
		Region *r1 = AddrToRegion(item1);
		Region *r2 = AddrToRegion(item2);
		return r1 == r2 || r1->reserveTop == r2->baseAddr;
	}

	void GCHeap::AddToFreeList(HeapBlock *block)
	{
		int index = GetFreeListIndex(block->size);
		HeapBlock *freelist = &freelists[index];

		HeapBlock *pointToInsert = freelist;
		
		// Note: We don't need to bother searching for the right
		// insertion point if we know all blocks on this free list
		// are the same size.
		if (block->size >= kUniqueThreshold) {
			while ((pointToInsert = pointToInsert->next) != freelist) {
				if (pointToInsert->size >= block->size) {
					break;
				}
			}
		}

		AddToFreeList(block, pointToInsert);
	}
		
	void GCHeap::AddToFreeList(HeapBlock *block, HeapBlock* pointToInsert)
	{
		CheckFreelist();

		block->next = pointToInsert;
		block->prev = pointToInsert->prev;
		block->prev->next = block;
		pointToInsert->prev = block;

		CheckFreelist();
	}						   

	void GCHeap::FreeBlock(HeapBlock *block)
	{
		GCAssert(block->inUse());
	
		// big block's that map to a region are free'd right away
		Region *r = AddrToRegion(block->baseAddr);
		if(block->baseAddr == r->baseAddr && block->endAddr() == r->reserveTop)
		{
			RemoveBlock(block);
			return;
		}
		
#ifdef _DEBUG
		// trash it. fb == free block
		VMPI_memset(block->baseAddr, 0xfb, block->size * kBlockSize);
#endif
		
		// Try to coalesce this block with its predecessor
		if(block->sizePrevious)
		{
			HeapBlock *prevBlock = block - block->sizePrevious;
			if (!prevBlock->inUse() && prevBlock->committed) 
			{
				// Remove predecessor block from free list
				RemoveFromList(prevBlock);
				
				// Increase size of predecessor block
				prevBlock->size += block->size;
				
				block->size = 0;
				block->sizePrevious = 0;
				block->baseAddr = 0;				
				
				block = prevBlock;
			}
		}

		// Try to coalesce this block with its successor
		HeapBlock *nextBlock = block + block->size;

		GCAssert(block->size != 0);

		if (!nextBlock->inUse() && nextBlock->committed) {
			// Remove successor block from free list
			RemoveFromList(nextBlock);

			// Increase size of current block
			block->size += nextBlock->size;
			nextBlock->size = 0;
			nextBlock->baseAddr = 0;
			nextBlock->sizePrevious = 0;
		}

		// Update sizePrevious in the next block
		nextBlock = block + block->size;
		nextBlock->sizePrevious = block->size;

		// Add this block to the right free list
		block->dirty = true;

		AddToFreeList(block);

		CheckFreelist();
	}

	void GCHeap::ExpandHeap(int askSize, bool canFail)
	{
		bool result = ExpandHeapInternal(askSize);
		if(!result)
		{ 
			// random policy choice: don't invoke OOM callbacks for
			// canFail allocs
			if(status != kMemReserve && !canFail) {

				if(statusNotificationBeingSent)
					Abort();
				

				// invoke callbacks
				StatusChangeNotify(kMemReserve);

				
				// try again
				result = ExpandHeapInternal(askSize);
			}

			if(!result) {
				if(canFail)
					return;
				else 
					Abort();
			}
		}


		size_t total = GetTotalHeapSize() ;
		if(config.heapSoftLimit && total > config.heapSoftLimit && status == kMemNormal)
		{
			GCDebugMsg(false, "*** Alloc exceed softlimit: ask for %d, usedheapsize =%d, totalHeap =%d\n", askSize, GetUsedHeapSize(), total );
			StatusChangeNotify(kMemSoftLimit);
		}

		// The guard on instance being non-NULL is a hack, to be fixed later (now=2009-07-20).
		// Some VMPI layers (WinMo is at least one of them) try to grab the GCHeap instance to get
		// at the map of private pages.  But the GCHeap instance is not available during the initial
		// call to ExpandHeap.  So sidestep that problem here.

		if (instance != NULL) {
			// GetTotalHeapSize is probably fairly cheap; even so this strikes me
			// as a bit of a hack.
			size_t heapSizeNow = GetTotalHeapSize() * kBlockSize;
			if (heapSizeNow > maxTotalHeapSize) {
				maxTotalHeapSize = heapSizeNow;
#ifdef MMGC_POLICY_PROFILING
				maxPrivateMemory = VMPI_getPrivateResidentPageCount() * VMPI_getVMPageSize();
#endif
			}
		}
	}
	 
	bool GCHeap::ExpandHeapInternal(int askSize)
	{
		int size = askSize;

#ifdef _DEBUG
		// Turn this switch on to test bridging of contiguous
		// regions.
		bool test_bridging = false;
		int defaultReserve = test_bridging ? (size+kMinHeapIncrement) : kDefaultReserve;
#else
		const int defaultReserve = kDefaultReserve;
#endif
		
		if(GetTotalHeapSize() > config.heapLimit)
			return false;
		
		char *baseAddr = NULL;
		char *newRegionAddr = NULL;
		int newRegionSize = 0;
		bool contiguous = false;
		int commitAvail = 0;
		
		// Allocate at least kMinHeapIncrement blocks
		if (size < kMinHeapIncrement) {
			size = kMinHeapIncrement;
		}

		// Round to the nearest kMinHeapIncrement
		size = ((size + kMinHeapIncrement - 1) / kMinHeapIncrement) * kMinHeapIncrement;

		if(config.useVirtualMemory)
		{
			Region *region = lastRegion;
			if (region != NULL)
			{
				commitAvail = (int)((region->reserveTop - region->commitTop) / kBlockSize);
				
				// Can this request be satisfied purely by committing more memory that
				// is already reserved?
				if (size <= commitAvail) {
					if (VMPI_commitMemory(region->commitTop, size * kBlockSize))
					{
						// Succeeded!
						baseAddr = region->commitTop;
						contiguous = true;
						
						// Update the commit top.
						region->commitTop += size*kBlockSize;
						
						// Go set up the block list.
						goto gotMemory;
					}
					else
					{
						// If we can't commit memory we've already reserved,
						// no other trick is going to work.  Fail.
						return false;
					}
				}
				
				// Try to reserve a region contiguous to the last region.
				
				// - Try for the "default reservation size" if it's larger than
				//   the requested block.
				if (defaultReserve > size) {
					newRegionAddr = (char*) VMPI_reserveMemoryRegion(region->reserveTop,
												  defaultReserve * kBlockSize);
					newRegionSize = defaultReserve;
				}
				
				// - If the default reservation size didn't work or isn't big
				//   enough, go for the exact amount requested, minus the
				//   committable space in the current region.
				if (newRegionAddr == NULL) {
					newRegionAddr = (char*) VMPI_reserveMemoryRegion(region->reserveTop,
												  (size - commitAvail)*kBlockSize);
					newRegionSize = size - commitAvail;
				}
				
				if (newRegionAddr != NULL) {
					// We were able to reserve some space.
					
					// Commit available space from the existing region.
					if (commitAvail != 0) {
						if (!VMPI_commitMemory(region->commitTop, commitAvail * kBlockSize))
						{
							// We couldn't commit even this space.  We're doomed.
							// Un-reserve the space we just reserved and fail.
							ReleaseMemory(newRegionAddr, newRegionSize);
							return false;
						}
					}
					
					// Commit needed space from the new region.
					if (!VMPI_commitMemory(newRegionAddr, (size - commitAvail) * kBlockSize))
					{
						// We couldn't commit this space.  We can't meet the
						// request.  Un-commit any memory we just committed,
						// un-reserve any memory we just reserved, and fail.
						if (commitAvail != 0) {
							VMPI_decommitMemory(region->commitTop,
										   commitAvail * kBlockSize);
						}
						ReleaseMemory(newRegionAddr,
									  (size-commitAvail)*kBlockSize);
						return false;
					}
					
					// We successfully reserved a new contiguous region
					// and committed the memory we need.  Finish up.
					baseAddr = region->commitTop;
					region->commitTop = lastRegion->reserveTop;
					contiguous = true;
					
					goto gotMemory;
				}
			}

			// We were unable to allocate a contiguous region, or there
			// was no existing region to be contiguous to because this
			// is the first-ever expansion.  Allocate a non-contiguous region.
			
			// don't waste this uncommitted space, go ahead and commit it
			if(commitAvail) {
				ExpandHeapInternal(commitAvail);
			}
			
			// Don't use any of the available space in the current region.
			commitAvail = 0;
			
			// - Go for the default reservation size unless the requested
			//   size is bigger.
			if (size < defaultReserve) {
				newRegionAddr = (char*) VMPI_reserveMemoryRegion(NULL,
												  defaultReserve*kBlockSize);
				newRegionSize = defaultReserve;
			}
			
			// - If that failed or the requested size is bigger than default,
			//   go for the requested size exactly.
			if (newRegionAddr == NULL) {
				newRegionAddr = (char*) VMPI_reserveMemoryRegion(NULL,
											  size*kBlockSize);
				newRegionSize = size;
			}
			
			// - If that didn't work, give up.
			if (newRegionAddr == NULL) {
				return false;
			}
			
			// - Try to commit the memory.
			if (VMPI_commitMemory(newRegionAddr,
							 size*kBlockSize) == 0)
			{
				// Failed.  Un-reserve the memory and fail.
				ReleaseMemory(newRegionAddr, newRegionSize*kBlockSize);
				return false;
			}
			
			// If we got here, we've successfully allocated a
			// non-contiguous region.
			baseAddr = newRegionAddr;
			contiguous = false;

		}
		else
		{		
			// Allocate the requested amount of space as a new region.
			newRegionAddr = (char*)VMPI_allocateAlignedMemory(size * kBlockSize);
			baseAddr = newRegionAddr;
			newRegionSize = size;
			
			// If that didn't work, give up.
			if (newRegionAddr == NULL) {
				return false;
			}
		}

	gotMemory:

		// If we were able to allocate a contiguous block, remove
		// the old top sentinel.
		if (contiguous) {
			blocksLen--;
		}

		// Expand the block list.
		int newBlocksLen = blocksLen + size;

		// Add space for the "top" sentinel
		newBlocksLen++;

		HeapBlock *newBlocks = new HeapBlock[newBlocksLen];
		if (!newBlocks) {
			// Could not get the memory.
			if( newRegionAddr )
				ReleaseMemory(newRegionAddr, newRegionSize);
			return false;
		}
		
		// Copy all the existing blocks.
		if (blocksLen) {
			VMPI_memcpy(newBlocks, blocks, blocksLen * sizeof(HeapBlock));

			// Fix up the prev/next pointers of each freelist.
			HeapBlock *freelist = freelists;
			for (int i=0; i<kNumFreeLists; i++) {
				HeapBlock *temp = freelist;
				do {
					if (temp->prev != freelist) {
						temp->prev = newBlocks + (temp->prev-blocks);
					}
					if (temp->next != freelist) {
						temp->next = newBlocks + (temp->next-blocks);
					}
				} while ((temp = temp->next) != freelist);
				freelist++;
			}
			CheckFreelist();
		}

		// Create a single free block for the new space,
		// and add it to the free list.
		HeapBlock *block = newBlocks+blocksLen;
		block->baseAddr = baseAddr;

		block->size = size;
		block->sizePrevious = 0;
		// link up contiguous blocks
		if(blocksLen && contiguous)
		{
			// search backwards for first real block
			HeapBlock *b = &blocks[blocksLen-1];
			while(b->size == 0) 
			{
				b--;
				GCAssert(b >= blocks);
			}
			block->sizePrevious = b->size;
			GCAssert((block - block->sizePrevious)->size == b->size);
		}
		block->prev = NULL;
		block->next = NULL;
		block->committed = true;
		block->dirty = config.useVirtualMemory ? VMPI_areNewPagesDirty() : true;

#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
		block->allocTrace = 0;
		block->freeTrace = 0;
#endif

		AddToFreeList(block);

		// Initialize the rest of the new blocks to empty.
		for (int i=1; i<size; i++) {
			block++;
			block->baseAddr = NULL;
			block->size = 0;
			block->sizePrevious = 0;
			block->prev = NULL;
			block->next = NULL;
			block->committed = false;
			block->dirty = false;
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
			block->allocTrace = 0;
			block->freeTrace = 0;
#endif
		}

		// Fill in the sentinel for the top of the heap.
		block++;
		block->baseAddr     = NULL;
		block->size         = 0;
		block->sizePrevious = size;
		block->prev         = NULL;
		block->next         = NULL;
		block->committed    = false;
		block->dirty        = false;
#if defined(MMGC_MEMORY_PROFILER) && defined(MMGC_MEMORY_INFO)
		block->allocTrace = 0;
		block->freeTrace = 0;
#endif

		// Replace the blocks list
		if (blocks) {
			delete [] blocks;
		}
		blocks = newBlocks;
		blocksLen = newBlocksLen;

		// If we created a new region, save the base address so we can free later.		
		if (newRegionAddr) {
			if(contiguous && config.mergeContiguousRegions) {
				lastRegion->reserveTop += newRegionSize*kBlockSize;
				lastRegion->commitTop += (size-commitAvail)*kBlockSize;
			} else {
				Region *newRegion = new Region;
				if (newRegion == NULL) {
					// Ugh, FUBAR.
					return false;
				}
				newRegion->baseAddr   = newRegionAddr;
				newRegion->reserveTop = newRegionAddr+newRegionSize*kBlockSize;
				newRegion->commitTop  = newRegionAddr+(size-commitAvail)*kBlockSize;
				newRegion->blockId    = newBlocksLen-(size-commitAvail)-1;
				newRegion->prev = lastRegion;
				lastRegion = newRegion;
				
				if(config.verbose)
					GCLog("reserved new region, %p - %p %s\n",
						   newRegion->baseAddr,
						   newRegion->reserveTop,
						   contiguous ? "contiguous" : "non-contiguous");
			}
		}

		CheckFreelist();
		
		if(config.verbose) {
			GCLog("heap expanded by %d pages\n", size);
			DumpHeapRep();
		}
		ValidateHeapBlocks();
			
		// Success!
		return true;
	}

	void GCHeap::RemoveRegion(Region *region)
	{
		Region **next = &lastRegion;
		while(*next != region) 
			next = &((*next)->prev);
		*next = region->prev;
		ReleaseMemory(region->baseAddr,
					  region->reserveTop-region->baseAddr);		
		if(config.verbose) {
			GCLog("unreserved region 0x%p - 0x%p (commitTop: %p)\n", region->baseAddr, region->reserveTop, region->commitTop);
			DumpHeapRep();
		}
		delete region;
	}

	void GCHeap::FreeAll()
	{
		// Release all of the heap regions
		while (lastRegion != NULL) {
			Region *region = lastRegion;
			lastRegion = lastRegion->prev;
			ReleaseMemory(region->baseAddr,
						  region->reserveTop-region->baseAddr);
			delete region;
		}
		delete [] blocks;
	}
	
#ifdef MMGC_HOOKS
	void GCHeap::AllocHook(const void *item, size_t askSize, size_t gotSize)
	{
		(void)item;
		(void)askSize;
		(void)gotSize;
		{
			MMGC_LOCK(m_spinlock);
#ifdef MMGC_MEMORY_PROFILER
			if(hasSpy) {
				VMPI_spyCallback();
			}
			if(profiler)
				profiler->RecordAllocation(item, askSize, gotSize);
#endif

#ifdef MMGC_MEMORY_INFO
			DebugDecorate(item, gotSize);
#endif
		}
#ifdef AVMPLUS_SAMPLER
		// this can't be called with the heap lock locked.
		avmplus::recordAllocationSample(item, gotSize);
#endif
	}

	void GCHeap::FinalizeHook(const void *item, size_t size)
	{
		(void)item,(void)size;
		{
			MMGC_LOCK(m_spinlock);
#ifdef MMGC_MEMORY_PROFILER
			if(profiler)
				profiler->RecordDeallocation(item, size);
#endif
		}
		
#ifdef AVMPLUS_SAMPLER
		avmplus::recordDeallocationSample(item, size);
#endif
	}

	void GCHeap::FreeHook(const void *item, size_t size, int poison)
	{
		(void)poison,(void)item,(void)size;
#ifdef MMGC_MEMORY_INFO
		DebugFree(item, poison, size);
#endif
	}
#endif // MMGC_HOOKS

	EnterFrame::EnterFrame() : m_heap(NULL), m_gc(NULL)
	{
		GCHeap *heap = GCHeap::GetGCHeap();
		if(heap->GetStackEntryAddress() == NULL) {
			m_heap = heap;
			heap->Enter(this);
		}
	}
	
	// this is the first thing we run after the Abort longjmp
	EnterFrame::~EnterFrame()
	{
		if(m_heap) {
			GCHeap *heap = m_heap;
			// this prevents us from doing multiple jumps in case leave results in more allocations
			m_heap = NULL;
			heap->Leave();
		}
	}
	
	void GCHeap::Abort()
	{
		status = kMemAbort;
		EnterFrame *ef = enterFrame;
		GCLog("error: out of memory\n");

		if(config.OOMExitCode != 0) 
		{
			VMPI_exit(config.OOMExitCode);
		}
			
		if(ef != NULL && ef->m_heap != NULL)
		{
			VMPI_lockRelease(&m_spinlock);
			if(ef->m_gc) {
				// we're about to jump across the GC lock, unlock it
				ef->m_gc->SetStackEnter(NULL);
			}
			longjmp(ef->jmpbuf, 1);
		}
		GCAssertMsg(false, "MMGC_ENTER missing or we allocated more memory trying to shutdown");
		VMPI_abort();
	}
	
	void GCHeap::Enter(EnterFrame *frame)
	{
		MMGC_LOCK(m_spinlock);
		enterCount++;
		enterFrame = frame;
	}

	void GCHeap::Leave()
	{
		GCHeap *heapToDestroy=NULL;
		{
			MMGC_LOCK(m_spinlock);

			// only safe to run bail out code on primary thread
			if(VMPI_currentThread() == primordialThread && 
			   status == kMemAbort && !abortStatusNotificationSent) {
				abortStatusNotificationSent = true;
				StatusChangeNotify(kMemAbort);
			}

			// do this after StatusChangeNotify it affects ShouldNotEnter
			enterFrame = NULL;

			enterCount--;

			if(status == kMemAbort && enterCount == 0 && abortStatusNotificationSent) {
				// last one out of the pool pulls the plug
				heapToDestroy = instance;
				instance = NULL;
			}
		}
		if(heapToDestroy != NULL) {
			// any thread can call this, just need to make sure all other
			// threads are done, hence the ref counting
			heapToDestroy->DestroyInstance();
		}
	}
	void GCHeap::log_percentage(const char *name, size_t bytes, size_t bytes_compare)
	{
		bytes_compare = size_t((bytes*100.0)/bytes_compare);
		if(bytes > 1<<20) {
			GCLog("%s %u (%.1fM) %u%%\n", name, (unsigned int)(bytes / GCHeap::kBlockSize), bytes * 1.0 / (1024*1024), (unsigned int)(bytes_compare));
		} else {
			GCLog("%s %u (%uK) %u%%\n", name, (unsigned int)(bytes / GCHeap::kBlockSize), (unsigned int)(bytes / 1024), (unsigned int)(bytes_compare));
		}
	}
	
	void GCHeap::DumpMemoryInfo()
	{
		MMGC_LOCK(m_spinlock);
		DumpMemoryInfoLocked();
	}

	void GCHeap::DumpMemoryInfoLocked()
	{
		size_t priv = VMPI_getPrivateResidentPageCount() * GCHeap::kBlockSize;
		size_t mmgc = GetTotalHeapSize() * GCHeap::kBlockSize;
		size_t unmanaged = GetFixedMalloc()->GetTotalSize() * GCHeap::kBlockSize;
		size_t fixed_alloced;
		size_t fixed_asksize;
		GetFixedMalloc()->GetUsageInfo(fixed_asksize, fixed_alloced);

		size_t gc_total=0;
		size_t gc_allocated_total =0;
		size_t gc_ask_total = 0;
		BasicListIterator<GC*> iter(gcManager.gcs());
		GC* gc;
		while((gc = iter.next()) != NULL)
		{
#ifdef MMGC_MEMORY_PROFILER
			GCLog("[mem] GC 0x%p:%s\n", (void*)gc, GetAllocationName(gc));
#else
			GCLog("[mem] GC 0x%p\n", (void*)gc);
#endif
			gc->DumpMemoryInfo();
			
			size_t ask;
			size_t allocated;
			gc->GetUsageInfo(ask, allocated);
			gc_ask_total += ask;
			gc_allocated_total += allocated;
			
			gc_total += gc->GetNumBlocks() * kBlockSize;
		}
		GCLog("[mem] ------- gross stats -----\n");
		log_percentage("[mem] private", priv, priv);
		log_percentage("[mem]\t mmgc", mmgc, priv);
		log_percentage("[mem]\t\t unmanaged", unmanaged, priv);
		log_percentage("[mem]\t\t managed", gc_total, priv);
		log_percentage("[mem]\t\t free",  (size_t)GetFreeHeapSize() * GCHeap::kBlockSize, priv);
		log_percentage("[mem]\t other",  priv - mmgc, priv);
		log_percentage("[mem] \tunmanaged overhead ", unmanaged-fixed_alloced, unmanaged);
		log_percentage("[mem] \tmanaged overhead ", gc_total - gc_allocated_total, gc_total);
#ifdef MMGC_MEMORY_PROFILER
		if(HooksEnabled())
		{
			log_percentage("[mem] \tunmanaged internal wastage", fixed_alloced - fixed_asksize, fixed_alloced);
			log_percentage("[mem] \tmanaged internal wastage", gc_allocated_total - gc_ask_total, gc_allocated_total);
		}
#endif
		GCLog("[mem] -------- gross stats end -----\n");
		
		DumpHeapRep();
		
#ifdef MMGC_MEMORY_PROFILER
		if(hasSpy)
			DumpFatties();
#endif
	}

#ifdef VMCFG_SYMBIAN
	
	void GCHeap::LogChar(char c, size_t count)
	{
		// TODO: implement without alloca.
	}
	void GCHeap::DumpHeapRep()
	{
		// TODO: implement without alloca.
	}
	
#else
	
	void GCHeap::LogChar(char c, size_t count)
	{
		char* buf = (char*)alloca(count+1);
		VMPI_memset(buf, c, count);
		buf[count] = '\0';

		GCLog(buf);
	}

	void GCHeap::DumpHeapRep()
	{
		Region **regions;
		Region *r = lastRegion;
		int numRegions = 0;

		// count and sort regions
		while(r) {
			numRegions++;
			r = r->prev;
		}
		regions = (Region**) alloca(sizeof(Region*)*numRegions);
		r = lastRegion;
		for(int i=numRegions-1; i >= 0; i--) {
			regions[i] = r;
			r = r->prev;
		}
	
		HeapBlock *spanningBlock = NULL;
		for(int i=0; i < numRegions; i++)
		{
			r = regions[i];
			GCLog("0x%p -  0x%p\n", r->baseAddr, r->reserveTop);
			char c;
			char *addr = r->baseAddr;
			
			if(spanningBlock) {
				GCAssert(spanningBlock->baseAddr + (spanningBlock->size * kBlockSize) > r->baseAddr);
				GCAssert(spanningBlock->baseAddr < r->baseAddr);				
				char *end = spanningBlock->baseAddr + (spanningBlock->size * kBlockSize);
				if(end > r->reserveTop)
					end = r->reserveTop;

				LogChar(spanningBlock->inUse() ? '1' : '0', (end - addr)/kBlockSize);
				addr = end;

				if(addr == spanningBlock->baseAddr + (spanningBlock->size * kBlockSize))
					spanningBlock = NULL;
			}
			HeapBlock *hb;
			while(addr != r->commitTop && (hb = AddrToBlock(addr)) != NULL) {
				GCAssert(hb->size);

				if(hb->inUse())
					c = '1';
				else if(hb->committed)
					c = '0';
				else 
					c = '-';
				int i, n;
				for(i=0, n=hb->size; i < n; i++, addr += GCHeap::kBlockSize) {
					if(addr == r->reserveTop) {
						// end of region!
						spanningBlock = hb;
						break;
					}
				}

				LogChar(c, i);
			}

			LogChar('-', (r->reserveTop - addr) / kBlockSize);

			GCLog("\n");
		}
	}

#endif // VMCFG_SYMBIAN
	
#ifdef MMGC_MEMORY_PROFILER

	/* static */
	void GCHeap::InitProfiler()
	{
		GCAssert(IsProfilerInitialized() == false);
		profiler = NULL;

#ifdef MMGC_MEMORY_INFO
		bool profilingEnabled = true;
#else
		bool profilingEnabled = VMPI_isMemoryProfilingEnabled();
#endif
		if(profilingEnabled)
		{
			profiler = new MemoryProfiler();
		}
	}

#endif //MMGC_MEMORY_PROFILER

#ifdef MMGC_USE_SYSTEM_MALLOC

	void GCHeap::TrackSystemAlloc(void *addr, size_t askSize)
	{
		(void)addr;
		(void)askSize;
		MMGC_LOCK(m_spinlock);
	#ifdef MMGC_MEMORY_PROFILER
		if(!IsProfilerInitialized())
		{
			InitProfiler();
		}
		if(profiler)
			profiler->RecordAllocation(addr, askSize, VMPI_size(addr));
	#endif //MMGC_MEMORY_PROFILER

	}

	void GCHeap::TrackSystemFree(void *addr)
	{
		(void)addr;		
		MMGC_LOCK(m_spinlock);
	#ifdef MMGC_MEMORY_PROFILER
		if(addr && profiler)
			profiler->RecordDeallocation(addr, VMPI_size(addr));
	#endif //MMGC_MEMORY_PROFILER		
	}

#endif //MMGC_USE_SYSTEM_MALLOC
	
	void GCHeap::ReleaseMemory(char *address, size_t size)
	{
		if(config.useVirtualMemory) {
			bool success = VMPI_releaseMemoryRegion(address, size);
			GCAssert(success);
			(void)success;
		} else {
			VMPI_releaseAlignedMemory(address);
		}
	}

	void GCManager::destroy()
	{
		collectors.Destroy();
	}
	
	void GCManager::signalStartCollection(GC* gc)
	{
		BasicListIterator<GC*> iter(collectors);
		GC* otherGC;
		while((otherGC = iter.next()) != NULL) 
			otherGC->policy.signalStartCollection(gc);
	}
	
	void GCManager::signalEndCollection(GC* gc)
	{
		BasicListIterator<GC*> iter(collectors);
		GC* otherGC;
		while((otherGC = iter.next()) != NULL) 
			otherGC->policy.signalStartCollection(gc);
	}

	/* this method is the heart of the OOM system.
	   its here that we call out to the mutator which may call
	   back in to free memory or try to get more.
	*/
	void GCHeap::StatusChangeNotify(MemoryStatus to)
	{
		statusNotificationBeingSent = true;
		MemoryStatus oldStatus = status;
		status = to;
		
		// unlock the heap so that memory operations are allowed

		// this isn't right, really what we want is to allow this
		// thread to call Free but keep other threads out, so what we
		// really want is a lock operation that allows repeated same
		// thread locks
		VMPI_lockRelease(&m_spinlock);
		
		BasicListIterator<OOMCallback*> iter(callbacks);
		OOMCallback *cb = NULL;
		do {
			{
				MMGC_LOCK(list_lock);
				cb = iter.next();
			}
			if(cb)
				cb->memoryStatusChange(oldStatus, to);
		} while(cb != NULL);

		statusNotificationBeingSent = false;

		VMPI_lockAcquire(&m_spinlock);

		CheckForStatusReturnToNormal();
	}

 	/*static*/
	bool GCHeap::ShouldNotEnter()
	{
		// don't enter if the heap is already gone or we're aborting but not on the aborting call stack in a nested enter call
		if(GetGCHeap() == NULL || 
		   (MMgc::GCHeap::GetGCHeap()->GetStatus() == MMgc::kMemAbort && MMgc::GCHeap::GetGCHeap()->GetEnterFrame() == NULL))
			return true;
		return false;
	}

	bool GCHeap::IsAddressInHeap(void *addr)
	{
		return AddrToBlock(addr) != NULL;
	}

	// Every new GC must register itself with the GCHeap.
	void GCHeap::AddGC(GC *gc)
	{ 
		MMGC_LOCK(list_lock);
		gcManager.addGC(gc); 
	}		
		
	// When the GC is destroyed it must remove itself from the GCHeap.
	void GCHeap::RemoveGC(GC *gc) 
	{ 
		MMGC_LOCK(list_lock);
		gcManager.removeGC(gc); 
	}
	
	void GCHeap::AddOOMCallback(OOMCallback *p) 
	{
		MMGC_LOCK(list_lock);
		callbacks.Add(p); 
	}
	
	void GCHeap::RemoveOOMCallback(OOMCallback *p) 
	{ 
		MMGC_LOCK(list_lock);
		callbacks.Remove(p); 
	}
}
