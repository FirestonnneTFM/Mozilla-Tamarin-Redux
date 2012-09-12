/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1056; // Cannot create property _ on _.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

class C {}

try {
    var result = "no error";
    var c:C = new C();
    c.c = 0;
} catch (err) {
    result = err.toString();
} finally {
    AddTestCase("Runtime Error", REFERENCEERROR + CODE, referenceError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
