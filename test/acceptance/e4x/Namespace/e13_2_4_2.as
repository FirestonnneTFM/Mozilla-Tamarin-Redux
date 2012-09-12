/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.2.4.2 - Namespace.prototype.toString");

var n1 = new Namespace('http://www.w3.org/TR/html4/');
var n2 = new Namespace('pfx','http://www.w3.org/TR/html4/');
var n3 = new Namespace();

AddTestCase( "Namespace.prototype.toString", 'http://www.w3.org/TR/html4/', n1.toString());
AddTestCase( "Namespace.prototype.toString", 'http://www.w3.org/TR/html4/', n2.toString());
AddTestCase( "Namespace.prototype.toString", '', n3.toString());

END();
