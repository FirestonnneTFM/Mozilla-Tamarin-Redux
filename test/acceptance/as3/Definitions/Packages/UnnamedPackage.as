/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

//Note that there is no import statement here

var SECTION = "Definitions/Packages";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "UnNamedPackage" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a = new A();
var b = new B();
var c = new C();

AddTestCase("Function defined in unNamedPackage", "A", a.whoAmI());
AddTestCase("Interface defined in unNamedPackage", "B", b.whoAmI());
AddTestCase("Variable defined in unNamedPackage", "hello", s);
AddTestCase("Function defined in unNamedPackage", "You passed 5", publicFunc(5));
AddTestCase("Namespace variable defined in unNamedPackage", true, c.returnNSVar());
AddTestCase("Namespace function defined in unNamedPackage", "1,2,3", c.callNSFunc().toString());

var obj:X = new X()

AddTestCase("Variable, namespace defined in unNamedPackage", 5, obj.Kitty::num);
AddTestCase("Function, namespace defined in unNamedPackage", "You said hi", obj.Kitty::kittyFunc("hi"));

test();       // leave this alone.  this executes the test cases and
              // displays results.
