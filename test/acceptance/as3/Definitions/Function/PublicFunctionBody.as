/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import PublicFunctionBody.*;

class PublicFunctionBodyClass {
    public function noReturnNoParams() { return "noReturnNoParams"; }
    public function noReturnParams(s:String, b:Boolean) { return s; }
    public function noReturnCustomParam(c:Custom) { return new Custom(); }
    public function returnNoParams():String { return "returnNoParams"; }
    public function returnParams(s:String, b:Boolean):String { return s; }
    public function returnCustomNoParams():Custom { return new Custom(); }
}

function noReturnNoParamsNoPackage() { return "noReturnNoParams"; }
function noReturnParamsNoPackage(s:String, b:Boolean) { return s; }
function noReturnCustomParamNoPackage(c:Custom) { return new Custom(); }
function returnNoParamsNoPackage():String { return "returnNoParams"; }
function returnParamsNoPackage(s:String, b:Boolean):String { return s; }
function returnCustomNoParamsNoPackage():Custom { return new Custom(); }

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Function Body Parameter/Result Type";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

var TESTOBJ;
var s:String = new String("this is a test");
var b:Boolean = new Boolean(true);
var c:Custom = new Custom();

// inside class inside package
TESTOBJ = new TestObj();
AddTestCase( "TESTOBJ.noReturnNoParams()", "noReturnNoParams", TESTOBJ.noReturnNoParams() );
AddTestCase( "TESTOBJ.noReturnParams(s,b)", "this is a test", TESTOBJ.noReturnParams(s,b) );
AddTestCase( "TESTOBJ.noReturnCustomParams()", "[object Custom]", String(TESTOBJ.noReturnCustomParam(c)) );
AddTestCase( "TESTOBJ.returnNoParams()", "returnNoParams", TESTOBJ.returnNoParams() );
AddTestCase( "TESTOBJ.returnParams(s,b)", "this is a test", TESTOBJ.returnParams(s,b) );
AddTestCase( "TESTOBJ.returnCustomNoParams()", "[object Custom]", String(TESTOBJ.returnCustomNoParams()) );

// inside package outside of class
AddTestCase( "noReturnNoParams()", "noReturnNoParams", noReturnNoParams() );
AddTestCase( "noReturnParams(s,b)", "this is a test", noReturnParams(s,b) );
AddTestCase( "noReturnCustomParams()", "[object Custom]", String(noReturnCustomParam(c)) );
AddTestCase( "returnNoParams()", "returnNoParams", returnNoParams() );
AddTestCase( "returnParams(s,b)", "this is a test", returnParams(s,b) );
AddTestCase( "returnCustomNoParams()", "[object Custom]", String(returnCustomNoParams()) );

// outside package inside class
TESTOBJ = new PublicFunctionBodyClass();
AddTestCase( "TESTOBJ.noReturnNoParams()", "noReturnNoParams", TESTOBJ.noReturnNoParams() );
AddTestCase( "TESTOBJ.noReturnParams(s,b)", "this is a test", TESTOBJ.noReturnParams(s,b) );
AddTestCase( "TESTOBJ.noReturnCustomParams()", "[object Custom]", String(TESTOBJ.noReturnCustomParam(c)) );
AddTestCase( "TESTOBJ.returnNoParams()", "returnNoParams", TESTOBJ.returnNoParams() );
AddTestCase( "TESTOBJ.returnParams(s,b)", "this is a test", TESTOBJ.returnParams(s,b) );
AddTestCase( "TESTOBJ.returnCustomNoParams()", "[object Custom]", String(TESTOBJ.returnCustomNoParams()) );

// outside package and outside class
AddTestCase( "noReturnNoParamsNoPackage()", "noReturnNoParams", noReturnNoParamsNoPackage() );
AddTestCase( "noReturnParamsNoPackage(s,b)", "this is a test", noReturnParamsNoPackage(s,b) );
AddTestCase( "noReturnCustomParamsNoPackage()", "[object Custom]", String(noReturnCustomParamNoPackage(c)) );
AddTestCase( "returnNoParamsNoPackage()", "returnNoParams", returnNoParamsNoPackage() );
AddTestCase( "returnParamsNoPackage(s,b)", "this is a test", returnParamsNoPackage(s,b) );
AddTestCase( "returnCustomNoParamsNoPackage()", "[object Custom]", String(returnCustomNoParamsNoPackage()) );

test();       // leave this alone.  this executes the test cases and
              // displays results.
