/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";        // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";                // Version of ECMAScript or ActionScript
var TITLE   = "delete operator";    // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                        // leave this alone

// create the new object "account"
var account:Object = new Object();

// create function
account.func = function () { return "account.func"; };

AddTestCase("object's function", "function Function() {}", account.func.toString());
AddTestCase("call object's function", "account.func", account.func());
AddTestCase("delete instantiated object's function", true, delete account.func);
AddTestCase("account.func", undefined, account.func);


test();       // leave this alone.  this executes the test cases and
              // displays results.
