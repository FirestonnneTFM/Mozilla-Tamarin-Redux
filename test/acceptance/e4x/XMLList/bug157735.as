/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug157735 - XMLList comments()");

XML.ignoreComments = false;

var p2 = new XMLList("<!--this is a comment-->this is normal text");


TEST(1, "this is normal text", p2.toString());



END();
