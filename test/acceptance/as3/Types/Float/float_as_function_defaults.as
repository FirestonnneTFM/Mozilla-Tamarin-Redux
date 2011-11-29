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

var SECTION = "4.3.1";
var VERSION = "AS3";
var TITLE   = "float ( value=0.0f )";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

/*
When the float class object is called as a function, it performs a type conversion and returns a float
value.
4.3.1 float ( value=0.0f )
Returns a float value computed by ToFloat(value).
Note: float(n) is equivalent to new float(n), and both are equivalent to n if n is a float value.
Implementation note:The ABC format has been revised to provide a new convert_f instruction that
implements ToFloat.
*/

var pi_float = float(3.14);
var pi_float_expected1 = 3.14f;
var pi_float_expected2:float = 3.14;
AddTestCase("float as function, with 'double' arg", pi_float_expected1, pi_float);
AddTestCase("float as function, with 'double' arg typed check", pi_float_expected2, pi_float);

var pi_floatf:float = float(3.14);
AddTestCase("typed float as function, with 'double' arg", pi_float_expected1, pi_floatf);
AddTestCase("typed float as function, with 'double' arg typed check", pi_float_expected2, pi_floatf);

var three_float = float(3);
var three_float_expected1 = 3f;
var three_float_expected2:float = 3;
AddTestCase("float as function, with 'int' arg", three_float_expected1, three_float);
AddTestCase("float as function, with 'int' arg typed check", three_float_expected2, three_float);

var three_floatf:float = float(3);
AddTestCase("typed float as function, with 'int' arg", three_float_expected1, three_floatf);
AddTestCase("typed float as function, with 'int' arg typed check", three_float_expected2, three_floatf);

// Note: not testing new float() - it's tested in section 4.4
/* Also - more complete testing of ToFloat() in section 9.2 */

test();

