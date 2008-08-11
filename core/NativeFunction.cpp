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
#ifdef AVMTHUNK_VERSION
	NativeMethod::NativeMethod(const NativeTableEntry& _nte)
		: AbstractFunction(), nte(_nte)
	{
		this->flags |= nte.flags;
		this->impl32 = verifyEnter;
	}
#else
	NativeMethod::NativeMethod(int flags, Handler handler, int cookie)
		: AbstractFunction()
	{
		m_handler = handler;
		m_cookie  = cookie;
		this->flags |= flags;
		this->impl32 = verifyEnter;
	}
#endif

	Atom NativeMethod::verifyEnter(MethodEnv* env, int argc, uint32 *ap)
	{
		NativeMethod* f = (NativeMethod*) env->method;

		f->verify(env->vtable->toplevel);

		#ifdef AVMPLUS_VERIFYALL
		f->flags |= VERIFIED;
		if (f->pool->core->verifyall && f->pool)
			f->pool->processVerifyQueue(env->toplevel());
		#endif

		env->impl32 = f->impl32;
		return f->impl32(env, argc, ap);
	}

	void NativeMethod::verify(Toplevel *toplevel)
	{
		AvmAssert(declaringTraits->linked);
		resolveSignature(toplevel);

#ifdef AVMTHUNK_VERSION
		union {
			Atom (*impl32)(MethodEnv*, int, uint32 *);
			AvmThunkNativeThunker thunker;
		} u;
		u.thunker = this->nte.thunker;
		this->impl32 = u.impl32;
#else
		// generate the native method thunk
		CodegenMIR cgen(this);
		cgen.emitNativeThunk(this);
		if (cgen.overflow)
			toplevel->throwError(kOutOfMemoryError);
#endif
	}
}
