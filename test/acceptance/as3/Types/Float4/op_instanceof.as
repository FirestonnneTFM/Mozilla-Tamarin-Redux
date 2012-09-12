/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.7.4";
var VERSION = "AS3";
var TITLE   = "The instanceof operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var onef:float4 = new float4(1f);


AddTestCase("float4 class is not instanceof float4", false, float4 instanceof float4);
AddTestCase("float4 instance is instanceof float4", true, onef instanceof float4);
AddTestCase("float4 class is instanceof Object", true, float4 instanceof Object);
AddTestCase("float4 class is instanceof Class", true, float4 instanceof Class);
AddTestCase("float4 class is not instanceof Function", false, float4 instanceof Function);
AddTestCase("float4 instance is instanceof Object", true, onef instanceof Object);

var vf = new Vector.<float>();
AddTestCase("Vector.<float> is not instanceof float", false, vf instanceof float);

AddTestCase("float4 class is not instanceof Number", false, float4 instanceof Number);
AddTestCase("float4 instance is not instanceof Number", false, onef instanceof Number);
AddTestCase("float4 class is not instanceof int", false, float4 instanceof int);
AddTestCase("float4 instance is not instanceof int", false, onef instanceof int);
AddTestCase("float4 class is not instanceof uint", false, float4 instanceof uint);
AddTestCase("float4 instance is not instanceof uint", false, onef instanceof uint);
AddTestCase("float4 class is not instanceof String", false, float4 instanceof String);
AddTestCase("float4 instance is not instanceof String", false, onef instanceof String);

AddErrorTest("AS: TypeError if datatype is not Class or Function", TYPEERROR, function(){ return float4(1f) instanceof float4(1f); });


test();

