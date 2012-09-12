/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    
    
    var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'String:concat';

    writeHeaderToLog('Executing script: concat.js');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = new getTestCases();
    test();
    
function getTestCases() {

    var array = new Array();
    var item = 0;
    
    var aString = new String("test string");
    var bString = new String(" another ");

    array[item++] = new TestCase( SECTION, "String.prototype.concat.length", 0,     String.prototype.concat.length);

    array[item++] = new TestCase( SECTION, "aString.concat(' more')", "test string more",     aString.concat(' more').toString());
    array[item++] = new TestCase( SECTION, "aString.concat(bString)", "test string another ", aString.concat(bString).toString());
    array[item++] = new TestCase( SECTION, "aString                ", "test string",          aString.toString());
    array[item++] = new TestCase( SECTION, "bString                ", " another ",            bString.toString());
    array[item++] = new TestCase( SECTION, "aString.concat(345)    ", "test string345",       aString.concat(345).toString());
    array[item++] = new TestCase( SECTION, "aString.concat(true)   ", "test stringtrue",      aString.concat(true).toString());
    array[item++] = new TestCase( SECTION, "aString.concat(null)   ", "test stringnull",      aString.concat(null).toString());
    array[item++] = new TestCase( SECTION, "aString.concat([])     ", "test string",          aString.concat([]).toString());
    array[item++] = new TestCase( SECTION, "aString.concat([1,2,3])", "test string1,2,3",     aString.concat([1,2,3]).toString());

    array[item++] = new TestCase( SECTION, "'abcde'.concat(' more')", "abcde more",     'abcde'.concat(' more').toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat(bString)", "abcde another ", 'abcde'.concat(bString).toString());
    array[item++] = new TestCase( SECTION, "'abcde'                ", "abcde",          'abcde');
    array[item++] = new TestCase( SECTION, "'abcde'.concat(345)    ", "abcde345",       'abcde'.concat(345).toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat(true)   ", "abcdetrue",      'abcde'.concat(true).toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat(null)   ", "abcdenull",      'abcde'.concat(null).toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat([])     ", "abcde",          'abcde'.concat([]).toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat([1,2,3])", "abcde1,2,3",     'abcde'.concat([1,2,3]).toString());
    array[item++] = new TestCase( SECTION, "'abcde'.concat([1,2,3])", "abcde1,2,33,4,5string12345nulltrueundefined",     'abcde'.concat([1,2,3],[3,4,5],'string',12345,null,true,undefined).toString());

    //what should this do:
    array[item++] = new TestCase( SECTION, "'abcde'.concat()       ", "abcde",          'abcde'.concat().toString());

    //concat method transferred to other objects for use as method
   
    var myobj = new Object();
       
    myobj.concat = String.prototype.concat;
       
       
    array[item++] = new TestCase( SECTION, "myobj.concat([1,2,3])", "[object Object]1,2,33,4,5string12345nulltrueundefined",     myobj.concat([1,2,3],[3,4,5],'string',12345,null,true,undefined).toString());
    
    return array;
}
