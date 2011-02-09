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

#ifndef __GCStack__
#define __GCStack__

namespace MMgc
{
    /**
     * A GCWorkItem represents a pointer that the collector must examine, and
     * information about the pointer.
     *
     * There are two fields, 'ptr' and 'size'.  Both are split into a n-2 bit
     * payload part (actual pointer value, actual size value) and a 2-bit
     * information part.
     *
     * The low two bits of the 'size' field encode the type of the work item:
     * whether it's a GC object or not (low bit), and whether we should scan
     * the pointed-to object for pointers into other objects.
     *
     * The high bits of the 'size' field are zero if the item is a GC item; in
     * this case the size is computed by the collector when the work item is
     * processed.
     *
     * For 'normal' work items the two low bits of the pointer field are zero.
     *
     * If the low bits of 'size' are zero and the rest of the size field carries
     * a special large value denoting a sentinel work item then the low bits of
     * the pointer carry additional information.  The additional information
     * depends on the sentinel type, and the pointer value may or may not
     * represent a pointer.  There are several sentinel values, each imposes 
     * each own interpretation of the two bits and the pointer value.
     */
    class GCWorkItem
    {
    public:
        // It's possible to 'or' kGCObject/kNonGCObject and kHasInteriorPtrs together, and
        // when MMGC_INTERIOR_PTRS is defined this happens automatically in the GCWorkItem
        // constructor.

        // We only have two bits here because GCRoot items can be a multiple of 4 bytes.

        enum GCWorkItemType
        {
            kNonGCObject=0,
            kGCObject=1,
            kHasInteriorPtrs=2,
            kStackMemory=2          // convenient shorthand for kNonGCObject|kHasInteriorPtrs
        };

        // A sentinel is a work item that doesn't actually do any mark work but
        // causes some action to be taken when encountered, see GC::HandleLargeMarkItem.
        // It is stored in lower bits of ptr, so again we only have 2 bits to play with.
        // Since we need more bits than that, we have multiple sentinel tags.
        
        enum GCSentinel1ItemType
        {
            kDeadItem=3, // Pop asserts on 0
            kGCLargeAlloc=1,
            kGCRoot=2,
        };

        // More sentinel tags (they use a different pseudo-size value).

        enum GCSentinel2ItemType
        {
            kLargeExactlyTracedTail=1,
            kInertPayload=2,
        };

        static const uint32_t kSentinel1Size = ~0U - 3; // low two bits
        static const uint32_t kSentinel2Size = ~0U - 7; //    must be zero

        // FIXME? The initialization is redundant for most locals and for the mark stack we
        // don't want to have to init all the elements in the array as it makes allocating a mark
        // stack segment expensive.  I believe we could safely get rid of the two initializing
        // clauses here.  --lars

        GCWorkItem() : ptr(NULL), _size(0) { }

        GCWorkItem(const void *p, uint32_t s, GCWorkItemType itemType);
        GCWorkItem(const void *p, GCSentinel1ItemType type);
        GCWorkItem(const void *p, GCSentinel2ItemType type);

        // Return non-zero if the item represents a GC item (a subtype of GCObject
        // or GCTraceableBase).
        uint32_t IsGCItem() const;

        // Return non-zero if the item holds an object that should be scanned
        // such that any pointers from the object into other objects should be
        // treated as pointers to the start of the latter objects.
        uint32_t HasInteriorPtrs() const;
        
        // Return true if the ptr is NULL.
        bool IsNull() const;
        
        // Return true if the item is no longer active because it has been cleared.
        bool IsClear() const;
        
        // Return true if the item is a sentinel of type 1.
        bool IsSentinel1Item() const;
        
        // Return true if the item is a sentinel of type 2.
        bool IsSentinel2Item() const;

        // Retrieve the size field.  Will compute the actual object size if the size
        // is not present in the mark item.
        uint32_t GetSize() const;
        
        // Retrieve the pointer value.
        const void* Ptr() const;

        // Compute the end of the object.
        void* GetEnd() const;

        // The item must be a sentinel of type 1.  Return its subtype.
        GCSentinel1ItemType GetSentinel1Type() const;
        
        // The item must be a sentinel of type 2.  Return its subtype.
        GCSentinel2ItemType GetSentinel2Type() const;
        
        // The item must be a sentinel of either type.  Return the pointer stored in
        // the sentinel.
        void *GetSentinelPointer() const;

        // Cancel item by clearing its pointer, setting sentinel to
        // kDeadItem, and setting size to kSentinelSize.
        void Clear();

    private:
        // If a WI is a GC item, `ptr` is the UserPointer; it must not
        // be the RealPointer nor an interior pointer.  When _size
        // is kSentinelSize the lower 2 bits of ptr contain the sentinel
        // type.
        union {
            const void *ptr;
            uintptr_t iptr;
        };

        // The low bit of _size stores whether this is a GC item.
        // Always access this through `GetSize` and `IsGCItem`
        uint32_t _size;
    };

    // Each GCWorkItem is two words.  There's a one-word overhead in the segment data
    // structure, and on a 32-bit system there's one word of alignment.  Ergo we have
    // space for (4k-8)/2w items in a block, where w(ordsize) is 4 or 8.  (FixedMalloc
    // does not add further overhead in Release builds.)
#ifdef AVMPLUS_64BIT
    enum { kMarkStackItems=255 };
#else
    enum { kMarkStackItems=511 };
#endif

    // Invariant: m_topSegment, m_base, m_top, and m_limit are never NULL following construction.
    // Invariant: m_base <= m_top <= m_limit
    // Invariant: m_base == m_topSegment->m_items
    // Invariant: m_limit == m_topSegment->m_items + kMarkStackItems

    class GCMarkStack
    {
    public:
#ifdef MMGC_MARKSTACK_ALLOWANCE
        GCMarkStack(uint32_t allowance);    // Pass 0 for allowance to request "unlimited"
#else
        GCMarkStack();
#endif
        ~GCMarkStack();

        /**
         * Push 'item' onto the stack.
         *
         * This should only ever be called from GC::PushWorkItem, because
         * that function does extra processing and may push various derived
         * items (for large objects).
         *
         * @return true if the item could be pushed, false if the system
         *         is out of memory and the item was not pushed.
         */
        bool Push(GCWorkItem item);

        /**
         * Pop one item off the stack.  Precondition: The stack must not be empty.
         * @return the popped element.
         */
        GCWorkItem Pop();

        /** @return the number of elements on the stack. */
        uint32_t Count();

        /** @return true if the stack is empty */
        bool IsEmpty();

        /** Pop all elements off the stack, discard the cached extra segment. */
        void Clear();

        /** @return the number of elements in a segment */
        uint32_t ElementsPerSegment();

        /** @return the number of entirely full segments */
        uint32_t EntirelyFullSegments();

        /**
         * Move one entirely full segment from 'other' and insert it into our segment list.
         * @return true if the transfer was successful, false if an out-of-memory condition
         *         prevented reestablishing invariants in 'other' following the transfer.
         *         (In the latter case the stacks remain unchanged.)
         */
        bool TransferOneFullSegmentFrom(GCMarkStack& other);

#ifdef MMGC_MARKSTACK_DEPTH
        /** @return the number of elements on the stack when its depth was the greatest */
        uint32_t MaxCount();
#endif

        /**
         * Get a pointer to the top of the stack.
         * @return top of stack
         */
        GCWorkItem *Peek();

        /** Retrieve the item above an existing stack item. If the
         * item passed is the top of the stack NULL is returned.  The
         * item must be in the stack.
         * @return item above argument
         */
        GCWorkItem *GetItemAbove(GCWorkItem *item);

    protected:
        // no implementation of these
        GCMarkStack(const GCMarkStack& other);
        GCMarkStack& operator=(const GCMarkStack& other);

    private:

        struct GCStackSegment
        {
            GCWorkItem      m_items[kMarkStackItems];
            GCStackSegment* m_prev;
        };

        GCWorkItem*         m_base;         // first entry in m_topSegment
        GCWorkItem*         m_top;          // first free entry in m_topSegment
        GCWorkItem*         m_limit;        // first entry following m_topSegment
        GCStackSegment*     m_topSegment;   // current stack segment, older segments linked through 'prev'
        uint32_t            m_hiddenCount;  // number of elements in those older segments
        GCStackSegment*     m_extraSegment; // single-element cache used to avoid hysteresis
#ifdef MMGC_MARKSTACK_ALLOWANCE
        uint32_t            m_allowance;    // allowance for the number of elements
#endif
#ifdef MMGC_MARKSTACK_DEPTH
        uint32_t            m_maxDepth;     // max depth of mark stack
#endif

        /**
         * The current segment must be NULL or full (top == limit).  Push a new segment onto the
         * stack, and update all instance vars.
         * @param mustSucceed  If true, the allocation must not fail.  This is true during initialization.
         *                     Failure in this case is signaled through the normal OOM mechanism.
         * @return true if the segment could be pushed or false if not (if it could not be allocated).
         */
        bool PushSegment(bool mustSucceed=false);

        // The current segment is discarded and the previous segment, if any, reinstated.
        // Update all instance vars.
        void PopSegment();

        // Allocate a segment, return NULL if it could not be allocated.  If mustSucceed is true
        // then abort the program if the allocation fails.
        void* AllocStackSegment(bool mustSucceed);

        // Free a segment allocated through AllocStackSegment.
        void FreeStackSegment(void* p);

#ifdef _DEBUG
        // Check as many invariants as possible
        bool Invariants();
#endif
    };
}

#endif /* __GCStack__ */
