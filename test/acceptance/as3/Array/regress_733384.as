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
* Portions created by the Initial Developer are Copyright (C) 2012
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

var SECTION = "regress_723461";
var VERSION = "AS3";
var TITLE   = "associative Array defined with [] does not show non-index elements as propertyIsEnumerable";
var bug = "723461";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

var emptyA = [];
var denseZ = [];
var denseO = [];
var indexK = [];
var sparse = [];
var object = {};

var all = [emptyA, denseZ, denseO, indexK, sparse, object];

denseZ[0]    = "dense starting at zero";

denseO[1]    = "dense starting at one";

indexK[1000] = "array starting at thousand";

sparse[1]    = "array starting at one";
sparse[1000] = "assuredly sparse due to element at thousand";

object[1000] = "object with value at thousand";

for each (x in all) {
    x["nonindex"] = "a non index in every tested object";
}

function AddCleanCase(name, object, key, expect) {
    AddTestCase(name, expect, object.propertyIsEnumerable(key));
}

AddCleanCase("emptyA pIE on present nonindex",   emptyA, "nonindex", true);
AddCleanCase("emptyA pIE on absent nonindex",    emptyA, "absent",  false);
AddCleanCase("denseZ pIE on present nonindex",   denseZ, "nonindex", true);
AddCleanCase("denseZ pIE on absent nonindex",    denseZ, "absent",  false);
AddCleanCase("denseO pIE on present nonindex",   denseO, "nonindex", true);
AddCleanCase("denseO pIE on absent nonindex",    denseO, "absent",  false);
AddCleanCase("indexK pIE on present nonindex",   indexK, "nonindex", true);
AddCleanCase("indexK pIE on absent nonindex",    indexK, "absent",  false);
AddCleanCase("sparse pIE on present nonindex",   sparse, "nonindex", true);
AddCleanCase("sparse pIE on absent nonindex",    sparse, "absent",  false);
AddCleanCase("object pIE on present nonindex",   object, "nonindex", true);
AddCleanCase("object pIE on absent nonindex",    object, "absent",  false);

function AddToggleCase(name, object, key, expect) {
    object.setPropertyIsEnumerable(key, false);
    AddTestCase(name, expect, object.propertyIsEnumerable(key));
}

AddToggleCase("emptyA tog pIE present nonindex", emptyA, "nonindex", false);
AddToggleCase("emptyA tog pIE absent nonindex",  emptyA, "absent",   false);
AddToggleCase("denseZ tog pIE present nonindex", denseZ, "nonindex", false);
AddToggleCase("denseZ tog pIE absent nonindex",  denseZ, "absent",   false);
AddToggleCase("denseO tog pIE present nonindex", denseO, "nonindex", false);
AddToggleCase("denseO tog pIE absent nonindex",  denseO, "absent",   false);
AddToggleCase("indexK tog pIE present nonindex", indexK, "nonindex", false);

AddToggleCase("indexK tog pIE absent nonindex",  indexK, "absent",   false);
AddToggleCase("sparse tog pIE present nonindex", sparse, "nonindex", false);
AddToggleCase("sparse tog pIE absent nonindex",  sparse, "absent",   false);
AddToggleCase("object tog pIE present nonindex", object, "nonindex", false);
AddToggleCase("object tog pIE absent nonindex",  object, "absent",   false);

test();
