/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "10.1.4-2";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Scope Chain and Identifier Resolution");

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( "SECTION", "with MyObject, eval should return square of ", "", "" );

    for ( tc=0; tc < array.length; tc++ ) {
        var MYOBJECT = new MyObject();
        var INPUT = 2;
        array[tc].description += "( "+INPUT +" )" ;

        with ( this ) {
            with ( MYOBJECT ) {
                array[tc].actual = eval( INPUT );
                array[tc].expect = Math.pow(INPUT,2);
            }
        }
    }

    return ( array );
}

function MyObject() {
    //this.eval = new Function( "x", "return(Math.pow(Number(x),2))" );
    this.eval = function(x){ return(Math.pow(Number(x),2));}
}
