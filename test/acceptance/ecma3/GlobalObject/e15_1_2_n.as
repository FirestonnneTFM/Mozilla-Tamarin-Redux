/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.1-2-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Global Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = new Array();
    thisError="no error";
    try{
       this();
    }catch(e:TypeError){
       thisError=e.toString();
    }finally{

    testcases[tc] = new TestCase(   SECTION,
                                    "this()",
                                    "TypeError: Error #1006",
                                    typeError(thisError) );
    }
    test();
