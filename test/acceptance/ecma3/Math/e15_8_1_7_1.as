/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.1.7-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.SQRT1_2";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError:String="no error";
    try{
        Math.SQRT1_2=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase(SECTION,"Trying to verify the ReadOnly attribute of Math.SQRT1_2","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION, "Math.SQRT1_2=0; Math.SQRT1_2", 0.7071067811865476, Math.SQRT1_2 );
    return ( array );
}

