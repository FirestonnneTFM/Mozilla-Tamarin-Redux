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
 * Portions created by the Initial Developer are Copyright (C) 2012
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
import avmplus.System;

var SECTION = "ByteArray";
var VERSION = "as3";
startTest();
var TITLE   = "test ByteArray capacity growth regression";

writeHeaderToLog( SECTION + " "+ TITLE );

var b:ByteArray = new ByteArray();
var MB:uint = 1024*1024;

// Initial State: Measure private mem before any real byte array allocation.
var privMem_0:uint = System.privateMemory;

// Test setup: Start off with 100 MB byte array.
b.length = 100*MB;
b[100*MB - 1] = 1;

var privMem_1:uint = System.privateMemory;

// First test: Increase byte array by 30 MB.
// Capacity should *not* increase to 200 MB.
b.length = 130*MB;

var privMem_2:uint = System.privateMemory;

var delta_0_1:int = (privMem_1 - privMem_0);
var delta_0_2:int = (privMem_2 - privMem_0);

var deltaLessThan2x:Boolean = (delta_0_2 < 2 * delta_0_1);

// Second test: Cut byte array to 1 MB.
// Capacity should be cut down from the original 100 MB.
b.length = 1*MB;

var privMem_3:uint = System.privateMemory;
var delta_1_3:int = (privMem_3 - privMem_1);
var deltaNegative:Boolean = (delta_1_3 < 0);


var info = {};
info.privMem_0 = privMem_0;
info.privMem_1 = privMem_1;
info.privMem_2 = privMem_2;
info.privMem_3 = privMem_3;
info.delta_0_1 = delta_0_1;
info.delta_0_2 = delta_0_2;
info.delta_1_3 = delta_1_3;
info.deltaLessThan2x = deltaLessThan2x;
info.deltaNegative = deltaNegative;

print(JSON.stringify(info));

AddTestCase("small length increase incurs less than 2x capacity growth",
            true, deltaLessThan2x);

AddTestCase("huge length decrease causes capacity drop",
            true, deltaNegative);

test();
