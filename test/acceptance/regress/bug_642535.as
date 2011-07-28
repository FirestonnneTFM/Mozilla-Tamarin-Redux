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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
 */

var SECTION = "regress_642535";
var VERSION = "AS3";
var TITLE   = "optimization incorrectly performs signed integer division on unsigned numbers";
var bug = "642535";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

function hide(x:Number):Number { return x; }

// We optimize certain cases of division when the result is coerced to int/uint and the rhs is a constant.

var x1 : uint = 0xffffffff;
x1 /= 3;

var x2 : uint = 0xffffffff;
x2 /= -3;

var y1 : uint = 0xffffffff;
y1 /= 32;

var y2 : uint = 0xffffffff;
y2 /= -32;

var z1 : uint = 0xffffffff;
z1 /= 0xffffffff;

var z2 : int = -1;
z2 /= 0xffffffff;

// Dividend is sufficiently large to appear negative if treated as signed.

AddTestCase("var x1:uint = 0xffffffff; x1 /= 3",   uint(hide(0xffffffff / 3)),   x1);
AddTestCase("var x2:uint = 0xffffffff; x2 /= -3",  uint(hide(0xffffffff / -3)),  x2);

AddTestCase("var y1:uint = 0xffffffff; y1 /= 32",   uint(hide(0xffffffff / 32)),   y1);
AddTestCase("var y2:uint = 0xffffffff; y2 /= -32",  uint(hide(0xffffffff / -32)),  y2);

// Divisor is sufficiently large to appear negative if treated as signed.

AddTestCase("var z1:uint = 0xffffffff; z1 /= 0xffffffff", uint(hide(0xffffffff / 0xffffffff)), z1);
AddTestCase("var z2:int = -1; z2 /= 0xffffffff", int(hide(-1 / 0xffffffff)), z2);

// Only one bit set, but number is negative.  Don't optimize this divisor as a shift!

var w1 : uint = 0xffffffff;
w1 /= -2147483648;

var w2 : int = -1;
w2 /= -2147483648;

AddTestCase("var w1:uint = 0xffffffff; w1 /= -2147483648", uint(hide(0xffffffff / -2147483648)), w1);
AddTestCase("var w2:int = -1; w2 /= -2147483648", int(hide(-1 / -2147483648)), w2);

test();
