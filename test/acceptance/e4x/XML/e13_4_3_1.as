/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.1 - XML.prototype");

AddTestCase( "typeof XML.prototype", "object", typeof XML.prototype);
AddTestCase( "XML.prototype instanceof XML", false, XML.prototype instanceof XML);
AddTestCase( "new XML().prototype instanceof XML", false, new XML().prototype instanceof XML);
AddTestCase( "typeof (new XML().prototype)", "xml", typeof (new XML().prototype));


END();
