/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.2.10";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.log(x)";
    var BUGNUMBER = "77391";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "Math.log.length",         1,              Math.log.length );
  /*thisError="no error";
    try{
        Math.log();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.log()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION,   "Math.log()",              Number.NaN,     Math.log() );*/
    array[item++] = new TestCase( SECTION,   "Math.log(void 0)",        Number.NaN,     Math.log(void 0) );
    array[item++] = new TestCase( SECTION,   "Math.log(null)",          Number.NEGATIVE_INFINITY,   Math.log(null) );
    array[item++] = new TestCase( SECTION,   "Math.log(true)",          0,              Math.log(true) );
    array[item++] = new TestCase( SECTION,   "Math.log(false)",         -Infinity,      Math.log(false) );
    array[item++] = new TestCase( SECTION,   "Math.log('0')",           -Infinity,      Math.log('0') );
    array[item++] = new TestCase( SECTION,   "Math.log('1')",           0,              Math.log('1') );
    array[item++] = new TestCase( SECTION,   "Math.log('Infinity')",    Infinity,       Math.log("Infinity") );

    array[item++] = new TestCase( SECTION,   "Math.log(NaN)",           Number.NaN,     Math.log(Number.NaN) );
    array[item++] = new TestCase( SECTION,   "Math.log(-0.0000001)",    Number.NaN,     Math.log(-0.000001)  );
    array[item++] = new TestCase( SECTION,   "Math.log(0.0000001)",    -13.815510557964274,     Math.log(0.000001)  );
    array[item++] = new TestCase( SECTION,   "Math.log(-1)",            Number.NaN,     Math.log(-1)        );
    array[item++] = new TestCase( SECTION,   "Math.log(0)",             Number.NEGATIVE_INFINITY,   Math.log(0) );
    array[item++] = new TestCase( SECTION,   "Math.log(-0)",            Number.NEGATIVE_INFINITY,   Math.log(-0));
    array[item++] = new TestCase( SECTION,   "Math.log(1)",             0,              Math.log(1) );
    array[item++] = new TestCase( SECTION,   "Math.log(2)",0.6931471805599453,              Math.log(2) );
    array[item++] = new TestCase( SECTION,   "Math.log(3)", 1.0986122886681098,              Math.log(3) );
    array[item++] = new TestCase( SECTION,   "Math.log(4)",1.3862943611198906,              Math.log(4) );
    array[item++] = new TestCase( SECTION,   "Math.log(Infinity)",      Number.POSITIVE_INFINITY,   Math.log(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Math.log(-Infinity)",     Number.NaN,     Math.log(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Math.log(10)",2.302585092994046,              Math.log(10) );
    array[item++] = new TestCase( SECTION,   "Math.log(100)",4.605170185988092,              Math.log(100) );
    array[item++] = new TestCase( SECTION,   "Math.log(100000)",11.512925464970229,              Math.log(100000) );
    array[item++] = new TestCase( SECTION,   "Math.log(300000)",12.611537753638338,              Math.log(300000) );
    return ( array );
}
