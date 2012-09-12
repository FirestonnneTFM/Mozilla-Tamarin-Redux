/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 

 package A {
    public class A {
        public function whoAmI():String {
            return "A.A";
        }
                
    }
    
    
    public class B  {
        var sB;
        public function createB() {
            sB = new A();
        }
        public function createB2() {
            sB = new A.A();
                   
        }
        public function whoAmI():String {
            return "A.B";
        }
    }
}

package D {
    public var D:String = "hello";
}
package E {
    public var E:String = "E";
        
}
package F {
    public function F(n:Number):String {
        return "You passed " + n;
    }
}
package IG {
    interface IG {
        function whoAmI():String;
    }
    public class G implements IG {
        public function whoAmI():String {
            return "G";
        }
    }
}

import A.*;
import D.*;
import E.*;
import F.*;
import IG.*;

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a = new A();
var b = new B();
var g = new G();

AddTestCase("Class A in package A", "A.A", a.whoAmI());
AddTestCase("Class B in package A", "A.B", b.whoAmI());

result = "";
try {
    b.createB();
    result = "no exception";
} catch (e2) {
    result = "exception";
}

// !!! This will have to be changed when bug 139002 is fixed.

AddTestCase("Access A in A as new A()", "no exception", result);

result = "";
try {
    b.createB2();
    result = "no exception";
} catch (e3) {
    result = "exception";
}

// !!! This will have to be changed when bug 138845 is fixed.
//bug 138845 is fixed so changing "exception" to "no exception"

AddTestCase("Access A in A as new A.A()", "no exception", result);
    
AddTestCase("Variable D in package D", "hello", D);

try {
    e=E.E;
    result = "no exception";
} catch(e) {
    result = "exception";
}
AddTestCase("Public variable E inside package E", "no exception", result);
AddTestCase("Public variable E inside package E", "E", E.E);
AddTestCase("Function F inside package F", "You passed 5", F(5));

AddTestCase("Interface IG defined in package IG", "G", g.whoAmI());

test();       // leave this alone.  this executes the test cases and
              // displays results.
