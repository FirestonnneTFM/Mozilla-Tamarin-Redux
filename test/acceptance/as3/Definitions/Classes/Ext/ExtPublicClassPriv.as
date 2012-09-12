/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";  // Version of JavaScript or ECMA
var TITLE   = "extend public class";       // Provide ECMA section title or a description
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

// ********************************************
// access private method from a default
// method of a sub class
//
// ********************************************

var arr = new Array(1, 2, 3);

EXTDCLASS = new ExtPublicClass();
var thisError = "no exception thrown!";
try {
    EXTDCLASS.testSubGetSetArray(arr);
} catch (e1) {
    thisError = e1.toString();
} finally {
    AddTestCase( "Access private method from a default method of a sub class",
                    REFERENCEERROR+1069,
                    referenceError( thisError ) );
}


// ********************************************
// access private method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new ExtPublicClass();
thisError = "no exception thrown!";
try {
    EXTDCLASS.pubSubSetArray(arr);
} catch (e2) {
    thisError = e2.toString();
} finally {
    AddTestCase( "Access private method from a public method of a sub class",
                    REFERENCEERROR+1069,
                    referenceError( thisError ) );
}



// ********************************************
// access private method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new ExtPublicClass();
thisError = "no exception thrown!";
try {
    EXTDCLASS.testPrivSubArray(arr);
} catch (e3) {
    thisError = e3.toString();
} finally {
    AddTestCase( "Access private method from a private method of a sub class",
                    REFERENCEERROR+1069,
                    referenceError( thisError ) );
}



// ********************************************
// access private property from
// default method in sub class
// ********************************************

EXTDCLASS = new ExtPublicClass();
thisError = "no exception thrown!";
try {
    EXTDCLASS.testSubGetSetDPArray(arr);
} catch (e4) {
    thisError = e4.toString();
} finally {
    AddTestCase( "Access private method from a public method of a sub class",
                    REFERENCEERROR+1069,
                    referenceError( thisError ) );
}



// ********************************************
// access private property from
// ********************************************

EXTDCLASS = new ExtPublicClass();
thisError = "no exception thrown!";
try {
    EXTDCLASS.pubSubGetDPArray();
} catch (e5) {
    thisError = e5.toString();
} finally {
    AddTestCase( "Access private method from a public method of a sub class",
                    REFERENCEERROR+1069,
                    referenceError( thisError ) );
}



// ********************************************
// access private property from
// private method in sub class
// ********************************************

EXTDCLASS = new ExtPublicClass();

thisError = "no Exception thrown!";
try{
    ExtPublicClass.pubStatSubGetDPArray();
} catch (e10){
    thisError = e10.toString();
} finally {
    AddTestCase( "access private property from public static method of sub class",
                    TYPEERROR+1006,
                    typeError( thisError ) );
}

test();       // leave this alone.  this executes the test cases and
              // displays results.
