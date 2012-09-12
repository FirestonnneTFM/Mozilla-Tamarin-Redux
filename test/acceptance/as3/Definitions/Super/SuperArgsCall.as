/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "8.6.1 Constructor Methods";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Implicit SuperStatement";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
import SuperArgsCall.*

var sac1 = new SuperArgsCall("one")
var sac2 = new SuperArgsCall("two")

AddTestCase( "test super(object).method(args), one self", "base f(one)", sac1.test0() );
AddTestCase( "test super(object).method(args), two self", "base f(two)", sac2.test0() );

AddTestCase( "test super(object).method(args), one other", "base f(two)", sac1.test1(sac2) );
AddTestCase( "test super(object).method(args), two other", "base f(one)", sac2.test1(sac1) );

//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
