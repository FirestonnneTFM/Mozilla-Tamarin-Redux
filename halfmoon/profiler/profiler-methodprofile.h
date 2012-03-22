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

/***
 * Interfaces and represents the whole profile information
 * for a given MethodInfo.
 */

#ifndef PROFILER_METHODPROFILE_H_
#define PROFILER_METHODPROFILE_H_

// Anyway to include nanojit allocators / contains w/o including the header here?
// Only methodprofile.cpp should include this file as well
#include "../nanojit/nanojit.h"

namespace profiler {
class ProfiledState;
using avmplus::MethodInfo;
using nanojit::Allocator;
using nanojit::HashMap;
using nanojit::Seq;

enum PROFILING_STATE { NONE, PROFILING, GATHERED, INACCURATE };

/***
 * A class that maps MethodInfos to their MethodProfile.
 * Have to do this since we can't keep MethodProfile, a non-GC object
 * in MethodInfo otherwise we leak memory.
 * We have to do manual memory management with NanojIT::allocators
 * 
 * This is attached to the PoolObject and thus is long lived.
 * May find out that MethodProfiles actually live too long
 * and may have to manually delete MethodProfiles 
 */
class MethodProfileMgr 
{
public:
  MethodProfileMgr(Allocator&);
  MethodProfile* getMethodProfile(MethodInfo* methodInfo);

private:
  typedef HashMap<MethodInfo*, MethodProfile*> MethodInfoMap;
  Allocator& method_profile_allocator_;
  Allocator& input_types_allocator_;
  MethodInfoMap method_info_map_;
  };

/*** 
 * Represents all the gathered runtime profiling data of an executed
 * ActionScript method. We keep track of the following things:
 *
 * Method invocation count
 * taken/ not taken branches. We keep track of the number of times a
 *      CFG edge is taken with a start -> target pair.
 * Runtime types of local variables that are declared the any type by the verifier.
 */
class MethodProfile
{
public:
  MethodProfile(Allocator& allocator, Allocator& runtime_type_allocator);
  ~MethodProfile();

   /// Returns the number of times this edge was taken.
   /// inputs: the starting abc pc. The opcode at the starting point must be a branch ABC opcode.
   /// target_abc_pc - the destination abc pc.
   /// 
  int32_t getBranchCount(int branch_abc_pc, int target_abc_pc);

  double getBranchProbability(int branch_abc_pc, int target_abc_pc);

  /// Returns the runtime profiled information for
  /// the given abc program location.
  /// 
  ProfiledState* getProfileState(int abc_pc, int input_count, int output_count); 

  /// Returns how many iterations the backwards branch to this
  /// loop header has occured.
  ///
  int32_t getLoopIterationCount(int branch_pc, int target_pc);

  /// Methods invoked during actual runtime profiling
  ///
  void initializeBranchCounters(int start_pc, int true_target_pc, int false_target_pc);
  void incrementBranchCounters(bool took_true_branch, int start_pc, int true_target_pc, int false_target_pc);

  /// Check if we already gathered data
  bool hasGatheredAllData();

  // Check if we have bailed out before.
  bool hasBailedOut();

  // Mark data as complete and inaccurate
  void finish();

private:
  HashMap<int,int>* getBranchTargetCounters(int abc_branch_pc);

public:
  // These have to be public so CodegenLIR can directly write to these fields.
  int32_t   method_invocation_count_;
  PROFILING_STATE current_profiler_state_;

private:
  // data
  int32_t*  loop_iteration_count_;

  /// Keep track of each ABC branch -> target edge.
  /// branch_counter_map == maps abc branch location -> map of all possible targets.
  /// possible targets map == target -> taken count
  ///
  typedef HashMap<int, HashMap<int,int>*> BranchCounters;
  typedef HashMap<int, ProfiledState*> InputTypes;

  Allocator& branch_counter_allocator_;
  Allocator& input_types_allocator_;
  BranchCounters branch_counter_map_;
  InputTypes runtime_type_map_;
};

}
#endif // PROFILER_METHODPROFILE_H_
