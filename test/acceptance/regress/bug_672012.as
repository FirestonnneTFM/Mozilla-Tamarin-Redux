/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Regression Tests";
var VERSION = "AS3";
var TITLE   = "Bug 672012";
var bug = "672012";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

var subject:String = "AAA";
subject.match(/(((((((((((((((((((a*)(abc|b))))))))))))))))))*.)*(...)*/g);
subject.match(/((((((((((((((((((d|.*)))))))))))))))))*.)*(...)*/g);
subject.match(/((((((((((((((((((a+)*))))))))))))))))*.)*(...)*/g);

AddTestCase("Completed", true, true);

test();

