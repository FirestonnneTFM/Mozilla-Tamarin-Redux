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
* Portions created by the Initial Developer are Copyright (C) 2008
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

import avmplus.*;
import avmshell.*;

startTest();

// standard AddErrorTest function doesn't handle no-error well.
function MyAddErrorTest(desc:String, expectedErr:String, testFunc:Function) 
{
    actualErr = "no error";
    try {
        testFunc();
    } catch (e) {
        actualErr = e;
    }
    grabError(actualErr, expectedErr);
    AddTestCase(desc, expectedErr, String(actualErr).substr(0, expectedErr.length));
}


const SUCCESS:String = "no error";
const FAILURE:String = "ArgumentError: Error #2012";

function expectSuccess(msg:String, cls:Class)
{
    MyAddErrorTest(msg, SUCCESS, function() { new cls; });
}

function expectFailure(msg:String, cls:Class)
{
    MyAddErrorTest(msg, FAILURE, function() { new cls; });
}


expectFailure("instantiate for construct=none", System);

class MySubclassOfAbstractBase2 extends avmshell.SubclassOfAbstractBase
{
}


expectFailure("instantiate for construct=abstract", AbstractBase);
expectSuccess("instantiate for native child of construct=abstract", NativeSubclassOfAbstractBase);
expectSuccess("instantiate for child of construct=abstract", SubclassOfAbstractBase);
expectSuccess("instantiate for grandchild of construct=abstract", MySubclassOfAbstractBase2);


class MySubclassOfRestrictedBase extends avmshell.RestrictedBase
{
}

class MySubclassOfRestrictedBase2 extends avmshell.SubclassOfRestrictedBase
{
}

class MySubclassOfRestrictedBase3 extends avmshell.NativeSubclassOfRestrictedBase
{
}

expectSuccess("instantiate for construct=restricted", RestrictedBase);
expectSuccess("instantiate for native child of construct=restricted", NativeSubclassOfRestrictedBase);
expectSuccess("instantiate for child of construct=restricted", SubclassOfRestrictedBase);
expectFailure("instantiate for external child of construct=restricted", MySubclassOfRestrictedBase);
expectSuccess("instantiate for external grandchild of construct=restricted", MySubclassOfRestrictedBase2);
expectSuccess("instantiate for external grandchild of native construct=restricted", MySubclassOfRestrictedBase3);

class MySubclassOfAbstractRestrictedBase extends avmshell.AbstractRestrictedBase
{
}

class MySubclassOfAbstractRestrictedBase2 extends MySubclassOfAbstractRestrictedBase
{
}

expectFailure("instantiate for construct=abstract-restricted", AbstractRestrictedBase);
expectSuccess("instantiate for native child of construct=abstract-restricted", NativeSubclassOfAbstractRestrictedBase);
expectSuccess("instantiate for child of construct=abstract-restricted", SubclassOfAbstractRestrictedBase);
expectFailure("instantiate for external child of construct=abstract-restricted", MySubclassOfAbstractRestrictedBase);
expectFailure("instantiate for external grandchild of construct=abstract-restricted", MySubclassOfAbstractRestrictedBase2);

MyAddErrorTest("instantiate for construct=check", "ArgumentError: Error #1001", function() { new CheckBase; });

test();

