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
//#define DOPROF
//#include "vprof.h"

namespace avmplus
{
    VTable::VTable(Traits* traits, VTable* _base, Toplevel* toplevel)
        : _toplevel(toplevel)
        , init(NULL)
        , base(_base)
        , ivtable(NULL)
        , traits(traits)
        , createInstance(ScriptObject::genericCreateInstance)
        , linked(false)
#ifdef VMCFG_AOT
        , interfaceBindingFunction(traits->m_interfaceBindingFunction)
#endif
    {
        AvmAssert(toplevel != NULL);
        AvmAssert(traits != NULL);
    }

    void VTable::resolveSignatures(ScopeChain* scope)
    {
        AvmAssert(scope != NULL);

        if( this->linked )
            return;
        linked = true;
        if (!traits->isResolved())
        {
            traits->resolveSignatures(toplevel());
            traits->setDeclaringScopes(scope->scopeTraits());
        }

#if defined(DEBUG) || defined(_DEBUG)
        // have to use local variables for CodeWarrior
        Traits* traitsBase = traits->base;
        Traits* baseTraits = base ? base->traits : 0;
        // make sure the traits of the base vtable matches the base traits
        AvmAssert((base == NULL && traits->base == NULL) || (base != NULL && traitsBase == baseTraits));
#endif // DEBUG

        AvmCore* core = traits->core;
        MMgc::GC* gc = core->GetGC();

        if (traits->init && !this->init)
        {
            this->init = makeMethodEnv(traits->init, scope);
        }

        // populate method table
        const TraitsBindingsp td = traits->getTraitsBindings();
        const TraitsBindingsp btd = td->base;
        for (uint32_t i = 0, n = td->methodCount; i < n; i++)
        {
            MethodInfo* method = td->getMethod(i);

            if (btd && i < btd->methodCount && method == btd->getMethod(i))
            {
                // inherited method
                // this->methods[i] = base->methods[i];
                WB(gc, this, &methods[i], base->methods[i]);
                continue;
            }

            // new definition
            if (method != NULL)
            {
                //this->methods[i] = new (gc) MethodEnv(method, this);
                WB(gc, this, &methods[i], makeMethodEnv(method, scope));
                continue;
            }
            #ifdef AVMPLUS_VERBOSE
            if (traits->pool->isVerbose(VB_traits))
            {
                // why would the compiler assign sparse disp_id's?
                traits->core->console << "WARNING: empty disp_id " << i << " on " << traits << "\n";
            }
            #endif
        }

        // this is done here b/c this property of the traits isn't set until the
        // Dictionary's ClassClosure is called
        if (base && base->traits->isDictionary())
            traits->set_isDictionary();

        traits->core->exec->notifyVTableResolved(this);
    }

    MethodEnv* VTable::makeMethodEnv(MethodInfo* func, ScopeChain* scope)
    {
        AvmCore* core = this->core();
        AbcEnv* abcEnv = scope->abcEnv();
        MethodEnv* methodEnv = MethodEnv::create(core->GetGC(), func, scope);
        // register this env in the callstatic method table
        int method_id = func->method_id();
        if (method_id != -1)
        {
            AvmAssert(abcEnv->pool() == func->pool());
            if (abcEnv->getMethod(method_id) == NULL)
            {
                abcEnv->setMethod(method_id, methodEnv);
            }
            #ifdef AVMPLUS_VERBOSE
            else if (func->pool()->isVerbose(VB_traits))
            {
                core->console << "WARNING: tried to re-register global MethodEnv for " << func << "\n";
            }
            #endif
        }
        return methodEnv;
    }

#ifdef DEBUGGER
    uint64_t VTable::bytesUsed() const
    {
        uint64_t bytesUsed = sizeof(VTable);

        if(ivtable != NULL)
            bytesUsed += ivtable->bytesUsed();

        const TraitsBindingsp td = traits->getTraitsBindings();
        const uint32_t n = td->methodCount;
        const uint32_t baseMethodCount = base ? td->base->methodCount : 0;
        bytesUsed += td->methodCount*sizeof(MethodInfo*);

        for (uint32_t i=0; i < n; i++)
        {
            MethodInfo* method = td->getMethod(i);

            if (i < baseMethodCount && td->base && method == td->base->getMethod(i))
            {
                continue;
            }
            else if(method != NULL)
            {
                bytesUsed += method->bytesUsed();
            }
        }
        return bytesUsed;
    }
#endif

    VTable* VTable::newParameterizedVTable(Traits* param_traits, Stringp fullname)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();
        Namespacep traitsNs = this->traits->ns();

        VTable* objVecVTable = toplevel->objectVectorClass->vtable;
        AbcEnv* objVecAbcEnv = toplevel->vectorobj_cscope->abcEnv();
        Toplevel* objVecToplevel = objVecVTable->toplevel();
        VTable* objVecIVTable = objVecVTable->ivtable;

        // these cases should all be filtered out by the caller;
        // we only want to handle Vector<SomeObject> here
        AvmAssert(param_traits != NULL &&
                    param_traits != toplevel->intClass->vtable->traits->itraits &&
                    param_traits != toplevel->uintClass->vtable->traits->itraits &&
                    param_traits != toplevel->numberClass->vtable->traits->itraits);

        PoolObject* traitsPool = this->traits->pool;

        Stringp classname = core->internString(fullname->appendLatin1("$"));
        Traits* ctraits = core->domainMgr()->findTraitsInPoolByNameAndNS(traitsPool, classname, traitsNs);
        Traits* itraits;
        if (!ctraits)
        {
            // important: base the new ctraits on objVecVTable->traits, *not* this->traits;
            // we want the result to be based off ObjectVectorClass, not VectorClass
            // (otherwise sizeofInstance would be too small and we'd be crashy)
            ctraits = objVecVTable->traits->newParameterizedCTraits(classname, traitsNs);
            ctraits->verifyBindings(toplevel);

            itraits = traitsPool->resolveParameterizedType(toplevel, this->ivtable->traits, param_traits);
            ctraits->itraits = itraits;
        }
        else
        {
            itraits = ctraits->itraits;
        }

        AvmAssert(itraits != NULL);

        VTable* cvtab = core->newVTable(ctraits, objVecToplevel->class_ivtable, objVecToplevel);
        ScopeChain* cvtab_cscope = toplevel->vectorobj_cscope->cloneWithNewVTable(core->GetGC(), cvtab, objVecAbcEnv);

        VTable* ivtab = core->newVTable(itraits, objVecIVTable, objVecToplevel);
        ScopeChain* ivtab_iscope = toplevel->vectorobj_iscope->cloneWithNewVTable(core->GetGC(), ivtab, objVecAbcEnv);
        cvtab->ivtable = ivtab;
        ivtab->init = objVecIVTable->init;

        cvtab->resolveSignatures(cvtab_cscope);
        ivtab->resolveSignatures(ivtab_iscope);

        return cvtab;
    }

#ifdef AVMPLUS_VERBOSE
    PrintWriter& VTable::print(PrintWriter& prw) const
    {
        return prw << traits;
    }
#endif
}
