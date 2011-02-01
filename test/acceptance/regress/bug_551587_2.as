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

var SECTION = "regress_551587_2";
var VERSION = "AS3";
var TITLE   = "MathClass:_min and _max does not correctly handle -0";
var bug = "551587";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

import avmplus.System;

if (System.swfVersion >= 11) {
    AddTestCase(
        "SWF 11+: 1.0/Math.min(-0.0, 0.0)",
        -Infinity,
        1.0/Math.min(-0.0, 0.0));
    AddTestCase(
        "SWF 11+: 1.0/Math.max(0.0, -0.0)",
        Infinity,
        1.0/Math.max(0.0, -0.0));
} else {
    // Bug only happens in wordcode and jit builds
    if (System.getRunmode().indexOf('jit') != -1 ||
        System.getFeatures().indexOf('AVMFEATURE_WORDCODE_INTERP') != -1)
    {
        AddTestCase(
        "SWF < 11, jit or wordcode build 1.0/Math.min(-0.0, 0.0)",
        Infinity,
        1.0/Math.min(-0.0, 0.0));
        AddTestCase(
        "SWF < 11, jit or wordcode build 1.0/Math.max(0.0, -0.0)",
        -Infinity,
        1.0/Math.max(0.0, -0.0));
    } else {
        AddTestCase(
        "SWF < 11, 1.0/Math.min(-0.0, 0.0)",
        -Infinity,
        1.0/Math.min(-0.0, 0.0));
        AddTestCase(
        "SWF < 11, 1.0/Math.max(0.0, -0.0)",
        Infinity,
        1.0/Math.max(0.0, -0.0));
    }
    
}


test();
