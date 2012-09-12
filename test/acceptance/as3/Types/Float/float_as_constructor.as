/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.4";
var VERSION = "AS3";
var TITLE   = "The float class object called as a constructor";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

/*
4.4 The 'float' class object called as a constructor
When the float class object is called as part of a new expression it is a constructor: it it returns a float
value.
*/


var result = new float();
AddTestCase("Float constructor with no args", "float", getQualifiedClassName(result));

var undefined_float = new float(undefined);
AddTestCase("Float constructor, with 'undefined' arg", "float", getQualifiedClassName(undefined_float));

var null_float = new float(null);
AddTestCase("Float constructor, with 'null' arg", "float", getQualifiedClassName(null_float));

var boolean_float = new float(true);
AddTestCase("Float constructor, with 'boolean' arg", "float", getQualifiedClassName(boolean_float));

var dble_float = new float(3.14);
AddTestCase("Float constructor, with 'double' arg", "float", getQualifiedClassName(dble_float));

var int_float = new float(3);
AddTestCase("Float constructor, with 'int' arg", "float", getQualifiedClassName(int_float));

var string_float = new float("3.14");
AddTestCase("Float constructor, with 'String' arg", "float", getQualifiedClassName(string_float));

var myObject:Object = {1:1};
var object_float = new float(myObject);
AddTestCase("Float constructor, with 'Object' arg", "float", getQualifiedClassName(object_float));

var literal_float = new float(3.14f);
AddTestCase("Float constructor, with 'FloatLiteral' arg", "float", getQualifiedClassName(literal_float));


test();

