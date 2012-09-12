/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";             // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";       // Version of JavaScript or ECMA
var TITLE   = "Using multiple includes Error if two files having same function name are given.";    // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                            // leave this alone



/*===========================================================================*/

// Including the same function name (with different return values) is the same as declaring a function twice ...
//  second declaration takes precedence

include "./MultipleIncOrder/Include1.txt"
include "./MultipleIncOrder/Include2.txt"

AddTestCase( "Include two files with same function name, second include takes precedence", "incFunc2", incFunc() );

/*===========================================================================*/

test();       // leave this alone.  this executes the test cases and
              // displays results.
