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

var SECTION = "4.3";
var VERSION = "AS3";
var TITLE   = "The float class object called as a function";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

/*
When the float class object is called as a function, it performs a type conversion and returns a float
value.
*/


var undefined_float = float(undefined);
AddTestCase("Float as function, with 'undefined' arg", "float", getQualifiedClassName(undefined_float));

var null_float = float(null);
AddTestCase("Float as function, with 'null' arg", "float", getQualifiedClassName(null_float));

var boolean_float = float(true);
AddTestCase("Float as function, with 'boolean' arg", "float", getQualifiedClassName(boolean_float));

var dble_float = float(3.14);
AddTestCase("Float as function, with 'double' arg", "float", getQualifiedClassName(dble_float));

var int_float = float(3);
AddTestCase("Float as function, with 'int' arg", "float", getQualifiedClassName(int_float));

var string_float = float("3.14");
AddTestCase("Float as function, with 'String' arg", "float", getQualifiedClassName(string_float));

var myObject:Object = {1:1};
var object_float = float(myObject);
AddTestCase("Float as function, with 'Object' arg", "float", getQualifiedClassName(object_float));

var literal_float = float(3.14f);
AddTestCase("Float as function, with 'FloatLiteral' arg", "float", getQualifiedClassName(literal_float));


// Note: not testing new float() - it's tested in section 4.4
/* Also - more complete testing of ToFloat() in section 9.2 */

test();

