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

package {
    import avmplus.Domain
    import avmplus.System

    var SECTION = "Domain";
    var VERSION = "Domain";
    startTest();
    var TITLE   = "Bug 567284";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var support_path:String = System.argv[0];

    var parentDomain:Domain = Domain.currentDomain;
    var childDomain:Domain = new Domain(parentDomain);

    childDomain.load(support_path + "DupExaminer.abc");
    childDomain.load(support_path + "Dup1.abc");

    var cls:Class = childDomain.getClass("DupExaminer");
    var examiner = new cls();
    var value = examiner.examine();

    AddTestCase("Test for non-crash in child Domain",
      "Dup1",
      String(value));

    parentDomain.load(support_path + "Dup2.abc")

    value = examiner.examine();

    // Note that we still expect "Dup1" as the first version of "Dup"
    // loaded should still take precedence, even though "Dup2" is higher
    // in the Domain chain, due to freeze-on-first-use
    AddTestCase("Test for non-crash in parent Domain",
      "Dup1",
      String(value));

    test();

}