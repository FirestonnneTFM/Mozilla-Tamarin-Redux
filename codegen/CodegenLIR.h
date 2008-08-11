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
 * Portions created by the Initial Developer are Copyright (C) 2004-2008
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

#ifndef __avmplus_CodegenLIR__
#define __avmplus_CodegenLIR__

namespace nanojit
{
	class LIns;
	class LirBuffer;
	class LirWriter;
    class Fragmento;
    enum LOpcode;
}

namespace avmplus
{
	using namespace nanojit;
    using namespace MMgc;

	class MethodInfo;
	typedef LIns OP;

	struct CodegenLabel {
		LIns *bb;
		LIns **nextPatchIns;
	};

    class PageMgr {
    public:
        Fragmento *frago;
        PageMgr();
    };

    enum MirOpcode {
        MIR_cm, MIR_cmop,
        MIR_cs, MIR_csop,
        MIR_fcm, MIR_fcmop,
        MIR_fcs, MIR_fcsop,
    };

	class CodegenLIR {
	public:
		bool overflow;
		LIns *exAtom;
		const byte *abcStart;
		const byte *abcEnd;

	private:
        GC *gc;
        AvmCore *core;
        MethodInfo *info;
        Fragmento *frago;
		LirBuffer *lirbuf;
		LirWriter *lirout;
		FrameState *state;
        LIns *locals;
        LIns *localTraits;
        LIns *env_param, *argc_param, *ap_param;
        LIns *_save_eip, *_ef;
        LIns *dxns, *dxnsAddrSave;
        LIns *_callStackNode;
        LIns *undefConst;
        bool interruptable;
        CodegenLabel interrupt_label;

        LIns *InsAlloc(int32_t);
        LIns *loadIns(LOpcode op, int32_t disp, LIns *base);
        LIns *Ins(LOpcode op, LIns *lhs, LIns *rhs);
        LIns *Ins(LOpcode op, LIns *a);
        LIns *Ins(LOpcode op);
        LIns *storeIns(LIns *val, int32_t disp, LIns *base);
        LIns *InsConst(int32_t c);
        LIns *defIns(LIns *i);
        LIns *atomToNativeRep(int loc, LIns *i);
        LIns *atomToNativeRep(Traits *, LIns *i);
        LIns *callIns(MirOpcode, uintptr_t funcid, int argc, ...);
        LIns *i2dIns(OP* v);
        LIns *leaIns(int32_t d, LIns *base);
        LIns *binaryIns(LOpcode, LIns *a, LIns *b);
        LIns *localGet(int i);
        LIns *localGetq(int i);
    	void patchPtr(OP** targetp, uintptr_t pc);
    	void patchPtr(OP** targetp, CodegenLabel& l);
        void patch(LIns *j, CodegenLabel& l);
        bool isDouble(int i);
        bool isPointer(int i);
        void saveState();

	public:
		CodegenLIR(MethodInfo* info);
		void emitMD();
	    void formatOperand(PrintWriter& buffer, OP* oprnd);
		void epilogue(FrameState* state);
		bool prologue(FrameState* state);
		void emitCall(FrameState* state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result);
		void emit(FrameState* state, AbcOpcode opcode, uintptr op1=0, uintptr op2=0, Traits* result=NULL);
		void emitIf(FrameState* state, AbcOpcode opcode, sintptr target, int lhs, int rhs);
		void emitSwap(FrameState* state, int i, int j);
		void emitCopy(FrameState* state, int src, int dest);
		void emitGetscope(FrameState* state, int scope, int dest);
		void emitKill(FrameState* state, int i);
		void emitBlockStart(FrameState* state);
		void emitBlockEnd(FrameState* state);
		void emitIntConst(FrameState* state, int index, uintptr c);
		void emitDoubleConst(FrameState* state, int index, double* pd);
		void emitCoerce(FrameState* state, int index, Traits* type);
		void emitCheckNull(FrameState* state, int index);
		void emitSetContext(FrameState* state, AbstractFunction* f);
		void emitSetDxns(FrameState* state);
		void merge(const Value& current, Value& target);
		void localSet(uintptr i, OP* o);
	};
}

#endif /* __avmplus_CodegenLIR__ */
