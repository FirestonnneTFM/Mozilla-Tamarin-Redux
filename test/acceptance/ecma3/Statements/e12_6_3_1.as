/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "12.6.3-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The for..in statment";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var x;
    Number.prototype.foo = 34;
    for ( j in 7 )
    {
        x = j;
        if(x = "foo"){           //The property foo will be returned during anytime using for..in                //loop.  So added this if statement and break to test that foo is returned
            break;         //--Subha Subramanian
        }
    }

    if( x != "foo" ){
        x = "not foo";
    }
    
    array[item++] = new TestCase( SECTION,
        "var x; Number.prototype.foo = 34; for ( j in 7 ) x = j; x",
        "foo",
        x);
    return ( array );
}


function MyObject(a, b, c, d, e) {


}
