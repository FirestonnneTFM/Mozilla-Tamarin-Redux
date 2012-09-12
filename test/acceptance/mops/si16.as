/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

//  Test indirect memory access instructions.

package {

    import flash.utils.ByteArray;
    import flash.utils.Endian;
    import avmplus.Domain;


    var SECTION = "mops";
    var VERSION = "AS3";
    var TITLE   = "si16";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("si16(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ SI16(0x0111, Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    /**
     * Test that ONLY the lowest 16 bits are stored
     */
    clearMemory();
    SI16(0x7F5A32, 0); // should only store 0x5A32
    // li16(1) should load 0x005A since memory is zereod
    AddTestCase("si16() only stores the least significant 16 bits", 0x005A, LI16(1));

    // Test the memory boundaries
    clearMemory();
    AddErrorTest("si16(0x0101, -1)", RANGEERROR+1506, function(){ SI16(0x0101, -1); });
    AddErrorTest("si16(0x0101, mem.length)", RANGEERROR+1506, function(){ SI16(0x0101, mem.length); });
    AddErrorTest("si16(0x0101, mem.length-1)", RANGEERROR+1506, function(){ SI16(0x0101, mem.length-1); });
    AddTestCase("si16(0x0101, mem.length-2)", undefined, SI16(0x0101, mem.length-2));
    AddTestCase("si16(0x0101FE, mem.length-2), should only store 16 bits so no overrun", undefined, SI16(0x0101FE, mem.length-2));
    AddTestCase("si16(0x0101FE, mem.length-2), should only store 16 bits so no overrun confirm", 0x01FE, LI16(mem.length-2));

    testli8();
    testli16();
    testli32();
    testlf32();
    testlf64();
    testreadByte();
    testreadUnsignedByte();
    testreadBoolean();
    testreadInt();
    testreadUnsignedInt();
    testreadFloat();
    testreadDouble();

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

    function testli8():void
    {
        clearMemory();
        SI16(0x807F, 0);
        AddTestCase("li8 load 1st byte written by si16(0x807F)", 0x7F, LI8(0));
        AddTestCase("li8 load 2nd byte written by si16(0x807F)", uint(0x80), LI8(1));
    }

    function testli16():void
    {
        clearMemory();
        SI16(0x80DE, 0);
        AddTestCase("li16 load bytes written by si16()", 0x80DE, LI16(0));
    }

    function testli32():void
    {
        clearMemory();
        SI16(0x80DE, 2);
        SI16(0x32F1, 0);
        AddTestCase("li32 load bytes written by si16()", int(0x80DE32F1), LI32(0));
    }

    function testlf32():void
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
        SI16(0x4146, 2);
        SI16(0x0000, 0);
        AddTestCase("lf32 load bytes written by si16()", 12.375, LF32(0));

    }

    function testlf64():void
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
        SI16(0x43E1, 6);
        SI16(0xC3ED, 4);
        SI16(0xA52E, 2);
        SI16(0x0C09, 0);
        AddTestCase("lf64 load bytes written by si16()", 1.0241024102410242048E19, LF64(0));
    }

    function testreadByte():void
    {
        clearMemory();
        SI16(0x007F, 0);
        SI16(0x80FF, 2);

        mem.position = 0;
        AddTestCase("readByte() load bytes written by si16(0x007F)", 0x7F, mem.readByte());
        AddTestCase("readByte() load bytes written by si16(0x007F)", 0, mem.readByte());
        AddTestCase("readByte() load bytes written by si16(0x80FF)", -1, mem.readByte());
        AddTestCase("readByte() load bytes written by si16(0x80FF)", -128, mem.readByte());
    }

    function testreadUnsignedByte():void
    {
        clearMemory();
        SI16(0x007F, 0);
        SI16(0x80FF, 2);

        mem.position = 0;
        AddTestCase("readUnsignedByte() load bytes written by si16(0x007F)", 127, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load bytes written by si16(0x007F)", 0, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load bytes written by si16(0x80FF)", 255, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load bytes written by si16(0x80FF)", 128, mem.readUnsignedByte());
    }


    function testreadBoolean():void
    {
        clearMemory();
        SI16(0x0100, 0);
        mem.position = 0;
        AddTestCase("readBoolean() load bytes written by si16(0x0100)", false, mem.readBoolean());
        AddTestCase("readBoolean() load bytes written by si16(0x0100)", true, mem.readBoolean());
    }

    function testreadInt():void
    {
        clearMemory();
        SI16(0x80DE, 2);
        SI16(0x32F1, 0);

        mem.position = 0;
        AddTestCase("readInt() load bytes written by si16()", int(0x80DE32F1), mem.readInt());
    }

    function testreadUnsignedInt():void
    {
        clearMemory();
        SI16(0x80DE, 2);
        SI16(0x32F1, 0);

        mem.position = 0;
        AddTestCase("readUnsignedInt() load bytes written by si16()", uint(0x80DE32F1), mem.readUnsignedInt());
    }

    function testreadFloat():void
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
        SI16(0x4146, 2);
        SI16(0x0000, 0);

        mem.position = 0;
        AddTestCase("readFloat() load bytes written by si16()", 12.375, mem.readFloat());
    }

    function testreadDouble():void
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
        SI16(0x43E1, 6);
        SI16(0xC3ED, 4);
        SI16(0xA52E, 2);
        SI16(0x0C09, 0);

        mem.position = 0;
        AddTestCase("readDouble() load bytes written by si16()", 1.0241024102410242048E19, mem.readDouble());
    }
}
