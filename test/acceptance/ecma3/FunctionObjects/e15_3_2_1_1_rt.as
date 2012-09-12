/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.2.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Function Constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array:Array = new Array();
    var item:Number = 0;
    
    var thisError:String="no error";

    try{
        var MyObject = Function( "value", "this.value = value; this.valueOf = new  Function( 'return this.value' ); this.toString = new Function( 'return String(this.value);' )" );
    }catch(e1:EvalError){
        thisError=(e1.toString()).substring(0,22);
    }finally{//print(thisError);
        array[item++] = new TestCase(   SECTION,"Function('function body') is not supported","EvalError: Error #1066",thisError);
    }
    var myfunc = new Function();

//    not going to test toString here since it is implementation dependent.
    array[item++] = new TestCase( SECTION,  "myfunc.toString()",     "function Function() {}",    myfunc.toString() );


    thisError="no error";
    try{
        myfunc.toString = Object.prototype.toString;
        myfunc.toString();
    }catch(e:Error){
        thisError = e.toString();
    }finally{//print(thisError);
        array[item++] = new TestCase(   SECTION,
                                    "myfunc = new Function(); myfunc.toString = Object.prototype.toString; myfunc.toString()",
                                    "no error",referenceError(thisError));
    }
    myfunc.myToString = Object.prototype.toString;

    array[item++] = new TestCase( SECTION,  "myfunc = new Function(); myfunc.myToString = Object.prototype.toString; myfunc.myToString()",
                                            true,
                                            myfunc.myToString().indexOf("[object Function-") == 0
                                             );
    array[item++] = new TestCase( SECTION,  "myfunc.length",                            0,                      myfunc.length );
    array[item++] = new TestCase( SECTION,  "myfunc.prototype.toString()",              "[object Object]",      myfunc.prototype.toString() );

    array[item++] = new TestCase( SECTION,  "myfunc.prototype.constructor",             myfunc,                 myfunc.prototype.constructor );
    //array[item++] = new TestCase( SECTION,  "myfunc.arguments",                         null,myfunc.arguments );

    function MyObject(value){
        this.value = value;
        this.valueOf = function() {return this.value;}
        this.toString = function() {return this.value+'';}
    }


    array[item++] = new TestCase( SECTION,  "var OBJ = new MyObject(true), OBJ.valueOf()",    true,             (OBJ = new MyObject(true), OBJ.valueOf() ) );

    array[item++] = new TestCase( SECTION,  "OBJ.toString()",                           "true", (OBJ = new MyObject(true),OBJ.toString()) );

    OBJ.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "OBJ.toString = Object.prototype.toString; OBJ.toString()", "[object Object]",   OBJ.toString());


    MyObject.myToString = Object.prototype.toString;

    array[item++] = new TestCase( SECTION,  "MyObject.toString = Object.prototype.toString; MyObject.toString()",    true,   MyObject.myToString().indexOf("[object Function-")==0);

    array[item++] = new TestCase( SECTION,  "MyObject.length",                              1,      MyObject.length );


    array[item++] = new TestCase( SECTION,  "MyObject.prototype.constructor",               MyObject,   MyObject.prototype.constructor );

    //not supported
    //array[item++] = new TestCase( SECTION,  "MyObject.arguments",                           null,MyObject.arguments);

    return ( array );
}
