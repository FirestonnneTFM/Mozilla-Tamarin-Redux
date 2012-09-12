/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import Example_9_3.*;

var eg = new ExampleTest();
AddTestCase("simple public implements", "a.T::f()", eg.doTestPublic());
AddTestCase("simple namespace implements", "a.g()", eg.doTestNS1());
AddTestCase("simple interface name implements", "b.T::f()", eg.doTestIName());
AddTestCase("simple namespace implements", "b.g()", eg.doTestNS2());

test();       // leave this alone.  this executes the test cases and
              // displays results.
