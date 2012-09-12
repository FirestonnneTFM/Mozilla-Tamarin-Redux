/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "10.1.4-9";
    var VERSION = "ECMA_2";
    startTest();

    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Scope Chain and Identifier Resolution");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "with MyObject, NEW_PROPERTY", "", "" );

    for ( tc=0; tc < array.length; tc++ ) {

        var MYOBJECT = new MyObject();
        var RESULT   = "hello";

        with ( MYOBJECT ) {
            NEW_PROPERTY = RESULT;
        }
        array[tc].actual = NEW_PROPERTY;
        array[tc].expect = RESULT;

    }

    return ( array );
}
function MyObject( n ) {
    // cn:  __proto__ not ecma3 compliant
    //this.__proto__ = Number.prototype;
}
