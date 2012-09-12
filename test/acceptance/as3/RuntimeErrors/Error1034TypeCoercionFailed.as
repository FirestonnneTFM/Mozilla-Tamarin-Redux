/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1034; // Type Coercion failed: cannot convert _ to _.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var result = "no error";
    f = function (arg):Function {return arg;};
    f({});
} catch (err) {
    result = err.toString();
    trace(err);
} finally {
    AddTestCase("Runtime Error", TYPEERROR + CODE, typeError(result));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
