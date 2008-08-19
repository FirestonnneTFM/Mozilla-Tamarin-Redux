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

/*namespace nanojit
{
	class LIns;
	class LirBuffer;
	class LirWriter;
    class Fragmento;
    enum LOpcode;
}*/
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

	enum MirOpcode 
	{
		MIR_bb      = 2,
		MIR_jmpt	= 3,				// offset, size
		MIR_cm		= 4,				// count, imm32  - call method
		MIR_cs		= 5,				// count, imm32  - call static
		MIR_ci		= 6,				// count, ptr	 - call indirect
		MIR_icmp 	= 7,				// ptr, imm32
		MIR_ucmp	= 8,				// ptr, imm32
		MIR_fcmp	= 9,				// ptr, imm32
		MIR_jeq		= 10,				// ptr, imm32
		MIR_jne		= 11,				// ptr, imm32
		MIR_ret		= 12,				// ptr
		MIR_jmp		= 13,				// ptr
		MIR_jmpi	= 14,				// ptr, disp
		MIR_st		= 15,				// ptr, disp, ptr
		MIR_arg     = 16,				// pos | reg - defines methods incoming arguments
		MIR_def		= 17,				// 
		MIR_use		= 18,				// 
		MIR_usea	= 19,				// imm32
		MIR_alloc   = 20,
		MIR_addp  = 21,     // no cse add for adjusted builtin ScriptObject ptrs
		MIR_ld      = 22,				// non-optimizable load
		MIR_jlt     = 23,
		MIR_jle		= 24,
		MIR_jnlt	= 25,
		MIR_jnle	= 26,
		MIR_file	= 27,
		MIR_line	= 28,
		MIR_st32	= 29,
#ifdef AVMPLUS_64BIT
		MIR_ld32	= 30,
		MIR_ld32u	= 31,
#else
		MIR_ld32	= MIR_ld,
#endif
    	MIR_float = 0x20,		// result is double
	    MIR_oper  = 0x40,		// eligible for cse

		MIR_imm		= 1  | MIR_oper,	// 0,imm32
		MIR_imul	= 2  | MIR_oper,
		MIR_neg		= 3  | MIR_oper,	// ptr, ptr
		MIR_cmop    = 4  | MIR_oper,    // MIR_cm|oper, call method w/out side effects
		MIR_csop    = 5  | MIR_oper,    // MIR_cs|oper, call static method w/out side effects
		MIR_lsh		= 6  | MIR_oper,	// <<
		MIR_rsh		= 7  | MIR_oper,	// >>
		MIR_ush		= 8  | MIR_oper,	// >>>
		MIR_and		= 9  | MIR_oper,
		MIR_or		= 10 | MIR_oper,
		MIR_xor		= 11 | MIR_oper,
		MIR_add		= 12 | MIR_oper,
		MIR_sub		= 13 | MIR_oper,	// ptr, ptr
		MIR_eq		= 14 | MIR_oper,
		MIR_le		= 15 | MIR_oper,
		MIR_lt		= 16 | MIR_oper,
		MIR_ne		= 17 | MIR_oper,
		MIR_lea		= 18 | MIR_oper,	// ptr, disp

		MIR_ldop    = 22 | MIR_oper,    // ptr, disp (optimizable)

		// After this point are all instructions that return a double-sized
		// result.
		MIR_fcm		= 4  | MIR_float,	// count, imm32 - call method, float return
		MIR_fcs		= 5  | MIR_float,	// count, imm32 - call static, float return
		MIR_fci		= 6	 | MIR_float,	// count, addr - call indirect, float return

		MIR_fdef    = 17 | MIR_float,   // defines value of variable as floating point
		MIR_fuse    = 18 | MIR_float,   // 

		MIR_fld		= 22 | MIR_float,	// float load

		MIR_i2d		= 1  | MIR_float | MIR_oper,	// ptr
		MIR_fneg	= 2  | MIR_float | MIR_oper,	// ptr
		MIR_u2d		= 3  | MIR_float | MIR_oper,
		MIR_fcmop   = 4  | MIR_float | MIR_oper,
		MIR_fcsop   = 5  | MIR_float | MIR_oper,
		MIR_fadd	= 6  | MIR_float | MIR_oper,	// ptr, ptr
		MIR_fsub	= 7  | MIR_float | MIR_oper,	// ptr, ptr
		MIR_fmul	= 8  | MIR_float | MIR_oper,	// ptr, ptr
		MIR_fdiv	= 9  | MIR_float | MIR_oper,	// ptr, ptr
#ifdef AVMPLUS_IA32
		MIR_faddi	= 10 | MIR_float | MIR_oper,	// ptr, disp
#endif
		
		MIR_fldop   = 22 | MIR_float | MIR_oper,	// ptr, disp (optimizable load)

		MIR_last	= 23 | MIR_float | MIR_oper // highest ordinal value possible
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
        bool interruptable;
        CodegenLabel interrupt_label, npe_label;
        sintptr lastPcSave;
        List<Patch, LIST_NonGCObjects> patches;

        LIns *InsAlloc(int32_t);
        LIns *loadIns(MirOpcode op, int32_t disp, LIns *base);
        LIns *Ins(MirOpcode);
        LIns *Ins(MirOpcode, uintptr_t);
        LIns *Ins(MirOpcode, LIns*, uintptr_t);
        LIns *Ins(MirOpcode, LIns *a, LIns *b);
        LIns *Ins(MirOpcode, LIns *a);
        void storeIns(LIns *val, int32_t disp, LIns *base);
        void storeIns(LIns *val, int32_t disp, LIns *base, bool force32);
        LIns *InsConst(int32_t c);
        LIns *defIns(LIns *i);
        LIns *atomToNativeRep(int loc, LIns *i);
        LIns *atomToNativeRep(Traits *, LIns *i);
        LIns *ptrToNativeRep(Traits*, LIns*);
        LIns *loadAtomRep(int i);
        LIns *callIns(MirOpcode, uintptr_t addr, uint32_t argc, ...);
        LIns *callIndirect(MirOpcode, LIns* addr, uint32_t argc, ...);
        LIns *leaIns(int32_t d, LIns *base);
        LIns *binaryIns(MirOpcode, LIns *a, LIns *b);
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
    	LIns* cmpEq(sintptr funcaddr, int lhsi, int rhsi);
    	LIns* cmpLt(int lhsi, int rhsi);
    	LIns* cmpLe(int lhsi, int rhsi);
        LIns* cmpOptimization(int lhsi, int rhsi, LOpcode icmp, LOpcode ucmp, LOpcode fcmp);
	    LIns* i2dIns(LIns* v);
	    LIns* u2dIns(LIns* v);
        bool isDouble(int i);
        bool isPointer(int i);
        void saveState();
        void label(CodegenLabel &label, LIns *bb);
        void emitPrep(AbcOpcode);
        void emitSampleCheck();
        void InsDealloc(LIns *a);
        bool verbose();
        void extendDefLifetime(OP*);
        void extendLastUse(LIns *i, sintptr pc);
        void extendLastUse(LIns *ins, LIns *use, LIns *target);
        void patchLater(LIns *br, CodegenLabel &);
        void patchLater(LIns *br, intptr_t pc);
        bool isCodeContextChanged() const;
        void mirLabel(CodegenLabel &l, LIns *target);
        void markDead(LIns *);

	public:
		CodegenLIR(MethodInfo* info);
        ~CodegenLIR();
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

    // helpers for jitted code
		static Atom coerce_o(Atom v);
	};
}

#endif /* __avmplus_CodegenLIR__ */
