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