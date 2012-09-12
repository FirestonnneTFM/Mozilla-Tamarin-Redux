/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=588041
*
*/
//-----------------------------------------------------------------------------

var SECTION = "588041";
var VERSION = "";
var TITLE   = "ToXMLList from XML object does not correctly set XMLListObject::m_targetObject ";
var bug = "588041";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {

    var listOrig:XMLList = <><item>1</item></>;
    var listCopy:XMLList = <></>;
    listCopy += XMLList(listOrig[0]);
    listCopy[0] += <item>2</item>;


    var array:Array = new Array();
    var status:String = '';
    var actual:String = '';
    var expect:String= '';

    status = "listCopy[0] += <item>2</item>";
    expect = '<item>1</item>\n<item>2</item>';
    actual = listCopy.toXMLString();
    array[0] = new TestCase(SECTION, status, expect, actual);

    return array;
}
