/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '15.5.4.12';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'String:search(regexp)';

    writeHeaderToLog('Executing script: search.as');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var aString = new String("test string");
    var bString = new String("one two three four five");

    var regExp = /Four/;
    
    result = aString.search("string").toString();
    array[item++] = new TestCase( SECTION, "aString.search(\"string\")", "5",  result);
    result = aString.search("String").toString();
    array[item++] = new TestCase( SECTION, "aString.search(\"String\")", "-1", result);
    array[item++] = new TestCase( SECTION, "aString.search(/String/i)", "5",     aString.search(/String/i).toString());
    array[item++] = new TestCase( SECTION, "bString.search(regExp)", "-1",     bString.search(regExp).toString());

    
    regExp = /four/;
    array[item++] = new TestCase( SECTION, "bString.search(regExp)", "14",     bString.search(regExp).toString());
    array[item++] = new TestCase( SECTION, "bString.search(/Four/i)", "14",     bString.search(/Four/i).toString());
    result = aString.search("notexist").toString();
    array[item++] = new TestCase( SECTION, "aString.search(/notexist/)", "-1", result);
    result = bString.search("notexist").toString();
    array[item++] = new TestCase( SECTION, "bString.search(\"notexist\")", "-1", result);

    return array;
}
