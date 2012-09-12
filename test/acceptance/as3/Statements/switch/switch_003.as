/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "switch";
    var VERSION = "ECMA_2";
    var TITLE   = "The switch statement";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    SwitchTest( 0, 4 );
    SwitchTest( 1, 1 );
    SwitchTest( 2, 6 );
    SwitchTest( 6, 4 );
    SwitchTest( 7, 8 );
    SwitchTest( 8, 4 );

    function SwitchTest( input:uint, expect:uint ) {
        var result = 0;

        switch ( input ) {
            case 2:
                result += 2;
            default:
                result += 4;
                break;
            case 1:
                result += 1;
                break;
            case 7:
                result += 8;
                break;
        }

        array[item++] = new TestCase(
            SECTION,
            "switch with out of order cases, fall through and gaps in cases: input is " + input,
            expect,
            result );
    }
    return array;
}