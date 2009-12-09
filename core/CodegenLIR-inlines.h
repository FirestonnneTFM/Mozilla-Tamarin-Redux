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

#ifdef VTUNE
inline LineNumberRecord* JITCodeInfo::add(MMgc::GC* gc, uintptr_t loc, Stringp file, uint32_t line)
{
    LineNumberRecord* record = new (gc) LineNumberRecord(file,line);
    lineNumTable.put(loc,record);
    return record;
}

inline void JITCodeInfo::clear()
{
    lineNumTable.clear();
    method = 0;
    vtune = 0;
    startAddr = 0;
    endAddr = 0;
}
#endif // VTUNE

inline BuiltinType LirHelper::bt(Traits *t)
{
    return Traits::getBuiltinType(t);
}

inline LIns* CodegenLIR::loadIns(LOpcode op, size_t disp, LIns *base)
{
    AvmAssert(isS32(disp));
    return lirout->insLoad(op, base, (int32_t)disp);
}

inline LIns* CodegenLIR::Ins(LOpcode op)
{
    return lirout->ins0(op);
}

inline LIns* CodegenLIR::Ins(LOpcode op, LIns *a)
{
    return lirout->ins1(op, a);
}

inline LIns* CodegenLIR::i2dIns(LIns* v)
{
    return lirout->ins1(LIR_i2f, v);
}

inline LIns* CodegenLIR::u2dIns(LIns* v)
{
    return lirout->ins1(LIR_u2f, v);
}

inline LIns* CodegenLIR::binaryIns(LOpcode op, LIns *a, LIns *b)
{
    return lirout->ins2(op,a,b);
}

inline LIns* LirHelper::InsConst(int32_t c)
{
    return lirout->insImm(c);
}

inline LIns* LirHelper::InsConstPtr(const void *p)
{
    return lirout->insImmPtr(p);
}

inline LIns* LirHelper::InsConstAtom(Atom c)
{
    return lirout->insImmPtr((void*)c);
}

inline LIns* LirHelper::i2p(LIns *i)
{
    return lirout->ins_i2p(i);
}

inline LIns* LirHelper::u2p(LIns *i)
{
    return lirout->ins_u2p(i);
}

inline LIns* LirHelper::p2i(LIns *i)
{
#ifdef NANOJIT_64BIT
    return lirout->ins1(LIR_qlo, i);
#else
    return i;
#endif
}

inline LIns* LirHelper::qlo(LIns* q)
{
    return lirout->ins1(LIR_qlo, q);
}

inline LIns* LirHelper::peq0(LIns* ptr)
{
    return lirout->ins_peq0(ptr);
}

inline LIns* LirHelper::eq0(LIns* ptr)
{
    return lirout->ins_eq0(ptr);
}

inline LIns* LirHelper::peq(LIns* a, Atom b)
{
    return lirout->ins2(LIR_peq, a, InsConstAtom(b));
}

inline LIns* LirHelper::choose(LIns* cond, Atom t, LIns* f)
{
    return lirout->ins_choose(cond, InsConstAtom(t), f, true/*use_cmov*/);
}

inline LIns* LirHelper::andp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_piand, a, InsConstAtom(mask));
}

inline LIns* LirHelper::orp(LIns* a, Atom mask)
{
    return lirout->ins2(LIR_pior, a, InsConstAtom(mask));
}

inline LIns* LirHelper::ori(LIns* a, int32_t mask)
{
    return lirout->ins2(LIR_or, a, InsConst(mask));
}

inline LIns* LirHelper::ret(LIns* a)
{
    return lirout->ins1(LIR_ret, a);
}

inline LIns* LirHelper::label()
{
    return lirout->ins0(LIR_label);
}

inline LIns* LirHelper::jlt(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jt, lirout->ins2(LIR_lt, a, InsConst(b)), NULL);
}

inline LIns* LirHelper::jgt(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jt, lirout->ins2(LIR_gt, a, InsConst(b)), NULL);
}

inline LIns* LirHelper::jne(LIns *a, int32_t b)
{
    return lirout->insBranch(LIR_jf, lirout->ins2(LIR_eq, a, InsConst(b)), NULL);
}

inline LIns* LirHelper::stp(LIns* val, LIns* p, int32_t d)
{
    AvmAssert(val->isPtr());
    return lirout->insStorei(val, p, d);
}

inline LIns* LirHelper::sti(LIns* val, LIns* p, int32_t d)
{
    AvmAssert(!val->isQuad());
    return lirout->insStorei(val, p, d);
}

inline LIns* LirHelper::stq(LIns* val, LIns* p, int32_t d)
{
    AvmAssert(val->isQuad());
    return lirout->insStorei(val, p, d);
}

inline LIns* LirHelper::ldp(LIns* p, int32_t d)
{
    return lirout->insLoad(LIR_ldp, p, d);
}

inline LIns* LirHelper::live(LIns* a)
{
    return lirout->ins1(LIR_live, a);
}

inline LIns* LirHelper::param(int id, const char *name)
{
    LIns* param = lirout->insParam(id, 0);
#ifdef NJ_VERBOSE
    if (frag->lirbuf->names)
        frag->lirbuf->names->addName(param, name);
#else
    (void)name;
#endif
    return param;
}

inline LIns* LirHelper::lshi(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_lsh, a, InsConst(b));
}

inline LIns* LirHelper::ushp(LIns* a, int32_t b)
{
    return lirout->ins2(LIR_pursh, a, InsConst(b));
}

} // namespace
