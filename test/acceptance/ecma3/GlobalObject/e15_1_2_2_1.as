/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.2.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "parseInt(string, radix)";
    var BUGNUMBER="111199";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var HEX_STRING = "0x0";
    var HEX_VALUE = 0;

    array[item++] = new TestCase( SECTION,  "parseInt.length",      2,      parseInt.length );

    var thisError:String = "no error";
    try
    {
         parseInt.length = 0;
    }
    catch(e:ReferenceError)
    {
     thisError = e.toString();
    }
    finally
    {
     array[item++] = new TestCase(SECTION, "parseInt.length = 0", "ReferenceError: Error #1074", referenceError(thisError));
    }

    var PROPS='';
    for ( var p in parseInt ) {
        PROPS += p;
    }

    array[item++] = new TestCase( SECTION,  "var PROPS='', for ( var p in parseInt ) { PROPS += p, }, PROPS",   "", PROPS );
    array[item++] = new TestCase( SECTION,  "delete parseInt.length",   false,  delete parseInt.length );
    delete parseInt.length;
    array[item++] = new TestCase( SECTION,  "delete parseInt.length; parseInt.length",  2,   parseInt.length);

    thisError = "no error";
    try
    {
        parseInt.length = null;
    }
    catch(e:ReferenceError)
    {
        thisError = e.toString();
    }
    finally
    {
        array[item++] = new TestCase(SECTION, "parseInt.length = null", "ReferenceError: Error #1074", referenceError(thisError));
    }

    array[item++] = new TestCase( SECTION,  "parseInt()",       NaN,    parseInt() );
    array[item++] = new TestCase( SECTION,  "parseInt('')",     NaN,    parseInt("") );
    array[item++] = new TestCase( SECTION,  "parseInt('','')",  NaN,    parseInt("","") );
    array[item++] = new TestCase( SECTION,
                    "parseInt(\"     0xabcdef     ",
                    11259375,
                    parseInt( "      0xabcdef     " ));

    array[item++] = new TestCase( SECTION,
                    "parseInt(\"     0XABCDEF     ",
                    11259375,
                    parseInt( "      0XABCDEF     " ) );

    array[item++] = new TestCase( SECTION,
                    "parseInt( 0xabcdef )",
                    11259375,
                    parseInt( "0xabcdef") );

    array[item++] = new TestCase( SECTION,
                    "parseInt( 0XABCDEF )",
                    11259375,
                    parseInt( "0XABCDEF") );

    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+")",    HEX_VALUE,  parseInt(HEX_STRING) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "0X0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+")",    HEX_VALUE,  parseInt(HEX_STRING) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+",16)",    HEX_VALUE,  parseInt(HEX_STRING,16) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+",16)",    HEX_VALUE,  parseInt(HEX_STRING,16) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+",null)",    HEX_VALUE,  parseInt(HEX_STRING,null) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }

    thisError="no error"

    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        try{
            parseInt(HEX_STRING, void 0);
        }catch(e:Error){
            thisError = e.toString();
        }finally{
            array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+", void 0)",    "no error",  typeError(thisError));
         }
      array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+", void 0)",    HEX_VALUE,  parseInt(HEX_STRING, void 0) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }

    // a few tests with spaces

    for ( var space = " ", HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0;
        POWER < 15;
        POWER++, HEX_STRING = HEX_STRING +"f", space += " ")
    {   try{
            parseInt(space+HEX_STRING+space, void 0);
        }catch(e1:Error){
            thisError = e1.toString();
        }finally{
            array[item++] = new TestCase( SECTION, "parseInt("+space+HEX_STRING+space+", void 0)",    "no error",  typeError(thisError) );
         }
        array[item++] = new TestCase( SECTION, "parseInt("+space+HEX_STRING+space+", void 0)",    HEX_VALUE,  parseInt(space+HEX_STRING+space, void 0) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }

    // a few tests with negative numbers
    for ( HEX_STRING = "-0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+")",    HEX_VALUE,  parseInt(HEX_STRING) );
        HEX_VALUE -= Math.pow(16,POWER)*15;
    }

    // we should stop parsing when we get to a value that is not a numeric literal for the type we expect

    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+"g,16)",    HEX_VALUE,  parseInt(HEX_STRING+"g",16) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+"g,16)",    HEX_VALUE,  parseInt(HEX_STRING+"G",16) );
        HEX_VALUE += Math.pow(16,POWER)*15;
    }

    for ( HEX_STRING = "-0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+")",    HEX_VALUE,  parseInt(HEX_STRING) );
        HEX_VALUE -= Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "-0X0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+")",    HEX_VALUE,  parseInt(HEX_STRING) );
        HEX_VALUE -= Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "-0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+",16)",    HEX_VALUE,  parseInt(HEX_STRING,16) );
        HEX_VALUE -= Math.pow(16,POWER)*15;
    }
    for ( HEX_STRING = "-0x0", HEX_VALUE = 0, POWER = 0; POWER < 15; POWER++, HEX_STRING = HEX_STRING +"f" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+HEX_STRING+",16)",    HEX_VALUE,  parseInt(HEX_STRING,16) );
        HEX_VALUE -= Math.pow(16,POWER)*15;
    }

    //  let us do some octal tests.  numbers that start with 0 and do not provid a radix should
    //  default to using "0" as a radix.
// mt: octal not supported

/*
    var OCT_STRING = "0";
    var OCT_VALUE = 0;

    for ( OCT_STRING = "0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+")",    OCT_VALUE,  parseInt(OCT_STRING) );
        OCT_VALUE += Math.pow(8,POWER)*7;
    }

    for ( OCT_STRING = "-0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+")",    OCT_VALUE,  parseInt(OCT_STRING) );
        OCT_VALUE -= Math.pow(8,POWER)*7;
    }

    // should get the same results as above if we provid the radix of 8 (or 010)

    for ( OCT_STRING = "0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+",8)",    OCT_VALUE,  parseInt(OCT_STRING,8) );
        OCT_VALUE += Math.pow(8,POWER)*7;
    }
    for ( OCT_STRING = "-0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+",010)",    OCT_VALUE,  parseInt(OCT_STRING,010) );
        OCT_VALUE -= Math.pow(8,POWER)*7;
    }

    // we shall stop parsing digits when we get one that isn't a numeric literal of the type we think
    // it should be.
    for ( OCT_STRING = "0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+"8,8)",    OCT_VALUE,  parseInt(OCT_STRING+"8",8) );
        OCT_VALUE += Math.pow(8,POWER)*7;
    }
    for ( OCT_STRING = "-0", OCT_VALUE = 0, POWER = 0; POWER < 15; POWER++, OCT_STRING = OCT_STRING +"7" ) {
        array[item++] = new TestCase( SECTION, "parseInt("+OCT_STRING+"8,010)",    OCT_VALUE,  parseInt(OCT_STRING+"8",010) );
        OCT_VALUE -= Math.pow(8,POWER)*7;
    }
*/
    array[item++] = new TestCase( SECTION, "parseInt( '0x' )",              NaN,        parseInt("0x") );
    array[item++] = new TestCase( SECTION, "parseInt( '0X' )",              NaN,        parseInt("0X") );

    array[item++] = new TestCase( SECTION, "parseInt( '11111111112222222222' )",    11111111112222222222,   parseInt("11111111112222222222") );
    array[item++] = new TestCase( SECTION, "parseInt( '111111111122222222223' )",    111111111122222222220,   parseInt("111111111122222222223") );
    array[item++] = new TestCase( SECTION, "parseInt( '11111111112222222222',10 )",    11111111112222222222,   parseInt("11111111112222222222",10) );
    array[item++] = new TestCase( SECTION, "parseInt( '111111111122222222223',10 )",    111111111122222222220,   parseInt("111111111122222222223",10) );

    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', -1 )",  Number.NaN,    parseInt("01234567890",-1) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 0 )",  Number.NaN,     parseInt("01234567890",1) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 1 )",  Number.NaN,     parseInt("01234567890",1) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 2 )",  1,              parseInt("01234567890",2) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 3 )",  5,              parseInt("01234567890",3) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 4 )",  27,             parseInt("01234567890",4) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 5 )",  194,            parseInt("01234567890",5) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 6 )",  1865,           parseInt("01234567890",6) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 7 )",  22875,          parseInt("01234567890",7) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 8 )",  342391,         parseInt("01234567890",8) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 9 )",  6053444,        parseInt("01234567890",9) );
    array[item++] = new TestCase( SECTION, "parseInt( '01234567890', 10 )", Number(1234567890),     parseInt("01234567890",10) );

    // need more test cases with hex radix

    array[item++] = new TestCase( SECTION, "parseInt( '1234567890', '0xa')", Number(1234567890), parseInt("1234567890","0xa") );

    array[item++] = new TestCase( SECTION, "parseInt( '012345', 11 )",      17715,          parseInt("012345",11) );

    array[item++] = new TestCase( SECTION, "parseInt( '012345', 35 )",      1590195,        parseInt("012345",35) );
    array[item++] = new TestCase( SECTION, "parseInt( '012345', 36 )",      1776965,        parseInt("012345",36) );
    array[item++] = new TestCase( SECTION, "parseInt( '012345', 37 )",      Number.NaN,     parseInt("012345",37) );

    return ( array );
}
