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

AddTestCase( "function getTeam1(){return Baseball::teamName}", "Giants", f.getTeam1() );
AddTestCase( "function getTeam2(){return Basketball::teamName}", "Kings", f.getTeam2() );
AddTestCase( "function getTeam3(){return Hockey::teamName}", "Sharks", f.getTeam3() );


test();       // leave this alone.  this executes the test cases and
              // displays results.
