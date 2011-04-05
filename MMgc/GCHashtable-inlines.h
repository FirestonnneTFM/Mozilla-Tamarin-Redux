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

#ifndef __GCHashtable_inlines_
#define __GCHashtable_inlines_

namespace MMgc
{
    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::GCHashtableBase(uint32_t capacity)
        : table(NULL)
        , tableSize(capacity)
        , numValues(0)
        , numDeleted(0)
#ifdef MMGC_GCHASHTABLE_PROFILER
        , probes(0)
        , accesses(0)
#endif
    {
        if (tableSize > 0)
        {
            grow(false);
        }
        else
        {
            // appear as full table so grow, numValues will go to zero on rehash
            tableSize = 4;
            numValues = 4;
            table = EMPTY;
        }
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::~GCHashtableBase()
    {
        if (table && table != EMPTY)
            ALLOCHANDLER::free(table);
        table = NULL;
        tableSize = 0;
        numValues = 0;
        numDeleted = 0;
#ifdef MMGC_GCHASHTABLE_PROFILER
        probes = 0;
        accesses = 0;
#endif
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    void GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::clear()
    {
        if (table && table != EMPTY)
            ALLOCHANDLER::free(table);
        table = EMPTY;
        tableSize = 4;
        numValues = 4;
        numDeleted = 0;
#ifdef MMGC_GCHASHTABLE_PROFILER
        // Do *not* clear probes and accesses, those are for the lifetime of the object (for better or worse)
#endif
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    uint32_t GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::find(const void* key, Entry* table, uint32_t tableSize)
    {
#ifdef MMGC_GCHASHTABLE_PROFILER
        accesses++;
#endif
        GCAssert(key != DELETED);

        uint32_t n = 0;
        // bitmask is defined in Symbian OS headers. changing to bitMask
        uint32_t const bitMask = (tableSize -1);
        uint32_t i = KEYHANDLER::hash(key) & bitMask;
        const void* k;
#ifdef MMGC_GCHASHTABLE_PROFILER
        probes++;
#endif
        while ((k = table[i].key) != NULL && !KEYHANDLER::equal(k, key))
        {
            i = (i +  (n += 1)) & bitMask;      // quadratic probe
#ifdef MMGC_GCHASHTABLE_PROFILER
            probes++;
#endif
        }
        GCAssert(i <= bitMask);
        return i;
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    void GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::put(const void* key, VAL value)
    {
#ifdef MMGC_GCHASHTABLE_PROFILER
        accesses++;
#endif
        GCAssert(table != NULL);

        // this is basically an inlined version of find() with one minor difference:
        // it notices if there are DELETED slots along the probe, and if there is one,
        // we recycle it rather than adding to the end of the probe chain. this allows us
        // to recycle deleted slots MUCH more quickly (without having to wait for a full rehash)
        // and can dramatically reduce the average probe depth if there are a lot of
        // insertions and removals.
        const uint32_t NO_DELINDEX = 0xffffffff;
        uint32_t delindex = NO_DELINDEX;
        // Quadratic probe: Hashtable size (S) is power of two
        //                  Probe function used: p(K,i) = (i*i + i)/2  [i = 0,1,2....S,....]
        //                  ith value in the probe sequence: [h(K) + p(K,i)] % S  
        uint32_t n = 0;
        uint32_t const bitMask = (tableSize - 1);
        uint32_t i = KEYHANDLER::hash(key) & bitMask;
        const void* k;
#ifdef MMGC_GCHASHTABLE_PROFILER
        probes++;
#endif
        while ((k = table[i].key) != NULL && !KEYHANDLER::equal(k, key))
        {
            // note that we can't just stop at the first DELETED value we find --
            // we might have a matching value later in the chain. We choose
            // the first such entry so that subsequent searches are as short as possible
            // (choosing any other entry would be fine, just suboptimal)
            if (k == DELETED && delindex == NO_DELINDEX) delindex = i;
            i = (i + (n += 1)) & bitMask;       // quadratic probe
#ifdef MMGC_GCHASHTABLE_PROFILER
            probes++;
#endif
        }
        GCAssert(k == NULL || KEYHANDLER::equal(k, key));
        if (k == NULL)
        {
            if (delindex != NO_DELINDEX)
            {
                // there's a deleted entry we can replace
                i = delindex;
                numDeleted--;
                // note that we don't increment numValues here!
            }
            else
            {
                // .75 load factor, note we don't take numDeleted into account
                // numValues includes numDeleted
                if (numValues * 4 >= tableSize * 3)
                {
                    grow(false);
                    // grow rehashes, so no DELETED items, thus normal find() is OK
                    GCAssert(numDeleted == 0);
                    i = find(key, table, tableSize);
                    GCAssert(!(table[i].key));
                }
                numValues++;
            }
            table[i].key = key;
        }
        table[i].value = value;
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    VAL GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::remove(const void* key, bool allowRehash)
    {
        VAL ret = 0;
        uint32_t i = find(key, table, tableSize);
        if (table[i].key == key)
        {
            table[i].key = DELETED;
            ret = table[i].value;
            table[i].value = 0;
            numDeleted++;
            // this helps a bit on pathologic memory profiler use case, needs more investigation
            // 20% deleted == rehash
            if (allowRehash && (numValues - numDeleted) * 5 < tableSize)
            {
                grow(true);
            }
        }
        return ret;
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    void GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::prune()
    {
        // this helps a bit on pathologic memory profiler use case, needs more investigation
        // 20% deleted == rehash
        // FIXME: Bugzilla
        if ((numValues - numDeleted) * 5 < tableSize)
        {
            grow(true);
        }
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    void GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::grow(bool isRemoval)
    {
        if (isRemoval)
        {
            // Bugzilla 553679: Skip table resizing in a removal situation if the heap
            // is in an abort state, we don't want to allocate during abort if we can
            // avoid it, and 'grow' is called when the collector clears its weak references.
            if (GCHeap::GetGCHeap()->GetStatus() == kMemAbort)
                return;
        }

        uint32_t newTableSize = tableSize;

        uint32_t occupiedSlots = numValues - numDeleted;
        GCAssert(numValues >= numDeleted);

        // grow or shrink as appropriate:
        // if we're greater than 50% full grow
        // if we're less than 10% shrink
        // else stay the same
        if (2 * occupiedSlots > tableSize)
            newTableSize <<= 1;
        else if (5 * occupiedSlots < tableSize && tableSize > kDefaultSize && table)
            newTableSize >>= 1;

        Entry* newTable;
        newTable = (Entry*)ALLOCHANDLER::alloc(newTableSize*sizeof(Entry), isRemoval);
        if (!newTable)
            return;

        VMPI_memset(newTable, 0, newTableSize*sizeof(Entry));

        numValues = 0;
        numDeleted = 0;

        if (table)
        {
            for (uint32_t i=0; i < tableSize; i++)
            {
                const void* oldKey;
                if ((oldKey=table[i].key) != NULL)
                {
                    // inlined & simplified version of put()
                    if (oldKey != DELETED) {
                        uint32_t j = find(oldKey, newTable, newTableSize);
                        newTable[j].key = oldKey;
                        newTable[j].value = table[i].value;
                        numValues++;
                    }
                }
            }
        }

        if (table && table != EMPTY)
        {
            ALLOCHANDLER::free(table);
        }
        table = newTable;
        tableSize = newTableSize;
        GCAssert(table != NULL);
    }

    template <typename VAL, class KEYHANDLER, class ALLOCHANDLER>
    int32_t GCHashtableBase<VAL, KEYHANDLER,ALLOCHANDLER>::nextIndex(int32_t index)
    {
        while(index < tableSize)
        {
            if (table[index].key > DELETED)
                return (index + 1);
            index++;
        }
        return 0;
    }

}

#endif

