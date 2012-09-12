/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "8.4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Number type";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
    
    //NaN values of ECMAScript

    var s:Number = 'string'
    array[item++] = new TestCase( SECTION,
                                    "var s:Number = 'string'",
                                    NaN,s );
    var k:Number = 'string'

    array[item++] = new TestCase( SECTION,
                                    "Two NaN values are different from each other",
                                    true,
                                    (k!=s) );

    //Positive Infinity and Negative Infinity

    array[item++] = new TestCase( SECTION,
                                    "The special value positive Infinity",
                                    Infinity,
                                    Number.POSITIVE_INFINITY );

    array[item++] = new TestCase( SECTION,
                                    "The special value negative Infinity",
                                    -Infinity,
                                    Number.NEGATIVE_INFINITY );

    //Positive zero and Negative Zero

    var x:Number = +0;

    array[item++] = new TestCase( SECTION,
                                    "positive zero",
                                    +0,
                                     x );

    array[item++] = new TestCase( SECTION,
                                    "positive zero",
                                    true,
                                     x==0 );

    var y:Number = -0;

    array[item++] = new TestCase( SECTION,
                                    "Negative zero",
                                    -0,
                                     y );


    array[item++] = new TestCase( SECTION,
                                    "Negative zero",
                                    true,
                                     y==0 );

    array[item++] = new TestCase( SECTION,
                                    "Negative zero==Positive zero",
                                    true,
                                     y==x );

    //Finite Non-zero values

    //Finite nonzero values  that are Normalised having the form s*m*2**e
    // where s is +1 or -1, m is a positive integer less than 2**53 but not
    // less than s**52 and e is an integer ranging from -1074 to 971

    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is -1074",4.4501477170144023e-308,(1*((Math.pow(2,53))-1)*(Math.pow(2,-1074))) );


    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is -1074",2.2250738585072014e-308,(1*(Math.pow(2,52))*(Math.pow(2,-1074))) );

    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is 971", "1e+308",(1*(Math.pow(2,52))*(Math.pow(2,971)))+"" );

    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is 971", "1.79769313486231e+308",(1*((Math.pow(2,53))-1)*(Math.pow(2,971)))+"" );

    array[item++] = new TestCase( SECTION,"Negative finite Non zero values where e is -1074",-2.2250738585072014e-308,(-1*(Math.pow(2,52))*(Math.pow(2,-1074))) );

    array[item++] = new TestCase( SECTION,"Negative finite Non zero values where e is 971", "-1e+308",(-1*(Math.pow(2,52))*(Math.pow(2,971)))+"" );


    //Finite nonzero values  that are denormalised having the form s*m*2**e
    // where s is +1 or -1, m is a positive integer less than 2**52
    // and e is -1074

    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is -1074",1.1125369292536007e-308,(1*(Math.pow(2,51))*(Math.pow(2,-1074))) );

    array[item++] = new TestCase( SECTION,"Positive finite Non zero values where e is -1074",-1.1125369292536007e-308,(-1*(Math.pow(2,51))*(Math.pow(2,-1074))) );

    //When number value for Y is closest to 2**1024 should convert to Infinity where x is
    // nonzero real mathematical quantity

    var Y:Number = 1e+308*2

    array[item++] = new TestCase( SECTION,"the number value for x closest to 2**1024",Infinity,Y);

    array[item++] = new TestCase( SECTION,"the number value for x closest to 2**1024",Infinity,(1*(Math.pow(2,53))*(Math.pow(2,971))));



    //When number value for z is closest to -2**1024 should convert to Infinity where x is
    // nonzero real mathematical quantity

    var z:Number = -1e+308*3

    array[item++] = new TestCase( SECTION,"the number value for x closest to -2**1024",-Infinity,z);

    //When number value for l is closest to +0 should convert to -0 where l is
    // nonzero real mathematical quantity and less than 0
    // Expected result should be -0, however, base 10 approximations of a base 2 number results in loss of precision

    var l:Number = 1e-308*2

    array[item++] = new TestCase( SECTION,"the number value for x closest to +0",1.9999999999999998e-308,l);

    var m:Number = -1e-308*3

    array[item++] = new TestCase( SECTION,"the number value for x closest to +0",-2.9999999999999997e-308,m);
    return array;
}
