/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=616125
*
*/
//-----------------------------------------------------------------------------

var SECTION = "616125";
var VERSION = "";
var TITLE   = "Need coverage around XML.setNotification(function)";
var bug = "616125";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);


var myXML:XML = <foo/>;

myXML.setNotification(notifier1);
myXML.@attrib1 = "foz"; // attributeAdded
function notifier1(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("attributeAdded-command", "attributeAdded", command);
    AddTestCase("attributeAdded-value", "attrib1", value);
    AddTestCase("attributeAdded-detail", "foz", detail);
}

myXML.setNotification(notifier2);
myXML.@attrib1 = "baz"; // attributeChanged
function notifier2(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("attributeChanged-command", "attributeChanged", command);
    AddTestCase("attributeChanged-value", "attrib1", value);
    AddTestCase("attributeChanged-detail", "foz", detail);
}

myXML.setNotification(notifier3);
delete myXML.@attrib1;  // attributeRemoved
function notifier3(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("attributeRemoved-command", "attributeRemoved", command);
    AddTestCase("attributeRemoved-value", "attrib1", value);
    AddTestCase("attributeRemoved-detail", "baz", detail);
}

myXML.setNotification(notifier4);
myXML.appendChild(<node1/>); // nodeAdded
function notifier4(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("nodeAdded-command", "nodeAdded", command);
}

myXML.setNotification(notifier5);
myXML.node1 = <node2/>;      // nodeChanged
function notifier5(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("nodeChanged-command", "nodeChanged", command);
}

myXML.setNotification(notifier6);
delete myXML.node2[0];       // nodeRemoved
function notifier6(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("nodeRemoved-command", "nodeRemoved", command);
}

myXML.setNotification(notifier7);
myXML.appendChild(<node3/>);     // nodeAdded
function notifier7(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("nodeAdded-command", "nodeAdded", command);
}

myXML.setNotification(notifier8);
myXML.node3 = "some text";       // textSet
function notifier8(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("textSet-command", "textSet", command);
}

myXML.setNotification(notifier9);
myXML.node3[0].setName("node4"); //nameSet
function notifier9(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("nameSet-command", "nameSet", command);
}

myXML.setNotification(notifier10);
myXML.setNamespace(new Namespace("fozbaz")); // namespaceSet
function notifier10(targetCurrent:Object, command:String, target:Object, value:Object, detail:Object):void {
    AddTestCase("namespaceSet-command", "namespaceSet", command);
}

// Notifiers MUST be functions or null
var err:String = "no error";
try {
    var strz:String = "string"
    myXML.setNotification(strz);

} catch (e:Error) {
    err = grabError(e, e.toString());
} finally {
    AddTestCase("StringNotifier", "Error #1034", err );
}


test();