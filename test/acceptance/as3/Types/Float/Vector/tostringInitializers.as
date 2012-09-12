/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "../floatUtil.as";


var SECTION = "";
var VERSION = "AS3";
var TITLE   = "Vector.toString-initializers with float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddTestCase(
         "small vector of floats toString",
         "1.100000023841858,3.140000104904175,99.98999786376953",
         new<float>[float(1.1),float(3.14),float(99.99)].toString() );

AddTestCase(
         "default float values",
         "NaN,NaN",
         new<float>[float.NaN,float.NaN,].toString());


test();
