/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.4.16.24";
var VERSION = "AS3";
var TITLE   = "Math and geometric methods public function dot3(arg1:float4, arg2:float4):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddErrorTest("float4.dot3() with no args", ARGUMENTERROR+1063,  function(){ float4.dot3(); });

test();

