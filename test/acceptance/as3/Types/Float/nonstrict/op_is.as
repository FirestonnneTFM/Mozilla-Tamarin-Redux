/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.7.1";
var VERSION = "AS3";
var TITLE   = "The is operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var pi_float:Object = new float(3.14);
AddErrorTest("TypeError if datatype is not Class", TYPEERROR, function(){ return pi_float is "float"; });

test();

