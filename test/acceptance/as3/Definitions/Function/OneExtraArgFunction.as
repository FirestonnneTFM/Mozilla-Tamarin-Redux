/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import OneExtraArgFunction.*

function returnRestNoPackage(... rest):Number { return rest.length; }


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Optional Argument test";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

var TESTOBJ = new TestObj();
var TESTOBJ1 = new OneExtraArgFunctionClass();

// Pass a Number argument
// inside class inside package
AddTestCase( "Number TESTOBJ.returnRest()", 1, TESTOBJ.returnRest(10) );

// inside package outside of class
AddTestCase( "Number returnRest()", 1, returnRest(20) );

// outside package inside class
AddTestCase( "Number TESTOBJ1.returnRest()", 1, TESTOBJ1.returnRest(30) );

// outside package and outside class
AddTestCase( "Number returnRestNoPackage()", 1, returnRestNoPackage(40) );


// Pass a String argument
// inside class inside package
AddTestCase( "String TESTOBJ.returnRest()", 1, TESTOBJ.returnRest("Str1") );

// inside package outside of class
AddTestCase( "String returnRest()", 1, returnRest("Str2") );

// outside package inside class
AddTestCase( "String TESTOBJ1.returnRest()", 1, TESTOBJ1.returnRest("Str3") );

// outside package and outside class
AddTestCase( "String returnRestNoPackage()", 1, returnRestNoPackage("Str4") );


// Pass a Boolean argument
// inside class inside package
AddTestCase( "Boolean TESTOBJ.returnRest()", 1, TESTOBJ.returnRest(true) );

// inside package outside of class
AddTestCase( "Boolean returnRest()", 1, returnRest(false) );

// outside package inside class
AddTestCase( "Boolean TESTOBJ1.returnRest()", 1, TESTOBJ1.returnRest(true) );

// outside package and outside class
AddTestCase( "Boolean returnRestNoPackage()", 1, returnRestNoPackage(false) );


// Pass an Object argument
// inside class inside package
AddTestCase( "Object TESTOBJ.returnRest()", 1, TESTOBJ.returnRest(new Object()) );

// inside package outside of class
AddTestCase( "Object returnRest()", 1, returnRest(new Object()) );

// outside package inside class
AddTestCase( "Object TESTOBJ1.returnRest()", 1, TESTOBJ1.returnRest(new Object()) );

// outside package and outside class
AddTestCase( "Object returnRestNoPackage()", 1, returnRestNoPackage(new Object()) );

// Pass an Array argument
// inside class inside package
AddTestCase( "Array TESTOBJ.returnRest()", 1, TESTOBJ.returnRest([10,20,30]) );

// inside package outside of class
AddTestCase( "Array returnRest()", 1, returnRest([10,20,30]) );

// outside package inside class
AddTestCase( "Array TESTOBJ1.returnRest()", 1, TESTOBJ1.returnRest([10,20,30]) );

// outside package and outside class
AddTestCase( "Array returnRestNoPackage()", 1, returnRestNoPackage([10,20,30]) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
