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

#include "profiler-main.h"
#ifdef VMCFG_HALFMOON

namespace profiler {

ProfiledState::ProfiledState(Allocator& allocator, int input_count, int output_count)
  : allocator_(allocator)
{
  this->input_count_ = input_count;
  this->output_count_ = output_count;
  init();
}

RecordedType ProfiledState::getInputType(int input_index) {
  assert (hasData());
  assert (input_index < input_count_);
  return profiled_types_[input_index];
}

RecordedType ProfiledState::getOutputType(int output_index) {
  assert (hasData());
  assert (output_index < output_count_);
  return profiled_types_[output_index + input_count_];
}

void ProfiledState::setOutputType(int output_index, Atom value) {
  assert (hasData());
  assert (output_index < output_count_);
  profiled_types_[output_index + input_count_] = getRecordedType(value);
}

RecordedType ProfiledState::getRecordedType(Atom value) {
  Atom atom_kind = atomKind(value);
  switch (atom_kind) {
  case kDoubleType: return kDOUBLE;
  case kIntptrType: return kINTEGER;
  case kStringType: return kSTRING;
  case kBooleanType: return kBOOLEAN;
  case kObjectType: {
    ScriptObject* object = AvmCore::atomToScriptObject(value);
    if (object == NULL) return kOBJECT; // undefined object
    if (object->toArrayObject() != NULL) return kARRAY;
    return kOBJECT;
  }
  case kUnusedAtomTag: return kUNINITIALIZED;
  case kNamespaceType: return kUNSUPPORTED;
  case kSpecialBibopType: return kUNSUPPORTED;
  default:
    printf("Unknown atom type %d\n", (int) atom_kind);
    assert (false);
  }

  assert (false);
  return kUNINITIALIZED;
}

bool ProfiledState::isNumericType(RecordedType t) {
  return t == kINTEGER 
    || t == kDOUBLE
    || t == kNUMERIC;
}


void ProfiledState::setInputType(int input_index, Atom value) {
  RecordedType new_type = getRecordedType(value);
  setInputRecordedType(input_index, new_type);
}

void ProfiledState::setInputRecordedType(int input_index, RecordedType new_type) {
  assert (hasData());
  assert (input_index < input_count_);
  RecordedType previous_type = profiled_types_[input_index];

  if ((new_type != previous_type) &&
      (previous_type != kUNINITIALIZED)) {
      new_type = kVARIADIC;
  }

  profiled_types_[input_index] = new_type;
}

void ProfiledState::init() {
  allocateInputTypes();
}

/***
 * If we have no data, that means the verifier already refined
 * the types to something more than the any type.
 */
bool ProfiledState::hasData() {
  return profiled_types_ != NULL;
}

void ProfiledState::allocateInputTypes() {
  int total_size = input_count_ + output_count_;
  profiled_types_ = new (allocator_) RecordedType[total_size];
  for (int i = 0; i < total_size; i++)
    profiled_types_[i] = kUNINITIALIZED;
}

} // namespace profiler {

#endif // VMCFG_HALFMOON
