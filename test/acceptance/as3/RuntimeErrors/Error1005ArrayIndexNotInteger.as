/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1005; // Array index is not a positive integer (_).

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var result = "no error";
    new Array(1.2);
} catch (err) {
    result = err.toString();
} finally {
    AddTestCase("Runtime Error", RANGEERROR + CODE, rangeError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
