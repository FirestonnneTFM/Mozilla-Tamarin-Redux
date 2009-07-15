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

//#define TESTING_MARKSTACK
#define MARKSTACK_ALLOWANCE  1

#ifndef MMGC_ENABLE_CPP_EXCEPTIONS
inline void* operator new(size_t, void* p) { return p; }
#endif

namespace MMgc
{
#ifdef TESTING_MARKSTACK
	static int markstack_allowance = MARKSTACK_ALLOWANCE;
#endif

	static inline void* AllocStackSegment(size_t nbytes)
	{
#ifdef TESTING_MARKSTACK
		if (markstack_allowance == 0)
			return NULL;
		--markstack_allowance;
#endif
		nbytes = (nbytes + 4095) & ~4095;
		return FixedMalloc::GetInstance()->PleaseAlloc(nbytes);
	}

	static inline void FreeStackSegment(void* p)
	{
#ifdef TESTING_MARKSTACK
		++markstack_allowance;
#endif
		FixedMalloc::GetInstance()->Free(p);
	}
	
	template<typename T, int kMarkStackItems>
	GCStack<T, kMarkStackItems>::GCStack()
		: m_base(NULL)
		, m_top(NULL)
		, m_limit(NULL)
		, m_topSegment(NULL)
		, m_hiddenCount(0)
		, m_extraSegment(NULL)
	{
		PushSegment();
	}

	template<typename T, int kMarkStackItems>
	GCStack<T, kMarkStackItems>::~GCStack()
	{
		while (m_topSegment != NULL)
			PopSegment();
		if (m_extraSegment)
			FreeStackSegment(m_extraSegment);
	}

	template<typename T, int kMarkStackItems>
	void GCStack<T, kMarkStackItems>::Clear()
	{
		// Clear out the elements
		while (m_topSegment->m_prev != NULL)
			PopSegment();
		m_top = m_base;

		// Discard the cached segment
		if (m_extraSegment != NULL) {
			FreeStackSegment(m_extraSegment);
			m_extraSegment = NULL;
		}
	}

	template<typename T, int kMarkStackItems> 
	bool GCStack<T, kMarkStackItems>::PushSegment()
	{
		GCAssert(sizeof(GCStackSegment) <= 4096);
		GCAssert(m_top == m_limit);
		if (m_extraSegment == NULL) {
			void *memory = AllocStackSegment(sizeof(GCStackSegment));
			if (memory == NULL)
				return false;
			m_extraSegment = new (memory) GCStackSegment();
		}
		if (m_topSegment != NULL)
			m_hiddenCount += kMarkStackItems;
		GCStackSegment* seg = m_extraSegment;
		m_extraSegment = NULL;
		seg->m_prev = m_topSegment;
		m_topSegment = seg;
		m_base = m_topSegment->m_items;
		m_limit = m_base + kMarkStackItems;
		m_top = m_base;
		return true;
	}

	template<typename T, int kMarkStackItems>
	void GCStack<T, kMarkStackItems>::PopSegment()
	{
		m_hiddenCount -= kMarkStackItems;
		GCStackSegment* seg = m_topSegment;
		m_topSegment = seg->m_prev;
		m_base = m_topSegment->m_items;
		m_limit = m_base + kMarkStackItems;
		m_top = m_limit;
		if (m_extraSegment == NULL) {
			seg->m_prev = NULL;
			m_extraSegment = seg;
		}
		else
			FreeStackSegment(seg);
	}

	template<typename T, int kMarkStackItems>
	void GCStack<T, kMarkStackItems>::TransferOneFullSegmentFrom(GCStack<T, kMarkStackItems>& other)
	{
		GCAssert(other.EntirelyFullSegments() > 0);
		GCStackSegment* seg;

		if (other.m_topSegment->m_prev == NULL) {
			// Picking off the only segment
			seg = other.m_topSegment;
			other.m_topSegment = NULL;
			other.m_top = NULL;
			other.m_limit = NULL;
			other.PushSegment();
		}
		else {
			// Picking off the one below the top always
			seg = other.m_topSegment->m_prev;
			other.m_topSegment->m_prev = seg->m_prev;
			other.m_hiddenCount -= kMarkStackItems;
		}

		// Insert it below our top segment
		seg->m_prev = m_topSegment->m_prev;
		m_topSegment->m_prev = seg;
		m_hiddenCount += kMarkStackItems;

		// Special case that occurs if a segment was inserted into an empty stack.
		if (m_top == m_base)
			PopSegment();
	}

	// Visual C++ 2008 requires the copy constructor and assignment operator to be present
	// for the explicit template instantiation below to work; GCC doesn't.  But GCC requires
	// the explicit template instantiation.
	//
	// (Neither function is ever called.)
	template<typename T, int kMarkStackItems>
	GCStack<T, kMarkStackItems>::GCStack(const GCStack<T, kMarkStackItems>& other)
	{
		(void)other;
		GCAssert(!"Copy constructor");
	}

	template<typename T, int kMarkStackItems>
	GCStack<T, kMarkStackItems>& GCStack<T, kMarkStackItems>::operator=(const GCStack<T, kMarkStackItems>& other)
	{
		(void)other;
		GCAssert(!"Assignment operator");
		return *(GCStack<T, kMarkStackItems>*)this;
	}

	template class GCStack<GCWorkItem>;
}
