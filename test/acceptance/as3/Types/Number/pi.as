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
include "numberUtil.as";


var SECTION = "15.8.1.6";
var VERSION = "AS3";
var TITLE   = "public static const PI:Number = 3.141592653589793;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var num_pi:Number = 3.141592653589793;

AddTestCase("Number.PI", num_pi, Number.PI);
AddTestCase("typeof Number.PI", "Number", getQualifiedClassName(Number.PI));

AddTestCase("Number.PI - DontDelete", false, delete(Number.PI));
AddTestCase("Number.PI is still ok", num_pi, Number.PI);

AddTestCase("Number.PI - DontEnum", '',getNumberProp('PI'));
AddTestCase("Number.PI is no enumberable", false, Number.propertyIsEnumerable('PI'));

AddErrorTest("Number.PI - ReadOnly", REFERENCEERROR+1074, function(){ Number.PI = 0; });
AddTestCase("Number.PI is still here", num_pi, Number.PI);

test();

