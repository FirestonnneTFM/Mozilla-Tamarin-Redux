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

var SECTION = "6.3.6";
var VERSION = "AS3";
var TITLE   = "The bitwise not ~ operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var flt:float = new float(3.1413119f);
AddStrictTestCase("bitwise not on float", ~3, ~flt);

// float 12.375f in binary 01000001010001100000000000000000
// bitwise NOT of memory   10111110101110011111111111111111
// int value of memory     -1095106561
// ~12.375f should be bitwise NOT of 12
// 12 in binary            00000000 00000000 00000000 00001100
// bitwise NOT of 13       11111111 11111111 11111111 11110011
// int value of memory     -13
flt = 12.375f;
AddStrictTestCase("ToInt32 of float value instead of float memory representation", true, Number(~flt) != -1095106561);
AddStrictTestCase("~12.375f ", ~12, ~flt);

test();

