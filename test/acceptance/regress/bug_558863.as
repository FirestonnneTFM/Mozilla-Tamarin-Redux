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
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=558863
 *
 */
//-----------------------------------------------------------------------------

var SECTION = "regress_558863";
var VERSION = "AS3";
var TITLE   = "bytearray in operator throws exception for non-natural number";
var bug = "558863";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {

    import avmplus.System;
    import flash.utils.ByteArray;

    function checkExn( x, thunk, expectExn )
    {
        try {
            var retval = thunk();
            return !expectExn && retval;
        } catch (e) {
            // trace("threw up on "+typeof(x)+" "+x);
            return expectExn;
        }
    }

    var b = new ByteArray()
    b[0] = 1
    b[2] = 1

    function trial( x, expect, expectExn )
    {
        var f = function () { return Boolean(int(!expect) ^ int(x in b)) };
        return checkExn( x, f, expectExn );
    }

    function btest_pre_bugfix()
    {
        return (trial(0, true,  false)
                && trial(1, true,  false)
                && trial(2, true,  false)
                && trial(3, false, false)

                // non-naturals below
                && trial(true, false, true)
                && trial("xy", false, true)
                && trial({},   false, true)
                && trial(5.5,  false, true)
                && trial(-5,   false, true))
    }

    function btest_post_bugfix()
    {
        return (trial(0, true,  false)
                && trial(1, true,  false)
                && trial(2, true,  false)
                && trial(3, false, false)

                // non-naturals below
                && trial(true, false, false)
                && trial("xy", false, false)
                && trial({},   false, false)
                && trial(5.5,  false, false)
                && trial(-5,   false, false))
    }

    var array:Array = new Array();
    if (System.swfVersion >= 11) {
        var status = "Verify byte-array in does not throw";
        var actual = btest_post_bugfix();
        var expect = true;
        array[0] = new TestCase(SECTION, status, expect, actual)
    } else {
        var status = "Verify byte-array in throws when expected";
        var actual = btest_pre_bugfix();
        var expect = true;
        array[0] = new TestCase(SECTION, status, expect, actual)
    }
    return array;
}
