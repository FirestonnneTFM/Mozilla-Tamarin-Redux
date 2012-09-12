/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "namespace inside a function";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


class A{
namespace Baseball;
namespace Football;
namespace Basketball;
namespace HelloKitty;


Football var teamName = "Chargers";
Baseball var teamName = "Giants";

use namespace Baseball;


Football function getTeam(){

    use namespace Football;
    return Football::teamName;
}

Baseball function getTeam() {
    return teamName;
}

public function callNSFunction() {
    return Football::getTeam();
}

public function getNSVariable() {
    return Football::teamName;
}

public function a1(){
return Football::getTeam()
}
public function a2(){
return Baseball::getTeam()
}
public function a3(){
return teamName
}


HelloKitty function sayHello(who) {
return "Hello " + who;
}

public function a4(){
return HelloKitty::sayHello("Odi")
}


}
var obj:A = new A();


AddTestCase( "function getTeam called use namespace locally", "Chargers", obj.a1());

AddTestCase( "function getTeam called from another function", "Chargers", obj.callNSFunction());

AddTestCase( "function called that returns a namespace variable", "Chargers", obj.getNSVariable());

AddTestCase( "Make sure outside of function, first ns is used", "Giants", obj.a2());

AddTestCase( "Make sure outside of function, first ns is used", "Giants", obj.a3());


AddTestCase("Calling a namespace function from a function", "Hello Odi", obj.a4());


test();       // leave this alone.  this executes the test cases and
              // displays results.
