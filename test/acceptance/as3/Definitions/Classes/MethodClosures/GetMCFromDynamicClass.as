/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import MCPackage.*;


var SECTION = "Method Closures";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Extract method from a dynamic class";        // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone




var obj:DynamicClass = new DynamicClass();


// *****************************
// Add the function to a dynamic class
// *****************************
obj.getDate = function():Date { return this.date; }
AddTestCase( "*** add the method to a dynamic object ***", 1, 1 );
var year=1969;
if (getTimeZoneDiff()>=0) {
    var year=1970;
}

AddTestCase( "obj.getDate()", year, obj.getDate().getFullYear() );


// *****************************
// Extract the method from dynamic class
// Trying to extract a new method from a dynamic class
// should not work, bug #135844
// *****************************
var mc : Function = obj.getDate;
AddTestCase( "*** try to extract the new method ***", 1, 1 );
AddTestCase( "obj.getDate() == mc()", null, mc() );






test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
