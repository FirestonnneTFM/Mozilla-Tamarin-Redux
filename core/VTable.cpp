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
	
	VTable::VTable(Traits* traits, VTable* _base, Toplevel* toplevel) :
		_toplevel(toplevel),
		init(NULL),
		base(_base),
		ivtable(NULL),
		traits(traits),
		linked(false)
	{
		AvmAssert(traits != NULL);
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst(TMT_vtable, this); )
	}

#ifdef AVMPLUS_TRAITS_MEMTRACK 
	VTable::~VTable()
	{
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst(TMT_vtable, this); )
	}
#endif

	void VTable::resolveSignatures(ScopeChain* scope)
	{
		AvmAssert(scope != NULL);

		if( this->linked )
			return;
		linked = true;
		if (!traits->isResolved())
		{
			traits->resolveSignatures(toplevel());
			traits->init_declaringScopes(scope->scopeTraits());
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
					//this->methods[i] = base->methods[i];
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
			if (traits->pool->verbose)
			{
				// why would the compiler assign sparse disp_id's?
				traits->core->console << "WARNING: empty disp_id " << i << " on " << traits << "\n";
			}
			#endif
		}

			// this is done here b/c this property of the traits isn't set until the
			// Dictionary's ClassClosure is called
		if (base)
			traits->isDictionary = base->traits->isDictionary;

#if defined FEATURE_NANOJIT
		{
			for (uint32_t i=0; i < Traits::IMT_SIZE; i++)
			{
				Binding b = traits->getIMT()[i];
				if (AvmCore::isMethodBinding(b))
				{
					//imt[i] = methods[AvmCore::bindingToMethodId(b)];
					WB(gc, this, &imt[i], methods[AvmCore::bindingToMethodId(b)]);
				}
				else if (AvmCore::bindingKind(b) == BKIND_ITRAMP)
				{
					if (base && b == traits->base->getIMT()[i])
					{
						// copy down imt stub from base class
						//imt[i] = base->imt[i];
						WB(gc, this, &imt[i], base->imt[i]);
					}
					else
					{
						// create new imt stub
						MethodInfo *mi = AvmCore::getITrampAddr(b);
						MethodEnv* e = new (gc) MethodEnv(MethodEnv::kTrampStub, mi, scope);
						WB(gc, this, &imt[i], e);
					}
				}
			}
		}
#endif
	}

	MethodEnv* VTable::makeMethodEnv(MethodInfo* func, ScopeChain* scope)
	{
		AvmCore* core = this->core();
		AbcEnv* abcEnv = scope->abcEnv();
		MethodEnv* methodEnv = new (core->GetGC()) MethodEnv(func, scope);
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
			else if (func->pool()->verbose)
			{
				core->console << "WARNING: tried to re-register global MethodEnv for " << func << "\n";
			}
			#endif
		}
		return methodEnv;
	}

#ifdef DEBUGGER
	uint32 VTable::size() const
	{
		uint32 size = sizeof(VTable);

		if(ivtable != NULL)
			size += ivtable->size();

		const TraitsBindingsp td = traits->getTraitsBindings();
		const uint32_t n = td->methodCount;
		const uint32_t baseMethodCount = base ? td->base->methodCount : 0;
		size += td->methodCount*sizeof(MethodInfo*);

		for (uint32_t i=0; i < n; i++)
		{
			MethodInfo* method = td->getMethod(i);
			
			if (i < baseMethodCount && td->base && method == td->base->getMethod(i))
			{
				continue;
			}
			else if(method != NULL)
			{
				size += method->size();
			}
		}
		return size;
	}
#endif

	VTable* VTable::newParameterizedVTable(Traits* param_traits, Stringp fullname)
	{
		Toplevel* toplevel = this->toplevel();
		AvmCore* core = toplevel->core();
		Namespacep traitsNs = this->traits->ns();
		PoolObject* traitsPool = this->traits->pool;

		Stringp classname = core->internString(fullname->appendLatin1("$"));
		Traits* ctraits = traitsPool->getTraits(Multiname(traitsNs, classname), toplevel);
		Traits* itraits;
		if (!ctraits)
		{
			ctraits = this->traits->newParameterizedCTraits(classname, traitsNs);
			itraits = traitsPool->resolveParameterizedType(toplevel, this->ivtable->traits, param_traits);
			ctraits->itraits = itraits;
		}
		else
		{
			itraits = ctraits->itraits;
		}

		AvmAssert(itraits != NULL);
		itraits->resolveSignatures(toplevel);
		ctraits->resolveSignatures(toplevel);

		VTable* objVecVTable = toplevel->objectVectorClass->vtable;
		AbcEnv* objVecAbcEnv = toplevel->vectorobj_cscope->abcEnv();
		Toplevel* objVecToplevel = objVecVTable->toplevel();
		VTable* objVecIVTable = objVecVTable->ivtable;

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
}
