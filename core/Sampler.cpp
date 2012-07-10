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

// Adobe patent application tracking #P721, entitled Application Profiling, inventors: T. Reilly

#ifdef DEBUGGER
namespace avmplus
{
    using namespace MMgc;

    // sadly, declaring this "static" produces spurious warnings in some GCC versions
    template<class T>
    /*static*/ void inline read(uint8_t*& p, T& u)
    {
        // weirdly, declaring a naked union here causes the ARM gcc compiler
        // to issue bogus "unused" warnings for p8 and pT. Declaring it as
        // a type and using that doesn't. yay, buggy compilers.
        union Foo {
            const uint8_t* p8;
            const T* pT;
        };
        Foo foo;
        foo.p8 = p;
        u = *foo.pT;
        p += sizeof(T);

    }

    template<class T>
    /*static*/ void inline write(uint8_t*& p, T u)
    {
        // weirdly, declaring a naked union here causes the ARM gcc compiler
        // to issue bogus "unused" warnings for p8 and pT. Declaring it as
        // a type and using that doesn't. yay, buggy compilers.
        union Foo {
            uint8_t* p8;
            T* pT;
        };
        Foo foo;
        foo.p8 = p;
        *foo.pT = u;
        p += sizeof(T);
    }

    // aligns to an 8-byte boundary -- apparently assumes input is at least 4-byte aligned.
    static void inline align(uint8_t*& p)
    {
        AvmAssert((uintptr_t(p) & 3) == 0);
        if (uintptr_t(p) & 4)
        {
#ifdef DEBUG
            union {
                uint8_t* p8;
                int32_t* p32;
            };
            p8 = p;
            *p32 = 0xaaaaaaaa;
#endif
            p += sizeof(int32_t);
        }
    }

    // A sampler is tied to a particular GC/core pair.  As each GC/core pair
    // can be moved from one thread to another in a timesliced fashion in some
    // applications we do not use a thread-local variable to hold the sampler,
    // but attach it directly to the GC, which we pick up from the EnterFrame.

    void AttachSampler(IMemorySampler* sampler)
    {
        GCHeap* heap = GCHeap::GetGCHeap();     // May be NULL during OOM shutdown
        if (heap)
        {
            EnterFrame* ef = heap->GetEnterFrame();
            if (ef)
            {
                GC* gc = ef->GetActiveGC();
                if (gc) {
                    // Don't remove an already attached sampler
                    if (sampler == NULL || gc->GetAttachedSampler() == NULL)
                        gc->SetAttachedSampler(sampler);
                }
            }
        }
    }

    IMemorySampler* GetSampler()
    {
        GCHeap* heap = GCHeap::GetGCHeap();     // May be NULL during OOM shutdown
        if (heap)
        {
            EnterFrame* ef = heap->GetEnterFrame();
            if (ef)
            {
                GC* gc = ef->GetActiveGC();
                if (gc)
                    return (IMemorySampler*)gc->GetAttachedSampler();
            }
        }
        return NULL;
    }

    /* static */
    void recordAllocationSample(const void* item, size_t size)
    {
        IMemorySampler *sampler = GetSampler();
        if (sampler) {
            sampler->recordAllocation(item, size);
        }
    }

    /* static */
    void recordDeallocationSample(const void* item, size_t size)
    {
        IMemorySampler *sampler = GetSampler();
        if (sampler) {
            sampler->recordDeallocation(item, size);
        }
    }

    Sampler::Sampler(AvmCore* _core) :
        GCRoot(_core->GetGC()),
        IMemorySampler(),
        sampleIteratorVTable(NULL),
        slotIteratorVTable(NULL),
        core(_core),
        fakeMethodNames(_core->GetGC(), kListInitialCapacity),
        allocId(1),
        sampleBufferId(0),
        samples(NULL),
        currentSample(NULL),
        lastAllocSample(NULL),
        lastSampleCheckMicros(0),
        callback(NULL),
        timerHandle(0),
        uids(1024),
        ptrSamples(1024),
        takeSample(0),
        numSamples(0),
        samples_size(0),
        samplingNow(false),
        samplingAllAllocs(false),
        runningCallback(false),
        autoStartSampling(false),
        _sampling(true)
    {
        GCHeap::GetGCHeap()->EnableHooks();
        AttachSampler(this);
    }

    Sampler::~Sampler()
    {
        stopSampling();
        if (GetSampler() == this)
            AttachSampler(NULL);
    }

    void Sampler::init(bool sampling, bool autoStart)
    {
        this->_sampling = sampling;
        this->autoStartSampling = autoStart;
    }

    uint8_t *Sampler::getSamples(uint32_t &num)
    {
        num = numSamples;
        uint8_t *start = samples;
        return start;
    }

    void Sampler::sample()
    {
        AvmAssertMsg(sampling(), "How did we get here if sampling is disabled?");
        if(!samplingNow)
            return;

        uint64_t nowMicros = this->nowMicros();
        const uint64_t sampleFrequencyMicros = SAMPLE_FREQUENCY_MILLIS * 1000;

        if (takeSample)
        {
            if (core->callStack)
            {
                // We may want to write more than one sample.  E.g. if 5.5 milliseconds have
                // passed, we'll write 5 samples.
                int sampleCount = 0;
                if (lastSampleCheckMicros != 0)
                    sampleCount = (int) ((nowMicros - lastSampleCheckMicros) / sampleFrequencyMicros);
                if (sampleCount <= 0)
                    sampleCount = 1;
                for (int sampleNum = sampleCount-1; sampleNum >= 0; sampleNum--)
                {
                    if (!sampleSpaceCheck())
                        break;

                    // We artificially manufacture a different time for each sample.
                    uint64_t sampleTimeMicros = nowMicros - (sampleNum * sampleFrequencyMicros);
                    writeRawSample(RAW_SAMPLE, sampleTimeMicros);
                    numSamples++;
                }
            }
        }

        // Even if the callstack was empty, don't take another sample until the next timer tick.
        takeSample = 0;

        // Don't just set lastSampleCheckMicros equal to nowMicros -- we want to keep the
        // sampling frequency as close to one per millisecond as we can.
        uint64_t elapsed = nowMicros - lastSampleCheckMicros;
        lastSampleCheckMicros += (elapsed / sampleFrequencyMicros * sampleFrequencyMicros);
    }

    int Sampler::sampleSpaceCheck(bool callback_ok)
    {
        if(!samples)
            return 0;

        uint32_t sampleSize = sizeof(Sample);
        uint32_t callStackDepth = core->callStack ? core->callStack->depth() : 0;
        sampleSize += callStackDepth * sizeof(StackTrace::Element);
        sampleSize += sizeof(uint64_t) * 2;
        if( callback && callback_ok && !runningCallback && currentSample+sampleSize+samples_size/3 > (samples + samples_size)
            && !core->GetGC()->Collecting()
            && !core->GetGC()->Reaping()
            )       {
            runningCallback = true;
            pauseSampling();
            Atom args[1] = { nullObjectAtom };
            Atom ret = AtomConstants::falseAtom;
            TRY(core, kCatchAction_Ignore)
            {
                ret = callback->call(0, args);
            }
            CATCH(Exception* pExceptionToIgnore)
            {
                (void) pExceptionToIgnore;
            }
            END_CATCH
            END_TRY

            if( ret == falseAtom)
                stopSampling();
            else
                startSampling();
            runningCallback = false;
        }
        if(currentSample + sampleSize > samples+samples_size) {
/*
#ifdef AVMPLUS_VERBOSE
            core->console << "****** Exhausted Sample Buffer *******\n";
#endif
*/
            // exhausted buffer
            stopSampling();
            return 0;
        }
        return 1;
    }

    uint64_t Sampler::nowMicros()
    {
        return GC::ticksToMicros(VMPI_getPerformanceCounter());
    }

    void Sampler::writeRawSample(SampleType sampleType, uint64_t sampleTimeMicros /* =0 */)
    {
        CallStackNode *csn = core->callStack;
        uint32_t depth = csn ? csn->depth() : 0;
        uint8_t *p = currentSample;
        if (sampleTimeMicros == 0)
            sampleTimeMicros = nowMicros();
        write(p, sampleTimeMicros);
        write(p, sampleType);
        if(sampleType != DELETED_OBJECT_SAMPLE)
        {
            //if(depth == 0)
            //  AvmDebugMsg(false, "Please add SAMPLE_FRAME's to give this allocation some context.");
            write(p, depth);
            while(csn)
            {
                VMPI_memset(p, 0, sizeof(StackTrace::Element));
                StackTrace::Element *e = (StackTrace::Element*)p;
                e->m_info = csn->isAS3Sample() ? csn->info() : (MethodInfo*) StackTrace::Element::EXTERNAL_CALL_FRAME;
                e->m_linenum = csn->linenum();
                if(csn->isAS3Sample())
                {
                    e->u.m_fakename = csn->fakename();
                    // FIXME: can filename can be stored in the AbstractInfo?
                    e->u.m_filename = csn->filename();
                }
                else
                {
                    e->m_functionId = csn->functionId();
                }
                // advance p over the current stack element
                p += sizeof(StackTrace::Element);
                csn = csn->next();
                depth--;
            }
            AvmAssert(depth == 0);
        }
        // padding to keep 8 byte alignment
        align(p);
        currentSample = p;
    }

    void Sampler::readSample(uint8_t *&p, Sample &s)
    {
        VMPI_memset(&s, 0, sizeof(Sample));
        read(p, s.micros);
        read(p, s.sampleType);
        AvmAssertMsg(s.sampleType == RAW_SAMPLE ||
                s.sampleType == NEW_OBJECT_SAMPLE ||
                s.sampleType == DELETED_OBJECT_SAMPLE ||
                s.sampleType == NEW_AUX_SAMPLE, "Sample stream corruption.");

        if(s.sampleType != DELETED_OBJECT_SAMPLE)
        {
            read(p, s.stack.depth);
            s.stack.trace = p;
#ifndef AVMPLUS_64BIT
            AvmAssert(sizeof(StackTrace::Element) == sizeof(MethodInfo *) + sizeof(Stringp) + sizeof(Stringp) + sizeof(int32_t));
#else
            // Extra int because of the structure padding
            AvmAssert(sizeof(StackTrace::Element) == sizeof(MethodInfo *) + sizeof(Stringp) + sizeof(Stringp) + sizeof(int32_t) + sizeof(int32_t));
#endif
            p += s.stack.depth * sizeof(StackTrace::Element);
        }
        // padding to keep 8 byte alignment
        align(p);
        if(s.sampleType != Sampler::RAW_SAMPLE)
        {
            read(p, s.id);
            if(s.sampleType == Sampler::NEW_OBJECT_SAMPLE || s.sampleType == Sampler::NEW_AUX_SAMPLE)
            {
                read(p, s.ptr);
                read(p, s.sot);
                read(p, s.alloc_size);

                if (s.ptr != NULL && sotGetKind(s.sot) != kSOT_Empty && !GC::IsFinalized(s.ptr))
                {
                    // s.ptr HAS to be a ScriptObject (that inherits from RCObject),
                    // but it seems that its destructor has already been called, because
                    // it was cleared by calling "delete" during Marking or Collection.
                    // In that cases the collector will just set its finalized flag
                    // to false and let it be a zombie (simple GCObject) until
                    // it isn't referenced anymore. The zombie might be deleted
                    // in another sweep session, meaning that the Sampler can
                    // run and crash when trying to make the Sample object for the zombie object.
                    // The Sampler will eventually be notified that the zombie is deleted.
                    s.ptr = NULL;
                }

            }
            else
            {
                read(p, s.size);
            }
        }
    }

    void Sampler::recordAllocation(const void *item, size_t size)
    {
        if (sampling())
            recordAllocationSample(item, size);
    }

    void Sampler::recordDeallocation(const void *item, size_t size)
    {
        /*if (sampling())*/
            recordDeallocationSample(item, size);
    }

    void Sampler::recordNewObjectAllocation(AvmPlusScriptableObject *obj, avmplus::SamplerObjectType sot)
    {
        if (sampling())
            recordAllocationInfo(obj, sot);
    }

    uint64_t Sampler::recordAllocationSample(const void* item, uint64_t size, bool callback_ok, bool forceWrite)
    {
        AvmAssertMsg(sampling(), "How did we get here if sampling is disabled?");
        if(!samplingNow)
            return 0;

        if(!(forceWrite || samplingAllAllocs))
            return 0;

        if(!sampleSpaceCheck(callback_ok))
            return 0;

        (void)item;

        lastAllocSample = currentSample;
        writeRawSample(NEW_AUX_SAMPLE);
        uint64_t uid = allocId++;
        uids.add(item, uid);
        write(currentSample, uid);
        write(currentSample, item);
        write(currentSample, sotEmpty());
        write(currentSample, size);

        AvmAssertMsg((uintptr_t)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.");
        numSamples++;

        return uid;
    }

    uint64_t Sampler::recordAllocationInfo(AvmPlusScriptableObject *obj, SamplerObjectType sot)
    {
        AvmAssertMsg(sampling(), "How did we get here if sampling is disabled?");
        if(!samplingNow)
            return 0;

        if( !samplingAllAllocs )
        {
            // Turn on momentarily to record the alloc for this object.
            samplingAllAllocs = true;
            uint64_t uid = recordAllocationSample(obj, 0);
            samplingAllAllocs = false;
            if( !uid )
            {
                // allocation must have failed because the buffer was full
                return 0;
            }
        }

        uint8_t* old_sample = lastAllocSample;
        Sample s;
        readSample(old_sample, s);
        old_sample = lastAllocSample;

        DomainEnv* domainEnv = core->codeContext() ? core->codeContext()->domainEnv() : NULL;
        Toplevel* toplevel = domainEnv ? domainEnv->toplevel() : NULL;
        sot = sotSetToplevel(sot, toplevel);

        AvmAssertMsg(s.sampleType == NEW_AUX_SAMPLE, "Sample stream corrupt - can only add info to an AUX sample.");
        AvmAssertMsg(s.ptr == (void*)obj, "Sample stream corrupt - last sample is not for same object.");

        uint8_t* pos = currentSample;
        currentSample = old_sample;
        // Rewrite the sample as a NEW_OBJECT_SAMPLE
        writeRawSample(NEW_OBJECT_SAMPLE);

        write(currentSample, s.id);

        AvmAssertMsg( ptrSamples.get(obj)==0, "Missing dealloc sample - same memory alloc'ed twice.");
        ptrSamples.add(obj, currentSample);

        write(currentSample, s.ptr);

        write(currentSample, sot);
        write(currentSample, s.alloc_size);

        AvmAssertMsg((uintptr_t)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.");
        currentSample = pos;

        return s.id;
    }

    void Sampler::recordDeallocationSample(const void* item, uint64_t size)
    {
        AvmAssertMsg(sampling(), "How did we get here if sampling is disabled?");
        AvmAssert(item != 0);
        // recordDeallocationSample doesn't honor the samplingNow flag
        // this is to avoid dropping deleted object samples when sampling is paused.
        uint64_t uid = uids.get(item);
        // If we didn't find a UID then this wasn't memory that the sampler knew was allocated
        if(uid && sampleSpaceCheck(false)) {


//          if( !uid )
//              uid = (uint64_t)-1;

            writeRawSample(DELETED_OBJECT_SAMPLE);
            write(currentSample, uid);
            write(currentSample, size);

            numSamples++;

            AvmAssertMsg((uintptr_t)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.");
        }

        // Nuke the ptr in the sample stream for the newobject sample
        if( samples )
        {

        uint8_t* oldptr = 0;
        if( (oldptr = (uint8_t*)ptrSamples.get(item)) != 0 )
        {
#ifdef _DEBUG
                void* oldval = 0;
                read(oldptr, oldval);
                AvmAssertMsg(oldval==item, "Sample stream corrupt, dealloc doesn't point to correct address");
                rewind(oldptr, sizeof(void*));
#endif
            write(oldptr, (void*)0);
            ptrSamples.remove(item);
        }
        }
        if(uid)
            uids.remove(item);
    }

    void Sampler::clearSamples()
    {
        //samples->free();
        currentSample = samples;
        ptrSamples.clear();
        numSamples = 0;
        lastSampleCheckMicros = 0;

        // Increment the sample buffer id, so that next time
        // a sample iterator tries to get the next sample
        // it will automatically get invalidated.
        // This is needed here even though the actual buffer
        // is not disposed, but the contents of the buffer
        // is garbaged and the sample iterator might create invalid
        // ScriptObject pointers.
        ++sampleBufferId;
    }

    void Sampler::startSampling()
    {
        if (!_sampling || samplingNow)
            return;

        if (!currentSample)
        {
            int megs = (callback != NULL) ? 16 : 256;
            while(!currentSample && megs > 0) {
                samples_size = megs*1024*1024;
                currentSample = samples = (uint8_t*)VMPI_alloc(samples_size);
                megs >>= 1;
            }
            if(!currentSample) {
                _sampling = autoStartSampling = false;
                return;
            }
        }

        init(_sampling, autoStartSampling);

        samplingNow = true;
        lastSampleCheckMicros = nowMicros();
        if(timerHandle == 0)
            timerHandle = OSDep::startIntWriteTimer(SAMPLE_FREQUENCY_MILLIS, &takeSample);
    }

    void Sampler::pauseSampling()
    {
        if (!_sampling || !samplingNow)
            return;
        samplingNow = false;
    }

    void Sampler::sampleInternalAllocs(bool b)
    {
        samplingAllAllocs = b;
    }

    void Sampler::setCallback(ScriptObject* callback)
    {
        (void)callback;
        // FIXME: bug 614529
        //this->callback = callback;
    }

    void Sampler::stopSampling()
    {
        if (!_sampling)
            return;

        if( samples )
            VMPI_free(samples);
        samples = 0;
        samples_size = 0;

        if(timerHandle != 0) {
            OSDep::stopTimer(timerHandle);
            timerHandle = 0;
        }

        samplingNow = false;
        numSamples = 0;
        lastSampleCheckMicros = 0;
        currentSample = NULL;

        // Increment the sample buffer id, so that next time
        // a sample iterator tries to get the next sample
        // it will automatically get invalidated.
        ++sampleBufferId;
    }

    void Sampler::initSampling()
    {
        if (!_sampling)
            return;

        // prime fake function table

        createFakeFunction("XML");
        createFakeFunction("Array");
        createFakeFunction("Date");

        createFakeFunction("[mark]");
        createFakeFunction("[sweep]");
        createFakeFunction("[reap]");
        createFakeFunction("[generate]");
        createFakeFunction("[verify]");
        createFakeFunction("[newclass]");

        createFakeFunction("[activation-object]");

        if(autoStartSampling) {
            startSampling();
        }
        return;
    }

    void Sampler::createFakeFunction(const char *name)
    {
        if (!_sampling)
            return;

        Stringp s = core->internConstantStringLatin1(name);
        // save it in fakeMethodNames just to be sure it isn't cleared from the intern-name list.
        if (fakeMethodNames.indexOf(s) < 0)
            fakeMethodNames.add(s);
    }

    Stringp Sampler::getFakeFunctionName(const char* name)
    {
        // this can't make any allocations, it's called from sensitive areas (like from
        // the GC marking routines).  For one we'll recurse but also GC state can get messed
        // up if for instance the allocation triggers a collection
        Stringp name_str = core->findInternedString(name, (int)VMPI_strlen(name));
        if (name_str != NULL)
        {
            sampleCheck();
        }
        return name_str;
    }

    /* sample data has pointers need to scan */
    void Sampler::presweep()
    {
        uint32_t num;
        uint8_t *p = getSamples(num);

        MMgc::GC * const gc = core->gc;

        for(uint32_t i=0; i < num ; i++)
        {
            Sample s;
            readSample(p, s);
            if(s.sampleType == NEW_OBJECT_SAMPLE) {
                // keep all weak refs and type's live, in postsweep we'll erase our weak refs
                // to objects that were finalized.  we can't nuke them here b/c pushing the
                // types could cause currently unmarked things to become live
                void *ptr = sotGetGCPointer(s.sot);
                if (ptr != NULL && !GC::GetMark(ptr))
                {
                    // NOTE that Push_GCObject_MayFail can fail due to mark stack overflow in tight memory
                    // situations.  It seems hard to compensate for it here, so we don't.  The most credible
                    // workaround is likely to test the overflow flag at the end of presweep and disable
                    // the sampler if it is set.
                    gc->Push_GCObject_MayFail(ptr);
                }
            }
#ifdef _DEBUG
#define NULL_OR_MARKED(_x) GCAssert(_x == NULL || GC::GetMark(_x))
            if(s.sampleType != DELETED_OBJECT_SAMPLE)
            {
                StackTrace::Element *e = (StackTrace::Element*)s.stack.trace;
                for(uint32_t i=0; i < s.stack.depth; i++, e++)
                {
                    NULL_OR_MARKED(e->fakename());
                    NULL_OR_MARKED(e->filename());
                }
            }
#endif
        }

        if (gc->GetMarkStackOverflow())
        {
            // see the comment above
            stopSampling();
        }
    }

    void Sampler::postsweep()
    {
    }

}
#endif // DEBUGGER



#ifdef VMCFG_TELEMETRY_SAMPLER

/**
 * Telemetry Based Sampler
 *
 * This is the new telemetry based sampler which works on Release builds.
 * It uses the MethodFrame stack to obtain the stack information, and sends
 * samples using Telemetry.
 */

// The sampler timer interval in microseconds
const int SAMPLER_TIMER_INTERVAL = 1000;

namespace avmplus {

    /*
     * Class "SamplerTimerClient" gathers tick statistics, including
     * distribution of tick intervals, min/max interval, and the exact timestamp of each tick.
     */

    // Call this function before starting our VMPI timer.
    void TelemetrySampler::SamplerTimerClient::start(telemetry::ITelemetry* pTelemetry, TelemetrySampler* pSampler) {
        m_totalTicks = 0;
        m_nextTickTimeIndex = 0;
        m_tickTimes[m_nextTickTimeIndex++] = pTelemetry->GetElapsedTime();
        m_minInterval = ULLONG_MAX;
        m_maxIntervalSinceLastFlush = 0;
        VMPI_memset(m_timerIntervalCounts, 0, INTERVAL_TABLE_SIZE);
        m_pTelemetry = pTelemetry;
        m_pSampler = pSampler;
    }

    // This function is called on each tick.
    void TelemetrySampler::SamplerTimerClient::tick() {
        VMPI_recursiveMutexLock(&m_pSampler->m_counterLock);

        // increment the tick counter. this tells the AS interpreter that it's time to take a sample.
        m_pSampler->m_core->sampleTicks += 1;

        // increment total number of ticks
        m_totalTicks++;

        // calculate the interval between the last tick and now.
        uint64_t now = m_pTelemetry->GetElapsedTime();
        uint64_t thisInterval = now - m_tickTimes[m_nextTickTimeIndex - 1]; // in microseconds

        // record the timestamp for this tick. the timestamps are kept
        // in a circular buffer 'm_tickTimes'.
        if (m_nextTickTimeIndex == TICK_TIME_TABLE_SIZE)
            m_nextTickTimeIndex = 0;
        m_tickTimes[m_nextTickTimeIndex++] = now;

        // update the min and max intervals
        if(thisInterval < m_minInterval)
            m_minInterval = thisInterval;
        if (thisInterval > m_maxIntervalSinceLastFlush)
            m_maxIntervalSinceLastFlush = thisInterval;

        // Increment the entry in m_timerIntervalCounts corresponding to "thisInterval".
        // m_timerIntervalCounts[k] is a count of how many times the interval happened to be k microseconds.
        // These counters are used later on in calculateMedianTimerInterval().
        unsigned int intervalIndex =
            (thisInterval < INTERVAL_TABLE_SIZE) ? (unsigned int)thisInterval : (INTERVAL_TABLE_SIZE - 1);
        m_timerIntervalCounts[intervalIndex] += 1;

        VMPI_recursiveMutexUnlock(&m_pSampler->m_counterLock);
    }

    // If we have fewer than this many ticks, we won't actually calculate a median,
    // so that the calculations are not unduly influenced by early fluctuations.
    static const uint64_t MIN_TICKS_NEEDED_FOR_RELIABLE_MEDIAN_CALCULATION = 100;

    // Calculates the median value of all the tick intervals that have occurred since the ticker was started.
    uint64_t TelemetrySampler::SamplerTimerClient::calculateMedianTimerInterval() {
        if(m_totalTicks <= MIN_TICKS_NEEDED_FOR_RELIABLE_MEDIAN_CALCULATION) {
            // there is not enough data to calculate a reliable result. Just return the nominal tick interval.
            return SAMPLER_TIMER_INTERVAL;
        }

        // m_timerIntervalCounts[k] is a count of how many times the interval happened to be k microseconds.
        // To find the median value, we'll iterate over the array accumulating the sum of
        // of the array items. We stop iterating when the sum >= 1/2 the total number of items. The index
        // we stopped at is the median value.
        //
        // In other words, the following code finds the lowest value value N such that
        //
        //      sum(m_timerIntervalCounts[j]) for j=0...N is >= 1/2 the total number of items.
        //
        // We optimize the algorithm by starting at index=m_minInterval rather than at index=0, because we know
        // that there are no non-zero items in the array below index=m_minInterval.
        //
        // Interval values tend to cluster around the nominal value "SAMPLER_TIMER_INTERVAL", so we probaby
        // will go around the loop only a few dozen times.
        uint64_t accumulator = 0;
        uint64_t halfTotalTicks = m_totalTicks / 2;
        uint64_t index = m_minInterval;
        // We know that this loop will exit, and that index will never go off the end of
        // m_timerIntervalCounts, because functions tick() and start() guarantee that
        // 1. m_timerIntervalCounts[k] >= 0 for all k
        // 2. sum(m_timerIntervalCounts[]) == m_totalTicks
        //
        while(accumulator < halfTotalTicks) {
            accumulator += m_timerIntervalCounts[index++];
        }
        return index - 1;
    }

    /*
     * Class "TelemetrySampler"
     */

    TelemetrySampler::TelemetrySampler(AvmCore* core)
    {
        m_core = core;
        m_timerId = NULL;
        m_samplesBuffer = NULL;
        m_started = false;
        m_numMappedMethods = 1;
        m_lastReportedMedianInterval = 0;
        m_lastFlushTime = 0;
        m_lastFlushTicks = 0;
        m_telemetry = m_core->getTelemetry();

        VMPI_recursiveMutexInit(&m_counterLock);
    }

    TelemetrySampler::~TelemetrySampler()
    {
        stop();
		VMPI_recursiveMutexDestroy(&m_counterLock);
    }

    void TelemetrySampler::start()
    {
        m_telemetry = m_core->getTelemetry();
        if (m_core->samplerEnabled && m_telemetry && !m_started) {
            m_samplesBuffer = (SamplesBuffer *) VMPI_alloc(sizeof(SamplesBuffer));
            m_samplesBuffer->nSamples = 0;
            m_samplesBuffer->nTickTimes = 0;
            m_lastReportedMedianInterval = 0;
            m_timerClient.start(m_telemetry, this);
            m_timerId = VMPI_startTimer(SAMPLER_TIMER_INTERVAL, &m_timerClient);
            m_started = true;
        }
    }

    void TelemetrySampler::stop()
    {
        if (m_started) {
            VMPI_stopTimer(m_timerId);
            m_timerId = NULL;
            m_started = false;
            VMPI_free(m_samplesBuffer);
            m_samplesBuffer = NULL;
        }
    }

    // Find out if the current method frame stack is empty
    bool TelemetrySampler::isMethodFrameStackEmpty() {
        for (MethodFrame* frame = m_core->currentMethodFrame; frame != NULL; frame = frame->next) {
            MethodEnv* env = frame->env();
            if (env && env->method) {
                return false;
            }
        }
        return true;
    }

    // Copy the current methodFrame stack into 'outFrameBuffer'. Returns the number of stack frames.
    unsigned int TelemetrySampler::takeStackSample(sample_frame_t* outFrameBuffer)
    {
        unsigned int nFramesWritten = 0;

        for (MethodFrame* curFrame = m_core->currentMethodFrame;
             curFrame != NULL;
             curFrame = curFrame->next) {
            MethodEnv* env = curFrame->env();
            if (env && env->method) {
                if (nFramesWritten == Sample::SAMPLE_MAX_STACK_DEPTH) {
                    // more stack frames than SAMPLE_MAX_STACK_DEPTH,
                    // return 1 greater than the max length so we know there is more..
                    return ++nFramesWritten;
                } else {
                    outFrameBuffer[nFramesWritten++] = env->method;
                }
            }
        }

        return nFramesWritten;
    }

    // Find out the function name corresponding to a given stack frame.
    Stringp TelemetrySampler::sampleFrameToString(sample_frame_t frame)
    {
        return frame->getMethodName();
    }

    // Capture one sample into m_samplesBuffer
    // Note: we do things in an awkward order in order to minimize the time spent with the mutex locked,
    // to minimize our effect on the timing of the ticker.
    void TelemetrySampler::takeSample()
    {
        AvmAssert(m_samplesBuffer != NULL);

        if (isMethodFrameStackEmpty()) {
            // The actionscript stack is empty. We will not bother taking a sample.
            VMPI_recursiveMutexLock(&m_counterLock);
            m_core->sampleTicks = 0;
            VMPI_recursiveMutexUnlock(&m_counterLock);
            return;
        }

        // Lock out the ticker thread while we capture the ticker's data...
        VMPI_recursiveMutexLock(&m_counterLock);

        // ... capture the tick count
        unsigned int nTicks = m_core->sampleTicks;
        m_core->sampleTicks = 0;
        AvmAssert(nTicks > 0);

        // ... figure out how many tick times we need to capture
        unsigned int numTickTimes = (nTicks <= SamplerTimerClient::TICK_TIME_TABLE_SIZE) ? nTicks : SamplerTimerClient::TICK_TIME_TABLE_SIZE;

        if (numTickTimes + m_samplesBuffer->nTickTimes > SamplesBuffer::TICK_TIMES_BUFFER_SIZE) {
            // we don't have enough room to capture all the tick times. Do a flush.

            // unlock the mutex while we flush, in case we take a long time, we don't want to slow down the ticker.
            VMPI_recursiveMutexUnlock(&m_counterLock);
            flushSamples();
            VMPI_recursiveMutexLock(&m_counterLock);

            // update the captured data in case a tick happened during the flush
            nTicks += m_core->sampleTicks;
            m_core->sampleTicks = 0;
            numTickTimes = (nTicks <= SamplerTimerClient::TICK_TIME_TABLE_SIZE) ? nTicks : SamplerTimerClient::TICK_TIME_TABLE_SIZE;
        }

        // ... capture the tick times
        uint32_t nextIndex =  m_timerClient.m_nextTickTimeIndex;
        AvmAssert(nextIndex <= SamplerTimerClient::TICK_TIME_TABLE_SIZE);
        AvmAssert(numTickTimes > 0 && numTickTimes <= SamplerTimerClient::TICK_TIME_TABLE_SIZE);
        AvmAssert(numTickTimes <= SamplesBuffer::TICK_TIMES_BUFFER_SIZE - m_samplesBuffer->nTickTimes);
        if (numTickTimes <= nextIndex) {
            // the stuff we want is one contiguous chunk
            VMPI_memcpy(&m_samplesBuffer->tickTimes[m_samplesBuffer->nTickTimes], &m_timerClient.m_tickTimes[nextIndex - numTickTimes],
                        sizeof(uint64_t) * numTickTimes);
        } else {
            // the stuff we want wraps around from the end of the buffer to beginning of the buffer.
            // first, grab the older stuff at the end of the buffer.
            VMPI_memcpy(&m_samplesBuffer->tickTimes[m_samplesBuffer->nTickTimes],
                        &m_timerClient.m_tickTimes[SamplerTimerClient::TICK_TIME_TABLE_SIZE - (numTickTimes - nextIndex)],
                        sizeof(uint64_t) * (numTickTimes - nextIndex));
            // now grab the newer stuff at the beginning of the buffer.
            VMPI_memcpy(&m_samplesBuffer->tickTimes[m_samplesBuffer->nTickTimes + numTickTimes - nextIndex], &m_timerClient.m_tickTimes[0],
                        sizeof(uint64_t) * nextIndex);
        }
        m_samplesBuffer->nTickTimes += numTickTimes;

        // We're finished capturing the ticker's data. Unlock the mutex.
        VMPI_recursiveMutexUnlock(&m_counterLock);

        // Find the next empty slot in m_samplesBuffer.
        Sample* curSample = m_samplesBuffer->samples + m_samplesBuffer->nSamples;
        m_samplesBuffer->nSamples += 1;

        // Capture the current actionscript stack
        curSample->nFrames = takeStackSample(curSample->frames);
        curSample->nTicks = nTicks;
        AvmAssert(curSample->nFrames > 0);
        curSample->timestamp = m_telemetry->GetElapsedTime();

        // If our sample buffer is full, force a flush
        if (m_samplesBuffer->nSamples == SamplesBuffer::SAMPLES_BUFFER_SIZE) {
            flushSamples();
        }
    }

    // Reports all the data we've accumlated in m_samplesBuffer.
    void TelemetrySampler::flushSamples()
    {
        // if we haven't created our samples buffer yet or aren't initialized, just return
        // also, if we have no samples to send, just return
        if (m_samplesBuffer == NULL || !m_core || !m_core->samplerEnabled || !m_samplesBuffer->nSamples || !m_telemetry)
            return;

        avmplus::StringBuffer methodNameMapBuffer(m_core);

        // we use this index to step through m_samplesBuffer->tickTimes
        unsigned int nextTickTimeIndex = 0;

        // For each sample...
        for (unsigned int i = 0; i < m_samplesBuffer->nSamples; i++) {

            Sample* sample = m_samplesBuffer->samples + i;

            // Report the time at which the sample was taken
            TELEMETRY_UINT64(m_telemetry, ".sampler.nextSampleTime", sample->timestamp);

            // Report the number of ticks the sample represents
            TELEMETRY_UINT32(m_telemetry, ".sampler.nextSampleTicks", sample->nTicks);

            // Report the exact time of each tick
            unsigned int numTickTimes = (sample->nTicks <= SamplerTimerClient::TICK_TIME_TABLE_SIZE) ? sample->nTicks : SamplerTimerClient::TICK_TIME_TABLE_SIZE;
            for (unsigned int k = 0; k < numTickTimes; k++) {
                TELEMETRY_UINT64(m_telemetry, ".sampler.nextSampleTickTime", m_samplesBuffer->tickTimes[nextTickTimeIndex++]);
            }

            // Get the stack array IDs and new method map names
            uint32_t* stackArray = mmfx_new_array(uint32_t, sample->nFrames);
            getSampleStackArray(sample, stackArray, methodNameMapBuffer);

            // Report the stackframes
            if (m_telemetry->IsActive())
                m_telemetry->WriteValue(".sampler.sample", stackArray, sample->nFrames);

            // Delete the stack array
            mmfx_delete_array(stackArray);
        }

        // Clear out the samples buffer, now that we've reported all the data.
        m_samplesBuffer->nSamples = 0;
        m_samplesBuffer->nTickTimes = 0;

        // Report any new mappings from method ID to method name
        if (methodNameMapBuffer.length() > 0) {
            TELEMETRY_STRING(m_telemetry, ".sampler.methodNameMap", methodNameMapBuffer.c_str());
        }

        // Report tick interval statistics...

        // ... the median tick interval
        uint64_t interval = m_timerClient.calculateMedianTimerInterval();
        if (interval > 0 && interval != m_lastReportedMedianInterval) {
            // only send the data if it is different from last time
            TELEMETRY_UINT64(m_telemetry, ".sampler.medianInterval", interval);
            m_lastReportedMedianInterval = interval;
        }

        // ... the number of ticks since the last flush
        uint64_t numberOfTicksSinceLastFlush = m_timerClient.m_totalTicks - m_lastFlushTicks;
        m_lastFlushTicks = m_timerClient.m_totalTicks;

        // ... the number of microseconds since the last flush
        uint64_t now = m_telemetry->GetElapsedTime();
        uint64_t microSecondsSinceLastFlush = now - m_lastFlushTime;
        m_lastFlushTime = now;

        // ... the average interval since the last flush
        uint64_t averageIntervalSinceLastFlush = numberOfTicksSinceLastFlush > 0 ? microSecondsSinceLastFlush / numberOfTicksSinceLastFlush : 0;
        TELEMETRY_UINT64(m_telemetry, ".sampler.averageInterval", averageIntervalSinceLastFlush);

        // ... the longest interval since the last flush
        TELEMETRY_UINT64(m_telemetry, ".sampler.maxInterval", m_timerClient.m_maxIntervalSinceLastFlush);
        m_timerClient.m_maxIntervalSinceLastFlush = 0;
    }

    void TelemetrySampler::getSampleStackArray(Sample* sample, uint32_t* stackArray, avmplus::StringBuffer& methodNameMapBuffer)
    {
        // In 'stackArray', gather the ids of all the methods in the stack.
        
        assert(stackArray != NULL);
        
        unsigned int methodId;
        sample_frame_t frame;

        // For each frame on the stack...
        int numFrames = (sample->nFrames > Sample::SAMPLE_MAX_STACK_DEPTH) ? Sample::SAMPLE_MAX_STACK_DEPTH : sample->nFrames;
        for (int j = 0; j < numFrames; j++) {
            frame = sample->frames[j];
            methodId = m_mappedMethods.get(frame);
            if (methodId == 0) {
                methodId = m_numMappedMethods++;

                // add to the method name map
                methodNameMapBuffer << methodId;
                methodNameMapBuffer << "=";
                methodNameMapBuffer << StUTF8String(sampleFrameToString(frame)).c_str();
                methodNameMapBuffer << ",";

                m_mappedMethods.add(frame, methodId);
            }

            stackArray[j] = methodId;
        }

        if (sample->nFrames > Sample::SAMPLE_MAX_STACK_DEPTH) {
            // more frames than we allow, send an ID as the last frame so
            // the client can identify the sampler stack overflow condition.
            stackArray[Sample::SAMPLE_MAX_STACK_DEPTH] = Sample::SAMPLER_STACK_OVERFLOW_ID;
        }
    }

} // namespace avmplus

#endif // VMCFG_TELEMETRY_SAMPLER
