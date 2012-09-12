/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.3.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the String Constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var thisError = "no exception thrown";
    try{
        String.prototype=null;
    } catch(e) {
        thisError=e.toString()
    } finally {
        array[item++] = new TestCase( SECTION,
                                "String.prototype=null;String.prototype",
                                "ReferenceError: Error #1074",
                                referenceError( thisError) );
    }
    return ( array );
}
