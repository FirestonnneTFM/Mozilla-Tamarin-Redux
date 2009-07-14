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

#ifndef __GCStack__
#define __GCStack__

namespace MMgc
{	
	// Optimize the number of elements in a mark stack segments for GCStack<GCWorkItem>.  
	// Each GCWorkItem is two words.  There's a one-word overhead in the segment data
	// structure, and on a 32-bit system there's one word of alignment.  Ergo we have
	// space for (4k-8)/2w items in a block, where w(ordsize) is 4 or 8.  (FixedMalloc 
	// does not add further overhead in Release builds.)
#ifdef AVMPLUS_64BIT
	enum { kDefaultMarkStackItems=255 };
#else
	enum { kDefaultMarkStackItems=511 };
#endif

	// Invariant: m_topSegment, m_base, m_top, and m_limit are never NULL following construction.
	// Invariant: m_base <= m_top <= m_limit
	// Invariant: m_base == m_topSegment->m_items
	// Invariant: m_limit == m_topSegment->m_items + kMarkStackItems
	
	template<typename T, int kMarkStackItems=kDefaultMarkStackItems>
	class GCStack
	{
	public:
		GCStack();
		~GCStack();

		/** 
		 * Push 'item' onto the stack. 
		 * @return true if the item could be pushed, false if the system
		 *		   is out of memory and the item was not pushed.
		 */
		bool Push(T item);

		/**
		 * Pop one item off the stack.  Precondition: The stack must not be empty.
		 * @return the popped element.
		 */
		T Pop();

		/**
		 * @return the top element.  
		 * Precondition: The stack must not be empty.
		 */
		T Peek();

		/** @return the number of elements on the stack. */
		uint32_t Count();

		/** Pop all elements off the stack, discard the cached extra segment. */
		void Clear();

		/** @return the number of elements in a segment */
		uint32_t ElementsPerSegment();
	
		/** @return the number of entirely full segments */
		uint32_t EntirelyFullSegments();

		/** Move one entirely full segment from 'other' and insert it into our segment list */
		void TransferOneFullSegmentFrom(GCStack<T, kMarkStackItems>& other);

	protected:
		// no implementation of these
		GCStack(const GCStack<T, kMarkStackItems>& other);
		GCStack<T, kMarkStackItems>& operator=(const GCStack<T, kMarkStackItems>& other);

	private:
		
		struct GCStackSegment
		{
			T				m_items[kMarkStackItems];
			GCStackSegment* m_prev;
		};
		
		T*					m_base;			// first entry in m_topSegment
		T*					m_top;			// first free entry in m_topSegment
		T*					m_limit;		// first entry following m_topSegment
		GCStackSegment*	    m_topSegment;	// current stack segment, older segments linked through 'prev'
		uint32_t			m_hiddenCount;	// number of elements in those older segments
		GCStackSegment*		m_extraSegment;	// single-element cache used to avoid hysteresis

		/**
		 * The current segment must be NULL or full (top == limit).  Push a new segment onto the 
		 * stack, and update all instance vars.
		 * @return true if the segment could be pushed or false if not (if it could not be allocated).
		 */
		bool PushSegment();
		
		// The current segment is discarded and the previous segment, if any, reinstated.
		// Update all instance vars.
		void PopSegment();
	};
	
	template<typename T, int kMarkStackItems> 
	inline bool GCStack<T, kMarkStackItems>::Push(T item)
	{
		if (m_top == m_limit) 
			if (!PushSegment())
				return false;
		GCAssert(m_top < m_limit);
		*m_top++ = item;
		return true;
	}
	
	template<typename T, int kMarkStackItems> 
	inline T GCStack<T, kMarkStackItems>::Pop()
	{
		GCAssert(m_top > m_base);
		T t = *--m_top;
#ifdef _DEBUG
		VMPI_memset(m_top, 0, sizeof(T));
#endif
		if (m_top == m_base)
			if (m_topSegment->m_prev != NULL)
				PopSegment();
		return t;
	}
	
	template<typename T, int kMarkStackItems> 
	inline T GCStack<T, kMarkStackItems>::Peek()
	{
		GCAssert(m_top > m_base);
		return *(m_top-1);
	}
	
	template<typename T, int kMarkStackItems> 
	inline uint32_t GCStack<T, kMarkStackItems>::Count()
	{
		return uint32_t(m_top - m_base) + m_hiddenCount;
	}

	template<typename T, int kMarkStackItems> 
	inline uint32_t GCStack<T, kMarkStackItems>::ElementsPerSegment()
	{
		return kMarkStackItems;
	}

	template<typename T, int kMarkStackItems>
	uint32_t GCStack<T, kMarkStackItems>::EntirelyFullSegments()
	{
		return Count() / kMarkStackItems;
	}
}

#endif /* __GCStack__ */
