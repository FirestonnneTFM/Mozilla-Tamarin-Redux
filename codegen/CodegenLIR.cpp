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

        int FASTCALL avmcore_integer_i(Atom a) {
            return AVMCORE_integer_i(a);
        }

        void FASTCALL debugenter(MethodEnv *env, int argc, uint32_t *ap, Traits** ft,
            int local_count, CallStackNode *csn, sintptr *eip) {
		    env->debugEnter(argc, ap, ft, local_count, csn, 0, eip);
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
        MIR_i2d = LIR_i2f,
        MIR_and = LIR_and,
        MIR_addp = LIR_add,
        MIR_bb = LIR_label,
        MIR_ldop = LIR_ldc,
        MIR_jmpi = LIR_ji,
        MIR_ld = LIR_ld,
        MIR_ush = LIR_ush;

    PageMgr::PageMgr() : frago(0)
    {}

	CodegenLIR::CodegenLIR(MethodInfo* info)
		: gc(info->pool->core->gc), info(info), overflow(true)
    {
        PoolObject *pool = info->pool;
        core = pool->core;
        if (!pool->codePages) {
            pool->codePages = new (gc) PageMgr();
            pool->codePages->frago = new (gc) Fragmento(core, 24/*16mb*/);
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
        lirout = new (gc) VerboseWriter(gc, lirout, lirbuf->names);
		
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
			//OP* invocationCount = loadIns(MIR_ldop64, offsetof(MethodEnv, invocationCount), ldargsIns(_env));
			//Ins(MIR_inc64, invocationCount);
			//storeIns64(invocationCount, offsetof(MethodEnv, invocationCount), ldargsIns(_env));
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
				OP* br = lirout->insBranch(LIR_jt, cmp, 0); // will patch
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
			OP* exBranch = lirout->insBranch(LIR_jt, cond, 0);

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
			OP* br = lirout->insBranch(LIR_jf, binaryIns(LIR_eq, interrupted, InsConst(0)), 0);
			patch(br, interrupt_label);
		}

		// this is not fatal but its good to know if our prologue estimation code is off.
		InsAlloc(0);

		return true;

	}

	void CodegenLIR::emitCall(FrameState* state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result) {
        this->state = state;
        (void) opcode;
        (void) method_id;
        (void) argc;
        (void) result;
    }

	void CodegenLIR::emit(FrameState* state, AbcOpcode opcode, uintptr op1, uintptr op2, Traits* result) {
        this->state = state;
        (void) opcode;
        (void) op1;
        (void) op2;
        (void) result;
    }

	void CodegenLIR::emitIf(FrameState* state, AbcOpcode opcode, sintptr target, int lhs, int rhs) {
        this->state = state;
        (void) opcode;
        (void) target;
        (void) lhs;
        (void) rhs;
    }

    void CodegenLIR::emitSwap(FrameState* state, int i, int j) {
        this->state = state;
        (void) i;
        (void) j;
    }

	void CodegenLIR::emitCopy(FrameState* state, int src, int dest) {
        this->state = state;
        (void) src;
        (void) dest;
    }

	void CodegenLIR::emitGetscope(FrameState* state, int scope, int dest) {
        this->state = state;
        (void) scope;
        (void) dest;
    }

	void CodegenLIR::emitKill(FrameState* state, int i) {
        this->state = state;
        (void) i;
    }

	void CodegenLIR::emitBlockStart(FrameState* state) {
        this->state = state;
    }

	void CodegenLIR::emitBlockEnd(FrameState* state) {
        this->state = state;
    }

	void CodegenLIR::emitIntConst(FrameState* state, int index, uintptr c) {
        this->state = state;
        (void) index;
        (void) c;
    }

	void CodegenLIR::emitDoubleConst(FrameState* state, int index, double* pd) {
        this->state = state;
        (void) index;
        (void) pd;
    }

	void CodegenLIR::emitCoerce(FrameState* state, int index, Traits* type) {
        this->state = state;
        (void) index;
        (void) type;
    }

	void CodegenLIR::emitCheckNull(FrameState* state, int index) {
        this->state = state;
        (void) index;
    }

	void CodegenLIR::emitSetContext(FrameState* state, AbstractFunction* f) {
        this->state = state;
        (void) f;
    }

	void CodegenLIR::emitSetDxns(FrameState* state) {
        this->state = state;
    }

	void CodegenLIR::merge(const Value& current, Value& target) {
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

    void CodegenLIR::patch(LIns *j, CodegenLabel &l) {
        if (l.bb) {
            j->target(l.bb);
        } else {
            AvmAssert(false); // need to queue to happen later
        }
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
