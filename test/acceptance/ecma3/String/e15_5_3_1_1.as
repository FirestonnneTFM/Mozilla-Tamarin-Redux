/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.3.1-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the String Constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    // bug 104702 NAB - since we decided String.prototype is a vanilla object
    array[item++] = new TestCase( SECTION, "String.prototype.length",   undefined,  String.prototype.length );

    var str = '';
    for (p in String ) {
        if ( p == 'prototype' )
            str += p;
    } str

    array[item++] = new TestCase(   SECTION,
                                    "var str='';for ( p in String ) { if ( p == 'prototype' ) str += p; } str",
                                    "",
                                    str );
    return ( array );
}
