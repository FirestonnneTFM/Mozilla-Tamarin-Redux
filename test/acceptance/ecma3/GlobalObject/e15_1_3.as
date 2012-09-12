/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15-1.3";
    var VERSION = "ECMA_3";
    startTest();
    var TITLE   = "Unicode Surrogate pairs";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    try {
        decodeURI('\uD800');
    } catch (e ){
        trace( "Exception thrown" );
    }

    array[item++] = new TestCase( SECTION, "escape( false )", "false",  escape( false ) );
    array[item++] = new TestCase( SECTION, "encodeURI('\u007f')", "%7F",  encodeURI('\u007f') );

    return ( array );
}
