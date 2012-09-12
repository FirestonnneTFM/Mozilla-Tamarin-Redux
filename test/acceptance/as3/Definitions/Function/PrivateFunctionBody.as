/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import PrivateFunctionBody.*

class PrivateFunctionBodyClass{
    private function noReturnNoParamsInner() { return "noReturnNoParams"; }
    private function noReturnParamsInner(s:String, b:Boolean) { return s; }
    private function noReturnCustomParamInner(c:Custom) { return new Custom(); }
    private function returnNoParamsInner():String { return "returnNoParams"; }
    private function returnParamsInner(s:String, b:Boolean):String { return s; }
    private function returnCustomNoParamsInner():Custom { return new Custom(); }

    public function noReturnNoParams() { return noReturnNoParamsInner(); }
    public function noReturnParams(s:String, b:Boolean) { return noReturnParamsInner(s,b); }
    public function noReturnCustomParam(c:Custom) { return noReturnCustomParamInner(c); }
    public function returnNoParams():String { return returnNoParamsInner(); }
    public function returnParams(s:String, b:Boolean):String { return returnParamsInner(s,b); }
    public function returnCustomNoParams():Custom { return returnCustomNoParamsInner(); }
}

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

// outside package inside class
TESTOBJ = new PrivateFunctionBodyClass();
AddTestCase( "TESTOBJ.noReturnNoParams()", "noReturnNoParams", TESTOBJ.noReturnNoParams() );
AddTestCase( "TESTOBJ.noReturnParams(s,b)", "this is a test", TESTOBJ.noReturnParams(s,b) );
AddTestCase( "TESTOBJ.noReturnCustomParams()", "[object Custom]", String(TESTOBJ.noReturnCustomParam(c)) );
AddTestCase( "TESTOBJ.returnNoParams()", "returnNoParams", TESTOBJ.returnNoParams() );
AddTestCase( "TESTOBJ.returnParams(s,b)", "this is a test", TESTOBJ.returnParams(s,b) );
AddTestCase( "TESTOBJ.returnCustomNoParams()", "[object Custom]", String(TESTOBJ.returnCustomNoParams()) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
