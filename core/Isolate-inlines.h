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

#ifndef __avmplus_Isolate_inlines__
#define __avmplus_Isolate_inlines__

#include "FixedHeapUtils-inlines.h"
#include "Channels-inlines.h"


namespace avmplus
{
    
    template <class T>
    IsolateEvent<T>::IsolateEvent(int32_t source, uint32_t previous, uint32_t current)
        : source(source), m_previousState(previous), m_currentState(current) {}


    template <class T>
    void WorkerClassBase<T>::handleLifecycleEvents()
    {
        GCRef<ClassClosure> workerClass = static_cast<ClassClosure*>(this);
        if (m_handleLifecycleEventsMethod == NULL) {
            const TraitsBindingsp td = workerClass->vtable->traits->getTraitsBindings();
            Binding const binding = td->findBinding(workerClass->core()->internStringLatin1("doHandleLifecycleEvents"));
            uint32_t methodId = static_cast<uint32_t>(AvmCore::bindingToMethodId(binding));
            m_handleLifecycleEventsMethod = workerClass->vtable->methods[methodId];
        }
        m_handleLifecycleEventsMethod->coerceEnter(workerClass->toAtom());
    }

    template<class T>
    void WorkerObjectBase<T>::throwError(const char* msgz)
    {
        AvmCore* core = AvmCore::getActiveCore();
        Toplevel* toplevel = core->codeContext()->domainEnv()->toplevel();
        Atom error_args[3] = { nullObjectAtom, core->newStringUTF8(msgz)->atom(), core->intToAtom(0) }; 
        core->throwAtom(toplevel->errorClass()->construct(2, error_args));
    }
    
    template<class T>
    void WorkerObjectBase<T>::throwIllegalOperationError(int errorID)
    {
        AvmCore* core = AvmCore::getActiveCore();
        Toplevel* toplevel = core->codeContext()->domainEnv()->toplevel();
		toplevel->builtinClasses()->get_IllegalOperationErrorClass()->throwError(errorID);
	}

    template <class T>
    WorkerObjectBase<T>::WorkerObjectBase()
        : giid(Isolate::INVALID_DESC)
        , m_isolate(NULL)
    {}

    template <class T>
    T* WorkerObjectBase<T>::self()
    {
        return static_cast<T*>(this);
    }

    template<class T>
    void WorkerObjectBase<T>::initialize(Isolate *thisIsolate)
    {
        if (thisIsolate == NULL)
        {
            Isolate* parent = self()->core()->getIsolate();
            
            // the following consumes a shared resource (m_globals entry).
            m_isolate = parent->getAggregate()->newIsolate(parent);
            // Can isolate have been deallocated in the meantime? No,
            // because an attempt must be first made to run the isolate
            // and the current isolate is the only one that knows about
            // this new isolate so far.
            // At aggregate termination we'll probably kill all the isolates first.
            
            if (m_isolate == NULL)
                throwError("Worker limit reached");
        } else {
            m_isolate = thisIsolate;
        }
        setIsolate(m_isolate);
    }

    template<class T>
    GCRef<ScriptObject> WorkerObjectBase<T>::setIsolate(Isolate* isolate)
    {
        if (m_isolate == NULL) {
            this->m_isolate = isolate;
        } else {
            AvmAssert(m_isolate == isolate);
        }
        this->giid = isolate->desc;
        AvmAssert(self()->toplevel()->lookupInternedObject(m_isolate, NULL) == NULL); // always check the intern table first
        return self()->toplevel()->lookupInternedObject(m_isolate, self());
    }

    
    template<class T>
    int32_t WorkerObjectBase<T>::descriptor()
    {
        return this->giid;
    }
    
    template<class T>
    WorkerObjectBase<T>::~WorkerObjectBase()
    {
        m_isolate = NULL;
    }

    template<class T>
    bool WorkerObjectBase<T>::isParentOf(WorkerObjectBase* worker)
    {
        if (worker == NULL)
			self()->toplevel()->checkNull(worker, "worker");
        if (this->giid == Isolate::INVALID_DESC 
            || worker->giid == Isolate::INVALID_DESC
            || worker->m_isolate == NULL)
			self()->toplevel()->throwArgumentError(kInvalidArgumentError);

        return worker->m_isolate->parentDesc == this->giid;
    }

    template<class T>
    bool WorkerObjectBase<T>::isPrimordial()
    {
        AvmAssert(this->giid >= 0);
        // if this isolate has had terminate called on it before the run loop
        // has started then its m_isolate value could be NULL since we may
        // be calling this method from Worker.current (see setDescriptors)
        return m_isolate ? m_isolate->isPrimordial() : false;
	}

    template<class T>
    bool WorkerObjectBase<T>::startWithChannels(ArrayObject* channels)
    {
        return internalStartWithChannels(channels);
    }

    template<class T>
    PromiseChannelObject* WorkerObjectBase<T>::newEventChannel()
    {
        PromiseChannelClass* promiseChannelClass = self()->toplevel()->builtinClasses()->get_PromiseChannelClass();
        PromiseChannelObject* channelObj = (PromiseChannelObject*)promiseChannelClass->newInstance();
        Isolate* current = self()->core()->getIsolate();
        IsolateEventListener* listener = current->getAggregate()->newEventListener(this->giid, current);
        // negative value b/c of the convention for event
        channelObj->initializeWithChannel(listener->channel);
        return channelObj;
    }

    template <class T>
    Stringp WorkerObjectBase<T>::get_state()
    {
        Aggregate* aggregate = m_isolate->getAggregate();
        Isolate::State code = aggregate->queryState(m_isolate);
        AvmAssert(code >= Isolate::NEW && code <= Isolate::EXCEPTION);
        if (code == Isolate::STARTING)
        {
            code = Isolate::RUNNING;
        }
        else if (code == Isolate::FINISHING)
        {
            code = Isolate::TERMINATED;
        }
        return self()->core()->workerStates[code];
     }
    
    template <class T>
    bool WorkerObjectBase<T>::stopInternal(bool shouldWait) 
    {
        Aggregate* aggregate = m_isolate->getAggregate();
        if (aggregate->isPrimordial(giid))  {
            aggregate->selfExit(self()->toplevel());
            return true; // not reached
        } else {
            return aggregate->requestExit(shouldWait, descriptor(), self()->toplevel());
        }
    }
    
    template <class T>
    ScriptObject* WorkerObjectBase<T>::cloneNonSlots(ClassClosure* classClosure, Cloner&) const
    {

        ScriptObject* prev = classClosure->toplevel()->lookupInternedObject(m_isolate, NULL);
        if (prev != NULL) {
            return static_cast<T*>(prev);
        }

        WorkerObjectBase<T>* clone = new (classClosure->gc(), 
                                   classClosure->ivtable()->getExtraSize())
            T(classClosure->ivtable(), classClosure->prototypePtr());
        clone->giid = giid;
        //clone->clearBlobs();
        clone->m_isolate = m_isolate;
        // FIXME assert that Worker is final or else this is wrong
        return clone->self();
    }


    template <class T>
    void WorkerObjectBase<T>::setSharedProperty(String* key, Atom value)
    {
        StUTF8String buf(key);
        ChannelItem item = m_isolate->makeChannelItem(self()->toplevel(), value);
        m_isolate->setSharedProperty(buf.c_str(), buf.length(), item);
    }

    template <class T>
    Atom WorkerObjectBase<T>::getSharedProperty(String* key)
    {
        if (m_isolate)
        {
            StUTF8String buf(key);
            ChannelItem item;
            bool ok = m_isolate->getSharedProperty(buf.c_str(), buf.length(), &item);
            if (ok) 
            {
                return m_isolate->extractAtom(self()->toplevel(), item);
            }
        }
        return undefinedAtom;
    }

    template<class T>
    bool WorkerObjectBase<T>::startVeryInternal()
    {
        if (m_isolate->getAggregate()->queryState(m_isolate) != Isolate::NEW)
            throwIllegalOperationError(kWorkerAlreadyStarted);
        
        return internalStartWithChannels(NULL);
    }
    
    template <class T>
    bool WorkerObjectBase<T>::internalStartWithChannels(ArrayObject* channelArray)
    {
        if (m_isolate->failed())
            throwIllegalOperationError(kFailedWorkerCannotBeRestarted);
        AvmCore* core = self()->core();
        if (channelArray) {
            FixedHeapArray<FixedHeapRef<PromiseChannel> >&  channels = m_isolate->m_initialChannels;
            channels.allocate(channelArray->get_length());
            PromiseChannelClass* promiseChannelClass = self()->toplevel()->builtinClasses()->get_PromiseChannelClass();
            for (int i = 0; i < channels.length; i++) {
                Atom entry = channelArray->getUintProperty(i);
                if (AvmCore::istype(entry, promiseChannelClass->ivtable()->traits)) {
                    PromiseChannelObject* channelObj = (PromiseChannelObject*)core->atomToScriptObject(entry);
                    // FIXME how do we guarantee that the PromiseChannel won't get closed and reclaimed?
                    // We could validate here.
                    channels.values[i] = channelObj->m_channel;
                } else {
                    channels.deallocate();
                    throwError("not a PromiseChannel");
                }
            }
        } 
        Aggregate* aggregate = m_isolate->getAggregate();
        
        ByteArrayObject* byteCode = self()->getByteCode();
        // stash away in non-gc'd memory
        // If byteCode == NULL, will try to get from primordial (shell only).
        m_isolate->copyByteCode(byteCode);
        self()->clearByteCode();

        if (aggregate->spawnAndWaitForInitialization(core, m_isolate)) { // FIXME atomicity here?
            return true;
        } else {
            // spawnAndWaitForInitialization() will recordSpawnFailure()
            // Not programmer's fault (unlike wrong argument types), don't throw, just return false.
            return false;
        }
    }

    template <class T>
    T* WorkerDomainObjectBase<T>::self()
    {
        return static_cast<T*>(this);
    }

    template <class T>
    ObjectVectorObject* WorkerDomainObjectBase<T>::listWorkers() 
    {
        return self()->core()->getIsolate()->getAggregate()->listWorkers(self()->toplevel());
    }

}

#endif /* __avmplus_Isolate_inlines__ */
