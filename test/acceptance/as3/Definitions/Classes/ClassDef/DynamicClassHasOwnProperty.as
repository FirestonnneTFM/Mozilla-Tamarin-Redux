/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import DynamicClassHasOwnPropertyPackage.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Call hasOwnProperty() on a property of a dynamic class";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



var Obj:DynamicClassHasOwnProperty = new DynamicClassHasOwnProperty();


// ********************************************
// Call hasOwnProperty()
//
// ********************************************

AddTestCase( "Obj.hasOwnProperty(\"bar\")", true, Obj.hasOwnProperty("bar") );


test();       // leave this alone.  this executes the test cases and
              // displays results.
