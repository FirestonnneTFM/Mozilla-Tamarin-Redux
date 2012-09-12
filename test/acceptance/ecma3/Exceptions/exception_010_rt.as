/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

// un-caught exception
// Null throw test.
// BUGNUMBER: 21799

var thisError = "Exited with uncaught exception";

try {
    throw null;
} catch(e) {
    thisError = e;
} finally {
        AddTestCase("Catch thrown null", "null", String(thisError));
}

test();