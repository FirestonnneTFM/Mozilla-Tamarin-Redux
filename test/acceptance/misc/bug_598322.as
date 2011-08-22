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
* Portions created by the Initial Developer are Copyright (C) 2009
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


    var SECTION = "String.charAt/codeCodeAt optimizations";

    startTest();
    var testcases = getTestCases();
    test();


    function strCharCodeAtFF(s:String, d:Number):Number
    {
        return s.charCodeAt(d);
    }

    function strCharCodeAtFI(s:String, i:int):Number
    {
        return s.charCodeAt(i);
    }

    function strCharCodeAtFU(s:String, u:uint):Number
    {
        return s.charCodeAt(u);
    }

    function strCharCodeAtIF(s:String, d:Number):int
    {
        return s.charCodeAt(d);
    }

    function strCharCodeAtII(s:String, i:int):int
    {
        return s.charCodeAt(i);
    }

    function strCharCodeAtIU(s:String, u:uint):int
    {
        return s.charCodeAt(u);
    }

    function strCharAtF(s:String, d:Number):String
    {
        return s.charAt(d);
    }

    function strCharAtI(s:String, i:int):String
    {
        return s.charAt(i);
    }

    function strCharAtU(s:String, u:uint):String
    {
        return s.charAt(u);
    }

    function getTestCases() {
        var array = new Array();
        var item = 0;
       
        var a = "abcdefg";

        // test 6 different possible charCodeAt calls
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtFF(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtFI(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtFU(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtIF(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtII(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(1)", 98, strCharCodeAtIU(a, 1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", NaN, strCharCodeAtFF(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", NaN, strCharCodeAtFI(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", NaN, strCharCodeAtFU(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", 0, strCharCodeAtIF(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", 0, strCharCodeAtII(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(-1)", 0, strCharCodeAtIU(a, -1));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", NaN, strCharCodeAtFF(a, 11));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", NaN, strCharCodeAtFI(a, 11));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", NaN, strCharCodeAtFU(a, 11));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", 0, strCharCodeAtIF(a, 11));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", 0, strCharCodeAtII(a, 11));
        array[item++] = new TestCase(SECTION, "charCodeAt(11)", 0, strCharCodeAtIU(a, 11));

        // test 3 different charAt calls
        array[item++] = new TestCase(SECTION, "charAt(1)", "b", strCharAtF(a, 1));
        array[item++] = new TestCase(SECTION, "charAt(1)", "b", strCharAtI(a, 1));
        array[item++] = new TestCase(SECTION, "charAt(1)", "b", strCharAtU(a, 1));
        array[item++] = new TestCase(SECTION, "charAt(-1)", "", strCharAtF(a, -1));
        array[item++] = new TestCase(SECTION, "charAt(-1)", "", strCharAtI(a, -1));
        array[item++] = new TestCase(SECTION, "charAt(-1)", "", strCharAtU(a, -1));
        array[item++] = new TestCase(SECTION, "charAt(11)", "", strCharAtF(a, 11));
        array[item++] = new TestCase(SECTION, "charAt(11)", "", strCharAtI(a, 11));
        array[item++] = new TestCase(SECTION, "charAt(11)", "", strCharAtU(a, 11));

        var s:String = "foobar";
        var i_index:int;
        var b:Boolean
        
        // Test the charCodeAt logic in optimizeIntCmpWithNumberCall.
        // String.CharCodeAt == int - any constant integer but zero
        // String.CharCodeAt < int  - zero or any negative integer constant
        // String.CharCodeAt <= int - any negative integer constant
        // int == String.CharCodeAt - any constant integer but zero
        // int < String.CharCodeAt  - zero or any positive integer constant
        // int <= String.CharCodeAt - any positive integer constant
        
        i_index = 100;
        b = s.charCodeAt(i_index) == 10;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 10", false, b);
        b = 9 == s.charCodeAt(i_index);
        array[item++] = new TestCase(SECTION, "9 == charCodeAt(100)", false, b);
        b = s.charCodeAt(i_index) < 8;
        array[item++] = new TestCase(SECTION, "charCodeAt(100 < 8)", false, b);
        b = s.charCodeAt(i_index) <= 7;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 7", false, b);
        b = s.charCodeAt(i_index) > 6;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 6", false, b);
        b = s.charCodeAt(i_index) >= 5;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 5", false, b);
        
        b = (s.charCodeAt(i_index) == -10);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == -10", false, b);
        b = (-9 == s.charCodeAt(i_index));
        array[item++] = new TestCase(SECTION, "-9 = charCodeAt(100)", false, b);
        b = (s.charCodeAt(i_index) < -8);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < -8", false, b);
        b = (s.charCodeAt(i_index) <= -7);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= -7", false, b);
        b = (s.charCodeAt(i_index) > -6);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > -6", false, b);
        b = (s.charCodeAt(i_index) >= -5);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= -5", false, b);
        
        b = (s.charCodeAt(i_index) == 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 0", false, b);
        b = (0 == s.charCodeAt(i_index));
        array[item++] = new TestCase(SECTION, "0 == charCodeAt(100)", false, b);
        b = (s.charCodeAt(i_index) < 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < 0", false, b);
        b = (s.charCodeAt(i_index) <= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 0", false, b);
        b = (s.charCodeAt(i_index) > 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 0", false, b);
        b = (s.charCodeAt(i_index) >= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 0", false, b);
    
        i_index = 1;
        b = (s.charCodeAt(i_index) == 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == 114", false, b);
        b = (114 == s.charCodeAt(i_index));
        array[item++] = new TestCase(SECTION, "114 = charCodeAt(1)", false, b);
        b = (s.charCodeAt(i_index) < 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < 114", true, b);
        b = (s.charCodeAt(i_index) <= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= 114", true, b);
        b = (s.charCodeAt(i_index) > 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > 114", false, b);
        b = (s.charCodeAt(i_index) >= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= 114", false, b);
        
        b = (s.charCodeAt(i_index) == i_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == i_index", false, b);
        b = (i_index == s.charCodeAt(i_index));
        array[item++] = new TestCase(SECTION, "i_index == charCodeAt(1)", false, b);
        b = (s.charCodeAt(i_index) < i_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < i_index", false, b);
        b = (s.charCodeAt(i_index) <= i_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= i_index", false, b);
        b = (s.charCodeAt(i_index) > i_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > i_index", true, b);
        b = (s.charCodeAt(i_index) >= i_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= i_index", true, b);

        var u_index:uint = 100;

        b = s.charCodeAt(u_index) == 10;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 10", false, b);
        b = 9 == s.charCodeAt(u_index);
        array[item++] = new TestCase(SECTION, "9 == charCodeAt(100)", false, b);
        b = s.charCodeAt(u_index) < 8;
        array[item++] = new TestCase(SECTION, "charCodeAt(100 < 8)", false, b);
        b = s.charCodeAt(u_index) <= 7;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 7", false, b);
        b = s.charCodeAt(u_index) > 6;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 6", false, b);
        b = s.charCodeAt(u_index) >= 5;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 5", false, b);
        
        b = (s.charCodeAt(u_index) == -10);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == -10", false, b);
        b = (-9 == s.charCodeAt(u_index));
        array[item++] = new TestCase(SECTION, "-9 = charCodeAt(100)", false, b);
        b = (s.charCodeAt(u_index) < -8);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < -8", false, b);
        b = (s.charCodeAt(u_index) <= -7);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= -7", false, b);
        b = (s.charCodeAt(u_index) > -6);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > -6", false, b);
        b = (s.charCodeAt(u_index) >= -5);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= -5", false, b);
        
        b = (s.charCodeAt(u_index) == 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 0", false, b);
        b = (0 == s.charCodeAt(u_index));
        array[item++] = new TestCase(SECTION, "0 == charCodeAt(100)", false, b);
        b = (s.charCodeAt(u_index) < 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < 0", false, b);
        b = (s.charCodeAt(u_index) <= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 0", false, b);
        b = (s.charCodeAt(u_index) > 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 0", false, b);
        b = (s.charCodeAt(u_index) >= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 0", false, b);
    
        u_index = 1;
        b = (s.charCodeAt(u_index) == 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == 114", false, b);
        b = (114 == s.charCodeAt(u_index));
        array[item++] = new TestCase(SECTION, "114 = charCodeAt(1)", false, b);
        b = (s.charCodeAt(u_index) < 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < 114", true, b);
        b = (s.charCodeAt(u_index) <= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= 114", true, b);
        b = (s.charCodeAt(u_index) > 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > 114", false, b);
        b = (s.charCodeAt(u_index) >= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= 114", false, b);
        
        b = (s.charCodeAt(u_index) == u_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == u_index", false, b);
        b = (u_index == s.charCodeAt(u_index));
        array[item++] = new TestCase(SECTION, "u_index == charCodeAt(1)", false, b);
        b = (s.charCodeAt(u_index) < u_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < u_index", false, b);
        b = (s.charCodeAt(u_index) <= u_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= u_index", false, b);
        b = (s.charCodeAt(u_index) > u_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > u_index", true, b);
        b = (s.charCodeAt(u_index) >= u_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= u_index", true, b);

        var f_index:Number = 100;
        b = s.charCodeAt(f_index) == 10;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 10", false, b);
        b = 9 == s.charCodeAt(f_index);
        array[item++] = new TestCase(SECTION, "9 == charCodeAt(100)", false, b);
        b = s.charCodeAt(f_index) < 8;
        array[item++] = new TestCase(SECTION, "charCodeAt(100 < 8)", false, b);
        b = s.charCodeAt(f_index) <= 7;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 7", false, b);
        b = s.charCodeAt(f_index) > 6;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 6", false, b);
        b = s.charCodeAt(f_index) >= 5;
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 5", false, b);
        
        b = (s.charCodeAt(f_index) == -10);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == -10", false, b);
        b = (-9 == s.charCodeAt(f_index));
        array[item++] = new TestCase(SECTION, "-9 = charCodeAt(100)", false, b);
        b = (s.charCodeAt(f_index) < -8);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < -8", false, b);
        b = (s.charCodeAt(f_index) <= -7);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= -7", false, b);
        b = (s.charCodeAt(f_index) > -6);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > -6", false, b);
        b = (s.charCodeAt(f_index) >= -5);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= -5", false, b);
        
        b = (s.charCodeAt(f_index) == 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) == 0", false, b);
        b = (0 == s.charCodeAt(f_index));
        array[item++] = new TestCase(SECTION, "0 == charCodeAt(100)", false, b);
        b = (s.charCodeAt(f_index) < 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) < 0", false, b);
        b = (s.charCodeAt(f_index) <= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) <= 0", false, b);
        b = (s.charCodeAt(f_index) > 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) > 0", false, b);
        b = (s.charCodeAt(f_index) >= 0);
        array[item++] = new TestCase(SECTION, "charCodeAt(100) >= 0", false, b);
    
        f_index = 1;
        b = (s.charCodeAt(f_index) == 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == 114", false, b);
        b = (114 == s.charCodeAt(f_index));
        array[item++] = new TestCase(SECTION, "114 = charCodeAt(1)", false, b);
        b = (s.charCodeAt(f_index) < 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < 114", true, b);
        b = (s.charCodeAt(f_index) <= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= 114", true, b);
        b = (s.charCodeAt(f_index) > 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > 114", false, b);
        b = (s.charCodeAt(f_index) >= 114);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= 114", false, b);
        
        b = (s.charCodeAt(f_index) == f_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) == f_index", false, b);
        b = (f_index == s.charCodeAt(f_index));
        array[item++] = new TestCase(SECTION, "f_index == charCodeAt(1)", false, b);
        b = (s.charCodeAt(f_index) < f_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) < f_index", false, b);
        b = (s.charCodeAt(f_index) <= f_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) <= f_index", false, b);
        b = (s.charCodeAt(f_index) > f_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) > f_index", true, b);
        b = (s.charCodeAt(f_index) >= f_index);
        array[item++] = new TestCase(SECTION, "charCodeAt(1) >= f_index", true, b);

        var val:int = 0;
        i_index = 0;
        switch (s.charAt(i_index))
        {
            case "a":
                val = 1;
                break;
            case "f":
                val = 6;
                break;
            default:
        }

        array[item++] = new TestCase(SECTION, "s.charAt(int) in switch", 6, val);

        u_index = 0;
        switch (s.charAt(u_index))
        {
            case "a":
                val = 1;
                break;
            case "f":
                val = 6;
                break;
            default:
        }

        array[item++] = new TestCase(SECTION, "s.charAt(uint) in switch", 6, val);

        f_index = 0;
        switch (s.charAt(f_index))
        {
            case "a":
                val = 1;
                break;
            case "f":
                val = 6;
                break;
            default:
        }

        array[item++] = new TestCase(SECTION, "s.charAt(Number) in switch", 6, val);

        return array;
    }


