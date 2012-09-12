/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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


#ifndef CONCURRENCYGLUE_INCLUDED
#define CONCURRENCYGLUE_INCLUDED

#if defined(DEBUG)
#define DEBUG_CONDITION_MUTEX
#endif // DEBUG


namespace avmplus {


#if defined(DEBUG_CONDITION_MUTEX)
    #define DEBUG_STATE(_x_) do { AvmLog _x_; } while(0)
#else
    #define DEBUG_STATE(_x_) do { } while(0)
#endif

    //
    // Mutexes in ActionScript are composed of a OS level
    // vmpi condition and vmpi mutex. this composition is 
    // created to allow easy interrupt of a blocked isolate 
    // to support script timeout, flashbuilder and fdb debugger 
    // call stack aquisition for a blocked isolate thread, termination, 
    // and the ability to add aid for deadlock detection. this data
    // can be sent over the debugger protocol allowing for 
    // more sophisticated IDEs to provide helpful UI.
    // 
    class GC_AS3_EXACT(MutexObject, ScriptObject)
    {
    public:
        MutexObject(VTable* vtbl, ScriptObject* delegate);
        virtual ~MutexObject();
        void lock();
        bool tryLock();
        void unlock();
        void ctor();
		ChannelItem* makeChannelItem();
        
        class State;
		
    private:
        friend class ConditionObject;

        GC_NO_DATA(MutexObject)
        DECLARE_SLOTS_MutexObject;
        FixedHeapRef<State> m_state;
    };
    
    //
    // Conditions in ActionScript are also composed of a OS level
    // vmpi condition and vmpi mutex. this composition is 
    // created to allow easy interrupt of a blocked isolate 
    // to support script timeout, flashbuilder and fdb debugger 
    // call stack aquisition for a blocked isolate thread, termination, 
    // and the ability to add aid for deadlock detection. this data
    // can be sent over the debugger protocol allowing for 
    // more sophisticated IDEs to provide helpful UI.
    // 
    class GC_AS3_EXACT(ConditionObject, ScriptObject)
    {
    public:
        ConditionObject(VTable* vtbl, ScriptObject* delegate);
        virtual ~ConditionObject();

        GCRef<MutexObject> get_mutex();
        
        void ctor(GCRef<MutexObject> mutex);
        bool wait(double timeout);
        void notify();
        void notifyAll();

		ChannelItem* makeChannelItem();
        
        class State;

    private:
        friend class MutexObject;

        GC_DATA_BEGIN(ConditionObject)
        GCMember<MutexObject> m_mutex;
        GC_DATA_END(ConditionObject)
        FixedHeapRef<State> m_state;
        
        DECLARE_SLOTS_ConditionObject;
    };

    //
    // this stores the state of the ActionScript Mutex 
    // object with a reference count.  this is done to allow
    // ActionScript Mutex objects to be passed between
    // isolates allowing multiple isolates to use the same
    // OS level Mutex for coordination.
    // 
    // InterruptibleState manages the list of WaitRecords
    // for this Mutex allowing blocking operations like lock()
    // to be interrupted for termination, debugging, or script timeout
    //
    class MutexObject::State: public FixedHeapRCObject
    {
    public:
        State();
        virtual void destroy();
        bool tryLock();
        void lock(AvmCore* core);
        bool unlock();

    private:
        friend class MutexObject;
        friend class ConditionObject;
        friend class ConditionObject::State;
        bool internalTryLock();
        // manages list of threads waiting for 
        // the lock, this is a FIFO list for acquisition
        // first one waiting on the lock gets it when it
        // is unlocked.
        struct LockWaitRecord
        {
            LockWaitRecord() 
                : next(NULL)
#ifdef DEBUG_CONDITION_MUTEX
                , threadID(VMPI_currentThread())
#endif // DEBUG_CONDITION_MUTEX
            {}

            LockWaitRecord* next;
#ifdef DEBUG_CONDITION_MUTEX
            vmpi_thread_t threadID;
#endif // DEBUG_CONDITION_MUTEX
        };

        REALLY_INLINE void lockAquired()
        {
            DEBUG_STATE(("thread %d acquired Mutex(%d)\n", VMPI_currentThread(), m_interruptibleState.gid));
            if (m_recursionCount == 0) {
                AvmAssert(m_ownerThreadID == VMPI_nullThread());
                m_ownerThreadID = VMPI_currentThread(); 
            } else {
                AvmAssert(m_ownerThreadID == VMPI_currentThread());
            }
            m_recursionCount++;
        }

        vmpi_mutex_t m_mutex;

        // recursionCount keeps track of the number of times that
        // Mutex.lock was called. Mutex.unlock needs to be called
        // that same number of times. large storage is used here
        // to try and avoid wrap around.
        int64_t m_recursionCount; 

        // keeps track of the thread that currently holds the lock
        // and is used to report programming errors back to 
        // actionscript developers.
        vmpi_thread_t volatile m_ownerThreadID;

        // when a thread attempts to acquire this mutex and fails
        // it will be placed into a FIFO wait list. the following 
        // two members help to manage that list.
        LockWaitRecord* m_lockWaitListHead;
        LockWaitRecord* m_lockWaitListTail;

        // keeps track of the success of initializing the vmpi_mutex_t
        // this value is then used to throw an Error in actionscript
        // indicating that the mutex could not be initialized.
        // additionally, if the platform does not support workers
        // this will be set to invalid during initialization, again causing
        // actionscript to throw an Error. 
        bool m_isValid;

        // any primitive like Mutex and Condition that have blocking
        // behavior need to be interruptible to allow for script timeout,
        // termination, and debugging call stack acquisition. 
        // Mutex uses an InterruptibleState when a blocking operation,
        // like waiting on Mutex.lock aquisition, needs to be performed.
        InterruptibleState m_interruptibleState;
    };
    
    //
    // this stores the state of the ActionScript Condition 
    // object with a reference count.  this is done to allow
    // ActionScript Condition objects to be passed between
    // isolates allowing multiple isolates to use the same
    // OS level condition for coordination.
    // 
    // InterruptableState manages the list of WaitRecords
    // for this Condition allowing blocking operations like wait()
    // to be interrupted for termination, debugging, or script timeout
    //
    class ConditionObject::State: public FixedHeapRCObject
    {
    public:
        State(MutexObject::State* mutexState);
        bool wait(int32_t millis, Isolate* isolate, Toplevel* toplevel);
        virtual void destroy();

    private:
        friend class ConditionObject;

        FixedHeapRef<MutexObject::State> m_mutexState;
        InterruptibleState m_interruptibleState;
    };
    
    class GC_AS3_EXACT(MutexClass, ClassClosure)
    {
    public:
        MutexClass(VTable* cvtable);
        bool isSupported();
    private:
        GC_NO_DATA(MutexClass)
        DECLARE_SLOTS_MutexClass;
    };

    
    class GC_AS3_EXACT(ConditionClass, ClassClosure)
    {
    public:
        ConditionClass(VTable* cvtable);
        bool isSupported();
    private:
        GC_NO_DATA(ConditionClass)
        DECLARE_SLOTS_ConditionClass;
    };

    //
    // This class provides a place to hang the memory fence and 
    // compare and swap functions so they can be called from 
    // ActionScript.
    // 
    class ConcurrentMemory
    {
    private:
        explicit ConcurrentMemory(); // never construct

    public:
        static void mfence(ScriptObject *obj);
        static int32_t casi32(ScriptObject *obj, int32_t addr, int32_t expectedVal, int32_t newVal);
    };

}




#endif
