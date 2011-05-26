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


var SECTION = "5.2.2";
var VERSION = "AS3";
var TITLE   = "The / operation agumented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


/*
If Type(w1) is float4 or Type(w2) is float4:
Let z1=ToFloat4(w1)
Let z2=ToFloat4(w2)
Let value3=z1 * z2 where * is float4 multiply
Goto PUSH
*/

var f1:float4 = float4(2f, 6f, 9f, 16f);
var f2:float4 = float4(1f, 2f, 3f, 4f);

function check(val1:*, val2:*):*
{
    return (val1 / val2);
}

AddStrictTestCase("float4 / float4", new float4(2f, 3f, 3f, 4f), f1 / f2);
AddStrictTestCase("float4 / float4", new float4(2f, 3f, 3f, 4f), check(f1, f2));

AddStrictTestCase("float4 / float", new float4(2f, 6f, 9f, 16f), f1 / float(1f));
AddStrictTestCase("float4 / float check()", new float4(2f, 6f, 9f, 16f), check(f1, float(1f)));

AddStrictTestCase("float / float4", new float4(2f/2f, 2f/6f, 2f/9f, 2f/16f), float(2f) / f1);
AddStrictTestCase("float / float4 check()", new float4(1f/2f, 1f/6f, 1f/9f, 1f/16f), check(float(1f), f1));

test();

