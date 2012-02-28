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

#ifndef __avmplus_Sampler__
#define __avmplus_Sampler__

#ifdef VMCFG_TELEMETRY_SAMPLER
namespace telemetry
{
    class ITelemetry;
}
#endif

namespace avmplus
{
#ifdef DEBUGGER

    //
    // Note that "SamplerObjectType" is atomlike, but is NOT an Atom:
    //
    // -- the lower three bits are SamplerObjectTypeKind
    // -- if kind is kSOT_Object, upper bits are a VTable*
    // -- if kind is kSOT_String or kSOT_Namespace, upper bits are a Toplevel*
    // -- if kind is kSOT_Empty, upper bits are zero
    //
    // note that for efficiency, the Toplevel* in the String/Namespace case is filled in lazily downstream
    // (via sotSetToplevel), to avoid having String/Namespace ctors look up the proper Toplevel
    // when not sampling.
    //
    // To reinforce the fact that this Isn't An Atom, it's now its own opaque type, with
    // lovely little accessors. Please use them now, rather than casting to intptr and
    // dancing on the bits directly.
    //

    enum SamplerObjectTypeKind
    {
        kSOT_Object = 0,
        kSOT_String = 1,
        kSOT_Namespace = 2,
        kSOT_Empty = 3
    };

    REALLY_INLINE SamplerObjectType sotNamespace()
    {
        // start with Toplevel == NULL, filled in implicitly later
        return SamplerObjectType(kSOT_Namespace);
    }

    REALLY_INLINE SamplerObjectType sotString()
    {
        // start with Toplevel == NULL, filled in implicitly later
        return SamplerObjectType(kSOT_String);
    }

    REALLY_INLINE SamplerObjectType sotEmpty()
    {
        return SamplerObjectType(kSOT_Empty);
    }

    REALLY_INLINE SamplerObjectType sotObject(VTable* vt)
    {
        MMGC_STATIC_ASSERT(kSOT_Object == 0);
        return SamplerObjectType(uintptr_t(vt) | uintptr_t(kSOT_Object));
    }

    REALLY_INLINE SamplerObjectTypeKind sotGetKind(SamplerObjectType sot)
    {
        return SamplerObjectTypeKind(uintptr_t(sot) & 7);
    }

    REALLY_INLINE VTable* sotGetVTable(SamplerObjectType sot)
    {
        MMGC_STATIC_ASSERT(kSOT_Object == 0);
        AvmAssert(sotGetKind(sot) == kSOT_Object);
        return (VTable*)(sot);
    }

    REALLY_INLINE Toplevel* sotGetToplevel(SamplerObjectType sot)
    {
        AvmAssert(sotGetKind(sot) == kSOT_String || sotGetKind(sot) == kSOT_Namespace);
        return (Toplevel*)(uintptr_t(sot) & ~7);
    }

    REALLY_INLINE SamplerObjectType sotSetToplevel(SamplerObjectType sot, Toplevel* toplevel)
    {
        SamplerObjectTypeKind const sk = sotGetKind(sot);
        if (sk == kSOT_String || sk == kSOT_Namespace)
        {
            sot = SamplerObjectType(uintptr_t(toplevel) | uintptr_t(sk));
        }
        return sot;
    }

    // return value will be a VTable* or a Toplevel* -- intended only for use in adding GC work items
    REALLY_INLINE void* sotGetGCPointer(SamplerObjectType sot)
    {
        return (void*)(uintptr_t(sot) & ~7);
    }

    // This structure is used to read/write data to the sample stream.
    // The fields are written out to the sample stream as they are defined here.
    struct Sample
    {
        uint64_t micros;
        uint32_t sampleType;
        union {
            // not filled in for sampleType==DELETED_OBJECT_SAMPLE
            struct {
                // Number of StackTraceElements in the trace
                uint32_t depth;
                // Beginning of an array of StackTraceElement.  Basically, an MethodInfo*, Stringp, Stringp, uint32_t for each entry.
                void *trace;
            } stack;
            // deleted object size record, instead of stack
            uint64_t size;
        };
        // filled for DELETED_OBJECT_SAMPLE + NEW_OBJECT_SAMPLE
        uint64_t id;

        // Following three fields are only filled in for sampleType==NEW_OBJECT_SAMPLE or NEW_AUX_SAMPLE
        // They are not present in the sample stream for other sample types
        SamplerObjectType sot;
        void *ptr;
        uint64_t alloc_size; // size for new mem sample
    };

    class Sampler : public MMgc::GCRoot
    {
    public:
        Sampler(AvmCore*);
        virtual ~Sampler();

        enum SampleType
        {
            RAW_SAMPLE=0x55555555,
            NEW_OBJECT_SAMPLE=0xaaaaaaaa,
            DELETED_OBJECT_SAMPLE=0xdddddddd,
            NEW_AUX_SAMPLE=0xeeeeeeee
        };

        enum { SAMPLE_FREQUENCY_MILLIS = 1 };

        // should use opaque Cursor type instead of uint8_t*
        uint8_t *getSamples(uint32_t &num);
        void readSample(uint8_t *&p, Sample &s);

        void init(bool sampling, bool autoStart);
        void sampleCheck() { if(takeSample) sample(); }

        uint64_t recordAllocationInfo(AvmPlusScriptableObject *obj, SamplerObjectType sot);
        uint64_t recordAllocationSample(const void* item, uint64_t size, bool callback_ok = true, bool forceWrite = false);
        void recordDeallocationSample(const void* item, uint64_t size);

        virtual void startSampling();
        virtual void stopSampling();
        virtual void clearSamples();
        virtual void pauseSampling();

        void sampleInternalAllocs(bool b);

        void setCallback(ScriptObject* callback);


        // called by VM after initBuiltin's
        void initSampling();

        void createFakeFunction(const char *name);
        Stringp getFakeFunctionName(const char* name);

        void presweep();
        void postsweep();

        inline uint32_t sampleCount() const { return numSamples; }
        inline bool activelySampling() { return samplingNow; }
        inline bool sampling() const { return _sampling; }
        inline uint64_t getSampleBufferId() const { return sampleBufferId; }

    private:

        void sample();

        void rewind(uint8_t*&b, uint32_t amount)
        {
            b -= amount;
        }

        int sampleSpaceCheck(bool callback_ok = true);

        // sampleTimeMicros is the timestamp you want to have written to the sample,
        // or 0 to use the current time.
        void writeRawSample(SampleType sampleType, uint64_t sampleTimeMicros = 0);

        // Returns the current time, as it should be written into samples.
        static uint64_t nowMicros();

    // ------------------------ DATA SECTION BEGIN
    public:
        VTable*             sampleIteratorVTable;
        VTable*             slotIteratorVTable;
    protected:
        AvmCore*            core;
    private:
        RCList<String>      fakeMethodNames;
        uint64_t            allocId;
        uint64_t            sampleBufferId;
        uint8_t*            samples;
        uint8_t*            currentSample;
        uint8_t*            lastAllocSample;
        uint64_t            lastSampleCheckMicros; // the last time we considered writing a timer sample
        GCMember<ScriptObject> callback;
        uintptr_t           timerHandle;
        MMgc::GCHashtableBase<uint64_t,MMgc::GCHashtableKeyHandler,MMgc::GCHashtableAllocHandler_VMPI>      uids;       // important to use the VMPI variant for non-MMGC-based memory allocation.
        MMgc::GCHashtable_VMPI      ptrSamples; // important to use the VMPI variant for non-MMGC-based memory allocation.
        volatile int32_t    takeSample;
        uint32_t            numSamples;
        uint32_t            samples_size;
        bool                samplingNow;
        bool                samplingAllAllocs;
        bool                runningCallback;
        bool                autoStartSampling;  // if true we call startSampling as early as possible during startup
        bool                _sampling;          // are we sampling at all
    // ------------------------ DATA SECTION END
    };

    #define SAMPLE_FRAME(_strp, _core)  avmplus::CallStackNode __fcsn((avmplus::AvmCore*)_core, _strp)
    #define SAMPLE_CHECK()              __fcsn.sampleCheck();

#else

    #define SAMPLE_FRAME(_x, _s)
    #define SAMPLE_CHECK()

#endif // DEBUGGER


#ifdef VMCFG_TELEMETRY_SAMPLER

    // Used for debug purposes to measure the performance of the sampler timer
    #undef REPORT_TOTAL_TICKS

    // The samples buffer size, we flush when we fill this buffer
    #define SAMPLES_BUFFER_SIZE     10000

    // The sampler timer interval in microseconds
    #define SAMPLER_TIMER_INTERVAL  1000

    // The maximum stack depth the sampler will send. We don't need to handle much higher
    // than this because even when there is deep recursion, seeing the same stack repeated
    // over and over is not useful, this condition will be evident by sending the first
    // part of the stack. We send a stack overflow ID at the end so the client can identify
    // this condition.
    #define SAMPLE_MAX_STACK_DEPTH  128
    const uint32_t SAMPLER_STACK_OVERFLOW_ID = 0xFFFFFFFF;

    /**
     * Telemetry Based Sampler
     *
     * This is the new telemetry based sampler which works on Release builds.
     * It uses the MethodFrame stack to obtain the stack information, and sends
     * samples using Telemetry.
     */
    class TelemetrySampler
    {
        // each sample frame is just a MethodInfo ptr
        typedef MethodInfo* sample_frame_t;

        // sample definition
        typedef struct Sample
        {
            // the frames, i.e. the stack
            sample_frame_t frames[SAMPLE_MAX_STACK_DEPTH];

            // number of frames in the stack.
            // if we have exceeded SAMPLE_MAX_STACK_DEPTH for a particular stack,
            // this will equal SAMPLE_MAX_STACK_DEPTH + 1
            unsigned int nFrames;

            // how many ticks since the last sample
            unsigned int nTicks;

            // the timestamp of this sample
            uint64_t timestamp;
        } Sample;

        // the buffer used to hold all samples, when it fills the samples
        // are flushed.
        typedef struct SamplesBuffer
        {
            Sample samples[SAMPLES_BUFFER_SIZE];
            unsigned int nSamples;
        #ifdef REPORT_TOTAL_TICKS
            unsigned int totalTicks;
        #endif
        } SamplesBuffer;

    public:
        TelemetrySampler(AvmCore* core);
        virtual ~TelemetrySampler();

        // take a stack sample
        void takeSample();

        // flush the samples - send them over the telemetry socket
        void flushSamples();

        // starts up the sampler, will only start is sampler currently is enabled
        void start();

        // stop sampling, performs cleanup
        void stop();
       
    private:
        unsigned int takeStackSample(sample_frame_t* outFrameBuffer);
        Stringp sampleFrameToString(sample_frame_t frame);

        AvmCore* m_core; // the core, one sampler per core
        telemetry::ITelemetry* m_telemetry; // instance of telemetry
        SamplesBuffer* m_samplesBuffer;
        bool m_timerStarted;
        vmpi_mutex_t m_counterLock;
        uintptr_t m_timerData;

        // map of <sample_frame_t, unsigned int> key/vaue pairs for the methods we have already mapped and a unique id for each one
        MMgc::GCHashtableBase<unsigned int, MMgc::GCHashtableKeyHandler, MMgc::GCHashtableAllocHandler_VMPI> m_mappedMethods;
        unsigned int m_numMappedMethods;
    };

#endif // VMCFG_TELEMETRY_SAMPLER

}
#endif // __avmplus_Sampler__
