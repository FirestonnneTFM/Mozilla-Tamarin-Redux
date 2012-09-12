/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "9.6";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Type Conversion:  ToUint32");
    test();

function ToUint32( n ) {
    n = Number( n );
    var sign = ( n < 0 ) ? -1 : 1;

    if ( Math.abs( n ) == 0 || Math.abs( n ) == Number.POSITIVE_INFINITY) {
        return 0;
    }
    n = sign * Math.floor( Math.abs(n) )

    n = n % Math.pow(2,32);

    if ( n < 0 ){
        n += Math.pow(2,32);
    }

    return ( n );
}
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "0 >>> 0",                          0,          0 >>> 0 );
//    array[item++] = new TestCase( SECTION,    "+0 >>> 0",                         0,          +0 >>> 0);
    array[item++] = new TestCase( SECTION,    "-0 >>> 0",                         0,          -0 >>> 0 );
    array[item++] = new TestCase( SECTION,    "'Infinity' >>> 0",                 0,          "Infinity" >>> 0 );
    array[item++] = new TestCase( SECTION,    "'-Infinity' >>> 0",                0,          "-Infinity" >>> 0);
    array[item++] = new TestCase( SECTION,    "'+Infinity' >>> 0",                0,          "+Infinity" >>> 0 );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY >>> 0",   0,          Number.POSITIVE_INFINITY >>> 0 );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY >>> 0",   0,          Number.NEGATIVE_INFINITY >>> 0 );
    array[item++] = new TestCase( SECTION,    "Number.NaN >>> 0",                 0,          Number.NaN >>> 0 );

    array[item++] = new TestCase( SECTION,    "Number.MIN_VALUE >>> 0",           0,          Number.MIN_VALUE >>> 0 );
    array[item++] = new TestCase( SECTION,    "-Number.MIN_VALUE >>> 0",          0,          Number.MIN_VALUE >>> 0 );
    array[item++] = new TestCase( SECTION,    "0.1 >>> 0",                        0,          0.1 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-0.1 >>> 0",                       0,          -0.1 >>> 0 );
    array[item++] = new TestCase( SECTION,    "1 >>> 0",                          1,          1 >>> 0 );
    array[item++] = new TestCase( SECTION,    "1.1 >>> 0",                        1,          1.1 >>> 0 );

    array[item++] = new TestCase( SECTION,    "-1.1 >>> 0",                       ToUint32(-1.1),       -1.1 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-1 >>> 0",                         ToUint32(-1),         -1 >>> 0 );

    array[item++] = new TestCase( SECTION,    "2147483647 >>> 0",         ToUint32(2147483647),     2147483647 >>> 0 );
    array[item++] = new TestCase( SECTION,    "2147483648 >>> 0",         ToUint32(2147483648),     2147483648 >>> 0 );
    array[item++] = new TestCase( SECTION,    "2147483649 >>> 0",         ToUint32(2147483649),     2147483649 >>> 0 );

    array[item++] = new TestCase( SECTION,    "4294967295 >>> 0",         ToUint32(4294967295),     4294967295 >>> 0 );
    array[item++] = new TestCase( SECTION,    "4294967296 >>> 0",         ToUint32(4294967296),     4294967296 >>> 0 );
    array[item++] = new TestCase( SECTION,    "4294967297 >>> 0",         ToUint32(4294967297),     4294967297 >>> 0 );

    array[item++] = new TestCase( SECTION,    "-2147483647 >>> 0",        ToUint32(-2147483647),    -2147483647 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-2147483648 >>> 0",        ToUint32(-2147483648),    -2147483648 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-2147483649 >>> 0",        ToUint32(-2147483649),    -2147483649 >>> 0 );

    array[item++] = new TestCase( SECTION,    "-4294967295 >>> 0",        ToUint32(-4294967295),    -4294967295 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-4294967296 >>> 0",        ToUint32(-4294967296),    -4294967296 >>> 0 );
    array[item++] = new TestCase( SECTION,    "-4294967297 >>> 0",        ToUint32(-4294967297),    -4294967297 >>> 0 );

    array[item++] = new TestCase( SECTION,    "'2147483647' >>> 0",       ToUint32(2147483647),     '2147483647' >>> 0 );
    array[item++] = new TestCase( SECTION,    "'2147483648' >>> 0",       ToUint32(2147483648),     '2147483648' >>> 0 );
    array[item++] = new TestCase( SECTION,    "'2147483649' >>> 0",       ToUint32(2147483649),     '2147483649' >>> 0 );

    array[item++] = new TestCase( SECTION,    "'4294967295' >>> 0",       ToUint32(4294967295),     '4294967295' >>> 0 );
    array[item++] = new TestCase( SECTION,    "'4294967296' >>> 0",       ToUint32(4294967296),     '4294967296' >>> 0 );
    array[item++] = new TestCase( SECTION,    "'4294967297' >>> 0",       ToUint32(4294967297),     '4294967297' >>> 0 );

    return ( array );
}
