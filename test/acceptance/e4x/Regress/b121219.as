/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
START("QName in nested functions");

var bug = 121219;
var actual = "";
var expect = "no error";

function doFrame() {
    function nestedFunc(a, b, c) {
    }
    
    x1 =
    <alpha>
    <bravo attr1="value1" ns:attr1="value3" xmlns:ns="http://someuri">
    <charlie attr1="value2" ns:attr1="value4"/>
    </bravo>
    </alpha>

    var n = new Namespace("http://someuri");

    q = new QName(n, "attr1");
    nestedFunc(7, "value3value4", x1..@[q]);

    var xml1 = "<c><color c='1'>pink</color><color c='2'>purple</color><color c='3'>orange</color></c>";
    var placeHolder = "c";

    nestedFunc("x1.node1[i].@attr", "1",( x2 = new XML(xml1), x2.color[0].@c.toString()));
}

try {
    doFrame();
    actual = "no error";
} catch(e1) {
    actual = "error thrown: " + e1.toString();
}
    


AddTestCase("QName in nested function", expect, actual);

END();
