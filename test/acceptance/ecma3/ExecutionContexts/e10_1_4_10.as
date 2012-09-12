/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "10.1.4-10";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Scope Chain and Identifier Resolution");

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( "SECTION", "MYOBJECT.toString()", "", "" );

    for ( tc=0; tc < array.length; tc++ ) {
        var VALUE = 12345;
        var MYOBJECT = new Number( VALUE );

        with ( MYOBJECT ) {
            array[tc].actual = toString();
            array[tc].expect = String(VALUE);
        }
    }

    return ( array );
}
