/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


import StaticPropertyPackage.*;

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Access static method of base class";       // Provide ECMA section title or a description
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

var obj:AccStatPropViaSubClass = new AccStatPropViaSubClass();

// ********************************************
// Try to access a static property (in a namespace)
// of the base class via a reference to the subclass
// ********************************************
var thisError = "no exception thrown";
try{
    var date = obj.ns1::date;
} catch (e1) {
    thisError = e1.toString();
} finally {
    AddTestCase( "access static property in namespace of base class using subclass",
                REFERENCEERROR+1069,
                referenceError( thisError) );
}

// ********************************************
// Try to access a static property of the base
// class via a reference to the subclass
// ********************************************
thisError = "no exception thrown";
try{
    var str = obj.string;
} catch (e2) {
    thisError = e2.toString();
} finally {
    AddTestCase( "access static property of base class using subclass",
                REFERENCEERROR+1069,
                referenceError( thisError) );
}

// ********************************************
// Try to access the static property of the base
// class from an instance method in the subclass
// using "this.foo"
// ********************************************
var thisError = "no exception thrown";
try{
    var str = obj.getString();
} catch (e3) {
    thisError = e3.toString();
} finally {
    AddTestCase( "access static property of base class in subclass with this.foo",
                REFERENCEERROR+1069,
                referenceError( thisError) );
}

test();       // leave this alone.  this executes the test cases and
              // displays results.
