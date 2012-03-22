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

/// Simple max function.
///
template<class T> T max(T a, T b) {
  return a > b ? a : b;
}

/// Simple min function.
///
template<class T> T min(T a, T b) {
  return a < b ? a : b;
}

/// Copy values from from_range to to_range.  Similar to STL copy(), except
/// that the ranges must be the same size, and no range is returned.
///
template<class FR, class TR>
inline void copyRange(FR from_range, TR to_range) {
  for (; !from_range.empty(); from_range.popFront(), to_range.popFront())
    to_range.front() = from_range.front();
  assert(to_range.empty());
}

/// Find value in range starting at the front.  Returns new range starting
/// with the found value.  Similar to STL find().
///
template<class R, class T>
inline R find(R r, T value) {
  for (; !r.empty(); r.popFront())
    if (r.front() == value)
      break;
  return r;
}

/// Count the number of elements in range.
///
template<class R>
inline int count(R r) {
  int n = 0;
  for (; !r.empty(); r.popFront())
    n++;
  return n;
}

/// Assign value to all elements in Range
///
template<class Range, class Value>
inline void fill(Range r, Value v) {
  for (; !r.empty(); r.popFront())
    r.front() = v;
}

} // namespace avmplus
