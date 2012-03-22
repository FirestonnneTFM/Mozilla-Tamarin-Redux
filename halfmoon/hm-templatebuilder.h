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

#ifndef TEMPLATE_BUILDER_H_
#define TEMPLATE_BUILDER_H_

namespace halfmoon {
using nanojit::BitSet;
using avmplus::ExceptionHandler;

/// A TemplateBuilder is used for creating InstrGraphs for
/// small instruction templates.
///
class TemplateBuilder {
public:
  TemplateBuilder(InstrFactory* factory);

  /// start the given template
  /// TODO handle multiple control inputs, data or control varargs
  void start(InstrKind k, int num_params, const Type* param_types[]);

  /// return a reference to the given template param
  Def* paramRef(int i) {
    assert(i >= 0 && i < numDefs(start_instr_));
    return &start_instr_->params[i];
  }

  /// add instr to template, return pointer to instr.
  /// We also check for return being added here,
  /// and set IR's end instr when we see it.
  ///
  Instr* addInstr(Instr* instr) {
    instr = builder_.addInstr(instr);
    if (kind(instr) == HR_return) {
      assert(!ir_->end);
      ir_->end = cast<StopInstr>(instr);
    }
    return instr;
  }

  /// add type const-generating instruction to template
  Def* traitsConst(Traits* traits) {
    return builder_.addConst(ir_->lattice.makeTraitsConst(traits));
  }

  /// add int const-generating instruction to template
  Def* intConst(int c) {
    return builder_.addConst(ir_->lattice.makeIntConst(c));
  }

  /// add double const-generating instruction to template
  Def* doubleConst(double c) {
    return builder_.addConst(ir_->lattice.makeDoubleConst(c));
  }

  /// return a reference to the finished template IR
  InstrGraph* ir() {
    assert(ir_->end && "incomplete template");
    return ir_;
  }

private:
  InstrFactory& factory_;
  InstrGraph* ir_;
  InstrGraphBuilder builder_;
  StartInstr* start_instr_;
};

} // namespace halfmoon

#endif // TEMPLATE_BUILDER_H_
