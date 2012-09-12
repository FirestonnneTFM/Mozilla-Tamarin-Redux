/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.3.5 - Properties of QName Instances");

q = new QName("http://someuri", "foo");
TEST(1, true, q.hasOwnProperty("localName"));
TEST(2, true, q.hasOwnProperty("uri"));
//TEST(3, true, q.propertyIsEnumerable("localName"));
//TEST(4, true, q.propertyIsEnumerable("uri"));

var localNameCount = 0;
var uriCount = 0;
var p;
for(p in q)
{
    if(p == "localName") localNameCount++;
    if(p == "uri") uriCount++;
}

TEST(5, 1, localNameCount);
TEST(6, 1, uriCount);
TEST(7, "http://someuri", q.uri);
TEST(8, "foo", q.localName);

qn = new QName("validname");
AddTestCase( "QName.localName", "validname", qn.localName);

qn = new QName("http://www.w3.org/TR/html4/", "validname");
AddTestCase( "QName.localName", "validname", qn.localName);

qn = new QName("validname");
AddTestCase( "qn = new QName('validname'), QName.uri", "", qn.uri);

qn = new QName(null, "validname");
AddTestCase( "qn = new QName(null, 'validname'), QName.uri", null, qn.uri);

qn = new QName("http://www.w3.org/TR/html4/", "validname");
AddTestCase( "QName.uri", "http://www.w3.org/TR/html4/", qn.uri);

qn = new QName("", "validname");
AddTestCase( "qn = new QName('', 'validname'), QName.uri", "", qn.uri);


END();
