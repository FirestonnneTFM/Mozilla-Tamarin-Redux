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


var SECTION = "4.6.5.1";
var VERSION = "AS3";
var TITLE   = "Enumeration for..in";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var expected:* = 4;
var result:* = 0;
var flt4:float4 = new float4(1f, 1f, 1f, 1f);
for ( var i in flt4 )
{
    AddTestCase("for .. in loop iterant is index NOT value", i, result);
    result++;
}
AddTestCase("for .. in loop over float4 should iterate 4 times", expected, result);


// every
var float4Array:Array = [float4(0f), float4(1f), float4(2f), float4(3f)];
var resultVal:float4 = new float4(0f);
function everyFunc(val, index, obj)
{
    AddTestCase("every val is passed as float4", "float4", getQualifiedClassName(val));
    resultVal+=val;
    return true;
}
float4Array.every(everyFunc);
AddTestCase("float4Array.every() sum up", new float4(6f), resultVal);


// forEach
float4Array = [float4(0f), float4(1f), float4(2f), float4(3f)];
resultVal = new float4(0f);
function forEachFunc(val, index, obj)
{
    AddTestCase("forEach val is passed as float4", "float4", getQualifiedClassName(val));
    resultVal+=val;
}
float4Array.forEach(forEachFunc);
AddTestCase("float4Array.forEach() sum up", new float4(6f), resultVal);


// map
float4Array = [float4(0f), float4(1f), float4(2f), float4(3f)];
resultVal = new float4(0f);
function mapFunc(val, index, obj)
{
    AddTestCase("map val is passed as float4", "float4", getQualifiedClassName(val));
    return val;
}
AddTestCase("float4Array.map()", [float4(0f), float4(1f), float4(2f), float4(3f)].toString(), float4Array.map(mapFunc).toString());
AddTestCase("float4Array.map() returns a new array", true, float4Array.map(mapFunc) !== float4Array);


// forEach
float4Array = [float4(0f), float4(1f), float4(2f), float4(3f)];
resultVal = new float4(0f);
function someFunc(val, index, obj)
{
    AddTestCase("some val is passed as float4", "float4", getQualifiedClassName(val));
    resultVal+=val;
}
float4Array.some(someFunc);
AddTestCase("float4Array.some() sum up", new float4(6f), resultVal);


// join
float4Array = [float4(0f), float4(1f), float4(2f), float4(3f)];
AddTestCase("float4Array.join()", "0,0,0,0|1,1,1,1|2,2,2,2|3,3,3,3", float4Array.join("|"));

var float4Array:Array = [float4(0f), float4(1f), float4(2f), float4(2f), float4(3f)];
AddTestCase("float4Array.indexOf(float4(0f, 1f, 2f, 3f))", -1, float4Array.indexOf(float4(0f, 1f, 2f, 3f)));
AddTestCase("float4Array.indexOf(float4(2f))", 2, float4Array.indexOf(float4(2f)));
AddTestCase("float4Array.lastIndexOf(float4(0f, 1f, 2f, 3f))", -1, float4Array.lastIndexOf(float4(0f, 1f, 2f, 3f)));
AddTestCase("float4Array.lastIndexOf(float4(2f))", 3, float4Array.lastIndexOf(float4(2f)));


test();

