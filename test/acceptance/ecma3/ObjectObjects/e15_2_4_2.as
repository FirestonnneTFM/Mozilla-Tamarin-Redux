/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.2.4.2";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Object.prototype.toString()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "(new Object()).toString()",    "[object Object]",  (new Object()).toString() );

    myvar = this;
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = this;  myvar.toString = Object.prototype.toString; myvar.toString()",
                                            GLOBAL,
                                             myvar.toString());


/*  myvar = MyObject;
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = MyObject; myvar.toString = Object.prototype.toString; myvar.toString()",
                                            "[object Function]",
                                             myvar.toString() );
*/
    myvar = new MyObject( true );
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = new MyObject( true ); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            '[object Object]',
                                            myvar.toString());

    // save
    var origNumProto = Number.prototype.toString;

    Number.prototype.toString=Object.prototype.toString;
    myvar = new Number(0);
    var expectedAns = "[object Number]";
    if (as3Enabled) {
        expectedAns = "0";
    }
    
    array[item++] = new TestCase( SECTION,  "myvar = new Number(0); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            expectedAns,
                                             myvar.toString());

    // restore
    Number.prototype.toString = origNumProto

    //save
    var origStrProto = String.prototype.toString;

    String.prototype.toString=Object.prototype.toString;
    myvar = new String('');
    expectedAns = "[object String]";
    if (as3Enabled) {
        expectedAns = "";
    }
    array[item++] = new TestCase( SECTION,  "myvar = new String(''); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            expectedAns,
                                            myvar.toString() );

    // restore
    String.prototype.toString = origStrProto;

    myvar = Math;

    var thisError = "no exception thrown";

// The new Funtion() has been replaced by function() {}
    myvar = function() {};
    
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = function() {}; myvar.toString = Object.prototype.toString; myvar.toString()",
                                            true,
                                            Boolean(myvar.toString().match(/\[object Function-[0-9]+\]/)) || myvar.toString()=="[object null]");

/*
    myvar = new Array();
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = new Array(); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            "[object Array]",
                                            myvar.toString());

    // save
    var origBoolProto = Boolean.prototype.toString;

    Boolean.prototype.toString=Object.prototype.toString;
    myvar = new Boolean();
    array[item++] = new TestCase( SECTION,  "myvar = new Boolean(); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            "[object Boolean]",
                                             myvar.toString());

    // restore
    Boolean.prototype.toString = origBoolProto;

    myvar = new Date();
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = new Date(); myvar.toString = Object.prototype.toString; myvar.toString()",
                                            "[object Date]",
                                            myvar.toString());

*/

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object( this ); MYVAR.toString()",
                                            GLOBAL,
                                            (MYVAR = new Object( this ), MYVAR.toString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(); MYVAR.toString()",
                                            "[object Object]",
                                            (MYVAR = new Object(), MYVAR.toString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(void 0); MYVAR.toString()",
                                            "[object Object]",
                                            (MYVAR = new Object(void 0), MYVAR.toString() ) );

    array[item++] = new TestCase( SECTION,  "var MYVAR = new Object(null); MYVAR.toString()",
                                            "[object Object]",
                                            (MYVAR = new Object(null), MYVAR.toString() ) );

    return ( array );
}

function MyObject( value ) {
    this.value = function() {return this.value;}
    this.toString = function() {return this.value+'';}
}
