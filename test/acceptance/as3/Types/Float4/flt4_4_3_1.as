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


var SECTION = "4.3.1";
var VERSION = "AS3";
var TITLE   = "The float4 method called as a constructor new float4 (x)";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var result = new float4();
AddTestCase("Float4 with no args", "float4", getQualifiedClassName(result));

var undefined_float4 = new float4(undefined);
AddTestCase("Float4 as constructor, with 'undefined' arg", "float4", getQualifiedClassName(undefined_float4));

var null_float4 = new float4(null);
AddTestCase("Float4 as constructor, with 'null' arg", "float4", getQualifiedClassName(null_float4));

var boolean_float4 = new float4(true);
AddTestCase("Float4 as constructor, with 'boolean' arg", "float4", getQualifiedClassName(boolean_float4));

var dble_float4 = new float4(3.14);
AddTestCase("Float4 as constructor, with 'double' arg", "float4", getQualifiedClassName(dble_float4));

var int_float4 = new float4(3);
AddTestCase("Float4 as constructor, with 'int' arg", "float4", getQualifiedClassName(int_float4));

var string_float4 = new float4("3.14");
AddTestCase("Float4 as constructor, with 'String' arg", "float4", getQualifiedClassName(string_float4));

var myObject:Object = {1:1};
var object_float4 = new float4(myObject);
AddTestCase("Float4 as constructor, with 'Object' arg", "float4", getQualifiedClassName(object_float4));

var literal_float4 = new float4(3.14f);
AddTestCase("Float4 as constructor, with 'FloatLiteral' arg", "float4", getQualifiedClassName(literal_float4));

var flt4 = new float4(1f, 1f, 1f, 1f);
var flt4_flt4 = new float4(flt4);
AddTestCase("Float4 as a constructor with float4 arg", "float4", getQualifiedClassName(flt4_flt4));
AddStrictTestCase("Return x if x is a float4, float4(x)", true, flt4 === flt4_flt4);

test();

