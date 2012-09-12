/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'compile.js';

/**
   Filename:     compile.js
   Description:  'Tests regular expressions method compile'

   Author:       Nick Lerissa
   Date:         March 10, 1998
*/

var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
var VERSION = 'no version';
startTest();  var testscases=[]; var index=0;
var TITLE   = 'RegExp: compile';

writeHeaderToLog('Executing script: compile.js');
writeHeaderToLog( SECTION + " "+ TITLE);

var regularExpression = /[0-9]{3}x[0-9]{4}/i;

testcases[index++] = new TestCase ( SECTION,
           "(compile '[0-9]{3}x[0-9]{4}','i')",
           String(["456X7890"]), String('234X456X7890'.match(regularExpression)));

testcases[index++] = new TestCase ( SECTION,
           "source of (compile '[0-9]{3}x[0-9]{4}','i')",
           "[0-9]{3}x[0-9]{4}", regularExpression.source);

testcases[index++] = new TestCase ( SECTION,
           "global of (compile '[0-9]{3}x[0-9]{4}','i')",
           false, regularExpression.global);

testcases[index++] = new TestCase ( SECTION,
           "ignoreCase of (compile '[0-9]{3}x[0-9]{4}','i')",
           true, regularExpression.ignoreCase);

regularExpression = /[0-9]{3}X[0-9]{3}/g;

testcases[index++] = new TestCase ( SECTION,
           "(compile '[0-9]{3}X[0-9]{3}','g')",
           String(["234X456"]), String('234X456X7890'.match(regularExpression)));

testcases[index++] = new TestCase ( SECTION,
           "source of (compile '[0-9]{3}X[0-9]{3}','g')",
           "[0-9]{3}X[0-9]{3}", regularExpression.source);

testcases[index++] = new TestCase ( SECTION,
           "global of (compile '[0-9]{3}X[0-9]{3}','g')",
           true, regularExpression.global);

testcases[index++] = new TestCase ( SECTION,
           "ignoreCase of (compile '[0-9]{3}X[0-9]{3}','g')",
           false, regularExpression.ignoreCase);


test();
