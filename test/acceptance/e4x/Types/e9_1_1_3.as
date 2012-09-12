/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("9.1.1.3 - XML [[Delete]]");

// .@
x1 =
<alpha attr1="value1">one</alpha>;

delete x1.@attr1;
TEST_XML(1, "", x1.@attr1);
TEST(2, <alpha>one</alpha>, x1);

// ..@
x1 =
<alpha attr1="value1">
    one
    <bravo attr2="value2">
        two
        <charlie attr3="value3">three</charlie>
    </bravo>
</alpha>;

xref =
<alpha attr1="value1">
    one
    <bravo attr2="value2">
        two
        <charlie attr3="value3">three</charlie>
    </bravo>
</alpha>;

correct =
<alpha attr1="value1">
    one
    <bravo attr2="value2">
        two
        <charlie>three</charlie>
    </bravo>
</alpha>;

delete x1..@attr3;

//Rhino test:
//TEST(3, correct, x1);

// We are different. Deleting descendant attributes doesn't change the original object:
TEST(3, xref.toString(), x1.toString());


// ..@*
x1 =
<alpha attr1="value1">
    one
    <bravo attr2="value2">
        two
        <charlie attr3="value3">three</charlie>
    </bravo>
</alpha>;

xref =
<alpha attr1="value1">
    one
    <bravo attr2="value2">
        two
        <charlie attr3="value3">three</charlie>
    </bravo>
</alpha>;

correct =
<alpha>
    one
    <bravo>
        two
        <charlie>three</charlie>
    </bravo>
</alpha>;

delete x1..@*;

// Rhino test:
//TEST(4, correct, x1);

// We are different. Deleting descendant attributes doesn't change the original object:
TEST(4, xref.toString(), x1.toString());

END();
