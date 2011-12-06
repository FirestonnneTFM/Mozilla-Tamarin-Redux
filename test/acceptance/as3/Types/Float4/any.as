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

var SECTION = "4.6.4";
var VERSION = "AS3";
var TITLE   = "public function get any(): Boolean";

/*
Let v be this float4 value. Return true if ToBoolean(v:x) is true or ToBoolean(v:y)
is true or ToBoolean(v:z) is true or ToBoolean(v:w) is true. Otherwise return false
 */

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4:float4 = new float4(1f);
AddStrictTestCase("flt4.any returns a Boolean", "Boolean", getQualifiedClassName(flt4.any));

function check(param:float4):Boolean { return param.any; }

var x:int = 0;
var y:int = 0;
var z:int = 0;
var w:int = 0;
var expect:Boolean = false;
for ( x = 0; x <=1; x++ )
{
    for ( y = 0; y <=1; y++ )
    {
        for ( z = 0; z <=1; z++ )
        {
            for ( w = 0; w <=1; w++ )
            {
                flt4 = new float4(x, y, z, w);
                AddStrictTestCase("flt4.any float4("+x+", "+y+", "+z+", "+w +")", expect, flt4.any);
                AddStrictTestCase("flt4.any float4("+x+", "+y+", "+z+", "+w +") check()", expect, check(flt4));
                // Only the first iteration should produce a false value, all others will be true
                if (!expect) expect = true;
            }
        }
    }
}

test();

