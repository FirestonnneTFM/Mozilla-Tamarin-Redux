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

/***
 * Represents the profile information gathered at one specific PC in
 * the ABC program. The information is specific to ABC information, not LIR.
 * We keep track of the ABC locals, scope stack, and operand stack type information.
 */

#ifndef PROFILER_PROFILEDSTATE_H_
#define PROFILER_PROFILEDSTATE_H_

/***
 * This represents the runtime profiled information
 * at a single ABC PC location. We only need to keep 
 * pertinent information about the current ABC opcode.
 * 
 * So we only have to track inputs -> output types.
 * Only need to track output types if we can have multiple
 * output types. eg bitand will always return an integer, so no
 * reason to track it.
 */
namespace profiler {
using avmplus::AvmCore;
using avmplus::Traits;
using avmplus::Atom;
using avmplus::ScriptObject;

class ProfiledState {
public:
  ProfiledState(Allocator& allocator, int input_count, int output_count);

  RecordedType getInputType(int inputIndex);
  RecordedType getOutputType(int outputIndex);
  bool isVariadicInputType(int inputIndex);
  bool isNumericType(RecordedType t);
  void setInputType(int inputIndex, Atom value);
  void setInputRecordedType(int input_index, RecordedType rt);
  void setOutputType(int outputIndex, Atom value);
  bool hasData();
  void init();
  RecordedType getRecordedType(Atom value);

private:
  void allocateInputTypes();
  RecordedType* profiled_types_;
  Allocator& allocator_;
  int input_count_;
  int output_count_;
};
}

#endif // PROFILER_PROFILEDSTATE_H_
