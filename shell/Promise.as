/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

package flash.system
{
    include "../core/api-versions.as"

    import flash.utils.flash_proxy;
    import flash.utils.Proxy;



    public final class PromiseState
    {
        public static const NEW:String = "new";
        public static const RECEIVED:String = "received";
        public static const BROKEN:String = "broken"; // system
        public static const EXCEPTION:String = "exception"; // user        
    }


    
    [native(cls="::avmplus::PromiseHelperClass", /*gc="exact",*/ methods="auto")]
    final class PromiseHelper
    {
        // The class itself is not accessible externally so all his
        // members can be public even though some of them don't have
        // to

        public static const CALL_REQUEST:uint = 0;
        public static const RESOLUTION_REQUEST:uint = 1;
        public static const CALLBACK_REQUEST:uint = 3;
        public static const GETPROP_REQUEST:uint = 4;

        public static const DESTROY_REQUEST:uint = 5;
        public static const DESTROY_DELAYED_REQUEST:uint = 6;

        public static const SUCCESS_RESPONSE:uint = 0;
        public static const EXCEPTION_RESPONSE:uint = 1;

        public native static function get currentGiid():int;
        public native static function getPromiseOwnerGiid(p:Promise):int;
        public native static function setPromiseOwnerGiid(p:Promise, giid:int):void;
        public native static function getPromiseGid(p:Promise):uint;
        public native static function setPromiseGid(p:Promise, gpid:uint):void;
        public native static function isPromiseEmpty(p:Promise):Boolean;
        public native static function schedulePromiseCollection(p:Promise):void;
        public native static function retargetIncChannel(ch:PromiseChannel, senderGiid:int, receiverGiid:int):void;
        public native static function retargetOutChannel(ch:PromiseChannel, receiverGiid:int, senderGiid:int):void;

        public static function isPromiseCreatedLocally(p:Promise, giid:int):Boolean
        {
            return getPromiseOwnerGiid(p) == giid;
        }

        // all empty promises for a given worker (indexed by m_gpid)
        public static var m_empty_promises:Array = new Array();
        // asynchronous handlers scheduled for local promises
        public static var m_local_requests:Vector.<Object> = new Vector.<Object>();
        // asynchronous handlers scheduled for promises that used to be empty
        public static var m_delayed_requests:Vector.<Object> = new Vector.<Object>();

        // wait for any send directed to a given worker;
        static native function waitForAnySend(block:Boolean):Boolean;

        // debugging only
        public static native function pr(s :String) :void;
        public static native function praddr(o :Object) :void;
        public static native function breakOn(o:*):void;
    }


    [native(cls="::avmplus::PromiseClass", instance="::avmplus::PromiseObject", methods="auto", construct="native")]
    public final dynamic class Promise
    {
        public native function isOwnedLocally():Boolean;

        // Dynamic because it has methods that are not statically declared

        public static function wrap(local:Object):Promise
        {
            if (local is Promise) {
                // flatten
                return local;
            }

            // don't put it into m_remote_proxies as we are not going to
            // listen on this one for remote requests
            return createLocal(local, false);
        }

        public static function empty():Promise
        {
            // don't put it into m_remote_proxies as we are not going to
            // listen on this one for remote requests
            var p:Promise =  createLocal(null, true);
            registerEmptyPromise(p, PromiseHelper.currentGiid);
            PromiseHelper.m_empty_promises[PromiseHelper.getPromiseGid(p)] = p;
            return p;
        }

        private function callProperty(envelope:Envelope):*
        {
            //m_async = this;
            var args:Array = envelope;
            if (envelope.name == "toString")
            {
                return "[Promise]";
            }
            if (m_empty)
                throw "cannot call methods on explicitly unresolved promise";
            if (isOwnedLocally())
            {
                for (var i:int = 0; i < args.length; i++)
                {
                    if ((args[i] is Promise) &&
                        PromiseHelper.isPromiseCreatedLocally(args[i], PromiseHelper.currentGiid))
                    {
                        // by analogy to globalPromise.receive(),
                        // promise representing global scope resolves
                        // to null
                        if (args[i].m_async.m_global)
                            args[i] = null;
                        else
                            args[i] = args[i].m_async.intern::m_resolved;
                    }
                }
                return wrap(RemoteProxy.callProp(intern::m_resolved, envelope));
            }
            try
            {
                // create a promise representing the result
                var out = new PromiseChannel(m_out.sender, m_out.receiver);
                var inc = new PromiseChannel(m_inc.sender, m_inc.receiver);
                var res:Promise = create(out, inc);
                m_out.send(PromiseHelper.CALL_REQUEST);
                m_out.send(inc);
                m_out.send(out);
                m_out.send(PromiseHelper.getPromiseGid(res));

                // process arguments of type Promise
                for (var i:int = 0; i < args.length; i++)
                {
                    if ((args[i] is Promise))
                    {
                        /*
                        if (args[i].m_package)
                        {
                            throw "packages cannot be used as remote function arguments";
                        }
                        */

                        // args[i] is either:
                        // a) a locally created promise representing
                        // object on the callee (do nothing as it
                        // will be resolved locally when processing
                        // arguments on the callee's side), or
                        // b) a locally created promise representing
                        // object on some worker W different than the
                        // callee - create a promise on caller
                        // connecting to a proxy on W
                        // c) an empty promise created by the current
                        // worker - simply pass it on (empty promises
                        // are passed on by copy until one of them is
                        // resolved in which case the runtime turns
                        // all empty promise copies into "regular"
                        // resolved promises)

                        if (PromiseHelper.isPromiseCreatedLocally(args[i], m_out.receiver))
                        {
                            if (args[i].m_async.m_global)
                            {
                                throw "promises representing global scope cannot be passed to the worker owning that scope";
                            }
                            continue;
                        }

                        if (!args[i].m_async.m_empty)
                        {
                            // if passing a regular promise, create
                            // a "fresh" promise representing worker W's
                            // object on the callee 
                            var ownerGiid:int = PromiseHelper.getPromiseOwnerGiid(args[i]);
                            var out:PromiseChannel = new PromiseChannel(m_out.receiver, ownerGiid);
                            var inc:PromiseChannel = new PromiseChannel(ownerGiid, m_inc.sender);

                            var fresh:Promise = create(out, inc);
                            fresh.m_async.m_global = args[i].m_async.m_global;
                            //fresh.m_package = args[i].m_package;
                            fresh.async.m_empty = args[i].m_async.m_empty;

                            if (PromiseHelper.isPromiseCreatedLocally(args[i], PromiseHelper.currentGiid))
                            {
                                // if args[i] represents a local
                                // object create a remote proxy
                                // (locally) that will be connected
                                // with previously create fresh
                                // promise
                                var remoteProxy:RemoteProxy = 
                                    RemoteProxy.create(fresh.m_async.m_inc, fresh.m_async.m_out, PromiseHelper.getPromiseGid(fresh));
                                remoteProxy.m_resolved = args[i].m_async.intern::m_resolved;
                                remoteProxy.m_state = args[i].m_async.intern::m_state;
                                remoteProxy.m_global = args[i].m_async.m_global;
                                RemoteProxy.m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                            }
                            else {
                                // if args[i] represents an object
                                // residing in some worker W, it
                                // should not be collected (as in such
                                // case args[i]'s object could already
                                // be collected as well) before the
                                // fresh promise is "connected" with
                                // this object via its own proxy
                                args[i].delayCollection(PromiseHelper.getPromiseGid(fresh));
                                notifyOwner(PromiseHelper.getPromiseGid(args[i]),
                                            PromiseHelper.getPromiseGid(fresh),
                                            fresh.m_async.m_out,
                                            fresh.m_async.m_inc);
                            }
                            args[i] = fresh;
                        }
                    }
                }

                m_out.send(envelope);

                PromiseHelper.schedulePromiseCollection(res);
                // what happens if a call on "res" will be triggered
                // before CALL_REQUEST is processed? the answer is -
                // nothing bad, as the promise on the callee side is
                // not going to be inserted into m_remote_proxies and, thus,
                // call request will will simply sit in the channel
                // until that happens
                return res;
            }
            catch (e) {
                intern::m_resolved = e;
                intern::m_state = BROKEN;
                throw e;
            }
            return null;
        }

        private function getProperty(envelope:Envelope):*
        {
            if (m_empty)
                throw "cannot call methods on explicitly unresolved promise";
            if (isOwnedLocally())
            {
                return wrap(RemoteProxy.getProp(intern::m_resolved, envelope));
            }
            try
            {
                // create a promise representing the result
                var res:Promise;
                var out = new PromiseChannel(m_out.sender, m_out.receiver);
                var inc = new PromiseChannel(m_inc.sender, m_inc.receiver);
                res = create(out, inc);
                m_out.send(PromiseHelper.GETPROP_REQUEST);
                m_out.send(inc);
                m_out.send(out);
                m_out.send(PromiseHelper.getPromiseGid(res));
                m_out.send(envelope);

                PromiseHelper.schedulePromiseCollection(res);
                return res;
            }
            catch (e) {
                intern::m_resolved = e;
                intern::m_state = BROKEN;
                throw e;
            }
            return null;
        }

        // Promise's m_gpid has been made native as it may have to be
        // accessed after the AS object is already GC-ed
        //        private var m_gpid:uint;
        var m_out:PromiseChannel;
        var m_inc:PromiseChannel;
        intern var m_resolved:Object;
        private var m_global:Boolean;

        intern var m_state:uint;
        private var m_empty:Boolean; // explicitly unresolved promise

        private var m_async:Promise;

        public function get async():Promise {
            // temporary hack to simulate local proxy; will be fixed later with refactoring
            /*
            m_async = null;
            return this;
            */
            return m_async;
        }

        public function resolve(o:Object):void
        {
            if (m_async.intern::m_resolved)
            {
                throw "an explicitly unresolved promise can be resolved only once";
            }
            m_async.intern::m_state = RECEIVED;
            m_async.intern::m_resolved = o;
            PromiseHelper.m_empty_promises[PromiseHelper.getPromiseGid(this)] = null;
            // notify all owners of empty promises that are "siblings"
            // of the current one (siblings in the sense of really
            // being an instance of the same original empty promise
            // passed around between different workers without being
            // resolved)
            notifyEmptyOwners(this);
            // this particular promise instance becomes a local promise to this worker
            PromiseHelper.setPromiseOwnerGiid(this, PromiseHelper.currentGiid);
            m_async.m_empty = false;
        }

        public function when(success:Function, fault:Function = null):void
        {
            if (PromiseHelper.isPromiseCreatedLocally(this, PromiseHelper.currentGiid))
            {
                PromiseHelper.m_local_requests.push({handler:success, p:this});
            }
            else if (m_async.m_empty)
            {
                var gpid:uint = PromiseHelper.getPromiseGid(this);
                var emptyRequests:Vector.<Object> = m_empty_requests[gpid];
                if (!emptyRequests) {
                    emptyRequests = new Vector.<Object>();
                    m_empty_requests[gpid] = emptyRequests;
                }
                emptyRequests.push({handler:success, p:this});
            }
            else {
                var thisPromise:Promise = this;
                function successCallbackFunction(res:Object, state:uint)
                {
                    m_async.intern::m_resolved = res;
                    m_async.intern::m_state = state;
                    //success(thisPromise);
                    success(res);
                }

                var faultCallbackFunction = null;
                if (fault != null)
                {
                    faultCallbackFunction = function(res:Object, state:uint)
                        {
                            m_async.intern::m_resolved = res;
                            m_async.intern::m_state = state;
                            //fault(thisPromise);
                            fault(res);
                        }
                }

                // "this" is a locally created promise representing an object
                // on the callee - connecting current worker with the
                // callee

                try
                {
                    // create a remote proxy to be callback's target
                    // and a respective promise to be sent to "the
                    // other side" to be used to trigger callback
                    var out = new PromiseChannel(m_async.m_out.receiver, m_async.m_out.sender);
                    var inc = new PromiseChannel(m_async.m_inc.receiver, m_async.m_inc.sender);
                    var callbackPromise:Promise = create(out, inc);
                    var callbackRemoteProxy:RemoteProxy = RemoteProxy.create(inc, out, PromiseHelper.getPromiseGid(callbackPromise));

                    m_async.m_out.send(PromiseHelper.CALLBACK_REQUEST);
                    m_async.m_out.send(callbackPromise);
                    callbackRemoteProxy.m_state = RECEIVED;
                    callbackRemoteProxy.m_resolved =
                        { successCallback: successCallbackFunction,
                          faultCallback: faultCallbackFunction };
                    RemoteProxy.m_remote_proxies[PromiseHelper.getPromiseGid(callbackPromise)] = callbackRemoteProxy;
                }
                catch (e) {
                    m_async.intern::m_state = BROKEN;
                    if (fault != null)
                    {
                        // communication with the callee failed - in order
                        // to trigger execution of the (fault) handler
                        // schedule it locally
                        PromiseHelper.m_local_requests.push({handler:fault, p:this});
                    }
                }
            }
        }

        public function receive():*
        {
            if (m_async.m_global)
                return null; // promises represeting global scope do not resolve to anything useful
                
            while (m_async.m_empty)
            {
                if (m_async.intern::m_state == RECEIVED) // resolved locally
                    return m_async.intern::m_resolved;
                if (!RemoteProxy.checkForCallRequestsConditional(false))
                {
                    // wait for send can be recursively invoked by
                    // checkForCallRequestsConditional() -- we need to break out
                    // before it's invoked again and the worker
                    // suspended
                    if (!m_async.m_empty) 
                        break;
                    // suspend until any request appears
                    // in which case all waiters will be resumed
                    if (!PromiseHelper.waitForAnySend(true))
                        throw "worker terminated while waiting for empty promise send";
                }
            }
            if (m_async.intern::m_resolved == null)
            {
                try
                {
                    m_async.m_out.send(PromiseHelper.RESOLUTION_REQUEST);
                    // while waiting for resolution, drop to the
                    // event loop - perhaps resolution depends on
                    // the callback
                    while (!m_async.m_inc.available())
                    {
                        if (!RemoteProxy.checkForCallRequestsConditional(false))
                        {
                            // suspend until any request appears
                            // in which case all waiters will be resumed
                            if (!PromiseHelper.waitForAnySend(true))
                                throw "worker terminated while waiting for promise resolution";
                        }
                    }
                    var response:uint  = m_async.m_inc.receive();
                    if (response == PromiseHelper.EXCEPTION_RESPONSE)
                    {
                        m_async.intern::m_resolved = m_async.m_inc.receive();
                        m_async.intern::m_state = EXCEPTION;
                        throw m_async.intern::m_resolved;
                    }
                    else {
                        m_async.intern::m_resolved = m_async.m_inc.receive();
                        m_async.intern::m_state = RECEIVED; 
                        // fall through to returning intern::m_resolved;
                    }
                }
                catch (e) {
                    m_async.intern::m_resolved = e;
                    m_async.intern::m_state = BROKEN;
                    throw e;
                }
            }
            else { // value already retrieved from the remote worker
                if (m_async.intern::m_state == EXCEPTION || m_async.intern::m_state == BROKEN)
                {
                    throw m_async.intern::m_resolved;
                }
            }

            return m_async.intern::m_resolved;
        }


        private static function resolveLocal(p:Promise):Object
        {
            var res:RemoteProxy = RemoteProxy.m_remote_proxies[PromiseHelper.getPromiseGid(p)];
            return res.m_resolved;
        }

        public static native function registerEmptyPromise(p:Promise, creatorGiid:int):void;

        // debugging
        private static native function printEmptyPromises():void;

        //private static native function isGlobal(o:Object):Boolean;

        private static native function create(out:PromiseChannel, inc:PromiseChannel):Promise;

        private static native function createLocal(o:Object, empty:Boolean):Promise;

        public static native function notifyOwner(resolvedPromiseGID:uint,
                                                  freshPromiseGID:uint,
                                                  out:PromiseChannel,
                                                  inc:PromiseChannel):void;

        private static native function notifyEmptyOwners(p:Promise):void;

        public native function delayCollection(fresh_gpid:uint):void;

        public function get state():String
        {
            switch (m_async.intern::m_state)
            {
                case Promise.NEW:
                return PromiseState.NEW;
                case Promise.RECEIVED:
                return PromiseState.RECEIVED;
                case Promise.BROKEN:
                return PromiseState.BROKEN;
                case Promise.EXCEPTION:
                return PromiseState.EXCEPTION;
                default:
                throw new Error("unknown state");
            }
        }

        public static const NEW:uint = 0;
        public static const RECEIVED:uint = 7;
        public static const BROKEN:uint = 6; // system
        public static const EXCEPTION:uint = 8; // user

        private static const DESTROY_REQUEST:uint = PromiseHelper.DESTROY_REQUEST;
        private static const DESTROY_DELAYED_REQUEST:uint = PromiseHelper.DESTROY_DELAYED_REQUEST;

        // asynchronous handlers for empty promises (indexed by m_gpid)
        private static var m_empty_requests:Array = new Array();

        /**
         * Temporary - debugging only
         */
        public function getPID() :uint
        {
            return PromiseHelper.getPromiseGid(this);
        }
    }

    namespace intern;

    [native(cls="::avmplus::RemoteProxyClass", /*gc="exact",*/ instance="::avmplus::RemoteProxyObject", methods="auto", construct="native")]
    final class RemoteProxy
    {        

        // The class itself is not accessible externally so all his
        // members can be public even though some of them don't have
        // to

        public static const NEW:uint = Promise.NEW;
        public static const RECEIVED:uint = Promise.RECEIVED;
        public static const BROKEN:uint = Promise.BROKEN;
        public static const EXCEPTION:uint = Promise.EXCEPTION;

        //public static const NO_PACKAGE:uint = 0;
        //public static const IS_PACKAGE:uint = 1;
        //public static const IS_PACKAGE_PREFIX:uint = 2;


        // initialized natively as it must be initialized early
        public static var m_remote_proxies:Array;

        public var m_gpid:uint;
        public var m_out:PromiseChannel;
        public var m_inc:PromiseChannel;
        public var m_resolved:Object;
        public var m_global:Boolean;
        //public var m_package:Boolean;
        public var m_state:uint;

        public static native function create(out:PromiseChannel, inc:PromiseChannel, gpid:uint):RemoteProxy;

        public static native function get m_workerClass(): Class;

        //public static native function isPackageOrPackagePrefix(name:String):uint;

        //public static native function getVar(prefix:String, name:String):Object;

        //public static native function callFunction(prefix:String, name:String, args:Array):Object;

        //public static native function getGlobalVar(name:String):Object;

        public static native function callProp(object:*, envelope:Envelope):*;

        public static native function getProp(object:*, envelope:Envelope):*;

        public native function triggerDelayedCollection(o:*):void;

        public function handleResolution():void
        {
            if (m_state == RECEIVED)
            {
                m_out.send(PromiseHelper.SUCCESS_RESPONSE);
            }
            else {
                m_out.send(PromiseHelper.EXCEPTION_RESPONSE);
            }
            try {
                m_out.send(m_resolved);
            } catch (e) {
                // Send did not complete or link somehow closed.
                m_state = BROKEN; // FIXME review?
                m_out.sendCondThrow(null, false); // Don't throw if link closed.
            }
        }

        public function handleCallback():void
        {
            var returnPromise:Promise = m_inc.receive();
            if (m_inc.sender != PromiseHelper.currentGiid && m_out.receiver != PromiseHelper.currentGiid) {
                // retarget channels - for details see comment in
                // handleCall()
                var inc:PromiseChannel = returnPromise.async.m_out;
                var out:PromiseChannel = returnPromise.async.m_inc;
                PromiseHelper.retargetOutChannel(out, PromiseHelper.currentGiid, out.sender);
                PromiseHelper.retargetIncChannel(inc, PromiseHelper.currentGiid, inc.receiver);
            }
            // enable collection of an object this promise is pointing
            // to
            PromiseHelper.schedulePromiseCollection(returnPromise);
            if (m_state == RECEIVED)
                returnPromise.async.successCallback(m_resolved, m_state);
            else if (returnPromise.async.faultCallback != null)
                returnPromise.async.faultCallback(m_resolved, m_state);

        }

        private function flattenPromise(resPromise:Promise, inc:PromiseChannel, out:PromiseChannel, gpid:uint)
        {
            if (PromiseHelper.isPromiseEmpty(resPromise)) {
                throw "empty promises cannot be returned to a worker";
            }
            else if (PromiseHelper.isPromiseCreatedLocally(resPromise, inc.sender)) {
                throw "promises representing objects of a given worker cannot be returned to the same worker";
            }
            else if (PromiseHelper.isPromiseCreatedLocally(resPromise, PromiseHelper.currentGiid)) {
                // flatten locally - create a new proxy pointing to
                // the same object as the local promise
                var remoteProxy = create(out, inc, gpid);
                m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                remoteProxy.m_resolved = resPromise.async.intern::m_resolved;
                remoteProxy.m_state = resPromise.async.intern::m_state;
            }
            else {
                // flatten remotely - connect caller's promise with an
                // object on the remote worker (via a proxy that will
                // be created on that remote worker)
                
                resPromise.delayCollection(gpid);
                var owner:int = PromiseHelper.getPromiseOwnerGiid(resPromise);
                // "inc" is outgoing channel of the promise on the other end
                PromiseHelper.retargetOutChannel(inc, owner, inc.sender);
                // "out" is incoming channel of the promise on the other end
                PromiseHelper.retargetIncChannel(out, owner, out.receiver);
                Promise.notifyOwner(PromiseHelper.getPromiseGid(resPromise),
                                    gpid,
                                    inc, 
                                    out);
            }
        }

        public function handleCall():void
        {
            var remoteProxy:RemoteProxy = null;
            var communicationSuccess:Boolean = false;
            try
            {
                var out:PromiseChannel = m_inc.receive();
                var inc:PromiseChannel = m_inc.receive();
                if (m_inc.sender != PromiseHelper.currentGiid && m_out.receiver != PromiseHelper.currentGiid) {
                    // channel on which "out" and "inc" have been sent
                    // has been retargetted due to promise flattening

                    // "inc" is outgoing channel of the promise on the other end
                    PromiseHelper.retargetOutChannel(inc, PromiseHelper.currentGiid, inc.sender);
                    // "out" is incoming channel of the promise on the other end
                    PromiseHelper.retargetIncChannel(out, PromiseHelper.currentGiid, out.receiver);
                }
                var gpid:uint = m_inc.receive();
                var envelope:Envelope = m_inc.receive();
                var args:Array = envelope;
                communicationSuccess = true;

                for (var i = 0; i < args.length; i++)
                {
                    if (args[i] is Promise)
                    {
                        if (PromiseHelper.isPromiseEmpty(args[i]))
                        {
                            // we "intern" empty promises so that a
                            // given worker has only one empty promise
                            // with a given gpid
                            var localEmpty:Promise = PromiseHelper.m_empty_promises[PromiseHelper.getPromiseGid(args[i])];
                            if (localEmpty)
                            {
                                args[i] = localEmpty;
                            }
                            else {
                                Promise.registerEmptyPromise(args[i], PromiseHelper.currentGiid);
                                PromiseHelper.m_empty_promises[PromiseHelper.getPromiseGid(args[i])] = args[i];
                            }
                        }
                        else if (PromiseHelper.isPromiseCreatedLocally(args[i], PromiseHelper.currentGiid))
                        {
                            // look up local promises table and
                            // replace the promise being passed with
                            // an actual value
                            args[i] = Promise.wrap(m_remote_proxies[PromiseHelper.getPromiseGid(args[i])].intern::m_resolved);
                        }
                        else {
                            // enable collection of an object this
                            // promise is pointing to
                            PromiseHelper.schedulePromiseCollection(args[i]);
                        }
                    }
                }
                var result:*;
                if (m_global)// || m_package)
                {
                    /*
                    var prefix:String = "";
                    if (m_package)
                        prefix = m_resolved;
                        */
                    result = callProp(null, envelope); // callFunction(prefix, name, args);
                }
                else {
                    // may not be resolved as it may not reside in
                    // global scope or in an appropriate class or in
                    // an appropriate package
                    if (!m_resolved)
                        throw new ReferenceError("Remote method call error");
                        /*
                    if (!m_resolved[name])
                    {
                        throw "Remote method not found: "+name;
                    }
                    */
                    result = callProp(m_resolved, envelope); // m_resolved[name].apply(m_resolved, args);
                }
                // flatten
                if (result is Promise) {
                    flattenPromise(result, inc, out, gpid);
                }
                else { 
                    var remoteProxy:RemoteProxy = create(out, inc, gpid);
                    m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                    PromiseHelper.breakOn(result);
                    remoteProxy.m_resolved = result;
                    remoteProxy.m_state = RECEIVED;                    
                }
            }
            catch (e) {
                if (communicationSuccess) {
                    remoteProxy = create(out, inc, gpid);
                    m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                    remoteProxy.m_resolved = e;
                    remoteProxy.m_state = EXCEPTION;
                }
            }
        }

        public function handleGetProp():void
        {
            var communicationSuccess:Boolean = false;
            try
            {
                var out:PromiseChannel = m_inc.receive();
                var inc:PromiseChannel = m_inc.receive();
                if (m_inc.sender != PromiseHelper.currentGiid && m_out.receiver != PromiseHelper.currentGiid) {
                    // retarget channels - for details see comment in
                    // handleCall()
                    PromiseHelper.retargetOutChannel(inc, PromiseHelper.currentGiid, inc.sender);
                    PromiseHelper.retargetIncChannel(out, PromiseHelper.currentGiid, out.receiver);
                }
                var gpid:uint = m_inc.receive();
                var envelope:Envelope = m_inc.receive();
                communicationSuccess = true;

                var result:*;
                if (m_global) // || m_package)
                {
                    /*
                    var prefix:String = ""; 
                    if (m_package)
                        prefix = m_resolved+".";
                    var fullName:String = prefix+name;
                    var pckgRes:uint; // = isPackageOrPackagePrefix(fullName);
                    // check if what we are seeing is a full package
                    // name; this case takes precedence even if there
                    // exists a variable in the global scope with the
                    // same name as the full package name
                    if (pckgRes == IS_PACKAGE)
                    {
                        var remoteProxy = create(out, inc, gpid);
                        m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                        remoteProxy.m_resolved = fullName;
                        remoteProxy.m_package = true;
                        remoteProxy.m_state = RECEIVED;
                        return;
                    }
                    */

                    // if what we are seeing is not a full package
                    // name then check if we see a variable in the
                    // current context (either global scope or the
                    // package "discovered" so far
                    //try {
                        // TODO - there may be a prettier way, but if
                        // we want variables to return undefined
                        // values then we'd have to figure out some
                        // way (other than via undefined) of
                        // signalling that variable is not found
                        //if (m_global)
                            result = getProp(null, envelope); //getGlobalVar(name);
                        //else
                        //    result = getProp(null, multiname); //getVar(m_resolved, name);

                    //} catch (x) {
                        // if variable does not exist than the assumption
                        // is that we are still "discovering" the full
                        // package name, provided that we have so far
                        // discovered some package prefix
                        /*
                        if (pckgRes == IS_PACKAGE_PREFIX)
                        {
                            var remoteProxy = create(out, inc, gpid);
                            m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                            remoteProxy.m_resolved = fullName;
                            remoteProxy.m_package = true;
                            remoteProxy.m_state = RECEIVED;
                            return;
                        }
                        else { */
                            //throw new ReferenceError("Remote global value access error");
                        //}
                    //}
                }
                else {
                    // may not be resolved as it may not reside in
                    // global scope or in an appropriate class or in
                    // an appropriate package
                    if (!m_resolved)
                        throw new ReferenceError("Remote value access error");
                        /*
                    if (!m_resolved[name]) {
                        throw "Remote value not found: "+name;
                    }
                    */
                    result = getProp(m_resolved, envelope); //m_resolved[name];
                }
                // flatten
                if (result is Promise) {
                    flattenPromise(result, inc, out, gpid);
                }
                else { 
                    var remoteProxy:RemoteProxy = create(out, inc, gpid);
                    m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                    remoteProxy.m_resolved = result;
                    PromiseHelper.breakOn(result);
                    remoteProxy.m_state = RECEIVED;                    
                }
            }
            catch (e) {
                if (communicationSuccess) {
                    var remoteProxy:RemoteProxy = create(out, inc, gpid);
                    m_remote_proxies[remoteProxy.m_gpid] = remoteProxy;
                    remoteProxy.m_resolved = e;
                    remoteProxy.m_state = EXCEPTION;
                }
            }
        }

        // Called from native code
        public static function checkForCallRequestsConditional(loop:Boolean):Boolean
        {
            // Worker is undefined
            // this should result in a finddef, which should succeed in both shell and player
            if (m_workerClass.handleLifecycleEvents)
            {
                m_workerClass.handleLifecycleEvents();
            }

            if (m_remote_proxies == null)
            {
                // KP: FIXME
                // Aparently this function can be called before PromiseClass::PromiseClass is called,
                // which may cause m_remote_proxies to be uninitialized.
                return false;
            }
            var res:Boolean;
            var count:uint = 0;
            const MAX_REQUESTS:uint = 1024;
            while (count < MAX_REQUESTS) // in principle count could overflow
            {
                // wait for any does processing related to handling
                // argument promises and empty promises - needs to be
                // invoked periodically here (though without actually
                // waiting) for fairness (requests may rely on the
                // effects of this processing to be completed)
                PromiseHelper.waitForAnySend(false);
                res = false;
                // handle execution of handlers for all local promises
                for (var i = 0; i < PromiseHelper.m_local_requests.length; i++)
                {
                    var req:Object = PromiseHelper.m_local_requests.pop();
                    req.handler(req.p.async.intern::m_resolved);
                    count ++;
                    res = true;
                }
                // handle execution of handlers for all (now resolved) empty promises
                for (var i = 0; i < PromiseHelper.m_delayed_requests.length; i++)
                {
                    var req:Object = PromiseHelper.m_delayed_requests.pop();
                    req.p.receive();
                    req.p.when(req.handler);
                    count++;
                    res = true;
                }
                // we want to loop back to process requests for
                // proxies with lower gpids (otherwise we never get to
                // them if the number of proxies keeps growing which
                // may delay collection of remote proxies, possibly
                // indefinitely)
                var len = m_remote_proxies.length;
                for (var i = 0; i < len; i++)
                {
                    var remoteProxy:RemoteProxy = m_remote_proxies[i];
                    if (!remoteProxy)
                        continue;
                    var available:Boolean = true;
                    try
                    {
                        available = remoteProxy.m_inc.available();
                    }
                    catch (e) { // channel closed error, anything else?
                        remoteProxy.m_resolved = e;
                        remoteProxy.m_state = BROKEN;
                        // FIXME check when handler?
                        // FIXME how about shrinking the array?
                        m_remote_proxies[i] = null;
                        continue;
                    }
                    res ||= available;
                    if (available)
                    {
                        count ++;
                        var msg:uint = remoteProxy.m_inc.receive();

                        if (msg == PromiseHelper.RESOLUTION_REQUEST)
                        {
                            remoteProxy.handleResolution();
                        }
                        else if (msg == PromiseHelper.CALLBACK_REQUEST)
                        {
                            remoteProxy.handleCallback();
                        }
                        else if (msg == PromiseHelper.CALL_REQUEST)
                        {
                            remoteProxy.handleCall();
                        }
                        else if (msg == PromiseHelper.GETPROP_REQUEST)
                        {
                            remoteProxy.handleGetProp();
                        }
                        else if (msg == PromiseHelper.DESTROY_REQUEST)
                        {
                            // remote object destruction request: kill
                            // the local reference so that object can be
                            // gc-ed
                            m_remote_proxies[i] = null;
                        }
                        else {
                            // trigger delayed remote object
                            // destruction - will be removed from the
                            // remote proxies dictionary once all
                            // resolved object owners are notified,
                            // that after all notifyOwner() requests
                            // are processed
                            var a:Array = remoteProxy.m_inc.receive();
                            remoteProxy.triggerDelayedCollection(a);
                        }
                    }
                }
                if (!res || !loop) break;
            }
            return res; // were any of the call requests processed?
        }

        // Called from native code
        public static function checkForCallRequests():Boolean
        {
            // true - keep going unless no more requests to process
            return checkForCallRequestsConditional(true);
        }
    }


    [native(cls="::avmshell::EnvelopeClass", instance="::avmshell::EnvelopeObject",  methods="auto")]
    public dynamic class Envelope extends Array
    {
        public function Envelope(length:uint) {
            super(uint, true);
        }
     
        public native function get name():String;
        
    }

}
