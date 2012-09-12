/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.5.4.3-3-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.valueOf";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var valof=String.prototype.valueOf;
    astring=new Number();
    
    var expectedError = 1056;
    if (as3Enabled) {
        expectedError = 1037;
    }
    try{
        astring.valueOf = valof;
    }catch(e:Error){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase( SECTION,
                "var valof=String.prototype.valueOf; astring=new Number(); astring.valueOf = valof; astring.valueOf()",
                REFERENCEERROR+expectedError,
                referenceError(thisError) )
    }

    

    return ( array );
}
