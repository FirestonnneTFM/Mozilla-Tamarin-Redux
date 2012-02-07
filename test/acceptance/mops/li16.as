/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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

//  Test indirect memory access instructions.

package {

    import flash.utils.ByteArray;
    import flash.utils.Endian;
    import avmplus.Domain;


    var SECTION:String = "mops";
    var VERSION:String = "AS3";
    var TITLE:String   = "li16";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("li16(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ LI16(Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    AddErrorTest("li16(-1)", RANGEERROR+1506, function(){ LI16(-1); });
    AddErrorTest("li16(mem.length)", RANGEERROR+1506, function(){ LI16(mem.length); });
    AddErrorTest("li16(mem.length-1)", RANGEERROR+1506, function(){ LI16(mem.length-1); });
    AddTestCase("li16(mem.length-2)", 0, LI16(mem.length-2));

    SI16(0x7FDE, 1);
    AddTestCase("li16(1) loads do not need to be aligned", 0x7FDE, LI16(1));

    testsi8();
    testsi16();
    testsi32();
    testsf32();
    testsf64();
    testwriteByte();
    testwriteBoolean();
    testwriteInt();
    testwriteFloat();
    testwriteDouble();

    test();

    function initMemory(bytes:int = 0):void
    {
        var min:int = Domain.MIN_DOMAIN_MEMORY_LENGTH;
        var memory:ByteArray = new ByteArray();
        // memory opcodes use native endianness, but ByteArray defaults to BigEndian
        memory.endian = Endian.LITTLE_ENDIAN;
        memory.length = bytes > min ? bytes : min;
        Domain.currentDomain.domainMemory = memory;
    }

    function clearMemory():void
    {
        var i:int;
        var len:int = Domain.currentDomain.domainMemory.length;
        for ( i=0; i < len; i++)
            SI8(0x00, i);
    }

    function testsi8():void
    {
        clearMemory();
        SI8(0x7F, 0);
        SI8(0x80, 1);
        AddTestCase("li16 load short written by si8()", 0x807F, LI16(0));
    }

    function testsi16():void
    {
        clearMemory();
        SI16(0x80DE, 0);
        AddTestCase("li16 load short written by si16(0x80DE)", 0x80DE, LI16(0));
    }

    function testsi32():void
    {
        clearMemory();
        SI32(0x80DE32F1, 0);
        AddTestCase("li16 load 1st short written by si32(0x80DE32F1)", 0x80DE, LI16(2));
        AddTestCase("li16 load 2nd short written by si32(0x80DE32F1)", 0x32F1, LI16(0));
    }

    function testsf32():void
    {
        /******************************************
         * 12.375f
         * (12.375)10 =
         * (12)10 + (0.375)10 =
         * (1100)2 + (0.011)2 =
         * (1100.011)2 =
         * (1.100011)2 x2^3
         * sign = 0
         * exponent = 130 (127 biased, 127 +3, binary 1000 0010)
         * fraction = 100011
         * 0-10000010-10001100000000000000000
         * 01000001 01000110 00000000 00000000 -> int 1095106560 -> 0x41460000
         *****************************************/
        clearMemory();
        SF32(12.375, 0);
        AddTestCase("li16 load 1st short written by sf32(12.375)", 0x4146, LI16(2));
        AddTestCase("li16 load 2nd short written by sf32(12.375)", 0x0000, LI16(0));
    }

    function testsf64():void
    {
        /******************************************
         * 10241024102410241024
         * 0x43E1C3EDA52E0C09
         * sign = 0
         * exponent = 10000111110
         * mantissa = 0001110000111110110110100101001011100000110000001001
         * 0x43E1C3EDA52E0C09 =
         * 01000011 11100001 11000011 11101101
         * 10100101 00101110 00001100 00001001
         *****************************************/
        clearMemory();
        SF64(1.0241024102410242048E19, 0);
        AddTestCase("li16 load 1st short written by sf64(10241024102410241024)", 0x43E1, LI16(6));
        AddTestCase("li16 load 2nd short written by sf64(10241024102410241024)", 0xC3ED, LI16(4));
        AddTestCase("li16 load 3rd short written by sf64(10241024102410241024)", 0xA52E, LI16(2));
        AddTestCase("li16 load 4th short written by sf64(10241024102410241024)", 0x0C09, LI16(0));
    }

    function testwriteByte():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeByte(127);
        mem.writeByte(128);

        AddTestCase("li16 load short written by writeByte()", 0x807F, LI16(0));
    }

    function testwriteBoolean():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeBoolean(false);
        mem.writeBoolean(true);

        AddTestCase("li16 load short written by writeBoolean()", 0x0100, LI16(0));
    }

    function testwriteInt():void
    {
        /******************************************
         * 2147473647 = 0x7FFFD8EF = 01111111 11111111 11011000 11101111
         * 01111111 = 127 = 0x7F
         * 11111111 = 255 = 0xFF
         * 11011000 = 216 = 0xD8
         * 11101111 = 239 = 0xEF
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeInt(2147473647);

        AddTestCase("li16 load 1st short written by writeInt(2147473647)", 0x7FFF, LI16(2));
        AddTestCase("li16 load 2nd short written by writeInt(2147473647)", 0xD8EF, LI16(0));
    }

    function testwriteFloat():void
    {
        /******************************************
         * 12.375f
         * (12.375)10 =
         * (12)10 + (0.375)10 =
         * (1100)2 + (0.011)2 =
         * (1100.011)2 =
         * (1.100011)2 x2^3
         * sign = 0
         * exponent = 130 (127 biased, 127 +3, binary 1000 0010)
         * fraction = 100011
         * 0-10000010-10001100000000000000000
         * 01000001 01000110 00000000 00000000 -> int 1095106560 -> 0x41460000
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeFloat(12.375);
        AddTestCase("li16 load 1st short written by writeFloat(12.375)", 0x4146, LI16(2));
        AddTestCase("li16 load 2nd short written by writeFloat(12.375)", 0x0000, LI16(0));
    }


    function testwriteDouble():void
    {
        /******************************************
         * 10241024102410241024
         * 0x43E1C3EDA52E0C09
         * sign = 0
         * exponent = 10000111110
         * mantissa = 0001110000111110110110100101001011100000110000001001
         * 0x43E1C3EDA52E0C09 =
         * 01000011 11100001 11000011 11101101
         * 10100101 00101110 00001100 00001001
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeDouble(1.0241024102410242048E19);
        AddTestCase("li16 load 1st short written by writeDouble(1.0241024102410242048E19)", 0x43E1, LI16(6));
        AddTestCase("li16 load 2nd short written by writeDouble(1.0241024102410242048E19)", 0xC3ED, LI16(4));
        AddTestCase("li16 load 3rd short written by writeDouble(1.0241024102410242048E19)", 0xA52E, LI16(2));
        AddTestCase("li16 load 4th short written by writeDouble(1.0241024102410242048E19)", 0x0C09, LI16(0));

    }

}
