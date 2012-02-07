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
    var TITLE:String   = "lf64";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("lf64(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ LF64(Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    AddErrorTest("lf64(-1)", RANGEERROR+1506, function(){ LF64(-1); });
    AddErrorTest("lf64(mem.length)", RANGEERROR+1506, function(){ LF64(mem.length); });
    AddErrorTest("lf64(mem.length-1)", RANGEERROR+1506, function(){ LF64(mem.length-1); });
    AddErrorTest("lf64(mem.length-2)", RANGEERROR+1506, function(){ LF64(mem.length-2); });
    AddErrorTest("lf64(mem.length-3)", RANGEERROR+1506, function(){ LF64(mem.length-3); });
    AddErrorTest("lf64(mem.length-4)", RANGEERROR+1506, function(){ LF64(mem.length-4); });
    AddErrorTest("lf64(mem.length-5)", RANGEERROR+1506, function(){ LF64(mem.length-5); });
    AddErrorTest("lf64(mem.length-6)", RANGEERROR+1506, function(){ LF64(mem.length-6); });
    AddErrorTest("lf64(mem.length-7)", RANGEERROR+1506, function(){ LF64(mem.length-7); });
    AddTestCase("lf64(mem.length-8)", 0, LF64(mem.length-8));

    SI32(0x4237D796, 5); // 0x4237D796EFC00000 == 102401241024
    SI32(0xEFC00000, 1); // 0x4237D796EFC00000 == 102401241024
    AddTestCase("lf64(1) loads do not need to be aligned", 102401241024, LF64(1));

    testsi8();
    testsi16();
    testsi32();
    testsf32();
    testsf64();
    testwriteByte();
    //testwriteBoolean();
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
         * 0x4237D796EFC00000 = 102401241024
         */
        clearMemory();
        SI8(0x00, 0);
        SI8(0x00, 1);
        SI8(0xC0, 2);
        SI8(0xEF, 3);
        SI8(0x96, 4);
        SI8(0xD7, 5);
        SI8(0x37, 6);
        SI8(0x42, 7);
        AddTestCase("lf64 load double written by si8()", 102401241024, LF64(0));
    }

    function testsi16():void
    {
        /**
         * 0x4237D796EFC00000 = 102401241024
         */
        clearMemory();
        SI16(0x0000, 0);
        SI16(0xEFC0, 2);
        SI16(0xD796, 4);
        SI16(0x4237, 6);
        AddTestCase("lf64 load double written by si16()", 102401241024, LF64(0));
    }

    function testsi32():void
    {
        /**
         * 0x4237D796EFC00000 = 102401241024
         */
        clearMemory();
        SI32(0xEFC00000, 0);
        SI32(0x4237D796, 4);
        AddTestCase("lf64 load double written by si32()", 102401241024, LF64(0));
    }

    function testsf32():void
    {
        // Can't use hex representation here since asc will just treat it
        // as an int|Number and not as a float.
        clearMemory();
        SF32(12.37548828125, 0);
        SF32(12.37548828125, 4);
        AddTestCase("lf64 load double written by sf32()", 2884608.5099489688873291015625, LF64(0));
    }

    function testsf64():void
    {
        clearMemory();
        SF64(102401241024, 0);
        AddTestCase("lflf load double written by sf64(102401241024)", 102401241024, LF64(0));
    }

    function testwriteByte():void
    {
        /**
         * 0x4237D796EFC00000 = 102401241024
         */
        clearMemory();
        mem.position = 0;
        mem.writeByte(0x00);
        mem.writeByte(0x00);
        mem.writeByte(0xC0);
        mem.writeByte(0xEF);
        mem.writeByte(0x96);
        mem.writeByte(0xD7);
        mem.writeByte(0x37);
        mem.writeByte(0x42);

        AddTestCase("lf64 load double written by writeByte()", 102401241024, LF64(0));
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
         * 0x4237D796EFC00000 = 102401241024
         *****************************************/
        clearMemory();
        mem.position = 0;
        mem.writeInt(-272629760);  // 0xEFC00000
        mem.writeInt(1110955926);  // 0x4237D796

        AddTestCase("lf64 load double written by writeInt()", 102401241024, LF64(0));
    }

    function testwriteFloat():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeFloat(12.37548828125);
        mem.writeFloat(12.37548828125);
        AddTestCase("lf64 load double written by writeFloat(12.37548828125)", 2884608.5099489688873291015625, LF64(0));
    }


    function testwriteDouble():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeDouble(102401241024);
        AddTestCase("lf64 load double written by writeDouble(102401241024)", 102401241024, LF64(0));

    }
}
