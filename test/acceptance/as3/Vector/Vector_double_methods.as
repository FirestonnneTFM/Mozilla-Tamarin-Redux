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

var SECTION = "Vector";
var VERSION = "Bug 592735: code coverage";
startTest();

writeHeaderToLog( SECTION + " Vector_double_AS3 methods based on missing code coverage");

function g(x) : Number { return x }

var v:Vector.<Number> = new Vector.<Number>;
var x:Number;
x = 20;
// avmplus::NativeID::__AS3___vec_Vector_double_AS3_push_thunk(MethodEnv*,uint32_t,Atom*)
v.push(g(x)/10);
AddTestCase("Vector_double_AS3_push", 1, v.length);
v.push();
AddTestCase("Vector_double_AS3_push null", 1, v.length);

// avmplus::NativeID::__AS3___vec_Vector_double_AS3_unshift_thunk(MethodEnv*,uint32_t,Atom*)
x = 10;
v.unshift(g(x)/10);
AddTestCase("Vector_double_AS3_unshift", "1,2", v.toString());
v.unshift();
AddTestCase("Vector_double_AS3_unshift null", "1,2", v.toString());

// avmplus::NativeID::__AS3___vec_Vector_double_AS3_shift_thunk(MethodEnv*,uint32_t,Atom*)
AddTestCase("Vector_double_AS3_shift", 1, v.shift());
AddTestCase("Vector_double_AS3_shift length", 1, v.length);

// avmplus::NativeID::__AS3___vec_Vector_double_AS3_pop_thunk(MethodEnv*,uint32_t,Atom*)
v.pop();
AddTestCase("Vector_double_AS3_pop", 0, v.length);

// avmplus::NativeID::__AS3___vec_Vector_double_length_set_thunk(MethodEnv*,uint32_t,Atom*)
v.length = 2;
AddTestCase("Vector_double_length_set", 2, v.length);

// avmplus::NativeID::__AS3___vec_Vector_double_fixed_set_thunk(MethodEnv*,uint32_t,Atom*)
// avmplus::NativeID::__AS3___vec_Vector_double_fixed_get_thunk(MethodEnv*,uint32_t,Atom*)
v.fixed = true;
AddTestCase("Vector_double_fixed_get", true, v.fixed);



v.fixed = false;

// __AS3___vec_Vector_double_private__map_thunk(MethodEnv*,uint32_t,Atom*)
x = 10;
v[0] = (g(x)/10);
x = 20;
v[1] = (g(x)/10);
function mapper1(value, index, obj)
{
    return value+1;
}
AddTestCase("Vector_double_private__map", "2,3", v.map(mapper1).toString()); // NOTE: this returns a new vector and does not alter

// __AS3___vec_Vector_double_private__reverse_thunk(MethodEnv*,uint32_t,Atom*)
AddTestCase("Vector_double_private__reverse", "2,1", v.reverse().toString());

test();
