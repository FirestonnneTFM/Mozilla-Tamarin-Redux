/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import ExtractMethPackage.*;


var SECTION = "Method Closures";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Extract methods from an internal class";     // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone




var obj:IntClassExtracMeth = new IntClassExtracMeth();

// *****************************
// Extract a public method
// *****************************
var mc : Function = obj.pubGetX;
AddTestCase( "*** extract a public function from an internal class", 1, 1 );
AddTestCase( "obj.pubGetX() == mc()", obj.pubGetX(), mc() );





test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
