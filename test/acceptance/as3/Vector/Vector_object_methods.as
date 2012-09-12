/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Vector";
var VERSION = "Bug 592735: code coverage";
startTest();

writeHeaderToLog( SECTION + " Vector_object_AS3 methods methods based on missing code coverage");

class C
{
    var x: C = null;  // just some field to make the type nontrivial
}

var v: Vector.<C> = new Vector.<C>;
v[0] = new C;

// avmplus::NativeID::__AS3___vec_Vector_object_fixed_set_thunk(MethodEnv*,uint32_t,Atom*)
// avmplus::NativeID::__AS3___vec_Vector_object_fixed_get_thunk(MethodEnv*,uint32_t,Atom*)
v.fixed = true;
AddTestCase("Vector_uint_fixed_get", true, v.fixed);

expected = "RangeError: Error #1126";
err = "exception not thrown";
try {
    v.push(new C());
 }
catch (e:Error){
    err = e.toString();
}
AddTestCase("RangeError: Error #1126: Cannot change the length of a fixed Vector",
               expected,
               parseError(err, expected.length));

v.fixed = false;


test();
