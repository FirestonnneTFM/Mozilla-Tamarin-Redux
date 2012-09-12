/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1077; // Illegal read of write-only property _ on _.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

class C {
    var x:int = 0;
    function set a(b:int):void {
        x = b;
    }
}

try {
    var result = "no error";
    var c = new C();
    c.a();
} catch (err) {
    result = err.toString();
} finally {
    AddTestCase("Runtime Error", REFERENCEERROR + CODE, referenceError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
