/* -*- Mode: js; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "avmplus::MathClass";
var VERSION = "";
startTest();
var TITLE = "Tests based on code coverage";

writeHeaderToLog( SECTION + " "+ TITLE);

var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Math.max(1, Number.NaN)",  Number.NaN, Math.max(1, Number.NaN) );
    array[item++] = new TestCase( SECTION,  "Math.max(0.0, 0.0)",  0.0, Math.max(0.0, 0.0) );


    return ( array );
}
