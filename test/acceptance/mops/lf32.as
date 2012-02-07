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
    var TITLE:String   = "lf32";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("lf32(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ LF32(Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    AddErrorTest("lf32(-1)", RANGEERROR+1506, function(){ LF32(-1); });
    AddErrorTest("lf32(mem.length)", RANGEERROR+1506, function(){ LF32(mem.length); });
    AddErrorTest("lf32(mem.length-1)", RANGEERROR+1506, function(){ LF32(mem.length-1); });
    AddErrorTest("lf32(mem.length-2)", RANGEERROR+1506, function(){ LF32(mem.length-2); });
    AddErrorTest("lf32(mem.length-3)", RANGEERROR+1506, function(){ LF32(mem.length-3); });
    AddTestCase("lf32(mem.length-4)", 0, LF32(mem.length-4));

    SI32(0x41460200, 1); // 0x41460200 == 12.37548828125
    AddTestCase("lf32(1) loads do not need to be aligned", 12.37548828125, LF32(1));

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
        /**
         * 0x41460200 = 01000001 01000110 00000010 00000000
         * 12.37548828125
         */
        clearMemory();
        SI8(0x00, 0);
        SI8(0x02, 1);
        SI8(0x46, 2);
        SI8(0x41, 3);
        AddTestCase("lf32 load float written by si8()", 12.37548828125, LF32(0));
    }

    function testsi16():void
    {
        /**
         * 0x41460200 = 01000001 01000110 00000010 00000000
         * 12.37548828125
         */
        clearMemory();
        SI16(0x0200, 0);
        SI16(0x4146, 2);
        AddTestCase("lf32 load float written by si16()", 12.37548828125, LF32(0));
    }

    function testsi32():void
    {
        clearMemory();
        SI32(0x41460200, 0);
        AddTestCase("lf32 load float written by si32(0x41460200)", 12.37548828125, LF32(0));
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
        // Can't use hex representation here since asc will just treat it
        // as an int|Number and not as a float.
        clearMemory();
        SF32(12.37548828125, 0);
        AddTestCase("lf32 load float written by sf32(12.37548828125)", 12.37548828125, LF32(0));
    }

    function testsf64():void
    {
        /******************************************
         * 2.8846085099489688873291015625E6
         * 0x4146020041460200
         * sign = 0
         * exponent = 10000010100
         * mantissa = 0110000000100000000001000001010001100000001000000000
         *****************************************/
        clearMemory();
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("lf32 load 1st float written by sf64(0x4146020041460200)", 12.37548828125, LF32(4));
        AddTestCase("lf32 load 2nd float written by sf64(0x4146020041460200)", 12.37548828125, LF32(0));
    }

    function testwriteByte():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeByte(0x00);
        mem.writeByte(0x02);
        mem.writeByte(0x46);
        mem.writeByte(0x41);

        AddTestCase("lf32 load float written by writeByte()", 12.37548828125, LF32(0));
    }

    function testwriteBoolean():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeBoolean(true);
        mem.writeBoolean(false);
        mem.writeBoolean(false);
        mem.writeBoolean(true);

        AddTestCase("lf32 load float written by writeBoolean()", 2.3510604481259484465715043694E-38, LF32(0));
    }

    function testwriteInt():void
    {
        /******************************************
         * 1095107072 = 0x41460200
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeInt(1095107072);

        AddTestCase("lf32 load float written by writeInt(2147473647)", 12.37548828125, LF32(0));
    }

    function testwriteFloat():void
    {
        /******************************************
         * 12.375f
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeFloat(12.375);
        AddTestCase("lf32 load float written by writeFloat(12.375)", 12.375, LF32(0));
    }


    function testwriteDouble():void
    {
        /******************************************
         * 2.8846085099489688873291015625E6
         * 0x4146020041460200
         * sign = 0
         * exponent = 10000010100
         * mantissa = 0110000000100000000001000001010001100000001000000000
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeDouble(2.8846085099489688873291015625E6);
        AddTestCase("lf32 load 1st float written by writeDouble(2.8846085099489688873291015625E6)", 12.37548828125, LF32(4));
        AddTestCase("lf32 load 2nd float written by writeDouble(2.8846085099489688873291015625E6)", 12.37548828125, LF32(0));

    }

}
