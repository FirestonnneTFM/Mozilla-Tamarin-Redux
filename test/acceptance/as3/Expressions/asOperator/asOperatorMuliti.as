/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";        // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";                // Version of ECMAScript or ActionScript
var TITLE   = "as operator";        // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

// as Array
AddTestCase( "null as Array as Array", null, (null as Array as Array));

// as Boolean
AddTestCase( "null as Boolean as Boolean", null, (null as Boolean as Boolean));

// as Date
AddTestCase( "null as Date as Date", null, (null as Date as Date));

// as Function
AddTestCase( "null as Function as Function", null, (null as Function as Function));

// as Math
AddTestCase( "null as Math as Math", null, (null as Math as Math));

// as Number
AddTestCase( "null as Number as Number", null, (null as Number as Number));

// as Object
AddTestCase( "null as Object as Object", null, (null as Object as Object));

// as RegExp
AddTestCase( "null as RegExp as RegExp", null, (null as RegExp as RegExp));

// as String
AddTestCase( "null as String as String", null, (null as String as String));

// as int
AddTestCase( "null as int as int", null, (null as int as int));

// as uint
AddTestCase( "null as uint as uint", null, (null as uint as uint));

// as void
//AddTestCase( "null as void as void", undefined, (null as void as void));

//other
AddTestCase( "null as Array as Boolean as Date as Number as String ", null,
             (null as Array as Boolean as Date as Number as String ));

test();       // leave this alone.  this executes the test cases and
              // displays results.


