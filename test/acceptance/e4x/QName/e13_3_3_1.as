/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.3.3.1 - QName.prototype");

AddTestCase( "typeof QName.prototype", "object", typeof QName.prototype);
AddTestCase( "QName.prototype instanceof QName", false, QName.prototype instanceof QName);

END();
