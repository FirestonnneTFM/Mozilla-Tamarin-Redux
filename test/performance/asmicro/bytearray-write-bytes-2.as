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

import flash.utils.ByteArray;

var DESC = "Write a large number of aligned bytes from ByteArray into ByteArray.  Compare bytearray-write-bytes-1.";
include "driver.as"

function bytearray_write_bytes(iter: int, a: ByteArray): uint
{
    // Sanity
    if (a.length != 8000 * 5)
        throw "Error in setup";

    var tmp1:ByteArray = new ByteArray;  tmp1.length = 8000;
    var tmp2:ByteArray = new ByteArray;  tmp2.length = 8000;
    var tmp3:ByteArray = new ByteArray;  tmp3.length = 8000;
    var tmp4:ByteArray = new ByteArray;  tmp4.length = 8000;
    var tmp5:ByteArray = new ByteArray;  tmp5.length = 8000;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        tmp1.position = 0;
        tmp2.position = 0;
        tmp3.position = 0;
        tmp4.position = 0;
        tmp5.position = 0;
        var k:int=0;
        for ( var j:int = 0 ; j < 10 ; j++ ) {
            tmp1.writeBytes(a, k, 800);
            tmp2.writeBytes(a, k, 800);
            tmp3.writeBytes(a, k, 800);
            tmp4.writeBytes(a, k, 800);
            tmp5.writeBytes(a, k, 800);
            k += 800;
        }
    }

    // Sanity
    tmp1.position = 32;
    var n : Number = tmp1.readDouble();
    if (n != Math.PI || tmp1.length != 8000)
        throw "Error in copying: length=" + tmp.length + ", sample=" + n;

    return tmp1.position+tmp2.position+tmp3.position+tmp4.position+tmp5.position;
}

var bai: ByteArray = new ByteArray();
(function () {
    for ( var i=0 ; i < 5000 ; i++ )
        bai.writeDouble(Math.PI);
 })();
TEST(function () { bytearray_write_bytes(250, bai); }, "bytearray-write-bytes-2");
