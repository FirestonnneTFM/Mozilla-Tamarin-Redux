/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START('XML("") should create empty text node');
BUG(271545);

// Check that text node should ignore any attempt to add a child to it


var x1;

x1 = new XML();
x1.a = "foo";
TEST_XML(1, "", x1);

x1 = new XML("");
x1.a = "foo";
TEST_XML(2, "", x1);

x1 = new XML(null);
x1.a = "foo";
TEST_XML(3, "", x1);

x1 = new XML(undefined);
x1.a = "foo";
TEST_XML(4, "", x1);

var textNodeContent = "some arbitrary text without XML markup";

x1 = new XML(textNodeContent);
x1.a = "foo";
TEST_XML(5, textNodeContent, x1);

END();
