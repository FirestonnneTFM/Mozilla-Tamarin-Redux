/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package Prototyping {



import FinalClassPrototype.*;

var SECTION = "Class Prototype";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Prototype testing for final classes";  // Provide ECMA section title or a description
//var BUGNUMBER = "";

startTest();                // leave this alone


var finalObj = new FinalClass();


FinalClass.prototype.array = new Array('a', 'b', 'c');
AddTestCase( "Try overriding default property through a Final Class' prototype object", "1,2,3", finalObj.accessDefaultProperty().toString() );

FinalClass.prototype.intNumber = 500;
AddTestCase( "Try overriding internal property through a Final Class' prototype object", "100", finalObj.intNumber.toString() );

FinalClass.prototype.protInt = 0;   // Note: this works because the protected property is not visible!
AddTestCase( "Try overriding protected property through a Final Class' prototype object", "0", finalObj.protInt.toString() );

FinalClass.prototype.pubUint = 0;
AddTestCase( "Try overriding public property through a Final Class' prototype object", "1", finalObj.pubUint.toString() );

FinalClass.prototype.privVar = false;
AddTestCase( "Try overriding private property through a Final Class' prototype object", "true", finalObj.accPrivProp().toString() );

FinalClass.prototype.pubStat = 200;
AddTestCase( "Try overriding public static property through a Final Class' prototype object", "100", FinalClass.pubStat.toString() );

FinalClass.prototype.nsProp = "fakeNS";
AddTestCase( "Try overriding namespace property through a Final Class' prototype object", "nsProp", finalObj.accNS().toString() );

FinalClass.prototype.defaultMethod = false;
AddTestCase( "Try overriding default methodsthrough a Final Class' prototype object", true, finalObj.defaultMethod() );

FinalClass.prototype.internalMethod = -1;
AddTestCase( "Try overriding internal method through a Final Class' prototype object", 1, finalObj.internalMethod() );

//FinalClass.prototype.protectedMethod = -1;
//AddTestCase( "Try overriding protected method through a Final Class' prototype object", 1, finalObj.protectedMethod() );

FinalClass.prototype.publicMethod = false;
AddTestCase( "Try overriding public method through a Final Class' prototype object", true, finalObj.publicMethod() );

FinalClass.prototype.privateMethod = false;
AddTestCase( "Try overriding private method through a Final Class' prototype object", true, finalObj.accPrivMethod() );

FinalClass.prototype.nsMethod = -1;
AddTestCase( "Try overriding namespace method through a Final Class' prototype object", 1, finalObj.accNSMethod() );

FinalClass.prototype.publicFinalMethod = -1;
AddTestCase( "Try overriding public final method through a Final Class' prototype object", 1, finalObj.publicFinalMethod() );

FinalClass.prototype.publicStaticMethod = -1;
AddTestCase( "Try overriding public static method through a Final Class' prototype object", 42, FinalClass.publicStaticMethod() );


FinalClass.prototype.newArray = new Array('a', 'b', 'c');
AddTestCase( "Try adding new property through a final class' prototype object", "a,b,c", finalObj.newArray.toString() );

FinalClass.prototype.testFunction = function () {return true};
AddTestCase("Try adding new method through a final class' prototype object", true, finalObj.testFunction());

var equivalent:Boolean = (FinalClass.prototype.constructor == FinalClass);
AddTestCase("Verify prototype constructor is equivalent to class object", true, equivalent);


var thisError10 = "no error thrown";
var temp:Object = new Object();
try{
    FinalClass.prototype = temp;
} catch (e) {
    thisError10 = e.toString();
} finally {
    AddTestCase( "Try to write to FinalClass' prototype object", "ReferenceError: Error #1074",
                referenceError( thisError10 ) );
}

test();       // leave this alone.  this executes the test cases and
              // displays results.

}
