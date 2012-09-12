/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=555544
*
*/
//-----------------------------------------------------------------------------

class A {};

startTest();
err = "no error";
// looking for ReferenceError: Error #1056: Cannot create property 10 on bug_555544.as$1.A.
try {
    var a = new A();
    a[10] = 0;

} catch (e) {
    err = grabError(e, e.toString());
} finally {
    AddTestCase("bug555544", "Error #1056", err );
}


test();
