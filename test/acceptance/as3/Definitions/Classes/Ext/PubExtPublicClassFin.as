/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


import PublicClass.*;

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";  // Version of JavaScript or ECMA
var TITLE   = "Extend Public Class";       // Provide ECMA section title or a description
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

  
// ********************************************
// access final method from a default
// method of a sub class
//
// ********************************************

var arr = [1,2,3];

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final method from default method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testSubSetArray(arr)", arr, PUBEXTDCLASS.testSubSetArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access final method from a public
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final method from public method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.pubSubSetArray(arr), PUBEXTDCLASS.pubSubGetArray()", arr, (PUBEXTDCLASS.pubSubSetArray(arr), PUBEXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access final method from a private
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final method from private method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testPrivSubArray(arr)", arr, PUBEXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access final method from a final
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final method from final method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testFinSubSetArray(arr)", arr, PUBEXTDCLASS.testFinSubSetArray(arr) );



// ********************************************
// access final property from
// default method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final property from method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testSubSetDPArray(arr)", arr, PUBEXTDCLASS.testSubSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access final property from
// public method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final property from public method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.pubSubSetDPArray(arr), PUBEXTDCLASS.pubSubGetDPArray()", arr, (PUBEXTDCLASS.pubSubSetDPArray(arr), PUBEXTDCLASS.pubSubGetDPArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access final property from
// private method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final property from private method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testPrivSubSetDPArray(arr)", arr, PUBEXTDCLASS.testPrivSubSetDPArray(arr) );



// ********************************************
// access final property from
// final method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtPublicClassFin();
AddTestCase( "*** Access final property from final method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testFinSubSetDPArray(arr)", arr, PUBEXTDCLASS.testFinSubSetDPArray(arr) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
