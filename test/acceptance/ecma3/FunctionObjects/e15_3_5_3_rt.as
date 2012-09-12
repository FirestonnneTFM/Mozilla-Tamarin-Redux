/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.3.5.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function.arguments";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array =new Array();
    var item = 0;

    thisError="no error";
    try{
        var MYFUNCTION = new Function( "return this.arguments" );
    }catch(e){
        thisError=(e.toString()).substring(0,22);
    }finally{
        array[item++] = new TestCase( SECTION,"Function('function body') not supported","EvalError: Error #1066",thisError);
    }

    //arguments not supported anymore
    //var MYFUNCTION = new Function();

    //array[item++] = new TestCase( SECTION,  "var MYFUNCTION = new Function(); MYFUNCTION.arguments",  null,   MYFUNCTION.arguments );

    return array;
}
