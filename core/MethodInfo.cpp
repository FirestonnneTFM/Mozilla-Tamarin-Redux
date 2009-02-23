/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
/* vi: set ts=4 sw=4: */
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

#ifdef FEATURE_NANOJIT
#include "CodegenLIR.h"
#endif

namespace avmplus
{
	using namespace MMgc;

	MethodInfo::MethodInfo(int _method_id) : 
		AbstractFunction(_method_id)
#ifdef DEBUGGER
		, m_dmi(NULL)
#endif
	{
		this->impl32 = verifyEnter;
	}

    void MethodInfo::setInterpImpl() 
	{
		if (returnTraits() == this->pool->core->traits.number_itraits)
			implN = avmplus::interpN;
		else
			impl32 = avmplus::interp32;
    }

	/*static*/ Atom MethodInfo::verifyEnter(MethodEnv* env, int argc, uint32 *ap)
	{
		MethodInfo* f = (MethodInfo*) env->method;

		#ifdef AVMPLUS_VERIFYALL
		// never verify late in verifyall mode
		AvmAssert(!f->pool->core->config.verifyall);
		#endif

		f->verify(env->vtable->toplevel);

#if 0 // This is handled near the top of interp() for the moment, see comments there
#ifdef AVMPLUS_WORD_CODE
		{
			int n;
			if ((int32)(n = f->word_code.cache_size) > 0) {
				AvmAssert(env->lookup_cache == NULL);
				env->lookup_cache = (MethodEnv::LookupCache*)env->core()->GetGC()->Alloc(sizeof(MethodEnv::LookupCache)*n, GC::kContainsPointers|GC::kZero);
			}
		}
#endif
#endif // 0

        AvmAssert(f->impl32 != MethodInfo::verifyEnter);
		env->impl32 = f->impl32;
		return f->impl32(env, argc, ap);
	}

	void MethodInfo::verify(Toplevel* toplevel)
	{
		AvmAssert(declaringTraits->isResolved());
		resolveSignature(toplevel);

		AvmCore* core = this->pool->core;

		#ifdef DEBUGGER
		// just a fake CallStackNode here , so that if we throw a verify error, 
		// we get a stack trace with the method being verified as its top entry.
		// init with an empty setup when debugger() isn't present, so we can
		// skip the call to getMethodName(), which is nonzero
		CallStackNode callStackNode(CallStackNode::kNoOp);
		if (core->debugger())
			callStackNode.init(core, this->getMethodName());
		#endif /* DEBUGGER */

		if (!body_pos)
		{
			// no body was supplied in abc
			toplevel->throwVerifyError(kNotImplementedError, core->toErrorString(this));
		}

		#if defined FEATURE_NANOJIT

		Verifier verifier(this, toplevel);

		if ((core->IsJITEnabled()) && !isFlagSet(AbstractFunction::SUGGEST_INTERP))
		{
            PERFM_NTPROF("verify & IR gen");

			#if defined FEATURE_NANOJIT
			CodegenLIR jit(this);
			#endif

			TRY(core, kCatchAction_Rethrow)
			{
				verifier.verify(&jit);	// pass 2 - data flow
                PERFM_TPROF_END();
        
				if (!jit.overflow)
					jit.emitMD(); // pass 3 - generate code

				// the MD buffer can overflow so we need to re-iterate
				// over the whole thing, since we aren't yet robust enough
				// to just rebuild the MD code.

				// mark it as interpreted and try to limp along
				if (jit.overflow) {
                    setInterpImpl();
				}
#ifdef AVMPLUS_WORD_CODE
				else {
					if(word_code.code_anchor) {
						word_code.code_anchor = NULL;
						codeStart = NULL;
					}
					if (word_code.exceptions) {
						word_code.exceptions = NULL;
					}
				}
#endif
			}
			CATCH (Exception *exception) 
			{
				// re-throw exception
				core->throwException(exception);
			}
			END_CATCH
			END_TRY
		}
		else
		{
			verifier.verify(NULL); // pass2 dataflow
            setInterpImpl();
		}
		#else
		Verifier verifier(this, toplevel);
		verifier.verify();
		setInterpImpl();
		#endif
		
        #ifdef DEBUGGER
		// no explicit exit call needed for fake CallStackNodes, they auto-cleanup in dtor
		// (note that this is true even if we didn't call CallStackNode::init; the dtor is a no-op in that case)
		//callStackNode.exit();
        #endif /* DEBUGGER */
	}
	
#ifdef DEBUGGER

	void MethodInfo::initDMI(int32_t local_count, uint32_t codeSize, int32_t max_scopes)
	{
		AvmAssert(m_dmi == NULL);
		
		AvmCore* core = this->pool->core;
		MMgc::GC* gc = core->GetGC();
		const uint32_t extra = (local_count <= 1) ? 0 : (sizeof(Stringp)*(local_count-1));

		DebuggerMethodInfo* dmi = new (gc, extra) DebuggerMethodInfo(local_count, codeSize, max_scopes);
		const Stringp undef = core->kundefined;
		for (int32_t i=0; i<local_count; i++)
		{
			WBRC(gc, dmi, &dmi->localNames[i], undef);
		}
		WB(gc, this, &this->m_dmi, dmi);
	}

	AbcFile* MethodInfo::file() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? (AbcFile*)(m_dmi->file) : NULL;
	}
	
	int32_t MethodInfo::firstSourceLine() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->firstSourceLine : 0;
	}

	int32_t MethodInfo::lastSourceLine() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->lastSourceLine : 0;
	}

	int32_t MethodInfo::offsetInAbc() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->offsetInAbc : 0;
	}

	uint32_t MethodInfo::codeSize() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->codeSize : 0;
	}

	int32_t MethodInfo::local_count() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->local_count : 0;
	}

	int32_t MethodInfo::max_scopes() const
	{
		AvmAssert(m_dmi != NULL);
		return m_dmi ? m_dmi->max_scopes : 0;
	}

	void MethodInfo::setFile(AbcFile* file) 
	{
		AvmAssert(m_dmi != NULL);
		if (m_dmi)
			m_dmi->file = file;
	}

	void MethodInfo::updateSourceLines(int32_t linenum, int32_t offset)
	{
		AvmAssert(m_dmi != NULL);
		if (m_dmi)
		{
			if (m_dmi->firstSourceLine == 0 || linenum < m_dmi->firstSourceLine)
				m_dmi->firstSourceLine = linenum;

			if (m_dmi->offsetInAbc == 0 || offset < m_dmi->offsetInAbc)
				m_dmi->offsetInAbc = offset;

			if (m_dmi->lastSourceLine == 0 || linenum > m_dmi->lastSourceLine)
				m_dmi->lastSourceLine = linenum;
		}
	}

	Stringp MethodInfo::getRegName(int slot) const 
	{
		AvmAssert(m_dmi != NULL);

		if (m_dmi && slot >= 0 && slot < m_dmi->local_count)
			return m_dmi->localNames[slot];

		return this->pool->core->kundefined;
	}

	void MethodInfo::setRegName(int slot, Stringp name)
	{
		AvmAssert(m_dmi != NULL);

		if (!m_dmi || slot < 0 || slot >= m_dmi->local_count)
			return;

		AvmCore* core = this->pool->core;

		// [mmorearty 5/3/05] temporary workaround for bug 123237: if the register
		// already has a name, don't assign a new one
		if (m_dmi->localNames[slot] != core->kundefined)
			return;

		WBRC(core->GetGC(), m_dmi, &m_dmi->localNames[slot], core->internString(name));
	}

	/**
	 * convert ap[start]...ap[start+count-1] entries from their native types into
	 * Atoms.  The result is placed into out[to]...out[to+count-1].
	 * 
	 * The traitArr is used to determine the type of conversion that should take place.
	 * traitArr[start]...traitArr[start+count-1] are used.
	 *
	 * If the method is interpreted then we just copy the Atom, no conversion is needed.
	 */
	void MethodInfo::boxLocals(void* src, int srcPos, Traits** traitArr, Atom* dest, int destPos, int length)
	{
		int size = srcPos+length;
		int at = destPos;

		// if we are running jit then the types are native and we
		// need to box em.
		if (isFlagSet(JIT_IMPL))
		{
			// each entry is a pointer into the function's stack frame
			void **in = (void**)src;			// WARNING this must match with JIT generator

			// now probe each type and do the atom conversion.
			AvmCore* core = this->pool->core;
			for (int i=srcPos; i<size; i++)
			{
				Traits* t = traitArr[i];
				void *p = in[i];
				if (t == NUMBER_TYPE) 
				{
					dest[at] = core->doubleToAtom( *((double*)p) );
				}
				else if (t == INT_TYPE)
				{
					dest[at] = core->intToAtom( *((int*)p) );
				}
				else if (t == UINT_TYPE)
				{
					dest[at] = core->uintToAtom( *((uint32*)p) );
				}
				else if (t == BOOLEAN_TYPE)
				{
					dest[at] = *((int*)p) ? trueAtom : falseAtom;
				}
				else if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
				{
					dest[at] = *((Atom*)p);
				}
				else
				{
					// it's a pointer type, either null or some specific atom tag.
					void* ptr = *((void**)p); // unknown pointer
					if (t == STRING_TYPE)
					{
						dest[at] = ((Stringp)ptr)->atom();
					}
					else if (t == NAMESPACE_TYPE)
					{
						dest[at] = ((Namespace*)ptr)->atom();
					}
					else 
					{
						dest[at] = ((ScriptObject*)ptr)->atom();
					}
				}
				at++;
			}
		}
		else
		{
			// no JIT then we know they are Atoms and we just copy them
			Atom* in = (Atom*)src;
			for(int i=srcPos; i<size; i++)
				dest[at++] = in[i];
		}
	}

	/**
	 * convert in[0]...in[count-1] entries from Atoms to native types placing them 
	 * in ap[start]...out[start+count-1].
	 * 
	 * The traitArr is used to determine the type of conversion that should take place.
	 * traitArr[start]...traitArr[start+count-1] are used.
	 *
	 * If the method is interpreted then we just copy the Atom, no conversion is needed.
	 */
	void MethodInfo::unboxLocals(Atom* src, int srcPos, Traits** traitArr, void* dest, int destPos, int length)
	{
		#ifdef AVMPLUS_64BIT
		AvmAssertMsg(false, "are these ops right for 64-bit?  alignment of int/uint/bool?\n");
		#endif
		int size = destPos+length;
		int at = srcPos;

		// If the method has been jit'd then we need to box em, otherwise just
		// copy them 
		if (isFlagSet(JIT_IMPL))
		{
			// we allocated double sized entry for each local src 
			void** out = (void**)dest;		// WARNING this must match with JIT generator

			// now probe each type and conversion.
			AvmCore* core = this->pool->core;
			for (int i=destPos; i<size; i++)
			{
				Traits* t = traitArr[i];
				void *p = out[i];
				if (t == NUMBER_TYPE) 
				{
					*((double*)p) = AvmCore::number_d(src[at++]);
				}
				else if (t == INT_TYPE)
				{
					*((int*)p) = AvmCore::integer_i(src[at++]);
				}
				else if (t == UINT_TYPE)
				{
					*((uint32*)p) = AvmCore::integer_u(src[at++]);
				}
				else if (t == BOOLEAN_TYPE)
				{
					*((int*)p) = (int)(src[at++]>>3);
				}
				else if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
				{
					*((Atom*)p) = src[at++];
				}
				else
				{
					// ScriptObject, String, Namespace, or Null
					*((sintptr*)p) = (src[at++] & ~7);
				}
			}
		}
		else
		{
			// no JIT then we know they are Atoms and we just copy them
			Atom* out = (Atom*)dest;
			for(int i=destPos; i<size; i++)
				out[i] = src[at++];
		}
	}

	uint32 MethodInfo::size() const
	{
		uint32 size = AbstractFunction::size();
		size += (sizeof(MethodInfo) - sizeof(AbstractFunction));
		size += codeSize();
		return size;
	}
#endif //DEBUGGER
}
