/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.7.3.2-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.MAX_VALUE";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var MAX_VAL = 1.7976931348623157e308;
    var thisError = "no error";
    try{
        Number.MAX_VALUE=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]= new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Number.MAX_VALUE","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION,
                                  "Number.MAX_VALUE=0; Number.MAX_VALUE",
                                   MAX_VAL,
                                   Number.MAX_VALUE );
    return ( array );
}
