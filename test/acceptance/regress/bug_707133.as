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
* Portions created by the Initial Developer are Copyright (C) 2011
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

var SECTION = "regress_707133";
var VERSION = "AS3";
var TITLE   = "adjusting arrays length should not introduce phantom elements";
var bug = "707133";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

function reducedTestCase()
{
    var a = new Array();
    a.length = 1; // or any semi-small K1; leaves m_denseArray at 0 elems
    a.length = 2; // or any semi-small K2+K1; oldLength = K1, and inserts
                  //   only K2 atomNotFound's instead of K2+K1 such entries.

    var keys = [];
    for (var keyObj:Object in a)
        keys.push(keyObj);
    keys.sort();

    var output="";
    for (var i=0; i < keys.length; i++)
    {
        var val:Object = a[keys[i]];
        output += "<" + keys[i] + ", " + val +">; ";
    }
    return output;
}

function originalTestCase()
{
    var ar:Array = new Array();

    for(var i:int = 0; i < 4; i++)
    {
        var key:String = "keyname_" + i;
        var value:Object = new Object();
        ar[key] = value;
        ar.length++;
    }

    // normalize output by making list of keys and sorting it.
    var keys = [];
    for (var keyObj:Object in ar)
        keys.push(keyObj);
    keys.sort();

    var output = "";
    for (var i=0; i < keys.length; i++)
    {
        var val:Object = ar[keys[i]];
        output += "<" + keys[i] + ", " + val +">; ";
    }
    return output;
}

AddTestCase("reduced test case", "", reducedTestCase());
AddTestCase("original test case",
            ("<keyname_0, [object Object]>; "+
             "<keyname_1, [object Object]>; "+
             "<keyname_2, [object Object]>; "+
             "<keyname_3, [object Object]>; "),
            originalTestCase());

test();
