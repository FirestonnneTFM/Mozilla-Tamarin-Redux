/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1007; // Instantiation attempted on a non-constructor.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var result = "no error";
    new this();
} catch (err) {
    result = err.toString();
} finally {
    AddTestCase("Runtime Error", TYPEERROR + CODE, typeError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
