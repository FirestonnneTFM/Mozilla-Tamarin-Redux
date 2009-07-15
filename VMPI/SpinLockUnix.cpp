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

#include <pthread.h>

#if defined(__GNUC__) && (defined(MMGC_IA32) || defined(MMGC_AMD64))

void VMPI_lockInit(vmpi_spin_lock_t *lock)
{
	*(volatile int*)lock = 0;
	__asm__ volatile("" : : : "memory");
}

void VMPI_lockDestroy(vmpi_spin_lock_t *lock)
{
	*(volatile int*)lock = 0;
	__asm__ volatile("" : : : "memory");
}

inline int X86_TestAndSet(volatile int *ptr, int val) {
	__asm__ volatile("xchgl %0, (%2)" :"=r"(val) : "0"(val), "r"(ptr));
	return val;
}

inline void X86_Pause(void)
{
	__asm__ volatile("pause");
}

bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
	while ( X86_TestAndSet((volatile int*)lock, 1) != 0 ) {
		X86_Pause();
	}
	__asm__ volatile("" : : : "memory");
	
	return true;
}

bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
	__asm__ volatile("" : : : "memory");
	*(volatile int*)lock = 0;
	
	return true;
}

bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
	__asm__ volatile("" : : : "memory");
	if(X86_TestAndSet((volatile int*)lock, 1) != 0)
		return false;
	return true;
}

#elif defined (USE_PTHREAD_MUTEX) //defined(MMGC_IA32) || defined(MMGC_AMD64)

void VMPI_lockInit(vmpi_spin_lock_t lock)
{
	pthread_mutex_init( (pthread__t*)lock, 0 );
}

void VMPI_lockDestroy(vmpi_spin_lock_t *lock)
{
	pthread_mutex_destroy( (pthread_mutex_t*)lock );
}

bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
	return pthread_mutex_lock( (pthread_mutex_t*)lock ) == 0;
}

bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
	return pthread_mutex_unlock( (pthread_mutex_t*)lock ) == 0;
}

bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
	return pthread_mutex_trylock( (pthread_mutex_t*)lock ) == 0;
}

#else //defined(MMGC_IA32) || defined(MMGC_AMD64)


void VMPI_lockInit(vmpi_spin_lock_t lock)
{
	pthread_spin_init( (pthread_spinlock_t*)lock, 0 );
}

void VMPI_lockDestroy(vmpi_spin_lock_t *lock)
{
	pthread_spin_destroy( (pthread_spinlock_t*)lock );
}

bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
	return pthread_spin_lock( (pthread_spinlock_t*)lock ) == 0;
}

bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
	return pthread_spin_unlock( (pthread_spinlock_t*)lock ) == 0;
}

bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
	return pthread_spin_trylock( (pthread_spinlock_t*)lock ) == 0;
}

#endif //defined(MMGC_IA32) || defined(MMGC_AMD64)
