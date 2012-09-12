/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4.3";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Number.prototype.toLocaleString()");
    test();

function getTestCases() {
    var array:Array = new Array();
    var item:Number = 0;
    var o:Number = 3;

    var thisError:String = "no error thrown";
    try{

        o.toString = Number.prototype.toString;
    } catch (e:ReferenceError) {
        thisError = e.toString();
    } finally {
        var expectedError = 1056;
        if (as3Enabled) {
            expectedError = 1037;
        }
        array[item++] = new TestCase(SECTION,  "o = 3; o.toString = Number.prototype.toString; o.toLocaleString()",
                                                REFERENCEERROR+expectedError,
                                                referenceError(thisError) );
    }


    return ( array );
}
