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

namespace avmplus {

    MutexObject::State::State()
        : m_recursion_count(0)
    {
        VMPI_recursiveMutexInit(&m_mutex);        
    }

    void MutexObject::State::destroy()
    {
        bool success = VMPI_recursiveMutexTryLock(&m_mutex);
        if (success) {
            // only access m_recursion_count if we know it's locked
            int saved_recursion_count = m_recursion_count;
            VMPI_recursiveMutexUnlock(&m_mutex);
            while (saved_recursion_count > 0) {
                saved_recursion_count = --m_recursion_count;
                VMPI_recursiveMutexUnlock(&m_mutex);
            }
            VMPI_recursiveMutexDestroy(&m_mutex);
            mmfx_delete(this);
        } else {
            // It's locked by a thread but not reachable through GC objecs.
            // We can't mmfx_delete(). We'll have leaks! but that's sortof OK.
            // We should have a final scavenge pass for such objects, when
            // all worker threads are stopped.
        }

    }

    MutexObject::MutexObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_state(NULL)
    {
    }

    void MutexObject::ctor() 
    {
        m_state = mmfx_new(MutexObject::State());
    }

    MutexObject::~MutexObject() 
    {
        m_state = NULL;
    }

    const int MAX_RECURSION = 1024; // that should be enough

    void MutexObject::lock()
    {
        VMPI_recursiveMutexLock(&m_state->m_mutex);
        m_state->m_recursion_count ++;
        if (m_state->m_recursion_count > MAX_RECURSION) {
            VMPI_recursiveMutexUnlock(&m_state->m_mutex);
            Atom args[2] = { nullObjectAtom, core()->newStringUTF8("Lock recursion maximum exceeded!")->atom() }; 
            core()->throwAtom(toplevel()->errorClass()->construct(1, args));
        }
    }
    
    void MutexObject::unlock()
    {
        if (!VMPI_recursiveMutexTryLock(&m_state->m_mutex)) {
            // we'd better own the mutex, or else we're missing a pairing lock().
            // And we need to protect the recursion count anyway.
            Atom args[2] = { nullObjectAtom, core()->newStringUTF8("Unlock() with no lock!")->atom() }; 
            core()->throwAtom(toplevel()->errorClass()->construct(1, args));
        }
        m_state->m_recursion_count --;
        AvmAssert(m_state->m_recursion_count >= 0);
        VMPI_recursiveMutexUnlock(&m_state->m_mutex); // This one is internal.
        VMPI_recursiveMutexUnlock(&m_state->m_mutex); // This one is the one requested by user code.
        
    }

    bool MutexObject::tryLock()
    {
        bool result = VMPI_recursiveMutexTryLock(&m_state->m_mutex);
        if (result == true) {
            m_state->m_recursion_count ++;
            if (m_state->m_recursion_count > MAX_RECURSION) {
                VMPI_recursiveMutexUnlock(&m_state->m_mutex);
                Atom args[2] = { nullObjectAtom, core()->newStringUTF8("Lock recursion maximum exceeded!")->atom() }; 
                core()->throwAtom(toplevel()->errorClass()->construct(1, args));
            }
        }
        return result;
    }

    ScriptObject* MutexObject::cloneNonSlots(ClassClosure* targetClosure, Cloner&) const
    {
        MutexObject* clone =   
            new (targetClosure->gc(), MMgc::kExact, targetClosure->ivtable()->getExtraSize()) MutexObject(targetClosure->ivtable(), targetClosure->prototypePtr());
        clone->m_state = this->m_state;
        return clone;
    }

    MutexClass::MutexClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }


    ConditionObject::ConditionObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
    {
        VMPI_condVarInit(&m_condVar);
    }

    void ConditionObject::broadcast()
    {
        VMPI_condVarBroadcast(&m_condVar);
    }

    void ConditionObject::signal()
    {
        VMPI_condVarSignal(&m_condVar);
    }

    void ConditionObject::wait(MutexObject* lock)
    {
        // FIXME throw if lock == null
        VMPI_condVarWait(&m_condVar, &lock->m_state->m_mutex);
    }

    ScriptObject* ConditionObject::cloneNonSlots(ClassClosure* targetClosure, Cloner& ) const
    {
        ConditionObject* clone =   
            new (targetClosure->gc(), MMgc::kExact, targetClosure->ivtable()->getExtraSize()) ConditionObject(targetClosure->ivtable(), targetClosure->prototypePtr());
        clone->m_condVar = this->m_condVar;
        return clone;
    }

    ConditionObject::~ConditionObject()
    {
        VMPI_condVarDestroy(&m_condVar);
    }


    ConditionClass::ConditionClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }



}

