/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "regress_700613";
var VERSION = "AS3";
var TITLE   = "uint coercion beyond MAX_VALUE";
var bug = "700613";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

function inc(arg)
{
    var n:uint = arg;
    n++;
    return n;
}

const MAX = uint.MAX_VALUE;

AddTestCase("uint(            -1  )++", 0,   inc(-1));
AddTestCase("uint(             0  )++", 1,   inc( 0));
AddTestCase("uint(uint.MAX_VALUE-1)++", MAX, inc( MAX-1));
AddTestCase("uint(uint.MAX_VALUE  )++", 0,   inc( MAX));
AddTestCase("uint(uint.MAX_VALUE+1)++", 1,   inc( MAX+1));

test();
