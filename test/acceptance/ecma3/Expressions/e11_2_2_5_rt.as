/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "e11_2_2_5_n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The new operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test()
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var NUMBER = 0;

    try{
       var n = new NUMBER();
    }catch(e:Error){
       thisError = e.toString();
    }finally{
       array[item++] = new TestCase( SECTION,
                                    "var n = new NUMBER()",
                                    "TypeError: Error #1007",
                                    typeError(thisError) );
     }

    /*array[item++] = new TestCase( SECTION,
                                    "NUMBER=0, var n = new NUMBER()",
                                    "error",
                                    n = new NUMBER() );*/
    return array;
}

function TestFunction() {
    return arguments;
}
