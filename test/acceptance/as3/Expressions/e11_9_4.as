/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "11.9.4";
    var VERSION = "ECMA_1";
    var BUGNUMBER="77393";
    
    startTest();
    var testcases = getTestCases();
    writeHeaderToLog( SECTION + " The Strict Equals Operator ( === )");
    test();
    
class AObj {
    function AObj() {}
}

function MyObject( value ) {
    this.value = value;
    //this.valueOf = new Function( "return this.value" );
    this.valueOf = function(){return this.value};
}

function getTestCases() {
    var array = new Array();
    var item = 0;

    // type x and type y are the same.  if type x is undefined or null, return true
    array[item++] = new TestCase( SECTION,    "void 0 === void 0",        true,   void 0 === void 0 );
    array[item++] = new TestCase( SECTION,    "null === null",          true,   null === null );

    //  if x is NaN, return false. if y is NaN, return false
    array[item++] = new TestCase( SECTION,    "NaN === NaN",             false,  Number.NaN === Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN === 0",               false,  Number.NaN === 0 );
    array[item++] = new TestCase( SECTION,    "0 === NaN",               false,  0 === Number.NaN );
    array[item++] = new TestCase( SECTION,    "NaN === Infinity",        false,  Number.NaN === Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Infinity === NaN",        false,  Number.POSITIVE_INFINITY === Number.NaN );

    // if x is the same number value as y, return true
    var bn = (12345.6789 === 12345.678900);
    array[item++] = new TestCase( SECTION,    "12345.6789 === 12345.678900",   true,   bn);
    array[item++] = new TestCase( SECTION,    "Number.MAX_VALUE === Number.MAX_VALUE",   true,   Number.MAX_VALUE === Number.MAX_VALUE );
    array[item++] = new TestCase( SECTION,    "Number.MIN_VALUE === Number.MIN_VALUE",   true,   Number.MIN_VALUE === Number.MIN_VALUE );
    array[item++] = new TestCase( SECTION,    "Number.POSITIVE_INFINITY === Number.POSITIVE_INFINITY",   true,   Number.POSITIVE_INFINITY === Number.POSITIVE_INFINITY );
    array[item++] = new TestCase( SECTION,    "Number.NEGATIVE_INFINITY === Number.NEGATIVE_INFINITY",   true,   Number.NEGATIVE_INFINITY === Number.NEGATIVE_INFINITY );

    //  if x is 0 and y is -0, return true.   if x is -0 and y is 0, return true.
    array[item++] = new TestCase( SECTION,    "0 === 0",                 true,   0 === 0 );
    array[item++] = new TestCase( SECTION,    "0 === -0",                true,   0 === -0 );
    array[item++] = new TestCase( SECTION,    "-0 === 0",                true,   -0 === 0 );
    var b0 = (-0 === -0);
    array[item++] = new TestCase( SECTION,    "-0 === -0",               true,   b0);

    // return false.
    array[item++] = new TestCase( SECTION,    "0.9 === 1",               false,  0.9 === 1 );
    array[item++] = new TestCase( SECTION,    "0.999999 === 1",          false,  0.999999 === 1 );
    array[item++] = new TestCase( SECTION,    "0.9999999999 === 1",      false,  0.9999999999 === 1 );
    array[item++] = new TestCase( SECTION,    "0.9999999999999 === 1",   false,  0.9999999999999 === 1 );

    // type x and type y are the same type, but not numbers
    // x and y are strings.  return true if x and y are exactly the same sequence of characters
    // otherwise, return false
    array[item++] = new TestCase( SECTION,    "'hello' === 'hello'",         true,   "hello" === "hello" );
    array[item++] = new TestCase( SECTION,    "'helloWorld' === 'hello'",    false,   "helloWorld" === "hello" );

    // x and y are booleans.  return true if both are true or both are false
    array[item++] = new TestCase( SECTION,    "true === true",               true,   true === true );
    array[item++] = new TestCase( SECTION,    "false === false",             true,   false === false );
    array[item++] = new TestCase( SECTION,    "true === false",              false,  true === false );
    array[item++] = new TestCase( SECTION,    "false === true",              false,  false === true );

    // return true if x and y refer to the same object.  otherwise return false
    var myobj1 = new MyObject(true);
    var myobj2 = myobj1;
    array[item++] = new TestCase( SECTION,    "var myobj1 = new MyObject(true); var myobj2 = myobj1; myobj1 === myobj2",  true,  myobj1 === myobj2 );
    array[item++] = new TestCase( SECTION,    "new MyObject(true) === new MyObject(true)",   false,  new MyObject(true) === new MyObject(true) );
    array[item++] = new TestCase( SECTION,    "new Boolean(true) === new Boolean(true)",     true,  new Boolean(true) === new Boolean(true) );
    array[item++] = new TestCase( SECTION,    "new Boolean(false) === new Boolean(false)",   true,  new Boolean(false) === new Boolean(false) );

    x = new MyObject(true); y = x; z = x;
    array[item++] = new TestCase( SECTION,    "x = new MyObject(true); y = x; z = x; z === y",   true,   z === y );
    x = new MyObject(false); y = x; z = x;
    array[item++] = new TestCase( SECTION,    "x = new MyObject(false); y = x; z = x; z === y",  true,  z === y );
    x = new Boolean(true); y = x; z = x;
    array[item++] = new TestCase( SECTION,    "x = new Boolean(true); y = x; z = x; z === y",   true,  z === y );
    x = new Boolean(false); y = x; z = x;
    array[item++] = new TestCase( SECTION,   "x = new Boolean(false); y = x; z = x; z === y",   true,  z === y );

    array[item++] = new TestCase( SECTION,    "new String(\"string\") === new String(\"string\")",     true,  new String("string") === new String("string") );
    array[item++] = new TestCase( SECTION,    "new String(\"string\") === \"string\"",   true,  new String("string") === "string" );

    // if Type(x) is different from Type(y), return false
    array[item++] = new TestCase( SECTION,    "null === void 0",             false,   null === void 0 );
    array[item++] = new TestCase( SECTION,    "void 0 === null",             false,   void 0 === null );
    array[item++] = new TestCase( SECTION,    "undefined === 5.44",          false,   undefined === 5.44 );
    array[item++] = new TestCase( SECTION,    "null === \"fdsee3f\" ",       false,   null === "fdsee3f" );
    
    // if Type(x) is Undefined, return true
    var an_undefined_var;
    var obj:Object;
    array[item++] = new TestCase( SECTION,    "undefined === an_undefined_var",  true,   undefined === an_undefined_var );
    array[item++] = new TestCase( SECTION,    "var obj:Object; obj === an_undefined_var",  false,   obj === an_undefined_var );
    
    // if Type(x) is Null, return true
    var nullobj:AObj;
    var b = (nullobj === null);
    //trace("nullobj = "+nullobj);
    array[item++] = new TestCase( SECTION,    "var nullobj:AObj; nullobj === null ",     true,   b );
    
    // if type(x) is Number and type(y) is string, return false
    array[item++] = new TestCase( SECTION,    "1 === '1'",                   false,   1 === '1' );
    array[item++] = new TestCase( SECTION,    "255 === '0xff'",              false,  255 === '0xff' );
    array[item++] = new TestCase( SECTION,    "0 === '\r'",                  false,   0 === "\r" );
    array[item++] = new TestCase( SECTION,    "1e19 === '1e19'",             false,   1e19 === "1e19" );

    array[item++] = new TestCase( SECTION,    "new Boolean(true) === true",  true,   true === new Boolean(true) );
    array[item++] = new TestCase( SECTION,    "new MyObject(true) === true", false,   true === new MyObject(true) );

    array[item++] = new TestCase( SECTION,    "new Boolean(false) === false",    true,   new Boolean(false) === false );
    array[item++] = new TestCase( SECTION,    "new MyObject(false) === false",   false,   new MyObject(false) === false );

    array[item++] = new TestCase( SECTION,    "true === new Boolean(true)",      true,   true === new Boolean(true) );
    array[item++] = new TestCase( SECTION,    "true === new MyObject(true)",     false,   true === new MyObject(true) );

    array[item++] = new TestCase( SECTION,    "false === new Boolean(false)",    true,   false === new Boolean(false) );
    array[item++] = new TestCase( SECTION,    "false === new MyObject(false)",   false,   false === new MyObject(false) );

    return ( array );
}


