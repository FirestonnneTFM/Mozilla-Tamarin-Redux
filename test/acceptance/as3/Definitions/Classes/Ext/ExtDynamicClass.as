/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Extend Dynamic Class";       // Provide ECMA section title or a description
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

import DynamicClass.*;
  
//**********************************************
// Default Methods and Default properties
//
// call a default Method of an object that
// inherited it from it's dynamic parent class
//**********************************************

//Cannot access default properties/methods outside the package

/*
var EXTDCLASS = new ExtDynamicClass();
var arr = new Array(1, 2, 3);
var date = new Date(0);
var func = new Function();
var math = new Math();
var num = new Number();
var obj = new Object();
var str = new String("test");
var sim = new Simple();

AddTestCase( "*** Default Methods and Default properites ***", 1, 1 );
AddTestCase( "EXTDCLASS.setArray(arr), EXTDCLASS.getArray()", arr, (EXTDCLASS.setArray(arr), EXTDCLASS.getArray()) );
AddTestCase( "EXTDCLASS.setBoolean(true), EXTDCLASS.getBoolean()", true, (EXTDCLASS.setBoolean(true), EXTDCLASS.getBoolean()) );
AddTestCase( "EXTDCLASS.setDate(date), EXTDCLASS.getDate()", date, (EXTDCLASS.setDate(date), EXTDCLASS.getDate()) );
AddTestCase( "EXTDCLASS.setFunction(func), EXTDCLASS.getFunction()", func, (EXTDCLASS.setFunction(func), EXTDCLASS.getFunction()) );
AddTestCase( "EXTDCLASS.setMath(math), EXTDCLASS.getMath()", math, (EXTDCLASS.setMath(math), EXTDCLASS.getMath()) );
AddTestCase( "EXTDCLASS.setNumber(num), EXTDCLASS.getNumber()", num, (EXTDCLASS.setNumber(num), EXTDCLASS.getNumber()) );
AddTestCase( "EXTDCLASS.setObject(obj), EXTDCLASS.getObject()", obj, (EXTDCLASS.setObject(obj), EXTDCLASS.getObject()) );
AddTestCase( "EXTDCLASS.setString(str), EXTDCLASS.getString()", str, (EXTDCLASS.setString(str), EXTDCLASS.getString()) );
AddTestCase( "EXTDCLASS.setSimple(sim), EXTDCLASS.getSimple()", sim, (EXTDCLASS.setSimple(sim), EXTDCLASS.getSimple()) );


// call setAll
arr = new Array( 3, 4, 5 );
date = new Date( 999999999999 );
func = undefined;
math = undefined;
num = new Number( 100 );
obj = undefined;
str = "new test";
sim = undefined;

AddTestCase( "EXTDCLASS.setAll(arr, false, date, func, math, num, obj, str, sim), EXTDCLASS.getBoolean()",
             false,
             (EXTDCLASS.setAll(arr, false, date, func, math, num, obj, str, sim), EXTDCLASS.getBoolean()) );
*/

//*******************************************
// public Methods and public properties
//
// call a public Method of an object that
// inherited it from it's parent class
//*******************************************

var EXTDCLASS = new ExtDynamicClass();

arr = new Array(1, 2, 3);
date = new Date(0);
func = new Function();
//math = new Math();
num = new Number();
obj = new Object();
str = new String("test");
//sim = new Simple();

AddTestCase( "*** Public Methods and Public properites ***", 1, 1 );
AddTestCase( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );
AddTestCase( "EXTDCLASS.setPubBoolean(true), EXTDCLASS.pubBoolean", true, (EXTDCLASS.setPubBoolean(true), EXTDCLASS.pubBoolean) );
//AddTestCase( "EXTDCLASS.setPubDate(date), EXTDCLASS.pubDate", date, (EXTDCLASS.setPubDate(date), EXTDCLASS.pubDate) );
AddTestCase( "EXTDCLASS.setPubFunction(func), EXTDCLASS.pubFunction", func, (EXTDCLASS.setPubFunction(func), EXTDCLASS.pubFunction) );
//AddTestCase( "EXTDCLASS.setPubMath(math), EXTDCLASS.pubMath", math, (EXTDCLASS.setPubMath(math), EXTDCLASS.pubMath) );
AddTestCase( "EXTDCLASS.setPubNumber(num), EXTDCLASS.pubNumber", num, (EXTDCLASS.setPubNumber(num), EXTDCLASS.pubNumber) );
AddTestCase( "EXTDCLASS.setPubObject(obj), EXTDCLASS.pubObject", obj, (EXTDCLASS.setPubObject(obj), EXTDCLASS.pubObject) );
AddTestCase( "EXTDCLASS.setPubString(str), EXTDCLASS.pubString", str, (EXTDCLASS.setPubString(str), EXTDCLASS.pubString) );
//AddTestCase( "EXTDCLASS.setPubSimple(sim), EXTDCLASS.pubSimple", sim, (EXTDCLASS.setPubSimple(sim), EXTDCLASS.pubSimple) );


// ********************************************
// access default method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubSetArray(arr)", arr, EXTDCLASS.testSubSetArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access default method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );


// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// default method in sub class
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default property from method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testSubSetDPArray(arr)", arr, EXTDCLASS.testSubSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// public method in sub class
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default property from public method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()", arr, (EXTDCLASS.pubSubSetDPArray(arr), EXTDCLASS.pubSubGetDPArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access default property from
// private method in sub class
// ********************************************

EXTDCLASS = new ExtDynamicClass();
AddTestCase( "*** Access default property from private method in sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubSetDPArray(arr)", arr, EXTDCLASS.testPrivSubSetDPArray(arr) );

// <TODO>  fill in the rest of the cases here



test();       // leave this alone.  this executes the test cases and
              // displays results.
