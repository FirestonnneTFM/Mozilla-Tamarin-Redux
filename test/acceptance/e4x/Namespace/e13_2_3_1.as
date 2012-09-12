/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.2.3.1 - Namespace.prototype");

AddTestCase( "typeof Namespace.prototype", "object", typeof Namespace.prototype);
AddTestCase( "Namespace.prototype instanceof Namespace", false, Namespace.prototype instanceof Namespace);
//AddTestCase( "new Namespace().prototype instanceof Namespace", true, new Namespace().prototype instanceof Namespace);
//AddTestCase( "typeof (new Namespace().prototype)", "xml", typeof (new Namespace().prototype));

END();
