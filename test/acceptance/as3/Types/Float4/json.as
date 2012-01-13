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
var TITLE   = "JSON functionality operating on float4";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

// Testing the following on float4:
//
//  - float4 data are formatted as objects with x, y, z, w fields
//  - structure is walked properly if replacer or property array is present
//  - toJSON on float4.prototype is obeyed
//  - toJSON on float.prototype [sic] is obeyed

var x = JSON.stringify(float4(1,2,3,4));
AddTestCase("float4 serializes as structure of numbers", x, x.match(/^\{"[xyzw]":[1234],"[xyzw]":[1234],"[xyzw]":[1234],"[xyzw]":[1234]\}$/)[0]);
AddTestCase("All fields present", true, x.match(/x/) != null && x.match(/y/) != null && x.match(/z/) != null && x.match(/w/) != null);

float4.prototype.toJSON = function (x) { return "hi there" };
AddTestCase("float4.prototype.toJSON is obeyed", "\"hi there\"", JSON.stringify(float4(1,2,3,4)));
delete float4.prototype.toJSON;

float.prototype.toJSON = function (k) { return this + 5 };
var x = JSON.stringify(float4(1,2,3,4));
AddTestCase("float4 serializes as structure of larger numbers", x, x.match(/^\{"[xyzw]":[6789],"[xyzw]":[6789],"[xyzw]":[6789],"[xyzw]":[6789]\}$/)[0]);
delete float.prototype.toJSON;

var x = JSON.stringify(float4(1,2,3,4), function (k,v) { if (v is float) return v+5; return v; }, 1);
AddTestCase("float4 serializes as structure of larger numbers with indent", x, x.match(/^\{\n "[xyzw]": [6789],\n "[xyzw]": [6789],\n "[xyzw]": [6789],\n "[xyzw]": [6789]\n\}$/)[0]);

test();
