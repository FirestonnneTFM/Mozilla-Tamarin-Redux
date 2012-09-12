/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "try-004";
    var VERSION = "ECMA_2";
    var TITLE   = "The try statement";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    TryToCatch( "Math.PI", Math.PI );
    TryToCatch2( "Thrower(5)",   "Caught 5" );
    TryToCatch3( "Thrower(\"some random exception\")", "Caught some random exception" );



    function Thrower( v ) {
        throw "Caught " + v;
    }


    // Math.PI
    function TryToCatch( value, expect ) {
        try {
            result = Math.PI;
        } catch ( e ) {
            result = e;
        }

        array[item++] = new TestCase(
            SECTION,
            value,
            expect,
            result );
    }

    //Thrower(5)
    function TryToCatch2( value, expect ) {
        try {
            result = Thrower(5);
        } catch ( e ) {
            result = e;
        }

        array[item++] = new TestCase(
            SECTION,
            value,
            expect,
            result );
    }

    // TryToCatch3( "Thrower(\"some random exception\")", "Caught some random exception" );
    function TryToCatch3( value, expect ) {
        try {
            result = Thrower("some random exception", "Caught some random exception" );
        } catch ( e ) {
            result = e;
        }

        array[item++] = new TestCase(
            SECTION,
            value,
            expect,
            result );
    }

    return array;
}
