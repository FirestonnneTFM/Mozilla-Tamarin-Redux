/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "10.2.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Global Code";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var THIS = this;

    array[item++] = new TestCase( SECTION,
                                    "this +''",
                                    GLOBAL,
                                    THIS + "" );

    var GLOBAL_PROPERTIES = new Array();
    var i = 0;

    for ( p in this ) {
        GLOBAL_PROPERTIES[i++] = p;
    }

    for ( i = 0; i < GLOBAL_PROPERTIES.length; i++ ) {
        array[item++] = new TestCase( SECTION,
                                        GLOBAL_PROPERTIES[i] +" == void 0",
                                        false,
                                        (GLOBAL_PROPERTIES[i] == void 0));
    }

    return ( array );
}
