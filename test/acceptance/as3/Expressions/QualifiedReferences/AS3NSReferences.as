/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "Namespace values";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


import ns.*;
var f:foo = new foo();

AddTestCase("f.N1::A()", "www.ecma-international.org", f.N1::A());
AddTestCase("f.N3::flower1", "Gerbera Daisy", f.N3::flower1);
AddTestCase("f.N4::flower2", "Rose", f.N4::flower2);

test();
