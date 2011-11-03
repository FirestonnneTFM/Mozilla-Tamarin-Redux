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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
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
 * ***** END LICENSE BLOCK ***** */

/*
Running this testcase and the entire as3/Vector/* acceptance tests will provide
almost full coverage of this change:
    http://hg.mozilla.org/tamarin-redux/diff/6f72616eadd7/core/Verifier.cpp

These testcases focus on covering all conditions of this line:
    bool maybeIntegerIndex = !attr && multiname.isRtname() && multiname.containsAnyPublicNamespace();

The only condition that is not being covered is the false branch of:
    multiname.containsAnyPublicNamespace().
 */

import avmplus.*;

var SECTION = " ";
var VERSION = "AS3";
startTest();
writeHeaderToLog( SECTION + " Vector code coverage around Verifier changes made in bug 678952");

class C
{
    var x: C = null;  // just some field to make the type nontrivial
}

var expected;
var err;
var a: Vector.<C> = new Vector.<C>;

expected = "ReferenceError: Error #1069";
err = "exception not thrown";
try {
    var f = a.foo;
 }
catch (e:Error){
    err = e.toString();
}
// http://hg.mozilla.org/tamarin-redux/diff/6f72616eadd7/core/Verifier.cpp#l1.26
AddTestCase("ReferenceError for multiname.isRtname() failing",
               expected,
               parseError(err, expected.length));

expected = "ReferenceError: Error #1081";
err = "exception not thrown";
try {
    // attr -> false
    var g = a.@attr;
 }
catch (e:Error){
    err = e.toString();
}
// http://hg.mozilla.org/tamarin-redux/diff/6f72616eadd7/core/Verifier.cpp#l1.26
AddTestCase("ReferenceError for !attr failing",
               expected,
               parseError(err, expected.length));



test();
