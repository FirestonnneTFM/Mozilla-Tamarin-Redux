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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

#include "avmplus.h"

namespace avmplus {

// Called after ABC is loaded before anything else happens.  We have a
// chance here to kick off eager verification.
void BaseExecMgr::notifyAbcPrepared(Toplevel* toplevel, AbcEnv* abcEnv)
{
#ifdef VMCFG_VERIFYALL
    if (config.verifyall) {
        PoolObject* pool = abcEnv->pool();
        for (int i=0, n=pool->scriptCount(); i < n; i++)
            enqTraits(pool->getScriptTraits(i));
        verifyEarly(toplevel, abcEnv);
    }
#endif
    (void) toplevel;
    (void) abcEnv;
}

#ifdef VMCFG_VERIFYALL
VerifyallWriter::VerifyallWriter(MethodInfo* m, BaseExecMgr* exec, CodeWriter *coder)
    : NullWriter(coder)
    , pool(m->pool())
    , exec(exec)
{}

void VerifyallWriter::write(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, Traits *type)
{
    if (opcode == OP_newactivation)
        exec->enqTraits(type);
    coder->write(state, pc, opcode, type);
}

void VerifyallWriter::writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, Traits *type)
{
    if (opcode == OP_newfunction) {
        MethodInfo *f = pool->getMethodInfo(opd1);
        AvmAssert(f->declaringTraits() == type);
        exec->enqFunction(f);
        exec->enqTraits(type);
    }
    else if (opcode == OP_newclass) {
        exec->enqTraits(type);
        exec->enqTraits(type->itraits);
    }
    coder->writeOp1(state, pc, opcode, opd1, type);
}

// True after a method is verified.
REALLY_INLINE bool BaseExecMgr::isVerified(const MethodInfo* m) const
{
    return (m->_flags & MethodInfo::VERIFIED) != 0;
}

// True when a method is in verifyFunctionQueue, reset to false once verified.
REALLY_INLINE bool BaseExecMgr::isVerifyPending(const MethodInfo* m) const
{
    return (m->_flags & MethodInfo::VERIFY_PENDING) != 0;
}

REALLY_INLINE void BaseExecMgr::setVerified(MethodInfo* m) const
{
    m->_flags = (m->_flags | MethodInfo::VERIFIED) & ~MethodInfo::VERIFY_PENDING;
}

REALLY_INLINE void BaseExecMgr::setVerifyPending(MethodInfo* m) const
{
    m->_flags |= MethodInfo::VERIFY_PENDING;
}

// Add a function to the verify queue if not already queued or verified.
void BaseExecMgr::enqFunction(MethodInfo* f)
{
    if (f != NULL && !isVerified(f) && !isVerifyPending(f)) {
        setVerifyPending(f);
        verifyFunctionQueue.add(f);
    }
}

// Add a Traits to verifyTraitsQueue if not already queued.
void BaseExecMgr::enqTraits(Traits* t)
{
    if (!t->isInterface() && verifyTraitsQueue.indexOf(t) < 0)
        verifyTraitsQueue.add(t);
}

// In verifyonly mode, this invoker is used for all functions, ensuring
// that no code actually runs.
Atom verifyOnlyInvoker(MethodEnv*, int32_t, Atom*)
{
    return undefinedAtom;
}

// After loading an ABC and inserting scripts into the verify queue,
// process the work queues until they are empty.
void BaseExecMgr::verifyEarly(Toplevel* toplevel, AbcEnv* abc_env)
{
    List<MethodInfo*, LIST_GCObjects> verifyQueue2(core->GetGC());
    int verified;
    do {
        verified = 0;
        while (!verifyTraitsQueue.isEmpty()) {
            Traits* t = verifyTraitsQueue.removeFirst();
            t->resolveSignatures(toplevel);
            TraitsBindingsp td = t->getTraitsBindings();
            enqFunction(t->init);
            for (int i=0, n=td->methodCount; i < n; i++)
                enqFunction(td->getMethod(i));
        }
        while (!verifyFunctionQueue.isEmpty()) {
            MethodInfo* f = verifyFunctionQueue.removeLast();
            if (!isVerified(f)) {
                if (f->declaringTraits()->init != f && f->declaringScope() == NULL) {
                    verifyQueue2.add(f);
                    continue;
                }
                verified++;
                //console << "pre verify " << f << "\n";
                verifyMethod(f, toplevel, abc_env);
                setVerified(f);
                if (config.verifyonly)
                    f->_invoker = verifyOnlyInvoker;
            }
        }
        while (!verifyQueue2.isEmpty())
            verifyFunctionQueue.add(verifyQueue2.removeLast());
    } while (verified > 0);
}

#endif // VMCFG_VERIFYALL

} // namespace avmplus

