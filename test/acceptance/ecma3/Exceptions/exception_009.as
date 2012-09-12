/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "exception-009";
    var VERSION = "JS1_4";
    var TITLE   = "Tests for JavaScript Standard Exceptions: SyntaxError";
    var BUGNUMBER= "312964";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    try {
        expect = "passed:  no exception thrown";
        result = expect;
        Nested_1();
    } catch ( e ) {
        result = "failed: threw " + e;
    } finally {
            array[item++] = new TestCase(
                SECTION,
                "nested try",
                expect,
                result );
    }

    function Nested_1() {
        try {
            try {
            } catch (a) {
            } finally {
            }
        } catch (b) {
        } finally {
        }
    }
    return array;
}
