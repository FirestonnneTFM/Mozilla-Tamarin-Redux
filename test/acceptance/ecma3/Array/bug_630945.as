/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "Array";
    var VERSION = "ecma3";
    startTest();
    var TITLE   = "test that push() doesn't assume length == dense.length";

    writeHeaderToLog( SECTION + " "+ TITLE );


    var a:Array = [];

    a.push(0); // a[0]
    a.push(1); // a[1]
    AddTestCase("test 1",
        "0,1",
        a.toString());

    delete a[1];
    delete a[0];

    AddTestCase("test 2",
        ",",
        a.toString());

    a.push(2);
    a.push(3);

    AddTestCase("test 3",
        ",,2,3",
        a.toString());

    delete a[3];
    delete a[2];

    AddTestCase("test 4",
        ",,,",
        a.toString());

    a.push(4);
    a.push(5);

    AddTestCase("test 5",
        ",,,,4,5",
        a.toString());

    delete a[5];
    delete a[4];
    
    AddTestCase("test 6",
        ",,,,,",
        a.toString());

    test();

