/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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