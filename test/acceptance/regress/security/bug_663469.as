/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK *****
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


