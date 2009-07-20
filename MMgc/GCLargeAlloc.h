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

#ifndef __GCLargeAlloc__
#define __GCLargeAlloc__

namespace MMgc
{
	/**
	 * This is a garbage collecting allocator for large memory blocks.
	 */
	class GCLargeAlloc : public GCAllocObject
	{
		friend class GC;
		friend class GCLargeAllocIterator;
	private:
		enum {
			kMarkFlag         = 0x1,
			kQueuedFlag       = 0x2,
			kFinalizeFlag     = 0x4,
			kHasWeakRef       = 0x8,
			kContainsPointers = 0x10,
			kRCObject         = 0x20
		};

	public:
		GCLargeAlloc(GC* gc);
		~GCLargeAlloc();

		void* Alloc(size_t originalSize, size_t requestSize, int flags);
		void Free(const void *ptr);
		void Finalize();
		void ClearMarks();

		// not a hot method
		static void SetHasWeakRef(const void *item, bool to)
		{
			if(to) {
				GetLargeBlock(item)->flags |= kHasWeakRef;
			} else {
				GetLargeBlock(item)->flags &= ~kHasWeakRef;
			}
		}

		// not a hot method
		static bool HasWeakRef(const void *item)
		{
			return (GetLargeBlock(item)->flags & kHasWeakRef) != 0;
		}

		REALLY_INLINE static bool IsLargeBlock(const void *item)
		{
			// The pointer should be 4K aligned plus 16 bytes
			// Mac inserts 16 bytes for new[] so make it more general
			return (((uintptr_t)item & 0xFFF) == sizeof(LargeBlock));
		}

		REALLY_INLINE static bool SetMark(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			bool oldMark = (block->flags & kMarkFlag) != 0;
			block->flags |= kMarkFlag;
			block->flags &= ~kQueuedFlag;
			return oldMark;
		}

		// Not a hot method but always inlining probably shrinks the code
		REALLY_INLINE static void SetFinalize(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			block->flags |= kFinalizeFlag;
		}
		
		REALLY_INLINE static bool GetMark(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (block->flags & kMarkFlag) != 0;
		}

#ifdef _DEBUG
		static bool IsWhite(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			if(!IsLargeBlock(item))
				return false;
			return (block->flags & (kMarkFlag|kQueuedFlag)) == 0;
		}
#endif
	
		REALLY_INLINE static bool IsMarkedThenMakeQueued(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			if ((block->flags & kMarkFlag) != 0) {
				block->flags ^= kMarkFlag|kQueuedFlag;
				return true;
			}
			return false;
		}

		REALLY_INLINE static bool IsQueued(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (block->flags & kQueuedFlag) != 0;
		}

		REALLY_INLINE static void* FindBeginning(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (void*) (block+1);
		}

		// not a hot method
		static void ClearFinalized(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			block->flags &= ~kFinalizeFlag;
		}

		// Not hot, because GC::MarkItem open-codes it
		static bool ContainsPointers(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (block->flags & kContainsPointers) != 0;
		}
		
		// not a hot method
		static bool IsFinalized(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (block->flags & kFinalizeFlag) != 0;
		}

		// Can be hot - used by PinStackObjects
		REALLY_INLINE static bool IsRCObject(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			return (block->flags & kRCObject) != 0;
		}

		//This method returns the number bytes allocated by FixedMalloc
		size_t GetBytesInUse();
		
		//This method is for more fine grained allocation details
		//It reports the total number of bytes requested (i.e. ask size) and
		//the number of bytes actually allocated.  The latter is the same
		//number as reported by GetBytesInUse()
		void GetUsageInfo(size_t& totalAskSize, size_t& totalAllocated);

	private:
		struct LargeBlock : GCBlockHeader
		{
			uint32_t flags;

			int GetNumBlocks() const
			{
				return (size + sizeof(LargeBlock)) / GCHeap::kBlockSize;
			}
		};

		REALLY_INLINE static LargeBlock* GetLargeBlock(const void *addr)
		{
			return (LargeBlock*)GetBlockHeader(addr);
		}
		
		// not a hot method
		static bool NeedsFinalize(LargeBlock *block)
		{
			return (block->flags & kFinalizeFlag) != 0;
		}			
		
		// not a hot method
		static void ClearQueued(const void *item)
		{
			LargeBlock *block = GetLargeBlock(item);
			block->flags &= ~kQueuedFlag;
		}
		
		// The list of chunk blocks
		LargeBlock* m_blocks;
#ifdef MMGC_MEMORY_PROFILER
		size_t m_totalAskSize;
#endif

		bool m_startedFinalize;
		
#ifdef _DEBUG
		static bool ConservativeGetMark(const void *item, bool bogusPointerReturnValue);
#endif

	protected:
		GC *m_gc;

	public:
		REALLY_INLINE static LargeBlock* Next(LargeBlock* b)
		{
			return (LargeBlock*)b->next;
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
	class GCLargeAllocIterator
	{
	public:
		GCLargeAllocIterator(MMgc::GCLargeAlloc* alloc) 
			: alloc(alloc)
			, block(alloc->m_blocks)
		{
		}
		
		bool GetNextMarkedObject(void*& out_ptr, uint32_t& out_size)
		{
			while (block != NULL) {
				GCLargeAlloc::LargeBlock* b = block;
				block = GCLargeAlloc::Next(block);
				if ((b->flags & (GCLargeAlloc::kContainsPointers|GCLargeAlloc::kMarkFlag)) == (GCLargeAlloc::kContainsPointers|GCLargeAlloc::kMarkFlag)) {
					out_ptr = GetUserPointer(b+1);
					out_size = b->size - (uint32_t)DebugSize();
					return true;
				}
			}
			return false;
		}
		
	private:
		GCLargeAlloc* const alloc;
		GCLargeAlloc::LargeBlock* block;
	};
}

#endif /* __GCLargeAlloc__ */
