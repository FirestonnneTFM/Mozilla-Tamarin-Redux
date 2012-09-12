/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
   File Name:          tostring.js
   ECMA Section:       Vector.toString()
   Description:        The elements of this object are converted to strings
   and these strings are then concatenated, separated by
   comma characters.  The result is the same as if the
   built-in join method were invoiked for this object
   with no argument.
   Author:             christine@netscape.com 7-Oct-1997
   Updated:            dschaffe@adobe.com 1-Nov-2007
*/

var SECTION = "";
var VERSION = "ECMA_1";
startTest();
var TITLE   = "Vector.toString-initializers";

writeHeaderToLog( SECTION + " "+ TITLE);
 
AddTestCase(
          "new <int>[].toString()",
          "",
          new <int>[].toString() );
AddTestCase(
          "(new Vector.<Boolean>(5)).toString()",
          "false,false,false,false,false",
          (new <Boolean>[false,false,false,false,false,]).toString() );
AddTestCase(
          "(new Vector.<String>(2)).toString()",
          ",",
          (new <String>["","",]).toString() );

AddTestCase(
          "small vector toString",
          "1.1,3.14,99.99",
          new<Number>[1.1,3.14,99.99].toString() );

AddTestCase(
          "default Number values",
          "NaN,NaN",
          new<Number>[NaN,NaN,].toString());
test();
