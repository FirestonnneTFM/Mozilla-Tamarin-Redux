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
#include "avmplus.h"
#include "avmshell.h"
namespace avmplus
{
    
    PromiseHelperClass::PromiseHelperClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    int32_t PromiseHelperClass::get_currentGiid()
    {
        return core()->getIsolate()->desc;
    }


    int32_t PromiseHelperClass::getPromiseOwnerGiid(PromiseObject* p)
    {
        return p->get_m_async()->owner_giid;
    }

    void PromiseHelperClass::setPromiseOwnerGiid(PromiseObject* p, int32_t giid)
    {
        AvmAssert(p->get_m_async()->owner_giid == Isolate::POISON_DESC);
        AvmAssert(p->get_m_async()->get_m_empty());
        p->get_m_async()->owner_giid = giid;
    }

    uint32_t PromiseHelperClass::getPromiseGid(PromiseObject* p)
    {
        return p->gpid;
    }

    void PromiseHelperClass::setPromiseGid(PromiseObject* p, uint32_t gpid)
    {
        p->get_m_async()->gpid = gpid;
        p->gpid = gpid;
    }

    bool PromiseHelperClass::isPromiseEmpty(PromiseObject* p)
    {
        return p->get_m_async()->get_m_empty();
    }


    void PromiseHelperClass::schedulePromiseCollection(PromiseObject* p)
    {
        p->get_m_async()->noCollection = false;
        GCRef<PromiseClass> promiseClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_PromiseClass();
        AvmAssert(AvmCore::isNullOrUndefined(promiseClass->outChannels->getUintProperty(p->gpid)));
        AvmAssert(p->get_m_async()->get_m_out() != NULL);
        AvmAssert(p->get_m_async()->get_m_out()->get_sender() == core()->getIsolate()->desc);
        promiseClass->outChannels->setUintProperty(p->gpid, p->get_m_async()->get_m_out()->toAtom());
    }

    void PromiseHelperClass::retargetIncChannel(PromiseChannelObject* ch, int32_t senderGiid, int32_t receiverGiid)
    {
        Isolate* isolate = core()->getIsolate();
        Aggregate* aggregate = isolate->getAggregate();
        // during retargetting we change (among other things) the end
        // point identifier; these are not used during transmission so
        // the only thing we should guarg against here is channel
        // being closed - m_lock shoudl suffice for that as it guards
        // Aggregate::closeChannelsWithEndpoint() and
        // Aggregate::destroyPromiseChannel() with the exception of
        // when invoked from PromiseChannel::destroy() (but we still
        // hold a reference here so message channel should not be
        // collected).
        SCOPE_LOCK(aggregate->m_globals->m_lock) {
            Isolate* sender = aggregate->m_globals->at(senderGiid);
            Isolate* receiver = aggregate->m_globals->at(receiverGiid);
            if (sender != NULL && sender->m_state == Isolate::RUNNING &&
                receiver != NULL && receiver->m_state == Isolate::RUNNING) {
                // this channel is not being used (in the sense of
                // anything being put into it) so playing the GC game
                // should be safe
                AvmAssert(sender->targetCore() != NULL);
                AvmAssert(sender->targetCore()->gc != NULL);
                ch->m_channel->unregisterRoot();
                ch->m_channel->registerWithGC(sender->targetCore()->gc);

                ch->retargetSender(senderGiid);
            }
        }
        (void)aggregate; // macro hides usage from VS compiler
        
    }

    void PromiseHelperClass::retargetOutChannel(PromiseChannelObject* ch, int32_t receiverGiid, int32_t senderGiid)
    {
        Isolate* isolate = core()->getIsolate();
        Aggregate* aggregate = isolate->getAggregate();
        // for why retargetting should be safe see comment in
        // retargetIncChannel() above
        SCOPE_LOCK(aggregate->m_globals->m_lock) {
            Isolate* receiver = aggregate->m_globals->at(receiverGiid);
            Isolate* sender = aggregate->m_globals->at(senderGiid);
            if (receiver != NULL && receiver->m_state == Isolate::RUNNING &&
                sender != NULL && sender->m_state == Isolate::RUNNING) {
                ch->retargetReceiver(receiverGiid);
            }
        }
        (void)aggregate; // macro hides usage from VS compiler
    }

    bool PromiseHelperClass::waitForAnySend(bool block)
    {
        Isolate* isolate = core()->getIsolate();
        Aggregate* aggregate = isolate->getAggregate();
        return aggregate->waitForAnySend(isolate, toplevel(), block);
    }

    void PromiseHelperClass::pr(Stringp str)
    {
        fprintf(stderr, "%s\n", avmplus::StUTF8String(core()->internString(str)).c_str());
        fflush(stderr);
        
    }

    void PromiseHelperClass::praddr(Atom a)
    {
        printf("%p\n", AvmCore::atomToScriptObject(a));
        fflush(stdout);
        
    }

    void PromiseHelperClass::breakOn(Atom a)
    {
        (void)a;
        // empty, put a break on it.
    }

    PromiseClass::PromiseClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();

        //Stringp uri = core()->internConstantStringLatin1("http://adobe.com/AS3/2011/async");
        //m_asyncNS = core()->internNamespace(core()->newNamespace(uri->atom()));

        m_getProperty          = initOneMethodEnv(ivtable(), "getProperty");
        m_callProperty         = initOneMethodEnv(ivtable(), "callProperty");

        ArrayClass* arrayClass = toplevel()->arrayClass();
        outChannels = ArrayObject::create(core()->gc, arrayClass->ivtable(), arrayClass->prototypePtr(), 1);
        gcDelayedPromises = ArrayObject::create(core()->gc, arrayClass->ivtable(), arrayClass->prototypePtr(), 1);
    }

    GCRef<MethodEnv> PromiseClass::initOneMethodEnv(VTable* vtable, const char* nm)
    {
        //Multiname mn(ns, core()->internConstantStringLatin1(nm));
        //Binding b = toplevel()->getBinding(this->vtable->traits->itraits, &mn);
        Binding b = vtable->traits->getTraitsBindings()->findBinding(vtable->core()->internConstantStringLatin1(nm));
        AvmAssert(AvmCore::isMethodBinding(b));
        GCRef<MethodEnv> method = vtable->methods[AvmCore::bindingToMethodId(b)];
        return method;
    }

    // TODO: functionality moved to RemoteProxyClass - update the
    // player to account for that
    bool PromiseClass::checkForCallRequests()
    {
        GCRef<RemoteProxyClass> remoteProxyClass =
            static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_RemoteProxyClass();
        return remoteProxyClass->checkForCallRequestsInternal();
    }

    void PromiseClass::sendDestroyMessage(uint32_t gpid, Atom fresh_gpids)
    {

        PromiseChannelObject* ch = getRegisteredOutChannel(gpid);
        if (ch != NULL && 
            !ch->isClosed()  && 
            ch->get_sender() == core()->getIsolate()->desc) { // we may have a third-party channel?

            // try sending, but if channel closed on the other side,
            // do not throw the exception; if that's the case than
            // there is nothing more to be done (no way to send the
            // destroy request) - the other worker is likely shutting
            // down anyway and will kill all its remote object anyways
            if (AvmCore::isNullOrUndefined(fresh_gpids)) { // no delay
                ch->sendCondThrow(core()->uintToAtom(get_DESTROY_REQUEST()), false);
            }
            else {
                ch->sendCondThrow(core()->uintToAtom(get_DESTROY_DELAYED_REQUEST()), false);
                ch->sendCondThrow(fresh_gpids, false);                
            }
            resetRegisteredOutChannel(gpid);
        }
    }

    void PromiseClass::destroyRemoteObjects()
    {
        for (uint32_t i=0; i<outChannels->get_length(); i++) {
            Atom a = gcDelayedPromises->getUintProperty(i);
            sendDestroyMessage(i, a);
            if (!AvmCore::isNullOrUndefined(a))
                gcDelayedPromises->setUintProperty(i, nullObjectAtom);
        }
        outChannels = NULL;
    }

    PromiseChannelObject* PromiseClass::getRegisteredOutChannel(uint32_t gpid)
    {
        // some promises (e.g. local) may not have channels assigned at all
        if (AvmCore::isNullOrUndefined(outChannels->getUintProperty(gpid)))
            return NULL;
        else
            return (PromiseChannelObject*)AvmCore::atomToScriptObject(outChannels->getUintProperty(gpid));
    }

    void PromiseClass::resetRegisteredOutChannel(uint32_t gpid)
    {
        AvmAssert(!AvmCore::isNullOrUndefined(outChannels->getUintProperty(gpid)));
        outChannels->setUintProperty(gpid, nullObjectAtom);
    }

    bool PromiseClass::allRegisteredChannelsDestroyed() {
        return outChannels == NULL;
    }

    void PromiseClass::notifyOwner(uint32_t resolvedPromiseGID,
                                   uint32_t freshPromiseGID,
                                   PromiseChannelObject* out,
                                   PromiseChannelObject* inc)
    {
        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();
        bool success = 
            aggregate->registerAdditionalRemoteProxy(resolvedPromiseGID,
                                                     freshPromiseGID,
                                                     out,
                                                     inc);
        if (!success) {
            core()->throwAtom(String::createLatin1(core(), "a promise argument refers to inactive worker")->toAtom());
        }
    }

    void PromiseClass::notifyEmptyOwners(PromiseObject *p) {
        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();
        bool success = aggregate->notifyEmptyOwners(p->gpid, p->get_m_async()->get_m_resolved(), toplevel());
        if (!success) {
            core()->throwAtom(String::createLatin1(core(), "an explicitly unresolved promise can be resolved only once")->toAtom());
        }
    }

    void PromiseClass::registerEmptyPromise(PromiseObject *p, int32_t callerGiid)
    {
        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();
        aggregate->registerEmptyPromise(p->gpid, callerGiid);
    }

    void PromiseClass::printEmptyPromises()
    {
        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();
        aggregate->printEmptyPromises();        
    }

    // invoked by a worker who holds a reference to a promise that
    // used to be empty (explicitly unresolved) but is now resolved
    void PromiseClass::processEmptyPromiseResolution(int32_t emptyPromiseGID,
                                                     int32_t newGID,
                                                     FixedHeapRef<PromiseChannel>& out,
                                                     FixedHeapRef<PromiseChannel>& inc)        
    {

        GCRef<PromiseHelperClass> promiseHelperClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_PromiseHelperClass();
        // mark empty promise as non-empty and connect it with the object owner
        ArrayObject* emptyPromises = promiseHelperClass->get_m_empty_promises();
        PromiseObject* empty = 
            (PromiseObject*)AvmCore::atomToScriptObject(emptyPromises->getUintProperty(emptyPromiseGID));
        
        PromiseChannelClass* promiseChannelClass = toplevel()->builtinClasses()->get_PromiseChannelClass();

        PromiseChannelObject* outChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        outChannel->initializeWithChannel(out); 
        PromiseChannelObject* incChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        incChannel->initializeWithChannel(inc); 

        int32_t ownerGiid = out->sender;
    
        //empty->owner_giid = ownerGiid;
        //[redundant]// empty->set_m_out(outChannel);
        //[redundant]// empty->set_m_inc(incChannel);
        //empty->set_m_empty(false);
        empty->gpid = newGID;

        empty->get_m_async()->owner_giid = ownerGiid;
        empty->get_m_async()->set_m_out(outChannel);
        empty->get_m_async()->set_m_inc(incChannel);
        empty->get_m_async()->set_m_empty(false);
        empty->get_m_async()->gpid = newGID;

	    // schedule collection of an object this promise is pointing to
        promiseHelperClass->schedulePromiseCollection(empty);
        

        Atom a = get_m_empty_requests()->getUintProperty(emptyPromiseGID);
        if(!AvmCore::isNullOrUndefined(a)) {
            ObjectVectorObject* emptyRequests = (ObjectVectorObject*)AvmCore::atomToScriptObject(a);
            do {
                Atom req = emptyRequests->AS3_pop();
                promiseHelperClass->get_m_delayed_requests()->AS3_push(&req, 1);
            } while (emptyRequests->get_length() > 0);
            get_m_empty_requests()->setUintProperty(emptyPromiseGID, nullObjectAtom);
        }
    }

    /*
    // FIXME move to Toplevel? 
    bool PromiseClass::isGlobal(Atom o)
    {
        AvmAssert(toplevel()->scriptEnvCount() > 0);
        for (int j = toplevel()->scriptEnvCount()-1; j >= 0; j--) {
            ScriptEnv* scriptEnv = toplevel()->scriptEnv(j);
            ScriptObject* globalObj = scriptEnv->global;
            if (!globalObj) // FIXME revisit, when is this true?
                continue;
            AvmAssert(globalObj->isGlobalObject());
            if (globalObj->toAtom() == o)
                return true;
        }
        return false;
    }
    */

    PromiseObject* PromiseClass::createLocal(Atom local, bool empty)
    {
        GCRef<PromiseObject> result = constructObject().staticCast<PromiseObject>();
        
        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();
        uint32_t gpid = aggregate->nextPromiseGID();
        int32_t dummy_giid = Isolate::POISON_DESC;

        //[redundant]// result->set_m_resolved(local);
        //[redundant]// result->set_m_out(NULL);
        //[redundant]// result->set_m_inc(NULL);
        //result->set_m_global(false); //empty ?  false : isGlobal(local));
        //result->set_m_package(false);
        result->gpid = gpid;
        //[redundant]// result->set_m_state(empty ?  get_NEW() : get_RECEIVED());
        //result->set_m_empty(empty);
        // dummy value below must be negative and different than -1 to
        // avoid representing a giid of any existing isolate
        //result->owner_giid = (empty ? dummy_giid : ent->desc);
        //result->noCollection = true;

        GCRef<PromiseObject> async = constructObject().staticCast<PromiseObject>();
        
        async->set_m_resolved(local);
        async->set_m_out(NULL);
        async->set_m_inc(NULL);
        async->set_m_global(false);
        //[redundant]// async->set_m_package(false);
        async->gpid = gpid;
        async->set_m_state(empty ?  get_NEW() : get_RECEIVED());
        async->set_m_empty(empty);
        // dummy value below must be negative and different than -1 to
        // avoid representing a giid of any existing isolate
        async->owner_giid = (empty ? dummy_giid : ent->desc);
        async->noCollection = true;

        result->set_m_async(async);

        async->set_m_async(NULL);
        
        return result;
    }


    PromiseObject* PromiseClass::create(PromiseChannelObject* out,
                                        PromiseChannelObject* inc)
    {

        Isolate* ent = core()->getIsolate();
        Aggregate* aggregate = ent->getAggregate();

        return createWithGID(out->m_channel,
                      inc->m_channel,
                      false,
                      aggregate->nextPromiseGID());
    }


    PromiseObject* PromiseClass::createWithGID(FixedHeapRef<PromiseChannel>& out,
                                        FixedHeapRef<PromiseChannel>& inc,
                                        bool global,
                                        uint32_t gid)
    {        

        PromiseChannelClass* promiseChannelClass = toplevel()->builtinClasses()->get_PromiseChannelClass();

        PromiseChannelObject* outChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        outChannel->initializeWithChannel(out);
        PromiseChannelObject* incChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        incChannel->initializeWithChannel(inc); 

        GCRef<PromiseObject> result = constructObject().staticCast<PromiseObject>();

        // out is promise's channel so owner of the actual object is
        // the receiver of this channel (worker on the remote proxy's
        // side)
        int32_t ownerGiid = out->receiver;

        //[redundant]// result->set_m_out(outChannel);
        //[redundant]// result->set_m_inc(incChannel);
        result->gpid = gid;
        //result->owner_giid = ownerGiid;
        //result->set_m_empty(false);
        //result->noCollection = true;

        //[redundant]// result->set_m_resolved(nullObjectAtom);
        //result->set_m_global(global);
        //result->set_m_package(false);
        //[redundant]// result->set_m_state(get_NEW());

        GCRef<PromiseObject> async = constructObject().staticCast<PromiseObject>();

        async->set_m_out(outChannel);
        async->set_m_inc(incChannel);
        async->gpid = gid;
        async->owner_giid = ownerGiid;
        async->set_m_empty(false);
        async->noCollection = true;

        async->set_m_resolved(nullObjectAtom);
        async->set_m_global(global);
        //[redundant]// async->set_m_package(false);
        async->set_m_state(get_NEW());

        result->set_m_async(async);

        async->set_m_async(NULL);

        return result;
    }

    PromiseObject::PromiseObject(VTable* vtable, ScriptObject* prototype)
        : ScriptObject(vtable, prototype) /*,
                                            owner_giid(0) */ {}

    PromiseObject::~PromiseObject()
    {
        if ((get_m_async() == NULL) && !noCollection) {
            GCRef<shell_toplevelClassManifest> shellClasses = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses;
            if (shellClasses != NULL) {
                // if it's not NULL then it will not become NULL until
                // the end of this method as GC will not run during
                // that time
                
                GCRef<PromiseClass> promiseClass = shellClasses->get_PromiseClass();
                if (!promiseClass->allRegisteredChannelsDestroyed()) {
                    Atom a = promiseClass->gcDelayedPromises->getUintProperty(gpid);
                    promiseClass->sendDestroyMessage(gpid, a);
                    if (!AvmCore::isNullOrUndefined(a))
                        promiseClass->gcDelayedPromises->setUintProperty(gpid, nullObjectAtom);
                }
            }
        }
    }

    bool PromiseObject::isOwnedLocally()
    {
        return (owner_giid == core()->getIsolate()->desc);
    }

    // collection needs to be delayed until remote proxies for all
    // "fresh" promises (representing a single "original" one) are
    // created on a given worker; we then collect the list of fresh
    // promise gpids and send it to the worker upon the original
    // promise destruction to signal that the original remote proxy
    // can be collected
    void PromiseObject::delayCollection(uint32_t fresh_gpid)
    {
        AvmAssert(!get_m_async()->noCollection); // it should already be scheduled for collection - simply delay it
        GCRef<PromiseClass> promiseClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_PromiseClass();
        Atom a = promiseClass->gcDelayedPromises->getUintProperty(gpid);
        ArrayObject* fresh_gpids;
        if (AvmCore::isNullOrUndefined(a)) {
            ArrayClass* arrayClass = toplevel()->arrayClass();
            fresh_gpids = ArrayObject::create(core()->gc, arrayClass->ivtable(), arrayClass->prototypePtr(), 0);
            promiseClass->gcDelayedPromises->setUintProperty(gpid, fresh_gpids->toAtom());
        }
        else {
            fresh_gpids = (ArrayObject*)AvmCore::atomToScriptObject(a);
        }
        Atom gpid_a = core()->uintToAtom(fresh_gpid);
        fresh_gpids->AS3_push(&gpid_a, 1);
    }


    Atom PromiseObject::getMultinameProperty(const Multiname* name) const
    {
        using namespace avmshell;
        GCRef<PromiseClass> promiseClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_PromiseClass();
        if (get_m_async() != NULL) {
            return ScriptObject::getMultinameProperty(name);
        }
        GCRef<EnvelopeClass> envelopeClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_EnvelopeClass();
        GCRef<EnvelopeObject> envelope = envelopeClass->constructObject(0).staticCast<EnvelopeObject>();
        envelope->m_multiname = *name;
        Atom argv[] = { atom(), envelope->toAtom()  }; 
        return promiseClass->m_getProperty->coerceEnter(1, argv);
    }

    Atom PromiseObject::callProperty(const Multiname*  name, int argc, Atom* argv)
    {
        using namespace avmshell;
        GCRef<PromiseClass> promiseClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_PromiseClass();
        if (get_m_async() != NULL) {
            return ScriptObject::callProperty(name, argc, argv);
        }
        
        GCRef<EnvelopeClass> envelopeClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_EnvelopeClass();
        GCRef<EnvelopeObject> envelope = envelopeClass->constructObject(argc - 1).staticCast<EnvelopeObject>();
        envelope->m_multiname = *name;
        //core()->console << "created for property " << *name << " length " << argc << "\n";
        envelope->set_length(argc);
        for (int i = 1; i <= argc; i++)
        {
            envelope->setUintProperty(i - 1, argv[i]);
        }
        Atom proxy_argv[] = { atom(), envelope->toAtom() };
        return promiseClass->m_callProperty->coerceEnter(1, proxy_argv);
    }

    ScriptObject* PromiseObject::cloneNonSlots(ClassClosure* targetClosure, Cloner& cloner) const
    {
        GCRef<PromiseObject> clone = static_cast<PromiseClass*>(targetClosure)->constructObject().staticCast<PromiseObject>();
        PromiseChannelObject* m_out = (PromiseChannelObject*)cloner.cloneScriptObject(get_m_async()->get_m_out());
        PromiseChannelObject* m_in = (PromiseChannelObject*)cloner.cloneScriptObject(get_m_async()->get_m_inc());
        Atom m_resolved = cloner.cloneAtom(get_m_async()->get_m_resolved());

        //clone->owner_giid = owner_giid;
        clone->gpid = gpid;        
        //[redundant]// clone->set_m_out(m_out);
        //[redundant]// clone->set_m_inc(m_in);
        //[redundant]// clone->set_m_resolved(m_resolved);
        //clone->set_m_global(get_m_global());
        //clone->set_m_package(get_m_package());
        //[redundant]// clone->set_m_state(get_m_async()->get_m_state());
        //clone->set_m_empty(get_m_empty());
        //clone->noCollection = true;

        GCRef<PromiseObject> async = static_cast<PromiseClass*>(targetClosure)->constructObject().staticCast<PromiseObject>();
        async->owner_giid = get_m_async()->owner_giid;
        async->gpid = gpid;        
        async->set_m_out(m_out);
        async->set_m_inc(m_in);
        async->set_m_resolved(m_resolved);
        async->set_m_global(get_m_async()->get_m_global());
        //[redundant]// async->set_m_package(get_m_package());
        async->set_m_state(get_m_async()->get_m_state());
        async->set_m_empty(get_m_async()->get_m_empty());
        async->noCollection = true;

        clone->set_m_async(async);

        async->set_m_async(NULL);

        return clone;
    }    


    RemoteProxyClass::RemoteProxyClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {                    
        createVanillaPrototype();
        
        m_checkForCallRequests = PromiseClass::initOneMethodEnv(cvtable, "checkForCallRequests");
        Isolate* ent = core()->getIsolate();

        ArrayClass* arrayClass = toplevel()->arrayClass();
        ArrayObject *remoteProxiesArray = ArrayObject::create(core()->gc, arrayClass->ivtable(), arrayClass->prototypePtr(), 1);
        set_m_remote_proxies(remoteProxiesArray);

        // channels, if initialized, are passed from the user level
        // and are not meant to be used to initialize a proxy
        if (ent->isPrimordial()) return;

        FixedHeapArray<FixedHeapRef<PromiseChannel> >& channels = ent->m_initialChannels;
        if (channels.length == 0) {
            // May be an additional toplevel (new security domain), initial channels already deallocated.
            // TODO verify that Promises are really unusable but don't crash.
            return;
        }
        AvmAssert(channels.length == 2);
        FixedHeapRef<PromiseChannel>& incChannel = channels.values[0];
        FixedHeapRef<PromiseChannel>& outChannel = channels.values[1];

        // registered during worker initialization, but may be already
        // closed if this worker's creator is already trying to shut
        // it down (and just closed the channels)
        AvmAssert(incChannel->isClosed() || incChannel->gc() != NULL);

        // the global id of current worker's proxy (and thus its slot
        // in the array of proxies initialized below) is always 0


        RemoteProxyObject* toplevelProxy = createWithGID(outChannel, incChannel, ent->m_global_gpid);
        toplevelProxy->set_m_resolved(nullObjectAtom);
        toplevelProxy->set_m_global(true);
        toplevelProxy->set_m_state(get_RECEIVED());
        
        toplevelProxy->refCount = 0;

        //toplevelProxy->set_m_package(false);

        channels.deallocate();
        // Initial channels deallocated, all subsequently created toplevels won't get them
        remoteProxiesArray->setUintProperty(toplevelProxy->get_m_gpid(), toplevelProxy->toAtom());
    }

    RemoteProxyObject* RemoteProxyClass::createWithGID(FixedHeapRef<PromiseChannel>& out,
                                                FixedHeapRef<PromiseChannel>& inc,
                                                uint32_t gid)
    {
        PromiseChannelClass* promiseChannelClass = toplevel()->builtinClasses()->get_PromiseChannelClass();

        PromiseChannelObject* outChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        outChannel->initializeWithChannel(out); 
        PromiseChannelObject* incChannel = (PromiseChannelObject*)promiseChannelClass->newInstance();
        incChannel->initializeWithChannel(inc); 

        GCRef<RemoteProxyObject> result = constructObject().staticCast<RemoteProxyObject>();

        result->set_m_out(outChannel);
        result->set_m_inc(incChannel);
        result->set_m_gpid(gid);

        return result;
    }

    bool RemoteProxyClass::createAndInsert(FixedHeapRef<PromiseChannel>& out,
                                           FixedHeapRef<PromiseChannel>& inc,
                                           uint32_t gid,
                                           uint32_t existingProxyGID)
    {
        ArrayObject* a = get_m_remote_proxies();
            
        // find proxy that resolves to the same object as the new one
        // should (both proxies are connected to different workers
        // and, as such, will be connected to different promises)
        uint32_t i=0;
        for (; i<a->getLength(); i++) {
            if (!AvmCore::isNullOrUndefined(a->getUintProperty(i))) {
                RemoteProxyObject* remoteProxy = 
                    (RemoteProxyObject*)AvmCore::atomToScriptObject(a->getUintProperty(i));
                if (remoteProxy->get_m_gpid() == existingProxyGID) {
                    GCRef<RemoteProxyObject> result = createWithGID(out, inc, gid);
                    result->set_m_resolved(remoteProxy->get_m_resolved());
                    result->set_m_global(remoteProxy->get_m_global());
                    //result->set_m_package(remoteProxy->get_m_package());
                    result->set_m_state(remoteProxy->get_m_state());
                    
                    AvmAssert(AvmCore::isNullOrUndefined(a->getUintProperty(gid)));
                    a->setUintProperty(gid, result->toAtom());

                    if (remoteProxy->refCount > 0) {
                        if (remoteProxy->refCount == 1) {
                            // last notifyOwner() request -- collect
                            a->setUintProperty(i, nullObjectAtom);
                        }
                        else {
                            // more notifyOwner() requests remaining before collection allowed
                            remoteProxy->refCount--;
                        }
                    }

                    return true;
                }
            }
        }
        // existing proxy for a given gpid not found because a remote
        // call that should have created it is not yet processed -- go
        // back to the event loop to process this request
        return false;
    }


    RemoteProxyObject* RemoteProxyClass::create(PromiseChannelObject* out,
                                                PromiseChannelObject* inc,
                                                uint32_t gid)
    {
        GCRef<RemoteProxyObject> result = createWithGID(out->m_channel, inc->m_channel, gid);
        result->set_m_resolved(nullObjectAtom);
        result->set_m_global(false);
        result->set_m_state(get_NEW());
        
        result->refCount = 0;

        //result->set_m_package(false);

        return result;
    }

    GCRef<ClassClosure> RemoteProxyClass::get_m_workerClass()
    {
        return toplevel()->workerClass();
    }

    bool RemoteProxyClass::checkForCallRequestsInternal()
    {
        Atom argv[1] = { this->atom() };
        const int argc = 0;
        Atom result = m_checkForCallRequests->coerceEnter(argc, argv);
        if (result == falseAtom) {
            // suspend until any request appears
            // in which case all waiters will be resumed
            Isolate* isolate = core()->getIsolate();
            Aggregate* aggregate = isolate->getAggregate();
            if (!aggregate->waitForAnySend(isolate, toplevel(), false))
                return false;
        }
        return true;
    }


    /*
    // Move to Toplevel?
    uint32_t RemoteProxyClass::isPackageOrPackagePrefix(Stringp fullName)
    {
        AvmAssert(toplevel()->scriptEnvCount() > 0);
        bool isPrefix = false;
        for (int j = toplevel()->scriptEnvCount()-1; j >= 0; j--) {
            PoolObject* pool = toplevel()->scriptEnv(j)->method->pool();
            for (uint32_t i = 1;i < pool->cpool_ns.length(); i++ ) {
                GCRef<Namespace> ns = pool->getNamespace(i);
                Stringp s = ns->getURI();
                if (ns->getType() == Namespace::NS_Public) {
                    if (s->equals(fullName)) {
                        return get_IS_PACKAGE();
                    } else if (!isPrefix && s->indexOf(fullName) == 0) {
                        isPrefix = true;
                    }
                }
            }
        }
        return isPrefix ? get_IS_PACKAGE_PREFIX() : get_NO_PACKAGE();
    }
    */

    /*
    // Move to Toplevel?
    Atom RemoteProxyClass::getVar(Stringp prefix, Stringp name)
    {
        AvmAssert(toplevel()->scriptEnvCount() > 0);
        for (int j = toplevel()->scriptEnvCount()-1; j >= 0; j--) {
            ScriptEnv* scriptEnv = toplevel()->scriptEnv(j);
            ScriptObject* globalObj = scriptEnv->global;
            if (!globalObj) continue; // FIXME revisit correctness of this?
            PoolObject* pool = scriptEnv->method->pool();

            for (uint32_t i = 1; i < pool->cpool_ns.length(); i++ ) {
                GCRef<Namespace> ns = pool->getNamespace(i);
                Stringp s = ns->getURI();
                if (ns->getType() == Namespace::NS_Public && s->equals(prefix)) {
                    Multiname varName(ns, core()->internString(name));
                    // Why not globalObj->getMultinameProperty() ?
                    if (toplevel()->hasproperty(globalObj->atom(), &varName, toplevel()->toVTable(globalObj->atom()))) {
                        return toplevel()->getproperty(globalObj->atom(), &varName, toplevel()->toVTable(globalObj->atom()));
                    }
                }
            }
        }
        core()->throwAtom(core()->concatStrings(String::createLatin1(core(), "Promise's variable not found: "), core()->concatStrings(prefix, name))->toAtom());
        return nullObjectAtom;
    }
    */

    /*
    Atom RemoteProxyClass::callFunction(Stringp prefix, Stringp name, ArrayObject* args)
    {        
        MMgc::GC::AllocaAutoPtr _atomArgs;
        int argsLen = args->getLength();
        Atom* atomArgs = (Atom*)VMPI_alloca(core(), _atomArgs, sizeof(Atom)*(argsLen+1));
        for (int32_t i = 0; i < argsLen; i++ )
            atomArgs[i+1] = args->getUintProperty(i);

        AvmAssert(toplevel()->scriptEnvCount() > 0);
        for (int j = toplevel()->scriptEnvCount() - 1; j >= 0; j--) {
            ScriptEnv* scriptEnv = toplevel()->scriptEnv(j);
            PoolObject* pool = scriptEnv->method->pool();
            ScriptObject* globalObj = scriptEnv->global;
            if (!globalObj) continue; // FIXME revisit correctness of this?            
            Atom globalObjAtom = globalObj->toAtom();
            atomArgs[0] = globalObjAtom;
                        
            // TODO: if someone knows a better way to call properties
            // here, it would be great
            if (prefix->equals(core()->kEmptyString)) {
                // find the private namespace of the script's global
                // environment and try calling method in its context
                for (uint32_t i = 1; i < pool->cpool_ns.length(); i++ ) {
                    if (pool->getNamespace(i)->isPrivate()) {
                        Multiname functionName(pool->getNamespace(i), core()->internString(name));
                        if (toplevel()->hasproperty(globalObjAtom, &functionName, toplevel()->toVTable(globalObjAtom))) {
                            return toplevel()->callproperty(globalObjAtom, &functionName, argsLen, atomArgs, toplevel()->toVTable(globalObjAtom));
                        }
                    }
                }
            }

            // find the namespace of the package (possibly unnamed) and try calling method in its context
            for (uint32_t i = 1; i < pool->cpool_ns.length(); i++ ) {
                GCRef<Namespace> ns = pool->getNamespace(i);
                Stringp s = ns->getURI();
                if (ns->getType() == Namespace::NS_Public && s->equals(prefix)) {
                    Multiname functionName(ns, core()->internString(name));
                    if (toplevel()->hasproperty(globalObjAtom, &functionName, toplevel()->toVTable(globalObjAtom))) {
                        return toplevel()->callproperty(globalObjAtom, &functionName, argsLen, atomArgs, toplevel()->toVTable(globalObjAtom));
                    }                
                }
            }
        }
        core()->throwAtom(core()->concatStrings(String::createLatin1(core(), "Promise's global method not found: "), core()->concatStrings(prefix, name))->toAtom());
        return nullObjectAtom;
    }
    */


    Atom RemoteProxyClass::getProp(Atom object, avmshell::EnvelopeObject* envelope)
    {
        const Multiname* mn = envelope->m_multiname;

        if (AvmCore::isNullOrUndefined(object)) {
            /*
            AvmAssert(toplevel()->scriptEnvCount() > 0);
            for (int j = toplevel()->scriptEnvCount() - 1; j >= 0; j--) {
                ScriptObject* globalObj = toplevel()->scriptEnv(j)->global;
                if (!globalObj) continue; // FIXME revisit correctness of this?            
                Atom global = globalObj->toAtom();
                if (toplevel()->hasproperty(global, &mn, toplevel()->toVTable(global))) {
                    return toplevel()->getproperty(global, &mn, toplevel()->toVTable(global));
                }
            }
            */
            AvmAssert(toplevel()->scriptEnvCount() > 0);
            Atom global = toplevel()->scriptEnv(0)->finddef(mn)->toAtom();
            return toplevel()->getproperty(global, mn, toplevel()->toVTable(global));
        } else if (toplevel()->hasproperty(object, mn, toplevel()->toVTable(object))) {
            return toplevel()->getproperty(object, mn, toplevel()->toVTable(object));
        }
        core()->throwAtom(core()->concatStrings(String::createLatin1(core(), "Promise's property not found: "),
                                                mn->getName())
                          ->toAtom());
        return nullObjectAtom;
    }

    Atom RemoteProxyClass::callProp(Atom object, avmshell::EnvelopeObject* envelope)
    {
     	const Multiname* mn = envelope->m_multiname;
        ArrayObject* args = envelope;
        MMgc::GC::AllocaAutoPtr _atomArgs;
        int argsLen = args->getLength();
        //core()->console << "callProp on " << envelope->m_multiname << "/" << envelope->get_length() << "\n";
        Atom* atomArgs = (Atom*)VMPI_alloca(core(), _atomArgs, sizeof(Atom)*(argsLen+1));
        for (int32_t i = 0; i < argsLen; i++ )
            atomArgs[i+1] = args->getUintProperty(i);
        
        if (AvmCore::isNullOrUndefined(object)) { 
            /*
            AvmAssert(toplevel()->scriptEnvCount() > 0);
            for (int j = toplevel()->scriptEnvCount() - 1; j >= 0; j--) {
                ScriptObject* globalObj = toplevel()->scriptEnv(j)->global;
                if (!globalObj) continue; // FIXME revisit correctness of this?            
                Atom global = globalObj->toAtom();
                atomArgs[0] = global;
                if (toplevel()->hasproperty(global, &mn, toplevel()->toVTable(global))) {
                    return toplevel()->callproperty(global, &mn, argsLen, atomArgs, toplevel()->toVTable(global));
                }
            } 
            */
            AvmAssert(toplevel()->scriptEnvCount() > 0);
            Atom global = toplevel()->scriptEnv(0)->finddef(mn)->toAtom();
            atomArgs[0] = global;
            Atom result = toplevel()->callproperty(global, mn, argsLen, atomArgs, toplevel()->toVTable(global));
            return result;
        } else if (toplevel()->hasproperty(object, mn, toplevel()->toVTable(object))) {
            atomArgs[0] = object;
            return toplevel()->callproperty(object, mn, argsLen, atomArgs, toplevel()->toVTable(object));
        }
        core()->throwAtom(core()->concatStrings(String::createLatin1(core(), "Promise's method not found: "),
                                                mn->getName())
                          ->toAtom());
        return nullObjectAtom;
    }

    /*
    Atom RemoteProxyClass::getGlobalVar(Stringp name)
    {
        AvmAssert(toplevel()->scriptEnvCount() > 0);
        for (int j = toplevel()->scriptEnvCount()-1; j >= 0; j--) {
            ScriptObject* globalObj = toplevel()->scriptEnv(j)->global;
            if (!globalObj) continue; // FIXME revisit correctness of this?
            GCRef<Traits> t = globalObj->traits();
            TraitsBindingsp tb = t->getTraitsBindings();
            StTraitsBindingsIterator iter(tb);
            while (iter.next()) {
                if (iter.key() && iter.key()->equals(name)) {
                    Binding b = iter.value();
                    if (AvmCore::isSlotBinding(b)) {
                        uint32_t slot =  AvmCore::bindingToSlotId(b);
                        return globalObj->getSlotAtom(slot);
                    } else if (AvmCore::isAccessorBinding(b)) {                    
                        // FIXME getter/setter binding?
                        int m = AvmCore::bindingToGetterId(b);
                        VTable* vtable = toplevel()->toVTable(globalObj->toAtom());
                        MethodEnv *f = vtable->methods[m];
                        return f->coerceEnter(globalObj->toAtom());
                    }
                }
            }
        }
        core()->throwAtom(core()->concatStrings(String::createLatin1(core(), "Promise's global variable not found: "), name)->toAtom());
        return nullObjectAtom;
    }
    */

    RemoteProxyObject::RemoteProxyObject(VTable* vtable, ScriptObject* prototype)
        : ScriptObject(vtable, prototype) {}

    void RemoteProxyObject::triggerDelayedCollection(Atom a)
    {
        ArrayObject* fresh_gpids = (ArrayObject*)AvmCore::atomToScriptObject(a);
        GCRef<RemoteProxyClass> remoteProxyClass = static_cast<avmshell::ShellToplevel*>(toplevel())->shellClasses->get_RemoteProxyClass();
        ArrayObject* remote_proxies = remoteProxyClass->get_m_remote_proxies();
        AvmAssert(refCount == 0);
        AvmAssert(fresh_gpids->get_length() > 0);
        do {
            Atom gpid_a = fresh_gpids->AS3_pop();
            uint32_t gpid= AvmCore::toUInt32(gpid_a);
            if (AvmCore::isUndefined(remote_proxies->getUintProperty(gpid))) {
                // notifyOwner() not processed yet (non-null -
                // processed, null - processed and collected)
                refCount++;
            }
        } while (fresh_gpids->get_length() > 0);
        if (refCount == 0) {
            // all notifyOwner() requests processed
            remote_proxies->setUintProperty(this->get_m_gpid(), nullObjectAtom);
        }
        
    }

    void RemoteProxyObject::setState(uint32_t state)
    {
        this->set_m_state(state);
    }

 
}

namespace avmshell {

    String* EnvelopeObject::get_name()
    {
        return m_multiname.getName();
    }

    ScriptObject* EnvelopeObject::cloneNonSlots(ClassClosure* targetClosure, Cloner& cloner) const
    {
        uint32_t length = get_length();
        AvmCore* targetCore = targetClosure->core();
        EnvelopeObject* newEnvelope = EnvelopeObject::create(targetCore->gc, 
                                                             targetClosure->ivtable(), 
                                                             targetClosure->prototypePtr(), 
                                                             length);
        newEnvelope->set_length(length);

        cloner.cloneMultiname(core(), m_multiname, newEnvelope->m_multiname);
        for (unsigned i = 0; i < length; i++) {
            newEnvelope->setUintProperty(i, cloner.cloneAtom(this->getUintProperty(i)));
        }
        return newEnvelope;

    }

}
