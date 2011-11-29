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
/**
   Description:  The elements of this object are converted to strings and
   these strings are then concatenated, separated by comma
   characters. The result is the same as if the built-in join
   method were invoiked for this object with no argument.
   */

var SECTION = "Vector";
var VERSION = "Bug 678983";
startTest();

writeHeaderToLog( SECTION + " fixed length");

function g(x) : Number { return x }
var err:String = "";

// -Dinterp avmplus::TypedVectorObject<TLIST>::checkWriteIndex_u(uint32_t) const
// -Ojit avmplus::TypedVectorObject<TLIST>::checkWriteIndex_d(double) const

err = "???"
try {
    var v:Vector.<*> = new Vector.<*>(10,true);
    var x:Number;
    x = 90;
    v[g(x)/10] = 'p';
    x = 100;
    v[g(x)/10] = 'p';
} catch (e) {
    err = e.toString();
}
// avmplus::TypedVectorObject<TLIST>::checkWriteIndex_d(double) const
AddTestCase("Vector fixed RangeError",
            "RangeError: Error #1125",
             err.substring(0,23));


err = "???"
try {
    var v:Vector.<*> = new Vector.<*>(10,true);
    var x:Number;
    x = 90;
    v[g(x)/10.1] = 'p';
} catch (e) {
    err = e.toString();
}
// avmplus::TypedVectorObject<TLIST>::checkWriteIndex_d(double) const
AddTestCase("Vector fixed RangeError: double(index_i) != index",
            "RangeError: Error #1125",
             err.substring(0,23));

err = "???"
try {
    var v:Vector.<*> = new Vector.<*>(10,true);
    var x:Number;
    x = 90;
    v[-g(x)/10] = 'p';
} catch (e) {
    err = e.toString();
}
// avmplus::TypedVectorObject<TLIST>::checkWriteIndex_d(double) const
AddTestCase("Vector fixed RangeError: index_i < 0",
            "RangeError: Error #1125",
             err.substring(0,23));


err = "???"
try {
    var v:Vector.<*> = new Vector.<*>(10,true);
    var x:Number;
    x = 90;
    var foo = v[g(x)/10];
    x = 100;
    var foo = v[g(x)/10];
} catch (e) {
    err = e.toString();
}
AddTestCase("Vector fixed RangeError checkReadIndex_d",
            "RangeError: Error #1125",
             err.substring(0,23));

test();
