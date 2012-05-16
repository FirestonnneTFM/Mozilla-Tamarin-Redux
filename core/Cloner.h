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

#ifndef __avmplus_Cloner__
#define __avmplus_Cloner__


namespace avmplus {

    class GC_CPP_EXACT(TraitsMorpher, MMgc::GCTraceableObject)
    {
    protected:
        TraitsMorpher(Traits* targetTraits)
            : m_targetTraits(targetTraits)
            , m_retainedTBs(targetTraits->getTraitsBindings())
            , m_retainedTraitsMetadata(targetTraits->getTraitsMetadata())
            , m_mostRecentSourceTraits(NULL)
            , m_mostRecentCodeLength(0) 
            {
                WB_NULL(&m_mostRecentCode);
            }
    public:
        REALLY_INLINE static TraitsMorpher* create(MMgc::GC* gc, GCRef<Traits> targetTraits)
        {
            AvmAssert(gc == targetTraits->core->gc);
            return new (gc, MMgc::kExact) TraitsMorpher(targetTraits);
        }

        bool compile(Traits* traits, Traits* newTraits, Toplevel* toplevel, Toplevel* newToplevel);
        void morph(Cloner& cloner, MMgc::GC* gc, const ScriptObject* obj, ScriptObject* newObj);
        bool containsTransientMetadata(PoolObject* pool, const uint8_t* meta_pos);
        bool slotContainsTransientMetadata(Traits *traits, int index);
        bool isSerializable(Traits * t, Namespace* ns, Binding b, AvmCore* currentCore);

    private:
        GC_DATA_BEGIN(TraitsMorpher)
        GCMember<Traits> m_targetTraits;
        GCMember<const TraitsBindings> m_retainedTBs; // Only here to prevent reconstruction via the QCache mechansim.
        GCMember<const TraitsMetadata> m_retainedTraitsMetadata; // Only here to prevent reconstruction via the QCache mechansim.
        void* m_mostRecentSourceTraits; // Opaque, not GC'd.
        intptr_t* GC_POINTER(m_mostRecentCode);
        int m_mostRecentCodeLength;
        GC_DATA_END(TraitsMorpher)
    };

    class Cloner { // stack allocaed
    public:
        Cloner(Toplevel* target);
        Toplevel* target();
        void cloneDynamicProperties(const ScriptObject* fromObject, ScriptObject* toObject, bool onlyValueKeys = false);
        void registerClone(const ScriptObject* original, ScriptObject* clone);
        bool interrupted;
        Atom cloneAtom(Atom a);
        const ScriptObject* cloneScriptObject(const ScriptObject* obj);
        Atom cloneDoubleAtom(Atom prop);
        String* cloneString(String* str);
        Namespace* cloneNamespace(Namespace* ns);
        void cloneMultiname(AvmCore* sourceCore, const HeapMultiname& src, HeapMultiname& dst);
        static bool canCoerce(Toplevel* fromTl, Traits* fromTraits, Toplevel* toTl, Traits* toTraits);
        static Traits* typeAt(Traits* traits, int slotId);
        Atom restoreGetterResult(ScriptObject* obj, int dispid); 
        void saveGetterResult(ScriptObject* obj, int dispid, Atom value);
        void destroy();
        
      private:
        ClassClosure* targetClosureFor(Toplevel* sourceToplevel, Traits* sourceTraits);
        void* operator new(size_t); // Declared but undefined, on the stack.
        Toplevel* m_target;
        FixedHeapHashTable<const AvmPlusScriptableObject*, const AvmPlusScriptableObject*> m_map;

    };
    

}
#endif


