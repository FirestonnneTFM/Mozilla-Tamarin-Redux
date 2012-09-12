/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import MCPackage.*;


var SECTION = "Method Closures";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Extract method and add to dynamic class";        // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone




var obj:SomeClass = new SomeClass();
obj.string = "this is my value";

// *****************************
// Extract a public method
// *****************************
var mc : Function = obj.getString;
AddTestCase( "obj.getString() == mc()", obj.getString(), mc() );



// *****************************
// Add the MC to a dynamic class
// *****************************
var dyn:DynamicClass = new DynamicClass();
dyn.foo = mc;
AddTestCase( "*** add the method closure to a dynamic object ***", 1, 1 );
AddTestCase( "dyn.foo()", obj.getString(), dyn.foo() );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
