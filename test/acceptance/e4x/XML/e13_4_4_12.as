/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.12 - XML descendants");

//TEST(1, true, XML.prototype.hasOwnProperty("descendants"));

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        two
        <bravo>three</bravo>
    </charlie>
</alpha>;

TEST(2, <bravo>three</bravo>, x1.charlie.descendants("bravo"));
TEST(3, new XMLList("<bravo>one</bravo><bravo>three</bravo>"), x1.descendants("bravo"));

// Test *
correct = new XMLList("<bravo>one</bravo>one<charlie>two<bravo>three</bravo></charlie>two<bravo>three</bravo>three");

XML.prettyPrinting = false;
TEST(4, correct, x1.descendants("*"));
TEST(5, correct, x1.descendants());
XML.prettyPrinting = true;

XML.prettyPrinting = false;

var xmlDoc = "<MLB><foo>bar</foo><Team>Giants<foo>bar</foo></Team><City><foo>bar</foo>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('Team')", "<Team>Giants<foo>bar</foo></Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XML(xmlDoc), MYXML.descendants('Team').toString()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('Team').length()", 2,
             (MYXML = new XML(xmlDoc), MYXML.descendants('Team').length()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('Team') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.descendants('Team') instanceof XMLList) );

// find multiple levels of descendants
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('foo')", "<foo>bar</foo>" + NL() + "<foo>bar</foo>" + NL() + "<foo>bar</foo>",
             (MYXML = new XML(xmlDoc), MYXML.descendants('foo').toString()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('foo').length()", 3,
             (MYXML = new XML(xmlDoc), MYXML.descendants('foo').length()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('foo') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.descendants('foo') instanceof XMLList) );

// no matching descendants
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('nomatch')", "",
             (MYXML = new XML(xmlDoc), MYXML.descendants('nomatch').toString()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('nomatch').length()", 0,
             (MYXML = new XML(xmlDoc), MYXML.descendants('nomatch').length()) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.descendants('nomatch') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.descendants('nomatch') instanceof XMLList) );
             
// descendant with hyphen

e =
<employees>
    <employee id="1"><first-name>Joe</first-name><age>20</age></employee>
    <employee id="2"><first-name>Sue</first-name><age>30</age></employee>
</employees>

correct =
<first-name>Joe</first-name> +
<first-name>Sue</first-name>;

names = e.descendants("first-name");

AddTestCase("Descendant with hyphen", correct, names);

END();
