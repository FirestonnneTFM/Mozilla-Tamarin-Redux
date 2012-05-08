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

var SECTION = "Regression Tests";
var VERSION = "AS3";
var TITLE   = "Bug 673284";
var bug = "673284";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);


var subject:String="AAA";
for (var i = 0; i < 10; i ++) {
    subject.match(/(?i)a(?-i)(.?)|c/g);
    subject.match(/(?i)a(?-i).?|c/g);
    subject.match(/(?i)a(?-i)(.??)|c/g);
    subject.match(/(?i)a(?-i).??|c/g);
    subject.match(/(?i)a(?-i)(\p{Z}[^\p{C}\p{Z}]+)*|c/g);
    subject.match(/(?i)a(?-i)[^\p{C}\p{Z}]+|c/g);

    subject.match(/(?i)a(?-i)[\pL](abc)(?1)|c/g); // overwrite #1

    subject.match(/(?i)a(?-i)[\pL]=(abc))*X|c/g);
    subject.match(/(?i)a(?-i)(?:\p{Lu}|\x20)+|c/g);
    subject.match(/(?i)a(?-i)[\p{Lu}\x20]+|c/g);
    subject.match(/(?i)a(?-i)(a.b(?s)c.d|x.y)|c/g);
    subject.match(/(?i)a(?-i)\d?|c/g);
    subject.match(/(?i)a(?-i)[abcd]*|c/g);
    subject.match(/(?i)a(?-i)[abcd]+|c/g);
    subject.match(/(?i)a(?-i)[abcd]?|c/g);
    subject.match(/(?i)a(?-i)[abcd]{2,3}|c/g);

    subject.match(/(?i)a(?-i)(abc)*|c/g); // overwrite #2

    subject.match(/(?i)a(?-i)(abc)+|c/g);
    subject.match(/(?i)a(?-i)(abc)?|c/g);        // overwrites
    subject.match(/(?i)a(?-i)(a*\w|ab)|c/g);
    subject.match(/(?i)a(?-i)(?<=abc|xy)|c/g);
    subject.match(/(?i)a(?-i)(a*|xyz)|c/g);
    subject.match(/(?i)a(?-i)(ab*(cd|ef))+|c/g); // overwrites
    subject.match(/(?i)a(?-i)(a+|b+|c+)*|c/g);
    subject.match(/(?i)a(?-i)(?<=a|bbbb)|c/g);
    subject.match(/(?i)a(?-i)[^\r\n]{6,}|c/g);
    subject.match(/(?i)a(?-i)[^a]{6,}|c/g);
    subject.match(/(?i)a(?-i)^\pN{2,3}|c/g);
    subject.match(/(?i)a(?-i)bac/g);
    subject.match(/(?i)a(?-i)b\tc/g);
    subject.match(/(?i)a(?-i)ba*c/g);
    subject.match(/(?i)a(?-i)bc?c/g);
    subject.match(/(?i)a(?-i)bz+c/g);
    subject.match(/(?i)a(?-i)br{3}c/g);
    subject.match(/(?i)a(?-i)bb{2,}c/g);
    subject.match(/(?i)a(?-i)by{4,5}c/g);
    subject.match(/(?i)a(?-i)b^c/g);
    subject.match(/(?i)a(?-i)b(abc){1,2}c/g);
    subject.match(/(?i)a(?-i)b(b+?|a){1,2}?c/g);
    subject.match(/(?i)a(?-i)bb+?c/g);
    subject.match(/(?i)a(?-i)b(b+|a){1,2}c/g);
    subject.match(/(?i)a(?-i)b(b+|a){1,2}?c/g);
    subject.match(/(?i)a(?-i)b(b*|ba){1,2}?c/g);
    subject.match(/(?i)a(?-i)b(ba|b*){1,2}?c/g);
    subject.match(/(?i)a(?-i)b\c/g);
    subject.match(/(?i)a(?-i)b[c/g);
    subject.match(/(?i)a(?-i)bc{c/g);
    subject.match(/(?i)a(?-i)b[ab\]cde]c/g);
    subject.match(/(?i)a(?-i)b[]cde]c/g);
    subject.match(/(?i)a(?-i)b[0-9]+c/g);
    subject.match(/(?i)a(?-i)b.*c/g);

}

AddTestCase("Completed", true, true);


test();

