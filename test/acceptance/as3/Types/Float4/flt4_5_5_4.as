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


var SECTION = "6.7.4";
var VERSION = "AS3";
var TITLE   = "The instanceof operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var onef:float4 = new float4(1f);


AddTestCase("float4 class is not instanceof float4", false, float4 instanceof float4);
AddTestCase("float4 instance is instanceof float4", true, onef instanceof float4);
AddTestCase("float4 class is instanceof Object", true, float4 instanceof Object);
AddTestCase("float4 class is instanceof Class", true, float4 instanceof Class);
AddTestCase("float4 class is not instanceof Function", false, float4 instanceof Function);
AddTestCase("float4 instance is instanceof Object", true, onef instanceof Object);

/* FIXME: https://bugzilla.mozilla.org/show_bug.cgi?id=696641
var vf = new Vector.<float>();
AddTestCase("Vector.<float> is not instanceof float", false, vf instanceof float);
*/

AddTestCase("float4 class is not instanceof Number", false, float4 instanceof Number);
AddTestCase("float4 instance is not instanceof Number", false, onef instanceof Number);
AddTestCase("float4 class is not instanceof int", false, float4 instanceof int);
AddTestCase("float4 instance is not instanceof int", false, onef instanceof int);
AddTestCase("float4 class is not instanceof uint", false, float4 instanceof uint);
AddTestCase("float4 instance is not instanceof uint", false, onef instanceof uint);
AddTestCase("float4 class is not instanceof String", false, float4 instanceof String);
AddTestCase("float4 instance is not instanceof String", false, onef instanceof String);

AddErrorTest("AS: TypeError if datatype is not Class or Function", TYPEERROR, function(){ return float4(1f) instanceof float4(1f); });


test();

