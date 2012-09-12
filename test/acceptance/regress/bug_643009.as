/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

    var a:Array = new Array;
    a[258] = "foo";
    a[259] = "bar";

    var results:Array = new Array;

    for (var idx:String in a)
    {
        results.push(idx);
        results.push(a[idx]);
    }

    for each (var v:String in a)
    {
        results.push(v);
    }

    AddTestCase(0, "258", String(results[0]));
    AddTestCase(1, "foo", results[1]);
    AddTestCase(2, "259", String(results[2]));
    AddTestCase(3, "bar", results[3]);
    AddTestCase(4, "foo", results[4]);
    AddTestCase(5, "bar", results[5]);

test();

