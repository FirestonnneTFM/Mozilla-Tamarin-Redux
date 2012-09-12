/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.6.4.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Boolean.prototype.toString()"
    writeHeaderToLog( SECTION + TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "new Boolean(1)",       "true",   (new Boolean(1)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(0)",       "false",  (new Boolean(0)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(-1)",      "true",   (new Boolean(-1)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean('1')",     "true",   (new Boolean("1")).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean('0')",     "true",   (new Boolean("0")).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(true)",    "true",   (new Boolean(true)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(false)",   "false",  (new Boolean(false)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean('true')",  "true",   (new Boolean('true')).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean('false')", "true",   (new Boolean('false')).toString() );

    array[item++] = new TestCase( SECTION,   "new Boolean('')",      "false",  (new Boolean('')).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(null)",    "false",  (new Boolean(null)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(void(0))", "false",  (new Boolean(void(0))).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(-Infinity)", "true", (new Boolean(Number.NEGATIVE_INFINITY)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(NaN)",     "false",  (new Boolean(Number.NaN)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean()",        "false",  (new Boolean()).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=1)",     "true",   (new Boolean(x=1)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=0)",     "false",  (new Boolean(x=0)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=false)", "false",  (new Boolean(x=false)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=true)",  "true",   (new Boolean(x=true)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=null)",  "false",  (new Boolean(x=null)).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x='')",    "false",  (new Boolean(x="")).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(x=' ')",   "true",   (new Boolean(x=" ")).toString() );

    array[item++] = new TestCase( SECTION,   "new Boolean(new MyObject(true))",     "true",   (new Boolean(new MyObject(true))).toString() );
    array[item++] = new TestCase( SECTION,   "new Boolean(new MyObject(false))",    "true",   (new Boolean(new MyObject(false))).toString() );

    return ( array );
}
function MyObject( value ) {
    this.value = value;
    this.valueOf = function() { return this.value; }
    this.valueOf = function() { return this.value; }
    return this;
}
