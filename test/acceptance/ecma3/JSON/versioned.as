/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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
