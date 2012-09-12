/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.2.4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.atan()";
    var BUGNUMBER="77391";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "Math.atan.length",        1,              Math.atan.length );
 /* var thisError="no error";
    try{
        Math.atan();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.atan()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION,   "Math.atan()",             Number.NaN,     Math.atan() );*/
    array[item++] = new TestCase( SECTION,   "Math.atan(void 0)",       Number.NaN,     Math.atan(void 0) );
    array[item++] = new TestCase( SECTION,   "Math.atan(null)",         0,              Math.atan(null) );
    array[item++] = new TestCase( SECTION,   "Math.atan(NaN)",          Number.NaN,     Math.atan(Number.NaN) );

    array[item++] = new TestCase( SECTION,   "Math.atan('a string')",   Number.NaN,     Math.atan("a string") );
    array[item++] = new TestCase( SECTION,   "Math.atan('0')",          0,              Math.atan('0') );
    array[item++] = new TestCase( SECTION,   "Math.atan('1')",          Math.PI/4,      Math.atan('1') );
    array[item++] = new TestCase( SECTION,   "Math.atan('-1')",         -Math.PI/4,     Math.atan('-1') );
    array[item++] = new TestCase( SECTION,   "Math.atan('Infinity)",    Math.PI/2,      Math.atan('Infinity') );
    array[item++] = new TestCase( SECTION,   "Math.atan('-Infinity)",   -Math.PI/2,     Math.atan('-Infinity') );

    array[item++] = new TestCase( SECTION,   "Math.atan(0)",            0,              Math.atan(0)          );
    array[item++] = new TestCase( SECTION,   "Math.atan(-0)",           -0,             Math.atan(-0)         );
    array[item++] = new TestCase( SECTION,   "Infinity/Math.atan(-0)",  -Infinity,      Infinity/Math.atan(-0) );
    array[item++] = new TestCase( SECTION,   "Math.atan(Infinity)",     Math.PI/2,      Math.atan(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Math.atan(-Infinity)",    -Math.PI/2,     Math.atan(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,   "Math.atan(1)",            Math.PI/4,      Math.atan(1)          );
    array[item++] = new TestCase( SECTION,   "Math.atan(-1)",           -Math.PI/4,     Math.atan(-1)         );
    return array;
}
