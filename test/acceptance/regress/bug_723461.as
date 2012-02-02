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
* The Original Code is [Open Source Virtual Machine.].
*
* The Initial Developer of the Original Code is
* Adobe System Incorporated.
* Portions created by the Initial Developer are Copyright (C) 2012
* the Initial Developer. All Rights Reserved.
*
* Contributor(s):
*   Adobe AS3 Team
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
* ***** END LICENSE BLOCK ***** */

var SECTION = "regress_723461";
var VERSION = "AS3";
var TITLE   = "ByteArray readUTFBytes does not properly update position when it starts at a UTF8 BOM";
var bug = "723461";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

import flash.utils.ByteArray;

function testCore(starting) {
    var results = {};
    var starting = 0;
    var b:ByteArray = new ByteArray();
    b.position = starting;
    b.writeUTFBytes('\ufeff1234');
    var posPostWrite = b.position;
    var len = b.length;
    b.writeUTFBytes('5678');
    var s1;
    var s2;
    var posPostRead;

    b.position = starting;
    try {
        s1 = b.readUTFBytes(len);
    } catch (e) { }
    posPostRead = b.position;

    try {
        s2 = b.readUTFBytes(4);
    } catch (e) { }


    results.s1 = s1;
    results.s2 = s2;
    results.posPostWrite = posPostWrite;
    results.posPostRead = posPostRead;

    return results;
}

function testStartAt0() {
    var results = testCore(0);

    AddTestCase("at 0 result string skips BOM",
                "1234",
                results.s1);

    AddTestCase("at 0 result subsequent reads correct",
                "5678",
                results.s2);

    AddTestCase("at 0 position updated correctly",
                results.posPostWrite,
                results.posPostRead);
}

function testStartAt10() {
    var results = testCore(10);

    AddTestCase("at 10 result string skips BOM",
                "1234",
                results.s1);

    AddTestCase("at 10 result subsequent reads correct",
                "5678",
                results.s2);

    AddTestCase("at 10 position updated correctly",
                results.posPostWrite,
                results.posPostRead);
}

testStartAt0();

testStartAt10();

test();
