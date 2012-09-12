/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.6.4.3-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Boolean.prototype.valueOf()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "new Boolean(1)",       true,   (new Boolean(1)).valueOf() );

    array[item++] = new TestCase( SECTION,   "new Boolean(0)",       false,  (new Boolean(0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(-1)",      true,   (new Boolean(-1)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean('1')",     true,   (new Boolean("1")).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean('0')",     true,   (new Boolean("0")).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(true)",    true,   (new Boolean(true)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(false)",   false,  (new Boolean(false)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean('true')",  true,   (new Boolean("true")).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean('false')", true,   (new Boolean('false')).valueOf() );

    array[item++] = new TestCase( SECTION,   "new Boolean('')",      false,  (new Boolean('')).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(null)",    false,  (new Boolean(null)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(void(0))", false,  (new Boolean(void(0))).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(-Infinity)", true, (new Boolean(Number.NEGATIVE_INFINITY)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(NaN)",     false,  (new Boolean(Number.NaN)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean()",        false,  (new Boolean()).valueOf() );

    array[item++] = new TestCase( SECTION,   "new Boolean(x=1)",     true,   (new Boolean(x=1)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=0)",     false,  (new Boolean(x=0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=false)", false,  (new Boolean(x=false)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=true)",  true,   (new Boolean(x=true)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=null)",  false,  (new Boolean(x=null)).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x='')",    false,  (new Boolean(x="")).valueOf() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=' ')",   true,   (new Boolean(x=" ")).valueOf() );

    return ( array );
}
