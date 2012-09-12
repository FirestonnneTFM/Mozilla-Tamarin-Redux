/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
1064    Cannot call method _ as constructor.
*/

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

class A {
    function f() {}
}

var a = new A();
var b = a.f;

try {
    var z = "no error";
    var c = new b();
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", "TypeError: Error #1064", typeError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
