/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Class Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import bug113887.*;

var eg = new BugTest();
AddTestCase("static initialization of class directly", "yes", eg.doBasicTest());
AddTestCase("static initialization of class via method", "yes", eg.doFunctionTest());

test();       // leave this alone.  this executes the test cases and
              // displays results.
