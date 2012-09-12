/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

var SECTION = "regress_663469";
var VERSION = "AS3";
var TITLE   = "restArgs optimization needs error checking for double-atom case";
var bug = "663469";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

function runTest(...args)
{
    // sample a variety of integers that are out of range, *and*
    // too large to fit into kIntptrType atom on 32-bit builds.
    // (Some may happen to not crash, depending on memory layout,
    // but all are accessing undefined memory.)
    var idx:int;
    idx = 0x1fffffff; AddTestCase("args["+String(idx)+"]","undefined",String(args[idx]));
    idx = 0x2fffffff; AddTestCase("args["+String(idx)+"]","undefined",String(args[idx]));
    idx = 0x7fffffff; AddTestCase("args["+String(idx)+"]","undefined",String(args[idx]));
    idx = 0xdeadbeef; AddTestCase("args["+String(idx)+"]","undefined",String(args[idx]));
    idx = 0x5DCD64BA; AddTestCase("args["+String(idx)+"]","undefined",String(args[idx]));
}
function doRunTest()
{
    // must call runTest() from a jitted method
    runTest();
}
doRunTest();

test();


