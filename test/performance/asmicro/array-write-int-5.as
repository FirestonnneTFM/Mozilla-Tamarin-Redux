/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

var DESC = "Write int from local into dense Array with var-const expression.  Compare array-write-int-1.";
include "driver.as"

function array_write_int(iter: int): Array
{
    // It will become initialized after the first iteration but it's more honest
    // to initialize it here, to try to ensure denseness.
    var a: Array = new Array(1000);
    for ( var k:int = 0 ; k < 1000 ; k++ )
        a[k] = 0;

    // Please do not change the type annotations
    var v0: int = 1;
    var v1: int = 2;
    var v2: int = 3;
    var v3: int = 4;
    var v4: int = 5;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        for ( var j:int = 4 ; j < 1000 ; j += 5 ) {
            a[j-4] = v0;
            a[j-3] = v1;
            a[j-2] = v2;
            a[j-1] = v3;
            a[j-0] = v4;
        }
    }
    if (a.length != 1000) throw "WROTE PAST END";
    return a;
}

TEST(function () { array_write_int(1000); }, "array-write-int-5");
