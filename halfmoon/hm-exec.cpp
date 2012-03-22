/* -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil; tab-width: 2 -*- */
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

//
// This file contains BaseExecMgr changes that belong in core/exec-jit.cpp
// or core/exec.cpp, but they are here to encapsulate them until halfmoon
// is a shipping feature.
//
#include "hm-main.h"
#ifdef VMCFG_HALFMOON
#include "profiler/profiler-main.h"

namespace avmplus {
using halfmoon::JitManager;

bool BaseExecMgr::verifyOptimizeJit(MethodInfo* m, MethodSignaturep ms,
                           Toplevel* toplevel, AbcEnv* abc_env, OSR* /* osr_state */) {
  if (!halfmoon::canCompile(m))
    return false;
  halfmoon::JitWriter jit(m, toplevel, abc_env);
  verifyCommon(m, ms, toplevel, abc_env, &jit);
  GprMethodProc code = jit.finish();
  if (code) {
    setJit(m, code);
    return true;
  }
  return false;
}

void BaseExecMgr::resetMethodInvokers(MethodEnv* env) {
    MethodInfo* method_info = env->method;
    method_info->_implGPR = verifyEnterGPR;
    method_info->_invoker = verifyInvoke;
    env->_implGPR = method_info->_implGPR;

    finish(JitManager::getProfile(method_info));
}

void BaseExecMgr::verifyProfilingJit(MethodInfo* methodInfo,
                                     MethodSignaturep methodSignature,
                                     Toplevel* toplevel, AbcEnv* abc_env) {
    profiler::ProfileLirEmitter jit(methodInfo, methodSignature, toplevel);
    verifyCommon(methodInfo, methodSignature, toplevel, abc_env, &jit);
    GprMethodProc code = jit.emitMD();

    if (code) {
        setJit(methodInfo, code);
    } else if (config.jitordie) {
        AvmAssert(false); // Not sure how to clean up yet
        jit.~ProfileLirEmitter(); // Explicit cleanup since destructor won't run otherwise.
    }
}

/// We finished profiling the method, at the next invocation recompile with halfmoon
/// Still pretty sure we don't have to set all 3 fields to redirect control flow.
/// What's the diff between env->_implGPR and env->method->implGPR and invoker?
/// I can't find a clear distinction
/* static */ void BaseExecMgr::setRecompileWithProfileData(MethodEnv* env)
{
    env->_implGPR = (GprMethodProc) jitInvokerWithProfileData;
    env->method->_implGPR = (GprMethodProc) jitInvokerWithProfileData;
    env->method->_invoker = jitInvokerWithProfileData;
}

/// We found out a method is hot. At the next invocation, recompile with instrumentation
/// I'm pretty sure we don't have to set all 3 fields... but I can't find another way
/* static */ void BaseExecMgr::setRecompileHotMethod(MethodEnv* env)
{
    env->_implGPR = (GprMethodProc)jitInvokerProfiler;
    env->method->_implGPR = (GprMethodProc)jitInvokerProfiler;
    env->method->_invoker = jitInvokerProfiler;
}

/// All the env, env->method, implGPR, invoker stuff is very confusing.
/// JIT compiled code that calls other JIT compiled code looks up the
/// method address at runtime based on the env->implGPR.
/// So we have to overwrite env->implGPR so the correct method is called.
///
/// env->method->implGPR is written with the address of the JIT compiled code during
/// actual compilation. I'm not sure when env->method->implGPR is ever directly loaded
/// but its the same address as env->implGPR. The "this" object must already be unboxed
/// into the appropriate script object
///
/// env->method->invoker is used when the method is not resolved (late bound).
/// This also means that the args are a boxed atom array.
///
/// The profiler never changes whether or not arguments are boxed/unboxed,
/// so never overwrite the invoker.
///
/// Any sound way to test if the this object is already unboxed?
///
/// I think this is the correct order, still slightly unsure / bug testing - Mason
Atom BaseExecMgr::executeMethod(MethodEnv* env, int argc, Atom* args) {
    GprMethodProc address = (GprMethodProc) env->method->_implGPR;
    env->_implGPR = address ;

    MethodInfo* method_info = env->method;
    Atom this_object = atomKind(args[0]);
    if (atomKind(this_object) == kUnusedAtomTag) {
      return env->_implGPR(env, argc, (uint32_t*) args);
    } else {
      return (method_info->_invoker(env, argc, args));
    }
}


/// We detected a hot method. Recompile the method with profiling instrumentation
/* static */
Atom BaseExecMgr::jitInvokerProfiler(MethodEnv* env, int argc, Atom* args)
{
    freeJitCompiledCode(env->method);
    BaseExecMgr *exec = BaseExecMgr::exec(env);
    exec->verifyProfilingJit(env->method, env->method->getMethodSignature(),
                             env->toplevel(), env->abcEnv());
    return executeMethod(env, argc, args);
}


/// We have gathered all the profiling data. Now recompile it with halfmoon
/// and execute the resulting code.
/* static */
Atom BaseExecMgr::jitInvokerWithProfileData(MethodEnv* env, int argc,
                                            Atom* args)
{
    freeJitCompiledCode(env->method);
    BaseExecMgr *exec = BaseExecMgr::exec(env);
    OSR* osr = NULL;
    exec->verifyJit(env->method, env->method->getMethodSignature(),
                    env->toplevel(), env->abcEnv(), osr);
    return executeMethod(env, argc, args);
}

// Free the memory allocated to the jit compiled code. Means we have to
// recompile the method.
// TODO: recursive calls, cannot free memory until we unwind stack.
void BaseExecMgr::freeJitCompiledCode(MethodInfo* method_info) {
    PoolObject* pool = method_info->pool();
    CodeMgr* alloc = pool->codeMgr;
    //alloc->freeCodeMemory(method_info);
    (void) alloc;
}

// Ideally, we would like to provide a MethodInfo* here,
// as this is the handle we'd naturally have available for
// a code cache flush.  Unfortunately, we need the abc_env
// for OSR::isSupported().  It's needed only for a version
// check.  Perhaps we can refactor to avoid this dependence.
// FIXME: this belongs in exec-jit.cpp, but its here to
// keep deoptimizer changes grouped while under development.

void BaseExecMgr::deoptimize(MethodEnv* env)
{
    AvmCore* core = env->core();
    MethodInfo* m = env->method;
    const MethodSignature* ms = m->getMethodSignature();

    AvmAssert(m->_deoptimizer != NULL);

#ifdef AVMPLUS_VERBOSE
        if (env->method->pool()->isVerbose(VB_execpolicy))
            env->core()->console << "execpolicy deoptimize " << m << "\n";
#endif

    m->_deoptimizer->deoptimize(core);

    // release space for code here

    setInterp(m, ms, OSR::isSupported(env->abcEnv(), m, ms));
}

} // namespace avmplus
#endif // VMCFG_HALFMOON
