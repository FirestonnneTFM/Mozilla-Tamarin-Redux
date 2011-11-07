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
package zip
{
    import flash.utils.ByteArray;
    import flash.utils.Endian;
    
    public class ZipFile
    {
        private static const EndOfCentralDirectoryRecordSize : uint = 4 + (4 * 2) + (2 * 4) + 2;
        private static const EndOfCentralDirectoryRecordMagic : uint = 0x06054B50
        private static const CentralDirectoryMagic : uint = 0x02014B50
        private static const LocalFileHeaderMagic : uint = 0x04034B50
        
        private static const ZIP_STORED : uint = 0;
        private static const ZIP_DEFLATED : uint = 8;
        
        public function ZipFile(input : ByteArray)
        {
            this.input = input;
            var ecd : EndOfCentralDirectoryRecord = findEndOfCentralDirectory(input);
            cd = readCentralDirectory(ecd);
        }
        
        private var input : ByteArray;
        private var cd : CentralDirectory;
        
        public function getEntryByName(n : String) : ByteArray
        {
            var entry : CentralDirectoryEntry = cd.getEntryByName(n)
            if (entry == null)
                return null;
            var localHeader : LocalFileHeader = readLocalFileHeader(entry)
            var result : ByteArray = readBytes(input.position, localHeader.compressedSize)
            if (localHeader.compressionMethod == ZIP_STORED)
                return result
            result.inflate()
            return result;
        }
        
        private function readBytes(offset : uint, len : uint) : ByteArray
        {
            var result : ByteArray = new ByteArray();
            if (len != 0)
            {
                input.position = offset;
                input.readBytes(result, 0, len);
            }
            return result;
        }
        
        private static function readEndOfCentralDirectory(input : ByteArray, offset : uint) : EndOfCentralDirectoryRecord
        {
            var result : EndOfCentralDirectoryRecord = new EndOfCentralDirectoryRecord();
            
            input.endian = Endian.LITTLE_ENDIAN;
            input.position = offset;
            result.diskNumber = input.readUnsignedShort();
            result.diskStart = input.readUnsignedShort();
            result.diskEntries = input.readUnsignedShort();
            result.totalEntries = input.readUnsignedShort();
            result.size = input.readUnsignedInt();
            result.offset = input.readUnsignedInt();
            return result;
        }
        
        private function readCentralDirectory(ecd : EndOfCentralDirectoryRecord) : CentralDirectory
        {
            var cd : CentralDirectory = new CentralDirectory();
            input.position = ecd.offset
            var endOfCod : uint = ecd.offset + ecd.size
            var entry : CentralDirectoryEntry
            while (input.position < endOfCod)
            {
                entry = readCentralDirectoryEntry()
                cd.addEntry(entry)
            }
            return cd;
        }
        
        private function readCentralDirectoryEntry() : CentralDirectoryEntry
        {
            var magic : uint = input.readUnsignedInt();
            if (magic != CentralDirectoryMagic)
                throw new InvalidZipFile("invalid central directory: 0x" + magic.toString(16))
            var result : CentralDirectoryEntry = new CentralDirectoryEntry();
            result.createVersion = input.readUnsignedByte()
            result.createSystem = input.readUnsignedByte()
            result.extractVersion = input.readUnsignedByte()
            result.extractSystem = input.readUnsignedByte()
            result.flags = input.readUnsignedShort()
            result.compressType = input.readUnsignedShort()
            result.time = input.readUnsignedShort()
            result.date = input.readUnsignedShort()
            result.crc = input.readUnsignedInt()
            result.compressedSize = input.readUnsignedInt()
            result.uncompressedSize = input.readUnsignedInt()
            result.fileNameLength = input.readUnsignedShort()
            result.extraFieldLength = input.readUnsignedShort()
            result.commentLength = input.readUnsignedShort()
            result.diskNumberStart = input.readUnsignedShort()
            result.internalFileAttributes = input.readUnsignedShort()
            result.externalFileAttributes = input.readUnsignedInt()
            result.localHeaderOffset = input.readUnsignedInt()
            result.fileName = input.readUTFBytes(result.fileNameLength)
            result.extra = readBytes(input.position, result.extraFieldLength)
            result.comment = input.readUTFBytes(result.commentLength)
            return result
        }
        
        private function readLocalFileHeader(entry : CentralDirectoryEntry) : LocalFileHeader
        {
            input.position = entry.localHeaderOffset;
            var magic : uint = input.readUnsignedInt();
            if (magic != LocalFileHeaderMagic)
                throw new InvalidZipFile("invalid local header: " + magic.toString(16));
            var result : LocalFileHeader = new LocalFileHeader();
            result.extractVersion = input.readUnsignedByte();
            result.extractSystem = input.readUnsignedByte();
            result.generalPurposeFlagBits = input.readUnsignedShort()
            result.compressionMethod = input.readUnsignedShort()
            result.lastModType = input.readUnsignedShort()
            result.lastModDate = input.readUnsignedShort()
            result.crc = input.readUnsignedInt()
            result.compressedSize = input.readUnsignedInt()
            result.uncompressedSize = input.readUnsignedInt()
            result.fileNameLength = input.readUnsignedShort()
            result.extraFieldLength = input.readUnsignedShort()
            result.fileName = input.readUTFBytes(result.fileNameLength)
            result.extraField = readBytes(input.position, result.extraFieldLength)
            if (result.compressedSize == 0)
                result.compressedSize = entry.compressedSize
            return result;
        }
        
        private static function findEndOfCentralDirectory(input : ByteArray) : EndOfCentralDirectoryRecord
        {
            input.endian = Endian.LITTLE_ENDIAN;
            input.position = input.length - EndOfCentralDirectoryRecordSize;
            var magic : uint = input.readUnsignedInt();
            
            
            if (magic == EndOfCentralDirectoryRecordMagic)
                return readEndOfCentralDirectory(input, input.position)
            return null;
        }
        
        public static function isZipFile(input : ByteArray) : Boolean
        {
            return findEndOfCentralDirectory(input) != null;
        }
    }
}

class InvalidZipFile extends Error
{
    public function InvalidZipFile(msg : String)
    {
        super(msg)
    }
}

class LocalFileHeader
{
    import flash.utils.ByteArray

    public function LocalFileHeader()
    {
    }
    
    public var extractVersion : uint
    public var extractSystem : uint
    public var generalPurposeFlagBits : uint
    public var compressionMethod : uint
    public var lastModType : uint
    public var lastModDate : uint
    public var crc : uint
    public var compressedSize : uint
    public var uncompressedSize : uint
    public var fileNameLength : uint
    public var extraFieldLength : uint
    
    public var fileName : String
    public var extraField : ByteArray
}

class CentralDirectory
{
    public function CentralDirectory()
    {
        entries = new Vector.<CentralDirectoryEntry>();
        index = new Object();
    }
    
    public function addEntry(e : CentralDirectoryEntry) : void
    {
        index[e.fileName] = entries.length
        entries.push(e);
    }
    
    public function getEntryByName(n : String) : CentralDirectoryEntry
    {
        if (n in index)
            return entries[index[n]];
        return null;
    }
    
    private var entries : Vector.<CentralDirectoryEntry>;
    private var index : Object;
}

class CentralDirectoryEntry
{
    import flash.utils.ByteArray
    
    public function CentralDirectoryEntry()
    {
    }
    
    public var createVersion : uint;
    public var createSystem : uint;
    public var extractVersion : uint;
    public var extractSystem : uint;
    public var flags : uint;
    public var compressType : uint;
    public var time : uint;
    public var date : uint;
    public var crc : uint;
    public var compressedSize : uint
    public var uncompressedSize : uint
    public var fileNameLength : uint
    public var extraFieldLength : uint
    public var commentLength : uint
    public var diskNumberStart : uint
    public var internalFileAttributes : uint
    public var externalFileAttributes : uint
    public var localHeaderOffset : uint
    public var fileName : String
    public var extra : ByteArray
    public var comment : String
    
    
    public function toString() : String
    {
        var result : String = ""
        var props : Array = [ "createVersion", "createSystem", "extractVersion", "extractSystem",
            "flags", "compressType", "time", "date", "crc", "compressedSize", "uncompressedSize",
            "fileNameLength", "extraFieldLength", "commentLength", "diskNumberStart",
            "internalFileAttributes", "externalFileAttributes", "localHeaderOffset", "fileName", "extra", "comment" ]
        for each (var n : String in props)
        {
            result += n + " = " + this[n].toString() + "\n"
        }
        return result;
    }
}

class EndOfCentralDirectoryRecord
{
    public function EndOfCentralDirectoryRecord()
    {
    }
    
    public var diskNumber : uint;
    public var diskStart : uint;
    public var diskEntries : uint;
    public var totalEntries : uint;
    public var size : uint;
    public var offset : uint;
    
    public function toString() : String
    {
        return "diskNumber: " + diskNumber + "\n" +
            "diskStart: " + diskStart + "\n" +
            "diskEntries: " + diskEntries + "\n" +
            "totalEntries: " + totalEntries + "\n" +
            "size: " + size + "\n" +
            "offset: " + offset;
    }
}