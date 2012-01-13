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

var SECTION = "ABC Ext 5.3";
var VERSION = "AS3";
var TITLE   = "The float4 backwards compatability, 46.16 exposed to float4";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var f4:* = float4(float(1));
AddTestCase("typeof f4", "float4", typeof f4);
AddTestCase("f4 is float4", true, f4 is float4);
AddTestCase("f4 as float4", f4, f4 as float4);
AddTestCase("typeof f4+f4 is number", "number", typeof op(f4, f4, "add"));
AddTestCase("typeof f4-f4 is number", "number", typeof op(f4, f4, "minus"));
AddTestCase("typeof f4*f4 is number", "number", typeof op(f4, f4, "multiply"));
AddTestCase("typeof f4/f4 is number", "number", typeof op(f4, f4, "divide"));
AddTestCase("typeof f4%f4 is number", "number", typeof op(f4, f4, "modulo"));
AddTestCase("typeof ++f4 is number", "number", typeof op(f4, f4, "prefixplus"));
AddTestCase("typeof --f4 is number", "number", typeof op(f4, f4, "prefixminus"));
AddTestCase("typeof f4++ is number", "number", typeof op(f4, f4, "postfixplus"));
AddTestCase("typeof f4-- is number", "number", typeof op(f4, f4, "postfixminus"));
AddTestCase("typeof -f4 is number", "number", typeof op(f4, f4, "negate"));
AddTestCase("typeof +f4 is number", "number", typeof op(f4, f4, "unplus"));

var f42:float4 = float4(float(1.1), float(2.2), float(3.3), float(4.4));
AddTestCase("typeof f4['x']", "float", typeof f4['x']);
AddTestCase("typeof f4['y']", "float", typeof f4['y']);
AddTestCase("typeof f4['z']", "float", typeof f4['z']);
AddTestCase("typeof f4['w']", "float", typeof f4['w']);
AddTestCase("typeof f4['xyzw']", "float4", typeof f4['xyzw']);

function op(param1:*, param2:*, op:String):*
{
    AddTestCase("typeof param1 >> "+op, "float4", typeof param1);
    var result:*;
    switch (op)
    {
        case "add":
            result = param1 + param2;
            break;
        case "minus":
            result = param1 - param2;
            break;
        case "multiply":
            result = param1 * param2;
            break;
        case "divide":
            result = param1 / param2;
            break;
        case "modulo":
            result = param1 % param2;
            break;
        case "prefixplus":
            result = ++param1;
            break;
        case "prefixminus":
            result = --param1;
            break;
        case "postfixplus":
            result = param1++;
            break;
        case "postfixminus":
            result = param1--;
            break;
        case "negate":
            result = -param1;
            break;
        case "unplus":
            result = +param1;
            break;
    }
    return result;
}


test();


