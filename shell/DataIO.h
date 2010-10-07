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


#ifndef DATAIO_INCLUDED
#define DATAIO_INCLUDED

namespace avmplus
{
    template <class T>
    REALLY_INLINE void CoreSwap(T& a, T& b)
    {
        T t = a;
        a = b;
        b = t;
    }

    REALLY_INLINE void FlipU16(uint16_t& value)
    {
        uint8_t *pa = (uint8_t*)&(value);
        CoreSwap(pa[0], pa[1]);
    }

    REALLY_INLINE void FlipU64(uint64_t& value)
    {
        uint8_t *pa = (uint8_t*)&(value);
        CoreSwap(pa[0], pa[7]);
        CoreSwap(pa[1], pa[6]);
        CoreSwap(pa[2], pa[5]);
        CoreSwap(pa[3], pa[4]);
    }

    REALLY_INLINE void FlipU32(uint32_t& value)
    {
        uint8_t *pa = (uint8_t *)&(value);
        CoreSwap(pa[0], pa[3]);
        CoreSwap(pa[1], pa[2]);
    }

    class DataIOBase
    {
    public:
        MMGC_DECLARE_OPERATOR_DELETES_FOR_CLASS

        REALLY_INLINE DataIOBase()
            : m_objectEncoding(kEncodeDefault)
            , m_endian(kBigEndian)
        {
        }

        virtual ~DataIOBase() {}

        REALLY_INLINE Endian GetEndian() const { return m_endian; }
        REALLY_INLINE void SetEndian(Endian endian) { m_endian = endian; }

        REALLY_INLINE ObjectEncoding GetObjectEncoding() const { return m_objectEncoding; }
        REALLY_INLINE void SetObjectEncoding(ObjectEncoding objectEncoding) { m_objectEncoding = objectEncoding; }

        REALLY_INLINE void ConvertU16(uint16_t& value)
        {
            if (GetEndian() != GetNativeEndian())
            {
                FlipU16(value);
            }
        }

        REALLY_INLINE void ConvertU32(uint32_t& value)
        {
            if (GetEndian() != GetNativeEndian())
            {
                FlipU32(value);
            }
        }

        REALLY_INLINE void ConvertU64(uint64_t& value)
        {
            if (GetEndian() != GetNativeEndian())
            {
                FlipU64(value);
            }
        }

        REALLY_INLINE void ConvertD64(uint64_t& value)
        {
#if defined(VMCFG_DOUBLE_MSW_FIRST)
            // Swap the high and low words so that the datum is in "natural" endianness,
            // this produces or consumes big-endian or little-endian external data
            // as appropriate.
            union {
                uint64_t v;
                struct { uint32_t a, b; }
            }
            v = value;
            uint32_t tmp = a;
            a = b;
            b = tmp;
            value = v;
#endif
            return ConvertU64(value);
        }

        REALLY_INLINE Endian GetNativeEndian() const
        {
            #if defined(AVMPLUS_LITTLE_ENDIAN)
            return kLittleEndian;
            #elif defined(AVMPLUS_BIG_ENDIAN)
            return kBigEndian;
            #else
            #error
            #endif
        }

    protected:
        virtual Toplevel* toplevel() const = 0;

        void ThrowEOFError();
        void ThrowMemoryError();
        void ThrowRangeError();
        
    private:
        // OPTIMIZEME these will fit into bytes, might be a tiny worthwhile savings
        ObjectEncoding  m_objectEncoding;
        Endian m_endian;
    };

    class DataInput : virtual public DataIOBase
    {
    public:
        REALLY_INLINE DataInput() : DataIOBase() {}

        virtual uint32_t Available() = 0;
        virtual void Read(void *buffer, uint32_t count) = 0;

        bool ReadBoolean();
        uint8_t ReadU8();
        uint16_t ReadU16();
        uint32_t ReadU32();
        float ReadFloat();
        double ReadDouble();
        String* ReadMultiByte(uint32_t length, String *charSet);
        String* ReadUTF();
        String* ReadUTFBytes(uint32_t length);
        void ReadByteArray(ByteArray& buffer, uint32_t offset, uint32_t count);
        Atom ReadObject();

    protected:
        void CheckEOF(uint32_t count);
    };

    class DataOutput : virtual public DataIOBase
    {
    public:
        REALLY_INLINE DataOutput() : DataIOBase() { }

        virtual void Write(const void *buffer, uint32_t count) = 0;

        void WriteBoolean(bool value);
        void WriteU8(uint8_t value);
        void WriteU16(uint16_t value);
        void WriteU32(uint32_t value);
        void WriteFloat(float value);
        void WriteDouble(double value);
        void WriteMultiByte(String *str, String *charSet);
        void WriteUTF(String *str);
        void WriteUTFBytes(String *str);
        void WriteByteArray(ByteArray& buffer, uint32_t offset, uint32_t count);
        void WriteObject(Atom atom);
    };
}

MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATES(avmplus::DataIOBase)

#endif /* DATAIO_INCLUDED */
