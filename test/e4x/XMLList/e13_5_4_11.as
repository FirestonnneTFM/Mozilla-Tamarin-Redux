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

START("13.5.4.11 - XMLList hasOwnProperty()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("hasOwnProperty"));
  

x1 = 
<>
<alpha attr1="value1">
    <bravo>one</bravo>
    <charlie>
        two
        three
        <echo>four</echo>
    </charlie>
    <delta />
</alpha>
<delta>
    <echo>five</echo>
</delta>
</>;

// Returns true for elements/attributes
TEST(2, true, x1.hasOwnProperty("bravo"));
TEST(3, true, x1.hasOwnProperty("@attr1"));
TEST(4, false, x1.hasOwnProperty("foobar"));
TEST(5, true, x1.hasOwnProperty("echo"));

// Test for XML Prototype Object - returns true for XML methods.
TEST(5, true, XMLList.prototype.hasOwnProperty("toString"));
TEST(6, false, XMLList.prototype.hasOwnProperty("foobar"));


var xmlDoc = "<employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age dob='1/2/1978'>26</age></employee>"

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('copy')", false, 
             (MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('copy')));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('hasSimpleContent')", false, 
             (MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('hasSimpleContent')));  

//!!@ we're not supporting prototype properties
AddTestCase( "XML.prototype.hasOwnProperty('copy')", true, 
             (XML.prototype.hasOwnProperty('copy')));
AddTestCase( "XML.prototype.hasOwnProperty('hasSimpleContent')", true, 
             (XML.prototype.hasOwnProperty('hasSimpleContent')));
             
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('firstname')", true, 
             (MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('firstname')));  
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('lastname')", true, 
             (MYXML = new XMLList(xmlDoc), MYXML.hasOwnProperty('lastname')));  
             
END();
