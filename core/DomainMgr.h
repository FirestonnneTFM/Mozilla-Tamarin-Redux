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

#ifndef __avmplus_DomainMgr__
#define __avmplus_DomainMgr__

namespace avmplus
{

/**
 *  Domain manager pure virtual interface.  An Domain manager implementation
 *  is responsible for all aspects of finding names in a given Domain stack.
 *
 *  Although some configurations may only have one concrete implementation,
 *  we use ordinary polymorphism instead of build-time polymorphism, to keep
 *  things simple.
 */
class DomainMgr
{
public:
    virtual ~DomainMgr() {}

    virtual void addNamedTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* traits) = 0;
    virtual void addNamedInstanceTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* itraits) = 0;
    virtual Traits* findBuiltinTraitsByName(PoolObject* pool, Stringp name) = 0;
    virtual Traits* findTraitsInPoolByNameAndNS(PoolObject* pool, Stringp name, Namespacep ns) = 0;
    virtual Traits* findTraitsInPoolByMultiname(PoolObject* pool, const Multiname& multiname) = 0;

    virtual void addNamedScript(PoolObject* pool, Stringp name, Namespacep ns, MethodInfo* script) = 0;
    virtual MethodInfo* findScriptInPoolByMultiname(PoolObject* pool, const Multiname& multiname) = 0;

    virtual void addNamedScriptEnvs(AbcEnv* abcEnv, const List<ScriptEnv*>& envs) = 0;
    virtual ScriptEnv* findScriptEnvInDomainEnvByMultiname(DomainEnv* domainEnv, const Multiname& multiname) = 0;
    virtual ScriptEnv* findScriptEnvInAbcEnvByMultiname(AbcEnv* abcEnv, const Multiname& multiname) = 0;

#ifdef DEBUGGER
    // look up a ScriptEnv by name only, ignoring namespace. This should be used only by the debugger,
    // when trying to match a user-specified name.
    virtual ScriptEnv* findScriptEnvInAbcEnvByNameOnly(AbcEnv* abcEnv, Stringp name) = 0;
#endif
};

class DomainMgrFP10 : public MMgc::GCFinalizedObject
    , /* implements */ public DomainMgr
{
public:
    DomainMgrFP10(AvmCore* core);
    virtual ~DomainMgrFP10();

    // DomainMgr methods:
    virtual void addNamedTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* traits);
    virtual void addNamedInstanceTraits(PoolObject* pool, Stringp name, Namespacep ns, Traits* itraits);
    virtual Traits* findBuiltinTraitsByName(PoolObject* pool, Stringp name);
    virtual Traits* findTraitsInPoolByNameAndNS(PoolObject* pool, Stringp name, Namespacep ns);
    virtual Traits* findTraitsInPoolByMultiname(PoolObject* pool, const Multiname& multiname);

    virtual void addNamedScript(PoolObject* pool, Stringp name, Namespacep ns, MethodInfo* script);
    virtual MethodInfo* findScriptInPoolByMultiname(PoolObject* pool, const Multiname& multiname);

    virtual void addNamedScriptEnvs(AbcEnv* abcEnv, const List<ScriptEnv*>& envs);
    virtual ScriptEnv* findScriptEnvInDomainEnvByMultiname(DomainEnv* domainEnv, const Multiname& multiname);
    virtual ScriptEnv* findScriptEnvInAbcEnvByMultiname(AbcEnv* abcEnv, const Multiname& multiname);

#ifdef DEBUGGER
    virtual ScriptEnv* findScriptEnvInAbcEnvByNameOnly(AbcEnv* abcEnv, Stringp name);
#endif
private:
    Traits* findTraitsInDomainByNameAndNSImpl(Domain* domain, Stringp name, Namespacep ns);
    Traits* findTraitsInPoolByNameAndNSImpl(PoolObject* pool, Stringp name, Namespacep ns);
    MethodInfo* findScriptInDomainByNameAndNSImpl(Domain* domain, Stringp name, Namespacep ns);
    MethodInfo* findScriptInDomainByMultinameImpl(Domain* domain, const Multiname& multiname);
    MethodInfo* findScriptInPoolByNameAndNSImpl(PoolObject* pool, Stringp name, Namespacep ns);
    ScriptEnv* findScriptEnvInDomainEnvByMultinameImpl(DomainEnv* domainEnv, const Multiname& multiname);
#ifdef DEBUGGER
    ScriptEnv* findScriptEnvInDomainEnvByNameOnlyImpl(DomainEnv* domainEnv, Stringp name);
#endif
#ifdef _DEBUG
    static void verifyMatchingLookup(Binding b, const List<MethodInfo*>& listMI, const List<ScriptEnv*>& listSE);
#endif
private:
    AvmCore* const core;
};


}
#endif // __avmplus_DomainMgr__
