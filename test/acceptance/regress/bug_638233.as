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
* Portions created by the Initial Developer are Copyright (C) 2008
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

var SECTION = "regress_638233";
var VERSION = "AS3";
var TITLE   = "constructProperty for primitive types";
var bug = "638233";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

namespace ns = "fnord"

var testnum = 1;
AddErrorTest(testnum++, "TypeError: Error #1007", function() { var a = 1; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1007", function() { var a = 3.1415; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1007", function() { var a = true; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1007", function() { var a = "string"; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1007", function() { var a = ns; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1009", function() { var a = null; new a.foo(); });
AddErrorTest(testnum++, "TypeError: Error #1010", function() { var a = undefined; new a.foo(); });

Number.prototype.foo = Number;
int.prototype.foo = int;
uint.prototype.foo = uint;

var a = 1;
AddTestCase(testnum++, 0, new a.foo());

var a = 3.1415;
AddTestCase(testnum++, 0, new a.foo());

Boolean.prototype.foo = Boolean;
var a = true;
AddTestCase(testnum++, false, new a.foo());

String.prototype.foo = String;
var a = "string";
AddTestCase(testnum++, "", new a.foo());

// ugly trick: not sure how to obtain the namespace that "new Namespace",
// so use "Number" here instead and test against that.
Namespace.prototype.foo = Number;
var a = ns;
AddTestCase(testnum++, 0, new a.foo());


test();
