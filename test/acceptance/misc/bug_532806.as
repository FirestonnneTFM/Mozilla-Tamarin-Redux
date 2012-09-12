/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

function test_switch(i)
{
    var j = "FAILED";
    switch (i)
    {
        default: j = "PASSED";
    }
    return j;
}

startTest();
AddTestCase("test", "PASSED", test_switch(0));

test();
