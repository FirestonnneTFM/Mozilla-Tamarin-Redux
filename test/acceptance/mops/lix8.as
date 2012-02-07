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
    var TITLE:String   = "lix8";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    AddErrorTest("lix8(Domain.MIN_DOMAIN_MEMORY_LENGTH) prior to initMemory()",
                 RANGEERROR+1506,
                 function(){ LIX8(Domain.MIN_DOMAIN_MEMORY_LENGTH); });

    initMemory();
    // Get a handle to the domainMemory after it is initialized
    var mem:ByteArray = Domain.currentDomain.domainMemory;

    AddErrorTest("lix8(-1)", RANGEERROR+1506, function(){ LIX8(-1); });
    AddErrorTest("lix8(mem.length)", RANGEERROR+1506, function(){ LIX8(mem.length); });
    AddTestCase("lix8(mem.length-1)", 0, LIX8(mem.length-1));

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
        clearMemory();
        SI8(0x7F, 0);
        SI8(0x80, 1);
        SI8(0xFF, 2);
        AddTestCase("lix8 load byte written by si8(0x7F)", 127, LIX8(0));
        AddTestCase("lix8 load byte written by si8(0x80)", -128, LIX8(1));
        AddTestCase("lix8 load byte written by si8(0xFF)", -1, LIX8(2));
    }

    function testsi16():void
    {
        clearMemory();
        SI16(0x7F80, 0);
        AddTestCase("lix8 load 1st byte written by si16(0x7F80)", 127, LIX8(1));
        AddTestCase("lix8 load 2nd byte written by si16(0x7F80)", -128, LIX8(0));
    }

    function testsi32():void
    {
        clearMemory();
        SI32(0x007F80FF, 0);
        AddTestCase("lix8 load 1st byte written by si32(0x007F80FF)", 0, LIX8(3));
        AddTestCase("lix8 load 2nd byte written by si32(0x007F80FF)", 127, LIX8(2));
        AddTestCase("lix8 load 3rd byte written by si32(0x007F80FF)", -128, LIX8(1));
        AddTestCase("lix8 load 4th byte written by si32(0x007F80FF)", -1, LIX8(0));
    }

    function testwriteByte():void
    {
        clearMemory();
        mem.position = 0;
        mem.writeByte(0);
        mem.writeByte(127);
        mem.writeByte(128);
        mem.writeByte(255);

        AddTestCase("lix8 load byte written by writeByte(0)", 0, LIX8(0));
        AddTestCase("lix8 load byte written by writeByte(127)", 127, LIX8(1));
        AddTestCase("lix8 load byte written by writeByte(128)", -128, LIX8(2));
        AddTestCase("lix8 load byte written by writeByte(255)", -1, LIX8(3));
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

        AddTestCase("lix8 load 1st byte written by writeInt(2147473647)", 127, LIX8(3));
        AddTestCase("lix8 load 2nd byte written by writeInt(2147473647)", -1, LIX8(2));
        AddTestCase("lix8 load 3rd byte written by writeInt(2147473647)", -40, LIX8(1));
        AddTestCase("lix8 load 4th byte written by writeInt(2147473647)", -17, LIX8(0));
    }

}
