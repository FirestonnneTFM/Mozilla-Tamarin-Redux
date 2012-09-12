/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_8_4";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " The greater-than-or-equal operator ( >= )");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "true >= false",              true,      true >= false );
    array[item++] = new TestCase( SECTION, "false >= true",              false,     false >= true );
    array[item++] = new TestCase( SECTION, "false >= false",             true,      false >= false );
    array[item++] = new TestCase( SECTION, "true >= true",               true,      true >= true );

    array[item++] = new TestCase( SECTION, "new Boolean(true) >= new Boolean(true)",     true,  new Boolean(true) >= new Boolean(true) );
    array[item++] = new TestCase( SECTION, "new Boolean(true) >= new Boolean(false)",    true,  new Boolean(true) >= new Boolean(false) );
    array[item++] = new TestCase( SECTION, "new Boolean(false) >= new Boolean(true)",    false,   new Boolean(false) >= new Boolean(true) );
    array[item++] = new TestCase( SECTION, "new Boolean(false) >= new Boolean(false)",   true,  new Boolean(false) >= new Boolean(false) );

    array[item++] = new TestCase( SECTION, "new MyObject(Infinity) >= new MyObject(Infinity)",   true,  new MyObject( Number.POSITIVE_INFINITY ) >= new MyObject( Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "new MyObject(-Infinity) >= new MyObject(Infinity)",  false,   new MyObject( Number.NEGATIVE_INFINITY ) >= new MyObject( Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "new MyObject(-Infinity) >= new MyObject(-Infinity)", true,  new MyObject( Number.NEGATIVE_INFINITY ) >= new MyObject( Number.NEGATIVE_INFINITY) );

    array[item++] = new TestCase( SECTION, "new MyValueObject(false) >= new MyValueObject(true)",  false,   new MyValueObject(false) >= new MyValueObject(true) );
    array[item++] = new TestCase( SECTION, "new MyValueObject(true) >= new MyValueObject(true)",   true,  new MyValueObject(true) >= new MyValueObject(true) );
    array[item++] = new TestCase( SECTION, "new MyValueObject(false) >= new MyValueObject(false)", true,  new MyValueObject(false) >= new MyValueObject(false) );

    array[item++] = new TestCase( SECTION, "new MyStringObject(false) >= new MyStringObject(true)",  false,   new MyStringObject(false) >= new MyStringObject(true) );
    array[item++] = new TestCase( SECTION, "new MyStringObject(true) >= new MyStringObject(true)",   true,  new MyStringObject(true) >= new MyStringObject(true) );
    array[item++] = new TestCase( SECTION, "new MyStringObject(false) >= new MyStringObject(false)", true,  new MyStringObject(false) >= new MyStringObject(false) );

    array[item++] = new TestCase( SECTION, "Number.NaN >= Number.NaN",   false,     Number.NaN >= Number.NaN );
    array[item++] = new TestCase( SECTION, "0 >= Number.NaN",            false,     0 >= Number.NaN );
    array[item++] = new TestCase( SECTION, "Number.NaN >= 0",            false,     Number.NaN >= 0 );

    array[item++] = new TestCase( SECTION, "0 >= -0",                    true,      0 >= -0 );
    array[item++] = new TestCase( SECTION, "-0 >= 0",                    true,      -0 >= 0 );

    array[item++] = new TestCase( SECTION, "Infinity >= 0",                  true,      Number.POSITIVE_INFINITY >= 0 );
    array[item++] = new TestCase( SECTION, "Infinity >= Number.MAX_VALUE",   true,      Number.POSITIVE_INFINITY >= Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION, "Infinity >= Infinity",           true,      Number.POSITIVE_INFINITY >= Number.POSITIVE_INFINITY );

    array[item++] = new TestCase( SECTION, "0 >= Infinity",                  false,       0 >= Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION, "Number.MAX_VALUE >= Infinity",   false,       Number.MAX_VALUE >= Number.POSITIVE_INFINITY );

    array[item++] = new TestCase( SECTION, "0 >= -Infinity",                 true,      0 >= Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION, "Number.MAX_VALUE >= -Infinity",  true,      Number.MAX_VALUE >= Number.NEGATIVE_INFINITY );
    array[item++] = new TestCase( SECTION, "-Infinity >= -Infinity",         true,      Number.NEGATIVE_INFINITY >= Number.NEGATIVE_INFINITY );

    array[item++] = new TestCase( SECTION, "-Infinity >= 0",                 false,       Number.NEGATIVE_INFINITY >= 0 );
    array[item++] = new TestCase( SECTION, "-Infinity >= -Number.MAX_VALUE", false,       Number.NEGATIVE_INFINITY >= -Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION, "-Infinity >= Number.MIN_VALUE",  false,       Number.NEGATIVE_INFINITY >= Number.MIN_VALUE );

    array[item++] = new TestCase( SECTION, "'string' >= 'string'",           true,       'string' >= 'string' );
    array[item++] = new TestCase( SECTION, "'astring' >= 'string'",          false,       'astring' >= 'string' );
    array[item++] = new TestCase( SECTION, "'strings' >= 'stringy'",         false,       'strings' >= 'stringy' );
    array[item++] = new TestCase( SECTION, "'strings' >= 'stringier'",       true,       'strings' >= 'stringier' );
    array[item++] = new TestCase( SECTION, "'string' >= 'astring'",          true,      'string' >= 'astring' );
    array[item++] = new TestCase( SECTION, "'string' >= 'strings'",          false,       'string' >= 'strings' );
    array[item++] = new TestCase( SECTION, "'string' >= 'str'",              true,       'string' >= 'str' );
    
    array[item++] = new TestCase( SECTION, "'string' >= undefined",          false,       'string' >= undefined );
    array[item++] = new TestCase( SECTION, "undefined  >= 'string'",          false,       undefined  >= 'string' );
    array[item++] = new TestCase( SECTION, "6.9 >= undefined",               false,       6.9 >= undefined );
    array[item++] = new TestCase( SECTION, "undefined >= 343",               false,       undefined >= 343);

    array[item++] = new TestCase( SECTION, "44 >= 55",          false,       44 >= 55 );
    array[item++] = new TestCase( SECTION, "55 >= 44",          true,       55 >= 44 );
    array[item++] = new TestCase( SECTION, "56.43 >= 65.0",          false,       56.43 >= 65.0 );
    array[item++] = new TestCase( SECTION, "65.0 >= 56.43",          true,       65.0 >= 56.43 );
    array[item++] = new TestCase( SECTION, "43247503.43 >= 945540654.654",          false,       43247503.43 >= 945540654.654 );
    array[item++] = new TestCase( SECTION, "43247503.43>=945540654.654",          false,       43247503.43>=945540654.654 );
    array[item++] = new TestCase( SECTION, "43247503.43>= 945540654.654",          false,       43247503.43>= 945540654.654 );
    array[item++] = new TestCase( SECTION, "43247503.43   >=  945540654.654",          false,       43247503.43   >=  945540654.654 );
    array[item++] = new TestCase( SECTION, "-56.43 >= 65.0",          false,       -56.43 >= 65.0 );
    array[item++] = new TestCase( SECTION, "-56.43 >= -65.0",          true,       -56.43 >= -65.0 );
    array[item++] = new TestCase( SECTION, "100 >= 100",               true,      100 >= 100 );
    array[item++] = new TestCase( SECTION, "-56.43 >= -56.43",          true,       -56.43 >= -56.43 );


    return ( array );
}
function MyObject(value) {
    this.value = value;
    //this.valueOf = new Function( "return this.value" );
    //this.toString = new Function( "return this.value +''" );
    this.valueOf = function(){return this.value};
    this.toString = function(){return this.value+''};
}
function MyValueObject(value) {
    this.value = value;
    //this.valueOf = new Function( "return this.value" );
    this.valueOf = function(){return this.value};
}
function MyStringObject(value) {
    this.value = value;
    //this.toString = new Function( "return this.value +''" );
    this.toString = function(){return this.value+''};
}
