/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "11_2_2_3_n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The new operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var NULL = null;

    try{
       var o = new NULL();
    }catch(e:Error){
       thisError = e.toString();
    }finally{
       array[item++] = new TestCase( SECTION,
                                    "var o = new NULL()",
                                    "TypeError: Error #1007",
                                    typeError(thisError) );
     }

    /*array[item++] = new TestCase( SECTION,
                                    "NULL = null; var o = new NULL()",
                                    "error",
                                    o = new NULL() );*/
    return array;
}

function TestFunction() {
    return arguments;
}
