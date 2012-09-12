/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "10.5.1-3";
    var VERSION = "ECMA_1";
    startTest();
    writeHeaderToLog( SECTION + " Global Ojbect");

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[0] = new TestCase( "SECTION", "Function Code check", "", "" );

    if ( Object == null ) {
        array[0].reason += " Object == null" ;
    }
    if ( Function == null ) {
        array[0].reason += " Function == null";
    }
    if ( String == null ) {
        array[0].reason += " String == null";
    }
    if ( Array == null ) {
        array[0].reason += " Array == null";
    }
    if ( Number == null ) {
        array[0].reason += " Function == null";
    }
    if ( Math == null ) {
        array[0].reason += " Math == null";
    }
    if ( Boolean == null ) {
        array[0].reason += " Boolean == null";
    }
    if ( Date  == null ) {
        array[0].reason += " Date == null";
    }
/*
    if ( NaN == null ) {
        array[0].reason += " NaN == null";
    }
    if ( Infinity == null ) {
        array[0].reason += " Infinity == null";
    }

    if ( eval == null ) {
        array[0].reason += " eval == null";
    }
    */
    if ( parseInt == null ) {
        array[0].reason += " parseInt == null";
    }

    if ( array[0].reason != "" ) {
        array[0].actual = "fail";
    } else {
        array[0].actual = "pass";
    }
    array[0].expect = "pass";

    return ( array );
}
