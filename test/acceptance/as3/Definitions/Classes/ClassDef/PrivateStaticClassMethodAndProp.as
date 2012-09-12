/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 
import PrivateStaticClassMethodAndProp.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Access Class Properties & Methods";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



var arr = new Array(1,2,3);

var Obj = new AccPrivStatClassMAndP();

var d = new Date();

var f = new Function();

var str = "Test";

var ob = new Object();


// ********************************************
// access default method
//
// ********************************************

AddTestCase( "*** Access default method of a static class ***", 1, 1 );
AddTestCase( "Obj.setArray(arr), Obj.getArray()", arr, Obj.testGetSetArray(arr) );


// ********************************************
// access private method
//
// ********************************************

// TODO: Need to modify the test to only create the date as Date(0) and just check the year
// AddTestCase( "*** Access private method of a static class ***", 1, 1 );
// AddTestCase( "Obj.setPrivDate(date), Obj.getPrivDate()", d, Obj.testGetSetPrivDate(d) );


// ********************************************
// access public method
//
// ********************************************

AddTestCase( "*** Access public method of a static class ***", 1, 1 );
AddTestCase( "Obj.setPubBoolean(b), Obj.getPubBoolean()", true, Obj.testGetSetPubBoolean(true) );


// ********************************************
// access static method
//
// ********************************************

AddTestCase( "*** Access static method of a static class ***", 1, 1 );
AddTestCase( "Obj.setStatFunction(f), Obj.getStatFunction()", f, Obj.testGetSetStatFunction(f) );

// ********************************************
// access private static method
// ********************************************

AddTestCase( "*** Access private static method of a static class ***", 1, 1 );
AddTestCase( "Obj.setPrivStatString(s), Obj.getPrivStatString", str, Obj.testGetSetPrivStatString(str) );


// ********************************************
// access public static method
// ********************************************

AddTestCase( "*** Access public static method of a static class ***", 1, 1 );
AddTestCase( "Obj.setPubStatObject(ob), Obj.getPubStatObject()", ob, Obj.testGetSetPubStatObject(ob) );


// ********************************************
// access final method
// ********************************************

AddTestCase( "*** Access final method of a static class ***", 1, 1 );
AddTestCase( "Obj.setFinNumber(10), Obj.getFinNumber()", 10, Obj.testGetSetFinNumber(10) );


// ********************************************
// access public final method
// ********************************************

AddTestCase( "*** Access public final method of a static class ***", 1, 1 );
AddTestCase( "Obj.setPubFinArray(arr), Obj.getPubFinArray()", arr, Obj.testGetSetPubArray(arr) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
