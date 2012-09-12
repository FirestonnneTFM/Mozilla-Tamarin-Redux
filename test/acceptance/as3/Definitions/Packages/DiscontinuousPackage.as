/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import DiscontinuousPackage.*;

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a = new A();
var b = new B();
var c = new C();

AddTestCase("Function defined in [Packagename]/A.as", "A", a.whoAmI());
AddTestCase("Interface defined in [Packagename]/B.as", "B", b.whoAmI());
AddTestCase("Variable defined in [Packagename]/vars.as", "hello", s);
AddTestCase("Function defined in [Packagename]/vars.as", "You passed 5", publicFunc(5));
AddTestCase("Namespace variable defined in [Packagename]/C.as", true, c.returnNSVar());
AddTestCase("Namespace function defined in [Packagename]/C.as", "1,2,3", c.callNSFunc().toString());

class X{
Kitty var num:Number = 5;
Kitty function kittyFunc(s:String):String {
    return "You said hi";
}
}
var obj:X = new X()
AddTestCase("Variable, namespace defined in [Packagename]/vars.as", 5, obj.Kitty::num);
AddTestCase("Function, namespace defined in [Packagename]/vars.as", "You said hi", obj.Kitty::kittyFunc("hi"));

test();       // leave this alone.  this executes the test cases and
              // displays results.
