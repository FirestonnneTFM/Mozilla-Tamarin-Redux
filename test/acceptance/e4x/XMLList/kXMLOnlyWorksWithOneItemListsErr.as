/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5 XMLList Objects - XML only works with one item lists error");

var xl;
var result, expected, expectedStr;

xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The addNamespace method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.addNamespace('uri');
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e1 ){

result = grabError(e1, e1.toString());

}

AddTestCase( "xmllist.addNamespace('uri')", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The appendChild method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.appendChild("<e>f</e>");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e2 ){

result = grabError(e2, e2.toString());

}

AddTestCase( "xmllist.appendChild('<e>f</e>')", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The inScopeNamespaces method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.inScopeNamespaces();
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e3 ){

result = grabError(e3, e3.toString());

}

AddTestCase( "xmllist.inScopeNamespaces()", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The insertChildAfter method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.insertChildAfter(null, "<s>t</s>");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e4 ){

result = grabError(e4, e4.toString());

}

AddTestCase( "xmllist.insertChildAfter(null, \"<s>t</s>\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The insertChildBefore method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.insertChildBefore(null, "<s>t</s>");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e5 ){

result = grabError(e5, e5.toString());

}

AddTestCase( "xmllist.insertChildBefore(null, \"<s>t</s>\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The name method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.name();
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e6 ){

result = grabError(e6, e6.toString());

}

AddTestCase( "xmllist.name()", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The getNamespace method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

//xl.getNamespace("blah");
myGetNamespace(xl, "blah");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e7 ){

result = grabError(e7, e7.toString());

}

AddTestCase( "xmllist.getNamespace(\"blah\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The namespaceDeclarations method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.namespaceDeclarations();
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e8 ){

result = grabError(e8, e8.toString());

}

AddTestCase( "xmllist.namespaceDeclarations()", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The nodeKind method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.nodeKind();
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e9 ){

result = grabError(e9, e9.toString());

}

AddTestCase( "xmllist.nodeKind()", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The removeNamespace method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.removeNamespace('pfx');
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e10 ){

result = grabError(e10, e10.toString());

}

AddTestCase( "xmllist.removeNamespace('pfx')", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The setChildren method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.setChildren("<c>4</c><c>5</c>");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e11 ){

result = grabError(e11, e11.toString());

}

AddTestCase( "xmllist.setChildren(\"<c>4</c><c>5</c>\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The setLocalName method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.setLocalName("new local name");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e12 ){

result = grabError(e12, e12.toString());

}

AddTestCase( "xmllist.setLocalName(\"new local name\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The setName method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.setName("myName");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e13 ){

result = grabError(e13, e13.toString());

}

AddTestCase( "xmllist.setName(\"myName\")", expected, result );



xl = new XMLList("<a>1</a><a>2</a><a>3</a>");
expectedStr = "TypeError: Error #1086: The setNamespace method works only on lists containing one item.";
expected = "Error #1086";
result = "error, exception not thrown";

try{

xl.setNamespace("pfx");
throw new Error("kXMLOnlyWorksWithOneItemLists error not thrown");

} catch( e14 ){

result = grabError(e14, e14.toString());

}

AddTestCase( "xmllist.setNamespace(\"pfx\")", expected, result );


END();

