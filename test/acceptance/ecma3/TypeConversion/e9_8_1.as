/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "9.8.1";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " ToString applied to the Number type");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "Number.NaN",       "NaN",                  Number.NaN + "" );
    array[item++] = new TestCase( SECTION,    "0",                "0",                    0 + "" );
    array[item++] = new TestCase( SECTION,    "-0",               "0",                   -0 + "" );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY", "Infinity",     Number.POSITIVE_INFINITY + "" );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY", "-Infinity",    Number.NEGATIVE_INFINITY + "" );
    array[item++] = new TestCase( SECTION,    "-1",               "-1",                   -1 + "" );

    // cases in step 6:  integers  1e21 > x >= 1 or -1 >= x > -1e21

    array[item++] = new TestCase( SECTION,    "1",                    "1",                    1 + "" );
    array[item++] = new TestCase( SECTION,    "10",                   "10",                   10 + "" );
    array[item++] = new TestCase( SECTION,    "100",                  "100",                  100 + "" );
    array[item++] = new TestCase( SECTION,    "1000",                 "1000",                 1000 + "" );
    array[item++] = new TestCase( SECTION,    "10000",                "10000",                10000 + "" );
    array[item++] = new TestCase( SECTION,    "10000000000",          "10000000000",          10000000000 + "" );
    array[item++] = new TestCase( SECTION,    "10000000000000000000", "10000000000000000000", 10000000000000000000 + "" );
    array[item++] = new TestCase( SECTION,    "100000000000000000000","100000000000000000000",100000000000000000000 + "" );

    array[item++] = new TestCase( SECTION,    "12345",                    "12345",                    12345 + "" );
    array[item++] = new TestCase( SECTION,    "1234567890",               "1234567890",               1234567890 + "" );

    array[item++] = new TestCase( SECTION,    "-1",                       "-1",                       -1 + "" );
    array[item++] = new TestCase( SECTION,    "-10",                      "-10",                      -10 + "" );
    array[item++] = new TestCase( SECTION,    "-100",                     "-100",                     -100 + "" );
    array[item++] = new TestCase( SECTION,    "-1000",                    "-1000",                    -1000 + "" );
    array[item++] = new TestCase( SECTION,    "-1000000000",              "-1000000000",              -1000000000 + "" );
    array[item++] = new TestCase( SECTION,    "-1000000000000000",        "-1000000000000000",        -1000000000000000 + "" );
    array[item++] = new TestCase( SECTION,    "-100000000000000000000",   "-100000000000000000000",   -100000000000000000000 + "" );
    array[item++] = new TestCase( SECTION,    "-1000000000000000000000",  "-1e+21",                   -1000000000000000000000 + "" );

    array[item++] = new TestCase( SECTION,    "-12345",                    "-12345",                  -12345 + "" );
    array[item++] = new TestCase( SECTION,    "-1234567890",               "-1234567890",             -1234567890 + "" );

    // cases in step 7: numbers with a fractional component, 1e21> x >1 or  -1 > x > -1e21,
    array[item++] = new TestCase( SECTION,    "1.0000001",                "1.0000001",                1.0000001 + "" );

    // cases in step 8:  fractions between 1 > x > -1, exclusive of 0 and -0

    // cases in step 9:  numbers with 1 significant digit >= 1e+21 or <= 1e-6

    array[item++] = new TestCase( SECTION,    "1000000000000000000000",   "1e+21",             1000000000000000000000 + "" );
    array[item++] = new TestCase( SECTION,    "10000000000000000000000",   "1e+22",            10000000000000000000000 + "" );

    //  cases in step 10:  numbers with more than 1 significant digit >= 1e+21 or <= 1e-6

    array[item++] = new TestCase( SECTION,    "1.2345",                    "1.2345",                  String( 1.2345));
    array[item++] = new TestCase( SECTION,    "1.234567890",               "1.23456789",             String( 1.234567890 ));


    array[item++] = new TestCase( SECTION,    ".12345",                   "0.12345",                String(.12345 )     );
    array[item++] = new TestCase( SECTION,    ".012345",                  "0.012345",               String(.012345)     );
    array[item++] = new TestCase( SECTION,    ".0012345",                 "0.0012345",              String(.0012345)    );
    array[item++] = new TestCase( SECTION,    ".00012345",                "0.00012345",             String(.00012345)   );
    array[item++] = new TestCase( SECTION,    ".000012345",               "0.000012345",            String(.000012345)  );
    array[item++] = new TestCase( SECTION,    ".0000012345",              "0.0000012345",           String(.0000012345) );
    array[item++] = new TestCase( SECTION,    ".00000012345",             "1.2345e-7",              String(.00000012345));

    array[item++] = new TestCase( SECTION,    "-1e21",                    "-1e+21",                 String(-1e21) );
    return ( array );
}
