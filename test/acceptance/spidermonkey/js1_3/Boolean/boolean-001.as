/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

gTestfile = 'boolean-001.js';

/**
 *  File Name:          boolean-001.js
 *  Description:
 *
 *  In JavaScript 1.2, new Boolean(false) evaluates to false.
 *
 *  Author:             christine@netscape.com
 *  Date:               11 August 1998
 */
var SECTION = "boolean-001.js";
var VERSION = "JS_1.3";
var TITLE   = "new Boolean(false) should evaluate to false";

startTest();  var testscases=[]; var index=0;
writeHeaderToLog( SECTION + " "+ TITLE);

AddTestCase( "new Boolean(true)",  new Boolean(true),  true );
AddTestCase( "new Boolean(false)", new Boolean(false), false );
AddTestCase( "true",               true,               true );
AddTestCase( "false",              false,              false );

test();


