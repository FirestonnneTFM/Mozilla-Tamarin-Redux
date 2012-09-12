/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "e11_2_3_1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function Calls";

    writeHeaderToLog( SECTION + " "+ TITLE);
    var testcases = getTestCases();

    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    // MemberExpression:  Identifier

    var OBJECT = true;

    array[item++] = new TestCase( SECTION,
                                    "OBJECT.toString()",
                                    "true",
                                    OBJECT.toString() );

    // MemberExpression[ Expression]

    array[item++] = new TestCase( SECTION,
                                    "(new Array())['length'].valueOf()",
                                    0,
                                    (new Array())["length"].valueOf() );

    // MemberExpression . Identifier
    array[item++] = new TestCase( SECTION,
                                    "(new Array()).length.valueOf()",
                                    0,
                                    (new Array()).length.valueOf() );
    // new MemberExpression Arguments

    array[item++] = new TestCase( SECTION,
                                    "(new Array(20))['length'].valueOf()",
                                    20,
                                    (new Array(20))["length"].valueOf() );
    return array;
}
