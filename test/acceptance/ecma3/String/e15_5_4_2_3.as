/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.5.4.2-3";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "String.prototype.toString";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var tostr=String.prototype.toString;
    String.prototype.toString=tostr;
    var astring;
    array[item++] = new TestCase( SECTION,
                                  "var tostr=String.prototype.toString, String.prototype.toString=tostr,astring=new String(), astring.toString()",
                                 "",
                                  (astring=new String(), astring.toString()) );
    array[item++] = new TestCase( SECTION,
                                  "var tostr=String.prototype.toString, String.prototype.toString=tostr,astring=new String(0),astring.toString()",
                                  "0",
                                  (astring=new String(0),astring.toString()) );
    array[item++] = new TestCase( SECTION,
                                  "var tostr=String.prototype.toString, String.prototype.toString=tostr,astring=new String('hello'), astring.toString()",
                                  "hello",
                                  (astring=new String('hello'), astring.toString()) );
    array[item++] = new TestCase( SECTION,
                                  "var tostr=String.prototype.toString, String.prototype.toString=tostr,astring=new String(''), astring.toString()",
                                  "",
                                  (astring=new String(''), astring.toString()) );

    return ( array );
}
