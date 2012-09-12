/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.6.3";
var VERSION = "AS3";
var TITLE   = "Component accesses";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

// Access component via v.x
var flt4:float4 = new float4(1f);
AddErrorTest("float4.x as a setter", REFERENCEERROR, function(){ flt4.x = 12f });
AddErrorTest("float4.y as a setter", REFERENCEERROR, function(){ flt4.y = 12f });
AddErrorTest("float4.z as a setter", REFERENCEERROR, function(){ flt4.z = 12f });
AddErrorTest("float4.w as a setter", REFERENCEERROR, function(){ flt4.w = 12f });

// Access outside of valid index ranges section 4.6.3.2.b
AddErrorTest("float4[-1]", REFERENCEERROR, function(){ flt4[-1]; });
AddErrorTest("float4[4]", RANGEERROR, function(){ flt4[4]; });

test();

