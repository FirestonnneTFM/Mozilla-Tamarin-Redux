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

// This is a copy from Unix code.
// TODO: implement on S60

/*
Threads and hybrid applications

The pthread and RThread APIs do not mix. Symbian OS heaps are managed thread-wise whereas P.I.P.S. heaps are managed process-wise. Mixing pthread and RThread may result in panics due to data being lost or orphaned. So, do not mix the two unless you know what you're doing.

User libraries or executables written using P.I.P.S. must not allocate resources in the context of the calling thread as the thread might be using a private heap which is inaccessible to other threads and might have a different lifetime.

To minimise the risks avoid using RThread APIs in primarily POSIX applications or libraries (those entering via main()), and avoid using pthread in primarily Symbian OS applications or libraries (those entering via E32Main()).

http://developer.symbian.com/main/documentation/sdl/symbian94/sdk/doc_source/guide/P.I.P.S.-subsystem-guide/PIPS/UsingPIPSForYourApps/HybridApps.html
*/

//#include <pthread.h>

class SpinLockSymbian : public MMgc::GCAllocObject
{
public:

#if defined(USE_PTHREAD_MUTEX)

	SpinLockSymbian()
	{
//		pthread_mutex_init( &m1, 0 );
	}

	~SpinLockSymbian()
	{
//		pthread_mutex_destroy( &m1 );
	}

	inline bool Acquire()
	{
		return true;
//		return pthread_mutex_lock( &m1 ) == 0;
	}
	
	inline bool Release()
	{
		return true;
//		return pthread_mutex_unlock( &m1 ) == 0;
	}

private:
	pthread_mutex_t m1;

#else // USE_PTHREAD_MUTEX

	SpinLockSymbian()
	{
//		pthread_spin_init( &m1, 0 );
	}

	~SpinLockSymbian()
	{
//		pthread_spin_destroy( &m1 );
	}

	inline bool Acquire()
	{
		return true;
//		return pthread_spin_lock( &m1 ) == 0;
	}
	
	inline bool Release()
	{
		return true;
//		return pthread_spin_unlock( &m1 ) == 0;
	}

	inline bool Try()
	{
		return true;
	}

private:
//	pthread_spinlock_t m1;

#endif
};

vmpi_spin_lock_t VMPI_lockCreate()
{
	return (vmpi_spin_lock_t) (new SpinLockSymbian);
}

void VMPI_lockDestroy(vmpi_spin_lock_t lock)
{
	delete (SpinLockSymbian*)lock;
}

bool VMPI_lockAcquire(vmpi_spin_lock_t lock)
{
	return ((SpinLockSymbian*)lock)->Acquire();
}

bool VMPI_lockRelease(vmpi_spin_lock_t lock)
{
	return ((SpinLockSymbian*)lock)->Release();
}

bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t lock)
{
	return ((SpinLockSymbian*)lock)->Try();
}
