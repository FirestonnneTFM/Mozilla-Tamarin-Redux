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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=598683
*
*/
//-----------------------------------------------------------------------------

var SECTION = "593383";
var VERSION = "";
var TITLE   = "Testing various cases where we may optimize charCodeAt";
var bug = "593383";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {

    var actual:String;
    try
    {
        var xml:XML=new XML("<a><b:c xmlns:b=\"abc\"></d:c></a>") ;
        actual = xml.toXMLString();
    }
    catch(e)
    {
        actual = grabError(e, e.toString());
    }
    
    var expect:String= "Error #1085"; // kXMLUnterminatedElementTag

    var array = new Array();
    var index = 0;
    
    var s:String = "simple";

    // test optimizeIntCmpWithNumberCall logic with int charCodeAt(int)
    function testInt(outofbounds:int, inbounds:int)
    {
        var b1:Boolean;
        var b2:Boolean;
        var b3:Boolean;
        var b4:Boolean;
        var b5:Boolean;
        var b6:Boolean;
        
        // test out of bounds charCodeAt which will return NaN (or zero after an integer coerce)
        
        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 10);
        b2 = (10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 10);
        b4 = (s.charCodeAt(outofbounds) <= 10);
        b5 = (s.charCodeAt(outofbounds) > 10);
        b6 = (s.charCodeAt(outofbounds) >= 10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 10", b1, false);
        array[index++] = new TestCase(SECTION, "10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 10", b5, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == -10);
        b2 = (-10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < -10);
        b4 = (s.charCodeAt(outofbounds) <= -10);
        b5 = (s.charCodeAt(outofbounds) > -10);
        b6 = (s.charCodeAt(outofbounds) >= -10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == -10", b1, false);
        array[index++] = new TestCase(SECTION, "-10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < -10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= -10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > -10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= -10", b6, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 0);
        b2 = (0 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 0);
        b4 = (s.charCodeAt(outofbounds) <= 0);
        b5 = (s.charCodeAt(outofbounds) > 0);
        b6 = (s.charCodeAt(outofbounds) >= 0);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 0", b1, false);
        array[index++] = new TestCase(SECTION, "0 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 0", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 0", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 0", b6, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 0 THIS ONE", b5, false);

        // s.charCodeAt(1) == 105.  Using constant for compare
        b1 = (s.charCodeAt(inbounds) == 105);
        b2 = (105 == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < 105);
        b4 = (s.charCodeAt(inbounds) <= 105);
        b5 = (s.charCodeAt(inbounds) > 105);
        b6 = (s.charCodeAt(inbounds) >= 105);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == 105", b1, true);
        array[index++] = new TestCase(SECTION, "105 == s.charCodeAt(1)", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < 105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= 105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > 105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= 105", b6, true);

        var i:int = s.charCodeAt(inbounds);
        b1 = (s.charCodeAt(inbounds) == i);
        b2 = (i == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < i);
        b4 = (s.charCodeAt(inbounds) <= i);
        b5 = (s.charCodeAt(inbounds) > i);
        b6 = (s.charCodeAt(inbounds) >= i);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == i, i=105", b1, true);
        array[index++] = new TestCase(SECTION, "i == s.charCodeAt(1),i=105", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < i,i=105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= i,i=105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > i,i=105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= i,i=105", b6, true);
    }
    testInt(100,1);

    // test optimizeIntCmpWithNumberCall logic with int charCodeAt(uint)
    function testUint(outofbounds:uint, inbounds:uint)
    {
        var b1:Boolean;
        var b2:Boolean;
        var b3:Boolean;
        var b4:Boolean;
        var b5:Boolean;
        var b6:Boolean;
        
        // test out of bounds charCodeAt which will return NaN (or zero after an integer coerce)
        
        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 10);
        b2 = (10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 10);
        b4 = (s.charCodeAt(outofbounds) <= 10);
        b5 = (s.charCodeAt(outofbounds) > 10);
        b6 = (s.charCodeAt(outofbounds) >= 10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 10", b1, false);
        array[index++] = new TestCase(SECTION, "10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 10", b5, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == -10);
        b2 = (-10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < -10);
        b4 = (s.charCodeAt(outofbounds) <= -10);
        b5 = (s.charCodeAt(outofbounds) > -10);
        b6 = (s.charCodeAt(outofbounds) >= -10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == -10", b1, false);
        array[index++] = new TestCase(SECTION, "-10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < -10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= -10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > -10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= -10", b6, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 0);
        b2 = (0 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 0);
        b4 = (s.charCodeAt(outofbounds) <= 0);
        b5 = (s.charCodeAt(outofbounds) > 0);
        b6 = (s.charCodeAt(outofbounds) >= 0);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 0", b1, false);
        array[index++] = new TestCase(SECTION, "0 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 0", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 0", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 0", b6, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 0 THIS ONE", b5, false);

        // s.charCodeAt(1) == 105.  Using constant for compare
        b1 = (s.charCodeAt(inbounds) == 105);
        b2 = (105 == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < 105);
        b4 = (s.charCodeAt(inbounds) <= 105);
        b5 = (s.charCodeAt(inbounds) > 105);
        b6 = (s.charCodeAt(inbounds) >= 105);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == 105", b1, true);
        array[index++] = new TestCase(SECTION, "105 == s.charCodeAt(1)", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < 105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= 105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > 105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= 105", b6, true);

        var i:int = s.charCodeAt(inbounds);
        b1 = (s.charCodeAt(inbounds) == i);
        b2 = (i == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < i);
        b4 = (s.charCodeAt(inbounds) <= i);
        b5 = (s.charCodeAt(inbounds) > i);
        b6 = (s.charCodeAt(inbounds) >= i);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == i, i=105", b1, true);
        array[index++] = new TestCase(SECTION, "i == s.charCodeAt(1),i=105", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < i,i=105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= i,i=105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > i,i=105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= i,i=105", b6, true);
    }
    testUint(100,1);

    // test optimizeIntCmpWithNumberCall logic with int charCodeAt(double)
    function testDouble(outofbounds:Number, inbounds:Number)
    {
        var b1:Boolean;
        var b2:Boolean;
        var b3:Boolean;
        var b4:Boolean;
        var b5:Boolean;
        var b6:Boolean;
        
        // test out of bounds charCodeAt which will return NaN (or zero after an integer coerce)
        
        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 10);
        b2 = (10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 10);
        b4 = (s.charCodeAt(outofbounds) <= 10);
        b5 = (s.charCodeAt(outofbounds) > 10);
        b6 = (s.charCodeAt(outofbounds) >= 10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 10", b1, false);
        array[index++] = new TestCase(SECTION, "10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 10", b5, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == -10);
        b2 = (-10 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < -10);
        b4 = (s.charCodeAt(outofbounds) <= -10);
        b5 = (s.charCodeAt(outofbounds) > -10);
        b6 = (s.charCodeAt(outofbounds) >= -10);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == -10", b1, false);
        array[index++] = new TestCase(SECTION, "-10 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < -10", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= -10", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > -10", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= -10", b6, false);

        // NaN should not equal any of these
        b1 = (s.charCodeAt(outofbounds) == 0);
        b2 = (0 == s.charCodeAt(outofbounds));
        b3 = (s.charCodeAt(outofbounds) < 0);
        b4 = (s.charCodeAt(outofbounds) <= 0);
        b5 = (s.charCodeAt(outofbounds) > 0);
        b6 = (s.charCodeAt(outofbounds) >= 0);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) == 0", b1, false);
        array[index++] = new TestCase(SECTION, "0 == s.charCodeAt(100)", b2, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) < 0", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) <= 0", b4, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) > 0", b6, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(100) >= 0 THIS ONE", b5, false);

        // s.charCodeAt(1) == 105.  Using constant for compare
        b1 = (s.charCodeAt(inbounds) == 105);
        b2 = (105 == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < 105);
        b4 = (s.charCodeAt(inbounds) <= 105);
        b5 = (s.charCodeAt(inbounds) > 105);
        b6 = (s.charCodeAt(inbounds) >= 105);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == 105", b1, true);
        array[index++] = new TestCase(SECTION, "105 == s.charCodeAt(1)", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < 105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= 105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > 105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= 105", b6, true);

        var i:int = s.charCodeAt(inbounds);
        b1 = (s.charCodeAt(inbounds) == i);
        b2 = (i == s.charCodeAt(inbounds));
        b3 = (s.charCodeAt(inbounds) < i);
        b4 = (s.charCodeAt(inbounds) <= i);
        b5 = (s.charCodeAt(inbounds) > i);
        b6 = (s.charCodeAt(inbounds) >= i);
        
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == i, i=105", b1, true);
        array[index++] = new TestCase(SECTION, "i == s.charCodeAt(1),i=105", b2, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < i,i=105", b3, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= i,i=105", b4, true);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > i,i=105", b5, false);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= i,i=105", b6, true);
    }
    testDouble(100.1,1.1);

    // Testing our code to swap a float returning charCodeAt to integer (Specializer)
    // passing in params to avoid constant folding
    function test2(i:int, ui:uint, d:Number, expectedInt:int, expectedDouble:Number)
    {
        var i1:int = s.charCodeAt(i);
        var i2:int = s.charCodeAt(ui);
        var i3:int = s.charCodeAt(d);
        var f1:Number = s.charCodeAt(i);
        var f2:Number = s.charCodeAt(ui);
        var f3:Number = s.charCodeAt(d);

        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) == i, i=105", i1, expectedInt);
        array[index++] = new TestCase(SECTION, "i == s.charCodeAt(1),i=105", i2, expectedInt);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) < i,i=105", i3, expectedInt);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) <= i,i=105", f1, expectedDouble);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) > i,i=105", f2, expectedDouble);
        array[index++] = new TestCase(SECTION, "s.charCodeAt(1) >= i,i=105", f3, expectedDouble);
        
    }
    test2(1, 1, 1, 105, 105);
    test2(-1,-1,-1, 0, NaN);
    test2(100,100,100, 0, NaN);
    
    return array;
}
