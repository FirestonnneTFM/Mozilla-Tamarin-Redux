/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4 XML Object - XML markup must be well-formed Error");

var xml;
var expectedStr = "TypeError: Error #1088: The markup in the document following the root element must be well-formed.";
var expected = "Error #1088";

var result = "error, exception not thrown";

 

try{

xml = new XML("<root><a><b>c</b></a></root></root>");
throw "kXMLMarkupMustBeWellFormed error not thrown";

} catch( e1 ){

result = grabError(e1, e1.toString());

}

AddTestCase( "new XML(\"<root><a><b>c</b></a></root></root>\")", expected, result );

expected = "TypeError: Error #1088: XML parser failure: element is malformed";

// This needs to be a compiler error test case.
/*
try{

xml =
<root>
<blah a="attr"
hi
</blah>
</root>;

throw "element malformed error";

} catch( e2 ){

result = e2.toString();

}

AddTestCase( "new XML(\"<root><blah a=\"attr\"hi</blah></root>\")", expected, result );
*/
END();

