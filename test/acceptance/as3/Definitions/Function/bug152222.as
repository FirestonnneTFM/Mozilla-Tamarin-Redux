/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1006; // _ is not a function.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

var expected = "Error #" + CODE;
var result = "no error";
try {
    var x:Number = 0;
    x.toString()();
} catch (err) {
    result = grabError(err, err.toString());
} finally {
    AddTestCase("Runtime Error", expected, result);
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
