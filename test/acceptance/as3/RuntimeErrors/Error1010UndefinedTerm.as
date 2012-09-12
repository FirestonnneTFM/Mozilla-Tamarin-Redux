/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
1010    A term is undefined and has no properties.
*/

var CODE = 1010;

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
    var z = "no error";
    var obj:Object = new Object();
    var a = obj.x.prop;
} catch (err) {
    z = err.toString();
} finally {
    AddTestCase("Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
