/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.3.1 - XMLList.prototype");

AddTestCase( "typeof XMLList.prototype", "object", typeof XMLList.prototype);
AddTestCase( "XMLList.prototype instanceof XMLList", false, XMLList.prototype instanceof XMLList);
AddTestCase( "new XMLList().prototype instanceof XMLList", true, new XMLList().prototype instanceof XMLList);
AddTestCase( "typeof (new XMLList().prototype)", "xml", typeof (new XMLList().prototype));

END();
