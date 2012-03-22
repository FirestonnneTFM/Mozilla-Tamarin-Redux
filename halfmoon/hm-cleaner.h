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

#ifndef HM_CLEANER_H_
#define HM_CLEANER_H_

namespace halfmoon {

/// Cleaner
/// in CFG postorder, until fixed point:
/// #1 eliminate redundant branch: edges to same label & same goto args:
///    replace with single goto
/// #2 eliminate empty block
///    [L1;goto->L2] - change all L1's gotos to L2, fix up shuffled args
/// #3 coalesce blocks
///    eliminate Label with 1 goto or arm chosen by const condition
///    done - see onePass() calling joinBlocks()
/// #4 hoist branches out of empty blocks
///    [goto->L1;cond a1,a2] => [cond]
///    replace arms with labels
///
class Cleaner {
public:
  Cleaner(InstrGraph* ir);
  bool onePass();
  LabelInstr* ensureLabel(ArmInstr* arm);

private:
  bool simplify(BlockEndInstr* block);
  bool hoistBranch(GotoInstr* go, CondInstr* branch);
  bool hoistGoto(GotoInstr* go, GotoInstr* succ_go);
  bool joinBlocks(BlockEndInstr* pred, BlockStartInstr* succ, InstrGraph* ir);
  bool joinArms(CondInstr* cond, LabelInstr* target);
  Def* translate(const Use&, GotoInstr* go);
  LabelInstr* findSingleTarget(CondInstr* branch);

private:
  Allocator alloc_;
  HashMap<int, LabelInstr*> arm_labels_; // one label for each arm that gained goto's
  InstrGraph* ir_;
  InstrFactory factory_;
};

/// Simplify the control flow graph as much as possible by
/// removing constant conditions, removing dead blocks, bypassing
/// redundant jumps, etc.
void cleanBlocks(Context* cxt, InstrGraph* ir, Cleaner*);

}

#endif
