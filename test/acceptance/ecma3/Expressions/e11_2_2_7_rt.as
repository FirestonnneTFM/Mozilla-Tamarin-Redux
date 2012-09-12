/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "e11_2_2_7_n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The new operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var STRING = new String("hi");
    try{
       var s = new STRING();
    }catch(e:Error){
       thisError = e.toString();
    }finally{
       array[item++] = new TestCase( SECTION,
                                    "var s = new STRING()",
                                    "TypeError: Error #1007",
                                    typeError(thisError) );
     }


   /* array[item++] = new TestCase( SECTION,
                                    "var STRING = new String('hi'); var s = new STRING()",
                                    "error",
                                    s = new STRING() );*/
    return array;
}

function TestFunction() {
    return arguments;
}
