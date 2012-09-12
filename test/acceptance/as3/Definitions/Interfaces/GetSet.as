/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import GetSet.*;

var eg = new GetSetTest();
AddTestCase("simple get", "x.A::get a()", eg.doGetAX());
AddTestCase("simple set", "x.A::set a()", eg.doSetAX());
AddTestCase("simple get", "x.A::get b()", eg.doGetBX());
AddTestCase("simple set", "x.A::set c()", eg.doSetCX());

AddTestCase("blend get", "y.A::get a()", eg.doGetAY());
AddTestCase("blend set", "y.A::set a()", eg.doSetAY());
AddTestCase("blend get", "y.A::get b()", eg.doGetBY());
AddTestCase("blend set", "y.B::set b()", eg.doSetBY());
AddTestCase("blend get", "y.B::get c()", eg.doGetCY());
AddTestCase("blend set", "y.A::set c()", eg.doSetCY());

test();       // leave this alone.  this executes the test cases and
              // displays results.
