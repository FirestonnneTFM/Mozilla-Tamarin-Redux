/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.8-3-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Math Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    thisError="no error";
    var MYMATH;
    try{
        MYMATH = Math();
    }catch(e:TypeError){
        thisError=e.toString();
    }finally{
    array[item++] = new TestCase( SECTION,
                                 "MYMATH = Math()",
                                 "TypeError: Error #1075",
                                 typeError(thisError));
    }

    return ( array );
}
