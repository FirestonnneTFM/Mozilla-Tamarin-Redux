/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import TraitsNotAccessible.*;

var eg = new TraitTest();
AddTestCase("call implemented method", "x.I::f()", eg.doCall());
var thisError : String = "no exception thrown";
var result = "";
try {
    result = eg.doSuperCall();
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("call super method", REFERENCEERROR+1070, referenceError(thisError));

}

test();       // leave this alone.  this executes the test cases and
              // displays results.
