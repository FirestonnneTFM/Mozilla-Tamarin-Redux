/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "Types: uint";
    var VERSION = "as3";
    startTest();
    var TITLE   = "x is uint";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var c = 0;
    array[item++] = new TestCase(SECTION, "var c=0;c is uint",true, c is uint );
    array[item++] = new TestCase(SECTION, "0 is uint",true, 0 is uint );

    var d = 1;
    array[item++] = new TestCase(SECTION, "var d=1;d is uint",true, d is uint );
    array[item++] = new TestCase(SECTION, "1 is uint",true, 1 is uint );

    var e = uint.MAX_VALUE;
    array[item++] = new TestCase(SECTION, "var e=uint.MAX_VALUE;e is uint",true, e is uint );
    array[item++] = new TestCase(SECTION, "uint.MAX_VALUE is uint",true, uint.MAX_VALUE is uint );
    array[item++] = new TestCase(SECTION, "4294967295 is uint",true, 4294967295 is uint );

    var f:int = -1;
    array[item++] = new TestCase(SECTION, "var f=-1;f is uint",false, f is uint );
    array[item++] = new TestCase(SECTION, "-1 is uint",false, -1 is uint );

    var g:int = int.MAX_VALUE;
    array[item++] = new TestCase(SECTION, "var g=int.MAX_VALUE;g is uint",true, g is uint );
    array[item++] = new TestCase(SECTION, "int.MAX_VALUE is uint",true, int.MAX_VALUE is uint );
    array[item++] = new TestCase(SECTION, "2147483647 is uint",true, 2147483647 is uint );

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
