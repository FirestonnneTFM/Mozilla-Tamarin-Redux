/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.8.2.12";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.min(x, y)";
    var BUGNUMBER="76439";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Math.min.length",              2,              Math.min.length );

    array[item++] = new TestCase( SECTION,  "Math.min()",                   Infinity,       Math.min() );
    array[item++] = new TestCase( SECTION,  "Math.min(void 0, 1)",          Number.NaN,     Math.min( void 0, 1 ) );
    array[item++] = new TestCase( SECTION,  "Math.min(void 0, void 0)",     Number.NaN,     Math.min( void 0, void 0 ) );
    array[item++] = new TestCase( SECTION,  "Math.min(null, 1)",            0,              Math.min( null, 1 ) );
    array[item++] = new TestCase( SECTION,  "Math.min(-1, null)",           -1,              Math.min( -1, null ) );
    array[item++] = new TestCase( SECTION,  "Math.min(true, false)",        0,              Math.min(true,false) );

    array[item++] = new TestCase( SECTION,  "Math.min('-99','99')",         -99,             Math.min( "-99","99") );

  /*array[item++] = new TestCase( SECTION,  "Math.min(NaN,0)",      Number.NaN, Math.min(Number.NaN,0) );*/
    array[item++] = new TestCase( SECTION,  "Math.min(NaN,0)",      Number.NaN, Math.min(Number.NaN,0) );
    array[item++] = new TestCase( SECTION,  "Math.min(NaN,1)",      Number.NaN, Math.min(Number.NaN,1) );
                          
    
 /* array[item++] = new TestCase( SECTION,  "Math.min(NaN,-1)",     Number.NaN, Math.min(Number.NaN,-1) );*/

    
    array[item++] = new TestCase( SECTION,  "Math.min(NaN,-1)",     Number.NaN, Math.min(Number.NaN,-1) );
    array[item++] = new TestCase( SECTION,  "Math.min(0,NaN)",      Number.NaN, Math.min(0,Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.min(1,NaN)",      Number.NaN, Math.min(1,Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.min(-1,NaN)",     Number.NaN, Math.min(-1,Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.min(NaN,NaN)",    Number.NaN, Math.min(Number.NaN,Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.min(1,1.0000000001)", 1,      Math.min(1,1.0000000001) );
    array[item++] = new TestCase( SECTION,  "Math.min(1.0000000001,1)", 1,      Math.min(1.0000000001,1) );
    array[item++] = new TestCase( SECTION,  "Math.min(0,0)",        0,          Math.min(0,0) );
    array[item++] = new TestCase( SECTION,  "Math.min(0,-0)",       -0,         Math.min(0,-0) );
    array[item++] = new TestCase( SECTION,  "Math.min(-0,-0)",      -0,         Math.min(-0,-0) );

    array[item++] = new TestCase( SECTION,  "Infinity/Math.min(0,-0)",       -Infinity,         Infinity/Math.min(0,-0) );
    array[item++] = new TestCase( SECTION,  "Infinity/Math.min(-0,-0)",      -Infinity,         Infinity/Math.min(-0,-0) );
    array[item++] = new TestCase( SECTION,  "Math.min(Infinity, Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY)", Number.NEGATIVE_INFINITY,   Math.min(Number.POSITIVE_INFINITY,Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION,  "Math.min(Infinity, Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY,0,-0,1,-1,'string',Number.NaN,null,void 0)", Number.NaN,   Math.min(Number.POSITIVE_INFINITY,Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY,0,-0,1,-1,'string',Number.NaN,null,void 0) );
    array[item++] = new TestCase( SECTION,  "Math.min(Infinity, Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY,0,-0,1,-1)", -Infinity,   Math.min(Number.POSITIVE_INFINITY,Number.MAX_VALUE,Number.MIN_VALUE,Number.NEGATIVE_INFINITY,0,-0,1) );


    return ( array );
}
