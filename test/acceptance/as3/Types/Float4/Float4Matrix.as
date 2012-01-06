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
 * Portions created by the Initial Developer are Copyright (C) 2012
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

var SECTION = "";
var VERSION = "AS3";
var TITLE   = "bz bug 708996";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

class Float4Matrix
{
    // public float4 access is the fastest way to get to our rows
    public var row0 : float4;
    public var row1 : float4;
    public var row2 : float4;
    public var row3 : float4;

    public function Float4Matrix ( ) {
        identity();
    }

    public function scale ( x:float, y:float, z:float ):void {
        row0 = float4(x,0.0f,0.0f,0.0f);
        row1 = float4(0.0f,y,0.0f,0.0f);
        row2 = float4(0.0f,0.0f,z,0.0f);
        row3 = float4(0.0f,0.0f,0.0f,1.0f);
    }

    public function identity():void {
        row0 = float4(1.0f,0.0f,0.0f,0.0f);
        row1 = float4(0.0f,1.0f,0.0f,0.0f);
        row2 = float4(0.0f,0.0f,1.0f,0.0f);
        row3 = float4(0.0f,0.0f,0.0f,1.0f);
    }
}

var f4m:Float4Matrix = new Float4Matrix();
f4m.scale(2,3,.4);

AddStrictTestCase("fm4.row0", float4(2,0,0,0), f4m.row0);
AddStrictTestCase("fm4.row1", float4(0,3,0,0), f4m.row1);
AddStrictTestCase("fm4.row2", float4(0,0,0.4000000059604645,0), f4m.row2);
AddStrictTestCase("fm4.row3", float4(0,0,0,1), f4m.row3);

test();