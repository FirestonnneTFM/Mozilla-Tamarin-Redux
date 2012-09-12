/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("Standalone <![CDATA[ .... ]]> should be allowed");
BUG(257679);

var x1 = <![CDATA[ < some & > arbirary text ]]>;

var expected = new XML("<![CDATA[ < some & > arbirary text ]]>");

TEST(1, expected, x1);

END();
