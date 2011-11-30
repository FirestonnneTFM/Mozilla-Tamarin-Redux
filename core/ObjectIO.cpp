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


#include "avmplus.h"

namespace avmplus
{
    //
    // ObjectOutputClass
    //
    static const char kStrValue[]             = "value";
    static const char kStrTypeValue[]         = "type";

    ObjectOutputClass::ObjectOutputClass(VTable *vtable) : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    void ObjectOutputObject::writeBytes(ByteArrayObject *bytes, uint32_t offset, uint32_t length) {
        // !!@ FIXME : CONSOLIDATE into WriteByteArray()
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = bytes->get_length() - offset;
        }
        m_out->DataOutput::WriteByteArray(bytes->GetByteArray(), offset, length);
    }

    void ObjectOutputObject::writeBoolean(bool value) {
        m_out->WriteBoolean(value);
    }

    void ObjectOutputObject::writeByte(int value) {
        m_out->WriteU8((uint8_t)value);
    }

    void ObjectOutputObject::writeShort(int value) {
        m_out->WriteU16((uint16_t)value);
    }

    void ObjectOutputObject::writeInt(int value) {
        m_out->WriteU32((uint32_t)value);
    }

    void ObjectOutputObject::writeUnsignedInt(uint32_t value) {
        m_out->WriteU32(value);
    }

    void ObjectOutputObject::writeFloat(double value) {
        m_out->WriteFloat((float)value);
    }

    void ObjectOutputObject::writeDouble(double value) {
        m_out->WriteDouble(value);
    }

    void ObjectOutputObject::writeMultiByte(String *value, String *charSet)
    {
        toplevel()->checkNull(value, kStrValue);
        toplevel()->checkNull(charSet, "charSet");
        m_out->WriteMultiByte(value, charSet);
    }

    void ObjectOutputObject::writeUTF(String *value) {
        // !!@ CONSOLIDATE INTO DataOutput
        toplevel()->checkNull(value, kStrValue);
        m_out->WriteUTF(value);
    }

    void ObjectOutputObject::writeUTFBytes(String *value) {
        // !!@ CONSOLIDATE INTO DataOutput
        toplevel()->checkNull(value, kStrValue);
        m_out->WriteUTFBytes(value);
    }

    void ObjectOutputObject::writeObject(Atom value) {
        // calling DataOutput::writeObject() would create a new DataOutputWrapper,
        // which creates new reference tables, which we don't want. So we call
        // WriteAtom() explicitly. This assumes AMF3 is the only version for this code.
        AvmAssert(kAMF3 == kEncodeDefault);

        m_out->AvmPlusObjectOutput::WriteAtom(value);
    }

    uint32_t ObjectOutputObject::get_objectEncoding()
    {
        return m_out->GetObjectEncoding();
    }

    void ObjectOutputObject::set_objectEncoding(uint32_t objectEncoding)
    {
        if ((objectEncoding == kAMF3) || (objectEncoding == kAMF0))
        {
            m_out->SetObjectEncoding(ObjectEncoding(objectEncoding));
        }
        else
        {
            toplevel()->argumentErrorClass()->throwError(kInvalidEnumError, core()->toErrorString("objectEncoding"));
        }
    }

    Stringp ObjectOutputObject::get_endian() {
        return (m_out->GetEndian() == kBigEndian) ? core()->kbigEndian : core()->klittleEndian;
    }

    void ObjectOutputObject::set_endian(Stringp type) {
        toplevel()->checkNull(type, "endian");
        type = core()->internString(type);
        if (type == core()->kbigEndian)
        {
              m_out->SetEndian(kBigEndian);
        }
        else if (type == core()->klittleEndian)
        {
              m_out->SetEndian(kLittleEndian);
        }
        else
        {
            toplevel()->argumentErrorClass()->throwError(kInvalidEnumError, core()->toErrorString(kStrTypeValue));
        }
    }

    //
    // ObjectInputClass
    //

    ObjectInputClass::ObjectInputClass(VTable *vtable) : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    void ObjectInputObject::readBytes(ByteArrayObject *bytes, uint32_t offset, uint32_t length)
    {
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = m_in->Available();
        }
        
        m_in->DataInput::ReadByteArray(bytes->GetByteArray(), offset, length);
    }
    
    bool ObjectInputObject::readBoolean()
    {
        return m_in->ReadBoolean();
    }

    int ObjectInputObject::readByte()
    {
        return (int8_t)m_in->ReadU8();
    }

    int ObjectInputObject::readUnsignedByte()
    {
        return m_in->ReadU8();
    }

    int ObjectInputObject::readShort()
    {
        return (int16_t)m_in->ReadU16();
    }

    int ObjectInputObject::readUnsignedShort()
    {
        return m_in->ReadU16();
    }

    int ObjectInputObject::readInt()
    {
        return (int32_t)m_in->ReadU32();
    }

    uint32_t ObjectInputObject::readUnsignedInt()
    {
        return m_in->ReadU32();
    }
    
    double ObjectInputObject::readFloat()
    {
        return m_in->ReadFloat();
    }

    double ObjectInputObject::readDouble()
    {
        return m_in->ReadDouble();
    }

    String* ObjectInputObject::readMultiByte(uint32_t length, String *charSet)
    {
        toplevel()->checkNull(charSet, "charSet");
        return m_in->ReadMultiByte(length, charSet);
    }
    
    String* ObjectInputObject::readUTF()
    {
        return m_in->ReadUTF();
    }

    String* ObjectInputObject::readUTFBytes(uint32_t length)
    {
        return m_in->ReadUTFBytes(length);
    }
    
    int ObjectInputObject::get_bytesAvailable()
    {
        return m_in->Available();
    }
    
    Atom ObjectInputObject::readObject()
    {
        // calling DataInput::readObject() would create a new DataInputWrapper,
        // which creates new reference tables, which we don't want. So we call
        // ReadAtom() explicitly. This assumes AMF3 is the only version for this code.
        AvmAssert(kAMF3 == kEncodeDefault);

        return m_in->AvmPlusObjectInput::ReadAtom();
    }

    uint32_t ObjectInputObject::get_objectEncoding()
    {
        return m_in->GetObjectEncoding();
    }

    void ObjectInputObject::set_objectEncoding(uint32_t objectEncoding)
    {
        if ((objectEncoding == kAMF3) || (objectEncoding == kAMF0))
        {
            m_in->SetObjectEncoding(ObjectEncoding(objectEncoding));
        }
        else
        {
            toplevel()->argumentErrorClass()->throwError(kInvalidEnumError, core()->toErrorString("objectEncoding"));
        }
    }

    Stringp ObjectInputObject::get_endian() {
        return (m_in->GetEndian() == kBigEndian) ? core()->kbigEndian : core()->klittleEndian;
    }

    void ObjectInputObject::set_endian(Stringp type) {
        toplevel()->checkNull(type, "endian");
        type = core()->internString(type);
        if (type == core()->kbigEndian)
        {
            m_in->SetEndian(kBigEndian);
        }
        else if (type == core()->klittleEndian)
        {
            m_in->SetEndian(kLittleEndian);
        }
        else
        {
            toplevel()->argumentErrorClass()->throwError(kInvalidEnumError, core()->toErrorString(kStrTypeValue));
        }
    }


    //
    // DynamicPropertyOutputClass
    //

    DynamicPropertyOutputClass::DynamicPropertyOutputClass(VTable *vtable) : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    void DynamicPropertyOutputObject::writeDynamicProperty(Stringp name, Atom value)
    {
        AvmAssert(NULL != m_out); // this should have been set after constructing the object
        if(NULL != m_out)
        {
            m_out->WriteDynamicProperty(name, value);
        }
    }

    //
    // ObjectEncodingClass
    //

    ObjectEncodingClass::ObjectEncodingClass(VTable *vtable) : ClassClosure(vtable), m_writer(GCREF_NULL(IDynamicPropertyWriterInterface))
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    ObjectEncodingClass::~ObjectEncodingClass() 
    { 
        m_writer = NULL;
    }
}

