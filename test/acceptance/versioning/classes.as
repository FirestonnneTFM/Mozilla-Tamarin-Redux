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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

import avmplus.*;
import avmshell.*;

var SECTION = 'API Versioning - classes';
var VERSION = 'AS3';

startTest();

writeHeaderToLog( SECTION );

var re:String;
var re1065:String = 'ReferenceError: Error #1065';
var re1056:String = 'ReferenceError: Error #1056';
var re1069:String = 'ReferenceError: Error #1069';

var apiVersion:int = System.apiVersion;

// expected answers
var apiExpectedAns:Array = [];
re = re1069;        
apiExpectedAns[API_FP_9_0] = [true, true,   re,   re,   re,   re,   re,   re,   re,   re, true,   re, true];
apiExpectedAns[API_AIR_1_0] = [true, true, true,   re,   re,   re,   re,   re,   re, true, true,   re, true];
apiExpectedAns[API_FP_10_0] = [true, true,   re, true,   re,   re,   re,   re,   re, true, true, true, true];
apiExpectedAns[API_AIR_1_5] = [true, true, true, true, true,   re,   re,   re,   re, true, true, true, true];
apiExpectedAns[API_AIR_1_5_1] = [true, true, true, true, true, true,   re,   re,   re, true, true, true, true];
apiExpectedAns[API_FP_10_0_32] = [true, true,   re, true,   re,   re, true,   re,   re, true, true, true, true];
apiExpectedAns[API_AIR_1_5_2] = [true, true, true, true, true, true, true, true,   re, true, true, true, true];

// expected answer for set
var apiExpectedSetAns:Array =[];
re = re1056; // missing set generates a 1056 ref error
apiExpectedSetAns[API_FP_9_0] = [true, true,   re,   re,   re,   re,   re,   re,   re,   re, true,   re, true];
apiExpectedSetAns[API_AIR_1_0] = [true, true, true,   re,   re,   re,   re,   re,   re, true, true,   re, true];
apiExpectedSetAns[API_FP_10_0] = [true, true,   re, true,   re,   re,   re,   re,   re, true, true, true, true];
apiExpectedSetAns[API_AIR_1_5] = [true, true, true, true, true,   re,   re,   re,   re, true, true, true, true];
apiExpectedSetAns[API_AIR_1_5_1] = [true, true, true, true, true, true,   re,   re,   re, true, true, true, true];
apiExpectedSetAns[API_FP_10_0_32] = [true, true,   re, true,   re,   re, true,   re,   re, true, true, true, true];
apiExpectedSetAns[API_AIR_1_5_2] = [true, true, true, true, true, true, true, true,   re, true, true, true, true];

var classExpectedAns:Array = [];
o = 'object'
u = 'undefined';        
classExpectedAns[API_FP_9_0] = [o, o,   u,   u,   u,   u,   u,   u,   u,   u, o,   u, o];
classExpectedAns[API_AIR_1_0] = [o, o,   o,   u,   u,   u,   u,   u,   u, o, o,   u, o];
classExpectedAns[API_FP_10_0] = [o, o,   u, o,   u,   u,   u,   u,   u, o, o, o, o];
classExpectedAns[API_AIR_1_5] = [o, o, o, o, o,   u,   u,   u,   u, o, o, o, o];
classExpectedAns[API_AIR_1_5_1] = [o, o, o, o, o, o,   u,   u,   u, o, o, o, o];
classExpectedAns[API_FP_10_0_32] = [o, o,   u, o,   u,   u, o,   u,   u, o, o, o, o];
classExpectedAns[API_AIR_1_5_2] = [o, o, o, o, o, o, o, o,   u, o, o, o, o];

// set expected answers to specified api version 
var ea:Array = apiExpectedAns[apiVersion]
var ea_set:Array = apiExpectedSetAns[apiVersion]
var cea:Array = classExpectedAns[apiVersion]

var pc = new public_class();

versionTest(function() { return pc.public_var }, 'pc.public_var', ea[0]);
versionTest(function() { return pc.public_var_FP_9_0 }, 'pc.public_var_FP_9_0', ea[1]);
versionTest(function() { return pc.public_var_AIR_1_0 }, 'pc.public_var_AIR_1_0', ea[2]);
versionTest(function() { return pc.public_var_FP_10_0 }, 'pc.public_var_FP_10_0', ea[3]);
versionTest(function() { return pc.public_var_AIR_1_5 }, 'pc.public_var_AIR_1_5', ea[4]);
versionTest(function() { return pc.public_var_AIR_1_5_1 }, 'pc.public_var_AIR_1_5_1', ea[5]);
versionTest(function() { return pc.public_var_FP_10_0_32 }, 'pc.public_var_FP_10_0_32', ea[6]);
versionTest(function() { return pc.public_var_AIR_1_5_2 }, 'pc.public_var_AIR_1_5_2', ea[7]);
versionTest(function() { return pc.public_var_AIR_1_0_FP_10_0 }, 'pc.public_var_AIR_1_0_FP_10_0', ea[9]);
versionTest(function() { return pc.public_var_AIR_1_5_2_FP_9_0 }, 'pc.public_var_AIR_1_5_2_FP_9_0', ea[10]);
versionTest(function() { return pc.public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2 }, 'pc.public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2', ea[11]);
versionTest(function() { return pc.public_var_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 }, 'pc.public_var_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', ea[12]);

versionTest(function() { return pc.public_const }, 'pc.public_const', ea[0]);
versionTest(function() { return pc.public_const_FP_9_0 }, 'pc.public_const_FP_9_0', ea[1]);
versionTest(function() { return pc.public_const_AIR_1_0 }, 'pc.public_const_AIR_1_0', ea[2]);
versionTest(function() { return pc.public_const_FP_10_0 }, 'pc.public_const_FP_10_0', ea[3]);
versionTest(function() { return pc.public_const_AIR_1_5 }, 'pc.public_const_AIR_1_5', ea[4]);
versionTest(function() { return pc.public_const_AIR_1_5_1 }, 'pc.public_const_AIR_1_5_1', ea[5]);
versionTest(function() { return pc.public_const_FP_10_0_32 }, 'pc.public_const_FP_10_0_32', ea[6]);
versionTest(function() { return pc.public_const_AIR_1_5_2 }, 'pc.public_const_AIR_1_5_2', ea[7]);
versionTest(function() { return pc.public_const_AIR_1_0_FP_10_0 }, 'pc.public_const_AIR_1_0_FP_10_0', ea[9]);
versionTest(function() { return pc.public_const_AIR_1_5_2_FP_9_0 }, 'pc.public_const_AIR_1_5_2_FP_9_0', ea[10]);
versionTest(function() { return pc.public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2 }, 'pc.public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2', ea[11]);
versionTest(function() { return pc.public_const_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 }, 'pc.public_const_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', ea[12]);

versionTest(function() { return pc.public_function()}, 'pc.public_function', ea[0]);
versionTest(function() { return pc.public_function_FP_9_0()}, 'pc.public_function_FP_9_0', ea[1]);
versionTest(function() { return pc.public_function_AIR_1_0()}, 'pc.public_function_AIR_1_0', ea[2]);
versionTest(function() { return pc.public_function_FP_10_0()}, 'pc.public_function_FP_10_0', ea[3]);
versionTest(function() { return pc.public_function_AIR_1_5()}, 'pc.public_function_AIR_1_5', ea[4]);
versionTest(function() { return pc.public_function_AIR_1_5_1()}, 'pc.public_function_AIR_1_5_1', ea[5]);
versionTest(function() { return pc.public_function_FP_10_0_32()}, 'pc.public_function_FP_10_0_32', ea[6]);
versionTest(function() { return pc.public_function_AIR_1_5_2()}, 'pc.public_function_AIR_1_5_2', ea[7]);
versionTest(function() { return pc.public_function_AIR_1_0_FP_10_0()}, 'pc.public_function_AIR_1_0_FP_10_0', ea[9]);
versionTest(function() { return pc.public_function_AIR_1_5_2_FP_9_0()}, 'pc.public_function_AIR_1_5_2_FP_9_0', ea[10]);
versionTest(function() { return pc.public_function_AIR_1_5_1_FP_10_0_AIR_1_5_2()}, 'pc.public_function_AIR_1_5_1_FP_10_0_AIR_1_5_2', ea[11]);
versionTest(function() { return pc.public_function_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0()}, 'pc.public_function_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', ea[12]);

versionTest(function() { return pc.public_getset }, 'pc.public_getset', ea[0]);
versionTest(function() { return pc.public_getset_FP_9_0 }, 'pc.public_getset_FP_9_0', ea[1]);
versionTest(function() { return pc.public_getset_AIR_1_0 }, 'pc.public_getset_AIR_1_0', ea[2]);
versionTest(function() { return pc.public_getset_FP_10_0 }, 'pc.public_getset_FP_10_0', ea[3]);
versionTest(function() { return pc.public_getset_AIR_1_5 }, 'pc.public_getset_AIR_1_5', ea[4]);
versionTest(function() { return pc.public_getset_AIR_1_5_1 }, 'pc.public_getset_AIR_1_5_1', ea[5]);
versionTest(function() { return pc.public_getset_FP_10_0_32 }, 'pc.public_getset_FP_10_0_32', ea[6]);
versionTest(function() { return pc.public_getset_AIR_1_5_2 }, 'pc.public_getset_AIR_1_5_2', ea[7]);
versionTest(function() { return pc.public_getset_AIR_1_0_FP_10_0 }, 'pc.public_getset_AIR_1_0_FP_10_0', ea[9]);
versionTest(function() { return pc.public_getset_AIR_1_5_2_FP_9_0 }, 'pc.public_getset_AIR_1_5_2_FP_9_0', ea[10]);
versionTest(function() { return pc.public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2 }, 'pc.public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2', ea[11]);
versionTest(function() { return pc.public_getset_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 }, 'pc.public_getset_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', ea[12]);

versionTest(function() { pc.public_getset = true; return true; }, 'pc.public_getset', ea_set[0]);
versionTest(function() { pc.public_getset_FP_9_0 = true; return true; }, 'pc.public_getset_FP_9_0', ea_set[1]);
versionTest(function() { pc.public_getset_AIR_1_0 = true; return true; }, 'pc.public_getset_AIR_1_0', ea_set[2]);
versionTest(function() { pc.public_getset_FP_10_0 = true; return true; }, 'pc.public_getset_FP_10_0', ea_set[3]);
versionTest(function() { pc.public_getset_AIR_1_5 = true; return true; }, 'pc.public_getset_AIR_1_5', ea_set[4]);
versionTest(function() { pc.public_getset_AIR_1_5_1 = true; return true; }, 'pc.public_getset_AIR_1_5_1', ea_set[5]);
versionTest(function() { pc.public_getset_FP_10_0_32 = true; return true; }, 'pc.public_getset_FP_10_0_32', ea_set[6]);
versionTest(function() { pc.public_getset_AIR_1_5_2 = true; return true; }, 'pc.public_getset_AIR_1_5_2', ea_set[7]);
versionTest(function() { pc.public_getset_AIR_1_0_FP_10_0 = true; return true; }, 'pc.public_getset_AIR_1_0_FP_10_0', ea_set[9]);
versionTest(function() { pc.public_getset_AIR_1_5_2_FP_9_0 = true; return true; }, 'pc.public_getset_AIR_1_5_2_FP_9_0', ea_set[10]);
versionTest(function() { pc.public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2 = true; return true; }, 'pc.public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2', ea_set[11]);
versionTest(function() { pc.public_getset_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 = true; return true; }, 'pc.public_getset_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', ea_set[12]);


versionTest(function() { return String(typeof(pc)) }, 'pc', cea[0]);
versionTest(function() { return String(typeof(public_class_FP_9_0)) }, 'public_class_FP_9_0', cea[1]);
versionTest(function() { return String(typeof(public_class_AIR_1_0)) }, 'public_class_AIR_1_0', cea[2]);
versionTest(function() { return String(typeof(public_class_FP_10_0)) }, 'public_class_FP_10_0', cea[3]);
versionTest(function() { return String(typeof(public_class_AIR_1_5)) }, 'public_class_AIR_1_5', cea[4]);
versionTest(function() { return String(typeof(public_class_AIR_1_5_1)) }, 'public_class_AIR_1_5_1', cea[5]);
versionTest(function() { return String(typeof(public_class_FP_10_0_32)) }, 'public_class_FP_10_0_32', cea[6]);
versionTest(function() { return String(typeof(public_class_AIR_1_5_2)) }, 'public_class_AIR_1_5_2', cea[7]);
versionTest(function() { return String(typeof(public_class_AIR_1_0_FP_10_0)) }, 'public_class_AIR_1_0_FP_10_0', cea[9]);
versionTest(function() { return String(typeof(public_class_AIR_1_5_2_FP_9_0)) }, 'public_class_AIR_1_5_2_FP_9_0', cea[10]);
versionTest(function() { return String(typeof(public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2)) }, 'public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2', cea[11]);
versionTest(function() { return String(typeof(public_class_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0)) }, 'public_class_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', cea[12]);

versionTest(function() { return String(typeof(public_interface)) }, 'public_interface', cea[0]);
versionTest(function() { return String(typeof(public_interface_FP_9_0)) }, 'public_interface_FP_9_0', cea[1]);
versionTest(function() { return String(typeof(public_interface_AIR_1_0)) }, 'public_interface_AIR_1_0', cea[2]);
versionTest(function() { return String(typeof(public_interface_FP_10_0)) }, 'public_interface_FP_10_0', cea[3]);
versionTest(function() { return String(typeof(public_interface_AIR_1_5)) }, 'public_interface_AIR_1_5', cea[4]);
versionTest(function() { return String(typeof(public_interface_AIR_1_5_1)) }, 'public_interface_AIR_1_5_1', cea[5]);
versionTest(function() { return String(typeof(public_interface_FP_10_0_32)) }, 'public_interface_FP_10_0_32', cea[6]);
versionTest(function() { return String(typeof(public_interface_AIR_1_5_2)) }, 'public_interface_AIR_1_5_2', cea[7]);
versionTest(function() { return String(typeof(public_interface_AIR_1_0_FP_10_0)) }, 'public_interface_AIR_1_0_FP_10_0', cea[9]);
versionTest(function() { return String(typeof(public_interface_AIR_1_5_2_FP_9_0)) }, 'public_interface_AIR_1_5_2_FP_9_0', cea[10]);
versionTest(function() { return String(typeof(public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2)) }, 'public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2', cea[11]);
versionTest(function() { return String(typeof(public_interface_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0)) }, 'public_interface_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0', cea[12]);

test();
