/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


import PublicClass.*;


var SECTION = "Definitions\Ext";                    // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                     // Version of JavaScript or ECMA
var TITLE   = "Final Class Extends Public Class Default Methods";       // Provide ECMA section title or a description
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
  
// Can't create an instance because it's not public
// Hence commenting out the lines where the class is initialized.
// var EXTDCLASS = new FinExtPublicClass();
  
  
// Create an array variable which will define the test array to be used
// for the given output.
var arr = new Array(1, 2, 3);


// access default method from a default method of a sub class
AddTestCase( "*** Access default method from default method of sub class ***", 1, 1 );
// AddTestCase( "subSetArray( arr ), subGetArray()", arr, ( subSetArray( arr ), subGetArray() ) );


// access default method from a dynamic method of a sub class
AddTestCase( "*** Acess default method from dynamic method of sub class ***", 1, 1 );
AddTestCase( "dynSubSetArray( arr ), dynSubGetArray()", arr, ( dynSubSetArray( arr ), dynSubGetArray()) );


// access default method from a public method of a sub class
AddTestCase( "*** Access default method from public method of sub class ***", 1, 1 );
AddTestCase( "pubSubSetArray( arr ), pubSubGetArray()", arr, ( pubSubSetArray( arr ), pubSubGetArray()) );


// access default method from a private method of a sub class
AddTestCase( "*** Access default method from private method of sub class ***", 1, 1 );
AddTestCase( "testPrivSubArray( arr )", arr, testPrivSubArray( arr ) );


// access default method from a static method of a sub class
AddTestCase( "*** Access default method from static method of sub class ***", 1, 1 );
AddTestCase( "*** Static Method cannot access any other methods except static methods of the parent class ***", 1, 1 );
// AddTestCase( "statSubSetArray( arr ), statSubGetArray()", arr, ( statSubSetArray( arr ), statSubGetArray() ) );


// access default method from a final method of a sub class
AddTestCase( "*** Access default method from final method of sub class ***", 1, 1 );
AddTestCase( "finSubSetArray( arr ), finSubGetArray()", arr, ( finSubSetArray( arr ), finSubGetArray() ) );


// access default method from a virtual method of a sub class
AddTestCase( "*** Access default method from virtual method of sub class ***", 1, 1 );
AddTestCase( "virSubSetArray( arr ), virSubSetArray()", arr, ( virSubSetArray( arr ), virSubGetArray() ) );


// access default method from a public dynamic method of a sub class
AddTestCase( "*** Acess default method from public dynamic method of sub class ***", 1, 1 );
AddTestCase( "pubDynSubSetArray( arr ), pubDynSubGetArray()", arr, ( pubDynSubSetArray( arr ), pubDynSubGetArray()) );


// access default method from a public static method of a sub class
AddTestCase( "*** Access default method from public static method of sub class ***", 1, 1 );
AddTestCase( "*** Static Method cannot access any other methods except static methods of the parent class ***", 1, 1 );
// AddTestCase( "pubStatSubSetArray( arr ), pubStatSubGetArray()", arr, ( pubStatSubSetArray( arr ), pubStatSubGetArray() ) );


// access default method from a public final method of a sub class
AddTestCase( "*** Access default method from public final method of sub class ***", 1, 1 );
AddTestCase( "pubFinSubSetArray( arr ), pubFinSubGetArray()", arr, ( pubFinSubSetArray( arr ), pubFinSubGetArray() ) );


// access default method from a public virtual method of a sub class
AddTestCase( "*** Access default method from public virtual method of sub class ***", 1, 1 );
AddTestCase( "pubVirSubSetArray( arr ), pubVirSubSetArray()", arr, ( pubVirSubSetArray( arr ), pubVirSubGetArray() ) );


// access default method from a final private method of a sub class
AddTestCase( "*** Access default method from final private method of sub class ***", 1, 1 );
AddTestCase( "testPrivFinSubArray( arr )", arr, testPrivFinSubArray( arr ) );


// access default method from a final static method of a sub class
AddTestCase( "*** Access default method from final static method of sub class ***", 1, 1 );
AddTestCase( "*** Static Method cannot access any other methods except static methods of the parent class ***", 1, 1 );
// AddTestCase( "finStatSubSetArray( arr ), finStatSubGetArray()", arr, ( finStatSubSetArray( arr ), finStatSubGetArray() ) );


// access default method from a private static method of a sub class
AddTestCase( "*** Access default method from private static method of sub class ***", 1, 1 );
AddTestCase( "*** Static Method cannot access any other methods except static methods of the parent class ***", 1, 1 );
// AddTestCase( "testPrivStatSubArray( arr )", arr, testPrivStatSubArray( arr ) );


// access default method from a private virtual method of a sub class
AddTestCase( "*** Access default method from private virtual method of sub class ***", 1, 1 );
AddTestCase( "testPrivVirSubArray( arr )", arr, testPrivVirSubArray( arr ) );



// access default property from outside the class
AddTestCase( "*** Access default property from outside the class ***", 1, 1 );
AddTestCase( "array = arr", arr, (array = arr, array) );


// access default property from a default method of a sub class
AddTestCase( "*** Access default property from default method of sub class ***", 1, 1 );
AddTestCase( "subSetDPArray( arr ), subGetDPArray()", arr, ( subSetDPArray( arr ), subGetDPArray() ) );


// access default property from a dynamic method of a sub class
AddTestCase( "*** Access default property from dynamic method of sub class ***", 1, 1 );
AddTestCase( "dynSubSetDPArray( arr ), dynSubGetDPArray()", arr, ( dynSubSetDPArray( arr ), dynSubGetDPArray() ) );


// access default property from a public method of a sub class
AddTestCase( "*** Access default property from public method of sub class ***", 1, 1 );
AddTestCase( "pubSubSetDPArray( arr ), pubSubGetDPArray()", arr, ( pubSubSetDPArray( arr ), pubSubGetDPArray() ) );


// access default property from a private method of a sub class
AddTestCase( "*** Access default property from private method of sub class ***", 1, 1 );
AddTestCase( "testPrivSubDPArray( arr )", arr, testPrivSubDPArray( arr ) );


// access default property from a static method of a sub class
AddTestCase( "*** Access default property from static method of sub class ***", 1, 1 );
AddTestCase( "statSubSetDPArray( arr ), statSubGetDPArray()", arr, ( statSubSetDPArray( arr ), statSubGetDPArray() ) );


// access default property from a final method of a sub class
AddTestCase( "*** Access default property from final method of sub class ***", 1, 1 );
AddTestCase( "finSubSetDPArray( arr ), finSubGetDPArray()", arr, ( finSubSetDPArray( arr ), finSubGetDPArray() ) );


// access default property from a private virtual method of a sub class
AddTestCase( "*** Access default property from private virtual method of sub class ***", 1, 1 );
AddTestCase( "virSubSetDPArray( arr ), virSubGetDPArray()", arr, ( virSubSetDPArray( arr ), virSubGetDPArray() ) );


// access default property from a public static method of a sub class
AddTestCase( "*** Access default property from public static method of sub class ***", 1, 1 );
AddTestCase( "pubStatSubSetDPArray( arr ), pubStatSubGetDPArray()", arr, ( pubStatSubSetDPArray( arr ), pubStatSubGetDPArray() ) );


// access default property from a private static method of a sub class
AddTestCase( "*** Access default property from private static method of sub class ***", 1, 1 );
AddTestCase( "testPrivStatSubDPArray( arr )", arr, testPrivStatSubDPArray( arr ) );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
