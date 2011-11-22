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
New static methods and constants on the Number object should only be
visible to SWF16 and above content.
*/

import avmplus.*;

var SECTION = "Number constants and static methods";
var VERSION = "AS3";
var TITLE   = "";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


if (System.apiVersion < 20)
{
    /*
    If the following do not produce the following error then the constants are not visisble
    and the test is considered passed.
        ReferenceError: Error #1074: Illegal write to read-only property XXX on class Number.
    */
    var num_e:Number = Number.E;
    var num_ln10:Number = Number.LN10;
    var num_ln2:Number = Number.LN2;
    var num_log10e:Number = Number.LOG10E;
    var num_log2e:Number = Number.LOG2E;
    var num_pi:Number = Number.PI;
    var num_sqrt1_2:Number = Number.SQRT1_2;
    var num_sqrt2:Number = Number.SQRT2;

    Number.E = 0;
    Number.LN10 = 0;
    Number.LN2 = 0;
    Number.LOG10E = 0;
    Number.LOG2E = 0;
    Number.PI = 0;
    Number.SQRT1_2 = 0;
    Number.SQRT2 = 0;

    // reset values just in case
    Number.E = num_e;
    Number.LN10 = num_ln10;
    Number.LN2 = num_ln2;
    Number.LOG10E = num_log10e;
    Number.LOG2E = num_log2e;
    Number.PI = num_pi;
    Number.SQRT1_2 = num_sqrt1_2;
    Number.SQRT2 = num_sqrt2;

    AddErrorTest("Number.abs()", TYPEERROR+1006, function(){ var foo = Number.abs(1.2); });
    AddErrorTest("Number.acos()", TYPEERROR+1006, function(){ var foo = Number.acos(1); });
    AddErrorTest("Number.atan()", TYPEERROR+1006, function(){ var foo = Number.atan(1); });
    AddErrorTest("Number.atan2()", TYPEERROR+1006, function(){ var foo = Number.atan2(0, 0); });
    AddErrorTest("Number.ceil()", TYPEERROR+1006, function(){ var foo = Number.ceil(1.1); });
    AddErrorTest("Number.cos()", TYPEERROR+1006, function(){ var foo = Number.cos(1); });
    AddErrorTest("Number.exp()", TYPEERROR+1006, function(){ var foo = Number.exp(1); });
    AddErrorTest("Number.floor()", TYPEERROR+1006, function(){ var foo = Number.floor(1); });
    AddErrorTest("Number.log()", TYPEERROR+1006, function(){ var foo = Number.log(2); });
    AddErrorTest("Number.max()", TYPEERROR+1006, function(){ var foo = Number.max(); });
    AddErrorTest("Number.min()", TYPEERROR+1006, function(){ var foo = Number.min(); });
    AddErrorTest("Number.pow()", TYPEERROR+1006, function(){ var foo = Number.pow(2, 2); });
    AddErrorTest("Number.random()", TYPEERROR+1006, function(){ var foo = Number.random(); });
    AddErrorTest("Number.round()", TYPEERROR+1006, function(){ var foo = Number.round(1.2); });
    AddErrorTest("Number.sin()", TYPEERROR+1006, function(){ var foo = Number.sin(1); });
    AddErrorTest("Number.sqrt()", TYPEERROR+1006, function(){ var foo = Number.sqrt(9); });
    AddErrorTest("Number.tan()", TYPEERROR+1006, function(){ var foo = Number.tan(1); });

}
else // Just make sure that we don't have any errors trying to access to methods/constants
{
    var foo;
    foo = Number.abs(1.2);
    foo = Number.acos(1);
    foo = Number.asin(1);
    foo = Number.atan(1);
    foo = Number.atan2(0, 0);
    foo = Number.ceil(1.1);
    foo = Number.cos(1);
    foo = Number.exp(1);
    foo = Number.floor(1);
    foo = Number.log(2);
    foo = Number.max();
    foo = Number.min();
    foo = Number.pow(2, 2);
    foo = Number.random();
    foo = Number.round(1.2);
    foo = Number.sin(1);
    foo = Number.sqrt(9);
    foo = Number.tan(1);

    AddErrorTest("Number.E - ReadOnly", REFERENCEERROR+1074, function(){ Number.E = 0; });
    AddErrorTest("Number.LN10 - ReadOnly", REFERENCEERROR+1074, function(){ Number.LN10 = 0; });
    AddErrorTest("Number.LN2 - ReadOnly", REFERENCEERROR+1074, function(){ Number.LN2 = 0; });
    AddErrorTest("Number.LOG10E - ReadOnly", REFERENCEERROR+1074, function(){ Number.LOG10E = 0; });
    AddErrorTest("Number.LOG2E - ReadOnly", REFERENCEERROR+1074, function(){ Number.LOG2E = 0; });
    AddErrorTest("Number.PI - ReadOnly", REFERENCEERROR+1074, function(){ Number.PI = 0; });
    AddErrorTest("Number.SQRT1_2 - ReadOnly", REFERENCEERROR+1074, function(){ Number.SQRT1_2 = 0; });
    AddErrorTest("Number.SQRT2 - ReadOnly", REFERENCEERROR+1074, function(){ Number.SQRT2 = 0; });

    // Basically just pass this test, if the above didn't throw an error we are good
    AddTestCase("New Number constants and methods are ok", true, true);
}

test();