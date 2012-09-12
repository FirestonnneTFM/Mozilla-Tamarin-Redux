/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions\const";                  // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";           // Version of JavaScript or ECMA
var TITLE   = "Initialize a subclass instance const globally";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();

class MyClass {

    public const pubConst;
}


class MySubClass extends MyClass {}

var myConstObj = new MySubClass();

var thisError:String = "no error";

try
{
    myConstObj.pubConst = -1;
}
catch(err)
{
    thisError = err.toString();
}
finally
{
    AddTestCase("Initialize a subclass instance const globally", "ReferenceError: Error #1074", referenceError(thisError));
}

test();
