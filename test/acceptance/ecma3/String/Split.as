/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '15.5.4.14';
    var VERSION = 'no version';

    startTest();
    var TITLE = 'String:split';

    writeHeaderToLog('Executing script: split.as');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var count = 0;
    var testcases = new Array();

    var bString = new String("one,two,three,four,five");

    splitString = bString.split(",");
    testcases[count++] = new TestCase( SECTION, "String.split(\",\")", "one", splitString[0]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\",\")", "two", splitString[1]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\",\")", "three", splitString[2]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\",\")", "four", splitString[3]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\",\")", "five", splitString[4]);

    bString = new String("one two three four five");
    splitString = bString.split(" ");

    testcases[count++] = new TestCase( SECTION, "String.split(\" \")", "one", splitString[0]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\" \")", "two", splitString[1]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\" \")", "three", splitString[2]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\" \")", "four", splitString[3]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\" \")", "five", splitString[4]);

    bString = new String("one,two,three,four,five");
    splitString = bString.split();
    
    testcases[count++] = new TestCase( SECTION, "bString.split()", "one,two,three,four,five", splitString[0]);
    testcases[count++] = new TestCase( SECTION, "bString.split()", "one,two,three,four,five",
splitString.toString());
    
    bString = new String("one two three");
    splitString = bString.split("");

    testcases[count++] = new TestCase( SECTION, "bString.split(\"\")", "o", splitString[0]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\"\")", "n", splitString[1]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\"\")", "r", splitString[10]);
    testcases[count++] = new TestCase( SECTION, "bString.split(\"\")", "e", splitString[12]);

    bString = new String("one-1,two-2,four-4");
    regExp = /,/;
    splitString = bString.split(regExp);
    
    testcases[count++] = new TestCase( SECTION, "bString.split(regExp)", "one-1", splitString[0]);
    testcases[count++] = new TestCase( SECTION, "bString.split(regExp)", "two-2", splitString[1]);
    testcases[count++] = new TestCase( SECTION, "bString.split(regExp)", "four-4", splitString[2]);

    
    function test()
    {
       for ( tc=0; tc < testcases.length; tc++ ) {
            testcases[tc].passed = writeTestCaseResult(
            testcases[tc].expect,
            testcases[tc].actual,
            testcases[tc].description +" = "+
            testcases[tc].actual );
            testcases[tc].reason += ( testcases[tc].passed ) ? "" : "wrong value ";
       }
       stopTest();
       return ( testcases );
    }

    test();

