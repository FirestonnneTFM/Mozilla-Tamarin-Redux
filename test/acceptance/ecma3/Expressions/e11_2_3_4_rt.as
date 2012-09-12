/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "e11_2_3_4_n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function Calls";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
    
    try{
       null.valueOf();
    }catch(e:Error){
       thisError = e.toString();
    }finally{
       array[item++] = new TestCase( SECTION,
                                    "null.valueOf()",
                                    "TypeError: Error #1009",
                                    typeError(thisError) );
     }
    return array;
}
    
