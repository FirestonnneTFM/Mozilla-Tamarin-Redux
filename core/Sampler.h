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

    // The abstract interface for a memory sampler. Use the AttachSampler() method to attach an
    // IMemorySampler based class to MMgc for getting called back when allocations/deallocations occur. 
    class IMemorySampler
    {
    public:
        // Called when a new auxiliary memory allocation occurs.
        virtual void recordAllocation(const void *item, size_t size) = 0;

        // Called when a memory deallocation occurs.
        virtual void recordDeallocation(const void *item, size_t size) = 0;

        // Called when a new ScriptObject based object has been allocated.
        virtual void recordNewObjectAllocation(AvmPlusScriptableObject *obj, avmplus::SamplerObjectType sot) = 0;
    };

    // Set the current memory sampler. A memory sampler is tied to a particular GC/core pair.    
    void AttachSampler(IMemorySampler* sampler);
    
    // Get the current memory sampler.
    IMemorySampler* GetSampler();

    class Sampler : public MMgc::GCRoot, public IMemorySampler
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

        void recordAllocation(const void *item, size_t size);
        void recordDeallocation(const void *item, size_t size);
        void recordNewObjectAllocation(AvmPlusScriptableObject *obj, avmplus::SamplerObjectType sot);
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

    /**
     * Telemetry Based Sampler
     *
     * This is the new telemetry based sampler which works on Release builds.
     * It uses the MethodFrame stack to obtain the stack information, and sends
     * samples using Telemetry. The sampler is driven by a periodic timer
     * provided by the VMPI_Timer feature of VMPI.h. Whenever this timer
     * fires (or "ticks"), two things happen:
     * - the variable m_core->sampleTicks gets incremented. A non-zero value in
     *   this variable informs the actionscript interpreter and JIT'ed code that
     *   it is time to take a sample, which is implemented in takeSample(). Samples
     *   are accumulated in a SamplesBuffer, and periodically flushed to an
     *   external client app via telemetry.
     * - the function SamplerTimerClient.tick() gets called. This collects
     *   statistics about the distribution of values of tick times. This information
     *   can be used by a client application to better analyze sampler results.
     */
    class TelemetrySampler
    {
    protected:
        // Each sample frame is just a MethodInfo ptr
        typedef MethodInfo* sample_frame_t;

        // Sample definition
        struct Sample
        {
            // The maximum stack depth the sampler will record. We don't need to handle much higher
            // than this because even when there is deep recursion, seeing the same stack repeated
            // over and over is not useful, this condition will be evident by sending the first
            // part of the stack. We send a stack overflow ID at the end so the client can identify
            // this condition.
            static const int SAMPLE_MAX_STACK_DEPTH = 128;
            static const uint32_t SAMPLER_STACK_OVERFLOW_ID = 0xFFFFFFFF;

            // the frames, i.e. the stack
            sample_frame_t frames[SAMPLE_MAX_STACK_DEPTH];

            // number of frames in the stack.
            // if we have exceeded SAMPLE_MAX_STACK_DEPTH for a particular stack,
            // this will equal SAMPLE_MAX_STACK_DEPTH + 1
            unsigned int nFrames;

            // how many ticks since the last sample
            unsigned int nTicks;

            // the time at which the sample was taken
            uint64_t timestamp;
        };

    private:
        // The buffer used to hold all samples, when it fills the samples
        // are flushed.
        struct SamplesBuffer
        {
            // An array of all the samples that have been collected by takeSample() and not
            // yet reported by flushSamples()
            static const int SAMPLES_BUFFER_SIZE = 1000;
            Sample          samples[SAMPLES_BUFFER_SIZE];
            unsigned int    nSamples;

            // There is one item in this array for each tick of each entry in 'samples'.
            static const int TICK_TIMES_BUFFER_SIZE = 10000;
            uint64_t        tickTimes[TICK_TIMES_BUFFER_SIZE];
            unsigned int    nTickTimes;
        };

        // The sampler's implementation of TimerClient. This object's tick() function
        // is invoked on every sampler tick, to collect statistics on tick timings.
        class SamplerTimerClient : public VMPI_TimerClient {
        public:
            // number of sampler ticks since the timer was started
            uint64_t    m_totalTicks;

            // the lowest interval value ever
            uint64_t    m_minInterval;

            // highest interval value since the last flush
            uint64_t    m_maxIntervalSinceLastFlush;

            // statistics on the distribution of interval times.
            // the k'th item in this array is a count of how many times the interval happened to be k microseconds
            static const uint32_t INTERVAL_TABLE_SIZE = 5000;
            uint64_t    m_timerIntervalCounts[INTERVAL_TABLE_SIZE];

            // the microsecond timestamp of the most recent ticks, stored as a circular buffer.
            static const uint32_t TICK_TIME_TABLE_SIZE = 10000;
            uint64_t    m_tickTimes[TICK_TIME_TABLE_SIZE];

            // next available spot in m_tickTimes
            uint32_t    m_nextTickTimeIndex;

            // Initializes our data. This must be called before any calls to tick() or calculateMedianTimerInterval().
            void start(telemetry::ITelemetry* pTelemetry, TelemetrySampler* pSampler);

            // This function gets called by the ticker on each tick
            void tick();

            // Compute the median tick interval since the timer was started
            uint64_t calculateMedianTimerInterval();

        private:
            telemetry::ITelemetry*  m_pTelemetry;
            TelemetrySampler*       m_pSampler;
        };

    public:
        TelemetrySampler(AvmCore* core);
        virtual ~TelemetrySampler();

        // Take a stack sample
        virtual void takeSample();

        // Flush the samples - send them to our client via telemetry
        virtual void flushSamples();

        // Starts up the sampler, will only start if sampler currently is enabled
        virtual void start();

        // Stop sampling, performs cleanup
        virtual void stop();

    protected:
        // Copy the current method frame stack to outFrameBuffer
        unsigned int takeStackSample(sample_frame_t* outFrameBuffer);

        // Find out if the method frame stack is currently empty
        bool isMethodFrameStackEmpty();

        // Get the string representation of a stack frame. This is typically a fully-qualified function name.
        Stringp sampleFrameToString(sample_frame_t frame);

        // Get the stack array and method names for the given sample. The stack array is returned in the buffer
        // passed in to stackArray, with a method ID in the array corresponding to each stack frame in sample. 
        // Each method has a unique method ID, if a method appears more than once in the stack, the same method
        // ID is used. The method name for each stack frame is added to methodNameMapBuffer if that method name 
        // has not already been mapped. The buffer passed in to stackArray must be large enough for the number
        // of samples in sample, as determined by sample->nFrames.
        void getSampleStackArray(Sample* sample, uint32_t* stackArray, avmplus::StringBuffer& methodNameMapBuffer);

        AvmCore* m_core; // the core, one sampler per core
        telemetry::ITelemetry* m_telemetry; // instance of telemetry

    private:
        // Where we keep all the samples
        SamplesBuffer* m_samplesBuffer;

        // Whether the sampler is started or stopped
        bool m_started;

        // A lock to control access to the data shared by tick() (on a timer thread) and takeSample() (on the AS execution thread)
        vmpi_mutex_t m_counterLock;

        // The id of the VMPI timer that generates our ticks
        uintptr_t m_timerId;

        // The last median interval value we reported. We only report this value when it changes.
        uint64_t m_lastReportedMedianInterval;

        // The time when we last flushed
        uint64_t m_lastFlushTime;

        // The value of "totalTicks" last time we flushed
        uint64_t m_lastFlushTicks;

        // The object that receives tick() calls from our VMPI timer, and records information about tick intervals and times.
        SamplerTimerClient m_timerClient;

        // map of <sample_frame_t, unsigned int> key/vaue pairs for the methods we have already mapped and a unique id for each one
        MMgc::GCHashtableBase<unsigned int, MMgc::GCHashtableKeyHandler, MMgc::GCHashtableAllocHandler_VMPI> m_mappedMethods;
        unsigned int m_numMappedMethods;
    };

#endif // VMCFG_TELEMETRY_SAMPLER

}
#endif // __avmplus_Sampler__
