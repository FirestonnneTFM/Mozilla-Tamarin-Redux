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
    
	//
	// WorkerObjectBase<T>
	//
    template<class T>
    void WorkerObjectBase<T>::throwIllegalOperationError(int errorID)
    {
        AvmCore* core = AvmCore::getActiveCore();
        Toplevel* toplevel = core->codeContext()->domainEnv()->toplevel();
		toplevel->builtinClasses()->get_IllegalOperationErrorClass()->throwError(errorID);
	}

    template <class T>
    WorkerObjectBase<T>::WorkerObjectBase()
        : m_isolate(NULL)
    {}

    template <class T>
    T* WorkerObjectBase<T>::self()
    {
        return static_cast<T*>(this);
    }

    template<class T>
    void WorkerObjectBase<T>::initialize(Isolate *isolate)
    {
        if (isolate == NULL)
        {
            Isolate* parent = self()->core()->getIsolate();
            
            // the following consumes a shared resource (m_globals entry).
            isolate = parent->getAggregate()->newIsolate(parent);
            // Can isolate have been deallocated in the meantime? No,
            // because an attempt must be first made to run the isolate
            // and the current isolate is the only one that knows about
            // this new isolate so far.
            // At aggregate termination we'll probably kill all the isolates first.

			AvmAssert(isolate != NULL); // the only way this should happen is if we run out of ids; you'd need > 2 billion active workers
		}

        setIsolate(isolate);
		self()->toplevel()->addWorker(self());
    }

    template<class T>
    GCRef<ScriptObject> WorkerObjectBase<T>::setIsolate(Isolate* isolate)
    {
        if (m_isolate == NULL) {
            m_isolate = isolate;
        } else {
            AvmAssert(m_isolate == isolate);
        }
        AvmAssert(self()->toplevel()->getInternedObject(m_isolate) == NULL); // always check the intern table first
        self()->toplevel()->internObject(m_isolate, self());
		return self();
    }

    
    template<class T>
	Isolate::descriptor_t WorkerObjectBase<T>::descriptor() const
    {
        return m_isolate->getDesc();
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
        if (m_isolate->getDesc() == Isolate::INVALID_DESC 
            || worker->m_isolate == NULL)
			self()->toplevel()->throwArgumentError(kInvalidArgumentError);

        return worker->m_isolate->getParentDesc() == m_isolate->getDesc();
    }

    template<class T>
    bool WorkerObjectBase<T>::isPrimordial() const
    {
        AvmAssert(m_isolate != NULL);
        AvmAssert(m_isolate->getDesc() >= 0);
        // if this isolate has had terminate called on it before the run loop
        // has started then its m_isolate value could be NULL since we may
        // be calling this method from Worker.current (see setDescriptors)
        return m_isolate->isPrimordial();
	}

    template<class T>
    bool WorkerObjectBase<T>::start( )
    {
        return startInternal();
    }

    template <class T>
    Stringp WorkerObjectBase<T>::get_state()
    {
        Aggregate* aggregate = m_isolate->getAggregate();
        Isolate::State code = aggregate->queryState(m_isolate);
        AvmAssert(code >= Isolate::NEW && code <= Isolate::EXCEPTION);
        if (code == Isolate::STARTING)
        {
            code = Isolate::NEW;
        }
        else if (code == Isolate::FINISHING)
        {
            code = Isolate::RUNNING;
        }
        return self()->core()->workerStates[code];
     }
    
    template <class T>
    bool WorkerObjectBase<T>::stopInternal() 
    {
        Aggregate* aggregate = m_isolate->getAggregate();
        if (aggregate->isPrimordial(m_isolate->getDesc()))  {
            aggregate->throwWorkerTerminatedException(self()->toplevel());
            return true; // not reached
        } else {
            return aggregate->requestIsolateExit(m_isolate->getDesc(), self()->toplevel());
        }
    }
    

    template <class T>
    void WorkerObjectBase<T>::setSharedProperty(String* key, Atom value)
    {
        StUTF8String buf(key);
        ChannelItem* item = m_isolate->makeChannelItem(self()->toplevel(), value);
        m_isolate->setSharedProperty(buf, item);
    }

    template <class T>
    Atom WorkerObjectBase<T>::getSharedProperty(String* key)
    {
		Atom result = undefinedAtom;
		StUTF8String buf(key);
		ChannelItem* item;
		const bool cOk = m_isolate->getSharedProperty(buf, &item);
		if (cOk) 
		{
			result =  item->getAtom(self()->toplevel());
		}

        return result;
    }

    template<class T>
    bool WorkerObjectBase<T>::startVeryInternal()
    {
        if (m_isolate->getAggregate()->queryState(m_isolate) != Isolate::NEW)
            throwIllegalOperationError(kWorkerAlreadyStarted);
        
        if (m_isolate->getParentDesc() != AvmCore::getActiveCore()->getIsolate()->getDesc())
            throwIllegalOperationError(kWorkerIllegalCallToStart);

        return startInternal();
    }
    
    template <class T>
    bool WorkerObjectBase<T>::startInternal( )
    {
        if (m_isolate->hasFailed())
            throwIllegalOperationError(kFailedWorkerCannotBeRestarted);
        Aggregate* aggregate = m_isolate->getAggregate();
        
        ByteArrayObject* byteCode = self()->getByteCode();
        // stash away in non-gc'd memory
        // If byteCode == NULL, will try to get from primordial (shell only).
        m_isolate->copyByteCode(byteCode);
        self()->clearByteCode();

        if (aggregate->spawnIsolateThread(m_isolate)) { // FIXME atomicity here?
            return true;
        } else {
            // spawnIsolateThread() will recordSpawnFailure()
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
	

	//
	// Aggregate
	//
	REALLY_INLINE bool Aggregate::isPrimordial(Isolate::descriptor_t giid) const
    {
        return giid == m_primordialGiid;
    }
	
	
}

#endif /* __avmplus_Isolate_inlines__ */

