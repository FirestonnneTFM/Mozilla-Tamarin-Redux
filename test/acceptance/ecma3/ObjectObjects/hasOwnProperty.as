/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '15.2.4.5';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'hasOwnProperty';

    writeHeaderToLog('Executing script: hasOwnProperty.as');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var count = 0;
    var testcases = new Array();


    testcases[count++] = new TestCase( SECTION, "String.prototype.hasOwnProperty(\"split\")", true,String.prototype.hasOwnProperty("split"));

    var str = new String("JScript");

    testcases[count++] = new TestCase( SECTION, "str.hasOwnProperty(\"split\")", false,str.hasOwnProperty("split"));

    testcases[count++] = new TestCase( SECTION, "Array.prototype.hasOwnProperty(\"pop\")", true,Array.prototype.hasOwnProperty("pop"));

    testcases[count++] = new TestCase( SECTION, "Number.prototype.hasOwnProperty(\"toPrecision\")", true,Number.prototype.hasOwnProperty("toPrecision"));

    testcases[count++] = new TestCase( SECTION, "Date.prototype.hasOwnProperty(\"getTime\")", true,Date.prototype.hasOwnProperty("getTime"));

    testcases[count++] = new TestCase( SECTION, "RegExp.prototype.hasOwnProperty(\"exec\")", true,RegExp.prototype.hasOwnProperty("exec"));

    testcases[count++] = new TestCase( SECTION, "String.prototype.hasOwnProperty(\"random\")", false,String.prototype.hasOwnProperty("random"));

    testcases[count++] = new TestCase( SECTION, "Object.prototype.hasOwnProperty(\"constructor\")", true,Object.prototype.hasOwnProperty("constructor"));

    testcases[count++] = new TestCase( SECTION, "Object.prototype.hasOwnProperty(\"getTime\")", false,Object.prototype.hasOwnProperty("getTime"));

    var myobj = new Object();

    testcases[count++] = new TestCase( SECTION, "myobj.hasOwnProperty(\"constructor\")", false,myobj.hasOwnProperty("constructor"));


    test();
