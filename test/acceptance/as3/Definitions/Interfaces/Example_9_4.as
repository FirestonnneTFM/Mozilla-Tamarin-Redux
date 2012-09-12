/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import Example_9_4.*;

var eg = new ExampleTest();
AddTestCase("unique references via interface parent types", "a.{T,U}::f(),a.U::g()", eg.doUniqueTest());
AddTestCase("references via blended interface parent type", "a.U::g(),a.V::h()", eg.doBlendTest());
AddTestCase("references via implementing object type", "a.U::g(),a.{T,U}::f()", eg.doImplementsTest());
AddTestCase("reference via untyped object", "a.{T,U}::f()", eg.doUntypedTest());

test();       // leave this alone.  this executes the test cases and
              // displays results.
