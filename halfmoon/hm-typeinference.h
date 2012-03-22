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

/**
 * Sparse Conditional Constant propagation.  Reset all types of all defs,
 * then recompute types using the classic worklist algorithm.
 * TODO: literature reference.
 */
void propagateTypes(InstrGraph*);

/**
 * Calculate the types of an IR graph with respect to the
 * specified argument types, rather than the graph start
 * instruction's stated param types.
 * 
 * Calculated types are left in the graph, with the exception
 * that the graph's param types are restored after the calculation.
 * Calculated output types may be retrieved from the graph's return
 * instruction. Note: it's the caller's responsibility to copy
 * calculated results to a permanent location: they will be
 * overwritten the next time this function is called on the graph.
*/
void propagateTypes(InstrGraph* ir, const Type** arg_types);

/**
 * Propagate types through a fat instruction subgraph,
 * starting from the input types of an instance.
 * 
 * Note: propagated type are left in place in the subgraph;
 * caller must copy them out to a permanent location.
 */
void propagateTypes(Instr* fat_instr);

}
