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
 * Portions created by the Initial Developer are Copyright (C) 2010
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
 * ***** END LICENSE BLOCK *****
 *
* See http://bugzilla.mozilla.org/show_bug.cgi?id=606478
*
*/

var SECTION = "606478";
var VERSION = "AS3";
var TITLE   = "Bug 606478 - Test only works in North America";
var bug = "606478";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();


function getTestCases() {
 
    var array:Array = new Array();
    var status:String = '';
    var actual:String = '';
    var expect:String= '';
    var x:int = 0;

    // Check DST start for 1990-2006 (first sunday in april)
    for (var year=1990; year<=2006; year++) {
        // Get the correct sunday
        var date:Date = new Date(GetFirstSundayInApril(TimeFromYear(year)));
        // set the time to 2 am
        actual = (new Date(date.toLocaleDateString()+" 02:00:00 AM")).toLocaleString();
        status = "new Date("+date.toLocaleDateString()+" 02:00:00 AM)";
        expect = date.toLocaleDateString()+" 03:00:00 AM"
        array[x++] = new TestCase(SECTION, status, expect, actual);
    }
    
    // Check DST start for 2007-2015 (second sunday in march)
    for (var year=2007; year<=2015; year++) {
        // Get the correct sunday
        var date:Date = new Date(GetSecondSundayInMarch(TimeFromYear(year)));
        // set the time to 2 am
        actual = (new Date(date.toLocaleDateString()+" 02:00:00 AM")).toLocaleString();
        status = "new Date("+date.toLocaleDateString()+" 02:00:00 AM)";
        expect = date.toLocaleDateString()+" 03:00:00 AM"
        array[x++] = new TestCase(SECTION, status, expect, actual);
    }

    return array;
}
