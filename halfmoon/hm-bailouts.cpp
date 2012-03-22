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
 * Portions created by the Initial Developer are Copyright (C) 2008
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

namespace halfmoon {
  BailoutData::BailoutData(Allocator& alloc, MethodInfo* method, 
    int scope_base, int stack_base) 
    : alloc_(alloc) 
    , method_info_(method)
    , state_map_(alloc)
    , scope_base_(scope_base)
    , stack_base_(stack_base)
  {
    MethodSignaturep method_signature = method->getMethodSignature();
    frame_size_ = method_signature->frame_size();
    init();
  }

  BailoutData::~BailoutData() {
  }

  void BailoutData::setNativeType(int local_index, SlotStorageType sst_type) {
    current_state_->local_types[local_index] = sst_type;
  }

  void BailoutData::do_safepoint(int abc_pc, int abc_scope_ptr, 
      int abc_stack_ptr) {
    current_state_->scope_ptr = abc_scope_ptr;
    current_state_->stack_ptr = abc_stack_ptr;
    state_map_.put(abc_pc, current_state_);

    SafepointData* new_state = new (alloc_) SafepointData;
    new_state->local_types = new (alloc_) SlotStorageType[frame_size_];
    new_state->scope_ptr = abc_scope_ptr;
    new_state->stack_ptr = abc_stack_ptr;

    SlotStorageType* local_types = new_state->local_types;
    for (int i = 0; i < frame_size_; i++) {
      local_types[i] = current_state_->local_types[i];
    }

    current_state_ = new_state;
  }

  int BailoutData::getStackPointer(int abc_pc) {
    SafepointData* state = getSafepointData(abc_pc);
    return state->stack_ptr;
  }

  int BailoutData::getScopeStack(int abc_pc) {
    SafepointData* state = getSafepointData(abc_pc);
    return state->scope_ptr;
  }

  SafepointData* BailoutData::getSafepointData(int abc_pc) {
    assert (state_map_.containsKey(abc_pc));
    return state_map_.get(abc_pc);
  }

  void BailoutData::init() {
    current_state_ = new (alloc_) SafepointData;
    current_state_->local_types = new (alloc_) SlotStorageType[frame_size_];
    current_state_->stack_ptr = stack_base_;
    current_state_->scope_ptr = scope_base_;
  }

  void BailoutData::clean() {
    state_map_.clear();
  }

} // end namespace
#endif // VMCFG_HALFMOON
