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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

#ifndef IDENTITYANALYZER_H_
#define IDENTITYANALYZER_H_

namespace halfmoon {

/// IdentityAnalyzer computes identities for each kind of instruction.
/// A def of an instruction has an identity def, if that def's value is always
/// the same as one of the instruction's inputs.
///
/// Instructions are not mutated or created, and this analyzer does not have
/// any global knowlege.  Identities are found just by looking at adjacent
/// instructions.
///
class IdentityAnalyzer: public KindAdapter<IdentityAnalyzer, Def*> {
public:
  IdentityAnalyzer(Def* def, Lattice* lattice)
  : def_(def)
  , lattice_(lattice)
  {}

  Def* identity(Instr*);

public: // dispatch() adapter methods.
  Def* do_default(Instr*) { return def_; }
  Def* do_arm(ArmInstr*);
  Def* do_label(LabelInstr*);
  Def* do_toprimitive(UnaryStmt*);
  Def* do_coerce(BinaryStmt*);
  Def* do_castobject(UnaryExpr* i) { return coerceIdentity(i, lattice_->object_type[kTypeNullable]); }
  Def* do_caststring(UnaryStmt* i) { return coerceIdentity(i, lattice_->string_type[kTypeNullable]); }
  Def* do_tonumber(UnaryStmt* i) { return coerceIdentity(i, lattice_->double_type); }
  Def* do_toint(UnaryStmt* i) { return coerceIdentity(i, lattice_->int_type); }
  Def* do_touint(UnaryStmt* i) { return coerceIdentity(i, lattice_->uint_type); }
  Def* do_toboolean(UnaryExpr* i) { return coerceIdentity(i, lattice_->boolean_type); }
  Def* do_doubletoint32(UnaryExpr* i) { return coerceIdentity(i, lattice_->int_type); }
  Def* do_abc_findproperty(NaryStmt2* i) { return doFindStmt(i); }
  Def* do_abc_findpropstrict(NaryStmt2* i) { return doFindStmt(i); }
  Def* do_atom2scriptobject(UnaryExpr* i) { return doModelChange(i, HR_scriptobject2atom); }
  Def* do_cast(BinaryStmt*);
  Def* do_cknull(UnaryStmt*);
  Def* do_cknullobject(UnaryStmt* i) { return do_cknull(i); }
  Def* do_u2i(UnaryExpr*);
  Def* do_speculate_number(BinaryExpr*);

private:
  /// Generic analyzer for lexical 'find' instructions.
  ///
  Def* doFindStmt(NaryStmt2*);

  /// Helper method: return the appropriate identity def based on which
  /// use value_in is, and what def_ is pointing to.
  ///
  Def* identity(BinaryStmt*, Def* value_in);
  Def* identity(UnaryStmt*, Def* value_in);

  /// Helper method: return UnaryStmt.effect_in or value_in based on
  /// what def_ is pointing to.
  ///
  Def* identity(UnaryStmt*);

  /// Identity for coerce opcodes
  ///
  Def* coerceIdentity(UnaryStmt*, const Type* to_type);
  Def* coerceIdentity(UnaryExpr*, const Type* to_type);
  Def* doModelChange(UnaryExpr*, InstrKind);

private:
  Def* const def_;        // The existing def_ we are analyzing.
  Lattice* const lattice_;
};

} // namespace halfmoon
#endif // IDENTITYANALYZER_H_
