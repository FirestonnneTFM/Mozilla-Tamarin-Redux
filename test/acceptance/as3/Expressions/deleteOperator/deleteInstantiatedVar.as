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

// assign property name to the account
account.name = "Jon";

// delete the property
AddTestCase("delete instantiated object's var", true, delete account.name);
AddTestCase("account.name", undefined, account.name);


test();       // leave this alone.  this executes the test cases and
              // displays results.
