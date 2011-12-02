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

/*
Returns an implementation-dependent approximation to the arc tangent of the
quotient y/x of the arguments y and x, where the signs of y and x are used to
determine the quadrant of the result. Note that it is intentional and traditional
for the two-argument arc tangent function that the argument named y be first and
the argument named x be second. The result is expressed in radians and ranges
from -PI to +PI.
*/

var SECTION = "4.5.19";
var VERSION = "AS3";
var TITLE   = "public function atan2(y:float,x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param1:float, param2:float):float { return float.atan2(param1, param2); }

AddErrorTest("float.atan2() with no args", ARGUMENTERROR+1063,  function(){ float.atan2(); });
AddErrorTest("float.atan2(0) with one args", ARGUMENTERROR+1063,  function(){ float.atan2(0); });

// If either x or y is NaN, the result is NaN.
AddStrictTestCase("float.atan2(0f, string)", float.NaN, float.atan2(0f, "string"));
AddStrictTestCase("float.atan2(string, 0f)", float.NaN, float.atan2("string", 0f));

AddStrictTestCase("float.atan2(0f, undefined)", float.NaN, float.atan2(0f, undefined));
AddStrictTestCase("float.atan2(undefined, 0f)", float.NaN, float.atan2(undefined, 0f));

// If y>0 and x is +0, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan2('1', '0')", float.PI/2f, float.atan2('1', '0'));

// If y>0 and x is -0, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan2('1', '-0')", float.PI/2f, float.atan2('1', '-0'));

test();

