/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is Rhino code, released
 * May 6, 1999.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1997-2000 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s):
 * Igor Bukanov
 * Ethan Hugg
 * Milen Nankov
 *
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU Public License (the "GPL"), in which case the
 * provisions of the GPL are applicable instead of those above.
 * If you wish to allow use of your version of this file only
 * under the terms of the GPL and not to allow others to use your
 * version of this file under the NPL, indicate your decision by
 * deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL.  If you do not delete
 * the provisions above, a recipient may use your version of this
 * file under either the NPL or the GPL.
 */

START("10.4.1 - toXMLList Applied to String type");

var x1, y1, correct;

x1 = 
<>
    <alpha>one</alpha>
    <bravo>two</bravo>
</>;

TEST(1, "xml", typeof(x1));
TEST(2, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", x1.toXMLString());

// Load from another XMLList
// Make sure it is copied if it's an XMLList
y1 = new XMLList(x1);

x1 += <charlie>three</charlie>;

TEST(3, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", y1.toXMLString());
   
// Load from one XML type
x1 = new XMLList(<alpha>one</alpha>);
TEST(4, "<alpha>one</alpha>", x1.toXMLString());

// Load from Anonymous
x1 = new XMLList(<><alpha>one</alpha><bravo>two</bravo></>);
TEST(5, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", x1.toXMLString());

// Load from Anonymous as string
x1 = new XMLList("<alpha>one</alpha><bravo>two</bravo>");
TEST(6, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", x1.toXMLString());

// Load from illegal type
//x1 = new XMLList("foobar");
//ADD(7, "", x);

John = "<employee><name>John</name><age>25</age></employee>";
Sue = "<employee><name>Sue</name><age>32</age></employee>";

correct = 
<>
    <employee><name>John</name><age>25</age></employee>
    <employee><name>Sue</name><age>32</age></employee>
</>;

var1 = new XMLList(John + Sue);

TEST(8, correct, var1);

END();
