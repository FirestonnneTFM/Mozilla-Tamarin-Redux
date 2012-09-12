/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_5_1";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Applying the * operator");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "Number.NaN * Number.NaN",    Number.NaN,     Number.NaN * Number.NaN );
    array[item++] = new TestCase( SECTION,    "Number.NaN * 1",             Number.NaN,     Number.NaN * 1 );
    array[item++] = new TestCase( SECTION,    "1 * Number.NaN",             Number.NaN,     1 * Number.NaN );

    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * 0",   Number.NaN, Number.POSITIVE_INFINITY * 0 );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * 0",   Number.NaN, Number.NEGATIVE_INFINITY * 0 );
    array[item++] = new TestCase( SECTION,    "0 * Number.POSITIVE_INFINITY",   Number.NaN, 0 * Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "0 * Number.NEGATIVE_INFINITY",   Number.NaN, 0 * Number.NEGATIVE_INFINITY );

    array[item++] = new TestCase( SECTION,    "-0 * Number.POSITIVE_INFINITY",  Number.NaN,   -0 * Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "-0 * Number.NEGATIVE_INFINITY",  Number.NaN,   -0 * Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * -0",  Number.NaN,   Number.POSITIVE_INFINITY * -0 );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * -0",  Number.NaN,   Number.NEGATIVE_INFINITY * -0 );

    array[item++] = new TestCase( SECTION,    "0 * -0",                         -0,         0 * -0 );
    array[item++] = new TestCase( SECTION,    "-0 * 0",                         -0,         -0 * 0 );
    array[item++] = new TestCase( SECTION,    "-0 * -0",                        0,          -0 * -0 );
    array[item++] = new TestCase( SECTION,    "0 * 0",                          0,          0 * 0 );

    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * Number.NEGATIVE_INFINITY",    Number.POSITIVE_INFINITY,   Number.NEGATIVE_INFINITY * Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * Number.NEGATIVE_INFINITY",    Number.NEGATIVE_INFINITY,   Number.POSITIVE_INFINITY * Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * Number.POSITIVE_INFINITY",    Number.NEGATIVE_INFINITY,   Number.NEGATIVE_INFINITY * Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * Number.POSITIVE_INFINITY",    Number.POSITIVE_INFINITY,   Number.POSITIVE_INFINITY * Number.POSITIVE_INFINITY );

    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * 1 ",                          Number.NEGATIVE_INFINITY,   Number.NEGATIVE_INFINITY * 1 );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY * -1 ",                         Number.POSITIVE_INFINITY,   Number.NEGATIVE_INFINITY * -1 );
    array[item++] = new TestCase( SECTION,    "1 * Number.NEGATIVE_INFINITY",                           Number.NEGATIVE_INFINITY,   1 * Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "-1 * Number.NEGATIVE_INFINITY",                          Number.POSITIVE_INFINITY,   -1 * Number.NEGATIVE_INFINITY );

    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * 1 ",                          Number.POSITIVE_INFINITY,   Number.POSITIVE_INFINITY * 1 );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY * -1 ",                         Number.NEGATIVE_INFINITY,   Number.POSITIVE_INFINITY * -1 );
    array[item++] = new TestCase( SECTION,    "1 * Number.POSITIVE_INFINITY",                           Number.POSITIVE_INFINITY,   1 * Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "-1 * Number.POSITIVE_INFINITY",                          Number.NEGATIVE_INFINITY,   -1 * Number.POSITIVE_INFINITY );

    array[item++] = new TestCase( SECTION,    "-1.0 * Number.MAX_VALUE",                         -Number.MAX_VALUE,     -1.0 * Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION,    "1.1 * Number.MAX_VALUE",                          Number.POSITIVE_INFINITY,   1.1 * Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION,    "-1.1 * Number.MAX_VALUE",                         Number.NEGATIVE_INFINITY,   -1.1 * Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION,    "Number.MAX_VALUE * Number.MAX_VALUE",             Number.POSITIVE_INFINITY,   Number.MAX_VALUE * Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION,    "(Number.MAX_VALUE-1) * (Number.MAX_VALUE-1)",     Number.POSITIVE_INFINITY,   (Number.MAX_VALUE-1) * (Number.MAX_VALUE-1) );
    array[item++] = new TestCase( SECTION,    "-1 * Number.MAX_VALUE * Number.MAX_VALUE",        Number.NEGATIVE_INFINITY,   -1 * Number.MAX_VALUE * Number.MAX_VALUE );

    array[item++] = new TestCase( SECTION,    "-1 * Number.MIN_VALUE",                           -4.9406564584124654e-324,   -1 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "0.9 * Number.MIN_VALUE",                          4.9406564584124654e-324,    0.9 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "-0.9 * Number.MIN_VALUE",                         -4.9406564584124654e-324, -0.9 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "0.51 * Number.MIN_VALUE",                          4.9406564584124654e-324,   0.51 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "-0.51 * Number.MIN_VALUE",                         -4.9406564584124654e-324, -0.51 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "0.5 * Number.MIN_VALUE",                          0,                          0.5 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "-0.5 * Number.MIN_VALUE",                         -0,                         -0.5 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "0.1 * Number.MIN_VALUE",                          0,                          0.1 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "-0.1 * Number.MIN_VALUE",                         -0,                         -0.1 * Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "Number.MIN_VALUE * Number.MIN_VALUE",             0,                          Number.MIN_VALUE * Number.MIN_VALUE );

    array[item++] = new TestCase( SECTION,    "1 * 1",        1,      1 * 1 );
    array[item++] = new TestCase( SECTION,    "-1 * 1",      -1,     -1 * 1 );
    array[item++] = new TestCase( SECTION,    "1 * (-1)",    -1,      1 * (-1) );
    array[item++] = new TestCase( SECTION,    "-1 * (-1)",    1,     -1 * (-1) );
    
    

    return ( array );
}
