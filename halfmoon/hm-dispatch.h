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

#ifndef HALFMOON_DISPATCH_H
#define HALFMOON_DISPATCH_H

namespace halfmoon {

/// KindAdapter implements a default do function for every opcode by calling
/// the adapter function A.do_default().  Subclasses shadow any function they
/// want to implement.  When used with do_instr<A>(), the subclass function
/// is called.  For example:
///
/// class MyKindAdapter : public KindAdapter<MyInstrAdapter, int> {
/// public:
///   int do_add(BinaryStmt* instr);
/// };
///
/// KindAdapter uses "static polymorphism", via the curiously recurring
/// template pattern (CRTP):
///
template<class SELF_CLASS, class RETURN_TYPE>
class KindAdapter {
public:
  typedef RETURN_TYPE dispatch_return_type;

#include "generated/KindAdapter_methods.hh"
};

/// do_instr() is a template function for doing something specific based
/// on opcode.  INSTR_ADAPTER must have a do_xxx for each opcode named HR_xxx,
/// plus a do_default function for opcodes that no adapter has any special
/// code for.  (basically instructions not yet implemented).
///
template<class KIND_ADAPTER>
typename KIND_ADAPTER::dispatch_return_type do_instr(KIND_ADAPTER* a, Instr* instr) {
  switch (kind(instr)) {
#include "generated/KindAdapter_cases.hh"
  default:
    assert(false && "unknown opcode");
    return a->do_default(instr);
  }
}

/// ShapeAdapter implements a default do function for every shape by calling
/// the adapter function A.do_default().  Subclasses shadow any function they
/// want to implement.  When used with do_shape<A>(), the subclass function
/// is called.  For example:
///
/// class MyShapeAdapter : public ShapeAdapter<MyShapeAdapter, int> {
/// public:
///   int do_BinaryStmt(BinaryStmt* instr);
/// };
///
/// ShapeAdapter uses "static polymorphism", via the curiously recurring
/// template pattern (CRTP):
///
template<class SELF_CLASS, class RETURN_TYPE>
class ShapeAdapter {
public:
  typedef RETURN_TYPE dispatch_return_type;

#include "generated/ShapeAdapter_methods.hh"
};

/// do_shape() is a template function for doing something specific based
/// on shape.  SHAPE_ADAPTER must have a do_xxx for each shape named xxx,
/// plus a do_default function for shapes that no adapter has any special
/// code for.
///
template<class SHAPE_ADAPTER>
typename SHAPE_ADAPTER::dispatch_return_type do_shape(SHAPE_ADAPTER* a, Instr* instr) {
  switch (shape(instr)) {
#include "generated/ShapeAdapter_cases.hh"
  default:
    assert(false && "unknown shape");
    return a->do_default(instr);
  }
}

} // namespace halfmoon

#endif // HALFMOON_DISPATCH_H
