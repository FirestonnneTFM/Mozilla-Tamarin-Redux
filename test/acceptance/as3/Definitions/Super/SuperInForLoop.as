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

// Regression test for CMP-1695.

class Zeeb
{
    public var moo;
}

class Zonk extends Zeeb
{
    public function for_array_access(zam)
    {
        var result = []
        for ( super['moo'] in zam ) {
            result.push(super.moo);
        }
        AddTestCase('for_array_access:length', true, result.indexOf('length') != -1 );
        AddTestCase('for_array_access:company', true, result.indexOf('company') != -1 );
        AddTestCase('for_array_access:year', true, result.indexOf('year') != -1 );
        AddTestCase('for_array_access:0', true, result.indexOf(0) != -1 );
    }
    
    public function foreach_array_access(zam)
    {
        var result = []
        for each ( super['moo'] in zam ) {
            result.push(super.moo);
        }
        AddTestCase('foreach_array_access:zero', true, result.indexOf('zero') != -1 );
        AddTestCase('foreach_array_access:4', true, result.indexOf(4) != -1 );
        AddTestCase('foreach_array_access:netscape', true, result.indexOf('netscape') != -1 );
        AddTestCase('foreach_array_access:2000', true, result.indexOf(2000) != -1 );
    }
    
    public function for_prop_access(zam)
    {
        var result = []
        for ( super['moo'] in zam ) {
            result.push(super.moo);
        }
        AddTestCase('for_prop_access:length', true, result.indexOf('length') != -1 );
        AddTestCase('for_prop_access:company', true, result.indexOf('company') != -1 );
        AddTestCase('for_prop_access:year', true, result.indexOf('year') != -1 );
        AddTestCase('for_prop_access:0', true, result.indexOf(0) != -1 );
    }
    
    public function foreach_prop_access(zam)
    {
        var result = []
        for each ( super['moo'] in zam ) {
            result.push(super.moo);
        }
        AddTestCase('foreach_prop_access:zero', true, result.indexOf('zero') != -1 );
        AddTestCase('foreach_prop_access:4', true, result.indexOf(4) != -1 );
        AddTestCase('foreach_prop_access:netscape', true, result.indexOf('netscape') != -1 );
        AddTestCase('foreach_prop_access:2000', true, result.indexOf(2000) != -1 );
    }
}

var SECTION = "Super";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Super used as assignment target in for loops";       // Provide ECMA section title or a description

startTest();                // leave this alone

var keys = ['length', 'company', 'year', 0];
var object = { length:4, company:"netscape", year:2000, 0:"zero" };
new Zonk().for_array_access(object);
new Zonk().foreach_array_access(object);
new Zonk().for_prop_access(object);
new Zonk().foreach_prop_access(object);

test();

