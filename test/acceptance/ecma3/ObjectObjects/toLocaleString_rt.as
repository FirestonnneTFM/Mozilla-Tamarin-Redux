/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.2.4.3";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Object.prototype.toLocaleString()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "(new Object()).toLocaleString()",    "[object Object]",  (new Object()).toLocaleString() );

    array[item++] = new TestCase( SECTION,  "myvar = this;  myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            GLOBAL,
                                            (myvar = this,  myvar.toLocaleString = Object.prototype.toLocaleString, myvar.toLocaleString()) );

    // work around for bug 175820
    array[item++] = new TestCase( SECTION,  "myvar = MyObject; myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            true,
                                            (myvar = MyObject, myvar.toLocaleString = Object.prototype.toLocaleString, myvar.toLocaleString()).match(/\[object Function-[0-9]+\]/) != null ||
                                            (myvar = MyObject, myvar.toLocaleString = Object.prototype.toLocaleString, myvar.toLocaleString())=="[object null]"
                                             );

    array[item++] = new TestCase( SECTION,  "myvar = new MyObject( true ); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            '[object Object]',
                                            (myvar = new MyObject( true ), myvar.toLocaleString = Object.prototype.toLocaleString, myvar.toLocaleString()) );

    Number.prototype.toLocaleString;
    //Object.prototpye.toLocaleString;
    array[item++] = new TestCase( SECTION,  "myvar = new Number(0); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "0",
                                            (myvar = new Number(0), myvar.toLocaleString()) );

/*    array[item++] = new TestCase( SECTION,  "myvar = new String(''); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object String]",
                                            eval("myvar = new String(''); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "myvar = Math; myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object Math]",
                                            eval("myvar = Math; myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "myvar = function() {}; myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object Function]",
                                            eval("myvar = function() {}; myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "myvar = new Array(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object Array]",
                                            eval("myvar = new Array(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "myvar = new Boolean(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object Boolean]",
                                            eval("myvar = new Boolean(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "myvar = new Date(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()",
                                            "[object Date]",
                                            eval("myvar = new Date(); myvar.toLocaleString = Object.prototype.toLocaleString; myvar.toLocaleString()") );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object( this ); MYVAR.toLocaleString()",
                                            GLOBAL,
                                            (MYVAR = new Object( this ), MYVAR.toLocaleString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(); MYVAR.toLocaleString()",
                                            "[object Object]",
                                            (MYVAR = new Object(), MYVAR.toLocaleString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(void 0); MYVAR.toLocaleString()",
                                            "[object Object]",
                                            (MYVAR = new Object(void 0), MYVAR.toLocaleString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(null); MYVAR.toLocaleString()",
                                            "[object Object]",
                                            (MYVAR = new Object(null), MYVAR.toLocaleString() ) );
*/
    return ( array );
}

function MyObject( value ) {
    this.value = function() { return this.value; }
    this.toLocaleString = function() { return this.value+''; }

    this.value = function() {return this.value;}
    this.toLocaleString = function() {return this.value+'';}
}
