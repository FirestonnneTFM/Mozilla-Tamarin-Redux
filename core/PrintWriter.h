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

#ifndef __avmplus_PrintWriter__
#define __avmplus_PrintWriter__


namespace avmplus
{
    /**
     * hexAddr is an operator that can be used with PrintWriter
     * to write out a dword/qword in hex
     */
    class hexAddr
    {
    public:
        hexAddr(uintptr_t _value) { this->value = _value; }
        hexAddr(const hexAddr& toCopy) { value = toCopy.value; }
        hexAddr& operator= (const hexAddr& toCopy) {
            value = toCopy.value;
            return *this;
        }
        uintptr_t getValue() const { return value; }

    private:
        uintptr_t value;
    };

    /**
     * asAtom is an operator to be used with PrintWriter
     * in order to write the value of an atom
     */
    class asAtom
    {
    public:
        asAtom(Atom a) : _atom(a) {}
        Atom _atom;
    };

    /**
     * asAtom is an operator to be used with PrintWriter
     * in order to write the value of an atom
     */
    class asAtomHex
    {
    public:
        asAtomHex(Atom a) : _atom(a) {}
        Atom _atom;
    };

    /**
     * asUTF16 is an operator to be used with PrintWriter
     * in order to write the contents of a wchar'd buffer
     */
    class asUTF16
    {
    public:
        asUTF16(wchar* w, uint32_t len) : _buf(w), _len(len) {}
        wchar* _buf;
        uint32_t _len;
    };

    /**
     * tabstop is an operator that can be used with PrintWriter
     * to advance to the specified tabstop
     */
    class tabstop
    {
    public:
        tabstop(int _spaces) { this->spaces = _spaces; }
        tabstop(const tabstop& toCopy) { spaces = toCopy.spaces; }
        tabstop& operator= (const tabstop& toCopy) {
            spaces = toCopy.spaces;
            return *this;
        }
        int getSpaces() const { return spaces; }

    private:
        int spaces;
    };

    class MethodRecognizer;

    /**
     * PrintWriter is a utility class for writing human-readable
     * text.  It has an interface similar to the C++ iostreams
     * library, overloading the "<<" operator to accept most
     * standard types used in the VM.
     *
     * A PrintWriter will keep any installed GCOutputStream alive.
     *
     * An exception can jump past the destructor of a PrintWriter without resources
     * leaking.
     *
     * NOTE!  This is *not* a GC class.  A PrintWriter instance *must* be allocated
     * on the stack, inside GCRoots, or inside GC'd objects (as a member, not a pointer).
     */
    class PrintWriter
    {
    private:
        static void *operator new(size_t size, MMgc::GC *gc); // private and not implemented, in order to catch errors

    public:
        PrintWriter(AvmCore* core) { m_core = core; }
        PrintWriter(AvmCore* core, GCOutputStream *stream) { m_core = core; m_stream.set(stream); }
        PrintWriter(AvmCore* core, NonGCOutputStream *stream) { m_core = core; m_stream.set(stream); }

        void setOutputStream(GCOutputStream *stream) { m_stream.set(stream); }
        void setOutputStream(NonGCOutputStream *stream) { m_stream.set(stream); }
        void setCore(AvmCore* core) { m_core = core; }

        void write(const char* utf8);  // null terminated
        void writeN(const char* utf8, size_t count);

        PrintWriter& operator<< (const char* str);
        PrintWriter& operator<< (char value);
        PrintWriter& operator<< (wchar value);
        PrintWriter& operator<< (int32_t value);
        PrintWriter& operator<< (uint32_t value);
        PrintWriter& operator<< (uint64_t value);
        PrintWriter& operator<< (int64_t value);
#if defined AVMPLUS_MAC && defined AVMPLUS_64BIT
        PrintWriter& operator<< (ptrdiff_t value);
#endif
        PrintWriter& operator<< (double value);
        PrintWriter& operator<< (const String* str);
        PrintWriter& operator<< (hexAddr tabs);
        PrintWriter& operator<< (asAtom a);
        PrintWriter& operator<< (asAtomHex a);
        PrintWriter& operator<< (asUTF16 a);
        PrintWriter& operator<< (bool b);
        PrintWriter& operator<< (const ScopeTypeChain* s);
        PrintWriter& operator<< (const ScopeChain* s);
        PrintWriter& operator<< (const MethodRecognizer* s);
        void writeAtom(Atom atom);
        void writeAtomHex(Atom atom);
        void writeUTF16(const void* buffer, size_t count);
        void writeHexByte(uint8_t value);
        void writeHexWord(uint16_t value);
        void writeHexAddr(uintptr_t value);
        void formatP(const char* format, Stringp arg1=0, Stringp arg2=0, Stringp arg3=0);

        AvmCore* core() { return m_core; }

    private:
        class StreamAdapter {
        public:
            StreamAdapter();
            void set(NonGCOutputStream* s);
            void set(GCOutputStream* s);
            void write(const char* utf8);
            void writeN(const char* utf8, size_t charCount);
        private:
            GCOutputStream*    gcStream;
            NonGCOutputStream* nongcStream;
        } m_stream;
        AvmCore *m_core;

        void writeHexNibble(uint8_t value);

        // These are defined for not DEBUGGER builds but fire asserts
    public:
        PrintWriter& operator<< (const ScriptObject* obj);
        PrintWriter& operator<< (const Traits* obj);
        PrintWriter& operator<< (const MethodInfo* obj);
        PrintWriter& operator<< (const NamespaceSet* obj);
        PrintWriter& operator<< (const Namespace* obj);
        PrintWriter& operator<< (const Multiname& obj);
    };
}

#endif /* __avmplus_PrintWriter__ */
