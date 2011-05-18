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

#include "LirHelper.h"

namespace avmplus
{

bool neverReturns(const CallInfo* call)
{
    return call == FUNCTIONID(throwAtom) ||
        call == FUNCTIONID(npe) ||
        call == FUNCTIONID(upe) ||
        call == FUNCTIONID(mop_rangeCheckFailed) ||
        call == FUNCTIONID(handleInterruptMethodEnv);
}

CodeMgr* initCodeMgr(PoolObject *pool)
{
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

LirHelper::LirHelper(PoolObject* pool) :
    pool(pool),
    core(pool->core),
    alloc1(mmfx_new(Allocator())),
    lir_alloc(mmfx_new(Allocator())),
#ifdef NANOJIT_IA32
    use_cmov(pool->core->config.njconfig.i386_use_cmov)
#else
    use_cmov(true)
#endif
{ }

LirHelper::~LirHelper()
{
    cleanup();
}

void LirHelper::cleanup()
{
    mmfx_delete( alloc1 );
    alloc1 = NULL;
    mmfx_delete( lir_alloc );
    lir_alloc = NULL;
}

// call
LIns* LirHelper::callIns(const CallInfo *ci, uint32_t argc, ...)
{
    va_list ap;
    va_start(ap, argc);
    LIns* ins = vcallIns(ci, argc, ap);
    va_end(ap);
    return ins;
}

LIns* LirHelper::vcallIns(const CallInfo *ci, uint32_t argc, va_list ap)
{
    AvmAssert(argc <= MAXARGS);
    AvmAssert(argc == ci->count_args());
    LIns* argIns[MAXARGS];
    for (uint32_t i=0; i < argc; i++)
        argIns[argc-i-1] = va_arg(ap, LIns*);
    LIns* ins = lirout->insCall(ci, argIns);

    // for non-returning functions ensure that we signify this fact
    // by terminating control-flow with a ret.
    if (neverReturns(ci))
        lirout->ins1(LIR_retp, InsConstPtr(0));
    return ins;
}

LIns* LirHelper::nativeToAtom(LIns* native, Traits* t)
{
    switch (bt(t)) {
    case BUILTIN_number:
        SSE2_ONLY(if(core->config.njconfig.i386_sse2) {
            return callIns(FUNCTIONID(doubleToAtom_sse2), 2, coreAddr, native);
        })

        return callIns(FUNCTIONID(doubleToAtom), 2, coreAddr, native);

    case BUILTIN_any:
    case BUILTIN_object:
    case BUILTIN_void:
        return native;  // value already represented as Atom

    case BUILTIN_int:
        if (native->isImmI()) {
            int32_t val = native->immI();
            if (atomIsValidIntptrValue(val))
                return InsConstAtom(atomFromIntptrValue(val));
        }
        return callIns(FUNCTIONID(intToAtom), 2, coreAddr, native);

    case BUILTIN_uint:
        if (native->isImmI()) {
            uint32_t val = native->immI();
            if (atomIsValidIntptrValue_u(val))
                return InsConstAtom(atomFromIntptrValue_u(val));
        }
        return callIns(FUNCTIONID(uintToAtom), 2, coreAddr, native);

    case BUILTIN_boolean:
        return ui2p(addi(lshi(native, 3), kBooleanType));

    case BUILTIN_string:
        return addp(native, kStringType);

    case BUILTIN_namespace:
        return addp(native, kNamespaceType);

    default:
        return addp(native, kObjectType);
    }
}

LIns* LirHelper::atomToNative(BuiltinType bt, LIns* atom)
{
    switch (bt)
    {
    case BUILTIN_any:
    case BUILTIN_object:
    case BUILTIN_void:
        return atom;

    case BUILTIN_number:
        if (atom->isImmP())
            return lirout->insImmD(AvmCore::number_d((Atom)atom->immP()));
        else
            return callIns(FUNCTIONID(number_d), 1, atom);

    case BUILTIN_int:
        if (atom->isImmP())
            return InsConst(AvmCore::integer_i((Atom)atom->immP()));
        else
            return callIns(FUNCTIONID(integer_i), 1, atom);

    case BUILTIN_uint:
        if (atom->isImmP())
            return InsConst(AvmCore::integer_u((Atom)atom->immP()));
        else
            return callIns(FUNCTIONID(integer_u), 1, atom);

    case BUILTIN_boolean:
        if (atom->isImmI())
            return InsConst((int32_t)atomGetBoolean((Atom)atom->immP()));
        else
            return p2i(rshup(atom, 3));

    default:
        // pointer type
        if (atom->isImmP())
            return InsConstPtr(atomPtr((Atom)atom->immP()));
        else
            return andp(atom, ~7);
    }

#ifdef __GNUC__
    return 0;// satisfy GCC, although we should never get here
#endif
}

void LirHelper::emitStart(Allocator& alloc, LirBuffer *lirbuf, LirWriter* &lirout) {
    (void)alloc; (void)lirbuf;
    debug_only(
        // catch problems before they hit the writer pipeline
        lirout = validate1 = new (alloc) ValidateWriter(lirout, lirbuf->printer, "emitStart");
    )
    lirout->ins0(LIR_start);

    // create params for saved regs -- processor specific
    for (int i=0; i < NumSavedRegs; i++) {
        LIns *p = lirout->insParam(i, 1); (void) p;
        verbose_only(if (lirbuf->printer)
            lirbuf->printer->lirNameMap->addName(p,
                regNames[REGNUM(Assembler::savedRegs[i])]);)
    }
}

void LirHelper::liveAlloc(LIns* alloc)
{
    if (alloc->isop(LIR_allocp))
        livep(alloc);
}

LIns* LirHelper::stForTraits(Traits *t, LIns* val, LIns* p, int32_t d, AccSet accSet)
{
    switch (bt(t)) {
        case BUILTIN_number:
            return std(val, p, d, accSet);
        case BUILTIN_int:
        case BUILTIN_uint:
        case BUILTIN_boolean:
            return sti(val, p, d, accSet);
        default:
            return stp(val, p, d, accSet);
    }
}

LIns* LirHelper::ldForTraits(Traits *t, LIns* p, int32_t d, AccSet accSet)
{
    switch (bt(t)) {
        case BUILTIN_number:
            return ldd(p, d, accSet);
        case BUILTIN_int:
        case BUILTIN_uint:
        case BUILTIN_boolean:
            return ldi(p, d, accSet);
        default:
            return ldp(p, d, accSet);
    }
}

// check valid pointer and unbox it (returns ScriptObject*)
LIns* LirHelper::downcast_obj(LIns* atom, LIns* env, Traits* t)
{
    callIns(FUNCTIONID(coerceobj_atom), 3, env, atom, InsConstPtr(t));
    return andp(atom, ~7);
}

int32_t LirHelper::argSize(MethodSignaturep ms, int i)
{
    return avmplus::argSize(ms->paramTraits(i));
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

}

//
// The following methods implement Service Provider API's defined in
// nanojit, which must be implemented by the nanojit embedder.
//
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
    // Note this method should only be called during debug builds.
    bool CodeAlloc::checkChunkMark(void* addr, size_t nbytes, bool isExec) {
        bool b = true;

        // iterate over each page checking permission bits
        size_t psize = VMPI_getVMPageSize();
        uintptr_t last = alignTo((uintptr_t)addr + nbytes-1, psize);
        uintptr_t start = (uintptr_t)addr;
        for( uintptr_t n=start; b && n<=last; n += psize) {
#ifdef AVMPLUS_WIN32
            /* windows */
            MEMORY_BASIC_INFORMATION buf;
            VMPI_memset(&buf, 0, sizeof(MEMORY_BASIC_INFORMATION));
            SIZE_T sz = VirtualQuery((LPCVOID)n, &buf, sizeof(buf));
            NanoAssert(sz > 0);
            b = isExec ? buf.Protect == PAGE_EXECUTE_READ
                       : buf.Protect == PAGE_READWRITE;
            NanoAssert(b);
#elif defined(__MACH30__)
            /* mach / osx */
            vm_address_t vmaddr = (vm_address_t)addr;
            vm_size_t vmsize = psize;
            vm_region_basic_info_data_64_t inf;
            mach_msg_type_number_t infoCnt = sizeof(vm_region_basic_info_data_64_t);
            mach_port_t port;
            VMPI_memset(&inf, 0, infoCnt);
            kern_return_t err = vm_region_64(mach_task_self(), &vmaddr, &vmsize, VM_REGION_BASIC_INFO_64, (vm_region_info_t)&inf, &infoCnt, &port);
            NanoAssert(err == KERN_SUCCESS);
            b = isExec ? inf.protection == (VM_PROT_READ | VM_PROT_EXECUTE)
                       : inf.protection == (VM_PROT_READ | VM_PROT_WRITE);
            NanoAssert(b);
#else
            (void)psize;
            (void)last;
            (void)start;
            (void)n;
            (void)isExec;
#endif
        }
        return b;
    }

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


#endif // VMCFG_NANOJIT

