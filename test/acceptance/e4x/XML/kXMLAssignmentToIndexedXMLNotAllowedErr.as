/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4 XML Object - Assignment to indexed XML not allowed error");

var xml;

xml = new XML("<x><a>1</a><b>2</b><c>3</c></x>");

var expectedStr = "TypeError: Error #1087: Assignment to indexed XML is not allowed.";
var expected = "Error #1087";
var result = "error, exception not thrown";

 

try{

xml[0] = 5;

throw "kXMLAssignmentToIndexedXMLNotAllowed error not thrown";

} catch( e1 ){

result = grabError(e1, e1.toString());
}


AddTestCase("xml[0] = 5", expected, result);

END();

