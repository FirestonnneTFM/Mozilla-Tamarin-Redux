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


    Aggregate::Globals::PromiseChannelMap::PromiseChannelMap(int initialSize)
        : FixedHeapHashTable<int64_t, PromiseChannel*>(initialSize)
    {}

    Aggregate::Globals::PromiseChannelMap::~PromiseChannelMap()
    {
        Clear();
        // The destructor defined in the parent class will call Clear(), but at that time
        // the object vtable will be that of the parent, so the overriden DestroyItem() won't 
        // be called! We'll call Clear() here first, the subsequent Clear() will have nothing to do. 
    }

    void Aggregate::Globals::PromiseChannelMap::DestroyItem(int64_t guid, PromiseChannel* channel)
    {
        AvmAssert(guid >= 0);
        (void)guid;
        // a leaf lock is being held, no more locking
        AvmAssert(channel->RefCount() == 0);
        mmfx_delete(channel);
    }
    
    Aggregate::Globals::EmptyPromisesMap::EmptyPromisesMap(int initialSize)
        : FixedHeapHashTable<int32_t, FixedHeapHashTable<int32_t, int32_t>* >(initialSize)
    {}

    Aggregate::Globals::EmptyPromisesMap::~EmptyPromisesMap()
    {}

    Aggregate::Aggregate()
        : m_primordialGiid(1) // eventually there will be many of those
        , m_activeIsolateCount(0)
        , m_commInProgress(0)
        , m_msgInTransit(0)
        , m_blockedChannels(0)
        , m_inShutdown(false)
    {}

    Aggregate::~Aggregate()
    {}

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
            if (isolate == NULL) 
                return false; // FIXME revisit
            if (isolate->m_state == Isolate::NEW || isolate->m_state > Isolate::FINISHING)
                return false; // not gonna wait 
                // Interrupt computation and blocking I/O, currently only message receive.
            closeChannelsWithEndpoint(isolate);
            if (isolate->m_state == Isolate::RUNNING || isolate->m_state == Isolate::STARTING)
                isolate->interrupt();
                // Ensure that the write to AvmCore::interrupted is visible to the other thread.
                // First set interrupted status, then notify 
                // there may be some isolates waiting for the call requests
            SCOPE_LOCK_NAMED(lk, m_commlock) {
                lk.notifyAll();
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
        this->selfExit(currentToplevel);
        return false;
    }


    void Aggregate::requestAggregateExit()
    {
        SCOPE_LOCK(m_globals->m_lock) {
            m_inShutdown = true;
            SCOPE_LOCK_NAMED(lk, m_commlock) {
                // there may be some isolates waiting for the call requests
                lk.notifyAll();
            }

            class CloseEveryChannel: public Globals::PromiseChannelMap::Iterator
            {
                PromiseChannel** toDelete;
                int& count;
                
            public:
                CloseEveryChannel(PromiseChannel** toDelete, int& count): toDelete(toDelete), count(count) {}
                virtual void each(int64_t id, PromiseChannel* channel)
                {
                    (void)id;
                    channel->unregisterRoot();
                    ((PromiseChannelImpl*)channel)->close();
                    if (channel->RefCount() == 0) {
                        toDelete[count++] = channel;
                    }

                }
            };

            int count = 0;
            MMgc::GC::AllocaAutoPtr _autoAlloca;
            PromiseChannel** toDelete = (PromiseChannel**) VMPI_alloca(AvmCore::getActiveCore(), _autoAlloca, 
                                                                       sizeof(PromiseChannel*)*m_globals->m_channelMap.GetNumItems());
            
            CloseEveryChannel closeEveryChannel(toDelete, count);

            SCOPE_LOCK(m_globals->m_channelMap.m_lock) {
                m_globals->m_channelMap.ForEach(closeEveryChannel);
                for (int i = 0; i < count; i++) {
                    destroyPromiseChannel(toDelete[i]);
                }
            }
            
            
            class IsolateKiller: public Globals::IsolateMap::Iterator
            {
                Aggregate* m_aggregate;
            public:
                IsolateKiller(Aggregate* aggregate): m_aggregate(aggregate) {}
                virtual void each(int32_t giid, FixedHeapRef<Isolate> isolate) 
                {
                    (void) giid;
                    if (m_aggregate != isolate->m_aggregate)
                        return;
                    if (isolate->m_state > Isolate::NEW) { // or is it m_core == NULL
                        if (isolate->isInterrupted())
                            return;
                        AvmCore* core = isolate->m_core;
                        // Ensure that the write to AvmCore::interrupted is visible to the other thread.
                        // Use safepoints for that? 

                        isolate->interrupt();
                        if (core) {
                            core->raiseInterrupt(AvmCore::ExternalInterrupt);
                            // Hope for the best? the thread being interrupted won't necessarily fence
                            vmbase::MemoryBarrier::readWrite();
                        } else {
                            // FIXME revisit why we can possibly take this branch.
                        }
                    }
                }
                virtual ~IsolateKiller() {}
            };
            
            IsolateKiller iKiller(this);
            SCOPE_LOCK(m_globals->m_isolateMap.m_lock) {
                m_globals->m_isolateMap.ForEach(iKiller);
            }
            SCOPE_LOCK_NAMED(lk, m_commlock) {
                // Wake up isolates in waitForAnySend()
                lk.notifyAll();
            }

        }
    }

    /* virtual */
    void Aggregate::selfExit(Toplevel* currentToplevel)
    {
        AvmCore* core = currentToplevel->core();
        AvmAssert(core->getIsolate()->getAggregate() == this);
        Stringp errorMessage = core->getErrorMessage(kScriptTerminatedError); // Better exception?
        GCRef<ErrorObject> error = currentToplevel->errorClass()->constructObject(errorMessage->atom(), core->intToAtom(0));
        Exception *exception = new (core->GetGC()) Exception(core, error->atom());
        exception->flags |= Exception::EXIT_EXCEPTION;
        exception->flags |= Exception::SUPPRESS_ERROR_REPORT;
        core->throwException(exception);
    }


    bool Aggregate::registerAdditionalRemoteProxy(uint32_t resolvedPromiseGID,
                                                  uint32_t freshPromiseGID,
                                                  PromiseChannelObject* out,
                                                  PromiseChannelObject* inc)
    {

        SCOPE_LOCK(m_globals->m_lock) {
            // out is the channel of the promise -- object's owner
            // will be receiver of this channel
            Isolate* owner(m_globals->at(out->get_receiver()));
            Isolate::State state = queryState(owner);
            
            if (state == Isolate::NEW || state > Isolate::RUNNING) {
                return false;
            }
            
            AvmAssert(owner != NULL);
            // notify this isolate that it should create a fresh promise
            // to wait for resolution requests from another worker
            SCOPE_LOCK_NAMED(lk, m_commlock) {
                int length = owner->m_additionalProxyInfo.length;
                if (length == 0) {
                    AvmAssert(owner->m_additionalProxyChannels.length == 0);
                    owner->m_additionalProxyInfo.allocate(4);
                    owner->m_additionalProxyChannels.allocate(4);
                }
                else if (owner->numAdditionalProxies == length) {
                    owner->m_additionalProxyInfo.resize(length + 4);
                    owner->m_additionalProxyChannels.resize(length + 4);
                }
                owner->m_additionalProxyInfo.values[owner->numAdditionalProxies] = resolvedPromiseGID;
                owner->m_additionalProxyInfo.values[owner->numAdditionalProxies+1] = freshPromiseGID;
                owner->m_additionalProxyChannels.values[owner->numAdditionalProxies] = out->m_channel;
                owner->m_additionalProxyChannels.values[owner->numAdditionalProxies+1] = inc->m_channel;
                owner->numAdditionalProxies+=2;
                
                lk.notifyAll();
            }
        }
        return true;
    }


    void Isolate::registerPromiseOwner(int32_t, avmplus::Atom, avmplus::Toplevel*)
    {
    }


    bool Aggregate::notifyEmptyOwners(int32_t emptyPromiseGID, Atom resolvedObject, Toplevel* toplevel)
    {
        bool success = false;
        SCOPE_LOCK(m_globals->m_lock) {

            class PromiseOwnerRegisterer: public FixedHeapHashTable<int32_t, int32_t>::Iterator
            {
                int32_t existingProxyGID; // == emptyPromiseGID (of the now resolved promise)
                Atom resolvedObject;
                Aggregate *aggregate;
                Toplevel* toplevel;
                
            public:
                PromiseOwnerRegisterer(int32_t id, Atom o, Aggregate *a, Toplevel *t) : 
                    existingProxyGID(id), resolvedObject(o), aggregate(a), toplevel(t) {}

                virtual void each(int32_t giid, int32_t same_giid) 
                {
                    (void)same_giid;
                    Isolate *currentIsolate = AvmCore::getActiveCore()->getIsolate();
                    if (currentIsolate->desc != giid) {
                        Isolate* isolate = aggregate->m_globals->at(giid);
                        if (isolate->m_state == Isolate::RUNNING) {
                            SCOPE_LOCK(aggregate->m_commlock) {
                                isolate->registerPromiseOwner(existingProxyGID, resolvedObject, toplevel);
                            }
                        }
                    }
                }
            };

            FixedHeapHashTable<int32_t, int32_t> *set = NULL;
            success = m_globals->m_emptyPromisesMap.LookupItem(emptyPromiseGID, &set);
            if (success) {
                // resolution request may not get propagated in time
                // to the current worker from the one that actually
                // resolved the promise

                PromiseOwnerRegisterer promiseOwnerRegisterer(emptyPromiseGID, resolvedObject, this, toplevel);
                set->ForEach(promiseOwnerRegisterer);
                
                success = m_globals->m_emptyPromisesMap.RemoveItem(emptyPromiseGID);
                AvmAssert(success);
                mmfx_delete(set);            
                
                SCOPE_LOCK_NAMED(lk, m_commlock) {
                    lk.notifyAll();
                }
            }
        }
        return success;
    }


    void Aggregate::registerEmptyPromise(int32_t emptyPromiseGID, int32_t callerGiid)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            FixedHeapHashTable<int32_t, int32_t> *set;
            bool found = m_globals->m_emptyPromisesMap.LookupItem(emptyPromiseGID, &set);
            if (!found) {
                set = mmfx_new((FixedHeapHashTable<int32_t, int32_t>));
                m_globals->m_emptyPromisesMap.InsertItem(emptyPromiseGID, set);
            }
            int32_t el;
            (void)el;
            AvmAssert(!set->LookupItem(callerGiid, &el));
            set->InsertItem(callerGiid, callerGiid);
        }
    }

    void Aggregate::printEmptyPromises()
    {
        class EmptyPromisesPrinter: public Globals::EmptyPromisesMap::Iterator
        {
        public:
            virtual void each(int32_t gpid, FixedHeapHashTable<int32_t, int32_t> *set) 
            {

                class Int32SetPrinter: public FixedHeapHashTable<int32_t, int32_t>::Iterator
                {
                public:
                    virtual void each(int32_t giid, int32_t same_giid) 
                    {
                        (void)same_giid;
                        printf("\t%d\n", giid);
                    }
                };

                printf("WORKERS FOR EMPTY PROMISE %d:\n", gpid);
                Int32SetPrinter setPrinter;
                set->ForEach(setPrinter);

            }
            
        };
        EmptyPromisesPrinter epPrinter;
        m_globals->m_emptyPromisesMap.ForEach(epPrinter);
        printf("\n");
    }


    Isolate::Isolate(int32_t desc, int32_t parentDesc, Aggregate* aggregate)
        : desc(desc)
        , parentDesc(parentDesc)
        , numAdditionalProxies(0)
        , additionalProxiesProcessed(0)
        , numEmptyPromiseOwners(0)
        , m_global_gpid(0)
        , m_core(NULL)
        , m_aggregate(aggregate)
        , m_thread(NULL)
        , m_state(Isolate::NEW)
        , m_failed(false)
        , m_interrupted(false)
        , m_listeners(NULL, 0)
    {
    }

    void Aggregate::stateTransition(Isolate* isolate, Isolate::State to)
    {
        AvmAssert(!m_commlock.isLockedByCurrentThread());
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
                    "STOPPED",
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
                AvmAssert(isolate->m_thread != NULL || isolate->desc == 1); // m_thread will be null for giid==1
                AvmAssert(isolate->m_core != NULL);
            } else if (to == Isolate::EXCEPTION) {
                AvmAssert(from > Isolate::NEW);
            } else if (to == Isolate::FAILED) {
                AvmAssert(from == Isolate::NEW);
                isolate->m_failed = true;
            } else if (to == Isolate::FINISHING) {
                AvmAssert(from == Isolate::RUNNING || from == Isolate::STARTING);
                AvmAssert(isolate->m_thread != NULL);
                isolate->m_interrupted = true;
                isolate->stopRunLoop();
            }

            intptr_t changeCode = (((intptr_t)from) << 16) | ((intptr_t)to);
            
            AvmAssert(!m_commlock.isLockedByCurrentThread());
            // Always grab m_listenerLock before m_commlock.
            SCOPE_LOCK(isolate->m_listenerLock) {
                for (unsigned i = 0; i < isolate->m_listeners.length(); i++) {
                    IsolateEventListener* listener = isolate->m_listeners.get(i);
                    // FIXME can this block when over capacity?
                    if (!beginChannelOp(listener->channel, true)) {
                    } else {
                        listener->channel->put(atomFromIntptrValue(changeCode));
                        endChannelOp(listener->channel, false);
                    }
                }
            }
        }
    }

    
    Isolate::StartArgumentMap::StartArgumentMap()
    {
    }
    
    Isolate::StartArgumentMap::~StartArgumentMap()
    {
        Clear();
        // The destructor defined in the parent class will call Clear(), but at that time
        // the object vtable will be that of the parent, so the overriden DestroyItem() won't 
        // be called! We'll call Clear() here first, the subsequent Clear() will have nothing to do. 
    }
    
    uintptr_t Isolate::StartArgumentMap::HashKey(Isolate::StartArgNamep key) const
    {
        return String::hashCodeLatin1(key->values, key->length);
    }
    
    bool Isolate::StartArgumentMap::KeysEqual(Isolate::StartArgNamep k1, const Isolate::StartArgNamep k2) const
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

    enum ChannelItemType {
        ChannelItemByteArray = 0x100,
        ChannelItemMutex = 0x101
    };
    
    void Isolate::StartArgumentMap::DestroyItem(Isolate::StartArgNamep key, ChannelItem item)
    {
        if (item.tag >= 0x100) { 
            FixedHeapRCObject* rcobj = static_cast<FixedHeapRCObject*>(item.asNative);
            rcobj->DecrementRef();
        }
        key->deallocate(); 
        mmfx_delete(key);
        
    }
    
    void Isolate::setStartArgument(const char* utf8String, int32_t len, ChannelItem item)
    {
        // FIXME: validate state
        Isolate::StartArgNamep key = mmfx_new(FixedHeapArray<char>());
        key->length = len;
        char* values = mmfx_new_array(char, len);
        VMPI_memcpy(values, utf8String, len* sizeof(char));
        key->values = values;
        ChannelItem previous;
        if (m_arguments.LookupItem(key, &previous)) {
            m_arguments.RemoveItem(key); // this will dealloc old key
        }
        m_arguments.InsertItem(key, item);
        // else the key is owned by the hashmap
    }

    bool Isolate::getStartArgument(const char* utf8String, int32_t len, ChannelItem* item)
    {
        // FIXME validate state.
        Isolate::StartArgNamep key = mmfx_new(FixedHeapArray<char>());
        key->values = (char*)utf8String; // it's OK, we won't touch it
        key->length = len;
        bool ok = m_arguments.LookupItem(key, item);
        key->values = NULL;
        mmfx_delete(key);
        return ok;
    }
    void Isolate::clearStartArguments()
    {
        // FIXME implement.
    }

    
    
    Atom Isolate::extractAtom(Toplevel* toplevel, ChannelItem item)
    {
        switch (item.tag) {
        case kDoubleType:
            return toplevel->core()->doubleToAtom(item.asNumber);
        case kBooleanType:
            return item.asBoolean ? trueAtom : falseAtom;
        case kIntptrType:
            return atomFromIntptrValue(item.asIntptr);
        case kSpecialBibopType:
            return undefinedAtom;
        case kObjectType:
            return nullObjectAtom;
        case kNamespaceType:
            return nullNsAtom;
        case kStringType:
            return nullStringAtom;
        case ChannelItemByteArray:
            {
                ByteArray::Buffer* baBuffer = static_cast<ByteArray::Buffer*>(item.asNative);
                ByteArrayClass* baClass = toplevel->byteArrayClass();
                ByteArrayObject* baObject = new (toplevel->gc(), MMgc::kExact) ByteArrayObject(baClass->ivtable(), baClass->prototypePtr(), baBuffer);
                // will increment the refcount of buffer
                return baObject->toAtom();
            }
        case ChannelItemMutex:
            {
                MutexObject::State* state = static_cast<MutexObject::State*>(item.asNative);
                MutexClass* mutexClass = toplevel->builtinClasses()->get_MutexClass();
                MutexObject* mutexObj  =   
                    new (toplevel->gc(), MMgc::kExact, mutexClass->ivtable()->getExtraSize()) MutexObject(mutexClass->ivtable(), mutexClass->prototypePtr());
                // will increment the refcount of m_state
                mutexObj->m_state = state;
                return mutexObj->toAtom();
            }

        default:
            AvmAssert(false);
            return unreachableAtom;
        }
    }

    ChannelItem Isolate::makeChannelItem(Toplevel* toplevel, Atom atom)
    {
        ChannelItem item;
        Atom kind = atomKind(atom);
        item.tag = int32_t(kind);
            
        if (kind == kDoubleType) {
            item.asNumber = toplevel->core()->atomToDouble(atom);
        } else if (kind == kIntptrType) {
            item.asIntptr = atomGetIntptr(atom);
        } else if (kind == kBooleanType) {
            item.asBoolean = atom == trueAtom ? true : false;
        } else if (kind == kSpecialBibopType) {
            // no value
        } else if (AvmCore::istype(atom, toplevel->byteArrayClass()->ivtable()->traits)) {
            ByteArrayObject* ba = static_cast<ByteArrayObject*>(toplevel->core()->atomToScriptObject(atom));
            if (ba->GetByteArray().isWorkerLocal()) {
                ByteArray::Buffer* buffer = ba->GetByteArray().getUnderlyingBuffer();
                ByteArray::Buffer* copy = mmfx_new(ByteArray::Buffer);
                copy->capacity = buffer->capacity;
                copy->length = buffer->length;
                if (buffer->array) {
                    copy->array = mmfx_new_array_opt(uint8_t, buffer->capacity, MMgc::kCanFailAndZero);
                    VMPI_memcpy(copy->array, buffer->array, buffer->length);
                } else {
                    copy->array = NULL;
                }
                copy->IncrementRef(); // It sits in the buffer so it's reachable
                item.asNative = copy;
            } else {
                ByteArray::Buffer* buffer = ba->GetByteArray().getUnderlyingBuffer();
                buffer->IncrementRef();
                item.asNative = buffer;
            }
            item.tag = ChannelItemByteArray;
        } else if (AvmCore::istype(atom, toplevel->builtinClasses()->get_MutexClass()->ivtable()->traits)) {
            MutexObject* mutexObj = static_cast<MutexObject*>(toplevel->core()->atomToScriptObject(atom));
            mutexObj->m_state->IncrementRef();
            item.asNative = mutexObj->m_state;
            item.tag = ChannelItemMutex;
        } else {
            item.asNative = NULL;
        }
        return item;
    }

    

    void Isolate::initialize(AvmCore* core) 
    {
        AvmAssert(AvmCore::getActiveCore() == core);
        for (int i = 0; i < m_initialChannels.length; i++) {
            FixedHeapRef<PromiseChannel>& m = m_initialChannels.values[i];
            if (m->sender == this->desc)
                m->registerWithGC(core->gc);
        }        
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

    void Isolate::eventLoop(Toplevel* )
    {
        AvmAssert(false);
        // redefine or don't use me.
    }

    Isolate::~Isolate()
    {
        m_listeners.destroy();
        m_code.deallocate();
    }

    // Caution, can be triggered by GC sweep or incremental collection.
    void Isolate::destroy()
    {
        AvmAssert(RefCount() == 0);
        if (m_code.length > 0) {
            for (int i = 0; i < m_code.length; i++)
                m_code.values[i].deallocate();
            m_code.deallocate();
        }
        if (m_additionalProxyInfo.length > 0) {
            AvmAssert(m_additionalProxyChannels.length > 0);
            m_additionalProxyInfo.deallocate();
            m_additionalProxyChannels.deallocate();
        }
        if (m_emptyPromiseInfo.length > 0) {
            AvmAssert(m_emptyPromiseChannels.length > 0);
            m_emptyPromiseInfo.deallocate();
            m_emptyPromiseChannels.deallocate();
        }
        destroyListeners();
        if (m_thread != vmbase::VMThread::currentThread()) {
            Aggregate::destroyIsolate(this); // deletes the thread 
        } else {
            // if m_thread == VMThread::currentThread(),the current isolate
            // cannot delete its VMThread object, because the destructor
            // of VMThread will block while the state of the thread is RUNNABLE
            // and the state of the thread will be RUNNABLE because it's running
            // and blocking on the VMThread destructor.
            // If no other isolate has a reference to this isolate, we'll have
            // a leak, so we have to scavenge - call Aggregate::destroyIsolate()
            // in waitUntilNoIsolates()
        }
        mmfx_delete(this);
    }

    void Aggregate::destroyIsolate(Isolate* isolate) {
        if (isolate->m_thread != NULL) {
            // FIXME hold the m_globals->m_lock lock here?
            isolate->m_thread->join(); // shouldn't block
            mmfx_delete(isolate->m_thread); // can't delete current thread
            isolate->m_thread = NULL;
        }
    }

    void Aggregate::destroyPromiseChannel(PromiseChannel* channel) {
        AvmAssert(channel->RefCount() == 0);
        SCOPE_LOCK(m_globals->m_channelMap.m_lock) {
            m_globals->m_channelMap.RemoveItem(channel->channelGuid); 
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

            class EmptyPromisesKiller: public Globals::EmptyPromisesMap::Iterator
            {
            public:
                virtual void each(int32_t gpid, FixedHeapHashTable<int32_t, int32_t> *set) 
                {
                    (void)gpid;
                    mmfx_delete(set);
                }
                
            };
            EmptyPromisesKiller epKiller;
            m_globals->m_emptyPromisesMap.ForEach(epKiller);

            mmfx_delete(m_globals);
            m_globals = NULL;
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
            isolate->destroyListeners();
            if (isolate->m_thread) {
                mmfx_delete(isolate->m_thread);
                isolate->m_thread = NULL;
            }
        }
    }

    void Isolate::destroyListeners()
    {
        // Hopefully nobody has a ref to this, so synchronization is not necessary.
        AvmAssert(!m_aggregate->m_commlock.isLockedByCurrentThread());
        SCOPE_LOCK(m_listenerLock) {
            while (!m_listeners.isEmpty()) {
                mmfx_delete(m_listeners.removeLast());
            }
        }
    }

    IsolateEventListener::IsolateEventListener(Aggregate* aggregate, int32_t sourceGid, int32_t consumerGid)
        : channel(aggregate->allocatePromiseChannel(sourceGid, consumerGid))
    {
    }

    IsolateEventListener* Aggregate::newEventListener(int32_t sourceGid, Isolate* destination)
    {
        // note negative value, values are generated by the system, not the isolate itself
        IsolateEventListener* listener = mmfx_new(IsolateEventListener(this, -sourceGid, destination->desc));
        bool success = false;
        SCOPE_LOCK(m_globals->m_lock) {
            Isolate* isolate = m_globals->at(sourceGid); 
            if (isolate) {
                AvmAssert(!m_commlock.isLockedByCurrentThread());
                SCOPE_LOCK(isolate->m_listenerLock) {
                    isolate->m_listeners.add(listener);
                }
                success = true;
            }
        }
        if (success) {
            return listener;
        } else {
            mmfx_delete(listener);
            return NULL;
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

    uint32_t Aggregate::nextPromiseGID()
    {
        uint32_t res = VMPI_atomicIncAndGet32(&m_globals->m_nextGlobalPromiseId);
        if (res == 0) {
            // Oops, unsigned integer wraparound.
            printf("PROMISE GLOBAL ID SPACE EXHAUSTED\n");
            VMPI_abort();
        }
        return res;
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
            AvmAssert(m_globals->at(current->desc)->m_state > Isolate::NEW);
            m_activeIsolateCount ++;
            locker.notifyAll();
        }
        AvmAssert(targetCore->getIsolate() == current);
    }

    EnterSafepointManager::EnterSafepointManager(AvmCore* core)
    {
        m_safepointMgr = core->getIsolate()->getAggregate()->safepointManager();
        m_safepointMgr->enter(&m_spRecord);
        m_spRecord.m_interruptLocation = (int*)&core->interrupted;
    }
    
    EnterSafepointManager::~EnterSafepointManager()
    {
        cleanup();

    }
    void EnterSafepointManager::cleanup() 
    {
        m_safepointMgr->leave(&m_spRecord);
        m_spRecord.m_interruptLocation = NULL;
    }

    void Aggregate::runIsolate(Isolate* isolate) 
    {
        // FIXME try-finally?
        //EnterSafepointManager enterSafepointManager(this);
        
        stateTransition(isolate, Isolate::STARTING);
        // Make sure the isolate survives for the duration of the following call.
        {
            FixedHeapRef<Isolate> handle(isolate);
            isolate->doRun();
        }
    }

    void Aggregate::beforeCoreDeletion(Isolate* current) {
        AvmAssert(AvmCore::getActiveCore()->getIsolate() == current);
        
        SCOPE_LOCK(m_globals->m_lock) {
            AvmAssert(current == m_globals->at(current->desc));
            // Careful, this will try to grab m_commlock
            // Note that the following will run due to external stop()
            // so may end up running twice.
            closeChannelsWithEndpoint(current);

            if (current->m_core)
                current->m_core->setIsolate(NULL);
        }
    }

    void Aggregate::afterGCDeletion(Isolate* current) {
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            // Ideally we would delete isolate->m_thread now, but it's still in referenced by a thread local.
            AvmAssert(current->isPrimordial() || current->m_thread != NULL); 
            m_activeIsolateCount --;
            locker.notifyAll();
            if (current->m_state != Isolate::EXCEPTION)
                stateTransition(current, Isolate::STOPPED); // otherwise it could be Exception

            current->m_core = NULL;
        }
    }

    void Aggregate::waitUntilNoIsolates()
    {
        SCOPE_LOCK_NAMED(locker, m_globals->m_lock) {
            while (m_activeIsolateCount > 0) {
                locker.wait();
            }

            class Scavenger: public Globals::IsolateMap::Iterator
            {
                FixedHeapArray<Isolate*>& m_array;
            public:
                Scavenger(FixedHeapArray<Isolate*>& array): m_array(array) {}
                virtual void each(int32_t, FixedHeapRef<Isolate> isolate) {
                    // Can't just destroyIsolate(), because that would be a concurrent modification.
                    // Can't use VMPI_alloca because we don't have a gc heap.
                    m_array.resize(m_array.length + 1); // suboptimal but good enough for now.
                    m_array.values[m_array.length - 1] = isolate;
                }
            };
            /*
            FixedHeapArray<Isolate*> array;
            Scavenger scavenger(array);
            m_globals->m_isolateMap.ForEach(scavenger);
            for (int i = 0; i < array.length; i++) {
                destroyIsolate(array.values[i]);
            }
            array.deallocate();
            */
        }
    }

    int64_t Aggregate::Globals::newChannelGuid() {
        AvmAssert(m_lock.isLockedByCurrentThread());
        // FIXME check wraparound
        return m_nextChannelGuid ++; 
    }

    FixedHeapRef<PromiseChannel> Aggregate::allocatePromiseChannel(int32_t senderGiid, int32_t receiverGiid)
    {
        SCOPE_LOCK(m_globals->m_lock) {
            MMgc::GC* gc = NULL;
            Isolate* isolate = m_globals->at(senderGiid);
            if (isolate && isolate->targetCore() != NULL)
                gc = isolate->targetCore()->gc;
            int64_t guid = m_globals->newChannelGuid();

            FixedHeapRef<PromiseChannel> channel(mmfx_new(PromiseChannel(guid, 
                                                                         senderGiid, 
                                                                         receiverGiid, gc)));
            // m_channelMap is protected by m_globals->m_lock
            SCOPE_LOCK(m_globals->m_channelMap.m_lock) {
                m_globals->m_channelMap.InsertItem(guid, channel);
            }
            return channel;
        }
        // not reached
        FixedHeapRef<PromiseChannel> dummy;
        return dummy;
    }

   
    void Aggregate::closeChannelsWithEndpoint(Isolate* endpoint)
    {

        SCOPE_LOCK(m_commlock) { 
            // FIXME who needs m_commlock ?
            
            class CloseEndpoint: public Globals::PromiseChannelMap::Iterator
            {
            public:
                Isolate* endpoint;
                PromiseChannel** toDelete;
                int& count;
                
                CloseEndpoint(Isolate* endpoint, PromiseChannel** toDelete, int& count): 
                    endpoint(endpoint), toDelete(toDelete), count(count) {}
                virtual void each(int64_t guid, PromiseChannel* channel) 
                {
                    (void)guid;
                    if (channel->isEndpoint(endpoint)) {
                        channel->close(endpoint->desc);
                    }
                    
                    if (channel->RefCount() == 0) {
                        toDelete[count++] = channel;
                    }
                }
                
            virtual ~CloseEndpoint() {}
            };
            
            AvmAssert(m_globals->m_lock.isLockedByCurrentThread());

            int count = 0;
            MMgc::GC::AllocaAutoPtr _autoAlloca;
            PromiseChannel** toDelete = (PromiseChannel**) VMPI_alloca(AvmCore::getActiveCore(), _autoAlloca, 
                                                                       sizeof(PromiseChannel*)*m_globals->m_channelMap.GetNumItems());
            
            // Goes through the all the channels, good enough for now.
            CloseEndpoint closeEndpoint(endpoint, toDelete, count);
            SCOPE_LOCK(m_globals->m_channelMap.m_lock) {
                // FIXME review what protection is needed by CloseEndpoint?
                m_globals->m_channelMap.ForEach(closeEndpoint);
                for (int i = 0; i < count; i++) {
                    destroyPromiseChannel(toDelete[i]);
                }
            }
        }
    }

    void Aggregate::closePromiseChannel(PromiseChannel* channel, int32_t endpoint_giid)
    {
        if (channel->sender < 0) {
            // event channel
            SCOPE_LOCK(m_globals->m_lock) {
                Isolate* isolate = m_globals->at(-channel->sender);
                AvmAssert(isolate != NULL);
                if (isolate) {
                    AvmAssert(!m_commlock.isLockedByCurrentThread());
                    SCOPE_LOCK(isolate->m_listenerLock) {
                        unsigned int listenerCount = isolate->m_listeners.length();
                        for (unsigned int i = 0; i < listenerCount; i++) {
                            if (isolate->m_listeners.get(i)->channel->channelGuid == channel->channelGuid) {
                                mmfx_delete(isolate->m_listeners.removeAt(i));
                                break;
                            }
                        }
                        AvmAssertMsg(listenerCount == isolate->m_listeners.length() + 1, "Channel not found");
                    }
                }
            }
        }
        
        SCOPE_LOCK_NAMED(lk, m_commlock) {
            // detect
            if (channel) {
                // wait for communication only on a given channel to stop
                while (channel->m_commInProgress > 0) 
                    lk.wait();
                AvmAssert(m_commlock.isLockedByCurrentThread());
                channel->close(endpoint_giid);
            }
        }
    }

    bool Aggregate::beginChannelOp(PromiseChannel* channel, bool item_sent)
    {
        bool result = false;
        SCOPE_LOCK_NAMED(lk, m_commlock) {
            if (channel == NULL) {
                result =  false;
            }
            else {
                if (item_sent) m_msgInTransit ++;
                channel->m_commInProgress ++;
                m_commInProgress ++;
                // if no messages were in transit then some workers
                // waiting for call requests may now be suspended - resume
                // them
                if (item_sent && m_msgInTransit == 1)
                    lk.notifyAll();
                result = true;
            }
        }
        return result;
    }

     
    void Aggregate::endChannelOp(PromiseChannel* channel, bool item_received)
    {
        SCOPE_LOCK_NAMED(lk, m_commlock) {
            AvmAssert(m_commInProgress > 0);
            AvmAssert(channel->m_commInProgress > 0);
            AvmAssert(!item_received || m_msgInTransit > 0);
            if (item_received) m_msgInTransit --;
            m_commInProgress --;
            channel->m_commInProgress --;
            if (m_commInProgress == 0 || m_blockedChannels > 0) {
                lk.notifyAll();
            }
        }
    }

    bool Isolate::processProxies(Toplevel* toplevel) 
    {
        (void)toplevel;
        // No proxy business by default, no need to wait (return true).
        return false;
    }


    bool Aggregate::waitForAnySend(Isolate* isolate, Toplevel* toplevel, bool block)
    {
        // SAFEPOINT_POLL_FAST(m_safepointMgr);
        SCOPE_LOCK_NAMED(lk, m_commlock) {
            if (isolate->isInterrupted())
                return false;

            bool wait = isolate->processProxies(toplevel);

            if (wait && block) {
                // wait only if no (possible) call requests in transit
                if (!m_msgInTransit &&
                    isolate->numAdditionalProxies == 0 &&
                    isolate->numEmptyPromiseOwners == 0 &&
                    m_blockedChannels == 0) {
                    // this prevents two workers going to sleep while
                    // requests still need to be processed
                    // (unfortunate sideeffect of past notify not
                    // preventing future wait on the same condition
                    // variable)
                    m_blockedChannels++;
                    lk.wait();
                    m_blockedChannels--;
                }
            }
        }
        return !isolate->isInterrupted();
    }

}

