/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug157735 - XML comments()");

XML.ignoreComments = false;

var p = <p><!--this is a comment-->this is normal text</p>;

TEST(1, "this is normal text", p.toString());



END();
