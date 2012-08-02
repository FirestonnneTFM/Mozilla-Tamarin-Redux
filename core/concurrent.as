/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

package flash.concurrent 
{

import flash.errors.IllegalOperationError;
include "api-versions.as"

/**
 * A Mutex is an object that facilitates "mutual exclusion"
 * of competing threads of execution in critical sections.
 *
 * At any given time there can be at most one thread of execution
 * which has ownership of a given mutex.
 * Transitions between who owns a mutex and who does not are always atomic.
 * The methods of this class are such that a critical section can be guarded
 * by acquiring and then releasing a mutex at its boundaries.
 *
 * Every new running worker contains at least one new thread of execution.
 * Mutexes treat all threads the same, irrespective of the workers they are in.
 * Thus mutexes can be used to control concurrency between workers as a whole
 * as well as threads within and across them.
 *
 * When a mutex is transported to another worker via an argument of a 
 * MessageChannel call or via Worker.setSharedProperty()
 * then the remote copy of the mutex will continue to use
 * the identical underlying lock handling data structures.
 * This makes the original mutex effectively shared between workers,
 * which can thus create critical sections that exclude each other.
 *
 * Note that locking and unlocking are not lexically paired.
 * Also note that these mutexes are recursive,
 * i.e. repeated locking increases an internal lock count
 * and only an equal amount of unlock calls finally releases a mutex.
 * Otherwise it stays locked.
 *
 * Any attempt to unlock a mutex that is not owned by the caller throws an error.
 *
 * @langversion 3.0
 * @playerversion Flash 11.4	
 * @playerversion AIR 3.4
 */
[API(CONFIG::SWF_17)]
[native(cls="MutexClass",instance="MutexObject",gc="exact")]
final public class Mutex
{
    /**
     * The constructor for mutexes.
     *
     * The initial internal lock count of every new mutex is zero.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public function Mutex()
    {
        ctor();
    }

    /**
     * Wait until this mutex is available and then take exclusive ownership,
     * increase the mutex's lock count by one, and proceed.
     * This is also known as "acquiring" this mutex.
     *
     * If a thread already owns a mutex when this call is made to lock it,
     * then its internal lock count is increased and no other action occurs.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public native function lock() :void

    /**
     * Attempt to acquire ownership of this mutex.
     *
     * If and only if the mutex is available, acquire it,
     * increase its lock count, and immediately return true.
     * Otherwise, do not acquire the mutex and immediately return false.
     * Do all of the above atomically.
     *
     * If the mutex is already owned by the current thread/worker,
     * the lock count is increased and no other action occurs.
     *
     * @return true if the lock was acquired, false otherwise.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public native function tryLock() :Boolean;

    /**
     * Release ownership of this mutex,
     * allowing any thread/worker to acquire it and proceed.
     *
     * This mutex must be locked and owned by the current thread/worker.
     * Otherwise an error is thrown.
     *
     * @throws IllegalOperationException when the current thread doesn't own the mutex.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    native public function unlock():void;

    private native function ctor() :void;
}
    
/**
 * A Condition (aka condition variable) is a synchronization primitive that facilitates
 * making threads of execution wait until a particular condition occurs.
 *
 * A condition is always associated with a mutex.
 * It can only be manipulated in conjunction with that mutex.
 * This ensures atomic state transitions for all involved threads of execution.
 *
 * @langversion 3.0
 * @playerversion Flash 11.4	
 * @playerversion AIR 3.4
 */
[API(CONFIG::SWF_17)]
[native(cls="ConditionClass",instance="ConditionObject",gc="exact")]
final public class Condition 
{
    /**
     * The constructor for condition variables.
     *
     * @param mutex the mutex associated with the condition
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public function Condition(mutex:Mutex)
    {
        if (mutex == null)
        	Error.throwError(ArgumentError, kNullPointerError, "mutex");
        ctor(mutex);
    }

    /**
     * Provides readonly access to mutex associated with this condition
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
     public native function get mutex():Mutex;


    /**
     * Releases the condition's mutex and then suspends the current thread/worker
     * until it is awoken by 'notify()' or 'notifyAll()'. If the mutex is owned recursively,
     * the recursion count will be restored upon return from wait.
     *
     * The current thread/worker must "own" the condition's mutex when making this call.
     * Otherwise an exception is thrown and the mutex and the condition remain unaffected.
     * @throws IllegalOperationException when the mutex is not owned by the current thread.
     * @param timeout timeout in milliseconds, -1 if no timeout, fractional values will be rounded up to the nearest millisecond.
     * @return false if wait() returned due to timeout, otherwise true.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public function wait(timeout:Number = -1) :Boolean
    {
        if (timeout < 0 && timeout != -1) {
            Error.throwError(ArgumentError, kConditionInvalidTimeoutError);
        }
        return waitImpl(Math.ceil(timeout));
    }

    /**
     * Wakes up one of the threads/workers waiting on this condition, if any, 
     * and releases its mutex.
     * The awoken thread/worker acquires the mutex and then starts executing.
     * All of the above happens atomically.
     *
     * The current thread/worker must "own" the condition's mutex when making this call.
     * Otherwise an exception is thrown and the mutex and the condition remain unaffected.
     * @throws IllegalOperationError if the condition's mutex is not owned by the current thread.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public function notify() :void
    {
        if (!notifyImpl()) {
        	Error.throwError(IllegalOperationError, kConditionCannotNotifyError);
        }
    }

    /**
     * Wakes up all threads/workers waiting on this condition, and releases its mutex.
     * If any threads have been waiting, then one of them acquires the mutex and then 
     * starts executing.
     * All of the above happens atomically.
     *
     * The awoken threads acquire the mutex and proceed one by one, in wait order.
     * Each thread continues to wait until its predecessor releases the mutex
     * (by calling Mutex.unlock or Condition.wait().
     *
     * The current thread/worker must "own" the condition's mutex when making this call.
     * Otherwise an exception is thrown and the mutex and the condition remain unaffected.
     * @throws IllegalOperationError if the condition's mutex is not owned by the current thread.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
    public function notifyAll() :void
    {
        if (!notifyAllImpl()) {
        	Error.throwError(IllegalOperationError, kConditionCannotNotifyAllError);
        }
    }

    private native function ctor(mutex:Mutex) :void;
    private native function notifyImpl() :Boolean;
    private native function notifyAllImpl() :Boolean;
    private native function waitImpl(timeout:Number) :int;

	private static const kNullPointerError:uint = 2007;
	private static const kConditionInvalidTimeoutError:uint = 1415;
	private static const kConditionCannotNotifyError:uint = 1516;
	private static const kConditionCannotNotifyAllError:uint = 1517;
}
}

package avm2.intrinsics.memory
{
    /**
     * A complete memory barrier for domainMemory (for both load and store instructions).
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
	[API(CONFIG::SWF_17)]
	[native("ConcurrentMemory::mfence")]
	public native function mfence():void;
    /**
     * A compare and swap for domainMemory.
     * Behaves like ByteArray.atomicCompareAndSwapIntAt but operates on the current domainMemory.
     *
     * @langversion 3.0
     * @playerversion Flash 11.4	
     * @playerversion AIR 3.4
     */
	[API(CONFIG::SWF_17)]
	[native("ConcurrentMemory::casi32")]
	public native function casi32(addr:int, expectedVal:int, newVal:int):int;
}

