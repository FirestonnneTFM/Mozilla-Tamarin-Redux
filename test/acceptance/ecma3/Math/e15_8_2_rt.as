/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8-2-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Math Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError="no error";
    try{

        var MYMATH = new Math();
    }
    catch(e){
        thisError=e.toString();
    }
    finally{
        array[item++] = new TestCase( SECTION,
                                 "MYMATH = new Math()",
                                 "TypeError: Error #1076",
                                 typeError(thisError) );
    }
    return ( array );
}
