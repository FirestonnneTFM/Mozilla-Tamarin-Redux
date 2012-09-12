/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var CODE = 1118; // Illegal cyclical loop between nodes.

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

var expected = "Error #" + CODE;
var result = "no error";
try {
    var xml:XML =
        <menu>
            <item>burger</item>
            <item>soda</item>
        </menu>;
    xml.insertChildAfter(xml.item[0], xml);
} catch (err) {
    result = grabError(err, err.toString());
} finally {
    AddTestCase("Runtime Error", expected, result);
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
