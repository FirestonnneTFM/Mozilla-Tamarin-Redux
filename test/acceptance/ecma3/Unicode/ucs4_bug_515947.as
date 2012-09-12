/*
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/**
 *  This template is a modified version of the test case
 *  templates taken from mozilla.org.  This template or
 *  any test cases written from it are not for external
 *  use or distribution.
 *
 *  Author: Brent Baker <brbaker@adobe.com>
 *  Date: 10/06/2009
 *
 *  Modifications: (Name   :Date)

 */

var SECTION = "Unicode";       // provide a document reference (ie, Actionscript section)
var VERSION = "ECMAScript";        // Version of ECMAScript or ActionScript
var TITLE   = "UTF16 surrogate pairs not being translated correctly from UTF8";
var BUGNUMBER = "515947";

startTest();                // leave this alone

// add your tests here

var s:String = "í¡€í²Š";
AddTestCase( "s.length", 2, s.length );
AddTestCase( "0xd840", "d840", s.charCodeAt(0).toString(16) );
AddTestCase( "0xdc8a", "dc8a", s.charCodeAt(1).toString(16) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
              



