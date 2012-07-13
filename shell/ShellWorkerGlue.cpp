/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

#include "avmshell.h"
namespace avmshell {
    using namespace avmplus;
    ShellWorkerObject::ShellWorkerObject(avmplus::VTable* vtable, avmplus::ScriptObject* prototype)
        : avmplus::ScriptObject(vtable, prototype)
    {
    }
    
    void ShellWorkerObject::clearByteCode()
    {
        set_m_byteCode(NULL);
    }

    void ShellWorkerObject::setByteCode(avmplus::ByteArrayObject* code)
    {
        set_m_byteCode(code);
    }
    
    avmplus::ByteArrayObject* ShellWorkerObject::getByteCode()
    {
        return get_m_byteCode();
    }

    bool ShellWorkerObject::terminate()
    {
        return stopInternal(true);
    }

    int32_t ShellWorkerObject::get_descriptor() const
    {
        return this->giid;
    }
    
    avmplus::PromiseChannelObject* ShellWorkerObject::newEventChannel()
    {
        return avmplus::WorkerObjectBase<ShellWorkerObject>::newEventChannel();
    }

    avmplus::PromiseObject* ShellWorkerObject::startInternal()
    {

        using namespace avmplus;
        Aggregate* aggregate = m_isolate->getAggregate();
        int32_t desc = m_isolate->desc;
        int32_t parentDesc = m_isolate->parentDesc;
        
        FixedHeapArray<FixedHeapRef<PromiseChannel> >&  channels = m_isolate->m_initialChannels;
        channels.allocate(2);
        FixedHeapRef<PromiseChannel> outChannel(aggregate->allocatePromiseChannel(parentDesc, desc));
        FixedHeapRef<PromiseChannel> incChannel(aggregate->allocatePromiseChannel(desc, parentDesc));
        AvmAssert(outChannel->gc() != NULL);
        AvmAssert(incChannel->gc() == NULL);
        channels.values[0] = outChannel;
        channels.values[1] = incChannel;

        uint32_t global_gpid = aggregate->nextPromiseGID();
        m_isolate->m_global_gpid = global_gpid;
        bool success = startVeryInternal();
        if (!success) 
            return false;
        ShellToplevel* tl = static_cast<ShellToplevel*>(toplevel());
        avmplus::PromiseClass* promiseClass = tl->shellClasses->get_PromiseClass();
        PromiseObject* result = promiseClass->createWithGID(outChannel,
                                                     incChannel,
                                                     true, // global
                                                     global_gpid);
        // Promise representing the global scope should not keep the scope
        // object alive.
        GCRef<PromiseHelperClass> promiseHelperClass = tl->shellClasses->get_PromiseHelperClass();
        promiseHelperClass->schedulePromiseCollection(result);
        return result;        
    }


    ShellWorkerClass::ShellWorkerClass(avmplus::VTable *cvtable)
        : avmplus::ClassClosure(cvtable)
    {
        AvmAssert(avmplus::AvmCore::getActiveCore() == cvtable->core());
        createVanillaPrototype();
        
        avmplus::Isolate* ent = core()->getIsolate();
        // By convention nobody will mutate the isolate table entry
        // except the current thread, as long as the entry has a nonnegative giid
        // so no need for locking.
        
        ShellWorkerObject* current = (ShellWorkerObject*)constructObject();
        set_m_current(current);
        current->setIsolate(ent);
    }
    
    void ShellWorkerClass::pr(avmplus::Stringp s)
    {
        printf("%s\n", avmplus::StUTF8String(core()->internString(s)).c_str());
        fflush(stdout);
    }
    
    ShellWorkerObject* ShellWorkerClass::getCurrentWorker()
    {
        // Exposing accessor as public.
        return get_m_current();
    }
    
}
