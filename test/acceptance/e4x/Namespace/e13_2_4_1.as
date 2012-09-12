/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.2.4.1 - Namespace.prototype.constructor");

AddTestCase( "Namespace.prototype.constructor", Namespace, Namespace.prototype.constructor);
AddTestCase( "Namespace.prototype.constructor", true, Namespace.prototype.constructor === Namespace);

END();
