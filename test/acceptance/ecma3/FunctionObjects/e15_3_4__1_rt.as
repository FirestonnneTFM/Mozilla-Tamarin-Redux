/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.3.4-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the Function Prototype Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    
    var origFunctionToString = Function.prototype.toString;

    array[item++] = new TestCase(   SECTION,
                                    "var myfunc = Function.prototype; myfunc.toString = Object.prototype.toString; myfunc.toString()",
                                    true,
                                    (myfunc = Function.prototype, myfunc.toString = Object.prototype.toString, myfunc.toString()).indexOf("[object Function-") == 0
                                    );

    array[item++] = new TestCase( SECTION,  "Function.prototype.valueOf",       Object.prototype.valueOf,   Function.prototype.valueOf );

    array[item++] = new TestCase( SECTION,  "Function.prototype()",undefined, Function.prototype() );

    array[item++] = new TestCase( SECTION,  "Function.prototype(1,true,false,'string', new Date(),null)",  (void 0), Function.prototype.call(1,true,false,'string', new Date(),null) );
    
    //restore
    Function.prototype.toString = origFunctionToString;
    
    return ( array );
}
