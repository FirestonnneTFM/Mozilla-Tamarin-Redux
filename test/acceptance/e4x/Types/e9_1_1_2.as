/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START('9.1.1.2 - XML [[Put]]');


// .
var x1 =
<alpha attr1="value1" attr2="value2">
    <bravo>
        one
        <charlie>two</charlie>
    </bravo>
</alpha>;

var correct =
<charlie>new</charlie>;

x1.bravo.charlie = "new"
TEST(1, correct, x1.bravo.charlie)
x1.bravo = <delta>three</delta>
TEST(2, "three", x1.delta.toString())

// .@
x1 = <alpha attr1="value1" attr2="value2"><bravo>one<charlie>two</charlie></bravo></alpha>
x1.@attr1 = "newValue"
TEST_XML(3, "newValue", x1.@attr1)

x1 = <alpha attr1="value1" name="value2"><bravo>one<charlie>two</charlie></bravo></alpha>
x1.@name = "foo";
TEST_XML(4, "foo", x1.@name)

var a = <a><b><c/></b></a>;

try {
    a.b[0] = a;
    result = a;
} catch (e1) {
    result = typeError(e1.toString());
}


// This might fail in tomorrow's build. 11/02/05
a = <a><b/>some junk<c/>some junk<d/>some junk</a>;
correct = <a><b/>some junk<c/>some junk<d/>some junk<newnode>with some text</newnode></a>;

AddTestCase("blah", correct, (a.*::foo = <newnode>with some text</newnode>, a));


END();
