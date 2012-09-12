/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_4_9";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Logical NOT operator (!)";

    writeHeaderToLog( SECTION + " "+ TITLE);

//    version("130")

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
    
    array[item++] = new TestCase( SECTION,   "!(null)",                true,   !(null) );
    array[item++] = new TestCase( SECTION,   "!(void 0)",              true,   !(void 0) );

    array[item++] = new TestCase( SECTION,   "!(false)",               true,   !(false) );
    array[item++] = new TestCase( SECTION,   "!(true)",                false,  !(true) );
    array[item++] = new TestCase( SECTION,   "!(0)",                   true,   !(0) );
    array[item++] = new TestCase( SECTION,   "!(-0)",                  true,   !(-0) );
    array[item++] = new TestCase( SECTION,   "!(NaN)",                 true,   !(Number.NaN) );
    array[item++] = new TestCase( SECTION,   "!(Infinity)",            false,  !(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "!(-Infinity)",           false,  !(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "!(Math.PI)",             false,  !(Math.PI) );
    array[item++] = new TestCase( SECTION,   "!(1)",                   false,  !(1) );
    array[item++] = new TestCase( SECTION,   "!(-1)",                  false,  !(-1) );
    array[item++] = new TestCase( SECTION,   "!('')",                  true,   !("") );
    array[item++] = new TestCase( SECTION,   "!('\t')",                false,  !("\t") );
    array[item++] = new TestCase( SECTION,   "!('0')",                 false,  !("0") );
    array[item++] = new TestCase( SECTION,   "!('string')",            false,  !("string") );
    array[item++] = new TestCase( SECTION,   "!(new String(''))",      true,  !(new String("")) );
    array[item++] = new TestCase( SECTION,   "!(new String('string'))",    false,  !(new String("string")) );
    array[item++] = new TestCase( SECTION,   "!(new String())",        true,  !(new String()) );
    array[item++] = new TestCase( SECTION,   "!(new Boolean(true))",   false,   !(new Boolean(true)) );
    array[item++] = new TestCase( SECTION,   "!(new Boolean(false))",  true,   !(new Boolean(false)) );
    array[item++] = new TestCase( SECTION,   "!(new Array())",         false,  !(new Array()) );
    array[item++] = new TestCase( SECTION,   "!(new Array(1,2,3)",     false,  !(new Array(1,2,3)) );
    array[item++] = new TestCase( SECTION,   "!(new Number())",        true,  !(new Number()) );
    array[item++] = new TestCase( SECTION,   "!(new Number(0))",       true,  !(new Number(0)) );
    array[item++] = new TestCase( SECTION,   "!(new Number(NaN))",     true,  !(new Number(Number.NaN)) );
    array[item++] = new TestCase( SECTION,   "!(new Number(Infinity))", false, !(new Number(Number.POSITIVE_INFINITY)) );

    return (array);
}

