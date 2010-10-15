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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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


// FIXME https://bugzilla.mozilla.org/show_bug.cgi?id=564248
// this should be "avmplus.h" once this file is moved into core
#include "avmshell.h"
#include "genericzlib.h"

namespace avmplus
{
    //
    // ByteArray
    //
    
    ByteArray::ByteArray(Toplevel* toplevel)
        : DataIOBase()
        , GlobalMemoryProvider()
        , DataInput()
        , DataOutput()
        , m_toplevel(toplevel)
        , m_gc(toplevel->core()->GetGC())
        , m_subscribers(m_gc, 0)
        , m_array(NULL)
        , m_capacity(0)
        , m_length(0)
        , m_position(0)
        , m_copyOnWrite(false)
    {
        AvmAssert(m_gc != NULL);
    }

    ByteArray::ByteArray(const ByteArray& lhs)
        : DataIOBase()
        , GlobalMemoryProvider()
        , DataInput()
        , DataOutput()
        , m_toplevel(lhs.m_toplevel)
        , m_gc(lhs.m_gc)
        , m_subscribers(m_gc, 0)
        , m_array(NULL)
        , m_capacity(0)
        , m_length(0)
        , m_position(0)
        , m_copyOnWrite(false)
    {
        AvmAssert(m_gc != NULL);
        m_array = mmfx_new_array_opt(uint8_t, lhs.m_length, MMgc::kCanFailAndZero);
        TellGcNewBufferMemory(m_array, lhs.m_length);
        if (!m_array)
        {
            ThrowMemoryError();
            return;
        }

        m_capacity = lhs.m_length;
        m_length   = lhs.m_length;

        VMPI_memcpy(m_array, lhs.m_array, m_length);
    }

    ByteArray::~ByteArray()
    {
        m_subscribers.clear();
        Clear();
    }

    void ByteArray::Clear()
    {
        if (m_subscribers.length() > 0)
        {
            AvmAssert(false); // shouldn't get here?
            m_toplevel->throwRangeError(kInvalidRangeError);
        }
        if (m_array && !m_copyOnWrite)
        {
            TellGcDeleteBufferMemory(m_array, m_length);
            mmfx_delete_array(m_array);
        }
        m_array        = NULL;
        m_length       = 0;
        m_capacity     = 0;
        m_copyOnWrite     = false;
    }

    void ByteArray::SetCopyOnWriteData(uint8_t* data, uint32_t length)
    {
        Clear();
        m_array        = data;
        m_length       = length;
        m_capacity     = length;
        m_copyOnWrite     = true;
    }
        
    void FASTCALL ByteArray::Grower::EnsureWritableCapacity(uint64_t minimumCapacity)
    {
        if (minimumCapacity > (MMgc::GCHeap::kMaxObjectSize - MMgc::GCHeap::kBlockSize*2))
            m_owner->ThrowMemoryError();

        if (minimumCapacity > m_owner->m_capacity || m_owner->m_copyOnWrite)
        {
            uint32_t newCapacity = m_owner->m_capacity << 1;          
            if (newCapacity < minimumCapacity)
                newCapacity = uint32_t(minimumCapacity);
            if (newCapacity < kGrowthIncr) 
                newCapacity = kGrowthIncr;

            m_oldArray = m_owner->m_array;
            m_oldLength = m_owner->m_length;

            uint8_t* newArray = mmfx_new_array_opt(uint8_t, newCapacity, MMgc::kCanFailAndZero);
            if (!newArray)
                m_owner->ThrowMemoryError();

            m_owner->TellGcNewBufferMemory(newArray, newCapacity);
            if (m_oldArray)
                VMPI_memcpy(newArray, m_oldArray, m_oldLength);

            m_owner->m_array = newArray;
            m_owner->m_capacity = newCapacity;
            m_owner->m_copyOnWrite = false;
        }
    }

    /*
        Why the "Grower" class?
        
        (1) It provides a clean way to defer discarding the old buffer until the
            end of the calling function; this matters in the case of Write(),
            as it's legal to call Write() on your own buffer, and so if growth
            occurs, you must not discard the old buffer until copying takes place.
        (2) It avoid redundant calls to NotifySubscribers(); previously we'd call
            once when a reallocation occurred, then again when the length field
            changed. 
        (3) It streamlines copy-on-write handling; formerly we either did
            redundant CopyOnWrite alloc-and-copy followed by a Grow alloc-and-copy,
            or an if-else clause with redundant alloc-and-copy.
            
        Of course, the dtor will be skipped (and thus notify and deletes skipped)
        if a longjmp over it, but the old code was subject to the same defects,
        so this is not a new liability.
    */
    ByteArray::Grower::~Grower()
    {
        if (m_oldArray != m_owner->m_array || m_oldLength != m_owner->m_length) 
        {
            m_owner->NotifySubscribers();
        }
        if (m_oldArray != m_owner->m_array) 
        {
            m_owner->TellGcDeleteBufferMemory(m_oldArray, m_oldLength);
            mmfx_delete_array(m_oldArray);
        }
    }

    uint8_t* FASTCALL ByteArray::GetWritableBuffer() 
    { 
        Grower grower(this);
        grower.EnsureWritableCapacity(m_capacity);
        return m_array; 
    }

    uint8_t& ByteArray::operator[](uint32_t index)
    {
        if (index >= m_length)
            SetLength(index + 1);
        return m_array[index];
    }

    void FASTCALL ByteArray::SetLength(uint32_t newLength)
    {
        if (m_subscribers.length() > 0 && m_length < DomainEnv::GLOBAL_MEMORY_MIN_SIZE)
            m_toplevel->throwRangeError(kInvalidRangeError);

        Grower grower(this);
        if (newLength > m_capacity)
        {
            grower.EnsureWritableCapacity(newLength);
        }
        m_length = newLength;
        if (m_position > newLength) 
            m_position = newLength;
    }

    // When we might be reading or writing to ourself, use this function
    // apparently SunPro compiler doesn't like combining REALLY_INLINE with static functions in CPP files
    /*static*/
    REALLY_INLINE void move_or_copy(void* dst, const void* src, uint32_t count)
    {
        if ((uintptr_t(dst) - uintptr_t(src)) >= uintptr_t(count)) 
        {
            VMPI_memcpy(dst, src, count);
        } 
        else 
        {
            VMPI_memmove(dst, src, count);
        }
    }

    void ByteArray::Read(void* buffer, uint32_t count)
    {
        CheckEOF(count);
        move_or_copy(buffer, m_array + m_position, count);
        m_position += count;
    }

    void ByteArray::Write(const void* buffer, uint32_t count)
    {
        uint32_t writeEnd = m_position + count;
        
        Grower grower(this);
        grower.EnsureWritableCapacity(writeEnd);
        
        move_or_copy(m_array + m_position, buffer, count);
        m_position += count;
        if (m_length < m_position) 
            m_length = m_position;
    }

    void ByteArray::EnsureCapacity(uint32_t capacity)
    {
        Grower grower(this);
        grower.EnsureWritableCapacity(capacity);
    }
    
    void ByteArray::NotifySubscribers()
    {
        for (uint32_t i = 0, n = m_subscribers.length(); i < n; ++i)
        {
            AvmAssert(m_length >= DomainEnv::GLOBAL_MEMORY_MIN_SIZE);
 
            GlobalMemorySubscriber* subscriber = m_subscribers.get(i);
            if (subscriber)
            {
                subscriber->notifyGlobalMemoryChanged(m_array, m_length);
            }
            else
            {
                // Domain went away? remove link
                m_subscribers.removeAt(i);
                --i;
            }
        }
    }
 
    bool ByteArray::addSubscriber(GlobalMemorySubscriber* subscriber)
    {
        if (m_length >= DomainEnv::GLOBAL_MEMORY_MIN_SIZE)
        {
            removeSubscriber(subscriber);
            m_subscribers.add(subscriber);
            // notify the new "subscriber" of the current state of the world
            subscriber->notifyGlobalMemoryChanged(m_array, m_length);
            return true;
        }
        return false;
    }
 
    bool ByteArray::removeSubscriber(GlobalMemorySubscriber* subscriber)
    {
        for (uint32_t i = 0, n = m_subscribers.length(); i < n; ++i)
        {
            if (m_subscribers.get(i) == subscriber)
            {
                m_subscribers.removeAt(i);
                return true;
            }
        }
        return false;
    }
 
#ifdef DEBUGGER
    uint64_t ByteArray::bytesUsed() const
    {
        // If m_copyOnWrite is set, then we don't own the buffer, so the profiler
        // should not attribute it to us.
        return m_copyOnWrite ? 0 : m_capacity;
    }
#endif

    void ByteArray::TellGcNewBufferMemory(const uint8_t* buf, uint32_t numberOfBytes)
    {
        if (buf && numberOfBytes > 0)
        {
            m_gc->SignalDependentAllocation(numberOfBytes);
        }
    }

    void ByteArray::TellGcDeleteBufferMemory(const uint8_t* buf, uint32_t numberOfBytes)
    {
        // Note that we can't rely on using m_toplevel->core()->GetGC();
        // order of destruction is unspecified, and if this is called at destruction
        // time, Toplevel might have been destroyed before us. So keep a separate GC*.
        if (buf && numberOfBytes > 0)
        {
            m_gc->SignalDependentDeallocation(numberOfBytes);
        }
    }
    
    //
    // ByteArrayObject
    //
    
    ByteArrayObject::ByteArrayObject(VTable* ivtable, ScriptObject* delegate, ObjectEncoding defaultEncoding)
        : ScriptObject(ivtable, delegate)
        , m_byteArray(toplevel())
    {
        c.set(&m_byteArray, sizeof(ByteArray));
        m_byteArray.SetObjectEncoding(defaultEncoding);
    }

    Atom ByteArrayObject::getUintProperty(uint32_t i) const
    {
        if (i < m_byteArray.GetLength()) 
        {
            intptr_t const b = m_byteArray[i];
            return atomFromIntptrValue(b);
        } 
        else 
        {
            return undefinedAtom;
        }
    }
    
    bool ByteArrayObject::hasUintProperty(uint32_t i) const
    {
        return i < m_byteArray.GetLength();
    }
    
    void ByteArrayObject::setUintProperty(uint32_t i, Atom value)
    {
        m_byteArray[i] = uint8_t(AvmCore::integer(value));
    }
    
    Atom ByteArrayObject::getAtomProperty(Atom name) const
    {
        uint32_t index;
        if (AvmCore::getIndexFromAtom(name, &index)) 
        {
            return getUintProperty(index);
        }

        return ScriptObject::getAtomProperty(name);
    }
    
    void ByteArrayObject::setAtomProperty(Atom name, Atom value)
    {
        uint32_t index;
        if (AvmCore::getIndexFromAtom(name, &index)) 
        {
            setUintProperty(index, value);
        } 
        else 
        {
            ScriptObject::setAtomProperty(name, value);
        }
    }
    
    bool ByteArrayObject::hasAtomProperty(Atom name) const
    {
        if (core()->currentBugCompatibility()->bugzilla558863) 
        {
            uint32_t index;
            if (AvmCore::getIndexFromAtom(name, &index)) 
            {
                return index < m_byteArray.GetLength();
            }

            return ScriptObject::hasAtomProperty(name);
        }
        else
        {
            return ScriptObject::hasAtomProperty(name)
                || getAtomProperty(name) != undefinedAtom;
        }
    }

    Atom ByteArrayObject::getMultinameProperty(const Multiname* name) const
    {
        uint32_t index;
        if (AvmCore::getIndexFromString(name->getName(), &index)) 
        {
            return getUintProperty(index);
        }

        return ScriptObject::getMultinameProperty (name);
    }

    void ByteArrayObject::setMultinameProperty(const Multiname* name, Atom value)
    {
        uint32_t index;
        if (AvmCore::getIndexFromString(name->getName(), &index)) 
        {
            setUintProperty(index, value);
        }
        else
        {
            ScriptObject::setMultinameProperty (name, value);
        }
    }

    bool ByteArrayObject::hasMultinameProperty(const Multiname* name) const
    {
        uint32_t index;
        if (this->core()->getIndexFromString(name->getName(), &index)) 
        {
            return index < m_byteArray.GetLength();
        }

        return ScriptObject::hasMultinameProperty(name);
    }

    String* ByteArrayObject::_toString()
    {
        uint32_t len = m_byteArray.GetLength();
        const uint8_t* c = m_byteArray.GetReadableBuffer();

        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if (len >= 3)
        {
            // UTF8 BOM
            if ((c[0] == 0xef) && (c[1] == 0xbb) && (c[2] == 0xbf))
            {
                return core->newStringUTF8((const char*)c + 3, len - 3);
            }
            else if ((c[0] == 0xfe) && (c[1] == 0xff))
            {
                //UTF-16 big endian
                c += 2;
                len = (len - 2) >> 1;
                return core->newStringEndianUTF16(/*littleEndian*/false, (const wchar*)c, len);
            }
            else if ((c[0] == 0xff) && (c[1] == 0xfe))
            {
                //UTF-16 little endian
                c += 2;
                len = (len - 2) >> 1;
                return core->newStringEndianUTF16(/*littleEndian*/true, (const wchar*)c, len);
            }
        }

        String* result = toplevel->tryFromSystemCodepage(c);
        if (result != NULL)
            return result;
        
        // Use newStringUTF8() with "strict" explicitly set to false to mimick old,
        // buggy behavior, where malformed UTF-8 sequences are stored as single characters.
        return core->newStringUTF8((const char*)c, len, false);
    }
    
    Atom ByteArrayObject::readObject()
    {
        return m_byteArray.ReadObject();
    }

    void ByteArrayObject::writeObject(Atom value)
    {
        m_byteArray.WriteObject(value);
    }
    
    int ByteArrayObject::readByte()
    {
        return (int8_t)m_byteArray.ReadU8();
    }

    int ByteArrayObject::readUnsignedByte()
    {
        return m_byteArray.ReadU8();
    }

    int ByteArrayObject::readShort()
    {
        return (int16_t)m_byteArray.ReadU16();
    }

    int ByteArrayObject::readUnsignedShort()
    {
        return m_byteArray.ReadU16();
    }

    int ByteArrayObject::readInt()
    {
        return (int32_t)m_byteArray.ReadU32();      
    }

    uint32_t ByteArrayObject::readUnsignedInt()
    {
        return m_byteArray.ReadU32();       
    }
    
    double ByteArrayObject::readFloat()
    {
        return m_byteArray.ReadFloat();
    }

    double ByteArrayObject::readDouble()
    {
        return m_byteArray.ReadDouble();
    }

    bool ByteArrayObject::readBoolean()
    {
        return m_byteArray.ReadBoolean();
    }

    void ByteArrayObject::writeBoolean(bool value)
    {
        m_byteArray.WriteBoolean(value);
    }

    void ByteArrayObject::writeByte(int value)
    {
        m_byteArray.WriteU8((uint8_t)value);
    }

    void ByteArrayObject::writeShort(int value)
    {
        m_byteArray.WriteU16((uint16_t)value);
    }

    void ByteArrayObject::writeInt(int value)
    {
        m_byteArray.WriteU32((uint32_t)value);
    }

    void ByteArrayObject::writeUnsignedInt(uint32_t value)
    {
        m_byteArray.WriteU32(value);
    }
    
    void ByteArrayObject::writeFloat(double value)
    {
        m_byteArray.WriteFloat((float)value);
    }

    void ByteArrayObject::writeDouble(double value)
    {
        m_byteArray.WriteDouble(value);
    }

    void ByteArrayObject::zlib_compress()
    {
        int len = m_byteArray.GetLength();
        if (!len) // empty buffer should give us a empty result
            return;
        unsigned long gzlen = len * 3/2 + 32; // enough for growth plus zlib headers
        uint8_t *gzdata = mmfx_new_array( uint8_t, gzlen );

        // Use zlib to compress the data
        compress2((uint8_t*)gzdata, (unsigned long*)&gzlen,
                  m_byteArray.GetReadableBuffer(), len, 9);

        // Replace the byte array with the compressed data
        m_byteArray.SetLength(0);
        m_byteArray.Write(gzdata, gzlen);

        mmfx_delete_array( gzdata );
    }

    void ByteArrayObject::zlib_uncompress()
    {
        // Snapshot the compressed data.
        unsigned long gzlen = m_byteArray.GetLength();
        if (!gzlen) // empty buffer should give us a empty result
            return;

        uint8_t *gzdata = mmfx_new_array( uint8_t, gzlen );
        VMPI_memcpy(gzdata, m_byteArray.GetReadableBuffer(), gzlen);

        // Clear the buffer
        m_byteArray.SetPosition(0);
        m_byteArray.SetLength(0);

        // The following block is to force destruction
        // of zstream before potential exception throw.
        int error = Z_OK;
        {
            // Decompress the data
            PlatformZlibStream zstream;
            zstream.SetNextIn(gzdata);
            zstream.SetAvailIn(gzlen);

            const int kBufferSize = 8192;
            uint8_t *buffer = mmfx_new_array( uint8_t, kBufferSize );

            do {
                zstream.SetNextOut(buffer);
                zstream.SetAvailOut(kBufferSize);
                error = zstream.InflateWithStatus();
                m_byteArray.Write(buffer, kBufferSize-zstream.AvailOut());
            } while (error == Z_OK);

            mmfx_delete_array( buffer );
            mmfx_delete_array( gzdata );
        }

        // position byte array at the beginning
        m_byteArray.SetPosition(0);

        if (error != Z_OK && error != Z_STREAM_END) {
            toplevel()->throwIOError(kCompressedDataError);
        }
    }

    void ByteArrayObject::writeBytes(ByteArrayObject *bytes,
                                     uint32_t offset,
                                     uint32_t length)
    {
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = bytes->get_length() - offset;
        }

        m_byteArray.WriteByteArray(bytes->GetByteArray(),
                                   offset,
                                   length);
    }

    void ByteArrayObject::readBytes(ByteArrayObject *bytes,
                                    uint32_t offset,
                                    uint32_t length)
    {
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = m_byteArray.Available();
        }

        m_byteArray.ReadByteArray(bytes->GetByteArray(),
                                  offset,
                                  length);
    }

    String* ByteArrayObject::readMultiByte(uint32_t length, String* charSet)
    {
        toplevel()->checkNull(charSet, "charSet");
        return m_byteArray.ReadMultiByte(length, charSet);
    }
    
    String* ByteArrayObject::readUTF()
    {
        return m_byteArray.ReadUTF();
    }

    String* ByteArrayObject::readUTFBytes(uint32_t length)
    {
        return m_byteArray.ReadUTFBytes(length);
    }

    void ByteArrayObject::writeMultiByte(String* value, String* charSet)
    {
        toplevel()->checkNull(value, "value");
        toplevel()->checkNull(charSet, "charSet");
        m_byteArray.WriteMultiByte(value, charSet);
    }
    
    void ByteArrayObject::writeUTF(String* value)
    {
        toplevel()->checkNull(value, "value");
        m_byteArray.WriteUTF(value);
    }

    void ByteArrayObject::writeUTFBytes(String* value)
    {
        toplevel()->checkNull(value, "value");
        m_byteArray.WriteUTFBytes(value);
    }

    uint32_t ByteArrayObject::get_objectEncoding()
    {
        return m_byteArray.GetObjectEncoding();
    }

    void ByteArrayObject::set_objectEncoding(uint32_t objectEncoding)
    {
        if ((objectEncoding == kAMF3)||(objectEncoding == kAMF0))
        {
            m_byteArray.SetObjectEncoding(ObjectEncoding(objectEncoding));
        }
        else
        {
            toplevel()->throwArgumentError(kInvalidEnumError, "objectEncoding");
        }
    }

    Stringp ByteArrayObject::get_endian()
    {
        return (m_byteArray.GetEndian() == kBigEndian) ? core()->kbigEndian : core()->klittleEndian;
    }

    void ByteArrayObject::set_endian(Stringp type)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        toplevel->checkNull(type, "endian");

        type = core->internString(type);
        if (type == core->kbigEndian)
        {
            m_byteArray.SetEndian(kBigEndian);
        }
        else if (type == core->klittleEndian)
        {
            m_byteArray.SetEndian(kLittleEndian);
        }
        else
        {
            toplevel->throwArgumentError(kInvalidEnumError, "type");
        }
    }
    
    void ByteArrayObject::clear()
    {
        m_byteArray.Clear();
        m_byteArray.SetPosition(0);
    }

#ifdef DEBUGGER
    uint64_t ByteArrayObject::bytesUsed() const
    {
        uint64_t size = ScriptObject::bytesUsed();
        size += m_byteArray.bytesUsed();
        return size;
    }
#endif

    //
    // ByteArrayClass
    //

    ByteArrayClass::ByteArrayClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
        set_defaultObjectEncoding(kEncodeDefault);
    }

    ScriptObject* ByteArrayClass::createInstance(VTable* ivtable, ScriptObject* prototype)
    {
        return new (ivtable->gc(), ivtable->getExtraSize()) ByteArrayObject(ivtable, prototype, (ObjectEncoding)get_defaultObjectEncoding());
    }

}

