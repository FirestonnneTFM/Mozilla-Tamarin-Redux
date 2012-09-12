/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import Qualifiers.*;

var eg = new QualifierTest();
AddTestCase("implements default interface, access via interface name", "defFunc()", eg.doDefByInt());
AddTestCase("implements default interface, access via public", "defFunc()", eg.doDefByPub());
AddTestCase("implements internal interface, access via interface name", "defFunc()", eg.doIntByInt());
AddTestCase("implements internal interface, access via public", "defFunc()", eg.doIntByPub());

AddTestCase("implements public interface, access via interface name", "defFunc()", eg.doPubByInt());
AddTestCase("implements public interface, access via public", "defFunc()", eg.doPubByPub());

test();       // leave this alone.  this executes the test cases and
              // displays results.
