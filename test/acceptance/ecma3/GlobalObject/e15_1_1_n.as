/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.1-1-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Global Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    thisError="no error";
    try{
        new this();
    }catch(e:TypeError){
        thisError=e.toString();
    }finally{
      array[item++] = new TestCase( SECTION,
                                    "new this()",
                                    "TypeError: Error #1007",
                                    typeError(thisError) );
    }

    return ( array );
}
