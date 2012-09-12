/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("toXMLString() should escape '>'");
BUG(264369);

var x1 = <a/>;
var chars = "<>&";
x1.b = chars;

TEST(1, "<b>&lt;&gt;&amp;</b>", x1.b.toXMLString());

END();
