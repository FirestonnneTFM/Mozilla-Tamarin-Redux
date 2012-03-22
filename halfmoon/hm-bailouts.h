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

#ifndef HM_BAILOUTS_H
#define HM_BAILOUTS_H

namespace halfmoon {
  struct SafepointData {
    SlotStorageType*  local_types;
    int   stack_ptr;
    int   scope_ptr;
  };

  /// At a given savepoint, we have to store the state of the
  /// locals, scope stack, and operand stack for temporaries.
  /// At the moment, it's only limited to the native type represented by halfmoon
class BailoutData {
  typedef HashMap<int, SafepointData*> StateMap;

public:
  BailoutData(Allocator& alloc, MethodInfo* method, int scope_base, int stack_base);
  ~BailoutData();

  int getStackPointer(int abc_pc);
  int getScopeStack(int abc_pc);
  void setNativeType(int localIndex, SlotStorageType sst_type);
  void do_safepoint(int abc_pc, int abc_scope_ptr, int abc_stack_ptr);
  void init();
  void clean();

private:
  SafepointData* getSafepointData(int abc_pc);

private:
  // Data
  Allocator& alloc_;
  MethodInfo* method_info_;
  StateMap state_map_;
  SafepointData* current_state_;
  int frame_size_;
  int scope_base_;
  int stack_base_;
};

} // end namespace

#endif

