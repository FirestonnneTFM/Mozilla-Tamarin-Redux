/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '15.2.4.6';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'isPrototypeOf';

    writeHeaderToLog('Executing script: isPrototypeOf');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var count = 0;
    var testcases = new Array();

    var re = new RegExp();


    testcases[count++] = new TestCase( SECTION, "RegExp.prototype.isPrototypeOf(re))", true,RegExp.prototype.isPrototypeOf(re));

    var str = new String("JScript");

    testcases[count++] = new TestCase( SECTION, "String.prototype.isPrototypeOf(str)", true,String.prototype.isPrototypeOf(str));

    testcases[count++] = new TestCase( SECTION, "String.prototype.isPrototypeOf(re)", false,String.prototype.isPrototypeOf(re));

    testcases[count++] = new TestCase( SECTION, "String.prototype.isPrototypeOf(new Number())", false,String.prototype.isPrototypeOf(new Number()));

    testcases[count++] = new TestCase( SECTION, "Object.prototype.isPrototypeOf(str)", true,Object.prototype.isPrototypeOf(str));

    testcases[count++] = new TestCase( SECTION, "Object.prototype.isPrototypeOf(re)", true,Object.prototype.isPrototypeOf(re));

    var myobj = new Object();


    testcases[count++] = new TestCase( SECTION, "String.prototype.isPrototypeOf(myobj)", false,String.prototype.isPrototypeOf(myobj));

    var myobj2 = null;

    testcases[count++] = new TestCase( SECTION, "Object.prototype.isPrototypeOf(myobj2)", false,Object.prototype.isPrototypeOf(myobj2));


    test();

