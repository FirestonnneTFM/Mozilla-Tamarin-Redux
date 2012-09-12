/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

const x = 20/2;

AddTestCase("Bug 424341 Regression: VerifyError when setting global const.", 10, x);

test();
