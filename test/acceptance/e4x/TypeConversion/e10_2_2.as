/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.2.2 - ToXMLString Applied to the XMLList Type");

//ToXMLString ( xl )

var x1  = new XMLList("<a>A</a><b>B</b><c>C</c>");
var x_ = x1.toXMLString();
var y1  = "<a>A</a>\n<b>B</b>\n<c>C</c>";

AddTestCase( "ToXMLString(XMLList)        :", true, (x_==y1) );

END();
