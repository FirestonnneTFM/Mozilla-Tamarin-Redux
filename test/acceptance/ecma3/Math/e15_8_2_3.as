/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.8.2.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.asin()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
 /* var thisError="no error";
    try{
        Math.asin();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.asin()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION, "Math.asin()",           Number.NaN,     Math.asin() );*/
    array[item++] = new TestCase( SECTION, "Math.asin(void 0)",     Number.NaN,     Math.asin(void 0) );
    array[item++] = new TestCase( SECTION, "Math.asin(null)",       0,              Math.asin(null) );
    array[item++] = new TestCase( SECTION, "Math.asin(NaN)",        Number.NaN,     Math.asin(Number.NaN)   );

    array[item++] = new TestCase( SECTION, "Math.asin('string')",   Number.NaN,     Math.asin("string")     );
    array[item++] = new TestCase( SECTION, "Math.asin('0')",        0,              Math.asin("0") );
    array[item++] = new TestCase( SECTION, "Math.asin('1')",        Math.PI/2,      Math.asin("1") );
    array[item++] = new TestCase( SECTION, "Math.asin('-1')",       -Math.PI/2,     Math.asin("-1") );
    array[item++] = new TestCase( SECTION, "Math.asin(Math.SQRT1_2+'')",    0.7853981633974484,  Math.asin(Math.SQRT1_2+'') );
    array[item++] = new TestCase( SECTION, "Math.asin(-Math.SQRT1_2+'')",   -0.7853981633974484, Math.asin(-Math.SQRT1_2+'') );

    array[item++] = new TestCase( SECTION, "Math.asin(1.000001)",    Number.NaN,    Math.asin(1.000001)     );
    array[item++] = new TestCase( SECTION, "Math.asin(-1.000001)",   Number.NaN,    Math.asin(-1.000001)    );
    array[item++] = new TestCase( SECTION, "Math.asin(0)",           0,             Math.asin(0)            );
    array[item++] = new TestCase( SECTION, "Math.asin(-0)",          -0,            Math.asin(-0)           );

    array[item++] = new TestCase( SECTION, "Infinity/Math.asin(-0)",    -Infinity,  Infinity/Math.asin(-0) );

    array[item++] = new TestCase( SECTION, "Math.asin(1)",              Math.PI/2,  Math.asin(1)            );
    array[item++] = new TestCase( SECTION, "Math.asin(-1)",             -Math.PI/2, Math.asin(-1)            );
    array[item++] = new TestCase( SECTION, "Math.asin(Math.SQRT1_2))",  0.7853981633974484,  Math.asin(Math.SQRT1_2) );
    array[item++] = new TestCase( SECTION, "Math.asin(-Math.SQRT1_2))", -0.7853981633974484, Math.asin(-Math.SQRT1_2));

    return ( array );
}
