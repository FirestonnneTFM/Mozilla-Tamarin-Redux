/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
// testcase from  Martin.Honnen@arcor.de

var bug = 277683;
var summary = 'processing instruction with target name XML';
var actual = '';
var expect = '';

START(summary);

printBugNumber (bug);
printStatus (summary);

expect = 'no error';
try
{
    XML.ignoreProcessingInstructions = false;
    var xml = <><?xml version="1.0"?><root><child>Kibo</child></root></>;
    actual = 'no error';
}
catch(e)
{
    actual = e.toString();
}

TEST(1, expect, actual);

END();
