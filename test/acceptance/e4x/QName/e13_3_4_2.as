/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.3.4.2 - QName.prototype.toString");

qn = new QName('validname');
AddTestCase( "QName.prototype.toString", 'validname', qn.toString());

qn = new QName('http://www.w3.org/TR/html4/','validname');
AddTestCase( "qn.toString", 'http://www.w3.org/TR/html4/::validname', qn.toString());

qn = new QName("");
AddTestCase( "qn = new QName(''), qn.toString", "", qn.toString());

END();
