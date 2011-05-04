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

    var SECTION = "15.2.3";
    var VERSION = "ECMA_3";
    startTest();
    var TITLE   = "JSON ecma-262 testcases";

    writeHeaderToLog( SECTION + " "+ TITLE);

    startTest();

    AddTestCase("15.12.3-0-1: JSON.stringify must exist as a function","function",typeof(JSON.stringify));
    AddTestCase("15.12.3-0-2: JSON.stringify must exist as a function taking 3 parameters",3,JSON.stringify.length);

    var exception1="no exception";
    try {
        JSON.stringify([42],{},'[42]');
    } catch (e) {
        exception1=removeExceptionDetail(e.toString());
    }
    AddTestCase("15.12.3-4-1: JSON.stringify ignores replacer aruguments that are not functions or arrays..","TypeError: Error #1131",exception1);

    var obj = {a1: {b1: [1,2,3,4], b2: {c1: 1, c2: 2}},a2: 'a2'};
    AddTestCase("15.12.3-5-a-i-1: JSON.stringify converts Number wrapper object space aruguments to Number values", true, JSON.stringify(obj,null, new Number(5)) === JSON.stringify(obj,null,5));

    AddTestCase("15.12.3-5-b-i-1: JSON.stringify converts String wrapper object space aruguments to String values", true, JSON.stringify(obj,null, new String('xxx')) === JSON.stringify(obj,null, 'xxx'));

    AddTestCase("15.12.3-6-a-1: JSON.stringify treats numeric space arguments greater than 10 the same as a  space argument of 10.", true, JSON.stringify(obj,null, 10) === JSON.stringify(obj,null, 100));

    AddTestCase("15.12.3-6-a-2: JSON.stringify truccates non-integer numeric space arguments to their integer part.", true, JSON.stringify(obj,null, 5.99999) === JSON.stringify(obj,null, 5));

    AddTestCase("15.12.3-6-b-1: JSON.stringify treats numeric space arguments less than 1 (0.999999) the same as emptry string space argument.", true, JSON.stringify(obj,null, 0.999999) === JSON.stringify(obj));

    AddTestCase("15.12.3-6-b-2: JSON.stringify treats numeric space arguments less than 1 (0)the same as emptry string space argument.", true, JSON.stringify(obj,null, 0) === JSON.stringify(obj));

    AddTestCase("15.12.3-6-b-3: JSON.stringify treats numeric space arguments less than 1 (-5) the same as empty string space argument.", true, JSON.stringify(obj,null, -5) === JSON.stringify(obj));

    var fiveSpaces='     ';
    AddTestCase("15.12.3-6-b-4: JSON.stringify treats numeric space arguments (in the range 1..10) is equivalent to a string of spaces of that length.", true, JSON.stringify(obj,null, 5) === JSON.stringify(obj, null, fiveSpaces));

    AddTestCase("15.12.3-7-a-1: JSON.stringify only uses the first 10 characters of a string space arguments.", true, JSON.stringify(obj,null, '0123456789xxxxxxxxx')=== JSON.stringify(obj,null, '0123456789'));

    AddTestCase("15.12.3-8-a-1: JSON.stringify treats an empty string space argument the same as a missing space argument.", true, JSON.stringify(obj)=== JSON.stringify(obj,null, ''));
    try {
        AddTestCase("15.12.3-8-a-2: JSON.stringify treats an Boolean space argument the same as a missing space argument.", true, JSON.stringify(obj)=== JSON.stringify(obj,null, true));
    } catch (e) {
        AddTestCase("15.12.3-8-a-2: JSON.stringify should treat Boolean space argument same as missing space argument", 'no exception', e.toString());
    }

    try {
        AddTestCase("15.12.3-8-a-3: JSON.stringify treats an null space argument the same as a missing space argument.", true, JSON.stringify(obj)=== JSON.stringify(obj,null, null));
    } catch (e) {
        AddTestCase("15.12.3-8-a-3: JSON.stringify treats an null space argument the same as a missing space argument. '",'no exception',e.toString());
    }  

    try {
        AddTestCase("15.12.3-8-a-4: JSON.stringify treats an Boolean wrapper space argument the same as a missing space argument.", true, JSON.stringify(obj)=== JSON.stringify(obj,null, new Boolean(true)));
    } catch (e) {
        AddTestCase("15.12.3-8-a-4: JSON.stringify treats an Boolean wrapper space argument the same as a missing space argument. '",'no exception',e.toString());
    }

    try {
        AddTestCase("15.12.3-8-a-5: JSON.stringify treats non-Number or String object space arguments the same as a missing space argument.", true, JSON.stringify(obj)=== JSON.stringify(obj,null, new Boolean(true)));
    } catch (e) {
        AddTestCase("15.12.3-8-a-5: JSON.stringify treats non-Number or String object space arguments the same as a missing space argument. '", 'no exception',e.toString());
    }

    var obj2 = {
        prop:42,
        toJSON: function () {return 'fortytwo objects'}
    };
    AddTestCase("15.12.3-2-2-b-i-1: JSON.stringify converts string wrapper objects returned from a toJSON call to literal strings.", '["fortytwo objects"]', JSON.stringify([obj2]));

    var obj3 = {
        prop:42,
        toJSON: function () {return new Number(42)}
    };
    AddTestCase("15.12.3-2-2-b-i-2: JSON.stringify converts Number wrapper objects returned from a toJSON call to literal Number.", '[42]', JSON.stringify([obj3]));

    var obj4 = {
        prop:42,
        toJSON: function () {return new Boolean(true)}
    };
    AddTestCase("15.12.3-2-2-b-i-3: JSON.stringify converts Boolean wrapper objects returned from a toJSON call to literal Boolean values.", '[true]', JSON.stringify([obj4]));

    // [fortytwo] ??
    AddTestCase("15.12.3-2-3-a-1: JSON.stringify converts string wrapper objects returned from replacer functions to literal strings.", '["fortytwo"]', JSON.stringify([42], function(k,v) {return v===42? new String('fortytwo'):v}));

    AddTestCase("15.12.3-2-3-a-2: JSON.stringify converts Number wrapper objects returned from replacer functions to literal numbers.", '[84]', JSON.stringify([42], function(k,v) {return v===42? new Number(84):v}));

    AddTestCase("15.12.3-2-3-a-3: JSON.stringify converts Boolean wrapper objects returned from replacer functions to literal numbers.", '[false]' ,JSON.stringify([42], function(k,v) {return v===42? new Boolean(false):v}));

    test();



}
