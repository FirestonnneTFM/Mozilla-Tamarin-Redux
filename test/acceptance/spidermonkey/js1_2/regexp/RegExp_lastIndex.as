/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code, released
 * March 31, 1998.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

gTestfile = 'RegExp_lastIndex.js';

/**
   Filename:     RegExp_lastIndex.js
   Description:  'Tests RegExps lastIndex property'

   Author:       Nick Lerissa
   Date:         March 17, 1998
*/

var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
var VERSION = 'no version';
var TITLE   = 'RegExp: lastIndex';
var BUGNUMBER="123802";

startTest();  var testscases=[]; var index=0;
writeHeaderToLog('Executing script: RegExp_lastIndex.js');
writeHeaderToLog( SECTION + " "+ TITLE);

// re=/x./g; re.lastIndex=4; re.exec('xyabcdxa');
re=/x./g;
re.lastIndex=4;
testcases[index++] = new TestCase ( SECTION, "re=/x./g; re.lastIndex=4; re.exec('xyabcdxa')",
           'xa', String(re.exec('xyabcdxa')));

// re.lastIndex
testcases[index++] = new TestCase ( SECTION, "re.lastIndex",
           8, re.lastIndex);

// re.exec('xyabcdef');
testcases[index++] = new TestCase ( SECTION, "re.exec('xyabcdef')",
           null, re.exec('xyabcdef'));

// re.lastIndex
testcases[index++] = new TestCase ( SECTION, "re.lastIndex",
           0, re.lastIndex);

// re.exec('xyabcdef');
testcases[index++] = new TestCase ( SECTION, "re.exec('xyabcdef')",
           'xy', String(re.exec('xyabcdef')));

// re.lastIndex=30; re.exec('123xaxbxc456');
re.lastIndex=30;
testcases[index++] = new TestCase ( SECTION, "re.lastIndex=30; re.exec('123xaxbxc456')",
           null, re.exec('123xaxbxc456'));

test();
