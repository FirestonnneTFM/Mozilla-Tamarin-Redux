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

/*
Returns a float value with positive sign, greater than or equal to 0 but less
than 1, chosen randomly or pseudo randomly with approximately uniform distribution
over that range, using an implementation-dependent algorithm or strategy. This
function takes no arguments.
*/

var SECTION = "4.5.28";
var VERSION = "AS3";
var TITLE   = "public function random():float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddStrictTestCase("float.random() returns a float", "float", getQualifiedClassName(float.random()));
AddStrictTestCase("float.random() length is 0", 0, float.random.length);
AddErrorTest("float.random() with args", ARGUMENTERROR+1063,  function(){ float.random(12); });

var myRandom:float;
for (var x:int = 0; x < 1000; x++)
{
    myRandom = float.random();
    if ( myRandom < 0f)
        AddTestCase("float.random() illegal value returned", "<0f", myRandom);
    if ( myRandom > 1f)
        AddTestCase("float.random() illegal value returned", ">1f", myRandom);
}


test();

