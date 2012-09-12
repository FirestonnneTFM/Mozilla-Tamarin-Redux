/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "Types: uint";
    var VERSION = "as3";
    startTest();
    var TITLE   = "typeof an int";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var i:uint = 3;
    var result;
    try{
        result = typeof i;
    } catch (e) {
        result = "exception thrown";
    } finally {
        array[item++] = new TestCase(SECTION, "typeof i:int",        "number",        result );
    }
    return ( array );
}
function test() {
    for ( tc = 0; tc < testcases.length; tc++ ) {
        testcases[tc].passed = writeTestCaseResult(
                            testcases[tc].expect,
                            testcases[tc].actual,
                            testcases[tc].description +" = "+ testcases[tc].actual );

        testcases[tc].reason += ( testcases[tc].passed ) ? "" : "delete should not be allowed "
    }
    stopTest();
    return ( testcases );
}
