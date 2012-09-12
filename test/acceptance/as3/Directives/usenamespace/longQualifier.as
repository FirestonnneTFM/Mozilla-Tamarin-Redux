/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "longQualifier";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here

//bug 150502
namespace T1;
class nsTest
{
    T1 function get x () { return 10;}
    public function get x () {return 0;}
}

var myTest = new nsTest;
var someVar = myTest.T1::x;
AddTestCase( "ns within a class", 10, someVar );


namespace get;
class Get
{
    get function get get () { return "get"; }
}

var g = new Get;
var myGet = g.get::get;
AddTestCase( "ns within a class - get keyword", "get", myGet );





//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
