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

#ifndef __avmplus_MultinameHashtable_impl__
#define __avmplus_MultinameHashtable_impl__

using namespace MMgc;

namespace avmplus
{
    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::gcTrace(MMgc::GC *gc)
    {
        gc->TraceLocation(&m_quads);
    }
    
    template <class VALUE_TYPE, class VALUE_WRITER>
    bool MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::gcTraceLarge(MMgc::GC *gc, size_t cursor)
    {
        return gcTraceLargeAsSmall(gc, cursor);
    }
    
    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::grow()
    {
        // double our table
        int capacity = numQuads*2;
        MMgc::GC* gc = MMgc::GC::GetGC(this);
        MMGC_MEM_TYPE(this);
        QuadContainer<VALUE_TYPE>* newAtoms = QuadContainer<VALUE_TYPE>::create(gc, capacity);
        rehash(m_quads->quads, numQuads, newAtoms->quads, capacity);
        freeQuads(gc);
        WB(gc, this, &m_quads, newAtoms);
        numQuads = capacity;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::getMulti(const Multiname* mname) const
    {
        // multiname must not be an attr name, have wildcards, or have runtime parts.
        AvmAssert(mname->isBinding() && !mname->isAnyName());

        if (!mname->isNsset())
            return get(mname->getName(), mname->getNamespace());
        else
            return get(mname->getName(), mname->getNsset());
    }

    // return the NS that unambigously matches in "match" (or null for none/ambiguous)
    template <class VALUE_TYPE, class VALUE_WRITER>
    VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::getMulti(const Multiname& mname, Namespacep& match) const
    {
        // multiname must not be an attr name, have wildcards, or have runtime parts.
        AvmAssert(mname.isBinding() && !mname.isAnyName());

        if (!mname.isNsset())
        {
            VALUE_TYPE b = get(mname.getName(), mname.getNamespace());
            match = (b != NULL) ? mname.getNamespace() : NULL;
            return b;
        }
        else
        {
            const Quad<VALUE_TYPE>* q = getNSSet(mname.getName(), mname.getNsset());
            match = q->ns;
            return q->value;
        }
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::MultinameHashtable(int capacity) :
        m_quads(NULL),
        size(0),
        numQuads(0)
    {
        // We really want alignment and size of the Quad to be tightly controlled.
        MMGC_STATIC_ASSERT(sizeof(Quad<VALUE_TYPE>) == 4*sizeof(uintptr_t));

        // Code near the end of MultinameHashtable::put assumes that API is a 32-bit type
        MMGC_STATIC_ASSERT(sizeof(API) == 4);

        Init(capacity);
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::Init(int capacity)
    {
        if (capacity)
        {
            numQuads = MathUtils::nextPowerOfTwo(capacity);

            MMgc::GC* gc = MMgc::GC::GetGC(this);

            AvmAssert(numQuads > 0);
            MMGC_MEM_TYPE(this);
            QuadContainer<VALUE_TYPE>* newAtoms = QuadContainer<VALUE_TYPE>::create(gc, numQuads);
            WB(gc, this, &m_quads, newAtoms);
        }
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::~MultinameHashtable()
    {
        freeQuads(GC::GetGC(this));
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::freeQuads(MMgc::GC* gc)
    {
        QuadContainer<VALUE_TYPE>* quads = m_quads;
        m_quads = NULL;     // Avoid dangling m_quad
        gc->Free(quads);
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    bool MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::isFull() const
    {
        // 0.80 load factor
        return 5*(size+1) >= numQuads*4;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    int MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::find(Stringp name, Namespacep ns, const Quad<VALUE_TYPE>* t, unsigned m)
    {
        AvmAssert(ns->getURI()->isInterned());
        AvmAssert(name != NULL && ns != NULL);
        AvmAssert(name->isInterned());

        // this is a quadratic probe but we only hit every third slot since those hold keys.
        int n = 7;

        int bitmask = (m - 1);

        // Note: Mask off MSB to avoid negative indices.  Mask off bottom
        // 3 bits because it doesn't contribute to hash.  Quad it
        // because names, namespaces, and values are stored adjacently.
        unsigned i = ((0x7FFFFFF8 & (uintptr_t)name) >> 3) & bitmask;

        Stringp k;
        while (((k=t[i].name) != name || !(t[i].ns == ns || matchNS(t[i].ns->m_uri, t[i].apis(), ns))) && k != NULL)
        {
            i = (i + (n++)) & bitmask;          // quadratic probe
        }
        return i;
    }

    template <class VALUE_TYPE>
    REALLY_INLINE QuadContainer<VALUE_TYPE>* QuadContainer<VALUE_TYPE>::create(MMgc::GC* gc, uint32_t capacity)
    {
        return MMgc::setExact(new (gc, sizeof(Quad<VALUE_TYPE>) * (capacity-1)) QuadContainer(capacity));
    }
    
    template <class VALUE_TYPE>
    void QuadContainer<VALUE_TYPE>::gcTrace(MMgc::GC* gc)
    {
        for ( uint32_t i=0 ; i < capacity ; i++ ) {
            Quad<VALUE_TYPE>& q = quads[i];
            gc->TraceLocation(&q.name);
            gc->TraceLocation(&q.ns);
            gc->TraceConservativeLocation((uintptr_t*)&q.value);
        }
    }

    template <class VALUE_TYPE>
    bool QuadContainer<VALUE_TYPE>::gcTraceLarge(MMgc::GC* gc, size_t cursor)
    {
        return gcTraceLargeAsSmall(gc, cursor);
    }
    
    /**
     * since identifiers are always interned strings, they can't be 0,
     * so we can use 0 as the empty value.
     */
    static const Stringp EMPTY = NULL;

    template <class VALUE_TYPE, class VALUE_WRITER>
    const Quad<VALUE_TYPE>* MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::getNSSet(Stringp mnameName, NamespaceSetp nsset) const
    {
        static const Quad<VALUE_TYPE> kBindNone = { NULL, NULL, NULL, 0 };
        static const Quad<VALUE_TYPE> kBindAmbiguous = { NULL, NULL, (VALUE_TYPE)-1, 0 };

        int nsCount = nsset->count();
        int j;

        const Quad<VALUE_TYPE>* match = &kBindNone;
        VALUE_TYPE matchValue = match->value;

        // this is a quadratic probe but we only hit every third slot since those hold keys.
        int n = 7;
        int bitMask = numQuads - 1;

        // Note: Mask off MSB to avoid negative indices.  Mask off bottom
        // 3 bits because it doesn't contribute to hash.  Quad it
        // because names, namespaces, and values are stored adjacently.
        unsigned i = ((0x7FFFFFF8 & (uintptr_t)mnameName)>>3) & bitMask;
        Stringp atomName;

        const Quad<VALUE_TYPE>* t = m_quads->quads;
        while ((atomName = t[i].name) != EMPTY)
        {
            if (atomName == mnameName)
            {
                Namespacep probeNS = t[i].ns;
                AvmAssert(probeNS->getURI()->isInterned());
                API probeAPIs = t[i].apis();
                uintptr_t probeURI = probeNS ? probeNS->m_uri : 0;
                for (j=0; j < nsCount; j++)
                {
                    Namespacep ns = nsset->nsAt(j);
                    AvmAssert(ns->getURI()->isInterned());
                    if (probeNS==ns || (probeURI == ns->m_uri && (probeAPIs & ns->m_api)))
                    {
                        match = &t[i];
                        matchValue = match->value;
                        goto found1;
                    }
                }
            }

            i = (i + (n++)) & bitMask;          // quadratic probe
        }

        return &kBindNone;

found1:
        if (t[i].multiNS())
        {
            int k = (i + (n++)) & bitMask;          // quadratic probe
            while ((atomName = t[k].name) != EMPTY)
            {
                if (atomName == mnameName)
                {
                    Namespacep probeNS = t[k].ns;
                    AvmAssert(probeNS->getURI()->isInterned());
                    API probeAPIs = t[k].apis();
                    uintptr_t probeURI = t[k].ns->m_uri;
                    for (j=0; j < nsCount; j++)
                    {
                        Namespacep ns = nsset->nsAt(j);
                        if ((probeNS==ns || matchNS(probeURI, probeAPIs, ns)) && matchValue != t[k].value)
                        {
                            return &kBindAmbiguous;

                        }
                    }
                }
                k = (k + (n++)) & bitMask;          // quadratic probe
            }
        }
        return match;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::get(Stringp name, Namespacep ns) const
    {
        AvmAssert(ns->getURI()->isInterned());
        const Quad<VALUE_TYPE>* t = m_quads->quads;
        int i = find(name, ns, t, numQuads);
        if (t[i].name == name)
        {
            const Quad<VALUE_TYPE>& tf = t[i];
            AvmAssert(tf.ns==ns || matchNS(tf.ns->m_uri, tf.apis(), ns));
            return tf.value;
        }
        return (VALUE_TYPE)NULL;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::getName(Stringp name) const
    {
        const Quad<VALUE_TYPE>* t = m_quads->quads;
        for (int i=0, n=numQuads; i < n; i++)
        {
            if (t[i].name == name)
            {
                const Quad<VALUE_TYPE>& tf = t[i];

                return tf.value;
            }
        }
        return (VALUE_TYPE)NULL;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::rehash(const Quad<VALUE_TYPE>* oldAtoms, int oldTriplet, Quad<VALUE_TYPE>* newAtoms, int newTriplet)
    {
        for (int i=0, n=oldTriplet; i < n; i++)
        {
            Stringp oldName;
            if ((oldName=oldAtoms[i].name) != EMPTY)
            {
                // inlined & simplified version of put()
                int j = find(oldName, oldAtoms[i].ns, newAtoms, newTriplet);
                // don't need WBRC/WB here because we are just moving pointers
                newAtoms[j].name = oldName;
                newAtoms[j].ns = oldAtoms[i].ns;
                newAtoms[j].value = oldAtoms[i].value;
                newAtoms[j].apisAndMultiNS = oldAtoms[i].apisAndMultiNS;
            }
        }
    }

    // call this method using the previous value returned
    // by this method starting with 0, until 0 is returned.
    template <class VALUE_TYPE, class VALUE_WRITER>
    int FASTCALL MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::next(int index) const
    {
        // Advance to first non-empty slot.
        const Quad<VALUE_TYPE>* t = m_quads->quads;
        while (index < numQuads) {
            if (t[index++].name != NULL) {
                return index;
            }
        }
        return 0;
    }

    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::add(Stringp name, Namespacep ns, VALUE_TYPE value)
    {
        if (isFull())
        {
            grow();
        }
        put(name, ns, value);
    }
    
    template <class VALUE_TYPE, class VALUE_WRITER>
    void MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::put(Stringp name, Namespacep ns, VALUE_TYPE value)
    {
        AvmAssert(!isFull());
        AvmAssert(name->isInterned());
        AvmAssert(ns->getURI()->isInterned());
        
        MMgc::GC* gc = MMgc::GC::GetGC(m_quads);
        
        uint32_t multiNS = 0;
        
        // inlined version of find(), so that we can sniff for the multiNS
        // case (and update as necessary) in a single pass (rather than the
        // two extra passes we used to do)... this relies on the fact that
        // the quadratic probe will walk thru every existing entry with the same
        // same name in order to find an empty slot, thus if there are any existing
        // entries with a different ns than what we are adding, all of those name
        // entries should be marked as multiNS.
        Quad<VALUE_TYPE>* cur;
        Quad<VALUE_TYPE>* const quadbase = m_quads->quads;
        {
            int n = 7;
            int const bitmask = (numQuads - 1);
            unsigned i = ((0x7FFFFFF8 & (uintptr_t)name) >> 3) & bitmask;
            cur = quadbase + i;
            for (;;)
            {
                Stringp probeName = cur->name;
                if (!probeName)
                {
                    // found the hole.
                    break;
                }
                
                if (probeName == name)
                {
                    // there's at least one existing entry with this name in the MNHT.
                    if (cur->ns == ns || matchNS(cur->ns->m_uri, cur->apis(), ns))
                    {
                        // it's the one we're looking for, just update the value.
                        goto write_value;
                    }
                    
                    // it's not the one we're looking for, thus we are now multiNS on this name.
                    if (cur->ns->m_uri != ns->m_uri) {
                        cur->apisAndMultiNS |= 1;
                        multiNS = 1;
                    }
                }
                
                i = (i + (n++)) & bitmask;          // quadratic probe
                cur = quadbase + i;
            }
        }
        
        AvmAssert(cur->name == NULL);
        
        // New table entry for this <name,ns> pair
        size++;
        //quads[i].name = name;
        WBRC(gc, m_quads, &cur->name, name);
        //quads[i].ns = ns;
        WBRC(gc, m_quads, &cur->ns, ns);
        cur->apisAndMultiNS = (cur->apisAndMultiNS & ~1) | multiNS;
        
    write_value:
        //quads[i].value = value;
        //WB(gc, quadbase, &cur->value, value);
        VALUE_WRITER::store(gc, m_quads, (void**)&cur->value, (void*)value);
        AvmAssert((ns->getAPI() & 0x80000000U) == 0);
        cur->apisAndMultiNS |= (uintptr_t)ns->getAPI() << 1;
    }
}

#endif /*__avmplus_MultinameHashtable_impl__ */
