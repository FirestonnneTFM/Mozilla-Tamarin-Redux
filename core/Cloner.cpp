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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

namespace avmplus {

    Cloner::Cloner(Toplevel* target)
        : interrupted(false)
        , m_target(target)
    {
    }

    Toplevel* Cloner::target()
    {
        return m_target;
    }
    void Cloner::destroy()
    {
        m_map.Destroy();
    }

    void Cloner::registerClone(const ScriptObject* original, ScriptObject* clone)
    {
        bool ok = m_map.InsertItem(original, clone);
        (void)ok;
        AvmAssert(ok);
    }

    void Cloner::cloneDynamicProperties(const ScriptObject* obj, ScriptObject* newObj, bool onlyValueKeys)
    {
        AvmAssert(m_target->core() == AvmCore::getActiveCore());
        InlineHashtable* ht = obj->getTable();
        AvmAssert(ht != NULL);
        AvmCore* targetCore = newObj->core();
        AvmAssert(targetCore == AvmCore::getActiveCore());
        AvmCore* sourceCore = obj->core(); // Faster alternative?
        AvmAssert(targetCore == sourceCore || ht->hasIterIndex());

        for (int i = ht->next(0); i != 0; i = ht->next(i)) {
            Atom key = ht->keyAt(i);
            Atom keyKind = atomKind(key);
            Atom value = ht->valueAt(i);
            // value is a private copy, so it should be immutable.
            // String dynmamicization and String::_append are a curious special case.
            Atom newValue = this->cloneAtom(value);
            if (newValue == undefinedAtom)
                continue; // functions
            if (keyKind == kStringType) {
                // Key better be immutable. Again, string dynamicization and String::_append are a curious special case.
                String* stringKey = AvmCore::atomToString(key);
                String* newStringKey = (sourceCore == targetCore) ? stringKey : targetCore->internForeignString(stringKey);
                // FIXME what if newObj has a slot with the same name? Is it even a dynamic type??
                AvmAssert(newObj->traits()->needsHashtable());
                newObj->setStringProperty(newStringKey, newValue);
            } else if (keyKind == kIntptrType) {
                uint32_t index;
                if (AvmCore::getIndexFromAtom(key, &index)) {
                    newObj->setUintProperty(index, newValue);
                } else {
                    AvmAssert(false);
                }
            } else {
                bool isKeyValue = (keyKind == kDoubleType); // handled strings already
                if (newObj->vtable->traits->isDictionary()) {
                    DictionaryObject* newDict = static_cast<DictionaryObject*>(newObj);
                    isKeyValue = !newDict->isUsingWeakKeys(); // we pretend that all keys are not values so that we can drop them
                    // FIXME
                }
                if (isKeyValue != true && onlyValueKeys == true)
                    continue;
                Atom newKey = this->cloneAtom(key);
                if (newKey == undefinedAtom)
                    continue; // functions
                newObj->setAtomProperty(newKey, newValue);
            }
        }
    }

    typedef void (*CloneOp)(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* args);

    static void cloneAtomSlot(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        Atom copy = cloner.cloneAtom(*(Atom*)slotPtr);
        WBATOM(gc, newObj, (Atom*)newSlotPtr, copy);
    }

    static void cloneScriptObjectSlot(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        AvmAssert(Cloner::canCoerce(obj->toplevel(), obj->traits(), newObj->toplevel(), newObj->traits()));
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        GCRef<const ScriptObject> copy = cloner.cloneScriptObject(*(const ScriptObject**)slotPtr);
        WBRC(gc, newObj, (ScriptObject**)newSlotPtr, copy);
    }

    static void checkedCloneScriptObjectSlot(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {

        Traits* fromTraits = (Traits*)code[1];
        int newSlotId = (int)code[2];
        Traits* toTraits = Cloner::typeAt(newObj->traits(), newSlotId);

        if (toTraits == NULL || !Cloner::canCoerce(obj->toplevel(), fromTraits, newObj->toplevel(), toTraits)) {
            newObj->toplevel()->throwTypeError(kCheckTypeFailedError, toTraits->name(), fromTraits->name());
        }
        cloneScriptObjectSlot(cloner, gc, obj, newObj, code);
    }

    Traits* Cloner::typeAt(Traits* traits, int slotId) 
    {
        const TraitsBindings::SlotInfo* slots = traits->getTraitsBindings()->getSlots();
        AvmAssert(slotId < (int)traits->getTraitsBindings()->slotCount);
        // FIXME this is too restrictive, string can be coerced to object, etc
        if (SST_scriptobject != slots[slotId].sst()) {
            return NULL;
        }
        return slots[slotId].type;
    }

    static void cloneStringSlot(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        Stringp src = *(Stringp*)slotPtr;
        GCRef<String> copy = src ? cloner.cloneString(src) : NULL;
        WBRC(gc, newObj, (Stringp*)newSlotPtr, copy);
    }

    static void cloneLocalStringSlot(Cloner&, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        Stringp src = *(Stringp*)slotPtr;
        WBRC(gc, newObj, (Stringp*)newSlotPtr, src);
    }

    static void cloneNamespaceSlot(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        GCRef<Namespace> copy = cloner.cloneNamespace(*(Namespacep*)slotPtr);
        WBRC(gc, newObj, (Namespacep*)newSlotPtr, copy);
    }

    static void cloneSignedWordSlot(Cloner& , MMgc::GC*, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        *(int32_t*)newSlotPtr = *(int32_t*)slotPtr;
    }

    static void cloneUnsignedWordSlot(Cloner&, MMgc::GC*, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        *(uint32_t*)newSlotPtr = *(uint32_t*)slotPtr;
    }

    static void cloneDoubleSlot(Cloner&, MMgc::GC*, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotPtr = intptr_t(obj) + code[1];
        intptr_t newSlotPtr = intptr_t((ScriptObject*)(newObj)) + code[2];
        *(double*)newSlotPtr = *(double*)slotPtr;
    }

    static void cloneSlotIntoProperty(Cloner& cloner, MMgc::GC*, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        intptr_t slotId = code[1];
        Stringp key = (Stringp)code[2];
        const TraitsBindingsp td = obj->traits()->getTraitsBindings();

        void* p;
        const SlotStorageType sst = td->calcSlotAddrAndSST((uint32_t)slotId, (void*)obj, p);
        // compare with ScriptObject::getSlotAtom()
        Atom value;
        if (sst == SST_atom)
        {
            value = cloner.cloneAtom(*((const Atom*)p));        
        }
        else if (sst == SST_double)
        {
            value = newObj->core()->doubleToAtom(*((const double*)p));
        }
#ifdef VMCFG_FLOAT
        else if (sst == SST_float)
        {
            AvmAssert(false); 
        }
        else if (sst == SST_float4)
        {
            AvmAssert(false);
        }
#endif // VMCFG_FLOAT
        else if (sst == SST_int32)
        {
            value = newObj->core()->intToAtom(*((const int32_t*)p));
        }
        else if (sst == SST_uint32)
        {
            value = newObj->core()->uintToAtom(*((const int32_t*)p));
        }
        else if (sst == SST_bool32)
        {
            value =(*((const int32_t*)p)<<3)|kBooleanType;
        }
        else if (sst == SST_string)
        {
            String* string = *((String**)p);
            value = string ? cloner.cloneString(string)->toAtom() : nullStringAtom;
        }
        else if (sst == SST_namespace)
        {
            Namespace* ns = *((Namespace**)p);
            value = ns ? cloner.cloneNamespace(ns)->toAtom() : nullNsAtom;
        }
        else // if (sst == SST_scriptobject)
        {
            AvmAssert(sst == SST_scriptobject);
            ScriptObject* object = *((ScriptObject**)p);
            value = object ? cloner.cloneScriptObject(object)->toAtom() : nullObjectAtom;
        }
        newObj->setStringProperty(key, value);
    }

#if 0
    static void cloneGetterSetter(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj, const intptr_t* code)
    {
        // FIXME handle exceptions?
        int getter_id = int(code[1]);
        if (obj->core() == newObj->core()) {
            int setter_id = int(code[2]);
            // Local copy
            VTable* vtable = obj->toplevel()->toVTable(obj->toAtom());
            MethodEnv *sourceGetter = vtable->methods[getter_id];
            Atom value = sourceGetter->coerceEnter(obj->toAtom());
            MethodEnv *targetSetter = vtable->methods[setter_id];
            Atom args[] = { obj->toAtom(), cloner.cloneAtom(value) };
            targetSetter->coerceEnter(1, args);
        } else if (gc == obj->gc()) {
            VTable* vtable = obj->toplevel()->toVTable(obj->toAtom());
            MethodEnv *sourceGetter = vtable->methods[getter_id];
            Atom value = sourceGetter->coerceEnter(obj->toAtom());
            cloner.saveGetterResult(obj, getter_id, cloner.cloneAtom(value));
        } else if (gc == newObj->gc()) {
            Atom value = cloner.restoreGetterResult(obj, getter_id);
            if (value != unreachableAtom) {
                int setter_id = int(code[2]);
                VTable* vtable = newObj->toplevel()->toVTable(newObj->toAtom());
                MethodEnv *targetSetter = vtable->methods[setter_id];
                // run the setter
                Atom args[] = { newObj->toAtom(), cloner.cloneAtom(value) };
                targetSetter->coerceEnter(1, args);
            }
        } else AvmAssert(false);
    }
#endif
    /*
    struct AccessedValueList
    {
        int disp;
        Atom value;
        AccessedValueList* next;
    };
    */
    

    Atom Cloner::restoreGetterResult(ScriptObject* obj, int disp)
    {
        (void)disp;
        const AvmPlusScriptableObject* info;
        bool ok = m_map.LookupItem(obj, &info);
        if (!ok) {
            return unreachableAtom;
        }
        /*
        AccessedValueList* list = (AccessedValueList*)info.context;
        fprintf(stderr,"restore on %p list %p\n", obj, list);

        while (list != NULL) {
            if (list->disp == disp) {
                obj->core()->console << "got value " << asAtom(list->value) << " at disp " << disp << " context " << hexAddr(uintptr_t(info.context)) << "\n";
                return list->value;
            }
            list = list->next;
        }
        */
        return undefinedAtom;
    }

    void Cloner::saveGetterResult(ScriptObject* obj, int disp, Atom value)
    {
        (void)disp;
        (void)value;
        const AvmPlusScriptableObject* info;
        bool ok = m_map.LookupItem(obj, &info);
        if (!ok) {
            return;

        }
        fprintf(stderr,"save  on %p\n", obj);
        /*
        AccessedValueList* list = (AccessedValueList*)info.context;
        if (list == NULL) {
            info.context = list = mmfx_new(AccessedValueList);
            list->next = NULL;
        } else {
            AccessedValueList* next = list->next;
            while (next != NULL) {
                list = next;
                next = list->next;
            }
            list->next = mmfx_new(AccessedValueList);
            list = next;
        }
        list->disp = disp;
        list->value = value;
        */
        
        
        // hash newObj & dispid 
    }



    /*static*/ bool Cloner::canCoerce(Toplevel* fromTl, Traits* fromTraits, Toplevel* toTl, Traits* toTraits)
    {
        if (Traits::getBuiltinType(fromTraits) == Traits::getBuiltinType(toTraits))
            return true;
        if (fromTraits == fromTl->byteArrayClass()->ivtable()->traits
            && toTraits == toTl->byteArrayClass()->ivtable()->traits) {
            return true;
        } else if (fromTraits == fromTl->builtinClasses()->get_DictionaryClass()->ivtable()->traits
                   && toTraits == toTl->builtinClasses()->get_DictionaryClass()->ivtable()->traits) {
            return true;
        }


        String* fromAlias = fromTl->getAliasFromTraits(fromTraits);
        String* toAlias = toTl->getAliasFromTraits(toTraits);

        if (toTraits != toTl->core()->traits.object_itraits && fromAlias->isEmpty()) {
            // if toTraits is not Object, and fromTraits is not registered, we can't coerce because fromTraits will end up being an Object
            return false;

        }
        return fromAlias->equals(toAlias);
    }

    static const char kTransient[] = "Transient";

    bool TraitsMorpher::containsTransientMetadata(PoolObject* pool, const uint8_t* meta_pos) {
        return meta_pos ? pool->hasMetadataName(meta_pos, m_targetTraits->core->internConstantStringLatin1(kTransient)) : false;
    }

    bool TraitsMorpher::slotContainsTransientMetadata(Traits *traits, int index)
    {
        PoolObject* pool = NULL;
        const uint8_t* pos = traits->getTraitsMetadata()->getSlotMetadataPos(index, pool);
        return containsTransientMetadata(pool, pos);
    }

    bool TraitsMorpher::isSerializable(Traits* traits, Namespacep ns, Binding b, AvmCore* currentCore)
    {
        // cf avmplus::ClassInfo::isSerializable()
        // Note that if we are in receive(), traits->core may be different from currentCore 
        (void)b;

        if (!ns->isPublic() || (ns->getApiVersion() > currentCore->getDefaultAPI())) {
            // The original AMF calls Orignal currentCore->isNamespaceVisibleToApiVersionFromCallStack(ns)),
            // i.e., it walks the stack to determine the API version. We choose the default API version.
            // Compiling TraitsMorpher means that the API version at lazy compile time could be captured in one versioning context and 
            // the TraitsMorpher reused in a different versioning context.
            // This may cause subtle versioning issues.
            // 
            return false;
        } else if (AvmCore::isVarBinding(b)) {
            uint32_t slot = AvmCore::bindingToSlotId(b);
            if (slotContainsTransientMetadata(traits, slot)) {
                // exclude slots contain metadata transient
                return false;
            }
        }
        return true;
    }

    // FIXME rename to maybeCompile
    bool TraitsMorpher::compile(Traits* traits, Traits* newTraits, Toplevel* toplevel, Toplevel* newToplevel)
    {
        // serializable slots in traits, serializable traits in newTraits, (offset -> offset) or (offset -> name)
        // post factum, if obj has properties that match slots in newObj, these should be handled
        // so we need a map from propnames to slots in newObj

        TraitsBindingsp tb = traits->getTraitsBindings();
        if (this->m_mostRecentSourceTraits == traits) {
            return this->m_mostRecentCode != NULL;
        }
        unsigned totalSlotCount = tb->slotCount;
        if (totalSlotCount == 0) {
            this->m_mostRecentSourceTraits = traits;
            WB_NULL(&this->m_mostRecentCode);
            return NULL;
        }
        MMgc::GC* gc = newTraits->core->gc;
        GCRef<intptr_t> code = (intptr_t*)gc->Alloc(sizeof(intptr_t)*totalSlotCount*3);
        WB(gc, this, &this->m_mostRecentCode, (intptr_t*)code);
        this->m_mostRecentSourceTraits = traits;

        AvmCore* targetCore = newTraits->core;

        TraitsBindingsp newTraitsBindings = newTraits->getTraitsBindings();
        const TraitsBindings::SlotInfo* newSlots = newTraitsBindings->getSlots();

        int pc = 0;
        for (Traitsp currentTraits = traits; currentTraits != NULL; currentTraits = currentTraits->base)
        {
            TraitsBindingsp currentTb = currentTraits->getTraitsBindings();
            const TraitsBindings::SlotInfo* slots = currentTb->getSlots();
            StTraitsBindingsIterator iter(currentTb);
            Stringp key = NULL;
            while (iter.next()) {
                key = iter.key();
                if (!key) continue;

                Binding b = iter.value();
                if (!isSerializable(traits, iter.ns(), b, targetCore))
                    continue;
                if (AvmCore::isAccessorBinding(b)) {
                    if (AvmCore::hasSetterBinding(b)) {
                        if (AvmCore::hasGetterBinding(b)) {
                            /*
                              code[pc++] = (intptr_t)cloneGetterSetter;
                              code[pc++] = (intptr_t)AvmCore::bindingToGetterId(b);
                              code[pc++] = (intptr_t)AvmCore::bindingToSetterId(b);
                            */
                        } // else what?
                    } 
                    continue;
                } else if (!AvmCore::isSlotBinding(b))
                    continue;
                int slotId = AvmCore::bindingToSlotId(b);

                intptr_t offset = (intptr_t)slots[slotId].offset();
                if (newTraits == targetCore->traits.object_itraits) {
                    // FIXME if newTraits does not contain slot with the name 'key'
                    code[pc++] = (intptr_t)cloneSlotIntoProperty;
                    code[pc++] = slotId;
                    code[pc++] = (intptr_t)targetCore->internForeignString(key);
                } else {
                    SlotStorageType type = slots[slotId].sst();
                    if (type != newSlots[slotId].sst()) {
                        newToplevel->throwTypeError(kCheckTypeFailedError, slots[slotId].type->name(), newSlots[slotId].type->name());
                    }

                    switch (slots[slotId].sst()) {
                    case SST_atom: {
                        //fprintf(stderr, "pc %d slot %d: atom %d\n", pc, slotId, (int)offset);
                        code[pc++] = (intptr_t)cloneAtomSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    case SST_scriptobject: {
                        // fprintf(stderr, "pc %d slot %d: offset %d\n", pc, slotId, (int)offset);
                        AvmAssert(slotId < (int)newTraitsBindings->slotCount);
                        if (!Cloner::canCoerce(toplevel, slots[slotId].type, newToplevel, newSlots[slotId].type)) { // FIXME this could be a maybe
                            // static check failed, do a dynamic check.
                            code[pc++] = (intptr_t)checkedCloneScriptObjectSlot;
                            // we burn in slot address in the code, note that it exists until traitsbindings is dropped, but that doesn't happen
                            // as long as the alias is registered, so the slot should survive the morpher
                            
                            code[pc++] = intptr_t(slots[slotId].type);
                            code[pc++] = slotId;
                        } else {
                            code[pc++] = intptr_t(cloneScriptObjectSlot);
                            // must be registered under the same name
                            code[pc++] = offset;
                            code[pc++] = offset;
                        }
                        //
                        break;
                    }
                    case SST_string: {
                        //fprintf(stderr, "pc %d slot %d: string %d\n", pc, slotId, (int)offset);
                        // if source and target are local, no need to copy
                        code[pc++] = (traits->core == targetCore) ? (intptr_t)cloneLocalStringSlot : (intptr_t)cloneStringSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    case SST_bool32:
                    case SST_int32: {
                        //fprintf(stderr, "pc %d slot %d: int/bool %d\n", pc, slotId, (int)offset);
                        code[pc++] = (intptr_t)cloneSignedWordSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    case SST_double: {
                        //fprintf(stderr, "pc %d slot %d: number %d\n", pc, slotId, (int)offset);
                        code[pc++] = (intptr_t)cloneDoubleSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    case SST_uint32: {
                        //fprintf(stderr, "pc %d slot %d: uint %d\n", pc, slotId, (int)offset);
                        code[pc++] = (intptr_t)cloneUnsignedWordSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    case SST_namespace: {
                        //fprintf(stderr, "pc %d slot %d: ns %d\n", pc, slotId, (int)offset);
                        code[pc++] = (intptr_t)cloneNamespaceSlot;
                        code[pc++] = offset;
                        code[pc++] = offset;
                        break;
                    }
                    default:
                        AvmAssert(false);
                    }
                }
            }
            this->m_mostRecentCodeLength = pc - 1;
        }

        return code != NULL;
    }

    void TraitsMorpher::morph(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj)
    {
        for (int pc = 0; pc < this->m_mostRecentCodeLength; pc += 3) {
            CloneOp func = (CloneOp)m_mostRecentCode[pc];
            func(cloner, gc, obj, newObj, m_mostRecentCode + pc);
        }
    }

    ClassClosure* Cloner::targetClosureFor(Toplevel* sourceToplevel, Traits* sourceTraits)
    {
        switch (Traits::getBuiltinType(sourceTraits)) {
        case BUILTIN_object:
            return m_target->objectClass;
        case BUILTIN_array:
            return m_target->arrayClass();
        case BUILTIN_vectorint:
            return m_target->intVectorClass();
        case BUILTIN_vectoruint:
            return m_target->uintVectorClass();
        case BUILTIN_vectorobj:
            return m_target->objectVectorClass();
        case BUILTIN_vectordouble:
            return m_target->doubleVectorClass();
        case BUILTIN_date:
            return m_target->dateClass();
        case BUILTIN_xml:
            return m_target->xmlClass();
        }
        
        if (sourceTraits == sourceToplevel->byteArrayClass()->ivtable()->traits) {
            return m_target->byteArrayClass();
        } else if (sourceTraits == sourceToplevel->builtinClasses()->get_DictionaryClass()->ivtable()->traits) {
            return m_target->builtinClasses()->get_DictionaryClass();
        }

        Stringp alias = sourceToplevel->getAliasFromTraits(sourceTraits);
        // FIXME if target is of different type (degraded), we shouldn't use cloneNonSlots
        bool degraded = alias->isEmpty();
        if (sourceToplevel->core() != m_target->core()) {
            // Alias is potentially foreign, better be really immutable!
            alias = m_target->core()->internForeignString(alias);
        }
        // FIXME morpher to Object should be retireved based on the source type, not the destination type
        // FIXME rework morpher to cache based on destination traits, not source traits?
        GCRef<ClassClosure> targetClosure = degraded ? m_target->objectClass : m_target->getClassClosureFromAlias(alias);
        return targetClosure;
    }


    const ScriptObject* Cloner::cloneScriptObject(const ScriptObject* obj)
    {
        if (obj == NULL)
            return NULL;
        AvmCore* targetCore = m_target->core();
        AvmAssert(targetCore == AvmCore::getActiveCore());
        MMgc::GC* gc = targetCore->gc;
        // we may be doing a lot of recursion

        targetCore->stackCheck(m_target); // FIXME detect and return, instead of throwing

        if (targetCore->interruptCheck(true)) {
            interrupted = true;
            return NULL;
        }

        if (AvmCore::istype(obj->toAtom(), m_target->core()->traits.function_itraits)) // FIXME memoize
            return NULL;

        const AvmPlusScriptableObject* replacement;
        bool ok = m_map.LookupItem(obj, &replacement);
        if (ok) {
            return static_cast<const ScriptObject*>(replacement);
        }

        GCRef<ClassClosure> targetClosure = targetClosureFor(obj->toplevel(), obj->traits());
        GCRef<TraitsMorpher> morpher =  targetClosure->ivtable()->traits->morpher;

        GCRef<ScriptObject> newObj = obj->cloneNonSlots(targetClosure, *this);
        GCRef<Traits> traits = obj->traits();
        GCRef<Traits> newTraits = newObj->traits();

        
        if (newTraits->needsHashtable()) {
            newObj->getTable()->expandForIterIndex();
        }

        if (morpher == NULL)
            return newObj;

        // compiler

        bool hasCode = morpher->compile(traits, newTraits, obj->toplevel(), newObj->toplevel());
        if (!hasCode)
            return newObj;

        morpher->morph(*this, gc, obj, newObj);

        if (interrupted)
            return NULL;
        else
            return newObj;
    }

    Atom Cloner::cloneDoubleAtom(Atom a)
    {
        return m_target->core()->allocDouble(AvmCore::atomToDouble(a));
    }

    String* Cloner::cloneString(String* str)
    {
        if (str == NULL)
            return NULL;
        const AvmPlusScriptableObject* replacement;
        bool ok = m_map.LookupItem(str, &replacement);
        if (ok)
            return (String*)replacement;
        String* newStr = str->clone(m_target->core());
        ok = m_map.InsertItem(str, newStr);
        return newStr;
    }

    Namespace* Cloner::cloneNamespace(Namespace* ns)
    {
        if (ns == NULL)
            return NULL;
        const AvmPlusScriptableObject* replacement;
        bool ok = m_map.LookupItem(ns, &replacement);
        if (ok)
            return (Namespace*)replacement;
        AvmCore* targetCore = m_target->core();
        // Interning all namespaces, which may be too much because
        // namespaces used in XML are apparently not interned.
        // Hopefully there aren't too many distinct 
        // so that should not be a footprint problem.
        Namespace* newNs = targetCore->internNamespace(targetCore->cloneNamespace(ns));
        m_map.InsertItem(ns, newNs);
        return newNs;
    }

    void Cloner::cloneMultiname(AvmCore* sourceCore, const HeapMultiname& src, HeapMultiname& dst)
    {
        AvmCore* targetCore = m_target->core();
        
        bool isShallow = (targetCore == sourceCore);
        String* localName = src.getName();
        Multiname dstCopy;
        if (localName) {
            dstCopy.setName((isShallow) ? localName : targetCore->internForeignString(localName));
        }
        int32_t count = src.namespaceCount();
        GCRef<NamespaceSet> nsset = NamespaceSet::_create(targetCore->gc, count);
        for (int32_t i = 0; i < count; i++) {
            Namespace* srcNs = src.getNamespace(i);
            nsset->_initNsAt(i, isShallow ? srcNs : targetCore->internNamespace(targetCore->cloneNamespace(srcNs)));
        }
        dstCopy.setNsset(nsset);
        dst = dstCopy;
    }
    


    Atom Cloner::cloneAtom(Atom a)
    {
        // Allegedly a simple if statement can be faster.
        switch (atomKind(a)) {
        case kIntptrType:
        case kBooleanType:
        case kSpecialBibopType:
            return a;
        case kNamespaceType: {
            Namespace* ns = AvmCore::atomToNamespace(a);
            Namespace* newNs = cloneNamespace(ns);
            return newNs == NULL ? nullNsAtom : newNs->toAtom();
        }
        case kDoubleType: {
            return cloneDoubleAtom(a);
        }
        case kStringType: {
            String* str = AvmCore::atomToString(a);
            String* newStr = cloneString(str);
            return newStr == NULL ? nullStringAtom : newStr->toAtom();
        }
        case kObjectType: {
            ScriptObject* obj = AvmCore::atomToScriptObject(a);
            const ScriptObject* newObj = cloneScriptObject(obj);
            if (interrupted)
                return unreachableAtom;
            if (newObj == NULL) {
                if (AvmCore::istype(a, m_target->core()->traits.function_itraits))
                    return undefinedAtom;
                else
                    return nullObjectAtom;
            } else
                return newObj->toAtom();
        }
        case 0:
            return 0;
        default:
            AvmAssert(false);
            return kUnusedAtomTag;
        }
    }
}
