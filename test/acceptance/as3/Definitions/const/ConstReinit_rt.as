/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions\const";                  // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";           // Version of JavaScript or ECMA
var TITLE   = "reinitialization of const";       // Provide ECMA section title or a description
var BUGNUMBER = "";

const string1:String = "abc";

startTest();

var thisError:String = "no error";

try
{
    string1 = "def";
}
catch(err)
{
    thisError = err.toString();
}
finally
{
    AddTestCase("Reinitialize const in global context", "ReferenceError: Error #1074", referenceError(thisError));
}

test();
