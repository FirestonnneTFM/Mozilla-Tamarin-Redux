/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=598683
*
*/
//-----------------------------------------------------------------------------

var SECTION = "598683";
var VERSION = "";
var TITLE   = "Bad XML with unterminated node with namespace not throwing correctly";
var bug = "598683";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {

    var actual:String;
    try
    {
        var xml:XML=new XML("<a><b:c xmlns:b=\"abc\"></d:c></a>") ;
        actual = xml.toXMLString();
    }
    catch(e)
    {
        actual = grabError(e, e.toString());
    }
    
    var expect:String= "Error #1085"; // kXMLUnterminatedElementTag

    var status:String = "new XML(\"<a><b:c xmlns:b=\"abc\"></d:c></a>\")";
    var array = new Array();
    array[0] = new TestCase(SECTION, status, expect, actual);

    return array;
}
