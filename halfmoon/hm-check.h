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

namespace halfmoon {

/// Run checkTypes(Instr) on every instruction reachable by PostorderDefIter.
///
bool checkTypes(InstrGraph*, bool check_model);

/// Check that the inputs to Instr have legal types.
///
bool checkTypes(Instr*, bool check_model);

/// Check that InstrGraph is well formed.
///
/// There must be exactly one Begin and one End instr.  Arguments cannot
/// be CTRL, and control inputs must be CTRL or UN.
///
/// Compute the set of uses for each Def by inspecting defs, then make sure
/// it maches the use list in each Def.
///
bool checkUses(InstrGraph*);

/// Ensure the graph has a begin instruction and either a return or throw
/// instruction, or both.
bool checkStartEnd(InstrGraph*);

/// Ensure that the ir has exactly one end instruction of the required opcode.
///
bool checkOneEnd(InstrGraph* ir, Instr* end, InstrKind k);

/// Check that each result type is defined.  This catches a mistake
/// where SomeInstr.computeTypes() fails to assign a type to every def.
///
bool checkResultTypes(Instr* n, bool check_model);

bool checkPruned(InstrGraph* ir);
bool checkSSA(InstrGraph* ir);

/// Check that the graph is fully linked: mark all linked instructions, then
/// assert that no unmarked instructions can be reached from a label->goto
/// edge, a def->use edge, or a use->def edge.
bool checkPruned(InstrGraph* ir);

bool checkSSA(InstrGraph* ir);

} // namespace avmplus
