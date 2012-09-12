/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.6.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Boolean constructor called as a function: Boolean( value ) and Boolean()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "Boolean(1)",         true,   Boolean(1) );
    array[item++] = new TestCase( SECTION,   "Boolean(0)",         false,  Boolean(0) );
    array[item++] = new TestCase( SECTION,   "Boolean(-1)",        true,   Boolean(-1) );
    array[item++] = new TestCase( SECTION,   "Boolean('1')",       true,   Boolean("1") );
    array[item++] = new TestCase( SECTION,   "Boolean('0')",       true,   Boolean("0") );
    array[item++] = new TestCase( SECTION,   "Boolean('-1')",      true,   Boolean("-1") );
    array[item++] = new TestCase( SECTION,   "Boolean(true)",      true,   Boolean(true) );
    array[item++] = new TestCase( SECTION,   "Boolean(false)",     false,  Boolean(false) );

    array[item++] = new TestCase( SECTION,   "Boolean('true')",    true,   Boolean("true") );
    array[item++] = new TestCase( SECTION,   "Boolean('false')",   true,   Boolean("false") );
    array[item++] = new TestCase( SECTION,   "Boolean(null)",      false,  Boolean(null) );

    array[item++] = new TestCase( SECTION,   "Boolean(-Infinity)", true,   Boolean(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Boolean(NaN)",       false,  Boolean(Number.NaN) );
    array[item++] = new TestCase( SECTION,   "Boolean(void(0))",   false,  Boolean( void(0) ) );
    array[item++] = new TestCase( SECTION,   "Boolean(x=0)",       false,  Boolean( x=0 ) );
    array[item++] = new TestCase( SECTION,   "Boolean(x=1)",       true,   Boolean( x=1 ) );
    array[item++] = new TestCase( SECTION,   "Boolean(x=false)",   false,  Boolean( x=false ) );
    array[item++] = new TestCase( SECTION,   "Boolean(x=true)",    true,   Boolean( x=true ) );
    array[item++] = new TestCase( SECTION,   "Boolean(x=null)",    false,  Boolean( x=null ) );
    array[item++] = new TestCase( SECTION,   "Boolean()",          false,  Boolean() );
//    array[item++] = new TestCase( SECTION,   "Boolean(var someVar)",     false,  Boolean( someVar ) );

    return ( array );
}
