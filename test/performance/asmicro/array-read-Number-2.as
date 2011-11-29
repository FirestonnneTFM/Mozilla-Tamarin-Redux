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

var DESC = "Read Number from sparse Array, store in local with type *.";
include "driver.as"

function array_read_Number(iter: int, a:Array)
{
    // Please do not change the type annotation
    var tmp1:*;
    var tmp2:*;
    var tmp3:*;
    var tmp4:*;
    var tmp5:*;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        for ( var j:int = 0 ; j < 10000 ; ) {
            tmp1 = a[j];  j += 10;
            tmp2 = a[j];  j += 10;
            tmp3 = a[j];  j += 10;
            tmp4 = a[j];  j += 10;
            tmp5 = a[j];  j += 10;
        }
    }
    return tmp1+tmp2+tmp3+tmp4+tmp5;
}

var an: Array = new Array(10000);
(function () {
    for ( var i=0 ; i < 10000 ; i+=10 )
        an[i] = 0.1;
})();
TEST(function () { array_read_Number(1000, an); }, "array-read-Number-2");
