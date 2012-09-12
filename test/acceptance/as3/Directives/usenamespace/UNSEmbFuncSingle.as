/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "use namespace";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


class A {
    namespace Baseball;
    Baseball var teamName = "Giants";

    namespace Football;
    Football var teamName = "Angels";

    public function nsTest1(){
        use namespace Baseball;
        return teamName;
    }

    public function nsTest2(){
        use namespace Football;
        return teamName;
    }
}

var obj:A = new A()

AddTestCase( "Namespace defined in function", "Giants", obj.nsTest1() );
AddTestCase( "Namespace defined in function", "Angels", obj.nsTest2() );


test();       // leave this alone.  this executes the test cases and
              // displays results.
