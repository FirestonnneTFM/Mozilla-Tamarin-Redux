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

#define MMGC_SCALAR_GUARD 0xafafafaf
#define MMGC_NORM_VECTOR_GUARD 0xbfbf0001
#define MMGC_PRIM_VECTOR_GUARD 0xbfbf0002

namespace MMgc
{
	void *AllocCall(size_t s, FixedMallocOpts opts) 
	{ 
		return AllocCallInline(s, opts);
	}

	void DeleteCall( void* p )
	{
		DeleteCallInline(p);
	}

#ifdef MMGC_USE_SYSTEM_MALLOC
	void *SystemNew(size_t size)
	{	
		void *space = VMPI_alloc(size);
		GCHeap::GetGCHeap()->TrackSystemAlloc(space, size);
		return space;
	}

	void SystemDelete(void *p)
	{
		GCHeap::GetGCHeap()->TrackSystemFree(p);
		VMPI_free(p);
	}
#endif
};

#ifndef MMGC_OVERRIDE_GLOBAL_NEW

void* operator new(size_t size, MMgc::NewDummyOperand /*ignored*/) MMGC_NEW_THROWS_CLAUSE
{
	return MMgc::NewCall(size);
}

void* operator new(size_t size, MMgc::NewDummyOperand /*ignored*/, MMgc::FixedMallocOpts opts) MMGC_NEW_THROWS_CLAUSE
{
	return MMgc::NewCall(size, opts);
}

namespace MMgc
{
	REALLY_INLINE void *GuardedFixedAlloc(size_t size, FixedMallocOpts opts, uint32_t guard)
	{
#ifdef MMGC_DELETE_DEBUGGING
		// lets store a guard cookie so that we can see if it is released with a proper delete (scalar/vector)
		size += sizeof(size_t);
#else
		(void)guard; // get rid of warning
#endif //MMGC_DELETE_DEBUGGING

		size_t* mem = (size_t*)AllocCallInline(size, opts);

#ifdef MMGC_DELETE_DEBUGGING
		if ( mem )
		{
			// add the guard cookie
			*(mem) = guard; 
			mem += 1;
		}
#endif // MMGC_DELETE_DEBUGGING

		return mem;
	}

	/*REALLY_INLINE*/
	void* NewCall(size_t size, FixedMallocOpts opts)
	{
		GCAssertMsg(GCHeap::GetGCHeap()->StackEnteredCheck() || (opts&kCanFail) != 0, "MMGC_ENTER macro must exist on the stack");
		return GuardedFixedAlloc(size, opts, MMGC_SCALAR_GUARD);
	}

	REALLY_INLINE size_t CallocSizeCalc(size_t el_size, size_t count, bool& overflow, bool addCookie)
	{
		uint64_t size = (uint64_t)count * (uint64_t)el_size;

		if(addCookie)
			size += sizeof(size_t);

		if(size > 0xfffffff0) 
		{
			overflow = true;
			return 0;
		}
		return (size_t)size;
	}

	void* NewArrayCalloc(size_t el_size, size_t count, FixedMallocOpts opts, bool isPrimitive) 
	{
		GCAssertMsg(GCHeap::GetGCHeap()->StackEnteredCheck() || (opts&kCanFail) != 0, "MMGC_ENTER macro must exist on the stack");

		bool overflow = false;
		size_t size = CallocSizeCalc(el_size, count, overflow, isPrimitive ? false : true);
		if(overflow) 
		{
			GCAssertMsg(false, "Attempted allocation overflows size_t\n");
			return NULL;
		}

		return GuardedFixedAlloc(size, opts, isPrimitive ? MMGC_PRIM_VECTOR_GUARD : MMGC_NORM_VECTOR_GUARD);
	}

#ifdef MMGC_DELETE_DEBUGGING
	// Helper functions to check the 
	bool CheckForAllocationGuard(size_t* mem, size_t guard)
	{
		mem--;
		return (*mem == guard);
	}

	bool IsScalarAllocation(void* p)
	{
		return CheckForAllocationGuard((size_t*)p, MMGC_SCALAR_GUARD);
	}

	bool IsVectorAllocation(void* p, bool primitive)
	{
		// Check if we have vector guard right before the pointer.
		size_t* w = (size_t*)p;
		size_t guard = primitive ? MMGC_PRIM_VECTOR_GUARD : MMGC_NORM_VECTOR_GUARD;
		return CheckForAllocationGuard(w, guard) || // simple vector
			CheckForAllocationGuard(w-1, guard); // vector with count
	}

	bool IsGCHeapAllocation(void* p)
	{
		return (GCHeap::GetGCHeap() && GCHeap::GetGCHeap()->IsAddressInHeap(p));
	}

	void VerifyScalarDelete(void* p)
	{
		if (!IsScalarAllocation(p))
		{
			if (IsVectorAllocation(p, true) || IsVectorAllocation(p, false))
			{
				GCAssertMsg(0, "Trying to release array pointer with scalar destructor! Check the allocation and free calls for this object!");
			}
			else if (!IsGCHeapAllocation(p))
			{
				GCAssertMsg(0, "Trying to release system memory with scalar deletefunc! Check the allocation and free calls for this object!");
			}
			else
			{
				GCAssertMsg(0, "Trying to release funky memory with scalar deletefunc! Check the allocation and free calls for this object!");
			}
		}
	}

	void VerifyVectorDelete(void* p, bool primitive)
	{
		if (!IsVectorAllocation(p, primitive))
		{
			if (IsVectorAllocation(p, !primitive))
			{
				GCAssertMsg(0, "Trying to release array pointer with different type destructor! Check the allocation and free calls for this object!");
			}
			if (IsScalarAllocation(p))
			{
				GCAssertMsg(0, "Trying to release scalar pointer with vector destructor! Check the allocation and free calls for this object!");
			}
			else if (!IsGCHeapAllocation(p))
			{
				GCAssertMsg(0, "Trying to release system pointer with vector deletefunc! Check the allocation and free calls for this object!");
			}
			else
			{
				GCAssertMsg(0, "Trying to release funky memory with vector deletefunc! Check the allocation and free calls for this object!");
			}
		}
	}

#endif //MMGC_DELETE_DEBUGGING

	// Functions to actually release the memory through FixedMalloc.
	void DeleteFunc( void* p )
	{
#ifdef MMGC_DELETE_DEBUGGING
		// we need to adjust the pointer to release also the guard.
		size_t* temp = (size_t*)p;
		temp--;
		p = temp;
#endif //MMGC_DELETE_DEBUGGING

		DeleteCallInline(p);
	}


	void DeleteArrayFunc( void* p )
	{
		if( p )
		{
#ifdef MMGC_DELETE_DEBUGGING
			p = ((size_t*)p - 2);
#else
			p = ((size_t*)p - 1);
#endif //MMGC_DELETE_DEBUGGING
			DeleteCallInline(p);
		}
	}

	void SimpleDestructorCall(void* p)
	{
		if( p ) 
		{
#ifdef MMGC_DELETE_DEBUGGING
			VerifyScalarDelete( p );
#endif
			DeleteFunc( p ); 
		}	
	}

	void SimpleDestructorArrayCall(void* p, bool primitive)
	{
		if(p) 
		{
#ifdef MMGC_DELETE_DEBUGGING
			VerifyVectorDelete( p, primitive );
#else
			(void)primitive; // get rid of warning
#endif
			// not using DeleteArrayFunc, that's for non-Simple case with count cookie
			DeleteFunc( p );
		}
	}

} // namespace MMgc

#endif //MMGC_OVERRIDE_GLOBAL_NEW
