/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";                                 // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";                           // Version of JavaScript or ECMA
var TITLE   = "Check if a file can be included using include without the # symbol and front slashes";     // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



/*===========================================================================*/

// Include.txt used so that it's not considered a testcase by harness
include "Include.txt"

AddTestCase( "Check if a file can be included using include without the # symbol:", "incFunc", incFunc() );

/*===========================================================================*/

test();       // leave this alone.  this executes the test cases and
              // displays results.
