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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

//
// GCWriteBarrier
//

#ifndef _WRITE_BARRIER_H_
#define _WRITE_BARRIER_H_

// inline write barrier
#define WB(gc, container, addr, value) gc->privateWriteBarrier(container, addr, (const void *) (value))

// fast manual RC write barrier
#define WBRC(gc, container, addr, value) gc->privateWriteBarrierRC(container, addr, (const void *) (value))

// declare write barrier
// put spaces around the template arg to avoid possible digraph warnings
#define DWB(type) MMgc::WriteBarrier< type >

// declare an optimized RCObject write barrier
// put spaces around the template arg to avoid possible digraph warnings
#define DRCWB(type) MMgc::WriteBarrierRC< type >

#ifdef MMGC_POLICY_PROFILING
    #define POLICY_PROFILING_ONLY(x) x
#else
    #define POLICY_PROFILING_ONLY(x)
#endif

namespace MMgc
{
	/*private*/
	REALLY_INLINE void GC::WriteBarrierWriteRC(const void *address, const void *value)
	{
		RCObject *rc = (RCObject*)Pointer(*(RCObject**)address);
		if(rc != NULL) {
			GCAssert(rc == FindBeginning(rc));
			GCAssert(IsRCObject(rc));
			rc->DecrementRef();
		}
		GCAssert(IsPointerIntoGCObject(address));
		*(uintptr_t*)address = (uintptr_t) value;
		rc = (RCObject*)Pointer(value);
		if(rc != NULL) {
			GCAssert(IsRCObject(rc));
			GCAssert(rc == FindBeginning(value));
			rc->IncrementRef();
		}
	}

	/*private*/
	REALLY_INLINE void GC::WriteBarrierWrite(const void *address, const void *value)
	{
		GCAssert(!IsRCObject(value));
		GCAssert(IsPointerIntoGCObject(address));
		*(uintptr_t*)address = (uintptr_t) value;
	}

	/*private*/
	REALLY_INLINE void GC::InlineWriteBarrierTrap(const void *container)
	{
		GCAssert(IsPointerToGCPage(container));
		
		POLICY_PROFILING_ONLY(int stage=0;)
		// If the object is black then it needs to be gray, because we just stored
		// something into it.
		// Need to check 'marking' for correctness.  (Not clear to me yet why.)
		// It's /sometimes/ useful to check 'value' for NULL - depends on the program, obviously.
		if (marking) {
			POLICY_PROFILING_ONLY(stage=1;)
			if (IsMarkedThenMakeQueued(container)) {
				POLICY_PROFILING_ONLY(stage=2;)
				// Now just push the gray object onto the barrier mark stack.
				// IncrementalMark may move a segment off the secondary mark stack;
				// FinishIncrementalMark will take care of what remains.
				// We don't care what 'value' is - the marker will perform a more efficient
				// check for pointers to GC objects than we can do here anyway.
				// Observe that if this push fails, then the item is just pushed onto
				// the regular mark stack as part of the normal stack overflow handling.
				// That is what we want.
				GCWorkItem item(container, (uint32_t)Size(container), true);
				PushBarrierItem(item);
			}
		}
		POLICY_PROFILING_ONLY( policy.signalWriteBarrierWork(stage); )
	}

	REALLY_INLINE void GC::privateInlineWriteBarrier(const void *container, const void *address, const void *value)
	{
		GCAssert(!container || IsPointerToGCPage(container));
		GCAssert(((uintptr_t)address & 3) == 0);
		
		if (container) {
			GCAssert(address >= container);
			GCAssert(address < (char*)container + Size(container));
			InlineWriteBarrierTrap(container);
		}
		WriteBarrierWrite(address, value);
	}

	REALLY_INLINE void GC::privateInlineWriteBarrierRC(const void *container, const void *address, const void *value)
	{
		GCAssert(IsPointerToGCPage(container));
		GCAssert(((uintptr_t)container & 3) == 0);
		GCAssert(((uintptr_t)address & 2) == 0);
		GCAssert(address >= container);
		GCAssert(address < (char*)container + Size(container));
		
		InlineWriteBarrierTrap(container);
		WriteBarrierWriteRC(address, value);
	}

	/**
	 * WB is a smart pointer write barrier meant to be used on any field of a GC object that
	 * may point to another GC object.  A write barrier may only be avoided if if the field is
	 * const and no allocations occur between the construction of the object holding the field 
	 * and the assignment. 
	 */
	template<class T> class WriteBarrier
	{
	private:
		// Always pay for a single real function call; then inline & optimize massively in WriteBarrier()
		REALLY_INLINE
		T set(const T tNew)
		{
			GC::WriteBarrier(&t, (const void*)tNew);	// updates 't'
			return tNew;
		}
	public:
		explicit REALLY_INLINE WriteBarrier() : t(0)  
		{
		}

		explicit REALLY_INLINE WriteBarrier(T _t) : t(_t)
		{ 
			//set(_t); not necessary
		}

		REALLY_INLINE ~WriteBarrier() 
		{ 
			t = 0;
		}

		REALLY_INLINE T operator=(const WriteBarrier<T>& wb)
		{
			return set(wb.t);	
		}

		REALLY_INLINE T operator=(T tNew)
		{
			return set(tNew);
		}

		// BEHOLD ... The weird power of C++ operator overloading
		REALLY_INLINE operator T() const { return t; }

		// let us peek at it without a cast
		REALLY_INLINE T value() const { return t; }

		REALLY_INLINE operator ZeroPtr<T>() const { return t; }

		REALLY_INLINE bool operator!=(T other) const { return other != t; }

		REALLY_INLINE T operator->() const
		{
			return t;
		}

	private:
		// Private constructor to prevent its use and someone adding it, GCC creates
		// WriteBarriers on the stack with it
		WriteBarrier(const WriteBarrier<T>& toCopy);	// unimplemented
		
		T t;
	};

	/**
	 * WriteBarrierRC is a write barrier for naked (not pointer swizzled) RC objects.
	 * the only thing going in and out of the slot is NULL or a valid RCObject
	 */
	template<class T> class WriteBarrierRC
	{
	private:
		// Always pay for a single real function call; then inline & optimize massively in WriteBarrierRC()
		REALLY_INLINE 		
		T set(const T tNew)
		{
			GC::WriteBarrierRC(&t, (const void*)tNew);	// updates 't'
			return tNew;
		}
		
	public:
		explicit REALLY_INLINE WriteBarrierRC() : t(0) 
		{
		}
		
		explicit REALLY_INLINE WriteBarrierRC(T _t) : t(0)
		{ 
			set(_t);
		}

		REALLY_INLINE ~WriteBarrierRC() 
		{
			if(t != 0) {
				((RCObject*)t)->DecrementRef();
				t=0;
			}
		}

		REALLY_INLINE T operator=(const WriteBarrierRC<T>& wb)
		{
			return set(wb.t);	
		}

		REALLY_INLINE T operator=(T tNew)
		{
			return set(tNew);
		}

		REALLY_INLINE operator T() const { return t; }

		REALLY_INLINE operator ZeroPtr<T>() const { return t; }

		REALLY_INLINE bool operator!=(T other) const { return other != t; }

		REALLY_INLINE T operator->() const
		{
			return t;
		}

		REALLY_INLINE void Clear() { t = 0; }
	private:
		// Private constructor to prevent its use and someone adding it, GCC creates
		// WriteBarrierRCs on the stack with it
		WriteBarrierRC(const WriteBarrierRC<T>& toCopy);
		
		T t;
	};
}

#endif // _WRITE_BARRIER_H_
