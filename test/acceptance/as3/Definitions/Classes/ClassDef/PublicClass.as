/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import PublicClassPackage.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Access Class Properties & Methods";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



var arr = new Array(1,2,3);
var arr2 = new Array(3,2,1);
var Obj = new PublicClass();
var d = new Date(0);
var d2 = new Date(1);
var f = new Function();
var str = "Test";
var ob = new Object();
var foo;


// ********************************************
// Basic Constructor tests
// ********************************************
AddTestCase( "*** No param constructor test ***", 1, 1 );
AddTestCase( "var foo = new PublicClass(), foo.constructorCount", 2, (foo = new PublicClass(), PublicClass.constructorCount) );
AddTestCase( "*** No param constructor test ***", 1, 1 );
AddTestCase( "var foo = new PublicClass, foo.constructorCount", 3, (foo = new PublicClass, PublicClass.constructorCount) );

// ********************************************
// Access Default method
// ********************************************
AddTestCase( "*** Access default method of a class ***", 1, 1 );
AddTestCase( "Obj.setArray(arr), Obj.getArray()", arr, Obj.testGetSetArray(arr) );

// ********************************************
// Access Default virtual method
// ********************************************
AddTestCase( "*** Access default virtual method of a class ***", 1, 1 );
AddTestCase( "Obj.setVirtArray(arr), Obj.getVirtArray()", arr2, Obj.testGetSetVirtualArray(arr2) );

// ********************************************
// Access Default Static method
// ********************************************
AddTestCase( "*** Access static method of a class ***", 1, 1 );
AddTestCase( "Obj.setStatFunction(f), Obj.getStatFunction()", f, Obj.testGetSetStatFunction(f) );

// ********************************************
// Access Default Final method
// ********************************************
AddTestCase( "*** Access final method of a class ***", 1, 1 );
AddTestCase( "Obj.setFinNumber(10), Obj.getFinNumber()", 10, Obj.testGetSetFinNumber(10) );

// ********************************************
// Access Internal method
// ********************************************
AddTestCase( "*** Access internal method of a class ***", 1, 1 );
AddTestCase( "Obj.setInternalArray(arr), Obj.getInternalArray()", arr, Obj.testGetSetInternalArray(arr) );

// ********************************************
// Access Internal virtual method
// ********************************************
AddTestCase( "*** Access internal virtual method of a class ***", 1, 1 );
AddTestCase( "Obj.setInternalVirtualArray(arr), Obj.getInternalVirtualArray()", arr2, Obj.testGetSetInternalVirtualArray(arr2) );


// ********************************************
// Access Internal Static method
// ********************************************
AddTestCase( "*** Access internal static method of a class ***", 1, 1 );
AddTestCase( "Obj.setInternalStatFunction(f), Obj.getInternalStatFunction()", f, Obj.testGetSetInternalStatFunction(f) );


// ********************************************
// Access Internal Final method
// ********************************************
AddTestCase( "*** Access internal final method of a class ***", 1, 1 );
AddTestCase( "Obj.setInternalFinNumber(10), Obj.getInternalFinNumber()", 10, Obj.testGetSetInternalFinNumber(10) );

// ********************************************
// Access Private method
// ********************************************
AddTestCase( "*** Access private method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivDate(date), Obj.getPrivDate()", d.getFullYear(), Obj.testGetSetPrivDate(d).getFullYear() );

// ********************************************
// Access Private virtual method
// ********************************************
AddTestCase( "*** Access private virtual method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivVirtualDate(date), Obj.getPrivVirtualDate()", d2.getFullYear(), Obj.testGetSetPrivVirtualDate(d2).getFullYear() );

// ********************************************
// Access Private Static method
// ********************************************
AddTestCase( "*** Access private static method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivStatString(s), Obj.getPrivStatString", str, Obj.testGetSetPrivStatString(str) );

// ********************************************
// Access Private Final method
// ********************************************
AddTestCase( "*** Access private final method of a class ***", 1, 1 );
AddTestCase( "Obj.setPrivFinalString(s), Obj.getPrivFinalString", str, Obj.testGetSetPrivFinalString(str) );

// ********************************************
// Access Public method
// ********************************************
AddTestCase( "*** Access public method of a class ***", 1, 1 );
AddTestCase( "Obj.setPubBoolean(b), Obj.getPubBoolean()", true, (Obj.setPubBoolean(true), Obj.getPubBoolean()) );

// ********************************************
// Access Public virtual method
// ********************************************
AddTestCase( "*** Access public virtual method of a class ***", 1, 1 );
AddTestCase( "Obj.setPubVirtualBoolean(b), Obj.getPubVirtualBoolean()", false, (Obj.setPubBoolean(false), Obj.getPubBoolean()) );

// ********************************************
// Access Public Static method
// ********************************************
AddTestCase( "*** Access public static method of a class ***", 1, 1 );
AddTestCase( "PublicClass.setPubStatObject(ob), PublicClass.getPubStatObject()", ob, (PublicClass.setPubStatObject(ob), PublicClass.getPubStatObject()) );

// ********************************************
// Access Public Final method
// ********************************************
AddTestCase( "*** Access public final method of a class ***", 1, 1 );
AddTestCase( "Obj.setPubFinArray(arr), Obj.getPubFinArray()", arr, (Obj.setPubFinArray(arr), Obj.getPubFinArray()) );





// ********************************************
// Access Public property
// ********************************************
AddTestCase( "*** Access public property of a class ***", 1, 1 );
AddTestCase( "Obj.pubBoolean = true, Obj.pubBoolean", true, (Obj.pubBoolean = true, Obj.pubBoolean) );

// ********************************************
// Access Public Static property
// ********************************************
AddTestCase( "*** Access public satic property of a class ***", 1, 1 );
AddTestCase( "PublicClass.pubStatObject = ob, PublicClass.pubStatObject", ob, (PublicClass.pubStatObject = ob, PublicClass.pubStatObject) );

// ********************************************
// Access Public Final property
// ********************************************
AddTestCase( "*** Access public final property of a class ***", 1, 1 );
AddTestCase( "Obj.pubFinArray = arr, Obj.pubFinArray", arr, (Obj.pubFinArray = arr, Obj.pubFinArray) );

// ********************************************
// Access Public Final Static property
// ********************************************
AddTestCase( "*** Access public final static property of a class ***", 1, 1 );
AddTestCase( "PublicClass.pubFinalStaticNumber = 10, PublicClass.pubFinalStaticNumber", 10, (PublicClass.pubFinalStaticNumber = 10, PublicClass.pubFinalStaticNumber) );



test();       // leave this alone.  this executes the test cases and
              // displays results.
