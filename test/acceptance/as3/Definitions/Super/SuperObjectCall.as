/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "8.6.1 Constructor Methods";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "SuperExpression on Object";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
import SuperObjectCall.*

var soc = new SuperObjectCall();
var thisException = "no exception thrown";
try {
    var s = soc.whatIsIt();
} catch (e) {
    thisException = e.toString();
} finally {
    AddTestCase( "super call to Object toString() should fail", REFERENCEERROR+1070, referenceError( thisException ) );
}

//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
