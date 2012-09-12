/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package A
{
    public class C
    {
        public function C()
        {
        }
    }
}

package B
{
    import A.*;
    public class C extends A.C
    {
        var _x = "FAILED";
        public function get x(){ return _x; }
        public function C()
        {
            _x = "PASSED";
        }
    }
}

import B.*;

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone

var TESTER:C = new C();

AddTestCase( "Same class name, different package name", "PASSED", TESTER.x );

test();       // leave this alone.  this executes the test cases and
              // displays results.
