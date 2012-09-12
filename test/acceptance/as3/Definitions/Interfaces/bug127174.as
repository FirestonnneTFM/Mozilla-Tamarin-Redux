/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import bug127174.*;

startTest();

var t:InterfaceCorceErrorTest = new InterfaceCorceErrorTest();
var k:ITestInterface = new CoerceErrorForInterfaces();
AddTestCase("regress for bug 127714", true, t.causeCoerceError(k));
test();


