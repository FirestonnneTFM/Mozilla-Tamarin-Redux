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

var DESC = "Write C object from local into sparse Array";
include "driver.as"

class C
{
    var x: C = null;  // just some field to make the type nontrivial
}

function array_write_obj(iter: int): Array
{
    // It will become initialized after the first iteration but it's more honest
    // to initialize it here.
    var a: Array = new Array(10000);
    for ( var k:int = 0 ; k < 10000 ; k += 10 )
        a[k] = 0;

    // Please do not change the type annotations
    // Please do not inline the arithmetic into the index expressions here
    var v0: C = new C;
    var v1: C = new C;
    var v2: C = new C;
    var v3: C = new C;
    var v4: C = new C;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        for ( var j:int = 0 ; j < 10000 ; ) {
            a[j] = v0;  j += 10;
            a[j] = v1;  j += 10;
            a[j] = v2;  j += 10;
            a[j] = v3;  j += 10;
            a[j] = v4;  j += 10;
        }
    }
    if (a.length != 10000) throw "WROTE PAST END";
    return a;
}

TEST(function () { array_write_obj(1000); }, "array-write-C-1");
