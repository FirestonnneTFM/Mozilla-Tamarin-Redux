/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "while-001";
    var VERSION = "ECMA_2";
    var TITLE   = "while statement";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);


    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    DoWhile();

    function DoWhile() {
        result = "pass";

        while (false) {
            result = "fail";
            break;
        }

        array[item++] = new TestCase(
            SECTION,
            "while statement: don't evaluate statement is expression is false",
            "pass",
            result );

    }
    return array;
}
