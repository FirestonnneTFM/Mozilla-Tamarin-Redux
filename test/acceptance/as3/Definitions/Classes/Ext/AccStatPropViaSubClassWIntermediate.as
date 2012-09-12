/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


import StaticPropertyPackage.*;

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Access static property of base class";       // Provide ECMA section title or a description
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

var obj:AccStatPropViaSubClassWIntermediate = new AccStatPropViaSubClassWIntermediate();

// ********************************************
// Try to access a static property of the base
// class via a reference to the subclass that
// extends an intermediary class
// ********************************************
var thisError = "no exception thrown";
try{
    var str = obj.string;
} catch (e1) {
    thisError = e1.toString();
} finally {
    AddTestCase( "access static property of base class using sub and intermediate",
                REFERENCEERROR+1069,
                referenceError( thisError) );
}


// ********************************************
// Try to access a static property in an instance
// method using an intermeidate base class
// ( C -> B -> A, in C.foo( return B.x))
// ********************************************
AddTestCase("*** access static property of base class using  sub and intermediate ***", 1, 1);
AddTestCase("obj.getString()", "baseclass", obj.getString());


test();       // leave this alone.  this executes the test cases and
              // displays results.
