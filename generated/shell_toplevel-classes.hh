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

// NOTE: The following classes are never actually instantiated as such;
// they are provided as a C++ front end onto pure AS3 classes.
//-----------------------------------------------------------
// avmplus::CTest$
//-----------------------------------------------------------
class CTestClass : public avmplus::ClassClosure
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
private:
    explicit CTestClass(); // unimplemented
    explicit CTestClass(const CTestClass&); // unimplemented
    void operator=(const CTestClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class CapabilitiesClass : public avmplus::ClassClosure
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
private:
    explicit CapabilitiesClass(); // unimplemented
    explicit CapabilitiesClass(const CapabilitiesClass&); // unimplemented
    void operator=(const CapabilitiesClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class$
//-----------------------------------------------------------
class public_classClass : public avmplus::ClassClosure
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
private:
    explicit public_classClass(); // unimplemented
    explicit public_classClass(const public_classClass&); // unimplemented
    void operator=(const public_classClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0$
//-----------------------------------------------------------
class public_class_AIR_1_0Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_0Class(); // unimplemented
    explicit public_class_AIR_1_0Class(const public_class_AIR_1_0Class&); // unimplemented
    void operator=(const public_class_AIR_1_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0$
//-----------------------------------------------------------
class public_class_FP_10_0Class : public avmplus::ClassClosure
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
private:
    explicit public_class_FP_10_0Class(); // unimplemented
    explicit public_class_FP_10_0Class(const public_class_FP_10_0Class&); // unimplemented
    void operator=(const public_class_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5$
//-----------------------------------------------------------
class public_class_AIR_1_5Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_5Class(); // unimplemented
    explicit public_class_AIR_1_5Class(const public_class_AIR_1_5Class&); // unimplemented
    void operator=(const public_class_AIR_1_5Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1$
//-----------------------------------------------------------
class public_class_AIR_1_5_1Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_5_1Class(); // unimplemented
    explicit public_class_AIR_1_5_1Class(const public_class_AIR_1_5_1Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_1Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32$
//-----------------------------------------------------------
class public_class_FP_10_0_32Class : public avmplus::ClassClosure
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
private:
    explicit public_class_FP_10_0_32Class(); // unimplemented
    explicit public_class_FP_10_0_32Class(const public_class_FP_10_0_32Class&); // unimplemented
    void operator=(const public_class_FP_10_0_32Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2$
//-----------------------------------------------------------
class public_class_AIR_1_5_2Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_5_2Class(); // unimplemented
    explicit public_class_AIR_1_5_2Class(const public_class_AIR_1_5_2Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_2Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class public_class_AIR_1_0_FP_10_0Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_0_FP_10_0Class(); // unimplemented
    explicit public_class_AIR_1_0_FP_10_0Class(const public_class_AIR_1_0_FP_10_0Class&); // unimplemented
    void operator=(const public_class_AIR_1_0_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2$
//-----------------------------------------------------------
class public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class : public avmplus::ClassClosure
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
private:
    explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(); // unimplemented
    explicit public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class&); // unimplemented
    void operator=(const public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class public_class_FP_10_0_32_AIR_1_0_FP_10_0Class : public avmplus::ClassClosure
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
private:
    explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(); // unimplemented
    explicit public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Class&); // unimplemented
    void operator=(const public_class_FP_10_0_32_AIR_1_0_FP_10_0Class&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase$
//-----------------------------------------------------------
class SubclassOfAbstractBaseClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmshell::AbstractBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmshell::AbstractBaseObject>((avmshell::AbstractBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit SubclassOfAbstractBaseClass(); // unimplemented
    explicit SubclassOfAbstractBaseClass(const SubclassOfAbstractBaseClass&); // unimplemented
    void operator=(const SubclassOfAbstractBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase$
//-----------------------------------------------------------
class SubclassOfRestrictedBaseClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit SubclassOfRestrictedBaseClass(); // unimplemented
    explicit SubclassOfRestrictedBaseClass(const SubclassOfRestrictedBaseClass&); // unimplemented
    void operator=(const SubclassOfRestrictedBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class SubclassOfAbstractRestrictedBaseClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmshell::AbstractRestrictedBaseObject>((avmshell::AbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
private:
    explicit SubclassOfAbstractRestrictedBaseClass(); // unimplemented
    explicit SubclassOfAbstractRestrictedBaseClass(const SubclassOfAbstractRestrictedBaseClass&); // unimplemented
    void operator=(const SubclassOfAbstractRestrictedBaseClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class EndianClass : public avmplus::ClassClosure
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
public:
    REALLY_INLINE avmplus::String* get_BIG_ENDIAN() const { return m_slots_EndianClass.get_BIG_ENDIAN(); }
public:
    REALLY_INLINE avmplus::String* get_LITTLE_ENDIAN() const { return m_slots_EndianClass.get_LITTLE_ENDIAN(); }
private:
    avmplus::NativeID::avmplus_EndianClassSlots m_slots_EndianClass;
private:
    explicit EndianClass(); // unimplemented
    explicit EndianClass(const EndianClass&); // unimplemented
    void operator=(const EndianClass&); // unimplemented
};

}

#endif // _H_nativegen_classes_shell_toplevel
