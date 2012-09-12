/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
1076    Math is not a constructor.
*/

var CODE = 1076;

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var z = "no error";
    new Math();
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
