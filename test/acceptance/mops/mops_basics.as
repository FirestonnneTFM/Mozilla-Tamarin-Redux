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


    var SECTION:String = "Actionscript";
    var VERSION:String = "AS3";
    var TITLE:String   = "Memory Opcodes";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var inPlayer:Boolean = false;

    function getDomainClass():Class
    {
        var ns:Namespace;

        try
        {
            ns = new Namespace("avmplus");
            return ns::["Domain"];
        }
        catch(e:*) {}
        try
        {
            ns = new Namespace("flash.system");
            var result:Class = ns::["ApplicationDomain"];
            inPlayer = true;
            return result;
        }
        catch(e:*) {}
        return null;
    }

    function getByteArrayClass():Class
    {
        var ns:Namespace = new Namespace("flash.utils");

        try
        {
            return (ns::["ByteArray"]);
        }
        catch(e:*) {}
        return null;
    }

    var domainClass:Class = getDomainClass();
    AddTestCase("domainClass != null", true, domainClass != null);

    var byteArrayClass:Class = getByteArrayClass();
    AddTestCase("byteArrayClass != null", true, byteArrayClass != null);

    var currentDomain:Object = domainClass.currentDomain;
    AddTestCase("currentDomain != null", true, currentDomain != null);

    var minMemSize:uint = domainClass.MIN_DOMAIN_MEMORY_LENGTH;
    AddTestCase("minMemSize >= 8", true, minMemSize >= 8);

    AddTestCase("currentDomain.domainMemory == null", true, currentDomain.domainMemory == null);


    var ba:Object;

    var emptyByteArrayOk:Boolean = false;

    ba = new byteArrayClass();
    try
    {
        currentDomain.domainMemory = ba;
        emptyByteArrayOk = true;
    }
    catch(e:*) {}

    AddTestCase("Empty byte array ok", false, emptyByteArrayOk);

    var smallByteArrayOk:Boolean = false;

    ba = new byteArrayClass();
    ba.length = domainClass.MIN_DOMAIN_MEMORY_LENGTH - 1;

    try
    {
        currentDomain.domainMemory = ba;
        smallByteArrayOk = true;
    }
    catch(e:*) {}

    AddTestCase("Small byte array ok", false, smallByteArrayOk);

    var wrongObj1Ok:Boolean = false;

    try
    {
        currentDomain.domainMemory = [];
        wrongObj1Ok = true;
    }
    catch(e:*) {}

    AddTestCase("Wrong obj (Array) ok", false, wrongObj1Ok);

    var wrongObj2Ok:Boolean = false;

    try
    {
        currentDomain.domainMemory = {};
        wrongObj2Ok = true;
    }
    catch(e:*) {}

    AddTestCase("Wrong obj (Object) ok", false, wrongObj2Ok);

    var wrongObj3Ok:Boolean = false;

    try
    {
        currentDomain.domainMemory = function(i:int):int { return i; };
        wrongObj3Ok = true;
    }
    catch(e:*) {}

    AddTestCase("Wrong obj (Function) ok", false, wrongObj3Ok);

    var wrongObj4Ok:Boolean = false;

    class UserClass1
    {
    };

    try
    {
        currentDomain.domainMemory = new UserClass1;
        wrongObj4Ok = true;
    }
    catch(e:*) {}

    AddTestCase("Wrong obj (user) ok", false, wrongObj4Ok);

    var minSizedByteArrayOk:Boolean = false;

    ba = new byteArrayClass();
    ba.length = domainClass.MIN_DOMAIN_MEMORY_LENGTH;

    try
    {
        currentDomain.domainMemory = ba;
        minSizedByteArrayOk = true;
    }
    catch(e:*) {}

    AddTestCase("Min sized byte array ok", true, minSizedByteArrayOk);


    var longTests:Array = [];

    function readTest(salt:Number, size:int, baWrite:Function, baRead:Function, op:Function)
    {
        currentDomain.domainMemory.endian = "littleEndian";

        var len:uint = currentDomain.domainMemory.length - size;
        var n:int;
        var e:Array = [];

        for(var offs:int = 0; offs < size; offs++)
        {
            for(n = offs; n <= len; n += size)
            {
                currentDomain.domainMemory.position = n;
                baWrite(n+salt);
                currentDomain.domainMemory.position = n;
                e[n] = baRead();
            }
            for(n = offs; n <= len; n += size)
            {
                if(op(n) != e[n])
                    return false;
            }
        }
        return true;
    }

    function readTestByte(salt:int):Boolean
    {
        return readTest(salt, 1,
                        currentDomain.domainMemory.writeByte,
                        currentDomain.domainMemory.readUnsignedByte,
                        function(addr:int):int { return LI8(addr); }
                        );
    }

    function readTestByteSX(salt:int):Boolean
    {
        return readTest(salt, 1,
                        currentDomain.domainMemory.writeByte,
                        currentDomain.domainMemory.readByte,
                        function(addr:int):int { return LIX8(addr); }
                        );
    }


    function readTestShort(salt:int):Boolean
    {
        return readTest(salt, 2,
                        currentDomain.domainMemory.writeShort,
                        currentDomain.domainMemory.readUnsignedShort,
                        function(addr:int):int { return LI16(addr); }
                        );
    }

    function readTestShortSX(salt:int):Boolean
    {
        return readTest(salt, 2,
                        currentDomain.domainMemory.writeShort,
                        currentDomain.domainMemory.readShort,
                        function(addr:int):int { return LIX16(addr); }
                        );
    }

    function readTestInt(salt:int):Boolean
    {
        return readTest(salt, 4,
                        currentDomain.domainMemory.writeInt,
                        currentDomain.domainMemory.readInt,
                        function(addr:int):int { return LI32(addr); }
                        );
    }

    function readTestFloat(salt:Number):Boolean
    {
        return readTest(salt, 4,
                        currentDomain.domainMemory.writeFloat,
                        currentDomain.domainMemory.readFloat,
                        function(addr:int):Number { return LF32(addr); }
                        );
    }

    function readTestDouble(salt:Number):Boolean
    {
        return readTest(salt, 8,
                        currentDomain.domainMemory.writeDouble,
                        currentDomain.domainMemory.readDouble,
                        function(addr:int):Number { return LF64(addr); }
                        );
    }


    longTests.push(function():void {
            AddTestCase("Read test byte w/ min sized", true, readTestByte(12));
            AddTestCase("Read test byte w/ sign extend w/ min sized", true, readTestByteSX(-21));
            AddTestCase("Read test short w/ min sized", true, readTestShort(3456));
            AddTestCase("Read test short w/ sign extend w/ min sized", true, readTestShortSX(-6543));
            AddTestCase("Read test int w/ min sized", true, readTestInt(567890));
            AddTestCase("Read test float w/ min sized", true, readTestFloat(12.34));
            AddTestCase("Read test double w/ min sized", true, readTestDouble(34.56));
        });



    function writeTest(salt:Number, size:int, test:Function, baRead:Function, op:Function):Boolean
    {
        currentDomain.domainMemory.endian = "littleEndian";

        var len:uint = currentDomain.domainMemory.length - size;
        var n:int;
        var v:*;

        for(var offs:int = 0; offs < size; offs++)
        {
            for(n = offs; n <= len; n += size)
            {
                op(n+salt, n);
            }
            for(n = offs; n <= len; n += size)
            {
                currentDomain.domainMemory.position = n;
                if(!test(baRead(), n+salt))
                    return false;
            }
        }
        return true;
    }

    function writeTestByte(salt:int):Boolean
    {
        return writeTest(salt, 1,
                         function(a:int, b:int):Boolean { return (a&0xff) == (b&0xff); },
                         currentDomain.domainMemory.readUnsignedByte,
                         function(v:int, n:int):void { SI8(v, n); }
                         );
    }

    function writeTestShort(salt:int):Boolean
    {
        return writeTest(salt, 2,
                         function(a:int, b:int):Boolean { return (a&0xffff) == (b&0xffff); },
                         currentDomain.domainMemory.readUnsignedShort,
                         function(v:int, n:int):void { SI16(v, n); }
                         );
}

    function writeTestInt(salt:int):Boolean
    {
        return writeTest(salt, 4,
                         function(a:int, b:int):Boolean { return a == b; },
                         currentDomain.domainMemory.readInt,
                         function(v:int, n:int):void { SI32(v, n); }
                         );
    }

    function writeTestFloat(salt:Number):Boolean
    {
        return writeTest(salt, 4,
                         function(a:Number, b:Number):Boolean { return Math.abs(a-b)<0.0001; },
                         currentDomain.domainMemory.readFloat,
                         function(v:Number, n:int):void { SF32(v, n); }
                         );
    }

    function writeTestDouble(salt:Number):Boolean
    {
        return writeTest(salt, 8,
                         function(a:Number, b:Number):Boolean { return Math.abs(a-b)<0.0001; },
                         currentDomain.domainMemory.readDouble,
                         function(v:Number, n:int):void { SF64(v, n); }
                         );
    }

    longTests.push(function():void {
            AddTestCase("Write test byte w/ min sized", true, writeTestByte(12));
            AddTestCase("Write test short w/ min sized", true, writeTestShort(3456));
            AddTestCase("Write test int w/ min sized", true, writeTestInt(567890));
            AddTestCase("Write test float w/ min sized", true, writeTestFloat(12.34));
            AddTestCase("Write test double w/ min sized", true, writeTestDouble(34.56));
        });

    function writeBytes(salt:int):void
    {
        var len:uint = currentDomain.domainMemory ? currentDomain.domainMemory.length :
                                                    domainClass.MIN_DOMAIN_MEMORY_LENGTH;

        var n:int;
        var v:int;

        // byte test
        for(n = 0; n < len; n += 1)
        {
            v = (n + salt) & 0xff;

            SI8(v, n);
        }
    }

    function verifyBytes(salt:int):Boolean
    {
        var len:uint = currentDomain.domainMemory ? currentDomain.domainMemory.length :
                                                    domainClass.MIN_DOMAIN_MEMORY_LENGTH;

        var n:int;
        var v:int;

        // byte test
        for(n = 0; n < len; n += 1)
        {
            v = (n + salt) & 0xff;

            if(LI8(n) != v)
                return false;
        }
        return true;
    }

    longTests.push(function():void {
            writeBytes(12);
            AddTestCase("Write min / verify min", true, verifyBytes(12));
        });

    longTests.push(function():void {
            ba = currentDomain.domainMemory;
            currentDomain.domainMemory = null;
            AddTestCase("Write min / verify scratch", false, verifyBytes(12));
        });

    longTests.push(function():void {
            writeBytes(34);
            AddTestCase("Write scratch / verify scratch", true, verifyBytes(34));
        });

    longTests.push(function():void {
            currentDomain.domainMemory = ba;
            AddTestCase("Write scratch / verify min", false, verifyBytes(34));
        });


    function rangeTest(size:int, f:Function):Boolean
    {
        var len:uint = currentDomain.domainMemory ? currentDomain.domainMemory.length :
                                                    domainClass.MIN_DOMAIN_MEMORY_LENGTH;

        var n:int;
        var v:int;
        var fails:Array = [];

        for(n = -10000; n < len + 10000; n += 1)
        {
            try
            {
                f(n);
            }
            catch(e:*)
            {
                fails.push(n);
            }
        }
        if(fails.length == 20000 + size - 1)
        {
            for(n = 0; n < 10000; n++)
                if(fails[n] != -10000 + n)
                    return false;
            for(n = 0; n < 10000 + size - 1; n++)
                if(fails[n + 10000] != len + n - (size - 1))
                {
                    print("fails[n + 10000]: " + fails[n + 10000]);
                    print("len:" + len);
                    print("size:" + size);
                    print("n:" + n);
                    return false;
                }
            return true;
        }
        return false;
    }

    function rangeReadTestByte():Boolean
    {
        return rangeTest(1, function(n:int):void { LI8(n); } );
    }

    function rangeOffsReadTestByte():Boolean
    {
        return rangeTest(1, function(n:int):void { var k:int = n - 4; LI8(ADD_I(k, 4)); }) &&
               rangeTest(1, function(n:int):void { var k:int = n + 4; LI8(SUBTRACT_I(k, 4)); }) &&
               rangeTest(1, function(n:int):void { var k:int = n + 4; LI8(ADD_I(k, -4)); }) &&
               rangeTest(1, function(n:int):void { var k:int = n - 4; LI8(SUBTRACT_I(k, -4)); });
    }


    function rangeReadTestShort():Boolean
    {
        return rangeTest(2, function(n:int):void { LI16(n); } );
    }

    function rangeOffsReadTestShort():Boolean
    {
        return rangeTest(2, function(n:int):void { var k:int = n - 4; LI16(ADD_I(k, 4)); }) &&
               rangeTest(2, function(n:int):void { var k:int = n + 4; LI16(SUBTRACT_I(k, 4)); }) &&
               rangeTest(2, function(n:int):void { var k:int = n + 4; LI16(ADD_I(k, -4)); }) &&
               rangeTest(2, function(n:int):void { var k:int = n - 4; LI16(SUBTRACT_I(k, -4)); });
    }

    function rangeReadTestInt():Boolean
    {
        return rangeTest(4, function(n:int):void { LI32(n); } );
    }

    function rangeOffsReadTestInt():Boolean
    {
        return rangeTest(4, function(n:int):void { var k:int = n - 4; LI32(ADD_I(k, 4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n + 4; LI32(SUBTRACT_I(k, 4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n + 4; LI32(ADD_I(k, -4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n - 4; LI32(SUBTRACT_I(k, -4)); });
    }

    function rangeReadTestFloat():Boolean
    {
        return rangeTest(4, function(n:int):void { LF32(n); } );
    }

    function rangeOffsReadTestFloat():Boolean
    {
        return rangeTest(4, function(n:int):void { var k:int = n - 4; LF32(ADD_I(k, 4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n + 4; LF32(SUBTRACT_I(k, 4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n + 4; LF32(ADD_I(k, -4)); }) &&
               rangeTest(4, function(n:int):void { var k:int = n - 4; LF32(SUBTRACT_I(k, -4)); });
    }

    function rangeReadTestDouble():Boolean
    {
        return rangeTest(8, function(n:int):void { LF64(n); } );
    }

    function rangeOffsReadTestDouble():Boolean
    {
        return rangeTest(8, function(n:int):void { var k:int = n - 4; LF64(ADD_I(k, 4)); }) &&
               rangeTest(8, function(n:int):void { var k:int = n + 4; LF64(SUBTRACT_I(k, 4)); }) &&
               rangeTest(8, function(n:int):void { var k:int = n + 4; LF64(ADD_I(k, -4)); }) &&
               rangeTest(8, function(n:int):void { var k:int = n - 4; LF64(SUBTRACT_I(k, -4)); });
    }

    longTests.push(function():void {
            AddTestCase("Range read test byte min", true, rangeReadTestByte());
            AddTestCase("Range offs read test byte min", true, rangeOffsReadTestByte());
            AddTestCase("Range read test short min", true, rangeReadTestShort());
            AddTestCase("Range offs read test short min", true, rangeOffsReadTestShort());
            AddTestCase("Range read test int min", true, rangeReadTestInt());
            AddTestCase("Range offs read test int min", true, rangeOffsReadTestInt());
            AddTestCase("Range read test float min", true, rangeReadTestFloat());
            AddTestCase("Range offs read test float min", true, rangeOffsReadTestFloat());
            AddTestCase("Range read test double min", true, rangeReadTestDouble());
            AddTestCase("Range offs read test double min", true, rangeOffsReadTestDouble());
        });


    function rangeReadTestWide():Boolean
    {
        return rangeTest(2009, function(n:int):void {
                var n2:int = n + 1004;
                LI8(SUBTRACT_I(n2, 1004));
                LI8(ADD_I(n2, 1004));
            } );
    }
    longTests.push(function():void{
            var oldLen:uint = currentDomain.domainMemory.length;
            currentDomain.domainMemory.length = 16384;
            AddTestCase("Range read test wide", true, rangeReadTestWide());
            currentDomain.domainMemory.length = oldLen;
        });


    function rangeWriteTestByte():Boolean
    {
        return rangeTest(1, function(n:int):void { SI8(-1, n); } );
    }

    function rangeWriteTestShort():Boolean
    {
        return rangeTest(2, function(n:int):void { SI16(-1, n); } );
    }

    function rangeWriteTestInt():Boolean
    {
        return rangeTest(4, function(n:int):void { SI32(-1, n); } );
    }

    function rangeWriteTestFloat():Boolean
    {
        return rangeTest(4, function(n:int):void { SF32(-1, n); } );
    }

    function rangeWriteTestDouble():Boolean
    {
        return rangeTest(8, function(n:int):void { SF64(-1, n); } );
    }

    longTests.push(function():void {
            AddTestCase("Range write test byte min", true, rangeWriteTestByte());
            AddTestCase("Range write test short min", true, rangeWriteTestShort());
            AddTestCase("Range write test int min", true, rangeWriteTestInt());
            AddTestCase("Range write test float min", true, rangeWriteTestFloat());
            AddTestCase("Range write test double min", true, rangeWriteTestDouble());
        });


    function rangeWriteTestWide():Boolean
    {
        return rangeTest(2009, function(n:int):void {
                var n2:int = n + 1004;
                SI8(-1, SUBTRACT_I(n2, 1004));
                SI8(-1, ADD_I(n2, 1004));
            } );
    }

    longTests.push(function():void {
            var oldLen:uint = currentDomain.domainMemory.length;
            currentDomain.domainMemory.length = 16384;
            AddTestCase("Range write test wide", true, rangeWriteTestWide());
            currentDomain.domainMemory.length = oldLen;
        });


    function genRangeTest(min:int, max:int, f:Function):Boolean
    {
        for(var n:int = min; n < max; n++)
            if(!f(n))
                return false;
        return true;
    }

    function sextTest():Boolean
    {
        return genRangeTest(0x6000, 0x12000, function(n:int):Boolean
                            {
                                var sx16:int = (n << 16) >> 16;
                                var sx8:int = (n << 24) >> 24;
                                var sx1:int = (n << 31) >> 31;

                                if(sx16 != SXI16(n))
                                    return false;
                                if(sx8 != SXI8(n))
                                    return false;
                                if(sx1 != SXI1(n))
                                    return false;
                                return true;
                            }
                            );
    }

    longTests.push(function():void {
            AddTestCase("Sign extend test", true, sextTest());
        });

    function readWriteTest(size:int, f:Function):Boolean
    {
        var len:uint = currentDomain.domainMemory ? currentDomain.domainMemory.length :
                                                    domainClass.MIN_DOMAIN_MEMORY_LENGTH;
        return genRangeTest(0, len - size + 1, f);
    }

    function readWriteTestByte(salt:int):Boolean
    {
        return readWriteTest(1, function(n:int):Boolean
                             {
                                 var v:int = (n + salt) & 0xff;
                                 SI8(v, n);
                                 return LI8(n) == v;
                             }
                             );
    }

    function readWriteTestShort(salt:int):Boolean
    {
        return readWriteTest(2, function(n:int):Boolean
                             {
                                 var v:int = (n + salt) & 0xffff;
                                 SI16(v, n);
                                 return LI16(n) == v;
                             }
                             );
    }

    function readWriteTestInt(salt:int):Boolean
    {
        return readWriteTest(4, function(n:int):Boolean
                             {
                                 var v:int = (n + salt);
                                 SI32(v, n);
                                 return LI32(n) == v;
                             }
                             );
    }

    function readWriteTestFloat(salt:Number):Boolean
    {
        return readWriteTest(4, function(n:int):Boolean
                             {
                                 var v:Number = (n + salt);
                                 SF32(v, n);
                                 return Math.abs(LF32(n) - v)<0.0001;
                             }
                             );
    }

    function readWriteTestDouble(salt:Number):Boolean
    {
        return readWriteTest(8, function(n:int):Boolean
                             {
                                 var v:Number = (n + salt);
                                 SF64(v, n);
                                 return Math.abs(LF64(n) - v)<0.0001;
                             }
                             );
    }

    longTests.push(function():void {
            AddTestCase("Read/write byte min", true, readWriteTestByte(12));
            AddTestCase("Read/write short min", true, readWriteTestShort(3456));
            AddTestCase("Read/write int min", true, readWriteTestInt(567890));
            AddTestCase("Read/write float min", true, readWriteTestFloat(12.34));
            AddTestCase("Read/write double min", true, readWriteTestDouble(34.56));
        });

    longTests.push(function():void {
            ba = currentDomain.domainMemory;
            currentDomain.domainMemory = null;

            AddTestCase("Read/write byte scratch", true, readWriteTestByte(12));
            AddTestCase("Read/write short scratch", true, readWriteTestShort(3456));
            AddTestCase("Read/write int scratch", true, readWriteTestInt(567890));
            AddTestCase("Read/write float scratch", true, readWriteTestFloat(12.34));
            AddTestCase("Read/write double scratch", true, readWriteTestDouble(34.56));

            currentDomain.domainMemory = ba;
        });


//
////////////////////////////////////////////////////////////////

    longTests.push(test);
    var n:int = 0;
    for(n = 0; n < longTests.length; n++)
        longTests[n]();

}
