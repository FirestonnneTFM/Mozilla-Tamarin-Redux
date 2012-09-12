/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "qualified references";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


 
import ns.*;
 
var f:foo = new foo();

AddTestCase( "f.Baseball::getTeam()", "Giants", f.Baseball::getTeam() );


AddTestCase( "f.Hockey::getTeam()", "Sharks", f.Hockey::getTeam() );

use namespace Basketball;
AddTestCase( "use namespace Basketball, f.getTeam()", "Kings", f.getTeam() );


test();       // leave this alone.  this executes the test cases and
              // displays results.
