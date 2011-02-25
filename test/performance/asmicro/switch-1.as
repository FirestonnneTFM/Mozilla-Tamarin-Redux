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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

var DESC = "Switch on int value, keys";

// All implementations should be able to do well here.
include "driver.as"

function switchloop():uint {
    return switchloop2(10);
}

function switchloop2(k:uint):uint {
    var i:uint=0;
    var v:uint=0;
    while (i < 100000) {
        i++;
        switch (k) {
        case 0: v += 1; break;
        case 1: v += 1; break;
        case 2: v += 2; break;
        case 3: v += 3; break;
        case 4: v += 5; break;
        case 5: v += 8; break;
        case 6: v += 13; break;
        case 7: v += 21; break;
        case 8: v += 34; break;
        case 9: v += 55; break;
        case 10: v += 89; break;
        case 11: v += 144; break;
        }
    }
    return v;
}

TEST(switchloop, "switch-1");
