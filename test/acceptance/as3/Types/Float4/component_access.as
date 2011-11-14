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


var SECTION = "4.6.3";
var VERSION = "AS3";
var TITLE   = "Component accesses";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

// Access component via v.x
var flt4:float4 = new float4(1f);
AddErrorTest("float4.x as a setter", REFERENCEERROR, function(){ flt4.x = 12f });
AddErrorTest("float4.y as a setter", REFERENCEERROR, function(){ flt4.y = 12f });
AddErrorTest("float4.z as a setter", REFERENCEERROR, function(){ flt4.z = 12f });
AddErrorTest("float4.w as a setter", REFERENCEERROR, function(){ flt4.w = 12f });
flt4 = new float4(1f, 2f, 3f, 4f);
AddStrictTestCase("float4.x as a getter", 1f, flt4.x);
AddStrictTestCase("float4.y as a getter", 2f, flt4.y);
AddStrictTestCase("float4.z as a getter", 3f, flt4.z);
AddStrictTestCase("float4.w as a getter", 4f, flt4.w);
flt4 = new float4(1f, 2f, 3f, 4f);
AddStrictTestCase("float4.xxxx as a getter", new float4(1f), flt4.xxxx);
AddStrictTestCase("float4.yyyy as a getter", new float4(2f), flt4.yyyy);
AddStrictTestCase("float4.zzzz as a getter", new float4(3f), flt4.zzzz);
AddStrictTestCase("float4.wwww as a getter", new float4(4f), flt4.wwww);
AddStrictTestCase("float4.xyzw as a getter", new float4(1f, 2f, 3f, 4f), flt4.xyzw);
AddStrictTestCase("float4.wzyx as a getter", new float4(4f, 3f, 2f, 1f), flt4.wzyx);

// Access component via v['x'] section 4.6.3.3.b
flt4 = new float4(1f);
AddErrorTest("float4['x'] as a setter", REFERENCEERROR, function(){ flt4['x'] = 12f });
AddErrorTest("float4['y'] as a setter", REFERENCEERROR, function(){ flt4['y'] = 12f });
AddErrorTest("float4['z'] as a setter", REFERENCEERROR, function(){ flt4['z'] = 12f });
AddErrorTest("float4['w'] as a setter", REFERENCEERROR, function(){ flt4['w'] = 12f });
flt4 = new float4(1f, 2f, 3f, 4f);
AddStrictTestCase("float4['x'] as a getter", 1f, flt4['x']);
AddStrictTestCase("float4['y'] as a getter", 2f, flt4['y']);
AddStrictTestCase("float4['z'] as a getter", 3f, flt4['z']);
AddStrictTestCase("float4['w'] as a getter", 4f, flt4['w']);
flt4 = new float4(1f, 2f, 3f, 4f);
AddStrictTestCase("float4['xxxx'] as a getter", new float4(1f), flt4['xxxx']);
AddStrictTestCase("float4['yyyy'] as a getter", new float4(2f), flt4['yyyy']);
AddStrictTestCase("float4['zzzz'] as a getter", new float4(3f), flt4['zzzz']);
AddStrictTestCase("float4['wwww'] as a getter", new float4(4f), flt4['wwww']);
AddStrictTestCase("float4['xyzw'] as a getter", new float4(1f, 2f, 3f, 4f), flt4['xyzw']);
AddStrictTestCase("float4['wzyx'] as a getter", new float4(4f, 3f, 2f, 1f), flt4['wzyx']);

// Access component via v[0] section 4.6.3.2.a
flt4 = new float4(1f);
AddErrorTest("float4[0] as a setter", REFERENCEERROR, function(){ flt4[0] = 12f });
AddErrorTest("float4[1] as a setter", REFERENCEERROR, function(){ flt4[1] = 12f });
AddErrorTest("float4[2] as a setter", REFERENCEERROR, function(){ flt4[2] = 12f });
AddErrorTest("float4[3] as a setter", REFERENCEERROR, function(){ flt4[3] = 12f });

// Access outside of valid index ranges section 4.6.3.2.b
AddErrorTest("float4[-1]", RANGEERROR, function(){ flt4[-1]; });
AddErrorTest("float4[4]", RANGEERROR, function(){ flt4[4]; });
var i:Number = -1;
AddErrorTest("float4[i] -1", RANGEERROR, function(){ flt4[i]; });
i = 4;
AddErrorTest("float4[i] 4", RANGEERROR, function(){ flt4[i]; });


// Access component via v['0'] section 4.6.3.3.a
flt4 = new float4(1f);
AddErrorTest("float4['0'] as a setter", REFERENCEERROR, function(){ flt4['0'] = 12f });
AddErrorTest("float4['1'] as a setter", REFERENCEERROR, function(){ flt4['1'] = 12f });
AddErrorTest("float4['2'] as a setter", REFERENCEERROR, function(){ flt4['2'] = 12f });
AddErrorTest("float4['3'] as a setter", REFERENCEERROR, function(){ flt4['3'] = 12f });
flt4 = new float4(1f, 2f, 3f, 4f);
AddStrictTestCase("float4['0'] as a getter", 1f, flt4['0']);
AddStrictTestCase("float4['1'] as a getter", 2f, flt4['1']);
AddStrictTestCase("float4['2'] as a getter", 3f, flt4['2']);
AddStrictTestCase("float4['3'] as a getter", 4f, flt4['3']);


// Access component via v['onProto'] section 4.6.3.3.c
float4.prototype.onProto = function(){ return "foobar"; };
flt4 = new float4(1f);
AddTestCase("float4['onProto']", "function", typeof flt4['onProto']);
delete(float4.prototype.onProto);
AddErrorTest("float4['onProto'] after removed", REFERENCEERROR, function(){ flt4['onProto']; });

test();

