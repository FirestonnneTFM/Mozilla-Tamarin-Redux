/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'toString.js';

/**
   Filename:     toString.js
   Description:  'Tests RegExp method toString'

   Author:       Nick Lerissa
   Date:         March 13, 1998
*/

var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
var VERSION = 'no version';
startTest();  var testscases=[]; var index=0;
var TITLE = 'RegExp: toString';

writeHeaderToLog('Executing script: toString.js');
writeHeaderToLog( SECTION + " "+ TITLE);

var re = new RegExp();
testcases[index++] = new TestCase ( SECTION, "var re = new RegExp(); re.toString()",
           '//', re.toString());

// re = /.+/; re.toString();
re = /.+/;
testcases[index++] = new TestCase ( SECTION, "re = /.+/; re.toString()",
           '/.+/', re.toString());

// re = /test/gi; re.toString()
re = /test/gi;
testcases[index++] = new TestCase ( SECTION, "re = /test/gi; re.toString()",
           '/test/gi', re.toString());

// re = /test2/ig; re.toString()
re = /test2/ig;
testcases[index++] = new TestCase ( SECTION, "re = /test2/ig; re.toString()",
           '/test2/gi', re.toString());

test();
