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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

var SECTION = "";       // provide a document reference (ie, Actionscript section)
var VERSION = "";        // Version of ECMAScript or ActionScript 
var TITLE   = "Surrogate pairs are mangled by String.Replace";       // Provide ECMA section title or a description
var BUGNUMBER = "439458";

startTest();                // leave this alone

// add your tests here

var text:String = String.fromCharCode(0xD840, 0xDC0B);
var dblSpacePattern:RegExp = /[\s]{2,}/g;
var strippedText:String = text.replace(dblSpacePattern, " ");
AddTestCase( "strippedText.charCodeAt(0).toString(16)", "d840", strippedText.charCodeAt(0).toString(16) );
AddTestCase( "strippedText.charCodeAt(1).toString(16)", "dc0b", strippedText.charCodeAt(1).toString(16) );
AddTestCase( "strippedText.charCodeAt(2).toString(16)", "NaN", strippedText.charCodeAt(2).toString(16) );
AddTestCase( "strippedText.charCodeAt(3).toString(16)", "NaN", strippedText.charCodeAt(3).toString(16) );
AddTestCase( "strippedText==text", true, strippedText==text );


test();       // leave this alone.  this executes the test cases and
              // displays results.

