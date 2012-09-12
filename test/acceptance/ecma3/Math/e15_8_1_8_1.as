/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.1.8-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.SQRT2";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError:String="no error";
    try{
        Math.SQRT2=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Math.SQRT2","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION, "Math.SQRT2=0; Math.SQRT2", 1.4142135623730951,     Math.SQRT2 );
    return ( array );
}
