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
 *   leon.sha@sun.com
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
#include "CodegenLIR.h"
#include "../core/FrameState.h"
#include "../nanojit/nanojit.h"

namespace avmplus 
{
	CodegenLIR::CodegenLIR(MethodInfo* info)
		: overflow(true)
	{}

	void CodegenLIR::emitMD()
	{}

	void CodegenLIR::formatOperand(PrintWriter& buffer, OP* oprnd)
	{}

	void CodegenLIR::epilogue(FrameState* state)
	{}

	bool CodegenLIR::prologue(FrameState* state) {
		return true;
	}

	void CodegenLIR::emitCall(FrameState* state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result)
	{}

	void CodegenLIR::emit(FrameState* state, AbcOpcode opcode, uintptr op1, uintptr op2, Traits* result)
	{}

	void CodegenLIR::emitIf(FrameState* state, AbcOpcode opcode, sintptr target, int lhs, int rhs)
	{}

	void CodegenLIR::emitSwap(FrameState* state, int i, int j)
	{}

	void CodegenLIR::emitCopy(FrameState* state, int src, int dest)
	{}

	void CodegenLIR::emitGetscope(FrameState* state, int scope, int dest)
	{}

	void CodegenLIR::emitKill(FrameState* state, int i)
	{}

	void CodegenLIR::emitBlockStart(FrameState* state)
	{}

	void CodegenLIR::emitBlockEnd(FrameState* state)
	{}

	void CodegenLIR::emitIntConst(FrameState* state, int index, uintptr c)
	{}

	void CodegenLIR::emitDoubleConst(FrameState* state, int index, double* pd)
	{}

	void CodegenLIR::emitCoerce(FrameState* state, int index, Traits* type)
	{}

	void CodegenLIR::emitCheckNull(FrameState* state, int index)
	{}

	void CodegenLIR::emitSetContext(FrameState* state, AbstractFunction* f)
	{}

	void CodegenLIR::emitSetDxns(FrameState* state)
	{}

	void CodegenLIR::merge(const Value& current, Value& target)
	{}

	void CodegenLIR::localSet(uintptr i, OP* o)
	{}

	bool isDef(LIns *i) {
		return i && i->isop(LIR_def);
	}

	LIns* CodegenLIR::localGet(int i)
	{
		Value &v = state->value(i);
		return isDef(v.ins) ? (v.ins = useIns(v.ins, i)) : v.ins;
	}

	LIns* CodegenLIR::useIns(LIns* def, int i)
	{
		return 0;
	}
}
