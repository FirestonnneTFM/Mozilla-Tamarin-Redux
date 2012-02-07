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
    var TITLE:String   = "lix16";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("lix16(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ LIX16(Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    AddErrorTest("lix16(-1)", RANGEERROR+1506, function(){ LIX16(-1); });
    AddErrorTest("lix16(mem.length)", RANGEERROR+1506, function(){ LIX16(mem.length); });
    AddErrorTest("lix16(mem.length-1)", RANGEERROR+1506, function(){ LIX16(mem.length-1); });
    AddTestCase("lix16(mem.length-2)", 0, LIX16(mem.length-2));

    testsi8();
    testsi16();
    testsi32();
    testwriteByte();
    testwriteInt();

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
        // 0x8000    -32768
        // 0xFFFF    -1
        // 0x7FFF    32767
        clearMemory();
        SI8(0x00, 0);
        SI8(0x80, 1);
        SI8(0xFF, 2);
        SI8(0xFF, 3);
        SI8(0xFF, 4);
        SI8(0x7F, 5);
        AddTestCase("lix16 load byte written by si8()", -32768, LIX16(0));
        AddTestCase("lix16 load byte written by si8()", -1, LIX16(2));
        AddTestCase("lix16 load byte written by si8()", 32767, LIX16(4));
    }

    function testsi16():void
    {
        // 0x8000    -32768
        // 0xFFFF    -1
        // 0x7FFF    32767
        clearMemory();
        SI16(0x8000, 0);
        SI16(0xFFFF, 2);
        SI16(0x7FFF, 4);
        AddTestCase("lix16 load bytes written by si16(0x8000)", -32768, LIX16(0));
        AddTestCase("lix16 load bytes written by si16(0xFFFF)", -1, LIX16(2));
        AddTestCase("lix16 load bytes written by si16(0x7FFF)", 32767, LIX16(4));
    }

    function testsi32():void
    {
        clearMemory();
        SI32(0x7FFF8000, 0);
        AddTestCase("lix16 load 1st short written by si32(0x7FFF8000)", -32768, LIX16(0));
        AddTestCase("lix16 load 2nd short written by si32(0x7FFF8000)", 32767, LIX16(2));
    }

    function testwriteByte():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeByte(0x00);
        mem.writeByte(0x80);
        mem.writeByte(0xFF);
        mem.writeByte(0x7F);

        AddTestCase("lix16 load bytes written by writeByte()", -32768, LIX16(0));
        AddTestCase("lix16 load bytes written by writeByte()", 32767, LIX16(2));
    }

    function testwriteInt():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeInt(2147450880);

        AddTestCase("lix16 load 1st short written by writeInt(2147450880)", -32768, LIX16(0));
        AddTestCase("lix16 load 2nd short written by writeInt(2147450880)", 32767, LIX16(2));
    }

}
