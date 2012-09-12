/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.2.15";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.round(x)";
    var BUGNUMBER="331411";

    var EXCLUDE = "true";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Math.round.length",   1,               Math.round.length );
  /*thisError="no error";
    try{
        Math.round();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.round()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION,  "Math.round()",         Number.NaN,     Math.round() );*/
    array[item++] = new TestCase( SECTION,  "Math.round(null)",     0,              Math.round(0) );
    array[item++] = new TestCase( SECTION,  "Math.round(void 0)",   Number.NaN,     Math.round(void 0) );
    array[item++] = new TestCase( SECTION,  "Math.round(true)",     1,              Math.round(true) );
    array[item++] = new TestCase( SECTION,  "Math.round(false)",    0,              Math.round(false) );
    array[item++] = new TestCase( SECTION,  "Math.round('.99999')",  1,              Math.round('.99999') );
    array[item++] = new TestCase( SECTION,  "Math.round('12345e-2')",  123,          Math.round('12345e-2') );

    array[item++] = new TestCase( SECTION,  "Math.round(NaN)",      Number.NaN,     Math.round(Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.round(0)",        0,              Math.round(0) );
    array[item++] = new TestCase( SECTION,  "Math.round(-0)",        0,            Math.round(-0));
    array[item++] = new TestCase( SECTION,  "Infinity/Math.round(-0)",  Infinity,  Infinity/Math.round(-0) );

    array[item++] = new TestCase( SECTION,  "Math.round(Infinity)", Number.POSITIVE_INFINITY,   Math.round(Number.POSITIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.round(-Infinity)",Number.NEGATIVE_INFINITY,       Math.round(Number.NEGATIVE_INFINITY));
    array[item++] = new TestCase( SECTION,  "Math.round(0.49)",     0,              Math.round(0.49));
    array[item++] = new TestCase( SECTION,  "Math.round(0.5)",      1,              Math.round(0.5));
    array[item++] = new TestCase( SECTION,  "Math.round(0.51)",     1,              Math.round(0.51));

    array[item++] = new TestCase( SECTION,  "Math.round(-0.49)",    0,             Math.round(-0.49));
    array[item++] = new TestCase( SECTION,  "Math.round(-0.5)",     0,             Math.round(-0.5));
    array[item++] = new TestCase( SECTION,  "Infinity/Math.round(-0.49)",    Infinity,             Infinity/Math.round(-0.49));
    array[item++] = new TestCase( SECTION,  "Infinity/Math.round(-0.5)",     Infinity,             Infinity/Math.round(-0.5));

    array[item++] = new TestCase( SECTION,  "Math.round(-0.51)",    -1,             Math.round(-0.51));
    array[item++] = new TestCase( SECTION,  "Math.round(3.5)",      4,              Math.round(3.5));
    array[item++] = new TestCase( SECTION,  "Math.round(-3.5)",     -3,             Math.round(-3));

    return ( array );
}
