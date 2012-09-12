/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Number.prototype.toString()");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var thisError="no error thrown";
    try{
        thisError = Number.prototype.toString();
    }
    catch(e)
    {
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase(SECTION, "Number.prototype.toString()",
                                              "0",
                                              thisError);
    }

    array[item++] = new TestCase(SECTION, "typeof(Number.prototype.toString())", "string",      typeof(Number.prototype.toString()) );


    var expectedError = 1056;
    if (as3Enabled) {
        expectedError = 1037;
    }

    thisError="no error thrown";
    try{
        s = Number.prototype.toString;
        o = new Number();
        o.toString = s;
    }
    catch(e1)
    {
        thisError=e1.toString();
    }finally{
        array[item++] = new TestCase(SECTION, "s = Number.prototype.toString",
                                            REFERENCEERROR+expectedError,
                                            referenceError(thisError));
    }

    thisError="no error thrown";
    try{
        s = Number.prototype.toString;
        o = new Number(1);
        o.toString = s;
    }
    catch(e2){
        thisError=e2.toString();
    }finally{
        array[item++] = new TestCase(SECTION, "s = Number.prototype.toString",
                                                REFERENCEERROR+expectedError,
                                                referenceError(thisError));
    }

    thisError="no error thrown";
    try{
        s = Number.prototype.toString;
        o = new Number(-1);
        o.toString = s;
    }
    catch(e3){
        thisError=e3.toString();
    }finally{
        array[item++] = new TestCase(SECTION, "s = Number.prototype.toString",
                                            REFERENCEERROR+expectedError,
                                            referenceError(thisError));
    }

    var MYNUM = new Number(255);
    array[item++] = new TestCase(SECTION, "var MYNUM = new Number(255); MYNUM.toString(10)",          "255",      MYNUM.toString(10) );

    var MYNUM = new Number(Number.NaN);
    array[item++] = new TestCase(SECTION, "var MYNUM = new Number(Number.NaN); MYNUM.toString(10)",   "NaN",      MYNUM.toString(10) );

    var MYNUM = new Number(Infinity);
    array[item++] = new TestCase(SECTION, "var MYNUM = new Number(Infinity); MYNUM.toString(10)",   "Infinity",   MYNUM.toString(10) );

    var MYNUM = new Number(-Infinity);
    array[item++] = new TestCase(SECTION, "var MYNUM = new Number(-Infinity); MYNUM.toString(10)",   "-Infinity", MYNUM.toString(10) );

    return ( array );
}
