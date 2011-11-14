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

var SECTION = "5.5.2";
var VERSION = "AS3";
var TITLE   = "Vector.<float4> smoketest";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

// Vector.<float4> smoketest.  Tests that vectors are initialized to
// zero, that reading and writing works, that the data written can be
// read again, and that we're not scribbling on memory.
//
// Run this with -Ojit and -Dinterp in a Debug build; the debugging
// functionality in MMgc will catch memory overwrites, should they
// occur.
//
// We test for a lot of different vector lengths, and with and without
// type information, in order to test more JIT and runtime paths.

// Global code, no annotations 

for ( var i=0 ; i < 100 ; i++ ) {
	var w = new Vector.<float4>(i);
	AddTestCase("Global: length", i, w.length);
	for ( var j=0 ; j < i ; j++ )
		AddTestCase("Global: zero", float4(0,0,0,0), w[j]);
	for ( var j=0 ; j < i ; j++ )
		w[j] = float4(1000+i, 2000+i, 3000+i, 4000+i);
	for ( var j=0 ; j < i ; j++ )
		AddTestCase("Global: read", float4(1000+i, 2000+i, 3000+i, 4000+i), w[j]);
}

// Function code, full annotations

function f(): void 
{
	for ( var i:int=0 ; i < 100 ; i++ ) {
		var w:Vector.<float4> = new Vector.<float4>(i);
		var j:int;
		AddTestCase("Local: length", i, w.length);
		for ( j=0 ; j < i ; j++ )
			AddTestCase("Local: zero", float4(0,0,0,0), w[j]);
		for ( j=0 ; j < i ; j++ )
			w[j] = float4(1000+i, 2000+i, 3000+i, 4000+i);
		for ( j=0 ; j < i ; j++ )
			AddTestCase("Local: read", float4(1000+i, 2000+i, 3000+i, 4000+i), w[j]);
	}
}

f();

test();
