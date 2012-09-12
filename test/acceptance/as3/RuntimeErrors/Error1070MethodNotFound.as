/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
1070    Method _ not found on _
*/

var CODE = 1070;

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

class A {}

class B extends A {
  function f() { super.f(); }
}

try {
    var z = "no error";
    new B().f();
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", "ReferenceError: Error #" + CODE, referenceError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
