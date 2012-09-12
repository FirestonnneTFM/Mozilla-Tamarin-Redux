/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.3.1-1";
    var VERSION = "ECMA_2";
    startTest();
    var TITLE   = "Function.prototype";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    // Result is false. See http://flashqa.macromedia.com/bugapp/detail.asp?ID=122988
    array[item++] = new TestCase( SECTION, "Function.constructor.prototype == Function.prototype", false, Function.constructor.prototype == Function.prototype );
    
    return array;
}
