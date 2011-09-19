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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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


    var SECTION = "Array";
    var VERSION = "ecma3";
    startTest();
    var TITLE   = "test that push() doesn't assume length == dense.length";

    writeHeaderToLog( SECTION + " "+ TITLE );


    var a:Array = [];

    a.push(0); // a[0]
    a.push(1); // a[1]
    AddTestCase("test 1",
        "0,1",
        a.toString());

    delete a[1];
    delete a[0];

    AddTestCase("test 2",
        ",",
        a.toString());

    a.push(2);
    a.push(3);

    AddTestCase("test 3",
        ",,2,3",
        a.toString());

    delete a[3];
    delete a[2];

    AddTestCase("test 4",
        ",,,",
        a.toString());

    a.push(4);
    a.push(5);

    AddTestCase("test 5",
        ",,,,4,5",
        a.toString());

    delete a[5];
    delete a[4];
    
    AddTestCase("test 6",
        ",,,,,",
        a.toString());

    test();

