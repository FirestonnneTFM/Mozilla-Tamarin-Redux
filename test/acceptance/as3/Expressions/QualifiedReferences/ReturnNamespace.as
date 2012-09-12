/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "qualified references";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


 
import ns.*;

var b:B = new B();
var a:A = new A();


AddTestCase("Ref to NS returned from another class", "making my day", b.befriendAnA(a));


test();       // leave this alone.  this executes the test cases and
              // displays results.
