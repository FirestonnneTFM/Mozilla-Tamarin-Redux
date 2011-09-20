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

var DESC = "Read long UTF string from length-prefixed ByteArray, store in local with type String.";
include "driver.as"

function bytearray_read_utf(iter: int, a: ByteArray, b: ByteArray): int
{
    var tmp1:String;
    var tmp2:String;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        a.position = 0;
        b.position = 0;
        for ( var j:int = 0 ; j < 1000 ; j++ ) {
            tmp1 = a.readUTF();
            tmp2 = b.readUTF();
        }
    }
    return tmp1+tmp2;
}

var ba1: ByteArray = new ByteArray();
var ba2: ByteArray = new ByteArray();
(function () {
    for ( var i=0 ; i < 1000 ; i++ ) {
        ba1.writeUTF("It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair, we had everything before us...");
        ba2.writeUTF("Ja vi elsker dette landet som det stiger frem furet vaerbitt over vannet med de tusen hjem elsker elsker det og tenker paa vaar far og mor og den saganatt som senker senker droemme paa vaar jord");
    }
 })();
TEST(function () { bytearray_read_utf(100, ba1, ba2); }, "bytearray-read-utf-2");
