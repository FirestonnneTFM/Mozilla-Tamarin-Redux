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

#ifndef __avmplus_ScriptObject_inlines__
#define __avmplus_ScriptObject_inlines__


namespace avmplus
{
REALLY_INLINE /*static*/ ScriptObject* ScriptObject::create(MMgc::GC* gc, VTable* vtable, ScriptObject* delegate)
{
    return new (gc, MMgc::kExact, vtable->getExtraSize()) ScriptObject(vtable, delegate);
}

REALLY_INLINE /*static*/ ScriptObject* ScriptObject::create(MMgc::GC* gc, VTable* vtable, ScriptObject* delegate, int htCapacity)
{
    return new (gc, MMgc::kExact, vtable->getExtraSize()) ScriptObject(vtable, delegate, htCapacity);
}

REALLY_INLINE ScriptObject* ScriptObject::getDelegate() const
{
    return delegate;
}

REALLY_INLINE void ScriptObject::setDelegate(ScriptObject *d)
{
    delegate = d;
}

REALLY_INLINE Atom ScriptObject::atom() const
{
    return kObjectType|(uintptr_t)this;
}

REALLY_INLINE /*virtual*/ Atom ScriptObject::toAtom() const
{
    return atom();
}

REALLY_INLINE Traits* ScriptObject::traits() const
{
    return vtable->traits;
}

REALLY_INLINE AvmCore* ScriptObject::core() const
{
    return vtable->traits->core;
}

REALLY_INLINE MMgc::GC* ScriptObject::gc() const
{
    return core()->GetGC();
}

REALLY_INLINE Toplevel* ScriptObject::toplevel() const
{
    return vtable->toplevel();
}

REALLY_INLINE InlineHashtable* ScriptObject::getTableNoInit() const
{
    InlineHashtable* iht = (InlineHashtable*)((uint8_t*)this + vtable->traits->getHashtableOffset());
    if(!vtable->traits->isDictionary())
    {
        return iht;
    }
    else
    {
        HeapHashtable** hht = (HeapHashtable**)iht;
        //DictionaryObjects store pointer to HeapHashtable at
        //the hashtable offset
        return (*hht)->get_ht();
    }
}

REALLY_INLINE Atom ScriptObject::getStringProperty(Stringp name) const
{
    AvmAssert(name != NULL && name->isInterned());
    return getAtomProperty(name->atom());
}

REALLY_INLINE Atom ScriptObject::getStringPropertyFromProtoChain(Stringp name, ScriptObject* protochain, Traits *origObjTraits) const
{
    return getAtomPropertyFromProtoChain(name->atom(), protochain, origObjTraits);
}

REALLY_INLINE void ScriptObject::setStringProperty(Stringp name, Atom value)
{
    setAtomProperty(name->atom(), value);
}

REALLY_INLINE bool ScriptObject::deleteStringProperty(Stringp name)
{
    return deleteAtomProperty(name->atom());
}

REALLY_INLINE bool ScriptObject::hasStringProperty(Stringp name) const
{
    AvmAssert(name != NULL && name->isInterned());
    return hasAtomProperty(name->atom());
}

REALLY_INLINE bool ScriptObject::getStringPropertyIsEnumerable(Stringp name) const
{
    AvmAssert(name != NULL && name->isInterned());
    return getAtomPropertyIsEnumerable(name->atom());
}

REALLY_INLINE void ScriptObject::setStringPropertyIsEnumerable(Stringp name, bool enumerable)
{
    setAtomPropertyIsEnumerable(name->atom(), enumerable);
}

REALLY_INLINE /*virtual*/ MethodClosure* ScriptObject::toMethodClosure() const
{
    return NULL;
}

REALLY_INLINE bool ScriptObject::isMethodClosure() const
{
    return toMethodClosure() != NULL;
}

REALLY_INLINE /*virtual*/ CodeContext* ScriptObject::getFunctionCodeContext() const
{
    AvmAssert(0);
    return NULL;
}

REALLY_INLINE /*virtual*/ ArrayObject* ScriptObject::toArrayObject()
{
    return NULL;
}

#if defined(DEBUGGER) || defined(VMCFG_AOT)
REALLY_INLINE /*virtual*/ MethodEnv* ScriptObject::getCallMethodEnv()
{
    return NULL;
}
#endif

REALLY_INLINE /*virtual*/ ClassClosure* ScriptObject::toClassClosure()
{
    return NULL;
}

}

#endif /* __avmplus_ScriptObject_inlines__ */
