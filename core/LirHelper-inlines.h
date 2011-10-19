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

namespace avmplus {

using namespace nanojit;

REALLY_INLINE BuiltinType LirHelper::bt(Traits *t)
{
    return Traits::getBuiltinType(t);
}

REALLY_INLINE LIns* LirHelper::InsConst(int32_t c)
{
    return lirout->insImmI(c);
}

REALLY_INLINE LIns* LirHelper::InsConstPtr(const void *p)
{
    return lirout->insImmP(p);
}

REALLY_INLINE LIns* LirHelper::InsConstAtom(Atom c)
{
    return lirout->insImmP((void*)c);
}

REALLY_INLINE LIns* LirHelper::i2p(LIns *i)
{
    return lirout->insI2P(i);
}

REALLY_INLINE LIns* LirHelper::ui2p(LIns *i)
{
    return lirout->insUI2P(i);
}

REALLY_INLINE LIns* LirHelper::p2i(LIns *i)
{
#ifdef NANOJIT_64BIT
    return lirout->ins1(LIR_q2i, i);
#else
    return i;
#endif
}

REALLY_INLINE LIns* LirHelper::p2dIns(LIns* v)
{
#ifdef NANOJIT_64BIT
    // Not yet implemented on 64-bit platforms.
    (void)v;
    AvmAssert(false);
    return NULL;
#else
    return lirout->ins1(LIR_i2d, v);
#endif
}


#if NJ_SOFTFLOAT_SUPPORTED
REALLY_INLINE LIns* LirHelper::qlo(LIns* q)
{
    return lirout->ins1(LIR_dlo2i, q);
}
#endif

REALLY_INLINE LIns* LirHelper::eqp0(LIns* ptr)
{
    return lirout->insEqP_0(ptr);
}

REALLY_INLINE LIns* LirHelper::eqi0(LIns* ptr)
{
    return lirout->insEqI_0(ptr);
}

REALLY_INLINE LIns* LirHelper::eqp(LIns* a, Atom b)
{
    return eqp(a, InsConstAtom(b));
}

REALLY_INLINE LIns* LirHelper::eqp(LIns* a, LIns* b)
{
    return lirout->ins2(LIR_eqp, a, b);
}

REALLY_INLINE LIns* LirHelper::ltup(LIns* a, LIns* b)
{
    return lirout->ins2(LIR_ltup, a, b);
}

REALLY_INLINE LIns* LirHelper::choose(LIns* cond, Atom t, LIns* f)
{
    return lirout->insChoose(cond, InsConstAtom(t), f, use_cmov);
}

REALLY_INLINE LIns* LirHelper::addp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_addp, a, InsConstAtom(mask));
}

REALLY_INLINE LIns* LirHelper::andp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_andp, a, InsConstAtom(mask));
}

REALLY_INLINE LIns* LirHelper::orp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_orp, a, InsConstAtom(mask));
}

REALLY_INLINE LIns* LirHelper::addi(LIns* a, int32_t mask)
{
    return lirout->ins2(LIR_addi, a, InsConst(mask));
}

REALLY_INLINE LIns* LirHelper::ori(LIns* a, int32_t mask)
{
    return lirout->ins2(LIR_ori, a, InsConst(mask));
}

REALLY_INLINE LIns* LirHelper::xorp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_xorp, a, InsConstAtom(mask));
}

REALLY_INLINE LIns* LirHelper::subp(LIns* a, int32_t offset)
{
    return lirout->ins2(LIR_subp, a, InsConstAtom(offset));
}

REALLY_INLINE LIns* LirHelper::retp(LIns* a)
{
    return lirout->ins1(LIR_retp, a);
}

REALLY_INLINE LIns* LirHelper::label()
{
    return lirout->ins0(LIR_label);
}

REALLY_INLINE LIns* LirHelper::jlti(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jt, lirout->ins2(LIR_lti, a, InsConst(b)), NULL);
}

REALLY_INLINE LIns* LirHelper::jgti(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jt, lirout->ins2(LIR_gti, a, InsConst(b)), NULL);
}

REALLY_INLINE LIns* LirHelper::jnei(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jf, lirout->ins2(LIR_eqi, a, InsConst(b)), NULL);
}

REALLY_INLINE LIns* LirHelper::stp(LIns* val, LIns* p, int32_t d, AccSet accSet)
{
    AvmAssert(val->isP());
    return lirout->insStore(LIR_stp, val, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::sti(LIns* val, LIns* p, int32_t d, AccSet accSet)
{
    AvmAssert(val->isI());
    return lirout->insStore(LIR_sti, val, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::std(LIns* val, LIns* p, int32_t d, AccSet accSet)
{
    AvmAssert(val->isD());
    return lirout->insStore(LIR_std, val, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::ldi(LIns* p, int32_t d, AccSet accSet)
{
    return lirout->insLoad(LIR_ldi, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::ldd(LIns* p, int32_t d, AccSet accSet)
{
    return lirout->insLoad(LIR_ldd, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::ldp(LIns* p, int32_t d, AccSet accSet)
{
    return lirout->insLoad(LIR_ldp, p, d, accSet);
}

REALLY_INLINE LIns* LirHelper::livep(LIns* a)
{
    return lirout->ins1(LIR_livep, a);
}

REALLY_INLINE LIns* LirHelper::param(int id, const char *name)
{
    LIns* param = lirout->insParam(id, 0);
#ifdef NJ_VERBOSE
    if (frag->lirbuf->printer)
        frag->lirbuf->printer->lirNameMap->addName(param, name);
#else
    (void)name;
#endif
    return param;
}

REALLY_INLINE LIns* LirHelper::lshi(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_lshi, a, InsConst(b));
}

REALLY_INLINE LIns* LirHelper::rshi(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_rshi, a, InsConst(b));
}

REALLY_INLINE LIns* LirHelper::lshp(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_lshp, a, InsConst(b));
}

REALLY_INLINE LIns* LirHelper::rshp(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_rshp, a, InsConst(b));
}

REALLY_INLINE LIns* LirHelper::rshup(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_rshup, a, InsConst(b));
}

/**
 * Returns true if mask has exactly one bit set
 * see http://aggregate.org/MAGIC/#Is%20Power%20of%202
 */
REALLY_INLINE bool exactlyOneBit(uint32_t m)
{
    AvmAssert(m != 0);
    return (m & (m-1)) == 0;
}


} // namespace
