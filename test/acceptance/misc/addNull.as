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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

var SECTION = "Expressions";
var VERSION = "AS3";
var TITLE   = "Addition/Concatenation with null";

startTest();

var null_atom:* = null;
var null_string:String = null;
var null_date:Date = null;
var null_object:Object = null;

var i:int = 5;
var u:uint = 5;
var d:Number = 5;
var a:* = 5;
var s:String = "5";

// A null value converts to zero when added to a number.

AddTestCase("null_atom + i", null_atom + i, 5);
AddTestCase("i + null_atom", i + null_atom, 5);
AddTestCase("null_atom + u", null_atom + u, 5);
AddTestCase("u + null_atom", u + null_atom, 5);
AddTestCase("null_atom + d", null_atom + d, 5);
AddTestCase("d + null_atom", d + null_atom, 5);
AddTestCase("null_atom + a", null_atom + a, 5);
AddTestCase("a + null_atom", a + null_atom, 5);

// A null value is still null even if statically typed as a string,
// thus it converts to zero, not "null", when added to a number.

AddTestCase("null_string + i", null_string + i, 5);
AddTestCase("i + null_string", i + null_string, 5);
AddTestCase("null_string + u", null_string + u, 5);
AddTestCase("u + null_string", u + null_string, 5);
AddTestCase("null_string + d", null_string + d, 5);
AddTestCase("d + null_string", d + null_string, 5);
AddTestCase("null_string + a", null_string + a, 5);
AddTestCase("a + null_string", a + null_string, 5);

// There are distinct code paths for Date, and also
// for objects that are neither String nor Date.
// Make sure we cover these.

AddTestCase("null_date + i", null_date + i, 5);
AddTestCase("i + null_date", i + null_date, 5);
AddTestCase("null_date + u", null_date + u, 5);
AddTestCase("u + null_date", u + null_date, 5);
AddTestCase("null_date + d", null_date + d, 5);
AddTestCase("d + null_date", d + null_date, 5);
AddTestCase("null_date + a", null_date + a, 5);
AddTestCase("a + null_date", a + null_date, 5);

AddTestCase("null_object + i", null_object + i, 5);
AddTestCase("i + null_object", i + null_object, 5);
AddTestCase("null_object + u", null_object + u, 5);
AddTestCase("u + null_object", u + null_object, 5);
AddTestCase("null_object + d", null_object + d, 5);
AddTestCase("d + null_object", d + null_object, 5);
AddTestCase("null_object + a", null_object + a, 5);
AddTestCase("a + null_object", a + null_object, 5);

// A null value converts to the string "null" when concatenated with a string.

AddTestCase("null_atom + s", null_atom + s, "null5");
AddTestCase("s + null_atom", s + null_atom, "5null");

AddTestCase("null_string + s", null_string + s, "null5");
AddTestCase("s + null_string", s + null_string, "5null");

AddTestCase("null_date + s", null_date + s, "null5");
AddTestCase("s + null_date", s + null_date, "5null");

AddTestCase("null_object + s", null_object + s, "null5");
AddTestCase("s + null_object", s + null_object, "5null");

test();
