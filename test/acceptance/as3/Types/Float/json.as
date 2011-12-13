/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
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

/*
Returns an implementation-dependent approximation to the arc tangent of x.
The result is expressed in radians and ranges from iPI/2 to +PI/2.
*/

var SECTION = "XXX";
var VERSION = "AS3";
var TITLE   = "JSON functionality operating on float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

// Testing the following on float:
//
//  - float data are formatted as Number
//  - toJSON on float.prototype is obeyed
//  - passing in float values for the number of spaces in stringify works
//  - using float values as property names in the replacer array works
//
// The two tests for "float values" are necessary because the JSON code switches on type
// and there is no generic "numeric" type for it to test, it proceeds by cases.

AddTestCase("float serializes as number", "37.5", JSON.stringify(37.5f));

AddTestCase("float can be used to denote spaces", "[\n    37\n]", JSON.stringify([37], null, 4f));

AddTestCase("float can be used as a property name in the replacer array", "{\"1\":\"b\",\"3\":\"d\"}", JSON.stringify({0:"a",1:"b",2:"c",3:"d"},[1f,3f]));

float.prototype.toJSON = float.prototype.toJSON = function (k) { return this + 5};
AddTestCase("float's toJSON is invoked properly and its value used", "[6,7,3]", JSON.stringify([1f,2f,3])); // Note, "3" is not intended to be float
delete float.prototype.toJSON;

test();
