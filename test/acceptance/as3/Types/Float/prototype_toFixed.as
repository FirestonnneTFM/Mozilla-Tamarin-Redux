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
include "floatUtil.as";


var SECTION = "4.6.6";
var VERSION = "AS3";
var TITLE   = "float.prototype.toFixed ( fractionDigits=0 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 3.14131211f;
AddTestCase("float.prototype.toFixed = function", true, float.prototype.toFixed is Function );
AddTestCase("float.prototype.toFixed returns a String", "String", getQualifiedClassName(test_flt.public::toFixed()));

var orig_tofixed = String.prototype.toFixed;
String.prototype.toFixed = float.prototype.toFixed;
var test_str:String = "3.14131211";
AddTestCase("float.prototype.toFixed() - does NOT throw TypeError", test_flt.public::toFixed(), test_str.public::toFixed());
AddTestCase("float.prototype.toFixed(7) - does NOT throw TypeError", test_flt.public::toFixed(7), test_str.public::toFixed(7));
// shouldn't throw according to Note
AddTestCase("float.prototype.toFixed - accepts 'undefined' for fractionDigits", test_flt.public::toFixed(undefined), test_strpublic::.toFixed(undefined));
String.prototype.toFixed = orig_tofixed;


AddTestCase("float.prototype.toFixed = invokes AS3::toFixed", test_flt.AS3::toFixed(), test_flt.public::toFixed());
AddTestCase("float.prototype.toFixed = invokes AS3::toFixed", test_flt.AS3::toFixed(7), test_flt.public::toFixed(7));

AddTestCase("float.prototype.toFixed - DontEnum", "", getFloatProtoProp("toFixed"));
AddTestCase("float.prototype.toFixed is not enumerable", false, float.prototype.propertyIsEnumerable("toFixed"));

orig_tofixed = float.prototype.toFixed;
float.prototype.toFixed = 1.1243174;
AddTestCase("float.prototype.toFixed - Writable", true, orig_tofixed != float.prototype.toFixed);
float.prototype.toFixed = orig_tofixed;

AddTestCase("float.prototype.toFixed - Deletable", true, delete(float.prototype.toFixed));
AddTestCase("float.prototype.toFixed should now be undefined", undefined, float.prototype.toFixed);
float.prototype.toFixed = orig_tofixed;

AddTestCase("float.prototype.toFixed default fractionDigits 0", test_flt.public::toFixed(0), test_flt.public::toFixed());

test();

