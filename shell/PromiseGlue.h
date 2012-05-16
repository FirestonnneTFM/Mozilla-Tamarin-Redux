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

#ifndef __avmplus_PromiseGlue__
#define __avmplus_PromiseGlue__
#include "avmplus-tracers.h"

namespace avmplus
{
 
    class PromiseHelperClass: public  ClassClosure 
    {
    public:
        PromiseHelperClass(VTable* cvtable);

        int32_t get_currentGiid();
        int32_t getPromiseOwnerGiid(PromiseObject* p);
        void setPromiseOwnerGiid(PromiseObject* p, int32_t giid);
        uint32_t getPromiseGid(PromiseObject* p);
        void setPromiseGid(PromiseObject* p, uint32_t gpid);
        bool isPromiseEmpty(PromiseObject* p);
        void schedulePromiseCollection(PromiseObject* p);
        void retargetIncChannel(PromiseChannelObject* ch, int32_t senderGiid, int32_t receiverGiid);
        void retargetOutChannel(PromiseChannelObject* ch, int32_t receiverGiid, int32_t senderGiid);

        void pr(Stringp str);
        void praddr(Atom a);
        void breakOn(Atom a);
        bool waitForAnySend(bool duringResolution);

        //GC_NO_DATA(PromiseHelperClass);
        DECLARE_SLOTS_PromiseHelperClass;
    };


    class PromiseClass: public ClassClosure
    {
        friend class PromiseObject;
        friend class RemoteProxyClass;
        friend class PromiseHelperClass;
    public:
        PromiseClass(VTable* cvtable);

        PromiseObject* createLocal(Atom local, bool empty);

        PromiseObject* create(PromiseChannelObject* out,
                              PromiseChannelObject* inc);

        // the creatorGiid and creatorParentGiid indentify two workers
        PromiseObject* createWithGID(FixedHeapRef<PromiseChannel>& out,
                              FixedHeapRef<PromiseChannel>& inc,
                              bool global,
                              uint32_t gid);
        
        void destroyRemoteObjects();

        PromiseChannelObject* getRegisteredOutChannel(uint32_t gpid);
        void resetRegisteredOutChannel(uint32_t gpid);
        bool allRegisteredChannelsDestroyed();

        void notifyOwner(uint32_t resolvedPromiseGID,
                         uint32_t freshPromiseGID,
                         PromiseChannelObject* out,
                         PromiseChannelObject* inc);

        void notifyEmptyOwners(PromiseObject *p);
        
        void registerEmptyPromise(PromiseObject *p, int32_t creatorGiid);
        
        void printEmptyPromises();
        
        void processEmptyPromiseResolution(int32_t emptyPromiseGID, 
                                           int32_t newGID,
                                           FixedHeapRef<PromiseChannel>& out,
                                           FixedHeapRef<PromiseChannel>& inc);
        
        bool checkForCallRequests();

        static GCRef<MethodEnv> initOneMethodEnv(VTable* vtable, const char* nm);

        void sendDestroyMessage(uint32_t gpid, Atom fresh_promises);
        
    private:
        //GC_DATA_BEGIN(PromiseClass)
        DECLARE_SLOTS_PromiseClass;
        GCMember<MethodEnv> GC_POINTER(m_getProperty);
        GCMember<MethodEnv> GC_POINTER(m_callProperty);
        // stores references to out channels of local promises
        // pointing to remote objects; used from promise's native
        // destructor (hence separate data structure - actual
        // promise's out channel could already be destroyed); channels
        // are inserted into this date structure in five cases:
        // 1. When promise representing remote call return value is
        // created
        // 2. When promise representing remote property access is
        // created
        // 3. When during passing a promise as a paremeter a fresh
        // promise is created
        // 4. When promise used for callback (when method) is created
        // 5. When an explicitly unresolved (empty) promise is finally
        // resolved
        GCMember<ArrayObject> GC_POINTER(outChannels);
        // a companion to outcChannels (same indexing) remembering
        // collection of which promises is delayed
        GCMember<ArrayObject> GC_POINTER(gcDelayedPromises);
        //GC_DATA_END(PromiseClass)
    };


    class PromiseObject: public ScriptObject
    {
        friend class PromiseClass;
        friend class PromiseHelperClass;
        
    protected:
        PromiseObject(VTable* vtable, ScriptObject* prototype); 

    public:
        ~PromiseObject();
        REALLY_INLINE static PromiseObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* prototype)
        {
            return new (gc, /*MMgc::kExact,*/ ivtable->getExtraSize()) PromiseObject(ivtable, prototype);
        }

        void delayCollection(uint32_t fresh_gpid);
        bool isOwnedLocally();

        virtual Atom getMultinameProperty(const Multiname* name) const;
        virtual Atom callProperty(const Multiname* multiname, int argc, Atom* argv);

        virtual ScriptObject* cloneNonSlots(ClassClosure* classClosure, Cloner& cloner) const;

    private:
        bool noCollection;  // unset on a promise that is supposed to send collection request

        int32_t owner_giid; // worker whose object this promise represents

        uint32_t gpid;
                
        //GC_NO_DATA(PromiseObject);
        DECLARE_SLOTS_PromiseObject;
    };


    class RemoteProxyClass: public ClassClosure
    {
        friend class RemoteProxyObject;
    public:
        RemoteProxyClass(VTable* cvtable);

        RemoteProxyObject* create(PromiseChannelObject* out,
                                  PromiseChannelObject* inc,
                                  uint32_t gid);

        RemoteProxyObject* createWithGID(FixedHeapRef<PromiseChannel>& out,
                                  FixedHeapRef<PromiseChannel>& inc,
                                  uint32_t gid);

        bool createAndInsert(FixedHeapRef<PromiseChannel>& out,
                             FixedHeapRef<PromiseChannel>& inc,
                             uint32_t gid,
                             uint32_t existingProxyGID);
            
        GCRef<ClassClosure> get_m_workerClass();

        bool checkForCallRequestsInternal();

        Atom callProp(Atom receiver, avmshell::EnvelopeObject* envelope);

        Atom getProp(Atom receiver, avmshell::EnvelopeObject* envelope);

        //GC_DATA_BEGIN(RemoteProxyClass);
        DECLARE_SLOTS_RemoteProxyClass;
        GCMember<MethodEnv> GC_POINTER(m_checkForCallRequests); // The player needs it
        //GC_DATA_END(RemoteProxyClass);
    };


    class RemoteProxyObject: public ScriptObject
    {
        friend class RemoteProxyClass;
    protected:
        RemoteProxyObject(VTable* vtable, ScriptObject* prototype); 
    public:
        REALLY_INLINE static RemoteProxyObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* prototype)
        {
            return new (gc, /*MMgc::kExact,*/ ivtable->getExtraSize()) RemoteProxyObject(ivtable, prototype);
        }
        void setState(uint32_t state);
        
        void triggerDelayedCollection(Atom a);
        // determines how many notifyOwner() requests are not yet
        // processed (represents "remote reference count");
        int refCount; 

        //GC_NO_DATA(RemoteProxyObject);
        DECLARE_SLOTS_RemoteProxyObject;
    };

}

namespace avmshell 
{

    using namespace avmplus;

    class EnvelopeClass: public ClassClosure
    {

        friend class PromiseChannelObject;
    protected:
        EnvelopeClass(VTable* cvtable)
            : ClassClosure(cvtable) {}
    private:
        //GC_NO_DATA(EnvelopeClass)
        DECLARE_SLOTS_EnvelopeClass;
    };

    class EnvelopeObject: public ArrayObject
    {
    public:
        REALLY_INLINE static EnvelopeObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, uint32_t capacity = 0)
        {
            return new (gc, /*MMgc::kExact,*/ ivtable->getExtraSize()) EnvelopeObject(ivtable, delegate, capacity);
        }
        EnvelopeObject(VTable* vtable, ScriptObject* prototype, uint32_t capacity = 0)
            : ArrayObject(vtable, prototype, capacity) {}

        virtual ScriptObject* cloneNonSlots(ClassClosure* targetClass, Cloner& cloner) const;
        String* get_name();
        
        //GC_DATA_BEGIN(EnvelopeObject)
        HeapMultiname GC_STRUCTURE(m_multiname);
    private:
        //GC_DATA_END(EnvelopeObject)
        DECLARE_SLOTS_EnvelopeObject;
    };

    
}

#endif /* __avmplus_PromiseGlue__ */
