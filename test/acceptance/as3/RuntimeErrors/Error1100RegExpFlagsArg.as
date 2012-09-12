/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1100; // Cannot supply flags when constructing one RegExp from another.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var result = "no error";
    var re:RegExp = new RegExp("ali", "/s");
    var re2:RegExp = new RegExp(re, "i");
} catch (err) {
    result = err.toString();
} finally {
    AddTestCase("Runtime Error", TYPEERROR + CODE, typeError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
