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

var SECTION = "JSON";
var VERSION = "AS3";
var TITLE   = "JSON versioning tests";

// The point of this test is to ensure that old content that
// defines a JSON class in one file and uses that class in
// another file all continues to run properly when run
// in a dynamic context before version SWF_13.

// This is the file that drives the test.  It is designed
// so that it can be compiled by the current tool chain
// regardless of the current tool chain's version.
// The legacy content is kept in two .abc files that have
// been compiled with asc and a set of builtins before JSON
// was added to the builtins.

startTest();

// versioned_defjson_helper.as_ and versioned_useoldjson_helper.as_ were
// both compiled with builtins _before_ JSON was added.
// to recompile the helper files sync to tr 6199
// rename the abc files to
// versioned_defjson_helper.abc_bin and versioned_useoldjson_helper.abc_bin

// the versioned.as.avm_args runs this test with:
//   -api SWF_12 ecma3/JSON/versioned_defjson_helper.abc_bin ecma3/JSON/versioned_useoldjson_helper.abc_bin

import versioned_defjson.samefile_call_stringify;
import versioned_defjson.samefile_call_encode;

import versioned_useoldjson.otherfile_call_stringify;
import versioned_useoldjson.otherfile_call_encode;

startTest();

var callFailException;
var result;

callFailException="no exception thrown";;
try {
    var a = {};
    samefile_call_stringify(a);
} catch (e) {
    callFailException=e.toString();
    callFailException=removeExceptionDetail(callFailException);
}
AddTestCase("user-defined JSON in same file not overridden by builtin stringify when < SWF_13.",
            "TypeError: Error #1006",
            callFailException);

try {
    var a = {};
    result = samefile_call_encode(a);
} catch (e) {
    result=e.toString();
}
AddTestCase("user JSON in same file not overridden by builtin lack of encode when < SWF_13.",
            "legacyEncodeOutput",
            result);

callFailException="no exception thrown";;
try {
    var a = {};
    otherfile_call_stringify(a);
} catch (e) {
    callFailException=e.toString();
    callFailException=removeExceptionDetail(callFailException);
}
AddTestCase("user-defined JSON in other file not overridden by builtin stringify when < SWF_13.",
            "TypeError: Error #1006",
            callFailException);

try {
    var a = {};
    result = otherfile_call_encode(a);
} catch (e) {
    result=e.toString();
}
AddTestCase("user JSON in other file not overridden by builtin lack of encode when < SWF_13.",
            "legacyEncodeOutput",
            result);

test();
