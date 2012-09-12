/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("9.2.1.9 XMLList [[Equals]]");

// Empty list should equal undefined
TEST(1, true, (new XMLList() == undefined) && (undefined == new XMLList()));

// Compare two lists if all are equal
x1 = <alpha>one</alpha> + <bravo>two</bravo>;
y1 = <alpha>one</alpha> + <bravo>two</bravo>;
TEST(2, true, (x1 == y1) && (y1 == x1));
y1 = <alpha>one</alpha> + <bravo>two</bravo> + <charlie>three</charlie>;
TEST(3, false, (x1 == y1) || (y1 == x1));
y1 = <alpha>one</alpha> + <bravo>not</bravo>;
TEST(4, false, (x1 == y1) || (y1 == x1));

// If XMLList has one argument should compare with just the 0th element.
x1= new XMLList("<alpha>one</alpha>");
y1 = <alpha>one</alpha>;
TEST(5, true, (x1 == y1) && (y1 == x1));
y1 = "one";
TEST(6, true, (x1 == y1) && (y1 == x1));

// Should return false even if list contains element equal to comparison
x1 = <alpha>one</alpha> + <bravo>two</bravo>;
y1 = <alpha>one</alpha>;
TEST(7, false, (x1 == y1) && (y1 == x1));

y1 = "<alpha>one</alpha>";
TEST(8, false, (x1 == y1) || (y1 == x1));

// Try other types - should return false
y1 = null;
TEST(9, false, (x1 == y1) || (y1 == x1));

y1 = new Object();
TEST(10, false, (x1 == y1) || (y1 == x1));

END();
