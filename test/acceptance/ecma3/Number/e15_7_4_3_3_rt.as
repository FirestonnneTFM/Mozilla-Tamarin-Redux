/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4.3-3-n";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Number.prototype.valueOf()");
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

//    array[item++] = new TestCase("15.7.4.1", "v = Number.prototype.valueOf; num = 3; num.valueOf = v; num.valueOf()", "error",  "v = Number.prototype.valueOf; num = 3; num.valueOf = v; num.valueOf()" );
/*
    v = Number.prototype.valueOf;
    o = new String('Infinity');
    o.valueOf = v;
    array[item++] = new TestCase("15.7.4.1", "v = Number.prototype.valueOf; o = new String('Infinity'); o.valueOf = v; o.valueOf()", "error",  o.valueOf() );*/
//    array[item++] = new TestCase("15.7.4.1", "v = Number.prototype.valueOf; o = new Object(); o.valueOf = v; o.valueOf()", "error",  "v = Number.prototype.valueOf; o = new Object(); o.valueOf = v; o.valueOf()" );
    var v = Number.prototype.valueOf;
    var o = new String('Infinity');

    var expectedError = 1056;
    if (as3Enabled) {
        expectedError = 1037;
    }

    try{
        o.valueOf = v;
        o.valueOf();
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase("15.7.4.1",
                                    "v = Number.prototype.valueOf; o = new String('Infinity'); o.valueOf = v; o.valueOf()",
                                    REFERENCEERROR+expectedError,
                                    referenceError(thisError) );
    }



    return ( array );
}
