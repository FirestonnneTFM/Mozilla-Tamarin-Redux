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

#ifndef _H_nativegen_classes_shell_toplevel
#define _H_nativegen_classes_shell_toplevel

namespace avmplus {

//-----------------------------------------------------------
// avmplus::CTest
//-----------------------------------------------------------
class CTestObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::CTestClass;
    REALLY_INLINE explicit CTestObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit CTestObject(const CTestObject&); // unimplemented
    void operator=(const CTestObject&); // unimplemented
};

//-----------------------------------------------------------
// avmplus::CTest$
//-----------------------------------------------------------
class CTestClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::CTestObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CTestObject>((avmplus::CTestObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::CTestObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CTestObject>((avmplus::CTestObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CTestObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CTestObject>((avmplus::CTestObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CTestObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CTestObject>((avmplus::CTestObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CTestObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CTestObject>((avmplus::CTestObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit CTestClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CTestClass(const CTestClass&); // unimplemented
    void operator=(const CTestClass&); // unimplemented
};

//-----------------------------------------------------------
// avmplus::System
//-----------------------------------------------------------
class SystemObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::SystemClass;
    REALLY_INLINE explicit SystemObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SystemObject(const SystemObject&); // unimplemented
    void operator=(const SystemObject&); // unimplemented
};

//-----------------------------------------------------------
// avmplus::File
//-----------------------------------------------------------
class FileObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::FileClass;
    REALLY_INLINE explicit FileObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit FileObject(const FileObject&); // unimplemented
    void operator=(const FileObject&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::NativeBaseAS3
//-----------------------------------------------------------
class NativeBaseAS3Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::NativeBaseAS3Class;
    REALLY_INLINE explicit NativeBaseAS3Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit NativeBaseAS3Object(const NativeBaseAS3Object&); // unimplemented
    void operator=(const NativeBaseAS3Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::NativeBaseAS3$
//-----------------------------------------------------------
class NativeBaseAS3Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct_native(avmplus::NativeBaseAS3Class::createInstanceProc, 0, args);
        return GCRef<avmplus::NativeBaseAS3Object>((avmplus::NativeBaseAS3Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::NativeBaseAS3Object>((avmplus::NativeBaseAS3Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::NativeBaseAS3Object>((avmplus::NativeBaseAS3Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::NativeBaseAS3Object>((avmplus::NativeBaseAS3Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::NativeBaseAS3Object>((avmplus::NativeBaseAS3Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit NativeBaseAS3Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit NativeBaseAS3Class(const NativeBaseAS3Class&); // unimplemented
    void operator=(const NativeBaseAS3Class&); // unimplemented
};

//-----------------------------------------------------------
// flash.system::Capabilities
//-----------------------------------------------------------
class CapabilitiesObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::CapabilitiesClass;
    REALLY_INLINE explicit CapabilitiesObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit CapabilitiesObject(const CapabilitiesObject&); // unimplemented
    void operator=(const CapabilitiesObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class CapabilitiesClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit CapabilitiesClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CapabilitiesClass(const CapabilitiesClass&); // unimplemented
    void operator=(const CapabilitiesClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class
//-----------------------------------------------------------
class public_classObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE bool get_public_var() const { return m_slots_public_classObject.m_public_var != 0; }
    REALLY_INLINE void set_public_var(bool32 newVal) { m_slots_public_classObject.m_public_var = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_0() const { return m_slots_public_classObject.m_public_var_AIR_1_0 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_0(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_0 = newVal; }
public:
    REALLY_INLINE bool get_public_var_FP_10_0() const { return m_slots_public_classObject.m_public_var_FP_10_0 != 0; }
    REALLY_INLINE void set_public_var_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_var_FP_10_0 = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_5() const { return m_slots_public_classObject.m_public_var_AIR_1_5 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_5(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_5 = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_5_1() const { return m_slots_public_classObject.m_public_var_AIR_1_5_1 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_5_1(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_5_1 = newVal; }
public:
    REALLY_INLINE bool get_public_var_FP_10_0_32() const { return m_slots_public_classObject.m_public_var_FP_10_0_32 != 0; }
    REALLY_INLINE void set_public_var_FP_10_0_32(bool32 newVal) { m_slots_public_classObject.m_public_var_FP_10_0_32 = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_5_2() const { return m_slots_public_classObject.m_public_var_AIR_1_5_2 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_5_2(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_5_2 = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_0_FP_10_0() const { return m_slots_public_classObject.m_public_var_AIR_1_0_FP_10_0 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_0_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_0_FP_10_0 = newVal; }
public:
    REALLY_INLINE bool get_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2() const { return m_slots_public_classObject.m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2 != 0; }
    REALLY_INLINE void set_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2(bool32 newVal) { m_slots_public_classObject.m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2 = newVal; }
public:
    REALLY_INLINE bool get_public_var_FP_10_0_32_AIR_1_0_FP_10_0() const { return m_slots_public_classObject.m_public_var_FP_10_0_32_AIR_1_0_FP_10_0 != 0; }
    REALLY_INLINE void set_public_var_FP_10_0_32_AIR_1_0_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_var_FP_10_0_32_AIR_1_0_FP_10_0 = newVal; }
public:
    REALLY_INLINE bool get_public_const() const { return m_slots_public_classObject.m_public_const != 0; }
    REALLY_INLINE void setconst_public_const(bool32 newVal) { m_slots_public_classObject.m_public_const = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_0() const { return m_slots_public_classObject.m_public_const_AIR_1_0 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_0(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_0 = newVal; }
public:
    REALLY_INLINE bool get_public_const_FP_10_0() const { return m_slots_public_classObject.m_public_const_FP_10_0 != 0; }
    REALLY_INLINE void setconst_public_const_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_const_FP_10_0 = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_5() const { return m_slots_public_classObject.m_public_const_AIR_1_5 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_5(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_5 = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_5_1() const { return m_slots_public_classObject.m_public_const_AIR_1_5_1 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_5_1(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_5_1 = newVal; }
public:
    REALLY_INLINE bool get_public_const_FP_10_0_32() const { return m_slots_public_classObject.m_public_const_FP_10_0_32 != 0; }
    REALLY_INLINE void setconst_public_const_FP_10_0_32(bool32 newVal) { m_slots_public_classObject.m_public_const_FP_10_0_32 = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_5_2() const { return m_slots_public_classObject.m_public_const_AIR_1_5_2 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_5_2(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_5_2 = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_0_FP_10_0() const { return m_slots_public_classObject.m_public_const_AIR_1_0_FP_10_0 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_0_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_0_FP_10_0 = newVal; }
public:
    REALLY_INLINE bool get_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2() const { return m_slots_public_classObject.m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2 != 0; }
    REALLY_INLINE void setconst_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2(bool32 newVal) { m_slots_public_classObject.m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2 = newVal; }
public:
    REALLY_INLINE bool get_public_const_FP_10_0_32_AIR_1_0_FP_10_0() const { return m_slots_public_classObject.m_public_const_FP_10_0_32_AIR_1_0_FP_10_0 != 0; }
    REALLY_INLINE void setconst_public_const_FP_10_0_32_AIR_1_0_FP_10_0(bool32 newVal) { m_slots_public_classObject.m_public_const_FP_10_0_32_AIR_1_0_FP_10_0 = newVal; }
private:
    avmplus::NativeID::avmplus_public_classObjectSlots m_slots_public_classObject;
protected:
    friend class avmplus::public_classClass;
    REALLY_INLINE explicit public_classObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_classObject(const public_classObject&); // unimplemented
    void operator=(const public_classObject&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class$
//-----------------------------------------------------------
class public_classClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_classObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_classObject>((avmplus::public_classObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_classObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_classObject>((avmplus::public_classObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_classObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_classObject>((avmplus::public_classObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_classObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_classObject>((avmplus::public_classObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_classObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_classObject>((avmplus::public_classObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_classClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_classClass(const public_classClass&); // unimplemented
    void operator=(const public_classClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0
//-----------------------------------------------------------
class public_class_AIR_1_0Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_0Class;
    REALLY_INLINE explicit public_class_AIR_1_0Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_0Object(const public_class_AIR_1_0Object&); // unimplemented
    void operator=(const public_class_AIR_1_0Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0$
//-----------------------------------------------------------
class public_class_AIR_1_0Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_0Object>((avmplus::public_class_AIR_1_0Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_0Object>((avmplus::public_class_AIR_1_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_0Object>((avmplus::public_class_AIR_1_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_0Object>((avmplus::public_class_AIR_1_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_0Object>((avmplus::public_class_AIR_1_0Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_0Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_0Class(const public_class_AIR_1_0Class&); // unimplemented
    void operator=(const public_class_AIR_1_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0
//-----------------------------------------------------------
class public_class_FP_10_0Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_FP_10_0Class;
    REALLY_INLINE explicit public_class_FP_10_0Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_FP_10_0Object(const public_class_FP_10_0Object&); // unimplemented
    void operator=(const public_class_FP_10_0Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0$
//-----------------------------------------------------------
class public_class_FP_10_0Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_FP_10_0Object>((avmplus::public_class_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0Object>((avmplus::public_class_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0Object>((avmplus::public_class_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0Object>((avmplus::public_class_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0Object>((avmplus::public_class_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_FP_10_0Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_FP_10_0Class(const public_class_FP_10_0Class&); // unimplemented
    void operator=(const public_class_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5
//-----------------------------------------------------------
class public_class_AIR_1_5Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_5Class;
    REALLY_INLINE explicit public_class_AIR_1_5Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_5Object(const public_class_AIR_1_5Object&); // unimplemented
    void operator=(const public_class_AIR_1_5Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5$
//-----------------------------------------------------------
class public_class_AIR_1_5Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_5Object>((avmplus::public_class_AIR_1_5Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5Object>((avmplus::public_class_AIR_1_5Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5Object>((avmplus::public_class_AIR_1_5Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5Object>((avmplus::public_class_AIR_1_5Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5Object>((avmplus::public_class_AIR_1_5Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_5Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_5Class(const public_class_AIR_1_5Class&); // unimplemented
    void operator=(const public_class_AIR_1_5Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1
//-----------------------------------------------------------
class public_class_AIR_1_5_1Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_5_1Class;
    REALLY_INLINE explicit public_class_AIR_1_5_1Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_5_1Object(const public_class_AIR_1_5_1Object&); // unimplemented
    void operator=(const public_class_AIR_1_5_1Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1$
//-----------------------------------------------------------
class public_class_AIR_1_5_1Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_5_1Object>((avmplus::public_class_AIR_1_5_1Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_1Object>((avmplus::public_class_AIR_1_5_1Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_1Object>((avmplus::public_class_AIR_1_5_1Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_1Object>((avmplus::public_class_AIR_1_5_1Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_1Object>((avmplus::public_class_AIR_1_5_1Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_5_1Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_5_1Class(const public_class_AIR_1_5_1Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_1Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32
//-----------------------------------------------------------
class public_class_FP_10_0_32Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_FP_10_0_32Class;
    REALLY_INLINE explicit public_class_FP_10_0_32Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_FP_10_0_32Object(const public_class_FP_10_0_32Object&); // unimplemented
    void operator=(const public_class_FP_10_0_32Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32$
//-----------------------------------------------------------
class public_class_FP_10_0_32Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_FP_10_0_32Object>((avmplus::public_class_FP_10_0_32Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0_32Object>((avmplus::public_class_FP_10_0_32Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0_32Object>((avmplus::public_class_FP_10_0_32Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0_32Object>((avmplus::public_class_FP_10_0_32Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0_32Object>((avmplus::public_class_FP_10_0_32Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_FP_10_0_32Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_FP_10_0_32Class(const public_class_FP_10_0_32Class&); // unimplemented
    void operator=(const public_class_FP_10_0_32Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2
//-----------------------------------------------------------
class public_class_AIR_1_5_2Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_5_2Class;
    REALLY_INLINE explicit public_class_AIR_1_5_2Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_5_2Object(const public_class_AIR_1_5_2Object&); // unimplemented
    void operator=(const public_class_AIR_1_5_2Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2$
//-----------------------------------------------------------
class public_class_AIR_1_5_2Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_5_2Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_5_2Class(const public_class_AIR_1_5_2Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_2Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class public_class_AIR_1_0_FP_10_0Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_0_FP_10_0Class;
    REALLY_INLINE explicit public_class_AIR_1_0_FP_10_0Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_0_FP_10_0Object(const public_class_AIR_1_0_FP_10_0Object&); // unimplemented
    void operator=(const public_class_AIR_1_0_FP_10_0Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class public_class_AIR_1_0_FP_10_0Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object>((avmplus::public_class_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object>((avmplus::public_class_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object>((avmplus::public_class_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object>((avmplus::public_class_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_0_FP_10_0Object>((avmplus::public_class_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_0_FP_10_0Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_0_FP_10_0Class(const public_class_AIR_1_0_FP_10_0Class&); // unimplemented
    void operator=(const public_class_AIR_1_0_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2
//-----------------------------------------------------------
class public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class;
    REALLY_INLINE explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object&); // unimplemented
    void operator=(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2$
//-----------------------------------------------------------
class public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object>((avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class public_class_FP_10_0_32_AIR_1_0_FP_10_0Object : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class;
    REALLY_INLINE explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Object(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Object(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Object&); // unimplemented
    void operator=(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Object&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class public_class_FP_10_0_32_AIR_1_0_FP_10_0Class : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object>((avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object>((avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object>((avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object>((avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object>((avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Class&); // unimplemented
    void operator=(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase
//-----------------------------------------------------------
class SubclassOfAbstractBaseObject : public avmshell::AbstractBaseObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SubclassOfAbstractBaseClass;
    REALLY_INLINE explicit SubclassOfAbstractBaseObject(VTable* ivtable, ScriptObject* delegate) : avmshell::AbstractBaseObject(ivtable, delegate) {}
private:
    explicit SubclassOfAbstractBaseObject(const SubclassOfAbstractBaseObject&); // unimplemented
    void operator=(const SubclassOfAbstractBaseObject&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase$
//-----------------------------------------------------------
class SubclassOfAbstractBaseClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SubclassOfAbstractBaseObject>((avmplus::SubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SubclassOfAbstractBaseObject>((avmplus::SubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfAbstractBaseObject>((avmplus::SubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SubclassOfAbstractBaseObject>((avmplus::SubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfAbstractBaseObject>((avmplus::SubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SubclassOfAbstractBaseClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SubclassOfAbstractBaseClass(const SubclassOfAbstractBaseClass&); // unimplemented
    void operator=(const SubclassOfAbstractBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase
//-----------------------------------------------------------
class SubclassOfRestrictedBaseObject : public avmshell::RestrictedBaseObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SubclassOfRestrictedBaseClass;
    REALLY_INLINE explicit SubclassOfRestrictedBaseObject(VTable* ivtable, ScriptObject* delegate) : avmshell::RestrictedBaseObject(ivtable, delegate) {}
private:
    explicit SubclassOfRestrictedBaseObject(const SubclassOfRestrictedBaseObject&); // unimplemented
    void operator=(const SubclassOfRestrictedBaseObject&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase$
//-----------------------------------------------------------
class SubclassOfRestrictedBaseClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SubclassOfRestrictedBaseObject>((avmplus::SubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SubclassOfRestrictedBaseObject>((avmplus::SubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfRestrictedBaseObject>((avmplus::SubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SubclassOfRestrictedBaseObject>((avmplus::SubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfRestrictedBaseObject>((avmplus::SubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SubclassOfRestrictedBaseClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SubclassOfRestrictedBaseClass(const SubclassOfRestrictedBaseClass&); // unimplemented
    void operator=(const SubclassOfRestrictedBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase
//-----------------------------------------------------------
class SubclassOfAbstractRestrictedBaseObject : public avmshell::AbstractRestrictedBaseObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SubclassOfAbstractRestrictedBaseClass;
    REALLY_INLINE explicit SubclassOfAbstractRestrictedBaseObject(VTable* ivtable, ScriptObject* delegate) : avmshell::AbstractRestrictedBaseObject(ivtable, delegate) {}
private:
    explicit SubclassOfAbstractRestrictedBaseObject(const SubclassOfAbstractRestrictedBaseObject&); // unimplemented
    void operator=(const SubclassOfAbstractRestrictedBaseObject&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class SubclassOfAbstractRestrictedBaseClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject>((avmplus::SubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject>((avmplus::SubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject>((avmplus::SubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject>((avmplus::SubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SubclassOfAbstractRestrictedBaseObject>((avmplus::SubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SubclassOfAbstractRestrictedBaseClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SubclassOfAbstractRestrictedBaseClass(const SubclassOfAbstractRestrictedBaseClass&); // unimplemented
    void operator=(const SubclassOfAbstractRestrictedBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::StackFrame
//-----------------------------------------------------------
class StackFrameObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_line() const { return m_slots_StackFrameObject.m_line; }
    REALLY_INLINE void setconst_line(uint32_t newVal) { m_slots_StackFrameObject.m_line = newVal; }
public:
    REALLY_INLINE avmplus::String* get_name() const { return m_slots_StackFrameObject.m_name; }
    REALLY_INLINE void setconst_name(avmplus::String* newVal) { m_slots_StackFrameObject.m_name = newVal; }
public:
    REALLY_INLINE avmplus::String* get_file() const { return m_slots_StackFrameObject.m_file; }
    REALLY_INLINE void setconst_file(avmplus::String* newVal) { m_slots_StackFrameObject.m_file = newVal; }
public:
    REALLY_INLINE double get_scriptID() const { return m_slots_StackFrameObject.m_scriptID; }
    REALLY_INLINE void setconst_scriptID(double newVal) { m_slots_StackFrameObject.m_scriptID = newVal; }
private:
    avmplus::NativeID::avmplus_StackFrameObjectSlots m_slots_StackFrameObject;
protected:
    friend class avmplus::StackFrameClass;
    REALLY_INLINE explicit StackFrameObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StackFrameObject(const StackFrameObject&); // unimplemented
    void operator=(const StackFrameObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::StackFrame$
//-----------------------------------------------------------
class StackFrameClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::StackFrameObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit StackFrameClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StackFrameClass(const StackFrameClass&); // unimplemented
    void operator=(const StackFrameClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::Sample
//-----------------------------------------------------------
class SampleObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ArrayObject* get_stack() const { return m_slots_SampleObject.m_stack; }
    REALLY_INLINE void setconst_stack(avmplus::ArrayObject* newVal) { m_slots_SampleObject.m_stack = newVal; }
public:
    REALLY_INLINE double get_time() const { return m_slots_SampleObject.m_time; }
    REALLY_INLINE void setconst_time(double newVal) { m_slots_SampleObject.m_time = newVal; }
private:
    avmplus::NativeID::avmplus_SampleObjectSlots m_slots_SampleObject;
protected:
    friend class avmplus::SampleClass;
    REALLY_INLINE explicit SampleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SampleObject(const SampleObject&); // unimplemented
    void operator=(const SampleObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::Sample$
//-----------------------------------------------------------
class SampleClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::SampleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SampleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SampleClass(const SampleClass&); // unimplemented
    void operator=(const SampleClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::ClassFactory
//-----------------------------------------------------------
class ClassFactoryObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ClassFactoryClass;
    REALLY_INLINE explicit ClassFactoryObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ClassFactoryObject(const ClassFactoryObject&); // unimplemented
    void operator=(const ClassFactoryObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::ClassFactory$
//-----------------------------------------------------------
class ClassFactoryClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ClassClosure* get_StackFrameClass() const { return m_slots_ClassFactoryClass.m_StackFrameClass; }
    REALLY_INLINE void setconst_StackFrameClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_StackFrameClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_SampleClass() const { return m_slots_ClassFactoryClass.m_SampleClass; }
    REALLY_INLINE void setconst_SampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_SampleClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_DeleteObjectSampleClass() const { return m_slots_ClassFactoryClass.m_DeleteObjectSampleClass; }
    REALLY_INLINE void setconst_DeleteObjectSampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_DeleteObjectSampleClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_NewObjectSampleClass() const { return m_slots_ClassFactoryClass.m_NewObjectSampleClass; }
    REALLY_INLINE void setconst_NewObjectSampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_NewObjectSampleClass = newVal; }
private:
    avmplus::NativeID::avmplus_ClassFactoryClassSlots m_slots_ClassFactoryClass;
protected:
    inline explicit ClassFactoryClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ClassFactoryClass(const ClassFactoryClass&); // unimplemented
    void operator=(const ClassFactoryClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class DeleteObjectSampleObject : public avmplus::SampleObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_id() const { return m_slots_DeleteObjectSampleObject.m_id; }
    REALLY_INLINE void setconst_id(double newVal) { m_slots_DeleteObjectSampleObject.m_id = newVal; }
public:
    REALLY_INLINE double get_size() const { return m_slots_DeleteObjectSampleObject.m_size; }
    REALLY_INLINE void setconst_size(double newVal) { m_slots_DeleteObjectSampleObject.m_size = newVal; }
private:
    avmplus::NativeID::avmplus_DeleteObjectSampleObjectSlots m_slots_DeleteObjectSampleObject;
protected:
    friend class avmplus::DeleteObjectSampleClass;
    REALLY_INLINE explicit DeleteObjectSampleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::SampleObject(ivtable, delegate) {}
private:
    explicit DeleteObjectSampleObject(const DeleteObjectSampleObject&); // unimplemented
    void operator=(const DeleteObjectSampleObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class DeleteObjectSampleClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit DeleteObjectSampleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit DeleteObjectSampleClass(const DeleteObjectSampleClass&); // unimplemented
    void operator=(const DeleteObjectSampleClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.trace::Trace
//-----------------------------------------------------------
class TraceObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::TraceClass;
    REALLY_INLINE explicit TraceObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit TraceObject(const TraceObject&); // unimplemented
    void operator=(const TraceObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::Endian
//-----------------------------------------------------------
class EndianObject : public avmplus::ScriptObject
{
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::EndianClass;
    REALLY_INLINE explicit EndianObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EndianObject(const EndianObject&); // unimplemented
    void operator=(const EndianObject&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class EndianClass : public avmplus::ClassClosure
{
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::EndianObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_BIG_ENDIAN() const { return m_slots_EndianClass.m_BIG_ENDIAN; }
    REALLY_INLINE void setconst_BIG_ENDIAN(avmplus::String* newVal) { m_slots_EndianClass.m_BIG_ENDIAN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LITTLE_ENDIAN() const { return m_slots_EndianClass.m_LITTLE_ENDIAN; }
    REALLY_INLINE void setconst_LITTLE_ENDIAN(avmplus::String* newVal) { m_slots_EndianClass.m_LITTLE_ENDIAN = newVal; }
private:
    avmplus::NativeID::avmplus_EndianClassSlots m_slots_EndianClass;
protected:
    inline explicit EndianClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EndianClass(const EndianClass&); // unimplemented
    void operator=(const EndianClass&); // unimplemented
};

}

#endif // _H_nativegen_classes_shell_toplevel
