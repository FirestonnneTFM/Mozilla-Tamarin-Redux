/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */



import DefaultClass.*;

var SECTION = "Definitions";                // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                    // Version of JavaScript or ECMA
var TITLE   = "final Class Extends Default Class";      // Provide ECMA section title or a description
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

var EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(10, 15, 20, 25, 30);
  
AddTestCase( "*** Access final method from final method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testFinSubArray(arr)", arr, (EXTDCLASS.testFinSubArray(arr)));


// ********************************************
// access final method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(1, 2, 3);
AddTestCase( "*** Access final method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubGetSetArray(arr)", arr, (EXTDCLASS.testSubGetSetArray(arr)) );



// ********************************************
// access final method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(4, 5, 6);
AddTestCase( "*** Access final method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );


// ********************************************
// access final method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(10, 50);
AddTestCase( "*** Access final method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );


// ********************************************
// access final method from a final
// method of a sub class
//
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(4, 5, 6);
AddTestCase( "*** Access final method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testFinSubArray(arr)", arr, (EXTDCLASS.testFinSubArray(arr)) );



// ********************************************
// access final method from a virtual
// method of a sub class
// ********************************************

AddTestCase( "access 'final' method from 'virtual' method of sub class", arr,
              EXTDCLASS.testVirtSubArray(arr) );

// ********************************************
// access final property from outside
// the class
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
AddTestCase( "*** Access final from outside the class ***", 1, 1 );
//AddTestCase( "EXTDCLASS.finArray = arr", arr, (EXTDCLASS.finArray = arr, EXTDCLASS.finArray) );

// ********************************************
// access final property from
// default method in sub class
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
var arr = new Array(10, 20, 30);
AddTestCase( "*** Access final property from default method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubGetSetDPArray(arr)", arr, (EXTDCLASS.testSubGetSetDPArray(arr)) );

// ********************************************
// access final property from
// public method in sub class
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
AddTestCase( "*** Access final property from public method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()", arr, (EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()) );


// ********************************************
// access final property from
// private method in sub class
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
AddTestCase( "*** Access final property from private method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubPrivDPArray(arr)", arr, (EXTDCLASS.testSubPrivDPArray(arr)) );

// ********************************************
// access final property from
// final method in sub class
// ********************************************

EXTDCLASS = new DynExtDefaultClassFin();
AddTestCase( "*** Access final property from final method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubFinDPArray(arr)", arr, (EXTDCLASS.testSubFinDPArray(arr)) );

// ********************************************
// access final property from
// virtual method in sub class
// ********************************************

DYNEXTDCLASS = new DynExtDefaultClassFin();
AddTestCase( "access 'final' property from 'virtual' method of sub class", arr,
                (EXTDCLASS.testVirtSubDPArray(arr)) );

test();       // leave this alone.  this executes the test cases and
              // displays results.
  
