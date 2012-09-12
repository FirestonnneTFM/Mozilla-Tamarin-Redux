/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '12.4';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'Statement:expression';

    writeHeaderToLog('Executing script: expression.as');
    writeHeaderToLog( SECTION + " "+ TITLE);


    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
            
    var t;
    var x = 3;
    var y= 5;
    ExpressionStatement: t = x + y;
            
    
    array[item++] = new TestCase( SECTION, "Expression:{t}", 8, t);
    return array;
}
