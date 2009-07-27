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

#ifndef __GCZCT__
#define __GCZCT__

namespace MMgc
{

	/**
	 * The Zero Count Table used by DRC.
	 */
	class ZCT
	{
	public:
		ZCT();
		void Destroy();
		
		// Associate the ZCT with 'gc' and perform final initialization of the ZCT.  To be 
		// called exactly once after the GC has been properly constructed: SetGC() uses
		// 'gc' to allocate memory.
		void SetGC(GC* gc);
		
		// Add obj to the ZCT; it must not already be in the ZCT.  This method can fail silently,
		// leaving the GC to reap the object in case its reference count stays zero.
		void Add(RCObject *obj REFCOUNT_PROFILING_ARG(bool initial=false));

		// Remove obj from the ZCT; it must already be in the ZCT.
		void Remove(RCObject *obj REFCOUNT_PROFILING_ARG(bool final=false));

		// Reap the ZCT: destroy every object in the ZCT that is not referenced from the
		// calling thread's stack or specially marked stack-like data structures in the GC
		// (see GC::allocaPush() and associated code).
		void Reap(bool scanStack=true);

		// Throw away unused memory (discretionary); to be called at the end of a GC.
		void Prune();
		
		bool IsReaping()
		{
			return reaping;
		}

	private:
		// @return the number of elements the table can accomodate
		int Capacity();

		// @return true iff the table can grow by at least one more block.
		bool CanGrow();
		
		// @return true iff the free list is not empty (and it's OK to call GrabFree)
		bool HasFree();

		// @return the next element off the free list
		int GrabFree();
	
		// Add the element at 'index' to the free list
		void MakeFree(int index);

		// @return the value stored at 'index'
		RCObject* Get(int index);

		// Store 'value' at 'index'
		void Put(int index, RCObject* value);

		// @return the block number for 'index'
		int BlockNumber(int index);

		// @return the entry within a block for 'index'
		int EntryNumber(int index);
		
		// @return the address corresponding to ZCT offset 'index'
		RCObject** PointerTo(int index);
		
		// If CanGrow is true, add a block of memory to the zct.  This may fail to
		// allocate that block; failure is silent but reflected in Capacity returning
		// the same value before and after the call.
		void Grow();

		// Conservatively scan memory starting at 'start' for 'len' bytes, examining each
		// aligned word.  If the value stored can be interpreted as a (possibly tagged)
		// pointer to the start of an RCObject, then pin that RCObject.  The value of
		// 'start' must itself be aligned.
		void PinStackObjects(const void *start, size_t len);

		// Private data

		GC *gc;
		RCObject ***blocktable;		// Table of pointers to individual blocks
		RCObject ***blocktop;		// Next free item in blocktable
		int freelist;				// index of first free element (element holds index of next free, or -1)
		bool reaping;				// are we reaping the zct?
		int count;					// table population in number of live elements
		int zctNext;				// index of first free element at the end
		int zctReapThreshold;		// if count reaches this then we reap
		int zctIndex;				// during a reap: next element to process (stepping up)
		int nextPinnedIndex;		// during a reap: next free slot for pinned elements (stepping up)
	};
}

#endif /* __GCZCT__ */
