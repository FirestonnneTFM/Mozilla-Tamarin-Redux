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


var SECTION = "6.3.8";
var VERSION = "AS3";
var TITLE   = "The prefix ++ operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var flt:float = new float(3.1413119f);
var flt_plus_1 = flt + 1.0f;
AddStrictTestCase("prefix ++ on float", flt_plus_1, ++flt);
AddStrictTestCase("prefix ++ on float", flt_plus_1, flt);
var u = flt;
AddTestCase("prefix ++ on float value should produce float value", "float", getQualifiedClassName(++u));


/*
++12.375f
-> int rep of memory 1096155136
-> 13.375 double is
01000000 00101010 11000000 00000000
00000000 00000000 00000000 00000000


12.375f
(12.375)10 =
(12)10 + (0.375)10 =
(1100)2 + (0.011)2 =
(1100.011)2 =
(1.100011)2 x2^3
sign = 0
exponent = 130 (127 biased, 127 +3, binary 1000 0010)
fraction = 100011
0-10000010-10001100000000000000000
01000001 01000110 00000000 00000000 -> int 1095106560


13.375f
(13.375)10 =
(13)10 + (0.375)10 =
(1101)2 + (0.011)2 =
(1101.011)2 =
(1.101011)2 x2^3
sign = 0
exponent = 130 (127 biased, 127 +3, binary 1000 0010)
fraction = 101011
0-10000010-10101100000000000000000
01000001 01010110 00000000 00000000 -> int 1096155136

*/


flt = new float(12.375f);
var flt_as_int = 1095106560;
var flt_plus_1_as_int = 1096155136;
AddTestCase("verify float bits", flt_as_int, FloatRawBits(flt));
AddTestCase("verify ++float is correct int representation", flt_plus_1_as_int, FloatRawBits(++flt));


flt = float.MAX_VALUE;
AddStrictTestCase("++float.MAX_VALUE", float.MAX_VALUE, ++flt);
flt = float.MIN_VALUE;
AddStrictTestCase("++float.MIN_VALUE", 1f, ++flt);
flt = float.POSITIVE_INFINITY;
AddStrictTestCase("++float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, ++flt);
flt = float.NEGATIVE_INFINITY;
AddStrictTestCase("++float.NEGATIVE_INFINITY", float.NEGATIVE_INFINITY, ++flt);


test();

