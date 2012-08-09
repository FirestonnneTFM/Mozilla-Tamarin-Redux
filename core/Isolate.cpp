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

#include "avmplus.h"

#include "FixedHeapUtils.cpp"
#include "Channels.cpp"

namespace avmplus
{

#define DEBUG_INTERRUPTABLE_STATE
#if defined(DEBUG) && defined(DEBUG_INTERRUPTABLE_STATE)
    #define DEBUG_STATE(_x_) do { AvmLog _x_; } while(0)
#else
    #define DEBUG_STATE(_x_) do { } while(0)
#endif


    Isolate* Aggregate::Globals::at(int32_t giid)
    {
        AvmAssert(m_lock.isLockedByCurrentThread());
        SCOPE_LOCK(m_isolateMap.m_lock) {
            FixedHeapRef<Isolate> isolateRef(NULL);
            if (m_isolateMap.LookupItem(giid, &isolateRef)) {
                AvmAssert(isolateRef->RefCount() > 0);
                return isolateRef;
            } else 
                return NULL;
        }
        AvmAssert(false);
        return NULL;
    }

    Aggregate::Globals::IsolateMap::IsolateMap(int initialSize)
        : FixedHeapHashTable<int32_t, FixedHeapRef<Isolate> >(initialSize)
    {}

    Aggregate::Globals::IsolateMap::~IsolateMap()
    {
        Clear();
        // The destructor defined in the parent class will call Clear(), but at that time
        // the object vtable will be that of the parent, so the overriden DestroyItem() won't 
        // be called! We'll call Clear() here first, the subsequent Clear() will have nothing to do. 
    }


    Aggregate::Aggregate()
        : m_primordialGiid(1) // eventually there will be many of those
        , m_activeIsolateCount(0)
        , m_inShutdown(false)
    {}

    Aggregate::~Aggregate()
    {
        m_threadCleanUps.deallocate();
    }

    void Aggregate::destroy()
    {
        mmfx_delete(this);
    }
    
    Aggregate::Globals* Aggregate::m_globals  = NULL;

    bool Aggregate::requestExit(bool shouldWait, int32_t desc, Toplevel* currentToplevel)
    {
        bool result = false;
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            Isolate* isolate = m_globals->at(desc);
            // if the isolate isn't found in the global table terminate 
            // has been called previously, and we can skip the rest.
            if (isolate == NULL) { 
                return false; 
            }

            if (isolate->m_state == Isolate::NEW || isolate->m_state > Isolate::FINISHING) {
                return false; // not gonna wait 
            }

            if (isolate->m_state == Isolate::RUNNING || isolate->m_state == Isolate::STARTING) {
                isolate->interrupt();
            }
            result = true;

            SCOPE_LOCK(m_globals->m_isolateMap.m_lock) { 
                m_globals->m_isolateMap.RemoveItem(desc);
            }

            AvmCore* core = isolate->m_core;
            if (core == NULL) {
                // FIXME - what invariant holds here?
                return result;
            } else if (core == currentToplevel->core()) {
                // Don't wait for itself, unwind the stack
                goto scope_end;
            } else {
                // Interrupt other, fall through and wait.
                core->raiseInterrupt(AvmCore::ExternalInterrupt);
                // Hope for the best? the thread being interrupted won't necessarily fence
                vmbase::MemoryBarrier::readWrite();
                isolate->signalActiveWaitRecord();
            }
            if (shouldWait) {
                while (isolate->m_core != NULL) {
                    locker.wait();
                }
            }

            return result;
            // We are relying on the isolate to clean itself up.
        scope_end: // unlock before throwing
            ;
        }
        this->throwWorkerTerminatedException(currentToplevel);
        return false;
    }


    void Aggregate::requestAggregateExit()
    {
        SCOPE_LOCK(m_globals->m_lock) {
            m_inShutdown = true;
            // this iterator intterupts every isolate's core
            class IsolateCoreInterrupt: public Globals::IsolateMap::Iterator
            {
                Aggregate* m_aggregate;
            public:
                IsolateCoreInterrupt(Aggregate* aggregate): m_aggregate(aggregate) {}
                virtual void each(int32_t giid, FixedHeapRef<Isolate> isolate) 
                {
                    (void) giid;
                    if (m_aggregate != isolate->m_aggregate)
                        return;
                    if (isolate->m_state > Isolate::NEW) { // or is it m_core == NULL
                        if (isolate->isInterrupted())
                            return;

                        if (isolate->m_state < Isolate::FAILED) {
                            AvmCore* core = isolate->m_core;
                            // Ensure that the write to AvmCore::interrupted is visible to the other thread.

                            // in some shutdown cases the core is already NULL so we have to check for
                            // this situation.
                            if (core != NULL) {
                                core->raiseInterrupt(AvmCore::ExternalInterrupt);
                            }
                            // Hope for the best? the thread being interrupted won't necessarily fence
                            vmbase::MemoryBarrier::readWrite();
                            isolate->interrupt();
                        }
                    }
                }
                virtual ~IsolateCoreInterrupt() {}
            };
            
            // this iterator intterupts every isolate's core
            class ReleaseResources: public Globals::IsolateMap::Iterator
            {
                Aggregate* m_aggregate;
            public:
                ReleaseResources(Aggregate* aggregate): m_aggregate(aggregate) {}
                virtual void each(int32_t giid, FixedHeapRef<Isolate> isolate) 
                {
                    (void) giid;
                    if (m_aggregate != isolate->m_aggregate)
                        return;

                    isolate->releaseActiveResources();
                }
                virtual ~ReleaseResources() {}
            };
            // we need to make two passes here 
            //  (1) needs to make sure that all cores are interrupted so that the very next
            //      thing they do is unwind, we don't want to continue executing if they could
            //      possibly be in an ideteriminate state (get unblocked from a Mutex or Condition
            //      when the condition hasn't been met.
            //  (2) needs to release resources (unlock any held Mutex or Condition, clear shared properties, etc)
            IsolateCoreInterrupt iInterrupt(this);
            ReleaseResources iRelease(this);
            SCOPE_LOCK(m_globals->m_isolateMap.m_lock) {
                m_globals->m_isolateMap.ForEach(iInterrupt);
                m_globals->m_isolateMap.ForEach(iRelease);
            }
        }
    }

    /* virtual */
    void Aggregate::throwWorkerTerminatedException(Toplevel* currentToplevel)
    {
        AvmCore* core = currentToplevel->core();
        AvmAssert(core->getIsolate()->getAggregate() == this);
        Stringp errorMessage = core->getErrorMessage(kWorkerTerminated);
        GCRef<ErrorObject> error = currentToplevel->errorClass()->constructObject(errorMessage->atom(), core->intToAtom(0));
        Exception *exception = new (core->GetGC()) Exception(core, error->atom());
        exception->flags |= Exception::EXIT_EXCEPTION;
        exception->flags |= Exception::SUPPRESS_ERROR_REPORT;
        core->throwException(exception);
    }

    Isolate::Isolate(int32_t desc, int32_t parentDesc, Aggregate* aggregate)
        : desc(desc)
        , parentDesc(parentDesc)
        , m_core(NULL)
        , m_waitRecordValid(false)
        , m_activeWaitRecord(NULL)
        , m_aggregate(aggregate)
        , m_thread(NULL)
        , m_state(Isolate::NEW)
        , m_failed(false)
        , m_interrupted(false)
    {
    }

    void Aggregate::stateTransition(Isolate* isolate, Isolate::State to)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            enum Isolate::State from = isolate->m_state;
            bool verbose = false;
            if (verbose) {
                
                static const char* state_names[] = {
                    "NONE",
                    "NEW",
                    "STARTING",
                    "RUNNING",
                    "FINISHING",
                    "TERMINATED",
                    "FAILED",
                    "ABORTED",
                    "EXCEPTION"
                };

                AvmAssert(from != to);
                fprintf(stderr, "%d: %s->%s\n", isolate->desc, state_names[from], state_names[to]);
            }
            isolate->m_state = to;
            if (to == Isolate::STARTING) {
                AvmAssert(from == Isolate::NEW);
            } else if (to == Isolate::RUNNING) {
                AvmAssert(from < to); // FIXME this can be violated (?)
                AvmAssert(isolate->m_thread != NULL || isolate->desc == m_primordialGiid); // m_thread will be null for primordial
                AvmAssert(isolate->m_core != NULL);
            } else if (to == Isolate::EXCEPTION) {
                AvmAssert(from > Isolate::NEW);
				isolate->m_interrupted = true;
                isolate->stopRunLoop();
            } else if (to == Isolate::FAILED) {
                AvmAssert(from == Isolate::NEW);
                isolate->m_failed = true;
            } else if (to == Isolate::FINISHING) {
                AvmAssert(from == Isolate::RUNNING || from == Isolate::STARTING);
                AvmAssert(isolate->m_thread != NULL || m_primordialGiid == isolate->desc);
                isolate->m_interrupted = true;
                isolate->stopRunLoop();
            } else if (to == Isolate::TERMINATED) {
                AvmAssert(from == Isolate::RUNNING || from == Isolate::STARTING || from == Isolate::FINISHING || from == Isolate::NEW);
				isolate->m_interrupted = true;
			}

        }
    }

    
    Isolate::SharedPropertyMap::SharedPropertyMap()
    {
    }
    
    Isolate::SharedPropertyMap::~SharedPropertyMap()
    {
        Clear();
        // The destructor defined in the parent class will call Clear(), but at that time
        // the object vtable will be that of the parent, so the overriden DestroyItem() won't 
        // be called! We'll call Clear() here first, the subsequent Clear() will have nothing to do. 
    }
    
    uintptr_t Isolate::SharedPropertyMap::HashKey(Isolate::SharedPropertyNamep key) const
    {
        return String::hashCodeLatin1(key->values, key->length);
    }
    
    bool Isolate::SharedPropertyMap::KeysEqual(Isolate::SharedPropertyNamep k1, const Isolate::SharedPropertyNamep k2) const
    {
        if (k1->length != k2->length)
            return false;
        int32_t length = k1->length;
        for (int32_t j = 0; j < length; j++)
        {
            if (k1->values[j] != k2->values[j])
                return false;
        }
        return true;
    }

    
    void Isolate::releaseActiveResources()
    {
        // make sure that we don't hold a reference to something that could prevent 
        // resources from being collected and released, like a locked Mutex, waiting Condition, 
        // or a reference to ourself 
        m_properties.Clear();
        
        // if we have any active Mutexes or Conditions release them.
        // this is safe because we have already interrupted our core and the very next execution
        // point should be to throw an external interrupt error
        signalActiveWaitRecord();
    }

    void Isolate::SharedPropertyMap::DestroyItem(Isolate::SharedPropertyNamep key, ChannelItem* item)
    {
        mmfx_delete(item);
        key->deallocate(); 
        mmfx_delete(key);
        
    }
    
    void Isolate::setSharedProperty(const char* utf8String, int32_t len, ChannelItem* item)
    {
        SCOPE_LOCK(m_sharedPropertyLock) {
            // FIXME: validate state
            Isolate::SharedPropertyNamep key = mmfx_new(FixedHeapArray<char>());
            key->length = len;
            char* values = mmfx_new_array(char, len);
            VMPI_memcpy(values, utf8String, len* sizeof(char));
            key->values = values;
            ChannelItem* previous;
            if (m_properties.LookupItem(key, &previous)) {
                m_properties.RemoveItem(key); // this will dealloc old key
            }
            if (item) {
                m_properties.InsertItem(key, item);
            } else {
                key->deallocate();
                mmfx_delete(key); // m_properties doesn't own the key
                // We already removed.
            }
        }
        // else the key is owned by the hashmap
    }

    bool Isolate::getSharedProperty(const char* utf8String, int32_t len, ChannelItem** item)
    {
        // FIXME validate state.
        SCOPE_LOCK(m_sharedPropertyLock) {
            Isolate::SharedPropertyNamep key = mmfx_new(FixedHeapArray<char>());
            key->values = (char*)utf8String; // it's OK, we won't touch it
            key->length = len;
            bool ok = m_properties.LookupItem(key, item);
            key->values = NULL;
            mmfx_delete(key);
            return ok;
        }
        AvmAssert(false);
        return false; // not reached
    }

    ChannelItem* Isolate::makeChannelItem(Toplevel* toplevel, Atom atom)
    {
        class DoubleChannelItem: public ChannelItem
        {
        public:
            DoubleChannelItem(double value) : m_value(value) {}

            Atom getAtom(Toplevel* toplevel) const
            {
                return toplevel->core()->doubleToAtom(m_value);
            }

        private:
            double m_value;
        };

        class IntPtrChannelItem: public ChannelItem
        {
        public:
            IntPtrChannelItem(intptr_t value):m_value(value) {}

            Atom getAtom(Toplevel* toplevel) const
            {
                (void)toplevel;
                return atomFromIntptrValue(m_value);
            }

        private:
            intptr_t m_value;
        };

        class BooleanChannelItem: public ChannelItem
        {
        public:
            BooleanChannelItem(bool value):m_value(value) {}

            Atom getAtom(Toplevel* toplevel) const
            {
                (void)toplevel;
                return m_value ? trueAtom : falseAtom;
            }

        private:
            bool m_value;
        };

        class ScriptObjectChannelItem: public ChannelItem
        {
        public:
            ScriptObjectChannelItem(Toplevel* toplevel, Atom value)
            {
                ByteArrayObject* ba = toplevel->byteArrayClass()->constructByteArray();
                ba->writeObject(value);
		        ByteArray::Buffer* buffer = ba->GetByteArray().getUnderlyingBuffer();
			    ByteArray::Buffer* copy = mmfx_new(ByteArray::Buffer);
			    copy->capacity = buffer->capacity;
			    copy->length = buffer->length;
			    if (buffer->array) {
				    copy->array = mmfx_new_array_opt(uint8_t, buffer->capacity, MMgc::kCanFailAndZero);
                    if (copy->array) {
				        VMPI_memcpy(copy->array, buffer->array, buffer->length);
                    }
			    } else {
				    copy->array = NULL;
			    }
                m_value = copy;
            }

            Atom getAtom(Toplevel* toplevel) const
            {
                ByteArrayClass* cls = toplevel->byteArrayClass();
		        ByteArrayObject* byteArray = new (toplevel->gc(), MMgc::kExact) ByteArrayObject(cls->ivtable(), cls->prototypePtr(), m_value);
                return byteArray->readObject();
            }

        private:
            FixedHeapRef<ByteArray::Buffer> m_value;
        };

        ChannelItem* item = NULL;
        Atom kind = atomKind(atom);
            
        if (kind == kDoubleType) {
            item = mmfx_new(DoubleChannelItem(toplevel->core()->atomToDouble(atom)));
        } else if (kind == kIntptrType) {
            item = mmfx_new(IntPtrChannelItem(atomGetIntptr(atom)));
        } else if (kind == kBooleanType) {
            item = mmfx_new(BooleanChannelItem(atom == trueAtom ? true : false));
        } else if (kind == kSpecialBibopType) {
            // no value
        } else if (AvmCore::istype(atom, toplevel->byteArrayClass()->ivtable()->traits)) {
            ByteArrayObject* ba = static_cast<ByteArrayObject*>(toplevel->core()->atomToScriptObject(atom));
			item = ba->makeChannelItem();
        } else if (AvmCore::istype(atom, toplevel->builtinClasses()->get_MutexClass()->ivtable()->traits)) {
            MutexObject* mutexObj = static_cast<MutexObject*>(toplevel->core()->atomToScriptObject(atom));
			item = mutexObj->makeChannelItem();
        } else if (AvmCore::istype(atom, toplevel->builtinClasses()->get_ConditionClass()->ivtable()->traits)) {
            ConditionObject* conditionObj = static_cast<ConditionObject*>(toplevel->core()->atomToScriptObject(atom));
			item = conditionObj->makeChannelItem();
        } else {
        	item = mmfx_new(ScriptObjectChannelItem(toplevel, atom));
        }
        return item;
    }
    
    void Isolate::removeWaitRecord(vmbase::WaitNotifyMonitor* record)
    {
        AvmAssert(record != NULL);
        // this will only be called outside of any lock on the 
        // specified monitor
        SCOPE_LOCK(m_activeRecordLock) {
            if (m_activeWaitRecord == record) {
                m_activeWaitRecord = NULL;
            }
        }
    }
    
    void Isolate::setActiveWaitRecord(vmbase::WaitNotifyMonitor* record)
    {
        if (!isInterrupted()) {
            // any calls to this must already hold the monitor lock
            AvmAssert(record->isLockedByCurrentThread());
            AvmAssert(m_waitRecordValid == false);
            SCOPE_LOCK(m_activeRecordLock) {
                m_activeWaitRecord = record;
            }
            // protected by the condition (record)
            m_waitRecordValid = true;
        }
    }
    
    void Isolate::invalidateActiveWaitRecord(vmbase::WaitNotifyMonitor* record)
    {
        AvmAssert(record->isLockedByCurrentThread());
        (void)record;
        // protected by the condition (record)
        m_waitRecordValid = false;
    }

    // this method is used to determine if a currently active
    // wait record should be reactivated. reactivating a waiting
    // record should only happen if the signal occured because 
    // the debugger needs to get a call stack.
    bool Isolate::retryActiveWaitRecord()
    {
        return false;
    }

    bool Isolate::signalActiveWaitRecord()
    {
        SCOPE_LOCK(m_activeRecordLock) {
            if (m_activeWaitRecord) {
                SCOPE_LOCK_NAMED(cond, *m_activeWaitRecord) {
                    // only notify the current condition if 
                    // it is still considered valid
                    // when the current waiting condition is
                    // notified outside of this method we don't
                    // it needs to "unset" the active wait record
                    // but going through the setActiveWaitRecord
                    // requires the m_activeRecordLock be held
                    // and that will create a dead lock.
                    // access to this value is protected by the condition
                    // itself.
                    if (m_waitRecordValid) {
                        cond.notifyAll();
                    }
                }
                m_activeWaitRecord = NULL;
                return true;
            }
        }
        return false;
    }

    void Isolate::initialize(AvmCore* core) 
    {
        AvmAssert(AvmCore::getActiveCore() == core);
        this->m_core = core; 
        core->setIsolate(this);
    }
    
    bool Isolate::copyByteCode(ByteArrayObject* byteCode)
    {
         if (byteCode) {
             ByteArray& bytes = byteCode->GetByteArray();
             m_code.allocate(1);
             m_code.values[0].allocate(bytes.GetLength());
             m_code.values[0].initialize(bytes.GetReadableBuffer());
             return true;
         }
         return false;
    }
    
    void Isolate::evalCodeBlobs(bool enter_debugger_on_launch)
    {
        // The isolate is now live and operating independently.
        AvmAssert(AvmCore::getActiveCore()->getIsolate() == this);
        AvmAssert(getAggregate()->queryState(this) == RUNNING);
        
        AvmCore* core = targetCore();
        for (int i = 0; i < m_code.length; i++ ) {
            // execute event loop at the end of the last script
            if (i == (m_code.length - 1) && !this->isPrimordial())
                core->enterEventLoop = true;
            // parse new bytecode
            ReadOnlyScriptBufferImpl* codeimpl = 
                new (core->gc) ReadOnlyScriptBufferImpl(m_code.values[i].values, m_code.values[i].length);
            ScriptBuffer code(codeimpl);
            core->evaluateScriptBuffer(code, enter_debugger_on_launch);
            // release bytes regardless of success/failure
            m_code.values[i].deallocate(); 
        }
        m_code.deallocate();

    }

    bool Isolate::failed()
    {
        AvmAssert(AvmCore::getActiveCore()->getIsolate()->isParentOf(this));
        return m_failed;
    }

    bool Isolate::interrupt()
    {
        bool wasInterrupted = m_interrupted;
        if (!wasInterrupted) {
            m_aggregate->stateTransition(this, Isolate::FINISHING);
        }
        return wasInterrupted;
    }

    bool Isolate::isInterrupted()
    {
        return m_interrupted;
    }

    bool Isolate::isMemoryManagementShutDown()
    {
        AvmAssert(AvmCore::getActiveCore() == m_core);
        // In the player it can happen when m_state == FINISHING
        return m_state > FINISHING;
    }
        
    bool Isolate::isPrimordial()
    {
        return m_aggregate->isPrimordial(this->desc);
    }
     
    void Isolate::run() 
    {
        // Weirdly, the Player doesn't use this call
        m_aggregate->runIsolate(this);
    }

    Isolate::~Isolate()
    {
        m_code.deallocate();
    }

    // Caution, can be triggered by GC sweep or incremental collection.
    void Isolate::destroy()
    {
        AvmAssert(m_activeWaitRecord == NULL);
        AvmAssert(RefCount() == 0);
        if (m_code.length > 0) {
            for (int i = 0; i < m_code.length; i++)
                m_code.values[i].deallocate();
            m_code.deallocate();
        }

        if (m_thread != vmbase::VMThread::currentThread()) {
            Aggregate::destroyIsolate(this); // deletes the thread 
        } else if (m_thread != NULL) {
            // if m_thread == VMThread::currentThread(),the current isolate
            // cannot delete its VMThread object, because the destructor
            // of VMThread will block while the state of the thread is RUNNABLE
            // and the state of the thread will be RUNNABLE because it's running
            // and blocking on the VMThread destructor.
            // If no other isolate has a reference to this isolate, we'll have
            // a leak, so we have to scavenge - call Aggregate::destroyIsolate()
            // in waitUntilNoIsolates(), put this into the cleanups list
            getAggregate()->addThreadCleanup(m_thread);
            m_thread = NULL;
        }
        mmfx_delete(this);
    }

    //
    // InterruptableState 
    //
#ifdef DEBUG
    int InterruptableState::globalId = 0;
#endif // DEBUG


    InterruptableState::EnterWait::EnterWait(Isolate* isolate, vmbase::MonitorLocker<vmbase::IMPLICIT_SAFEPOINT>& cond, int32_t timeout)
        : interrupted(false)
    {
        if (isolate) {
            isolate->setActiveWaitRecord(cond.getMonitor());
        }
        DEBUG_STATE(("thread %d is sleeping\n", VMPI_currentThread()));
        if (timeout == -1) {
            cond.wait();
        }
        else {
            result = cond.wait(timeout);
        }
        DEBUG_STATE(("thread %d is awake\n", VMPI_currentThread()));

        if (isolate) 
		{
            isolate->invalidateActiveWaitRecord(cond.getMonitor());
            // we want to interrupt if the isolate was interrupted OR if a script timeout has fired (only happens in the primordial)
			interrupted = isolate->isInterrupted() || isolate->targetCore()->interruptCheckReason(AvmCore::ScriptTimeout);

        }
    }

    InterruptableState::InterruptableState()
    {
#ifdef DEBUG
        gid = ++globalId;
#endif // DEBUG
    }

    void InterruptableState::notify()
    {
        SCOPE_LOCK_NAMED(cond, m_condition) {
            DEBUG_STATE(("thread %d is calling notify on (%d)\n", VMPI_currentThread(), gid));
            cond.notify();
        }
    }

    void InterruptableState::notifyAll()
    {
        SCOPE_LOCK_NAMED(cond, m_condition) {
            DEBUG_STATE(("thread %d is calling notifyAll on (%d)\n", VMPI_currentThread(), gid));
            cond.notifyAll();
        }
    }

    //
    // Aggregate
    //

    void Aggregate::destroyIsolate(Isolate* isolate) {
        if (isolate->m_thread != NULL) {
            // FIXME hold the m_globals->m_lock lock here?
            isolate->m_thread->join(); // shouldn't block
            mmfx_delete(isolate->m_thread); // can't delete current thread
            isolate->m_thread = NULL;
        }
    }

    void Aggregate::initializeGlobals()
    {
        // must be single-threaded and called only once
        AvmAssert(m_globals == NULL);
        m_globals = mmfx_new(Globals);
    }

    void Aggregate::reclaimGlobals() 
    {
        if (m_globals != NULL) {
            mmfx_delete(m_globals);
            m_globals = NULL;
        } 
    }

    void Aggregate::addThreadCleanup(vmbase::VMThread* thread)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            // since we may not be within a GC enter we have to allow the following
            // allocation to fail, and if it does we will leak the thread, but, if
            // the allocation fails we have much bigger issues.
            if (m_threadCleanUps.resize(m_threadCleanUps.length+1, true /*can fail*/)) {
                m_threadCleanUps.values[m_threadCleanUps.length-1] = thread;
            }
        }
    }

    bool Aggregate::spawnAndWaitForInitialization(AvmCore* spawningCore, Isolate* isolate)
    {
        (void)spawningCore;
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            AvmAssert(isolate->m_thread == NULL);
            vmbase::VMThread* thread = mmfx_new(vmbase::VMThread(isolate));
            isolate->m_thread = thread; 
            if (thread->start()) {
                while (isolate->m_state == Isolate::NEW) {
                    locker.wait();
                }
                return true;
            } else {
                // Will never try to spawn this isolate again.
                // recursively locks m_globals->m_lock
                recordSpawnFailure(isolate);
                return false;
            }
        }
        NOT_REACHED;
    }

    void Aggregate::recordSpawnFailure(Isolate* isolate)
    {
        stateTransition(isolate, Isolate::FAILED);
        SCOPE_LOCK(m_globals->m_lock) { // may be recursive

            if (isolate->m_thread) {
                mmfx_delete(isolate->m_thread);
                isolate->m_thread = NULL;
            }
        }
    }

    Isolate* Aggregate::getIsolate(int32_t desc)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            return m_globals->at(desc);
        }
        NOT_REACHED;
    }
    
    Isolate::State Aggregate::queryState(Isolate* isolate) 
    {
        AvmAssert(isolate != NULL);
        SCOPE_LOCK(m_globals->m_lock) {
            return isolate->m_state;
        }
        // not reached
        AvmAssert(false);
        return Isolate::NONE;
    }

    void Aggregate::dumpGlobals() 
    {
        //FIXME
    }

    bool Aggregate::isGlobalsLocked() {
#ifdef DEBUG        
        return m_globals->m_lock.isLockedByCurrentThread();
#else
        return true;
#endif
    }

    bool Aggregate::isPrimordial(int32_t giid)
    {
        return giid == m_primordialGiid;
    }

    Isolate* Aggregate::newIsolate(Isolate* parent)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            if (m_inShutdown) {
                return NULL;
            }
            
            int32_t giid = m_globals->m_nextGlobalIsolateId ++; 
            if (giid == Isolate::POISON_DESC) { // Reached max int
                // Oops, integer wraparound.
                printf("WORKER GLOBAL ID SPACE EXHAUSTED\n");
                VMPI_abort();
            }
            Isolate* isolate = Isolate::newIsolate(giid, 
                                                   parent ? parent->desc : Isolate::INVALID_DESC, this);
            SCOPE_LOCK(m_globals->m_isolateMap.m_lock) {
                m_globals->m_isolateMap.InsertItem(giid, FixedHeapRef<Isolate>(isolate));
            }
            AvmAssert(isolate->m_thread == NULL);
            if (parent != NULL) {
                AvmAssert(AvmCore::getActiveCore()->getIsolate() == parent);
            } else {
                // Primordial isolate, already active.
                m_primordialGiid = giid;
                m_activeIsolateCount ++; 
                isolate->m_thread = vmbase::VMThread::currentThread();
            }
            return isolate;
        }
        NOT_REACHED;
    }

    void Aggregate::initializeAndNotify(AvmCore* targetCore, Isolate* current)
    {
        AvmAssert(AvmCore::getActiveCore() == targetCore);
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            current->initialize(targetCore);
            // if terminate is called before we actually start we will not 
            // have an entry in the global table
            AvmAssert(m_globals->at(current->desc) == NULL || m_globals->at(current->desc)->m_state > Isolate::NEW);
            m_activeIsolateCount ++;
            locker.notifyAll();
        }
        AvmAssert(targetCore->getIsolate() == current);
    }

    EnterSafepointManager::EnterSafepointManager(AvmCore* core)
    {
        Isolate* isolate = core->getIsolate();
        if (isolate) {
		    m_aggregate = isolate->getAggregate();
		}
        m_safepointMgr = core->getSafepointManager();
        m_spRecord.setLocationAndDesc( (int32_t*)&core->interrupted, core->getIsolateDesc() ); 

        m_safepointMgr->enter(&m_spRecord);
    }
    
    EnterSafepointManager::~EnterSafepointManager()
    {
        cleanup();
    }

    void EnterSafepointManager::cleanup() 
    {
        m_safepointMgr->leave(&m_spRecord);
        m_spRecord.setLocationAndDesc( NULL, -1 );
    }

    void Aggregate::runIsolate(Isolate* isolate) 
    {
        stateTransition(isolate, Isolate::STARTING);
        // Make sure the isolate survives for the duration of the following call.
        {
            FixedHeapRef<Isolate> handle(isolate);
            isolate->doRun();
        }
    }

    void Aggregate::beforeCoreDeletion(Isolate* current) {
        // if we terminate before the core is running we may not have one
        AvmAssert(AvmCore::getActiveCore() == NULL || AvmCore::getActiveCore()->getIsolate() == current);
        
        SCOPE_LOCK(m_globals->m_lock) {
#ifdef DEBUG
            {
                Isolate* checked = m_globals->at(current->desc);
                AvmAssert(checked == NULL || checked == current);
            }
#endif
            if (current->m_core) {
                current->m_core->setIsolate(NULL);
            }
        }
    }

    void Aggregate::afterGCDeletion(Isolate* current) {
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            // Ideally we would delete isolate->m_thread now, but it's still in referenced by a thread local.
            AvmAssert(current->isPrimordial() || current->m_thread != NULL); 
            m_activeIsolateCount --;
            locker.notifyAll();
            if (current->m_state != Isolate::EXCEPTION) {
                stateTransition(current, Isolate::TERMINATED); // otherwise it could be Exception
            }
			current->releaseActiveResources();

            current->m_core = NULL;
        }
    }

    void Aggregate::waitUntilNoIsolates()
    {
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            while (m_activeIsolateCount > 0) {
                locker.wait();
            }
            for (int i=0; i< m_threadCleanUps.length; i++)
            {
                mmfx_delete(m_threadCleanUps.values[i]);
            }
        }
    }

    GCRef<ObjectVectorObject> Aggregate::listWorkers(Toplevel* toplevel)
    {
        GCRef<ClassClosure> workerClass = toplevel->workerClass();
        GCRef<ObjectVectorObject> workerVector = toplevel->vectorClass()->newVector(workerClass);
        
        class IsolateLister: public Globals::IsolateMap::Iterator
        {
            Aggregate* m_aggregate;
            GCRef<ObjectVectorObject> m_workerVector;
            Toplevel* m_toplevel;
            int m_index;
        public:
            IsolateLister(Aggregate* aggregate, GCRef<ObjectVectorObject> workerVector, Toplevel* toplevel)
                : m_aggregate(aggregate)
                , m_workerVector(workerVector)
                , m_toplevel(toplevel)
                , m_index(0)
            {}
            virtual void each(int32_t, FixedHeapRef<Isolate> isolate) 
            {
                //  Only list workers that are in the RUNNING state
                if (isolate->m_aggregate->queryState(isolate) == Isolate::RUNNING)
                {
                    GCRef<ScriptObject> interned = m_toplevel->getInternedObject(isolate);
                    if (interned == NULL) {
                        interned = isolate->workerObject(m_toplevel);
                    }
                    m_workerVector->setUintProperty(m_index++, interned->atom());
                }
            }
            virtual ~IsolateLister() {}
        };
        
        IsolateLister lister(this, workerVector, toplevel);
        SCOPE_LOCK(m_globals->m_isolateMap.m_lock) {
            m_globals->m_isolateMap.ForEach(lister);
        }
        
        return workerVector;
    }


    void Aggregate::runSafepointTaskHoldingIsolateMapLock(vmbase::SafepointTask* task)
    {
        SCOPE_LOCK(m_globals->m_isolateMap.m_lock) {
            safepointManager()->requestSafepointTask(*task);
        }
    }
    

    void Aggregate::reloadGlobalMemories()
    {
        // This is a heavyhanded approach and reloads all the global memories
        // known, because the ByteArray subscriber mechanism can't yet handle
        // cross-GC-heap references.
        class Reloader: public Globals::IsolateMap::Iterator
        {
            virtual void each(int32_t, FixedHeapRef<Isolate> isolate) 
            {
                AvmCore* core = isolate->targetCore();
                if (isolate->m_state < Isolate::RUNNING || isolate->m_state >= Isolate::FINISHING) {
                    // running in a safepoint, so no potection for m_state needed
                    return;
                }
                for (uint32_t i = 0, n = core->m_domainEnvs.length(); i < n; ++i)
                 {
                     DomainEnv* domainEnv = core->m_domainEnvs.get(i);
                     if (domainEnv) {
                         ByteArrayObject* mem = domainEnv->get_globalMemory();
                         if (!mem) 
                             continue;
                         mem->GetByteArray().NotifySubscribers();
                     }
                 }
            }
        };
     
        AvmAssert(m_globals->m_isolateMap.m_lock.isLockedByCurrentThread());
        Reloader reloader;
        m_globals->m_isolateMap.ForEach(reloader);
    }

}

