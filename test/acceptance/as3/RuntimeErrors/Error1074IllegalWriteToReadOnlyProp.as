/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1074; // Illegal write to read-only property _ on _.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var z = "no error";
    Object = new Object();
    Object.valueOf = Number.prototype.valueOf;
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", REFERENCEERROR + CODE, referenceError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
