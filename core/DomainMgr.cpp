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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

DomainMgrFP10::DomainMgrFP10(AvmCore* _core) : core(_core)
{
}

DomainMgrFP10::~DomainMgrFP10()
{
}

void DomainMgrFP10::addNamedTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* traits)
{
    // look for class in VM-wide type table, *without* recursion
    // (don't look for traits in pool, ever.)
    Traits* t = (Traits*)pool->domain->m_namedTraits->get(name, ns);

    if (t == NULL)
    {
        pool->domain->m_namedTraits->add(name, ns, (Binding)traits);
    }
}

void DomainMgrFP10::addNamedInstanceTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* itraits)
{
    // look for class in VM-wide type table, *without* recursion
    Traits* t = (Traits*)pool->domain->m_namedTraits->get(name, ns);

    // look for class in current pool
    if (t == NULL)
    {
        t = (Traits*)pool->m_namedTraits->get(name, ns);
    }

    if (t == NULL)
    {
        pool->m_namedTraits->add(name, ns, (Binding)itraits);
    }
}

Traits* DomainMgrFP10::findBuiltinTraitsByName(PoolObject* pool, Stringp name)
{
    return (Traits*)pool->m_namedTraits->getName(name);
}

Traits* DomainMgrFP10::findTraitsInDomainByNameAndNSImpl(Domain* domain, Stringp name, Namespacep ns)
{
    Traits* traits = NULL;
    for (uint32_t i = domain->m_baseCount; i > 0; --i)
    {
        Domain* d = domain->m_bases[i-1];
        traits = (Traits*)d->m_namedTraits->get(name, ns);
        if (traits != NULL)
            break;
    }
    return traits;
}

Traits* DomainMgrFP10::findTraitsInPoolByNameAndNSImpl(PoolObject* pool, Stringp name, Namespacep ns)
{
    // look for class in VM-wide type table
    Traits* t = findTraitsInDomainByNameAndNSImpl(pool->domain, name, ns);

    // look for class in current ABC file
    if (t == NULL)
    {
        t = (Traits*)pool->m_namedTraits->get(name, ns);
    }
    
    return t;
}

Traits* DomainMgrFP10::findTraitsInPoolByNameAndNS(PoolObject* pool, Stringp name, Namespacep ns)
{
    return findTraitsInPoolByNameAndNSImpl(pool, name, ns);
}

Traits* DomainMgrFP10::findTraitsInPoolByMultiname(PoolObject* pool, const Multiname& multiname)
{
    // do full lookup of multiname, error if more than 1 match
    // return Traits if 1 match, NULL if 0 match, BIND_AMBIGUOUS >1 match
    Traits* found = NULL;
    if (multiname.isBinding())
    {
        // multiname must not be an attr name, have wildcards, or have runtime parts.
        for (int32_t i=0, n=multiname.namespaceCount(); i < n; i++)
        {
            Traits* t = findTraitsInPoolByNameAndNSImpl(pool, multiname.getName(), multiname.getNamespace(i));
            if (t != NULL)
            {
                if (found == NULL)
                {
                    found = t;
                }
                else if (found != t)
                {
                    // ambiguity
                    return (Traits*)BIND_AMBIGUOUS;
                }
            }
        }
    }
    return found;
}

static void addScript(Stringp name, Namespacep ns, MethodInfo* script, List<MethodInfo*>& scriptList, MultinameHashtable* scriptMap)
{
    scriptList.add(script);
    // note that this is idx+1 -- can't use idx=0 since that's BIND_NONE
    uint32_t idx = scriptList.size();
    scriptMap->add(name, ns, Binding(idx));
}

void DomainMgrFP10::addNamedScript(PoolObject* pool, Stringp name, Namespacep ns, MethodInfo* script)
{
    if (ns->isPrivate())
    {
        addScript(name, ns, script, pool->m_namedScriptsList, pool->m_namedScriptsMap);
    }
    else
    {
        Domain* domain = pool->domain;
        MethodInfo* s = findScriptInDomainByNameAndNSImpl(domain, name, ns);
        if (s == NULL)
        {
            addScript(name, ns, script, domain->m_namedScriptsList, domain->m_namedScriptsMap);
        }
    }
}

MethodInfo* DomainMgrFP10::findScriptInDomainByNameAndNSImpl(Domain* domain, Stringp name, Namespacep ns)
{
    for (uint32_t i = domain->m_baseCount; i > 0; --i)
    {
        Domain* d = domain->m_bases[i-1];
		Binding b = d->m_namedScriptsMap->get(name, ns);
        if (b != BIND_NONE)
        {
            // BIND_AMBIGUOUS not possible here
            return d->m_namedScriptsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return NULL;
}

MethodInfo* DomainMgrFP10::findScriptInDomainByMultinameImpl(Domain* domain, const Multiname& multiname)
{
    for (uint32_t i = domain->m_baseCount; i > 0; --i)
    {
        Domain* d = domain->m_bases[i-1];
		Binding b = d->m_namedScriptsMap->getMulti(multiname);
        if (b != BIND_NONE)
        {
            return (b == BIND_AMBIGUOUS) ? 
                    (MethodInfo*)BIND_AMBIGUOUS : 
                    d->m_namedScriptsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return NULL;
}

MethodInfo* DomainMgrFP10::findScriptInPoolByNameAndNSImpl(PoolObject* pool, Stringp name, Namespacep ns)
{
    MethodInfo* f = findScriptInDomainByNameAndNSImpl(pool->domain, name, ns);
    if (f == NULL)
    {
		Binding b = pool->m_namedScriptsMap->get(name, ns);
        if (b != BIND_NONE)
        {
            // BIND_AMBIGUOUS not possible here
            f = pool->m_namedScriptsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return f;
}

MethodInfo* DomainMgrFP10::findScriptInPoolByMultiname(PoolObject* pool, const Multiname& multiname)
{
    MethodInfo* f = findScriptInDomainByMultinameImpl(pool->domain, multiname);
    if (f == NULL)
    {
		Binding b = pool->m_namedScriptsMap->getMulti(multiname);
        if (b != BIND_NONE)
        {
            f = (b == BIND_AMBIGUOUS) ? 
                    (MethodInfo*)BIND_AMBIGUOUS : 
                    pool->m_namedScriptsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return f;
}

void DomainMgrFP10::addNamedScriptEnvs(AbcEnv* abcEnv, const List<ScriptEnv*>& envs)
{
    HeapHashtable* ht = new(core->GetGC()) HeapHashtable(core->GetGC());
    for (uint32_t i = 0, n = envs.size(); i < n; ++i)
    {
        ScriptEnv* se = envs[i];
        AvmAssert(se->abcEnv() == abcEnv);
        MethodInfo* mi = se->method;
        ht->add((Atom)mi, (Atom)se);
    }
    
    AvmAssert(abcEnv->m_namedScriptEnvsList.size() == 0);
    PoolObject* pool = abcEnv->pool();
    abcEnv->m_namedScriptEnvsList.ensureCapacity(pool->m_namedScriptsList.size());
    for (uint32_t i = 0, n = pool->m_namedScriptsList.size(); i < n; ++i)
    {
        MethodInfo* mi = pool->m_namedScriptsList[i];
        AvmAssert(mi->pool() == abcEnv->pool());
        ScriptEnv* se = (ScriptEnv*)ht->get((Atom)mi);
        AvmAssert(se != (ScriptEnv*)undefinedAtom);
        abcEnv->m_namedScriptEnvsList.set(i, se);
    }
    
    // since a DomainEnv can be shared among several AbcEnv's, 
    // its list might not be empty.
    Domain* domain = pool->domain;
    abcEnv->domainEnv()->m_namedScriptEnvsList.ensureCapacity(domain->m_namedScriptsList.size());
    for (uint32_t i = 0, n = domain->m_namedScriptsList.size(); i < n; ++i)
    {
        MethodInfo* mi = domain->m_namedScriptsList[i];
        if (mi->pool() != abcEnv->pool())
            continue; 
        ScriptEnv* se = (ScriptEnv*)ht->get((Atom)mi);
        AvmAssert(se != (ScriptEnv*)undefinedAtom);
        abcEnv->domainEnv()->m_namedScriptEnvsList.set(i, se);
    }
    
    delete ht;

#ifdef VMCFG_LOOKUP_CACHE
    // Adding scripts to a domain always invalidates the lookup cache.
    core->invalidateLookupCache();
#endif
}

ScriptEnv* DomainMgrFP10::findScriptEnvInDomainEnvByMultinameImpl(DomainEnv* domainEnv, const Multiname& multiname)
{
    for (uint32_t i = domainEnv->m_baseCount; i > 0; --i)
    {
        DomainEnv* d = domainEnv->m_bases[i-1];
		Binding b = d->domain()->m_namedScriptsMap->getMulti(multiname);
        if (b != BIND_NONE)
        {
            return (b == BIND_AMBIGUOUS) ? 
                    (ScriptEnv*)BIND_AMBIGUOUS : 
                    d->m_namedScriptEnvsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return NULL;
}

ScriptEnv* DomainMgrFP10::findScriptEnvInDomainEnvByMultiname(DomainEnv* domainEnv, const Multiname& multiname)
{
    return findScriptEnvInDomainEnvByMultinameImpl(domainEnv, multiname);
}

ScriptEnv* DomainMgrFP10::findScriptEnvInAbcEnvByMultiname(AbcEnv* abcEnv, const Multiname& multiname)
{
    // note, lookup order must match findNamedScript!
    ScriptEnv* se = findScriptEnvInDomainEnvByMultinameImpl(abcEnv->domainEnv(), multiname);
    if (se == NULL)
    {
		Binding b = abcEnv->pool()->m_namedScriptsMap->getMulti(multiname);
        if (b != BIND_NONE)
        {
            se = (b == BIND_AMBIGUOUS) ? 
                    (ScriptEnv*)BIND_AMBIGUOUS : 
                    abcEnv->m_namedScriptEnvsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return se;
}

#ifdef DEBUGGER

ScriptEnv* DomainMgrFP10::findScriptEnvInDomainEnvByNameOnlyImpl(DomainEnv* domainEnv, Stringp name)
{
    for (uint32_t i = domainEnv->m_baseCount; i > 0; --i)
    {
        DomainEnv* d = domainEnv->m_bases[i-1];
		Binding b = d->domain()->m_namedScriptsMap->getName(name);
        if (b != BIND_NONE)
        {
            ScriptEnv* f = (ScriptEnv*)d->m_namedScriptEnvsList.get(uint32_t(uintptr_t(b))-1);
            return f;
        }
    }
    return NULL;
}

ScriptEnv* DomainMgrFP10::findScriptEnvInAbcEnvByNameOnly(AbcEnv* abcEnv, Stringp name)
{
    ScriptEnv* se = findScriptEnvInDomainEnvByNameOnlyImpl(abcEnv->domainEnv(), name);
    if (se == NULL)
    {
		Binding b = abcEnv->pool()->m_namedScriptsMap->getName(name);
        if (b != BIND_NONE)
        {
            se = abcEnv->m_namedScriptEnvsList.get(uint32_t(uintptr_t(b))-1);
        }
    }
    return se;
}

#endif // DEBUGGER

} // namespace avmplus
