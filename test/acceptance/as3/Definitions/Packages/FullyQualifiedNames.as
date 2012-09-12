/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
package OtherPackage {
    public namespace Kitty;
    
    public interface IClickable {
            function whoAmI():String;
    }
}
 
package FullyQualifiedNames {
    
    import OtherPackage.*;


    public class A {
        public function whoAmI():String {
            return "A";
        }
    
    }
    
    use namespace OtherPackage.Kitty;
    
    public class C {
        Kitty var b:Boolean = true;
        public function returnNSVar():Boolean {
            return Kitty::b;
        }
        
        Kitty function returnArray():Array {
            return [1,2,3];
        }
        
        public function callNSFunc() {
            var k:Array = Kitty::returnArray();
            return k;
        }
    }

    public class B implements OtherPackage.IClickable {
        public function whoAmI():String {
            return "B";
        }
    
    }


    public var s:String = "hello";
    var p:String = "private";
    public function publicFunc(i:int):String {
        return "You passed " + i.toString();
    }
    
    
    
}

import FullyQualifiedNames.*;

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a = new FullyQualifiedNames.A();
var b = new FullyQualifiedNames.B();
var c = new FullyQualifiedNames.C();

AddTestCase("Function in fully qualified class", "A", a.whoAmI());
AddTestCase("Interface with fully qualified path", "B", b.whoAmI());
AddTestCase("Fully qualified reference to variable", "hello", FullyQualifiedNames.s);

try {
    p = FullyQualifiedNames.p;
    result = "no exception";
} catch(e) {
    result = "exception";
}
AddTestCase("Fully qualified reference to internal variable", "exception", result);
AddTestCase("Fully qualified reference to function", "You passed 5", FullyQualifiedNames.publicFunc(5));
AddTestCase("Namespace variable, fully qualified path", true, c.returnNSVar());
AddTestCase("Namespace function, fully qualified path", "1,2,3", c.callNSFunc().toString());

test();       // leave this alone.  this executes the test cases and
              // displays results.
