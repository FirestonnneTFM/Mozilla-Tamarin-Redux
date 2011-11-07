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
 * Portions created by the Initial Developer are Copyright (C) 2004-2011
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
package SWF
{
    import flash.utils.ByteArray
    import flash.utils.Endian

    import abc.IReader
    import abc.ABCReader
    import abc.Types.ABCFile
    
    
    public final class SWFReader implements IReader
    {
        private var bitPos:int
        private var bitBuf:int
    
        private var originalData : ByteArray;
        private var data : ByteArray;
        
        public function SWFReader(data:ByteArray)
        {
            this.originalData = data;
        }
        
        public function readABC() : Array {
            var swf : SWF = decodeSWFHeader();
            var abcs : Array = new Array();
            decodeTags(swf, function (abcData : ByteArray, abcName : String) : void {
                var a : ABCFile = new ABCReader(abcData).readABC()[0]
                a.abcName = abcName
                abcs.push(a)
            });
            
            return abcs;
        }
        
        public function readABCBytes() : Array
        {
            var swf : SWF = decodeSWFHeader();
            var abcs : Array = new Array();
            decodeTags(swf, function (abcData : ByteArray, abcName : String) : void {
                abcs.push(abcData)
            });
            return abcs;
        }
        
        public function readSWF() : SWF
        {
            var swf : SWF = decodeSWFHeader();
            decodeTags(swf, function (...rest) : void {});
            return swf;
        }
        
        public function getDecompressedBytes() : ByteArray
        {
            decodeSWFHeader()
            return data;
        }
        
        public function getOriginalBytes() : ByteArray
        {
            return originalData;
        }
        
        private function decodeSWFHeader() : SWF
        {
            decompressIfNeededAndSkipHeader();
            var swf : SWF = new SWF(data);
            swf.rect = decodeRect();
            swf.frameRate = (data.readUnsignedByte()<<8|data.readUnsignedByte())
            swf.frameCount = data.readUnsignedShort()
            return swf;
        }
        
        public static function decodeABCTag(tag : Tag, swfBytes : ByteArray, abcHandler : Function) : void
        {
            var abcLength : uint = tag.length;
            var abcName : String = "<unamed>"
            swfBytes.position = tag.payloadPos
            
            switch (tag.type)
            {
            case Constants.TAG_DoABC2:
                swfBytes.readInt()
                abcName = readStringFromBytes(swfBytes)
                abcLength -= (swfBytes.position-tag.payloadPos)
                // fall through
            case Constants.TAG_DoABC:
                var abcBytes : ByteArray = new ByteArray()
                abcBytes.endian = "littleEndian"
                swfBytes.readBytes(abcBytes,0,abcLength)
                abcHandler(abcBytes, abcName)
                break
            }
        }
        
        private function decodeTags(swf : SWF, abcHandler : Function) : void
        {
            var type:int, h:int, length:int
            var offset:int
            var abcName : String = "<unamed>";
            while (data.position < data.length)
            {
                var currTag : Tag = new Tag(swf);
                var currTagPos : uint = data.position;
                h = data.readUnsignedShort();
                var currTagType : uint = h >> 6;
                
                currTag.pos = data.position;
                
                currTag.type = h >> 6;
                length = h & 0x3F;
                
                if (length == 0x3F)
                    length = data.readInt();
                currTag.length = length;
                currTag.payloadPos = data.position
                
                swf.tags.push(currTag)
                
                switch (currTag.type)
                {
                case 0: return
                case Constants.TAG_DoABC2:
                case Constants.TAG_DoABC:
                    decodeABCTag(currTag, data, abcHandler)
                    break
                default:
                    data.position += length
                }
            }
        }

        private function readString():String
        {
            return readStringFromBytes(data)
        }
        
        private static function readStringFromBytes(bytes : ByteArray) : String
        {
            var s:String = ""
            var c:int

            while (c=bytes.readUnsignedByte())
                s += String.fromCharCode(c)
            return s
        }

        private function syncBits() : void
        {
            bitPos = 0
        }

        private function decodeRect():Rect
        {
            syncBits();

            var rect:Rect = new Rect();

            var nBits:int = readUBits(5)
            rect.xMin = readSBits(nBits);
            rect.xMax = readSBits(nBits);
            rect.yMin = readSBits(nBits);
            rect.yMax = readSBits(nBits);

            return rect;
        }

        private function readSBits(numBits:int):int
        {
            if (numBits > 32)
                throw new Error("Number of bits > 32");

            var num:int = readUBits(numBits);
            var shift:int = 32-numBits;
            // sign extension
            num = (num << shift) >> shift;
            return num;
        }

        private function readUBits(numBits:int):uint
        {
            if (numBits == 0)
                return 0

            var bitsLeft:int = numBits;
            var result:int = 0;

            if (bitPos == 0) //no value in the buffer - read a byte
            {
                bitBuf = data.readUnsignedByte()
                bitPos = 8;
            }

            while (true)
            {
                var shift:int = bitsLeft - bitPos;
                if (shift > 0)
                {
                    // Consume the entire buffer
                    result |= bitBuf << shift;
                    bitsLeft -= bitPos;

                    // Get the next byte from the input stream
                    bitBuf = data.readUnsignedByte();
                    bitPos = 8;
                }
                else
                {
                    // Consume a portion of the buffer
                    result |= bitBuf >> -shift;
                    bitPos -= bitsLeft;
                    bitBuf &= 0xff >> (8 - bitPos); // mask off the consumed bits

                    return result;
                }
            }

            // unreachable, but fixes a spurious compiler warning
            return result;
        }
        
        private function decompressIfNeededAndSkipHeader():void
        {
            originalData.position = 0
            originalData.endian = Endian.LITTLE_ENDIAN
            var version:uint = this.originalData.readUnsignedInt()
            switch (version&0xffffff) {
            case 67|87<<8|83<<16: // SWC
                data = new ByteArray()
                data.endian = Endian.LITTLE_ENDIAN
                originalData.position = 8
                originalData.readBytes(data,0,originalData.length-originalData.position)
                data.uncompress()
                break;
            case 70|87<<8|83<<16: // SWF
                data = originalData;
                data.position = 8;
                break;
            default:
                data = null;
            }
        }
        
        public function supportsContent():Boolean {
            originalData.position = 0
            this.originalData.endian = Endian.LITTLE_ENDIAN
            var version:uint = this.originalData.readUnsignedInt()
            switch (version&0xffffff) {
            case 67|87<<8|83<<16: // SWC
            case 70|87<<8|83<<16: // SWF
                return true;
            }
            return false;
        }
        
    }
}
