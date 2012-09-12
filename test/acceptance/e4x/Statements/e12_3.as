/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("12.3 - For-each statement");

// XML Object

var i, s="";

var xmlDoc = "<L><z><A>1</A></z><z><A>2</A></z><z><A>3</A></z></L>";
var x1 = new XML(xmlDoc);

for each(i in x1.z) {
      s += i.A;
}

AddTestCase( "for-each-in       :", true, (s=="123") );

s = "";

for each ( i in x1.z )
    s += i.A;

AddTestCase( "for-each-in (var) :", true, (s=="123") );


// XMLList Object

xl = new XMLList(xmlDoc);

s = "";

for each(i in xl.z) {
      s += i.A;
}

AddTestCase( "for-each-in       :", true, (s=="123") );

s = "";

for each ( i in xl.z )
    s += i.A;

AddTestCase( "for-each-in (var) :", true, (s=="123") );

END();
