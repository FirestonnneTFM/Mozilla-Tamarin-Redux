/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
    In Ecma4 there are three sealed types; Boolean, Number and String
    You cannot set properties of an instance of a sealed type

    Should throw a ReferenceError

    Author:     mtilburg@macromedia.com
    Date:       October 13, 2004

*/
    var SECTION = "ECMA_4";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "valof=Boolean.prototype.valueOf;booleanObj=new Boolean(false);booleanObj.valueOf=valof;";
    writeHeaderToLog( TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var booleanObj = new Boolean(false);
    var thisError = "no error thrown";
    var array = new Array();
    var item = 0;

    try{
        booleanObj.valueOf=true;
    }catch(e){
        thisError=e.toString();
    }finally{
        if (as3Enabled) {
            array[item++] =new TestCase(SECTION,
                                        "Cannot assign to a method toString on Boolean.",
                                        "ReferenceError: Error #1037",
                                        referenceError( thisError ) );
        } else {
            array[item++] =new TestCase(SECTION,
                                        "Cannot create a property on Boolean",
                                        "ReferenceError: Error #1056",
                                        referenceError( thisError ) );
        }
    }

    return ( array );
}
