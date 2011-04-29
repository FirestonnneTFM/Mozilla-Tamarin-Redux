/* -*- Mode: js; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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

var SECTION:String = "RegExpObject::replace(Stringp, Stringp)";
var VERSION:String = "";
startTest();
var TITLE:String = "Tests based on code coverage";

writeHeaderToLog( SECTION + " "+ TITLE);

var testcases = getTestCases();
test();

function getTestCases() : Array
{
    var array:Array = new Array();
    var item:int = 0;

    var str:String;
    var pattern:RegExp;

    str = "one-two";
    pattern = /(\w+)-(\w+)/g;
    array[item++] = new TestCase(SECTION, 'str.replace(pattern, "$2-$1")', "two-one", str.replace(pattern, "$2-$1") );

    pattern = /(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)/g;
    str = "one-two-three-four-five-six-seven-eight-nine-ten";
    array[item++] = new TestCase(SECTION, 'str.replace(pattern, "$9-$8-$7-$6-$5-$4-$3-$2-$1")', "nine-eight-seven-six-five-four-three-two-one", str.replace(pattern, "$9-$8-$7-$6-$5-$4-$3-$2-$1") );

    pattern = /(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)-(\w+)/g;
    str = "one-two-three-four-five-six-seven-eight-nine-ten";
    array[item++] = new TestCase(SECTION, 'str.replace(pattern, "$10-$1")', "ten-one", str.replace(pattern, "$10-$1") );

    str = "one-two";
    pattern = /(\w+)-(\w+)/g;
    array[item++] = new TestCase(SECTION, 'str.replace(pattern, "$2-$A")', "two-$A", str.replace(pattern, "$2-$A") );

    str = "one-two";
    pattern = /(\w+)-(\w+)/g;
    array[item++] = new TestCase(SECTION, 'str.replace(pattern, "$02-$01")', "two-one", str.replace(pattern, "$02-$01") );

    str = "abc-123-abc";
    pattern = /(?P<mygroup>abc)-123-(?P=mygroup)/g;
    array[item++] = new TestCase(SECTION, "pattern.exec(str)", "abc", pattern.exec(str)[1] );

    str = "abc-456-abc";
    pattern = /(?P<mygroup>abc)-123-(?P=mygroup)/g;
    array[item++] = new TestCase(SECTION, "pattern.exec(str)", null, pattern.exec(str) );

    return ( array );
}

