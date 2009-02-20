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
#include "BuiltinNatives.h"

#ifdef AVMPLUS_MIR
#include "../codegen/CodegenMIR.h"
#endif

using namespace MMgc;

namespace avmplus
{
	// ---------------

	NativeMethod::NativeMethod(int _method_id, AvmThunkNativeThunker _thunker, AvmThunkNativeHandler _handler)
		: AbstractFunction(_method_id), thunker(_thunker), handler(_handler)
	{
		this->impl32 = verifyEnter;
	}

	typedef AvmBox (*AvmThunkNativeThunker)(AvmMethodEnv env, uint32_t argc, AvmBox* argv);

#ifdef DEBUGGER
	/*static*/ AvmBox NativeMethod::debugEnterExitWrapper32(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
	{
		CallStackNode csn(CallStackNode::kEmpty); 
		env->debugEnter(argc, (uint32_t*)argv, /*frametraits*/0, /*localCount*/0, &csn, /*framep*/0, /*eip*/0); 
		const AvmBox result = static_cast<NativeMethod*>(env->method)->thunker(env, argc, argv);
		env->debugExit(&csn);
		return result;
	}

	/*static*/ double NativeMethod::debugEnterExitWrapperN(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
	{
		CallStackNode csn(CallStackNode::kEmpty); 
		env->debugEnter(argc, (uint32_t*)argv, /*frametraits*/0, /*localCount*/0, &csn, /*framep*/0, /*eip*/0); 
		const double result = (reinterpret_cast<AvmThunkNativeThunkerN>(static_cast<NativeMethod*>(env->method)->thunker))(env, argc, argv);
		env->debugExit(&csn);
		return result;
	}
#endif

	/*static*/ Atom NativeMethod::verifyEnter(MethodEnv* env, int argc, uint32* ap)
	{
		NativeMethod* f = (NativeMethod*) env->method;

		#ifdef AVMPLUS_VERIFYALL
		// never verify late in verifyall mode
		AvmAssert(!f->pool->core->config.verifyall);
		#endif

		f->verify(env->vtable->toplevel);
		env->impl32 = f->impl32;
		return f->impl32(env, argc, ap);
	}

	void NativeMethod::verify(Toplevel *toplevel)
	{
		AvmAssert(declaringTraits->isResolved());
		resolveSignature(toplevel);
		union {
			Atom (*impl32)(MethodEnv*, int, uint32 *);
			AvmThunkNativeThunker thunker;
			AvmThunkNativeThunkerN thunkerN;
		} u;
#ifdef DEBUGGER
		if (toplevel->core()->debugger())
		{
			if (Traits::getBuiltinType(returnTraits()) == BUILTIN_number)
				u.thunkerN = NativeMethod::debugEnterExitWrapperN;
			else
				u.thunker = NativeMethod::debugEnterExitWrapper32;
		}
		else
#endif
		{
			u.thunker = this->thunker;
		}
		this->impl32 = u.impl32;
	}

	// ---------------

	NativeInitializer::NativeInitializer(AvmCore* _core, 
											const uint8_t* _abcData,
											uint32_t _abcDataLen,
											uint32_t _methodCount,
											uint32_t _classCount) :
		core(_core),
		abcData(_abcData),
		abcDataLen(_abcDataLen),
		methods((MethodType*)core->GetGC()->Calloc(_methodCount, sizeof(MethodType), GC::kZero)),
		classes((ClassType*)core->GetGC()->Calloc(_classCount, sizeof(ClassType), GC::kZero)),
		methodCount(_methodCount),
		classCount(_classCount)
	{
	}

#ifdef AVMPLUS_NO_STATIC_POINTERS
	void NativeInitializer::fillIn(NativeInitializer::FillInProc p)
	{
		(*p)(methods, classes);
	}
#else
	void NativeInitializer::fillInMethods(const NativeMethodInfo* _methodEntry)
	{
		while (_methodEntry->method_id != -1)
		{
			// if we overwrite a native method mapping, something is hosed
			AvmAssert(methods[_methodEntry->method_id] == NULL);
			methods[_methodEntry->method_id] = _methodEntry;
			_methodEntry++;
		}
	}

	void NativeInitializer::fillInClasses(const NativeClassInfo* _classEntry)
	{
		while (_classEntry->class_id != -1)
		{
			// if we overwrite a native class mapping, something is hosed
			AvmAssert(classes[_classEntry->class_id]  == NULL);
			classes[_classEntry->class_id] = _classEntry;
			_classEntry++;
		}
	}

#endif // AVMPLUS_NO_STATIC_POINTERS
	
	PoolObject* NativeInitializer::parseBuiltinABC(Domain* domain, const List<Stringp, LIST_RCObjects>* includes)
	{
		AvmAssert(domain != NULL);
		
		ScriptBuffer code = ScriptBuffer(new (core->GetGC()) ReadOnlyScriptBufferImpl(abcData, abcDataLen));

		return core->parseActionBlock(code, /*start*/0, /*toplevel*/NULL, domain, this, (const List<Stringp>*)includes);
	}
	
	NativeMethod* NativeInitializer::newNativeMethod(uint32_t i) const
	{
		const NativeMethodInfo* ni = get_method(i);
		if (!ni)
			return NULL;

		NativeMethod* info = new (core->GetGC()) NativeMethod(i, ni->thunker, ni->handler);
		info->flags |= AbstractFunction::ABSTRACT_METHOD | AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS;
		return info;
	}

	NativeInitializer::~NativeInitializer()
	{
		// might as well explicitly free now
		core->GetGC()->Free(methods);
		core->GetGC()->Free(classes);
	}
}
