/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.8.2.16";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.sin(x)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Math.sin.length",      1,              Math.sin.length );
  /*thisError="no error";
    try{
        Math.sin();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.sin()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION,  "Math.sin()",           Number.NaN,     Math.sin() );*/
    array[item++] = new TestCase( SECTION,  "Math.sin(null)",       0,              Math.sin(null) );
    array[item++] = new TestCase( SECTION,  "Math.sin(void 0)",     Number.NaN,     Math.sin(void 0) );
    array[item++] = new TestCase( SECTION,  "Math.sin(false)",      0,              Math.sin(false) );
    array[item++] = new TestCase( SECTION,  "Math.sin('2.356194490192')",    0.7071067811867916,    Math.sin('2.356194490192') );

    array[item++] = new TestCase( SECTION,  "Math.sin(NaN)",        Number.NaN,     Math.sin(Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.sin(0)",          0,              Math.sin(0) );
    array[item++] = new TestCase( SECTION,  "Math.sin(-0)",         -0,             Math.sin(-0));
    array[item++] = new TestCase( SECTION,  "Math.sin(Infinity)",   Number.NaN,     Math.sin(Number.POSITIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.sin(-Infinity)",  Number.NaN,     Math.sin(Number.NEGATIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.sin(0.7853981633974)",    0.7071067811865134,    Math.sin(0.7853981633974));
    array[item++] = new TestCase( SECTION,  "Math.sin(1.570796326795)",     1,                  Math.sin(1.570796326795));
    array[item++] = new TestCase( SECTION,  "Math.sin(2.356194490192)",     0.7071067811867916,    Math.sin(2.356194490192));
    array[item++] = new TestCase( SECTION,  "Math.sin(3.14159265359)",      -2.0682311115474694e-13,                  Math.sin(3.14159265359));

    return ( array );
}
