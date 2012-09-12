/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "exception-006";
    var VERSION = "js1_4";
    var TITLE   = "Tests for JavaScript Standard Exceptions: TypeError";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    ToPrimitive_1();


    function MyObject() {
        this.toString = void 0;
        this.valueOf = void 0;
    }

    function ToPrimitive_1() {
        result = "failed: no exception thrown";
        exception = null;

        try {
           result = new MyObject() + new MyObject();
        } catch ( e ) {
            result = "passed:  threw exception",
            exception = e.toString();
        } finally {
            array[item++] = new TestCase(
                SECTION,
                "new MyObject() + new MyObject()",
                "TypeError: Error #1006",
                typeError( exception ) );
        }
    }
    
    return array;
}
