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

#ifdef DARWIN
#include <Carbon/Carbon.h>
#endif

#if defined(WIN32) && defined(AVMPLUS_ARM)
#include <cmnintrin.h>
#endif

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

#ifdef AVMPLUS_ARM
#ifdef _MSC_VER
#define RETURN_METHOD_PTR(_class, _method) \
return *((int*)&_method);
#else
#define RETURN_METHOD_PTR(_class, _method) \
union { \
    int (_class::*bar)(); \
    int foo[2]; \
}; \
bar = _method; \
return foo[1];
#endif

#elif defined AVMPLUS_MAC
#if !TARGET_RT_MAC_MACHO
// CodeWarrior makes us jump through some hoops
// to dereference pointer->method...
// Convert pointer->method to integer for Carbon.
#define RETURN_METHOD_PTR(_class, _method) \
int foo; \
asm("lwz %0,0(r5)" : "=r" (foo)); \
return foo;
#else
#define RETURN_METHOD_PTR(_class, _method) \
union { \
    int (_class::*bar)(); \
    sintptr foo; \
}; \
bar = _method; \
return foo;
#endif

#else
#define RETURN_METHOD_PTR(_class, _method) \
return *((sintptr*)&_method);
#endif

// VOID variant
#ifdef AVMPLUS_ARM
#ifdef _MSC_VER
#define RETURN_VOID_METHOD_PTR(_class, _method) \
return *((int*)&_method);
#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
union { \
    void (_class::*bar)(); \
    int foo[2]; \
}; \
bar = _method; \
return foo[1];
#endif

#elif defined AVMPLUS_MAC
#if !TARGET_RT_MAC_MACHO
// CodeWarrior makes us jump through some hoops
// to dereference pointer->method...
// Convert pointer->method to integer for Carbon.
#define RETURN_VOID_METHOD_PTR(_class, _method) \
int foo; \
asm("lwz %0,0(r5)" : "=r" (foo)); \
return foo;
#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
union { \
    void (_class::*bar)(); \
    sintptr foo; \
}; \
bar = _method; \
return foo;
#endif

#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
return *((sintptr*)&_method);
#endif

#ifdef AVMPLUS_SPARC
extern  "C"
{
	void sync_instruction_memory(caddr_t v, u_int len);
}
#endif

#ifdef PERFM
#include "../vprof/vprof.h"
#endif /* PERFM */

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
	#ifdef VTUNE
		extern void VTune_RegisterMethod(MethodInfo* info, CodegenLIR *mir, AvmCore* core); 
	#endif  // VTUNE

		#define PROFADDR(f) profAddr((void (DynamicProfiler::*)())(&f))
		#define COREADDR(f) coreAddr((int (AvmCore::*)())(&f))
		#define GCADDR(f) gcAddr((int (MMgc::GC::*)())(&f))
		#define ENVADDR(f) envAddr((int (MethodEnv::*)())(&f))
		#define TOPLEVELADDR(f) toplevelAddr((int (Toplevel::*)())(&f))
		#define CALLSTACKADDR(f) callStackAddr((int (CallStackNode::*)())(&f))	
		#define SCRIPTADDR(f) scriptAddr((int (ScriptObject::*)())(&f))
		#define ARRAYADDR(f) arrayAddr((int (ArrayObject::*)())(&f))
		#define VECTORINTADDR(f) vectorIntAddr((int (IntVectorObject::*)())(&f))
		#define VECTORUINTADDR(f) vectorUIntAddr((int (UIntVectorObject::*)())(&f))
		#define VECTORDOUBLEADDR(f) vectorDoubleAddr((int (DoubleVectorObject::*)())(&f))
		#define VECTOROBJADDR(f) vectorObjAddr((int (ObjectVectorObject::*)())(&f))
		#define EFADDR(f)   efAddr((int (ExceptionFrame::*)())(&f))
		#define DEBUGGERADDR(f)   debuggerAddr((int (Debugger::*)())(&f))
		#define CLASSCLOSUREADDR(f)   classClosureAddr((int (ClassClosure::*)())(&f))

	#ifndef AVMPLUS_MAC
		#define FUNCADDR(addr) (uintptr)addr
	#else
		#if TARGET_RT_MAC_MACHO
			#define FUNCADDR(addr) (uintptr)addr
		#else
			#define FUNCADDR(addr) (*((uintptr*)addr))	
		#endif
	#endif

		sintptr coreAddr( int (AvmCore::*f)() )
		{
			RETURN_METHOD_PTR(AvmCore, f);
		}

		sintptr  gcAddr( int (MMgc::GC::*f)() )
		{
			RETURN_METHOD_PTR(MMgc::GC, f);
		}
		
		sintptr  envAddr( int (MethodEnv::*f)() )
		{
			RETURN_METHOD_PTR(MethodEnv, f);
		}

		sintptr  toplevelAddr( int (Toplevel::*f)() )
		{
			RETURN_METHOD_PTR(Toplevel, f);
		}

	#ifdef DEBUGGER
		sintptr  callStackAddr( int (CallStackNode::*f)() )
		{
			RETURN_METHOD_PTR(CallStackNode, f);
		}
		
		sintptr  debuggerAddr( int (Debugger::*f)() )
		{
			RETURN_METHOD_PTR(Debugger, f);
		}		
	#endif /* DEBUGGER */

		sintptr scriptAddr(int (ScriptObject::*f)())
		{
			RETURN_METHOD_PTR(ScriptObject, f);
		}

		sintptr  arrayAddr(int (ArrayObject::*f)())
		{
			RETURN_METHOD_PTR(ArrayObject, f);
		}

		sintptr vectorIntAddr(int (IntVectorObject::*f)())
		{
			RETURN_METHOD_PTR(IntVectorObject, f);
		}

		sintptr vectorUIntAddr(int (UIntVectorObject::*f)())
		{
			RETURN_METHOD_PTR(UIntVectorObject, f);
		}

		sintptr vectorDoubleAddr(int (DoubleVectorObject::*f)())
		{
			RETURN_METHOD_PTR(DoubleVectorObject, f);
		}

		sintptr vectorObjAddr(int (ObjectVectorObject::*f)())
		{
			RETURN_METHOD_PTR(ObjectVectorObject, f);
		}
		sintptr efAddr( int (ExceptionFrame::*f)() )
		{
			RETURN_METHOD_PTR(ExceptionFrame, f);
		}
		sintptr classClosureAddr(int (ClassClosure::*f)())
		{
			RETURN_METHOD_PTR(ClassClosure, f);
		}

	using namespace MMgc;
	using namespace nanojit;

	#ifdef AVMPLUS_MIR

    enum IndirectFunctionId {
        CALL_INDIRECT, FCALL_INDIRECT, CALL_IMT, FCALL_IMT
    };

	#if defined(_MSC_VER) && !defined(AVMPLUS_ARM)
	#define SETJMP ((uintptr)_setjmp3)
	#else
		#ifdef AVMPLUS_MAC_CARBON
			#define SETJMP setjmpAddress
		#else
			#define SETJMP ((uintptr)setjmp)
		#endif
	#endif /* _MSC_VER */

#define INTERP_FOPCODE_LIST_BEGIN static const CallInfo k_functions[] = {
#define INTERP_FOPCODE_LIST_END };

#ifdef NJ_VERBOSE
    #define INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,cse,fold,abi,ret,args,name) \
        { f, sig, cse, fold, abi, #name },
#else
    #define INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,cse,fold,abi,ret,args,name) \
        { f, sig, cse, fold, abi },
#endif

    #include "../core/vm_fops.h"

#undef INTERP_FOPCODE_LIST_BEGIN
#undef INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM
#undef INTERP_FOPCODE_LIST_END

	#ifdef AVMPLUS_SYMBIAN
	static const int mir_buffer_reserve_size =	1*1024*1024;	// 2MB
	#else
	static const int mir_buffer_reserve_size =	32*1024*1024;	// 32MB
	#endif
	static const int mir_buffer_size_min	 =	1024*1024;		// 1MB

	#ifdef AVMPLUS_AMD64
	static const int prologue_size = 65536; 
	#else
	static const int prologue_size = 32768; //3840;
	#endif
	static const int epilogue_size = 208;

	/**
	 * 3 instruction formats 
	 *
	 *  format 1  : oprnd1 = 0 and value = imm32
	 *  format 2  : oprnd1 = ptr | imm8 and value = imm32 (conditional branches oprnd1 = ptr [MIR_cm / MIR_cs / MIR_fcm / MIR_fcs] oprnd1 = imm8)
	 *  format 3  : oprnd1 = ptr  oprnd2 / oprnd3 are optional ptr (only MIR_st should use oprnd3)
	 */

	// format 2
	OP* CodegenLIR::Ins(MirOpcode code, OP* a1, uintptr_t v2)
	{
        switch(code) {
            case MIR_faddi: {
                uint64_t *dp = (uint64_t*)v2;
                return lirout->ins2(LIR_fadd, a1, lirout->insImmq(*dp));
            }
            default:
                AvmAssert(false);
                return 0;
        }
    }

    // unary
    LIns *CodegenLIR::Ins(LOpcode op, LIns* a) {
        return lirout->ins1(op, a);
    }

    // binary
	OP* CodegenLIR::Ins(MirOpcode code, OP* a1, OP* a2)
	{
        LOpcode op;
        switch(code) {
            case MIR_addp: op = LIR_add; break; // fixme - need non-cse ptr add
            default:
                AvmAssert(false);
                return 0;
        }
        return lirout->ins2(op, a1, a2);
	}

	OP* CodegenLIR::binaryIns(MirOpcode code, OP* a1, OP* a2) {
        return Ins(code, a1, a2);
	}

    OP* CodegenLIR::binaryIns(LOpcode op, LIns *a, LIns *b) {
        return lirout->ins2(op, a, b);
    }

	/**
 	 * ---------------------------------
	 * Instruction convenience functions 
	 * ---------------------------------
	 */

	// store to register + offset
	void CodegenLIR::storeIns(OP* value, int32_t disp, OP* base, bool force32) {
        if (force32 && value->isQuad())
            value = lirout->ins1(LIR_qlo, value);
        storeIns(value, disp, base);
    }

    void CodegenLIR::storeIns(LIns *value, int32_t disp, LIns* base) {
        lirout->store(value, base, disp);
	}

	OP* CodegenLIR::defIns(OP* value) {
        return value;
	}

	// address calc instruction
	OP* CodegenLIR::leaIns(int32_t disp, OP* base) {
        return lirout->ins2(LIR_add, base, lirout->insImm(disp));
	}

    // call 
	OP* CodegenLIR::callIns(uint32_t fid, uint32_t argc, ...)
	{
        AvmAssert(argc <= MAXARGS);
        AvmAssert(argc == k_functions[fid].count_args());

        LInsp args[MAXARGS];
        va_list ap;
        va_start(ap, argc);
        for (uint32_t i=0; i < argc; i++)
            args[argc-i-1] = va_arg(ap, LIns*);
        va_end(ap);

        return lirout->insCall(fid, args);
	}

	OP* CodegenLIR::callIndirect(uint32_t fid, OP* target, uint32_t argc, ...)
	{
        AvmAssert(argc+1 <= MAXARGS);
        AvmAssert(argc+1 == k_functions[fid].count_args());

        LInsp args[MAXARGS];
        va_list ap;
        va_start(ap, argc);
        for (uint32_t i=0; i < argc; i++)
            args[argc-i-1] = va_arg(ap, LIns*);
        va_end(ap);
        args[argc] = target; // addr is final arg in arglist

        return lirout->insCall(fid, args);
	}

    LIns *CodegenLIR::localCopy(int i) {
        return lirout->insLoad(
            state->value(i).traits == NUMBER_TYPE ? LIR_ldq : LIR_ld,
            vars, i<<3);
    }

	OP* CodegenLIR::localGet(int i) {
        return lirout->insLoadi(vars, i*8);
	}

	OP* CodegenLIR::localGetq(int i) {
        return lirout->insLoad(LIR_ldq, vars, i*8);
	}

	void  CodegenLIR::localSet(uintptr i, OP* o)	
	{
        Value &v = state->value(i);
        v.ins = lirout->store(o, vars, i*8);
        v.stored = true;
	}

	OP* CodegenLIR::atomToNativeRep(int i, OP* atom)
	{
		return atomToNativeRep(state->value(i).traits, atom);
	}

	OP* CodegenLIR::ptrToNativeRep(Traits*t, OP* ptr)
	{
		if (t->isMachineType)
		{
			return binaryIns(LIR_or, ptr, InsConst(kObjectType));
		}
		return ptr;
	}

	bool CodegenLIR::isPointer(int i)
	{
		return !state->value(i).traits->isMachineType;
	}

	bool CodegenLIR::isDouble(int i)
	{
		return state->value(i).traits == NUMBER_TYPE;
	}

	OP* CodegenLIR::loadAtomRep(int i)
	{
		Value& v = state->value(i);
		Traits* t = v.traits;

        // handle Number first in case we need to do a quad load
		if (t == NUMBER_TYPE)
		{
			uint32_t fid = FUNCTIONID(doubleToAtom);
#ifdef AVMPLUS_IA32
			if (core->config.sse2)
				fid = FUNCTIONID(doubleToAtom_sse2);
#endif
			return callIns(fid, 2, InsConst((uintptr)core), localGetq(i));
		}

		OP* native = localGet(i);

		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
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
				Atom a = core->uintToAtom(native->constval());
				if(AvmCore::isInteger(a))
					return InsConst(a);
			}

			if (t == BOOLEAN_TYPE)
			{
				return InsConst(native->constval() ? trueAtom : falseAtom);
			}

			if (!t->isMachineType && native->constval() == 0)
			{
				return InsConst(nullObjectAtom);
			}
		}

		if (t == INT_TYPE)
		{
			return callIns(FUNCTIONID(intToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == UINT_TYPE)
		{
			return callIns(FUNCTIONID(uintToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == BOOLEAN_TYPE)
		{
			OP* i1 = binaryIns(LIR_lsh, native, InsConst(3));
			return binaryIns(LIR_or, i1, InsConst(kBooleanType));
		}

		// possibly null pointers
		if (t == STRING_TYPE)
		{
			return binaryIns(LIR_or, native, InsConst(kStringType));
		}
		if (t == NAMESPACE_TYPE)
		{
			return binaryIns(LIR_or, native, InsConst(kNamespaceType));
		}

		return binaryIns(LIR_or, native, InsConst(kObjectType));
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
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	store args\n";
		#endif
		OP* ap = InsAlloc(sizeof(Atom)*(count+1));
		storeIns(receiver, 0, ap);
		for (int i=1; i <= count; i++)
		{
			OP* v = loadAtomRep(index++);
			storeIns(v, sizeof(Atom)*i, ap);
		}
		return ap;
	}

#ifdef DEBUGGER
	void CodegenLIR::extendDefLifetime(OP* current)
	{
        AvmAssert(false); (void) current; /*
		for (int i=0, n=state->verifier->local_count; i < n; i++)
		{
			OP* def = state->value(i).ins;
			if (!def)
				continue;
			if ((def->code & ~MIR_float) == MIR_use)
				def = def->oprnd1;
			AvmAssert(def && (def->code & ~MIR_float) == MIR_def);
			while (def->join)
				def = def->join;
			def->lastUse = current;
		}*/
	}
#endif

	void CodegenLIR::saveState()
	{
#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    save state\n";
#endif
	}

	void CodegenLIR::extendLastUse(OP* ins, OP* use, OP* target)
	{
        AvmAssert(false);
        (void) ins;
        (void) use;
        (void) target;
	}

	void CodegenLIR::extendLastUse(OP* use, sintptr targetpc)
	{
		// if target of the branch is in the middle of any
		// live range, extend the live range to include
		// the branch
        AvmAssert(false);
        (void) use;
        (void) targetpc;
	}

	void CodegenLIR::InsDealloc(OP* alloc)
	{
        (void) alloc;
		AvmAssert(alloc->isop(LIR_alloc));
		//alloc->lastUse = ip-1;
	}

	CodegenLIR::CodegenLIR(MethodInfo* i)
		: gc(i->core()->gc), core(i->core()), pool(i->pool), info(i), patches(gc), 
			interruptable(true)
	{
		state = NULL;

		#ifdef AVMPLUS_MAC_CARBON
		setjmpInit();
		#endif
		
		#ifdef AVMPLUS_ARM
		#ifdef AVMPLUS_VERBOSE
		this->verboseFlag = pool->verbose;
		#endif
		this->console = &core->console;
		#endif		

		abcStart = NULL;
		abcEnd   = NULL;

		overflow = false;
	
		#ifdef VTUNE
		hasDebugInfo = false;
		vtune = 0;
		mdOffsets = 0;
		#endif /* VTUNE */

        // set up the generator LIR pipeline
        if (!pool->codePages) {
			PageMgr *mgr = pool->codePages = new (gc) PageMgr();
            mgr->frago = new (gc) Fragmento(core, 24/*16mb*/);
			verbose_only(
                mgr->frago->assm()->_verbose = verbose();
                if (verbose()) {
				    LabelMap *labels = mgr->frago->labels = new (gc) LabelMap(core, 0);
				    labels->add(core, sizeof(AvmCore), 0, "core");
                }
			)
        }
	}

	CodegenLIR::~CodegenLIR()
	{
		//if (arg_count > 0)
		//	core->console << "mir_arg " << arg_count << " of " << InsNbr(ip) << "\n";
		//arg_count = 0;

		//clearMIRBuffers();
	}

	void CodegenLIR::clearMIRBuffers()
	{
		// free scratch buffers explicitly.  None of these have any pointers
		// in them, and none of them will have escaped into other objects.
		// freeing them now reduces GC pressure at startup time.

		// return the buffer back to the global list
		if (frag) 
			frag->releaseLirBuffer();
	}
	
	#ifdef AVMPLUS_MAC_CARBON
	int CodegenLIR::setjmpAddress = 0;

	extern "C" int __setjmp();
	
	asm int CodegenLIR::setjmpDummy(jmp_buf buf)
	{
		b __setjmp;	
	}
	
	void CodegenLIR::setjmpInit()
	{
		// CodeWarrior defies all reasonable efforts to get
		// the address of __vec_setjmp.  So, we resort to
		// a crude hack: We'll search the actual code
		// of setjmpDummy for the branch instruction.
		if (setjmpAddress == 0)
		{
			setjmpAddress = *((int*)&setjmpDummy);
		}
	}
	#endif

	Atom CodegenLIR::coerce_o(Atom v)
	{
		return v == undefinedAtom ? nullObjectAtom : v;
	}

#if defined AVMPLUS_PPC || defined AVMPLUS_SPARC
	// This helper function exists only on PowerPC in order to
	// minimize the code size of generated stack overflow checks.
	// It is static and takes only one parameter, env.
	// The env parameter goes into R3, which is where it also goes
	// in a JIT-ted function's method signature (env, argc, ap)
	// This enables us to not move any registers around.
	void CodegenLIR::stackOverflow(MethodEnv *env)
	{
		env->core()->stackOverflow(env);		
	}
#endif

#ifdef AVMPLUS_ARM
	double CodegenLIR::fadd(double x, double y)
	{
		return x+y;
	}
	
	double CodegenLIR::fsub(double x, double y)
	{
		return x-y;
	}

	double CodegenLIR::fmul(double x, double y)
	{
		return x*y;
	}

	double CodegenLIR::fdiv(double x, double y)
	{
		return x/y;
	}
	
	int   CodegenLIR::fcmp(double x, double y)
	{
		if (x<y)
		{
			return -1;
		}
		else if (x>y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	double CodegenLIR::i2d(int i)
	{
		return (double)i;
	}
	
	double CodegenLIR::u2d(uint32 i)
	{
		return (double)i;
	}
#endif /* AVMPLUS_ARM */

#ifndef FEATURE_BUFFER_GUARD
	bool CodegenLIR::checkOverflow()
	{
		if (overflow)
			return overflow;

		// if this fails, we aren't estimating a big enough space for MIR
		uintptr curSize = (uintptr)ip-(uintptr)ipStart;
		if (curSize >= mirBuffSize)
		{
			// start over with bigger buffer.
			expansionFactor *= 2;
			overflow = true;
		}
		return overflow;
	}
#endif

	OP* CodegenLIR::atomToNativeRep(Traits* t, OP* atom)
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
					return loadIns(MIR_fldop, 0, InsConst(a&~7));
				} else {
					AvmAssert(AvmCore::isInteger(a));
					return i2dIns(InsConst(a>>3));
				}
			} else {
				return callIns(FUNCTIONID(number_d), 1, atom);
			}
		}
		else if (t == INT_TYPE)
		{
			if (atom->isconst())
				return InsConst(AVMCORE_integer_i(atom->constval()));
			else
				return callIns(FUNCTIONID(integer_i), 1, atom);
		}
		else if (t == UINT_TYPE)
		{
			if (atom->isconst())
				return InsConst(AvmCore::integer_u(atom->constval()));
			else
				return callIns(FUNCTIONID(integer_u), 1, atom);
		}
		else if (t == BOOLEAN_TYPE)
		{
			if (atom->isconst())
				return InsConst(urshift(atom->constval(),3));
			else
				return binaryIns(LIR_ush, atom, InsConst(3));
		}
		else
		{
			// pointer type
			if (atom->isconst())
				return InsConst(atom->constval() & ~7);
			else
				return binaryIns(LIR_and, atom, InsConst(uintptr(~7)));
		}
		
#ifdef __GNUC__
		return 0;	// satisfy GCC, although we should never get here
#endif
	}

#ifdef _DEBUG
    class ValidateWriter: public LirWriter
    {
    public:
        ValidateWriter(LirWriter *out) : LirWriter(out)
        {}
        LIns *ins0(LOpcode op) {
            switch (op) {
                case LIR_tramp: AvmAssert(false); break;
                case LIR_neartramp: AvmAssert(false); break;
                case LIR_skip: AvmAssert(false); break;
                case LIR_nearskip: AvmAssert(false); break;
                case LIR_label: break;
                case LIR_start: break;
                default:AvmAssert(false);
            }
            return out->ins0(op);
        }

        LIns *insParam(int32_t i) {
            return out->insParam(i);
        }

        LIns *insImm(int32_t i) {
            return out->insImm(i);
        }

        LIns *insImmq(uint64_t i) {
            return out->insImmq(i);
        }

        LIns *ins1(LOpcode op, LIns *a) {
            switch (op) {
                case LIR_fneg: AvmAssert(a->isQuad()); break;
                case LIR_fret: AvmAssert(a->isQuad()); break;
                case LIR_not:  AvmAssert(!a->isQuad()); break;
                case LIR_neg:  AvmAssert(!a->isQuad()); break;
                case LIR_i2f:  AvmAssert(!a->isQuad()); break;
                case LIR_u2f:  AvmAssert(!a->isQuad()); break;
                case LIR_ret:  AvmAssert(!a->isQuad()); break;
                case LIR_qlo:  AvmAssert(a->isQuad()); break;
                case LIR_qhi:  AvmAssert(a->isQuad()); break;
                case LIR_live: break;
                default:AvmAssert(false);
            }
            return out->ins1(op, a);
        }

        LIns *ins2(LOpcode op, LIns *a, LIns *b) {
            switch (op) {
                case LIR_fadd: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fsub: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fmul: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fdiv: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_feq: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_flt: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fle: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fgt: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_fge: AvmAssert(a->isQuad() && b->isQuad()); break;
                case LIR_qjoin: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_add: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_sub: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_mul: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_and: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_or: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_xor: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_lsh: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_rsh: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_ush: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_eq: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_lt: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_gt: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_le: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_ge: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_ult: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_ule: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_ugt: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                case LIR_uge: AvmAssert(!a->isQuad() && !b->isQuad()); break;
                default:AvmAssert(false);
            }
            return out->ins2(op, a, b);
        }

        LIns *insLoad(LOpcode op, LIns *base, LIns *disp) {
            switch (op) {
                case LIR_ld: AvmAssert(!base->isQuad() && !disp->isQuad()); break;
                case LIR_ldc: AvmAssert(!base->isQuad() && !disp->isQuad()); break;
                case LIR_ldq: AvmAssert(!base->isQuad() && !disp->isQuad()); break;
                default: AvmAssert(false);
            }
            return out->insLoad(op, base, disp);
        }

        LIns *insStore(LIns *value, LIns *base, LIns *disp) {
            AvmAssert(base && value && !base->isQuad() && !disp->isQuad());
            return out->insStore(value, base, disp);
        }

        LIns *insStorei(LIns *value, LIns *base, int32_t d) {
            AvmAssert(base && value && !base->isQuad());
            return out->insStorei(value, base, d);
        }

        LIns *insBranch(LOpcode op, LIns *cond, LIns *to) {
            switch (op) {
                case LIR_jt: AvmAssert(cond->isCond() && (!to || to->isop(LIR_label))); break;
                case LIR_jf: AvmAssert(cond->isCond() && (!to || to->isop(LIR_label))); break;
                case LIR_j:  AvmAssert(!cond && (!to || to->isop(LIR_label))); break;
                case LIR_ji: AvmAssert(!cond && to && !to->isop(LIR_label)); break;
                default: AvmAssert(false);
            }
            return out->insBranch(op, cond, to);
        }

        LIns *insGuard(LOpcode v, LIns *cond, SideExit *x) {
            AvmAssert(false);
            return out->insGuard(v, cond, x);
        }

        LIns *insAlloc(int32_t size) {
            AvmAssert(size >= 4 && isU16((size+3)>>2));
            return out->insAlloc(size);
        }

        LIns *insCall(uint32_t fid, LInsp args[]) {
            const CallInfo &call = k_functions[fid];
            ArgSize sizes[2*MAXARGS];
            uint32_t argc = call.get_sizes(sizes);
            if (call.isIndirect()) {
                argc--;
                AvmAssert(!args[argc]->isQuad());
            }
            for (uint32_t i=0; i < argc; i++) {
                switch (sizes[i]) {
                    default: AvmAssert(false);
                    case ARGSIZE_LO: NanoAssert(!args[i]->isQuad()); break;
                    case ARGSIZE_Q: NanoAssert(args[i]->isQuad()); break;
                    case ARGSIZE_F: NanoAssert(args[i]->isQuad()); break;
                }
            }
            return out->insCall(fid, args);
        }
    };
#endif //  _DEBUG

    class CopyPropagation: public LirWriter
    {
        SortedMap<int, LIns*, LIST_NonGCObjects> tracker;
        LIns *vars;
    public:
        CopyPropagation(GC *gc, LirWriter *out) : LirWriter(out), tracker(gc)
        {}

        void init(LIns *vars) {
            this->vars = vars;
        }

        void store(int d, LIns *val) {
            tracker.put(d, val);
        }

        void reset() {
            tracker.clear();
        }

        LIns *insLoad(LOpcode op, LIns *base, LIns *disp) {
            if (base == vars) {
                int d = disp->constval();
                LIns *val = tracker.get(d);
                if (val) {
                    return val;
                }
            }
            return out->insLoad(op, base, disp);
        }

        LIns *insStore(LIns *value, LIns *base, LIns *disp) {
            if (base == vars)
                store(disp->constval(), value);
            return out->insStore(value, base, disp);
        }

        LIns *insStorei(LIns *value, LIns *base, int32_t d) {
            if (base == vars)
                store(d, value);
            return out->insStorei(value, base, d);
        }

        LIns *ins0(LOpcode op) {
            if (op == LIR_label)
                reset();
            return out->ins0(op);
        }

        LIns *ins1(LOpcode op, LIns* a) {
            if (isRet(op))
                reset();
            return out->ins1(op, a);
        }

        // TODO
        // * reset when vars passed as arg to a function that could modify vars (debugenter/exit)
        // * handle load/store size mismatches -- loading high word of quad, etc
        // * suppress stores until saveState() points.
    };

	// f(env, argc, instance, argv)
	bool CodegenLIR::prologue(FrameState* state)
	{
		this->state = state;
		abcStart = state->verifier->code_pos;
		abcEnd   = abcStart + state->verifier->code_length;

        Fragmento *frago = pool->codePages->frago;
        frag = frago->getAnchor(abcStart);
        gc->Free(frag->mergeCounts);
        lirbuf = frag->lirbuf = new (gc) LirBuffer(frago, k_functions);
        lirbuf->abi = ABI_CDECL;
        lirout = new (gc) LirBufWriter(lirbuf);
        debug_only(
            // catch problems before they hit the buffer
            lirout = new (gc) ValidateWriter(lirout);
        )
        verbose_only(
            if (verbose()) {
                lirbuf->names = new (gc) LirNameMap(gc, k_functions, frago->labels);
                lirout = new (gc) VerboseWriter(gc, lirout, lirbuf->names);
            }
        )
        lirout = new (gc) ExprFilter(lirout);
        CopyPropagation *copier = new (gc) CopyPropagation(gc, lirout);
        lirout = copier;
        debug_only(
            // catch problems before they hit the pipeline
            lirout = new (gc) ValidateWriter(lirout);
        )

        lirout->ins0(LIR_start);

		if (overflow) return false;

#ifndef FEATURE_BUFFER_GUARD 
		// if we aren't growing the buffer dynamically then commit a whole bunch of it
		mirBuffSize = sizeof(OP) * (40*expansionFactor*(abcEnd-abcStart)) + epilogue_size + prologue_size;  // MIR instructions
		mirBuffSize = BIT_ROUND_UP(mirBuffSize, mirBuffer->pageSize());
		mirBuffer->growBy(mirBuffSize);
#endif /* FEATURE_BUFFER_GUARD */

		// last pc value that we generated a store for 
		lastPcSave = 0;

		//
		// mir to define incoming method arguments.  Stack 
		// frame allocations follow.
		//

        env_param = lirout->insParam(0);
        argc_param = lirout->insParam(1);
        ap_param = lirout->insParam(2);
        vars = InsAlloc(state->verifier->frameSize * 8);
        lirbuf->sp = vars;
        if (copier)
            copier->init(vars);

        verbose_only( if (lirbuf->names) {
            lirbuf->names->addName(env_param, "env");
            lirbuf->names->addName(argc_param, "argc");
            lirbuf->names->addName(ap_param, "ap");
            lirbuf->names->addName(vars, "vars");
        })

        #ifdef DEBUGGER
		// pointers to traits so that the debugger can decode the locals
		// IMPORTANT don't move this around unless you change MethodInfo::boxLocals()
		varTraits = InsAlloc(state->verifier->local_count * sizeof(Traits*));
		varPtrs = InsAlloc((state->verifier->local_count + state->verifier->max_scope) * sizeof(void*));
        verbose_only( if (lirbuf->names) {
            lirbuf->names->addName(varTraits, "varTraits");
            lirbuf->names->addName(varPtrs, "varPtrs");
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
            verbose_only( if (lirbuf->names) {
                lirbuf->names->addName(_save_eip, "_save_eip");
                lirbuf->names->addName(_ef, "_ef");
            })
		}

		if (info->setsDxns())
		{
			dxns = InsAlloc(sizeof(Namespace*));
            verbose_only( if (lirbuf->names) {
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
			OP* invocationCount = loadIns(MIR_ldop, offsetof(MethodEnv, invocationCount), env_param);
			OP *result = binaryIns(LIR_add, invocationCount, InsConst(1));
			storeIns(result, offsetof(MethodEnv, invocationCount), env_param);
		}

		// Allocate space for the call stack
		csn = InsAlloc(sizeof(CallStackNode));
        verbose_only( if (lirbuf->names) {
            lirbuf->names->addName(csn, "csn");
        })
		#endif
		
		if (info->setsDxns())
		{
			// dxns = env->vtable->scope->defaultXmlNamespace
			OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
			OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
			OP* capturedDxns = loadIns(MIR_ldop, offsetof(ScopeChain, defaultXmlNamespace), scope);
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
			{
				if (info->paramTraits(i) == NUMBER_TYPE)
				{
					offset += 8;
				}
				else
				{
#ifdef AVMPLUS_64BIT
					offset += 8;
#else
					offset += 4;
#endif
				}
			}

			// now copy the default optional values
			OP* argcarg = argc_param;
			for (int i=0, n=info->optional_count; i < n; i++)
			{
				// first set the local[p+1] = defaultvalue
				int param = i + info->param_count - info->optional_count; // 0..N
				int loc = param+1;

				OP* defaultVal = InsConst(info->getDefaultValue(i));
				defaultVal = defIns(atomToNativeRep(loc, defaultVal));
                localSet(loc, defaultVal);
				
				// then generate: if (argc > p) local[p+1] = arg[p+1]
				OP* cmp = binaryIns(LIR_le, argcarg, InsConst((int32)param));
				OP* br = branchIns(LIR_jt, cmp); // will patch
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
				localSet(loc, arg);

                LIns *label = Ins(LIR_label);
				br->target(label);
                label->setimm24((loc+1) * 8);
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
			OP* argcArg = argc_param;
			OP* apArg = ap_param;

			// use csop so if rest value never used, we don't bother creating array
			OP* rest = callIns(FUNCTIONID(createRestHelper), 3, 
				env_param, argcArg, apArg);

			localSet(firstLocal, rest);
			firstLocal++;
		}
		else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
		{
			//framep[info->param_count+1] = createArguments(env, argv, argc);
			OP* argcArg = argc_param;
			OP* apArg = ap_param;

			// use csop so if arguments never used, we don't create it
			OP* arguments = callIns(FUNCTIONID(createArgumentsHelper), 3, 
				env_param, argcArg, apArg);

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

		callIns(FUNCTIONID(debugEnter), 8,
			env_param, argc_param, ap_param, // for sendEnter
			leaIns(0, varTraits), InsConst(state->verifier->local_count), // for clearing traits pointers
			leaIns(0, csn), 
			leaIns(0, varPtrs),
			info->hasExceptions() ? leaIns(0, _save_eip) : InsConst(0)
			);

		#endif // DEBUGGER

		if (info->isFlagSet(AbstractFunction::HAS_EXCEPTIONS))
		{
			// _ef.beginTry(core);
			callIns(FUNCTIONID(beginTry), 2,
				leaIns(0,_ef), InsConst((uintptr)core));

			// spill prior to jmp so that our stack is cleared of 
			// any transient locals.
			saveState();

			// force the locals to be clean for the setjmp call
			LIns *label = Ins(LIR_label);
            label->setimm24(state->verifier->frameSize * 8);
			
			// Exception* _ee = setjmp(_ef.jmpBuf);
			// ISSUE this needs to be a cdecl call
			OP* jmpbuf = leaIns(offsetof(ExceptionFrame, jmpbuf), _ef);
			OP* ee = callIns(FUNCTIONID(fsetjmp), 2,
				jmpbuf, InsConst(0));

#ifdef AVMPLUS_SPARC
			beginCatch_start = ee;
#endif

			// if (setjmp() == 0) goto start
			OP* cond = binaryIns(LIR_eq, ee, InsConst(0));
			OP* exBranch = branchIns(LIR_jt, cond);

			// exception case
			exAtom = loadIns(MIR_ld, offsetof(Exception, atom), ee);
			// need to convert exception from atom to native rep, at top of 
			// catch handler.  can't do it here because it could be any type.

			// _ef.beginCatch()
			// ISSUE why do we have to redefine ef? it is NULL when exception happens
			OP* pc = loadIns(MIR_ld, 0, _save_eip);
			OP* handler = callIns(FUNCTIONID(beginCatch), 5,
				InsConst((uintptr)core), leaIns(0,_ef), InsConst((uintptr)info), pc, ee);

#ifdef AVMPLUS_SPARC
			beginCatch_end = handler;
#endif

			// jump to catch handler
            handler = loadIns(MIR_ld, offsetof(ExceptionHandler, target), handler);
			branchIns(LIR_ji, 0, handler);

			// target of conditional
            label->setimm24(state->verifier->frameSize * 8);
			exBranch->target(label);
		}

		// If interrupts are enabled, generate an interrupt check.
		// This ensures at least one interrupt check per method.
		if (interruptable && core->config.interrupts)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			#ifdef AVMPLUS_64BIT
			OP* interrupted = loadIns(MIR_ld32, 0, InsConst((uintptr)&core->interrupted));
			#else
			OP* interrupted = loadIns(MIR_ld, 0, InsConst((uintptr)&core->interrupted));
			#endif
			OP* br = branchIns(LIR_jf, binaryIns(LIR_eq, interrupted, InsConst(0)));
			patchLater(br, interrupt_label);
		}

        // mark end of prolog
        //LIns *label = Ins(LIR_label);
        //label->setimm24(state->verifier->scopeBase * 8);

		return true;
	}

	void CodegenLIR::emitCopy(FrameState* state, int src, int dest) {
		this->state = state;
		localSet(dest, localCopy(src));
	}

	void CodegenLIR::emitGetscope(FrameState* state, int scope_index, int dest)
	{
		this->state = state;
		Traits* t = info->declaringTraits->scope->scopes[scope_index].traits;
		OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
		OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
		OP* scopeobj = loadIns(MIR_ldop, offsetof(ScopeChain, scopes) + scope_index*sizeof(Atom), scope);
		localSet(dest, atomToNativeRep(t, scopeobj));
	}

	void CodegenLIR::emitSwap(FrameState* state, int i, int j) {
		this->state = state;
		OP* t = localCopy(i);
		localSet(i, localCopy(j));
		localSet(j, t);
	}

	void CodegenLIR::emitKill(FrameState* state, int i)
	{
		this->state = state;
		localSet(i, undefConst);
	}

	void CodegenLIR::emitSetContext(FrameState *state, AbstractFunction *f)
	{
		this->state = state;
		//
		// initialize the code context
		//
		if (isCodeContextChanged())
		{
 			if (!f || f->usesCallerContext())
			{
				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console << "        	set code context\n";
				#endif

				// core->codeContext = env;
				storeIns(env_param, 0, InsConst((uintptr)&core->codeContextAtom));
			}

			if (!f || f->usesDefaultXmlNamespace())
			{
				emitSetDxns(state);

				// used to dump all functions that still say they required DXNS code
				#if 0//def _DEBUG
				if (f && (f->flags & AbstractFunction::NATIVE))
				{
					StringBuffer buffer(core);		
					const wchar *foo = f->name->c_str();
					buffer << "function is:" << foo << "\r\n";

					AvmDebugMsg (false, buffer.c_str());
					//core->console << " f->
				}
				#endif
			}
		}
	}

	void CodegenLIR::emitSetDxns(FrameState* state)
	{
		this->state = state;

		OP* dxnsAddr;

		if (info->isFlagSet(AbstractFunction::SETS_DXNS)) {
			dxnsAddr = leaIns(0,dxns);
		}
		else {
			// dxnsAddr = &env->vtable->scope->defaultXmlNamespace
			OP* env = env_param;
			OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env);
			OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
			dxnsAddr = leaIns(offsetof(ScopeChain, defaultXmlNamespace), scope);
		}

		storeIns(dxnsAddr, 0, InsConst((uintptr)&core->dxnsAddr));
	}

	void CodegenLIR::merge(const Value& current, Value& target)
	{
		if (target.ins != current.ins)
		{
			AvmAssert(target.ins->isStore() && current.ins->isStore());
		}
	}


	void CodegenLIR::emitBlockStart(FrameState* state)
	{
		// our new extended BB now starts here, this means that any branch targets
		// should hit the next instruction our bb start instruction
		OP* bb = Ins(LIR_label); // mark start of block
        bb->setimm24((state->sp()+1) * 8);

		// get a label for our block start and tie it to this location
		mirLabel(state->verifier->getFrameState(state->pc)->label, bb);

		// If this is a backwards branch, generate an interrupt check.
		// current verifier state, includes tack pointer.
		if (interruptable && core->config.interrupts && state->targetOfBackwardsBranch)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			#ifdef AVMPLUS_AMD64
			OP* interrupted = loadIns(MIR_ld, 0, InsConst((uintptr)&core->interrupted));
			#else
			OP* interrupted = loadIns(MIR_ld, 0, InsConst((uintptr)&core->interrupted));
			#endif
			OP* br = branchIns(LIR_jf, binaryIns(LIR_eq, interrupted, InsConst(0)));
			patchLater(br, interrupt_label);
		}
	}

	void CodegenLIR::emitBlockEnd(FrameState* state)
	{
		this->state = state;

#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "       block end\n";
#endif

		// our eBB now terminates.  For all branch instructions we are
		// able to detect this situation and have already generated the 
		// correct spill code prior to the jump, only for the case where 
		// the pc is a target of a jump do we not know enough during emit() 
		// to do this.  The Verifier tracks this information and merges
		// the states across the various blocks generating this op prior
		// to the merge.  After this emit, we should receive an emitBlockStart()
		// from the Verifier.
		saveState();
	}

	void CodegenLIR::emitIntConst(FrameState* state, int index, uintptr c)
	{
		this->state = state;
		localSet(index, InsConst(c));
	}

	void CodegenLIR::emitDoubleConst(FrameState* state, int index, double* pd)
	{
		this->state = state;
        uint64_t *pquad = (uint64_t*) pd;
		localSet(index, lirout->insImmq(*pquad));
	}

	void CodegenLIR::emitCoerce(FrameState* state, int loc, Traits* result)
	{
		this->state = state;
		emitPrep(OP_coerce);

		Value& value = state->value(loc);
		Traits* in = value.traits;

		if (result == NULL)
		{
			// coerce to * is simple, we just save the atom rep.
			localSet(loc, loadAtomRep(loc));
		}
		else if (result == OBJECT_TYPE)
		{
			if (in == NULL || in == VOID_TYPE)
			{
				// value already boxed but we need to coerce undefined->null
				if (!value.notNull)
					localSet(loc, callIns(FUNCTIONID(coerce_o), 1,
										localGet(loc)));
			}
			else
			{
				// value cannot be undefined so just box it
				localSet(loc, loadAtomRep(loc));
			}
		}
		else if (!result->isMachineType && in == NULL_TYPE)
		{
			// do nothing, it's fine to coerce null to a pointer type
		}
		else if (result == NUMBER_TYPE)
		{
			if (in && in->isNumeric || in == BOOLEAN_TYPE)
			{
				localSet(loc, promoteNumberIns(in, loc));
			}
			else
			{
				// * -> Number
				localSet(loc, callIns(FUNCTIONID(number), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == INT_TYPE)
		{
			if (in == UINT_TYPE || in == BOOLEAN_TYPE)
			{
				//do nothing
			}
			else if (in == NUMBER_TYPE)
			{
				OP* ins = localGetq(loc);
				if (ins != NULL && ins->isop(LIR_fadd) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					// old: int(fadd(Number(int),Number(int)))
					// new: iadd(int,int)
					localSet(loc, binaryIns(LIR_add, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && ins->isop(LIR_fsub) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					localSet(loc, binaryIns(LIR_sub, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && ins->isop(LIR_fmul) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					localSet(loc, binaryIns(LIR_mul, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && (ins->isop(LIR_i2f) || ins->isop(LIR_u2f)))
				{
					localSet(loc, ins->oprnd1());
					markDead(ins);
				}
				else
				{
					uint32_t funcaddr = FUNCTIONID(integer_d);
					// narrowing conversion number->int
#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					if (core->config.sse2)
						funcaddr = FUNCTIONID(integer_d_sse2);
	#endif
					localSet(loc, callIns(funcaddr, 1, localGetq(loc)));
				}
			}
			else
			{
				// * -> int
				localSet(loc, callIns(FUNCTIONID(integer), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == UINT_TYPE)
		{
			if (in == INT_TYPE || in == BOOLEAN_TYPE)
			{
				//do nothing
			}
			else if (in == NUMBER_TYPE)
			{
				OP* ins = localGetq(loc);
				if (ins != NULL && ins->isop(LIR_fadd) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					// old: uint(fadd(Number(uint),Number(uint)))
					// new: iadd(int,int)
					localSet(loc, binaryIns(LIR_add, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && ins->isop(LIR_fsub) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					localSet(loc, binaryIns(LIR_sub, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && ins->isop(LIR_fmul) &&
					(ins->oprnd1()->isop(LIR_u2f) || ins->oprnd1()->isop(LIR_i2f)) &&
					(ins->oprnd2()->isop(LIR_u2f) || ins->oprnd2()->isop(LIR_i2f)))
				{
					localSet(loc, binaryIns(LIR_mul, ins->oprnd1()->oprnd1(), ins->oprnd2()->oprnd1()));
					markDead(ins);
				}
				else if (ins != NULL && ((ins->isop(LIR_i2f)) || (ins->isop(LIR_u2f))))
				{
					localSet(loc, ins->oprnd1());
					markDead(ins);
				}
				else
				{

	#if defined(AVMPLUS_IA32) || defined (AVMPLUS_AMD64)
					if (core->config.sse2)
					{
						// Note: make sure we call the version that returns a
						// 32-bit result here
						localSet(loc, callIns(FUNCTIONID(integer_d_sse2), 1,
											localGetq(loc)));
					}
					else
	#endif
					{
						localSet(loc, callIns(FUNCTIONID(integer_d), 1,
											localGetq(loc)));
					}
				}
			}
			else
			{
				// * -> uint
				localSet(loc, callIns(FUNCTIONID(toUInt32), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == BOOLEAN_TYPE)
		{
			if (in == NUMBER_TYPE)
			{
                localSet(loc, callIns(FUNCTIONID(doubleToBool), 1, localGetq(loc)));
			}
			else if (in == INT_TYPE || in == UINT_TYPE || (in && !in->notDerivedObjectOrXML))
			{
                // int to bool: b = !!i
				localSet(loc, binaryIns(LIR_eq, 
                    binaryIns(LIR_eq, localGet(loc), InsConst(0)),
                    InsConst(0)));
			}
			else
			{
				// * -> Boolean
				localSet(loc, callIns(FUNCTIONID(boolean), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == STRING_TYPE)
		{
			if (in == INT_TYPE)
			{
				localSet(loc, callIns(FUNCTIONID(intToString), 2,
					InsConst((uintptr)core), localGet(loc)));
			}
			else if (in == UINT_TYPE)
			{
				localSet(loc, callIns(FUNCTIONID(uintToString), 2,
					InsConst((uintptr)core), localGet(loc)));
			}
			else if (in == NUMBER_TYPE)
			{
				localSet(loc, callIns(FUNCTIONID(doubleToString), 2,
					InsConst((uintptr)core), localGetq(loc)));
			}
			else if (in == BOOLEAN_TYPE)
			{
				// load "true" or "false"
#ifdef AVMPLUS_64BIT
				OP *index = binaryIns(LIR_lsh, localGet(loc), InsConst(3));
#else
				OP *index = binaryIns(LIR_lsh, localGet(loc), InsConst(2));
#endif
				localSet(loc, loadIns(MIR_ldop, (uintptr)&core->booleanStrings, index));
			}
			else if (value.notNull)
			{
				// not eligible for CSE, and we know it's not null/undefined
				localSet(loc, callIns(FUNCTIONID(string), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
			else
			{
				localSet(loc, callIns(FUNCTIONID(coerce_s), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (in && !in->isMachineType && !result->isMachineType
			   && in != STRING_TYPE && in != NAMESPACE_TYPE)
		{
			OP* toplevel = loadToplevel(env_param);
			// coerceobj is void, but we mustn't optimize it out; verifier only calls it when required
			callIns(FUNCTIONID(coerceobj), 3,
				toplevel, localGet(loc), InsConst((uintptr)result));
			// the input pointer has now been checked but it's still the same value.
			// verifier remembers this fact by updating the verify time type.
		}
		else if (!result->isMachineType && result != NAMESPACE_TYPE)
		{
			// result is a ScriptObject based type.
			localSet(loc, callIns(FUNCTIONID(coerceAtom2SO), 3,
				env_param, loadAtomRep(loc), InsConst((uintptr)result)));
		}
		else
		{
			OP* value = loadAtomRep(loc);
			OP* toplevel = loadToplevel(env_param);
			// sp[0] = toplevel->coerce(sp[0], traits)
			OP* out = callIns(FUNCTIONID(coerce), 3,
				toplevel,
				value,
				InsConst((uintptr)result));

			// store the result
			localSet(loc, atomToNativeRep(result, out));
		}
	}

	void CodegenLIR::emitCheckNull(FrameState* state, int index)
	{
		this->state = state;
		emitPrep(OP_convert_o);

		// The result is either unchanged or an exception is thrown, so 
		// we don't save the result.  This is the null pointer check.
		Traits* t = state->value(index).traits;
		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
			// checking atom for null or undefined (AvmCore::isNullOrUndefined())
			OP* value = localGet(index);
			callIns(FUNCTIONID(nullcheck), 2, env_param, value);
		}
		else if (!t->isMachineType)
		{
			// checking pointer for null
			OP* value = localGet(index);
			OP* br = branchIns(LIR_jt, binaryIns(LIR_eq, value, InsConst(0))); // will be patched
			patchLater(br, npe_label);
		}
		// else: number, int, uint, and boolean, are never null
	}

	void CodegenLIR::emitPrep(AbcOpcode opcode)
	{
		(void)opcode;

		// update bytecode ip if necessary
		if (state->insideTryBlock && lastPcSave != state->pc)
		{
			storeIns(InsConst(state->pc), 0, _save_eip);
			lastPcSave = state->pc;
		}
	}

	void CodegenLIR::emitCall(FrameState *state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result)
	{
		this->state = state;
		emitPrep(opcode);

		int sp = state->sp();

		int dest = sp-argc;
		int objDisp = dest;

		// make sure null check happened.
		AvmAssert(state->value(objDisp).notNull);

		OP *method = NULL;
		OP *iid = NULL;
		switch (opcode)
		{
		case OP_constructsuper:
		{
			// env->vtable->base->init->enter32v(argc, ...);
			OP* envArg = env_param;
			OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
			OP* base = loadIns(MIR_ldop, offsetof(VTable,base), vtable);
			method = loadIns(MIR_ldop, offsetof(VTable,init), base);
			break;
		}
		case OP_callmethod:
		{
			// stack in:  obj arg1..N
			// stack out: result
			// sp[-argc] = callmethod(disp_id, argc, ...);
			// method_id is disp_id of virtual method
			OP* vtable = loadVTable(objDisp);
			method = loadIns(MIR_ldop, offsetof(VTable, methods)+sizeof(uintptr)*method_id, vtable);
			break;
		}
		case OP_callsuperid:
		{
			// stack in: obj arg1..N
			// stack out: result
			// method_id is disp_id of super method
			OP* declvtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
			OP* basevtable = loadIns(MIR_ldop, offsetof(VTable, base), declvtable);
			method = loadIns(MIR_ldop, offsetof(VTable, methods)+sizeof(uintptr)*method_id, basevtable);
			break;
		}
		case OP_callstatic:
		{
			// stack in: obj arg1..N
			// stack out: result

			OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env_param);
			OP* abcenv = loadIns(MIR_ldop, offsetof(VTable, abcEnv), vtable);
			method = loadIns(MIR_ldop, offsetof(AbcEnv,methods)+sizeof(uintptr)*method_id, abcenv);
			break;
		}
		case OP_callinterface:
		{
			// method_id is pointer to interface method name (multiname)
			int index = int(method_id % Traits::IMT_SIZE);
			OP* vtable = loadVTable(objDisp);
			method = loadIns(MIR_ldop, offsetof(VTable, imt)+sizeof(uintptr)*index, vtable);
			iid = InsConst(method_id);
			break;
		}
		case OP_construct:
		{
			// stack in: ctor arg1..N
			// stack out: newinstance
			OP* vtable = loadVTable(objDisp);
			OP* ivtable = loadIns(MIR_ldop, offsetof(VTable, ivtable), vtable);
			method = loadIns(MIR_ldop, offsetof(VTable, init), ivtable);
			OP* inst = callIns(FUNCTIONID(newInstance),1, localGet(objDisp));
			localSet(dest, inst);
			break;
		}
		default:
			AvmAssert(false);
		}

		// store args for the call
		int index = objDisp;
		OP* ap = InsAlloc(4);
		int disp = 0;
		for (int i=0; i <= argc; i++)
		{
            // use localCopy so we sniff the arg type and use appropriate load instruction
			OP* v = localCopy(index++);
			storeIns(v, disp, ap);
            disp += v->isQuad() ? 8 : 4;
		}
		// patch the size to what we actually need
        AvmAssert(isU16(disp));
		ap->setimm16(disp);

		OP* target = loadIns(MIR_ld, offsetof(MethodEnv, impl32), method);
		OP* apAddr = leaIns(0, ap);

        LIns *out;
        if (!iid) {
            uint32_t fid = result==NUMBER_TYPE ? FUNCTIONID(fcalli) : FUNCTIONID(calli);
		    out = callIndirect(fid, target, 3, method, InsConst(argc), apAddr);
        } else {
            uint32_t fid = result==NUMBER_TYPE ? FUNCTIONID(fcallimt) : FUNCTIONID(callimt);
		    out = callIndirect(fid, target, 4, iid, method, InsConst(argc), apAddr);
        }

		InsDealloc(ap);

		if (opcode != OP_constructsuper && opcode != OP_construct)
		{
			localSet(dest, out); 
		}
	}

	void CodegenLIR::emit(FrameState* state, AbcOpcode opcode, uintptr op1, uintptr op2, Traits* result)
	{
		this->state = state;
		emitPrep(opcode);

		int sp = state->sp();

		switch (opcode)
		{
			case OP_jump:
			{
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
				OP* p = branchIns(LIR_j, 0); // will be patched
				patchLater(p, targetpc);
				break;
			}

			case OP_lookupswitch:
			{
				//int index = integer(*(sp--));
				//pc += readS24(index < readU16(pc+4) ? 
				//	(pc+6+3*index) :	// matched case
				//	(pc+1));			// default
				int count = int(1 + op2);
				sintptr targetpc = op1;

				AvmAssert(state->value(sp).traits == INT_TYPE);

				saveState();

				OP* input = localGet(sp);
				OP* cmp = binaryIns(LIR_ult, input, InsConst(count));
				OP* p = branchIns(LIR_jf, cmp); // will be patched
				patchLater(p, targetpc);

                // fixme - this is just a bunch of if's

				const byte* pc = 4 + abcStart + state->pc;
                AvmCore::readU30(pc);

				for (int i=0; i < count; i++)
				{
					sintptr target = state->pc + AvmCore::readS24(pc+3*i);
                    LIns *br = branchIns(LIR_jt, binaryIns(LIR_eq, input, InsConst(i)));
                    patchLater(br, target);
					//if (target < state->pc)
					//	extendLastUse(jmpt, target);
				}
				break;
			}

			case OP_setglobalslot:
			case OP_setslot:
			case OP_getslot:
			{
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
                    // use localCopy() to sniff the type and use ldq if it's Number
					OP* value = localCopy(sp);					

					#ifndef MMGC_DRC
					storeIns(value, offset, ptr);
					#endif

					#ifdef WRITE_BARRIERS
					// if storing to a pointer-typed slot, inline a WB
					Traits* slotType = t->getSlotTraits(slot);

					if (core->GetGC()->incremental &&
						(!slotType || !slotType->isMachineType || slotType == OBJECT_TYPE))
					{
						#ifdef MMGC_DRC
						uint32_t wbAddr = FUNCTIONID(writeBarrierRC);
						if(slotType == NULL || slotType == OBJECT_TYPE) {
							// use fast atom wb
							// TODO: inline pointer check
							wbAddr = FUNCTIONID(atomWriteBarrier);
						}
						callIns(wbAddr, 4, 
								InsConst((uintptr)core->GetGC()), 
								unoffsetPtr, 
								leaIns(offset, ptr),
								value);
						#else // !DRC
						// use non-substitute WB
						callIns(FUNCTIONID(WriteBarrierTrap), 3, 
								InsConst((int)core->gc), 
								unoffsetPtr,
								(slotType && slotType != OBJECT_TYPE) ? value :
								binaryIns(MIR_and, value, InsConst(~7)));
						#endif
					}					
					#ifdef MMGC_DRC
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
					#endif //MMGC_DRC
					#endif //WRITE_BARRIERS
				}
				break;
			}

			case OP_returnvoid:
			case OP_returnvalue:
			{
				// ISSUE if a method has multiple returns this causes some bloat

				// restore AvmCore::dxnsAddr if we set it to a stack addr in our frame
				if(info->setsDxns()) {
					storeIns(dxnsAddrSave, 0, InsConst((uintptr)&core->dxnsAddr));
				}

				#ifdef DEBUGGER
				callIns(FUNCTIONID(debugExit), 2,
					env_param, leaIns(0, csn));
				// now we toast the cse and restore contents in order to 
				// ensure that any variable modifications made by the debugger
				// will be pulled in.
				//firstCse = ip;
				#endif // DEBUGGER

				if (info->exceptions)
				{
					// _ef.endTry();
					OP* ef = leaIns(0, _ef);
					callIns(FUNCTIONID(endTry), 1,
						ef);
				}

				OP* retvalue;
				if (opcode == OP_returnvalue)
				{
					// already coerced to required native type
                    // use localCopy to sniff type and use appropriate load instruction
					retvalue = localCopy(op1);
				}
				else
				{
					retvalue = undefConst;
					Traits* t = info->returnTraits();
					if (t && t != VOID_TYPE)
					{
						// implicitly coerce undefined to the return type
						OP* toplevel = loadToplevel(env_param);
						retvalue = callIns(FUNCTIONID(coerce), 3,
							toplevel, retvalue, InsConst((uintptr)t));
						retvalue = atomToNativeRep(t, retvalue);
					}
				}
                Ins((retvalue->isQuad() ? LIR_fret : LIR_ret), retvalue);
				break;
			}

			case OP_typeof:
			{
				//sp[0] = typeof(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(FUNCTIONID(typeof), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_not:
			{
				AvmAssert(state->value(op1).traits == BOOLEAN_TYPE);
				OP* value = localGet(op1);
				OP* i3 = binaryIns(LIR_xor, value, InsConst(1));
				localSet(op1, i3);
				break;
			}

            case OP_negate: {
				localSet(op1, Ins(LIR_fneg, localGetq(op1)));
				break;
			}

            case OP_negate_i: {
				//framep[op1] = -framep[op1]
				AvmAssert(state->value(op1).traits == INT_TYPE);
				localSet(op1, Ins(LIR_neg, localGet(op1)));
				break;
			}

			case OP_increment:
			case OP_decrement:
			case OP_inclocal:
            case OP_declocal: {
				localSet(op1, binaryIns(LIR_fadd, localGetq(op1), i2dIns(InsConst(op2))));
				break;
			}

			case OP_inclocal_i:
			case OP_declocal_i:
			case OP_increment_i:
            case OP_decrement_i: {
				AvmAssert(state->value(op1).traits == INT_TYPE);
				localSet(op1, binaryIns(LIR_add, localGet(op1), InsConst(op2)));
				break;
			}

            case OP_bitnot: {
				// *sp = core->intToAtom(~integer(*sp));
				AvmAssert(state->value(op1).traits == INT_TYPE);
				localSet(op1, lirout->ins1(LIR_not, localGet(op1)));
				break;
			}

            case OP_modulo: {
				OP* out = callIns(FUNCTIONID(mod), 2,
					localGetq(sp-1), localGetq(sp));
				localSet(sp-1,	out);
				break;
			}

            case OP_divide:
            case OP_multiply:
            case OP_subtract:
            case OP_add_d: {
				LOpcode mircode;
				switch (opcode) {
					default:
					case OP_divide:     mircode = LIR_fdiv; break;
					case OP_multiply:   mircode = LIR_fmul; break;
					case OP_subtract:   mircode = LIR_fsub; break;
					case OP_add_d:      mircode = LIR_fadd; break;
				}
                localSet(sp-1, binaryIns(mircode, localGetq(sp-1), localGetq(sp)));
                break;
            }

			case OP_subtract_i:
			case OP_add_i:
			case OP_multiply_i:
			case OP_lshift:
			case OP_rshift:
			case OP_urshift:
			case OP_bitand:
			case OP_bitor:
			case OP_bitxor:
			{
				LOpcode mircode;
				switch (opcode) {
                    default:
					case OP_bitxor:     mircode = LIR_xor;  break;
					case OP_bitor:      mircode = LIR_or;   break;
					case OP_bitand:     mircode = LIR_and;  break;
					case OP_urshift:    mircode = LIR_ush;  break;
					case OP_rshift:     mircode = LIR_rsh;  break;
					case OP_lshift:     mircode = LIR_lsh;  break;
					case OP_multiply_i: mircode = LIR_mul; break;
					case OP_add_i:      mircode = LIR_add;  break;
					case OP_subtract_i: mircode = LIR_sub;  break;
				}
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = binaryIns(mircode, lhs, rhs);
				localSet(sp-1, out);
				break;
			}

			case OP_throw:
			{
				// flush it all out
				OP* value = loadAtomRep(op1);
				saveState();
				//throwAtom(*sp--);
				callIns(FUNCTIONID(throwAtom), 2,
					InsConst((uintptr)core), value);
				break;
			}

			case OP_getsuper:
			{
				// stack in: obj [ns [name]]
				// stack out: value
				// sp[0] = env->getsuper(sp[0], multiname)
				int objDisp = sp;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);

				OP* i3 = callIns(FUNCTIONID(getsuper), 3,
					env_param, obj, leaIns(0,multi));

				InsDealloc(multi);

				i3 = atomToNativeRep(result, i3);
				localSet(objDisp, i3);
				break;
			}

			case OP_setsuper:
			{
				// stack in: obj [ns [name]] value
				// stack out: nothing
				// core->setsuper(sp[-1], multiname, sp[0], env->vtable->base)
				int objDisp = sp-1;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);
				OP* value = loadAtomRep(sp);

				callIns(FUNCTIONID(setsuper), 4,
					env_param, obj, leaIns(0, multi), value);

				InsDealloc(multi);
				break;
			}

			case OP_nextname:
			case OP_nextvalue:
			{
				// sp[-1] = next[name|value](sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns((opcode == OP_nextname) ? FUNCTIONID(nextname) : FUNCTIONID(nextvalue), 3,
					env_param, obj, index);
				localSet(sp-1, atomToNativeRep(result, i1));
				break;
			}

			case OP_hasnext: 
			{
				// sp[-1] = hasnext(sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns(FUNCTIONID(hasnext), 3,
					env_param, obj, index);
				AvmAssert(result == INT_TYPE);
				localSet(sp-1, i1);
				break;
			}

			case OP_hasnext2: 
			{
                // fixme - if obj is already Atom, or index is already int,
                // easier to directly reference space in vars.
				OP* obj = InsAlloc(sizeof(Atom));
				OP* index = InsAlloc(sizeof(int));
				storeIns(loadAtomRep(op1), 0, obj);
				storeIns(localGet(op2), 0, index);
				OP* i1 = callIns(FUNCTIONID(hasnextproto), 3,
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
				//sp[0] = core->newfunction(env, body, _scopeBase, scopeDepth);
 				AbstractFunction* func = pool->getMethodInfo((uint32)op1);
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* envArg = env_param;
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(FUNCTIONID(newfunction), 4,
					envArg, InsConst((uintptr)func), outer, argv);

				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(op2, i3);
				break;
			}

			case OP_call:
			{
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

				OP* i3 = callIns(FUNCTIONID(op_call), 4, 
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_callproperty:
			case OP_callproplex:
			case OP_callpropvoid:
			{
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

				OP* out = callIns(FUNCTIONID(callproperty), 6,
					toplevel, base, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(baseDisp, atomToNativeRep(result, out));
				break;
			}

			case OP_constructprop:
			{
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
				OP* i3 = callIns(FUNCTIONID(constructprop), 5,
					toplevel, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_callsuper:
			case OP_callsupervoid:
			{
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
				OP* i3 = callIns(FUNCTIONID(callsuper), 4,
					env_param, leaIns(0, multi), InsConst(argc), atomv);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_construct:
 			{
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

				OP* i3 = callIns(FUNCTIONID(op_construct), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
 			}

			case OP_applytype:
			{
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

				OP* i3 = callIns(FUNCTIONID(op_applytype), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_newobject:
			{
 				// result = env->op_newobject(sp, argc)
 				int argc = int(op1);
 				int dest = sp - (2*argc-1);
				int arg0 = dest;

				// convert args to Atom for the call[]
				OP* ap = storeAtomArgs(2*argc, arg0);

				OP* i3 = callIns(FUNCTIONID(op_newobject), 3,
					env_param, leaIns(sizeof(Atom)*(2*argc-1), ap), InsConst(argc));
				InsDealloc(ap);

				localSet(dest, ptrToNativeRep(result, i3));
				break;
			}

			case OP_newactivation:
			{
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* envArg = env_param;
				OP* activationVTable = callIns(FUNCTIONID(getActivation), 1, envArg);
				OP* activation = callIns(FUNCTIONID(newActivation), 3, 
										 InsConst((uintptr)core), activationVTable, InsConst(0));

				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

			case OP_newcatch:
			{
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* activation = callIns(FUNCTIONID(newcatch), 2, 
										 env_param, InsConst((uintptr)result));

				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

 			case OP_newarray:
 			{
				// sp[-argc+1] = core->arrayClass->newarray(sp-argc+1, argc)
 				int argc = int(op1);
 				int arg0 = sp - 1*argc+1;

				// convert array elements to Atom[]
				OP* ap = storeAtomArgs(argc, arg0);
				OP* toplevel = loadToplevel(env_param);
				OP* arrayClass = loadIns(MIR_ldop, offsetof(Toplevel,arrayClass), toplevel);
				OP* i3 = callIns(FUNCTIONID(newarray), 3,
					arrayClass, leaIns(0,ap), InsConst(argc));
				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(arg0, i3);
				break;
 			}

			case OP_newclass:
			{
				// sp[0] = core->newclass(env, cinit, scopeBase, scopeDepth, base)
				sintptr cinit = op1;
				int localindex = int(op2);
				int extraScopes = state->scopeDepth;

				OP* envArg = env_param;
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* base = localGet(localindex);

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(FUNCTIONID(newclass), 5, 
					envArg, InsConst((sintptr)cinit), base, outer, argv);
				InsDealloc(ap);

				AvmAssert(!result->isMachineType);
				localSet(localindex, i3);
				break;
			}

			case OP_getdescendants:
			{
				// stack in: obj [ns [name]]
				// stack out: value
				//sp[0] = core->getdescendants(sp[0], name);
				int objDisp = sp;
				Multiname* multiname = (Multiname*) op1;

				OP* envArg = env_param;
				OP* out;
				OP* multi = initMultiname(multiname, objDisp);
				OP* obj = loadAtomRep(objDisp);
				AvmAssert(state->value(objDisp).notNull);

				out = callIns(FUNCTIONID(getdescendants), 3,
					envArg, obj, leaIns(0, multi));

				InsDealloc(multi);
				localSet(objDisp, atomToNativeRep(result, out));
				break;
			}

            case OP_checkfilter: {
				callIns(FUNCTIONID(checkfilter), 2,
					env_param, loadAtomRep(op1));
				break;
			}

			case OP_findpropstrict: 
			case OP_findproperty: 
			{
				// stack in: [ns [name]]
				// stack out: obj
				// sp[1] = env->findproperty(scopeBase, scopedepth, name, strict)
				int dest = sp;
				OP* multi = initMultiname((Multiname*)op1, dest);
				dest++;
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* envArg = env_param;
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv,vtable), envArg);
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

				OP* i3 = callIns(FUNCTIONID(findproperty), 7, 
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
					out = callIns(FUNCTIONID(finddefNsset), 3,
						env_param,
						InsConst((uintptr)multiname->getNsset()),
						name);
				}
				else
				{
					out = callIns(FUNCTIONID(finddefNs), 3,
						env_param,
						InsConst((uintptr)multiname->getNamespace()),
						name);
				}
				localSet(dest, ptrToNativeRep(result, out));
				break;
			}

			case OP_getproperty:
			{
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
						value = callIns((objType==ARRAY_TYPE ? 
										FUNCTIONID(ArrayObject_getIntProperty) :
										FUNCTIONID(ObjectVectorObject_getIntProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE)
					{
						if( result == INT_TYPE || result == UINT_TYPE)
						{
							value = callIns((objType==VECTORINT_TYPE ? 
													FUNCTIONID(IntVectorObject_getNativeIntProperty) :
													FUNCTIONID(UIntVectorObject_getNativeIntProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns((objType==VECTORINT_TYPE ? 
													FUNCTIONID(IntVectorObject_getIntProperty) :
													FUNCTIONID(UIntVectorObject_getIntProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )
						{
							value = callIns(FUNCTIONID(DoubleVectorObject_getNativeIntProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(FUNCTIONID(DoubleVectorObject_getIntProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(FUNCTIONID(getpropertylate_i), 3,
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
						value = callIns((objType==ARRAY_TYPE ? 
												FUNCTIONID(ArrayObject_getUintProperty) :
												FUNCTIONID(ObjectVectorObject_getUintProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( result == INT_TYPE || result == UINT_TYPE )
						{
							value = callIns((objType==VECTORINT_TYPE ?
													FUNCTIONID(IntVectorObject_getNativeUintProperty) :
													FUNCTIONID(UIntVectorObject_getNativeUintProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns((objType==VECTORINT_TYPE ?
													FUNCTIONID(IntVectorObject_getUintProperty) : 
													FUNCTIONID(UIntVectorObject_getUintProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )//|| result == UINT_TYPE)
						{
							value = callIns(FUNCTIONID(DoubleVectorObject_getNativeUintProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(FUNCTIONID(DoubleVectorObject_getUintProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(FUNCTIONID(getpropertylate_u), 3,
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

					OP* value = callIns(FUNCTIONID(getpropertyHelper), 5,
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
					OP* value = callIns(FUNCTIONID(getproperty), 4,
										toplevel, obj, leaIns(0, multi), vtable);

					InsDealloc(multi);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_initproperty:
			case OP_setproperty:
			{
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
						callIns((objType==ARRAY_TYPE ? 
										FUNCTIONID(ArrayObject_setIntProperty) :
										FUNCTIONID(ObjectVectorObject_setIntProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns((objType==VECTORINT_TYPE ? 
											FUNCTIONID(IntVectorObject_setNativeIntProperty) :
											FUNCTIONID(UIntVectorObject_setNativeIntProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns((objType==VECTORINT_TYPE ? 
											FUNCTIONID(IntVectorObject_setNativeIntProperty) :
											FUNCTIONID(UIntVectorObject_setNativeIntProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns((objType==VECTORINT_TYPE ? 
													FUNCTIONID(IntVectorObject_setIntProperty) :
													FUNCTIONID(UIntVectorObject_setIntProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGetq(sp);
							callIns(FUNCTIONID(DoubleVectorObject_setNativeIntProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(FUNCTIONID(DoubleVectorObject_setIntProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(FUNCTIONID(setpropertylate_i), 4,
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
						callIns((objType==ARRAY_TYPE ? 
										FUNCTIONID(ArrayObject_setUintProperty) :
										FUNCTIONID(ObjectVectorObject_setUintProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns((objType==VECTORINT_TYPE ? 
											FUNCTIONID(IntVectorObject_setNativeUintProperty) :
											FUNCTIONID(UIntVectorObject_setNativeUintProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns((objType==VECTORINT_TYPE ? 
											FUNCTIONID(IntVectorObject_setNativeUintProperty) :
											FUNCTIONID(UIntVectorObject_setNativeUintProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns((objType==VECTORINT_TYPE ? 
													FUNCTIONID(IntVectorObject_setUintProperty) :
													FUNCTIONID(UIntVectorObject_setUintProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGetq(sp);
							callIns(FUNCTIONID(DoubleVectorObject_setNativeUintProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(FUNCTIONID(DoubleVectorObject_setUintProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(FUNCTIONID(setpropertylate_u), 4,
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
					OP* envarg = env_param;

					// copy the compile-time namespace to the temp multiname
					OP* mSpace = InsConst((uintptr)multiname->ns);
					storeIns(mSpace, offsetof(Multiname, ns), _tempname);

					OP *multi = leaIns(0, _tempname);

					uint32_t func = opcode==OP_setproperty ? FUNCTIONID(setpropertyHelper) :
														FUNCTIONID(initpropertyHelper);
					callIns(func, 6,
							envarg, obj, multi, value, vtable, index);

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
					OP* envarg = env_param;

					if (OP_setproperty)
					{
						OP* toplevel = loadToplevel(envarg);
						callIns(FUNCTIONID(setproperty), 5,
										toplevel, obj, leaIns(0, multi), value, vtable);
					}
					else
					{
						callIns(FUNCTIONID(initproperty), 5,
							envarg, obj, leaIns(0, multi), value, vtable);
					}

					InsDealloc(multi);
				}
				break;
			}

			case OP_deleteproperty:
			{
				// stack in: obj [ns] [name]
				// stack out: Boolean
				//sp[0] = delproperty(sp[0], multiname);
				int objDisp = sp;
				Multiname *multiname = (Multiname*)op1;
				if(!multiname->isRtname()) {
					OP* multi = initMultiname(multiname, objDisp, true);

					OP* obj = loadAtomRep(objDisp);
					
					OP* i3 = callIns(FUNCTIONID(delproperty), 3,
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
						OP* internNs = callIns(FUNCTIONID(internRtns), 2,
							env_param, nsAtom);

						storeIns(internNs, offsetof(Multiname,ns), _tempname);
					}

					AvmAssert(state->value(objDisp).notNull);
					OP* obj = loadAtomRep(objDisp);

					OP *multi = leaIns(0, _tempname);

					OP* value = callIns(FUNCTIONID(delpropertyHelper), 4,
									    env_param, obj, multi, index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_convert_s:
			{
				localSet(op1, callIns(FUNCTIONID(string), 2,
					InsConst((uintptr)core), loadAtomRep(op1)));
				break;
			}

			case OP_esc_xelem: // ToXMLString will call EscapeElementValue
			{
				//sp[0] = core->ToXMLString(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(FUNCTIONID(ToXMLString), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_esc_xattr:
			{
				//sp[0] = core->EscapeAttributeValue(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(FUNCTIONID(EscapeAttributeValue), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_astype:
			{
				// sp[0] = core->astype(sp[0], traits)
				OP* obj = loadAtomRep(op2);
				OP* i1 = callIns(FUNCTIONID(astype), 3,
					env_param,
					obj,
					InsConst(op1)); // traits

				i1 = atomToNativeRep(result, i1);
				localSet(op2, i1);
				break;
			}

			case OP_astypelate:
			{
				//sp[-1] = astype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* envarg = env_param;
				OP* itraits = callIns(FUNCTIONID(toClassITraits), 2,
					envarg, type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(FUNCTIONID(astype), 3,
					envarg, obj, itraits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}


			case OP_add:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(env_param);
				OP* out = callIns(FUNCTIONID(add2), 3,
					toplevel, lhs, rhs);
				localSet(sp-1, atomToNativeRep(result, out));
				break;
			}

			case OP_concat:
			{
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = callIns(FUNCTIONID(concatStrings), 3,
					InsConst((uintptr)core), lhs, rhs);
				localSet(sp-1,	out);
				break;
			}

			case OP_strictequals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpEq(FUNCTIONID(stricteq), sp-1, sp));
				break;
			}

			case OP_equals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpEq(FUNCTIONID(equals), sp-1, sp));
				break;
			}

			case OP_lessthan:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpLt(sp-1, sp));
				break;
			}

			case OP_lessequals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpLe(sp-1, sp));
				break;
			}

			case OP_greaterthan:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpLt(sp, sp-1));
				break;
			}

			case OP_greaterequals: 
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, cmpLe(sp, sp-1));
				break;
			}

			case OP_instanceof:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(env_param);
				OP* out = callIns(FUNCTIONID(instanceof), 3,
					toplevel, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1,	out);
				break;
			}

			case OP_in:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* out = callIns(FUNCTIONID(in), 3,
					env_param, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1, out);
				break;
			}

			case OP_istype:
			{			
				// expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				//sp[0] = istype(sp[0], itraits);
				OP* obj = loadAtomRep(op2);
				OP* itraits = InsConst(op1);
				OP* out = callIns(FUNCTIONID(istypeAtom), 3,
					InsConst((uintptr)core), obj, itraits);
				out = atomToNativeRep(result, out);
				localSet(op2, out);
				break;
			}

			case OP_istypelate:
			{
				//sp[-1] = istype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* traits = callIns(FUNCTIONID(toClassITraits), 2,
					env_param, type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(FUNCTIONID(istypeAtom), 3,
					InsConst((uintptr)core), obj, traits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}

			case OP_dxns:
			{
				OP* uri = InsConst(op1); // uri
				OP* ns = callIns(FUNCTIONID(newPublicNamespace), 
					2, 
					InsConst((uintptr)core), 
					uri);
				storeIns(ns, 0, dxns);
				break;
			}

			case OP_dxnslate:
			{
				OP* atom = loadAtomRep(op1);				
				OP* uri = callIns(FUNCTIONID(intern), 2,
					InsConst((uintptr)core), atom);
				OP* ns = callIns(FUNCTIONID(newPublicNamespace), 
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
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(FUNCTIONID(debugFile), 2,
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
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(FUNCTIONID(debugLine), 2,
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

	} // emit()

	void CodegenLIR::emitIf(FrameState *state, AbcOpcode opcode, sintptr target, int a, int b)
	{
		this->state = state;

#ifdef DEBUGGER
		if(core->sampling() && target < state->pc)
		{
			emitSampleCheck();
		}
#endif

		// 
		// compile instructions that cannot throw exceptions before we add exception handling logic
		//

		// op1 = abc opcode target
		// op2 = what local var contains condition

		// spill all, dont include cond since it gets consumed
		// UBER IMPORTANT we need to spill prior to compare since
		// mir MD generations needs compare and branch to be adjacent.
		OP* cond;
		LOpcode br;
		
		switch (opcode)
		{
		case OP_iftrue:
			br = LIR_jf;
			cond = binaryIns(LIR_eq, localGet(a), InsConst(0));
			break;
		case OP_iffalse:
			br = LIR_jt;
			cond = binaryIns(LIR_eq, localGet(a), InsConst(0));
			break;
		case OP_iflt:
			br = LIR_jt;
			cond = cmpLt(a, b);
			break;
		case OP_ifnlt:
			br = LIR_jf;
			cond = cmpLt(a, b);
			break;
		case OP_ifle:
			br = LIR_jt;
			cond = cmpLe(a, b);
			break;
		case OP_ifnle:
			br = LIR_jf;
			cond = cmpLe(a, b);
			break;
		case OP_ifgt:  // a>b === b<a
			br = LIR_jt;
			cond = cmpLt(b, a);
			break;
		case OP_ifngt: // !(a>b) === !(b<a)
			br = LIR_jf;
			cond = cmpLt(b, a);
			break;
		case OP_ifge:  // a>=b === b<=a
			br = LIR_jt;
			cond = cmpLe(b, a);
			break;
		case OP_ifnge: // !(a>=b) === !(a<=b)
			br = LIR_jf;
			cond = cmpLe(b, a);
			break;
		case OP_ifeq:
			br = LIR_jt;
			cond = cmpEq(FUNCTIONID(equals), a, b);
			break;
		case OP_ifne:
			br = LIR_jf;
			cond = cmpEq(FUNCTIONID(equals), a, b);
			break;
		case OP_ifstricteq:
			br = LIR_jt;
			cond = cmpEq(FUNCTIONID(stricteq), a, b);
			break;
		case OP_ifstrictne:
			br = LIR_jf;
			cond = cmpEq(FUNCTIONID(stricteq), a, b);
			break;
		default:
			AvmAssert(false);
			return;
		}

        if (cond->isconst()) {
            if (br == LIR_jt && cond->constval() || br == LIR_jf && !cond->constval()) {
                // taken
                br = LIR_j;
                cond = 0;
            }
            else {
                // not taken = no-op
                return;
            }
        }

		saveState();
        patchLater(branchIns(br, cond), target);
	} // emitIf()

	OP* CodegenLIR::i2dIns(OP* v)
	{
		#ifdef AVMPLUS_ARM
		return callIns(FUNCTIONID(i2d), 1, v);
		#else
		return Ins(LIR_i2f, v);
		#endif
	}

	OP* CodegenLIR::u2dIns(OP* v)
	{
		#ifdef AVMPLUS_ARM
		return callIns(FUNCTIONID(u2d), 1, v);
		#else
		return Ins(LIR_u2f, v);
		#endif
	}
	
	// Faster compares for ints, uint, doubles
	OP* CodegenLIR::cmpOptimization(int lhsi, int rhsi, LOpcode icmp, LOpcode ucmp, LOpcode fcmp)
	{
		Traits* lht = state->value(lhsi).traits;
		Traits* rht = state->value(rhsi).traits;

		if (lht == rht && lht == INT_TYPE)
		{
			OP* lhs = localGet(lhsi);
			OP* rhs = localGet(rhsi);
			return binaryIns(icmp, lhs, rhs);
		}
		else if (lht == rht && lht == UINT_TYPE)
		{
			OP* lhs = localGet(lhsi);
			OP* rhs = localGet(rhsi);
			return binaryIns(ucmp, lhs, rhs);
		}
		else if (lht && lht->isNumeric && rht && rht->isNumeric)
		{
			// If we're comparing a uint to an int and the int is a non-negative
			// integer constant, don't promote to doubles for the compare
			if ((lht == UINT_TYPE) && (rht == INT_TYPE))
			{
				OP* lhs = localGet(lhsi);
				OP* rhs = localGet(rhsi);
				#ifdef AVMPLUS_AMD64
				// 32-bit signed and unsigned values fit in our 64-bit registers
				// so we can simply do a signed compare with mixed int/uint types
				return binaryIns(MIR_lt, lhs, rhs);
				#else
				if (rhs->isconst() && rhs->constval() >= 0)
				{
					return binaryIns(ucmp, lhs, rhs);
				}
				#endif
			}
			else if ((lht == INT_TYPE) && (rht == UINT_TYPE))
			{
				OP* lhs = localGet(lhsi);
				OP* rhs = localGet(rhsi);
				#ifdef AVMPLUS_AMD64
				// 32-bit signed and unsigned values fit in our 64-bit registers
				// so we can simply do a signed compare with mixed int/uint types
				return binaryIns(MIR_icmp, lhs, rhs);
				#else
				if (lhs->isconst() && lhs->constval() >= 0)
				{
					return binaryIns(ucmp, lhs, rhs);
				}
				#endif
			}

			OP* lhs = promoteNumberIns(lht, lhsi);
			OP* rhs = promoteNumberIns(rht, rhsi);
			return binaryIns(fcmp, lhs, rhs);
		}

		return NULL;
	}	

	// set cc's for < operator
	OP* CodegenLIR::cmpLt(int lhsi, int rhsi)
	{
		OP *result = cmpOptimization (lhsi, rhsi, LIR_lt, LIR_ult, LIR_flt);
		if (result)
			return result;

		AvmAssert(trueAtom == 13);
		AvmAssert(falseAtom == 5);
		AvmAssert(undefinedAtom == 4);
		OP* lhs = loadAtomRep(lhsi);
		OP* rhs = loadAtomRep(rhsi);
		OP* atom = callIns(FUNCTIONID(compare), 3,
			InsConst((uintptr)core), lhs, rhs);

		// caller will use jt for (a<b) and jf for !(a<b)
		// compare          ^8    <8 
		// true       1101  0101   y 
		// false      0101  1101   n 
		// undefined  0100  1100   n 

		OP* c = InsConst(8);
		return binaryIns(LIR_lt, binaryIns(LIR_xor, atom, c), c);
	}

	OP* CodegenLIR::cmpLe(int lhsi, int rhsi)
	{
		OP *result = cmpOptimization (lhsi, rhsi, LIR_le, LIR_ule, LIR_fle);
		if (result)
			return result;

		OP* lhs = loadAtomRep(lhsi);
		OP* rhs = loadAtomRep(rhsi);
		OP* atom = callIns(FUNCTIONID(compare), 3,
			InsConst((uintptr)core), rhs, lhs);

		// assume caller will use jt for (a<=b) and jf for !(a<=b)
		// compare          ^1    <=4
		// true       1101  1100  n
		// false      0101  0100  y
		// undefined  0100  0101  n

		OP* c2 = InsConst(1);
		OP* c4 = InsConst(4);
		return binaryIns(LIR_le, binaryIns(LIR_xor, atom, c2), c4);
	}

	LIns* CodegenLIR::cmpEq(uint32_t fid, int lhsi, int rhsi)
	{
		LIns *result = cmpOptimization (lhsi, rhsi, LIR_eq, LIR_eq, LIR_feq);
		if (result) {
			return result;
		}

		Traits* lht = state->value(lhsi).traits;
		Traits* rht = state->value(rhsi).traits;
		
		// If we have null and a type that is derived from an Object (but not Object or XML)
		// we can optimize our equal comparison down to a simple ptr comparison. This also
		// works when both types are derived Object types.
		if (((lht == NULL_TYPE) && (rht && !rht->notDerivedObjectOrXML)) || 
			((rht == NULL_TYPE) && (lht && !lht->notDerivedObjectOrXML)) ||
			((rht && !rht->notDerivedObjectOrXML) && (lht && !lht->notDerivedObjectOrXML)))
		{
			LIns* lhs = localGet(lhsi);
			LIns* rhs = localGet(rhsi);
			result = binaryIns(LIR_eq, lhs, rhs);
		}
		else
		{
			LIns* lhs = loadAtomRep(lhsi);
			LIns* rhs = loadAtomRep(rhsi);
			LIns* out = callIns(fid, 3, InsConst((uintptr)core), lhs, rhs);
			result = binaryIns(LIR_eq, out, InsConst(trueAtom));
		}
		return result;
	}

	void CodegenLIR::epilogue(FrameState *state)
	{
		this->state = state;

#ifdef AVMPLUS_SPARC
		if(beginCatch_start && beginCatch_end) {
			beginCatch_end->lastUse = ip;
			for (OP* temp_ip = beginCatch_start; temp_ip <= beginCatch_end; temp_ip++) {
				switch(temp_ip->code) {
				case MIR_cs:
				case MIR_cm:
				case MIR_ld:
				case MIR_lea:
					temp_ip->lastUse = ip;
				}
			}
		}
#endif

		if (info->setsDxns()) {
			InsDealloc(dxns);
		}

		// exceptions dealloc
		if (info->exceptions)
		{
			InsDealloc(_ef);
			InsDealloc(_save_eip);
		}

		#ifdef DEBUGGER
		InsDealloc(varPtrs);
		InsDealloc(varTraits);
		InsDealloc(csn);
		#endif

        if (npe_label.preds) {
            LIns *label = Ins(LIR_label);
            label->setimm24(state->verifier->frameSize * 8);
			mirLabel(npe_label, label);
			callIns(FUNCTIONID(npe), 1, env_param);
		}

        if (interrupt_label.preds) {
            LIns *label = Ins(LIR_label);
            label->setimm24(state->verifier->frameSize * 8);
			mirLabel(interrupt_label, label);
			callIns(FUNCTIONID(interrupt), 1, env_param);
		}

        // extend live range of critical stuff
        // fixme -- this should be automatic based on live analysis
        lirout->ins1(LIR_live, env_param);
        lirout->ins1(LIR_live, vars);

        // one last label, to make sure it's the first thing we see in reverse
        LIns *end = lirout->ins0(LIR_label);
        end->setimm24(state->verifier->frameSize * 8);

		// bail if no room in the buffer.  
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return;
#endif /* FEATURE_BUFFER_GUARD */

		if (info->exceptions)
		{
			for (int i=0, n=info->exceptions->exception_count; i < n; i++)
			{
				ExceptionHandler* h = &info->exceptions->exceptions[i]; (void)h;
				AvmAssertMsg(state->verifier->getFrameState(h->target)->label.bb != NULL, "Exception target address MUST have been resolved");
				//mirPatchPtr( (OP**)&h->target, h->target );
			}
		}

        for (int i=0, n=patches.size(); i < n; i++) {
            Patch p = patches[i];
            AvmAssert(p.label->bb != 0);
            p.br->target(p.label->bb);
        }

        frag->lastIns = lirbuf->next()-1;
	}

	OP* CodegenLIR::initMultiname(Multiname* multiname, int& csp, bool isDelete /*=false*/)
	{
#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	init multiname\n";
#endif
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
			OP* internNs = callIns(FUNCTIONID(internRtns), 2,
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
				callIns(FUNCTIONID(initMultinameLateForDelete), 3,
						env_param,
						leaIns(0, _tempname),
						nameAtom);
			}
			else
			{
				callIns(FUNCTIONID(initMultinameLate), 3,
						InsConst((uintptr)core),
						leaIns(0, _tempname),
						nameAtom);
			}				
		}

		return _tempname;
	}

	OP* CodegenLIR::loadToplevel(OP* env)
	{
		OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env);
		return loadIns(MIR_ldop, offsetof(VTable, toplevel), vtable);
	}

	OP* CodegenLIR::loadVTable(int i)
	{
		AvmAssert(state->value(i).notNull);
		Traits* t = state->value(i).traits;

		if (t && !t->isMachineType && t != STRING_TYPE && t != NAMESPACE_TYPE && t != NULL_TYPE)
		{
			// must be a pointer to a scriptobject, and we've done the n
			// all other types are ScriptObject, and we've done the null check
			return loadIns(MIR_ldop, offsetof(ScriptObject, vtable), localGet(i));
		}

		OP* toplevel = loadToplevel(env_param);

		int offset;
		if (t == NAMESPACE_TYPE)	offset = offsetof(Toplevel, namespaceClass);
		else if (t == STRING_TYPE)	offset = offsetof(Toplevel, stringClass);
		else if (t == BOOLEAN_TYPE)	offset = offsetof(Toplevel, booleanClass);
		else if (t == NUMBER_TYPE)	offset = offsetof(Toplevel, numberClass);
		else if (t == INT_TYPE)		offset = offsetof(Toplevel, intClass);
		else if (t == UINT_TYPE)	offset = offsetof(Toplevel, uintClass);
		else 
		{
			// *, Object or Void
			OP* obj = loadAtomRep(i);
			return callIns(FUNCTIONID(toVTable), 2, toplevel, obj);
		}

		// now offset != -1 and we are returning a primitive vtable

		OP* cc = loadIns(MIR_ldop, offset, toplevel);
		OP* cvtable = loadIns(MIR_ldop, offsetof(ClassClosure, vtable), cc);
		return loadIns(MIR_ldop, offsetof(VTable, ivtable), cvtable);
	}

	OP* CodegenLIR::promoteNumberIns(Traits* t, int i)
	{
		if (t == NUMBER_TYPE)
		{
			return localGetq(i);
		}
		if (t == INT_TYPE || t == BOOLEAN_TYPE)
		{
			return i2dIns(localGet(i));
		}
		if (t == UINT_TYPE)
		{
#ifdef AVMPLUS_IA32
			if (core->config.sse2)
			{
				// Faster to emit this:
				// sub eax,0x80000000
				// cvtsi2sd xmm0,eax
				// addsd xmm0, 2147483648.0
				OP *op1 = binaryIns(LIR_sub, localGet(i), InsConst(0x80000000));
				OP *op2 = i2dIns(op1);
				static const double k_NEGONE = 2147483648.0;
				return Ins(MIR_faddi, op2, (uintptr) &k_NEGONE);
			}
			else
#endif // AVMPLUS_IA32
			return u2dIns(localGet(i));
		}
		AvmAssert(false);
		return NULL;
	}

#ifdef AVMPLUS_VERBOSE

	void CodegenLIR::formatOperand(PrintWriter& buffer, LIns* opr)
	{
        if (opr) {
            if (opr->isStore() && opr->oprnd2() == vars) {
                opr = opr->oprnd1(); // show the value stored
            }
			buffer.format("@%s", lirbuf->names->formatRef(opr));
        }
        else {
			buffer << "0";
        }
	}

#endif /* AVMPLUS_VERBOSE */

	bool CodegenLIR::isCodeContextChanged() const
	{
		return pool->domain->base != NULL;
	}

	/* set position of label */
	void CodegenLIR::mirLabel(CodegenLabel& l, OP* bb) {
        AvmAssert(bb->isop(LIR_label));
        AvmAssert(l.bb == 0);
        l.bb = bb;
    }

#ifdef DEBUGGER
	void CodegenLIR::emitSampleCheck()
	{
		/* @todo  inlined sample check doesn't work, help! 
			OP* takeSample = loadIns(MIR_ld, (int)&core->takeSample, NULL);
			OP* br = Ins(MIR_jeq, binaryIns(MIR_ucmp, takeSample, InsConst(0)));
			callIns(FUNCTIONID(sample), 1, InsConst((int32)core));
			br->target = Ins(LIR_label);
		*/
		callIns(FUNCTIONID(sampleCheck), 1, InsConst((uintptr)core));
	}
#endif

#ifdef AVMPLUS_VERBOSE
	bool CodegenLIR::verbose() 
	{
		return state && state->verifier->verbose || pool->verbose;
	}
#endif

    LIns *CodegenLIR::branchIns(LOpcode op, LIns *cond, LIns *target) {
        if (cond) {
            if (!cond->isCmp()) {
                // branching on a non-condition expression, so test (v==0)
                // and invert the sense of the branch.
                cond = lirout->ins_eq0(cond);
                op = LOpcode(op ^ 1);
            }
            if (cond->isconst()) {
                if (op == LIR_jt && cond->constval() || op == LIR_jf && !cond->constval()) {
                    // taken
                    op = LIR_j;
                    cond = 0;
                }
                else {
                    // not taken - no code to emit.
                    // fixme - but what to return? caller wants to patch something.
                    AvmAssert(false);
                }
            }
        }
        return lirout->insBranch(op, cond, target);
    }

    LIns *CodegenLIR::Ins(LOpcode code) {
        return lirout->ins0(code);
    }

	/* patch the location 'where' with the value of the label */
	void CodegenLIR::patchLater(OP* br, intptr_t pc)	{
        patchLater(br, state->verifier->getFrameState(pc)->label);
	}

    void CodegenLIR::patchLater(LIns *br, CodegenLabel &l) {
        l.preds++;
        if (l.bb != 0) {
            br->target(l.bb);
        } else {
            patches.add(Patch(br, l));
        }
    }

    LIns* CodegenLIR::InsConst(int32_t c) {
        return lirout->insImm(c);
    }

    LIns* CodegenLIR::InsAlloc(int32_t size) {
        //fixme - why InsAlloc(0)?
        return lirout->insAlloc(size >= 4 ? size : 4);
    }

    LIns* CodegenLIR::loadIns(MirOpcode code, int32_t disp, LIns *base) {
        LOpcode op;
        switch (code) {
            case MIR_ld: op = LIR_ld; break;
            case MIR_ldop: op = LIR_ldc; break;
            case MIR_fld: op = LIR_ldq; break;
            case MIR_fldop: op = LIR_ldq; break; // fixme: need cse version
            default:
                AvmAssert(false);
                return 0;
        }
        return lirout->insLoad(op, base, disp);
    }

    void CodegenLIR::markDead(LIns*) 
    {}

    PageMgr::PageMgr() : frago(0)
    {}

    PageMgr::~PageMgr() {
        frago->clearFrags();
    }

#ifdef _DEBUG
    class ValidateReader: public LirFilter {
    public:
        ValidateReader(LirFilter *in) : LirFilter(in)
        {}

        LIns* read() {
            LIns *i = in->read();
            if (i) {
                switch (i->opcode()) {
                case LIR_jt:
                case LIR_jf:
                case LIR_j: 
                    AvmAssert(*i->targetAddr() != 0 && *i->targetAddr() == i->oprnd2() && i->oprnd2()->isop(LIR_label));
                    break;
                }
            }
            return i;
        }
    };
#endif

    static int loopcount=0;
    static int normalcount=0;

    void CodegenLIR::emitMD() 
    {
#ifdef PERFM
		uint64_t start = rtstamp();
#endif /* PERFM */
        debug_only(
            LirReader reader(lirbuf);
            ValidateReader validator(&reader);
            while (validator.read())
            {}
        )

        verbose_only(if (verbose()) {
            live(gc, lirbuf);
        })

        Fragmento *frago = pool->codePages->frago;
        Assembler *assm = frago->assm();

		verbose_only( StringList asmOutput(gc); )
		verbose_only( assm->_outputCache = &asmOutput; )

        RegAllocMap regMap(gc);
        NInsList loopJumps(gc);
        assm->hasLoop = false;
        assm->beginAssembly(&regMap);
        assm->assemble(frag, loopJumps);
        assm->endAssembly(frag, loopJumps);
#ifdef PERFM
		uint64_t stop = rtstamp();
#endif /* PERFM */
		
		verbose_only(
            assm->_outputCache = 0;
            for (int i=asmOutput.size()-1; i>=0; --i) {
                assm->outputf("%s",asmOutput.get(i)); 
            }
        );

#ifdef PERFM
		const int mhz = 100;
		double time = (stop-start)/(100.0*mhz);
		_nvprof("compile", time);
		_nvprof("lir bytes", lirbuf->byteCount());
		_nvprof("lir", lirbuf->insCount());		
		_nvprof("IR/tick", lirbuf->insCount()/time);		
#endif /* PERFM */
		
        frag->releaseLirBuffer();

        assm->hasLoop ? loopcount++ : normalcount++;
        //_nvprof("assm->error", assm->error());
        //_nvprof("hasExceptions", info->hasExceptions());
        //_nvprof("hasLoop", assm->hasLoop);

        bool keep = (!assm->hasLoop /*&& normalcount <= 0*/ || assm->hasLoop /*&& loopcount <= 0*/) 
            && !info->hasExceptions() && !assm->error();

        //_nvprof("keep",keep);
        if (keep) {
            // save pointer to generated code
            union {
                Atom (*fp)(MethodEnv*, int, uint32_t*);
                void *vp;
            } u;
            u.vp = frag->code();
            info->impl32 = u.fp;
            verbose_only(if (verbose()) {
                if (assm->hasLoop) {
                    printf("keeping loopy code %d\n", loopcount);
                } else {
                    printf("keeping plain code %d\n", normalcount);
                }
            })
        } else {
            // assm puked, or we did something untested, so interpret.
            // fixme: need to remove this frag from Fragmento and free everything.
            frag->releaseCode(frago);
            overflow = true;
            verbose_only(if (verbose()) {
                printf("reverting to interpreter\n");
            })
        }
    }
}

namespace nanojit
{
    int StackFilter::getTop(LIns* i) {
        if (i->isBranch()) {
            return i->oprnd2()->imm24();
        }
        else if (i->isop(LIR_label)) {
            return i->imm24();
        }
        else {
            AvmAssert(false);
            return 0x7fffffff; // highest top possible = most conservative
        }
    }

    #ifdef NJ_VERBOSE
    void LirNameMap::formatGuard(LIns*, char*) {
        AvmAssert(false);
    }
    #endif

    void Assembler::asm_bailout(LIns*, Register) {
        AvmAssert(false);
    }

    void Assembler::initGuardRecord(LIns*, GuardRecord*) {
        AvmAssert(false);
    }
}
