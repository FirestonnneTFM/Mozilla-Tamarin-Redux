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

var SECTION = "6.4.3";
var VERSION = "AS3";
var TITLE   = "The % operation agumented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var f1:float = 1.2345678e9;
var f2:float = 6.543210987;
 /*
    virgilp: 09/23/2011
    modulo on float & number should THEORETICALLY yield different results
    However, on gcc & VisualC (windows/x86), fmod seems to return identical results with fmodf
    if the input values are identical
    (and no, I didn't get fooled by the "fmod" version with float arguments - I explicitly
    casted the parameters to double)
    I suspect the runtime library implementations perform both operations on 64 bits.
    The thing is, there's no hardware instruction for modulo - except the x87 FPU
    (it has a "FPREM" instruction)
    Bottom line is - the C runtimelibrary makes no diffeernce (not on x86 and x64, Mac/Win, at least)
   */

// ABC Extension spec states that Float modulo can happen in double precision
AddTestCase("modulo on float & number should yield different results", true, (Number(f1)%Number(f2)) == (f1%f2) );

test();

