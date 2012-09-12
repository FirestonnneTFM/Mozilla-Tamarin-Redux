/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "exception-004";
    var VERSION = "js1_4";
    var TITLE   = "Tests for Actionscript Standard Exceptions: ToObjectError";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    ToObject_1();

    function ToObject_1() {
        result = "failed: no exception thrown";
        exception = null;

        try {
           result = foo["bar"];
        } catch ( e ) {
            result = "passed:  threw exception",
            exception = e.toString();
        } finally {
            array[item++] = new TestCase(
                SECTION,
                "foo[\"bar\"]",
                REFERENCEERROR+1065,
                referenceError( exception ) );
        }
    }
    return array;
}
