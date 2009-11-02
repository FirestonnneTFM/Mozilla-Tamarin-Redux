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


#include "avmplus.h"
#include "FrameState.h" // FIXME required because FrameState has dependencies on the jitters

namespace avmplus
{
	/*static*/ const ScopeTypeChain* ScopeTypeChain::create(MMgc::GC* gc, Traits* traits, const ScopeTypeChain* outer, const FrameState* state, Traits* append, Traits* extra)
	{
		const int32_t stateScopeDepth = (state ? state->scopeDepth : 0);
		const int32_t capture = stateScopeDepth + (append ? 1 : 0);
		const int32_t extraEntries = extra ? 1 : 0;
		const int32_t outerSize = (outer ? outer->size : 0);
		const int32_t pad = capture + extraEntries;
		const size_t padSize = sizeof(uintptr_t) * (((pad > 0) ? (pad - 1) : 0) + outerSize);
		ScopeTypeChain* nscope = new(gc, padSize) ScopeTypeChain(outerSize + capture, outerSize + capture + extraEntries, traits);
		int32_t j = 0;
		for (int32_t i = 0; i < outerSize; i++)
		{
			nscope->_scopes[j++] = outer->_scopes[i];
		}
		for (int32_t i = 0; i < stateScopeDepth; i++)
		{
			const Value& v = state->scopeValue(i);
			nscope->setScopeAt(j++, v.traits, v.isWith);
		}
		if (append)
		{
			nscope->setScopeAt(j++, append, false);
		}
		if (extra)
		{
			nscope->setScopeAt(j++, extra, false);
		}
		AvmAssert(j == nscope->fullsize);
		return nscope;
	}

	const ScopeTypeChain* ScopeTypeChain::cloneWithNewTraits(MMgc::GC* gc, Traits* p_traits) const
	{
		if (p_traits == this->traits())
			return this;
			
		const size_t padSize = sizeof(uintptr_t) * (this->fullsize ? this->fullsize-1 : 0);
		ScopeTypeChain* nscope = new(gc, padSize) ScopeTypeChain(this->size, this->fullsize, p_traits);
		for (int32_t i=0; i < this->fullsize; i ++)
		{
			nscope->_scopes[i] = this->_scopes[i];
		}
		return nscope;
	}

	#if VMCFG_METHOD_NAMES
	Stringp ScopeTypeChain::format(AvmCore* core) const
	{
		Stringp r = core->kEmptyString;
		r = r->appendLatin1("STC:[traits=");
		r = r->append(_traits->format(core));
		r = r->appendLatin1(",");
		for (int32_t i = 0; i < fullsize; i++)
		{
			if (i > 0)
				r = r->appendLatin1(",");
			Traits* t = getScopeTraitsAt(i);
			bool b = getScopeIsWithAt(i);
			r = r->append(t->format(core));
			r = r->appendLatin1(b?":1":":0");
		}
		r = r->appendLatin1("]");
		return r;
	}
	#endif

	/*static*/ ScopeChain* ScopeChain::create(MMgc::GC* gc, VTable* vtable, AbcEnv* abcEnv, const ScopeTypeChain* scopeTraits, const ScopeChain* outer, Namespacep dxns)
	{
		AvmAssert(vtable->traits == scopeTraits->traits());
		const int32_t scopeTraitsSize = scopeTraits->size;
		const int32_t outerSize = outer ? outer->_scopeTraits->size : 0;
		const size_t padSize = scopeTraitsSize > 0 ? sizeof(Atom) * (scopeTraitsSize-1) : 0;
		ScopeChain* nscope = new(gc, padSize) ScopeChain(vtable, abcEnv, scopeTraits, dxns);
		for (int32_t i=0; i < outerSize; i ++)
		{
			nscope->setScope(gc, i, outer->_scopes[i]);
		}
		return nscope;
	}

	ScopeChain* ScopeChain::cloneWithNewVTable(MMgc::GC* gc, VTable* p_vtable, AbcEnv* p_abcEnv, const ScopeTypeChain* p_scopeTraits)
	{
		if (p_vtable == this->vtable() && p_abcEnv == this->abcEnv())
			return this;
		
		const ScopeTypeChain* nstc = p_scopeTraits ? p_scopeTraits : _scopeTraits->cloneWithNewTraits(gc, p_vtable->traits);
		AvmAssert(nstc->traits() == p_vtable->traits);
		const int32_t scopeTraitsSize = nstc->size;
		const size_t padSize = scopeTraitsSize > 0 ? sizeof(Atom) * (scopeTraitsSize-1) : 0;
		ScopeChain* nscope = new(gc, padSize) ScopeChain(p_vtable, p_abcEnv, nstc, _defaultXmlNamespace);
		for (int32_t i=0; i < nstc->size; i ++)
		{
			nscope->setScope(gc, i, this->_scopes[i]);
		}
		return nscope;
	}

	void ScopeChain::setScope(MMgc::GC* gc, int32_t i, Atom value)
	{
		AvmAssert(i >= 0 && i < _scopeTraits->size);
		//scopes[i] = value;
		WBATOM(gc, this, &_scopes[i], value);
	}

	#if VMCFG_METHOD_NAMES
	Stringp ScopeChain::format(AvmCore* core) const
	{
		Stringp r = core->kEmptyString;
		r = r->appendLatin1("SC:{dxns=(");
		r = r->append(_defaultXmlNamespace->format(core));
		r = r->appendLatin1("),");
		r = r->append(_scopeTraits->format(core));
		r = r->appendLatin1(",V:[");
		for (int32_t i = 0; i < _scopeTraits->size; i++)
		{
			if (i > 0)
				r = r->appendLatin1(",");
			r = r->append(core->format(_scopes[i]));
		}
		r = r->appendLatin1("]}");
		return r;
	}
	#endif
}
