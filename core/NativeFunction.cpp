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

namespace avmplus
{
	NativeMethod::NativeMethod(const NativeMethodInfo& _nte)
		: AbstractFunction(), nte(_nte)
	{
		this->flags |= nte.flags;
		this->impl32 = verifyEnter;
	}

	Atom NativeMethod::verifyEnter(MethodEnv* env, int argc, uint32 *ap)
	{
		NativeMethod* f = (NativeMethod*) env->method;

        //f->core()->console << "native verify " << f << "\n";
		f->verify(env->vtable->toplevel);

		#ifdef AVMPLUS_VERIFYALL
		f->flags |= VERIFIED;
		f->core()->processVerifyQueue(env->toplevel());
		#endif

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
		} u;
		u.thunker = this->nte.thunker;
		this->impl32 = u.impl32;
	}

	// ---------------

	NativeInitializer::NativeInitializer(AvmCore* _core, 
											NativeClassInfop _classEntry, 
											NativeScriptInfop _scriptEntry,
											NativeClassInfop _classEntry2, 
											NativeScriptInfop _scriptEntry2,
											const uint8_t* _abcData,
											uint32_t _abcDataLen,
											uint32_t _methodCount,
											uint32_t _classCount,
											uint32_t _scriptCount) :
		core(_core),
		abcData(_abcData),
		abcDataLen(_abcDataLen),
		methods((NativeMethodInfop*)core->GetGC()->Calloc(_methodCount, sizeof(NativeMethodInfop), GC::kZero)),
		classes((NativeClassInfop*)core->GetGC()->Calloc(_classCount, sizeof(NativeClassInfop), GC::kZero)),
		scripts((NativeScriptInfop*)core->GetGC()->Calloc(_scriptCount, sizeof(NativeScriptInfop), GC::kZero)),
		methodCount(_methodCount),
		classCount(_classCount),
		scriptCount(_scriptCount)
	{
		fillInClasses(_classEntry);
		if (_classEntry2 != _classEntry)
			fillInClasses(_classEntry2);

		fillInScripts(_scriptEntry);
		if (_scriptEntry2 != _scriptEntry)
			fillInScripts(_scriptEntry2);
	}

	void NativeInitializer::fillInMethods(NativeMethodInfop _methodEntry)
	{
		while (_methodEntry->method_id != -1)
		{
			// if we overwrite a native method mapping, something is hosed
			AvmAssert(methods[_methodEntry->method_id] == NULL);
			methods[_methodEntry->method_id] = _methodEntry;
			_methodEntry++;
		}
	}

	void NativeInitializer::fillInClasses(NativeClassInfop _classEntry)
	{
		while (_classEntry->class_id != -1)
		{
			classes[_classEntry->class_id] = _classEntry;
			fillInMethods(_classEntry->nativeMap);
			_classEntry++;
		}
	}

	void NativeInitializer::fillInScripts(NativeScriptInfop _scriptEntry)
	{
		while (_scriptEntry->script_id != -1)
		{
			scripts[_scriptEntry->script_id] = _scriptEntry;
			fillInMethods(_scriptEntry->nativeMap);
			_scriptEntry++;
		}
	}
	
	PoolObject* NativeInitializer::parseBuiltinABC(const List<Stringp, LIST_RCObjects>* includes)
	{
		AvmAssert(core->builtinDomain != NULL);
		
		ScriptBuffer code = ScriptBuffer(new (core->GetGC()) ReadOnlyScriptBufferImpl(abcData, abcDataLen));

		return core->parseActionBlock(code, /*start*/0, /*toplevel*/NULL, core->builtinDomain, this, includes);
	}
	
	NativeInitializer::~NativeInitializer()
	{
		// might as well explicitly free now
		core->GetGC()->Free(methods);
		core->GetGC()->Free(classes);
		core->GetGC()->Free(scripts);
	}
}
