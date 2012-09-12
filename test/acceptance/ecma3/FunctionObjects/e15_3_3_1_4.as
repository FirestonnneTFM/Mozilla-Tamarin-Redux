/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.3.1-4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function.prototype";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    
    try{
        Function.prototype = null;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Trying to verify that Function.prototype is Readonly","ReferenceError: Error #1074",referenceError(thisError));
    }
    
    return ( array );
}
