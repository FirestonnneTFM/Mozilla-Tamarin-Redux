/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import avmplus.Domain
import avmplus.System

var domain = Domain.currentDomain;

var SECTION = "regression test";
var VERSION = "as3";
var TITLE   = "Regression test for bug 618215";
startTest();

var support_abc:String = System.argv[0];

var err = "";
try {
    domain.load(support_abc);
} catch (e) {
    err = e.toString();
}

AddTestCase("Fuzzed file should throw kIllegalOperandTypeError", "TypeError: Error #1034", err.substring(0,22));

test();