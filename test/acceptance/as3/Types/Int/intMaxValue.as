/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var SECTION = "int.MAX_VALUE";
var VERSION = "AS3";
startTest();
var TITLE =  "int.MAX_VALUE";

writeHeaderToLog( SECTION + " "+ TITLE);

var testcases = getTestCases();

test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    // MAX_VALUE
    array[item++] = new TestCase( SECTION, "int.MAX_VALUE",      2147483647,     int.MAX_VALUE );

    // MAX_VALUE should be read-only
    delete( int.MAX_VALUE );
    array[item++] = new TestCase( SECTION, "delete( int.MAX_VALUE ); int.MAX_VALUE",      2147483647, int.MAX_VALUE );
    array[item++] = new TestCase( SECTION, "delete( int.MAX_VALUE )",                        false,                  delete(int.MAX_VALUE) );

    // moved to error folder
    //int.MAX_VALUE=0;
    //array[item++] = new TestCase( SECTION, "int.MAX_VALUE=0,int.MAX_VALUE", 2147483647, int.MAX_VALUE );

    var string:String = '';
    for ( var prop in int ) {
        string += ( prop == 'MAX_VALUE' ) ? prop : '';
    }

    array[item++] = new TestCase(
                    SECTION,
                    "var string = ''; for ( prop in int) { string += ( prop == 'MAX_VALUE' ) ? prop : '' } string;",
                    "",
                    string
                    );
    
    return ( array );
}

/*function test() {
        for ( tc = 0; tc < testcases.length; tc++ ) {
            testcases[tc].passed = writeTestCaseResult(
                            testcases[tc].expect,
                            testcases[tc].actual,
                            testcases[tc].description +" = "+ testcases[tc].actual );
        }
        stopTest();
        return ( testcases );
}*/



