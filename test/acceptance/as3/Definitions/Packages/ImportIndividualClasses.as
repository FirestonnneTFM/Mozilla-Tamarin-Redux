/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
package ImportIndividualClasses {

    public interface IClickable {
        function whoAmI():String;
    }
}

package ImportIndividualClasses {

    public class A {
        public function whoAmI():String {
            return "A";
        }
    
    }
}

package ImportIndividualClasses {
    import kitty.Kitty;
    use namespace Kitty;
    
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
}

package AnotherPackage {
    import ImportIndividualClasses.IClickable;
    public class B implements IClickable {
        public function whoAmI():String {
            return "B";
        }
    
    }

}

package ImportIndividualClasses {

    public var s:String = "hello";
    public function publicFunc(i:int):String {
        return "You passed " + i.toString();
    }
}

package kitty {
    public namespace Kitty;
}

import ImportIndividualClasses.A;
import AnotherPackage.B;
import ImportIndividualClasses.C;
import kitty.Kitty;
import ImportIndividualClasses.s;
import ImportIndividualClasses.publicFunc;

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a = new A();
var b = new B();
var c = new C();

AddTestCase("Class A imported individually", "A", a.whoAmI());
AddTestCase("Interface imported individually", "B", b.whoAmI());
AddTestCase("Variable s imported individually", "hello", s);
AddTestCase("Function publicFunc imported individually", "You passed 5", publicFunc(5));
AddTestCase("Namespace imported individually, function", true, c.returnNSVar());
AddTestCase("Namespace in class, imported individually,", "1,2,3", c.callNSFunc().toString());

class X{
Kitty var num:Number = 5;
Kitty function kittyFunc(s:String):String {
    return "You said hi";
}
}

var obj:X = new X()
AddTestCase("Variable, namespace imported individually", 5, obj.Kitty::num);
AddTestCase("Function, namespace imported individually", "You said hi", obj.Kitty::kittyFunc("hi"));

test();       // leave this alone.  this executes the test cases and
              // displays results.
