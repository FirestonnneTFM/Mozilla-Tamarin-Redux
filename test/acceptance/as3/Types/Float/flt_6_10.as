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


var SECTION = "6.10";
var VERSION = "AS3";
var TITLE   = "The binary logical operators augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var neg_onef:float = -1f;
var zerof:float = 0f;
var onef:float = 1f;
var ninef:float = 9f;
var tenf:float = 10f;

AddTestCase("void 0 && 1f", undefined, void 0 && onef );
AddTestCase("void 0 && 1f FloatLiteral", undefined, void 0 && 1f );
AddTestCase("null && 1f", null, null && onef );
AddTestCase("null && 1f FloatLiteral", null, null && 1f );
AddTestCase("1f && void 0", undefined, onef && void 0 );
AddTestCase("1f FloatLiteral && void 0", undefined, 1f && void 0 );
AddTestCase("1f && null", null, onef && null );
AddTestCase("1f FloatLiteral && null", null, 1f && null );

AddStrictTestCase("0f && 0f", 0f, zerof && zerof );
AddStrictTestCase("0f FloatLiteral && 0f FloatLiteral", 0f, 0f && 0f );
AddStrictTestCase("1f && 1f", 1f, onef && onef );
AddStrictTestCase("1f FloatLiteral && 1f FloatLiteral", 1f, 1f && 1f );
AddStrictTestCase("-1f && -1f", -1f, neg_onef && neg_onef );
AddStrictTestCase("-1f FloatLiteral && -1f FloatLiteral", -1f, -1f && -1f );

AddStrictTestCase("10f && 9f", 9f, tenf && ninef );
AddStrictTestCase("10f FloatLiteral && 9f FloatLiteral", 9f, 10f && 9f );


AddStrictTestCase("0f && true", 0f, zerof && true );
AddStrictTestCase("0f FloatLiteral && true", 0f, 0f && true );
AddStrictTestCase("true && 0f", 0f, true && zerof );
AddStrictTestCase("true && 0f FloatLiteral", 0f, true && 0f );
AddStrictTestCase("true && 1f", 1f, true && onef );
AddStrictTestCase("true && 1f FloatLiteral", 1f, true && 1f );
AddStrictTestCase("1f && true", true, onef && true );
AddStrictTestCase("1f FloatLiteral && true", true, 1f && true );
AddStrictTestCase("-1f && true", true, neg_onef && true );
AddStrictTestCase("-1f FloatLiteral && true", true, -1f && true );
AddStrictTestCase("true && -1f", -1f, true && neg_onef );
AddStrictTestCase("true && -1f FloatLiteral", -1f, true && -1f );
AddStrictTestCase("true && 10f", 10f, true && tenf );
AddStrictTestCase("true && 10f FloatLiteral", 10f, true && 10f );
AddStrictTestCase("10f && true", true, tenf && true );
AddStrictTestCase("10f FloatLiteral && true", true, 10f && true );
AddStrictTestCase("-1f && true", true, neg_onef && true );
AddStrictTestCase("-1f FloatLiteral && true", true, -1f && true );
AddStrictTestCase("true && float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, true && float.POSITIVE_INFINITY );
AddStrictTestCase("float.NEGATIVE_INFINITY && true", true, float.NEGATIVE_INFINITY && true );
AddTestCase("float.NaN && float.NaN", float.NaN,  float.NaN && float.NaN );
AddTestCase("float.NaN && 0f", float.NaN,  float.NaN && 0f );
AddTestCase("0f && float.NaN", 0f,  0f && float.NaN );
AddTestCase("flaot.NaN && float.POSITIVE_INFINITY", float.NaN,  float.NaN && float.POSITIVE_INFINITY );
AddTestCase("float.POSITIVE_INFINITY && float.NaN", float.NaN,  float.POSITIVE_INFINITY && float.NaN );



AddTestCase("void 0 || 1f", 1f, void 0 || onef );
AddTestCase("void 0 || 1f FloatLiteral", 1f, void 0 || 1f );
AddTestCase("null || 1f", 1f, null || onef );
AddTestCase("null || 1f FloatLiteral", 1f, null || 1f );
AddTestCase("1f || void 0", 1f, onef || void 0 );
AddTestCase("1f FloatLiteral || void 0", 1f, 1f || void 0 );
AddTestCase("1f || null", 1f, onef || null );
AddTestCase("1f FloatLiteral || null", 1f, 1f || null );

AddStrictTestCase("0f || 0f", 0f, zerof || zerof );
AddStrictTestCase("0f FloatLiteral || 0f FloatLiteral", 0f, 0f || 0f );
AddStrictTestCase("1f || 1f", 1f, onef || onef );
AddStrictTestCase("1f FloatLiteral || 1f FloatLiteral", 1f, 1f || 1f );
AddStrictTestCase("-1f || -1f", -1f, neg_onef || neg_onef );
AddStrictTestCase("-1f FloatLiteral || -1f FloatLiteral", -1f, -1f || -1f );

AddStrictTestCase("10f || 9f", 10f, tenf || ninef );
AddStrictTestCase("10f FloatLiteral || 9f FloatLiteral", 10f, 10f || 9f );


AddStrictTestCase("1f || true", 1f, onef || true );
AddStrictTestCase("1f FloatLiteral || true", 1f, 1f || true );
AddStrictTestCase("0f || true", true, zerof || true );
AddStrictTestCase("0f FloatLiteral || true", true, 0f || true );
AddStrictTestCase("true || 0f", true, true || zerof );
AddStrictTestCase("true || 0f FloatLiteral", true, true || 0f );
AddStrictTestCase("true || 1f", true, true || onef );
AddStrictTestCase("true || 1f FloatLiteral", true, true || 1f );
AddStrictTestCase("1f || true", 1f, onef || true );
AddStrictTestCase("1f FloatLiteral || true", 1f, 1f || true );
AddStrictTestCase("-1f || true", -1f, neg_onef || true );
AddStrictTestCase("-1f FloatLiteral || true", -1f, -1f || true );
AddStrictTestCase("true || -1f", true, true || neg_onef );
AddStrictTestCase("true || -1f FloatLiteral", true, true || -1f );
AddStrictTestCase("true || 10f", true, true || tenf );
AddStrictTestCase("true || 10f FloatLiteral", true, true || 10f );
AddStrictTestCase("10f || true", 10f, tenf || true );
AddStrictTestCase("10f FloatLiteral || true", 10f, 10f || true );
AddStrictTestCase("-1f || true", -1f, neg_onef || true );
AddStrictTestCase("-1f FloatLiteral || true", -1f, -1f || true );
AddStrictTestCase("true || float.POSITIVE_INFINITY", true, true || float.POSITIVE_INFINITY );
AddStrictTestCase("float.NEGATIVE_INFINITY || true", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY || true );
AddTestCase("float.NaN || float.NaN", float.NaN,  float.NaN || float.NaN );
AddTestCase("float.NaN || 0f", 0f,  float.NaN || 0f );
AddTestCase("0f || float.NaN", float.NaN,  0f || float.NaN );
AddStrictTestCase("flaot.NaN || float.POSITIVE_INFINITY", float.POSITIVE_INFINITY,  float.NaN || float.POSITIVE_INFINITY );
AddStrictTestCase("float.POSITIVE_INFINITY || float.NaN", float.POSITIVE_INFINITY,  float.POSITIVE_INFINITY || float.NaN );

test();
