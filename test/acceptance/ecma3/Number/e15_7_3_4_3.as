/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.7.3.4-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.NaN";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError = "no error";
    try{
        Number.NaN=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Number.NaN","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase(
                    SECTION,
                    "Number.NaN=0; Number.NaN",
                    Number.NaN,
                    Number.NaN );

    return ( array );
}
