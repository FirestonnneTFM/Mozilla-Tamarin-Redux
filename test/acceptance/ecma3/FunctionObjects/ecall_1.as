/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "call-1";
    var VERSION = "ECMA_2";
    var TITLE   = "Function.prototype.call";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    array[item++] = new TestCase( SECTION,
                        "ToString.call( this, this )",
                        GLOBAL,
                        ToString.call( this, this ) );

    array[item++] = new TestCase( SECTION,
                        "ToString.call( Boolean, Boolean.prototype )",
                        "false",
                        ToString.call( Boolean, Boolean.prototype+"" ) );

    array[item++] = new TestCase( SECTION,
                        "ToString.call( Boolean, Boolean.prototype.valueOf() )",
                        "false",
                        ToString.call( Boolean, Boolean.prototype.valueOf()+"" ) );
    return array;
}

function ToString( obj ) {
    return obj +"";
}
