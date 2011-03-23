/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

#ifdef VMCFG_NANOJIT

#include "CodegenLIR.h"

#if defined(WIN32) && defined(AVMPLUS_ARM)
#include <cmnintrin.h>
#endif

#ifdef VMCFG_VTUNE
namespace vtune {
    using namespace avmplus;
    void* vtuneInit(String*);
    void vtuneCleanup(void*);
}
using namespace vtune;
#endif // VMCFG_VTUNE

// Sparc, ARM and SH4 have buggy LIR_d2i support (bug 613189)
#if (defined(NANOJIT_SPARC) || defined(NANOJIT_SH4) || defined(NANOJIT_ARM))
# undef NJ_F2I_SUPPORTED
# define NJ_F2I_SUPPORTED 0
#endif

#ifdef _MSC_VER
    #if !defined (AVMPLUS_ARM)
    extern "C"
    {
        int __cdecl _setjmp3(jmp_buf jmpbuf, int arg);
    }
    #else
    #include <setjmp.h>
    #undef setjmp
    extern "C"
    {
        int __cdecl setjmp(jmp_buf jmpbuf);
    }
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
return foo[0];
#endif

#elif defined __GNUC__
#define RETURN_METHOD_PTR(_class, _method) \
union { \
    int (_class::*bar)(); \
    intptr_t foo; \
}; \
bar = _method; \
return foo;
#else
#define RETURN_METHOD_PTR(_class, _method) \
return *((intptr_t*)&_method);
#endif

#ifdef PERFM
#define DOPROF
#endif /* PERFM */

//#define DOPROF
#include "../vprof/vprof.h"

// Profiling generated code.

#ifdef DOPROF
#define JIT_EVENT(id) \
    do { \
        static void* id; \
        _jnvprof_init(&id, #id, NULL); \
        callIns(FUNCTIONID(jitProfileEvent), 1, InsConstPtr(id)); \
    } while (0)
#define JIT_VALUE(id, val) \
    do { \
        static void* id; \
        _jnvprof_init(&id, #id, NULL); \
        callIns(FUNCTIONID(jitProfileValue32), 2, InsConstPtr(id), val); \
    } while (0)
#define JIT_TAGVAL(id, val) \
    do { \
        static void* id; \
        _jnhprof_init(&id, #id, 8, 1, 2, 3, 4, 5, 6, 7, 8); \
        LIns* jit_tagval_tag = p2i(andp((val), 7)); \
        callIns(FUNCTIONID(jitProfileHist32), 2, InsConstPtr(id), jit_tagval_tag); \
    } while (0)
#else
#define JIT_EVENT(id)       do { } while (0)
#define JIT_VALUE(id, val)  do { } while (0)
#define JIT_TAGVAL(id, val) do { } while (0)
#endif

#ifdef AVMPLUS_64BIT
#define PTR_SCALE 3
#else
#define PTR_SCALE 2
#endif

#define IS_ALIGNED(x, size) ((uintptr_t(x) & ((size)-1)) == 0)

namespace avmplus
{
        #define COREADDR(f) coreAddr((int (AvmCore::*)())(&f))
        #define GCADDR(f) gcAddr((int (MMgc::GC::*)())(&f))
        #define ENVADDR(f) envAddr((int (MethodEnv::*)())(&f))
        #define ARRAYADDR(f) arrayAddr((int (ArrayObject::*)())(&f))
        #define STRINGADDR(f) stringAddr((int (String::*)())(&f))
        #define VECTORINTADDR(f) vectorIntAddr((int (IntVectorObject::*)())(&f))
        #define VECTORUINTADDR(f) vectorUIntAddr((int (UIntVectorObject::*)())(&f))
        #define VECTORDOUBLEADDR(f) vectorDoubleAddr((int (DoubleVectorObject::*)())(&f))
        #define VECTOROBJADDR(f) vectorObjAddr((int (ObjectVectorObject::*)())(&f))
        #define EFADDR(f)   efAddr((int (ExceptionFrame::*)())(&f))
        #define DEBUGGERADDR(f)   debuggerAddr((int (Debugger::*)())(&f))
        #define FUNCADDR(addr) (uintptr_t)addr

        intptr_t coreAddr( int (AvmCore::*f)() )
        {
            RETURN_METHOD_PTR(AvmCore, f);
        }

        intptr_t  gcAddr( int (MMgc::GC::*f)() )
        {
            RETURN_METHOD_PTR(MMgc::GC, f);
        }

        intptr_t  envAddr( int (MethodEnv::*f)() )
        {
            RETURN_METHOD_PTR(MethodEnv, f);
        }

    #ifdef DEBUGGER
        intptr_t  debuggerAddr( int (Debugger::*f)() )
        {
            RETURN_METHOD_PTR(Debugger, f);
        }
    #endif /* DEBUGGER */

        intptr_t  arrayAddr(int (ArrayObject::*f)())
        {
            RETURN_METHOD_PTR(ArrayObject, f);
        }

        intptr_t  stringAddr(int (String::*f)())
        {
            RETURN_METHOD_PTR(String, f);
        }

        intptr_t vectorIntAddr(int (IntVectorObject::*f)())
        {
            RETURN_METHOD_PTR(IntVectorObject, f);
        }

        intptr_t vectorUIntAddr(int (UIntVectorObject::*f)())
        {
            RETURN_METHOD_PTR(UIntVectorObject, f);
        }

        intptr_t vectorDoubleAddr(int (DoubleVectorObject::*f)())
        {
            RETURN_METHOD_PTR(DoubleVectorObject, f);
        }

        intptr_t vectorObjAddr(int (ObjectVectorObject::*f)())
        {
            RETURN_METHOD_PTR(ObjectVectorObject, f);
        }
        intptr_t efAddr( int (ExceptionFrame::*f)() )
        {
            RETURN_METHOD_PTR(ExceptionFrame, f);
        }

    using namespace MMgc;
    using namespace nanojit;

    #if defined _MSC_VER && !defined AVMPLUS_ARM
    #  define SETJMP ((uintptr_t)_setjmp3)
    #elif defined AVMPLUS_MAC_CARBON
    #  define SETJMP setjmpAddress
    #else
    #  define SETJMP ((uintptr_t)VMPI_setjmpNoUnwind)
    #endif // _MSC_VER

    #include "../core/jit-calls.h"

#if NJ_EXPANDED_LOADSTORE_SUPPORTED && defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    #define VMCFG_MOPS_USE_EXPANDED_LOADSTORE_INT
#endif

#if NJ_EXPANDED_LOADSTORE_SUPPORTED && defined(VMCFG_UNALIGNED_FP_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    #define VMCFG_MOPS_USE_EXPANDED_LOADSTORE_FP
#endif

    // source of entropy for Assembler
    JITNoise::JITNoise()
    {
        MathUtils::initRandom(&randomSeed);
    }

    // produce a random number from 0-maxValue for the JIT to use in attack mitigation
    uint32_t JITNoise::getValue(uint32_t maxValue)
    {
        int32_t v = MathUtils::Random(maxValue, &randomSeed);
        AvmAssert(v>=0);
        return (uint32_t)v;
    }

    // AccSet conventions
    // nanojit currently supports very coarse grained access-set tags
    // for loads, stores, and calls.  See the comments in LIR.h for a
    // detailed description.  Here we define a set of constants to use that
    // are more fine grained, and then map them to AccessSets that nanojit supports.
    //
    // If you aren't sure what to use, use ACCSET_LOAD_ANY or ACCSET_STORE_ANY.
    // Warning: if you annotate a load or store with something other
    // than ACC_*_ANY, and get it wrong, you will introduce subtle and
    // hard to find bugs: "if you lie to the compiler, it will get its revenge"
    //
    // we use ACCSET_OTHER for a catchall that does not overlap with any other
    // predefined alias set.  Future work should subdivide this set where
    // the improvements outweigh the cost of additional alias sets.

    static const AccSet ACCSET_VARS  = (1 << 0);    // values of local variables
    static const AccSet ACCSET_TAGS  = (1 << 1);    // BuiltinTraits tags for local variables
    static const AccSet ACCSET_OTHER = (1 << 2);
    static const uint8_t TR_NUM_USED_ACCS = 3;      // number of access regions used by Tamarin

    struct MopsInfo
    {
        uint32_t size;
        LOpcode op;
        const CallInfo* call;
    };

    static const MopsInfo kMopsLoadInfo[7] = {
        { 1, LIR_ldc2i,   FUNCTIONID(mop_lix8) },
        { 2, LIR_lds2i,   FUNCTIONID(mop_lix16) },
        { 1, LIR_lduc2ui, FUNCTIONID(mop_liz8) },
        { 2, LIR_ldus2ui, FUNCTIONID(mop_liz16) },
        { 4, LIR_ldi,     FUNCTIONID(mop_li32) },
        { 4, LIR_ldf2d,   FUNCTIONID(mop_lf32) },
        { 8, LIR_ldd,     FUNCTIONID(mop_lf64) }
    };

    static const MopsInfo kMopsStoreInfo[5] = {
        { 1, LIR_sti2c, FUNCTIONID(mop_si8) },
        { 2, LIR_sti2s, FUNCTIONID(mop_si16) },
        { 4, LIR_sti,   FUNCTIONID(mop_si32) },
        { 4, LIR_std2f, FUNCTIONID(mop_sf32) },
        { 8, LIR_std,   FUNCTIONID(mop_sf64) }
     };

    class MopsRangeCheckFilter: public LirWriter
    {
    private:
        LirWriter* const prolog_out;
        LIns* const env_domainenv;
        LIns* curMemBase;
        LIns* curMemSize;
        LIns* curMopAddr;
        LIns* curRangeCheckLHS;
        LIns* curRangeCheckRHS;
        int32_t curRangeCheckMinValue;
        int32_t curRangeCheckMaxValue;

    private:
        void clearMemBaseAndSize();

        static void extractConstantDisp(LIns*& mopAddr, int32_t& curDisp);
        LIns* safeIns2(LOpcode op, LIns*, int32_t);
        void safeRewrite(LIns* ins, int32_t);

    public:
        MopsRangeCheckFilter(LirWriter* out, LirWriter* prolog_out, LIns* env_domainenv);

        LIns* emitRangeCheck(LIns*& mopAddr, int32_t const size, int32_t* disp, LIns*& br);
        void flushRangeChecks();

        // overrides from LirWriter
        LIns* ins0(LOpcode v);
        LIns* insCall(const CallInfo* call, LIns* args[]);
    };

    inline MopsRangeCheckFilter::MopsRangeCheckFilter(LirWriter* out, LirWriter* prolog_out, LIns* env_domainenv) :
        LirWriter(out),
        prolog_out(prolog_out),
        env_domainenv(env_domainenv),
        curMemBase(NULL),
        curMemSize(NULL),
        curMopAddr(NULL),
        curRangeCheckLHS(NULL),
        curRangeCheckRHS(NULL),
        curRangeCheckMinValue(int32_t(0x7fffffff)),
        curRangeCheckMaxValue(int32_t(0x80000000))
    {
        clearMemBaseAndSize();
    }

    void MopsRangeCheckFilter::clearMemBaseAndSize()
    {
        curMemBase = curMemSize = NULL;
    }

    void MopsRangeCheckFilter::flushRangeChecks()
    {
        AvmAssert((curRangeCheckLHS != NULL) == (curRangeCheckRHS != NULL));
        if (curRangeCheckLHS)
        {
            curRangeCheckLHS = curRangeCheckRHS = curMopAddr = NULL;
            curRangeCheckMinValue = int32_t(0x7fffffff);
            curRangeCheckMaxValue = int32_t(0x80000000);
            // but don't clearMemBaseAndSize()!
        }
        else
        {
            AvmAssert(curMopAddr == NULL);
            AvmAssert(curRangeCheckMinValue == int32_t(0x7fffffff));
            AvmAssert(curRangeCheckMaxValue == int32_t(0x80000000));
        }
    }

    static bool sumFitsInInt32(int32_t a, int32_t b)
    {
        return int64_t(a) + int64_t(b) == int64_t(a + b);
    }

    /*static*/ void MopsRangeCheckFilter::extractConstantDisp(LIns*& mopAddr, int32_t& curDisp)
    {
        // mopAddr is an int (an offset from globalMemoryBase) on all archs.
        // if mopAddr is an expression of the form
        //      expr+const
        //      const+expr
        //      expr-const
        //      (but not const-expr)
        // then try to pull the constant out and return it as a displacement to
        // be used in the instruction as an addressing-mode offset.
        // (but only if caller requests it that way.)
        for (;;)
        {
            LOpcode const op = mopAddr->opcode();
            if (op != LIR_addi && op != LIR_subi)
                break;

            int32_t imm;
            LIns* nonImm;
            if (mopAddr->oprnd2()->isImmI())
            {
                imm = mopAddr->oprnd2()->immI();
                nonImm = mopAddr->oprnd1();

                if (op == LIR_subi)
                    imm = -imm;
            }
            else if (mopAddr->oprnd1()->isImmI())
            {
                // don't try to optimize const-expr
                if (op == LIR_subi)
                    break;

                imm = mopAddr->oprnd1()->immI();
                nonImm = mopAddr->oprnd2();
            }
            else
            {
                break;
            }

            if (!sumFitsInInt32(curDisp, imm))
                break;

            curDisp += imm;
            mopAddr = nonImm;
        }
    }

    LIns* MopsRangeCheckFilter::emitRangeCheck(LIns*& mopAddr, int32_t const size, int32_t* disp, LIns*& br)
    {
        int32_t offsetMin = 0;
        if (disp != NULL)
        {
            *disp = 0;
            extractConstantDisp(mopAddr, *disp);
            offsetMin = *disp;
        }

        int32_t offsetMax = offsetMin + size;

        AvmAssert((curRangeCheckLHS != NULL) == (curRangeCheckRHS != NULL));

        AvmAssert(mopAddr != NULL);
        if (curRangeCheckLHS != NULL && curMopAddr == mopAddr)
        {
            int32_t n_curRangeCheckMin = curRangeCheckMinValue;
            if (n_curRangeCheckMin > offsetMin)
                n_curRangeCheckMin = offsetMin;
            int32_t n_curRangeCheckMax = curRangeCheckMaxValue;
            if (n_curRangeCheckMax < offsetMax)
                n_curRangeCheckMax = offsetMax;

            if ((n_curRangeCheckMax - n_curRangeCheckMin) <= DomainEnv::GLOBAL_MEMORY_MIN_SIZE)
            {
                if (curRangeCheckMinValue != n_curRangeCheckMin)
                    safeRewrite(curRangeCheckLHS, curRangeCheckMinValue);

                if ((n_curRangeCheckMax - n_curRangeCheckMin) != (curRangeCheckMaxValue - curRangeCheckMinValue))
                    safeRewrite(curRangeCheckRHS, curRangeCheckMaxValue - curRangeCheckMinValue);

                curRangeCheckMinValue = n_curRangeCheckMin;
                curRangeCheckMaxValue = n_curRangeCheckMax;
            }
            else
            {
                // if collapsed ranges get too large, pre-emptively flush, so that the
                // range-checking code can always assume the range is within minsize
                flushRangeChecks();
            }
        }
        else
        {
            flushRangeChecks();
        }

        if (!curMemBase)
        {
            //AvmAssert(curMemSize == NULL);
            curMemBase = out->insLoad(LIR_ldp, env_domainenv, offsetof(DomainEnv,m_globalMemoryBase), ACCSET_OTHER);
            curMemSize = out->insLoad(LIR_ldi, env_domainenv, offsetof(DomainEnv,m_globalMemorySize), ACCSET_OTHER);
        }

        AvmAssert((curRangeCheckLHS != NULL) == (curRangeCheckRHS != NULL));

        if (!curRangeCheckLHS)
        {
            AvmAssert(!curMopAddr);
            curMopAddr = mopAddr;
            curRangeCheckMinValue = offsetMin;
            curRangeCheckMaxValue = offsetMax;

            AvmAssert(env_domainenv != NULL);

            // we want to pass range-check if
            //
            //      (curMopAddr+curRangeCheckMin >= 0 && curMopAddr+curRangeCheckMax <= mopsMemorySize)
            //
            // which is the same as
            //
            //      (curMopAddr >= -curRangeCheckMin && curMopAddr <= mopsMemorySize - curRangeCheckMax)
            //
            // which is the same as
            //
            //      (curMopAddr >= -curRangeCheckMin && curMopAddr < mopsMemorySize - curRangeCheckMax + 1)
            //
            // and since (x >= min && x < max) is equivalent to (unsigned)(x-min) < (unsigned)(max-min)
            //
            //      (unsigned(curMopAddr + curRangeCheckMin) < unsigned(mopsMemorySize - curRangeCheckMax + 1 + curRangeCheckMin))
            //
            // from there, you'd think you could do
            //
            //      (curMopAddr < mopsMemorySize - curRangeCheckMax + 1))
            //
            // but that is only valid if you are certain that curMopAddr>0, due to the unsigned casting...
            // and curMopAddr could be anything, which is really the point of this whole exercise. Instead, settle for
            //
            //      (unsigned(curMopAddr + curRangeCheckMin) <= unsigned(mopsMemorySize - (curRangeCheckMax-curRangeCheckMin)))
            //

            AvmAssert(curRangeCheckMaxValue > curRangeCheckMinValue);
            AvmAssert(curRangeCheckMaxValue - curRangeCheckMinValue <= DomainEnv::GLOBAL_MEMORY_MIN_SIZE);

            curRangeCheckLHS = safeIns2(LIR_addi, curMopAddr, curRangeCheckMinValue);
            curRangeCheckRHS = safeIns2(LIR_subi, curMemSize, curRangeCheckMaxValue - curRangeCheckMinValue);

            LIns* cond = this->ins2(LIR_leui, curRangeCheckLHS, curRangeCheckRHS);
            br = this->insBranch(LIR_jf, cond, NULL);
        }

        return curMemBase;
    }

    // workaround for WE2569232: don't let these adds get specialized or CSE'd.
    LIns* MopsRangeCheckFilter::safeIns2(LOpcode op, LIns* lhs, int32_t rhsConst)
    {
        LIns* rhs = prolog_out->insImmI(rhsConst);
        LIns* ins = out->ins2(op, lhs, rhs);
        AvmAssert(ins->isop(op) && ins->oprnd1() == lhs && ins->oprnd2() == rhs);
        return ins;
    }

    // rewrite the instruction with a new rhs constant
    void MopsRangeCheckFilter::safeRewrite(LIns* ins, int32_t rhsConst)
    {
        LIns* rhs = prolog_out->insImmI(rhsConst);
        AvmAssert(ins->isop(LIR_addi) || ins->isop(LIR_subi));
        ins->initLInsOp2(ins->opcode(), ins->oprnd1(), rhs);
    }

    LIns* MopsRangeCheckFilter::ins0(LOpcode v)
    {
        if (v == LIR_label)
        {
            flushRangeChecks();
            clearMemBaseAndSize();
        }
        return LirWriter::ins0(v);
    }

    LIns* MopsRangeCheckFilter::insCall(const CallInfo *ci, LIns* args[])
    {
        // calls could potentially resize globalMemorySize, so we
        // can't collapse range checks across them
        if (!ci->_isPure)
        {
            flushRangeChecks();
            clearMemBaseAndSize();
        }
        return LirWriter::insCall(ci, args);
    }

    /**
     * ---------------------------------
     * Instruction convenience functions
     * ---------------------------------
     */

    // address calc instruction
    LIns* CodegenLIR::leaIns(int32_t disp, LIns* base) {
        return lirout->ins2(LIR_addp, base, InsConstPtr((void*)disp));
    }

    LIns* CodegenLIR::localCopy(int i)
    {
        switch (bt(state->value(i).traits)) {
        case BUILTIN_number:
            return localGetf(i);
        case BUILTIN_boolean:
        case BUILTIN_int:
        case BUILTIN_uint:
            return localGet(i);
        default:
            return localGetp(i);
        }
    }

    // returns true if mask has exactly one bit set
    // see http://aggregate.org/MAGIC/#Is%20Power%20of%202
    REALLY_INLINE bool exactlyOneBit(uint32_t m)
    {
        AvmAssert(m != 0);
        return (m & (m-1)) == 0;
    }

    void CodegenLIR::localSet(int i, LIns* o, Traits* type)
    {
        BuiltinType tag = bt(type);
        SlotStorageType sst = valueStorageType(tag);
#ifdef DEBUG
        jit_sst[i] = uint8_t(1 << sst);
#endif
        lirout->insStore(o, vars, i * VARSIZE, ACCSET_VARS);
        lirout->insStore(LIR_sti2c, InsConst(sst), tags, i, ACCSET_TAGS);
    }

    LIns* CodegenLIR::atomToNativeRep(int i, LIns* atom)
    {
        return atomToNativeRep(state->value(i).traits, atom);
    }

    LIns* CodegenLIR::ptrToNativeRep(Traits*t, LIns* ptr)
    {
        return t->isMachineType() ? addp(ptr, kObjectType) : ptr;
    }

#ifdef _DEBUG
    bool CodegenLIR::isPointer(int i)   {
        return !state->value(i).traits->isMachineType();
    }
#endif

    LIns* CodegenLIR::loadAtomRep(int i)
    {
        return nativeToAtom(localCopy(i), state->value(i).traits);
    }

    LIns* CodegenLIR::storeAtomArgs(int count, int index)
    {
        LIns* ap = insAlloc(sizeof(Atom)*count);
        for (int i=0; i < count; i++)
            stp(loadAtomRep(index++), ap, i * sizeof(Atom), ACCSET_OTHER);
        return ap;
    }

    LIns* CodegenLIR::storeAtomArgs(LIns* receiver, int count, int index)
    {
        #ifdef NJ_VERBOSE
        if (verbose())
            core->console << "          store args\n";
        #endif
        LIns* ap = insAlloc(sizeof(Atom)*(count+1));
        stp(receiver, ap, 0, ACCSET_OTHER);
        for (int i=1; i <= count; i++)
        {
            LIns* v = loadAtomRep(index++);
            stp(v, ap, sizeof(Atom)*i, ACCSET_OTHER);
        }
        return ap;
    }

    // initialize the code manager the first time we jit any method for this PoolObject.
    CodeMgr* initCodeMgr(PoolObject *pool) {
        if (!pool->codeMgr) {
            CodeMgr *mgr = mmfx_new( CodeMgr() );
            pool->codeMgr = mgr;
#ifdef NJ_VERBOSE
            mgr->log.core = pool->core;
            mgr->log.lcbits = pool->verbose_vb;
#endif
        }
        return pool->codeMgr;
    }

#ifdef NJ_VERBOSE
    void AvmLogControl::printf( const char* format, ... )
    {
        AvmAssert(core!=NULL);

        va_list vargs;
        va_start(vargs, format);

        char str[1024];
        VMPI_vsnprintf(str, sizeof(str), format, vargs);
        va_end(vargs);

        core->console << str;
    }
#endif

    CodegenLIR::CodegenLIR(MethodInfo* i, MethodSignaturep ms, Toplevel* toplevel) :
        LirHelper(i->pool()),
        info(i),
        ms(ms),
        toplevel(toplevel),
        pool(i->pool()),
        driver(NULL),
        state(NULL),
        mopsRangeCheckFilter(NULL),
        restArgc(NULL),
        restLocal(-1),
        interruptable(true),
        npe_label("npe"),
        upe_label("upe"),
        interrupt_label("interrupt"),
        mop_rangeCheckFailed_label("mop_rangeCheckFailed"),
        catch_label("catch"),
        call_cache_builder(*alloc1, *initCodeMgr(pool)),
        get_cache_builder(*alloc1, *pool->codeMgr),
        set_cache_builder(*alloc1, *pool->codeMgr),
        prolog(NULL),
        skip_ins(NULL),
        specializedCallHashMap(NULL),
        blockLabels(NULL),
        cseFilter(NULL),
        noise()
        DEBUGGER_ONLY(, haveDebugger(core->debugger() != NULL) )
    {
        #ifdef AVMPLUS_MAC_CARBON
        setjmpInit();
        #endif

        verbose_only(
            if (pool->isVerbose(VB_jit)) {
                core->console << "codegen " << i;
                core->console <<
                    " required=" << ms->requiredParamCount() <<
                    " optional=" << (ms->param_count() - ms->requiredParamCount()) << "\n";
            })
    }

    CodegenLIR::~CodegenLIR() {
        cleanup();
    }

    void CodegenLIR::cleanup()
    {
        finddef_cache_builder.cleanup();
        LirHelper::cleanup();
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

    void CodegenLIR::suspendCSE()
    {
        if (cseFilter) cseFilter->suspend();
    }

    void CodegenLIR::resumeCSE()
    {
        if (cseFilter) cseFilter->resume();
    }

    LIns* CodegenLIR::atomToNativeRep(Traits* t, LIns* atom)
    {
        return atomToNative(bt(t), atom);
    }

    bool isNullable(Traits* t) {
        BuiltinType bt = Traits::getBuiltinType(t);
        return bt != BUILTIN_int && bt != BUILTIN_uint && bt != BUILTIN_boolean && bt != BUILTIN_number;
    }

    /**
     * Eliminates redundant loads within a block, and tracks the nullability of pointers
     * within blocks and across edges.  CodegenLIR will inform VarTracker that a
     * pointer is not null by calling setNotNull(ptr, type) either when the Verifier's
     * FrameState.FrameValue is not null, in localGetp(), or after a null check in emitNullCheck().
     *
     * Within a block, we track nullability of references to instructions; when references
     * are copied, we know the copies are not null.
     *
     * At block boundaries, different values may flow together, so we track nullability
     * in variable slots instead of specific instruction references.
     */
    class VarTracker: public LirWriter
    {
        Allocator &alloc;               // Allocator for the lifetime of this filter
        LIns** varTracker;              // remembers the last value stored in each var
        LIns** tagTracker;              // remembers the last tag stored in each var
        HashMap<LIns*, bool> *checked;  // pointers we know are not null.
        nanojit::BitSet *notnull;       // stack locations we know are not null
        LIns* vars;                     // LIns that defines the vars[] array
        LIns* tags;                     // LIns that defines the tags[] array
        const int nvar;                 // this method's frame size.
        const int scopeBase;            // index of first local scope
        const int stackBase;            // index of first stack slot
        int restLocal;                  // -1 or, if it's lazily allocated, the local holding the rest array

        // false after an unconditional control flow instruction (jump, throw, return),
        // true from the start and after we start a block via trackLabel()
        bool reachable;

        // true if any backedges exist in LIR, false otherwise.
        bool has_backedges;

#ifdef DEBUGGER
        bool haveDebugger;              // true if debugger is currently enabled
#else
        static const bool haveDebugger = false;
#endif
#ifdef AVMPLUS_VERBOSE
        bool verbose;                   // true when generating verbose output
#else
        static const bool verbose = false;
#endif

    public:
        VarTracker(MethodInfo* info, Allocator& alloc, LirWriter *out,
                int nvar, int scopeBase, int stackBase, int restLocal,
                uint32_t code_len)
            : LirWriter(out), alloc(alloc),
              vars(NULL), tags(NULL),
              nvar(nvar), scopeBase(scopeBase), stackBase(stackBase),
              restLocal(restLocal), reachable(true),
              has_backedges(false)
#ifdef DEBUGGER
            , haveDebugger(info->pool()->core->debugger() != NULL)
#endif
#ifdef AVMPLUS_VERBOSE
            , verbose(info->pool()->isVerbose(VB_jit))
#endif
        {
            (void) info; // suppress warning if !DEBUGGER && !AVMPLUS_VERBOSE
            varTracker = new (alloc) LIns*[nvar];
            tagTracker = new (alloc) LIns*[nvar];
            // allocate a large value until https://bugzilla.mozilla.org/show_bug.cgi?id=565489 is resolved
            checked = new (alloc) HashMap<LIns*,bool>(alloc, code_len < 16700 ? code_len : 16700);
            notnull = new (alloc) nanojit::BitSet(alloc, nvar);
            clearState();
        }

        void init(LIns *vars, LIns* tags) {
            this->vars = vars;
            this->tags = tags;
        }

        bool hasBackedges() const {
            return has_backedges;
        }

        void setNotNull(LIns* ins, Traits* t) {
            if (isNullable(t))
                checked->put(ins, true);
        }

        bool isNotNull(LIns* ins) {
            return checked->containsKey(ins);
        }

        void initNotNull(const FrameState* state) {
            syncNotNull(notnull, state);
        }

        // We're at the start of an AS3 basic block; syncronize our
        // notnull bits for that block with ones from the driver.
        void syncNotNull(nanojit::BitSet* bits, const FrameState* state) {
            int scopeTop = scopeBase + state->scopeDepth;
            int stackTop = stackBase + state->stackDepth;
            if (state->targetOfBackwardsBranch) {
                // Clear any notNull bits that are not set in FrameState.
                for (int i=0, n=nvar; i < n; i++) {
                    const FrameValue& v = state->value(i);
                    bool stateNotNull = v.notNull && isNullable(v.traits);
                    if (!stateNotNull || (i >= scopeTop && i < stackBase) || (i >= stackTop))
                        bits->clear(i);
                    else
                        bits->set(i);
                }
                printNotNull(bits, "loop label");
            } else {
                // Set any notNull bits that are set in FrameState.
                // If we are tracking an expression for a non-null variable,
                // add it to the set of checked expressions.
                for (int i=0, n=nvar; i < n; i++) {
                    const FrameValue& v = state->value(i);
                    bool stateNotNull = v.notNull && isNullable(v.traits);
                    if ((i >= scopeTop && i < stackBase) || (i >= stackTop)) {
                        bits->clear(i);
                    } else if (stateNotNull) {
                        bits->set(i);
                        if (varTracker[i])
                            checked->put(varTracker[i], true);
                    } else if (bits->get(i) && varTracker[i])
                        checked->put(varTracker[i], true);
                }
                printNotNull(bits, "forward label");
            }
        }

        // Model a control flow edge by merging our current state with the state
        // saved at the target.  Used for forward branches and exception edges.
        void trackForwardEdge(CodegenLabel& target, bool isExceptionEdge) {
            AvmAssert(target.labelIns == NULL);  // illegal to call trackEdge on backedge

            // Merge varTracker/tagTracker state with state at target label.
            // Due to hidden internal control flow in exception dispatch, state may not be
            // propagated across exception edges.  Thus, if a label may be reached from such
            // an edge, we cannot determine accurate state at the label, and must clear it.
            // The state will remain cleared due to the monotonicity of the merge.
            if (!target.varTracker) {
                // Allocate state vectors for target label upon first encounter.
                target.varTracker = new (alloc) LIns*[nvar];
                target.tagTracker = new (alloc) LIns*[nvar];
                if (isExceptionEdge) {
                    VMPI_memset(target.varTracker, 0, nvar*sizeof(LIns*));
                    VMPI_memset(target.tagTracker, 0, nvar*sizeof(LIns*));
                } else {
                    VMPI_memcpy(target.varTracker, varTracker, nvar*sizeof(LIns*));
                    VMPI_memcpy(target.tagTracker, tagTracker, nvar*sizeof(LIns*));
                }
            } else if (isExceptionEdge) {
                VMPI_memset(target.varTracker, 0, nvar*sizeof(LIns*));
                VMPI_memset(target.tagTracker, 0, nvar*sizeof(LIns*));
            } else {
                for (int i=0, n=nvar; i < n; i++) {
                    if (varTracker[i] != target.varTracker[i])
                        target.varTracker[i] = NULL;
                    if (tagTracker[i] != target.tagTracker[i])
                        target.tagTracker[i] = NULL;
                }
            }

            for (int i=0, n=nvar; i < n; i++) {
                if (varTracker[i]) {
                    if (checked->containsKey(varTracker[i]))
                        notnull->set(i);
                    else
                        AvmAssert(!notnull->get(i));
                }
            }
            if (!target.notnull) {
                //printf("save state\n");
                target.notnull = new (alloc) nanojit::BitSet(alloc, nvar);
                target.notnull->setFrom(*notnull);
            } else {
                // target.notnull &= notnull
                for (int i=0, n=nvar; i < n; i++)
                    if (!notnull->get(i))
                        target.notnull->clear(i);
            }
        }

#ifdef AVMPLUS_VERBOSE
        void printNotNull(nanojit::BitSet* bits, const char* title) {
            if (verbose) {
                if (bits) {
                    printf("%s notnull = ", title);
                    for (int i=0, n=nvar; i < n; i++)
                        if (bits->get(i))
                            printf("%d ", i);
                    printf("\n");
                } else {
                    printf("%s notnull = null\n", title);
                }
            }
        }
#else
        void printNotNull(nanojit::BitSet*, const char*)
        {}
#endif

        void checkBackEdge(CodegenLabel& target, const FrameState* state) {
            has_backedges = true;
#ifdef DEBUG
            AvmAssert(target.labelIns != NULL);
            if (target.notnull) {
                printNotNull(notnull, "current");
                printNotNull(target.notnull, "target");
                int scopeTop = scopeBase + state->scopeDepth;
                int stackTop = stackBase + state->stackDepth;
                // make sure our notnull bits at the target of the backedge were safe.
                for (int i=0, n=nvar; i < n; i++) {
                    if ((i >= scopeTop && i < stackBase) || i >= stackTop)
                        continue; // skip empty locations
                    if (!isNullable(state->value(i).traits))
                        continue; // skip non-nullable types in current state
                    //  current   target    assert(!target || current)
                    //  -------   ------    ------
                    //  false     false     true
                    //  false     true      false (assertion fires)
                    //  true      false     true
                    //  true      true      true
                    bool currentNotNull = (varTracker[i] ? isNotNull(varTracker[i]) : false) || notnull->get(i);
                    AvmAssert(!target.notnull->get(i) || currentNotNull);
                }
            }
#else
            (void) target;
            (void) state;
#endif // DEBUG
        }

        // starts a new block.  if the new label is reachable from here,
        // merge our state with it.  then initialize from the new merged state.
        void trackLabel(CodegenLabel& label, const FrameState* state) {
            if (reachable)
                trackForwardEdge(label, false); // model the fall-through path as an edge
            clearState();
            label.labelIns = out->ins0(LIR_label);

            // Load varTracker/tagTracker state accumulated from forward branches.
            // Do not load if there are any backward branches, as the tracker state may
            // not be accurate.  Just switch the pointers -- no need to copy the arrays.
            if (!state->targetOfBackwardsBranch && label.varTracker) {
                varTracker = label.varTracker;
                tagTracker = label.tagTracker;
            }

            // load state saved at label
            if (label.notnull) {
                syncNotNull(label.notnull, state);
                notnull->setFrom(*label.notnull);
                printNotNull(notnull, "merged label");
            } else {
                syncNotNull(notnull, state);
                printNotNull(notnull, "first-time label");
            }
            reachable = true;
        }

        // Clear the var and tag expression states, but do not clear the nullability
        // state.  Called around debugger safe points to ensure that we reload values
        // that are possibly modified by the debugger.  Clearing the nullability state
        // correctly must be done at the verifier level, and at that level, it must always
        // be done or never be done (can't be conditional on debugging).
        // FIXME: bug 544238: clearing only the var state has questionable validity
        void clearVarState() {
            VMPI_memset(varTracker, 0, nvar*sizeof(LIns*));
            VMPI_memset(tagTracker, 0, nvar*sizeof(LIns*));
        }

        // clear all nullability and var/tag tracking state at branch targets
        void clearState() {
            clearVarState();
            checked->clear();
            notnull->reset();
        }

        REALLY_INLINE int varOffsetToIndex(int offset) {
            AvmAssert(IS_ALIGNED(offset, VARSIZE));
            return offset / VARSIZE;
        }

        // keep track of the value stored in var d and update notnull
        void trackVarStore(LIns *value, int i) {
            varTracker[i] = value;
            if (checked->containsKey(value))
                notnull->set(i);
            else
                notnull->clear(i);
        }

        // keep track of the tag stored in var i.
        void trackTagStore(LIns *value, int i) {
            tagTracker[i] = value;
        }

        // The first time we see a load from variable i, remember it,
        // and if we know that slot is nonnull, add the load instruction to the nonnull set.
        void trackVarLoad(LIns* value, int i) {
            varTracker[i] = value;
            if (notnull->get(i))
                checked->put(value, true);
        }

        // first time we read a tag for variable i, remember it.
        void trackTagLoad(LIns* value, int i) {
            tagTracker[i] = value;
        }

        // monitor loads emitted by the LIR generator, track access to vars and tags
        LIns *insLoad(LOpcode op, LIns *base, int32_t d, AccSet accSet, LoadQual loadQual) {
            if (base == vars) {
                int i = varOffsetToIndex(d);
                LIns *val = varTracker[i];
                if (!val) {
                    val = out->insLoad(op, base, d, accSet, loadQual);
                    trackVarLoad(val, i);
                }
                return val;
            }
            if (base == tags) {
                int i = d; // 1 byte per tag
                LIns *tag = tagTracker[i];
                if (!tag) {
                    tag = out->insLoad(op, base, d, accSet, loadQual);
                    trackTagLoad(tag, i);
                }
                return tag;
            }
            return out->insLoad(op, base, d, accSet, loadQual);
        }

        // monitor all stores emitted by LIR generator, update our tracking state
        // when we see stores to vars or tags.
        LIns *insStore(LOpcode op, LIns *value, LIns *base, int32_t d, AccSet accSet) {
            if (base == vars)
                trackVarStore(value, varOffsetToIndex(d));
            else if (base == tags)
                trackTagStore(value, d);
            return out->insStore(op, value, base, d, accSet);
        }

        // we expect the frontend to use CodegenLabels and call trackLabel for all
        // LIR label creation.  Assert to prevent unknown label generation.
        LIns *ins0(LOpcode op) {
            AvmAssert(op != LIR_label); // trackState must be called directly to generate a label.
            return out->ins0(op);
        }

        // set reachable = false after return instructions
        LIns* ins1(LOpcode op, LIns* a) {
            if (isRetOpcode(op))
                reachable = false;
            return out->ins1(op, a);
        }

        // set reachable = false after unconditional jumps
        LIns *insBranch(LOpcode v, LIns* cond, LIns* to) {
            if (v == LIR_j)
                reachable = false;
            return out->insBranch(v, cond, to);
        }

        // set reachable = false after LIR_jtbl which has explicit targets for all cases
        LIns *insJtbl(LIns* index, uint32_t size) {
            reachable = false;
            return out->insJtbl(index, size);
        }

        // assume any non-pure function can throw an exception, and that pure functions cannot.
        bool canThrow(const CallInfo* call)
        {
            return !call->_isPure;
        }

        // if debugging is attached, clear our tracking state when calling side-effect
        // fucntions, which are effectively debugger safe points.
        // also set reachable = false if the function is known to always throw, and never return.
        LIns *insCall(const CallInfo *call, LIns* args[]) {
            if (haveDebugger && canThrow(call))
                clearVarState(); // debugger might have modified locals, so make sure we reload after call.
            if (neverReturns(call))
                reachable = false;
            if (call->_address == (uintptr_t)&restargHelper) {
                // That helper has a by-reference argument which points into the vars array
                AvmAssert(restLocal != -1);
                varTracker[restLocal] = 0;
            }
            return out->insCall(call, args);
        }
    };

    LIns* CodegenLIR::localGet(int i) {
#ifdef DEBUG
        const FrameValue& v = state->value(i);
        AvmAssert((v.sst_mask == (1 << SST_int32) && v.traits == INT_TYPE) ||
                  (v.sst_mask == (1 << SST_uint32) && v.traits == UINT_TYPE) ||
                  (v.sst_mask == (1 << SST_bool32) && v.traits == BOOLEAN_TYPE));
#endif
        return lirout->insLoad(LIR_ldi, vars, i * VARSIZE, ACCSET_VARS);
    }

    LIns* CodegenLIR::localGetf(int i) {
#ifdef DEBUG
        const FrameValue& v = state->value(i);
        AvmAssert(v.sst_mask == (1<<SST_double) && v.traits == NUMBER_TYPE);
#endif
        return lirout->insLoad(LIR_ldd, vars, i * VARSIZE, ACCSET_VARS);
    }

    // Load a pointer-sized var, and update null tracking state if the driver
    // informs us that it is not null via FrameState.value.
    LIns* CodegenLIR::localGetp(int i)
    {
        const FrameValue& v = state->value(i);
        LIns* ins;
        if (exactlyOneBit(v.sst_mask)) {
            // pointer or atom
            AvmAssert(!(v.sst_mask == (1 << SST_int32) && v.traits == INT_TYPE) &&
                      !(v.sst_mask == (1 << SST_uint32) && v.traits == UINT_TYPE) &&
                      !(v.sst_mask == (1 << SST_bool32) && v.traits == BOOLEAN_TYPE) &&
                      !(v.sst_mask == (1 << SST_double) && v.traits == NUMBER_TYPE));
            ins = lirout->insLoad(LIR_ldp, vars, i * VARSIZE, ACCSET_VARS);
        } else {
            // more than one representation is possible: convert to atom using tag found at runtime.
            AvmAssert(bt(v.traits) == BUILTIN_any || bt(v.traits) == BUILTIN_object);
            LIns* tag = lirout->insLoad(LIR_lduc2ui, tags, i, ACCSET_TAGS);
            LIns* varAddr = leaIns(i * VARSIZE, vars);
            ins = callIns(FUNCTIONID(makeatom), 3, coreAddr, varAddr, tag);
        }
        if (v.notNull)
            varTracker->setNotNull(ins, v.traits);
        return ins;
    }

    LIns* CodegenLIR::callIns(const CallInfo *ci, uint32_t argc, ...)
    {
        const uint8_t* pc = state->abc_pc;

        // Each exception edge needs to be tracked to make sure we correctly
        // model the notnull state at the starts of catch blocks.  Treat any function
        // with side effects as possibly throwing an exception.

        // We must ignore catch blocks that the driver has determined are not reachable,
        // because we emit a call to debugExit (modeled as possibly throwing) as part of
        // OP_returnvoid/returnvalue, which ordinarily don't throw.
        if (!ci->_isPure && pc >= try_from && pc < try_to) {
            // inside exception handler range, calling a function that could throw
            ExceptionHandlerTable *exTable = info->abc_exceptions();
            for (int i=0, n=exTable->exception_count; i < n; i++) {
                ExceptionHandler* handler = &exTable->exceptions[i];
                const uint8_t* from   = code_pos + handler->from;
                const uint8_t* to     = code_pos + handler->to;
                const uint8_t* target = code_pos + handler->target;
                if (pc >= from && pc < to && driver->hasFrameState(target))
                    varTracker->trackForwardEdge(getCodegenLabel(target), true);
            }
        }

        va_list ap;
        va_start(ap, argc);
        LIns* ins = LirHelper::vcallIns(ci, argc, ap);
        va_end(ap);
        return ins;
    }

#if defined(DEBUGGER) && defined(_DEBUG)
    // The AS debugger requires type information for variables contained
    // in the AS frame regions (i.e. 'vars').  In the interpreter this
    // is not an issues, since the region contains box values (i.e. Atoms)
    // and so the type information is self-contained.  With the jit, this is
    // not the case, and thus 'tags' is used to track the type of each
    // variable in 'vars'.
    // This filter watches stores to 'vars' and 'tags' and upon encountering
    // debugline (i.e. place where debugger can halt), it ensures that the
    // tags entry is consistent with the value stored in 'vars'
    class DebuggerCheck : public LirWriter
    {
        AvmCore* core;
        LIns** varTracker;
        LIns** tagTracker;
        LIns *vars;
        LIns *tags;
        int nvar;
    public:
        DebuggerCheck(AvmCore* core, Allocator& alloc, LirWriter *out, int nvar)
            : LirWriter(out), core(core), vars(NULL), tags(NULL), nvar(nvar)
        {
            varTracker = new (alloc) LIns*[nvar];
            tagTracker = new (alloc) LIns*[nvar];
            clearState();
        }

        void init(LIns *vars, LIns *tags) {
            this->vars = vars;
            this->tags = tags;
        }

        void trackVarStore(LIns *value, int d) {
            AvmAssert(IS_ALIGNED(d, VARSIZE));
            int i = d / VARSIZE;
            if (i >= nvar)
                return;
            varTracker[i] = value;
        }

        void trackTagStore(LIns *value, int d) {
            int i = d; // 1 byte per tag
            if (i >= nvar)
                return;
            tagTracker[i] = value;
            checkValid(i);
            tagTracker[i] = (LIns*)((intptr_t)value|1); // lower bit => validated;
        }

        void clearState() {
            VMPI_memset(varTracker, 0, nvar * sizeof(LIns*));
            VMPI_memset(tagTracker, 0, nvar * sizeof(LIns*));
        }

        void checkValid(int i) {
            // @pre tagTracker[i] has been previously filled
            LIns* val = varTracker[i];
            LIns* tra = tagTracker[i];
            NanoAssert(val && tra);

            switch ((SlotStorageType) tra->immI()) {
            case SST_double:
                AvmAssert(val->isQorD());
                break;
            case SST_int32:
            case SST_uint32:
            case SST_bool32:
                AvmAssert(val->isI());
                break;
            default:
                AvmAssert(val->isP());
                break;
            }
        }

        void checkState() {
            for (int i=0; i < this->nvar; i++) {
                LIns* val = varTracker[i];
                LIns* tra = tagTracker[i];
                AvmAssert(val && tra);

                // isValid should have already been called on everything
                AvmAssert(((intptr_t)tra&0x1) == 1);
            }
        }

        LIns *insCall(const CallInfo *call, LIns* args[]) {
            if (call == FUNCTIONID(debugLine))
                checkState();
            return out->insCall(call,args);
        }

        LIns *insStore(LOpcode op, LIns *value, LIns *base, int32_t d, AccSet accSet) {
            if (base == vars)
                trackVarStore(value, d);
            else if (base == tags)
                trackTagStore(value, d);
            return out->insStore(op, value, base, d, accSet);
        }

    };
#endif

    // writer for the prolog.  instructions written here dominate code in the
    // body, and so are added to the body's CseFilter
    class PrologWriter : public LirWriter
    {
    public:
        LIns* lastIns;
        LIns* env_scope;
        LIns* env_vtable;
        LIns* env_abcenv;
        LIns* env_domainenv;
        LIns* env_toplevel;

        PrologWriter(LirWriter *out):
            LirWriter(out),
            lastIns(NULL),
            env_scope(NULL),
            env_vtable(NULL),
            env_abcenv(NULL),
            env_domainenv(NULL),
            env_toplevel(NULL)
        {}

        virtual LIns* ins0(LOpcode v) {
            return lastIns = out->ins0(v);
        }
        virtual LIns* ins1(LOpcode v, LIns* a) {
            return lastIns = out->ins1(v, a);
        }
        virtual LIns* ins2(LOpcode v, LIns* a, LIns* b) {
            return lastIns = out->ins2(v, a, b);
        }
        virtual LIns* ins3(LOpcode v, LIns* a, LIns* b, LIns* c) {
            return lastIns = out->ins3(v, a, b, c);
        }
        virtual LIns* insGuard(LOpcode v, LIns *c, GuardRecord *gr) {
            return lastIns = out->insGuard(v, c, gr);
        }
        virtual LIns* insBranch(LOpcode v, LIns* condition, LIns* to) {
            return lastIns = out->insBranch(v, condition, to);
        }
        // arg: 0=first, 1=second, ...
        // kind: 0=arg 1=saved-reg
        virtual LIns* insParam(int32_t arg, int32_t kind) {
            return lastIns = out->insParam(arg, kind);
        }
        virtual LIns* insImmI(int32_t imm) {
            return lastIns = out->insImmI(imm);
        }
#ifdef AVMPLUS_64BIT
        virtual LIns* insImmQ(uint64_t imm) {
            return lastIns = out->insImmQ(imm);
        }
#endif
        virtual LIns* insImmD(double d) {
            return lastIns = out->insImmD(d);
        }
        virtual LIns* insLoad(LOpcode op, LIns* base, int32_t d, AccSet accSet, LoadQual loadQual) {
            return lastIns = out->insLoad(op, base, d, accSet, loadQual);
        }
        virtual LIns* insStore(LOpcode op, LIns* value, LIns* base, int32_t d, AccSet accSet) {
            return lastIns = out->insStore(op, value, base, d, accSet);
        }
        // args[] is in reverse order, ie. args[0] holds the rightmost arg.
        virtual LIns* insCall(const CallInfo *call, LIns* args[]) {
            return lastIns = out->insCall(call, args);
        }
        virtual LIns* insAlloc(int32_t size) {
            NanoAssert(size != 0);
            return lastIns = out->insAlloc(size);
        }
        virtual LIns* insJtbl(LIns* index, uint32_t size) {
            return lastIns = out->insJtbl(index, size);
        }

    };

    // Generate the prolog for a function with this C++ signature:
    //
    //    <return-type> f(MethodEnv* env, int argc, void* args)
    //
    // argc is the number of arguments, not counting the receiver
    // (aka "this"). args points to the arguments in memory:
    //
    //    [receiver] [arg1, arg2, ... ]
    //
    // the arguments in memory are typed according to the AS3 method
    // signature.  types * and Object are represented as Atom, and all
    // other types are native pointers or values.  return-type is whatever
    // the native type is for the AS3 return type; one of double, int32_t,
    // uint32_t, ScriptObject*, String*, Namespace*, Atom, or void.
    //
    // The stack frame layout of a jit-compiled function is determined by
    // the jit backend.  Stack-allocated structs are declared in LIR with
    // a LIR_allocp instruction.  Incoming parameters are declared with LIR_paramp
    // instructions, and any other local variables with function-body scope
    // and lifetime are declared with the expressions that compute them.
    // The backend will also allocate additional stack space for spilled values
    // and callee-saved registers.  The VM and LIR do not currently depend on how
    // the backend organizes the stack frame.
    //
    // Incoming parameters:
    //
    // env_param (LIR_paramp, MethodEnv*) is the incoming MethodEnv* parameter
    // that provides access to the environment for this function and all vm services.
    //
    // argc_param (LIR_paramp, int32_t) the # of arguments that follow.  Ignored
    // when the # of args is fixed, but otherwise used for optional arg processing
    // and/or creating the rest[] or arguments[] arrays for undeclared varargs.
    //
    // ap_param (LIR_paramp, uint32_t*) pointer to (argc+1) incoming arguments.
    // arguments are packed.  doubles are sizeof(double), everything else is sizeof(Atom).
    //
    // Distinguished locals:
    //
    // methodFrame (LIR_allocp, MethodFrame*) is the current MethodFrame.  in the prolog
    // we push this onto the call stack pointed to by AvmCore::currentMethodFrame, and
    // in the epilog we pop it back off.
    //
    // coreAddr (LIR_immi|LIR_immq) constant address of AvmCore*.  used in lots of places.
    // undefConst (LIR_immi|LIR_immq) constant value = undefinedAtom. used all over.
    //
    // vars (LIR_allocp) storage for ABC stack frame variables.  8 bytes per variable,
    // always, laid out according to ABC param/local var numbering.  The total number
    // is local_count + scope_depth + stack_depth, i.e. enough for the whole ABC frame.
    // values at any given point in the jit code are are represented according to the
    // statically known type of the variable at that point in the code.  (the type and
    // representation may change at different points.  CodegenDriver maintains
    // the known static types of variables and exposes them via FrameState.
    //
    // tags (LIR_allocp) SlotStorageType of each var in vars, one byte per variable.
    //
    // The contents of vars+tags are up-to-date at all labels and debugging safe points.
    // Inbetween those points, the contents are stale; the JIT optimizes away
    // stores and loads in straightline code.  Additional dead stores
    // are elided by deadvars_analyze() and deadvars_kill().
    //
    // Locals for Debugger use, only present when Debugger is in use:
    //
    // csn (LIR_allocp, CallStackNode).  extra information about this call frame
    // used by the debugger and also used for constructing human-readable stack traces.
    //
    // Locals for Exception-handling, only present when method has try/catch blocks:
    //
    // _save_eip (LIR_allocp, intptr_t) storage for the current ABC-based "pc", used by exception
    // handling to determine which catch blocks are in scope.  The value is an ABC
    // instruction offset, which is how catch handler records are indexed.
    //
    // _ef (LIR_allocp, ExceptionFrame) an instance of struct ExceptionFrame, including
    // a jmp_buf holding our setjmp() state, a pointer to the next outer ExceptionFrame,
    // and other junk.
    //
    // setjmpResult (LIR_call, int) result from calling setjmp; feeds a conditional branch
    // that surrounds the whole function body; logic to pick a catch handler and jump to it
    // is compiled after the function body.  if setjmp returns a nonzero result then we
    // jump forward, pick a catch block, then jump backwards to the catch block.
    //

    void CodegenLIR::writePrologue(const FrameState* state, const uint8_t* pc,
            CodegenDriver* driver)
    {
        this->state = state;
        this->driver = driver;
        this->code_pos = pc;
        this->try_from = driver->getTryFrom();
        this->try_to = driver->getTryTo();
        framesize = ms->frame_size();

        if (info->needRestOrArguments() && info->lazyRest())
            restLocal = ms->param_count()+1;

        frag = new (*lir_alloc) Fragment(pc verbose_only(, 0));
        LirBuffer *prolog_buf = frag->lirbuf = new (*lir_alloc) LirBuffer(*lir_alloc);
        prolog_buf->abi = ABI_CDECL;

        lirout = new (*alloc1) LirBufWriter(prolog_buf, core->config.njconfig);

        verbose_only(
            vbNames = 0;
            if (verbose()) {
                vbNames = new (*lir_alloc) LInsPrinter(*lir_alloc, TR_NUM_USED_ACCS);
                vbNames->addrNameMap->addAddrRange(pool->core, sizeof(AvmCore), 0, "core");
                prolog_buf->printer = vbNames;
            }
        )
        debug_only(
            lirout = validate2 = new (*alloc1) ValidateWriter(lirout, prolog_buf->printer,
                                                  "writePrologue(prologue)");
        )
        verbose_only(
            vbWriter = 0;
            if (verbose())
                lirout = vbWriter = new (*alloc1) VerboseWriter(*alloc1, lirout, vbNames, &pool->codeMgr->log, "PROLOG");
        )
        prolog = new (*alloc1) PrologWriter(lirout);
        redirectWriter = lirout = new (*lir_alloc) LirWriter(prolog);
        if (core->config.njconfig.cseopt)
            lirout = cseFilter = new (*alloc1) CseFilter(lirout, TR_NUM_USED_ACCS, *alloc1);
#if defined(NANOJIT_ARM)
        if (core->config.njconfig.soft_float)
            lirout = new (*alloc1) SoftFloatFilter(lirout);
#endif
        lirout = new (*alloc1) ExprFilter(lirout);

        #ifdef DEBUGGER
        dbg_framesize = ms->local_count() + ms->max_scope();
        #ifdef DEBUG
        DebuggerCheck *checker = NULL;
        if (haveDebugger) {
            checker = new (*alloc1) DebuggerCheck(core, *alloc1, lirout, dbg_framesize);
            lirout = checker;
        }
        #endif // DEBUG
        #endif // DEBUGGER

        emitStart(*alloc1, prolog_buf, lirout);

        // add the VarTracker filter last because we want it to be first in line.
        lirout = varTracker = new (*alloc1) VarTracker(info, *alloc1, lirout,
                framesize, ms->scope_base(), ms->stack_base(), restLocal,
                info->parse_code_length());

        // last pc value that we generated a store for
        lastPcSave = NULL;

        //
        // generate lir to define incoming method arguments.  Stack
        // frame allocations follow.
        //

        env_param = lirout->insParam(0, 0);
        argc_param = lirout->insParam(1, 0);
    #ifdef AVMPLUS_64BIT
        argc_param = lirout->ins1(LIR_q2i, argc_param);
    #endif
        ap_param = lirout->insParam(2, 0);

        // allocate room for a MethodFrame structure
        methodFrame = insAlloc(sizeof(MethodFrame));
        verbose_only( if (vbNames) {
            vbNames->lirNameMap->addName(methodFrame, "methodFrame");
        })

        coreAddr = InsConstPtr(core);

        // replicate MethodFrame ctor inline
        LIns* currentMethodFrame = loadIns(LIR_ldp, offsetof(AvmCore,currentMethodFrame), coreAddr, ACCSET_OTHER);
        // save env in MethodFrame.envOrCodeContext
        //     explicitly leave IS_EXPLICIT_CODECONTEXT clear
        //     explicitly leave DXNS_NOT_NULL clear, dxns is effectively null without doing the store here.
        stp(env_param, methodFrame, offsetof(MethodFrame,envOrCodeContext), ACCSET_OTHER);
        stp(currentMethodFrame, methodFrame, offsetof(MethodFrame,next), ACCSET_OTHER);
        stp(methodFrame, coreAddr, offsetof(AvmCore,currentMethodFrame), ACCSET_OTHER);
        #ifdef _DEBUG
        // poison MethodFrame.dxns since it's uninitialized by default
        stp(InsConstPtr((void*)(uintptr_t)0xdeadbeef), methodFrame, offsetof(MethodFrame,dxns), ACCSET_OTHER);
        #endif

        // allocate room for our local variables
        vars = insAlloc(framesize * VARSIZE);   // room for double|Atom|int|pointer
        tags = insAlloc(framesize);             // one tag byte per var
        prolog_buf->sp = vars;
        varTracker->init(vars, tags);

        verbose_only( if (prolog_buf->printer) {
            prolog_buf->printer->lirNameMap->addName(env_param, "env");
            prolog_buf->printer->lirNameMap->addName(argc_param, "argc");
            prolog_buf->printer->lirNameMap->addName(ap_param, "ap");
            prolog_buf->printer->lirNameMap->addName(vars, "vars");
            prolog_buf->printer->lirNameMap->addName(tags, "tags");
        })

        debug_only(
            void** extras = new (*alloc1) void*[2];
            extras[0] = vars;
            extras[1] = tags;
            validate1->setCheckAccSetExtras(extras);
            validate2->setCheckAccSetExtras(extras);
        )

        // stack overflow check - use methodFrame address as comparison
        LIns *d = loadIns(LIR_ldp, offsetof(AvmCore, minstack), coreAddr, ACCSET_OTHER);
        LIns *c = binaryIns(LIR_ltup, methodFrame, d);
        CodegenLabel &begin_label = createLabel("begin");
        branchToLabel(LIR_jf, c, begin_label);
        callIns(FUNCTIONID(handleStackOverflowMethodEnv), 1, env_param);
        emitLabel(begin_label);

        // we emit the undefined constant here since we use it so often and
        // to ensure it dominates all uses.
        undefConst = InsConstAtom(undefinedAtom);

        // whether this sequence is interruptable or not.
        interruptable = ! info->isNonInterruptible();

        // then space for the exception frame, be safe if its an init stub
        if (driver->hasReachableExceptions()) {
            // [_save_eip][ExceptionFrame]
            // offsets of local vars, rel to current ESP
            _save_eip = insAlloc(sizeof(intptr_t));
            _ef       = insAlloc(sizeof(ExceptionFrame));
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(_save_eip, "_save_eip");
                vbNames->lirNameMap->addName(_ef, "_ef");
            })
        } else {
            _save_eip = NULL;
            _ef = NULL;
        }

        #ifdef DEBUGGER
        if (haveDebugger) {
            // tell the sanity checker about vars and tags
            debug_only( checker->init(vars, tags); )

            // Allocate space for the call stack
            csn = insAlloc(sizeof(CallStackNode));
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(csn, "csn");
            })
        }
        #endif

#ifdef DEBUG
        jit_sst = new (*alloc1) uint8_t[framesize];
        memset(jit_sst, 0, framesize);
#endif

        //
        // copy args to local frame
        //

        // copy required args, and initialize optional args.
        // this whole section only applies to functions that actually
        // have arguments.

        const int param_count = ms->param_count();
        const int optional_count = ms->optional_count();
        const int required_count = param_count - optional_count;

        LIns* apArg = ap_param;
        if (info->hasOptional())
        {
            // compute offset of first optional arg
            int offset = 0;
            for (int i=0, n=required_count; i <= n; i++)
                offset += argSize(ms, i);

            // now copy the default optional values
            LIns* argcarg = argc_param;
            for (int i=0, n=optional_count; i < n; i++)
            {
                // first set the local[p+1] = defaultvalue
                int param = i + required_count; // 0..N
                int loc = param+1;

                LIns* defaultVal = InsConstAtom(ms->getDefaultValue(i));
                defaultVal = atomToNativeRep(loc, defaultVal);
                localSet(loc, defaultVal, state->value(loc).traits);

                // then generate: if (argc > p) local[p+1] = arg[p+1]
                LIns* cmp = binaryIns(LIR_lei, argcarg, InsConst(param));
                CodegenLabel& optional_label = createLabel("param_", i);
                branchToLabel(LIR_jt, cmp, optional_label); // will patch
                copyParam(loc, offset);
                emitLabel(optional_label);
            }
        }
        else
        {
            // !info->hasOptional()
            AvmAssert(optional_count == 0);
        }

        // now set up the required args (we can ignore argc)
        // for (int i=0, n=param_count; i <= n; i++)
        //     framep[i] = argv[i];
        int offset = 0;
        for (int i=0, n=required_count; i <= n; i++)
            copyParam(i, offset);

        if (info->unboxThis())
        {
            localSet(0, atomToNativeRep(0, localGet(0)), state->value(0).traits);
        }

        int firstLocal = 1+param_count;

        // Capture remaining args.
        //
        // Optimized ...rest and 'arguments':
        //
        // We avoid constructing the rest array if possible.  An analysis in the
        // verifier sets the _lazyRest bit if access patterns to the rest argument
        // or the arguments array are only OBJ.length or OBJ[prop] for arbitrary
        // propery; see comments in Verifier::verify.  The former pattern
        // results in an OP_restargc instruction, while the latter results in an
        // OP_restarg instruction.  Those instructions will access an unconsed
        // rest array or arguments array when possible, and otherwise access a
        // constructed rest array.  (For example, if prop turns out to be "slice"
        // we must construct the array.  This will almost never happen.) They're
        // implemented via helper functions restargcHelper and restargHelper.
        //
        // The unconsed rest or arguments array, the argument count, the consed array,
        // and the flag that determines whether to use the unconsed or the consed array,
        // are represented as follows:
        //
        //  - The unconsed array restArg is represented indirectly via ap_param and
        //    rest_offset.
        //  - The argument count restArgc is a LIR expression of type uint32 computed from
        //    argc_param and param_count.
        //  - The rest parameter local is an array, it is either null (no rest array
        //    consed yet) or a raw array pointer, so it doubles as the flag.  The offset
        //    of this variable is 1+param_count.
        //
        // The rest parameter local is passed by reference to restargHelper, which
        // may update it.
        //
        // The difference between a ...rest argument and an arguments array are that in
        // the former case,
        //
        //    restArgc = MAX(argc_param - param_count, 0)
        //    restArg = is ap_param + rest_offset
        //
        // while in the latter case
        //
        //    restArgc = argc_param
        //    restArg = ap_param + 1
        //
        // restArg is computed in the code generation case for OP_restarg.

        if (info->needRest())
        {
            if (info->lazyRest())
            {
                LIns* x0 = binaryIns(LIR_subi, argc_param, InsConst(param_count));
                LIns* x1 = binaryIns(LIR_lti, x0, InsConst(0));
                restArgc = lirout->insChoose(x1, InsConst(0), x0, use_cmov);

                // Store a NULL array pointer
                localSet(firstLocal, InsConstPtr(0), ARRAY_TYPE);
            }
            else
            {
                //framep[info->param_count+1] = createRest(env, argv, argc);
                // use csop so if rest value never used, we don't bother creating array
                LIns* rest = callIns(FUNCTIONID(createRestHelper), 3,
                    env_param, argc_param, apArg);
                localSet(firstLocal, rest, ARRAY_TYPE);
            }
            firstLocal++;
        }
        else if (info->needArguments())
        {
            if (info->lazyRest())
            {
                restArgc = argc_param;

                // Store a NULL array pointer
                localSet(firstLocal, InsConstPtr(0), ARRAY_TYPE);
            }
            else {
                //framep[info->param_count+1] = createArguments(env, argv, argc);
                // use csop so if arguments never used, we don't create it
                LIns* arguments = callIns(FUNCTIONID(createArgumentsHelper), 3,
                    env_param, argc_param, apArg);
                localSet(firstLocal, arguments, ARRAY_TYPE);
            }
            firstLocal++;
        }

        // set remaining locals to undefined
        for (int i=firstLocal, n = ms->local_count(); i < n; i++) {
            AvmAssert(state->value(i).traits == NULL);
            localSet(i, undefConst, NULL); // void would be more precise
        }

        /// SWITCH PIPELINE FROM PROLOG TO BODY
        verbose_only( if (vbWriter) { vbWriter->flush();} )
        // we have written the prolog to prolog_buf, now create a new
        // LirBuffer to hold the body, and redirect further output to the body.
        LirBuffer *body_buf = new (*lir_alloc) LirBuffer(*lir_alloc);
        LirWriter *body = new (*alloc1) LirBufWriter(body_buf, core->config.njconfig);
        skip_ins = body->insSkip(prolog->lastIns);
        debug_only(
            body = validate3 = new (*alloc1) ValidateWriter(body, vbNames, "writePrologue(body)");
            validate3->setCheckAccSetExtras(extras);
        )
        verbose_only(
            if (verbose()) {
                AvmAssert(vbNames != NULL);
                body_buf->printer = vbNames;
                body = vbWriter = new (*alloc1) VerboseWriter(*alloc1, body, vbNames, &pool->codeMgr->log);
            }
        )
        redirectWriter->out = body;
        /// END SWITCH CODE

        varTracker->initNotNull(state);

        // Generate code to initialize the object, if we are compiling an initializer.
        // This is intentionally before debugEnter(), to match interpreter behavior.
        if (info->isConstructor())
            emitInitializers();

        if (haveDebugger)
            emitDebugEnter();

        if (driver->hasReachableExceptions()) {
            // _ef.beginTry(core);
            callIns(FUNCTIONID(beginTry), 2, _ef, coreAddr);

            // Exception* setjmpResult = setjmp(_ef.jmpBuf);
            // ISSUE this needs to be a cdecl call
            LIns* jmpbuf = leaIns(offsetof(ExceptionFrame, jmpbuf), _ef);
            setjmpResult = callIns(FUNCTIONID(fsetjmp), 2, jmpbuf, InsConst(0));

            // If (setjmp() != 0) goto catch dispatcher, which we generate in the epilog.
            // Note that register contents following setjmp return via longjmp are not predictable.
            branchToLabel(LIR_jf, eqi0(setjmpResult), catch_label);
        }
        verbose_only( if (vbWriter) { vbWriter->flush();} )
    }

    void CodegenLIR::emitInitializers()
    {
        struct JitInitVisitor: public InitVisitor {
            CodegenLIR *jit;
            JitInitVisitor(CodegenLIR *jit) : jit(jit) {}
            virtual ~JitInitVisitor() {}
            void defaultVal(Atom value, uint32_t slot, Traits* slotType) {
#ifdef NJ_VERBOSE
                if (jit->verbose()) {
                    jit->vbWriter->flush();
                    jit->core->console << "init [" << slot << "] = " << asAtom(value) << "\n";
                }
#endif
                LIns* defaultVal = jit->InsConstAtom(value);
                defaultVal = jit->atomToNativeRep(slotType, defaultVal);
                jit->emitSetslot(OP_setslot, slot, 0, defaultVal);
            }
        };
        JitInitVisitor visitor(this);
        Traits* t = info->declaringTraits();
        const TraitsBindings *tb = t->getTraitsBindings();
        t->visitInitBody(&visitor, toplevel, tb);
    }

    void CodegenLIR::emitDebugEnter()
    {
        #ifdef DEBUGGER
        for (int i = ms->scope_base(), n = ms->stack_base(); i < n; ++i)
            localSet(i, undefConst, VOID_TYPE);

        callIns(FUNCTIONID(debugEnter), 5,
            env_param,
            tags,
            csn,
            vars,
            driver->hasReachableExceptions() ? _save_eip : InsConstPtr(0));
        #endif // DEBUGGER
    }

    void CodegenLIR::copyParam(int i, int& offset) {
        LIns* apArg = ap_param;
        Traits* type = ms->paramTraits(i);
        LIns *arg;
        switch (bt(type)) {
        case BUILTIN_number:
            arg = loadIns(LIR_ldd, offset, apArg, ACCSET_OTHER, LOAD_CONST);
            offset += sizeof(double);
            break;
        case BUILTIN_int:
        case BUILTIN_uint:
        case BUILTIN_boolean:
            // in the args these are widened to intptr_t or uintptr_t, so truncate here.
            arg = p2i(loadIns(LIR_ldp, offset, apArg, ACCSET_OTHER, LOAD_CONST));
            offset += sizeof(Atom);
            break;
        default:
            arg = loadIns(LIR_ldp, offset, apArg, ACCSET_OTHER, LOAD_CONST);
            offset += sizeof(Atom);
            break;
        }
        localSet(i, arg, type);
    }

    void CodegenLIR::emitCopy(int src, int dest) {
        localSet(dest, localCopy(src), state->value(src).traits);
    }

    void CodegenLIR::emitGetscope(int scope_index, int dest)
    {
        Traits* t = info->declaringScope()->getScopeTraitsAt(scope_index);
        LIns* scope = loadEnvScope();
        LIns* scopeobj = loadIns(LIR_ldp, offsetof(ScopeChain,_scopes) + scope_index*sizeof(Atom), scope, ACCSET_OTHER, LOAD_CONST);
        localSet(dest, atomToNativeRep(t, scopeobj), t);
    }

    void CodegenLIR::emitSwap(int i, int j) {
        LIns* t = localCopy(i);
        localSet(i, localCopy(j), state->value(j).traits);
        localSet(j, t, state->value(i).traits);
    }

    void CodegenLIR::emitKill(int i)
    {
        localSet(i, undefConst, NULL);
    }

#ifdef VMCFG_FASTPATH_ADD

#ifdef VMCFG_FASTPATH_ADD_INLINE

    // Emit code for the fastpath for int + intptr => intptr addition.
    // Branch to fallback label if rhs is not intptr, or result cannot be so represented due to overflow.
    //
    // 64-bit:
    //
    // FAST_ADD_INT_TO_ATOM(lhs, rhs, result, fallback)
    //    if ((rhs & kAtomTypeMask) != kIntptrType) goto fallback;   # punt if atom argument rhs is not intptr
    //    intptr_t lhsExtended = i;                                  # extend int argument lhs to atom size
    //    intptr_t lhsShifted = lhsExtended << (kAtomTypeSize+8);    # align lhs with 53-bit payload of rhs (see next step)
    //    intptr_t rhsShifted = rhs << 8;                            # left-justify 53-bit payload of rhs (note rhs is tagged)
    //    intptr_t sumShifted = lhsShifted + rhsShifted;             # add aligned values, producing 56-bit tagged sum, left-justified
    //    if (OVERFLOW) goto fallback;                               # punt on overflow, as sum will not fit in 53-bit field allotted
    //    intptr_t sum = sumShifted >> 8;                            # right-justify 56-bit tagged value (53 payload bits + 3 tag bits)
    //    result = sum;                                              # result is intptr atom, properly tagged
    //
    // 32-bit:
    //
    // FAST_ADD_INT_TO_ATOM(lhs, rhs, result, fallback)
    //    if ((rhs & kAtomTypeMask) != kIntptrType) goto fallback;   # punt if atom argument rhs is not intptr
    //    intptr_t lhsExtended = i;                                  # extend int argument lhs to atom size (a nop on 32-bit platforms)
    //    intptr_t lhsShifted = lhsExtended << kAtomTypeSize;        # left-justify 29-bit payload
    //    intptr_t lhsRestored = lhsShifted >> kAtomTypeSize;        # restore
    //    if (lhsRestored != lhsExtended) goto fallback;             # high-order bits were lost, value will not fit in 29-bit field allotted
    //    intptr_t sum = lhsShifted + rhs;                           # add left-justified lhs to tagged rhs, resulting in tagged result
    //    if (OVERFLOW) goto fallback;                               # punt on overflow, as sum will not fit in 29-bit field allotted
    //    result = sum;                                              # result is intptr atom, properly tagged
    //
    // Note: If lhs will not fit in 29 bits, the fastpath will fail even if the result may fit.  We expect this to be an
    // uncommon case.  Generating code as we do avoids extra tag manipulations that would be required if we did a full
    // 32-bit addition followed by a range check.

    void CodegenLIR::emitIntPlusAtomFastpath(int i, Traits* type, LIns* lhs, LIns* rhs, CodegenLabel &fallback)
    {
        LIns* tag = andp(rhs, AtomConstants::kAtomTypeMask);
        branchToLabel(LIR_jf, eqp(tag, AtomConstants::kIntptrType), fallback);
        LIns* lhsExtended = i2p(lhs);
        #ifdef AVMPLUS_64BIT
            // int argument is guaranteed to fit, but must restrict intptr result to 53 bit range
            // TODO: Consider maintaining 53-bit intptrs in pre-shifted form.
            LIns* lhsShifted = lshp(lhsExtended, AtomConstants::kAtomTypeSize + 8);
            LIns* rhsShifted = lshp(rhs, 8);
            LIns* sumShifted = branchJovToLabel(LIR_addjovp, lhsShifted, rhsShifted, fallback);
            LIns* sum = rshp(sumShifted, 8);
        #else
            // verify that int value will fit in intptr
            LIns* lhsShifted = lshp(lhsExtended, AtomConstants::kAtomTypeSize);
            LIns* lhsRestored = rshp(lhsShifted, AtomConstants::kAtomTypeSize);
            branchToLabel(LIR_jf, binaryIns(LIR_eqp, lhsRestored, lhsExtended), fallback);
            LIns* sum = branchJovToLabel(LIR_addjovp, lhsShifted, rhs, fallback);
        #endif
        localSet(i, sum, type);
    }
#endif /* VMCFG_FASTPATH_ADD_INLINE */

    // Emit code for int + atom => atom addition.
    // The usual helper function call may be bypassed with a fastpath for the int + intptr => intptr case:
    //
    //     intptr_t rhsa = CONVERT_TO_ATOM(rhs);                    # box atom if needed
    //     FAST_ADD_INT_TO_ATOM(lhs, rhsa, result, fallback);       # handle the fastpath, branching to fallback label on failure
    //     goto done;                                               # fastpath succeeded
    // fallback:
    //     result = op_add_a_ia(coreAddr, lhs, rhsa);               # fastpath failed, fall back to helper function
    // done:

    void CodegenLIR::emitAddIntToAtom(int i, int j, Traits* type)
    {
        LIns* rhs = loadAtomRep(j);
        LIns* lhs = localGet(i);
        #ifdef VMCFG_FASTPATH_ADD_INLINE
            CodegenLabel fallback("fallback");
            CodegenLabel done("done");
            suspendCSE();
            emitIntPlusAtomFastpath(i, type, lhs, rhs, fallback);
            JIT_EVENT(jit_add_a_ia_fast_intptr);
            branchToLabel(LIR_j, NULL, done);
            emitLabel(fallback);
            LIns* out = callIns(FUNCTIONID(op_add_a_ia), 3, coreAddr, lhs, rhs);
            localSet(i, out, type);
            JIT_EVENT(jit_add_a_ia_slow);
            emitLabel(done);
            resumeCSE();
        #else
            LIns* out = callIns(FUNCTIONID(op_add_a_ia), 3, coreAddr, lhs, rhs);
            localSet(i, out, type);
            JIT_EVENT(jit_add_a_ia);
        #endif
    }

    // Emit code for double + atom => atom addition.

    void CodegenLIR::emitAddDoubleToAtom(int i, int j, Traits* type)
    {
        LIns* rhs = loadAtomRep(j);
        LIns* lhs = localGetf(i);
        LIns* out = callIns(FUNCTIONID(op_add_a_da), 3, coreAddr, lhs, rhs);
        localSet(i, out, type);
        JIT_EVENT(jit_add_a_da);
    }

    // Emit code for atom + int => atom addition.
    // The usual helper function call may be bypassed with a fastpath for the intptr + int => intptr case:
    //
    //     intptr_t lhsa = CONVERT_TO_ATOM(lhs);                    # box atom if needed
    //     FAST_ADD_INT_TO_ATOM(rhs, lhsa, result, fallback);       # handle the fastpath, note it is OK to commute arguments here
    //     goto done;                                               # fastpath succeeded
    // fallback:
    //     result = op_add_a_ai(coreAddr, lhsa, rhs);               # fastpath failed, fall back to helper function
    // done:

    void CodegenLIR::emitAddAtomToInt(int i, int j, Traits* type)
    {
        LIns* lhs = loadAtomRep(i);
        LIns* rhs = localGet(j);
        #ifdef VMCFG_FASTPATH_ADD_INLINE
            CodegenLabel fallback("fallback");
            CodegenLabel done("done");
            suspendCSE();
            emitIntPlusAtomFastpath(i, type, rhs, lhs, fallback);
            JIT_EVENT(jit_add_a_ai_fast_intptr);
            branchToLabel(LIR_j, NULL, done);
            emitLabel(fallback);
            LIns* out = callIns(FUNCTIONID(op_add_a_ai), 3, coreAddr, lhs, rhs);
            localSet(i, out, type);
            JIT_EVENT(jit_add_a_ai_slow);
            emitLabel(done);
            resumeCSE();
        #else
            LIns* out = callIns(FUNCTIONID(op_add_a_ai), 3, coreAddr, lhs, rhs);
            localSet(i, out, type);
            JIT_EVENT(jit_add_a_ai);
        #endif
    }

    // Emit code for atom + double => atom addition.

    void CodegenLIR::emitAddAtomToDouble(int i, int j, Traits* type)
    {
        LIns* lhs = loadAtomRep(i);
        LIns* rhs = localGetf(j);
        LIns* out = callIns(FUNCTIONID(op_add_a_ad), 3, coreAddr, lhs, rhs);
        localSet(i, out, type);
        JIT_EVENT(jit_add_a_ad);
    }

    // Emit code for atom + atom => atom addition.
    //
    // We implement a fastpath for the intptr + intptr => intptr case:
    //
    // 64-bit:
    //
    //     intptr_t lhsa = CONVERT_TO_ATOM(lhs);                    # box atom if needed
    //     intptr_t rhsa = CONVERT_TO_ATOM(rhs);                    # box atom if needed
    //     if (((lhsa ^ kIntptrType) | (rhsa ^ kIntptrType)) & kAtomTypeMask) goto fallback;
    //     # both arguments are intptr atoms
    //     intptr_t lhsStripped = lhsa - kIntptrtype;               # zero out tag bits on lhs
    //     intptr_t lhsShifted = lhsStripped << 8;                  # left-justify 53-bit payload (followed by 0s in tag position)
    //     intptr_t rhsShifted = rhsa << 8;                         # align rhs payload and tag with left-justified lhs
    //     intptr_t sumShifted = lhsShifted + rhsShifted;           # add aligned values, producing 53-bit left-justified sum followed by tag
    //     if (OVERFLOW) goto fallback;
    //     result = sumShifted >> 8;                                # right-justify tagged sum (53-bit payload + 3-bit tag)
    //     goto done;
    // fallback:
    //     result = op_add_a_aa(coreAddr, lhsa, rhsa);              # handle the general case out-of-line
    // done:
    //
    // 32-bit:
    //
    //     intptr_t lhsa = CONVERT_TO_ATOM(lhs);                    # box atom if needed
    //     intptr_t rhsa = CONVERT_TO_ATOM(rhs);                    # box atom if needed
    //     if (((lhsa ^ kIntptrType) | (rhsa ^ kIntptrType)) & kAtomTypeMask) goto fallback;
    //     # both arguments are intptr atoms
    //     intptr_t lhsStripped = lhsa - kIntptrtype;               # zero out tag bits on lhs (note rhs retains its tag)
    //     intptr_t sum = lhsStripped + rhs;                        # add, producing 29-bit sum followed by 3-bit tag
    //     if (OVERFLOW) goto fallback;
    //     result = sum;
    //     goto done;
    // fallback:
    //     result = op_add_a_aa(coreAddr, lhsa, rhsa);              # handle the general case out-of-line
    // done:

    void CodegenLIR::emitAddAtomToAtom(int i, int j, Traits* type)
    {
        LIns* lhs = loadAtomRep(i);
        LIns* rhs = loadAtomRep(j);
        #ifdef VMCFG_FASTPATH_ADD_INLINE
            CodegenLabel fallback("fallback");
            CodegenLabel done("done");
            // intptr + intptr fastpath
            suspendCSE();
            LIns* t0 = xorp(lhs, AtomConstants::kIntptrType);
            LIns* t1 = xorp(rhs, AtomConstants::kIntptrType);
            LIns* t2 = binaryIns(LIR_orp, t0, t1);
            LIns* t3 = andp(t2, AtomConstants::kAtomTypeMask);
            branchToLabel(LIR_jf, eqp0(t3), fallback);
            LIns* lhsStripped = subp(lhs, AtomConstants::kIntptrType);
            #ifdef AVMPLUS_64BIT
                // restrict range of intptr result to 53 bits
                // since 64-bit int atoms expect exactly 53 bits of precision, shift bit 53+3 up into the sign bit
                LIns* lhsShifted = lshp(lhsStripped, 8);
                LIns* rhsShifted = lshp(rhs, 8);
                LIns* sumShifted = branchJovToLabel(LIR_addjovp, lhsShifted, rhsShifted, fallback);
                LIns* sum = rshp(sumShifted, 8);
            #else
                LIns* sum = branchJovToLabel(LIR_addjovp, lhsStripped, rhs, fallback);
            #endif
            localSet(i, sum, type);
            JIT_EVENT(jit_add_a_aa_fast_intptr);
            branchToLabel(LIR_j, NULL, done);
            emitLabel(fallback);
            LIns* out = callIns(FUNCTIONID(op_add_a_aa), 3, coreAddr, lhs, rhs);
            localSet(i, out, type);
            JIT_EVENT(jit_add_a_aa_slow);
            emitLabel(done);
            resumeCSE();
        #else
            LIns* out = callIns(FUNCTIONID(op_add_a_aa), 3, coreAddr, lhs, rhs);
            localSet(i, atomToNativeRep(type, out), type);
            JIT_EVENT(jit_add_a_aa);
        #endif
    }

#else /* VMCFG_FASTPATH_ADD */

    void CodegenLIR::emitAddAtomToAtom(int i, int j, Traits* type)
    {
        LIns* lhs = loadAtomRep(i);
        LIns* rhs = loadAtomRep(j);
        LIns* out = callIns(FUNCTIONID(op_add), 3, coreAddr, lhs, rhs);
        localSet(i, atomToNativeRep(type, out), type);
        JIT_EVENT(jit_add);
    }

#endif /* VMCFG_FASTPATH_ADD */

    void CodegenLIR::emitAdd(int i, int j, Traits* type)
    {
        const FrameValue& val1 = state->value(i);
        const FrameValue& val2 = state->value(j);
        if ((val1.traits == STRING_TYPE && val1.notNull) || (val2.traits == STRING_TYPE && val2.notNull)) {
            // string concatenation
            AvmAssert(type == STRING_TYPE);
            LIns* lhs = convertToString(i, true);
            LIns* rhs = convertToString(j, true);
            LIns* out = callIns(FUNCTIONID(concatStrings), 3, coreAddr, lhs, rhs);
            localSet(i,  out, type);
            JIT_EVENT(jit_add_a_ss);
        } else if (val1.traits && val2.traits && val1.traits->isNumeric() && val2.traits->isNumeric()) {
            // numeric + numeric
            // TODO: The tests for isNumeric() above could be isNumericOrBool(),
            // but a corresponding change would be needed in the verifier, resulting
            // in a slight change to the verifier's type inference algorithm.
            AvmAssert(type == NUMBER_TYPE);
            LIns* lhs = coerceToNumber(i);
            LIns* rhs = coerceToNumber(j);
            localSet(i, binaryIns(LIR_addd, lhs, rhs), type);
            JIT_EVENT(jit_add_a_nn);
#ifdef VMCFG_FASTPATH_ADD
        // If we arrive here, at least one argument is not known to be of a numeric type.
        // Thus, having determined one argument to be of a known numeric type, we will coerce
        // the other to an atom.  We speculate that the other argument will already be an atom
        // of type kIntptrType or kDoubleType, checking for these cases first.
        } else if (val1.traits == INT_TYPE) {
            // integer + atom
            AvmAssert(type == OBJECT_TYPE);
            emitAddIntToAtom(i, j, type);
        } else if (val1.traits == NUMBER_TYPE) {
            // double + atom
            AvmAssert(type == OBJECT_TYPE);
            emitAddDoubleToAtom(i, j, type);
        } else if (val2.traits == INT_TYPE) {
            // atom + integer
            AvmAssert(type == OBJECT_TYPE);
            emitAddAtomToInt(i, j, type);
        } else if (val2.traits == NUMBER_TYPE) {
            // atom + double
            AvmAssert(type == OBJECT_TYPE);
            emitAddAtomToDouble(i, j, type);
#endif
        } else {
            // Neither argument is known to be of a numeric type, so coerce both to atoms.
            AvmAssert(type == OBJECT_TYPE);
            emitAddAtomToAtom(i, j, type);
        }
    }

    void CodegenLIR::writeBlockStart(const FrameState* state)
    {
        this->state = state;
        // get the saved label for our block start and tie it to this location
        CodegenLabel& label = getCodegenLabel(state->abc_pc);
        emitLabel(label);
        emitSetPc(state->abc_pc);

#ifdef DEBUG
        memset(jit_sst, 0, framesize);
#endif

        // If this is a backwards branch, generate an interrupt check.
        if (interruptable && core->config.interrupts && state->targetOfBackwardsBranch) {
            LIns* interrupted = loadIns(LIR_ldi, offsetof(AvmCore,interrupted),
                    coreAddr, ACCSET_OTHER, LOAD_VOLATILE);
            LIns* cond = binaryIns(LIR_eqi, interrupted, InsConst(AvmCore::NotInterrupted));
            branchToLabel(LIR_jf, cond, interrupt_label);
        }
    }

    void CodegenLIR::writeOpcodeVerified(const FrameState* state, const uint8_t*, AbcOpcode)
    {
        verbose_only( if (vbWriter) { vbWriter->flush();} )
#ifdef DEBUG
        this->state = NULL; // prevent access to stale state
        int scopeTop = ms->scope_base() + state->scopeDepth;
        for (int i=0, n=state->sp()+1; i < n; i++) {
            if (i >= scopeTop && i < ms->stack_base())
                continue;
            const FrameValue& v = state->value(i);
            AvmAssert(!jit_sst[i] || jit_sst[i] == v.sst_mask);
        }
#else
        (void)state;
#endif
    }

    // this is a no-op for the JIT because we do all label patching in emitLabel().
    void CodegenLIR::writeFixExceptionsAndLabels(const FrameState*, const uint8_t*)
    {}

    void CodegenLIR::write(const FrameState* state, const uint8_t* pc, AbcOpcode opcode, Traits *type)
    {
      //AvmLog("CodegenLIR::write %x\n", opcode);
        this->state = state;
        emitSetPc(pc);
        const uint8_t* nextpc = pc;
        unsigned int imm30=0, imm30b=0;
        int imm8=0, imm24=0;
        AvmCore::readOperands(nextpc, imm30, imm24, imm30b, imm8);
        int sp = state->sp();

        switch (opcode) {
        case OP_nop:
        case OP_pop:
        case OP_label:
            // do nothing
            break;
        case OP_getlocal0:
        case OP_getlocal1:
        case OP_getlocal2:
        case OP_getlocal3:
            imm30 = opcode-OP_getlocal0;
            // hack imm30 and fall through
        case OP_getlocal:
            emitCopy(imm30, sp+1);
            break;
        case OP_setlocal0:
        case OP_setlocal1:
        case OP_setlocal2:
        case OP_setlocal3:
            imm30 = opcode-OP_setlocal0;
            // hack imm30 and fall through
        case OP_setlocal:
            emitCopy(sp, imm30);
            break;
        case OP_pushtrue:
            AvmAssert(type == BOOLEAN_TYPE);
            emitIntConst(sp+1, 1, type);
            break;
        case OP_pushfalse:
            AvmAssert(type == BOOLEAN_TYPE);
            emitIntConst(sp+1, 0, type);
            break;
        case OP_pushnull:
            AvmAssert(type == NULL_TYPE);
            emitPtrConst(sp+1, 0, type);
            break;
        case OP_pushundefined:
            AvmAssert(type == VOID_TYPE);
            emitPtrConst(sp+1, (void*)undefinedAtom, type);
            break;
        case OP_pushshort:
            AvmAssert(type == INT_TYPE);
            emitIntConst(sp+1, (signed short)imm30, type);
            break;
        case OP_pushbyte:
            AvmAssert(type == INT_TYPE);
            emitIntConst(sp+1, (signed char)imm8, type);
            break;
        case OP_pushstring:
            AvmAssert(type == STRING_TYPE);
            emitPtrConst(sp+1, pool->getString(imm30), type);
            break;
        case OP_pushnamespace:
            AvmAssert(type == NAMESPACE_TYPE);
            emitPtrConst(sp+1, pool->cpool_ns[imm30], type);
            break;
        case OP_pushint:
            AvmAssert(type == INT_TYPE);
            emitIntConst(sp+1, pool->cpool_int[imm30], type);
            break;
        case OP_pushuint:
            AvmAssert(type == UINT_TYPE);
            emitIntConst(sp+1, pool->cpool_uint[imm30], type);
            break;
        case OP_pushdouble:
            AvmAssert(type == NUMBER_TYPE);
            emitDoubleConst(sp+1, &pool->cpool_double[imm30]->value);
            break;
        case OP_pushnan:
            AvmAssert(type == NUMBER_TYPE);
            emitDoubleConst(sp+1, (double*)atomPtr(core->kNaN));
            break;
        case OP_lookupswitch:
            emit(opcode, uintptr_t(pc + imm24), imm30b /*count*/);
            break;
        case OP_throw:
        case OP_returnvalue:
        case OP_returnvoid:
            emit(opcode, sp);
            break;
        case OP_debugfile:
        {
#if defined VMCFG_VTUNE
            emit(opcode, (uintptr_t)pool->getString(imm30));
#elif defined DEBUGGER
            if (haveDebugger)
                emit(opcode, (uintptr_t)pool->getString(imm30));
#endif
           break;
        }
        case OP_dxns:
        {
            Stringp str = pool->getString(imm30);  // assume been checked already
            emit(opcode, (uintptr_t)str);
            break;
        }
        case OP_dxnslate:
            // codgen will call intern on the input atom.
            emit(opcode, sp);
            break;
        case OP_kill:
            emitKill(imm30);
            break;
        case OP_inclocal:
        case OP_declocal:
            emit(opcode, imm30, opcode==OP_inclocal ? 1 : -1, NUMBER_TYPE);
            break;
        case OP_inclocal_i:
        case OP_declocal_i:
            emit(opcode, imm30, opcode==OP_inclocal_i ? 1 : -1, INT_TYPE);
            break;
        case OP_lessthan:
        case OP_greaterthan:
        case OP_lessequals:
        case OP_greaterequals:
            emit(opcode, 0, 0, BOOLEAN_TYPE);
            break;

        case OP_getdescendants:
        {
            const Multiname *name = pool->precomputedMultiname(imm30);
            emit(opcode, (uintptr_t)name, 0, NULL);
            break;
        }

        case OP_checkfilter:
            emit(opcode, sp, 0, NULL);
            break;

        case OP_deleteproperty:
        {
            const Multiname *name = pool->precomputedMultiname(imm30);
            emit(opcode, (uintptr_t)name, 0, BOOLEAN_TYPE);
            break;
        }

        case OP_astype:
        {
            emit(OP_astype, (uintptr_t)type, sp, type && type->isMachineType() ? OBJECT_TYPE : type);
            break;
        }
        case OP_astypelate:
        {
            emit(OP_astypelate, 0, 0, type);
            break;
        }

        case OP_coerce:
        case OP_coerce_b:
        case OP_convert_b:
        case OP_coerce_o:
        case OP_coerce_a:
        case OP_convert_i:
        case OP_coerce_i:
        case OP_convert_u:
        case OP_coerce_u:
        case OP_convert_d:
        case OP_coerce_d:
        case OP_coerce_s:
            AvmAssert(
                    (opcode == OP_coerce    && type != NULL) ||
                    (opcode == OP_coerce_b  && type == BOOLEAN_TYPE) ||
                    (opcode == OP_convert_b && type == BOOLEAN_TYPE) ||
                    (opcode == OP_coerce_o  && type == OBJECT_TYPE) ||
                    (opcode == OP_coerce_a  && type == NULL) ||
                    (opcode == OP_convert_i && type == INT_TYPE) ||
                    (opcode == OP_coerce_i  && type == INT_TYPE) ||
                    (opcode == OP_convert_u && type == UINT_TYPE) ||
                    (opcode == OP_coerce_u  && type == UINT_TYPE) ||
                    (opcode == OP_convert_d && type == NUMBER_TYPE) ||
                    (opcode == OP_coerce_d  && type == NUMBER_TYPE) ||
                    (opcode == OP_coerce_s  && type == STRING_TYPE));
            emitCoerce(sp, type);
            break;

        case OP_istype:
        {
            // used when operator "is" RHS is a compile-time type constant
            //sp[0] = istype(sp[0], itraits);
            LIns* obj = loadAtomRep(sp);
            LIns* out = callIns(FUNCTIONID(istype), 2, obj, InsConstPtr(type));
            localSet(sp, out, BOOLEAN_TYPE);
            break;
        }

        case OP_istypelate:
        {
            // null check for the type value T in (x is T).  This also preserves
            // any side effects from loading T, even if we end up inlining T.itraits() as a const.
            Traits* class_type = state->value(sp).traits;
            emitCheckNull(localCopy(sp), class_type);
            LIns* obj = loadAtomRep(sp-1);
            LIns* istype_result;
            if (class_type && class_type->base == CLASS_TYPE) {
                // (x is T) where T is a class object: get T.itraits as constant.
                istype_result = callIns(FUNCTIONID(istype), 2, obj, InsConstPtr(class_type->itraits));
            } else {
                // RHS is unknown, call general istype
                istype_result = callIns(FUNCTIONID(istypelate), 3, env_param, obj, loadAtomRep(sp));
            }
            localSet(sp-1, istype_result, BOOLEAN_TYPE);
            break;
        }

        case OP_convert_o:
            // NOTE check null has already been done
            break;

        case OP_applytype:
            // * is ok for the type, as Vector classes have no statics
            // when we implement type parameters fully, we should do something here.
            emit(opcode, imm30/*argc*/, 0, NULL);
            break;

        case OP_newobject:
            emit(opcode, imm30, 0, OBJECT_TYPE);
            break;

        case OP_newarray:
            emit(opcode, imm30, 0, ARRAY_TYPE);
            break;

        case OP_newactivation:
            emit(opcode, 0, 0, info->activationTraits());
            break;

        case OP_newcatch:
        {
            ExceptionHandler* handler = &info->abc_exceptions()->exceptions[imm30];
            emit(opcode, 0, 0, handler->scopeTraits);
            break;
        }

        case OP_popscope:
            if (haveDebugger)
                emitKill(ms->local_count()/*scopeBase*/ + state->scopeDepth);
            break;

        case OP_getslot:
        {
            const FrameValue& obj = state->peek(1);
            int index = imm30-1;
            Traits* slotTraits = obj.traits ? obj.traits->getTraitsBindings()->getSlotTraits(index) : NULL;
            emitGetslot(index, sp, slotTraits);
            break;
        }

        case OP_setslot:
            emitSetslot(OP_setslot, imm30-1, sp-1);
            break;

        case OP_dup:
            emitCopy(sp, sp+1);
            break;

        case OP_swap:
            emitSwap(sp, sp-1);
            break;

        case OP_add:
            emitAdd(sp-1, sp, type);
            break;

        case OP_equals:
        case OP_strictequals:
        case OP_instanceof:
        case OP_in:
            emit(opcode, 0, 0, BOOLEAN_TYPE);
            break;

        case OP_not:
            AvmAssert(type == BOOLEAN_TYPE);
            emit(opcode, sp, 0, type);
            break;

        case OP_modulo:
        case OP_subtract:
        case OP_divide:
        case OP_multiply:
            emit(opcode, 0, 0, NUMBER_TYPE);
            break;

        case OP_increment:
        case OP_decrement:
            emit(opcode, sp, opcode == OP_increment ? 1 : -1, NUMBER_TYPE);
            break;

        case OP_increment_i:
        case OP_decrement_i:
            emit(opcode, sp, opcode == OP_increment_i ? 1 : -1, INT_TYPE);
            break;

        case OP_add_i:
        case OP_subtract_i:
        case OP_multiply_i:
            emit(opcode, 0, 0, INT_TYPE);
            break;

        case OP_negate:
            emit(opcode, sp, 0, NUMBER_TYPE);
            break;

        case OP_negate_i:
            emit(opcode, sp, 0, INT_TYPE);
            break;

        case OP_bitand:
        case OP_bitor:
        case OP_bitxor:
            emit(opcode, 0, 0, INT_TYPE);
            break;

        case OP_lshift:
        case OP_rshift:
            emit(opcode, 0, 0, INT_TYPE);
            break;

        case OP_urshift:
            emit(opcode, 0, 0, UINT_TYPE);
            break;

        case OP_bitnot:
            emit(opcode, sp, 0, INT_TYPE);
            break;

        case OP_typeof:
            emit(opcode, sp, 0, STRING_TYPE);
            break;

        case OP_debugline:
        {
#if defined VMCFG_VTUNE
            emit(opcode, imm30);
#elif defined DEBUGGER
            if (haveDebugger) {
                // we actually do generate code for these, in debugger mode
                emit(opcode, imm30);
            }
#endif
           break;
        }
        case OP_nextvalue:
        case OP_nextname:
            emit(opcode, 0, 0, NULL);
            break;

        case OP_hasnext:
            emit(opcode, 0, 0, INT_TYPE);
            break;

        case OP_hasnext2:
            emit(opcode, imm30, imm30b, BOOLEAN_TYPE);
            break;

        // sign extends
        case OP_sxi1:
        case OP_sxi8:
        case OP_sxi16:
            emit(opcode, sp, 0, INT_TYPE);
            break;

        // loads
        case OP_lix8:
        case OP_lix16:
        case OP_li8:
        case OP_li16:
        case OP_li32:
        case OP_lf32:
        case OP_lf64:
        {
            Traits* result = (opcode == OP_lf32 || opcode == OP_lf64) ? NUMBER_TYPE : INT_TYPE;
            emit(opcode, sp, 0, result);
            break;
        }

        // stores
        case OP_si8:
        case OP_si16:
        case OP_si32:
        case OP_sf32:
        case OP_sf64:
        {
            emit(opcode, 0, 0, VOID_TYPE);
            break;
        }

        case OP_getglobalscope:
            emitGetGlobalScope(sp+1);
            break;

        case OP_convert_s:
            localSet(sp, convertToString(sp, false), STRING_TYPE);
            break;

        case OP_esc_xelem:
        case OP_esc_xattr:
            emit(opcode, sp, 0, STRING_TYPE);
            break;

        case OP_debug:
            // ignored
            break;

        case OP_restargc:
        {
            // See documentation in writePrologue regarding rest arguments
            AvmAssert(info->needRestOrArguments() && info->lazyRest());
            LIns* out = callIns(FUNCTIONID(restargcHelper),
                                2,
                                localGetp(restLocal),
                                restArgc);
            localSet(sp, out, UINT_TYPE);
            break;
        }

        default:
            AvmAssertMsg(false, "unhandled opcode in CodegenLIR::write()");
            break;
        }
    }

    // coerce parameter types, starting at firstArg.
    void CodegenLIR::coerceArgs(MethodSignaturep mms, int argc, int firstArg)
    {
        int sp = state->sp();
        for (int arg = argc, n = 1; arg >= firstArg; arg--, n++) {
            Traits* target = (arg <= mms->param_count()) ? mms->paramTraits(arg) : NULL;
            int index = sp - (n - 1);
            emitCoerce(index, target);
        }
    }

    // Coerce parameter types, but not receiver.  The object in the reciever
    // position is the class or function object and we haven't called newInstance yet.
    // In this case, emitCall() will generate a call to newInstance, producing the
    // new object, then call its init function with the coerced arguments.
    void CodegenLIR::emitConstructCall(intptr_t method_id, int argc, LIns* ctor, Traits* ctraits)
    {
        Traits* itraits = ctraits->itraits;
        MethodInfo* m = itraits->init;
        MethodSignaturep mms = m->getMethodSignature();
        AvmAssert(mms->argcOk(argc)); // caller must check this before early binding to ctor

        coerceArgs(mms, argc, 1);
        emitCall(OP_construct, method_id, argc, ctor, ctraits, itraits, mms);
    }

    /**
     * emitCoerceCall is used when the jit finds an opportunity to early bind that the
     * driver did not.  It does the coersions using the signature of the callee, and
     * does not mutate FrameState.
     */
    void CodegenLIR::emitCoerceCall(AbcOpcode opcode, intptr_t method_id, int argc, MethodSignaturep mms)
    {
        AvmAssert(state->value(state->sp() - argc).notNull);  // make sure null check happened
        AvmAssert(opcode != OP_construct);
        AvmAssert(mms->argcOk(argc));
        coerceArgs(mms, argc, 0);
        emitCall(opcode, method_id, argc, mms->returnTraits(), mms);
    }

    void CodegenLIR::emitGetGlobalScope(int dest)
    {
        const ScopeTypeChain* scope = info->declaringScope();
        int captured_depth = scope->size;
        if (captured_depth > 0)
        {
            // enclosing scope
            emitGetscope(0, dest);
        }
        else
        {
            // local scope
            AvmAssert(state->scopeDepth > 0); // verifier checked.
            emitCopy(ms->scope_base(), dest);
        }
    }

    void CodegenLIR::writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, Traits *type)
    {
        this->state = state;
        emitSetPc(pc);
        switch (opcode) {
        case OP_iflt:
        case OP_ifle:
        case OP_ifnlt:
        case OP_ifnle:
        case OP_ifgt:
        case OP_ifge:
        case OP_ifngt:
        case OP_ifnge:
        case OP_ifeq:
        case OP_ifstricteq:
        case OP_ifne:
        case OP_ifstrictne:
        {
            int32_t offset = (int32_t) opd1;
            int lhs = state->sp()-1;
            emitIf(opcode, pc+4/*size*/+offset, lhs, lhs+1);
            break;
        }
        case OP_iftrue:
        case OP_iffalse:
        {
            int32_t offset = (int32_t) opd1;
            int sp = state->sp();
            emitIf(opcode, pc+4/*size*/+offset, sp, 0);
            break;
        }
        case OP_jump:
        {
            int32_t offset = (int32_t) opd1;
            emit(opcode, uintptr_t(pc+4/*size*/+offset));
            break;
        }
        case OP_getslot:
            emitGetslot(opd1, state->sp(), type);
            break;
        case OP_getglobalslot: {
            int32_t dest_index = state->sp(); // driver already incremented it
            uint32_t slot = opd1;
            emitGetGlobalScope(dest_index);
            emitGetslot(slot, dest_index, type /* slot type */);
            break;
        }
        case OP_setglobalslot:
            emitSetslot(OP_setglobalslot, opd1, 0 /* computed or ignored */);
            break;
        case OP_call:
            emit(opcode, opd1 /*argc*/, 0, NULL);
            break;

        case OP_construct:
        {
            const uint32_t argc = opd1;
            int ctor_index = state->sp() - argc;
            Traits* ctraits = state->value(ctor_index).traits;
            LIns* ctor = localCopy(ctor_index);
            emitConstruct(argc, ctor, ctraits);
            break;
        }
        case OP_getouterscope:
            emitGetscope(opd1, state->sp()+1);
            break;
        case OP_getscopeobject:
            emitCopy(opd1 + ms->scope_base(), state->sp()+1);
            break;
        case OP_newfunction:
            AvmAssert(pool->getMethodInfo(opd1)->declaringTraits() == type);
            emit(opcode, opd1, state->sp()+1, type);
            break;
        case OP_pushscope:
        case OP_pushwith:
            emitCopy(state->sp(), opd1);
            break;
        case OP_findpropstrict:
        case OP_findproperty:
        {
            const Multiname *name = pool->precomputedMultiname(opd1);
            emit(opcode, (uintptr_t)name, 0, OBJECT_TYPE);
            break;
        }
        case OP_findpropglobalstrict:
        {
            // NOTE opcode not supported, deoptimizing
            const Multiname *name = pool->precomputedMultiname(opd1);
            emit(OP_findpropstrict, (uintptr_t)name, 0, OBJECT_TYPE);
            break;
        }
        case OP_findpropglobal:
        {
            // NOTE opcode not supported, deoptimizing
            const Multiname *name = pool->precomputedMultiname(opd1);
            emit(OP_findproperty, (uintptr_t)name, 0, OBJECT_TYPE);
            break;
        }

        case OP_newclass:
        {
            Traits* ctraits = pool->getClassTraits(opd1);
            AvmAssert(ctraits == type);
            emit(opcode, (uintptr_t)(void*)ctraits, state->sp(), type);
            break;
        }

        case OP_finddef:
        {
            // opd1=name index
            // type=script->declaringTraits
            const Multiname *multiname = pool->precomputedMultiname(opd1);
            AvmAssert(multiname->isBinding());
            int32_t dest_index = state->sp() + 1;
            // This allocates a cache slot even if the finddef ultimately becomes dead.
            // As long as caches tend to be small compared to size of pool data and code,
            // filtering out dead cache lines isn't worth the complexity.
            LIns* slot = InsConst(finddef_cache_builder.allocateCacheSlot(opd1));
            LIns* out = callIns(FUNCTIONID(finddef_cache), 3, env_param, InsConstPtr(multiname), slot);
            localSet(dest_index, ptrToNativeRep(type, out), type);
            break;
        }

        case OP_restarg:
        {
            // See documentation in writePrologue regarding rest arguments
            AvmAssert(info->needRestOrArguments() && info->lazyRest());
            const Multiname *multiname = pool->precomputedMultiname(opd1);
            // The by-reference parameter &restLocal is handled specially for this
            // helper function in VarTracker::insCall and in CodegenLIR::analyze_call.
            LIns* out = callIns(FUNCTIONID(restargHelper),
                                6,
                                loadEnvToplevel(),
                                InsConstPtr(multiname),
                                loadAtomRep(state->sp()),
                                leaIns(restLocal * VARSIZE, vars),
                                restArgc,
                                (info->needRest() ?
                                    binaryIns(LIR_addp, ap_param, InsConstPtr((void*)(ms->rest_offset()))) :
                                    binaryIns(LIR_addp, ap_param, InsConstPtr((void*)sizeof(Atom)))));
            localSet(state->sp()-1, out, type);
            break;
        }

        default:
            // writeOp1() called with an improper opcode.
            AvmAssert(false);
            break;
        }
    }

    LIns* CodegenLIR::coerceToString(int index)
    {
        const FrameValue& value = state->value(index);
        Traits* in = value.traits;

        switch (bt(in)) {
        case BUILTIN_null:
        case BUILTIN_string:
            // fine to just load the pointer
            return localGetp(index);
        case BUILTIN_int:
            return callIns(FUNCTIONID(intToString), 2, coreAddr, localGet(index));
        case BUILTIN_uint:
            return callIns(FUNCTIONID(uintToString), 2, coreAddr, localGet(index));
        case BUILTIN_number:
            return callIns(FUNCTIONID(doubleToString), 2, coreAddr, localGetf(index));
        case BUILTIN_boolean: {
            // load "true" or "false" string constant from AvmCore.booleanStrings[]
            LIns *offset = binaryIns(LIR_lshp, i2p(localGet(index)), InsConst(PTR_SCALE));
            LIns *arr = InsConstPtr(&core->booleanStrings);
            return loadIns(LIR_ldp, 0, binaryIns(LIR_addp, arr, offset), ACCSET_OTHER, LOAD_CONST);
        }
        default:
            if (value.notNull) {
                // not eligible for CSE, and we know it's not null/undefined
                return emitStringCall(index, FUNCTIONID(string), true); // call string
            }
            return emitStringCall(index, FUNCTIONID(coerce_s), true); // call coerce_s
        }
    }

    /** emit code for * -> Number conversion */
    LIns* CodegenLIR::coerceToNumber(int index)
    {
        const FrameValue& value = state->value(index);
        Traits* in = value.traits;

        if (in && (in->isNumeric() || in == BOOLEAN_TYPE)) {
            return promoteNumberIns(in, index);
        } else {
            // * -> Number
#ifdef VMCFG_FASTPATH_FROMATOM
            //     double rslt;
            //     intptr_t val = CONVERT_TO_ATOM(arg);
            //     if ((val & kAtomTypeMask) != kIntptrType) goto not_intptr;   # test for kIntptrType tag
            //     # kIntptrType
            //     rslt = double(val >> kAtomTypeSize);                         # extract integer value and convert to double
            //     goto done;
            // not_intptr:
            //     if ((val & kAtomTypeMask) != kDoubleType) goto not_double;   # test for kDoubleType tag
            //     # kDoubleType
            //     rslt = *(val - kDoubleType);                                 # remove tag and dereference
            //     goto done;
            // not_double:
            //     rslt = number(val);                                          # slow path -- call helper
            // done:
            //     result = rslt;
            CodegenLabel not_intptr;
            CodegenLabel not_double;
            CodegenLabel done;
            suspendCSE();
            LIns* val = loadAtomRep(index);
            LIns* rslt = insAlloc(sizeof(double));
            LIns* tag = andp(val, AtomConstants::kAtomTypeMask);
            // kIntptrType
            branchToLabel(LIR_jf, eqp(tag, AtomConstants::kIntptrType), not_intptr);
            // Note that this works on 64bit platforms only if we are careful
            // to restrict the range of intptr values to those that fit within
            // the integer range of the double type.
            std(p2dIns(rshp(val, AtomConstants::kAtomTypeSize)), rslt, 0, ACCSET_OTHER);
            JIT_EVENT(jit_atom2double_fast_intptr);
            branchToLabel(LIR_j, NULL, done);
            emitLabel(not_intptr);
            // kDoubleType
            branchToLabel(LIR_jf, eqp(tag, AtomConstants::kDoubleType), not_double);
            std(ldd(subp(val, AtomConstants::kDoubleType), 0, ACCSET_OTHER), rslt, 0, ACCSET_OTHER);
            JIT_EVENT(jit_atom2double_fast_double);
            branchToLabel(LIR_j, NULL, done);
            emitLabel(not_double);
            std(callIns(FUNCTIONID(number), 1, val), rslt, 0, ACCSET_OTHER);
            JIT_EVENT(jit_atom2double_slow);
            emitLabel(done);
            resumeCSE();
            return ldd(rslt, 0, ACCSET_OTHER);
#else
            return callIns(FUNCTIONID(number), 1, loadAtomRep(index));
#endif
        }
    }

    LIns *CodegenLIR::emitStringCall(int index, const CallInfo *stringCall, bool preserveNull)
    {
        // Inline fast path for string conversion.
        // if preserveNull == false:
        //   if ((input & kAtomTypeMask) != kStringType) || (input == kStringType))
        //     output = stringCall (input);
        //   else
        //     output = input ^ kStringType;
        //
        // if preserveNull == true:
        //   if (input & kAtomTypeMask) != kStringType)
        //     output = stringCall (input);
        //   else
        //     output = input ^ kStringType;

        CodegenLabel not_stringptr;
        CodegenLabel done;
        suspendCSE();
        LIns* val = loadAtomRep(index);
        LIns* result = insAlloc(sizeof(intptr_t));
        LIns* tag = andp(val, AtomConstants::kAtomTypeMask);
        // kStringType
        branchToLabel(LIR_jf, eqp(tag, AtomConstants::kStringType), not_stringptr);
        if (!preserveNull) {
            // If our value is equal to kStringType, we have a null String ptr
            branchToLabel(LIR_jt, eqp(val, AtomConstants::kStringType), not_stringptr);
        }
        stp(xorp(val, AtomConstants::kStringType), result, 0, ACCSET_OTHER);
        branchToLabel(LIR_j, NULL, done);

        emitLabel(not_stringptr);
        stp(callIns(stringCall, 2, coreAddr, val), result, 0, ACCSET_OTHER);
        emitLabel(done);
        resumeCSE();
        return ldp(result, 0, ACCSET_OTHER);
    }

    // OP_convert_s needs a null String ptr to be converted to "null"
    // while our other usage prior to concatStrings handles null ptrs
    // correctly in AvmCore::concatStrings.  This function is different
    // than coerceToString in how undefinedAtom is handled:
    // convert: undefinedAtom -> "undefined"
    // coerce:  undefinedAtom -> "null" (see coerce_s)
    LIns* CodegenLIR::convertToString(int index, bool preserveNull)
    {
        const FrameValue& value = state->value(index);
        Traits* in = value.traits;
        Traits* stringType = STRING_TYPE;

        if (in != stringType || (!preserveNull && !value.notNull)) {
            if (in && (value.notNull || in->isNumeric() || in == BOOLEAN_TYPE)) {
                // convert is the same as coerce
                return coerceToString(index);
            } else {
                 // explicitly convert to string
                return emitStringCall(index, FUNCTIONID(string), preserveNull);
            }
        }

        // already String*
        return localGetp(index);
     }

    void CodegenLIR::writeNip(const FrameState* state, const uint8_t *pc)
    {
        this->state = state;
        emitSetPc(pc);
        emitCopy(state->sp(), state->sp()-1);
    }

    void CodegenLIR::writeMethodCall(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, MethodInfo* m, uintptr_t disp_id, uint32_t argc, Traits *type)
    {
        this->state = state;
        emitSetPc(pc);
        switch (opcode) {
        case OP_callproperty:
        case OP_callproplex:
        case OP_callpropvoid:
            AvmAssert(m->declaringTraits()->isInterface());
            emitTypedCall(OP_callinterface, ImtHolder::getIID(m), argc, type, m);
            break;
        case OP_callmethod:
            emitTypedCall(OP_callmethod, disp_id, argc, type, m);
            break;
        default:
            AvmAssert(false);
            break;
        }
    }

    void CodegenLIR::writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits *type)
    {
        this->state = state;
        emitSetPc(pc);
        int sp = state->sp();
        switch (opcode) {

        case OP_constructsuper:
        {
            Traits* base = info->declaringTraits()->base;
            // opd1=unused, opd2=argc
            if (base == OBJECT_TYPE && base->init->isTrivial()) {
                AvmAssert(opd2 == 0);   // The verifier should have caught a non-zero argc
                break;
            }
            emitTypedCall(OP_constructsuper, 0, opd2, VOID_TYPE, base->init);
            break;
        }

        case OP_setsuper:
        {
            const uint32_t index = opd1;
            const uint32_t n = opd2;
            Traits* base = type;
            int32_t ptrIndex = sp-(n-1);

            const Multiname* name = pool->precomputedMultiname(index);

            Binding b = toplevel->getBinding(base, name);
            Traits* propType = Traits::readBinding(base, b);
            const TraitsBindingsp basetd = base->getTraitsBindings();

            if (AvmCore::isSlotBinding(b)) {
                if (!AvmCore::isVarBinding(b)) {
                    // else, ignore write to readonly accessor
                    break;
                }
                int slot_id = AvmCore::bindingToSlotId(b);
                LIns* value = coerceToType(sp, propType);
                emitSetslot(OP_setslot, slot_id, ptrIndex, value);
                break;
            }
            if (AvmCore::isAccessorBinding(b)) {
                if (!AvmCore::hasSetterBinding(b)) {
                    // ignore write to readonly accessor
                    break;
                }
                // Invoke the setter
                int disp_id = AvmCore::bindingToSetterId(b);
                MethodSignaturep mms = basetd->getMethod(disp_id)->getMethodSignature();
                if (mms->argcOk(1)) {
                    emitCoerceCall(OP_callsuperid, disp_id, 1, mms);
                    break;
                }
            }
            // generic late bound case
            emit(opcode, (uintptr_t)name);
            break;
        }
        case OP_getsuper:
        {
            const uint32_t index = opd1;
            const uint32_t n = opd2;
            Traits* base = type;

            const Multiname* name = pool->precomputedMultiname(index);

            Binding b = toplevel->getBinding(base, name);
            Traits* propType = Traits::readBinding(base, b);

            if (AvmCore::isSlotBinding(b)) {
                int slot_id = AvmCore::bindingToSlotId(b);
                emitGetslot(slot_id, state->sp()-(n-1), propType);
                break;
            }
            if (AvmCore::hasGetterBinding(b)) {
                // Invoke the getter
                int disp_id = AvmCore::bindingToGetterId(b);
                const TraitsBindingsp basetd = base->getTraitsBindings();
                MethodSignaturep mms = basetd->getMethod(disp_id)->getMethodSignature();
                if (mms->argcOk(0)) {
                    emitCoerceCall(OP_callsuperid, disp_id, 0, mms);
                    break;
                }
            }

            // generic late-bound case
            emit(opcode, (uintptr_t)name, 0, propType);
            break;
        }
        case OP_callsuper:
        case OP_callsupervoid:
        {
            const uint32_t index = opd1;
            const uint32_t argc = opd2;
            Traits* base = type;
            const TraitsBindingsp basetd = base->getTraitsBindings();

            const Multiname *name = pool->precomputedMultiname(index);

            Binding b = toplevel->getBinding(base, name);

            if (AvmCore::isMethodBinding(b)) {
                int disp_id = AvmCore::bindingToMethodId(b);
                MethodSignaturep mms = basetd->getMethod(disp_id)->getMethodSignature();
                if (mms->argcOk(argc)) {
                    emitCoerceCall(OP_callsuperid, disp_id, argc, mms);
                    break;
                }
            }
            // generic late bound case
            emit(opcode, (uintptr_t)name, argc, NULL);
            break;
        }

        case OP_constructprop:
        {
            const uint32_t argc = opd2;
            const Multiname* name = pool->precomputedMultiname(opd1);

            const FrameValue& obj = state->peek(argc+1); // object
            Binding b = toplevel->getBinding(obj.traits, name);

            if (AvmCore::isSlotBinding(b))
            {
                int slot_id = AvmCore::bindingToSlotId(b);
                int ctor_index = state->sp() - argc;
                LIns* ctor = loadFromSlot(ctor_index, slot_id, type);
                emitConstruct(argc, ctor, type);
            }
            else
            {
                emit(opcode, (uintptr_t)name, argc, NULL);
            }
            break;
        }

        case OP_getproperty:
        {
            // NOTE opd2 is the stack offset to the reciever
            const Multiname* name = pool->precomputedMultiname(opd1);
            const FrameValue& obj = state->peek(opd2); // object
            Binding b = toplevel->getBinding(obj.traits, name);

            // early bind accessor
            if (AvmCore::hasGetterBinding(b))
            {
                // Invoke the getter
                int disp_id = AvmCore::bindingToGetterId(b);
                const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
                MethodInfo *f = objtd->getMethod(disp_id);
                AvmAssert(f != NULL);

                if (!obj.traits->isInterface()) {
                    emitTypedCall(OP_callmethod, disp_id, 0, type, f);
                }
                else {
                    emitTypedCall(OP_callinterface, ImtHolder::getIID(f), 0, type, f);
                }
                AvmAssert(type == f->getMethodSignature()->returnTraits());
            }
            else {
                emit(OP_getproperty, opd1, 0, type);
            }
            break;
        }

        case OP_setproperty:
        case OP_initproperty:
        {
            // opd2=n the stack offset to the reciever
            const Multiname *name = pool->precomputedMultiname(opd1);
            const FrameValue& obj = state->peek(opd2); // object
            Binding b = toplevel->getBinding(obj.traits, name);

            // early bind accessor
            if (AvmCore::hasSetterBinding(b))
            {
                // invoke the setter
                int disp_id = AvmCore::bindingToSetterId(b);
                const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
                MethodInfo *f = objtd->getMethod(disp_id);
                AvmAssert(f != NULL);

                if (!obj.traits->isInterface()) {
                    emitTypedCall(OP_callmethod, disp_id, 1, type, f);
                }
                else {
                    emitTypedCall(OP_callinterface, ImtHolder::getIID(f), 1, type, f);
                }
            }
            else {
                emit(opcode, (uintptr_t)name);
            }
            break;
        }

        case OP_setslot:
            emitSetslot(OP_setslot, opd1, opd2);
            break;

        case OP_callproperty:
        case OP_callproplex:
        case OP_callpropvoid:
        {
            emit(opcode, opd1, opd2, NULL);
            break;
        }

        case OP_callstatic: {
            uint32_t method_id = opd1;
            uint32_t argc = opd2;
            emitTypedCall(OP_callstatic, method_id, argc, type, pool->getMethodInfo(method_id));
            break;
        }

        default:
            AvmAssert(false);
            break;
        }
    }

    void CodegenLIR::emitIntConst(int index, int32_t c, Traits* type)
    {
        localSet(index, lirout->insImmI(c), type);
    }

    void CodegenLIR::emitPtrConst(int index, void* c, Traits* type)
    {
        localSet(index, lirout->insImmP(c), type);
    }

    void CodegenLIR::emitDoubleConst(int index, const double* pd)
    {
        localSet(index, lirout->insImmD(*pd), NUMBER_TYPE);
    }

    void CodegenLIR::writeCoerce(const FrameState* state, uint32_t loc, Traits* result)
    {
        this->state = state;
        emitSetPc(state->abc_pc);
        emitCoerce(loc, result);
    }

    void CodegenLIR::emitCoerce(uint32_t loc, Traits* result)
    {
        localSet(loc, coerceToType(loc, result), result);
    }

    // If we have already generated this specialized function, return our
    // prior entry instead of re-specializing the same function.
    LIns* CodegenLIR::getSpecializedCall(LIns* origCall)
    {
        if (!specializedCallHashMap)
            return NULL;

        return specializedCallHashMap->get(origCall);
    }

    // Track any specialized function so if we try to specialize the same function
    // again we can re-use the original one.
    LIns * CodegenLIR::addSpecializedCall(LIns* origCall, LIns* specializedCall)
    {
        if (!specializedCallHashMap)
            specializedCallHashMap = new (*alloc1) HashMap<LIns *, LIns *>(*alloc1);

        specializedCallHashMap->put(origCall, specializedCall);

        return specializedCall;
    }

    // Attempt to replace a call with a call to another function, using the
    // mapping given by 'specs'.  The intent is that the replacement function
    // yield equivalent semantics in the context in which it will appear, but
    // more efficiently.  A single replacement is generated for each call LIns*,
    // and subquent requests to perform the same specializatoin will return
    // the previously-constructed replacement LIns*.  If an attempt is made to
    // specialize a function call for which no replacement is given in 'specs', we
    // return NULL.  It is assumed that the replacement function will return
    // an int32 value.

    LIns* CodegenLIR::specializeIntCall(LIns* call, Specialization* specs)
    {
        LIns *priorCall = getSpecializedCall(call);
        if (priorCall)
            return priorCall;

        const CallInfo *ci = call->callInfo();
        int i = 0;
        while (specs[i].oldFunc != NULL) {
            if (specs[i].oldFunc == ci) {
                const CallInfo* nci = specs[i].newFunc;
                AvmAssert(nci->returnType() == ARGTYPE_I);
                LIns* specialization = callIns(nci, 2, call->arg(1), call->arg(0), INT_TYPE);
                addSpecializedCall(call, specialization);
                return specialization;
            }
            i++;
        }
        return NULL;
    }

    // Return true if we are promoting an int or uint to a double
    bool CodegenLIR::isPromote(LOpcode op)
    {
        return op == LIR_ui2d || op == LIR_i2d;
    }

    // Return non-null LIns* if input is a constant that fits into a int32_t
    LIns* CodegenLIR::imm2Int(LIns* imm)
    {
        if (imm->isImmI())
            ; // just use imm
        else if (imm->isImmD()) {
            double val = imm->immD();
            double cvt = (int32_t)val;
            if (val == 0 || val == cvt)
                imm = InsConst((int32_t)cvt);
            else
                imm = 0; // can't convert
        } else {
            imm = 0; // non-imm
        }
        return imm;
    }

    static Specialization coerceDoubleToInt[] = {
        { FUNCTIONID(String_charCodeAtFI),    FUNCTIONID(String_charCodeAtIU) },
        { FUNCTIONID(String_charCodeAtFU),    FUNCTIONID(String_charCodeAtIU) },
        { FUNCTIONID(String_charCodeAtFF),    FUNCTIONID(String_charCodeAtIF) },
        { 0, 0 }
    };

    // Perform coercion from a double to integer.
    // Try various optimization to avoid double math if possible
    // and specialize charCodeAt to an faster integer version.
    LIns* CodegenLIR::coerceNumberToInt(int loc)
    {
        LIns *arg = localGetf(loc);
        LOpcode op = arg->opcode();
        switch (op) {
            case LIR_ui2d:
            case LIR_i2d:
                return arg->oprnd1();
            case LIR_addd:
            case LIR_subd:
            case LIR_muld: {
                LIns *a = arg->oprnd1();
                a = isPromote(a->opcode()) ? a->oprnd1() : imm2Int(a);
                if (a) {
                    LIns *b = arg->oprnd2();
                    b = isPromote(b->opcode()) ? b->oprnd1() : imm2Int(b);
                    if (b)
                        return lirout->ins2(arithOpcodeD2I(op), a, b);
                }
                break;
            }
            // optimize integer division when divisor is non-zero constant integer
            case LIR_divd: {
                LIns *a = arg->oprnd1();
                LOpcode aOpcode = a->opcode();
                a = isPromote(aOpcode) ? a->oprnd1() : imm2Int(a);
                if (a) {
                    LIns *b = arg->oprnd2();
                    b = imm2Int(b);
                    if (b) {
                        int32_t intConst = b->immI();
                        if (intConst) {
                            // use faster unsigned right shift if our arg is unsigned and
                            // we have just one bit set in the divisor.
                            if (exactlyOneBit(intConst) && aOpcode == LIR_ui2d) {
                                return lirout->ins2(LIR_rshui, a, lirout->insImmI(msbSet32(intConst)));
                            }
#if NJ_DIVI_SUPPORTED
                            else {
                                return lirout->ins2(LIR_divi, a, b);
                            }
#endif // NJ_DIVI_SUPPORTED
                        }
                    }
                }
                break;
            }
#ifdef AVMPLUS_64BIT
            case LIR_immq:
#endif // AVMPLUS_64BIT
            case LIR_immd:
                // const fold
                return InsConst(AvmCore::integer_d(arg->immD()));
            // Try to replace a call returning a double, which will then be
            // coerced to an integer, with a call that will produce an equivalent
            // integer value directly.
            case LIR_calld: {
                LIns* specialized = specializeIntCall(arg, coerceDoubleToInt);
                if (specialized)
                    return specialized;
            }
        }

        // For SSE capable machines, inline our double to integer conversion
        // using the CVTTSD2SI instruction.  If we get a 0x80000000 return
        // value, our double is outside the valid integer range we fallback
        // to calling doubleToInt32.
#if defined AVMPLUS_IA32 || defined AVMPLUS_AMD64
#ifndef AVMPLUS_AMD64
        SSE2_ONLY(if(core->config.njconfig.i386_sse2))
#endif // AVMPLUS_AMD64
        {
            suspendCSE();
            CodegenLabel skip_label("goodint");
            LIns* intResult = insAlloc(sizeof(int32_t));
            LIns* fastd2i = lirout->ins1(LIR_d2i, arg);
            sti(fastd2i, intResult, 0, ACCSET_STORE_ANY);      // int32_t index
            LIns *c = binaryIns(LIR_eqi, fastd2i, InsConst(1L << 31));
            branchToLabel(LIR_jf, c, skip_label);
            LIns *funcCall = callIns(FUNCTIONID(doubleToInt32), 1, arg);
            sti(funcCall, intResult, 0, ACCSET_STORE_ANY);      // int32_t index
            emitLabel(skip_label);
            LIns *result = loadIns(LIR_ldi, 0, intResult, ACCSET_LOAD_ANY);
            resumeCSE();
            return result;
        }
#endif // AVMPLUS_IA32 || AVMPLUS_AMD64

#ifndef AVMPLUS_AMD64
         return callIns(FUNCTIONID(integer_d), 1, arg);
#endif // AVMPLUS_AMD64
    }


    LIns* CodegenLIR::coerceToType(int loc, Traits* result)
    {
        const FrameValue& value = state->value(loc);
        Traits* in = value.traits;
        LIns* expr;

        if (result == NULL)
        {
            // coerce to * is simple, we just save the atom rep.
            expr = loadAtomRep(loc);
        }
        else if (result == OBJECT_TYPE)
        {
            if (in == NULL || in == VOID_TYPE)
            {
                // value already boxed but we need to coerce undefined->null
                if (!value.notNull) {
                    // v == undefinedAtom ? nullObjectAtom : v;
                    LIns *v = localGetp(loc);
                    expr = choose(eqp(v, undefConst), nullObjectAtom, v);
                } else {
                    expr = loadAtomRep(loc);
                }
            }
            else
            {
                // value cannot be undefined so just box it
                expr = loadAtomRep(loc);
            }
        }
        else if (!result->isMachineType() && in == NULL_TYPE)
        {
            // it's fine to coerce null to a pointer type, just load the value
            expr = localGetp(loc);
        }
        else if (result == NUMBER_TYPE)
        {
            expr = coerceToNumber(loc);
        }
        else if (result == INT_TYPE)
        {
            if (in == UINT_TYPE || in == BOOLEAN_TYPE || in == INT_TYPE)
            {
                // just load the value
                expr = localGet(loc);
            }
            else if (in == NUMBER_TYPE)
            {
                // narrowing conversion number->int
                expr = coerceNumberToInt(loc);
            }
            else
            {
                // * -> int
                expr = callIns(FUNCTIONID(integer), 1, loadAtomRep(loc));
            }
        }
        else if (result == UINT_TYPE)
        {
            if (in == INT_TYPE || in == BOOLEAN_TYPE || in == UINT_TYPE)
            {
                // just load the value
                expr = localGet(loc);
            }
            else if (in == NUMBER_TYPE)
            {
                expr = coerceNumberToInt(loc);
            }
            else
            {
                // * -> uint
                expr = callIns(FUNCTIONID(toUInt32), 1, loadAtomRep(loc));
            }
        }
        else if (result == BOOLEAN_TYPE)
        {
            if (in == BOOLEAN_TYPE)
            {
                expr = localGet(loc);
            }
            else if (in == NUMBER_TYPE)
            {
                expr = callIns(FUNCTIONID(doubleToBool), 1, localGetf(loc));
            }
            else if (in == INT_TYPE || in == UINT_TYPE)
            {
                // int to bool: b = (i==0) == 0
                expr = eqi0(eqi0(localGet(loc)));
            }
            else if (in && !in->hasComplexEqualityRules())
            {
                // ptr to bool: b = (p==0) == 0
                expr = eqi0(eqp0(localGetp(loc)));
            }
            else
            {
                // * -> Boolean
                expr = callIns(FUNCTIONID(boolean), 1, loadAtomRep(loc));
            }
        }
        else if (result == STRING_TYPE)
        {
            expr = coerceToString(loc);
        }
        else if (in && !in->isMachineType() && !result->isMachineType()
               && in != STRING_TYPE && in != NAMESPACE_TYPE)
        {
            if (!Traits::canAssign(result, in)) {
                // coerceobj_obj() is void, but we mustn't optimize it out; we only call it when required
                callIns(FUNCTIONID(coerceobj_obj), 3,
                    env_param, localGetp(loc), InsConstPtr(result));
            }
            // the input pointer has now been checked but it's still the same value.
            expr = localGetp(loc);
        }
        else if (!result->isMachineType() && result != NAMESPACE_TYPE)
        {
            // result is a ScriptObject based type.
            expr = downcast_obj(loadAtomRep(loc), env_param, result);
        }
        else if (result == NAMESPACE_TYPE && in == NAMESPACE_TYPE)
        {
            expr = localGetp(loc);
        }
        else
        {
            LIns* value = loadAtomRep(loc);
            // resultValue = coerce(caller_env, inputValue, traits)
            LIns* out = callIns(FUNCTIONID(coerce), 3,
                env_param, value, InsConstPtr(result));

            // store the result
            expr = atomToNativeRep(result, out);
        }
        return expr;
    }

    void CodegenLIR::writeCheckNull(const FrameState* state, uint32_t index)
    {
        this->state = state;
        emitSetPc(state->abc_pc);
        emitCheckNull(localCopy(index), state->value(index).traits);
    }

    void CodegenLIR::emitCheckNull(LIns* ptr, Traits* t)
    {
        // The result is either unchanged or an exception is thrown, so
        // we don't save the result.  This is the null pointer check.
        if (!isNullable(t) || varTracker->isNotNull(ptr))
            return;
        _nvprof("nullcheck",1);
        BuiltinType ty = bt(t);
        if (valueStorageType(ty) == SST_atom) {
            _nvprof("nullcheck atom", 1);
            if (ty != BUILTIN_object) {
                // If we know atom value is an object, it cannot be undefined.
                branchToLabel(LIR_jt, eqp(ptr, undefConst), upe_label); // if (p == undefined) throw undefined pointer error
            }
            branchToLabel(LIR_jt, ltup(ptr, undefConst), npe_label);    // if (p < undefined) throw null pointer error
        } else {
            _nvprof("nullcheck ptr", 1);
            branchToLabel(LIR_jt, eqp0(ptr), npe_label);
        }
        varTracker->setNotNull(ptr, t);
    }

    // Save our current PC location for the catch finder later.
    void CodegenLIR::emitSetPc(const uint8_t* pc)
    {
        AvmAssert(state->abc_pc == pc);
        // update bytecode ip if necessary
        if (_save_eip && lastPcSave != pc) {
            stp(InsConstPtr((void*)(pc - code_pos)), _save_eip, 0, ACCSET_OTHER);
            lastPcSave = pc;
        }
    }

    // This is for VTable->createInstanceProc which is called by OP_construct
    FASTFUNCTION(CALL_INDIRECT, SIG2(P,P,P), createInstanceProc)

    bool CodegenLIR::specializeOneArgFunction(Traits *result, const CallInfo *ciInt, const CallInfo *ciUint, const CallInfo *ciNumber)
    {
        // One arg that may be a number, int or uint
        // charCodeAt, charAt
        int op1 = state->sp();
        LIns *arg = localGetf(op1);
        // argument is a constant integer
        if (arg->isImmD() && ((double)(int32_t)arg->immD() == arg->immD())) {
            localSet(op1-1, callIns(ciInt, 2, localGetp(op1-1), InsConst((int32_t)arg->immD())), result);
        }
        else if (arg->opcode() == LIR_i2d) {
            localSet(op1-1, callIns(ciInt, 2, localGetp(op1-1), arg->oprnd1()), result);
        }
        else if (arg->opcode() == LIR_ui2d) {
            localSet(op1-1, callIns(ciUint, 2, localGetp(op1-1), arg->oprnd1()), result);
        }
        else {
            localSet(op1-1, callIns(ciNumber, 2, localGetp(op1-1), arg), result);
        }
        return true;
    }

    bool CodegenLIR::inlineBuiltinFunction(AbcOpcode, intptr_t, int argc, Traits* result, MethodInfo* mi)
    {
        if (haveDebugger)
            return false;

        if (mi->pool() == core->builtinPool && mi->isFinal()) {
            switch (mi->method_id()) {
                case avmplus::NativeID::native_script_function_isNaN: {
                    if (argc == 1) {
#ifndef AVMPLUS_SSE2_ALWAYS
                        // On x86, inline NaN compares are slower with non-SSE instructions
                        SSE2_ONLY(if(core->config.njconfig.i386_sse2))
#endif // AVMPLUS_SSE2_ALWAYS
                        {
                            int op1 = state->sp();
                            LIns *f = localGetf(op1);
                            if (isPromote(f->opcode())) {
                                localSet(op1-1, InsConst(0), result);
                            }
                            else {
                                localSet(op1-1, binaryIns(LIR_eqi, binaryIns(LIR_eqd, f, f), InsConst(0)), result);
                            }
                            return true;
                        }
                    }
                    break;
                }
                case avmplus::NativeID::String_AS3_charCodeAt: {
                    if (argc == 1) {
                        return specializeOneArgFunction(result, FUNCTIONID(String_charCodeAtFI), FUNCTIONID(String_charCodeAtFU), FUNCTIONID(String_charCodeAtFF));
                    }
                    break;
                }
                case avmplus::NativeID::String_AS3_charAt: {
                    if (argc == 1) {
                        return specializeOneArgFunction(result, FUNCTIONID(String_charAtI), FUNCTIONID(String_charAtU), FUNCTIONID(String_charAtF));
                    }
                    break;
                }
            }
        }

        return false;
    }

#ifdef DEBUG
    /**
     * emitTypedCall is used when the Verifier has found an opportunity to early bind,
     * and has already coerced arguments from whatever native type is discovered, to
     * the required types.  emitTypedCall() then just double-checks (via assert) that
     * the arg types are already correct.
     */
    void CodegenLIR::emitTypedCall(AbcOpcode opcode, intptr_t method_id, int argc, Traits* result, MethodInfo* mi)
    {
        AvmAssert(opcode != OP_construct);
        AvmAssert(state->value(state->sp() - argc).notNull); // make sure null check happened

        MethodSignaturep ms = mi->getMethodSignature();
        AvmAssert(ms->argcOk(argc));
        int objDisp = state->sp() - argc;
        for (int arg = 0; arg <= argc && arg <= ms->param_count(); arg++)
            AvmAssert(Traits::canAssign(state->value(objDisp+arg).traits, ms->paramTraits(arg)));
        for (int arg = ms->param_count()+1; arg <= argc; arg++) {
            BuiltinType t = bt(state->value(objDisp+arg).traits);
            AvmAssert(valueStorageType(t) == SST_atom);
        }

        if (inlineBuiltinFunction(opcode, method_id, argc, result, mi))
            return;

        emitCall(opcode, method_id, argc, result, ms);
    }
#else
    REALLY_INLINE void CodegenLIR::emitTypedCall(AbcOpcode opcode, intptr_t method_id, int argc, Traits* result, MethodInfo* mi)
    {
        if (inlineBuiltinFunction(opcode, method_id, argc, result, mi))
            return;

        emitCall(opcode, method_id, argc, result, mi->getMethodSignature());
    }
#endif

    void CodegenLIR::emitCall(AbcOpcode opcode, intptr_t method_id, int argc, Traits* result, MethodSignaturep ms)
    {
        int objDisp = state->sp() - argc;
        LIns* obj = localCopy(objDisp);
        Traits* objType = state->value(objDisp).traits;
        emitCall(opcode, method_id, argc, obj, objType, result, ms);
    }

    void CodegenLIR::emitCall(AbcOpcode opcode, intptr_t method_id, int argc, LIns* obj, Traits* objType, Traits* result, MethodSignaturep ms)
    {
        int sp = state->sp();
        int dest = sp-argc;
        int objDisp = dest;

        LIns *method = NULL;
        LIns *iid = NULL;
        switch (opcode)
        {
        case OP_constructsuper:
        {
            // env->vtable->base->init->enter32v(argc, ...);
            LIns* vtable = loadEnvVTable();
            LIns* base = loadIns(LIR_ldp, offsetof(VTable,base), vtable, ACCSET_OTHER, LOAD_CONST);
            method = loadIns(LIR_ldp, offsetof(VTable,init), base, ACCSET_OTHER, LOAD_CONST);
            break;
        }
        case OP_callmethod:
        {
            // stack in:  obj arg1..N
            // stack out: result
            // sp[-argc] = callmethod(disp_id, argc, ...);
            // method_id is disp_id of virtual method
            LIns* vtable = loadVTable(obj, objType);
            method = loadIns(LIR_ldp, int32_t(offsetof(VTable,methods)+sizeof(MethodEnv*)*method_id), vtable, ACCSET_OTHER, LOAD_CONST);
            break;
        }
        case OP_callsuperid:
        {
            // stack in: obj arg1..N
            // stack out: result
            // method_id is disp_id of super method
            LIns* declvtable = loadEnvVTable();
            LIns* basevtable = loadIns(LIR_ldp, offsetof(VTable, base), declvtable, ACCSET_OTHER, LOAD_CONST);
            method = loadIns(LIR_ldp, int32_t(offsetof(VTable,methods)+sizeof(MethodEnv*)*method_id), basevtable, ACCSET_OTHER, LOAD_CONST);
            break;
        }
        case OP_callstatic:
        {
            // stack in: obj arg1..N
            // stack out: result
            LIns* abcenv = loadEnvAbcEnv();
            method = loadIns(LIR_ldp, int32_t(offsetof(AbcEnv,m_methods)+sizeof(MethodEnv*)*method_id), abcenv, ACCSET_OTHER, LOAD_CONST);
            break;
        }
        case OP_callinterface:
        {
            // method_id is pointer to interface method name (multiname)
            uint32_t index = ImtHolder::hashIID(method_id);
            LIns* vtable = loadVTable(obj, objType);
            // note, could be MethodEnv* or ImtThunkEnv*
            method = loadIns(LIR_ldp, offsetof(VTable, imt.entries) + index * sizeof(ImtThunkEnv*), vtable, ACCSET_OTHER, LOAD_CONST);
            iid = InsConstPtr((void*)method_id);
            break;
        }
        case OP_construct:
        {
            // stack in: ctor arg1..N
            // stack out: newinstance
            LIns* vtable = loadVTable(obj, objType);
            LIns* ivtable = loadIns(LIR_ldp, offsetof(VTable, ivtable), vtable, ACCSET_OTHER, LOAD_CONST);
            method = loadIns(LIR_ldp, offsetof(VTable, init), ivtable, ACCSET_OTHER, LOAD_CONST);
            LIns* createInstanceProc = loadIns(LIR_ldp, offsetof(VTable, createInstanceProc), ivtable, ACCSET_OTHER);
            obj = callIns(FUNCTIONID(createInstanceProc), 2, createInstanceProc, obj);
            objType = result;
            // the call below to the init function is void; the expression result we want
            // is the new object, not the result from the init function.  save it now.
            localSet(dest, obj, result);
            break;
        }
        default:
            AvmAssert(false);
        }

        // store args for the call
        LIns* ap = insAlloc(sizeof(Atom)); // we will update this size, below
        int disp = 0;
        int pad = 0;

        int param_count = ms->param_count();
        // LIR_allocp of any size >= 8 is always 8-aligned.
        // if the first double arg would be unaligned, add padding to align it.
    #if !defined AVMPLUS_64BIT
        for (int i=0; i <= argc && i <= param_count; i++) {
            if (ms->paramTraits(i) == NUMBER_TYPE) {
                if ((disp&7) != 0) {
                    // this double would be unaligned, so add some padding
                    pad = 8-(disp&7); // should be 4
                }
                break;
            }
            else {
                disp += sizeof(Atom);
            }
        }
    #endif

        disp = pad;
        for (int i=0, index=objDisp; i <= argc; i++, index++) {
            Traits* paramType = i <= param_count ? ms->paramTraits(i) : NULL;
            LIns* v;
            switch (bt(paramType)) {
            case BUILTIN_number:
                v = (i == 0) ? obj : lirout->insLoad(LIR_ldd, vars, index * VARSIZE, ACCSET_VARS);
                std(v, ap, disp, ACCSET_OTHER);
                disp += sizeof(double);
                break;
            case BUILTIN_int:
                v = (i == 0) ? obj : lirout->insLoad(LIR_ldi, vars, index * VARSIZE, ACCSET_VARS);
                stp(i2p(v), ap, disp, ACCSET_OTHER);
                disp += sizeof(intptr_t);
                break;
            case BUILTIN_uint:
            case BUILTIN_boolean:
                v = (i == 0) ? obj : lirout->insLoad(LIR_ldi, vars, index * VARSIZE, ACCSET_VARS);
                stp(ui2p(v), ap, disp, ACCSET_OTHER);
                disp += sizeof(uintptr_t);
                break;
            default:
                v = (i == 0) ? obj : lirout->insLoad(LIR_ldp, vars, index * VARSIZE, ACCSET_VARS);
                stp(v, ap, disp, ACCSET_OTHER);
                disp += sizeof(void*);
                break;
            }
        }

        // patch the size to what we actually need
        ap->setSize(disp);

        LIns* target = loadIns(LIR_ldp, offsetof(MethodEnvProcHolder,_implGPR), method, ACCSET_OTHER);
        LIns* apAddr = leaIns(pad, ap);

        LIns *out;
        BuiltinType rbt = bt(result);
        if (!iid) {
            const CallInfo *fid;
            switch (rbt) {
            case BUILTIN_number:
                fid = FUNCTIONID(fcalli);
                break;
            case BUILTIN_int: case BUILTIN_uint: case BUILTIN_boolean:
                fid = FUNCTIONID(icalli);
                break;
            default:
                fid = FUNCTIONID(acalli);
                break;
            }
            out = callIns(fid, 4, target, method, InsConst(argc), apAddr);
        } else {
            const CallInfo *fid;
            switch (rbt) {
            case BUILTIN_number:
                fid = FUNCTIONID(fcallimt);
                break;
            case BUILTIN_int: case BUILTIN_uint: case BUILTIN_boolean:
                fid = FUNCTIONID(icallimt);
                break;
            default:
                fid = FUNCTIONID(acallimt);
                break;
            }
            out = callIns(fid, 5, target, method, InsConst(argc), apAddr, iid);
        }

        // ensure the stack-allocated args are live until after the call
        liveAlloc(ap);

        if (opcode != OP_constructsuper && opcode != OP_construct)
            localSet(dest, out, result);
    }

    LIns* CodegenLIR::loadFromSlot(int ptr_index, int slot, Traits* slotType)
    {
        Traits *t = state->value(ptr_index).traits;
        LIns *ptr = localGetp(ptr_index);
        AvmAssert(state->value(ptr_index).notNull);
        AvmAssert(isPointer((int)ptr_index)); // obj

        AvmAssert(t->isResolved());
        const TraitsBindingsp tb = t->getTraitsBindings();
        int offset = tb->getSlotOffset(slot);

        // get
        LOpcode op;
        switch (bt(slotType)) {
        case BUILTIN_number:    op = LIR_ldd;   break;
        case BUILTIN_int:
        case BUILTIN_uint:
        case BUILTIN_boolean:   op = LIR_ldi;    break;
        default:                op = LIR_ldp;   break;
        }
        return loadIns(op, offset, ptr, ACCSET_OTHER);
    }

    void CodegenLIR::emitGetslot(int slot, int ptr_index, Traits *slotType)
    {
        localSet(ptr_index, loadFromSlot(ptr_index, slot, slotType), slotType);
    }

    void CodegenLIR::emitSetslot(AbcOpcode opcode, int slot, int ptr_index)
    {
        emitSetslot(opcode, slot, ptr_index, localCopy(state->sp()));
    }

    void CodegenLIR::emitSetslot(AbcOpcode opcode, int slot, int ptr_index, LIns* value)
    {
        Traits* t;
        LIns* ptr;

        if (opcode == OP_setslot)
        {
            t = state->value(ptr_index).traits;
            ptr = localGetp(ptr_index);
            AvmAssert(state->value(ptr_index).notNull);
            AvmAssert(isPointer((int)ptr_index)); // obj
        }
        else
        {
            // setglobalslot
            const ScopeTypeChain* scopeTypes = info->declaringScope();
            if (scopeTypes->size == 0)
            {
                // no captured scopes, so global is local scope 0
                ptr_index = ms->scope_base();
                t = state->value(ptr_index).traits;
                ptr = localGetp(ptr_index);
                AvmAssert(state->value(ptr_index).notNull);
                AvmAssert(isPointer((int)ptr_index)); // obj
            }
            else
            {
                // global is outer scope 0
                t = scopeTypes->getScopeTraitsAt(0);
                LIns* scope = loadEnvScope();
                LIns* scopeobj = loadIns(LIR_ldp, offsetof(ScopeChain,_scopes) + 0*sizeof(Atom), scope, ACCSET_OTHER);
                ptr = atomToNativeRep(t, scopeobj);
            }
        }

        AvmAssert(t->isResolved());
        const TraitsBindingsp tb = t->getTraitsBindings();
        int offset = tb->getSlotOffset(slot);

        LIns *unoffsetPtr = ptr;

        // if storing to a pointer-typed slot, inline a WB
        Traits* slotType = tb->getSlotTraits(slot);

        if (!slotType || !slotType->isMachineType() || slotType == OBJECT_TYPE)
        {
            // slot type is Atom (for *, Object) or RCObject* (String, Namespace, or other user types)
            const CallInfo *wbAddr = FUNCTIONID(privateWriteBarrierRC);
            if (slotType == NULL || slotType == OBJECT_TYPE) {
                // use fast atom wb
                wbAddr = FUNCTIONID(atomWriteBarrier);
            }
            callIns(wbAddr, 4,
                    InsConstPtr(core->GetGC()),
                    unoffsetPtr,
                    leaIns(offset, ptr),
                    value);
        }
        else if (slotType == NUMBER_TYPE) {
            // slot type is double or int
            std(value, ptr, offset, ACCSET_OTHER);
        } else {
            AvmAssert(slotType == INT_TYPE || slotType == UINT_TYPE || slotType == BOOLEAN_TYPE);
            sti(value, ptr, offset, ACCSET_OTHER);
        }
    }

    /**
     * Emit a constructor call, or a late bound constructor call.
     * Early binding is possible when we know the constructor (class) being
     * used, and we know it doesn't override ClassClosure::construct(),
     * as indicated by the itraits->hasCustomConstruct flag.
     */
    void CodegenLIR::emitConstruct(int argc, LIns* ctor, Traits* ctraits)
    {
        // Attempt to early bind to constructor method.
        Traits* itraits = NULL;
        if (ctraits && (itraits = ctraits->itraits) != NULL &&
                !ctraits->hasCustomConstruct) {
            // Inline the body of ClassClosure::construct() and early bind the call
            // to the constructor method, if it's resolved and argc is legal.
            // Cannot resolve signatures now because that could cause a premature verification failure,
            // one that should occur in the class's script-init.
            // If it's already resolved then we're good to go.
            if (itraits->init && itraits->init->isResolved() && itraits->init->getMethodSignature()->argcOk(argc)) {
                // The explicit null check will throw a different exception than
                // the generic call to op_construct below, or to similar paths through
                // interpreted code!
                emitCheckNull(ctor, ctraits);
                emitConstructCall(0, argc, ctor, ctraits);
                return;
            }
        }

        // Generic path: could not early bind to a constructor method.
        // stack in: ctor-object arg1..N
        // sp[-argc] = construct(env, sp[-argc], argc, null, arg1..N)
        int ctor_index = state->sp() - argc;
        LIns* func = nativeToAtom(ctor, ctraits);
        LIns* args = storeAtomArgs(InsConstAtom(nullObjectAtom), argc, ctor_index+1);
        LIns* newobj = callIns(FUNCTIONID(op_construct), 4, env_param, func, InsConst(argc), args);
        liveAlloc(args);
        localSet(ctor_index, atomToNativeRep(itraits, newobj), itraits);
    }

    typedef const CallInfo *CallInfop;

    // Generate code for get obj[index] where index is a signed or unsigned integer type
    LIns* CodegenLIR::emitGetIntProperty(int objIndexOnStack, LIns *index, Traits *result, bool bUnsigned)
    {
        Traits* objType = state->value(objIndexOnStack).traits;
        bool valIsAtom = true;
        LIns *value;

        if (objType == ARRAY_TYPE) {
            value = callIns((bUnsigned ?
                FUNCTIONID(ArrayObject_getUintProperty) :
                FUNCTIONID(ArrayObject_getIntProperty)),
                2, localGetp(objIndexOnStack), index);
        }
        else if (objType != NULL && objType->subtypeof(VECTOROBJ_TYPE)) {
            value = callIns((bUnsigned ?
                FUNCTIONID(ObjectVectorObject_getUintProperty) :
                FUNCTIONID(ObjectVectorObject_getIntProperty)),
                2, localGetp(objIndexOnStack), index);
        }
        else if (objType == VECTORINT_TYPE) {
            if (result == INT_TYPE || result == UINT_TYPE) {
                value = callIns((bUnsigned ?
                    FUNCTIONID(IntVectorObject_getNativeUintProperty) :
                    FUNCTIONID(IntVectorObject_getNativeIntProperty)),
                    2, localGetp(objIndexOnStack), index);
                valIsAtom = false;
            }
            else {
                value = callIns((bUnsigned ?
                    FUNCTIONID(IntVectorObject_getUintProperty) :
                    FUNCTIONID(IntVectorObject_getIntProperty)),
                    2, localGetp(objIndexOnStack), index);
            }
        }
        else if (objType == VECTORUINT_TYPE) {
            if (result == INT_TYPE || result == UINT_TYPE) {
                value = callIns((bUnsigned ?
                    FUNCTIONID(UIntVectorObject_getNativeUintProperty) :
                    FUNCTIONID(UIntVectorObject_getNativeIntProperty)),
                    2, localGetp(objIndexOnStack), index);
                valIsAtom = false;
            }
            else {
                value = callIns((bUnsigned ?
                    FUNCTIONID(UIntVectorObject_getUintProperty) :
                    FUNCTIONID(UIntVectorObject_getIntProperty)),
                    2, localGetp(objIndexOnStack), index);
            }
        }
        else if (objType == VECTORDOUBLE_TYPE) {
            if (result == NUMBER_TYPE) {
                value = callIns(bUnsigned ?
                    FUNCTIONID(DoubleVectorObject_getNativeUintProperty) :
                    FUNCTIONID(DoubleVectorObject_getNativeIntProperty),
                    2, localGetp(objIndexOnStack), index);
                valIsAtom = false;
            }
            else {
                value = callIns(bUnsigned ?
                    FUNCTIONID(DoubleVectorObject_getUintProperty) :
                    FUNCTIONID(DoubleVectorObject_getIntProperty),
                    2, localGetp(objIndexOnStack), index);
            }
        }
        else {
            value = callIns(bUnsigned ?
                FUNCTIONID(getpropertylate_u) :
                FUNCTIONID(getpropertylate_i),
                3, env_param, loadAtomRep(objIndexOnStack), index);
        }

        return valIsAtom ? atomToNativeRep(result, value) : value;
    }

    // Generate code for 'obj[index] = value' where index is a signed or unsigned integer type
    void CodegenLIR::emitSetIntProperty(int objIndexOnStack, int valIndexOnStack, LIns *index, bool bUnsigned)
    {
        Traits* valueType = state->value(valIndexOnStack).traits;
        Traits* objType = state->value(objIndexOnStack).traits;

        if (objType == ARRAY_TYPE) {
            LIns* value = loadAtomRep(valIndexOnStack);
            callIns((bUnsigned ?
                FUNCTIONID(ArrayObject_setUintProperty) :
                FUNCTIONID(ArrayObject_setIntProperty)),
                3, localGetp(objIndexOnStack), index, value);
        }
        else if (objType != NULL && objType->subtypeof(VECTOROBJ_TYPE)) {
            LIns* value = loadAtomRep(valIndexOnStack);
            callIns((bUnsigned ?
                FUNCTIONID(ObjectVectorObject_setUintProperty) :
                FUNCTIONID(ObjectVectorObject_setIntProperty)),
                3, localGetp(objIndexOnStack), index, value);
        }
        else if (objType == VECTORINT_TYPE) {
            if (valueType == INT_TYPE || valueType == UINT_TYPE) {
                LIns* value = localGet(valIndexOnStack);
                callIns((bUnsigned ?
                    FUNCTIONID(IntVectorObject_setNativeUintProperty) :
                    FUNCTIONID(IntVectorObject_setNativeIntProperty)),
                    3, localGetp(objIndexOnStack), index, value);
            }
            else {
                LIns* value = loadAtomRep(valIndexOnStack);
                value = callIns((bUnsigned ?
                    FUNCTIONID(IntVectorObject_setUintProperty) :
                    FUNCTIONID(IntVectorObject_setIntProperty)),
                    3, localGetp(objIndexOnStack), index, value);
            }
        }
        else if (objType == VECTORUINT_TYPE) {
            if (valueType == INT_TYPE || valueType == UINT_TYPE) {
                LIns* value = localGet(valIndexOnStack);
                callIns((bUnsigned ?
                    FUNCTIONID(UIntVectorObject_setNativeUintProperty) :
                    FUNCTIONID(UIntVectorObject_setNativeIntProperty)),
                    3, localGetp(objIndexOnStack), index, value);
            }
            else {
                LIns* value = loadAtomRep(valIndexOnStack);
                value = callIns((bUnsigned ?
                    FUNCTIONID(UIntVectorObject_setUintProperty) :
                    FUNCTIONID(UIntVectorObject_setIntProperty)),
                    3, localGetp(objIndexOnStack), index, value);
            }
        }
        else if (objType == VECTORDOUBLE_TYPE) {
            if (valueType == NUMBER_TYPE) {
                LIns* value = localGetf(valIndexOnStack);
                callIns(bUnsigned ?
                    FUNCTIONID(DoubleVectorObject_setNativeUintProperty) :
                    FUNCTIONID(DoubleVectorObject_setNativeIntProperty),
                    3, localGetp(objIndexOnStack), index, value);
            }
            else {
                LIns* value = loadAtomRep(valIndexOnStack);
                value = callIns(bUnsigned ?
                    FUNCTIONID(DoubleVectorObject_setUintProperty) :
                    FUNCTIONID(DoubleVectorObject_setIntProperty),
                    3, localGetp(objIndexOnStack), index, value);
            }
        }
        else {
            LIns* value = loadAtomRep(valIndexOnStack);
            callIns(bUnsigned ?
                FUNCTIONID(setpropertylate_u) :
                FUNCTIONID(setpropertylate_i),
                4, env_param, loadAtomRep(objIndexOnStack), index, value);
        }
    }

    // Try to optimize our input argument to the fastest possible type.
    //   Non-negative integer constants can be considered unsigned.
    //   Promotions from int/uint to number can be used as integers.
    //   Double constants that are actually integers can be used as integers.
    LIns *CodegenLIR::optimizeIndexArgumentType(int32_t sp, Traits** indexType)
    {
        LIns *index = NULL;
        if (*indexType == INT_TYPE) {
            index = localGet(sp);
            if (index->isImmI() && index->immI() > 0) {
                *indexType = UINT_TYPE;
            }

            return index;
        }
        else if (*indexType == UINT_TYPE) {
            return localGet(sp);
        }
        // Convert number inputs to ints or uints if they are promotions
        // from int, uint or constant integers promoted
        else if (*indexType == NUMBER_TYPE) {
            index = localGetf(sp);
            if (index->opcode() == LIR_i2d) {
                *indexType = INT_TYPE;
                return index->oprnd1();
            }
            else if (index->opcode() == LIR_ui2d) {
                *indexType = UINT_TYPE;
                return index->oprnd1();
            }
            else if (index->isImmD())
            {
                double d = index->immD();
                int32_t i = int32_t(d);
                if (i == d) {
                    if (i >= 0) {
                        *indexType = UINT_TYPE;
                    }
                    else {
                        *indexType = INT_TYPE;
                    }
                    return InsConst(i);
                }
            }
        }

        return index;
    }

    void CodegenLIR::emit(AbcOpcode opcode, uintptr_t op1, uintptr_t op2, Traits* result)
    {
        int sp = state->sp();

        switch (opcode)
        {
            // sign extends
            case OP_sxi1:
            case OP_sxi8:
            case OP_sxi16:
            {
                // straightforward shift based sign extension
                static const uint8_t kShiftAmt[3] = { 31, 24, 16 };
                int32_t index = (int32_t) op1;
                LIns* val = localGet(index);
                if ((opcode == OP_sxi8 && val->opcode() == LIR_ldc2i) ||
                    (opcode == OP_sxi16 && val->opcode() == LIR_lds2i))
                {
                    // if we are sign-extending the result of a load-and-sign-extend
                    // instruction, no need to do anything.
                    break;
                }
                LIns* sh = InsConst(kShiftAmt[opcode - OP_sxi1]);
                LIns* shl = binaryIns(LIR_lshi, val, sh);
                LIns* res = binaryIns(LIR_rshi, shl, sh);
                localSet(index, res, result);
                break;
            }

            // loads
            case OP_lix8:
            case OP_lix16:
            case OP_li8:
            case OP_li16:
            case OP_li32:
            {
                int32_t index = (int32_t) op1;
                LIns* mopAddr = localGet(index);
                const MopsInfo& mi = kMopsLoadInfo[opcode-OP_lix8];
            #ifdef VMCFG_MOPS_USE_EXPANDED_LOADSTORE_INT
                int32_t disp = 0;
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, &disp);
                LIns* i2 = loadIns(mi.op, disp, realAddr, ACCSET_OTHER);
            #else
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, NULL);
                LIns* i2 = callIns(mi.call, 1, realAddr);
            #endif
                localSet(index, i2, result);
                break;
            }

            case OP_lf32:
            case OP_lf64:
            {
                int32_t index = (int32_t) op1;
                LIns* mopAddr = localGet(index);
                const MopsInfo& mi = kMopsLoadInfo[opcode-OP_lix8];
            #ifdef VMCFG_MOPS_USE_EXPANDED_LOADSTORE_FP
                int32_t disp = 0;
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, &disp);
                LIns* i2 = loadIns(mi.op, disp, realAddr, ACCSET_OTHER);
            #else
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, NULL);
                LIns* i2 = callIns(mi.call, 1, realAddr);
            #endif
                localSet(index, i2, result);
                break;
            }

            // stores
            case OP_si8:
            case OP_si16:
            case OP_si32:
            {
                LIns* svalue = localGet(sp-1);
                LIns* mopAddr = localGet(sp);
                const MopsInfo& mi = kMopsStoreInfo[opcode-OP_si8];
            #ifdef VMCFG_MOPS_USE_EXPANDED_LOADSTORE_INT
                int32_t disp = 0;
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, &disp);
                lirout->insStore(mi.op, svalue, realAddr, disp, ACCSET_OTHER);
            #else
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, NULL);
                callIns(mi.call, 2, realAddr, svalue);
            #endif
                break;
            }

            case OP_sf32:
            case OP_sf64:
            {
                LIns* svalue = localGetf(sp-1);
                LIns* mopAddr = localGet(sp);
                const MopsInfo& mi = kMopsStoreInfo[opcode-OP_si8];
            #ifdef VMCFG_MOPS_USE_EXPANDED_LOADSTORE_FP
                int32_t disp = 0;
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, &disp);
                lirout->insStore(mi.op, svalue, realAddr, disp, ACCSET_OTHER);
            #else
                LIns* realAddr = mopAddrToRangeCheckedRealAddrAndDisp(mopAddr, mi.size, NULL);
                callIns(mi.call, 2, realAddr, svalue);
            #endif
                break;
            }

            case OP_jump:
            {
                // spill everything first
                const uint8_t* target = (const uint8_t*) op1;

#ifdef DEBUGGER
                Sampler* s = core->get_sampler();
                if (s && s->sampling() && target < state->abc_pc)
                {
                    emitSampleCheck();
                }
#endif

                branchToAbcPos(LIR_j, 0, target);
                break;
            }

            case OP_lookupswitch:
            {
                //int index = integer(*(sp--));
                //pc += readS24(index < readU16(pc+4) ?
                //  (pc+6+3*index) :    // matched case
                //  (pc+1));            // default
                int count = int(1 + op2);
                const uint8_t* targetpc = (const uint8_t*) op1;

                AvmAssert(state->value(sp).traits == INT_TYPE);
                AvmAssert(count >= 0);

                // Compute address of jump table
                const uint8_t* pc = 4 + state->abc_pc;
                AvmCore::readU32(pc);  // skip count

                // Delete any trailing table entries that == default case (effective for asc output)
                while (count > 0 && targetpc == (state->abc_pc + AvmCore::readS24(pc+3*(count-1))))
                    count--;

                if (count > 0) {
                    LIns* index = localGet(sp);
                    LIns* cmp = binaryIns(LIR_ltui, index, InsConst(count));
                    branchToAbcPos(LIR_jf, cmp, targetpc);

                    // count == 1 is equivalent to if (case) else (default), so don't bother with jtbl
                    if (NJ_JTBL_SUPPORTED && count > 1) {
                        // Backend supports LIR_jtbl for jump tables
                        LIns* jtbl = lirout->insJtbl(index, count);
                        for (int i=0; i < count; i++) {
                            const uint8_t* target = state->abc_pc + AvmCore::readS24(pc+3*i);
                            patchLater(jtbl, target, i);
                        }
                    } else {
                        // Backend doesn't support jump tables, use cascading if's
                        for (int i=0; i < count; i++) {
                            const uint8_t* target = state->abc_pc + AvmCore::readS24(pc+3*i);
                            branchToAbcPos(LIR_jt, binaryIns(LIR_eqi, index, InsConst(i)), target);
                        }
                    }
                }
                else {
                    // switch collapses into a single target
                    branchToAbcPos(LIR_j, 0, targetpc);
                }
                break;
            }

            case OP_returnvoid:
            case OP_returnvalue:
            {
                // ISSUE if a method has multiple returns this causes some bloat

                #ifdef DEBUGGER
                if (haveDebugger) {
                    callIns(FUNCTIONID(debugExit), 2,
                        env_param, csn);
                    // now we toast the cse and restore contents in order to
                    // ensure that any variable modifications made by the debugger
                    // will be pulled in.
                    //firstCse = ip;
                }
                #endif // DEBUGGER

                if (driver->hasReachableExceptions())
                {
                    // _ef.endTry();
                    callIns(FUNCTIONID(endTry), 1, _ef);
                }

                // replicate MethodFrame dtor inline -- must come after endTry call (if any)
                LIns* nextMethodFrame = loadIns(LIR_ldp, offsetof(MethodFrame,next), methodFrame, ACCSET_OTHER);
                stp(nextMethodFrame, coreAddr, offsetof(AvmCore,currentMethodFrame), ACCSET_OTHER);

                Traits* t = ms->returnTraits();
                LIns* retvalue;
                if (opcode == OP_returnvalue)
                {
                    // already coerced to required native type
                    // use localCopy() to sniff type and use appropriate load instruction
                    int32_t index = (int32_t) op1;
                    retvalue = localCopy(index);
                }
                else
                {
                    retvalue = undefConst;
                    if (t && t != VOID_TYPE)
                    {
                        // implicitly coerce undefined to the return type
                        retvalue = callIns(FUNCTIONID(coerce), 3,
                            env_param, retvalue, InsConstPtr(t));
                        retvalue = atomToNativeRep(t, retvalue);
                    }
                }
                switch (bt(t)) {
                case BUILTIN_number:
                    Ins(LIR_retd, retvalue);
                    break;
                case BUILTIN_int:
                    retp(i2p(retvalue));
                    break;
                case BUILTIN_uint:
                case BUILTIN_boolean:
                    retp(ui2p(retvalue));
                    break;
                default:
                    retp(retvalue);
                    break;
                }
                break;
            }

            case OP_typeof:
            {
                //sp[0] = typeof(sp[0]);
                int32_t index = (int32_t) op1;
                LIns* value = loadAtomRep(index);
                LIns* i3 = callIns(FUNCTIONID(typeof), 2,
                    coreAddr, value);
                AvmAssert(result == STRING_TYPE);
                localSet(index, i3, result);
                break;
            }

            case OP_not:
            {
                int32_t index = (int32_t) op1;
                AvmAssert(state->value(index).traits == BOOLEAN_TYPE && result == BOOLEAN_TYPE);
                LIns* value = localGet(index); // 0 or 1
                LIns* i3 = eqi0(value); // 1 or 0
                localSet(index, i3, result);
                break;
            }

            case OP_negate: {
                int32_t index = (int32_t) op1;
                localSet(index, Ins(LIR_negd, localGetf(index)),result);
                break;
            }

            case OP_negate_i: {
                //framep[op1] = -framep[op1]
                int32_t index = (int32_t) op1;
                AvmAssert(state->value(index).traits == INT_TYPE);
                localSet(index, Ins(LIR_negi, localGet(index)), result);
                break;
            }

            case OP_increment:
            case OP_decrement:
            case OP_inclocal:
            case OP_declocal: {
                int32_t index = (int32_t) op1;
                int32_t incr = (int32_t) op2; // 1 or -1
                localSet(index, binaryIns(LIR_addd, localGetf(index), i2dIns(InsConst(incr))), result);
                break;
            }

            case OP_inclocal_i:
            case OP_declocal_i:
            case OP_increment_i:
            case OP_decrement_i: {
                int32_t index = (int32_t) op1;
                int32_t incr = (int32_t) op2;
                AvmAssert(state->value(index).traits == INT_TYPE);
                localSet(index, binaryIns(LIR_addi, localGet(index), InsConst(incr)), result);
                break;
            }

            case OP_bitnot: {
                // *sp = core->intToAtom(~integer(*sp));
                int32_t index = (int32_t) op1;
                AvmAssert(state->value(index).traits == INT_TYPE);
                localSet(index, lirout->ins1(LIR_noti, localGet(index)), result);
                break;
            }

            case OP_modulo: {
                LIns* out = callIns(FUNCTIONID(mod), 2,
                    localGetf(sp-1), localGetf(sp));
                localSet(sp-1,  out, result);
                break;
            }

            case OP_divide:
            case OP_multiply:
            case OP_subtract: {
                LOpcode op;
                switch (opcode) {
                    default:
                    case OP_divide:     op = LIR_divd; break;
                    case OP_multiply:   op = LIR_muld; break;
                    case OP_subtract:   op = LIR_subd; break;
                }
                localSet(sp-1, binaryIns(op, localGetf(sp-1), localGetf(sp)), result);
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
                LOpcode op;
                switch (opcode) {
                    default:
                    case OP_bitxor:     op = LIR_xori;  break;
                    case OP_bitor:      op = LIR_ori;   break;
                    case OP_bitand:     op = LIR_andi;  break;
                    case OP_urshift:    op = LIR_rshui; break;
                    case OP_rshift:     op = LIR_rshi;  break;
                    case OP_lshift:     op = LIR_lshi;  break;
                    case OP_multiply_i: op = LIR_muli;  break;
                    case OP_add_i:      op = LIR_addi;  break;
                    case OP_subtract_i: op = LIR_subi;  break;
                }
                LIns* lhs = localGet(sp-1);
                LIns* rhs = localGet(sp);
                LIns* out = binaryIns(op, lhs, rhs);
                localSet(sp-1, out, result);
                break;
            }

            case OP_throw:
            {
                //throwAtom(*sp--);
                int32_t index = (int32_t) op1;
                callIns(FUNCTIONID(throwAtom), 2, coreAddr, loadAtomRep(index));
                break;
            }

            case OP_getsuper:
            {
                // stack in: obj [ns [name]]
                // stack out: value
                // sp[0] = env->getsuper(sp[0], multiname)
                int objDisp = sp;
                LIns* multi = initMultiname((Multiname*)op1, objDisp);
                AvmAssert(state->value(objDisp).notNull);

                LIns* obj = loadAtomRep(objDisp);

                LIns* i3 = callIns(FUNCTIONID(getsuper), 3,
                    env_param, obj, multi);
                liveAlloc(multi);

                i3 = atomToNativeRep(result, i3);
                localSet(objDisp, i3, result);
                break;
            }

            case OP_setsuper:
            {
                // stack in: obj [ns [name]] value
                // stack out: nothing
                // core->setsuper(sp[-1], multiname, sp[0], env->vtable->base)
                int objDisp = sp-1;
                LIns* multi = initMultiname((Multiname*)op1, objDisp);
                AvmAssert(state->value(objDisp).notNull);

                LIns* obj = loadAtomRep(objDisp);
                LIns* value = loadAtomRep(sp);

                callIns(FUNCTIONID(setsuper), 4,
                    env_param, obj, multi, value);
                liveAlloc(multi);
                break;
            }

            case OP_nextname:
            case OP_nextvalue:
            {
                // sp[-1] = next[name|value](sp[-1], sp[0]);
                LIns* obj = loadAtomRep(sp-1);
                AvmAssert(state->value(sp).traits == INT_TYPE);
                LIns* index = localGet(sp);
                LIns* i1 = callIns((opcode == OP_nextname) ? FUNCTIONID(nextname) : FUNCTIONID(nextvalue), 3,
                                   env_param, obj, index);
                localSet(sp-1, atomToNativeRep(result, i1), result);
                break;
            }

            case OP_hasnext:
            {
                // sp[-1] = hasnext(sp[-1], sp[0]);
                LIns* obj = loadAtomRep(sp-1);
                AvmAssert(state->value(sp).traits == INT_TYPE);
                LIns* index = localGet(sp);
                LIns* i1 = callIns(FUNCTIONID(hasnext), 3,
                    env_param, obj, index);
                AvmAssert(result == INT_TYPE);
                localSet(sp-1, i1, result);
                break;
            }

            case OP_hasnext2:
            {
                // fixme - if obj is already Atom, or index is already int,
                // easier to directly reference space in vars.
                int32_t obj_index = (int32_t) op1;
                int32_t index_index = (int32_t) op2;
                LIns* obj = insAlloc(sizeof(Atom));
                LIns* index = insAlloc(sizeof(int32_t));
                stp(loadAtomRep(obj_index), obj, 0, ACCSET_STORE_ANY);       // Atom obj
                sti(localGet(index_index), index, 0, ACCSET_STORE_ANY);      // int32_t index
                LIns* i1 = callIns(FUNCTIONID(hasnextproto), 3,
                                     env_param, obj, index);
                localSet(obj_index, loadIns(LIR_ldp, 0, obj, ACCSET_LOAD_ANY), OBJECT_TYPE);  // Atom obj
                localSet(index_index, loadIns(LIR_ldi, 0, index, ACCSET_LOAD_ANY), INT_TYPE); // int32_t index
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp+1, i1, result);
                break;
            }

            case OP_newfunction:
            {
                uint32_t function_id = (uint32_t) op1;
                int32_t index = (int32_t) op2;
                //sp[0] = core->newfunction(env, body, _scopeBase, scopeDepth);
                MethodInfo* func = pool->getMethodInfo(function_id);
                int extraScopes = state->scopeDepth;

                // prepare scopechain args for call
                LIns* ap = storeAtomArgs(extraScopes, ms->scope_base());

                LIns* outer = loadEnvScope();

                LIns* i3 = callIns(FUNCTIONID(newfunction), 4,
                    env_param, InsConstPtr(func), outer, ap);
                liveAlloc(ap);

                AvmAssert(!result->isMachineType());
                localSet(index, i3, result);
                break;
            }

            case OP_call:
            {
                // stack in: method obj arg1..N
                // sp[-argc-1] = op_call(env, sp[-argc], argc, ...)
                int argc = int(op1);
                int funcDisp = sp - argc - 1;
                int dest = funcDisp;

                // convert args to Atom[] for the call
                LIns* func = loadAtomRep(funcDisp);
                LIns* ap = storeAtomArgs(loadAtomRep(funcDisp+1), argc, funcDisp+2);
                LIns* i3 = callIns(FUNCTIONID(op_call), 4, env_param, func, InsConst(argc), ap);
                liveAlloc(ap);
                localSet(dest, atomToNativeRep(result, i3), result);
                break;
            }

            case OP_callproperty:
            case OP_callproplex:
            case OP_callpropvoid:
            {
                // stack in: obj [ns [name]] arg1..N
                // stack out: result

                // obj = sp[-argc]
                //tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
                //  *(sp -= argc) = tempAtom;
                int argc = int(op2);
                int argv = sp-argc+1;
                int baseDisp = sp-argc;
                const Multiname* name = pool->precomputedMultiname((int)op1);
                LIns* multi = initMultiname(name, baseDisp);
                AvmAssert(state->value(baseDisp).notNull);

                // convert args to Atom[] for the call
                LIns* base = loadAtomRep(baseDisp);
                LIns* receiver = opcode == OP_callproplex ? InsConstAtom(nullObjectAtom) : base;
                LIns* ap = storeAtomArgs(receiver, argc, argv);

                Traits* baseTraits = state->value(baseDisp).traits;
                Binding b = toplevel->getBinding(baseTraits, name);

                LIns* out;
                if (AvmCore::isSlotBinding(b)) {
                    // can early bind call to closure in slot
                    Traits* slotType = Traits::readBinding(baseTraits, b);
                    // todo if funcValue is already a ScriptObject then don't box it, use a different helper.
                    LIns* funcValue = loadFromSlot(baseDisp, AvmCore::bindingToSlotId(b), slotType);
                    LIns* funcAtom = nativeToAtom(funcValue, slotType);
                    out = callIns(FUNCTIONID(op_call), 4, env_param, funcAtom, InsConst(argc), ap);
                }
                else if (!name->isRuntime()) {
                    // use inline cache for late bound call
                    // cache contains: [handler, vtable, [data], Multiname*]
                    // and we call (*cache->handler)(cache, obj, argc, args*, MethodEnv*)
                    CallCache* cache = call_cache_builder.allocateCacheSlot(name);
                    LIns* cacheAddr = InsConstPtr(cache);
                    LIns* handler = loadIns(LIR_ldp, offsetof(CallCache, call_handler), cacheAddr, ACCSET_OTHER);
                    out = callIns(FUNCTIONID(call_cache_handler), 6,
                        handler, cacheAddr, base, InsConst(argc), ap, env_param);
                }
                else {
                    // generic late bound call to anything
                    out = callIns(FUNCTIONID(callprop_late), 5, env_param, base, multi, InsConst(argc), ap);
                    liveAlloc(multi);
                }
                liveAlloc(ap);
                localSet(baseDisp, atomToNativeRep(result, out), result);
                break;
            }

            case OP_constructprop:
            {
                // stack in: obj [ns [name]] arg1..N
                // stack out: result

                int argc = int(op2);
                // obj = sp[-argc]
                //tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
                //  *(sp -= argc) = tempAtom;
                int argv = sp-argc+1;

                int objDisp = sp-argc;
                LIns* multi = initMultiname((Multiname*)op1, objDisp);
                AvmAssert(state->value(objDisp).notNull);

                // convert args to Atom[] for the call
                LIns* ap = storeAtomArgs(loadAtomRep(objDisp), argc, argv);
                LIns* i3 = callIns(FUNCTIONID(construct_late), 4,
                    env_param, multi, InsConst(argc), ap);
                liveAlloc(multi);
                liveAlloc(ap);

                localSet(objDisp, atomToNativeRep(result, i3), result);
                break;
            }

            case OP_callsuper:
            case OP_callsupervoid:
            {
                // stack in: obj [ns [name]] arg1..N
                // stack out: result
                // null check must have already happened.
                //  tempAtom = callsuper(multiname, obj, sp-argc+1, argc, vtable->base);
                int argc = int(op2);
                int argv = sp - argc + 1;
                int objDisp = sp - argc;
                LIns* multi = initMultiname((Multiname*)op1, objDisp);
                AvmAssert(state->value(objDisp).notNull);

                // convert args to Atom[] for the call
                LIns* obj = loadAtomRep(objDisp);

                LIns* ap = storeAtomArgs(obj, argc, argv);

                LIns* i3 = callIns(FUNCTIONID(callsuper), 4,
                    env_param, multi, InsConst(argc), ap);
                liveAlloc(multi);
                liveAlloc(ap);

                localSet(objDisp, atomToNativeRep(result, i3), result);
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

                LIns* func = loadAtomRep(funcDisp);

                // convert args to Atom[] for the call
                LIns* ap = storeAtomArgs(argc, arg0);

                LIns* i3 = callIns(FUNCTIONID(op_applytype), 4,
                    env_param, func, InsConst(argc), ap);
                liveAlloc(ap);

                localSet(dest, atomToNativeRep(result, i3), result);
                break;
            }

            case OP_newobject:
            {
                // result = env->op_newobject(sp, argc)
                int argc = int(op1);
                int dest = sp - (2*argc-1);
                int arg0 = dest;

                // convert args to Atom for the call[]
                LIns* ap = storeAtomArgs(2*argc, arg0);

                LIns* i3 = callIns(FUNCTIONID(op_newobject), 3,
                    env_param, leaIns(sizeof(Atom)*(2*argc-1), ap), InsConst(argc));
                liveAlloc(ap);

                localSet(dest, ptrToNativeRep(result, i3), result);
                break;
            }

            case OP_newactivation:
            {
                // result = env->newActivation()
                LIns* activation = callIns(FUNCTIONID(newActivation), 1, env_param);
                localSet(sp+1, ptrToNativeRep(result, activation), result);
                break;
            }

            case OP_newcatch:
            {
                // result = core->newObject(env->activation, NULL);
                int dest = sp+1;

                LIns* activation = callIns(FUNCTIONID(newcatch), 2,
                                         env_param, InsConstPtr(result));

                localSet(dest, ptrToNativeRep(result, activation), result);
                break;
            }

            case OP_newarray:
            {
                // sp[-argc+1] = env->toplevel()->arrayClass->newarray(sp-argc+1, argc)
                int argc = int(op1);
                int arg0 = sp - 1*argc+1;

                // convert array elements to Atom[]
                LIns* ap = storeAtomArgs(argc, arg0);
                LIns* i3 = callIns(FUNCTIONID(newarray), 3, env_param, InsConst(argc), ap);
                liveAlloc(ap);

                AvmAssert(!result->isMachineType());
                localSet(arg0, i3, result);
                break;
            }

            case OP_newclass:
            {
                // sp[0] = core->newclass(env, ctraits, scopeBase, scopeDepth, base)
                Traits* ctraits = (Traits*) op1;
                int localindex = int(op2);
                int extraScopes = state->scopeDepth;

                LIns* outer = loadEnvScope();
                LIns* base = localGetp(localindex);

                // prepare scopechain args for call
                LIns* ap = storeAtomArgs(extraScopes, ms->scope_base());

                LIns* i3 = callIns(FUNCTIONID(newclass), 5,
                    env_param, InsConstPtr(ctraits), base, outer, ap);
                liveAlloc(ap);

                AvmAssert(!result->isMachineType());
                localSet(localindex, i3, result);
                break;
            }

            case OP_getdescendants:
            {
                // stack in: obj [ns [name]]
                // stack out: value
                //sp[0] = core->getdescendants(sp[0], name);
                int objDisp = sp;
                Multiname* multiname = (Multiname*) op1;

                LIns* multi = initMultiname(multiname, objDisp);
                LIns* obj = loadAtomRep(objDisp);
                AvmAssert(state->value(objDisp).notNull);

                LIns* out = callIns(FUNCTIONID(getdescendants), 3,
                    env_param, obj, multi);
                liveAlloc(multi);

                localSet(objDisp, atomToNativeRep(result, out), result);
                break;
            }

            case OP_checkfilter: {
                int32_t index = (int32_t) op1;
                callIns(FUNCTIONID(checkfilter), 2, env_param, loadAtomRep(index));
                break;
            }

            case OP_findpropstrict:
            case OP_findproperty:
            {
                // stack in: [ns [name]]
                // stack out: obj
                // sp[1] = env->findproperty(scopeBase, scopedepth, name, strict)
                int dest = sp;
                LIns* multi = initMultiname((Multiname*)op1, dest);
                dest++;
                int extraScopes = state->scopeDepth;

                // prepare scopechain args for call
                LIns* ap = storeAtomArgs(extraScopes, ms->scope_base());

                LIns* outer = loadEnvScope();

                LIns* withBase;
                if (state->withBase == -1)
                {
                    withBase = InsConstPtr(0);
                }
                else
                {
                    withBase = leaIns(state->withBase*sizeof(Atom), ap);
                }

                //      return env->findproperty(outer, argv, extraScopes, name, strict);

                LIns* i3 = callIns(FUNCTIONID(findproperty), 7,
                    env_param, outer, ap, InsConst(extraScopes), multi,
                    InsConst((int32_t)(opcode == OP_findpropstrict)),
                    withBase);
                liveAlloc(multi);
                liveAlloc(ap);

                localSet(dest, atomToNativeRep(result, i3), result);
                break;
            }

            case OP_getproperty:
            {
                // stack in: obj [ns] [name]
                // stack out: value
                // obj=sp[0]
                //sp[0] = env->getproperty(obj, multiname);

                const Multiname* multiname = pool->precomputedMultiname((int)op1);
                bool attr = multiname->isAttr();
                Traits* indexType = state->value(sp).traits;
                LIns* index = NULL;
                bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->containsAnyPublicNamespace();

                if (maybeIntegerIndex)
                    index = optimizeIndexArgumentType(sp, &indexType);

                if (maybeIntegerIndex && indexType == INT_TYPE) {
                    LIns *value = emitGetIntProperty(sp-1, index, result, false);
                    localSet(sp-1, value, result);
                }
                else if (maybeIntegerIndex && indexType == UINT_TYPE) {
                    LIns *value = emitGetIntProperty(sp-1, index, result, true);
                    localSet(sp-1, value, result);
                }
                else if (maybeIntegerIndex && indexType == NUMBER_TYPE) {
                    LIns *value;

                    CodegenLabel slow_path("slow");
                    CodegenLabel done_path("done");
                    suspendCSE();

#if defined(VMCFG_FASTPATH_ADD_INLINE) || NJ_F2I_SUPPORTED
                    LIns* tempResult = insAllocForTraits(result);
#endif // defined(VMCFG_FASTPATH_ADD_INLINE) || NJ_F2I_SUPPORTED

                    bool bGeneratedFastPath = false;
#ifdef VMCFG_FASTPATH_ADD_INLINE
                    LOpcode op = index->opcode();
                    if (op == LIR_addd || op == LIR_subd) {
                        LIns *a = index->oprnd1();
                        LIns *b = index->oprnd2();
                        // Our addjovi only works with signed integers so don't use isPromote.
                        a = (a->opcode() == LIR_i2d) ? a->oprnd1() : imm2Int(a);
                        b = (b->opcode() == LIR_i2d) ? b->oprnd1() : imm2Int(b);
                        if (a && b) {
                            // Inline fast path for index generated from integer add
                            // if (a+b) does not overflow && ((a+b) >= 0)
                            //   call getUintProperty(obj, a + b)
                            // else
                            //   call getprop_index_add (env, obj, multiname, a, b)
                            // (for subtraction, we emit (a-b) and call getprop_index_subtract)
                            LIns *addOp = branchJovToLabel((op == LIR_addd) ? LIR_addjovi : LIR_subjovi, a, b, slow_path);
                            branchToLabel(LIR_jt, binaryIns(LIR_lti, addOp, InsConst(0)), slow_path);
                            value = emitGetIntProperty(sp-1, addOp, result, true);
                            stForTraits(result, value, tempResult, 0, ACCSET_STORE_ANY);
                            branchToLabel(LIR_j, NULL, done_path);

                            emitLabel(slow_path);
                            LIns* multi = InsConstPtr(multiname); // inline ptr to precomputed name
                            value = callIns((op == LIR_addd) ?
                                FUNCTIONID(getprop_index_add) : FUNCTIONID(getprop_index_subtract), 5,
                                env_param, loadAtomRep(sp-1), multi, a, b);

                            stForTraits(result, atomToNativeRep(result, value), tempResult, 0, ACCSET_STORE_ANY);
                            emitLabel(done_path);

                            localSet(sp-1, ldForTraits(result, tempResult, 0, ACCSET_LOAD_ANY), result);
                            bGeneratedFastPath = true;
                        }
                    }
#endif // VMCFG_FASTPATH_ADD_INLINE
                    if (!bGeneratedFastPath) {
#if NJ_F2I_SUPPORTED
                        // Inline fast path for index values that are unsigned integers
                        // if ((i2d(d2i(index)) == index) && d2i(index) >= 0)
                        //   call getProperty[uint]
                        // else
                        //   call getprop_index
                        //
                        LIns *intIndex = lirout->ins1(LIR_d2i, index);
                        LIns *dIndex = i2dIns(intIndex);

                        // if (i2d(d2i(index)) != index), not a valid int
                        branchToLabel(LIR_jf, binaryIns(LIR_eqd, dIndex, index), slow_path);
                        // if intIndex < 0, not a valid unsigned int
                        branchToLabel(LIR_jt, binaryIns(LIR_lti, intIndex, InsConst(0)), slow_path);

                        value = emitGetIntProperty(sp-1, intIndex, result, true);
                        stForTraits(result, value, tempResult, 0, ACCSET_STORE_ANY);
                        branchToLabel(LIR_j, NULL, done_path);

                        emitLabel(slow_path);
#endif // NJ_F2I_SUPPORTED
                        LIns* multi = InsConstPtr(multiname); // inline ptr to precomputed name
                        index = nativeToAtom(index, NUMBER_TYPE);
                        value = callIns(FUNCTIONID(getprop_index), 4,
                                            env_param, loadAtomRep(sp-1), multi, index);
#if NJ_F2I_SUPPORTED
                        stForTraits(result, atomToNativeRep(result, value), tempResult, 0, ACCSET_STORE_ANY);
                        emitLabel(done_path);
                        localSet(sp-1, ldForTraits(result, tempResult, 0, ACCSET_LOAD_ANY), result);
#else
                        localSet(sp-1, atomToNativeRep(result, value), result);
#endif // NJ_F2I_SUPPORTED
                    }
                    resumeCSE();
                }
                else if (maybeIntegerIndex && indexType != STRING_TYPE) {
                    LIns* multi = InsConstPtr(multiname); // inline ptr to precomputed name
                    LIns* index = loadAtomRep(sp);
                    AvmAssert(state->value(sp-1).notNull);
                    LIns* obj = loadAtomRep(sp-1);
                    LIns* value = callIns(FUNCTIONID(getprop_index), 4,
                                        env_param, obj, multi, index);

                    localSet(sp-1, atomToNativeRep(result, value), result);
                }
                else {
                    int objDisp = sp;
                    LIns* multi = initMultiname(multiname, objDisp);
                    AvmAssert(state->value(objDisp).notNull);

                    LIns* value;
                    LIns* obj = loadAtomRep(objDisp);
                    if (multiname->isRuntime()) {
                        //return getprop_late(obj, name);
                        value = callIns(FUNCTIONID(getprop_late), 3, env_param, obj, multi);
                        liveAlloc(multi);
                    } else {
                        // static name, use property cache
                        GetCache* cache = get_cache_builder.allocateCacheSlot(multiname);
                        LIns* cacheAddr = InsConstPtr(cache);
                        LIns* handler = loadIns(LIR_ldp, offsetof(GetCache, get_handler), cacheAddr, ACCSET_OTHER);
                        value = callIns(FUNCTIONID(get_cache_handler), 4, handler, cacheAddr, env_param, obj);
                    }

                    localSet(objDisp, atomToNativeRep(result, value), result);
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

                const Multiname* multiname = (const Multiname*)op1;
                bool attr = multiname->isAttr();
                Traits* indexType = state->value(sp-1).traits;
                LIns* index = NULL;
                bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->containsAnyPublicNamespace();

                if (maybeIntegerIndex)
                    index = optimizeIndexArgumentType(sp-1, &indexType);

                if (maybeIntegerIndex && indexType == INT_TYPE) {
                    emitSetIntProperty(sp-2, sp, index, false);
                }
                else if (maybeIntegerIndex && indexType == UINT_TYPE) {
                    emitSetIntProperty(sp-2, sp, index, true);
                }
                else if (maybeIntegerIndex && indexType == NUMBER_TYPE) {
                    CodegenLabel slow_path("slow");
                    CodegenLabel done_path("done");
                    suspendCSE();

                    bool bGeneratedFastPath = false;
#ifdef VMCFG_FASTPATH_ADD_INLINE
                    LOpcode op = index->opcode();
                    if (op == LIR_addd || op == LIR_subd) {
                        LIns *a = index->oprnd1();
                        LIns *b = index->oprnd2();
                        // Our addjovi only works with signed integers.
                        a = (a->opcode() == LIR_i2d) ? a->oprnd1() : imm2Int(a);
                        b = (b->opcode() == LIR_i2d) ? b->oprnd1() : imm2Int(b);
                        if (a && b) {
                            // Inline fast path for index generated from integer add
                            // if (a + b) does not overflow && ((a+b) >= 0)
                            //   call setProperty(obj, value, a + b)
                            // else
                            //   call set/initprop_index_add(env, obj, name, value, a, b)
                            // (for subtraction, we emit (a-b) and call set/initprop_index_subtract)
                            LIns *addOp = branchJovToLabel((op == LIR_addd) ? LIR_addjovi : LIR_subjovi, a, b, slow_path);
                            branchToLabel(LIR_jt, binaryIns(LIR_lti, addOp, InsConst(0)), slow_path);
                            emitSetIntProperty(sp-2, sp, addOp, true);
                            branchToLabel(LIR_j, NULL, done_path);

                            emitLabel(slow_path);
                            LIns* name = InsConstPtr(multiname); // precomputed multiname
                            LIns* value = loadAtomRep(sp);
                            AvmAssert(state->value(sp-2).notNull);
                            LIns* obj = loadAtomRep(sp-2);
                            const CallInfo *func;
                            if (op == LIR_addd) {
                                func = opcode==OP_setproperty ? FUNCTIONID(setprop_index_add) :
                                                                FUNCTIONID(initprop_index_add);
                            }
                            else {
                                func = opcode==OP_setproperty ? FUNCTIONID(setprop_index_subtract) :
                                                                FUNCTIONID(initprop_index_subtract);
                            }
                            callIns(func, 6, env_param, obj, name, value, a, b);
                            emitLabel(done_path);
                            bGeneratedFastPath = true;
                        }
                    }
#endif // VMCFG_FASTPATH_ADD_INLINE
                    if (!bGeneratedFastPath) {
#if NJ_F2I_SUPPORTED
                        // Inline fast path for index values that are unsigned integers
                        // if ((i2d(d2i(index)) == index) && d2i(index) >= 0)
                        //   call setProperty[uint]
                        // else
                        //   call setprop_index
                        //
                        LIns *intIndex = lirout->ins1(LIR_d2i, index);
                        LIns *dIndex = i2dIns(intIndex);

                        // if (i2d(d2i(index)) != index), not a valid int
                        branchToLabel(LIR_jf, binaryIns(LIR_eqd, dIndex, index), slow_path);
                        // if intIndex < 0, not a valid unsigned int
                        branchToLabel(LIR_jt, binaryIns(LIR_lti, intIndex, InsConst(0)), slow_path);

                        emitSetIntProperty(sp-2, sp, intIndex, true);
                        branchToLabel(LIR_j, NULL, done_path);

                        emitLabel(slow_path);
#endif // NJ_F2I_SUPPORTED
                        LIns* name = InsConstPtr(multiname); // precomputed multiname
                        LIns* value = loadAtomRep(sp);
                        index = nativeToAtom(index, NUMBER_TYPE);
                        AvmAssert(state->value(sp-2).notNull);
                        LIns* obj = loadAtomRep(sp-2);
                        const CallInfo *func = opcode==OP_setproperty ? FUNCTIONID(setprop_index) :
                                                            FUNCTIONID(initprop_index);
                        callIns(func, 5, env_param, obj, name, value, index);
#if NJ_F2I_SUPPORTED
                        emitLabel(done_path);
#endif // NJ_F2I_SUPPORTED
                    }
                    resumeCSE();
                }
                else if (maybeIntegerIndex) {
                    LIns* name = InsConstPtr(multiname); // precomputed multiname
                    LIns* value = loadAtomRep(sp);
                    LIns* index = loadAtomRep(sp-1);
                    AvmAssert(state->value(sp-2).notNull);
                    LIns* obj = loadAtomRep(sp-2);
                    const CallInfo *func = opcode==OP_setproperty ? FUNCTIONID(setprop_index) :
                                                        FUNCTIONID(initprop_index);
                    callIns(func, 5, env_param, obj, name, value, index);
                }
                else {
                    int objDisp = sp-1;
                    LIns* value = loadAtomRep(sp);
                    LIns* multi = initMultiname(multiname, objDisp);
                    AvmAssert(state->value(objDisp).notNull);

                    LIns* obj = loadAtomRep(objDisp);
                    if (opcode == OP_setproperty) {
                        if (!multiname->isRuntime()) {
                            // use inline cache for dynamic setproperty access
                            SetCache* cache = set_cache_builder.allocateCacheSlot(multiname);
                            LIns* cacheAddr = InsConstPtr(cache);
                            LIns* handler = loadIns(LIR_ldp, offsetof(SetCache, set_handler), cacheAddr, ACCSET_OTHER);
                            callIns(FUNCTIONID(set_cache_handler), 5, handler, cacheAddr, obj, value, env_param);
                        } else {
                            // last resort slow path for OP_setproperty
                            callIns(FUNCTIONID(setprop_late), 4, env_param, obj, multi, value);
                            liveAlloc(multi);
                        }
                    }
                    else {
                        // initproplate is rare in jit code because we typically interpret static
                        // initializers, and constructor initializers tend to early-bind successfully.
                        callIns(FUNCTIONID(initprop_late), 4, env_param, obj, multi, value);
                        liveAlloc(multi);
                    }
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
                    LIns* multi = initMultiname(multiname, objDisp, true);

                    LIns* obj = loadAtomRep(objDisp);

                    LIns* i3 = callIns(FUNCTIONID(delproperty), 3,
                        env_param, obj, multi);
                    liveAlloc(multi);

                    localSet(objDisp, atomToNativeRep(result, i3), result);
                } else {
                    LIns* _tempname = copyMultiname(multiname);
                    LIns* index = loadAtomRep(objDisp--);

                    if( !multiname->isRtns() )
                    {
                        // copy the compile-time namespace to the temp multiname
                        LIns* mSpace = InsConstPtr(multiname->ns);
                        stp(mSpace, _tempname, offsetof(Multiname, ns), ACCSET_OTHER);
                    }
                    else
                    {
                        // intern the runtime namespace and copy to the temp multiname
                        LIns* nsAtom = loadAtomRep(objDisp--);
                        LIns* internNs = callIns(FUNCTIONID(internRtns), 2,
                            env_param, nsAtom);

                        stp(internNs, _tempname, offsetof(Multiname,ns), ACCSET_OTHER);
                    }
                    liveAlloc(_tempname);

                    AvmAssert(state->value(objDisp).notNull);
                    LIns* obj = loadAtomRep(objDisp);

                    LIns* value = callIns(FUNCTIONID(delpropertyHelper), 4,
                                        env_param, obj, _tempname, index);

                    localSet(objDisp, atomToNativeRep(result, value), result);
                }
                break;
            }

            case OP_esc_xelem: // ToXMLString will call EscapeElementValue
            {
                //sp[0] = core->ToXMLString(sp[0]);
                int32_t index = (int32_t) op1;
                LIns* value = loadAtomRep(index);
                LIns* i3 = callIns(FUNCTIONID(ToXMLString), 2,
                    coreAddr, value);
                AvmAssert(result == STRING_TYPE);
                localSet(index, i3, result);
                break;
            }

            case OP_esc_xattr:
            {
                //sp[0] = core->EscapeAttributeValue(sp[0]);
                int32_t index = (int32_t) op1;
                LIns* value = loadAtomRep(index);
                LIns* i3 = callIns(FUNCTIONID(EscapeAttributeValue), 2,
                    coreAddr, value);
                AvmAssert(result == STRING_TYPE);
                localSet(index, i3, result);
                break;
            }

            case OP_astype:
            {
                // sp[0] = AvmCore::astype(sp[0], traits)
                Traits *type = (Traits*) op1;
                int32_t index = (int32_t) op2;
                LIns* obj = loadAtomRep(index);
                LIns* i1 = callIns(FUNCTIONID(astype), 2, obj, InsConstPtr(type));
                i1 = atomToNativeRep(result, i1);
                localSet(index, i1, result);
                break;
            }

            case OP_astypelate:
            {
                //sp[-1] = astype_late(env, sp[-1], sp[0]);
                LIns* type = loadAtomRep(sp);
                LIns* obj = loadAtomRep(sp-1);
                LIns* i3 = callIns(FUNCTIONID(astype_late), 3, env_param, obj, type);
                i3 = atomToNativeRep(result, i3);
                localSet(sp-1, i3, result);
                break;
            }

            case OP_strictequals:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpEq(FUNCTIONID(stricteq), sp-1, sp), result);
                break;
            }

            case OP_equals:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpEq(FUNCTIONID(equals), sp-1, sp), result);
                break;
            }

            case OP_lessthan:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpLt(sp-1, sp), result);
                break;
            }

            case OP_lessequals:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpLe(sp-1, sp), result);
                break;
            }

            case OP_greaterthan:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpLt(sp, sp-1), result);
                break;
            }

            case OP_greaterequals:
            {
                AvmAssert(result == BOOLEAN_TYPE);
                localSet(sp-1, cmpLe(sp, sp-1), result);
                break;
            }

            case OP_instanceof:
            {
                LIns* lhs = loadAtomRep(sp-1);
                LIns* rhs = loadAtomRep(sp);
                LIns* out = callIns(FUNCTIONID(instanceof), 3, env_param, lhs, rhs);
                out = atomToNativeRep(result, out);
                localSet(sp-1,  out, result);
                break;
            }

            case OP_in:
            {
                // sp[-1] = env->in_operator(sp[-1], sp[0])
                int lhsDisp = sp-1;
                LIns *lhs;
                LIns *rhs = loadAtomRep(sp);
                LIns *out;
                Traits *lhsType = state->value(lhsDisp).traits;
                switch (bt(lhsType)) {
                case BUILTIN_uint:
                    lhs = localGet(lhsDisp);
                    out = callIns(FUNCTIONID(haspropertylate_u), 3, env_param, rhs, lhs);
                    break;
                case BUILTIN_int:
                    lhs = localGet(lhsDisp);
                    out = callIns(FUNCTIONID(haspropertylate_i), 3, env_param, rhs, lhs);
                    break;
                default:
                    lhs = loadAtomRep(lhsDisp);
                    out = callIns(FUNCTIONID(op_in), 3, env_param, lhs, rhs);
                    out = atomToNativeRep(result, out);
                    break;
                }
                localSet(sp-1, out, result);
                break;
            }

            case OP_dxns:
            {
                LIns* uri = InsConstPtr((String*)op1); // namespace uri from string pool
                callIns(FUNCTIONID(setDxns), 3, coreAddr, methodFrame, uri);
                break;
            }

            case OP_dxnslate:
            {
                int32_t index = (int32_t) op1;
                LIns* atom = loadAtomRep(index);
                callIns(FUNCTIONID(setDxnsLate), 3, coreAddr, methodFrame, atom);
                break;
            }

            /*
             * debugger instructions
             */
            case OP_debugfile:
            {
            #ifdef DEBUGGER
            if (haveDebugger) {
                // todo refactor api's so we don't have to pass argv/argc
                LIns* debugger = loadIns(LIR_ldp, offsetof(AvmCore, _debugger), coreAddr, ACCSET_OTHER, LOAD_CONST);
                callIns(FUNCTIONID(debugFile), 2,
                        debugger,
                        InsConstPtr((String*)op1));
            }
            #endif // DEBUGGER
            #ifdef VMCFG_VTUNE
                Ins(LIR_file, InsConstPtr((String*)op1));
            #endif /* VMCFG_VTUNE */
                break;
            }

            case OP_debugline:
            {
            #ifdef DEBUGGER
            if (haveDebugger) {
                // todo refactor api's so we don't have to pass argv/argc
                LIns* debugger = loadIns(LIR_ldp, offsetof(AvmCore, _debugger), coreAddr, ACCSET_OTHER, LOAD_CONST);
                callIns(FUNCTIONID(debugLine), 2,
                        debugger,
                        InsConst((int32_t)op1));
            }
            #endif // DEBUGGER
            #ifdef VMCFG_VTUNE
                Ins(LIR_line, InsConst((int32_t)op1));
            #endif /* VMCFG_VTUNE */
                break;
            }

            default:
            {
                AvmAssert(false); // unsupported
            }
        }

    } // emit()

    void CodegenLIR::emitIf(AbcOpcode opcode, const uint8_t* target, int a, int b)
    {
#ifdef DEBUGGER
        Sampler* s = core->get_sampler();
        if (s && s->sampling() && target < state->abc_pc)
        {
            emitSampleCheck();
        }
#endif

        //
        // compile instructions that cannot throw exceptions before we add exception handling logic
        //

        // op1 = abc opcode target
        // op2 = what local var contains condition

        LIns* cond;
        LOpcode br;

        switch (opcode)
        {
        case OP_iftrue:
            NanoAssert(state->value(a).traits == BOOLEAN_TYPE);
            br = LIR_jf;
            cond = eqi0(localGet(a));
            break;
        case OP_iffalse:
            NanoAssert(state->value(a).traits == BOOLEAN_TYPE);
            br = LIR_jt;
            cond = eqi0(localGet(a));
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

        if (cond->isImmI()) {
            if ((br == LIR_jt && cond->immI()) || (br == LIR_jf && !cond->immI())) {
                // taken
                br = LIR_j;
                cond = 0;
            }
            else {
                // not taken = no-op
                return;
            }
        }

        branchToAbcPos(br, cond, target);
    } // emitIf()

    // Try to optimize comparison of a function call yielding NUMBER_TYPE with another expression
    // of INT_TYPE.  We may be able to simplify the function and/or the comparison based on the
    // type or value, if constant, of the other argument.  The function call is normally presumed
    // to be the left-hand argument.  The swap parameter, if true, reverses this convention.

    static Specialization intCmpWithNumber[] = {
        { FUNCTIONID(String_charCodeAtFI),    FUNCTIONID(String_charCodeAtIU) },
        { FUNCTIONID(String_charCodeAtFU),    FUNCTIONID(String_charCodeAtIU) },
        { FUNCTIONID(String_charCodeAtFF),    FUNCTIONID(String_charCodeAtIF) },
        { 0, 0 }
    };

    LIns *CodegenLIR::optimizeIntCmpWithNumberCall(int callIndex, int otherIndex, LOpcode icmp, bool swap)
    {
        LIns* numSide = localGetf(callIndex);
        const CallInfo *ci = numSide->callInfo();

        // Try to optimize charCodeAt to return an integer if possible. Because it can return NaN for
        // out of bounds access, we need to limit our support to constant integer values that generate
        // the same results for both NaN (floating point result) and zero (NaN cast to integer result).
        // These are the six possibilities:
        // String.CharCodeAt == int - any constant integer but zero
        // String.CharCodeAt < int  - zero or any negative integer constant
        // String.CharCodeAt <= int - any negative integer constant
        // int == String.CharCodeAt - any constant integer but zero
        // int < String.CharCodeAt  - zero or any positive integer constant
        // int <= String.CharCodeAt - any positive integer constant

        if (ci == FUNCTIONID(String_charCodeAtFI) || ci == FUNCTIONID(String_charCodeAtFU) || ci == FUNCTIONID(String_charCodeAtFF)) {

            AvmAssert(numSide->opcode() == LIR_calld);

            LIns* intSide = localGet(otherIndex);
            if (!intSide->isImmI())
                return NULL;
            int32_t intVal = intSide->immI();

            if ((icmp == LIR_eqi && intVal != 0) ||
                (icmp == LIR_lti && (swap ? intVal >= 0 : intVal <= 0)) ||
                (icmp == LIR_lei && (swap ? intVal > 0 : intVal < 0))) {

                numSide = specializeIntCall(numSide, intCmpWithNumber);
                AvmAssert(numSide != NULL);
                if (swap) {
                    return binaryIns(icmp, intSide, numSide);
                } else {
                    return binaryIns(icmp, numSide, intSide);
                }
            }
        }

        return NULL;
    }

    static Specialization stringCmpWithString[] = {
        { FUNCTIONID(String_charAtI),    FUNCTIONID(String_charCodeAtII) },
        { FUNCTIONID(String_charAtU),    FUNCTIONID(String_charCodeAtIU) },
        { FUNCTIONID(String_charAtF),    FUNCTIONID(String_charCodeAtIF) },
        { 0, 0 }
    };

    LIns *CodegenLIR::optimizeStringCmpWithStringCall(int callIndex, int otherIndex, LOpcode icmp, bool swap)
    {
        LIns* callSide = localGetp(callIndex);
        const CallInfo *ci = callSide->callInfo();
        if (ci == FUNCTIONID(String_charAtI) || ci == FUNCTIONID(String_charAtU) || ci == FUNCTIONID(String_charAtF)) {
            LIns*  strSide = localGetp(otherIndex);
            if (!strSide->isImmP())
                return NULL;

            String *s = (String *) strSide->immP();
            // If we have a single character constant string that is not the null
            // character, we can use charCodeAt which is about 2x faster.
            if (s->length() == 1 && s->charAt(0) != 0) {
                int32_t firstChar = s->charAt(0);
                strSide = InsConst(firstChar);
                callSide = specializeIntCall(callSide, stringCmpWithString);
                AvmAssert(callSide != NULL);
                if (swap) {
                    return binaryIns(icmp, strSide, callSide);
                } else {
                    return binaryIns(icmp, callSide, strSide);
                }
            }
        }

        return NULL;
    }

    // Faster compares for int, uint, double, boolean
    LIns* CodegenLIR::cmpOptimization(int lhsi, int rhsi, LOpcode icmp, LOpcode ucmp, LOpcode fcmp)
    {
        Traits* lht = state->value(lhsi).traits;
        Traits* rht = state->value(rhsi).traits;

        if (lht == rht && (lht == INT_TYPE || lht == BOOLEAN_TYPE))
        {
            LIns* lhs = localGet(lhsi);
            LIns* rhs = localGet(rhsi);
            return binaryIns(icmp, lhs, rhs);
        }
        else if (lht == rht && lht == UINT_TYPE)
        {
            LIns* lhs = localGet(lhsi);
            LIns* rhs = localGet(rhsi);
            return binaryIns(ucmp, lhs, rhs);
        }
        else if (lht && lht->isNumeric() && rht && rht->isNumeric())
        {
            // Comparing the result of a call returning a Number to another int value.
            if (lht == NUMBER_TYPE && rht == INT_TYPE && localGetf(lhsi)->opcode() == LIR_calld) {
                LIns* result = optimizeIntCmpWithNumberCall(lhsi, rhsi, icmp, false);
                if (result)
                    return result;
            }
            if (rht == NUMBER_TYPE && lht == INT_TYPE && localGetf(rhsi)->opcode() == LIR_calld) {
                LIns* result = optimizeIntCmpWithNumberCall(rhsi, lhsi, icmp, true);
                if (result)
                    return result;
            }

            // If we're comparing a uint to an int and the int is a non-negative
            // integer constant, don't promote to doubles for the compare
            if ((lht == UINT_TYPE) && (rht == INT_TYPE))
            {
                LIns* lhs = localGet(lhsi);
                LIns* rhs = localGet(rhsi);
            #ifdef AVMPLUS_64BIT
                // 32-bit signed and unsigned values fit in 64-bit registers
                // so we can promote and simply do a signed 64bit compare
                LOpcode qcmp = cmpOpcodeI2Q(icmp);
                NanoAssert((icmp == LIR_eqi && qcmp == LIR_eqq) ||
                           (icmp == LIR_lti && qcmp == LIR_ltq) ||
                           (icmp == LIR_lei && qcmp == LIR_leq));
                return binaryIns(qcmp, ui2p(lhs), i2p(rhs));
            #else
                if (rhs->isImmI() && rhs->immI() >= 0)
                    return binaryIns(ucmp, lhs, rhs);
            #endif
            }
            else if ((lht == INT_TYPE) && (rht == UINT_TYPE))
            {
                LIns* lhs = localGet(lhsi);
                LIns* rhs = localGet(rhsi);
            #ifdef AVMPLUS_64BIT
                // 32-bit signed and unsigned values fit in 64-bit registers
                // so we can promote and simply do a signed 64bit compare
                LOpcode qcmp = cmpOpcodeI2Q(icmp);
                NanoAssert((icmp == LIR_eqi && qcmp == LIR_eqq) ||
                           (icmp == LIR_lti && qcmp == LIR_ltq) ||
                           (icmp == LIR_lei && qcmp == LIR_leq));
                return binaryIns(qcmp, i2p(lhs), ui2p(rhs));
            #else
                if (lhs->isImmI() && lhs->immI() >= 0)
                    return binaryIns(ucmp, lhs, rhs);
            #endif
            }

            LIns* lhs = promoteNumberIns(lht, lhsi);
            LIns* rhs = promoteNumberIns(rht, rhsi);
            return binaryIns(fcmp, lhs, rhs);
        }

        if (lht == STRING_TYPE && rht == STRING_TYPE) {
            if (localGetp(lhsi)->opcode() == LIR_calli) {
                LIns* result = optimizeStringCmpWithStringCall(lhsi, rhsi, icmp, false);
                if (result)
                    return result;
            }
            else if (localGetp(rhsi)->opcode() == LIR_calli) {
                LIns* result = optimizeStringCmpWithStringCall(rhsi, lhsi, icmp, true);
                if (result)
                    return result;
            }
        }

        return NULL;
    }

    // set cc's for < operator
    LIns* CodegenLIR::cmpLt(int lhsi, int rhsi)
    {
        LIns *result = cmpOptimization(lhsi, rhsi, LIR_lti, LIR_ltui, LIR_ltd);
        if (result)
            return result;

        AvmAssert(trueAtom == 13);
        AvmAssert(falseAtom == 5);
        AvmAssert(undefinedAtom == 4);
        LIns* lhs = loadAtomRep(lhsi);
        LIns* rhs = loadAtomRep(rhsi);
        LIns* atom = callIns(FUNCTIONID(compare), 3,
            coreAddr, lhs, rhs);

        // caller will use jt for (a<b) and jf for !(a<b)
        // compare          ^8    <8
        // true       1101  0101   y
        // false      0101  1101   n
        // undefined  0100  1100   n

        LIns* c = InsConst(8);
        return binaryIns(LIR_lti, binaryIns(LIR_xori, p2i(atom), c), c);
    }

    LIns* CodegenLIR::cmpLe(int lhsi, int rhsi)
    {
        LIns *result = cmpOptimization(lhsi, rhsi, LIR_lei, LIR_leui, LIR_led);
        if (result)
            return result;

        LIns* lhs = loadAtomRep(lhsi);
        LIns* rhs = loadAtomRep(rhsi);
        LIns* atom = callIns(FUNCTIONID(compare), 3,
            coreAddr, rhs, lhs);

        // assume caller will use jt for (a<=b) and jf for !(a<=b)
        // compare          ^1    <=4
        // true       1101  1100  n
        // false      0101  0100  y
        // undefined  0100  0101  n

        LIns* c2 = InsConst(1);
        LIns* c4 = InsConst(4);
        return binaryIns(LIR_lei, binaryIns(LIR_xori, p2i(atom), c2), c4);
    }

    LIns* CodegenLIR::cmpEq(const CallInfo *fid, int lhsi, int rhsi)
    {
        LIns *result = cmpOptimization(lhsi, rhsi, LIR_eqi, LIR_eqi, LIR_eqd);
        if (result) {
            return result;
        }

        Traits* lht = state->value(lhsi).traits;
        Traits* rht = state->value(rhsi).traits;

        // There are various conditions we can check for that simplify our equality check down
        // to a ptr comparison:
        //  - null and a type that does not require complex equality checks
        //  - null and a string - no string comparison is performed, just ptrs
        //  - both types do not have complex equality checks (non builtin derived Object types)
        // This does not work for various other types (not a complete list) such as:
        //    string vs string - performs string comparison
        //    number vs string - type conversion is performed
        //    XML types - complex equality checks
        //    OBJECT_TYPE - this can mean even Number and String
        if (((lht == NULL_TYPE) && (rht && (!rht->hasComplexEqualityRules() || rht == STRING_TYPE))) ||
            ((rht == NULL_TYPE) && (lht && (!lht->hasComplexEqualityRules() || lht == STRING_TYPE))) ||
            ((rht && !rht->hasComplexEqualityRules()) && (lht && !lht->hasComplexEqualityRules()))) {
            LIns* lhs = localGetp(lhsi);
            LIns* rhs = localGetp(rhsi);
            return binaryIns(LIR_eqp, lhs, rhs);
        }

        if ((lht == rht) && (lht == STRING_TYPE)) {
            LIns* lhs = localGetp(lhsi);
            LIns* rhs = localGetp(rhsi);
            return callIns(FUNCTIONID(String_equals), 2, lhs, rhs, result);
        }

        LIns* lhs = loadAtomRep(lhsi);
        LIns* rhs = loadAtomRep(rhsi);
        LIns* out = callIns(fid, 3, coreAddr, lhs, rhs);
        result = binaryIns(LIR_eqp, out, InsConstAtom(trueAtom));
        return result;
    }

    void CodegenLIR::writeEpilogue(const FrameState *state)
    {
        this->state = state;
        this->labelCount = driver->getBlockCount();

        if (mop_rangeCheckFailed_label.unpatchedEdges) {
            emitLabel(mop_rangeCheckFailed_label);
            Ins(LIR_regfence);
            callIns(FUNCTIONID(mop_rangeCheckFailed), 1, env_param);
        }

        if (npe_label.unpatchedEdges) {
            emitLabel(npe_label);
            Ins(LIR_regfence);
            callIns(FUNCTIONID(npe), 1, env_param);
        }

        if (upe_label.unpatchedEdges) {
            emitLabel(upe_label);
            Ins(LIR_regfence);
            callIns(FUNCTIONID(upe), 1, env_param);
        }

        if (interrupt_label.unpatchedEdges) {
            emitLabel(interrupt_label);
            Ins(LIR_regfence);
            callIns(FUNCTIONID(handleInterruptMethodEnv), 1, env_param);
        }

        if (driver->hasReachableExceptions()) {
            // exception case
            emitLabel(catch_label);

            // This regfence is necessary for correctness,
            // as register contents after a longjmp are unpredictable.
            Ins(LIR_regfence);

            // _ef.beginCatch()
            int stackBase = ms->stack_base();
            LIns* pc = loadIns(LIR_ldp, 0, _save_eip, ACCSET_OTHER);
            LIns* slotAddr = leaIns(stackBase * VARSIZE, vars);
            LIns* tagAddr = leaIns(stackBase, tags);
            LIns* handler_ordinal = callIns(FUNCTIONID(beginCatch), 6, coreAddr, _ef, InsConstPtr(info), pc, slotAddr, tagAddr);

            int handler_count = info->abc_exceptions()->exception_count;
            // Jump to catch handler
            // Find last handler, to optimize branches generated below.
            int i;
            for (i = handler_count-1; i >= 0; i--) {
                ExceptionHandler* h = &info->abc_exceptions()->exceptions[i];
                const uint8_t* handler_pc = code_pos + h->target;
                if (driver->hasFrameState(handler_pc)) break;
            }
            int last_ordinal = i;
            // There should be at least one reachable handler.
            AvmAssert(last_ordinal >= 0);
            // Do a compare & branch to each possible target.
            for (int j = 0; j <= last_ordinal; j++) {
                ExceptionHandler* h = &info->abc_exceptions()->exceptions[j];
                const uint8_t* handler_pc = code_pos + h->target;
                if (driver->hasFrameState(handler_pc)) {
                    CodegenLabel& label = getCodegenLabel(handler_pc);
                    AvmAssert(label.labelIns != NULL);
                    if (j == last_ordinal) {
                        lirout->insBranch(LIR_j, NULL, label.labelIns);
                    } else {
                        LIns* cond = binaryIns(LIR_eqi, handler_ordinal, InsConst(j));
                        // Don't use branchToLabel() here because we don't want to check null bits;
                        // this backedge is internal to exception handling and doesn't affect user
                        // variable dataflow.
                        lirout->insBranch(LIR_jt, cond, label.labelIns);
                    }
                }
            }
            livep(_ef);
            livep(_save_eip);
        }

        if (prolog->env_scope)      livep(prolog->env_scope);
        if (prolog->env_vtable)     livep(prolog->env_vtable);
        if (prolog->env_abcenv)     livep(prolog->env_abcenv);
        if (prolog->env_domainenv)  livep(prolog->env_domainenv);
        if (prolog->env_toplevel)   livep(prolog->env_toplevel);
        if (restArgc) {
            lirout->ins1(LIR_livei, restArgc);
            livep(ap_param);
        }

        #ifdef DEBUGGER
        if (haveDebugger)
            livep(csn);
        #endif

        // extend live range of critical stuff
        // fixme -- this should be automatic based on live analysis
        livep(methodFrame);
        livep(env_param);
        frag->lastIns = livep(coreAddr);
        skip_ins->overwriteWithSkip(prolog->lastIns);

        info->set_lookup_cache_size(finddef_cache_builder.next_cache);

        // After CodeWriter::writeEpilogue() is called, driver is invalid
        // and could be destructed.  Null out our pointer as a precaution.
        this->driver = NULL;
    }

    // emit code to create a stack-allocated copy of the given multiname.
    // this helper only initializes Multiname.flags and Multiname.next_index
    LIns* CodegenLIR::copyMultiname(const Multiname* multiname)
    {
        LIns* name = insAlloc(sizeof(Multiname));
        sti(InsConst(multiname->ctFlags()), name, offsetof(Multiname, flags), ACCSET_OTHER);
        sti(InsConst(multiname->next_index), name, offsetof(Multiname, next_index), ACCSET_OTHER);
        return name;
    }

    LIns* CodegenLIR::initMultiname(const Multiname* multiname, int& csp, bool isDelete /*=false*/)
    {
        if (!multiname->isRuntime()) {
            // use the precomputed multiname
            return InsConstPtr(multiname);
        }

        // create an initialize a copy of the given multiname
        LIns* _tempname = copyMultiname(multiname);

        // then initialize its name and ns|nsset fields.
        LIns* nameAtom = NULL;
        if (multiname->isRtname())
        {
            nameAtom = loadAtomRep(csp--);
        }
        else
        {
            // copy the compile-time name to the temp name
            LIns* mName = InsConstPtr(multiname->name);
            stp(mName, _tempname, offsetof(Multiname,name), ACCSET_OTHER);
        }

        if (multiname->isRtns())
        {
            // intern the runtime namespace and copy to the temp multiname
            LIns* nsAtom = loadAtomRep(csp--);
            LIns* internNs = callIns(FUNCTIONID(internRtns), 2,
                env_param, nsAtom);

            stp(internNs, _tempname, offsetof(Multiname,ns), ACCSET_OTHER);
        }
        else
        {
            // copy the compile-time namespace to the temp multiname
            LIns* mSpace = InsConstPtr(multiname->ns);
            stp(mSpace, _tempname, offsetof(Multiname, ns), ACCSET_OTHER);
        }

        // Call initMultinameLate as the last step, since if a runtime
        // namespace is present, initMultinameLate may clobber it if a
        // QName is provided as index.
        if (nameAtom)
        {
            if (isDelete)
            {
                callIns(FUNCTIONID(initMultinameLateForDelete), 3,
                        env_param, _tempname, nameAtom);
            }
            else
            {
                callIns(FUNCTIONID(initMultinameLate), 3,
                        coreAddr, _tempname, nameAtom);
            }
        }

        return _tempname;
    }

    LIns* CodegenLIR::mopAddrToRangeCheckedRealAddrAndDisp(LIns* mopAddr, int32_t const size, int32_t* disp)
    {
        AvmAssert(size > 0);    // it's signed to help make the int promotion correct

        if (!mopsRangeCheckFilter) {
            // add a MopsRangeCheckFilter to the back end of the lirout pipeline, just after CseFilter.
            // fixme bug Bug 554030: We must put this after CseFilter and ExprFilter so that
            // the range-check expression using LIR_addi/LIR_subi are not modified (by ExprFilter)
            // and no not become referenced by other unrelated code (by CseFilter).
            AvmAssert(lirout == varTracker);
            mopsRangeCheckFilter = new (*alloc1) MopsRangeCheckFilter(redirectWriter->out, prolog, loadEnvDomainEnv());
            redirectWriter->out = mopsRangeCheckFilter;
        }

        // note, mopAddr and disp are both in/out parameters
        LIns* br = NULL;
        LIns* mopsMemoryBase = mopsRangeCheckFilter->emitRangeCheck(mopAddr, size, disp, br);
        if (br)
            patchLater(br, mop_rangeCheckFailed_label);


        // if mopAddr is a compiletime constant, we still have to do the range-check above
        // (since globalMemorySize can vary at runtime), but we might be able to encode
        // the entire address into the displacement (if any)...
        if (mopAddr->isImmI() && disp != NULL && sumFitsInInt32(*disp, mopAddr->immI()))
        {
            *disp += mopAddr->immI();
            return mopsMemoryBase;
        }

        // (yes, i2p, not u2p... it might legitimately be negative due to the
        // displacement optimization in emitCheck().)
        return binaryIns(LIR_addp, mopsMemoryBase, i2p(mopAddr));
    }

    LIns* CodegenLIR::loadEnvScope()
    {
        LIns* scope = prolog->env_scope;
        if (!scope)
        {
            prolog->env_scope = scope = prolog->insLoad(LIR_ldp, env_param, offsetof(MethodEnv, _scope), ACCSET_OTHER, LOAD_CONST);
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(scope, "env_scope");
            })
            verbose_only( if (vbWriter) { vbWriter->flush(); } )
        }
        return scope;
    }

    LIns* CodegenLIR::loadEnvVTable()
    {
        LIns* vtable = prolog->env_vtable;
        if (!vtable)
        {
            LIns* scope = loadEnvScope();
            prolog->env_vtable = vtable = prolog->insLoad(LIR_ldp, scope, offsetof(ScopeChain, _vtable), ACCSET_OTHER, LOAD_CONST);
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(vtable, "env_vtable");
            })
            verbose_only( if (vbWriter) { vbWriter->flush(); } )
        }
        return vtable;
    }

    LIns* CodegenLIR::loadEnvAbcEnv()
    {
        LIns* abcenv = prolog->env_abcenv;
        if (!abcenv)
        {
            LIns* scope = loadEnvScope();
            prolog->env_abcenv = abcenv = prolog->insLoad(LIR_ldp, scope, offsetof(ScopeChain, _abcEnv), ACCSET_OTHER, LOAD_CONST);
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(abcenv, "env_abcenv");
            })
            verbose_only( if (vbWriter) { vbWriter->flush(); } )
        }
        return abcenv;
    }

    LIns* CodegenLIR::loadEnvDomainEnv()
    {
        LIns* domainenv = prolog->env_domainenv;
        if (!domainenv)
        {
            LIns* abcenv = loadEnvAbcEnv();
            prolog->env_domainenv = domainenv = prolog->insLoad(LIR_ldp, abcenv, offsetof(AbcEnv, m_domainEnv), ACCSET_OTHER, LOAD_CONST);
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(domainenv, "env_domainenv");
            })
            verbose_only( if (vbWriter) { vbWriter->flush(); } )
        }
        return domainenv;
    }

    LIns* CodegenLIR::loadEnvToplevel()
    {
        LIns* toplevel = prolog->env_toplevel;
        if (!toplevel)
        {
            LIns* vtable = loadEnvVTable();
            prolog->env_toplevel = toplevel = prolog->insLoad(LIR_ldp, vtable, offsetof(VTable, _toplevel), ACCSET_OTHER, LOAD_CONST);
            verbose_only( if (vbNames) {
                vbNames->lirNameMap->addName(toplevel, "env_toplevel");
            })
            verbose_only( if (vbWriter) { vbWriter->flush(); } )
        }
        return toplevel;
    }

    /**
     * given an object and type, produce code that loads the VTable for
     * the object.  Handles all types: primitive vables get loaded from
     * Toplevel, Object and * vtables get loaded by calling the toVTable() helper.
     * ScriptObject* vtables are loaded from the ScriptObject.
     */
    LIns* CodegenLIR::loadVTable(LIns* obj, Traits* t)
    {
        if (t && !t->isMachineType() && t != STRING_TYPE && t != NAMESPACE_TYPE && t != NULL_TYPE)
        {
            // must be a pointer to a scriptobject, and we've done the n
            // all other types are ScriptObject, and we've done the null check
            return loadIns(LIR_ldp, offsetof(ScriptObject, vtable), obj, ACCSET_OTHER, LOAD_CONST);
        }

        LIns* toplevel = loadEnvToplevel();

        int offset;
        if (t == NAMESPACE_TYPE)    offset = offsetof(Toplevel, _namespaceClass);
        else if (t == STRING_TYPE)  offset = offsetof(Toplevel, _stringClass);
        else if (t == BOOLEAN_TYPE) offset = offsetof(Toplevel, _booleanClass);
        else if (t == NUMBER_TYPE)  offset = offsetof(Toplevel, _numberClass);
        else if (t == INT_TYPE)     offset = offsetof(Toplevel, _intClass);
        else if (t == UINT_TYPE)    offset = offsetof(Toplevel, _uintClass);
        else
        {
            // *, Object or Void
            LIns* atom = nativeToAtom(obj, t);
            return callIns(FUNCTIONID(toVTable), 2, toplevel, atom);
        }

        // now offset != -1 and we are returning a primitive vtable

        LIns* cc = loadIns(LIR_ldp, offset, toplevel, ACCSET_OTHER, LOAD_CONST);
        LIns* cvtable = loadIns(LIR_ldp, offsetof(ClassClosure, vtable), cc, ACCSET_OTHER, LOAD_CONST);
        return loadIns(LIR_ldp, offsetof(VTable, ivtable), cvtable, ACCSET_OTHER, LOAD_CONST);
    }

    LIns* CodegenLIR::promoteNumberIns(Traits* t, int i)
    {
        if (t == NUMBER_TYPE)
        {
            return localGetf(i);
        }
        if (t == INT_TYPE || t == BOOLEAN_TYPE)
        {
            return i2dIns(localGet(i));
        }
        AvmAssert(t == UINT_TYPE);
        return ui2dIns(localGet(i));
    }

    /// set position of a label and patch all pending jumps to point here.
    void CodegenLIR::emitLabel(CodegenLabel& label) {
        varTracker->trackLabel(label, state);

        // patch all unpatched branches to this label
        LIns* labelIns = label.labelIns;
        bool jtbl_forward_target = false;
        for (Seq<InEdge>* p = label.unpatchedEdges; p != NULL; p = p->tail) {
            InEdge& patch = p->head;
            LIns* branchIns = patch.branchIns;
            if (branchIns->isop(LIR_jtbl)) {
                jtbl_forward_target = true;
                branchIns->setTarget(patch.index, labelIns);
            } else {
                AvmAssert(branchIns->isBranch() && patch.index == 0);
                branchIns->setTarget(labelIns);
            }
        }
        if (jtbl_forward_target) {
            // A jtbl (switch) jumps forward to here, creating a situation our
            // register allocator cannot handle; force regs to be loaded at the
            // start of this block.
            Ins(LIR_regfence);
        }

#ifdef NJ_VERBOSE
        if (vbNames && label.name)
            vbNames->lirNameMap->addName(label.labelIns, label.name);
#endif
    }

#ifdef DEBUGGER
    void CodegenLIR::emitSampleCheck()
    {
        /* @todo inline the sample check code, help!  */
        callIns(FUNCTIONID(sampleCheck), 1, coreAddr);
    }
#endif

#ifdef NJ_VERBOSE
    bool CodegenLIR::verbose()
    {
        return pool->isVerbose(VB_jit);
    }
#endif

    // emit a conditional branch to the given label.  If we have already emitted
    // code for that label then the branch is complete.  If not then add a patch
    // record to the label, which will patch the branch when the label position
    // is reached.  cond == NULL for unconditional branches (LIR_j).
    void CodegenLIR::branchToLabel(LOpcode op, LIns *cond, CodegenLabel& label) {
        if (cond && !cond->isCmp()) {
            // branching on a non-condition expression, so test (v==0)
            // and invert the sense of the branch.
            cond = eqi0(cond);
            op = invertCondJmpOpcode(op);
        }
        LIns* labelIns = label.labelIns;
        LIns* br = lirout->insBranch(op, cond, labelIns);
        if (br != NULL) {
            if (labelIns != NULL) {
                varTracker->checkBackEdge(label, state);
            } else {
                label.unpatchedEdges = new (*alloc1) Seq<InEdge>(InEdge(br), label.unpatchedEdges);
                varTracker->trackForwardEdge(label, false);
            }
        } else {
            // branch was optimized away.  do nothing.
        }
    }

    LIns* CodegenLIR::branchJovToLabel(LOpcode op, LIns *a, LIns *b, CodegenLabel& label) {
        LIns* labelIns = label.labelIns;
        LIns* result = lirout->insBranchJov(op, a, b, labelIns);
        NanoAssert(result);
        if (result->isop(op)) {
            if (labelIns != NULL) {
                varTracker->checkBackEdge(label, state);
            } else {
                label.unpatchedEdges = new (*alloc1) Seq<InEdge>(InEdge(result), label.unpatchedEdges);
                varTracker->trackForwardEdge(label, false);
            }
        } else {
            // The root operator of the expression has been eliminated via
            // constant folding or other simplification.  This is only valid
            // if no overflow is possible, in which case the branch is not needed.
            // Do nothing.
        }
        return result;
    }

    // emit a relative branch to the given ABC pc-offset by mapping pc
    // to a corresponding CodegenLabel, and creating a new one if necessary
    void CodegenLIR::branchToAbcPos(LOpcode op, LIns *cond, const uint8_t* pc) {
        CodegenLabel& label = getCodegenLabel(pc);
        branchToLabel(op, cond, label);
    }

    CodegenLabel& CodegenLIR::createLabel(const char* name) {
        return *(new (*alloc1) CodegenLabel(name));
    }

    CodegenLabel& CodegenLIR::createLabel(const char* prefix, int id) {
        CodegenLabel* label = new (*alloc1) CodegenLabel();
#ifdef NJ_VERBOSE
        if (vbNames) {
            char *name = new (*lir_alloc) char[VMPI_strlen(prefix)+16];
            VMPI_sprintf(name, "%s%d", prefix, id);
            label->name = name;
        }
#else
        (void) prefix;
        (void) id;
#endif
        return *label;
    }

    CodegenLabel& CodegenLIR::getCodegenLabel(const uint8_t* pc) {
        AvmAssert(driver->hasFrameState(pc));
        if (!blockLabels)
            blockLabels = new (*alloc1) HashMap<const uint8_t*,CodegenLabel*>(*alloc1, driver->getBlockCount());
        CodegenLabel* label = blockLabels->get(pc);
        if (!label) {
            label = new (*alloc1) CodegenLabel();
            blockLabels->put(pc, label);
        }
#ifdef NJ_VERBOSE
        if (!label->name && vbNames) {
            char *name = new (*lir_alloc) char[16];
            VMPI_sprintf(name, "B%d", int(pc - code_pos));
            label->name = name;
        }
#endif
        return *label;
    }

    /// connect to a label for one entry of a switch
    void CodegenLIR::patchLater(LIns* jtbl, const uint8_t* pc, uint32_t index) {
        CodegenLabel& target = getCodegenLabel(pc);
        if (target.labelIns != 0) {
            jtbl->setTarget(index, target.labelIns);           // backward edge
            varTracker->checkBackEdge(target, state);
        } else {
            target.unpatchedEdges = new (*alloc1) Seq<InEdge>(InEdge(jtbl, index), target.unpatchedEdges);
            varTracker->trackForwardEdge(target, false);
        }
    }

    void CodegenLIR::patchLater(LIns *br, CodegenLabel &target) {
        if (!br) return; // occurs if branch was unconditional and thus never emitted.
        if (target.labelIns != 0) {
            br->setTarget(target.labelIns); // backwards edge
            varTracker->checkBackEdge(target, state);
        } else {
            target.unpatchedEdges = new (*alloc1) Seq<InEdge>(InEdge(br), target.unpatchedEdges);
            varTracker->trackForwardEdge(target, false);
        }
    }

    LIns* CodegenLIR::insAlloc(int32_t size) {
        return lirout->insAlloc(size >= 4 ? size : 4);
    }

    LIns* CodegenLIR::insAllocForTraits(Traits *t)
    {
        switch (bt(t)) {
            case BUILTIN_number:
                return insAlloc(sizeof(double));
            case BUILTIN_int:
            case BUILTIN_uint:
            case BUILTIN_boolean:
                return insAlloc(sizeof(int32_t));
            default:
                return insAlloc(sizeof(intptr_t));
        }
    }

    CodeMgr::CodeMgr() : codeAlloc(), bindingCaches(NULL)
    {
        verbose_only( log.lcbits = 0; )
    }

    void CodeMgr::flushBindingCaches()
    {
        // this clears vtable so all kObjectType receivers are invalidated.
        // of course, this field is also "tag" for primitive receivers,
        // but 0 is never a legal value there (and this is asserted when the tag is set)
        // so this should safely invalidate those as well (though we don't really need to invalidate them)
        for (BindingCache* b = bindingCaches; b != NULL; b = b->next)
            b->vtable = NULL;
    }

    void analyze_edge(LIns* label, nanojit::BitSet &livein,
                      LabelBitSet& labels, InsList* looplabels)
    {
        nanojit::BitSet *lset = labels.get(label);
        if (lset) {
            livein.setFrom(*lset);
        } else {
            AvmAssertMsg(looplabels != NULL, "Unexpected back-edge");
            looplabels->add(label);
        }
    }

    // Treat addp(vars, const) as a load from vars[const]
    // for the sake of dead store analysis.
    void analyze_addp(LIns* ins, LIns* vars, nanojit::BitSet& varlivein)
    {
        AvmAssert(ins->isop(LIR_addp));
        if (ins->oprnd1() == vars && ins->oprnd2()->isImmP()) {
            AvmAssert(IS_ALIGNED(ins->oprnd2()->immP(), VARSIZE));
            int d = int(uintptr_t(ins->oprnd2()->immP()) / VARSIZE);
            varlivein.set(d);
        }
    }

    // Treat the calculated address of addp(vars, const) as the target
    // of a store to the variable pointed to, as well as its associated tag.
    void analyze_addp_store(LIns* ins, LIns* vars, nanojit::BitSet& varlivein, nanojit::BitSet& taglivein)
    {
        AvmAssert(ins->isop(LIR_addp));
        if (ins->oprnd1() == vars && ins->oprnd2()->isImmP()) {
            AvmAssert(IS_ALIGNED(ins->oprnd2()->immP(), VARSIZE));
            int d = int(uintptr_t(ins->oprnd2()->immP()) / VARSIZE);
            varlivein.clear(d);
            taglivein.clear(d);
        }
    }

    void analyze_call(LIns* ins, LIns* catcher, LIns* vars, DEBUGGER_ONLY(bool haveDebugger, int dbg_framesize,)
            nanojit::BitSet& varlivein, LabelBitSet& varlabels,
            nanojit::BitSet& taglivein, LabelBitSet& taglabels)
    {
        if (ins->callInfo() == FUNCTIONID(beginCatch)) {
            // beginCatch(core, ef, info, pc, &vars[i], &tags[i]) => store to &vars[i] and &tag[i]
            LIns* varPtrArg = ins->arg(4);  // varPtrArg == vars, OR addp(vars, index)
            if (varPtrArg == vars) {
                varlivein.clear(0);
                taglivein.clear(0);
            } else if (varPtrArg->isop(LIR_addp)) {
                analyze_addp_store(varPtrArg, vars, varlivein, taglivein);
            }
        } else if (!ins->callInfo()->_isPure) {
            if (catcher) {
                // non-cse call is like a conditional forward branch to the catcher label.
                // this could be made more precise by checking whether this call
                // can really throw, and only processing edges to the subset of
                // reachable catch blocks.  If we haven't seen the catch label yet then
                // the call is to an exception handling helper (eg beginCatch())
                // that won't throw.
                nanojit::BitSet *varlset = varlabels.get(catcher);
                if (varlset)
                    varlivein.setFrom(*varlset);
                nanojit::BitSet *taglset = taglabels.get(catcher);
                if (taglset)
                    taglivein.setFrom(*taglset);
            }
#ifdef DEBUGGER
            if (haveDebugger) {
                // all vars and scopes must be considered "read" by any call
                // the debugger can stop in.  The debugger also will access tags[].
                for (int i = 0, n = dbg_framesize; i < n; i++) {
                    varlivein.set(i);
                    taglivein.set(i);
                }
            }
#endif
        }
        else if (ins->callInfo() == FUNCTIONID(makeatom)) {
            // makeatom(core, &vars[index], tag[index]) => treat as load from &vars[index]
            LIns* varPtrArg = ins->arg(1);  // varPtrArg == vars, OR addp(vars, index)
            if (varPtrArg == vars)
                varlivein.set(0);
            else if (varPtrArg->isop(LIR_addp))
                analyze_addp(varPtrArg, vars, varlivein);
        }
        else if (ins->callInfo() == FUNCTIONID(restargHelper)) {
            // restargHelper(Toplevel*, Multiname*, Atom, ArrayObject**, uint32_t, Atom*)
            // The ArrayObject** is a reference to a var
            LIns* varPtrArg = ins->arg(3);  // varPtrArg == vars, OR addp(vars, index)
            if (varPtrArg == vars)
                varlivein.set(0);
            else if (varPtrArg->isop(LIR_addp))
                analyze_addp(varPtrArg, vars, varlivein);
        }
    }

    // Analyze a LIR_label.  We're at the top of a block, save livein for
    // this block so it can be propagated to predecessors.
    bool analyze_label(LIns* i, Allocator& alloc, bool again,
            int framesize, InsList* looplabels,
            nanojit::BitSet& varlivein, LabelBitSet& varlabels,
            nanojit::BitSet& taglivein, LabelBitSet& taglabels)
    {
        nanojit::BitSet *var_lset = varlabels.get(i);
        if (!var_lset) {
            var_lset = new (alloc) nanojit::BitSet(alloc, framesize);
            varlabels.put(i, var_lset);
        }
        if (var_lset->setFrom(varlivein) && !again) {
            for (Seq<LIns*>* p = looplabels->get(); p != NULL; p = p->tail) {
                if (p->head == i) {
                    again = true;
                    break;
                }
            }
        }
        nanojit::BitSet *tag_lset = taglabels.get(i);
        if (!tag_lset) {
            tag_lset = new (alloc) nanojit::BitSet(alloc, framesize);
            taglabels.put(i, tag_lset);
        }
        if (tag_lset->setFrom(taglivein) && !again) {
            for (Seq<LIns*>* p = looplabels->get(); p != NULL; p = p->tail) {
                if (p->head == i) {
                    again = true;
                    break;
                }
            }
        }
        return again;
    }

    void CodegenLIR::deadvars_analyze(Allocator& alloc,
            nanojit::BitSet& varlivein, LabelBitSet& varlabels,
            nanojit::BitSet& taglivein, LabelBitSet& taglabels)
    {
        LIns *catcher = this->catch_label.labelIns;
        InsList looplabels(alloc);

        verbose_only(int iter = 0;)
        bool again;
        do {
            again = false;
            varlivein.reset();
            taglivein.reset();
            LirReader in(frag->lastIns);
            for (LIns *i = in.read(); !i->isop(LIR_start); i = in.read()) {
                LOpcode op = i->opcode();
                switch (op) {
                case LIR_reti:
                CASE64(LIR_retq:)
                case LIR_retd:
                    varlivein.reset();
                    taglivein.reset();
                    break;
                CASE64(LIR_stq:)
                case LIR_sti:
                case LIR_std:
                case LIR_sti2c:
                    if (i->oprnd2() == vars) {
                        int d = i->disp() / VARSIZE;
                        varlivein.clear(d);
                    } else if (i->oprnd2() == tags) {
                        int d = i->disp(); // 1 byte per tag
                        taglivein.clear(d);
                    }
                    break;
                case LIR_addp:
                    // treat pointer calculations into vars as a read from vars
                    // FIXME: Bug 569677
                    // This is extremely fragile.  There is no reason to suppose
                    // that the address will be used for a read rather than a store,
                    // other than that to do so would break the deadvars analysis
                    // because of the dodgy assumption made here.
                    analyze_addp(i, vars, varlivein);
                    break;
                CASE64(LIR_ldq:)
                case LIR_ldi:
                case LIR_ldd:
                case LIR_lduc2ui: case LIR_ldc2i:
                    if (i->oprnd1() == vars) {
                        int d = i->disp() / VARSIZE;
                        varlivein.set(d);
                    }
                    else if (i->oprnd1() == tags) {
                        int d = i->disp(); // 1 byte per tag
                        taglivein.set(d);
                    }
                    break;
                case LIR_label:
                    again |= analyze_label(i, alloc, again, framesize, &looplabels,
                            varlivein, varlabels, taglivein, taglabels);
                    break;
                case LIR_j:
                    // the fallthrough path is unreachable, clear it.
                    varlivein.reset();
                    taglivein.reset();
                    // fall through to other branch cases
                case LIR_jt:
                case LIR_jf:
                    // merge the LiveIn sets from each successor:  the fall
                    // through case (livein) and the branch case (lset).
                    analyze_edge(i->getTarget(), varlivein, varlabels, &looplabels);
                    analyze_edge(i->getTarget(), taglivein, taglabels, &looplabels);
                    break;
                case LIR_jtbl:
                    varlivein.reset(); // fallthrough path is unreachable, clear it.
                    taglivein.reset(); // fallthrough path is unreachable, clear it.
                    for (uint32_t j=0, n=i->getTableSize(); j < n; j++) {
                        analyze_edge(i->getTarget(j), varlivein, varlabels, &looplabels);
                        analyze_edge(i->getTarget(j), taglivein, taglabels, &looplabels);
                    }
                    break;
                CASE64(LIR_callq:)
                case LIR_calli:
                case LIR_calld:
                case LIR_callv:
                    analyze_call(i, catcher, vars, DEBUGGER_ONLY(haveDebugger, dbg_framesize,)
                            varlivein, varlabels, taglivein, taglabels);
                    break;
                }
            }
            verbose_only(iter++;)
        }
        while (again);

        // now make a final pass, modifying LIR to delete dead stores (make them LIR_neartramps)
        verbose_only( if (pool->isVerbose(LC_Liveness))
            AvmLog("killing dead stores after %d LA iterations.\n",iter);
        )
    }

    // Erase the instruction by rewriting it as a skip.
    // TODO this can go away if we turn this kill pass into a LirReader
    // and do the work inline with the assembly pass.
    void CodegenLIR::eraseIns(LIns* ins, LIns* prevIns)
    {
#ifdef NJ_VERBOSE
      LInsPrinter *printer = frag->lirbuf->printer;
      bool verbose = printer && pool->isVerbose(VB_jit);
      if (verbose) {
          InsBuf b;
          AvmLog("- %s\n", printer->formatIns(&b, ins));
      }
#endif
      ins->overwriteWithSkip(prevIns);
    }

    void CodegenLIR::deadvars_kill(Allocator& alloc,
            nanojit::BitSet& varlivein, LabelBitSet& varlabels,
            nanojit::BitSet& taglivein, LabelBitSet& taglabels)
    {
#ifdef NJ_VERBOSE
        LInsPrinter *printer = frag->lirbuf->printer;
        bool verbose = printer && pool->isVerbose(VB_jit);
        InsBuf b;
#endif
        LIns *catcher = this->catch_label.labelIns;
        varlivein.reset();
        taglivein.reset();
        bool tags_touched = false;
        bool vars_touched = false;
        LirReader in(frag->lastIns);
        for (LIns *i = in.read(); !i->isop(LIR_start); i = in.read()) {
            LOpcode op = i->opcode();
            switch (op) {
                case LIR_reti:
                CASE64(LIR_retq:)
                case LIR_retd:
                    varlivein.reset();
                    taglivein.reset();
                    break;
                CASE64(LIR_stq:)
                case LIR_sti:
                case LIR_std:
                case LIR_sti2c:
                    if (i->oprnd2() == vars) {
                        int d = i->disp() / VARSIZE;
                        if (!varlivein.get(d)) {
                            eraseIns(i, in.peek());
                            continue;
                        } else {
                            varlivein.clear(d);
                            vars_touched = true;
                        }
                    }
                    else if (i->oprnd2() == tags) {
                        int d = i->disp(); // 1 byte per tag
                        if (!taglivein.get(d)) {
                            eraseIns(i, in.peek());
                            continue;
                        } else {
                            // keep the store
                            taglivein.clear(d);
                            tags_touched = true;
                        }
                    }
                    break;
                case LIR_addp:
                    // treat pointer calculations into vars as a read from vars
                    analyze_addp(i, vars, varlivein);
                    break;
                CASE64(LIR_ldq:)
                case LIR_ldi:
                case LIR_ldd:
                case LIR_lduc2ui: case LIR_ldc2i:
                    if (i->oprnd1() == vars) {
                        int d = i->disp() / VARSIZE;
                        varlivein.set(d);
                    }
                    else if (i->oprnd1() == tags) {
                        int d = i->disp(); // 1 byte per tag
                        taglivein.set(d);
                    }
                    break;
                case LIR_label:
                    analyze_label(i, alloc, true, framesize, 0,
                            varlivein, varlabels, taglivein, taglabels);
                    break;
                case LIR_j:
                    // the fallthrough path is unreachable, clear it.
                    varlivein.reset();
                    taglivein.reset();
                    // fall through to other branch cases
                case LIR_jt:
                case LIR_jf:
                    // merge the LiveIn sets from each successor:  the fall
                    // through case (live) and the branch case (lset).
                    analyze_edge(i->getTarget(), varlivein, varlabels, 0);
                    analyze_edge(i->getTarget(), taglivein, taglabels, 0);
                    break;
                case LIR_jtbl:
                    varlivein.reset();
                    taglivein.reset();
                    for (uint32_t j = 0, n = i->getTableSize(); j < n; j++) {
                        analyze_edge(i->getTarget(j), varlivein, varlabels, 0);
                        analyze_edge(i->getTarget(j), taglivein, taglabels, 0);
                    }
                    break;
                CASE64(LIR_callq:)
                case LIR_calli:
                case LIR_calld:
                case LIR_callv:
                    analyze_call(i, catcher, vars, DEBUGGER_ONLY(haveDebugger, dbg_framesize,)
                            varlivein, varlabels, taglivein, taglabels);
                    break;
            }
            verbose_only(if (verbose) {
                AvmLog("  %s\n", printer->formatIns(&b, i));
            })
        }
        // if we have not removed all stores to the tags array, mark it live
        // so its live range will span loops.
        if (tags_touched)
            livep(tags);
        if (vars_touched)
            livep(vars);
    }

    /*
     * this is iterative live variable analysis.  We walk backwards through
     * the code.  when we see a load, we mark the variable live, and when
     * we see a store, we mark it dead.  Dead stores are dropped, not returned
     * by read().
     *
     * at labels, we save the liveIn set associated with that label.
     *
     * at branches, we merge the liveIn sets from the fall through case (which
     * is the current set) and the branch case (which was saved with the label).
     * this filter can be run multiple times, which is required to pick up
     * loop-carried live variables.
     *
     * once the live sets are stable, the DeadVars.kill flag is set to cause the filter
     * to not only drop dead stores, but overwrite them as tramps so they'll be
     * ignored by any later passes even without using this filter.
     */

    void CodegenLIR::deadvars()
    {
        // allocator used only for duration of this phase.  no exceptions are
        // thrown while this phase runs, hence no try/catch is necessary.
        Allocator dv_alloc;

        // map of label -> bitset, tracking what is livein at each label.
        // populated by deadvars_analyze, then used by deadvars_kill.
        // Estimated number of required buckets is based on the driver's block count,
        // which is slightly below the actual # of labels in LIR.  Being slightly low
        // is okay for a bucket hashtable.  note: labelCount is 0 for simple 1-block
        // methods, so use labelCount+1 as the estimate to ensure we have >0 buckets.
        LabelBitSet varlabels(dv_alloc, labelCount + 1);
        LabelBitSet taglabels(dv_alloc, labelCount + 1);

        // scratch bitset used by both dv_analyze and dv_kill.  Each resets
        // the bitset before using it.  creating it here saves one allocation.
        nanojit::BitSet varlivein(dv_alloc, framesize);
        nanojit::BitSet taglivein(dv_alloc, framesize);

        // If catch_label.labelIns is non-null, we emitted an exception
        // handler dispatcher, which generates back-edges into the method.
        if (varTracker->hasBackedges() || catch_label.labelIns)
            deadvars_analyze(dv_alloc, varlivein, varlabels, taglivein, taglabels);
        deadvars_kill(dv_alloc, varlivein, varlabels, taglivein, taglabels);
    }

#ifdef AVMPLUS_JITMAX
    int jitcount = 0;
    int jitmin = 1;
    int jitmax = 0x7fffffff;
#endif

#ifdef NJ_VERBOSE
    void listing(const char* title, AvmLogControl &log, Fragment* frag)
    {
        LirReader reader(frag->lastIns);
        Allocator lister_alloc;
        ReverseLister lister(&reader, lister_alloc, frag->lirbuf->printer, &log, title);
        for (LIns* ins = lister.read(); !ins->isop(LIR_start); ins = lister.read())
        {}
        lister.finish();
    }
#endif

    // return pointer to generated code on success, NULL on failure (frame size too large)
    GprMethodProc CodegenLIR::emitMD()
    {
        deadvars();  // deadvars_kill() will add livep(vars) or livep(tags) if necessary

        // do this very last so it's after livep(vars)
        frag->lastIns = livep(undefConst);

        PERFM_NTPROF_BEGIN("compile");
        mmfx_delete( alloc1 );
        alloc1 = NULL;

        CodeMgr *mgr = pool->codeMgr;
        #ifdef NJ_VERBOSE
        if (pool->isVerbose(LC_ReadLIR)) {
            StringBuffer sb(core);
            sb << info;
            core->console << "Final LIR " << info;
            listing(sb.c_str(), mgr->log, frag);
        }
        if (pool->isVerbose(LC_Liveness)) {
            Allocator live_alloc;
            LirReader in(frag->lastIns);
            nanojit::live(&in, live_alloc, frag, &mgr->log);
        }
        if (pool->isVerbose(LC_AfterDCE | LC_Native)) {
            StringBuffer sb(core);
            sb << info;
            mgr->log.printf("jit-assembler %s\n", sb.c_str());
        }
        #endif

        Assembler *assm = new (*lir_alloc) Assembler(mgr->codeAlloc, mgr->allocator, *lir_alloc, &mgr->log, core->config.njconfig);
        #ifdef VMCFG_VTUNE
        assm->vtuneHandle = vtuneInit(info->getMethodName());
        #endif /* VMCFG_VTUNE */

        assm->setNoiseGenerator( &noise );

        verbose_only( StringList asmOutput(*lir_alloc); )
        verbose_only( if (!pool->isVerbose(VB_raw)) assm->_outputCache = &asmOutput; )

        assm->beginAssembly(frag);
        LirReader reader(frag->lastIns);
        assm->assemble(frag, &reader);
        assm->endAssembly(frag);
        PERFM_NTPROF_END("compile");

        verbose_only(
            assm->_outputCache = 0;
            for (Seq<char*>* p = asmOutput.get(); p != NULL; p = p->tail) {
                assm->outputf("%s", p->head);
            }
        );

        PERFM_NVPROF("IR-bytes", frag->lirbuf->byteCount());
        PERFM_NVPROF("IR", frag->lirbuf->insCount());

        bool keep = //!driver->hasReachableExceptions() &&
            !assm->error();
#ifdef AVMPLUS_JITMAX
        jitcount++;
        keep = keep && (jitcount >= jitmin && jitcount <= jitmax);
        //AvmLog(stderr, "jitcount %d keep %d\n", jitcount, (int)keep);
#endif
        //_nvprof("keep",keep);
        GprMethodProc code;
        if (keep) {
#if defined AVMPLUS_JITMAX && defined NJ_VERBOSE
            if (pool->isVerbose(VB_execpolicy))
                AvmLog("keeping %d, loop=%d\n", jitcount, assm->hasLoop);
#endif
            // save pointer to generated code
            code = (GprMethodProc) frag->code();
            PERFM_NVPROF("JIT method bytes", CodeAlloc::size(assm->codeList));
        } else {
#if defined AVMPLUS_JITMAX && defined NJ_VERBOSE
            if (pool->isVerbose(VB_execpolicy))
                AvmLog("reverting to interpreter %d assm->error %d \n", jitcount, assm->error());
#endif
            // assm puked, or we did something untested, so interpret.
            code = NULL;
#ifdef AVMPLUS_JITMAX
            // we need to distiguish between an error and the policy saying we want
            // to interp.   In the latter case, we should free up jit resources.
            if (!assm->error())
                assm->cleanupAfterError();
#endif // AVMPLUS_JITMAX
            PERFM_NVPROF("lir-error",1);
        }

        #ifdef VMCFG_VTUNE
        if (assm->vtuneHandle) {
            vtuneCleanup(assm->vtuneHandle);
        }
        #endif /* VMCFG_VTUNE */
        return code;
    }

    REALLY_INLINE BindingCache::BindingCache(const Multiname* name, BindingCache* next)
        : name(name), next(next)
    {}

    REALLY_INLINE CallCache::CallCache(const Multiname* name, BindingCache* next)
        : BindingCache(name, next), call_handler(callprop_miss)
    {}

    REALLY_INLINE GetCache::GetCache(const Multiname* name, BindingCache* next)
        : BindingCache(name, next), get_handler(getprop_miss)
    {}

    REALLY_INLINE SetCache::SetCache(const Multiname* name, BindingCache* next)
        : BindingCache(name, next), set_handler(setprop_miss)
    {}

    template <class C>
    C* CacheBuilder<C>::findCacheSlot(const Multiname* name)
    {
        for (Seq<C*> *p = caches.get(); p != NULL; p = p->tail)
            if (p->head->name == name)
                return p->head;
        return NULL;
    }

    // The cache structure is expected to be small in the normal case, so use a
    // linear list.  For some programs, notably classical JS programs, it may however
    // be larger, and we may need a more sophisticated structure.
    template <class C>
    C* CacheBuilder<C>::allocateCacheSlot(const Multiname* name)
    {
        C* c = findCacheSlot(name);
        if (!c) {
            _nvprof("binding cache bytes", sizeof(C));
            c = new (codeMgr.allocator) C(name, codeMgr.bindingCaches);
            codeMgr.bindingCaches = c;
            caches.add(c);
        }
        return c;
    }
}

namespace nanojit
{
    int StackFilter::getTop(LIns* /*br*/) {
        AvmAssert(false);
        return 0;
    }

    #ifdef NJ_VERBOSE
    void LInsPrinter::formatGuard(InsBuf*, LIns*) {
        AvmAssert(false);
    }
    void LInsPrinter::formatGuardXov(InsBuf*, LIns*) {
        AvmAssert(false);
    }

    const char* LInsPrinter::accNames[] = {
        "v",    // (1 << 0) == ACCSET_VARS
        "t",    // (1 << 1) == ACCSET_TAGS
        "o",    // (1 << 2) == ACCSET_OTHER
                  "?", "?", "?", "?", "?", "?", "?", "?",   //  3..10 (unused)
        "?", "?", "?", "?", "?", "?", "?", "?", "?", "?",   // 11..20 (unused)
        "?", "?", "?", "?", "?", "?", "?", "?", "?", "?",   // 21..30 (unused)
        "?"                                                 //     31 (unused)
    };
    #endif

    void* Allocator::allocChunk(size_t size, bool /* fallible */) {
        return mmfx_alloc(size);
    }

    void Allocator::freeChunk(void* p) {
        mmfx_free(p);
    }

    void Allocator::postReset() {
    }

    void* CodeAlloc::allocCodeChunk(size_t nbytes) {
        return VMPI_allocateCodeMemory(nbytes);
    }

    void CodeAlloc::freeCodeChunk(void* addr, size_t nbytes) {
        VMPI_freeCodeMemory(addr, nbytes);
    }

    void CodeAlloc::markCodeChunkExec(void* addr, size_t nbytes) {
        //printf("protect   %d %p\n", (int)nbytes, addr);
        VMPI_makeCodeMemoryExecutable(addr, nbytes, true); // RX
    }

    void CodeAlloc::markCodeChunkWrite(void* addr, size_t nbytes) {
        //printf("unprotect %d %p\n", (int)nbytes, addr);
        VMPI_makeCodeMemoryExecutable(addr, nbytes, false); // RW
    }

#ifdef DEBUG
    void ValidateWriter::checkAccSet(LOpcode op, LIns* base, int32_t disp, AccSet accSet)
    {
        (void)disp;
        LIns* vars = checkAccSetExtras ? (LIns*)checkAccSetExtras[0] : 0;
        LIns* tags = checkAccSetExtras ? (LIns*)checkAccSetExtras[1] : 0;

        // not enough to check base == xxx , since cse or lirbuffer may split (ld/st,b,d) into (ld/st,(addp,b,d),0)
        bool isTags = (base == tags) ||
                      ( (base->opcode() == LIR_addp) && (base->oprnd1() == tags) );
        bool isVars = (base == vars) ||
                      ( (base->opcode() == LIR_addp) && (base->oprnd1() == vars) );
        bool isUnknown = !isTags && !isVars;

        bool ok;

        NanoAssert(accSet != ACCSET_NONE);
        switch (accSet) {
        case avmplus::ACCSET_VARS:   ok = isVars;        break;
        case avmplus::ACCSET_TAGS:   ok = isTags;        break;
        case avmplus::ACCSET_OTHER:  ok = isUnknown;     break;
        default:
            // This assertion will fail if any single-region AccSets aren't covered
            // by the switch -- only multi-region AccSets should be handled here.
            AvmAssert(compressAccSet(accSet).val == MINI_ACCSET_MULTIPLE.val);
            ok = true;
            break;
        }

        if (!ok) {
            InsBuf b1, b2;
            printer->formatIns(&b1, base);
            VMPI_snprintf(b2.buf, b2.len, "but the base pointer (%s) doesn't match", b1.buf);
            errorAccSet(lirNames[op], accSet, b2.buf);
         }
    }
#endif

}

//
// JIT compiler for invoker stubs
//
namespace avmplus
{
    bool InvokerCompiler::canCompileInvoker(MethodInfo* method)
    {
        MethodSignaturep ms = method->getMethodSignature();
        int32_t rest_offset = ms->rest_offset();
        int32_t param_count = ms->param_count();
        if (rest_offset > int32_t((param_count+1) * sizeof(Atom)) &&
            method->needRestOrArguments()) {
            // situation: natively represented args need more space than provided,
            // and this method uses varargs (rest args or arguments array); this means
            // the declared args must grow, which requires allocating an unknown amount
            // of space since we don't know (at compile time) how many extra varags are present.
            //
            // punt for now.  to better handle this in the future, the cases are:
            //
            // jit function with rest args:
            //   the prolog will create an array with these extra args, so all
            //   we should need is a way to pass in the pointer to them.  (tweak ABI).
            //
            // jit function that needs arguments:
            //   the prolog will create an array with all the args re-boxed as Atom,
            //   plus the extra ones.  (the unboxed copies are still available in the callee).
            //
            // native function with rest args:
            //   the native function abi passes rest args via (argc,Atom*) parameters
            //   which we could adapt to here without shifting or copying, if we could
            //   bypass the normal Gpr/FprMethodProc ABI.
            //
            // native function with arguments:
            //   doesn't happen.  native functions only support rest args.
            //
            // Given the current JIT and native ABI, we can't support shifting and
            // copying the extra unknown number of args.  With changes to the native
            // ABI, we could pass a reference to the extra args without any copying.
            return false;
        }
        return true;
    }

    // compiler driver
    AtomMethodProc InvokerCompiler::compile(MethodInfo* method)
    {
        InvokerCompiler compiler(method);
        compiler.generate_lir();
        return (AtomMethodProc) compiler.assemble();
    }

    InvokerCompiler::InvokerCompiler(MethodInfo* method)
        : LirHelper(method->pool())
        , method(method)
        , ms(method->getMethodSignature())
        , maxargs_br(NULL)
        , minargs_br(NULL)
    {
        this->method = method;
        this->ms = method->getMethodSignature();

        initCodeMgr(method->pool());
        frag = new (*lir_alloc) Fragment(0 verbose_only(, 0));
        LirBuffer* lirbuf = frag->lirbuf = new (*lir_alloc) LirBuffer(*lir_alloc);
        lirbuf->abi = ABI_CDECL;
        LirWriter* lirout = new (*alloc1) LirBufWriter(lirbuf, core->config.njconfig);
        verbose_only(
            if (verbose()) {
                lirbuf->printer = new (*lir_alloc) LInsPrinter(*lir_alloc, TR_NUM_USED_ACCS);
                lirbuf->printer->addrNameMap->addAddrRange(pool->core, sizeof(AvmCore), 0, "core");
            }
        )
        debug_only(
            lirout = validate2 = new (*alloc1) ValidateWriter(lirout, lirbuf->printer, "InvokerCompiler");
        )
        verbose_only(
            if (verbose()) {
                CodeMgr *codeMgr = method->pool()->codeMgr;
                core->console << "compileInvoker " << method << "\n";
                core->console <<
                    " required=" << ms->requiredParamCount() <<
                    " optional=" << (ms->param_count() - ms->requiredParamCount()) << "\n";
                lirout = new (*alloc1) VerboseWriter(*alloc1, lirout, lirbuf->printer, &codeMgr->log);
            }
        )
#if defined(NANOJIT_ARM)
        if (core->config.njconfig.soft_float)
        {
            lirout = new (*alloc1) SoftFloatFilter(lirout);
        }
#endif
        // add other LirWriters here
        this->lirout = lirout;
        emitStart(*alloc1, lirbuf, lirout);
    }

    // recipe for an invoke wrapper:
    //    Atom <generated invoker>(MethodEnv* env, int argc, Atom* argv) {
    //        1. check argc:            env->startCoerce(argc, env->get_ms());
    //        2. unbox args:            unboxCoerceArgs, unrolled for each arg
    //        3. return box(call(...))
    //    }

    // jit-compile an invoker for mi
    void InvokerCompiler::generate_lir()
    {
        // invoker params
        LIns* env_param = param(0, "env");
        LIns* argc_param = p2i(param(1, "argc"));
        LIns* args_param = param(2, "args");
        coreAddr = InsConstPtr(core);

        // if unboxing args will make them expand, allocate more space.
        int32_t rest_offset = ms->rest_offset();
        if (rest_offset > int32_t((ms->param_count()+1)*sizeof(Atom))) {
            AvmAssert(!method->needRestOrArguments());
            args_out = lirout->insAlloc(rest_offset);
        } else {
            // we can do in-place unboxing of args.
            args_out = args_param;
        }

        // 1. check argc
        emit_argc_check(argc_param);

        // 2. unbox & coerce args
        downcast_args(env_param, argc_param, args_param);

        // 3. call, box result, return atom
        call_method(env_param, argc_param);

        // error handler for argc error
        if (minargs_br || maxargs_br) {
            LIns* errlabel = label();
            if (minargs_br) minargs_br->setTarget(errlabel);
            if (maxargs_br) maxargs_br->setTarget(errlabel);
            callIns(FUNCTIONID(argcError), 2, env_param, argc_param);
        }

        // mark the endpoint of generated LIR with an instruction the Assembler allows at the end
        frag->lastIns = livep(env_param);

        // we're done with LIR generation, free up what we can.
        mmfx_delete(alloc1);
        alloc1 = NULL;
    }

    void InvokerCompiler::emit_argc_check(LIns* argc_param)
    {
        int min_argc = ms->requiredParamCount();
        int param_count = ms->param_count();
        if (min_argc == param_count && !ms->argcOk(param_count + 1)) {
            // exactly param_count args required
            // if (argc != param_count) goto error
            maxargs_br = jnei(argc_param, param_count);
        } else {
            if (!ms->argcOk(param_count+1)) {
                // extra params are not allowed, must check for max args
                // if (argc > param_count) goto error
                maxargs_br = jgti(argc_param, param_count);
            }
            if (min_argc > 0) {
                // at least 1 param is required, so check
                // if (argc < min_argc) goto error
                minargs_br = jlti(argc_param, min_argc);
            }
        }
    }

    void InvokerCompiler::downcast_arg(int i, int offset, LIns* env_param, LIns* args_param)
    {
        BuiltinType bt = ms->paramTraitsBT(i);
        if (bt != BUILTIN_any) {
            LIns* atom = ldp(args_param, i*sizeof(Atom), ACCSET_OTHER);
            LIns* native = downcast_expr(atom, ms->paramTraits(i), env_param);
            lirout->insStore(native, args_out, offset, ACCSET_OTHER);
        } else if (copyArgs()) {
            LIns* atom = ldp(args_param, i*sizeof(Atom), ACCSET_OTHER);
            lirout->insStore(atom, args_out, offset, ACCSET_OTHER);
        }
    }

    void InvokerCompiler::downcast_args(LIns* env_param, LIns* argc_param, LIns* args_param)
    {
        // the receiver arg (arg0) only needs to be unboxed, not coerced
        verbose_only( if (verbose())
            core->console << "unbox arg 0 " << ms->paramTraits(0) << "\n";
        )
        LIns* atom = ldp(args_param, 0, ACCSET_OTHER);
        LIns* native = atomToNative(ms->paramTraitsBT(0), atom);
        if (native != atom || copyArgs())
            lirout->insStore(native, args_out, 0, ACCSET_OTHER);
        int offset = argSize(ms, 0);

        // the required args need to be coerced and unboxed
        int i;
        int required_count = ms->requiredParamCount();
        for (i = 1; i <= required_count; i++) {
            verbose_only( if (verbose())
                core->console << "arg " << i << " " << ms->paramTraits(i) << "\n";
            )
            downcast_arg(i, offset, env_param, args_param);
            offset += argSize(ms, i);
        }

        // optional args also need coercing and unboxing when they're present
        int param_count = ms->param_count();
        if (required_count < param_count) {
            int optional_count = param_count - required_count;
            int branch_count = 0;
            LIns** branches = new (*alloc1) LIns*[optional_count];
            for (; i <= param_count; i++) {
                verbose_only( if (verbose())
                    core->console << "optional arg " << i << " " << ms->paramTraits(i) << "\n";
                )
                // if (argc < i) { goto done }
                branches[branch_count++] = jlti(argc_param, i);
                downcast_arg(i, offset, env_param, args_param);
                offset += argSize(ms, i);
            }
            if (branch_count > 0) {
                // done: patch all the optional-arg branches
                LIns* done_label = label();
                for (i = 0; i < branch_count; i++)
                    branches[i]->setTarget(done_label);
            }
        }
    }

    void* InvokerCompiler::assemble()
    {
        CodeMgr* codeMgr = method->pool()->codeMgr;

        verbose_only(if (pool->isVerbose(LC_Liveness)) {
            Allocator live_alloc;
            LirReader in(frag->lastIns);
            nanojit::live(&in, live_alloc, frag, &codeMgr->log);
        })

        // disable hardening features when compiling thunks
        nanojit::Config cfg = core->config.njconfig;
        cfg.harden_function_alignment = false;
        cfg.harden_nop_insertion = false;

        Assembler *assm = new (*lir_alloc) Assembler(codeMgr->codeAlloc, codeMgr->allocator, *lir_alloc,
            &codeMgr->log, cfg);
        verbose_only( StringList asmOutput(*lir_alloc); )
        verbose_only( if (!pool->isVerbose(VB_raw)) assm->_outputCache = &asmOutput; )
        LirReader bufreader(frag->lastIns);
        assm->beginAssembly(frag);
        assm->assemble(frag, &bufreader);
        assm->endAssembly(frag);

        verbose_only(
            assm->_outputCache = 0;
            for (Seq<char*>* p = asmOutput.get(); p != NULL; p = p->tail)
                assm->outputf("%s", p->head);
        );
        if (!assm->error()) {
            if (method->isNative()) {
                PERFM_NVPROF("C++ invoker bytes", CodeAlloc::size(assm->codeList));
            } else {
                PERFM_NVPROF("JIT invoker bytes", CodeAlloc::size(assm->codeList));
            }
            return frag->code();
        } else {
            return NULL;
        }
    }

    void InvokerCompiler::call_method(LIns* env_param, LIns* argc_param)
    {
        // We know we've called the method at least once, so method->implGPR pointer is correct.
        CallInfo* call = (CallInfo*) lir_alloc->alloc(sizeof(CallInfo));
        call->_isPure = 0;
        call->_storeAccSet = ACCSET_STORE_ANY;
        call->_abi = ABI_FUNCTION;
        verbose_only( if (verbose()) {
            StUTF8String name(method->getMethodName());
            char *namestr = new (*lir_alloc) char[VMPI_strlen(name.c_str())+1];
            VMPI_strcpy(namestr, name.c_str());
            call->_name = namestr;
        })
        switch (ms->returnTraitsBT()) {
        case BUILTIN_number:
            call->_address = (uintptr_t) method->_implFPR;
            call->_typesig = SIG3(F,P,I,P);
            break;
        case BUILTIN_int: case BUILTIN_uint: case BUILTIN_boolean:
            call->_address = (uintptr_t) method->_implGPR;
            call->_typesig = SIG3(I,P,I,P);
            break;
        default:
            call->_address = (uintptr_t) method->_implGPR;
            call->_typesig = SIG3(A,P,I,P);
            break;
        }
        LIns* result = callIns(call, 3, env_param, argc_param, args_out);
        livep(args_out);
        // box and return the result
        retp(nativeToAtom(result, ms->returnTraits()));
    }

    LIns* InvokerCompiler::downcast_expr(LIns* atom, Traits* t, LIns* env)
    {
        switch (bt(t)) {
        case BUILTIN_object:
            // return (atom == undefinedAtom) ? nullObjectAtom : atom;
            return choose(eqp(atom, undefinedAtom), nullObjectAtom, atom);
        case BUILTIN_int:
            return i2p(callIns(FUNCTIONID(integer), 1, atom));
        case BUILTIN_uint:
            return ui2p(callIns(FUNCTIONID(toUInt32), 1, atom));
        case BUILTIN_number:
            return callIns(FUNCTIONID(number), 1, atom);
        case BUILTIN_boolean:
            return ui2p(callIns(FUNCTIONID(boolean), 1, atom));
        case BUILTIN_string:
            return callIns(FUNCTIONID(coerce_s), 2, InsConstPtr(t->core), atom);
        case BUILTIN_namespace:
            return andp(callIns(FUNCTIONID(coerce), 3, env, atom, InsConstPtr(t)), ~7);
        case BUILTIN_void:
        case BUILTIN_null:
        case BUILTIN_any:
            AvmAssert(false);
        default:
            return downcast_obj(atom, env, t);
        }
    }

#ifdef NJ_VERBOSE
    bool InvokerCompiler::verbose()
    {
        return method->pool()->isVerbose(VB_jit);
    }
#endif
}

#endif // VMCFG_NANOJIT

