/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


import DynamicClass.*;

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";  // Version of JavaScript or ECMA
var TITLE   = "public extend Default Class";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

/**
 * Calls to AddTestCase here. AddTestCase is a function that is defined
 * in shell.js and takes three arguments:
 * - a string representation of what is being tested
 * - the expected result
 * - the actual result
 *
 * For example, a test might look like this:
 *
 * var helloWorld = "Hello World";
 *
 * AddTestCase(
 * "var helloWorld = 'Hello World'",   // description of the test
 *  "Hello World",                     // expected result
 *  helloWorld );                      // actual result
 *
 */

var EXTDCLASS = new PubExtDynamicClassPub();
  
//*******************************************
// access public method of parent class
// from outside of class
//*******************************************

arr = new Array(1, 2, 3);

AddTestCase( "*** access public method of parent class from outside of class ***", 1, 1 );
AddTestCase( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );

// ********************************************
// access public method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubGetSetArray(arr)", arr, EXTDCLASS.testSubGetSetArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access public method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public method from a final
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testFinSubArray(arr)", arr, EXTDCLASS.testFinSubArray(arr) );

// ********************************************
// access public property from outside
// the class
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public property from outside the class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubArray = arr", arr, (EXTDCLASS.pubArray = arr, EXTDCLASS.pubArray) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public property from
// default method in sub class
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public property from default method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubGetSetDPArray(arr)", arr, EXTDCLASS.testSubGetSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public property from
// public method in sub class
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public property from public method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()", arr, (EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public property from
// private method in sub class
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public property from private method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubDPArray(arr)", arr, EXTDCLASS.testPrivSubDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public property from
// final method in sub class
// ********************************************

EXTDCLASS = new PubExtDynamicClassPub();
AddTestCase( "*** Access public property from default method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testFinSubDPArray(arr)", arr, EXTDCLASS.testFinSubDPArray(arr) );



test();       // leave this alone.  this executes the test cases and
              // displays results.
