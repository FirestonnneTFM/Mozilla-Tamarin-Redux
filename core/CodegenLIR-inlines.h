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

REALLY_INLINE LIns* CodegenLIR::loadIns(LOpcode op, int32_t disp, LIns *base, AccSet accSet, LoadQual loadQual)
{
    return lirout->insLoad(op, base, disp, accSet, loadQual);
}

REALLY_INLINE LIns* CodegenLIR::storeIns(LOpcode op, LIns* val, int32_t disp, LIns *base, AccSet accSet)
{
    return lirout->insStore(op, val, base, disp, accSet);
}

REALLY_INLINE LIns* CodegenLIR::Ins(LOpcode op)
{
    return lirout->ins0(op);
}

REALLY_INLINE LIns* CodegenLIR::Ins(LOpcode op, LIns *a)
{
    return lirout->ins1(op, a);
}

REALLY_INLINE LIns* CodegenLIR::i2dIns(LIns* v)
{
    return lirout->ins1(LIR_i2d, v);
}

REALLY_INLINE LIns* CodegenLIR::ui2dIns(LIns* v)
{
    return lirout->ins1(LIR_ui2d, v);
}

REALLY_INLINE LIns* CodegenLIR::binaryIns(LOpcode op, LIns *a, LIns *b)
{
    return lirout->ins2(op,a,b);
}

REALLY_INLINE bool InvokerCompiler::copyArgs()
{
    return args_out->isop(LIR_allocp);
}

// Return true if JIT failure can be predicted from method signature prior to JIT invocation.
// This supports a fast-fail mechanism to avoid blowup of non-linear JIT algorithms on atypical
// methods, e.g., very long or with many variables.

REALLY_INLINE bool CodegenLIR::jitWillFail(const MethodSignaturep ms)
{
    // Assembly cannot succeed if frame is too large for NanoJIT.
    // Large frame sizes can lead to pathological VarTracker behavior -- see bug 601794.
    return ms->frame_size() * 2 > NJ_MAX_STACK_ENTRY;
}

template <class C>
REALLY_INLINE C* CacheBuilder<C>::findCacheSlot(const Multiname* name)
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
REALLY_INLINE C* CacheBuilder<C>::allocateCacheSlot(const Multiname* name)
{
    C* c = findCacheSlot(name);
    if (!c) {
        c = new (codeMgr.allocator) C(name, codeMgr.bindingCaches);
        codeMgr.bindingCaches = c;
        caches.add(c);
    }
    return c;
}

} // namespace
