/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
#ifndef __avmplus_Isolate__
#define __avmplus_Isolate__

#include "FixedHeapUtils.h"
#include "Channels.h"

#ifdef DEBUG
#define DEBUG_INTERRUPTIBLE_STATE
#endif // DEBUG 


namespace avmplus
{
    /*
     * Represents an isolate in various stages of its lifecycle. There's only one Isolate
     * object per isolate.
     */
    class Isolate : public vmbase::Runnable, public FixedHeapRCObject
    {
        friend class Aggregate;
        friend class WorkerObject;
        
    public:
		typedef int32_t descriptor_t;

        static const descriptor_t INVALID_DESC	= 0;
        static const descriptor_t POISON_DESC	= 0x7FFFFFFF; // Max int32
        // Isolate objects are created by client code (e.g., the shell), before their AvmCores are instantiated.
        // If the isolate is successfully started, the Isolate object will delete itself upon isolate termination. 
        // Otherwise, the AS glue object (IsolateObject) destructor will delete Isolate objects that have not been
        // started or have failed.
        Isolate(descriptor_t desc, descriptor_t parentDesc, Aggregate* aggregate);

        static Isolate* newIsolate(descriptor_t desc, descriptor_t parentDesc, Aggregate* aggregate); 

        void initialize(AvmCore* core);

        virtual void run(); // Inherited from Runnable.

        virtual void destroy();
        virtual ~Isolate();

        AvmCore* getAvmCore () const
        {
            return m_core;
        }

        Aggregate* getAggregate() const
        {
            return m_aggregate;
        }

        bool isParentOf(const Isolate* other) const
        {
            AvmAssert(other != NULL);
            return other->m_parentDesc == m_desc;
        }

        virtual void copyByteCode(ByteArrayObject* array);
        
        // WorkerObject type depends on the overiding class.
        virtual ScriptObject* newWorkerObject(Toplevel* toplevel) =  0;

        bool interrupt();				// false if already interrupted
        bool isInterrupted() const;
        bool hasFailed() const;

        // Last phase of termination.
        virtual bool isMemoryManagementShutDown() const; 

        bool isPrimordial() const;
        
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

    protected:
        FixedHeapArray<uint8_t> getByteCode() const
        { 
            return m_code.values[0]; 
        }
		
        virtual void stopRunLoop() 
        {
			// This is the default impl for AvmShellIsolate and any other Isolate derived classes that
			// do not have a run loop.
        }

        virtual void doRun() = 0;

    public:
		descriptor_t getDesc() const { return m_desc; }
		descriptor_t getParentDesc() const { return m_parentDesc; }
		void resetParent() { m_parentDesc = INVALID_DESC; }
		
    protected:
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
		
        FixedHeapArray< FixedHeapArray<uint8_t> > m_code;
        
    private:
		descriptor_t m_desc;
        descriptor_t m_parentDesc;

        virtual void releaseActiveResources();
 		vmbase::RecursiveMutex m_sharedPropertyLock; 
		SharedPropertyMap m_sharedProperties;

    public:
        void clearThread();
        void setSharedProperty(const StUTF8String& key, ChannelItem* item);
        bool getSharedProperty(const StUTF8String& key, ChannelItem** outItem);
        virtual ChannelItem* makeChannelItem(Toplevel* toplevel, Atom atom);
        void signalInterruptibleState();
        virtual bool retryInterruptibleState();


        /*
         * InterruptibleState provides basic management 
         * for any objects running within an isolate that 
         * need to enter a blocking state and be 
         * interruptable to support termination, debugging, 
         * and script-timeouts
         */ 
        class InterruptibleState
        {
        public:
            InterruptibleState();
            bool hasWaiters();
            void notify();
            void notifyAll();
            // signal is a specialized case of notifyAll.
            // it is used to wake up all threads and have
            // them check if they should exit their waiting
            // state or return to a blocked state. this
            // is needed to support script timeout, terminate
            // and call stack acquisition for fdb.
            void signal();

            //
            // This is intended as a stack based RAII helper for 
            // locking and waiting on an InterruptibleState, as 
            // well as associating that waiting state with a
            //
            class Enter
            {
            public:
                Enter(InterruptibleState* state, Isolate* isolate);
                void wait(int32_t timeout=-1);
                void notify();
                bool interrupted;
                bool result;

                // Force stack allocation
                void* operator new(size_t);

            private:
                friend class Isolate;
                // RAII for setting and removing the active intteruptible
                // state object for the associated isolate
                class ActiveInterruptibleStateHelper
                {
                public:
                    ActiveInterruptibleStateHelper(Isolate* isolate, InterruptibleState* state);
                    ~ActiveInterruptibleStateHelper();
                    void unlock() const;
                    Isolate* getIsolate() const;


        #ifdef DEBUG_INTERRUPTIBLE_STATE
			        Isolate::descriptor_t gid;
        #endif // DEBUG_INTERRUPTIBLE_STATE
                private:

                    Isolate* m_isolate;
                    // reference to the mutex that is used to 
                    // protect the active state on isolate
                    vmpi_mutex_t* m_mutex;
                };
                // we must always set the isolate's active state
                // before getting a lock on the monitor
                // *and* release them in the opposite order
                // we are relying on the initialization and 
                // destruction order for this.
                ActiveInterruptibleStateHelper m_stateSetter;
                vmbase::MonitorLocker< vmbase::IMPLICIT_SAFEPOINT > m_monitor;
                InterruptibleState* m_state;
            };

            vmbase::WaitNotifyMonitor& getMonitor() { return m_condition; }

#ifdef DEBUG_INTERRUPTIBLE_STATE
             int32_t gid;
#endif // DEBUG_INTERRUPTIBLE_STATE

        private:
            friend class Enter;
            vmbase::WaitNotifyMonitor m_condition;
            volatile int32_t m_waiterCount;
            int32_t m_signaledWaiters;

#ifdef DEBUG_INTERRUPTIBLE_STATE
            static  int32_t globalId; // global id counter
#endif // DEBUG_INTERRUPTIBLE_STATE
        };

    private:
        friend class InterruptibleState::Enter::ActiveInterruptibleStateHelper;

        void lockInSafepoint(vmpi_mutex_t* mutex) const;
        static void lockInSafepointGate(void* stackPointer, void* mutex);

		AvmCore* m_core;

		// when an isolate is blocked from ActionScript either due to a 
        // Condition.wait or a Mutex.lock or other blocking operation
        // the activeWaitRecord is used. The activeWaitRecord provides
        // a simple way for the runtime to "wake" a blocked thread so that
        // operations like Worker.terminate, shutdown, and script timeout can
        // occur.
        InterruptibleState* m_interruptibleState;
        vmpi_mutex_t m_interruptibleStateMutex;

        FixedHeapRef<Aggregate> m_aggregate;
        Isolate::State m_state;
        bool m_failed; // only accessed by the parent isolate.
        bool m_interrupted; 

        // *** end data ***
    };


    /* An aggregate is a collection of isolates that have been transitively created from 
     * a single isolate (the primordial isolate).
     * In the avm shell build there is only one of these but in the Flash Player there would be one
     * for each Player instance (for each <object/> or <embed/> tag).
     */
    class Aggregate : public FixedHeapRCObject
    { 
    private:
        class Globals 
        {
            friend class Aggregate;
        public:
            Globals()
                  : m_nextGlobalIsolateId(1) 
 				  , m_idsWrapped(false)
                  , m_isolateMap(16)
            {}
			
			Isolate::descriptor_t getNewID()
			{
				Isolate::descriptor_t newID = m_nextGlobalIsolateId;
				bool hadWrap = (newID == Isolate::POISON_DESC);
				m_idsWrapped = m_idsWrapped || hadWrap;
				
				if (m_idsWrapped)
				{
					if (hadWrap)
						m_nextGlobalIsolateId = 1;
					
					FixedHeapRef<Isolate> isolateRef(NULL);
					while (m_isolateMap.LookupItem(m_nextGlobalIsolateId, &isolateRef)) 
					{
						m_nextGlobalIsolateId++;
					}
					newID = m_nextGlobalIsolateId;
				}
				
				m_nextGlobalIsolateId++;
				return newID;
			}
			
			void orphanFor(Isolate::descriptor_t giid)
			{
				class Orphanize: public Globals::IsolateMap::Iterator
				{
				private:
					const Isolate::descriptor_t m_TargetID;
					
				public:
					Orphanize(Isolate::descriptor_t target)
					: m_TargetID(target)
					{}
					
					virtual void each(Isolate::descriptor_t, FixedHeapRef<Isolate> isolate) 
					{
						if (isolate->getParentDesc() == m_TargetID)
						{
							isolate->resetParent();
						}
					}
				};
				
				Orphanize makeOrphansFor(giid);
				SCOPE_LOCK(m_isolateMap.m_lock) {
					m_isolateMap.ForEach(makeOrphansFor);
				}
			}

        private:

            Isolate* getIsolateForID(Isolate::descriptor_t giid);  // cannot be const because m_isolateMap is ill defined;

            vmbase::WaitNotifyMonitor m_lock; // protects m_globals and all Aggregate instances (curently).
            
            Isolate::descriptor_t m_nextGlobalIsolateId;
			bool m_idsWrapped;

            class IsolateMap: public FixedHeapHashTable<Isolate::descriptor_t, FixedHeapRef<Isolate> > 
            {
            public:
                IsolateMap(int initialSize);
                virtual ~IsolateMap();
                vmbase::WaitNotifyMonitor m_lock;
            };
			
            IsolateMap m_isolateMap;
        }; // Globals

        //
        // Provides a container for all threads that are still
        // executing code and will need to be waited on before
        // shutting down the associated Aggregate.
        //
        class ActiveIsolateThreadMap: public FixedHeapHashTable<Isolate::descriptor_t, vmbase::VMThread*>
		{
		public:
			ActiveIsolateThreadMap(int initialSize);
			void cleanup();
		};
		
    public:
        Aggregate();
        virtual ~Aggregate();
        virtual void destroy();

        bool isPrimordial(Isolate::descriptor_t giid) const;

        // If parent == NULL, the primordial isolate will be created.
        Isolate* newIsolate(Isolate* parent);

        bool spawnIsolateThread(Isolate* isolate);

        void initialize(AvmCore* targetCore, Isolate* isolate);

        void beforeCoreDeletion(Isolate* current);
        void afterGCDeletion(Isolate* current);

        /* True if request caused exit */
        bool requestIsolateExit(Isolate::descriptor_t desc, Toplevel* currentToplevel);
        void requestAggregateExit();
        void waitUntilNoIsolates();

        virtual void throwWorkerTerminatedException(Toplevel* toplevel);

        GCRef<ObjectVectorObject> listWorkers(Toplevel* toplevel);
        void runSafepointTaskHoldingIsolateMapLock(vmbase::SafepointTask* task);
        void reloadGlobalMemories();
        void cleanupIsolate(Isolate* isolate);

        Isolate* getIsolate(Isolate::descriptor_t desc);
        Isolate::State queryState(Isolate* isolate);

        void stateTransition(Isolate* isolate, enum Isolate::State to);
        vmbase::SafepointManager* safepointManager()
        {
            return &m_safepointMgr;
        }
        
        bool inShutdown() const
        {
            return m_inShutdown;
        }
		
    private:
        Globals m_globals;
		Isolate::descriptor_t m_primordialGiid;
        int m_activeIsolateCount;
        vmbase::SafepointManager m_safepointMgr; // Currently for shared byte array only.
        bool m_inShutdown;
  		ActiveIsolateThreadMap m_activeIsolateThreadMap;
    };

    // Stack allocated, RAII pattern.
    class EnterSafepointManager
    {
    public:
        EnterSafepointManager(AvmCore* core);
        void leaveSafepoint();					// If manual exit/cleanup needed b/c of longjmp.
        ~EnterSafepointManager();
    private:
		FixedHeapRef<Aggregate> m_aggregate;					// to keep the safepoint mgr alive during shutdown, etc.
        vmbase::SafepointManager* m_safepointMgr;
        vmbase::SafepointRecord m_spRecord;
    };

    template <class T>
    class WorkerDomainObjectBase
    {
    public:
        T* self();
        ObjectVectorObject* listWorkers();
    };


    template <class T>
    class WorkerObjectBase
    {
        T* self();
    public:
        WorkerObjectBase();
        //  If "thisIsolate == NULL" then create a new isolate.  Otherwise, use thisIsolate to construct the worker
        void initialize(Isolate *isolate = NULL);

        GCRef<ScriptObject> setIsolate(Isolate* isolate);

        ~WorkerObjectBase();
		Isolate::descriptor_t descriptor() const;
        Stringp get_state();

        bool isParentOf(WorkerObjectBase* worker);
        bool isPrimordial() const;

        bool start( );
        bool startInternal( );
        // obviously candidate for further refactoring
        bool startVeryInternal();
        bool stopInternal();

        void setSharedProperty(String* key, Atom value);
        Atom getSharedProperty(String* key);
        
    	static void throwIllegalOperationError(int errorID);

    protected:
		Isolate* getIsolate() const 		{ return m_isolate; }
		
	private:
        FixedHeapRef<Isolate> m_isolate;
        
    };
    
}
#endif

