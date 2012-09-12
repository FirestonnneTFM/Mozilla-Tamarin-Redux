/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "6-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Source Text";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    // encoded quotes should not end a quote

    var s = 'PAS\u0022SED';
      
    array[item++]= new TestCase(  SECTION,
                                    "var s = 'PAS\\u0022SED'; s",
                                    "PAS\"SED",
                                    s);
    var s = "PAS\u0022SED";
    
    array[item++]= new TestCase(  SECTION,
                                    'var s = "PAS\\u0022SED"; s',
                                    "PAS\"SED",
                                     s );

    var s = 'PAS\u0027SED';
    
    array[item++]= new TestCase(  SECTION,
                                    "var s = 'PAS\\u0027SED'; s",
                                    "PAS\'SED",
                                    s);

    var s = "PAS\u0027SED";
    
    array[item++]= new TestCase(  SECTION,
                                    'var s = "PAS\\u0027SED"; s',
                                    "PAS\'SED",
                                     s );
    var s = "PAS\u0027SED";
    
    array[item++] = new TestCase( SECTION,
                                    'var s = "PAS\\u0027SED"; s',
                                    "PAS\'SED",
                                    s )
   
    var s = "PAS\u0022SED";
    array[item++]= new TestCase(  SECTION,
                                    'var s = "PAS\\u0027SED"; s',
                                    "PAS\"SED",
                                    s );
    

    return array;
}
