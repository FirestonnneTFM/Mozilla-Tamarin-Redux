/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.5.4.4-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.charAt";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var TEST_STRING = new String( " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" );

    var testcases = getTestCases();

    writeLineToLog( "TEST_STRING = new String(\" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\")" );
    
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    for (  i = 0x0020; i < 0x007e; i++, item++) {
        array[item] = new TestCase( SECTION,
                                "TEST_STRING.charAt("+item+")",
                                String.fromCharCode( i ),
                                TEST_STRING.charAt( item ) );
    }
    for ( i = 0x0020; i < 0x007e; i++, item++) {
        array[item] = new TestCase( SECTION,
                                "TEST_STRING.charAt("+item+") == TEST_STRING.substring( "+item +", "+ (item+1) + ")",
                                true,
                                TEST_STRING.charAt( item )  == TEST_STRING.substring( item, item+1 )
                                );
    }
    array[item++] = new TestCase( SECTION,  "String.prototype.charAt.length",       1,  String.prototype.charAt.length );

    return array;
}
