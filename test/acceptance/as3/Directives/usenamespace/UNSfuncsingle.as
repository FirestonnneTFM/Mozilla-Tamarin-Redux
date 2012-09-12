/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "use namespace";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone



class A{

namespace Baseball;
namespace Basketball;
namespace Hockey;

Baseball function getTeam(){
    return "Giants";
}
Basketball function getTeam(){
    return "Kings";
}
Hockey function getTeam(){
    return "Sharks";
}
public function a1(){
  return Baseball::getTeam()
}
public function a2(){
  return Hockey::getTeam()
}
public function a3(){
 use namespace Basketball;
  return getTeam()
}
}

var obj:A = new A();

AddTestCase( "Baseball function getTeam()", "Giants", obj.a1());


AddTestCase( "Hockey function getTeam()", "Sharks", obj.a2());



AddTestCase( "Basketball function getTeam()", "Kings", obj.a3());


test();       // leave this alone.  this executes the test cases and
              // displays results.
