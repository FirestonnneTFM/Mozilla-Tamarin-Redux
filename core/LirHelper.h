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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

#ifndef __avmplus_LirHelper__
#define __avmplus_LirHelper__

using namespace MMgc;
#include "../nanojit/nanojit.h"

#ifdef DEBUGGER
#define DEBUGGER_ONLY(...) __VA_ARGS__
#else
#define DEBUGGER_ONLY(...)
#endif

#ifdef VMCFG_SSE2
# define SSE2_ONLY(...) __VA_ARGS__
#else
# define SSE2_ONLY(...)
#endif

/** Wrapper macro to generate the name of a CallInfo structure */
#define FUNCTIONID(n) &ci_##n

namespace avmplus
{
    using namespace nanojit;

    /** helper code to make LIR generation nice and tidy */
    class LirHelper {
    protected:
        LirHelper(PoolObject*);
        ~LirHelper();
        void cleanup();

    protected:
        LIns* downcast_obj(LIns* atom, LIns* env, Traits* t); // atom -> typed scriptobj
        static BuiltinType bt(Traits *t);
        LIns* nativeToAtom(LIns* value, Traits* valType);
        LIns* atomToNative(BuiltinType, LIns* i);
        LIns* eqi0(LIns* i);             // eq(i, imm(0))
        LIns* eqp0(LIns* ptr);          // peq(ptr, immq(0))
        LIns* qlo(LIns* q);             // LIR_dlo2i(q)
        LIns* i2p(LIns* i);             // 32bit: nop, 64bit: l2q(i)
        LIns* ui2p(LIns* u);             // 32bit: nop, 64bit: ul2uq(i)
        LIns* p2i(LIns* ptr);           // 32bit: nop, 64bit: q2l(ptr)
        LIns* InsConst(int32_t c);
        LIns* InsConstPtr(const void *p);
        LIns* InsConstAtom(Atom c);
        LIns* callIns(const CallInfo *, uint32_t argc, ...);
        LIns* vcallIns(const CallInfo *, uint32_t argc, va_list args);
        LIns* eqp(LIns* a, Atom b);
        LIns* eqp(LIns* a, LIns* b);
        LIns* ltup(LIns* a, LIns* b);
        LIns* choose(LIns* c, Atom t, LIns* f);
        LIns* addp(LIns* a, Atom imm);
        LIns* addi(LIns* a, int32_t imm);
        LIns* andp(LIns* a, Atom mask);
        LIns* orp(LIns* a, Atom mask);
        LIns* ori(LIns* a, int32_t mask);
        LIns* xorp(LIns* a, Atom mask);
        LIns* subp(LIns* a, int32_t offset);
        LIns* retp(LIns* a);
        LIns* label();
        LIns* jlti(LIns* a, int32_t b);
        LIns* jgti(LIns* a, int32_t b);
        LIns* jnei(LIns* a, int32_t b);
        LIns* sti(LIns* val, LIns* p, int32_t d, AccSet);
        LIns* stp(LIns* val, LIns* p, int32_t d, AccSet);
        LIns* std(LIns* val, LIns* p, int32_t d, AccSet);
        LIns* stForTraits(Traits *t, LIns* val, LIns* p, int32_t d, AccSet);
        LIns* ldi(LIns* p, int32_t d, AccSet);
        LIns* ldd(LIns* p, int32_t d, AccSet);
        LIns* ldp(LIns* p, int32_t d, AccSet);
        LIns* ldForTraits(Traits *t, LIns* p, int32_t d, AccSet);
        LIns* livep(LIns*);
        LIns* param(int n, const char *name);
        LIns* lshi(LIns* a, int32_t b);
        LIns* rshi(LIns* a, int32_t b);
        LIns* lshp(LIns* a, int32_t b);
        LIns* rshp(LIns* a, int32_t b);
        LIns* rshup(LIns* a, int32_t b);
        void  liveAlloc(LIns* expr);        // extend lifetime of LIR_allocp, otherwise no-op
        void  emitStart(Allocator&, LirBuffer*, LirWriter*&);

        /**
         * Compute number of bytes needed for the unboxed representation
         * of this argument value when passed on the stack.
         */
        static int32_t argSize(MethodSignaturep, int32_t i);

    protected: // data
        LirWriter *lirout;
        Fragment *frag;
        PoolObject* pool;
        AvmCore *core;
        LIns *coreAddr;
        Allocator* alloc1;    // allocator used in first pass, while writing LIR
        Allocator* lir_alloc; // allocator with LIR buffer lifetime
        bool const use_cmov;
        debug_only(ValidateWriter* validate1;)
        debug_only(ValidateWriter* validate2;)
    };

    /** Returns true for functions that never return. */
    bool neverReturns(const CallInfo* call);

    // Forward declarations for CallInfos of shared helper functions.
    extern const CallInfo ci_doubleToAtom;
    extern const CallInfo ci_intToAtom;
    extern const CallInfo ci_uintToAtom;
    extern const CallInfo ci_number_d;
    extern const CallInfo ci_integer_i;
    extern const CallInfo ci_integer_u;
    extern const CallInfo ci_throwAtom;
    extern const CallInfo ci_npe;
    extern const CallInfo ci_upe;
    extern const CallInfo ci_mop_rangeCheckFailed;
    extern const CallInfo ci_handleInterruptMethodEnv;
    extern const CallInfo ci_coerceobj_atom;

#ifdef VMCFG_SSE2
    extern const CallInfo ci_doubleToAtom_sse2;
#endif

    const ArgType ARGTYPE_U = ARGTYPE_UI; // uint32_t
    const ArgType ARGTYPE_F = ARGTYPE_D;  // double
    const ArgType ARGTYPE_A = ARGTYPE_P;  // Atom

}

#include "LirHelper-inlines.h"

#endif /* __avmplus_LirHelper__ */
