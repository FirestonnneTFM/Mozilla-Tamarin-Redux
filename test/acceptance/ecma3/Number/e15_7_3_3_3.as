/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.3.3-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.MIN_VALUE:  ReadOnly Attribute";

    writeHeaderToLog( SECTION + " "+TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError:String="no error";
    try{
        Number.MIN_VALUE=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Number.MIN_VALUE","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase(
                    SECTION,
                    "Number.MIN_VALUE=0; Number.MIN_VALUE",
                    Number.MIN_VALUE,
                    Number.MIN_VALUE );
    return ( array );
}
