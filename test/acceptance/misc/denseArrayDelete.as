/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Array";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "test";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

// add your tests here
function arrayCrasher():Boolean
{
    var a:Array = new Array();
    a[0] = 1; // so that the array "hasDense"
    a[0x10000000] = 3;
    delete a[0x10000000]; // stack overflow
    return true;
}

// Lack of a crash means the bug is fixed
AddTestCase( "var helloWorld = 'Hello World'", true, arrayCrasher() );


test();       // leave this alone.  this executes the test cases and
              // displays results.
