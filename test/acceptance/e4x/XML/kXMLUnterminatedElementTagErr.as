/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4 XML Object - XML Unterminated Element Tag Error");

var expectedStr = "TypeError: Error #1085: The element type \"unterminated\" must be terminated by the matching end-tag \"</unterminated>\".";
expected = "Error #1085";

var result = "error, exception not thrown";

 

try{

var xml = new XML("<unterminated><terminated>text</terminated>");
throw "kXMLUnterminatedElementTag";

} catch( e1 ){

result = grabError(e1, e1.toString());

}

 

AddTestCase( "new XML(\"<unterminated><terminated>text</terminated>\")", expected, result );

 

try{

xml = new XML("<unterminated><terminated>text</terminated></unterm>");
throw "kXMLUnterminatedElementTag";

} catch( e2 ){

result = grabError(e2, e2.toString());

}

 

AddTestCase( "new XML(\"<unterminated><terminated>text</terminated></unterm>\")", expected, result );

END();

