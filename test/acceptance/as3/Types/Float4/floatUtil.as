/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

import flash.utils.ByteArray;
import avmplus.*;

function AddStrictTestCase(desc, expected, actual)
{
    if (expected===actual && typeof(expected)==typeof(actual))
        AddTestCase(desc, expected, actual);
    else
        AddTestCase(desc, typeof(expected)+"["+expected+"]","(STRICT EQ); "+typeof(actual)+"["+actual+"]");
}

var dummy_number = NaN;
var isAS3:Boolean = dummy_number.toString == dummy_number.AS3::toString;

function getFloat4Prop(name):String
{
   string = '';
   for ( prop in float4 )
   {
       string += ( prop == name ) ? prop : '';
   }
   return string;
}

function getFloat4ProtoProp(name):String
{
   string = '';
   for ( prop in float4.prototype )
   {
       string += ( prop == name ) ? prop : '';
   }
   return string;
}

function FloatRawBits(param:float):int
{
    // Don't catch exceptions here - caller function should catch them
    var byteArr:ByteArray = new ByteArray();
    byteArr.writeFloat(param);
    byteArr.position = 0;
    var result:int =  byteArr.readInt();
    return result;
}

function DoubleRawBits(param:Number):Array
{
    // Don't catch exceptions here - caller function should catch them
    var byteArr:ByteArray = new ByteArray();
    byteArr.writeDouble(param);
    byteArr.position = 0;
    var result0:int =  byteArr.readInt();
    var result1:int =  byteArr.readInt();
    return [result0,result1];
}

function MyValueAlteringObject(value)
{
    this.value = value;
    this.valueOf = function(){var v = ++this.value; return v};
}
function MyStringObject(value)
{
    this.value = value;
    this.toString = function(){return this.value+''};
}
function MyObject(value)
{
    this.value = value;
    this.valueOf = function(){return this.value};
}
