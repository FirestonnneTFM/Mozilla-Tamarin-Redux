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

    SwitchTest( -1, 1 );
    SwitchTest( 0, 1 );
    SwitchTest( 2, 1 );

    function SwitchTest( input:uint, expect:uint ) {
        var result = 0;

        switch ( input ) {
            default:
                result += 1;
        }

        array[item++] = new TestCase(
            SECTION,
            "switch with only default case: input is " + input,
            expect,
            result );
    }
    return array;
}
