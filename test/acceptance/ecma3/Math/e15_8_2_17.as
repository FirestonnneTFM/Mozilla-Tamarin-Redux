/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.2.17";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.sqrt(x)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Math.sqrt.length",     1,              Math.sqrt.length );
  /*thisError="no error";
    try{
        Math.sqrt();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.sqrt()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION,  "Math.sqrt()",          Number.NaN,     Math.sqrt() );*/
    array[item++] = new TestCase( SECTION,  "Math.sqrt(void 0)",    Number.NaN,     Math.sqrt(void 0) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt(null)",      0,              Math.sqrt(null) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt(true)",      1,              Math.sqrt(1) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt(false)",     0,              Math.sqrt(false) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt('225')",     15,             Math.sqrt('225') );

    array[item++] = new TestCase( SECTION,  "Math.sqrt(NaN)",       Number.NaN,     Math.sqrt(Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt(-Infinity)", Number.NaN,     Math.sqrt(Number.NEGATIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(-1)",        Number.NaN,     Math.sqrt(-1));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(-0.5)",      Number.NaN,     Math.sqrt(-0.5));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(0)",         0,              Math.sqrt(0));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(-0)",        -0,             Math.sqrt(-0));
    array[item++] = new TestCase( SECTION,  "Infinity/Math.sqrt(-0)",   -Infinity,  Infinity/Math.sqrt(-0) );
    array[item++] = new TestCase( SECTION,  "Math.sqrt(Infinity)",  Number.POSITIVE_INFINITY,   Math.sqrt(Number.POSITIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(1)",         1,              Math.sqrt(1));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(2)",         Math.SQRT2,     Math.sqrt(2));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(0.5)",       Math.SQRT1_2,   Math.sqrt(0.5));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(4)",         2,              Math.sqrt(4));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(9)",         3,              Math.sqrt(9));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(16)",        4,              Math.sqrt(16));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(25)",        5,              Math.sqrt(25));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(36)",        6,              Math.sqrt(36));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(49)",        7,              Math.sqrt(49));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(64)",        8,              Math.sqrt(64));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(256)",       16,             Math.sqrt(256));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(10000)",     100,            Math.sqrt(10000));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(65536)",     256,            Math.sqrt(65536));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(0.09)",      0.3,            Math.sqrt(0.09));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(0.01)",      0.1,            Math.sqrt(0.01));
    array[item++] = new TestCase( SECTION,  "Math.sqrt(0.00000001)",0.0001,         Math.sqrt(0.00000001));

    return ( array );
}
