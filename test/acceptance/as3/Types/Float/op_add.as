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

var SECTION = "6.5.1";
var VERSION = "AS3";
var TITLE   = "The + operation agumented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var f1:float = 1.2345678e9;
var f2:float = 6.543210987;
f2 *= float(10000); // TODO: use 10000f

AddTestCase("float addition result", float(1.234633216e+09), f1+f2);
AddTestCase("FloatLiteral addition result", float(1.234633216e+09), 1.2345678e9f+65432.10987f);
AddTestCase("addition on float & number should yield different results", true, (Number(f1)+Number(f2)) != Number(f1+f2) );
AddTestCase("additiom of 2 floats returns a float", "float", getQualifiedClassName(f1+f2));

function check(val1:*, val2:*):*
{
    return (val1 + val2);
}
var onef:float = 1f;
AddStrictTestCase("float + Number", 2, check(onef, 1));
AddStrictTestCase("FloatLiteral + Number", 2, check(1f, 1));
AddStrictTestCase("Number + float", 2, check(1, onef));
AddStrictTestCase("Number + FloatLiteral", 2, check(1, 1f));
AddStrictTestCase("Boolean + float", 2, check(true, onef));
AddStrictTestCase("String + float", String("11"), check("1", onef));



test();

