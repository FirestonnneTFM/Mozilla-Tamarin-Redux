/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
   Modified 1/5/2005 by Sushant Dutta (sdutta@macromedia.com)
   
   Changed the expected result from Number.POSITIVE_INFINITY to Infinity
*/

    var SECTION = "15.7.3.6-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.POSITIVE_INFINITY";

    writeHeaderToLog( SECTION + " "+TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError:String = "no error"
    try{
        Number.POSITIVE_INFINITY=0;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Verifying the ReadOnly attribute of Number.POSITIVE_INFINITY","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase(
                    SECTION,
                    "Number.POSITIVE_INFINITY=0; Number.POSITIVE_INFINITY",
                    Infinity,
                    Number.POSITIVE_INFINITY );
    return ( array );
}
