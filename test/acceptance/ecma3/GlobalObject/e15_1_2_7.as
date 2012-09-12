/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.2.7";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "isFinite( x )";

    var BUGNUMBER= "77391";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "isFinite.length",      1,                  isFinite.length );
    //array[item++] = new TestCase( SECTION, "isFinite.length = null; isFinite.length",   1,      eval("isFinite.length=null; isFinite.length") );

    var thisError:String = "no error";
    try
    {
        isFinite.length=null;
    }
    catch(e:ReferenceError)
    {
        thisError = e.toString();
    }
    finally
    {
        array[item++] = new TestCase(SECTION, "isFinite.length = null", "ReferenceError: Error #1074", referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION, "delete isFinite.length",                    false,  delete isFinite.length );
    //array[item++] = new TestCase( SECTION, "delete isFinite.length; isFinite.length",   1,      eval("delete isFinite.length; isFinite.length") );
    delete isFinite.length;
    array[item++] = new TestCase( SECTION, "delete isFinite.length; isFinite.length",   1, isFinite.length);

    var MYPROPS='';
    for ( var p in isFinite ) {
       MYPROPS += p;
    }


    array[item++] = new TestCase( SECTION, "var MYPROPS='', for ( var p in isFinite ) { MYPROPS+= p }, MYPROPS",    "", MYPROPS );

    array[item++] = new TestCase( SECTION,  "isFinite()",           false,              isFinite() );
    array[item++] = new TestCase( SECTION, "isFinite( null )",      true,              isFinite(null) );
    array[item++] = new TestCase( SECTION, "isFinite( void 0 )",    false,             isFinite(void 0) );
    array[item++] = new TestCase( SECTION, "isFinite( false )",     true,              isFinite(false) );
    array[item++] = new TestCase( SECTION, "isFinite( true)",       true,              isFinite(true) );
    array[item++] = new TestCase( SECTION, "isFinite( ' ' )",       true,              isFinite( " " ) );

    array[item++] = new TestCase( SECTION, "isFinite( new Boolean(true) )",     true,   isFinite(new Boolean(true)) );
    array[item++] = new TestCase( SECTION, "isFinite( new Boolean(false) )",    true,   isFinite(new Boolean(false)) );

    array[item++] = new TestCase( SECTION, "isFinite( 0 )",        true,              isFinite(0) );
    array[item++] = new TestCase( SECTION, "isFinite( 1 )",        true,              isFinite(1) );
    array[item++] = new TestCase( SECTION, "isFinite( 2 )",        true,              isFinite(2) );
    array[item++] = new TestCase( SECTION, "isFinite( 3 )",        true,              isFinite(3) );
    array[item++] = new TestCase( SECTION, "isFinite( 4 )",        true,              isFinite(4) );
    array[item++] = new TestCase( SECTION, "isFinite( 5 )",        true,              isFinite(5) );
    array[item++] = new TestCase( SECTION, "isFinite( 6 )",        true,              isFinite(6) );
    array[item++] = new TestCase( SECTION, "isFinite( 7 )",        true,              isFinite(7) );
    array[item++] = new TestCase( SECTION, "isFinite( 8 )",        true,              isFinite(8) );
    array[item++] = new TestCase( SECTION, "isFinite( 9 )",        true,              isFinite(9) );

    array[item++] = new TestCase( SECTION, "isFinite( '0' )",        true,              isFinite('0') );
    array[item++] = new TestCase( SECTION, "isFinite( '1' )",        true,              isFinite('1') );
    array[item++] = new TestCase( SECTION, "isFinite( '2' )",        true,              isFinite('2') );
    array[item++] = new TestCase( SECTION, "isFinite( '3' )",        true,              isFinite('3') );
    array[item++] = new TestCase( SECTION, "isFinite( '4' )",        true,              isFinite('4') );
    array[item++] = new TestCase( SECTION, "isFinite( '5' )",        true,              isFinite('5') );
    array[item++] = new TestCase( SECTION, "isFinite( '6' )",        true,              isFinite('6') );
    array[item++] = new TestCase( SECTION, "isFinite( '7' )",        true,              isFinite('7') );
    array[item++] = new TestCase( SECTION, "isFinite( '8' )",        true,              isFinite('8') );
    array[item++] = new TestCase( SECTION, "isFinite( '9' )",        true,              isFinite('9') );

    array[item++] = new TestCase( SECTION, "isFinite( 0x0a )",    true,                 isFinite( 0x0a ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0xaa )",    true,                 isFinite( 0xaa ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0x0A )",    true,                 isFinite( 0x0A ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0xAA )",    true,                 isFinite( 0xAA ) );

    array[item++] = new TestCase( SECTION, "isFinite( '0x0a' )",    true,               isFinite( "0x0a" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0xaa' )",    true,               isFinite( "0xaa" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0x0A' )",    true,               isFinite( "0x0A" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0xAA' )",    true,               isFinite( "0xAA" ) );

    array[item++] = new TestCase( SECTION, "isFinite( 077 )",       true,               isFinite( 077 ) );
    array[item++] = new TestCase( SECTION, "isFinite( '077' )",     true,               isFinite( "077" ) );

    array[item++] = new TestCase( SECTION, "isFinite( new String('Infinity') )",        false,      isFinite(new String("Infinity")) );
    array[item++] = new TestCase( SECTION, "isFinite( new String('-Infinity') )",       false,      isFinite(new String("-Infinity")) );

    array[item++] = new TestCase( SECTION, "isFinite( 'Infinity' )",        false,      isFinite("Infinity") );
    array[item++] = new TestCase( SECTION, "isFinite( '-Infinity' )",       false,      isFinite("-Infinity") );
    array[item++] = new TestCase( SECTION, "isFinite( Number.POSITIVE_INFINITY )",  false,  isFinite(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.NEGATIVE_INFINITY )",  false,  isFinite(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.NaN )",                false,  isFinite(Number.NaN) );

    array[item++] = new TestCase( SECTION, "isFinite( Infinity )",  false,  isFinite(Infinity) );
    array[item++] = new TestCase( SECTION, "isFinite( -Infinity )",  false,  isFinite(-Infinity) );
    array[item++] = new TestCase( SECTION, "isFinite( NaN )",                false,  isFinite(NaN) );


    array[item++] = new TestCase( SECTION, "isFinite( Number.MAX_VALUE )",          true,  isFinite(Number.MAX_VALUE) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.MIN_VALUE )",          true,  isFinite(Number.MIN_VALUE) );

    return ( array );
}
