/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4 XML Object - XML prefix not bound error");

var xml;
expectedStr = "TypeError: Error #1083: The prefix \"ns\" for element \"ns:x\" is not bound.";
expected = "Error #1083";
result = "error, exception not thrown";

try{

xml = new XML("<ns:x><a>1</a><a>2</a><a>3</a></ns:x>");
throw new Error("kXMLPrefixNotBound error not thrown");

} catch( e1 ){

result = grabError(e1, e1.toString());

}

AddTestCase( "x = new XML(var xml = new XML(\"<ns:x><a>1</a><a>2</a><a>3</a></ns:x>\")", expected, result );



expectedStr = "TypeError: Error #1083: The prefix \"ns\" for element \"ns:x\" is not bound.";
expected = "Error #1083";
result = "error, exception not thrown";

try{

xml = new XML("<ns:x xmlns:as=\"http://foo.bar\"><a>1</a><a>2</a><a>3</a></ns:x>");
throw new Error("kXMLPrefixNotBound error not thrown");

} catch( e2 ){

result = grabError(e2, e2.toString());

}

AddTestCase( "x = new XML(var xml = new XML(\"<ns:x xmlns:as=\"http://foo.bar\"><a>1</a><a>2</a><a>3</a></ns:x>\")", expected, result );



expectedStr = "TypeError: Error #1083: The prefix \"as\" for element \"as:a\" is not bound.";
expected = "Error #1083";
result = "error, exception not thrown";

try{

xml = new XML("<ns:b xmlns:ns=\"http://foo.bar\"><as:a>1</as:a></ns:b>");
throw new Error("kXMLPrefixNotBound error not thrown");

} catch( e3 ){

result = grabError(e3, e3.toString());

}

AddTestCase( "x = new XML(var xml = new XML(\"<ns:b xmlns:ns=\"http://foo.bar\"><as:a>1</as:a></ns:b>\")", expected, result );


END();

