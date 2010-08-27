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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=564468
*
*/
//-----------------------------------------------------------------------------

var SECTION = "564468";
var VERSION = "";
var TITLE   = " XMLParser need to use caseless compares for ?XML and CDATA tags";
var bug = "564468";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);


// Unable to access xml declaration node via AS code so instead cause an
// XMLParser::kUnterminatedXMLDeclaration error to be thrown by XMLParser.getNext().
// Prior to this fix this code would throw an XMLParser::kUnterminatedProcessingInstruction
// error was thrown since it fell into the "<?" processing instruction check block
var err:String = "no error";
try {
    var y:String = "<?xml version='1.0'?";
    var z:XML = new XML(y);
} catch (e:Error) {
    err = grabError(e, e.toString());
} finally {
    AddTestCase("lowercase xml", "Error #1092", err );
}

err = "no error";
try {
    var y:String = "<?XML version='1.0'?";
    var z:XML = new XML(y);
} catch (e:Error) {
    err = grabError(e, e.toString());
} finally {
    AddTestCase("uppercase xml", "Error #1092", err );
}

err = "no error";
try {
    var y:String = "<?Xml version='1.0'?";
    var z:XML = new XML(y);
} catch (e:Error) {
    err = grabError(e, e.toString());
} finally {
    AddTestCase("mixed xml", "Error #1092", err );
}


var lowerdata:String = "<text><![cdata[ This <> is some cdata!]]></text>";
var lowerCDATA:XML = new XML(lowerdata);
AddTestCase("lower CDATA", "<text><![CDATA[ This <> is some cdata!]]></text>", lowerCDATA.toXMLString() );

var mixeddata:String = "<text><![Cdata[ This <> is some cdata!]]></text>";
var mixedCDATA:XML = new XML(mixeddata);
AddTestCase("mixed CDATA", "<text><![CDATA[ This <> is some cdata!]]></text>", mixedCDATA.toXMLString() );

var upperdata:String = "<text><![CDATA[ This <> is some cdata!]]></text>";
var upperCDATA:XML = new XML(upperdata);
AddTestCase("upper CDATA", "<text><![CDATA[ This <> is some cdata!]]></text>", upperCDATA.toXMLString() );

test();