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
 * Portions created by the Initial Developer are Copyright (C) 2010
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


    var SECTION = "15.8.2.12";
    var VERSION = "";
    startTest();
    var TITLE   = "Math.min(x, y, ... rest) and additional tests base on code coverage";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    /*
      Testcases based on code coverage analysis:
      core/MathClass.cpp
      Lars: "You can tell -0 from 0 by dividing 1 by the zero, -0 gives -Infinity
      and 0 gives Infinity, so if you know x is a zero the test for negative
      zero is (1/x < 0)."
    */
    array[item++] = new TestCase( SECTION,  "Math.min(Number.NaN, 2, 1)", Number.NaN, Math.min(Number.NaN, 2, 1) );
    array[item++] = new TestCase( SECTION,  "Math.min(1, Number.NaN, 1)", Number.NaN, Math.min(1, Number.NaN, 1) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(-0.0, 0.0)",    -Infinity,  1.0/Math.min(-0.0, 0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(-0.0, -0.0)",   -Infinity,  1.0/Math.min(-0.0, -0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(0.0, 0.0)",     Infinity,   1.0/Math.min(0.0, 0.0) );
    array[item++] = new TestCase( SECTION,  "Math.min(2, 2, 1)",          1,          Math.min(2, 2, 1) );
    array[item++] = new TestCase( SECTION,  "Math.min(1, 2, 2)",          1,          Math.min(1, 2, 2) );
    array[item++] = new TestCase( SECTION,  "Math.min(1, 2, 1)",          1,          Math.min(1, 2, 1) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(0.0, 2, 0.0)",  Infinity,   1.0/Math.min(0.0, 2, 0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(-0.0, 2, -0.0)",-Infinity,  1.0/Math.min(-0.0, 2, -0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(-0.0, 2, 0.0)", -Infinity,  1.0/Math.min(-0.0, 2, 0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.min(3, 2, 1, 0, 0.0, -0.0)", -Infinity, 1.0/Math.min(3, 2, 1, 0, 0.0, -0.0) );

    return ( array );
}
