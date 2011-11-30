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


#ifndef OBJECTIOGLUE_INCLUDED
#define OBJECTIOGLUE_INCLUDED

namespace avmplus
{
    class ObjectOutput;
    class AvmPlusObjectOutput; // Needed to add to compile on Linux
    class AvmPlusObjectInput; // Needed to add to compile on Linux
    //
    // ObjectOutputObject
    //
    
    class GC_AS3_EXACT(ObjectOutputObject, ScriptObject)
    {
    public:
        ObjectOutputObject(VTable *vtable, GCRef<ScriptObject> delegate) : ScriptObject(vtable, delegate) {}
        virtual ~ObjectOutputObject() { m_out = 0; }

        void writeBytes(ByteArrayObject *bytes, uint32_t offset, uint32_t length);

        void writeBoolean(bool value);
        void writeByte(int value);
        void writeShort(int value);
        void writeInt(int value);
        void writeUnsignedInt(uint32_t value);
        void writeFloat(double value);
        void writeDouble(double value);
        void writeMultiByte(String *value, String *charSet);        
        void writeUTF(String *value);
        void writeUTFBytes(String *value);
        void writeObject(Atom value);

        uint32_t get_objectEncoding();
        void set_objectEncoding(uint32_t objectEncoding);

        Stringp get_endian();
        void set_endian(Stringp type);

        GC_DATA_BEGIN(ObjectOutputObject)
    public:
        AvmPlusObjectOutput *m_out;
        GC_DATA_END(ObjectOutputObject)
        
        DECLARE_SLOTS_ObjectOutputObject;
    };

    //
    // ObjectOutputClass
    //
    
    class GC_AS3_EXACT(ObjectOutputClass, ClassClosure)
    {
    public:
        ObjectOutputClass(VTable *vtable);

        DECLARE_SLOTS_ObjectOutputClass;

        GC_NO_DATA(ObjectOutputClass)
    };

    //
    // ObjectOutputInput
    //
    
    class GC_AS3_EXACT(ObjectInputObject, ScriptObject)
    {
    public:
        ObjectInputObject(VTable *vtable, GCRef<ScriptObject> delegate) : ScriptObject(vtable, delegate) {}
        virtual ~ObjectInputObject() { m_in = 0; }

        void readBytes(ByteArrayObject *bytes, uint32_t offset, uint32_t length);
        bool readBoolean();
        int readByte();
        int readUnsignedByte();
        int readShort();
        int readUnsignedShort();
        int readInt();
        uint32_t readUnsignedInt();
        double readFloat();
        double readDouble();
        String* readMultiByte(uint32_t length, String *charSet);
        String* readUTF();
        String* readUTFBytes(uint32_t length);        
        Atom readObject();

        int get_bytesAvailable();

        uint32_t get_objectEncoding();
        void set_objectEncoding(uint32_t objectEncoding);

        Stringp get_endian();
        void set_endian(Stringp type);

        GC_DATA_BEGIN(ObjectInputObject)
    public:
        AvmPlusObjectInput *m_in;

        GC_DATA_END(ObjectInputObject)
        
        DECLARE_SLOTS_ObjectInputObject;
    };

    //
    // ObjectInputClass
    //
    
    class GC_AS3_EXACT(ObjectInputClass, ClassClosure)
    {
    public:
        ObjectInputClass(VTable *vtable);

        GC_NO_DATA(ObjectInputClass)

        DECLARE_SLOTS_ObjectInputClass;
    };

    //
    // DynamicPropertyOutputObject
    //

    class GC_AS3_EXACT(DynamicPropertyOutputObject, ScriptObject)
    {
    public:
        DynamicPropertyOutputObject(VTable *vtable, GCRef<ScriptObject> delegate) : ScriptObject(vtable, delegate) {m_out = NULL;}
        virtual ~DynamicPropertyOutputObject() { m_out = NULL; }

        void writeDynamicProperty(Stringp name, Atom value);

        GC_DATA_BEGIN(DynamicPropertyOutputObject)
    public:
        ObjectOutput *m_out;

        GC_DATA_END(DynamicPropertyOutputObject)
        
        DECLARE_SLOTS_DynamicPropertyOutputObject;
    };

    //
    // DynamicPropertyOutputClass
    //
    
    class GC_AS3_EXACT(DynamicPropertyOutputClass, ClassClosure)
    {
    public:
        DynamicPropertyOutputClass(VTable *vtable);

        GC_NO_DATA(DynamicPropertyOutputClass)
        
        private:
        DECLARE_SLOTS_DynamicPropertyOutputClass;
    };

    //
    // ObjectEncodingClass
    //
    
    class GC_AS3_EXACT(ObjectEncodingClass, ClassClosure)
    {
    public:
        ObjectEncodingClass(VTable *vtable);
        ~ObjectEncodingClass();

        IDynamicPropertyWriterInterface* get_dynamicPropertyWriter() { return m_writer; }
        void set_dynamicPropertyWriter(IDynamicPropertyWriterInterface* writer) { m_writer = writer; }

        GC_DATA_BEGIN(ObjectEncodingClass)
        public:
        GCMember<IDynamicPropertyWriterInterface> GC_POINTER(m_writer);
        GC_DATA_END(ObjectEncodingClass)

        DECLARE_SLOTS_ObjectEncodingClass;
    };

}

#endif /* OBJECTIOGLUE_INCLUDED */

