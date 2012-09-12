/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
