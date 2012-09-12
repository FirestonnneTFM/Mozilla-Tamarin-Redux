/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.2.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Function Constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);


    var testcases = getTestCases();
    test();


function getTestCases() {
    var array:Array = new Array();
    var item:Number = 0;
        
    var thisError="no error";
    try{
        var myfunc1 = new Function("a","b","c", "return a+b+c" );
    }catch(e:Error){
        thisError=(e.toString()).substring(0,22);
    }finally{
        array[item++] = new TestCase( SECTION,"Function('function body') not supported","EvalError: Error #1066",thisError);
    }

    //commenting out all these tests as new Function() is no longer valid

    /*var myfunc1 = new Function();
    

    myfunc1.myToString = Object.prototype.toString;
    

    array[item++] = new TestCase( SECTION,  "myfunc1 = new Function(); myfunc.myToString = Object.prototype.toString; myfunc1.myToString()",
                                            true,
                                            myfunc1.myToString().indexOf("[object Function-")==0 );

    array[item++] = new TestCase( SECTION,  "myfunc1.length",0,myfunc1.length );
    array[item++] = new TestCase( SECTION,  "myfunc1.prototype.toString()",              "[object Object]",myfunc1.prototype.toString() );

    array[item++] = new TestCase( SECTION,  "myfunc1.prototype.constructor",             myfunc1,myfunc1.prototype.constructor );
    array[item++] = new TestCase( SECTION,  "myfunc1.arguments",                         null,                   myfunc1.arguments );
    array[item++] = new TestCase( SECTION,  "myfunc1()",undefined,myfunc1() );

    MYPROPS = '';
    for ( var p in myfunc1.prototype ) {
        MYPROPS += p;
    }

    array[item++] = new TestCase( SECTION,  "var MYPROPS = ''; for ( var p in myfunc1.prototype ) { MYPROPS += p; }; MYPROPS",
                                            "",
                                            MYPROPS );*/

    return ( array );
}
