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

package {

    var SECTION = "15.2";
    var VERSION = "ECMA_3";
    startTest();
    var TITLE   = "JSON ecma-262 testcases";

    writeHeaderToLog( SECTION + " "+ TITLE);

    startTest();

    AddTestCase("15.12-0-1: JSON must be a built-in object","object",typeof(JSON));

    // 15.12-0-2: JSON must not support the [[Construct]] method
    var constructorException="no exception";
    try {
        var j = new JSON();
    } catch(e) {
        constructorException=e.toString();
        constructorException=removeExceptionDetail(constructorException);
    }
    AddTestCase("15.12-0-2: JSON must not support the [[Construct]] method","ArgumentError: Error #2012",constructorException);

    // 15.12-0-3: JSON must not support the [[Call] method
    var callException="no exception";
    try {
        var k = JSON();
    } catch(e) {
        callException=e.toString();
        callException=removeExceptionDetail(callException);
    }
    AddTestCase("15.12-0-3: JSON must not support the [[Call]] method","ArgumentError: Error #1112",callException);
    
    // 15.12-0-4: JSON object properties must be non enumerable
    var i=0;
    for (var p in JSON) {
        i++;
    }
    AddTestCase("15.12-0-4: JSON object properties must be non enumerable",0,i);

    test();

}
