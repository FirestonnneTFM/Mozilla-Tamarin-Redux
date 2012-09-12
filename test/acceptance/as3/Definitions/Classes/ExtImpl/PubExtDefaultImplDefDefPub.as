/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Extend Default Class Implement Default interface";       // Provide ECMA section title or a description
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

import DefaultClass.*;

var PUBEXTDEFIMPLDEFDEFPUB = new PubExtDefaultImplDefDefPub();

// *******************************************
// define default method from interface as a
// public method in the sub class
// *******************************************
//var i:DefaultInt=PUBEXTDEFIMPLDEFDEFPUB;
//var j:DefaultIntDef=PUBEXTDEFIMPLDEFDEFPUB;
var k = new PubExtDefaultImplDefDefPubAccessor();
//AddTestCase( "*** default(<empty>) method implemented interface ***", 1, 1 );
//AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setBoolean(false), PUBEXTDEFIMPLDEFDEFPUB.iiGetBoolean()", false, k.acciiGetBoolean() );
//AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setBoolean(true), PUBEXTDEFIMPLDEFDEFPUB.jiGetBoolean()", true, k.accjiGetBoolean());

// *******************************************
// define public method from interface as a
// public method in the sub class
// *******************************************

AddTestCase( "*** public method implemented interface ***", 1, 1 );
AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setPubBoolean(false), PUBEXTDEFIMPLDEFDEFPUB.iGetPubBoolean()", false, (PUBEXTDEFIMPLDEFDEFPUB.setPubBoolean(false), PUBEXTDEFIMPLDEFDEFPUB.iGetPubBoolean()) );
AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setPubBoolean(true), PUBEXTDEFIMPLDEFDEFPUB.iGetPubBoolean()", true, (PUBEXTDEFIMPLDEFDEFPUB.setPubBoolean(true), PUBEXTDEFIMPLDEFDEFPUB.iGetPubBoolean()) );

// *******************************************
// define default method from interface 2 as a
// public method in the sub class
// *******************************************

//AddTestCase( "*** default(<empty>) method implemented interface 2 ***", 1, 1 );
AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setNumber(420), PUBEXTDEFIMPLDEFDEFPUB.iiGetNumber()", 420, k.acciiGetNumber() );
AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setNumber(420), PUBEXTDEFIMPLDEFDEFPUB.jiGetNumber()", 420, k.accjiGetNumber() );
// *******************************************
// define public method from interface 2 as a
// public method in the sub class
// *******************************************

AddTestCase( "*** public method implemented interface 2 ***", 1, 1 );
AddTestCase( "PUBEXTDEFIMPLDEFDEFPUB.setPubNumber(14), PUBEXTDEFIMPLDEFDEFPUB.iGetPubNumber()", 14, (PUBEXTDEFIMPLDEFDEFPUB.setPubNumber(14), PUBEXTDEFIMPLDEFDEFPUB.iGetPubNumber()) );

//*******************************************
// access from outside of class
//*******************************************

var EXTDCLASS = new PubExtDefaultImplDefDefPub();

arr = new Array(1, 2, 3);

AddTestCase( "*** access public methods and properties from outside of class ***", 1, 1 );
AddTestCase( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );

// ********************************************
// access public method from a default
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultImplDefDefPub();
AddTestCase( "*** Access public method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testGetSubArray(arr)", arr, EXTDCLASS.testGetSubArray(arr) );


// ********************************************
// access public method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultImplDefDefPub();
AddTestCase( "*** Access public method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );


// ********************************************
// access public method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultImplDefDefPub();
AddTestCase( "*** Access public method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// ********************************************
// access public method from a final
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDefaultImplDefDefPub();
AddTestCase( "*** Access public method from final method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testFinSubArray(arr)", arr, EXTDCLASS.testFinSubArray(arr) );



test();       // leave this alone.  this executes the test cases and
              // displays results.
