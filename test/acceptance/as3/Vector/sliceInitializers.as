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
 * Portions created by the Initial Developer are Copyright (C) 2007-2008
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
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.slice()");

AddTestCase(
        "slice no args on empty vector",
        "",
        new<String>[].slice().toString());

AddTestCase(
    "slice startIndex only",
    "6,7,8,9",
    new<int>[0,1,2,3,4,5,6,7,8,9].slice(6).toString());
    
AddTestCase(
    "slice -1 to -1",
    "",
    new<int>[0,1,2,3,4,5,6,7,8,9].slice(-1,-1).toString());
    
AddTestCase(
    "slice -2 to -1",
    "8",
    new<int>[0,1,2,3,4,5,6,7,8,9].slice(-2,-1).toString());
    
AddTestCase(
    "verify return type",
    true,
    new<Number>[3.14,2.73,9999,.0001,1e13].slice(3,-1) is Vector.<Number>)
    

test();