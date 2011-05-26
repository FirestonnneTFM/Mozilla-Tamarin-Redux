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


var SECTION = "4.2";
var VERSION = "AS3";
var TITLE   = "Literal syntax";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

/*
The NumericLiteral rule of the lexical grammar (lines 160-161) is extended as follows:
NumericLiteral
...
FloatLiteral
FloatLiteral
DecimalLiteral f
The letter f is the Unicode letter "LATIN-SMALL-LETTER-F", code point 102. (As is normal in the
lexical grammar, no white space or other token separator is allowed between DecimalLiteral and the
letter f.)
For example,
1f
31.4159e-1f
Note: The suffix f appears only in the surface lexical syntax. It is not understood by ToNumeric or
ToFloat. It is not produced by any function that converts a float to a string, notably ToString. Finally,
it is not understood by the parseFloat operator (where it would break backward compatibility by
returning a non-Number for a number value that happened to be followed by the character f, where
that f would previously be uninterpreted). See the rationale for a longer discussion of these issues.
Implementation note: The ABC format has been revised to provide a section for float constant values
as well as a pushfloat instructions.
*/


var one_f = 1f;
var one_float:float = float(1);
AddTestCase("literal 1f", one_float, one_f);

var pi_f = 31.4159e-1f;
var pi_float:float = float(31.4159e-1);
AddTestCase("Literal 31.4159e-1f", pi_float, pi_f);

/* The "Note" is tested in section 9.8 (operation ToString) and 9.2 (operation ToFloat),
   as well as section 11 (parseFloat). We don't add specific testcases here. */

test();

