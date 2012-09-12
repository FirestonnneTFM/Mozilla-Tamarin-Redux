/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Super Behavior Tests";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
import SuperExprChainAccess.*

var seca = new SuperExprChainAccess();

AddTestCase( "direct call to f()", "derived f()", seca.callf1() );
AddTestCase( "super call to f()", "middle1 f()", seca.callf2() );

AddTestCase( "direct call to g()", "derived g()", seca.callg1() );
AddTestCase( "super chain call to g()", "base g()", seca.callg2() );

AddTestCase( "direct call to h()", "middle2 h()", seca.callh1() );
AddTestCase( "super chain call to h()", "middle2 h()", seca.callh2() );
AddTestCase( "super parent call to h()", "middle1 h()", seca.callh3() );

AddTestCase( "direct call to i()", "middle2 i()", seca.calli1() );
AddTestCase( "super chain call to i()", "middle2 i()", seca.calli2() );
AddTestCase( "super parent call to i()", "base i()", seca.calli3() );

//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
