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

#include "hm-main.h"
#ifdef VMCFG_HALFMOON

#include "profiler/profiler-main.h"

namespace halfmoon {
  using avmplus::CodeMgr;
  using avmplus::DomainMgr;
  using avmplus::ScopeTypeChain;
  using profiler::MethodProfile;
  using profiler::MethodProfileMgr;

JitManager::JitManager(Allocator& mgr_alloc, PoolObject* pool)
  : mgr_alloc_(mgr_alloc)
  , mgr_alloc0_(mgr_alloc)
  , lattice_(pool->core, mgr_alloc)
  , infos_(mgr_alloc)
  , method_count_(pool->methodCount())
  , methods_(new (mgr_alloc0_) MethodData*[pool->methodCount()])
  , profile_mgr_(new (mgr_alloc) MethodProfileMgr(mgr_alloc)) {
}

JitManager* JitManager::init(PoolObject* pool) {
  CodeMgr* mgr = initCodeMgr(pool);
  JitManager* j2 = mgr->jit_mgr;
  if (!j2) {
    Allocator& mgr_alloc = mgr->allocator;
    mgr->jit_mgr = j2 = new (mgr_alloc) JitManager(mgr_alloc, pool);
  }
  return j2;
}

const InterpreterData& JitManager::interpreter(MethodEnv* env) {
  JitManager* j2 = env->method->pool()->codeMgr->jit_mgr;
  return *j2->methods_[env->method->method_id()]->interp_data;
}

void JitManager::set_interp(MethodInfo* method, InstrGraph* ir) {
  MethodData* data = ensureMethodData(method);
  data->interp_data = new (mgr_alloc_) InterpreterData(mgr_alloc_, ir);
}

void JitManager::set_lir(MethodInfo* method, InstrGraph* ir, 
                        ProfiledInformation* profiled_info) {
  MethodData* data = ensureMethodData(method);

  Context cxt(method);
  //TODO: Pass both results via pointers for consistency.
  data->code = LirEmitter(&cxt, ir, profiled_info).emit(&data->deopt_data);
}

void JitManager::set_ir(MethodInfo* method, InstrGraph* ir) {
  ensureMethodData(method)->ir = ir;
}

InstrGraph* JitManager::ir(MethodInfo* method) {
  return ensureMethodData(method)->ir;
}

GprMethodProc JitManager::getImpl(MethodInfo* method) {
  int method_id = method->method_id();
  if (haveCode(method_id))
    return methods_[method_id]->code;
  if (haveInterp(method_id))
    switch (method->getMethodSignature()->returnTraitsBT()) {
      case BUILTIN_number:  return (GprMethodProc)Interpreter::fprStub;
      case BUILTIN_int:     return Interpreter::intStub;
      case BUILTIN_uint:
      case BUILTIN_boolean: return Interpreter::uintStub;
      default: return Interpreter::gprStub;
    }
  return 0;
}

// Allocate a new MethodData object.
JitManager::MethodData* JitManager::ensureMethodData(MethodInfo* method) {
  assert(checkMethodId(method->method_id()));
  int method_id = method->method_id();
  MethodData* method_data = methods_[method_id];
  if (!method_data) {
    MethodSignaturep method_signature = method->getMethodSignature();
    int scope_base = method_signature->scope_base();
    int operand_base = method_signature->stack_base();

    BailoutData* meta_data = new (mgr_alloc_)
                               BailoutData(mgr_alloc_, method,
                               scope_base - 1, operand_base - 1);
    methods_[method_id] = method_data = new (mgr_alloc_) MethodData(meta_data);
  }

  return method_data;
}

MethodProfile* JitManager::getProfile(MethodInfo* info) {
  CodeMgr* mgr = info->pool()->codeMgr;
  if (!mgr || !mgr->jit_mgr)
    return 0;
  return mgr->jit_mgr->profile_mgr()->getMethodProfile(info);
}

} // end namespace halfmoon
#endif // VMCFG_HALFMOON
