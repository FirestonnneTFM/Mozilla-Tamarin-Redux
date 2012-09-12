/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import DynamicClassMethPackage.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Add function to Dynamic Class";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



var Obj = new DynamicClassMeth();

Obj.foo = function () { return 100;}


// ********************************************
// Access property of type Number
//
// ********************************************

AddTestCase( "*** Access function added to a dynamic class ***", 1, 1 );
AddTestCase( "Obj.foo()", 100, Obj.foo() );


test();       // leave this alone.  this executes the test cases and
              // displays results.
