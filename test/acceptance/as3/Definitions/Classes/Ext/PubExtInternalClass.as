/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import InternalClass.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Extend Default Class";  // Provide ECMA section title or a description
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

// ************************************
// public class extends <empty> class
// ************************************

var arr = new Array(1,2,3);

// ********************************************
// access default method from outside of class
// ********************************************

// this should give a compiler error
PUBEXTDCLASS = new PubExtInternalClass();

//We cannot access the default method from outside the class
//AddTestCase( "PUBEXTDCLASS.setArray(arr), PUBEXTDCLASS.getArray()", arr, (PUBEXTDCLASS.setArray(arr), PUBEXTDCLASS.getArray()) );


// ********************************************
// access default method from a default
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default method from default method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.subSetArray(arr), PUBEXTDCLASS.subGetArray()", arr, PUBEXTDCLASS.testSubGetSetArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access default method from a public
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default method from public method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.pubSubSetArray(arr), PUBEXTDCLASS.pubSubGetArray()", arr, (PUBEXTDCLASS.pubSubSetArray(arr), PUBEXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default method from a private
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default method from private method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.testPrivSubArray(arr)", arr, PUBEXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default method from a final
// method of a sub class
//
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default method from default method of sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.finSubSetArray(arr), PUBEXTDCLASS.finSubGetArray()", arr, PUBEXTDCLASS.testFinSubArray(arr) );

// ********************************************
// access default property from outside
// the class
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default property from outside the class ***", 1, 1 );
//AddTestCase( "PUBEXTDCLASS.array = arr", arr, (PUBEXTDCLASS.array = arr, PUBEXTDCLASS.array) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// default method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default property from method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.subSetDPArray(arr), PUBEXTDCLASS.subGetDPArray()", arr, PUBEXTDCLASS.testSubGetSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// public method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default property from public method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.pubSubSetDPArray(arr), PUBEXTDCLASS.pubSubGetDPArray()", arr, (PUBEXTDCLASS.pubSubSetDPArray(arr), PUBEXTDCLASS.pubSubGetDPArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// private method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default property from private method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.privSubSetDPArray(arr), PUBEXTDCLASS.privSubGetDPArray()", arr, PUBEXTDCLASS.testPrivSubDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// final method in sub class
// ********************************************

PUBEXTDCLASS = new PubExtInternalClass();
AddTestCase( "*** Access default property from final method in sub class ***", 1, 1 );
AddTestCase( "PUBEXTDCLASS.finSubSetDPArray(arr), PUBEXTDCLASS.finSubGetDPArray()", arr, PUBEXTDCLASS.testFinSubDPArray(arr) );




test();       // leave this alone.  this executes the test cases and
              // displays results.
