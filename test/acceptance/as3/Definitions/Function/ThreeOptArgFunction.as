/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import ThreeOptArgFunction.*

class ThreeOptArgFunctionClass {
    function returnArguments(s:String = "Str3", b:Boolean = true, n:Number = 30) {
        str = s;
        bool = b;
        num = n;
    }
}

function returnArgumentsNoPackage(s:String = "Str4", b:Boolean = false, n:Number = 40) {

        str = s;
        bool = b;
        num = n;
}


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Function Body Parameter/Result Type";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

var TESTOBJ = new TestObj();
var TESTOBJ1 = new ThreeOptArgFunctionClass();

var success = false;
TESTOBJ.returnArguments();

if(str == "Str1" && bool == true && num == 10)
{ success = true;}
else
{ success = false;}

AddTestCase( "TESTOBJ.returnArguments();", true, success );


success = false;
returnArguments();

if(str == "Str2" && bool == false && num == 20)
{ success = true;}
else
{ success = false;}

AddTestCase( "returnArguments();", true, success );


success = false;
TESTOBJ1.returnArguments();

if(str == "Str3" && bool == true && num == 30)
{ success = true;}
else
{ success = false;}

AddTestCase( "TESTOBJ1.returnArguments();", true, success );


success = false;
returnArgumentsNoPackage();

if(str == "Str4" && bool == false && num == 40)
{ success = true;}
else
{ success = false;}

AddTestCase( "returnArgumentsNoPackage();", true, success );


test();       // leave this alone.  this executes the test cases and
              // displays results.
