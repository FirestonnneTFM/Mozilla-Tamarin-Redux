/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-311515.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 311515;
var summary = 'Array.sort should skip holes and undefined during sort';
var actual = '';
var expect = '';

printBugNumber(BUGNUMBER);
printStatus (summary);

var a = [, 1, , 2, undefined];

actual = a.sort().toString();
expect = '1,2,,,';

AddTestCase(summary, expect, actual);

test();
