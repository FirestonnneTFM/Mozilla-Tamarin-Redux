/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_2_2_6_n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The new operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var BOOLEAN  = true;

    try{
       var b = new BOOLEAN();
    }catch(e:Error){
       thisError = e.toString();
    }finally{
       array[item++] = new TestCase( SECTION,
                                    "var b = new BOOLEAN()",
                                    "TypeError: Error #1007",
                                    typeError(thisError) );
     }

  /*array[item++] = new TestCase( SECTION,
                                    "BOOLEAN = true; var b = new BOOLEAN()",
                                    "error",
                                    b = new BOOLEAN() );*/
    return array;
}

function TestFunction() {
    return arguments;
}
