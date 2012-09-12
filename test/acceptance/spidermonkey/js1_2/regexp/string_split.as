/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'string_split.js';

/**
   Filename:     string_split.js
   Description:  'Tests the split method on Strings using regular expressions'

   Author:       Nick Lerissa
   Date:         March 11, 1998
*/

var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
var VERSION = 'no version';
startTest();  var testscases=[]; var index=0;
var TITLE   = 'String: split';

writeHeaderToLog('Executing script: string_split.js');
writeHeaderToLog( SECTION + " "+ TITLE);


// 'a b c de f'.split(/\s/)
testcases[index++] = new TestCase ( SECTION, "'a b c de f'.split(/\s/)",
           String(["a","b","c","de","f"]), String('a b c de f'.split(/\s/)));

// 'a b c de f'.split(/\s/,3)
testcases[index++] = new TestCase ( SECTION, "'a b c de f'.split(/\s/,3)",
           String(["a","b","c"]), String('a b c de f'.split(/\s/,3)));

// 'a b c de f'.split(/X/)
testcases[index++] = new TestCase ( SECTION, "'a b c de f'.split(/X/)",
           String(["a b c de f"]), String('a b c de f'.split(/X/)));

// 'dfe23iu 34 =+65--'.split(/\d+/)
testcases[index++] = new TestCase ( SECTION, "'dfe23iu 34 =+65--'.split(/\d+/)",
           String(["dfe","iu "," =+","--"]), String('dfe23iu 34 =+65--'.split(/\d+/)));

// 'dfe23iu 34 =+65--'.split(new RegExp('\d+'))
testcases[index++] = new TestCase ( SECTION, "'dfe23iu 34 =+65--'.split(new RegExp('\\d+'))",
           String(["dfe","iu "," =+","--"]), String('dfe23iu 34 =+65--'.split(new RegExp('\\d+'))));

// 'abc'.split(/[a-z]/)
testcases[index++] = new TestCase ( SECTION, "'@ab*c'.split(/[a-z]/)",
           String(["@","","*",""]), String('@ab*c'.split(/[a-z]/)));

// 'abc'.split(/[a-z]/)
testcases[index++] = new TestCase ( SECTION, "'a!b!c'.split(/[a-z]/)",
           String(["","!","!","!"]), String('a!b!c!'.split(/[a-z]/)));

// 'abc'.split(new RegExp('[a-z]'))
testcases[index++] = new TestCase ( SECTION, "'!@a\(bc&&'.split(new RegExp('[a-z]'))",
           String(["!@","(","","&&"]), String('!@a\(bc&&'.split(new RegExp('[a-z]'))));

// 'abc'.split(new RegExp('[a-z]'))
testcases[index++] = new TestCase ( SECTION, "'\(abc\)'.split(new RegExp('[a-z]'))",
           String(["(","","",")"]), String('\(abc\)'.split(new RegExp('[a-z]'))));

test();
