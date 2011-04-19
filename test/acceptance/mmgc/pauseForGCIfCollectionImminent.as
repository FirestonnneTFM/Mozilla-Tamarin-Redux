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
 * Portions created by the Initial Developer are Copyright (C) 2009
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
try {
    import avmplus. * ; // System class in the avmshell
} catch (e) {
    import flash.system. * ; // System class in the flash player
}

var SECTION = "System::pauseForGCIfCollectionImminent";
var VERSION = "";
startTest();
var TITLE = "Test pauseForGCIfCollectionImminent api";


class Node {
    var left: Node, right: Node;
    var i: int, j: int;

    function Node(l: Node = null,
    r: Node = null) {
        left = l;
        right = r;
    }
}

var fractions = [Number.MIN_VALUE, 0, -0, 0.2499999, 0.25, 0.5, 0.75, 1.0];
for each(var f in fractions) {
    trace("starting pauseForGCIfCollectionImminent test @ " + f);

    var hits = 0;
    var a = [];
    for (var i = 0; i < 1000; i++) {
        for (var j = 0; j < 1000; j++)
        a[0] = 3.14159 + i * j; // compute a Number and store it in a * location to box it
        var before = System.totalMemory - System.freeMemory;
        System.pauseForGCIfCollectionImminent(f);
        var after = System.totalMemory - System.freeMemory;
        
        if (after < before)
            hits++;
        if (((i + 1) % 100) == 0)
            trace("Hits: " + hits);
    }

    AddTestCase("pauseForGCIfCollectionImminent test f=" + f + " : hits="+hits,
                true,
                ((hits > 0) == (f < 1.0)));
}

// Error cases
if (playerType == 'AVMPlus') {
    expected_error = "ArgumentError: Error #1508";
} else {
    expected_error = "ArgumentError: Error #2004";
}

var error_cases = [NaN, undefined, Number.NEGATIVE_INFINITY,
                   -1, 1.000000001, 10000, Number.MAX_VALUE,
                   Number.POSITIVE_INFINITY];

for each(var ec in error_cases) {
    error = "no error";
    try {
        System.pauseForGCIfCollectionImminent(ec);
    } catch (err) {
        error = err.toString().substr(0, expected_error.length);
    }
    AddTestCase("pauseForGCIfCollectionImminent error - " + ec,
                expected_error, error);
}

test();
