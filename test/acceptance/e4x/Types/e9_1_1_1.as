/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START('9.1.1.1 XML [[Get]]');

var x1 =
<alpha attr1="value1" attr2="value2">
    <bravo>
        one
        <charlie>two</charlie>
    </bravo>
</alpha>;

// .
TEST(1, <bravo>one<charlie>two</charlie></bravo>, x1.bravo);
TEST(2, <charlie>two</charlie>, x1.bravo.charlie);
TEST(3, <charlie>two</charlie>, x1.bravo.charlie.parent().charlie);

// .*
var correct = new XMLList("one<charlie>two</charlie>");
TEST(4, correct, x1.bravo.*);
TEST_XML(5, "two", x1.bravo.charlie.*);
TEST(6, <bravo>one<charlie>two</charlie></bravo>, x1.*[0]);

// .@
TEST_XML(7, "value1", x1.@attr1);
TEST_XML(8, "value2", x1.@attr2);

// ..
TEST(9, <bravo>one<charlie>two</charlie></bravo>, x1..bravo);
TEST(10, <charlie>two</charlie>, x1..charlie);

// .@*
correct = new XMLList();
correct += new XML("value1");
correct += new XML("value2");
TEST(11, correct, x1.@*);

x1 =
<alpha attr1="value1" attr2="value2">
    <bravo>
        one
        <charlie>two</charlie>
    </bravo>
</alpha>;

// ..*
XML.prettyPrinting = false;
correct = new XMLList("<bravo>one<charlie>two</charlie></bravo>one<charlie>two</charlie>two");
TEST(12, correct, x1..*);
XML.prettyPrinting = true;

x1 =
<alpha attr1="value1" attr2="value2">
    <bravo attr3="value3">
        one
        <charlie attr3="value4">two</charlie>
    </bravo>
</alpha>;

// ..@
correct = new XMLList();
correct += new XML("value3");
correct += new XML("value4");
TEST(13, correct, x1..@attr3)

// ..@*
correct = new XMLList();
correct += new XML("value1");
correct += new XML("value2");
correct += new XML("value3");
correct += new XML("value4");
TEST(14, correct, x1..@*);


// Check reserved words
x1 =
<alpha>
    <prototype>one</prototype>
</alpha>;

TEST(15, <prototype>one</prototype>, x1.prototype);

// Check method names
x1 =
<alpha>
    <name>one</name>
    <toString>two</toString>
</alpha>;

TEST(16, <name>one</name>, x1.name);
TEST(17, QName("alpha"), x1.name());
TEST(18, <toString>two</toString>, x1.toString);
TEST(19, x1.toXMLString(), x1.toString());

// Test super-expandos
x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <delta>two</delta>
        </charlie>
     </bravo>
</alpha>;

x1.bravo.charlie.delta = <delta>two</delta>;
TEST(20, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <delta>two</delta>
        </charlie>
     </bravo>
</alpha>;

x1.bravo.charlie.delta = "two";
TEST(21, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <echo>two</echo>
        </charlie>
     </bravo>
</alpha>;

x1.bravo.charlie.delta = <echo>two</echo>;
TEST(22, correct, x1);

// Also ADD with *, children() and child()
x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <delta>two</delta>
        </charlie>
     </bravo>
</alpha>;

x1.*.charlie.delta = <delta>two</delta>;
TEST(23, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <delta>two</delta>
        </charlie>
     </bravo>
</alpha>;

x1.children().charlie.delta = <delta>two</delta>;
TEST(24, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>
        one
        <charlie>
            <delta>two</delta>
        </charlie>
     </bravo>
</alpha>;

x1.child("bravo").charlie.delta = <delta>two</delta>;
TEST(25, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>one</bravo>
    <newChild>
        <charlie>
            <delta>two</delta>
        </charlie>
     </newChild>
</alpha>;

x1.child("newChild").charlie.delta = <delta>two</delta>;
TEST(26, correct, x1);

// These should fail because the XMLList is size > 1
x1 =
<alpha>
    <bravo>one</bravo>
    <bravo>two</bravo>
</alpha>;

try {
    x1.*.charlie.delta = "more";
    SHOULD_THROW(27);
} catch (ex1) {
    TEST(27, "TypeError", ex1.name);
}

x1 =
<alpha>
    <bravo>one</bravo>
    <bravo>two</bravo>
</alpha>;

try {
    x1.children().charlie.delta = "more";
    SHOULD_THROW(28);
} catch (ex2) {
    TEST(28, "TypeError", ex2.name);
}

x1 =
<alpha>
    <bravo>one</bravo>
    <bravo>two</bravo>
</alpha>;

try {
    x1.child("bravo").charlie.delta = "more";
    SHOULD_THROW(29);
} catch (ex3) {
    TEST(29, "TypeError", ex3.name);
}

// ..@::
var x1 = <x xmlns:ns="foo" a='10'><y ns:a='20'><z a='30'></z></y></x>;
var n = new Namespace("foo");

TEST(30, "20", x1..@n::a.toString());

var x1 = new XML(<a><class>i</class></a>);
AddTestCase("Reserved keyword used as element name", "i", x1["class"].toString());

END();
