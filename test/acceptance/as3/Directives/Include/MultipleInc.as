/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";             // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";       // Version of JavaScript or ECMA
var TITLE   = "Using multiple includes";    // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                            // leave this alone



/*===========================================================================*/

include "Include.txt"
include "Include1.txt"

include "./MultipleInc/Include2.txt"

AddTestCase( "Check if a multiple files can be included:", "incFunc", incFunc() );
AddTestCase( "Check if a multiple files can be included:", "incFunc1", incFunc1() );
AddTestCase( "Check if a multiple files can be included:", "incFunc2", incFunc2() );

/*===========================================================================*/

test();       // leave this alone.  this executes the test cases and
              // displays results.
