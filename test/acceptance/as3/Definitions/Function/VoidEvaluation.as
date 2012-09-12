/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import voidEvaluation.*


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Function Return Type";       // Provide ECMA section title or a description
var BUGNUMBER = "108487";

startTest();                // leave this alone

var TESTOBJ = new TestObj();

var result = "exception";
try {
    TESTOBJ.g();
    result = "no exception";
}  catch (e1) {
    result = e1.toString();
}

AddTestCase("Assign function that returns void", "no exception",  result);

AddTestCase("Test for g being called", "hello from g", TESTOBJ.varG);

AddTestCase("Test for f being called", "hello from f", TESTOBJ.varF);

test();       // leave this alone.  this executes the test cases and
              // displays results.
