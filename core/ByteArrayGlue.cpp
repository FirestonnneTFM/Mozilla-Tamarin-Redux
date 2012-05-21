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


#include "avmplus.h"
#include "zlib.h"

// Compiler and architecture dependent byte swapping functions.
//
// Define HAVE_BYTESWAP32 and/or HAVE_BYTESWAP16 on platforms where there are
// instructions or fast idioms for byte swapping backed by compiler intrinsics.
//
// This is not quite a porting API, because we do not abstract byteSwap16()
// and byteSwap32() generally: if fast byte swapping is not available then 
// it's probably faster to use generic in-line byte load/store code.  Hence 
// the code is all here and not in a platform file.
//
// Survey of architectures:
//
//   On x86 there is BSWAP (32-bit) and XCHG (16-bit).
//   On PPC there is supposedly a three-operation sequence that byte swaps 32-bit
//     data [Warren, Hacker's Delight].
//   On MIPS a two-operation sequence of WSBH and ROTR can byte swap a 32-bit word,
//     WSBH can byte swap a halfword by itself.
//   On SH4 a combination of SWAP.B (twice) and SWAP.H should byte swap a 32-bit word,
//     while SWAP.B by itself should byte swap a 16-bit halfword.
//   On ARM there are the REV (32-bit) and REV16 (16-bit) instructions since ARMv6.
//   To my knowledge SPARC has no byte swap instructions.
//
// Survey of compilers:
//
//   MSVC starting with Visual Studio 2005 have _byteswap_ulong, _byteswap_ushort, _byteswap_uint64.
//   GCC starting with 4.3 have __builtin_bswap32 and __builtin_bswap64, must include <byteswap.h>

#if defined VMCFG_IA32 || defined VMCFG_AMD64 || defined VMCFG_PPC || defined VMCFG_MIPS || defined VMCFG_SH4 || defined VMCFG_ARM

#if defined _MSC_VER
#define HAVE_BYTESWAP32
#define HAVE_BYTESWAP16
REALLY_INLINE uint32_t byteSwap32(uint32_t x)
{
    return _byteswap_ulong(x);
}

REALLY_INLINE uint16_t byteSwap16(uint16_t x)
{
    return _byteswap_ushort(x);
}
#endif // _MSC_VER

#if defined __GNUC__ && (__GNUC__ == 4 && __GNUC_MINOR__ >= 3 || __GNUC__ > 4)
#include <byteswap.h>
#define HAVE_BYTESWAP32

REALLY_INLINE uint32_t byteSwap32(uint32_t x)
{
    return __builtin_bswap32(x);
}
#endif // __GNUC__

#endif // Various architectures with byteswap idioms backed by intrinsics

// MAX_BYTEARRAY_STORE_LENGTH is the largest value that can be taken on by m_length,
// strictly less than 2^32.  See constraint in ByteArray::Grower::ReallocBackingStore().
//
// MAX_BYTEARRAY_SHORT_ACCESS_LENGTH is a value no smaller than 4095 and no greater
// than 2^32-1-MAX_BYTEARRAY_STORE_LENGTH.
//
// The purpose of these two limits is to allow relatively efficient bounds checking
// on common ByteArray accesses, see comments on ByteArray::requestBytesForShortRead()
// and ByteArray::requestBytesForShortWrite() for more information.

#define MAX_BYTEARRAY_STORE_LENGTH (MMgc::GCHeap::kMaxObjectSize - MMgc::GCHeap::kBlockSize*2)
#define MAX_BYTEARRAY_SHORT_ACCESS_LENGTH (MMgc::GCHeap::kBlockSize*2 - 1)

namespace avmplus
{
    template <typename T> REALLY_INLINE T min(T a, T b) {
        return (a < b) ? a : b;
    }

    // Rounds a up to nearest integral multiple of b.
    // requires: T is integral type.
    // returns r, where r is least integral multiple of b such that r >= a.
    //
    // Bugzilla 699176: lift to shared header or specialize to uint64_t.
    template <typename T> REALLY_INLINE T roundUpTo(T a, T b) {
        return ((a + (b - 1)) / b) * b;
    }

    //
    // ByteArray
    //
    
    ByteArray::ByteArray(Toplevel* toplevel)
        : DataIOBase()
        , DataInput()
        , DataOutput()
        , m_toplevel(toplevel)
        , m_gc(toplevel->core()->GetGC())
        , m_subscribers(m_gc, 0)
        , m_copyOnWriteOwner(NULL)
        , m_position(0)
        , m_buffer(mmfx_new(Buffer))
        , m_workerLocal(true)
        , m_isLinkWrapper(false)
    {
        static_assert(uint64_t(MAX_BYTEARRAY_STORE_LENGTH) < 0x100000000ULL, "Constraint on MAX_BYTEARRAY_STORE_LENGTH");
        static_assert(MAX_BYTEARRAY_SHORT_ACCESS_LENGTH >= 4095, "Constraint on MAX_BYTEARRAY_SHORT_ACCESS_LENGTH");
        static_assert(uint64_t(MAX_BYTEARRAY_STORE_LENGTH) + uint64_t(MAX_BYTEARRAY_SHORT_ACCESS_LENGTH) < 0x100000000ULL, "Constraints on internal ByteArray constants");
        AvmAssert(m_gc != NULL);

        m_buffer->array = NULL;
        m_buffer->capacity = 0;
        m_buffer->length = 0;
    }


    ByteArray::ByteArray(Toplevel* toplevel, const ByteArray& other)
        : DataIOBase()
        , DataInput()
        , DataOutput()
        , m_toplevel(toplevel)
        , m_gc(toplevel->core()->GetGC())
        , m_subscribers(m_gc, 0)
        , m_copyOnWriteOwner(NULL)
        , m_position(0)
        , m_buffer(other.m_workerLocal ? mmfx_new(Buffer) : other.m_buffer)
        , m_workerLocal(other.m_workerLocal)
        , m_isLinkWrapper(false)
    {
        AvmAssert(m_gc != NULL);
        if (!m_workerLocal) {
            return;
        }
        m_buffer->capacity = other.m_buffer->capacity;
        m_buffer->length = other.m_buffer->length;
        m_buffer->array = mmfx_new_array_opt(uint8_t, m_buffer->capacity, MMgc::kCanFailAndZero);

        if (!m_buffer->array)
           ThrowMemoryError();
        
        TellGcNewBufferMemory(m_buffer->array, m_buffer->capacity);
        if (other.m_buffer->array)
            VMPI_memcpy(m_buffer->array, other.m_buffer->array, m_buffer->length);
    }


    ByteArray::ByteArray(Toplevel* toplevel, ByteArray::Buffer* source, bool workerLocal)
        : DataIOBase()
        , DataInput()
        , DataOutput()
        , m_toplevel(toplevel)
        , m_gc(toplevel->core()->GetGC())
        , m_subscribers(m_gc, 0)
        , m_copyOnWriteOwner(NULL)
        , m_position(0)
        , m_buffer(source)
        , m_workerLocal(workerLocal) 
        , m_isLinkWrapper(false)
    {
    }


    /* virtual */ void ByteArray::Buffer::destroy() 
    {
        if (array)
        {
            AvmAssert(capacity > 0);
            // FIXME: the lack of the following appears to be accidentally correct, because
            // for normal uses array will be NULL in this->destroy()
            // and the Isolate use doesn't signal dependent allocation
            //m_gc->SignalDependentDeallocation(capacity, MMgc::typeByteArray);
            mmfx_delete_array(array);
        }
        mmfx_delete(this);
    }

    /* virtual */ ByteArray::Buffer::~Buffer() 
    {
    }

    ByteArray::~ByteArray()
    {
        // no: this can reallocate memory, which is bad to do in a dtor
        // m_subscribers.clear();
        _Clear();
        m_buffer = NULL;
    }

    void ByteArray::Clear()
    {
        if (m_subscribers.length() > 0)
        {
            AvmAssert(false); // shouldn't get here?
            m_toplevel->throwRangeError(kInvalidRangeError);
        }
        _Clear();
    }
    
    void ByteArray::_Clear()
    {
        if (m_buffer->array && !IsCopyOnWrite())
        {
            AvmAssert(m_buffer->capacity > 0);
            // Note that TellGcXXX always expects capacity, not (logical) length.
            TellGcDeleteBufferMemory(m_buffer->array, m_buffer->capacity);
            mmfx_delete_array(m_buffer->array);
        }
        m_buffer->array             = NULL;
        m_buffer->capacity          = 0;
        m_buffer->length            = 0;
        m_copyOnWriteOwner  = NULL;
    }

    void ByteArray::SetCopyOnWriteOwner(MMgc::GCObject* owner)
    {
        if (owner != NULL && m_gc->IsPointerToGCPage(this))
        {
            WB(m_gc, m_gc->FindBeginningFast(this), &m_copyOnWriteOwner, owner);
        }
        else
        {
            m_copyOnWriteOwner = owner;
        }
    }

    void ByteArray::SetCopyOnWriteData(MMgc::GCObject* owner, const uint8_t* data, uint32_t length)
    {
        Clear();
        m_buffer->array             = const_cast<uint8_t*>(data);
        m_buffer->capacity          = length;
        m_buffer->length            = length;
        // we must have a non-null value for m_copyOnWriteOwner, as we
        // use it as an implicit boolean as well, so if none is provided,
        // cheat and use m_gc->emptyWeakRef
        if (owner == NULL)
            owner = (MMgc::GCObject*)m_gc->emptyWeakRef;
        SetCopyOnWriteOwner(owner);
    }
        
    void FASTCALL ByteArray::Grower::EnsureWritableCapacity()
    {
        if (m_minimumCapacity > (MMgc::GCHeap::kMaxObjectSize - MMgc::GCHeap::kBlockSize*2))
            m_owner->ThrowMemoryError();

        if (m_minimumCapacity > m_owner->m_buffer->capacity || m_owner->IsCopyOnWrite())
        {
            uint32_t newCapacity = m_owner->m_buffer->capacity << 1;
            if (newCapacity < m_minimumCapacity)
                newCapacity = m_minimumCapacity;
            if (newCapacity < kGrowthIncr)
                newCapacity = kGrowthIncr;

            m_minimumCapacity = newCapacity;
            ReallocBackingStore();
        }
    }

    void FASTCALL ByteArray::Grower::ReallocBackingStore()
    {
        // The extra check on maximum size is necessary because
        // mmfx_new_array_opt doesn't return NULL but instead Aborts
        // when the size approaches 2^32. We want to be consistent
        // across the entire uint32_t range and throw a memory error
        // instead.  The subtraction of two blocks has to do with how
        // FixedMalloc::LargeAlloc does this check.
        //
        // The length limitation is however useful for other purposes.
        // Observe that the length limit is duplicated above in the 
        // definition of MAX_BYTEARRAY_STORE_LENGTH and that there is 
        // code below in ByteArray::requestBytesForShortRead() and
        // ByteArray::requestBytesForShortWrite() that depends on the
        // limit on m_length, see comments there and also comments on
        // MAX_BYTEARRAY_STORE_LENGTH.

        static_assert(MAX_BYTEARRAY_STORE_LENGTH == (MMgc::GCHeap::kMaxObjectSize - MMgc::GCHeap::kBlockSize*2),
                      "Constraint on maximum ByteArray storage size");

        if (m_minimumCapacity > (MMgc::GCHeap::kMaxObjectSize - MMgc::GCHeap::kBlockSize*2))
            m_owner->ThrowMemoryError();

        if (m_minimumCapacity > m_owner->m_buffer->capacity || m_owner->IsCopyOnWrite())
        {
            growTask();
        }
    }

    void ByteArray::Grower::growTask() {
        if (!m_owner->m_workerLocal) {
            vmbase::SafepointManager* tm = m_owner->m_toplevel->core()->getIsolate()->getAggregate()->safepointManager();
            tm->requestSafepointTask(*this);
        } else {
            run();
        }
    }

    void ByteArray::Grower::run() {
        uint32_t newCapacity = m_owner->m_buffer->capacity << 1;
        if (newCapacity < m_minimumCapacity)
            newCapacity = m_minimumCapacity;
        if (newCapacity < kGrowthIncr)
            newCapacity = kGrowthIncr;
        
        m_oldArray = m_owner->m_buffer->array;
        m_oldLength = m_owner->m_buffer->length;
        m_oldCapacity = m_owner->m_buffer->capacity;

        uint8_t* newArray = mmfx_new_array_opt(uint8_t, newCapacity, MMgc::kCanFail);
        if (!newArray)
            m_owner->ThrowMemoryError();

        // Note that TellGcXXX always expects capacity, not (logical) length.
        m_owner->TellGcNewBufferMemory(newArray, newCapacity);
        if (m_oldArray)
        {
            VMPI_memcpy(newArray, m_oldArray, min(newCapacity, m_oldLength));
            if (newCapacity > m_oldLength)
                VMPI_memset(newArray+m_oldLength, 0, newCapacity-m_oldLength);
        }
        else
        {
            VMPI_memset(newArray, 0, newCapacity);
        }

        m_owner->m_buffer->array = newArray;
        m_owner->m_buffer->capacity = newCapacity;
        if (m_owner->m_copyOnWriteOwner != NULL)
        {
            m_owner->m_copyOnWriteOwner = NULL;
            // Set this to NULL so we don't attempt to delete it in our dtor.
            m_oldArray = NULL;
        }
    }

    /*
        Why the "Grower" class?
        
        (1) It provides a clean way to defer discarding the old buffer until the
            end of the calling function; this matters in the case of Write(),
            as it's legal to call Write() on your own buffer, and so if growth
            occurs, you must not discard the old buffer until copying takes place.
        (2) It avoid redundant calls to NotifySubscribers(); previously we'd call
            once when a reallocation occurred, then again when the length field
            changed.
        (3) It streamlines copy-on-write handling; formerly we either did
            redundant CopyOnWrite alloc-and-copy followed by a Grow alloc-and-copy,
            or an if-else clause with redundant alloc-and-copy.
            
        Of course, the dtor will be skipped (and thus notify and deletes skipped)
        if a longjmp over it, but the old code was subject to the same defects,
        so this is not a new liability.
    */
    ByteArray::Grower::~Grower()
    {
        if (m_oldArray != m_owner->m_buffer->array || m_oldLength != m_owner->m_buffer->length)
        {
            m_owner->NotifySubscribers();
        }
        // m_oldArray could be NULL if we grew a copy-on-write ByteArray.
        if (m_oldArray != NULL && m_oldArray != m_owner->m_buffer->array)
        {
            // Note that TellGcXXX always expects capacity, not (logical) length.
            m_owner->TellGcDeleteBufferMemory(m_oldArray, m_oldCapacity);
            mmfx_delete_array(m_oldArray);
        }
    }

    uint8_t* FASTCALL ByteArray::GetWritableBuffer()
    {
        Grower grower(this, m_buffer->capacity);
        grower.EnsureWritableCapacity();
        return m_buffer->array;
    }

    uint8_t& ByteArray::operator[](uint32_t index)
    {
        if (index >= m_buffer->length)
            SetLength(index + 1);
        return m_buffer->array[index];
    }

    // Set the length to x+y, but check for overflow.
    //
    // MemoryError is the error thrown by SetLength(index), or really by
    // ByteArray::Grower::ReallocBackingStore(), if we try to create a
    // buffer larger than the buffer limit, so it's the most consistent 
    // error to throw here.
    //
    // We don't know anything about x and y so 64-bit math is the most
    // expedient solution.  SetLength() is not hot in any case, it's always
    // guarded by some other check.

    void FASTCALL ByteArray::SetLength(uint32_t x, uint32_t y)
    {
        uint64_t sum = uint64_t(x) + uint64_t(y);
        if (sum >= 0x100000000ULL)
            ThrowMemoryError();
        SetLength(uint32_t(sum));
    }

    // Bugzilla 699176: This threshold controls whether we switch to
    // large-size handling.  The chosen increment (24 MB) was
    // suggested by Scott Petersen based on experiments with policy in
    // Alchemy; the chosen threshold (also 24 MB) was assumed to be an
    // appropriate value, but it would be worthwhile to check that
    // assumption when time permits.

    static const uint32_t kHugeGrowthThreshold = 24*1024*1024;
    static const uint32_t kHugeGrowthIncr = 24*1024*1024;

    void ByteArray::SetLengthCommon(uint32_t newLength, bool calledFromLengthSetter)
    {
        if (m_subscribers.length() > 0 && m_buffer->length < DomainEnv::GLOBAL_MEMORY_MIN_SIZE)
            m_toplevel->throwRangeError(kInvalidRangeError);

        Grower grower(this, newLength);
        if (!calledFromLengthSetter ||
            (newLength < kHugeGrowthThreshold &&
             m_buffer->length < kHugeGrowthThreshold))
        {
            if (newLength > m_buffer->capacity)
            {
                grower.EnsureWritableCapacity();
            }
        }
        else
        {
            // Bugzilla 699176: Setting the length is different than other
            // expanding/contracting operations; it represents the client
            // saying exactly how much (or how little) storage they
            // anticipate using.
            //
            // Thus, when we are (or will be) at a large size:
            // 1. Call ReallocBackingStore() directly and unconditionally,
            //    rather than conditionally via EnsureWritableCapacity().
            // 2. Round capacity up to multiple of kHugeGrowthIncr to
            //    avoid some pathoglogical cases.

            // (overflow paranoia; see notes above SetLength(uint32_t, uint32_t).
            uint64_t newCapRoundedUp =
                roundUpTo(uint64_t(newLength), uint64_t(kHugeGrowthIncr));
            uint32_t newCap = ((newCapRoundedUp <= MAX_BYTEARRAY_STORE_LENGTH)
                               ? uint32_t(newCapRoundedUp) : newLength);

            AvmAssert(newCap >= newLength);

            if (newCap != m_buffer->capacity)
            {
                grower.ReallocBackingStore();
            }
        }

        m_buffer->length = newLength;
        if (m_position > newLength)
            m_position = newLength;
    }

    void FASTCALL ByteArray::SetLength(uint32_t newLength)
    {
        SetLengthCommon(newLength, false);
    }

    void FASTCALL ByteArray::SetLengthFromAS3(uint32_t newLength)
    {
        SetLengthCommon(newLength, true);
    }

    // When we might be reading or writing to ourself, use this function
    // apparently SunPro compiler doesn't like combining REALLY_INLINE with static functions in CPP files
    /*static*/
    REALLY_INLINE void move_or_copy(void* dst, const void* src, uint32_t count)
    {
        if ((uintptr_t(dst) - uintptr_t(src)) >= uintptr_t(count))
        {
            VMPI_memcpy(dst, src, count);
        }
        else
        {
            VMPI_memmove(dst, src, count);
        }
    }

    void ByteArray::Read(void* buffer, uint32_t count)
    {
        CheckEOF(count);
        move_or_copy(buffer, m_buffer->array + m_position, count);
        m_position += count;
    }

    void ByteArray::Write(const void* buffer, uint32_t count)
    {
        uint32_t writeEnd = m_position + count;
        
        Grower grower(this, writeEnd);
        grower.EnsureWritableCapacity();
        
        move_or_copy(m_buffer->array + m_position, buffer, count);
        m_position += count;
        if (m_buffer->length < m_position)
            m_buffer->length = m_position;
    }

    void ByteArray::EnsureCapacity(uint32_t capacity)
    {
        Grower grower(this, capacity);
        grower.EnsureWritableCapacity();
    }
    
    void ByteArray::NotifySubscribers()
    {
        for (uint32_t i = 0, n = m_subscribers.length(); i < n; ++i)
        {
            AvmAssert(m_buffer->length >= DomainEnv::GLOBAL_MEMORY_MIN_SIZE);
 
            DomainEnv* subscriber = m_subscribers.get(i);
            if (subscriber)
            {
                subscriber->notifyGlobalMemoryChanged(m_buffer->array, m_buffer->length);
            }
            else
            {
                // Domain went away? remove link
                m_subscribers.removeAt(i);
                --i;
            }
        }
    }
 
    bool ByteArray::addSubscriber(DomainEnv* subscriber)
    {
        if (m_buffer->length >= DomainEnv::GLOBAL_MEMORY_MIN_SIZE)
        {
            removeSubscriber(subscriber);
            m_subscribers.add(subscriber);
            // notify the new "subscriber" of the current state of the world
            subscriber->notifyGlobalMemoryChanged(m_buffer->array, m_buffer->length);
            return true;
        }
        return false;
    }
 
    bool ByteArray::removeSubscriber(DomainEnv* subscriber)
    {
        for (uint32_t i = 0, n = m_subscribers.length(); i < n; ++i)
        {
            if (m_subscribers.get(i) == subscriber)
            {
                m_subscribers.removeAt(i);
                return true;
            }
        }
        return false;
    }
 
#ifdef DEBUGGER
    uint64_t ByteArray::bytesUsed() const
    {
        // If m_copyOnWrite is set, then we don't own the buffer, so the profiler
        // should not attribute it to us.
        return IsCopyOnWrite() ? 0 : m_buffer->capacity;
    }
#endif

    void ByteArray::TellGcNewBufferMemory(const uint8_t* buf, uint32_t numberOfBytes)
    {
        if (buf && numberOfBytes > 0)
        {
            m_gc->SignalDependentAllocation(numberOfBytes, MMgc::typeByteArray);
        }
    }

    void ByteArray::TellGcDeleteBufferMemory(const uint8_t* buf, uint32_t numberOfBytes)
    {
        // Note that we can't rely on using m_toplevel->core()->GetGC();
        // order of destruction is unspecified, and if this is called at destruction
        // time, Toplevel might have been destroyed before us. So keep a separate GC*.
        if (buf && numberOfBytes > 0)
        {
            m_gc->SignalDependentDeallocation(numberOfBytes, MMgc::typeByteArray);
        }
    }

    void ByteArray::Compress(CompressionAlgorithm algorithm)
    {
        // Snarf the data and give ourself some empty data
        // (remember, existing data might be copy-on-write so don't dance on it)
        uint8_t* origData                       = m_buffer->array;
        uint32_t origLen                        = m_buffer->length;
        uint32_t origCap                        = m_buffer->capacity;
        MMgc::GCObject* origCopyOnWriteOwner    = m_copyOnWriteOwner;
        if (!origLen) // empty buffer should give empty result
            return;

        m_buffer->array             = NULL;
        m_buffer->length            = 0;
        m_buffer->capacity          = 0;
        m_position          = 0;
        m_copyOnWriteOwner  = NULL;

        int error = Z_OK;
        
        // Use zlib to compress the data. This next block is essentially the
        // implementation of the compress2() method, but modified to pass a
        // negative window value (-15) to deflateInit2() for k_deflate mode
        // in order to obtain deflate-only compression (no ZLib headers).

        const int MAX_WINDOW_RAW_DEFLATE = -15;
        const int DEFAULT_MEMORY_USE = 8;

        z_stream stream;
        VMPI_memset(&stream, 0, sizeof(stream));
        error = deflateInit2(&stream,
                                Z_BEST_COMPRESSION,
                                Z_DEFLATED,
                                algorithm == k_zlib ? MAX_WBITS : MAX_WINDOW_RAW_DEFLATE,
                                DEFAULT_MEMORY_USE,
                                Z_DEFAULT_STRATEGY);
        AvmAssert(error == Z_OK);

        uint32_t newCap = deflateBound(&stream, origLen);
        EnsureCapacity(newCap);

        stream.next_in = origData;
        stream.avail_in = origLen;
        stream.next_out = m_buffer->array;
        stream.avail_out = m_buffer->capacity;

        error = deflate(&stream, Z_FINISH);
        AvmAssert(error == Z_STREAM_END);

        m_buffer->length = stream.total_out;
        AvmAssert(m_buffer->length <= m_buffer->capacity);

        // Note that Compress() has always ended with position == length,
        // but Uncompress() has always ended with position == 0.
        // Weird, but we must maintain it.
        m_position = m_buffer->length;

        deflateEnd(&stream);

        // Note: the Compress() method has never reported an error for corrupted data,
        // so we won't start now. (Doing so would probably require a version check,
        // to avoid breaking content that relies on misbehavior.)
        if (origData && origData != m_buffer->array && origCopyOnWriteOwner == NULL)
        {
            // Note that TellGcXXX always expects capacity, not (logical) length.
            TellGcDeleteBufferMemory(origData, origCap);
            mmfx_delete_array(origData);
        }
    }

    void ByteArray::Uncompress(CompressionAlgorithm algorithm)
    {
        // Snarf the data and give ourself some empty data
        // (remember, existing data might be copy-on-write so don't dance on it)
        uint8_t* origData                       = m_buffer->array;
        uint32_t origCap                        = m_buffer->capacity;
        uint32_t origLen                        = m_buffer->length;
        uint32_t origPos                        = m_position;
        MMgc::GCObject* origCopyOnWriteOwner    = m_copyOnWriteOwner;
        if (!origLen) // empty buffer should give empty result
            return;

        m_buffer->array             = NULL;
        m_buffer->length            = 0;
        m_buffer->capacity          = 0;
        m_position          = 0;
        m_copyOnWriteOwner  = NULL;
        // we know that the uncompressed data will be at least as
        // large as the compressed data, so let's start there,
        // rather than at zero.
        EnsureCapacity(origCap);

        const uint32_t kScratchSize = 8192;
        uint8_t* scratch = mmfx_new_array(uint8_t, kScratchSize);

        int error = Z_OK;
        
        z_stream stream;
        VMPI_memset(&stream, 0, sizeof(stream));
        error = inflateInit2(&stream, algorithm == k_zlib ? 15 : -15);
        AvmAssert(error == Z_OK);

        stream.next_in = origData;
        stream.avail_in = origLen;
        while (error == Z_OK)
        {
            stream.next_out = scratch;
            stream.avail_out = kScratchSize;
            error = inflate(&stream, Z_NO_FLUSH);
            Write(scratch, kScratchSize - stream.avail_out);
        }

        inflateEnd(&stream);

        mmfx_delete_array(scratch);

        if (error == Z_STREAM_END)
        {
            // everything is cool
            if (origData && origData != m_buffer->array && origCopyOnWriteOwner == NULL)
            {
                // Note that TellGcXXX always expects capacity, not (logical) length.
                TellGcDeleteBufferMemory(origData, origCap);
                mmfx_delete_array(origData);
            }

            // Note that Compress() has always ended with position == length,
            // but Uncompress() has always ended with position == 0.
            // Weird, but we must maintain it.
            m_position = 0;
        }
        else
        {
            // When we error:

            // 1) free the new buffer
            TellGcDeleteBufferMemory(m_buffer->array, m_buffer->capacity);
            mmfx_delete_array(m_buffer->array);

            // 2) put the original data back.
            m_buffer->array = origData;
            m_buffer->length = origLen;
            m_buffer->capacity = origCap;
            m_position = origPos;
            SetCopyOnWriteOwner(origCopyOnWriteOwner);
            toplevel()->throwIOError(kCompressedDataError);
        }
    }

    // For requestBytesForShortRead() there is no limit on m_position, but m_length 
    // is limited to MAX_BYTEARRAY_STORE_LENGTH, which is well below 2^32.  We limit 
    // nbytes to MAX_BYTEARRAY_SHORT_ACCESS_LENGTH, which is less than
    // 2^32-MAX_BYTEARRAY_STORE_LENGTH but at least 4095.  Callers that might have a
    // larger value for nbytes should not use this API.  The purpose of all these limits
    // is to make the range check tractably small for inlining in jitted code without
    // limiting the ByteArray size unreasonably.  (Requiring m_length < 2^31 would lead 
    // to further optimizations but that seems unreasonably short.)
    //
    // Observe that ByteArray::Grower::ReallocBackingStore() implements the appropriate
    // limit on m_capacity, and that is the only code that allocates memory for ByteArray.
    // Everywhere else we ensure m_length <= m_capacity.

    REALLY_INLINE uint8_t* ByteArray::requestBytesForShortRead(uint32_t nbytes)
    {
        AvmAssert(m_buffer->length <= m_buffer->capacity);
        AvmAssert(m_buffer->capacity <= MAX_BYTEARRAY_STORE_LENGTH);
        AvmAssert(nbytes > 0 && nbytes <= MAX_BYTEARRAY_SHORT_ACCESS_LENGTH);

        // m_position + nbytes does not overflow uint32_t in the second disjunct because:
        //
        //   m_position < m_length <= m_capacity <= MAX_BYTEARRAY_STORE_LENGTH      (by the first disjunct + global invariants)
        //   nbytes <= MAX_BYTEARRAY_SHORT_ACCESS_LENGTH                            (global invariant)
        //   MAX_BYTEARRAY_STORE_LENGTH + MAX_BYTEARRAY_SHORT_ACCESS_LENGTH < 2^32  (global invariant)

        if (m_position >= m_buffer->length || m_position + nbytes > m_buffer->length)
            ThrowEOFError();      // Does not return
        uint8_t *b = m_buffer->array + m_position;
        m_position += nbytes;
        return b;
    }

    // Same argument as for requestBytesForShortRead(), above.
    
    REALLY_INLINE uint8_t* ByteArray::requestBytesForShortWrite(uint32_t nbytes)
    {
        AvmAssert(nbytes > 0 && nbytes <= MAX_BYTEARRAY_SHORT_ACCESS_LENGTH);
    
        // m_position + nbytes does not overflow uint32_t in the second disjunct because:
        //
        //   m_position < m_length <= m_capacity <= MAX_BYTEARRAY_STORE_LENGTH     (by the first disjunct + global invariants)
        //   nbytes <= MAX_BYTEARRAY_SHORT_ACCESS_LENGTH                           (global invariant)
        //   MAX_BYTEARRAY_STORE_LENGTH + MAX_BYTEARRAY_SHORT_ACCESS_LENGTH < 2^32 (global invariant)

        if (m_position >= m_buffer->length || m_position + nbytes > m_buffer->length)
            SetLength(m_position, nbytes);  // The addition would *not* be safe against overflow here
    
        AvmAssert(m_buffer->length <= m_buffer->capacity);
        AvmAssert(m_buffer->capacity <= MAX_BYTEARRAY_STORE_LENGTH);
        AvmAssert(m_buffer->length >= nbytes && m_position <= m_buffer->length - nbytes);

        uint8_t *b = m_buffer->array + m_position;
        m_position += nbytes;
        return b;
    }
    
    bool ByteArray::CAS(uint32_t index, int32_t expected, int32_t next)
    {
        if (index >= m_buffer->length) // Handle the race. 
            m_toplevel->throwRangeError(kInvalidRangeError);
        if (index % sizeof(expected) != 0) // require word alignment
            m_toplevel->throwRangeError(kInvalidRangeError);

        uint8_t* wordptr = &m_buffer->array[index];
        return vmbase::AtomicOps::compareAndSwap32WithBarrier(expected, next, (int32_t*)wordptr);
    }

    bool ByteArray::isWorkerLocal()
    {
        return m_workerLocal;
    }

    bool ByteArray::setWorkerLocal(bool flag)
    {
        if (m_workerLocal == flag)
            return false; // no change.
        if (m_workerLocal == false && flag == true)
            return false; // FIXME can't 'localize' yet. No change
        m_workerLocal = flag;
        return true;  // changed.
    }
    
    
    //
    // ByteArrayObject
    //
    
    ByteArrayObject::ByteArrayObject(VTable* ivtable, ScriptObject* delegate)
        : ScriptObject(ivtable, delegate)
        , m_byteArray(toplevel())
    {
        c.set(&m_byteArray, sizeof(ByteArray));
        ByteArrayClass* cls = toplevel()->byteArrayClass();
        m_byteArray.SetObjectEncoding((ObjectEncoding)cls->get_defaultObjectEncoding());
        toplevel()->byteArrayCreated(this);
    }

    ByteArrayObject::ByteArrayObject(VTable* ivtable, ScriptObject* delegate, const ByteArray& source)
        : ScriptObject(ivtable, delegate)
        , m_byteArray(toplevel(), source)
    {
        c.set(&m_byteArray, sizeof(ByteArray));
        toplevel()->byteArrayCreated(this);
    }


    ByteArrayObject::ByteArrayObject(VTable* ivtable, ScriptObject* delegate, ByteArray::Buffer* source)
        : ScriptObject(ivtable, delegate)
        , m_byteArray(toplevel(), source, false)
    {
        c.set(&m_byteArray, sizeof(ByteArray));
        toplevel()->byteArrayCreated(this);
    }


    // Inspection of the object code (GCC 4.2) shows that the forced inlining of GetLength
    // and operator[] lead to optimal code here: no redundant range check is being executed
    // even if there is a redundant check in operator[].
    Atom ByteArrayObject::getUintProperty(uint32_t i) const
    {
        if (i < m_byteArray.GetLength())
        {
            intptr_t const b = m_byteArray[i];
            return atomFromIntptrValue(b);
        }
        else
        {
            return undefinedAtom;
        }
    }
    
    bool ByteArrayObject::hasUintProperty(uint32_t i) const
    {
        return i < m_byteArray.GetLength();
    }
    
    void ByteArrayObject::setUintProperty(uint32_t i, Atom value)
    {
        m_byteArray[i] = uint8_t(AvmCore::integer(value));
    }
    
    Atom ByteArrayObject::getAtomProperty(Atom name) const
    {
        uint32_t index;
        if (AvmCore::getIndexFromAtom(name, &index))
        {
            return getUintProperty(index);
        }

        return ScriptObject::getAtomProperty(name);
    }
    
    void ByteArrayObject::setAtomProperty(Atom name, Atom value)
    {
        uint32_t index;
        if (AvmCore::getIndexFromAtom(name, &index))
        {
            setUintProperty(index, value);
        }
        else
        {
            ScriptObject::setAtomProperty(name, value);
        }
    }
    
    bool ByteArrayObject::hasAtomProperty(Atom name) const
    {
        if (core()->currentBugCompatibility()->bugzilla558863)
        {
            uint32_t index;
            if (AvmCore::getIndexFromAtom(name, &index))
            {
                return index < m_byteArray.GetLength();
            }

            return ScriptObject::hasAtomProperty(name);
        }
        else
        {
            return ScriptObject::hasAtomProperty(name)
                || getAtomProperty(name) != undefinedAtom;
        }
    }

    Atom ByteArrayObject::getMultinameProperty(const Multiname* name) const
    {
        uint32_t index;
        if (name->getName()->parseIndex(index))
        {
            return getUintProperty(index);
        }

        return ScriptObject::getMultinameProperty(name);
    }

    void ByteArrayObject::setMultinameProperty(const Multiname* name, Atom value)
    {
        uint32_t index;
        if (name->getName()->parseIndex(index))
        {
            setUintProperty(index, value);
        }
        else
        {
            ScriptObject::setMultinameProperty(name, value);
        }
    }

    bool ByteArrayObject::hasMultinameProperty(const Multiname* name) const
    {
        uint32_t index;
        if (name->getName()->parseIndex(index))
        {
            return index < m_byteArray.GetLength();
        }

        return ScriptObject::hasMultinameProperty(name);
    }

    /*virtual*/ 
    ScriptObject* ByteArrayObject::cloneNonSlots(ClassClosure* targetClass, Cloner&) const
    {
        ByteArrayObject* clone = new (targetClass->gc(), MMgc::kExact) ByteArrayObject(targetClass->ivtable(), targetClass->prototypePtr(), m_byteArray);
        return clone;
    }

    String* ByteArrayObject::_toString()
    {
        uint32_t len = m_byteArray.GetLength();
        const uint8_t* c = m_byteArray.GetReadableBuffer();

        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if (len >= 3)
        {
            // UTF8 BOM
            if ((c[0] == 0xef) && (c[1] == 0xbb) && (c[2] == 0xbf))
            {
                return core->newStringUTF8((const char*)c + 3, len - 3);
            }
            else if ((c[0] == 0xfe) && (c[1] == 0xff))
            {
                //UTF-16 big endian
                c += 2;
                len = (len - 2) >> 1;
                return core->newStringEndianUTF16(/*littleEndian*/false, (const wchar*)c, len);
            }
            else if ((c[0] == 0xff) && (c[1] == 0xfe))
            {
                //UTF-16 little endian
                c += 2;
                len = (len - 2) >> 1;
                return core->newStringEndianUTF16(/*littleEndian*/true, (const wchar*)c, len);
            }
        }

        String* result = toplevel->tryFromSystemCodepage(c);
        if (result != NULL)
            return result;
        
        // Use newStringUTF8() with "strict" explicitly set to false to mimick old,
        // buggy behavior, where malformed UTF-8 sequences are stored as single characters.
        return core->newStringUTF8((const char*)c, len, false);
    }
    
    Atom ByteArrayObject::readObject()
    {
        return m_byteArray.ReadObject();
    }

    void ByteArrayObject::writeObject(Atom value)
    {
        m_byteArray.WriteObject(value);
    }
    
    int ByteArrayObject::readByte()
    {
        return (int8_t)*m_byteArray.requestBytesForShortRead(1);
    }

    int ByteArrayObject::readUnsignedByte()
    {
        return *m_byteArray.requestBytesForShortRead(1);
    }

    REALLY_INLINE uint32_t ByteArrayObject::read16()
    {
        uint8_t *b = m_byteArray.requestBytesForShortRead(2);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian()) {  // GetNativeEndian expands to a constant
#if defined VMCFG_UNALIGNED_INT_ACCESS
            return *(uint16_t*)b;
#elif defined VMCFG_BIG_ENDIAN
            return ((uint32_t)b[0] << 8) | (uint32_t)b[1]; // read big-endian
#else
            return ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP16
            return byteSwap16(*(uint16_t*)b);
#elif defined VMCFG_BIG_ENDIAN
            return ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
#else
            return ((uint32_t)b[0] << 8) | (uint32_t)b[1]; // read big-endian
#endif
        }
    }
    
    int ByteArrayObject::readShort()
    {
        return (int)(int16_t)read16();
    }

    int ByteArrayObject::readUnsignedShort()
    {
        return (int)read16();
    }

    REALLY_INLINE uint32_t ByteArrayObject::read32()
    {
        uint8_t* b = m_byteArray.requestBytesForShortRead(4);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())  // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS
            return *(uint32_t*)b;
#elif defined VMCFG_BIG_ENDIAN
            return ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; // read big-endian
#else
            return ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            return byteSwap32(*(uint32_t*)b);
#elif defined VMCFG_BIG_ENDIAN
            return ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
#else
            return ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; // read big-endian
#endif
        }
    }

    int ByteArrayObject::readInt()
    {
        return (int)read32();
    }

    uint32_t ByteArrayObject::readUnsignedInt()
    {
        return read32();
    }

    // Some observations from x86 testing of float and double reading:
    //
    //  - It pays to make use of VMCFG_UNALIGNED_FP_ACCESS.
    //  - It pays to assemble an int32 in a register and then store it in
    //    a 32-bit field of the union, that is then read (either alone for
    //    float or as part of a pair for double), rather than shuffling 
    //    bytes individually into a byte array in the union.

    // Bugzilla 569691/685441: Do not try to be clever here by loading from
    // '*(uint32_t*)b' into 'u.word', even if VMCFG_UNALIGNED_INT_ACCESS and
    // on native endianness - gcc may emit code that loads directly
    // to the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.

    REALLY_INLINE float ByteArrayObject::readFloatHelper(uint8_t* b)
    {
        union {
            uint32_t word;
            float    fval;
        } u;
        
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())  // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_FP_ACCESS
            return *(float*)b;
#elif defined VMCFG_BIG_ENDIAN
            u.word = ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; // read big-endian
            return u.fval;
#else
            u.word = ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
            return u.fval;
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            u.word = byteSwap32(*(uint32_t*)b);
#elif defined VMCFG_BIG_ENDIAN
            u.word = ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read little-endian
#else
            u.word = ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; // read big-endian
#endif
            return u.fval;
        }    }
    
    double ByteArrayObject::readFloat()
    {
        return readFloatHelper(m_byteArray.requestBytesForShortRead(4));
    }

#ifdef VMCFG_FLOAT
    // There will be four endianness checks here but one hopes the compiler will
    // common them after inlining.
    void ByteArrayObject::readFloat4(float4_t* retval)
    {
        uint8_t *b = m_byteArray.requestBytesForShortRead(16);
        float x = readFloatHelper(b);
        float y = readFloatHelper(b+4);
        float z = readFloatHelper(b+8);
        float w = readFloatHelper(b+12);
        float4_t v = { x, y, z, w };
        *retval = v;
    }
#endif

    // Bugzilla 569691/685441: Do not try to be clever here by loading from
    // '*(uint32_t*)b' into 'u.word[i]', even if VMCFG_UNALIGNED_INT_ACCESS and
    // on native endianness - gcc may emit code that loads directly
    // to the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.
    
    double ByteArrayObject::readDouble()
    {
        // Handle reversed word order for doubles
#if defined VMCFG_DOUBLE_MSW_FIRST
        const int first = 1;
        const int second = 0;
#else
        const int first = 0;
        const int second = 1;
#endif
        union {
            uint32_t words[2];
            double   dval;
        } u;
        uint8_t *b = m_byteArray.requestBytesForShortRead(8);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())  // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_FP_ACCESS
            return *(double*)b;
#elif defined VMCFG_BIG_ENDIAN
            u.words[first] = ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; // read
            u.words[second] = ((uint32_t)b[4] << 24) | ((uint32_t)b[5] << 16) | ((uint32_t)b[6] << 8) | (uint32_t)b[7]; //   big-endian
            return u.dval;
#else
            u.words[first] = ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; // read
            u.words[second] = ((uint32_t)b[7] << 24) | ((uint32_t)b[6] << 16) | ((uint32_t)b[5] << 8) | (uint32_t)b[4]; //   little-endian
            return u.dval;
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            u.words[first] = byteSwap32(*(uint32_t*)(b+4));
            u.words[second] = byteSwap32(*(uint32_t*)b);
#elif defined VMCFG_BIG_ENDIAN
            u.words[first] = ((uint32_t)b[7] << 24) | ((uint32_t)b[6] << 16) | ((uint32_t)b[5] << 8) | (uint32_t)b[4]; // read
            u.words[second] = ((uint32_t)b[3] << 24) | ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0]; //   little-endian
#else
            u.words[first] = ((uint32_t)b[4] << 24) | ((uint32_t)b[5] << 16) | ((uint32_t)b[6] << 8) | (uint32_t)b[7]; // read
            u.words[second] = ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | (uint32_t)b[3]; //   big-endian
#endif
            return u.dval;
        }
    }

    bool ByteArrayObject::readBoolean()
    {
        return (*m_byteArray.requestBytesForShortRead(1)) != 0;
    }

    void ByteArrayObject::writeBoolean(bool value)
    {
        m_byteArray.requestBytesForShortWrite(1)[0] = (value ? 1 : 0);
    }

    void ByteArrayObject::writeByte(int value)
    {
        m_byteArray.requestBytesForShortWrite(1)[0] = (uint8_t)value;
    }

    void ByteArrayObject::writeShort(int value)
    {
        uint8_t *b = m_byteArray.requestBytesForShortWrite(2);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())   // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS
            *(int16_t*)b = (int16_t)value;
#elif defined VMCFG_BIG_ENDIAN
            b[0] = (value >> 8);  // write
            b[1] = value;         //   big-endian
#else
            b[1] = (value >> 8);  // write
            b[0] = value;         //   little-endian
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP16
            *(int16_t*)b = byteSwap16((uint16_t)value);
#elif defined VMCFG_BIG_ENDIAN
            b[1] = (value >> 8);  // write
            b[0] = value;         //   little-endian
#else
            b[0] = (value >> 8);  // write
            b[1] = value;         //   big-endian
#endif
        }
    }

    REALLY_INLINE void ByteArrayObject::write32(uint32_t value)
    {
        uint8_t *b = m_byteArray.requestBytesForShortWrite(4);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())   // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS
            *(uint32_t*)b = value;
#elif defined VMCFG_BIG_ENDIAN
            b[0] = (value >> 24);   // write
            b[1] = (value >> 16);   //   big
            b[2] = (value >> 8);    //     endian
            b[3] = value;
#else
            b[3] = (value >> 24);   // write
            b[2] = (value >> 16);   //   little
            b[1] = (value >> 8);    //     endian
            b[0] = value;
#endif
        }
        else
        {
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            *(uint32_t*)b = byteSwap32(value);
#elif defined VMCFG_BIG_ENDIAN
            b[3] = (value >> 24);   // write
            b[2] = (value >> 16);   //   little
            b[1] = (value >> 8);    //     endian
            b[0] = value;
#else
            b[0] = (value >> 24);   // write
            b[1] = (value >> 16);   //   big
            b[2] = (value >> 8);    //     endian
            b[3] = value;
#endif
        }
    }

    void ByteArrayObject::writeInt(int value)
    {
        write32((uint32_t)value);
    }

    void ByteArrayObject::writeUnsignedInt(uint32_t value)
    {
        write32(value);
    }
    
    // Bugzilla 569691/685441: Do not try to be clever here by storing from
    // 'u.word' into '*(uint32_t*)b', even if both VMCFG_UNALIGNED_INT_ACCESS and
    // on native endianness - gcc will emit code that stores directly
    // from the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.

    REALLY_INLINE void ByteArrayObject::writeFloatHelper(float value, uint8_t* b)
    {
        union {
            uint32_t word;
            float    fval;
        } u;
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())   // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_FP_ACCESS
            *(float*)b = value;
#elif defined VMCFG_BIG_ENDIAN
            u.fval = value;
            uint32_t w = u.word;
            b[0] = (w >> 24);   // write
            b[1] = (w >> 16);   //   big
            b[2] = (w >> 8);    //     endian
            b[3] = w;
#else
            u.fval = value;
            uint32_t w = u.word;
            b[3] = (w >> 24);   // write
            b[2] = (w >> 16);   //   little
            b[1] = (w >> 8);    //     endian
            b[0] = w;
#endif
        }
        else
        {
            u.fval = value;
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            *(uint32_t*)b = byteSwap32(u.word);
#elif defined VMCFG_BIG_ENDIAN
            uint32_t w = u.word;
            b[3] = (w >> 24);   // write
            b[2] = (w >> 16);   //   little
            b[1] = (w >> 8);    //     endian
            b[0] = w;
#else
            uint32_t w = u.word;
            b[0] = (w >> 24);   // write
            b[1] = (w >> 16);   //   big
            b[2] = (w >> 8);    //     endian
            b[3] = w;
#endif
        }
    }

    void ByteArrayObject::writeFloat(double value)
    {
        writeFloatHelper((float)value, m_byteArray.requestBytesForShortWrite(4));
    }

#ifdef VMCFG_FLOAT
    // There will be four endianness checks here but one hopes the compiler will
    // common them after inlining.
    void ByteArrayObject::writeFloat4(const float4_t& v)
    {
        uint8_t* b = m_byteArray.requestBytesForShortWrite(16);
        writeFloatHelper(f4_x(v), b);
        writeFloatHelper(f4_y(v), b+4);
        writeFloatHelper(f4_z(v), b+8);
        writeFloatHelper(f4_w(v), b+12);
    }
#endif
    
    // Bugzilla 569691/685441: Do not try to be clever here by storing from
    // 'u.word[i]' into '*(uint32_t*)b', even if both VMCFG_UNALIGNED_INT_ACCESS and
    // on native endianness - gcc will emit code that stores directly
    // from the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.
    
    void ByteArrayObject::writeDouble(double value)
    {
        // Handle reversed word order for doubles
#if defined VMCFG_DOUBLE_MSW_FIRST
        const int first = 1;
        const int second = 0;
#else
        const int first = 0;
        const int second = 1;
#endif
        union {
            uint32_t words[2];
            double   dval;
        } u;
        uint8_t *b = m_byteArray.requestBytesForShortWrite(8);
        if (m_byteArray.GetEndian() == m_byteArray.GetNativeEndian())   // GetNativeEndian expands to a constant
        {
#if defined VMCFG_UNALIGNED_FP_ACCESS
            *(double*)b = value;
#elif defined VMCFG_BIG_ENDIAN
            uint32_t w;
            u.dval = value;
            w = u.words[first];
            b[0] = (w >> 24);   // write
            b[1] = (w >> 16);   //   big
            b[2] = (w >> 8);    //     endian
            b[3] = w;
            w = u.words[second];
            b[4] = (w >> 24);   // write
            b[5] = (w >> 16);   //   big
            b[6] = (w >> 8);    //     endian
            b[7] = w;
#else
            uint32_t w;
            u.dval = value;
            w = u.words[first];
            b[3] = (w >> 24);   // write
            b[2] = (w >> 16);   //   little
            b[1] = (w >> 8);    //     endian
            b[0] = w;
            w = u.words[second];
            b[7] = (w >> 24);   // write
            b[6] = (w >> 16);   //   little
            b[5] = (w >> 8);    //     endian
            b[4] = w;
#endif
        }
        else
        {
            u.dval = value;
#if defined VMCFG_UNALIGNED_INT_ACCESS && defined HAVE_BYTESWAP32
            *(uint32_t*)b = byteSwap32(u.words[second]);       // write
            *(uint32_t*)(b+4) = byteSwap32(u.words[first]);   //   opposite endianness
#elif defined VMCFG_BIG_ENDIAN
            uint32_t w;
            u.dval = value;
            w = u.words[first];
            b[7] = (w >> 24);   // write
            b[6] = (w >> 16);   //   little
            b[5] = (w >> 8);    //     endian
            b[4] = w;
            w = u.words[second];
            b[3] = (w >> 24);   // write
            b[2] = (w >> 16);   //   little
            b[1] = (w >> 8);    //     endian
            b[0] = w;
#else
            uint32_t w;
            u.dval = value;
            w = u.words[second];
            b[0] = (w >> 24);   // write
            b[1] = (w >> 16);   //   big
            b[2] = (w >> 8);    //     endian
            b[3] = w;
            w = u.words[first];
            b[4] = (w >> 24);   // write
            b[5] = (w >> 16);   //   big
            b[6] = (w >> 8);    //     endian
            b[7] = w;
#endif
        }
    }

    ByteArray::CompressionAlgorithm ByteArrayObject::algorithmToEnum(String* algorithm)
    {
        Toplevel* toplevel = this->toplevel();
        toplevel->checkNull(algorithm, "algorithm");
        if (algorithm->equalsLatin1("zlib"))
        {
            return ByteArray::k_zlib;
        }
        if (algorithm->equalsLatin1("deflate"))
        {
            return ByteArray::k_deflate;
        }
        else
        {
            // Unknown format
            toplevel->throwIOError(kCompressedDataError);
            return ByteArray::k_zlib; // not reached, pacify compiler
        }
    }

    void ByteArrayObject::_compress(String* algorithm)
    {
        m_byteArray.Compress(algorithmToEnum(algorithm));
    }

    void ByteArrayObject::_uncompress(String* algorithm)
    {
        m_byteArray.Uncompress(algorithmToEnum(algorithm));
    }

    void ByteArrayObject::writeBytes(ByteArrayObject *bytes,
                                     uint32_t offset,
                                     uint32_t length)
    {
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = bytes->get_length() - offset;
        }

        m_byteArray.WriteByteArray(bytes->GetByteArray(),
                                   offset,
                                   length);
    }

    void ByteArrayObject::readBytes(ByteArrayObject *bytes,
                                    uint32_t offset,
                                    uint32_t length)
    {
        toplevel()->checkNull(bytes, "bytes");

        if (length == 0) {
            length = m_byteArray.Available();
        }

        m_byteArray.ReadByteArray(bytes->GetByteArray(),
                                  offset,
                                  length);
    }

    String* ByteArrayObject::readMultiByte(uint32_t length, String* charSet)
    {
        toplevel()->checkNull(charSet, "charSet");
        return m_byteArray.ReadMultiByte(length, charSet);
    }
    
    String* ByteArrayObject::readUTF()
    {
        return readUTFBytes((uint32_t)readUnsignedShort());
    }

    String* ByteArrayObject::readUTFBytes(uint32_t length)
    {
        if (m_byteArray.Available() < length)
            toplevel()->throwEOFError(kEOFError);

        const uint8_t* p = (const uint8_t*)m_byteArray.GetReadableBuffer() + m_byteArray.GetPosition();

        uint32_t countBytesConsumed = length;
        // Skip UTF8 BOM (it is consumed from input, but not part of output).
        if (length >= 3 && p[0] == 0xEFU && p[1] == 0xBBU && p[2] == 0xBFU)
        {
            p += 3;
            length -= 3;
        }
        
        // Bugzilla 687341: we must stop at NUL, so here we need to scan for a NUL
        // in the portion we're considering.  With a fix to that bug we won't need
        // to do so.
#if 1
        const uint8_t* limit = p + length;
        const uint8_t* q = p;
        while (q < limit && *q != 0)
            q++;
#else
        const uint8_t* q = p + length;
#endif

        String *result = toplevel()->core()->newStringUTF8((const char*)p, int(q-p));

        // The position is always updated as if the entire string had been consumed, 
        // even if there was a NUL that made us stop early.
        m_byteArray.SetPosition(m_byteArray.GetPosition()+countBytesConsumed);

        return result;
    }

    void ByteArrayObject::writeMultiByte(String* value, String* charSet)
    {
        toplevel()->checkNull(value, "value");
        toplevel()->checkNull(charSet, "charSet");
        m_byteArray.WriteMultiByte(value, charSet);
    }
    
    void ByteArrayObject::writeUTF(String* value)
    {
        toplevel()->checkNull(value, "value");
        m_byteArray.WriteUTF(value);
    }

    void ByteArrayObject::writeUTFBytes(String* value)
    {
        toplevel()->checkNull(value, "value");
        m_byteArray.WriteUTFBytes(value);
    }

    uint32_t ByteArrayObject::get_objectEncoding()
    {
        return m_byteArray.GetObjectEncoding();
    }

    void ByteArrayObject::set_objectEncoding(uint32_t objectEncoding)
    {
        if ((objectEncoding == kAMF3)||(objectEncoding == kAMF0))
        {
            m_byteArray.SetObjectEncoding(ObjectEncoding(objectEncoding));
        }
        else
        {
            toplevel()->throwArgumentError(kInvalidEnumError, "objectEncoding");
        }
    }

    Stringp ByteArrayObject::get_endian()
    {
        return (m_byteArray.GetEndian() == kBigEndian) ? core()->kbigEndian : core()->klittleEndian;
    }

    void ByteArrayObject::set_endian(Stringp type)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        toplevel->checkNull(type, "endian");

        type = core->internString(type);
        if (type == core->kbigEndian)
        {
            m_byteArray.SetEndian(kBigEndian);
        }
        else if (type == core->klittleEndian)
        {
            m_byteArray.SetEndian(kLittleEndian);
        }
        else
        {
            toplevel->throwArgumentError(kInvalidEnumError, "type");
        }
    }
    
    void ByteArrayObject::clear()
    {
        m_byteArray.Clear();
        m_byteArray.SetPosition(0);
    }

    bool ByteArrayObject::compareAndSwapWordAt(uint32_t index, int32_t expected, int32_t next)
    {
        return m_byteArray.CAS(index, expected, next);
    }

    bool ByteArrayObject::share()
    {
        if (m_byteArray.isWorkerLocal()) {
            return m_byteArray.setWorkerLocal(false);
        } 
        return m_byteArray.isWorkerLocal() == false;
    }


#ifdef DEBUGGER
    uint64_t ByteArrayObject::bytesUsed() const
    {
        uint64_t size = ScriptObject::bytesUsed();
        size += m_byteArray.bytesUsed();
        return size;
    }
#endif

    //
    // ByteArrayClass
    //

    ByteArrayClass::ByteArrayClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
        set_defaultObjectEncoding(kEncodeDefault);
    }

    GCRef<ByteArrayObject> ByteArrayClass::constructByteArray()
    {
        return constructObject();
    }
}

