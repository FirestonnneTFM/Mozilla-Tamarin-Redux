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

#if defined FEATURE_NANOJIT
	MethodInfo::MethodInfo(void* tramp) : method_id(-1)
	{
		union {
			void* t;
			AtomMethodProc p;
		};
		t = tramp;
		this->impl32 = p;
	}
#endif

	MethodInfo::MethodInfo(int _method_id, const NativeMethodInfo* native_info)
		:  method_id(_method_id)
	{

#if !defined(AVMPLUS_TRAITS_MEMTRACK) && !defined(MEMORY_INFO)
		MMGC_STATIC_ASSERT(offsetof(MethodInfo, impl32) == 0);
#endif

		this->impl32 = verifyEnter;
		this->flags = 0;
#ifdef DEBUGGER
		this->m_dmi = NULL;
#endif
		if (native_info)
		{
			this->_native.thunker = native_info->thunker;
			this->_native.handler = native_info->handler;
			this->flags |= MethodInfo::NEEDS_CODECONTEXT | MethodInfo::NEEDS_DXNS | MethodInfo::ABSTRACT_METHOD;
		}
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst(TMT_abstractfunction, this); )
	}

#ifdef AVMPLUS_TRAITS_MEMTRACK
	MethodInfo::~MethodInfo()
	{
		AVMPLUS_TRAITS_MEMTRACK_ONLY( if (m_types) tmt_sub_mem(TMT_abstractfunction, GC::Size(m_types) ); )
		AVMPLUS_TRAITS_MEMTRACK_ONLY( if (m_values) tmt_sub_mem(TMT_abstractfunction, GC::Size(m_values) ); )
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst(TMT_abstractfunction, this); )
	}
#endif

    void MethodInfo::setInterpImpl() 
	{
		if (returnTraits() == this->pool->core->traits.number_itraits)
			implN = avmplus::interpN;
		else
			impl32 = avmplus::interp32;
    }

#ifdef DEBUGGER
	/*static*/ AvmBox MethodInfo::debugEnterExitWrapper32(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
	{
		CallStackNode csn(CallStackNode::kEmpty); 
		env->debugEnter(argc, (uint32_t*)argv, /*frametraits*/0, /*localCount*/0, &csn, /*framep*/0, /*eip*/0); 
		const AvmBox result = env->method->thunker()(env, argc, argv);
		env->debugExit(&csn);
		return result;
	}

	/*static*/ double MethodInfo::debugEnterExitWrapperN(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
	{
		CallStackNode csn(CallStackNode::kEmpty); 
		env->debugEnter(argc, (uint32_t*)argv, /*frametraits*/0, /*localCount*/0, &csn, /*framep*/0, /*eip*/0); 
		const double result = (reinterpret_cast<AvmThunkNativeThunkerN>(env->method->thunker()))(env, argc, argv);
		env->debugExit(&csn);
		return result;
	}
#endif

	/*static*/ Atom MethodInfo::verifyEnter(MethodEnv* env, int argc, uint32* ap)
	{
		MethodInfo* f = env->method;

		#ifdef AVMPLUS_VERIFYALL
		// never verify late in verifyall mode
		AvmAssert(!f->pool->core->config.verifyall);
		#endif

		f->verify(env->vtable->toplevel);

        AvmAssert(f->impl32 != MethodInfo::verifyEnter);
#if VMCFG_METHODENV_IMPL32
		env->_impl32 = f->impl32;
#endif
		return f->impl32(env, argc, ap);
	}

	void MethodInfo::verify(Toplevel *toplevel)
	{
		AvmAssert(declaringTraits->isResolved());
		resolveSignature(toplevel);
		AvmCore* core = this->pool->core;
		if (isNative())
		{
			union {
				Atom (*impl32)(MethodEnv*, int, uint32 *);
				AvmThunkNativeThunker thunker;
				AvmThunkNativeThunkerN thunkerN;
			} u;
	#ifdef DEBUGGER
			if (core->debugger())
			{
				if (Traits::getBuiltinType(returnTraits()) == BUILTIN_number)
					u.thunkerN = MethodInfo::debugEnterExitWrapperN;
				else
					u.thunker = MethodInfo::debugEnterExitWrapper32;
			}
			else
	#endif
			{
				u.thunker = this->thunker();
			}
			this->impl32 = u.impl32;
		}
		else
		{
			#ifdef DEBUGGER
			// just a fake CallStackNode here , so that if we throw a verify error, 
			// we get a stack trace with the method being verified as its top entry.
			// init with an empty setup when debugger() isn't present, so we can
			// skip the call to getMethodName(), which is nonzero
			CallStackNode callStackNode(CallStackNode::kNoOp);
			if (core->debugger())
				callStackNode.init(this->pool->core, this->getMethodName());
			#endif /* DEBUGGER */

			if (!_abc.body_pos)
			{
				// no body was supplied in abc
				toplevel->throwVerifyError(kNotImplementedError, this->pool->core->toErrorString(this));
			}

			#if defined FEATURE_NANOJIT
			Verifier verifier(this, toplevel);

			if ((core->IsJITEnabled()) && !isFlagSet(MethodInfo::SUGGEST_INTERP))
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
						if (_abc.word_code.code_anchor) 
						{
							set_word_code_start(core->GetGC(), NULL, NULL);
						}
						if (_abc.word_code.exceptions) 
						{
							_abc.word_code.exceptions = NULL;
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
			// we allocated double sized entry for each local src CodegenJIT
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

#endif //DEBUGGER

	void MethodInfo::initParamTypes(int count)
	{
		MMGC_MEM_TYPE(this);
		AvmAssert(m_types == NULL);
		m_types = (Traits**)pool->core->GetGC()->Calloc(count, sizeof(Traits*), GC::kContainsPointers|GC::kZero);
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_mem(TMT_abstractfunction, GC::Size(m_types) ); )
	}

	void MethodInfo::initDefaultValues(int count)
	{
		MMGC_MEM_TYPE(this);
		AvmAssert(m_values == NULL);
		m_values = (Atom*)pool->core->GetGC()->Calloc(count, sizeof(Atom), GC::kContainsPointers|GC::kZero);
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_mem(TMT_abstractfunction, GC::Size(m_values) ); )
	}
	
	void MethodInfo::setParamType(int index, Traits* t)
	{
		AvmAssert(index >= 0 && index <= param_count);
		WB(pool->core->GetGC(), m_types, &m_types[index], t);
	}

	void MethodInfo::setDefaultValue(int index, Atom value)
	{
		AvmAssert(index > (param_count-optional_count) && index <= param_count);
		int i = index-(param_count-optional_count)-1;
		AvmAssert(i >= 0 && i < optional_count);
		WBATOM(pool->core->GetGC(), m_values, &m_values[i], value);
	}
	
#ifdef AVMPLUS_VERBOSE
	Stringp MethodInfo::format(AvmCore* core) const
	{
		Stringp n = getMethodName();
		return n ?
				n->appendLatin1("()") :
				core->newConstantStringLatin1("?()");
	}
#endif // AVMPLUS_VERBOSE

	bool MethodInfo::makeMethodOf(Traits* traits)
	{
		if (!m_types[0])
		{
			declaringTraits = traits;
			setParamType(0, traits);
			flags |= NEED_CLOSURE;

			if (traits->final)
			{
				// all methods of a final class are final
				flags |= FINAL;
			}

			return true;
		}
		else
		{
			#ifdef AVMPLUS_VERBOSE
			if (pool->verbose)
				pool->core->console << "WARNING: method " << this << " was already bound to " << declaringTraits << "\n";
			#endif

			return false;
		}
	}

	void MethodInfo::makeIntoPrototypeFunction(const Toplevel* toplevel)
	{
		if (declaringTraits == NULL)
		{
			// make sure param & return types are fully resolved.
			// this does not set the verified flag, so real verification will
			// still happen before the function runs the first time.
			resolveSignature(toplevel);

			// type of F is synthetic subclass of Function, with a unique
			// [[call]] property and a unique scope

			Traits* ftraits = Traits::newFunctionTraits(toplevel, pool, method_id);
			this->declaringTraits = ftraits;
			

#ifdef AVMPLUS_UNCHECKED_HACK
			// HACK - compiler should do this, and only to toplevel functions
			// that meet the E4 criteria for being an "unchecked function"
			// the tests below are too loose

			// if all params and return types are Object then make all params optional=undefined
			if (param_count == 0)
				flags |= IGNORE_REST;
			if (!(flags & HAS_OPTIONAL) && param_count > 0)
			{
				if (m_returnType == NULL)
				{
					for (int i=1; i <= param_count; i++)
					{
						if (m_types[i] != NULL)
							return;
					}

					// make this an unchecked function
					flags |= HAS_OPTIONAL | IGNORE_REST;
					optional_count = param_count;
					initDefaultValues(optional_count);
					for (int i=1; i <= optional_count; i++)
					{
						// since the type is object the default value is undefined.
						setDefaultValue(i, undefinedAtom);
					}
				}
			}
#endif
		}
	}
	
	/**
	 * convert native args to atoms.  argc is the number of
	 * args, not counting the instance which is arg[0].  the
	 * layout is [instance][arg1..argN]
	 */
	void MethodInfo::boxArgs(int argc, uint32 *ap, Atom* out)
	{
		// box the typed args, up to param_count
		AvmCore* core = this->pool->core;
		for (int i=0; i <= argc; i++)
		{
			if (i <= param_count)
			{
				Traits* t = paramTraits(i);
				AvmAssert(t != VOID_TYPE);

				if (t == NUMBER_TYPE) 
				{
					out[i] =  core->doubleToAtom(*(double *)ap);
					ap += 2;
				}
				else if (t == INT_TYPE)
				{
					out[i] = core->intToAtom((int32)*(Atom*) ap);
					ap += sizeof(Atom) / sizeof(uint32);
				}
				else if (t == UINT_TYPE)
				{
					out[i] = core->uintToAtom((uint32)*(Atom*) ap);
					ap += sizeof(Atom) / sizeof(uint32);
				}
				else if (t == BOOLEAN_TYPE)
				{
					out[i] = (*(Atom*) ap) ? trueAtom : falseAtom;
					ap += sizeof(Atom) / sizeof(uint32);
				}
				else if (!t || t == OBJECT_TYPE)
				{
					out[i] = *(Atom *) ap;
					ap += sizeof(Atom) / sizeof(uint32);
				}
				else
				{
					// it's a pointer type, possibly null

					void* p = *(void **)ap; // unknown pointer
					if (t == STRING_TYPE)
					{
						out[i] = ((Stringp)p)->atom();
					}
					else if (t == NAMESPACE_TYPE)
					{
						out[i] = ((Namespace*)p)->atom();
					}
					else 
					{
						out[i] = ((ScriptObject*)p)->atom();
					}
					ap += sizeof(void *) / sizeof(uint32);
				}
			}
			else
			{
				out[i] = *(Atom *) ap;
				ap += sizeof(Atom) / sizeof(uint32);
			}
		}
	}

	void MethodInfo::resolveSignature(const Toplevel* toplevel)
	{
		if (!(flags & LINKED))
		{
			AvmCore* core = this->pool->core;
			AvmAssert(abc_info_pos != NULL);

			const byte* pos = abc_info_pos;

			Traits* t = pool->resolveTypeName(pos, toplevel, /*allowVoid=*/true);

			m_returnType = t;

			restOffset = 0;

			// param 0 is contextual
			t = m_types[0];
			if (!t)
			{
				setParamType(0, OBJECT_TYPE);
				restOffset += sizeof(Atom);
			}
			else
			{
				if (t == NUMBER_TYPE)
					restOffset += sizeof(double);
				else
					restOffset += sizeof(Atom);
				if (t->isInterface)
					flags |= ABSTRACT_METHOD;
			}

			// param types 1..N come from abc stream
			for (int i=1, n=param_count; i <= n; i++)
			{
				t = pool->resolveTypeName(pos, toplevel);
				setParamType(i, t);
				if (t == NUMBER_TYPE)
					restOffset += sizeof(double);
				else
					restOffset += sizeof(Atom);
			}

			AvmCore::skipU30(pos); // name_index;
			pos++; // skip flags

			if (flags & HAS_OPTIONAL)
			{
				AvmCore::skipU30(pos); // optional_count

				initDefaultValues(optional_count);

				for (int j=0,n=optional_count; j < n; j++)
				{
					int param = param_count-optional_count+1+j;
					int index = AvmCore::readU30(pos);
					CPoolKind kind = (CPoolKind)*pos++;

					// check that the default value is legal for the param type
					Traits* t = this->paramTraits(param);
					AvmAssert(Traits::getBuiltinType(t) != BUILTIN_void);

					Atom value = pool->getLegalDefaultValue(toplevel, index, kind, t);
					setDefaultValue(param, value);
				}
			}

			/*
			// Don't need this for anything yet, so no point in wasting time parsing it.  Here just so we don't
			// forget about it if we add any sections after this one, and need to skip past it.  
			if( flags & MethodInfo::HAS_PARAM_NAMES)
			{
				// AVMPlus doesn't care about the param names, just skip past them
				AvmCore::skipU30(pos, param_count);
			}
			*/
			flags |= LINKED;
		}
	}

#ifdef DEBUGGER
	uint32 MethodInfo::size() const 
	{
		uint32 size = sizeof(MethodInfo);
		size += param_count * 2 * sizeof(Atom);
		size += codeSize();
		return size;
	}
#endif

	bool MethodInfo::usesCallerContext() const
	{
		return pool->isBuiltin && (!(isNative()) || (flags & NEEDS_CODECONTEXT));
	}

	// Builtin + non-native functions always need the dxns code emitted 
	// Builtin + native functions have flags to specify if they need the dxns code
	bool MethodInfo::usesDefaultXmlNamespace() const
	{
		return pool->isBuiltin && (!(isNative()) || (flags & NEEDS_DXNS));
	}

#if VMCFG_METHOD_NAMES
	Stringp MethodInfo::getMethodName() const 
	{
		AvmAssert(pool != NULL);

		Stringp name = NULL;
		
		AvmCore* core = pool->core;
		if (core->config.methodNames)
		{
			if (uint32_t(method_id) < uint32_t(pool->method_name_indices.size()))
			{
				const int32_t index = pool->method_name_indices[method_id];
				if (index >= 0)
				{
					name = pool->getString(index);
				}
				else
				{
#ifdef AVMPLUS_WORD_CODE
					// PrecomputedMultinames may not be inited yet, but we'll need them eventually,
					// so go ahead and init them now
					pool->initPrecomputedMultinames();
					const Multiname& mn = pool->word_code.cpool_mn->multinames[-index];
#else
					Multiname mn;
					pool->parseMultiname(pool->cpool_mn[-index], mn);
#endif
					name = Multiname::format(core, mn.getNamespace(), mn.getName());
				}
			}

			if (name && name->length() == 0) 
			{
				name = core->kanonymousFunc;	
			}
			
			Traitsp t = this->declaringTraits;
			if (t)
			{
				Stringp tname = t->format(core);
				if (core->config.oldVectorMethodNames)
				{
					// Tamarin used to incorrectly return the internal name of these
					// Vector types rather than the "official" name due to initialization
					// order. Names on the left are "more correct" but old builds might
					// require the "classic" name for compatibility purposes, so check.
					struct NameMapRec { const char* n; const char* o; };
					static const NameMapRec kNameMap[4] = 
					{
						{ "Vector.<Number>", "Vector$double" }, 
						{ "Vector.<int>", "Vector$int" }, 
						{ "Vector.<uint>", "Vector$uint" }, 
						{ "Vector.<*>", "Vector$object" },
					};
					for (int i = 0; i < 4; ++i)
					{
						if (tname->equalsLatin1(kNameMap[i].n))
							tname = core->newConstantStringLatin1(kNameMap[i].o);
					}
				};
				
				if (this == t->init)
				{
					// careful, name could be null, that's ok for init methods
					if (t->posType() == TRAITSTYPE_SCRIPT_FROM_ABC)
					{
						name = tname->appendLatin1("$init");
					}
					else if (t->posType() == TRAITSTYPE_CLASS_FROM_ABC)
					{
						name = tname->appendLatin1("cinit");
					}
					else
					{
						AvmAssert(t->posType() == TRAITSTYPE_INSTANCE_FROM_ABC || t->posType() == TRAITSTYPE_ACTIVATION);
						name = tname;
					}
				}
				else if (name)
				{
					const char* sep;
					if (flags & IS_GETTER)
						sep = "/get ";
					else if (flags & IS_SETTER)
						sep = "/set ";
					else 
						sep = "/";
					name = tname->appendLatin1(sep)->append(name);
				}
			}
		}
		
		// if config.methodNames isn't set, might as well still return a non-null result
		if (name == NULL)
			name = core->concatStrings(core->newConstantStringLatin1("MethodInfo-"), core->intToString(method_id));
		
		return name;
	}
#endif		
}
