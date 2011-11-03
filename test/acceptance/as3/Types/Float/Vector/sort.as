/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
include "../floatUtil.as";


var SECTION = "";
var VERSION = "AS3";
var TITLE   = "Vector.sort(comparefn) with float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

class TestClass {
    private var myVal:Object;
    public function TestClass(v:Object):void {
        myVal = v;
    }
    public function toString():String {
        return myVal.toString();
    }
    public function get val():Object {
        return myVal;
    }
}

var testClassVector = new Vector.<TestClass>();
for (var i=0; i<20; i++) {
    testClassVector.push(new TestClass(i));
}
// push one duplicate value
testClassVector.push(new TestClass(12));

// regular sort returning non-standard values
var myFloatSortFunction:Function = function (x,y):float {
    if (x.val < y.val)
        return float(-Infinity);  // TODO: a float literal for "-Infinity"?
    if (x.val > y.val)
        return float.MAX_VALUE;
    return undefined;
}

AddTestCase("Custom vector sort using sort function with non-standard (float) values",
            "0,1,2,3,4,5,6,7,8,9,10,11,12,12,13,14,15,16,17,18,19",
            testClassVector.sort(myFloatSortFunction).toString()
            );

test();
