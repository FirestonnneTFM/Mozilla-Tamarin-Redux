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


var SECTION = "4.6.5";
var VERSION = "AS3";
var TITLE   = "float.prototype.toExponential ( fractionDigits=0 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 3.14131211f;
AddTestCase("float.prototype.toExponential = function", true, float.prototype.toExponential is Function );
AddTestCase("float.prototype.toExponential returns a String", "String", getQualifiedClassName(test_flt.toExponential()));

var orig_toexpo = String.prototype.toExponential;
String.prototype.toExponential = float.prototype.toExponential;
var test_str:String = "3.14131211";
AddTestCase("float.prototype.toExponential() on String does NOT throw TypeError", test_flt.toExponential(), test_str.toExponential());
AddTestCase("float.prototype.toExponential(7) on String does NOT throw TypeError", test_flt.toExponential(7), test_str.toExponential(7));

// shouldn't throw according to Note
AddTestCase("float.prototype.toExponential - accepts 'undefined' for fractionDigits", test_flt.toExponential(undefined), test_str.toExponential(undefined));
String.prototype.toExponential = orig_toexpo;

AddTestCase("float.prototype.toExponential = invokes AS3::toExponential", test_flt.AS3::toExponential(), test_flt.toExponential());
AddTestCase("float.prototype.toExponential = invokes AS3::toExponential", test_flt.AS3::toExponential(6), test_flt.toExponential(6));

AddTestCase("float.prototype.toExponential - DontEnum", "", getFloatProtoProp("toExponential"));
AddTestCase("float.prototype.toExponential is not enumerable", false, float.prototype.propertyIsEnumerable("toExponential"));

orig_toexpo = float.prototype.toExponential;
float.prototype.toExponential = 1.1243174;
AddTestCase("float.prototype.toExponential - Writable", true, orig_toexpo != float.prototype.toExponential);
float.prototype.toExponential = orig_toexpo;

AddTestCase("float.prototype.toExponential - Deletable", true, delete(float.prototype.toExponential));
AddTestCase("float.prototype.toExponential should now be undefined", undefined, float.prototype.toExponential);
float.prototype.toExponential = orig_toexpo;

AddTestCase("float.prototype.toExponential default fractionDigits 0", test_flt.toExponential(0), test_flt.toExponential());

test();

