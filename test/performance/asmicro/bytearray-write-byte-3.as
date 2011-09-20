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

var DESC = "Write byte to ByteArray with [] operator and expression index, from literal data.  Compare bytearray-write-byte-{1,2}.";
include "driver.as"

function bytearray_write_byte(iter: int, a: ByteArray): void
{
    for ( var i:int = 0 ; i < iter ; i++ ) {
        a.position = 0;
        // Please don't move the expression on j out of the brackets in the code below,
        // we're testing whether the indexing optimization has been implemented for
        // ByteArray.  Wrapping them in int(...) increases performance, so don't do that
        // either - that's not what we're testing here.
        for ( var j:int = 0 ; j < 1000 ; j += 5 ) {
            a[j+0] = 1;
            a[j+1] = 2;
            a[j+2] = 3;
            a[j+3] = 4;
            a[j+4] = 5;
        }
    }
}

var bai: ByteArray = new ByteArray();
(function () {
    for ( var i=0 ; i < 5000 ; i++ )
        bai.writeByte(i);
 })();
TEST(function () { bytearray_write_byte(1000, bai); }, "bytearray-write-byte-3");
