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

#ifdef AVMPLUS_SAMPLER
 //sampling support
#include "avmplus.h"
#else
#define SAMPLE_FRAME(_x, _s) 
#define SAMPLE_CHECK() 
#endif

#define CAPACITY(T)  (unsigned(GCHeap::kBlockSize) / unsigned(sizeof(T)))

namespace MMgc
{
	////////////// ZCT /////////////////////////////////////////////////////////////////////////////
	
//#define ZCT_TESTING					// Test the handling of a failure to extend the ZCT

#ifdef ZCT_TESTING
	static int zct_allowance = 0;		// The first block isn't accounted for, so add one to this number
										// for the true number of blocks
#endif

	// We can grow if adding a block makes the largest index of the grown table representable
	// in the field in RCObject used to hold the ZCT index for the object.
	inline bool ZCT::CanGrow()
	{
		return uint32_t(Capacity() + CAPACITY(RCObject*) - 1) <= uint32_t(RCObject::ZCT_INDEX)>>8;
	}
	
	inline int ZCT::Capacity()
	{
		return int((blocktop - blocktable) * CAPACITY(RCObject*));
	}
	
	inline bool ZCT::HasFree()
	{
		return freelist != -1;
	}
	
	inline int ZCT::BlockNumber(int index)
	{
		return int(unsigned(index)/CAPACITY(RCObject**));
	}
	
	inline int ZCT::EntryNumber(int index)
	{
		return index & int(CAPACITY(RCObject*)-1);
	}

	inline RCObject** ZCT::PointerTo(int index)
	{
		GCAssert(index >= 0 && index < Capacity());
		return blocktable[BlockNumber(index)] + EntryNumber(index);
	}

	inline int ZCT::GrabFree()
	{
		GCAssert( HasFree() );
		int index = freelist;
		freelist = (int)(uintptr_t)Get(index);
		return index;
	}
	
	inline void ZCT::MakeFree(int index)
	{
		GCAssert(index >= 0 && index < Capacity());
		*PointerTo(index) = (RCObject*)(uintptr_t)freelist;
		freelist = index;
	}
	
	inline RCObject* ZCT::Get(int index)
	{
		return *PointerTo(index);
	}
	
	inline void ZCT::Put(int index, RCObject* value)
	{
		*PointerTo(index) = value;
	}

	ZCT::ZCT()
		: gc(NULL)					// will be set in SetGC
		, blocktable(NULL)			// will be set in SetGC
		, blocktop(NULL)			// will be set in SetGC
		, freelist(-1)
		, reaping(false)
		, count(0)
		, zctNext(0)
		, zctReapThreshold(0)		// will be set in SetGC
		, zctIndex(0)
		, nextPinnedIndex(0)
	{
	}
	
	void ZCT::Destroy()
	{
		for ( RCObject*** p = blocktable ; p < blocktop ; p++ )
			gc->heapFree(*p);
		gc->heapFree(blocktable);
	}
	
	void ZCT::SetGC(GC *gc)
	{
		this->gc = gc;
		
		// The size of the block table is limited by the field in the RCObject header
		// that accomodates the ZCT index.  This field is currently 20 bits, so
		// the max number of entries in the ZCT is 1M.  On a 64-bit system each block
		// holds 512 elements so the block table needs 2K entries, occupying
		// four blocks.  On a 32-bit system each block holds 1K elements so the block
		// table needs 1K entries, occupying a single block.  Instead of messing with
		// growing the block table later, just allocate full tables here.  The
		// pointed-to blocks are still allocated on demand.
		
		GCAssert((uint32_t(RCObject::ZCT_INDEX)>>8) == 0xFFFFFU);
#ifdef MMGC_64BIT
		const int numblocks = 4;
#else
		const int numblocks = 1;
#endif
		blocktable = (RCObject***) gc->heapAlloc(numblocks);	// must succeed
		for ( unsigned i=0 ; i < CAPACITY(RCObject**)*numblocks ; i++ )
			blocktable[i] = NULL;
		blocktable[0] = (RCObject**) gc->heapAlloc(1);			// must succeed
		blocktop = blocktable + 1;
		zctReapThreshold = int(gc->policy.zctNewReapThreshold(blocktop - blocktable, 0));
	}
	
	void ZCT::Add(RCObject *obj REFCOUNT_PROFILING_ARG(bool initial))
	{
		REFCOUNT_PROFILING_ONLY( gc->policy.signalZCTAdd(initial, count); )
		if(gc->collecting)
		{
			// this is a vestige from FP8 to fix bug 165100, it has the affect of delaying 
			// the deletion of some objects which causes the site to work
			if(gc->dontAddToZCTDuringCollection)
				return;
			
			// unmarked objects are gonna get swept anyways
			if(!GC::GetMark(obj))
				return;
		}
		
#if 0
		// note if we add things while reaping we could delete the object
		// here if we had a way to monitor our stack usage
		if(reaping && PLENTY_OF_STACK()) {
			for ( GCCallback *cb = gc->m_callbacks; cb ; cb = cb->nextCB )
				cb->prereap(obj);
			if(gc->IsFinalized(obj))
				((GCFinalizable*)obj)->~GCFinalizable();
			gc->Free(obj);
			return;
		}
#endif
		
		if(HasFree()) {
			int index = GrabFree();
			Put(index, obj);
			obj->setZCTIndex(index);
		}
		else if(reaping && zctIndex > nextPinnedIndex) {
			// we're going over the list, insert this guy at the front if possible
			zctIndex--;
			GCAssert(Get(zctIndex) == NULL);
			Put(zctIndex, obj);
			obj->setZCTIndex(zctIndex);
		}
		else if(zctNext < Capacity()) {
			Put(zctNext, obj);
			obj->setZCTIndex(zctNext);
			zctNext++;
		}
		else {
			// zct is full, do nothing, mark/sweep will have to handle it
			return;
		}
		
		count++;
		
		bool should_grow = false;
		
		if(!reaping) {
			// object that were pinned last reap should be unpinned
			if(obj->IsPinned())
				obj->Unpin();
			if(!gc->collecting && zctNext >= zctReapThreshold) {
				Reap();
				should_grow = gc->policy.queryZctShouldGrowAfterReap(blocktop - blocktable, count);
			}
		}
		
		GCAssert(zctNext <= Capacity());
		
		if((should_grow || zctNext == Capacity()) && CanGrow()) 
			Grow();
	}
	
	void ZCT::Remove(RCObject *obj REFCOUNT_PROFILING_ARG(bool final))
	{
		REFCOUNT_PROFILING_ONLY( gc->policy.signalZCTRemove(final); )
		int index = obj->getZCTIndex();
		GCAssert(Get(index) == obj);
		
		if(reaping) {
			// freelist doesn't exist during reaping, simplifies things, holes will
			// be compacted next go around if index < nextPinnedIndex.  the freelist
			// allows incoming object to be added behind zctIndex which would mean
			// the reap process wouldn't cascade like its supposed to. 
			Put(index,NULL);
		}
		else {
			MakeFree(index);
		}
		obj->ClearZCTFlag();
		count--;
	}
	
	void ZCT::PinStackObjects(const void *start, size_t len)
	{
		RCObject **p = (RCObject**)start;
		RCObject **end = p + len/sizeof(RCObject*);
		
		const void *_memStart = (const void*)gc->memStart;
		const void *_memEnd = (const void*)gc->memEnd;
		
		while(p < end) {
			const void *val = GC::Pointer(*p++);	
			
			if(val < _memStart || val >= _memEnd)
				continue;
			
			int bits = gc->GetPageMapValue((uintptr_t)val); 
			bool doit = false;
			if (bits == GC::kGCAllocPage) {
				doit = GCAlloc::IsRCObject(val) && GCAlloc::FindBeginning(val) == GetRealPointer(val);
			} 
			else if(bits == GC::kGCLargeAllocPageFirst) {
				doit = GCLargeAlloc::IsRCObject(val) && GCLargeAlloc::FindBeginning(val) == GetRealPointer(val);
			}
			
			if(doit) {
				RCObject *obj = (RCObject*)val;
				obj->Pin();
			}
		}
	}

	void ZCT::Reap(bool scanStack)
	{
		if(gc->collecting || reaping || count == 0)
			return;
		
		gc->policy.signal(GCPolicyManager::START_ReapZCT);
		
		volatile uint64_t start = 0;
		if(gc->heap->Config().gcstats) {
			start = VMPI_getPerformanceCounter();
		}
		uint32_t pagesStart = (uint32_t)gc->GetNumBlocks();
		uint32_t numObjects=0;
		size_t objSize=0;
		
		reaping = true;
		
		SAMPLE_FRAME("[reap]", gc->core());
		
		// start by pinning live stack objects
		GCWorkItem item;
		MMGC_GET_STACK_EXTENTS(gc, item.ptr, item._size);
		if (scanStack)
			PinStackObjects(item.ptr, item._size);
		
		GC::RCRootSegment* segment = gc->rcRootSegments;
		while(segment)
		{
			PinStackObjects(segment->mem, segment->size);
			segment = segment->next;
		}
		
		// important to do this before calling prereap
		// use index to iterate in case it grows, as we go through the list we
		// unpin pinned objects and pack them at the front of the list, that
		// way the ZCT is in a good state at the end
		zctIndex = 0;
		nextPinnedIndex = 0;
		
		// invoke prereap on all callbacks
		for ( GCCallback *cb = gc->m_callbacks; cb ; cb = cb->nextCB )
			cb->prereap();
		
#ifdef _DEBUG
		if(gc->validateDefRef) {
			// kill incremental mark since we're gonna wipe the marks
			gc->marking = false;
			gc->m_incrementalWork.Clear();
			gc->m_barrierWork.Clear();
			gc->Trace(item.ptr, item._size);
		}
#endif
		
		// first nuke the freelist, we won't have one when we're done reaping
		// and we don't want secondary objects put on the freelist (otherwise
		// reaping couldn't be a linear scan)
		while (HasFree())
			Put(GrabFree(), NULL);
		
#ifdef MMGC_POLICY_PROFILING
		uint32_t objects_reaped = 0;
		uint32_t objects_pinned = 0;
#endif
		
		while(zctIndex < zctNext) {
			SAMPLE_CHECK();
			RCObject *rcobj = Get(zctIndex++);
			if(rcobj && !rcobj->IsPinned()) {
				rcobj->ClearZCTFlag();
				Put(zctIndex-1, NULL);
				count--;
#ifdef _DEBUG
				if(gc->validateDefRef) {
					if(gc->GetMark(rcobj)) {
#ifdef MMGC_RC_HISTORY
						rcobj->DumpHistory();
#endif
#ifdef MMGC_MEMORY_INFO
						GCDebugMsg(false, "Back pointer chain:");
						gc->DumpBackPointerChain(rcobj);
#endif
						GCAssertMsg(false, "Zero count object reachable, ref counts not correct!");
					}
				}
#endif
				// invoke prereap on all callbacks
				for ( GCCallback *cb = gc->m_callbacks; cb ; cb = cb->nextCB )
					cb->prereap(rcobj);
				
				GCAssert(*(intptr_t*)rcobj != 0);
				GCAssert(gc->IsFinalized(rcobj));
				((GCFinalizable*)rcobj)->~GCFinalizable();
				numObjects++;
				objSize += GC::Size(rcobj);
#ifdef MMGC_POLICY_PROFILING
				objects_reaped++;
#endif
				gc->Free(rcobj);
				
				GCAssert(gc->weakRefs.get(rcobj) == NULL);
			}
			else if(rcobj) {
				// move it to front
				rcobj->Unpin();
#ifdef MMGC_POLICY_PROFILING
				objects_pinned++;
#endif
				if(nextPinnedIndex != zctIndex-1) {
					rcobj->setZCTIndex(nextPinnedIndex);
					GCAssert(Get(nextPinnedIndex) == NULL);
					Put(nextPinnedIndex, rcobj);
					Put(zctIndex-1, NULL);
				}
				nextPinnedIndex++;				
			}
		}
		
		zctNext = nextPinnedIndex;
		zctReapThreshold = int(gc->policy.zctNewReapThreshold(blocktop - blocktable, count));
		GCAssert(nextPinnedIndex == count);
		zctIndex = nextPinnedIndex = 0;
		
		// invoke postreap on all callbacks
		for ( GCCallback *cb = gc->m_callbacks; cb ; cb = cb->nextCB )
			cb->postreap();
		
		if(gc->heap->Config().gcstats && numObjects) {
			gc->gclog("[mem] DRC reaped %d objects (%d kb) freeing %d pages (%d kb) in %.2f millis (%.4f s)\n", 
					  numObjects, objSize>>10, pagesStart - gc->GetNumBlocks(), gc->GetNumBlocks()*GCHeap::kBlockSize >> 10, 
					  GC::duration(start), gc->duration(gc->t0)/1000);
		}
		reaping = false;
		
#ifdef _DEBUG
		if(gc->validateDefRef) {
			gc->Sweep();
		}
#endif
		
#ifdef MMGC_POLICY_PROFILING
		gc->policy.signalReapWork(objects_reaped, uint32_t(objSize), objects_pinned);
#endif
		gc->policy.signal(GCPolicyManager::END_ReapZCT);
	}
	
	void ZCT::Grow()
	{
		GCAssert(CanGrow());
		GCAssert(*blocktop == NULL);

#ifdef ZCT_TESTING
		if (zct_allowance == 0)
			return;
		--zct_allowance;
#endif
		// Allocate one more block
		// The flags are the default flags for heapAlloc() + kCanFail
		*blocktop = (RCObject**)gc->heapAlloc(1, GCHeap::kExpand|GCHeap::kZero|GCHeap::kProfile|GCHeap::kCanFail);
		if (*blocktop == NULL)
			return;
		blocktop++;
		
		// If the ZCT is nearly full after Reap then the new threshold will be
		// pinned within the old size but the ZCT may still grow; recompute the
		// threshold following growth to get something more realistic.
		zctReapThreshold = int(gc->policy.zctNewReapThreshold(blocktop - blocktable, count));
	}

	void ZCT::Prune()
	{
		int lastblock = (zctNext - 1) / int(CAPACITY(RCObject*));
		// Both Grow() and ~ZCT depend on there being no blocks at or above blocktop, so if 
		// that changes here then be sure to fix those as well.
		for ( int i=lastblock + 1, limit=int(blocktop - blocktable) ; i < limit ; i++ ) {
			gc->heapFree(blocktable[i]);
			blocktable[i] = NULL;
#ifdef ZCT_TESTING
			zct_allowance++;
#endif
		}
		blocktop = blocktable + lastblock + 1;
	}
}
