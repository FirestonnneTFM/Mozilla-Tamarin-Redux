/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

var SECTION = "regress_609416";
var VERSION = "AS3";
var TITLE   = "encodeURIComponent and decodeURIComponent give wrong output when input contains surrogate pairs";
var bug = "609416";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

import avmplus.System;

var src:String = String.fromCharCode(0xD842, 0xDF9F);
var encodedStr:String = encodeURIComponent(src);
var decodedStr:String = "";
var errorMsgStr:String = "no error";

try {
    decodedStr = decodeURIComponent(encodedStr);
} catch(e:Error) {
    errorMsgStr = e.toString();
}

if (System.swfVersion >= 11) {
    AddTestCase(
        "transcode UTF16 to UTF8 when the UTF16 code points contain a surrogate pair",
        src,
        decodedStr);
} else {
    AddTestCase(
        "transcode UTF16 to UTF8 when the UTF16 code points contain a surrogate pair",
        "URIError: Error #1052",
        parseError(errorMsgStr,"URIError: Error #1052".length));
}


test();



    
