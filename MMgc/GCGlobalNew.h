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

#ifndef __GCGLOBALNEW__
#define __GCGLOBALNEW__

#ifdef MMGC_ENABLE_CPP_EXCEPTIONS
#include <new>
#define NEW_THROWS_CLAUSE throw (std::bad_alloc)
#define DELETE_THROWS_CLAUSE throw ()
#else
#define NEW_THROWS_CLAUSE 
#define DELETE_THROWS_CLAUSE 
#endif

// User-defined operator new.
REALLY_INLINE void *operator new(size_t size) NEW_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	void *space = VMPI_alloc(size);
	MMgc::GCHeap::TrackSystemAlloc(space, size);
	return space;
#else
	GCAssertMsg(MMgc::GCHeap::GetGCHeap()->StackEnteredCheck(), "MMGC_ENTER macro must exist on the stack");
	return MMgc::FixedMalloc::GetFixedMalloc()->Alloc(size);
#endif
}
       
REALLY_INLINE void *operator new[](size_t size) NEW_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	void *space = VMPI_alloc(size);
	MMgc::GCHeap::TrackSystemAlloc(space, size);
	return space;
#else
	GCAssertMsg(MMgc::GCHeap::GetGCHeap()->StackEnteredCheck(), "MMGC_ENTER macro must exist on the stack");
	return MMgc::FixedMalloc::GetFixedMalloc()->Alloc(size);
#endif
}
       
// User-defined operator delete.
REALLY_INLINE void operator delete( void *p) DELETE_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	MMgc::GCHeap::TrackSystemFree(p);
	VMPI_free(p);
#else
	MMgc::FixedMalloc::GetFixedMalloc()->Free(p);
#endif
}
       
REALLY_INLINE void operator delete[]( void *p ) DELETE_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	MMgc::GCHeap::TrackSystemFree(p);
	VMPI_free(p);
#else
	MMgc::FixedMalloc::GetFixedMalloc()->Free(p);
#endif
}

#ifdef MMGC_ENABLE_CPP_EXCEPTIONS
#undef NEW_THROWS_CLAUSE
#undef DELETE_THROWS_CLAUSE
#endif

#endif // __GCGLOBALNEW__
