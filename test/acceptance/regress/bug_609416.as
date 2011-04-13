/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK *****
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



    
