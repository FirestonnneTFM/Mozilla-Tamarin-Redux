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

// SETJMP setup
#ifdef _MSC_VER
#if !defined (AVMPLUS_ARM)
extern "C"
{
	int __cdecl _setjmp3(jmp_buf jmpbuf, int arg);
}
#else
#include <setjmp.h>
jmp_buf buf;
#endif // AVMPLUS_ARM
#endif // _MSC_VER

#ifdef AVMPLUS_64BIT
#define AVMCORE_integer			AvmCore::integer64
#define AVMCORE_integer_i		AvmCore::integer64_i
#define AVMCORE_integer_d		AvmCore::integer64_d
#define AVMCORE_integer_d_sse2	AvmCore::integer64_d_sse2
#else
#define AVMCORE_integer			AvmCore::integer
#define AVMCORE_integer_i		AvmCore::integer_i
#define AVMCORE_integer_d		AvmCore::integer_d
#define AVMCORE_integer_d_sse2	AvmCore::integer_d_sse2
#endif


namespace avmplus 
{
    namespace helpers
    {
        //using namespace avmplus;

        Atom FASTCALL doubleToAtom(AvmCore *core, double d) {
            return core->doubleToAtom(d);
        }

        Atom FASTCALL doubleToAtom_sse2(AvmCore *core, double d) {
            return core->doubleToAtom_sse2(d);
        }

        Atom FASTCALL intToAtom(AvmCore *core, int i) {
            return core->intToAtom(i);
        }
        Atom FASTCALL uintToAtom(AvmCore *core, int i) {
            return core->uintToAtom(i);
        }

        int FASTCALL avmcore_integer_i(Atom a) {
            return AVMCORE_integer_i(a);
        }

        void FASTCALL debugenter(MethodEnv *env, int argc, uint32_t *ap, Traits** ft,
            int local_count, CallStackNode *csn, sintptr *eip) {
		    env->debugEnter(argc, ap, ft, local_count, csn, 0, eip);
        }

        void FASTCALL debugexit(MethodEnv *env, CallStackNode *csn) {
            env->debugExit(csn);
        }

        ArrayObject* FASTCALL createRestHelper(MethodEnv *env, int argc, uint32 *ap) {
            return env->createRestHelper(argc, ap);
        }

        ArrayObject* FASTCALL createArgumentsHelper(MethodEnv *env, int argc, uint32 *ap) {
            return env->createArgumentsHelper(argc, ap);
        }

        void FASTCALL beginTry(ExceptionFrame *ef, AvmCore *core) {
            return ef->beginTry(core);
        }

        int FASTCALL lirsetjmp(int *buf, int arg) {
            // this probably won't work -- need to call the real setjmp directly from jitted code.
            return _setjmp3(buf, arg);
        }

        ExceptionHandler* FASTCALL beginCatch(AvmCore *core, ExceptionFrame *ef,
            MethodInfo *info, sintptr pc, Exception *exception) {
            return core->beginCatch(ef, info, pc, exception);
        }

        double FASTCALL number_d(Atom a) {
            return AvmCore::number_d(a);
        }

        uint32_t FASTCALL integer_u(Atom a) {
            return AvmCore::integer_u(a);
        }

        void FASTCALL wbrc(GC *gc, const void *container, const void *addr, const void *value) {
            gc->writeBarrierRC(container, addr, value);
        }

        void FASTCALL wbatom(GC *gc, const void *container, Atom *addr, Atom a) {
            AvmCore::atomWriteBarrier(gc, container, addr, a);
        }

        void FASTCALL endtry(ExceptionFrame *ef) {
            ef->endTry();
        }

        Atom FASTCALL coerce(Toplevel *tl, Atom a, Traits *t) {
            return tl->coerce(a, t);
        }

        double FASTCALL mod(double a, double b) {
            return MathUtils::mod(a, b);
        }

        void FASTCALL throwatom(AvmCore *core, Atom a) {
            core->throwAtom(a);
        }

        Stringp FASTCALL typeof(AvmCore *core, Atom a) {
            return core->_typeof(a);
        }

        Atom FASTCALL getsuper(MethodEnv *env, Atom obj, Multiname *n) {
            return env->getsuper(obj, n);
        }

        void FASTCALL setsuper(MethodEnv *env, Atom obj, Multiname *n, Atom v) {
            env->setsuper(obj, n, v);
        }

        Atom FASTCALL nextname(MethodEnv *env, Atom obj, int i) {
            return env->nextname(obj, i);
        }

        Atom FASTCALL nextvalue(MethodEnv *env, Atom obj, int i) {
            return env->nextvalue(obj, i);
        }

        int FASTCALL hasnext(MethodEnv *env, Atom obj, int i) {
            return env->hasnext(obj, i);
        }
        int FASTCALL hasnext2(MethodEnv *env, Atom &obj, int &i) {
            return env->hasnext2(obj, i);
        }

        Namespace* FASTCALL intern_ns(MethodEnv *env, Atom ns) {
            return env->internRtns(ns);
        }

        void FASTCALL initname_late(AvmCore *core, Multiname &name, Atom n) {
            return core->initMultinameLate(name, n);
        }

        void FASTCALL initname_late_del(MethodEnv *env, Multiname &name, Atom n) {
            return env->initMultinameLateForDelete(name, n);
        }

        #define INTERP_FOPCODE_LIST_BEGIN static const CallInfo functions[] = {
        #define INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,cse,fold,ret,args) \
            { (intptr_t)helpers::f, sig, cse, fold, #f },
        #define INTERP_FOPCODE_LIST_END };

            #include "../core/vm_fops.h"

        #undef INTERP_FOPCODE_LIST_BEGIN
        #undef INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM
        #undef INTERP_FOPCODE_LIST_END
    }

    static const LOpcode 
        MIR_add = LIR_add,
        MIR_fldop = LIR_ldq, // need cse-optimized version
        MIR_fld = LIR_ldq,
        MIR_i2d = LIR_i2f,
        MIR_and = LIR_and,
        MIR_xor = LIR_xor,
        MIR_or = LIR_or,
        MIR_imul = LIR_mul,
        MIR_sub = LIR_sub,
        MIR_neg = LIR_neg,
        MIR_fneg = LIR_fneg,
        MIR_fadd = LIR_fadd,
        MIR_fmul = LIR_fmul,
        MIR_fsub = LIR_fsub,
        MIR_fdiv = LIR_fdiv,
        MIR_addp = LIR_add,
        MIR_bb = LIR_label,
        MIR_ldop = LIR_ldc,
        MIR_jmpi = LIR_ji,
        MIR_ld = LIR_ld,
        MIR_ush = LIR_ush,
        MIR_lsh = LIR_lsh,
        MIR_rsh = LIR_rsh;

    PageMgr::PageMgr() : frago(0)
    {}

	CodegenLIR::CodegenLIR(MethodInfo* info)
		: gc(info->pool->core->gc), info(info), overflow(false)
    {
        PoolObject *pool = this->pool = info->pool;
        core = pool->core;
        if (!pool->codePages) {
            pool->codePages = new (gc) PageMgr();
            pool->codePages->frago = new (gc) Fragmento(core, 24/*16mb*/);
            pool->codePages->frago->labels = new (gc) LabelMap(core, 0);
        }
        frago = pool->codePages->frago;
    }

    void CodegenLIR::emitMD() {
        // run the assembler
	}

	void CodegenLIR::formatOperand(PrintWriter& buffer, LIns* i) {
        buffer << "@" << lirbuf->names->formatRef(i);
    }

	void CodegenLIR::epilogue(FrameState* state) {
        this->state = state;
    }

	bool CodegenLIR::prologue(FrameState* state) {
        this->state = state;
        lirbuf = new (gc) LirBuffer(frago, helpers::functions);
        lirout = new (gc) LirBufWriter(lirbuf);
        lirbuf->names = new (gc) LirNameMap(gc, helpers::functions, frago->labels);
        lirout = new (gc) VerboseWriter(gc, lirout, lirbuf->names);
        lirout = new (gc) ExprFilter(lirout);
		
		abcStart = state->verifier->code_pos;
		abcEnd   = abcStart + state->verifier->code_length;

        // cdecl calling convention
        env_param = lirout->insParam(0);
        argc_param = lirout->insParam(1);
        ap_param = lirout->insParam(2);
        locals = InsAlloc(state->verifier->frameSize * 8);
        verbose_only(if (lirbuf->names) {
            lirbuf->names->addName(locals, "locals"); 
            lirbuf->names->addName(localTraits, "localTraits"); 
            lirbuf->names->addName(env_param, "env_param"); 
            lirbuf->names->addName(argc_param, "argc_param"); 
            lirbuf->names->addName(ap_param, "ap_param"); 
        })

		#ifdef DEBUGGER
		// pointers to traits so that the debugger can decode the locals
		// IMPORTANT don't move this around unless you change MethodInfo::boxLocals()
		localTraits = InsAlloc(state->verifier->local_count * sizeof(Traits*));
        verbose_only(if (lirbuf->names) {
            lirbuf->names->addName(localTraits, "localTraits"); 
        })
		#endif //DEBUGGER

		// whether this sequence is interruptable or not.
		interruptable = (info->flags & AbstractFunction::NON_INTERRUPTABLE) ? false : true;
		
		// then space for the exception frame, be safe if its an init stub
		if (info->isFlagSet(AbstractFunction::HAS_EXCEPTIONS))
		{
			// [_save_eip][ExceptionFrame]
			// offsets of local vars, rel to current ESP
			_save_eip = InsAlloc(sizeof(byte*));
			_ef       = InsAlloc(sizeof(ExceptionFrame));
            verbose_only(if (lirbuf->names) {
                lirbuf->names->addName(_save_eip, "_save_eip"); 
                lirbuf->names->addName(_ef, "_ef"); 
            })
		}

		if (info->setsDxns())
		{
			dxns = InsAlloc(sizeof(Namespace*));
            verbose_only(if (lirbuf->names) {
                lirbuf->names->addName(dxns, "dxns"); 
            })
		}

		#ifdef DEBUGGER
		if(core->sampling())
		{
			// FIXME: 64 bit integer math needed!
			//OP* invocationCount = loadIns(MIR_ldop64, offsetof(MethodEnv, invocationCount), env_param);
			//Ins(MIR_inc64, invocationCount);
			//storeIns64(invocationCount, offsetof(MethodEnv, invocationCount), env_param);
			OP* invocationCount = loadIns(LIR_ldc, offsetof(MethodEnv, invocationCount), env_param);
			OP *result = Ins(LIR_add, invocationCount, InsConst(1));
			storeIns(result, offsetof(MethodEnv, invocationCount), env_param);
		}

		// Allocate space for the call stack
		_callStackNode = InsAlloc(sizeof(CallStackNode));
        verbose_only(if (lirbuf->names) {
            lirbuf->names->addName(_callStackNode, "_callStackNode"); 
        })
		#endif
		
		if (info->setsDxns())
		{
			// dxns = env->vtable->scope->defaultXmlNamespace
			OP* declVTable = loadIns(LIR_ldc, offsetof(MethodEnv, vtable), env_param);
			OP* scope = loadIns(LIR_ldc, offsetof(VTable, scope), declVTable);
			OP* capturedDxns = loadIns(LIR_ldc, offsetof(ScopeChain, defaultXmlNamespace), scope);
			storeIns(capturedDxns, 0, dxns);

			// dxnsSave = AvmCore::dxnsAddr
			dxnsAddrSave = loadIns(MIR_ldop, offsetof(AvmCore, dxnsAddr), InsConst((uintptr)core));
		}

		for (int i=0, n = state->verifier->stackBase+state->stackDepth; i < n; i++)
		{
			Value& v = state->value(i);
			v.ins = 0;
			v.stored = false;
		}

		//
		// copy args to local frame
		//

		// copy required args, and initialize optional args.
		// this whole section only applies to functions that actually
		// have arguments.

		OP* apArg = ap_param;
		if (info->flags & AbstractFunction::HAS_OPTIONAL)
		{
			// compute offset of first optional arg
			int offset = 0;
			for (int i=0, n=info->param_count-info->optional_count; i <= n; i++)
                offset += info->paramTraits(i) == NUMBER_TYPE ? 8 : sizeof(Atom);

			// now copy the default optional values
			OP* argcarg = argc_param;
			for (int i=0, n=info->optional_count; i < n; i++)
			{
				// first set the local[p+1] = defaultvalue
				int param = i + info->param_count - info->optional_count; // 0..N
				int loc = param+1;

				OP* defaultVal = InsConst(info->getDefaultValue(i));
				defaultVal = defIns(atomToNativeRep(loc, defaultVal));
				
				// then generate: if (argc > p) local[p+1] = arg[p+1]
				OP* cmp = binaryIns(LIR_le, argcarg, InsConst((int32)param));
				OP* br = branchIns(LIR_jt, cmp, 0); // will patch
				OP* arg;
				if (isDouble(loc))
				{
					arg = loadIns(MIR_fldop, offset, apArg);
					offset += 8;
				}
				else
				{
					arg = loadIns(MIR_ldop, offset, apArg);
#ifdef AVMPLUS_64BIT
					offset += 8;
#else
					offset += 4;
#endif
				}
				arg = defIns(arg);
				localSet(loc, defaultVal);

				br->target(Ins(MIR_bb));
			}
		}
		else
		{
			// !HAS_OPTIONAL
			AvmAssert(info->optional_count == 0);
		}

		// now set up the required args (we can ignore argc)
		// for (int i=0, n=param_count; i <= n; i++)
		//     framep[i] = argv[i];
		int offset = 0;
		for (int i=0, n=info->param_count-info->optional_count; i <= n; i++)
		{
			Traits* t = info->paramTraits(i);
			OP* arg; 
			if (t == NUMBER_TYPE)
			{
				arg = loadIns(MIR_fldop, offset, apArg);
				localSet(i, arg);
				offset += 8;
			}
			else
			{
				arg = loadIns(MIR_ldop, offset, apArg);
				localSet(i, arg);
#ifdef AVMPLUS_AMD64
				offset += 8;
#else
				offset += 4;
#endif
			}
		}

		if (info->flags & AbstractFunction::UNBOX_THIS)
		{
			localSet(0, atomToNativeRep(0, localGet(0)));
		}

		int firstLocal = 1+info->param_count;

		// capture remaining args
		if (info->flags & AbstractFunction::NEED_REST)
		{
			//framep[info->param_count+1] = createRest(env, argv, argc);

			// use csop so if rest value never used, we don't bother creating array
			OP* rest = callIns(MIR_cmop, FUNCTIONID(createRestHelper), 3, 
				env_param, argc_param, ap_param);

			localSet(firstLocal, rest);
			firstLocal++;
		}
		else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
		{
			//framep[info->param_count+1] = createArguments(env, argv, argc);

			// use csop so if arguments never used, we don't create it
			OP* arguments = callIns(MIR_cmop, FUNCTIONID(createArgumentsHelper), 3, 
				env_param, argc_param, ap_param);

			localSet(firstLocal, arguments);
			firstLocal++;
		}

		undefConst = InsConst(undefinedAtom);
		if (firstLocal < state->verifier->local_count)
		{
			// set remaining locals to undefined
			for (int i=firstLocal, n=state->verifier->local_count; i < n; i++)
			{
				if(!(state->value(i).traits == NULL)){ // expecting *
 					AvmAssertMsg(0,"(state->value(i).traits != NULL)");
 					return false; // fail verify
 				}
				localSet(i, undefConst);
			}
		}

		#ifdef DEBUGGER

		for (int i=state->verifier->scopeBase; i<state->verifier->scopeBase+state->verifier->max_scope; ++i)
		{
			localSet(i, undefConst);
		}

		callIns(MIR_cm, FUNCTIONID(debugenter), 7,
			env_param, argc_param, ap_param, // for sendEnter
			leaIns(0, localTraits), InsConst(state->verifier->local_count), // for clearing traits pointers
			leaIns(0, _callStackNode), 
			info->hasExceptions() ? leaIns(0, _save_eip) : InsConst(0)
			);

		#endif // DEBUGGER

		if (info->isFlagSet(AbstractFunction::HAS_EXCEPTIONS))
		{
			// _ef.beginTry(core);
			callIns(MIR_cm, FUNCTIONID(beginTry), 2,
				leaIns(0,_ef), InsConst((uintptr)core));

			// spill prior to jmp so that our stack is cleared of 
			// any transient locals.
			saveState();

			// force the locals to be clean for the setjmp call
			Ins(MIR_bb);
			
			// Exception* _ee = setjmp(_ef.jmpBuf);
			// ISSUE this needs to be a cdecl call
			OP* jmpbuf = leaIns(offsetof(ExceptionFrame, jmpbuf), _ef);
			OP* ee = callIns(MIR_cs, FUNCTIONID(lirsetjmp), 2,
				jmpbuf, InsConst(0));

#ifdef AVMPLUS_SPARC
			beginCatch_start = ee;
#endif

			// if (setjmp() == 0) goto start
			OP* cond = binaryIns(LIR_eq, ee, InsConst(0));
			OP* exBranch = branchIns(LIR_jt, cond, 0);

			// exception case
			exAtom = loadIns(MIR_ld, offsetof(Exception, atom), ee);
			// need to convert exception from atom to native rep, at top of 
			// catch handler.  can't do it here because it could be any type.

			// _ef.beginCatch()
			// ISSUE why do we have to redefine ef? it is NULL when exception happens
			OP* pc = loadIns(MIR_ld, 0, _save_eip);
			OP* handler = callIns(MIR_cm, FUNCTIONID(beginCatch), 5,
				InsConst((uintptr)core), leaIns(0,_ef), InsConst((uintptr)info), pc, ee);

#ifdef AVMPLUS_SPARC
			beginCatch_end = handler;
#endif

			// jump to catch handler
			Ins(MIR_jmpi, loadIns(MIR_ld, (int32)offsetof(ExceptionHandler, target), handler));

			// target of conditional
			exBranch->target(Ins(MIR_bb));
		}

		// If interrupts are enabled, generate an interrupt check.
		// This ensures at least one interrupt check per method.
		if (interruptable && core->config.interrupts)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			#ifdef AVMPLUS_64BIT
			OP* interrupted = loadIns(MIR_ld32, (uintptr)&core->interrupted, NULL);
			#else
			OP* interrupted = loadIns(MIR_ld, (uintptr)&core->interrupted, NULL);
			#endif
			OP* br = branchIns(LIR_jf, binaryIns(LIR_eq, interrupted, InsConst(0)), 0);
			patch(br, interrupt_label);
		}

        Ins(LIR_label);

		return true;
	}

	void CodegenLIR::emitCall(FrameState* state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result) {
        this->state = state;
        AvmAssert(false);
        (void) opcode;
        (void) method_id;
        (void) argc;
        (void) result;
    }

    void CodegenLIR::emitPrep() {
		// update bytecode ip if necessary
		if (state->insideTryBlock && lastPcSave != state->pc)
		{
			storeIns(InsConst(state->pc), 0, _save_eip);
			lastPcSave = state->pc;
		}
    }

	void CodegenLIR::emit(FrameState* state, AbcOpcode opcode, uintptr op1, uintptr op2, Traits* result) {
        this->state = state;
		emitPrep();

		int sp = state->sp();
		switch (opcode)
		{
			case OP_jump:
			{
                AvmAssert(false);
				// spill everything first
				sintptr targetpc = op1;

				saveState();
				
#ifdef DEBUGGER
				if(core->sampling() && targetpc < state->pc)
				{
					emitSampleCheck();
				}
#endif

				// relative branch
				OP* p = Ins(LIR_j, 0); // will be patched

				patch(p, targetpc);
				break;
			}

			case OP_lookupswitch:
			{
                AvmAssert(false);
				//int index = integer(*(sp--));
				//pc += readS24(index < readU16(pc+4) ? 
				//	(pc+6+3*index) :	// matched case
				//	(pc+1));			// default
				int count = int(1 + op2);
				sintptr targetpc = op1;

				AvmAssert(state->value(sp).traits == INT_TYPE);

				saveState();

				OP* input = localGet(sp);
				OP* cmp = binaryIns(LIR_lt, input, InsConst(count));
				OP* p = branchIns(LIR_jf, cmp, 0); // will be patched
				patch(p, targetpc);

				// now for non-default cases

                // fixme - compiles into a series of eq/branch checks.
				const byte* pc = abcStart + state->pc + 4;
                AvmCore::readU30(pc);
				for (int i=0; i < count; i++) {
					sintptr off = state->pc + AvmCore::readS24(pc+3*i);
                    OP *br = branchIns(LIR_jt, binaryIns(LIR_eq, input, InsConst(i)), 0);
                    patch(br, state->pc+off);
				}
				break;
			}

			case OP_setglobalslot:
			case OP_setslot:
			case OP_getslot:
			{
                AvmAssert(false);
				Traits* t;
				OP* ptr;
				sintptr ptr_index;
				
				if (opcode == OP_getslot || opcode == OP_setslot)
				{
					ptr_index = op2;
					t = state->value(ptr_index).traits;
					ptr = localGet(ptr_index);
					AvmAssert(state->value(ptr_index).notNull);
					AvmAssert(isPointer((int)ptr_index)); // obj
				}
				else
				{
					ScopeTypeChain* scopeTypes = info->declaringTraits->scope;
					if (scopeTypes->size == 0)
					{
						// no captured scopes, so scope 0 is a local scope
						ptr_index = state->verifier->scopeBase;
						t = state->value(ptr_index).traits;
						ptr = localGet(ptr_index);
						AvmAssert(state->value(ptr_index).notNull);
						AvmAssert(isPointer((int)ptr_index)); // obj
					}
					else
					{
						t = scopeTypes->scopes[0].traits;
						OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
						OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
						OP* scopeobj = loadIns(MIR_ld, offsetof(ScopeChain, scopes) + 0*sizeof(Atom), scope);
						ptr = atomToNativeRep(t, scopeobj);
					}				
				}

				int slot = int(op1);

				AvmAssert(t->linked);
				int offset = t->getOffsets()[slot];
				
				OP *unoffsetPtr = ptr;
				if (t->pool->isBuiltin && !t->final)
				{
					// t's slots aren't locked in, so we have to adjust for the actual runtime
					// traits->sizeofInstance.
					OP* vtable = loadIns(MIR_ldop, offsetof(ScriptObject,vtable), ptr);
					OP* traits = loadIns(MIR_ldop, offsetof(VTable,traits), vtable);
					offset -= (int)(t->sizeofInstance);
					OP* sizeofInstance = loadIns(MIR_ldop, offsetof(Traits, sizeofInstance), traits);
					ptr = binaryIns(MIR_addp, sizeofInstance, ptr);
				}

				if (opcode == OP_getslot) 
				{
					// get
					if (result == NUMBER_TYPE)
						localSet(op2, loadIns(MIR_fld, offset, ptr));
					else
					{
						#ifdef AVMPLUS_64BIT
						// Could be signed or unsigned 
						Traits* slotType = t->getSlotTraits(slot);
						if (slotType==INT_TYPE) //signed
							localSet(op2, loadIns(MIR_ld32, offset, ptr));
						else if (slotType==UINT_TYPE || slotType==BOOLEAN_TYPE) // unsigned
							localSet(op2, loadIns(MIR_ld32u, offset, ptr));
						else
							localSet(op2, loadIns(MIR_ld, offset, ptr));
						#else
						localSet(op2, loadIns(MIR_ld, offset, ptr));
						#endif
					}
				} 
				else
				{
					// set
					OP* value = localGet(sp);					

					#ifdef WRITE_BARRIERS
					// if storing to a pointer-typed slot, inline a WB
					Traits* slotType = t->getSlotTraits(slot);

					if (core->GetGC()->incremental &&
						(!slotType || !slotType->isMachineType || slotType == OBJECT_TYPE) &&
						!value->isconst())
					{
						MirOpcode op = MIR_cm;
						sintptr wbAddr = FUNCTIONID(wbrc);
						if(slotType == NULL || slotType == OBJECT_TYPE) {
							// use fast atom wb
							// TODO: inline pointer check
							op = MIR_cs;
							wbAddr = FUNCTIONID(wbatom);
						}
						callIns(op, wbAddr, 4, 
								InsConst((uintptr)core->GetGC()), 
								unoffsetPtr, 
								leaIns(offset, ptr),
								value);
					}
					else {
#ifdef AVMPLUS_AMD64
					if (slotType==INT_TYPE || slotType==UINT_TYPE || slotType==BOOLEAN_TYPE)
					{
						// Need to force a 32-bit store here, since we
						// are storing into a 32-bit slot
						storeIns(value, offset, ptr, true);
					}
					else
#endif
						storeIns(value, offset, ptr);
					}
					#endif //WRITE_BARRIERS
				}
				break;
			}

			case OP_returnvoid:
			case OP_returnvalue:
			{
                AvmAssert(false);
				// ISSUE if a method has multiple returns this causes some bloat

				// restore AvmCore::dxnsAddr if we set it to a stack addr in our frame
				if(info->setsDxns()) {
					storeIns(dxnsAddrSave, (uintptr)&core->dxnsAddr, 0);
				}

				#ifdef DEBUGGER
				callIns(MIR_cm, FUNCTIONID(debugexit), 2,
					env_param, leaIns(0, _callStackNode));
				#endif // DEBUGGER

				if (info->exceptions)
					callIns(MIR_cm, FUNCTIONID(endtry), 1, leaIns(0, _ef));

				if (opcode == OP_returnvalue)
				{
					// already coerced to required native type
					retIns(localGet(op1));
				}
				else
				{
					Traits* t = info->returnTraits();
					if (t && t != VOID_TYPE) {
						// implicitly coerce undefined to the return type
						OP* toplevel = loadToplevel(env_param);
						OP *retvalue = callIns(MIR_cmop, FUNCTIONID(coerce), 3,
							toplevel, undefConst, InsConst((uintptr)t));
						retIns(atomToNativeRep(t, retvalue));
					}
                    else {
                        retIns(undefConst);
                    }
				}
				break;
			}

			case OP_typeof:
			{
                AvmAssert(false);
				//sp[0] = typeof(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, FUNCTIONID(typeof), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_not:
			{
                AvmAssert(false);
				AvmAssert(state->value(op1).traits == BOOLEAN_TYPE);

				OP* value = localGet(op1);
				OP* i3 = binaryIns(MIR_xor, value, InsConst(1));
				localSet(op1, i3);
				break;
			}

			case OP_negate:
			{
                AvmAssert(false);
				OP* in = localGet(op1);
				OP* out = Ins(MIR_fneg, in);
				localSet(op1, out);
				break;
			}

			case OP_negate_i:
			{
                AvmAssert(false);
				//framep[op1] = -framep[op1]
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* value = localGet(op1);
				OP* i2 = Ins(MIR_neg, value);  // -number  
				localSet(op1, i2);
				break;
			}

			case OP_increment:
			case OP_decrement:
			case OP_inclocal:
			case OP_declocal:
			{
                AvmAssert(false);
				OP* in = localGet(op1);
				OP* inc = i2dIns(InsConst(op2)); // 1 or -1
				OP* out = binaryIns(MIR_fadd, in, inc);
				localSet(op1, out);
				break;
			}

			case OP_inclocal_i:
			case OP_declocal_i:
			case OP_increment_i:
			case OP_decrement_i:
			{
                AvmAssert(false);
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* in = localGet(op1);
				OP* out = binaryIns(MIR_add, in, InsConst(op2));
				localSet(op1, out);
				break;
			}

			case OP_bitnot:
			{
                AvmAssert(false);
				// *sp = core->intToAtom(~integer(*sp));
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* value = localGet(op1);
				OP* out = binaryIns(MIR_xor, value, InsConst(uintptr(~0)));
				localSet(op1, out);
				break;
			}

			case OP_modulo:
			{
                AvmAssert(false);
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = callIns(MIR_fcsop, FUNCTIONID(mod), 2,
					lhs, rhs);
				localSet(sp-1,	out);
				break;
			}

			case OP_add_d:
			case OP_subtract:
			case OP_subtract_i:
			case OP_add_i:
			case OP_multiply:
			case OP_multiply_i:
			case OP_divide:
			case OP_lshift:
			case OP_rshift:
			case OP_urshift:
			case OP_bitand:
			case OP_bitor:
			case OP_bitxor:
			{
                AvmAssert(false);
				LOpcode mircode;
				switch (opcode) {
					case OP_bitxor:     mircode = MIR_xor;  break;
					case OP_bitor:      mircode = MIR_or;   break;
					case OP_bitand:     mircode = MIR_and;  break;
					case OP_urshift:    mircode = MIR_ush;  break;
					case OP_rshift:     mircode = MIR_rsh;  break;
					case OP_lshift:     mircode = MIR_lsh;  break;
					case OP_divide:     mircode = MIR_fdiv; break;
					case OP_multiply:   mircode = MIR_fmul; break;
					case OP_multiply_i: mircode = MIR_imul; break;
					case OP_add_i:      mircode = MIR_add;  break;
					case OP_subtract_i: mircode = MIR_sub;  break;
					case OP_subtract:   mircode = MIR_fsub; break;
					case OP_add_d:      mircode = MIR_fadd; break;
					default: break;
				}
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = binaryIns(mircode, lhs, rhs);
				localSet(sp-1, out);
				break;
			}

			case OP_throw:
			{
                AvmAssert(false);
				// flush it all out
				OP* value = loadAtomRep(op1);
				saveState();
				//throwAtom(*sp--);
				callIns(MIR_cm, FUNCTIONID(throwatom), 2,
					InsConst((uintptr)core), value);
				break;
			}

			case OP_getsuper:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]]
				// stack out: value
				// sp[0] = env->getsuper(sp[0], multiname)
				int objDisp = sp;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);

				OP* i3 = callIns(MIR_cm, FUNCTIONID(getsuper), 3,
					env_param, obj, leaIns(0,multi));

				InsDealloc(multi);

				i3 = atomToNativeRep(result, i3);
				localSet(objDisp, i3);
				break;
			}

			case OP_setsuper:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]] value
				// stack out: nothing
				// core->setsuper(sp[-1], multiname, sp[0], env->vtable->base)
				int objDisp = sp-1;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);
				OP* value = loadAtomRep(sp);

				callIns(MIR_cm, FUNCTIONID(setsuper), 4,
					env_param, obj, leaIns(0, multi), value);

				InsDealloc(multi);
				break;
			}

			case OP_nextname:
			case OP_nextvalue:
			{
                AvmAssert(false);
				// sp[-1] = next[name|value](sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns(MIR_cm, (opcode == OP_nextname) ? FUNCTIONID(nextname) : FUNCTIONID(nextvalue), 3,
					env_param, obj, index);
				localSet(sp-1, atomToNativeRep(result, i1));
				break;
			}

			case OP_hasnext: 
			{
                AvmAssert(false);
				// sp[-1] = hasnext(sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns(MIR_cm, FUNCTIONID(hasnext), 3,
					env_param, obj, index);
				AvmAssert(result == INT_TYPE);
				localSet(sp-1, i1);
				break;
			}

			case OP_hasnext2: 
			{
                AvmAssert(false);
				OP* obj = InsAlloc(sizeof(Atom));
				OP* index = InsAlloc(sizeof(int));
				storeIns(loadAtomRep(op1), 0, obj);
				storeIns(localGet(op2), 0, index);
				OP* i1 = callIns(MIR_cm, FUNCTIONID(hasnext2), 3,
									 env_param, leaIns(0, obj), leaIns(0, index));
				localSet(op1, loadIns(MIR_ldop, 0, obj));
				localSet(op2, loadIns(MIR_ldop, 0, index));
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp+1, i1);
				InsDealloc(obj);
				InsDealloc(index);
				break;
			}
			
			case OP_newfunction:
			{
                AvmAssert(false);
				//sp[0] = core->newfunction(env, body, _scopeBase, scopeDepth);
 				AbstractFunction* func = pool->getMethodInfo((uint32)op1);
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* envArg = env_param;
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::newfunction), 4,
					envArg, InsConst((uintptr)func), outer, argv);

				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(op2, i3);
				break;
			}

			case OP_call:
			{
                AvmAssert(false);
				// stack in: method obj arg1..N
				// sp[-argc-1] = call(env, sp[-argc], argc, ...)
				int argc = int(op1);
				int funcDisp = sp - argc - 1;
				int dest = funcDisp;

				// convert args to Atom[] for the call
				OP* func = loadAtomRep(funcDisp);
				OP* ap = storeAtomArgs(loadAtomRep(funcDisp+1), argc, funcDisp+2);

				OP* toplevel = loadToplevel(env_param);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_call), 4, 
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_callproperty:
			case OP_callproplex:
			case OP_callpropvoid:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]] arg1..N
				// stack out: result

				int argc = int(op2);
				// obj = sp[-argc]
				//tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
				//	*(sp -= argc) = tempAtom;
				int argv = sp-argc+1;

				int baseDisp = sp-argc;
				OP* multi = initMultiname((Multiname*)op1, baseDisp);

				AvmAssert(state->value(baseDisp).notNull);

				// convert args to Atom[] for the call
				OP* base = loadAtomRep(baseDisp);
				OP* receiver = opcode == OP_callproplex ? InsConst(nullObjectAtom) : base;
				OP* ap = storeAtomArgs(receiver, argc, argv);

				OP* vtable = loadVTable(baseDisp);
				OP* toplevel = loadToplevel(env_param);
				OP* atomv = leaIns(0, ap);

				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::callproperty), 6,
					toplevel, base, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(baseDisp, atomToNativeRep(result, out));
				break;
			}

			case OP_constructprop:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]] arg1..N
				// stack out: result

				int argc = int(op2);
				// obj = sp[-argc]
				//tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
				//	*(sp -= argc) = tempAtom;
				int argv = sp-argc+1;

				int objDisp = sp-argc;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				// convert args to Atom[] for the call
				OP* obj = loadAtomRep(objDisp);
				OP* vtable = loadVTable(objDisp);
				OP* ap = storeAtomArgs(obj, argc, argv);

				OP* toplevel = loadToplevel(env_param);
				OP* atomv = leaIns(0, ap);
				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::constructprop), 5,
					toplevel, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_callsuper:
			case OP_callsupervoid:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]] arg1..N
				// stack out: result
				// null check must have already happened.
				//	tempAtom = callsuper(multiname, obj, sp-argc+1, argc, vtable->base);
				int argc = int(op2);
				int argv = sp - argc + 1;
				int objDisp = sp - argc;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				// convert args to Atom[] for the call
				OP* obj = loadAtomRep(objDisp);

				OP* ap = storeAtomArgs(obj, argc, argv);

				OP* atomv = leaIns(0, ap);
				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::callsuper), 4,
					env_param, leaIns(0, multi), InsConst(argc), atomv);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_construct:
 			{
                AvmAssert(false);
				// stack in: method arg1..N
				// sp[-argc] = construct(env, sp[-argc], argc, null, arg1..N)
 				int argc = int(op1);
 				int funcDisp = sp - argc;
 				int dest = funcDisp;

				OP* func = loadAtomRep(funcDisp);

				// convert args to Atom[] for the call
				OP* ap = storeAtomArgs(InsConst(nullObjectAtom), argc, funcDisp+1);

				OP* toplevel = loadToplevel(env_param);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_construct), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
 			}

			case OP_applytype:
			{
                AvmAssert(false);
				// stack in: method arg1..N
				// sp[-argc] = applytype(env, sp[-argc], argc, null, arg1..N)
				int argc = int(op1);
				int funcDisp = sp - argc;
				int dest = funcDisp;
				int arg0 = sp - argc + 1;

				OP* func = loadAtomRep(funcDisp);

				// convert args to Atom[] for the call
				OP* ap = storeAtomArgs(argc, arg0);

				OP* toplevel = loadToplevel(env_param);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_applytype), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_newobject:
			{
                AvmAssert(false);
 				// result = env->op_newobject(sp, argc)
 				int argc = int(op1);
 				int dest = sp - (2*argc-1);
				int arg0 = dest;

				// convert args to Atom for the call[]
				OP* ap = storeAtomArgs(2*argc, arg0);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::op_newobject), 3,
#ifdef AVMPLUS_64BIT
					env_param, leaIns(8*(2*argc-1), ap), InsConst(argc));
#else
					env_param, leaIns(4*(2*argc-1), ap), InsConst(argc));
#endif
				InsDealloc(ap);

				localSet(dest, ptrToNativeRep(result, i3));
				break;
			}

			case OP_newactivation:
			{
                AvmAssert(false);
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* activationVTable = callIns(MIR_cm, ENVADDR(MethodEnv::getActivation), 1, env_param);
				OP* activation = callIns(MIR_cm, COREADDR(AvmCore::newActivation), 3, 
										 InsConst((uintptr)core), activationVTable, InsConst(0));

				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

			case OP_newcatch:
			{
                AvmAssert(false);
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* activation = callIns(MIR_cm, ENVADDR(MethodEnv::newcatch), 2, 
										 env_param, InsConst((uintptr)result));

				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

 			case OP_newarray:
 			{
                AvmAssert(false);
				// sp[-argc+1] = core->arrayClass->newarray(sp-argc+1, argc)
 				int argc = int(op1);
 				int arg0 = sp - 1*argc+1;

				// convert array elements to Atom[]
				OP* ap = storeAtomArgs(argc, arg0);
				OP* toplevel = loadToplevel(env_param);
				OP* arrayClass = loadIns(MIR_ldop, offsetof(Toplevel,arrayClass), toplevel);
				OP* i3 = callIns(MIR_cm, SCRIPTADDR(ArrayClass::newarray), 3,
					arrayClass, leaIns(0,ap), InsConst(argc));
				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(arg0, i3);
				break;
 			}

			case OP_newclass:
			{
                AvmAssert(false);
				// sp[0] = core->newclass(env, cinit, scopeBase, scopeDepth, base)
				sintptr cinit = op1;
				int localindex = int(op2);
				int extraScopes = state->scopeDepth;

				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* base = localGet(localindex);

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::newclass), 5, 
					envArg, InsConst((sintptr)cinit), base, outer, argv);
				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(localindex, i3);
				break;
			}

			case OP_getdescendants:
			{
                AvmAssert(false);
				// stack in: obj [ns [name]]
				// stack out: value
				//sp[0] = core->getdescendants(sp[0], name);
				int objDisp = sp;
				Multiname* multiname = (Multiname*) op1;

				OP* out;
				OP* multi = initMultiname(multiname, objDisp);
				OP* obj = loadAtomRep(objDisp);
				AvmAssert(state->value(objDisp).notNull);

				out = callIns(MIR_cm, ENVADDR(MethodEnv::getdescendants), 3,
					env_param, obj, leaIns(0, multi));

				InsDealloc(multi);
				localSet(objDisp, atomToNativeRep(result, out));
				break;
			}

			case OP_checkfilter:
			{
                AvmAssert(false);
				// stack in: obj 
				// stack out: obj
				callIns(MIR_cm, ENVADDR(MethodEnv::checkfilter), 2,
					env_param, loadAtomRep(op1));
				break;
			}

			case OP_findpropstrict: 
			case OP_findproperty: 
			{
                AvmAssert(false);
				// stack in: [ns [name]]
				// stack out: obj
				// sp[1] = env->findproperty(scopeBase, scopedepth, name, strict)
				int dest = sp;
				OP* multi = initMultiname((Multiname*)op1, dest);
				dest++;
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv,vtable), env_param);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable,scope), vtable);

				OP* withBase;
				if (state->withBase == -1)
				{
					withBase = InsConst(0);
				}
				else
				{
					withBase = leaIns(state->withBase*sizeof(Atom), ap);
				}
	
				// 		return env->findproperty(outer, argv, extraScopes, name, strict);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::findproperty), 7, 
					envArg, outer, leaIns(0,ap), InsConst(extraScopes), leaIns(0, multi), 
					InsConst((int32)(opcode == OP_findpropstrict)),
					withBase);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_finddef: 
			{
                AvmAssert(false);
				// stack in: 
				// stack out: obj
				// framep[op2] = env->finddef(name)
				Multiname* multiname = (Multiname*) op1;
				sintptr dest = op2;
				OP* name = InsConst((uintptr)multiname->getName());
				OP* out;

				AvmAssert(multiname->isBinding());
				if (multiname->isNsset())
				{
					out = callIns(MIR_cmop, ENVADDR(MethodEnv::finddefNsset), 3,
						env_param,
						InsConst((uintptr)multiname->getNsset()),
						name);
				}
				else
				{
					out = callIns(MIR_cmop, ENVADDR(MethodEnv::finddefNs), 3,
						env_param,
						InsConst((uintptr)multiname->getNamespace()),
						name);
				}
				localSet(dest, ptrToNativeRep(result, out));
				break;
			}

			case OP_getproperty:
			{
                AvmAssert(false);
				// stack in: obj [ns] [name]
				// stack out: value
				// obj=sp[0]
				//sp[0] = env->getproperty(obj, multiname);

				Multiname* multiname = (Multiname*)op1;
				bool attr = multiname->isAttr();
				Traits* indexType = state->value(sp).traits;
				int objDisp = sp;

				bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->contains(core->publicNamespace);

				if (maybeIntegerIndex && indexType == INT_TYPE)
				{
					bool valIsAtom = true;
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					OP *value;
					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)) )
					{
						value = callIns(MIR_cm, (objType==ARRAY_TYPE ? 
												ARRAYADDR(ArrayObject::_getIntProperty) :
												VECTOROBJADDR(ObjectVectorObject::_getIntProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE)
					{
						if( result == INT_TYPE || result == UINT_TYPE)
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_getNativeIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_getIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_getIntProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )
						{
							value = callIns(MIR_fcm, VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_getIntProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertylate_i), 3,
							env_param, loadAtomRep(sp-1), index);
					}

					localSet(sp-1, valIsAtom?atomToNativeRep(result, value):value);
				}
				else if (maybeIntegerIndex && indexType == UINT_TYPE)
				{
					bool valIsAtom = true;

					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					OP *value;
					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						value = callIns(MIR_cm, (objType==ARRAY_TYPE ? 
												ARRAYADDR(ArrayObject::_getUintProperty) :
												VECTOROBJADDR(ObjectVectorObject::_getUintProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( result == INT_TYPE || result == UINT_TYPE )
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ?
													VECTORINTADDR(IntVectorObject::_getNativeUintProperty) :
													VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ?
													VECTORINTADDR(IntVectorObject::_getUintProperty) : 
													VECTORUINTADDR(UIntVectorObject::_getUintProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )//|| result == UINT_TYPE)
						{
							value = callIns(MIR_fcm, VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_getUintProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertylate_u), 3,
							env_param, loadAtomRep(sp-1), index);
					}

					localSet(sp-1, valIsAtom?atomToNativeRep(result, value):value);
				}
				else if (maybeIntegerIndex && indexType != STRING_TYPE)
				{
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);
					AvmAssert(state->value(objDisp).notNull);

					OP* obj = loadAtomRep(objDisp);

					// copy the compile-time namespace to the temp multiname
					OP* mSpace = InsConst((uintptr)multiname->ns);
					storeIns(mSpace, offsetof(Multiname, ns), _tempname);

					OP *multi = leaIns(0, _tempname);

					OP* value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertyHelper), 5,
									    env_param, obj, multi, loadVTable(objDisp), index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				else
				{
					OP* multi = initMultiname((Multiname*)op1, objDisp);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);
					OP* toplevel = loadToplevel(env_param);

					//return toplevel->getproperty(obj, name, toplevel->toVTable(obj));
					OP* value = callIns(MIR_cm, TOPLEVELADDR(Toplevel::getproperty), 4,
										toplevel, obj, leaIns(0, multi), vtable);

					InsDealloc(multi);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_initproperty:
			case OP_setproperty:
			{
                AvmAssert(false);
				// stack in: obj [ns] [name] value
				// stack out:
				// obj = sp[-1]
				//env->setproperty(obj, multiname, sp[0], toVTable(obj));
				//OP* value = loadAtomRep(sp);

				Multiname* multiname = (Multiname*)op1;
				bool attr = multiname->isAttr();
				Traits* indexType = state->value(sp-1).traits;
				Traits* valueType = state->value(sp).traits;
				int objDisp = sp-1;

				bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->contains(core->publicNamespace);

				if (maybeIntegerIndex && indexType == INT_TYPE)
				{
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, (objType==ARRAY_TYPE ? 
										ARRAYADDR(ArrayObject::_setIntProperty) :
										VECTOROBJADDR(ObjectVectorObject::_setIntProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeIntProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeIntProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_setIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_setIntProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setIntProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, ENVADDR(MethodEnv::setpropertylate_i), 4,
							env_param, loadAtomRep(objDisp), index, value);
					}
				}
				else if (maybeIntegerIndex && indexType == UINT_TYPE)
				{
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, (objType==ARRAY_TYPE ? 
										ARRAYADDR(ArrayObject::_setUintProperty) :
										VECTOROBJADDR(ObjectVectorObject::_setUintProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeUintProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeUintProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_setUintProperty) :
													VECTORUINTADDR(UIntVectorObject::_setUintProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setUintProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, ENVADDR(MethodEnv::setpropertylate_u), 4,
							env_param, loadAtomRep(objDisp), index, value);
					}
				}
				else if (maybeIntegerIndex)
				{
					OP* value = loadAtomRep(sp);
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);

					// copy the compile-time namespace to the temp multiname
					OP* mSpace = InsConst((uintptr)multiname->ns);
					storeIns(mSpace, offsetof(Multiname, ns), _tempname);

					OP *multi = leaIns(0, _tempname);

					sintptr func = opcode==OP_setproperty ? ENVADDR(MethodEnv::setpropertyHelper) :
														ENVADDR(MethodEnv::initpropertyHelper);
					callIns(MIR_cm, func, 6,
							env_param, obj, multi, value, vtable, index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				else
				{
					OP* value = loadAtomRep(sp);
					OP* multi = initMultiname((Multiname*)op1, objDisp);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);

					if (OP_setproperty)
					{
						OP* toplevel = loadToplevel(env_param);
						callIns(MIR_cm, TOPLEVELADDR(Toplevel::setproperty), 5,
										toplevel, obj, leaIns(0, multi), value, vtable);
					}
					else
					{
						callIns(MIR_cm, ENVADDR(MethodEnv::initproperty), 5,
							env_param, obj, leaIns(0, multi), value, vtable);
					}

					InsDealloc(multi);
				}
				break;
			}

			case OP_deleteproperty:
			{
                AvmAssert(false);
				// stack in: obj [ns] [name]
				// stack out: Boolean
				//sp[0] = delproperty(sp[0], multiname);
				int objDisp = sp;
				Multiname *multiname = (Multiname*)op1;
				if(!multiname->isRtname()) {
					OP* multi = initMultiname(multiname, objDisp, true);

					OP* obj = loadAtomRep(objDisp);
					
					OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::delproperty), 3,
						env_param, obj, leaIns(0, multi));

					InsDealloc(multi);

					localSet(objDisp, atomToNativeRep(result, i3));
				} else {
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);

					if( !multiname->isRtns() )
					{
						// copy the compile-time namespace to the temp multiname
						OP* mSpace = InsConst((uintptr)multiname->ns);
						storeIns(mSpace, offsetof(Multiname, ns), _tempname);
					}
					else
					{
						// intern the runtime namespace and copy to the temp multiname
						OP* nsAtom = loadAtomRep(objDisp--);
						OP* internNs = callIns(MIR_cm, ENVADDR(MethodEnv::internRtns), 2,
							env_param, nsAtom);

						storeIns(internNs, offsetof(Multiname,ns), _tempname);
					}

					AvmAssert(state->value(objDisp).notNull);
					OP* obj = loadAtomRep(objDisp);

					OP *multi = leaIns(0, _tempname);

					OP* value = callIns(MIR_cm, ENVADDR(MethodEnv::delpropertyHelper), 4,
									    env_param, obj, multi, index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_convert_s:
			{
                AvmAssert(false);
				localSet(op1, callIns(MIR_cm, COREADDR(AvmCore::string), 2,
					InsConst((uintptr)core), loadAtomRep(op1)));
				break;
			}

			case OP_esc_xelem: // ToXMLString will call EscapeElementValue
			{
                AvmAssert(false);
				//sp[0] = core->ToXMLString(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::ToXMLString), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_esc_xattr:
			{
                AvmAssert(false);
				//sp[0] = core->EscapeAttributeValue(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::EscapeAttributeValue), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_astype:
			{
                AvmAssert(false);
				// sp[0] = core->astype(sp[0], traits)
				OP* obj = loadAtomRep(op2);
				OP* i1 = callIns(MIR_cmop, ENVADDR(MethodEnv::astype), 3,
					env_param,
					obj,
					InsConst(op1)); // traits

				i1 = atomToNativeRep(result, i1);
				localSet(op2, i1);
				break;
			}

			case OP_astypelate:
			{
                AvmAssert(false);
				//sp[-1] = astype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* itraits = callIns(MIR_cmop, ENVADDR(MethodEnv::toClassITraits), 2,
					env_param, type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(MIR_cmop, ENVADDR(MethodEnv::astype), 3,
					envarg, obj, itraits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}


			case OP_add:
			{
                AvmAssert(false);
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(env_param);
				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::add2), 3,
					toplevel, lhs, rhs);
				localSet(sp-1, atomToNativeRep(result, out));
				break;
			}

			case OP_concat:
			{
                AvmAssert(false);
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = callIns(MIR_cmop, COREADDR(AvmCore::concatStrings), 3,
					InsConst((uintptr)core), lhs, rhs);
				localSet(sp-1,	out);
				break;
			}

			case OP_equals:
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_eq, cmpEq(COREADDR(AvmCore::eq), sp-1, sp)));
				break;
			}

			case OP_strictequals:
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_eq, cmpEq(COREADDR(AvmCore::stricteq), sp-1, sp)));
				break;
			}

			case OP_lessthan:
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_lt, cmpLt(sp-1, sp)));
				break;
			}

			case OP_lessequals:
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_le, cmpLe(sp-1, sp)));
				break;
			}

			case OP_greaterthan:
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_lt, cmpLt(sp, sp-1)));
				break;
			}

			case OP_greaterequals: 
			{
                AvmAssert(false);
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_le, cmpLe(sp, sp-1)));
				break;
			}

			case OP_instanceof:
			{
                AvmAssert(false);
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(env_param);
				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::instanceof), 3,
					toplevel, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1,	out);
				break;
			}

			case OP_in:
			{
                AvmAssert(false);
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* out = callIns(MIR_cm, ENVADDR(MethodEnv::in), 3,
					env_param, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1, out);
				break;
			}

			case OP_istype:
			{
                AvmAssert(false);
				// expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				//sp[0] = istype(sp[0], itraits);
				OP* obj = loadAtomRep(op2);
				OP* itraits = InsConst(op1);
				OP* out = callIns(MIR_cm, COREADDR(AvmCore::istypeAtom), 3,
					InsConst((uintptr)core), obj, itraits);
				out = atomToNativeRep(result, out);
				localSet(op2, out);
				break;
			}

			case OP_istypelate:
			{
                AvmAssert(false);
				//sp[-1] = istype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* traits = callIns(MIR_cmop, ENVADDR(MethodEnv::toClassITraits), 2,
					env_param, type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(MIR_cm, COREADDR(AvmCore::istypeAtom), 3,
					InsConst((uintptr)core), obj, traits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}

			case OP_dxns:
			{
                AvmAssert(false);
				OP* uri = InsConst(op1); // uri
				OP* ns = callIns(MIR_cm, 
					COREADDR(AvmCore::newPublicNamespace), 
					2, 
					InsConst((uintptr)core), 
					uri);
				storeIns(ns, 0, dxns);
				break;
			}

			case OP_dxnslate:
			{
                AvmAssert(false);
				OP* atom = loadAtomRep(op1);				
				OP* uri = callIns(MIR_cm, COREADDR(AvmCore::intern), 2,
					InsConst((uintptr)core), atom);
				OP* ns = callIns(MIR_cm, 
					COREADDR(AvmCore::newPublicNamespace), 
					2, 
					InsConst((uintptr)core), 
					uri);
				storeIns(ns, 0, dxns);
				break;
			}

			/*
			 * debugger instructions 
			 */
			case OP_debugfile:
			{
                AvmAssert(false);
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(MIR_cm, DEBUGGERADDR(Debugger::debugFile), 2,
						debugger,
						InsConst(op1));
			#endif // DEBUGGER
			#ifdef VTUNE
				Ins(MIR_file, op1);
			#endif /* VTUNE */
				break;
		    }

			case OP_debugline:
			{
                AvmAssert(false);
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(MIR_cm, DEBUGGERADDR(Debugger::debugLine), 2,
						debugger,
						InsConst(op1));
			#endif // DEBUGGER
			#ifdef VTUNE
				Ins(MIR_line, op1);
				hasDebugInfo = true;
			#endif /* VTUNE */
				break;
			}
			#endif // DEBUGGER

			default:
			{
				AvmAssert(false); // unsupported
			}
		}
    }

	void CodegenLIR::emitIf(FrameState* state, AbcOpcode opcode, sintptr target, int lhs, int rhs) {
        this->state = state;
        AvmAssert(false);
        (void) opcode;
        (void) target;
        (void) lhs;
        (void) rhs;
    }

    void CodegenLIR::emitSwap(FrameState* state, int i, int j) {
        this->state = state;
		this->state = state;
		OP* a = localGet(i);
		OP* b = localGet(j);
		localSet(i, b);
		localSet(j, a);
    }

	void CodegenLIR::emitCopy(FrameState* state, int src, int dest) {
        this->state = state;
		localSet(dest, localGet(src));
    }

	void CodegenLIR::emitGetscope(FrameState* state, int scope, int dest) {
        this->state = state;
        AvmAssert(false);
        (void) scope;
        (void) dest;
    }

	void CodegenLIR::emitKill(FrameState* state, int i) {
        this->state = state;
        localSet(i, undefConst);
    }

	void CodegenLIR::emitBlockStart(FrameState* state) {
        this->state = state;
		// our new extended BB now starts here, this means that any branch targets
		// should hit the next instruction our bb start instruction
		OP* bb = Ins(MIR_bb); // mark start of block

		// get a label for our block start and tie it to this location
		label(state->verifier->getFrameState(state->pc)->label, bb);

		// If this is a backwards branch, generate an interrupt check.
		// current verifier state, includes tack pointer.
		if (interruptable && core->config.interrupts && state->targetOfBackwardsBranch)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			#ifdef AVMPLUS_AMD64
			OP* interrupted = loadIns(MIR_ld, (uintptr)&core->interrupted, NULL);
			#else
			OP* interrupted = loadIns(MIR_ld, (uintptr)&core->interrupted, NULL);
			#endif
			OP* br = branchIns(LIR_jf, binaryIns(LIR_eq, interrupted, InsConst(0)), 0);
			patch(br, interrupt_label);
		}
    }

	void CodegenLIR::emitBlockEnd(FrameState* state) {
        this->state = state;
        saveState();
    }

	void CodegenLIR::emitIntConst(FrameState* state, int index, uintptr c) {
        this->state = state;
		localSet(index, InsConst(c));
    }

	void CodegenLIR::emitDoubleConst(FrameState* state, int index, double* pd) {
        this->state = state;
		localSet(index, loadIns(MIR_fldop, (uintptr)pd, NULL));
    }

	void CodegenLIR::emitCoerce(FrameState* state, int index, Traits* type) {
        this->state = state;
        AvmAssert(false);
        (void) index;
        (void) type;
    }

	void CodegenLIR::emitCheckNull(FrameState* state, int index) {
        this->state = state;
        AvmAssert(false);
        (void) index;
    }

	void CodegenLIR::emitSetContext(FrameState* state, AbstractFunction* f) {
        this->state = state;
        AvmAssert(false);
        (void) f;
    }

	void CodegenLIR::emitSetDxns(FrameState* state) {
        this->state = state;
        AvmAssert(false);
    }

	void CodegenLIR::merge(const Value& current, Value& target) {
        AvmAssert(false);
        (void) current;
        (void) target;
    }

	void CodegenLIR::localSet(uintptr i, OP* o) {
        lirout->insStorei(o, locals, i*8);
    }

    LIns *CodegenLIR::InsAlloc(int32_t size) {
        return lirout->insAlloc(size);
    }

    LIns *CodegenLIR::loadIns(LOpcode op, int32_t disp, LIns *base) {
        return lirout->insLoad(op, base, disp);
    }

    LIns *CodegenLIR::Ins(LOpcode op) {
        return lirout->ins0(op);
    }

    LIns *CodegenLIR::Ins(LOpcode op, LIns *a) {
        return lirout->ins1(op, a);
    }

    LIns *CodegenLIR::Ins(LOpcode op, LIns *lhs, LIns *rhs) {
        return lirout->ins2(op, lhs, rhs);
    }

    LIns *CodegenLIR::storeIns(LIns *val, int32_t disp, LIns *base) {
        return lirout->insStorei(val, base, disp);
    }

    LIns *CodegenLIR::InsConst(int32_t c) {
        return lirout->insImm(c);
    }

    LIns *CodegenLIR::defIns(LIns *i) {
        return i;
    }

    LIns *CodegenLIR::atomToNativeRep(int loc, LIns *atom) {
		return atomToNativeRep(state->value(loc).traits, atom);
    }

    LIns *CodegenLIR::atomToNativeRep(Traits *t, LIns *atom) 
    {
		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
			return atom;
		}
		else if (t == NUMBER_TYPE)
		{
			if (atom->isconst()) {
				Atom a = atom->constval();
				if (AvmCore::isDouble(a)) {
					return loadIns(MIR_fldop, a&~7, 0);
				} else {
					AvmAssert(AvmCore::isInteger(a));
					return i2dIns(InsConst(a>>3));
				}
			} else {
				return callIns(MIR_fcsop, FUNCTIONID(number_d), 1, atom);
			}
		}
		else if (t == INT_TYPE)
		{
			if (atom->isconst())
				return InsConst(AVMCORE_integer_i(atom->constval()));
			else
				return callIns(MIR_csop, FUNCTIONID(avmcore_integer_i), 1, atom);
		}
		else if (t == UINT_TYPE)
		{
			if (atom->isconst())
				return InsConst(AvmCore::integer_u(atom->constval()));
			else
				return callIns(MIR_csop, FUNCTIONID(integer_u), 1, atom);
		}
		else if (t == BOOLEAN_TYPE)
		{
			if (atom->isconst())
				return InsConst(urshift(atom->constval(),3));
			else
				return binaryIns(MIR_ush, atom, InsConst(3));
		}
		else
		{
			// pointer type
			if (atom->isconst())
				return InsConst(atom->constval() & ~7);
			else
				return binaryIns(MIR_and, atom, InsConst(uintptr(~7)));
		}
    }

    OP* CodegenLIR::i2dIns(OP* v)
	{
		return Ins(MIR_i2d, v);
	}

    OP* CodegenLIR::callIns(MirOpcode callop, uintptr_t funcid, int argc, ...)
    {
        (void) callop;
        AvmAssert(argc < 10);
        AvmAssert(argc == (int)helpers::functions[funcid].count_args());
        AvmAssert(
            (callop == MIR_fcsop||callop==MIR_fcmop||callop==MIR_cmop||callop==MIR_csop) && helpers::functions[funcid].cse)
            || (callop == MIR_fcs||callop==MIR_fcm||callop==MIR_cm||callop==MIR_cs) && !helpers::functions[funcid].cse)
        );

        LInsp args[10];
        va_list ap;
        va_start(ap, argc);
        for (int i=0; i < argc; i++)
            args[argc-i-1] = va_arg(ap, LIns*);
        va_end(ap);

        return lirout->insCall(funcid, args);
    }

    /* patch the location 'where' with the value of the label */
	void CodegenLIR::patchPtr(OP** targetp, uintptr_t pc)
	{
        AvmAssert(false);
		patchPtr(targetp, state->verifier->getFrameState(pc)->label);
	}

	void CodegenLIR::patchPtr(OP** targetp, CodegenLabel& l)
	{
        AvmAssert(false);
		// either patch it now if we know the location of label or add it to the chain
		if (l.bb)
		{
			*targetp = l.bb;
		}
		else
		{
			*targetp = (OP*)l.nextPatchIns;
			l.nextPatchIns = targetp;
		}
	}

    void CodegenLIR::patch(LIns *j, uintptr_t pc) {
        patch(j, state->verifier->getFrameState(pc)->label);
    }

    void CodegenLIR::patch(LIns *j, CodegenLabel &l) {
        if (l.bb) {
            j->target(l.bb);
        } else {
            AvmAssert(false); // need to queue to happen later
        }
    }

    void CodegenLIR::label(CodegenLabel &label, LIns *bb) {
        (void) label;
        (void) bb;
    }

    LIns *CodegenLIR::leaIns(int32_t d, LIns *base) {
        AvmAssert(base->isop(LIR_alloc));
        return lirout->ins2i(MIR_addp, base, d);
    }

    LIns *CodegenLIR::binaryIns(LOpcode op, LIns *a, LIns *b) {
        return lirout->ins2(op, a, b);
    }

    bool CodegenLIR::isPointer(int i) {
		return !state->value(i).traits->isMachineType;
	}

    bool CodegenLIR::isDouble(int i) {
		return state->value(i).traits == NUMBER_TYPE;
	}

    LIns *CodegenLIR::localGet(int i) {
        return lirout->insLoadi(locals, i*8);
    }

    LIns *CodegenLIR::localGetq(int i) {
        return lirout->insLoad(LIR_ldq, locals, i*8);
    }

    void CodegenLIR::saveState() {
        AvmAssert(false);
    }

    LIns *CodegenLIR::branchIns(LOpcode op, LIns *cond, LIns *target) {
        return lirout->insBranch(op, cond, target);
    }

    LIns *CodegenLIR::emitSampleCheck() {
        AvmAssert(false);
        return 0;
    }

    LIns *CodegenMIR::retIns(LIns *) {
        AvmAssert(false);
        return 0;
    }

    LIns* CodegenMIR::loadToplevel(OP* env) {
		OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env);
		return loadIns(MIR_ldop, offsetof(VTable, toplevel), vtable);
	}

    LIns *CodegenLIR::loadAtomRep(int i) {
		Value& v = state->value(i);
		Traits* t = v.traits;
		OP* native = localGet(i);

		if (!t || t == OBJECT_TYPE || t == VOID_TYPE) {
			return native;
		}
		
		// short circuit immediates
		if (native->isconst())
		{
			if (t == INT_TYPE)
			{
				Atom a = core->intToAtom(int(native->constval()));
				if(AvmCore::isInteger(a))
					return InsConst(a);
			}

			if (t == UINT_TYPE)
			{
				Atom a = core->uintToAtom(uint32(native->constval()));
				if(AvmCore::isInteger(a))
					return InsConst(a);
			}

			if (t == BOOLEAN_TYPE)
			{
				return InsConst(native->imm ? trueAtom : falseAtom);
			}

			if (!t->isMachineType && native->isconstval(0))
			{
				return InsConst(nullObjectAtom);
			}
		}

		if (t == NUMBER_TYPE)
		{
			sintptr funcaddr = FUNCTIONID(doubleToAtom);
#ifdef AVMPLUS_IA32
			if (core->config.sse2)
				funcaddr = FUNCTIONID(doubleToAtom_sse2);
#endif
			return callIns(MIR_cmop, funcaddr, 2, InsConst((uintptr)core), native);
		}
		if (t == INT_TYPE)
		{
			return callIns(MIR_cmop, FUNCTIONID(intToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == UINT_TYPE)
		{
			return callIns(MIR_cmop, FUNCTIONID(uintToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == BOOLEAN_TYPE)
		{
			OP* i1 = binaryIns(MIR_lsh, native, InsConst(3));
			return binaryIns(MIR_or, i1, InsConst(kBooleanType));
		}

		// possibly null pointers
		if (t == STRING_TYPE)
		{
			return binaryIns(MIR_or, native, InsConst(kStringType));
		}
		if (t == NAMESPACE_TYPE)
		{
			return binaryIns(MIR_or, native, InsConst(kNamespaceType));
		}

		return binaryIns(MIR_or, native, InsConst(kObjectType));
    }

    LIns* CodegenLIR::initMultiname(Multiname* multiname, int& csp, bool isDelete /*=false*/)
	{
		OP* _tempname = InsAlloc(sizeof(Multiname));

		// copy the flags
		OP* mFlag = InsConst(multiname->ctFlags());
		storeIns(mFlag, offsetof(Multiname,flags), _tempname);

		OP* nameAtom = NULL;
		
		if (multiname->isRtname())
		{
			nameAtom = loadAtomRep(csp--);			
		}
		else
		{
			// copy the compile-time name to the temp name
			OP* mName = InsConst((uintptr)multiname->name);
			storeIns(mName, offsetof(Multiname,name), _tempname);
		}

		if (multiname->isRtns())
		{
			// intern the runtime namespace and copy to the temp multiname
			OP* nsAtom = loadAtomRep(csp--);
			OP* internNs = callIns(MIR_cm, FUNCTIONID(intern_ns), 2,
				env_param, nsAtom);

			storeIns(internNs, offsetof(Multiname,ns), _tempname);
		}
		else
		{
			// copy the compile-time namespace to the temp multiname
			OP* mSpace = InsConst((uintptr)multiname->ns);
			storeIns(mSpace, offsetof(Multiname, ns), _tempname);
		}

		// Call initMultinameLate as the last step, since if a runtime
		// namespace is present, initMultinameLate may clobber it if a
		// QName is provided as index.
		if (nameAtom)
		{
			if (isDelete)
			{
				callIns(MIR_cm, FUNCTIONID(initname_late_del), 3,
						ldargIns(_env),
						leaIns(0, _tempname),
						nameAtom);
			}
			else
			{
				callIns(MIR_cm, FUNCTIONID(initname_late), 3,
						InsConst((uintptr)core),
						leaIns(0, _tempname),
						nameAtom);
			}				
		}

		return _tempname;
	}

    void CodegenLIR::InsDealloc(LIns* a) {
        AvmAssert(a->isop(LIR_alloc));
        // make sure it's live until here.
    }

	OP* CodegenLIR::storeAtomArgs(int count, int index)
	{
		OP* ap = InsAlloc(sizeof(Atom)*count);
		for (int i=0; i < count; i++)
		{
			OP* v = loadAtomRep(index++);
			storeIns(v, sizeof(Atom)*i, ap);
		}
		return ap;
	}

	OP* CodegenLIR::storeAtomArgs(OP* receiver, int count, int index)
	{
		OP* ap = InsAlloc(sizeof(Atom)*(count+1));
		storeIns(receiver, 0, ap);
		for (int i=1; i <= count; i++)
		{
			OP* v = loadAtomRep(index++);
			storeIns(v, sizeof(Atom)*i, ap);
		}
		return ap;
	}

}

namespace nanojit
{
    int StackFilter::getTop(LIns*) {
        return 0;
    }

    void Assembler::asm_bailout(LIns*, Register) {
    }

    void Assembler::initGuardRecord(LIns*, GuardRecord*) {
    }

    void LirNameMap::formatGuard(LIns*, char*) {
    }
}
