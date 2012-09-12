/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.2.2";
var VERSION = "AS3";
var TITLE   = "The float4 method called as a function float4 (x, y, z, w)";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddErrorTest("float4() with 2 args", ARGUMENTERROR, function(){ result = float4(1, 2);});
AddErrorTest("float4() with 3 args", ARGUMENTERROR, function(){ result = float4(1, 2, 3);});
AddErrorTest("float4() with 5 args", ARGUMENTERROR, function(){ result = float4(1, 2, 3, 4, 5);});

test();

