/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Extend Public Class Implement Default interface";       // Provide ECMA section title or a description
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

import PublicClass.*;

var PUBEXTDYNIMPLDEFDEFPUB = new PubExtPublicImplDefDefPub();

// *******************************************
// define default method from interface as a
// public method in the sub class
// *******************************************

// Should give an error

AddTestCase( "*** default(<empty>) method implemented interface ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.testGetBoolean(false)", false, PUBEXTDYNIMPLDEFDEFPUB.testGetBoolean(false) );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.testGetBoolean(true)", true, PUBEXTDYNIMPLDEFDEFPUB.testGetBoolean(true) );

// *******************************************
// define public method from interface as a
// public method in the sub class
// *******************************************

AddTestCase( "*** public method implemented interface ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.testGetPubBoolean(false)", false, PUBEXTDYNIMPLDEFDEFPUB.testGetPubBoolean(false) );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.testGetPubBoolean(true)", true, PUBEXTDYNIMPLDEFDEFPUB.testGetPubBoolean(true) );

// *******************************************
// define default method from interface 2 as a
// public method in the sub class
// *******************************************

//Should give an error

AddTestCase( "*** default(<empty>) method implemented interface 2 ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.testGetSetNumber(420)", 420, PUBEXTDYNIMPLDEFDEFPUB.testGetSetNumber(420) );

// *******************************************
// define public method from interface 2 as a
// public method in the sub class
// *******************************************

AddTestCase( "*** public method implemented interface 2 ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFDEFPUB.setPubNumber(14), PUBEXTDYNIMPLDEFDEFPUB.iGetPubNumber()", 14, (PUBEXTDYNIMPLDEFDEFPUB.setPubNumber(14), PUBEXTDYNIMPLDEFDEFPUB.iGetPubNumber()) );

//*******************************************
// access from outside of class
//*******************************************

var EXTDCLASS = new PubExtPublicImplDefDefPub();

arr = new Array(1, 2, 3);

AddTestCase( "*** access public methods and properties from outside of class ***", 1, 1 );
AddTestCase( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );

// ********************************************
// access public method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtPublicImplDefDefPub();
AddTestCase( "*** Access public method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testGetSubArray(arr)", arr, EXTDCLASS.testGetSubArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access public method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtPublicImplDefDefPub();
AddTestCase( "*** Access public method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtPublicImplDefDefPub();
AddTestCase( "*** Access public method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here


test();       // leave this alone.  this executes the test cases and
              // displays results.
