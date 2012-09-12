/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "9.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "ToBoolean";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    // special cases here

    array[item++] = new TestCase( SECTION,   "Boolean()",                     false,  Boolean() );
    var x;
    array[item++] = new TestCase( SECTION,   "Boolean(var x)",                false,  Boolean(x) );
    array[item++] = new TestCase( SECTION,   "Boolean(void 0)",               false,  Boolean(void 0) );
    array[item++] = new TestCase( SECTION,   "Boolean(null)",                 false,  Boolean(null) );
    array[item++] = new TestCase( SECTION,   "Boolean(false)",                false,  Boolean(false) );
    array[item++] = new TestCase( SECTION,   "Boolean(true)",                 true,   Boolean(true) );
    array[item++] = new TestCase( SECTION,   "Boolean(0)",                    false,  Boolean(0) );
    array[item++] = new TestCase( SECTION,   "Boolean(-0)",                   false,  Boolean(-0) );
    array[item++] = new TestCase( SECTION,   "Boolean(NaN)",                  false,  Boolean(Number.NaN) );
    array[item++] = new TestCase( SECTION,   "Boolean('')",                   false,  Boolean("") );

    // normal test cases here

    array[item++] = new TestCase( SECTION,   "Boolean(Infinity)",             true,   Boolean(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Boolean(-Infinity)",            true,   Boolean(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Boolean(Math.PI)",              true,   Boolean(Math.PI) );
    array[item++] = new TestCase( SECTION,   "Boolean(1)",                    true,   Boolean(1) );
    array[item++] = new TestCase( SECTION,   "Boolean(-1)",                   true,   Boolean(-1) );
    array[item++] = new TestCase( SECTION,   "Boolean([tab])",                true,   Boolean("\t") );
    array[item++] = new TestCase( SECTION,   "Boolean('0')",                  true,   Boolean("0") );
    array[item++] = new TestCase( SECTION,   "Boolean('string')",             true,   Boolean("string") );

    // ToBoolean (object) should always return true.
    array[item++] = new TestCase( SECTION,   "Boolean(new String() )",        false,   Boolean(new String()) );
    array[item++] = new TestCase( SECTION,   "Boolean(new String('') )",      false,   Boolean(new String("")) );

    array[item++] = new TestCase( SECTION,   "Boolean(new Boolean(true))",    true,   Boolean(new Boolean(true)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Boolean(false))",   false,   Boolean(new Boolean(false)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Boolean() )",       false,   Boolean(new Boolean()) );

    array[item++] = new TestCase( SECTION,   "Boolean(new Array())",          true,   Boolean(new Array()) );

    array[item++] = new TestCase( SECTION,   "Boolean(new Number())",         false,   Boolean(new Number()) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Number(-0))",       false,   Boolean(new Number(-0)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Number(0))",        false,   Boolean(new Number(0)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Number(NaN))",      false,   Boolean(new Number(Number.NaN)) );

    array[item++] = new TestCase( SECTION,   "Boolean(new Number(-1))",       true,   Boolean(new Number(-1)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Number(Infinity))", true,   Boolean(new Number(Number.POSITIVE_INFINITY)) );
    array[item++] = new TestCase( SECTION,   "Boolean(new Number(-Infinity))",true,   Boolean(new Number(Number.NEGATIVE_INFINITY)) );

    array[item++] = new TestCase( SECTION,    "Boolean(new Object())",       true,       Boolean(new Object()) );
    array[item++] = new TestCase( SECTION,    "Boolean(new Function())",     true,       Boolean(new Function()) );
    array[item++] = new TestCase( SECTION,    "Boolean(new Date())",         true,       Boolean(new Date()) );
    array[item++] = new TestCase( SECTION,    "Boolean(new Date(0))",         true,       Boolean(new Date(0)) );
    array[item++] = new TestCase( SECTION,    "Boolean(Math)",         true,       Boolean(Math) );
    
    return array;
}
