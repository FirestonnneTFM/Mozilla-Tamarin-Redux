/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

#ifndef __avmplus_Isolate__
#define __avmplus_Isolate__

#include "FixedHeapUtils.h"
#include "Channels.h"

namespace avmplus
{

    template <class T>
    class IsolateEvent
    {
    public:
        uint32_t get_previousState();
        uint32_t get_currentState();
        int32_t source;
        IsolateEvent<T>* next;
        IsolateEvent(int32_t source, uint32_t previous, uint32_t current);
    private:
        uint32_t m_previousState;
        uint32_t m_currentState;

    };

    class IsolateEventListener;


    /*
     * Represents an isolate in various stages of its lifecycle. There's only one Isolate
     * object per isolate.
     */
    class Isolate : public vmbase::Runnable, public FixedHeapRCObject
    {
        friend class Aggregate;
        friend class WorkerObject;
        friend class PromiseHelperClass;
        
    public:

        static const int32_t INVALID_DESC = 0;
        static const int32_t POISON_DESC = 0x7FFFFFFF; // Max int32
        // Isolate objects are created by client code (e.g., the shell), before their AvmCores are instantiated.
        // If the isolate is successfully started, the Isolate object will delete itself upon isolate termination. 
        // Otherwise, the AS glue object (IsolateObject) destructor will delete Isolate objects that have not been
        // started or have failed.
        Isolate(int32_t desc, int32_t parentDesc, Aggregate* aggregate);

        static Isolate* newIsolate(int32_t desc, int32_t parentDesc, Aggregate* aggregate); 

        void initialize(AvmCore* core);

        virtual void run(); // Inherited from Runnable.

        void evalCodeBlobs(bool enter_debugger_on_launch);

        virtual void destroy();
        virtual ~Isolate();

        AvmCore* targetCore()
        {
            return m_core;
        }

        Aggregate* getAggregate() const
        {
            return m_aggregate;
        }

        bool isParentOf(Isolate* other)
        {
            AvmAssert(other != NULL);
            return other->parentDesc == desc;
        }

        void copyArguments(ArrayObject* array);

        // Returns false if array contains elements of unhandled type (i.e., not ByteArrayObjects)
        // If ba is null, copy from primordial.
        virtual bool copyByteCode(ByteArrayObject* array);
        
        bool failed();

        // the type of workerObject is not available here, overwrite.
        virtual ScriptObject* workerObject(Toplevel* toplevel) =  0;


        bool interrupt(); // false if already interrupted
        bool isInterrupted();
        // Last phase of termination.
        virtual bool isMemoryManagementShutDown(); 

        bool isPrimordial();
        
        void destroyListeners();

        virtual void eventLoop(Toplevel* toplevel);
        virtual bool processProxies(Toplevel* toplevel);
        virtual void registerPromiseOwner(int32_t existingProxyGID, Atom resolvedObject, Toplevel* toplevel);

        // keep in sync with constants in Worker
        enum State {
            NONE = 0, // sentinel
            NEW = 1, 
            STARTING = 2, 
            RUNNING = 3, 
            FINISHING = 4, 
            TERMINATED = 5, 
            FAILED = 6, 
            ABORTED = 7, 
            EXCEPTION = 8
        };


        typedef FixedHeapArray<char>* SharedPropertyNamep;

        class SharedPropertyMap: public FixedHeapHashTable<SharedPropertyNamep, ChannelItem*>
        {
        public:
            SharedPropertyMap();
            virtual ~SharedPropertyMap();
        protected:
            virtual uintptr_t HashKey(SharedPropertyNamep key) const;
            virtual bool KeysEqual(SharedPropertyNamep key1, const SharedPropertyNamep key2) const;
            virtual void DestroyItem(SharedPropertyNamep key, ChannelItem* value);
        };


    protected:
        FixedHeapArray<uint8_t> getByteCode() const
        { 
            return m_code.values[0]; 
        }
        virtual void stopRunLoop() 
        {
        }

        virtual void doRun() = 0;

        // *** data ***
    public:
        int32_t desc;
        int32_t parentDesc;

    protected:
        FixedHeapArray< FixedHeapArray<uint8_t> > m_code;
        vmbase::RecursiveMutex m_sharedPropertyLock; 
        

    protected: // Access moved to subclass
        FixedHeapArray<int32_t> m_additionalProxyInfo;
        // used to create new promises during promise info argument passing
        FixedHeapArray< FixedHeapRef<PromiseChannel> > m_additionalProxyChannels;
        int numAdditionalProxies;
        int additionalProxiesProcessed;
        FixedHeapArray<int32_t> m_emptyPromiseInfo;
        // used to initialize empty promises after their target has been resolved
        FixedHeapArray< FixedHeapRef<PromiseChannel> > m_emptyPromiseChannels;
        int numEmptyPromiseOwners;
        
    public: 
        // 
        // this structure is used to block threads
        // that call wait on the AS condition object
        // we keep this data here to allow us to 
        // interrupt any thread waiting on a condition
        // 
        struct WaitRecord
        {
            WaitRecord();
            virtual ~WaitRecord();
            vmpi_condvar_t condVar;
            vmpi_mutex_t privateMutex;
            bool isValid;
        };


        // used to initialize channels during worker startup
        FixedHeapArray< FixedHeapRef<PromiseChannel> > m_initialChannels;
        

        // gpid of the promise representing global scope - used during
        // initialization of the main isolate
        uint32_t m_global_gpid;

    private:
        virtual void releaseActiveResources();
        SharedPropertyMap m_properties;

    public:
        void setSharedProperty(const char* utf8String, int32_t len, ChannelItem* item);
        bool getSharedProperty(const char* utf8String, int32_t len, ChannelItem** outItem);
        virtual ChannelItem* makeChannelItem(Toplevel* toplevel, Atom atom);
        void setActiveWaitRecord(WaitRecord* record);
        bool signalActiveWaitRecord();
        virtual bool retryActiveWaitRecord();
		
		virtual void uncaughtErrorRaised ()	{}

    protected:
        void abortActiveWaitRecord();
        AvmCore* m_core;

    private:
        // when an isolate is blocked from ActionScript either due to a 
        // condition.wait or a mutex.lock this holds the active wait record
        // from that call. 
        vmbase::RecursiveMutex m_activeRecordLock;
        WaitRecord* m_activeWaitRecord;

        FixedHeapRef<Aggregate> m_aggregate;
        // VMThread objects have to be reclaimed after the threads
        // represented by them have terminated, but there's generally
        // no other thread trying to join() on the owner thread, so
        // there's no good point to delete the VMThread. As a result,
        // VMThread objects are retained and deleted
        // opportunistically.
        vmbase::VMThread* m_thread; 
        Isolate::State m_state;
        bool m_failed; // only accessed by the parent isolate.
        bool m_interrupted; 
        vmbase::WaitNotifyMonitor m_listenerLock; // May eventually protect more state.
        UnmanagedPointerList<IsolateEventListener*> m_listeners;

        // *** end data ***
    };

    /*
     * InterruptableState provides basic management 
     * for any objects running within an isolate that 
     * need to enter a blocking state and be 
     * interruptable to support termination, debugging, 
     * and script-timeouts
     */ 
    class InterruptableState: public FixedHeapRCObject 
    {
    public:
        InterruptableState();
        virtual void destroy();
        void notify();
        void notifyAll();

    protected:
        Isolate::WaitRecord* enterWait(Isolate* isolate);
        bool wait(Isolate::WaitRecord* record, Isolate* isolate, int32_t millis);
        void exitWait(Isolate* isolate, Isolate::WaitRecord* record);
#ifdef DEBUG
        virtual bool lockIsHeld() = 0;
#endif // DEABUG

    private:
        // list of all isolate threads currently waiting on this state
        MMgc::BasicList<Isolate::WaitRecord*> m_waitList;
    };


    /* An aggregate is a collection of isolates that have been transitively created from 
     * a single isolate (the primordial isolate).
     * In the avm shell build there is only one of these but in the Flash Player there would be one
     * for each Player instance (for each <object/> or <embed/> tag).
     */
    class Aggregate : public FixedHeapRCObject
    { 
        friend void Isolate::destroyListeners();
        friend class PromiseHelperClass;
    private:
        // singleton
        class Globals 
        {
            friend class Aggregate;
            friend class PromiseHelperClass;
        public:
            Globals()
                  : m_nextGlobalIsolateId(1) 
                  , m_nextGlobalPromiseId(0)
                  , m_isolateMap(16)
                  , m_channelMap(32)
                  , m_nextChannelGuid(1)
                  , m_emptyPromisesMap(16)
            {}

            ~Globals()
            {
            }


        private:

            Isolate* at(int32_t giid);

            int64_t newChannelGuid();

            /**** data ****/
            vmbase::WaitNotifyMonitor m_lock; // protects m_globals and all Aggregate instances (curently).
            
            int32_t m_nextGlobalIsolateId;
            int32_t m_nextGlobalPromiseId;

            class IsolateMap: public FixedHeapHashTable<int32_t, FixedHeapRef<Isolate> > 
            {
            public:
                IsolateMap(int initialSize);
                virtual ~IsolateMap();
                vmbase::WaitNotifyMonitor m_lock;
            };
            IsolateMap m_isolateMap;

            class PromiseChannelMap: public FixedHeapHashTable<int64_t, PromiseChannel* > 
            {
            public:
                PromiseChannelMap(int initialSize);
                virtual void DestroyItem(int64_t guid, PromiseChannel* channel);
                virtual ~PromiseChannelMap();
                vmbase::WaitNotifyMonitor m_lock;
            };
            PromiseChannelMap m_channelMap;

            int64_t m_nextChannelGuid;

            class EmptyPromisesMap: public FixedHeapHashTable<int32_t, FixedHeapHashTable<int32_t, int32_t>* >
            {
            public:
                EmptyPromisesMap(int initialSize);
                virtual ~EmptyPromisesMap();
            };

            EmptyPromisesMap m_emptyPromisesMap;


            /**** end data ****/
        }; // Globals

    public:
        Aggregate();
        virtual ~Aggregate();
        virtual void destroy();

        bool isPrimordial(int32_t giid);

        uint32_t nextPromiseGID();

        // If parent == NULL, the primordial isolate will be created.
        Isolate* newIsolate(Isolate* parent);

        void addThreadCleanup(vmbase::VMThread* thread);
        bool spawnAndWaitForInitialization(AvmCore* spawningCore, Isolate* isolate);
        void recordSpawnFailure(Isolate* isolate);

        void initializeAndNotify(AvmCore* targetCore, Isolate* isolate);

        virtual void runIsolate(Isolate* isolate);

        void beforeCoreDeletion(Isolate* current);
        void afterGCDeletion(Isolate* current);

        /* True if request caused exit */
        bool requestExit(bool shouldWait, int32_t desc, Toplevel* currentToplevel);
        void requestAggregateExit();
        void waitUntilNoIsolates();
        static void destroyIsolate(Isolate* isolate);
        static void destroyPromiseChannel(PromiseChannel* channel);


        static void initializeGlobals();
        static void reclaimGlobals();
        static void dumpGlobals(); // debugging

        FixedHeapRef<PromiseChannel> allocatePromiseChannel(int32_t senderGiid, int32_t receiverGiid);
        void closePromiseChannel(PromiseChannel* channel, int32_t endpoint_giid);
        void closeChannelsWithEndpoint(Isolate* endpoint);
        bool beginChannelOp(PromiseChannel* channel, bool item_sent);
        void endChannelOp(PromiseChannel* channel, bool item_received);

        bool waitForAnySend(Isolate* isolate, Toplevel* toplevel, bool block);

        virtual void selfExit(Toplevel* toplevel);

        // false if failure, e.g., worker inactive.
        bool registerAdditionalRemoteProxy(uint32_t resolvedPromiseGID,
                                           uint32_t freshPromiseGID,
                                           PromiseChannelObject* out,
                                           PromiseChannelObject* inc);
        
        // false if failure
        bool notifyEmptyOwners(int32_t emptyPromiseGID, Atom resolvedObject, Toplevel* toplevel);

        void registerEmptyPromise(int32_t emptyPromiseGID, int32_t creatorGiid);

        void printEmptyPromises();

        GCRef<ObjectVectorObject> listWorkers(Toplevel* toplevel);
        void runHoldingIsolateMapLock(vmbase::SafepointTask* task);
        void reloadGlobalMemories();

        Isolate* getIsolate(int32_t desc);
        Isolate::State queryState(Isolate* isolate);
        static bool isGlobalsLocked();
        void stateTransition(Isolate* isolate, enum Isolate::State to);
        IsolateEventListener* newEventListener(int32_t sourceGiid, Isolate* destination);
        vmbase::SafepointManager* safepointManager()
        {
            return &m_safepointMgr;
        }
        
        bool inShutdown()
        {
            return m_inShutdown;
        }

    private:
        static Globals* m_globals;
        int32_t m_primordialGiid;
        int m_activeIsolateCount;
        vmbase::WaitNotifyMonitor m_commlock; // protects all communication (ouch)
        int32_t m_commInProgress;
        int32_t m_msgInTransit; // sent but not received messages
        int32_t m_blockedChannels; // channels waiting for resolution in waitForAnySend()
        vmbase::SafepointManager m_safepointMgr; // Currently for shared byte array only.
        bool m_inShutdown;
        
        FixedHeapArray<vmbase::VMThread*> m_threadCleanUps;

    };

    // Stack allocated, RAII pattern.
    class EnterSafepointManager
    {
    public:
        EnterSafepointManager(AvmCore* core);
        void cleanup(); // If manual cleanup needed b/c of longjmp.
        ~EnterSafepointManager();
    private:
        vmbase::SafepointManager* m_safepointMgr;
        vmbase::SafepointRecord m_spRecord;
    };


    class IsolateEventListener
    {
    public:
        FixedHeapRef< PromiseChannel > channel;
        IsolateEventListener(Aggregate* aggregate, int32_t sourceGid, int32_t consumerGid);
    };

    template <class T>
    class WorkerDomainObjectBase
    {
    public:
        T* self();
        ObjectVectorObject* listWorkers();
    };


    template <class T>
    class WorkerClassBase
    {
        MethodEnv* m_handleLifecycleEventsMethod;

    public:
        WorkerClassBase(): m_handleLifecycleEventsMethod(NULL) {}
        void handleLifecycleEvents();
    };

    template <class T>
    class WorkerObjectBase
    {
        T* self();
    public:
        WorkerObjectBase();
        //  If "thisIsolate == NULL" then create a new isolate.  Otherwise, use thisIsolate to construct the worker
        void initialize(Isolate *thisIsolate = NULL);

        GCRef<ScriptObject> setIsolate(Isolate* isolate);

        ~WorkerObjectBase();
        int32_t descriptor();
        Stringp get_state();
        bool stopInternal(bool shouldWait);

        bool isParentOf(WorkerObjectBase* worker);
        bool isPrimordial();

        bool startWithChannels(ArrayObject* channels);
        bool internalStartWithChannels(ArrayObject* channels);
        // obviously candidate for further refactoring
        bool startVeryInternal();

        void setSharedProperty(String* key, Atom value);
        Atom getSharedProperty(String* key);

        
        PromiseChannelObject* newEventChannel();
        
        static void throwError(const char* msgz);        
    	static void throwIllegalOperationError(int errorID);

        int32_t giid; // const
    protected:
        FixedHeapRef<Isolate> m_isolate;
        
    };
    
}
#endif
