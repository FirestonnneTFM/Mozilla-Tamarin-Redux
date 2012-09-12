/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.6.4.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the Boolean Object:  valueOf"
    writeHeaderToLog( SECTION + TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "(new Boolean(1)).valueOf()",       true,   (new Boolean(1)).valueOf() );

    array[item++] = new TestCase( SECTION,   "(new Boolean(0)).valueOf()",       false,  (new Boolean(0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(-1)).valueOf()",      true,   (new Boolean(-1)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean('1')).valueOf()",     true,   (new Boolean("1")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean('0')).valueOf()",     true,   (new Boolean("0")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(true)).valueOf()",    true,   (new Boolean(true)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(false)).valueOf()",   false,  (new Boolean(false)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean('true')).valueOf()",  true,   (new Boolean("true")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean('false')).valueOf()", true,   (new Boolean('false')).valueOf() );

    array[item++] = new TestCase( SECTION,   "(new Boolean('')).valueOf()",      false,  (new Boolean('')).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(null)).valueOf()",    false,  (new Boolean(null)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(void(0))).valueOf()", false,  (new Boolean(void(0))).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(-Infinity)).valueOf()", true, (new Boolean(Number.NEGATIVE_INFINITY)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(NaN)).valueOf()",     false,  (new Boolean(Number.NaN)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean()).valueOf()",        false,  (new Boolean()).valueOf() );

    array[item++] = new TestCase( SECTION,   "(new Boolean(x=1)).valueOf()",     true,   (new Boolean(x=1)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x=0)).valueOf()",     false,  (new Boolean(x=0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x=false)).valueOf()", false,  (new Boolean(x=false)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x=true)).valueOf()",  true,   (new Boolean(x=true)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x=null)).valueOf()",  false,  (new Boolean(x=null)).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x='')).valueOf()",    false,  (new Boolean(x="")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new Boolean(x=' ')).valueOf()",   true,   (new Boolean(x=" ")).valueOf() );

    return ( array );
}
