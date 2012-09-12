/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.1.2 Qualified Identifiers - XML bad QName error");

var expected, result, expectedStr;

expectedStr = "TypeError: Error #1084: Element or attribute (\":x\") do not match QName production: QName::=(NCName':')?NCName";
expected = "Error #1084";

result = "error, exception not thrown";

namespace ns="http://www.foo.com";
var x1 = new XML("<x xmlns='http://www.foo.com'><a>foo</a></x>");

try{

x1 = new XML("<:x>hi</x>");
throw "kXMLBadQname error not thrown";

} catch( e1 ){

result = grabError(e1, e1.toString());

}


AddTestCase("<:x>hi</x>", expected, result);


expectedStr = "TypeError: Error #1084: Element or attribute (\":ns\") do not match QName production: QName::=(NCName':')?NCName";
expected = "Error #1084";

try{

x1 = new XML("<x :ns='attr'>hi</x>");
throw "kXMLBadQname error not thrown";

} catch( e2 ){

result = grabError(e2, e2.toString());

}


AddTestCase("<x :ns='attr'>hi</x>", expected, result);

END();

