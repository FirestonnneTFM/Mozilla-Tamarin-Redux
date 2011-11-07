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
package abc {

    import avmplus.File

    import flash.utils.ByteArray
    
    import Utils
    import abc.Types.ABCFile
    import abc.ABCReader
    import SWF.SWFReader
    import SWC.SWCReader

    public final class Reader {

        public static function readS32(data:ByteArray):int {
            var result:int = data.readUnsignedByte();
            if (!(result & 0x00000080))
                return result;
            result = result & 0x0000007f | data.readUnsignedByte()<<7;
            if (!(result & 0x00004000))
                return result;
            result = result & 0x00003fff | data.readUnsignedByte()<<14;
            if (!(result & 0x00200000))
                return result;
            result = result & 0x001fffff | data.readUnsignedByte()<<21;
            if (!(result & 0x10000000))
                return result;
            return   result & 0x0fffffff | data.readUnsignedByte()<<28;
        }
        
        public static function readS24(data:ByteArray):int
        {
            var b:int = data.readUnsignedByte()
            b |= data.readUnsignedByte()<<8
            b |= data.readByte()<<16
            return b
        }

        public static function readU32(data:ByteArray):uint {
            return readS32(data)
        }
        
        public static function readU30(data:ByteArray):uint {
            return readS32(data)
        }

        public static function readS30(data:ByteArray):int {
            return readS32(data)
        }
        
        public static function createReader(file : String) : IReader
        {
            var data:ByteArray = File.readByteArray(file)
            var readers:Array = [ABCReader, SWFReader, SWCReader]
            
            for each(var ri : Class in readers) {
                var r:IReader = new ri(data)
                if(r.supportsContent())
                    return r
            }
            
            Utils.error("No readers are capable of handling '"+file+"'")
            return null
        }
        
        public static function readFile(file:String):Array
        {
            var r : IReader = createReader(file);
            if (r != null)
                return r.readABC()
            return []
        }
        
        public static function readABCBytes(file : String) : Array
        {
            var r : IReader = createReader(file);
            if (r != null)
                return r.readABCBytes()
            return []
        }
    }
}