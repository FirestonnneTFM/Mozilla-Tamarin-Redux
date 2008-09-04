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

#include "../nanojit/nanojit.h"

namespace avmplus
{
	using namespace nanojit;
    using namespace MMgc;

	class MethodInfo;
	typedef LIns OP;

	class CodegenLabel {
    public:
		LIns *bb;
		int preds;
        CodegenLabel() : bb(0), preds(0)
        {}
	};

    class PageMgr : public GCFinalizedObject {
    public:
        DWB(Fragmento*) frago;
        PageMgr();
        virtual ~PageMgr();
    };

    class Patch {
    public:
        LIns *br;
        CodegenLabel *label;
        Patch() : br(0), label(0) {}
        Patch(int) : br(0), label(0) {}
        Patch(LIns *br, CodegenLabel &l) : br(br), label(&l) {}
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
        PoolObject *pool;
        Fragment *frag;
		LirBuffer *lirbuf;
		LirWriter *lirout;
		FrameState *state;
        LIns *vars, *varTraits, *varPtrs;
        LIns *env_param, *argc_param, *ap_param;
        LIns *_save_eip, *_ef;
        LIns *dxns, *dxnsAddrSave;
        LIns *csn;
        LIns *undefConst;
		LIns *coreAddr;
        bool interruptable;
        CodegenLabel interrupt_label, npe_label;
        sintptr lastPcSave;
        List<Patch, LIST_NonGCObjects> patches;

        LIns *InsAlloc(int32_t);
        LIns *loadIns(LOpcode op, int32_t disp, LIns *base);
        LIns *Ins(LOpcode);
        LIns *Ins(LOpcode, LIns *a);
        void storeIns(LIns *val, int32_t disp, LIns *base);
        void storeIns(LIns *val, int32_t disp, LIns *base, bool force32);
        LIns *InsConst(int32_t c);
        LIns *InsConst(const void *p) { return InsConst((int32_t)p); }
        LIns *defIns(LIns *i);
        LIns *atomToNativeRep(int loc, LIns *i);
        LIns *atomToNativeRep(Traits *, LIns *i);
        LIns *ptrToNativeRep(Traits*, LIns*);
        LIns *loadAtomRep(int i);
        LIns *callIns(uint32_t fid, uint32_t argc, ...);
        LIns *callIndirect(uint32_t fid, LIns* addr, uint32_t argc, ...);
        LIns *leaIns(int32_t d, LIns *base);
        LIns *binaryIns(LOpcode, LIns *a, LIns *b);
        LIns *localGet(int i);
        LIns *localGetq(int i);
        LIns *localCopy(int i); // sniff's type
        LIns *branchIns(LOpcode op, LIns *cond, LIns *target=0);
        LIns *retIns(LIns *val);
        LIns *loadToplevel(LIns* env);
        LIns *initMultiname(Multiname* multiname, int& csp, bool isDelete =false);
        LIns *storeAtomArgs(int count, int index);
        LIns *storeAtomArgs(LIns *obj, int count, int index);
        LIns *promoteNumberIns(Traits *t, int i);
        LIns *loadVTable(int i);
    	LIns *cmpEq(uint32_t fid, int lhsi, int rhsi);
    	LIns *cmpLt(int lhsi, int rhsi);
    	LIns *cmpLe(int lhsi, int rhsi);
        LIns *cmpOptimization(int lhsi, int rhsi, LOpcode icmp, LOpcode ucmp, LOpcode fcmp);
	    LIns *i2dIns(LIns* v);
	    LIns *u2dIns(LIns* v);
        bool isDouble(int i);
        bool isPointer(int i);
        void label(CodegenLabel &label, LIns *bb);
        void emitPrep(AbcOpcode);
        void emitSampleCheck();
        bool verbose();
        void patchLater(LIns *br, CodegenLabel &);
        void patchLater(LIns *br, intptr_t pc);
        bool isCodeContextChanged() const;
        void mirLabel(CodegenLabel &l, LIns *target);
        uint32_t find_fid(uintptr_t addr);
        void deadvars();

	public:
		CodegenLIR(MethodInfo* info);
        ~CodegenLIR();
		void clearMIRBuffers();
		void emitMD();
	    void formatOperand(PrintWriter& buffer, LIns* oprnd);
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
		void localSet(uintptr i, LIns* o);

    // helpers for jitted code
		static Atom coerce_o(Atom v);
	};
}

#endif /* __avmplus_CodegenLIR__ */
