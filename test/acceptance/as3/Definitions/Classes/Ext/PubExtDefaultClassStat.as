/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


// imports must be first statement
import DefaultClass.*;

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


arr = new Array(1, 2, 3);

//*******************************************
// access static method of parent class
// from outside of class
//*******************************************

//AddTestCase( "Access static method of parent class from outside of class", arr,(PubExtDefaultClassStat.setStatArray(arr),PubExtDefaultClassStat.statArray) );


// ********************************************
// access static method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.subSetArray(arr), EXTDCLASS.subGetArray()", arr, EXTDCLASS.testSubGetSetArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access static method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static method from a final
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "access static method from final method of sub class", arr, EXTDCLASS.testFinSubArray(arr) );

// ********************************************
// access static method from a static
// method of a sub class
//
// ********************************************

AddTestCase( "*** Access static method from static method of sub class ***", 1, 1 );
AddTestCase( "PubExtDefaultClassStat.testStatSubArray(arr)", arr, PubExtDefaultClassStat.testStatSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static method from a public static
// method of a sub class
//
// ********************************************

AddTestCase( "*** Access static method from public static method of sub class ***", 1, 1 );
AddTestCase( "PubExtDefaultClassStat.pubStatSubSetArray(arr), PubExtDefaultClassStat.pubStatSubGetArray()", arr,
             (PubExtDefaultClassStat.pubStatSubSetArray(arr), PubExtDefaultClassStat.pubStatSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static method from a private static
// method of a sub class
//
// ********************************************

var EXTDEFAULTCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static method from private static method of sub class ***", 1, 1 );
AddTestCase( "EXTDEFAULTCLASS.testPrivStatSubArray(arr)", arr,
              EXTDEFAULTCLASS.testPrivStatSubArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static property from
// default method in sub class
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static property from default method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.subSetDPArray(arr), EXTDCLASS.subGetDPArray()", arr, EXTDCLASS.testSubGetSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access static property from
// public method in sub class
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static property from public method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()", arr, (EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static property from
// private method in sub class
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static property from private method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.privSubSetDPArray(arr), EXTDCLASS.privSubGetDPArray()", arr, EXTDCLASS.testPrivSubDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static property from
// static method in sub class
// ********************************************

AddTestCase( "*** Access static property from static method in sub class ***", 1, 1 );
AddTestCase( "PubExtDefaultClassStat.testStatSubPArray(arr)", arr, PubExtDefaultClassStat.testStatSubPArray(arr) );

// ********************************************
// access static property from
// public static method in sub class
// ********************************************

AddTestCase( "*** Access static property from public static method in sub class ***", 1, 1 );
AddTestCase( "PubExtDefaultClassStat.pubStatSubSetSPArray(arr), PubExtDefaultClassStat.pubStatSubGetSPArray()", arr,
             (PubExtDefaultClassStat.pubStatSubSetSPArray(arr), PubExtDefaultClassStat.pubStatSubGetSPArray()) );



// ********************************************
// access static property from
// private static method in sub class
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static property from private static method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivStatSubPArray(arr)", arr,
              EXTDCLASS.testPrivStatSubPArray(arr));

// <TODO>  fill in the rest of the cases here

// ********************************************
// access static property from
// final method in sub class
// ********************************************

EXTDCLASS = new PubExtDefaultClassStat();
AddTestCase( "*** Access static property from final method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.finSubSetDPArray(arr), EXTDCLASS.finSubGetDPArray()", arr, EXTDCLASS.testFinSubDPArray(arr) );

test();       // leave this alone.  this executes the test cases and
              // displays results.
