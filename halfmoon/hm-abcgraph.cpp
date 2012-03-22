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

//
// hm-abcgraph.cpp: implementation code for ABC Control Flow Graphs
//

#include "hm-main.h"
#ifdef VMCFG_HALFMOON

namespace halfmoon {

AbcGraph::AbcGraph(MethodInfo* method)
: alloc0_(alloc_), blockmap_(alloc_), abc_instrs(alloc_), entry_(0)
, handlers_(0), handler_count_(0), table_(0), method(method) {
  // create label at head of method's abc stream
  code_pos_ = method->getMethodSignature()->abc_code_start();
  entry_ = newAbcBlock(code_pos_);
  if ((table_ = method->abc_exceptions()) != 0)
    createTryCatchBlocks();
}

/// Create and add a label starting at pc to blockmap_, 
/// if not already present.
///
AbcBlock* AbcGraph::newAbcBlock(const uint8_t* pc) {
  AbcBlock* b = blockmap_.get(pc);
  if (!b) {
    if (enable_verbose)
      printf("createBlock %d\n", int(pc - code_pos_));
    blockmap_.put(pc, b = new (alloc0_) AbcBlock(pc));
  }
  return b;
}

/// Record an edge from one label to another, by adding
/// 'to' label to 'from' label's succ list. Create 'to'
/// label from target pc if necessary, and add it to
/// worklist if so.
///
void AbcGraph::addAbcEdge(AbcBlock* fm, const uint8_t* target_pc, int edge_index) {
  AbcBlock* to = newAbcBlock(target_pc);
  ++to->num_preds;
  if (target_pc <= fm->start)
    to->abc_loop = true;
  fm->succ_blocks[edge_index] = to;

  if (enable_verbose)
    printf("edge %d->%d\n", int(fm->start - code_pos_), int(target_pc  - code_pos_));
}

void AbcGraph::createTryCatchBlocks() {
  handler_count_ = table_->exception_count;
  if (!handler_count_)
    return;
  handlers_ = new (alloc_) AbcBlock*[handler_count_];
  for (int i = 0, n = handler_count_; i < n; ++i) {
    ExceptionHandler* handler = &table_->exceptions[i];
    newAbcBlock(code_pos_ + handler->from);
    newAbcBlock(code_pos_ + handler->to);
    handlers_[i] = newAbcBlock(code_pos_ + handler->target);
  }
}

void AbcGraph::analyzeExceptions(AbcBlock* fm) {
  assert(!fm->catch_blocks && !fm->max_catch_blocks);
  if (!table_)
    return;
  int n = table_->exception_count;
  const uint8_t* pc = fm->start;
  fm->max_catch_blocks = n;
  fm->catch_blocks = new (alloc0_) AbcBlock*[n];
  for (int i = 0; i < n; ++i) {
    ExceptionHandler* handler = &table_->exceptions[i];
    if (pc >= code_pos_ + handler->from && pc < code_pos_ + handler->to) {
      AbcBlock* catch_block = blockmap_.get(code_pos_ + handler->target);
      ++catch_block->num_preds;
      fm->catch_blocks[i] = catch_block;
    }
  }
}

void AbcGraph::analyzeBranch(AbcBlock* blk, AbcOpcode abcop, 
                             const uint8_t* nextpc, int32_t offset) {
  assert(isBranchOpcode(abcop) && abcop != OP_jump); (void)abcop;

  newSuccEdges(blk, 2);
  addAbcEdge(blk, nextpc, 0);
  addAbcEdge(blk, nextpc + offset, 1);
}

void AbcGraph::analyzeSwitch(AbcBlock* blk, const uint8_t* pc,
                             const uint8_t* nextpc, int32_t default_offset,
                             uint32_t num_cases) {
  newSuccEdges(blk, num_cases + 1);
  for (uint32_t i = 0; i < num_cases; ++i, nextpc += 3)
    addAbcEdge(blk, pc + AvmCore::readS24(nextpc), i); // case edge
  addAbcEdge(blk, pc + default_offset, num_cases); // default edge
}

// Add edge to next instr - our label ends here and
// we fall through to next label
void AbcGraph::analyzeEnd(AbcBlock* blk, const uint8_t* nextpc) {
  newSuccEdges(blk, 1);
  addAbcEdge(blk, nextpc, 0);
}

void AbcGraph::newSuccEdges(AbcBlock* block, int count) {
  assert(!block->succ_blocks && !block->num_succ_blocks);
  block->succ_blocks = new (alloc_) AbcBlock*[count];
  block->num_succ_blocks = count;
}

} // namespace avmplus
#endif // VMCFG_HALFMOON
