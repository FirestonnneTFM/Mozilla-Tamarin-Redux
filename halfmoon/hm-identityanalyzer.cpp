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

#include "hm-main.h"
#ifdef VMCFG_HALFMOON

namespace halfmoon {

/// Return the identity def for the given instruction, which will either
/// be effect_in, or the given value_in.
///
Def* IdentityAnalyzer::identity(BinaryStmt* instr, Def* value_in) {
  return def_ == instr->effect_out() ? def(instr->effect_in()) : value_in;
}

Def* IdentityAnalyzer::identity(UnaryStmt* instr, Def* value_in) {
  return def_ == instr->effect_out() ? def(instr->effect_in()) : value_in;
}

/// Return the identity def for the given instruction, which will either
/// be effect_in, or the given value_in.
///
Def* IdentityAnalyzer::identity(UnaryStmt* instr) {
  return def(def_ == instr->effect_out() ? instr->effect_in() :
             instr->value_in());
}

Def* IdentityAnalyzer::identity(Instr* instr) {
  assert(definer(def_) == instr && "Illegal def");
  return do_instr(this, instr);
}

/// Analyze lexical lookup instructions HR_findprop and HR_findpropstrict.
///
Def* IdentityAnalyzer::doFindStmt(NaryStmt2* instr) {
  int index;
  if (findScope(lattice_, instr, &index) == kScopeLocal)
    return def(instr->vararg(index));
  return def_;
}

Def* IdentityAnalyzer::do_cast(BinaryStmt* instr) {
  const Type* traits_type = type(instr->lhs_in());
  if (!isConst(traits_type))
    return def_; // Don't know the target traits.
  const Type* to_type = lattice_->makeType(traitsVal(traits_type));
  // fixme: this is copied from coerceIdentity().
  Def* value_in = def(instr->rhs_in());
  if (subtypeof(type(value_in), to_type))  
    return identity(instr, value_in);
  return def_;
}

Def* IdentityAnalyzer::do_toprimitive(UnaryStmt* instr) {
  if (isPrimitive(type(instr->value_in())))
    return identity(instr);
  return def_;
}

Def* IdentityAnalyzer::coerceIdentity(UnaryExpr* instr, const Type* to_type) {
  Def* value_in = def(instr->value_in());
  if (subtypeof(type(value_in), to_type))
    return value_in;
  return def_;
}

Def* IdentityAnalyzer::coerceIdentity(UnaryStmt* instr, const Type* to_type) {
  Def* value_in = def(instr->value_in());
  if (subtypeof(type(value_in), to_type))
    return identity(instr, value_in);
  return def_;
}

Def* IdentityAnalyzer::do_coerce(BinaryStmt* instr) {
  const Type* traits_type = type(instr->lhs_in());
  if (isConst(traits_type)) {
    const Type* to_type = lattice_->makeType(traitsVal(traits_type));
    Def* value_in = def(instr->rhs_in());
    if (subtypeof(type(value_in), to_type))
      return identity(instr, value_in);
  }
  return def_;
}

Def* IdentityAnalyzer::do_cknull(UnaryStmt* instr) {
  if (!isNullable(type(instr->value_in())))
    return identity(instr);
  return def_;
}

Def* IdentityAnalyzer::do_u2i(UnaryExpr* instr) {
  Def* d2;
  if (match(instr->value_in(), HR_i2u, &d2))
    return d2;
  return def_;
}

/// Process each def leaving this label, treating each def as a phi pseudo-
/// function.  phi(x,y) means a dataflow merge of x and y at this label.
///
/// 1. If all the values are the same, return that value.
///    z = phi(x, ..., x) => z = x
/// 2. If the only non-self value is x, return that:
///    z = phi(x, z, ..., z) => z = x
///
Def* IdentityAnalyzer::do_label(LabelInstr* label) {
  assert(label->preds);
  // must have at least one predecessor.
  Def* d = 0;
  for (LabelArgRange r(label, pos(def_)); !r.empty(); r.popFront()) {
    Def* d2 = def(r.front());
    if (d2 != def_ && d2 != d) {
      if (!d)
        d = d2;
      else
        return def_;
    }
  }
  assert(d && "no external values reached this label");
  return d;
}

/// Un-split any def on this edge, if its type is the same as the value
/// going into the IF, except EFFECT types.
///
Def* IdentityAnalyzer::do_arm(ArmInstr* arm) {
  if (isLinear(type(def_))) {
    // Do not un-split linear types, so as to avoid creating scheduling
    // headaches later by allowing uses to float out of basic blocks.
    return def_;
  }
  Def* arg = def(arm->owner->arg(pos(def_)));
  if (*type(def_) == *type(arg))
    return arg;
  return def_;
}

Def* IdentityAnalyzer::do_speculate_number(BinaryExpr* instr) {
  //assert (type(instr->lhs_in()) != type(instr->value_out()));
  Def* lhs_in = def(instr->lhs_in());
  if (isNumber(type(lhs_in)))
    return lhs_in;
  return def_;
}

Def* IdentityAnalyzer::doModelChange(UnaryExpr* expr, InstrKind opposite) {
  Def* in;
  if (match(expr->value_in(), opposite, &in))
    return in;
  return def_;
}

} // namespace halfmoon
#endif // VMCFG_HALFMOON
