/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import PublicStaticFinalDynamicClassMethodAndProp.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Access Class Properties & Methods";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



var arr = new Array(1,2,3);

var Obj = new AccPubStatFinDynClassMAndP();

var d = new Date(0);

var f = new Function();

var str = "Test";

var ob = new Object();


// ********************************************
// access default method
//
// ********************************************

AddTestCase( "*** Access default method of a class ***", 1, 1 );
AddTestCase( "Obj.setArray(arr), Obj.getArray()", arr, Obj.testGetSetArray(arr) );


// ********************************************
// access private method
//
// ********************************************

AddTestCase( "*** Access private method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivDate(date), Obj.getPrivDate()", d.getFullYear(), Obj.testGetSetPrivDate(d).getFullYear() );


// ********************************************
// access public method
//
// ********************************************

AddTestCase( "*** Access public method of a class ***", 1, 1 );
AddTestCase( "Obj.setPubBoolean(b), Obj.getPubBoolean()", true, (Obj.setPubBoolean(true), Obj.getPubBoolean()) );


// ********************************************
// access static method
//
// ********************************************

AddTestCase( "*** Access static method of a class ***", 1, 1 );
AddTestCase( "Obj.setStatFunction(f), Obj.getStatFunction()", f, Obj.testGetSetStatFunction(f) );

// ********************************************
// access private static method
// ********************************************

AddTestCase( "*** Access private static method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivStatString(s), Obj.getPrivStatString", str, Obj.testGetSetPrivStatString(str) );


// ********************************************
// access public static method
// ********************************************

AddTestCase( "*** Access public static method of a class ***", 1, 1 );
AddTestCase( "AccPubStatFinDynClassMAndP.setPubStatObject(ob), AccPubStatFinDynClassMAndP.getPubStatObject()", ob,
    (AccPubStatFinDynClassMAndP.setPubStatObject(ob), AccPubStatFinDynClassMAndP.getPubStatObject()) );


// ********************************************
// access final method
// ********************************************

AddTestCase( "*** Access final method of a class ***", 1, 1 );
AddTestCase( "Obj.setFinNumber(10), Obj.getFinNumber()", 10, Obj.testGetSetFinNumber(10) );


// ********************************************
// access public final method
// ********************************************

AddTestCase( "*** Access public final method of a class ***", 1, 1 );
AddTestCase( "Obj.setPubFinArray(arr), Obj.getPubFinArray()", arr, (Obj.setPubFinArray(arr), Obj.getPubFinArray()) );


// ********************************************
// access public property
// ********************************************

AddTestCase( "*** Access public property of a class ***", 1, 1 );
AddTestCase( "Obj.pubBoolean = true, Obj.pubBoolean", true, (Obj.pubBoolean = true, Obj.pubBoolean) );

// ********************************************
// access public static property
// ********************************************

AddTestCase( "*** Access public satic property of a class ***", 1, 1 );
AddTestCase( "AccPubStatFinDynClassMAndP.pubStatObject = ob, AccPubStatFinDynClassMAndP.pubStatObject", ob, (AccPubStatFinDynClassMAndP.pubStatObject = ob, AccPubStatFinDynClassMAndP.pubStatObject) );


// ********************************************
// access public final property
// ********************************************

AddTestCase( "*** Access public final property of a class ***", 1, 1 );
AddTestCase( "Obj.pubFinArray = arr, Obj.pubFinArray", arr, (Obj.pubFinArray = arr, Obj.pubFinArray) );



test();       // leave this alone.  this executes the test cases and
              // displays results.
