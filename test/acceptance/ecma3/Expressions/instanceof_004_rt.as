/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "instanceof-004_TypeErrors";
var VERSION = "ECMA_2";
var TITLE   = "instanceof"

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var testcases = getTestCases();
test();

function InstanceOf( object_1, object_2, expect, array, item ) {

    try{
        result = object_1 instanceof object_2;
    } catch (e) {
        result = e.toString();
    } finally {
        array[item] = new TestCase(
            SECTION,
            "(" + object_1 + ") instanceof " + object_2,
            expect,
            result);
    }

}
function getTestCases() {
    var array = new Array();
    var item = 0;

// I'm not sure what we expect here yet... All I know is that this needs to be tested...

    function GenB(value) {
        this.value=value;
        this.generation="B";
        this.toString=function(){return "toString";}
    }

    GenB.name = "B";
    GenB.prototype = undefined;

    InstanceOf( new GenB(), GenB, true, array, item++ );
    return array;
}
