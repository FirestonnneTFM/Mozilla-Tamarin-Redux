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

namespace avmplus
{
    DomainEnv::DomainEnv(AvmCore* core, Domain* domain, DomainEnv* base, uint32_t baseCount)
        : m_namedScriptEnvsList(core->GetGC(), 0)
        , m_domain(domain)
        , m_globalMemoryScratch(mmfx_new0(Scratch))
        , m_globalMemoryBase(m_globalMemoryScratch->scratch)
        , m_globalMemorySize(GLOBAL_MEMORY_MIN_SIZE)
        , m_baseCount(baseCount)
    {
        WB(core->GetGC(), this, &this->m_bases[0], this);
        for (uint32_t i = 1; i < baseCount; ++i)
        {
            WB(core->GetGC(), this, &this->m_bases[i], base->m_bases[i-1]);
        }

    #ifdef _DEBUG
        List<Domain*> dl(core->GetGC());
        for (Domain* di = m_domain; di != NULL; di = di->base())
            dl.add(di);
        
        List<DomainEnv*> el(core->GetGC());
        for (DomainEnv* di = this; di != NULL; di = di->base())
            el.add(di);
        
        AvmAssert(dl.size() == el.size());
        for (uint32_t i = 0, n = el.size(); i < n; ++i)
        {
            Domain* d = dl[i];
            DomainEnv* e = el[i];
            AvmAssert(e->domain() == d);
        }
    #endif
    }

    DomainEnv* DomainEnv::newDomainEnv(AvmCore* core, Domain* domain, DomainEnv* base)
    {
        uint32_t baseCount = (base ? base->m_baseCount : 0) + 1;
        // Note that we deliberately overallocate by one here (the proper
        // amount is baseCount-1) so that we always have one, zeroed-out
        // entry at the end. This allows us to always use "m_bases[1]"
        // to get our immediate base, even if our base is NULL, thus
        // avoiding a check in the implementation of base().
        uint32_t extra = baseCount * sizeof(DomainEnv*);
        return new (core->GetGC(), extra) DomainEnv(core, domain, base, baseCount);
    }

    DomainEnv::~DomainEnv()
    {
        mmfx_delete(m_globalMemoryScratch);
    }

    Toplevel* DomainEnv::toplevel() const
    {
        if(m_toplevel) return m_toplevel;
        if(base()) return base()->toplevel();
        AvmAssert(0);
        return NULL;
    }

    bool DomainEnv::set_globalMemory(ScriptObject* providerObject)
    {
        if (!providerObject || !providerObject->getGlobalMemoryProvider())
        {
            // null obj -- use scratch
            if (m_globalMemoryProviderObject) // unsubscribe from current if any
                globalMemoryUnsubscribe(m_globalMemoryProviderObject);
            // remember NULL obj
            m_globalMemoryProviderObject = NULL;
            // point at scratch mem
            notifyGlobalMemoryChanged(m_globalMemoryScratch->scratch, GLOBAL_MEMORY_MIN_SIZE);
        }
        else if (!globalMemorySubscribe(providerObject))
        {
            // failed... do nothing
            return false;
        }
        else
        {
            // success on globalMemorySubscribe would have led to notifyGlobalMemoryChanged
            // success... unsubscribe from original
            if (m_globalMemoryProviderObject)
                globalMemoryUnsubscribe(m_globalMemoryProviderObject);
            // remember the new one
            m_globalMemoryProviderObject = providerObject;
        }
        return true;
    }

    // memory changed so go through and update all reference to both the base
    // and the size of the global memory
    void DomainEnv::notifyGlobalMemoryChanged(uint8_t* newBase, uint32_t newSize)
    {
        AvmAssert(newBase != NULL); // real base address
        AvmAssert(newSize >= GLOBAL_MEMORY_MIN_SIZE); // big enough

        m_globalMemoryBase = newBase;
        m_globalMemorySize = newSize;
    }

    bool DomainEnv::globalMemorySubscribe(ScriptObject* providerObject) 
    {
        GlobalMemoryProvider* provider = providerObject->getGlobalMemoryProvider();
        return provider ? provider->addSubscriber(this) : false;
    }
 
    bool DomainEnv::globalMemoryUnsubscribe(ScriptObject* providerObject)
    {
        GlobalMemoryProvider* provider = providerObject->getGlobalMemoryProvider();
        return provider ? provider->removeSubscriber(this) : false;
    }
}


