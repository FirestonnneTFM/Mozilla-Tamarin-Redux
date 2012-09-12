/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_4_2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The void operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "void(new String('string object'))",      void 0,  void(new String( 'string object' )) );
    array[item++] = new TestCase( SECTION,   "void('string primitive')",               void 0,  void("string primitive") );
    array[item++] = new TestCase( SECTION,   "void(Number.NaN)",                       void 0,  void(Number.NaN) );
    array[item++] = new TestCase( SECTION,   "void(Number.POSITIVE_INFINITY)",         void 0,  void(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "void(1)",                                void 0,  void(1) );
    array[item++] = new TestCase( SECTION,   "void(0)",                                void 0,  void(0) );
    array[item++] = new TestCase( SECTION,   "void(-1)",                               void 0,  void(-1) );
    array[item++] = new TestCase( SECTION,   "void(Number.NEGATIVE_INFINITY)",         void 0,  void(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "void(Math.PI)",                          void 0,  void(Math.PI) );
    array[item++] = new TestCase( SECTION,   "void(true)",                             void 0,  void(true) );
    array[item++] = new TestCase( SECTION,   "void(false)",                            void 0,  void(false) );
    array[item++] = new TestCase( SECTION,   "void(null)",                             void 0,  void(null) );
    array[item++] = new TestCase( SECTION,   "void new String('string object')",      void 0,  void new String( 'string object' ) );
    array[item++] = new TestCase( SECTION,   "void 'string primitive'",               void 0,  void "string primitive" );
    array[item++] = new TestCase( SECTION,   "void Number.NaN",                       void 0,  void Number.NaN );
    array[item++] = new TestCase( SECTION,   "void Number.POSITIVE_INFINITY",         void 0,  void Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,   "void 1",                                void 0,  void 1 );
    array[item++] = new TestCase( SECTION,   "void 0",                                void 0,  void 0 );
    array[item++] = new TestCase( SECTION,   "void -1",                               void 0,  void -1 );
    array[item++] = new TestCase( SECTION,   "void Number.NEGATIVE_INFINITY",         void 0,  void Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION,   "void Math.PI",                          void 0,  void Math.PI );
    array[item++] = new TestCase( SECTION,   "void true",                             void 0,  void true );
    array[item++] = new TestCase( SECTION,   "void false",                            void 0,  void false );
    array[item++] = new TestCase( SECTION,   "void null",                             void 0,  void null );

//     array[item++] = new TestCase( SECTION,   "void()",                                 void 0,  void() );

    return ( array );
}

function test() {
    for ( i = 0; i < testcases.length; i++ ) {
            testcases[i].passed = writeTestCaseResult(
                    testcases[i].expect,
                    testcases[i].actual,
                    testcases[i].description +" = "+ testcases[i].actual );
            testcases[i].reason += ( testcases[i].passed ) ? "" : "wrong value "
    }
    stopTest();
    return ( testcases );
}
