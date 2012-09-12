/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import InterfaceAsType.*;

var eg = new TypeTest();
AddTestCase("class as interface, call via interface", "x.A::a()", eg.doCallXViaA());
AddTestCase("class as interface, call via interface", "x.B::b()", eg.doCallXViaB());
AddTestCase("class passed as interface, call via args", "x.A::a(),x.B::b()", eg.doCallXViaArgs());
AddTestCase("class returned as interface, call via result", "x.A::a(),x.B::b()", eg.doCallXViaReturn());

AddTestCase("class as extended interface, call via interface", "y.A::a()", eg.doCallYViaA());
AddTestCase("class as extended interface, call via interface", "y.B::b()", eg.doCallYViaB());
AddTestCase("class as extended interface, call via extended interface", "y.A::a(),y.B::b()", eg.doCallYViaC());
AddTestCase("class passed as extended interface, call via args", "y.A::a(),y.B::b()", eg.doCallYViaArgs());
AddTestCase("class passed as interface, call via extended args", "y.A::a(),y.B::b()", eg.doCallYViaArgC());
AddTestCase("class returned as extended interface, call via result", "y.A::a(),y.B::b()", eg.doCallYViaReturn());
AddTestCase("class returned as interface, call via extended result", "y.A::a(),y.B::b()", eg.doCallYViaReturnC());

test();       // leave this alone.  this executes the test cases and
              // displays results.
