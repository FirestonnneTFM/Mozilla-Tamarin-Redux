/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.7.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Number Constructor Called as a Function";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(SECTION, "Number()",                  0,          Number() );
    array[item++] = new TestCase(SECTION, "Number(void 0)",            Number.NaN,  Number(void 0) );
    array[item++] = new TestCase(SECTION, "Number(null)",              0,          Number(null) );
    array[item++] = new TestCase(SECTION, "Number()",                  0,          Number() );
    array[item++] = new TestCase(SECTION, "Number(new Number())",      0,          Number( new Number() ) );
    array[item++] = new TestCase(SECTION, "Number(0)",                 0,          Number(0) );
    array[item++] = new TestCase(SECTION, "Number(1)",                 1,          Number(1) );
    array[item++] = new TestCase(SECTION, "Number(-1)",                -1,         Number(-1) );
    array[item++] = new TestCase(SECTION, "Number(NaN)",               Number.NaN, Number( Number.NaN ) );
    array[item++] = new TestCase(SECTION, "Number('string')",          Number.NaN, Number( "string") );
    array[item++] = new TestCase(SECTION, "Number(new String())",      0,          Number( new String() ) );
    array[item++] = new TestCase(SECTION, "Number('')",                0,          Number( "" ) );
    array[item++] = new TestCase(SECTION, "Number(Infinity)",          Number.POSITIVE_INFINITY,   Number("Infinity") );

    array[item++] = new TestCase(SECTION, "Number(-Infinity)",          Number.NEGATIVE_INFINITY,   Number("-Infinity") );

    array[item++] = new TestCase(SECTION, "Number(3.141592653589793)",          Math.PI,   Number("3.141592653589793") );

    array[item++] = new TestCase(SECTION, "Number(4294967297)",          (Math.pow(2,32)+1),   Number("4294967297") );

    array[item++] = new TestCase(SECTION, "Number(1e2000)",          Infinity,   Number(1e2000) );

    array[item++] = new TestCase(SECTION, "Number(-1e2000)",     -Infinity,   Number(-1e2000) );

    array[item++] = new TestCase(SECTION, "Number(1e-2000)",          0,   Number(1e-2000) );

    array[item++] = new TestCase(SECTION, "Number(1/1e-2000)",         Infinity,   Number(1/1e-2000) );

    array[item++] = new TestCase(SECTION, "Number(true)",         1,   Number(true) );

    array[item++] = new TestCase(SECTION, "Number(false)",         0,   Number(false) );

    array[item++] = new TestCase(SECTION, "Number(new Boolean(false)",         0,   Number(new Boolean(false)) );

    array[item++] = new TestCase(SECTION, "Number(new String('Number.POSITIVE_INFINITY')",         Infinity,   Number(new String(Number.POSITIVE_INFINITY)) );

    array[item++] = new TestCase(SECTION, "Number(new Number(false)",         0,   Number(new Number(false)) );
    

    array[item++] = new TestCase(SECTION, "Number('3000000000.25')",          (3000000000.25),   Number("3000000000.25") );

    array[item++] = new TestCase(SECTION, "Number(-'3000000000.25')",          (-3000000000.25),   Number(-"3000000000.25") );

    array[item++] = new TestCase(SECTION, "Number('1.79769313486231e+308')",(Number.MAX_VALUE+""),Number("1.79769313486231e+308")+"" );
    // https://bugzilla.mozilla.org/show_bug.cgi?id=555805 - MIN_VALUE is not a cross-platform constant,
    // This test is not useful.  The number formatter prevents us from making it useful.
    //array[item++] = new TestCase(SECTION, "Number('4.9406564584124654e-324')",(Number.MIN_VALUE+""),Number("4.9406564584124654e-324")+"" );
    array[item++] = new TestCase(SECTION, "Number.MIN_VALUE > 0", Number.MIN_VALUE > 0, true);
    array[item++] = new TestCase(SECTION, "Number.MIN_VALUE/2", Number.MIN_VALUE/2, 0.0);
    array[item++] = new TestCase(SECTION, "Number(new MyObject(100))",  100,        Number(new MyObject(100)) );

   var s:String =
"0xFFFFFFFFFFFFF80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    array[item++] = new TestCase(SECTION, "Number(s)",parseInt(s),   Number(s) );

    array[item++] = new TestCase(SECTION, "Number(-s)",((-5.03820925841965e+263)+""),   Number(-s)+"" );

    array[item++] = new TestCase( SECTION,
                                "Number(-\"\")",
                                0,
                                Number(-"" ));

    array[item++] = new TestCase( SECTION,
                                "Number(-\" \")",
                                0,
                                Number(-" " ));
    array[item++] = new TestCase( SECTION,
                                "Number(-\"999\")",
                                -999,
                                Number(-"999") );

    array[item++] = new TestCase( SECTION,
                                "Number(-\" 999\")",
                                -999,
                                Number(-" 999") );

    array[item++] = new TestCase( SECTION,
                                "Number(-\"\\t999\")",
                                -999,
                                Number(-"\t999") );

    array[item++] = new TestCase( SECTION,
                                "Number(-\"013  \")",
                                -13,
                                Number(-"013  " ));

    array[item++] = new TestCase( SECTION,
                                "Number(-\"999\\t\")",
                                -999,
                                Number(-"999\t") );

    array[item++] = new TestCase( SECTION,
                                "Number(-\"-Infinity\")",
                                Infinity,
                                Number(-"-Infinity" ));

    array[item++] = new TestCase( SECTION,
                                "Number(-\"-infinity\")",
                                NaN,
                                Number(-"-infinity"));


    array[item++] = new TestCase( SECTION,
                                "Number(-\"+Infinity\")",
                                -Infinity,
                                Number(-"+Infinity") );

    array[item++] = new TestCase( SECTION,
                                "Number(-\"+Infiniti\")",
                                NaN,
                                Number(-"+Infiniti"));

    array[item++] = new TestCase( SECTION,
                                "Number(- -\"0x80000000\")",
                                2147483648,
                                Number(- -"0x80000000"));

    array[item++] = new TestCase( SECTION,
                                "Number(- -\"0x100000000\")",
                                4294967296,
                                Number(- -"0x100000000") );

    array[item++] = new TestCase( SECTION,
                                "Number(- \"-0x123456789abcde8\")",
                                81985529216486880,
                                Number(- "-0x123456789abcde8"));



    return ( array );
}

function MyObject( value ) {
    this.value = value;
    this.valueOf = function() { return this.value; }
}
