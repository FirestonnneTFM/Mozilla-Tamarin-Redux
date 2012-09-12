/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.4.5";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Array.prototype.join";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Array.prototype.join.length",  1,  Array.prototype.join.length );

    array[item++] = new TestCase( SECTION,  "(new Array()).join()",     "",     (new Array()).join() );
    array[item++] = new TestCase( SECTION,  "(new Array(2)).join()",    ",",    (new Array(2)).join() );
    array[item++] = new TestCase( SECTION,  "(new Array(0,1)).join()",  "0,1",  (new Array(0,1)).join() );
    array[item++] = new TestCase( SECTION,  "(new Array(0,1)).join(separator)",  "0/1",  (new Array(0,1)).join("/") );
    array[item++] = new TestCase( SECTION,  "(new Array( Number.NaN, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)).join()",  "NaN,Infinity,-Infinity",   (new Array( Number.NaN, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)).join() );
    array[item++] = new TestCase( SECTION,  "(new Array( Boolean(1), Boolean(0))).join()",   "true,false",   (new Array(Boolean(1),Boolean(0))).join() );
    array[item++] = new TestCase( SECTION,  "(new Array(void 0,null)).join()",    ",",    (new Array(void 0,null)).join() );

    var EXPECT_STRING = "";
    var MYARR = new Array();

    for ( var i = -50; i < 50; i+= 0.25 ) {
        MYARR[MYARR.length] = i;
        EXPECT_STRING += i +"/";
    }

    EXPECT_STRING = EXPECT_STRING.substring( 0, EXPECT_STRING.length -1 );

    array[item++] = new TestCase( SECTION, "MYARR.join(separator)",  EXPECT_STRING,  MYARR.join("/") );

   var MYARR2 = [0,1,2,3,4,5,6,7,8,9]

   array[item++] = new TestCase( SECTION, "MYARR2.join(separator)",  "0separator1separator2separator3separator4separator5separator6separator7separator8separator9",  MYARR2.join("separator") );

   var MYARRARR = [new Array(1,2,3),new Array(4,5,6)]

   array[item++] = new TestCase( SECTION, "MYARRARR.join(separator)",  "1,2,34,5,6",MYARRARR.join("") );

   var obj;
   var MYUNDEFARR = [obj];

   array[item++] = new TestCase( SECTION, "MYUNDEFARR.join()",  "",MYUNDEFARR.join() );

   var MYNULLARR = [null]

   array[item++] = new TestCase( SECTION, "MYNULLARR.join()",  "",MYNULLARR.join());

   var MYNULLARR2 = new Array(null);

   array[item++] = new TestCase( SECTION, "MYNULLARR2.join()",  "",MYNULLARR2.join() );

   var MyAllArray = new Array(new String('string'),new Array(1,2,3),new Number(100000),Boolean(0),Number.MAX_VALUE)

   array[item++] = new TestCase( SECTION, "MyAllArray.join(separator)",  "string&1,2,3&100000&false&1.79769313486231e+308",MyAllArray.join("&") );



   return ( array );
}
