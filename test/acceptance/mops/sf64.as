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


    var SECTION = "mops";
    var VERSION = "AS3";
    var TITLE   = "sf64";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    // 0x4146020041460200 == 2.8846085099489688873291015625E6
    AddErrorTest("sf64(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ SF64(2.8846085099489688873291015625E6, Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    // Test the memory boundaries
    clearMemory();
    AddErrorTest("sf64(0x4146020041460200, -1)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, -1); });
    AddErrorTest("sf64(0x4146020041460200, mem.length)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-1)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-1); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-2)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-2); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-3)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-3); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-4)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-4); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-5)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-5); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-6)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-6); });
    AddErrorTest("sf64(0x4146020041460200, mem.length-7)", RANGEERROR+1506, function(){ SF64(2.8846085099489688873291015625E6, mem.length-7); });

    AddTestCase("sf64(0x4146020041460200, mem.length-8)", undefined, SF64(0x4146020041460200, mem.length-8));

    testli8();
    testli16();
    testli32();
    testlf32();
    testlf64();
    testreadByte();
    testreadUnsignedByte();
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
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("li8 load 1st byte written by sf64()", uint(0x00), LI8(0));
        AddTestCase("li8 load 2nd byte written by sf64()", uint(0x02), LI8(1));
        AddTestCase("li8 load 3rd byte written by sf64()", uint(0x46), LI8(2));
        AddTestCase("li8 load 4th byte written by sf64()", uint(0x41), LI8(3));
        AddTestCase("li8 load 5th byte written by sf64()", uint(0x00), LI8(4));
        AddTestCase("li8 load 6th byte written by sf64()", uint(0x02), LI8(5));
        AddTestCase("li8 load 7th byte written by sf64()", uint(0x46), LI8(6));
        AddTestCase("li8 load 8th byte written by sf64()", uint(0x41), LI8(7));
    }

    function testli16():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("li16 load bytes written by sf64()", 0x0200, LI16(0));
        AddTestCase("li16 load bytes written by sf64()", 0x4146, LI16(2));
        AddTestCase("li16 load bytes written by sf64()", 0x0200, LI16(4));
        AddTestCase("li16 load bytes written by sf64()", 0x4146, LI16(6));
    }

    function testli32():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("li32 load bytes written by sf64()", int(0x41460200), LI32(0));
        AddTestCase("li32 load bytes written by sf64()", int(0x41460200), LI32(4));
    }

    function testlf32():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("lf32 load bytes written by sf64()", 12.37548828125, LF32(0));
        AddTestCase("lf32 load bytes written by sf64()", 12.37548828125, LF32(4));
    }

    function testlf64():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        AddTestCase("lf64 load bytes written by sf64()", 2.8846085099489688873291015625E6, LF64(0));
    }

    function testreadByte():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readByte() load 1st byte written by sf64()", 0x00, mem.readByte());
        AddTestCase("readByte() load 2nd byte written by sf64()", 0x02, mem.readByte());
        AddTestCase("readByte() load 3rd byte written by sf64()", 0x46, mem.readByte());
        AddTestCase("readByte() load 4th byte written by sf64()", 0x41, mem.readByte());
        AddTestCase("readByte() load 5th byte written by sf64()", 0x00, mem.readByte());
        AddTestCase("readByte() load 6th byte written by sf64()", 0x02, mem.readByte());
        AddTestCase("readByte() load 7th byte written by sf64()", 0x46, mem.readByte());
        AddTestCase("readByte() load 8th byte written by sf64()", 0x41, mem.readByte());
    }

    function testreadUnsignedByte():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readUnsignedByte() load 1st byte written by sf64()", 0x00, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 2nd byte written by sf64()", 0x02, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 3rd byte written by sf64()", 0x46, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 4th byte written by sf64()", 0x41, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 5th byte written by sf64()", 0x00, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 6th byte written by sf64()", 0x02, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 7th byte written by sf64()", 0x46, mem.readUnsignedByte());
        AddTestCase("readUnsignedByte() load 8th byte written by sf64()", 0x41, mem.readUnsignedByte());
    }

    function testreadInt():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readInt() load bytes written by sf64()", int(0x41460200), mem.readInt());
        AddTestCase("readInt() load bytes written by sf64()", int(0x41460200), mem.readInt());
    }

    function testreadUnsignedInt():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readUnsignedInt() load bytes written by sf64()", uint(0x41460200), mem.readUnsignedInt());
        AddTestCase("readUnsignedInt() load bytes written by sf64()", uint(0x41460200), mem.readUnsignedInt());
    }

    function testreadFloat():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readFloat() load bytes written by sf64()", 12.37548828125, mem.readFloat());
        AddTestCase("readFloat() load bytes written by sf64()", 12.37548828125, mem.readFloat());
    }

    function testreadDouble():void
    {
        clearMemory();
        // 0x4146020041460200 == 2.8846085099489688873291015625E6
        SF64(2.8846085099489688873291015625E6, 0);
        mem.position = 0;
        AddTestCase("readDouble() load bytes written by sf64()", 2.8846085099489688873291015625E6, mem.readDouble());
    }

}
