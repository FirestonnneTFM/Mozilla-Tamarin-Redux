/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4.2-2-n";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Number.prototype.toString()");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    o = new Object();
    o.toString = Number.prototype.toString;

    thisError="no error";
    try{
        o.toString();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,18);
    }finally{trace(thisError);
        array[item++] = new TestCase(SECTION,  "o = new Object(); o.toString = Number.prototype.toString; o.toString()",  "TypeError: Error #",thisError );
    }
  /*array[item++] = new TestCase(SECTION,  "o = new Object(); o.toString = Number.prototype.toString; o.toString()",  "NaN",    o.toString(10) );*/
    //array[item++] = new TestCase(SECTION,  "o = new String(); o.toString = Number.prototype.toString; o.toString()",  "error",    "o = new String(); o.toString = Number.prototype.toString; o.toString()" );
    //array[item++] = new TestCase(SECTION,  "o = 3; o.toString = Number.prototype.toString; o.toString()",             "error",    "o = 3; o.toString = Number.prototype.toString; o.toString()" );

    return ( array );
}
