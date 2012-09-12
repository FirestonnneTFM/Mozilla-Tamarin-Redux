/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
package Package1
{
    public class Class1
    {
        public static var item1;
    }
}

import Package1.*;

startTest();

var c1 = new Class1();

var thisError = "no error";

try
{
    c1.item1 = "updated";
}
catch(err)
{
    thisError = err.toString();
}
finally
{
    AddTestCase("Attempt to modified class variable in an object instance", "ReferenceError: Error #1056", referenceError(thisError));
}

test();
