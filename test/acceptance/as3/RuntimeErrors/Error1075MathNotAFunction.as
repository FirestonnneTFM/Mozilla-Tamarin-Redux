/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1075; // Math is not a function.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var z = "no error";
    Math();
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
