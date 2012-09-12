/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.8.1.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.LN10";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    try{
        Math.LN10=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]= new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Math.LN10","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION, "Math.LN10=0; Math.LN10",   2.302585092994046,      Math.LN10 );
    return ( array );
}
