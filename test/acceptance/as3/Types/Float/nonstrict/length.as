/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.5.1";
var VERSION = "AS3";
var TITLE   = "float.length";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddTestCase("float.length is 1", 1 , float.length );
AddTestCase("float.length is int", "int" , getQualifiedClassName(float.length));

AddTestCase("float.length - DontDelete", false, delete(float.length));
AddTestCase("float.length is still ok", 1, float.length);

AddTestCase("float.length - DontEnum", '', getFloatProp('length'));
AddTestCase("float.length is not enumerable", false, float.propertyIsEnumerable('length'));

AddErrorTest("float.length - ReadOnly", REFERENCEERROR+1074, function(){ float.length = 0; });
AddTestCase("float.length is still here", 1 , float.length );

test();

