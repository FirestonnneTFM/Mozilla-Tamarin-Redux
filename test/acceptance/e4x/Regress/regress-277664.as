/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
// testcase from  Martin.Honnen@arcor.de

var bug = 277664;
var summary = 'duplicate attribute names';
var actual = '';
var expect = '';

START(summary);

printBugNumber (bug);
printStatus (summary);

expect = 'error';
try
{
    var god = <god firstname="Kibo" firstname="Xibo" />;
    actual = 'no error';
}
catch(e)
{
    actual = 'error';
}

TEST(1, expect, actual);

END();
