/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "11_13_2_1";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Compound Assignment: *=");
    test();

function getTestCases()
{
    var array = new Array();
    var item = 0;

    // NaN cases

    VAR1 = Number.NaN; VAR2=1;
    array[item++] = new TestCase( SECTION,    "VAR1 = NaN; VAR2=1; VAR1 *= VAR2",       Number.NaN,  VAR1 *= VAR2 );
    VAR1 = Number.NaN; VAR2=1; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = NaN; VAR2=1; VAR1 *= VAR2; VAR1", Number.NaN,  VAR1 );

    // number cases
    VAR1 = 0; VAR2=1;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2=1; VAR1 *= VAR2",         0,          VAR1 *= VAR2 );
    VAR1 = 0; VAR2=1; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2=1; VAR1 *= VAR2;VAR1",    0,          VAR1 );
    VAR1 = 0XFF; VAR2 = 0XA;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0xFF; VAR2 = 0xA, VAR1 *= VAR2", 2550,      VAR1 *= VAR2 );

    // special multiplication cases
    VAR1 = 0; VAR2 = Number.POSITIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2= Infinity; VAR1 *= VAR2",    Number.NaN,      VAR1 );
    VAR1 = -0; VAR2 = Number.POSITIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = -0; VAR2= Infinity; VAR1 *= VAR2",   Number.NaN,      VAR1 );
     VAR1 = -0; VAR2 = Number.NEGATIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = -0; VAR2= -Infinity; VAR1 *= VAR2",  Number.NaN,      VAR1 );
    VAR1 = 0; VAR2 = Number.NEGATIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2= -Infinity; VAR1 *= VAR2",   Number.NaN,      VAR1 );
    VAR1 = 0; VAR2 = Number.POSITIVE_INFINITY; VAR2 *= VAR1;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2= Infinity; VAR2 *= VAR1",    Number.NaN,       VAR2 );
    VAR1 = -0; VAR2 = Number.POSITIVE_INFINITY; VAR2 *= VAR1;
    array[item++] = new TestCase( SECTION,    "VAR1 = -0; VAR2= Infinity; VAR2 *= VAR1",   Number.NaN,       VAR2 );
    VAR1 = -0; VAR2 = Number.NEGATIVE_INFINITY; VAR2 *= VAR1;
    array[item++] = new TestCase( SECTION,    "VAR1 = -0; VAR2= -Infinity; VAR2 *= VAR1",  Number.NaN,       VAR2 );
    VAR1 = 0; VAR2 = Number.NEGATIVE_INFINITY; VAR2 *= VAR1;
    array[item++] = new TestCase( SECTION,    "VAR1 = 0; VAR2= -Infinity; VAR2 *= VAR1",   Number.NaN,       VAR2 );
    VAR1 = Number.POSITIVE_INFINITY; VAR2 = Number.POSITIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = Infinity; VAR2= Infinity; VAR1 *= VAR2",   Number.POSITIVE_INFINITY,       VAR1 );
    VAR1 = Number.POSITIVE_INFINITY; VAR2 = Number.NEGATIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = Infinity; VAR2= -Infinity; VAR1 *= VAR2",  Number.NEGATIVE_INFINITY,       VAR1 );
    VAR1 = Number.NEGATIVE_INFINITY; VAR2 = Number.POSITIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 =-Infinity; VAR2= Infinity; VAR1 *= VAR2",   Number.NEGATIVE_INFINITY,       VAR1 );
    VAR1 = Number.NEGATIVE_INFINITY; VAR2 = Number.NEGATIVE_INFINITY; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 =-Infinity; VAR2=-Infinity; VAR1 *= VAR2",   Number.POSITIVE_INFINITY,       VAR1 );

    // string cases
    VAR1 = 10; VAR2 = '255';
    array[item++] = new TestCase( SECTION,    "VAR1 = 10; VAR2 = '255', VAR1 *= VAR2", 2550,        VAR1 *= VAR2 );
    VAR1 = '255'; VAR2 = 10;
    array[item++] = new TestCase( SECTION,    "VAR1 = '255'; VAR2 = 10, VAR1 *= VAR2", 2550,        VAR1 *= VAR2 );
    VAR1 = 10; VAR2 = '0XFF';
    array[item++] = new TestCase( SECTION,    "VAR1 = 10; VAR2 = '0XFF', VAR1 *= VAR2", 2550,       VAR1 *= VAR2 );
    VAR1 = '0XFF'; VAR2 = 0XA;
    array[item++] = new TestCase( SECTION,    "VAR1 = '0xFF'; VAR2 = 0xA, VAR1 *= VAR2", 2550,       VAR1 *= VAR2 );
    VAR1 = '10'; VAR2 = '255';
    array[item++] = new TestCase( SECTION,    "VAR1 = '10'; VAR2 = '255', VAR1 *= VAR2", 2550,       VAR1 *= VAR2);
    VAR1 = '10'; VAR2 = '0XFF';
    array[item++] = new TestCase( SECTION,    "VAR1 = '10'; VAR2 = '0XFF', VAR1 *= VAR2", 2550,      VAR1 *= VAR2);
    VAR1 = '0XFF'; VAR2 = 0XA;
    array[item++] = new TestCase( SECTION,    "VAR1 = '0xFF'; VAR2 = 0xA, VAR1 *= VAR2", 2550,      VAR1 *= VAR2);

    // boolean cases
    VAR1 = true; VAR2 = false;
    array[item++] = new TestCase( SECTION,    "VAR1 = true; VAR2 = false; VAR1 *= VAR2",    0,       VAR1 *= VAR2 );
    VAR1 = true; VAR2 = true;
    array[item++] = new TestCase( SECTION,    "VAR1 = true; VAR2 = true; VAR1 *= VAR2",    1,      VAR1 *= VAR2);

    // object cases
    VAR1 = new Boolean(true); VAR2 = 10; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = new Boolean(true); VAR2 = 10; VAR1 *= VAR2;VAR1",    10,       VAR1 );
    VAR1 = new Number(11); VAR2 = 10; VAR1 *= VAR2;
    array[item++] = new TestCase( SECTION,    "VAR1 = new Number(11); VAR2 = 10; VAR1 *= VAR2; VAR1",    110,      VAR1);
    VAR1 = new Number(11); VAR2 = new Number(10);
    array[item++] = new TestCase( SECTION,    "VAR1 = new Number(11); VAR2 = new Number(10); VAR1 *= VAR2",    110,       VAR1 *= VAR2 );
    VAR1 = String('15'); VAR2 = new String('0xF');
    array[item++] = new TestCase( SECTION,    "VAR1 = new String('15'); VAR2 = new String('0xF'); VAR1 *= VAR2",    225,      VAR1 *= VAR2);

    return ( array );
}
