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

namespace avmplus {

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
        friend class ConditionObject;
        friend class Isolate;

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
        friend class MutexObject;
    public:
        ConditionObject(VTable* vtbl, ScriptObject* delegate);
        virtual ~ConditionObject();

        GCRef<MutexObject> get_mutex();
        
        void ctor(GCRef<MutexObject> mutex);
        bool waitImpl(double timeout);
        bool notifyImpl();
        bool notifyAllImpl();

		ChannelItem* makeChannelItem();
        
        class State;

		
    private:
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
    // InterruptableState manages the list of WaitRecords
    // for this Mutex allowing blocking operations like lock()
    // to be interrupted for termination, debugging, or script timeout
    //
    class MutexObject::State: public InterruptableState
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
        // manages list of threads waiting for 
        // the lock, this is a FIFO list for acquisition
        // first one waiting on the lock gets it when it
        // is unlocked.
        struct LockWaitRecord
        {
            LockWaitRecord() 
                : next(NULL)
#ifdef DEBUG
                , threadID(VMPI_currentThread())
#endif // DEBUG
            {}

            LockWaitRecord* next;
#ifdef DEBUG
            vmpi_thread_t threadID;
#endif // DEBUG
        };

        vmpi_mutex_t m_mutex;
        int64_t m_recursion_count; // generous to avoid wraparound.
        vmpi_thread_t volatile m_ownerThreadID;
        LockWaitRecord* m_lockWaitListHead;
        LockWaitRecord* m_lockWaitListTail;
        bool m_isValid;
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
    class ConditionObject::State: public InterruptableState
    {
        friend class ConditionObject;
        FixedHeapRef<MutexObject::State> m_mutexState;

        
    public:
        State(MutexObject::State* mutexState);
        bool wait(int32_t millis, Isolate* isolate, Toplevel* toplevel);
        virtual void destroy();
    };
    
    class GC_AS3_EXACT(MutexClass, ClassClosure)
    {
    public:
        MutexClass(VTable* cvtable);
    private:
        GC_NO_DATA(MutexClass)
        DECLARE_SLOTS_MutexClass;
    };

    
    class GC_AS3_EXACT(ConditionClass, ClassClosure)
    {
    public:
        ConditionClass(VTable* cvtable);
    private:
        GC_NO_DATA(ConditionClass)
        DECLARE_SLOTS_ConditionClass;
    };

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
