/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.1.1-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Function Constructor Called as a Function";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError="no error";
    try{
        var MyObject = Function( "value", "this.value = value; this.valueOf =  Function( 'return this.value' ); this.toString =  Function( 'return String(this.value);' )" );
    }catch(e1:EvalError){
        thisError=(e1.toString()).substring(0,22);
    }finally{
        array[item++] = new TestCase(   SECTION,"Function('function body') is not supported","EvalError: Error #1066",thisError);
    }
    var myfunc:Function = Function();
    myfunc.myToString=Object.prototype.toString;

    array[item++] = new TestCase(   SECTION,
                                    "myfunc = Function(); myfunc.myToString = Object.prototype.toString; myfunc.myToString()",
                                    true,
                                    myfunc.myToString().indexOf("[object Function-") == 0
                                     );
    thisError="no error";
    try{
        myfunc.toString = Object.prototype.toString;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }
    array[item++] = new TestCase(   SECTION,
                                    "myfunc = Function(); myfunc.toString = Object.prototype.toString; myfunc.toString()",
                                    "no error",
                                    referenceError(thisError) );

    array[item++] = new TestCase( SECTION,  "myfunc.length",0,                     myfunc.length );
    array[item++] = new TestCase( SECTION,  "myfunc.prototype.toString()",              "[object Object]",      myfunc.prototype.toString() );
    array[item++] = new TestCase( SECTION,  "myfunc.prototype.constructor",             myfunc,                 myfunc.prototype.constructor );
  //array[item++] = new TestCase( SECTION,  "myfunc.arguments",                         undefined,myfunc.arguments );


    return ( array );
}
