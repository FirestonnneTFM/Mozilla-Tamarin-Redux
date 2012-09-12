/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "Qualified references with AssignmentExpression";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



import ns.*;
var f:foo = new foo();

 AddTestCase("f.N2::n2='3'", 3, f.N2::n2);
 AddTestCase("f.1::v3='3'", 3, f.N1::v3);
 AddTestCase("f.v3='5'", 5, f.v3);

 AddTestCase("f.N2::n3=v3", 5, f.N2::n3);
 AddTestCase("f.N2::n3=v3; f.N2::['n3']", 5, f.N2::['n3']);
 AddTestCase("f.N2::n4=o[holder]", 4, f.N2::n4);
 
 AddTestCase("N4 = N3; f.N3::v1 =5; f.N4::v1", 5, f.N4::v1);
 AddTestCase("N4 = N3; f.N3::['v2'] =5; f.N4::v2", 5, f.N4::v2);
 
 test();
