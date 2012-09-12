/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'toString-001.js';

/**
   File Name:          toString_1.js
   ECMA Section:       Object.toString()
   Description:

   This checks the ToString value of Object objects under JavaScript 1.2.

   In JavaScript 1.2, Object.toString()

   Author:             christine@netscape.com
   Date:               12 november 1997
*/

var SECTION = "JS1_2";
var VERSION = "JS1_2";
startTest();  var testscases=[]; var index=0;
var TITLE   = "Object.toString()";

writeHeaderToLog( SECTION + " "+ TITLE);

var o = new Object();

testcases[index++] = new TestCase( SECTION,
          "var o = new Object(); o.toString()",
          "[object Object]",
          o.toString() );

o = {};

testcases[index++] = new TestCase( SECTION,
          "o = {}; o.toString()",
          "[object Object]",
          o.toString() );


o = { name:"object", length:0, value:"hello",
      toString:function (){return this.value+''} }

  testcases[index++] = new TestCase( SECTION,
        "o = { name:\"object\", length:0, value:\"hello\", "+
        "toString:new Function( \"return this.value+''\" ) }; o.toString()",
        "hello",
        o.toString() );



test();



