/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'String.js';

/**
   Filename:     String.js
   Description:  'This tests the function String(Object)'

   Author:       Nick Lerissa
   Date:         Fri Feb 13 09:58:28 PST 1998
*/

var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
var VERSION = 'no version';
startTest();  var testscases=[]; var index=0;
var TITLE = 'functions: String';

writeHeaderToLog('Executing script: String.js');
writeHeaderToLog( SECTION + " "+ TITLE);

testcases[index++] = new TestCase( SECTION, "String(true)            ",
          'true',  (String(true)));
testcases[index++] = new TestCase( SECTION, "String(false)           ",
          'false',  (String(false)));
testcases[index++] = new TestCase( SECTION, "String(-124)           ",
          '-124',  (String(-124)));
testcases[index++] = new TestCase( SECTION, "String(1.23)          ",
          '1.23',  (String(1.23)));
testcases[index++] = new TestCase( SECTION, "String({p:1})           ",
          '[object Object]',  (String({p:1})));
testcases[index++] = new TestCase( SECTION, "String(null)            ",
          'null',  (String(null)));
testcases[index++] = new TestCase( SECTION, "String([1,2,3])            ",
          '1,2,3',  (String([1,2,3])));

test();

