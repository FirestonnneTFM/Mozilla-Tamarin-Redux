/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import ImplementMultipleInterfaces.*;

var eg = new ImplementTest();
AddTestCase("single implements", "x1.A::a()", eg.doTestX1());
AddTestCase("double implements", "x2.A::a(),x2.B::b()", eg.doTestX2());
AddTestCase("triple implements", "x3.A::a(),x3.B::b(),x3.C::c()", eg.doTestX3());
AddTestCase("quadruple implements", "x4.A::a(),x4.B::b(),x4.C::c(),x4.D::d()", eg.doTestX4());

AddTestCase("extends single, single implements", "x1.A::a(),y1.B::b()", eg.doTestY1());
AddTestCase("extends double, double implements", "x1.A::a(),y2.B::b(),y2.C::c()", eg.doTestY2());
AddTestCase("extends double, double implements", "x2.A::a(),x2.B::b(),y3.C::c(),y3.D::d()", eg.doTestY3());
AddTestCase("extends triple, single implements", "x3.A::a(),x3.B::b(),x3.C::c(),y4.D::d()", eg.doTestY4());

test();       // leave this alone.  this executes the test cases and
              // displays results.
