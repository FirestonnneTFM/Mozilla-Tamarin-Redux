/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.4.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Array.prototype.toString";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Array.prototype.toString.length",  0,  Array.prototype.toString.length );

    array[item++] = new TestCase( SECTION,  "(new Array()).toString()",     "",     (new Array()).toString() );
    array[item++] = new TestCase( SECTION,  "(new Array(2)).toString()",    ",",    (new Array(2)).toString() );
    array[item++] = new TestCase( SECTION,  "(new Array(0,1)).toString()",  "0,1",  (new Array(0,1)).toString() );
    array[item++] = new TestCase( SECTION,  "(new Array( Number.NaN, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)).toString()",  "NaN,Infinity,-Infinity",   (new Array( Number.NaN, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)).toString() );

    array[item++] = new TestCase( SECTION,  "(new Array( Boolean(1), Boolean(0))).toString()",   "true,false",   (new Array(Boolean(1),Boolean(0))).toString() );
    array[item++] = new TestCase( SECTION,  "(new Array(void 0,null)).toString()",    ",",    (new Array(void 0,null)).toString() );

    var EXPECT_STRING = "";
    var MYARR = new Array();

    for ( var i = -50; i < 50; i+= 0.25 ) {
        MYARR[MYARR.length] = i;
        EXPECT_STRING += i +",";
    }

    EXPECT_STRING = EXPECT_STRING.substring( 0, EXPECT_STRING.length -1 );

    array[item++] = new TestCase( SECTION, "MYARR.toString()",  EXPECT_STRING,  MYARR.toString() );

   var MYARR2 = [0,1,2,3,4,5,6,7,8,9]

   array[item++] = new TestCase( SECTION, "MYARR2.toString()",  "0,1,2,3,4,5,6,7,8,9",  MYARR2.toString() );

   var MYARRARR = [new Array(1,2,3),new Array(4,5,6)]

   array[item++] = new TestCase( SECTION, "MYARRARR.toString()",  "1,2,3,4,5,6",MYARRARR.toString() );

   var obj;
   var MYUNDEFARR = [obj];

   array[item++] = new TestCase( SECTION, "MYUNDEFARR.toString()",  "",MYUNDEFARR.toString() );

   var MYNULLARR = [null]

   array[item++] = new TestCase( SECTION, "MYNULLARR.toString()",  "",MYNULLARR.toString() );

   var MYNULLARR2 = new Array(null);

   array[item++] = new TestCase( SECTION, "MYNULLARR2.toString()",  "",MYNULLARR2.toString() );

   return ( array );
}
