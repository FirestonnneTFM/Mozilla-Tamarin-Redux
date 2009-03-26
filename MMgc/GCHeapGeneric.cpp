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
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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
#include "GCDebug.h"
#include "GC.h"

namespace MMgc
{
	void *aligned_malloc(size_t size, size_t align_size, GCMallocFuncPtr m_malloc)
	{
		char *ptr, *ptr2, *aligned_ptr;
		int align_mask = align_size - 1;

		int alloc_size = size + align_size + sizeof(int);
		ptr=(char *)m_malloc(alloc_size);

		if(ptr==NULL) return(NULL);

		ptr2 = ptr + sizeof(int);

		aligned_ptr = ptr2 + (align_size - ((size_t)ptr2 & align_mask));

		ptr2 = aligned_ptr - sizeof(int);
		*((int *)ptr2)=(int)(aligned_ptr - ptr);

		return(aligned_ptr);
	}

	void aligned_free(void *ptr, GCFreeFuncPtr m_free)
	{
		int *ptr2=(int *)ptr - 1;
		char *unaligned_ptr = (char*) ptr - *ptr2;
		m_free(unaligned_ptr);
	}

	uint32_t GCHeap::vmPageSize()
	{
#ifdef MMGC_PORTING_API
		return MMGC_PortAPI_GetPageSize();
#else
		return 4096;
#endif
	}

#ifdef MEASURE_MEMORY_HIGHWATER

ChunkTracker* ChunkTracker::s_pHead = NULL;
unsigned int ChunkTracker::s_highwater = 0;
unsigned int ChunkTracker::s_total_mem = 0;
unsigned int ChunkTracker::s_blocks = 0;
unsigned int ChunkTracker::s_maxblocks = 0;



#endif
	
	char* GCHeap::AllocateAlignedMemory(size_t size)
	{
		GCMallocFuncPtr m;
#ifdef MMGC_PORTING_API
		m = MMGC_PortAPI_Alloc;
#else
		m = malloc;
#endif

#ifdef MEASURE_MEMORY_HIGHWATER
		ChunkTracker::s_total_mem += size;
		if (ChunkTracker::s_total_mem > ChunkTracker::s_highwater)
		{
			ChunkTracker::s_highwater = ChunkTracker::s_total_mem;
		}
		ChunkTracker::s_blocks++;
		if (ChunkTracker::s_blocks > ChunkTracker::s_maxblocks)
		{
			ChunkTracker::s_maxblocks = ChunkTracker::s_blocks;
		}
		void* block = aligned_malloc(size, vmPageSize(), m);
		ChunkTracker* chunk = new ChunkTracker(block, size);
		chunk->m_pNext = ChunkTracker::s_pHead;
		ChunkTracker::s_pHead = chunk;
		return (char*)block;
#else
		return (char *) aligned_malloc(size, vmPageSize(), m);
#endif
	}

	void GCHeap::ReleaseAlignedMemory(char *address, size_t)
	{
		GCFreeFuncPtr f;
#ifdef MMGC_PORTING_API
		f = MMGC_PortAPI_Free;
#else
		f = free;
#endif

#ifdef MEASURE_MEMORY_HIGHWATER
		ChunkTracker::s_blocks--;
		ChunkTracker* chunk = ChunkTracker::s_pHead;
		ChunkTracker* prev = NULL;
		while(chunk)
		{
			if (chunk->m_block == address)
			{
				ChunkTracker::s_total_mem -= chunk->m_size;
				if (prev)
				{
					prev->m_pNext = chunk->m_pNext;
				}
				else
				{
					ChunkTracker::s_pHead = chunk->m_pNext;
				}
				delete chunk;
				break;
			}
			prev = chunk;
			chunk = chunk->m_pNext;
		}
#endif
		aligned_free(address, f);
	}	

	void GetStackTrace(int* /* trace */, int /* len */, int /* skip */)
	{
	}
	
	void GetInfoFromPC(int /* pc */, char *buff, int buffSize)
	{
		if (buffSize > 0)
		{
			buff[0] = '\0';
		}
	}

	/*static*/
	size_t GCHeap::GetPrivateBytes() { return 0; } // TODO	

	bool GCHeap::osSupportsRegionMerging()
	{
		return false;
	}

	bool GCHeap::osSupportsVirtualMemory()
	{
		return false;
	}

	
	char *GCHeap::ReserveMemory(char *, size_t) { GCAssert(false); return NULL; }
	bool GCHeap::CommitMemory(char *, size_t) { GCAssert(false); return false; }
	bool GCHeap::DecommitMemory(char *, size_t) { GCAssert(false); return false; }
	void GCHeap::ReleaseMemory(char *, size_t ) { GCAssert(false); }		
	
	bool GCHeap::CommitMemoryThatMaySpanRegions(char *, size_t) { GCAssert(false); return false; }
	bool GCHeap::DecommitMemoryThatMaySpanRegions(char *, size_t)  { GCAssert(false); return false; }
}
