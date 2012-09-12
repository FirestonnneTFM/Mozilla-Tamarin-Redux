/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "11.11";
    var VERSION = "ECMA_1";
    var BUGNUMBER="771111";

    startTest();
    var testcases = getTestCases();
    writeHeaderToLog( SECTION + " The Binary Logical Operator ( && )");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "void 0 && void 0",        undefined,   void 0 && void 0 );
    array[item++] = new TestCase( SECTION,    "null && null",          null,   null && null );
    array[item++] = new TestCase( SECTION,    "0 && 0",        0,   0 && 0 );
    array[item++] = new TestCase( SECTION,    "1 && 1",          1,   1 && 1 );
    array[item++] = new TestCase( SECTION,    "-1 && -1",          -1,   -1 && -1 );
    array[item++] = new TestCase( SECTION,    "54 && 54",          54,   54 && 54 );
    array[item++] = new TestCase( SECTION,    "54 && 45",          45,   54 && 45 );
    array[item++] = new TestCase( SECTION,    "true && true",          true,   true && true );
    array[item++] = new TestCase( SECTION,    "true && false",          false,   true && false );
    array[item++] = new TestCase( SECTION,    "false && true",          false,   false && true );
    array[item++] = new TestCase( SECTION,    "false && false",          false,   false && false );
    array[item++] = new TestCase( SECTION,    "0 && true",          0,   0 && true );
    array[item++] = new TestCase( SECTION,    "true && 0",          0,   true && 0 );
    array[item++] = new TestCase( SECTION,    "true && 1",          1,   true && 1 );
    array[item++] = new TestCase( SECTION,    "1 && true",          true,   1 && true );
    array[item++] = new TestCase( SECTION,    "-1 && true",          true,   -1 && true );
    array[item++] = new TestCase( SECTION,    "true && -1",          -1,   true && -1 );
    array[item++] = new TestCase( SECTION,    "true && 9",          9,   true && 9 );
    array[item++] = new TestCase( SECTION,    "true && -9",          -9,   true && -9 );
    array[item++] = new TestCase( SECTION,    "9 && true",          true,   9 && true );
    array[item++] = new TestCase( SECTION,    "true && Number.POSITIVE_INFINITY",          Number.POSITIVE_INFINITY,   true && Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY && true",          true,   Number.NEGATIVE_INFINITY && true );
    array[item++] = new TestCase( SECTION,    "true && 'str'",          "str",   true && "str" );
    array[item++] = new TestCase( SECTION,    "'str' && true",          true,   "str" && true);
    array[item++] = new TestCase( SECTION,    "false && 'str'",          false,   false && "str" );
    array[item++] = new TestCase( SECTION,    "'str' && false",          false,   "str" && false);
    array[item++] = new TestCase( SECTION,    "NaN && NaN",             NaN,  Number.NaN && Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN && 0",               NaN,  Number.NaN && 0 );
    array[item++] = new TestCase( SECTION,    "0 && NaN",               0,  0 && Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN && Infinity",        NaN,  Number.NaN && Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Infinity && NaN",        NaN,  Number.POSITIVE_INFINITY && Number.NaN );

    array[item++] = new TestCase( SECTION,    "void 0 || void 0",        undefined,   void 0 || void 0 );
    array[item++] = new TestCase( SECTION,    "null || null",          null,   null || null );
    array[item++] = new TestCase( SECTION,    "0 || 0",        0,   0 || 0 );
    array[item++] = new TestCase( SECTION,    "1 || 1",          1,   1 || 1 );
    array[item++] = new TestCase( SECTION,    "-1 || -1",          -1,   -1 || -1 );
    array[item++] = new TestCase( SECTION,    "54 || 54",          54,   54 || 54 );
    array[item++] = new TestCase( SECTION,    "54 || 45",          54,   54 || 45 );
    array[item++] = new TestCase( SECTION,    "true || true",          true,   true || true );
    array[item++] = new TestCase( SECTION,    "true || false",          true,   true || false );
    array[item++] = new TestCase( SECTION,    "false || true",          true,   false || true );
    array[item++] = new TestCase( SECTION,    "false || false",          false,   false ||false );
    array[item++] = new TestCase( SECTION,    "0 || true",          true,   0 || true );
    array[item++] = new TestCase( SECTION,    "true || 0",          true,   true || 0 );
    array[item++] = new TestCase( SECTION,    "true || 1",          true,   true || 1 );
    array[item++] = new TestCase( SECTION,    "1 || true",          1,   1 || true );
    array[item++] = new TestCase( SECTION,    "-1 || true",          -1,   -1 || true );
    array[item++] = new TestCase( SECTION,    "true || -1",          true,   true || -1 );
    array[item++] = new TestCase( SECTION,    "true || 9",          true,   true || 9 );
    array[item++] = new TestCase( SECTION,    "true || -9",          true,   true || -9 );
    array[item++] = new TestCase( SECTION,    "9 || true",          9,   9 || true );
    array[item++] = new TestCase( SECTION,    "true || Number.POSITIVE_INFINITY",          true,   true || Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY || true",          Number.NEGATIVE_INFINITY,   Number.NEGATIVE_INFINITY ||true );
    array[item++] = new TestCase( SECTION,    "true || 'str'",          true,   true || "str" );
    array[item++] = new TestCase( SECTION,    "'str'|| true",          "str",   "str" || true);
    array[item++] = new TestCase( SECTION,    "false || 'str'",          "str",   false ||"str" );
    array[item++] = new TestCase( SECTION,    "'str' || false",         "str",   "str" || false);
    array[item++] = new TestCase( SECTION,    "NaN || NaN",             NaN,  Number.NaN || Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN || 0",              0,  Number.NaN || 0 );
    array[item++] = new TestCase( SECTION,    "0 || NaN",               NaN,  0 || Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN || Infinity",       Infinity,  Number.NaN ||Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Infinity || NaN",        Infinity,  Number.POSITIVE_INFINITY || Number.NaN );

    return ( array );
}
