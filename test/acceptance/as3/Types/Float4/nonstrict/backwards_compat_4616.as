/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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


