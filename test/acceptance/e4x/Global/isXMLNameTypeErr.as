/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.1.2.1 isXMLName - Passing object to isXMLName() TypeError");

var expectedStr = "TypeError: Error #1050";
var result = "error, exception not thrown";
var expected = "Error #1050";

var object1 = { toString: function() { return this; } };

try{

isXMLName(object1);

throw "TypeError not thrown";

} catch( e1 ){

    result = grabError(e1, e1.toString());
}


AddTestCase("var object1 = { toString: function() { return this; } }; isXMLName(object1)", expected, result);


// Check indirect throw of TypeError
var object2 = { toString: function() { return String(object1); } }

try{

isXMLName(object2);

throw "TypeError not thrown";

} catch( e2 ){

    grabError(e2, e2.toString());

}


AddTestCase("var object2 = { toString: function() { return String(object1); } }; isXMLName(object2)", expected, result);



END();

