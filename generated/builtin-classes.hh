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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
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

/* machine generated file -- do not edit */

#ifndef _H_nativegen_classes_builtin
#define _H_nativegen_classes_builtin

namespace avmplus {

// NOTE: The following classes are never actually instantiated as such;
// they are provided as a C++ front end onto pure AS3 classes.
//-----------------------------------------------------------
// flash.errors::IOError$
//-----------------------------------------------------------
class IOErrorClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit IOErrorClass(); // unimplemented
    explicit IOErrorClass(const IOErrorClass&); // unimplemented
    void operator=(const IOErrorClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.errors::MemoryError$
//-----------------------------------------------------------
class MemoryErrorClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit MemoryErrorClass(); // unimplemented
    explicit MemoryErrorClass(const MemoryErrorClass&); // unimplemented
    void operator=(const MemoryErrorClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.errors::EOFError$
//-----------------------------------------------------------
class EOFErrorClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit EOFErrorClass(); // unimplemented
    explicit EOFErrorClass(const EOFErrorClass&); // unimplemented
    void operator=(const EOFErrorClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm$
//-----------------------------------------------------------
class CompressionAlgorithmClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmplus::ScriptObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ScriptObject>((avmplus::ScriptObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::String* get_ZLIB() const { return m_slots_CompressionAlgorithmClass.get_ZLIB(); }
    REALLY_INLINE avmplus::String* get_DEFLATE() const { return m_slots_CompressionAlgorithmClass.get_DEFLATE(); }
private:
    avmplus::NativeID::avmplus_CompressionAlgorithmClassSlots m_slots_CompressionAlgorithmClass;
private:
    explicit CompressionAlgorithmClass(); // unimplemented
    explicit CompressionAlgorithmClass(const CompressionAlgorithmClass&); // unimplemented
    void operator=(const CompressionAlgorithmClass&); // unimplemented
};

}

#endif // _H_nativegen_classes_builtin
