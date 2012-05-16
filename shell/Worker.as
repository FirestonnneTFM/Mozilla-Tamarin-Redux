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

package flash.system
{

    import flash.utils.Dictionary;
    import flash.utils.ByteArray;

    /**
    * A user program-initiated, software-isolated, virtual player instance.
    *
    * There can be multiple ActionScript programs running in the same OS process.
    * In earlier versions, this only happened when a user opened several browser tabs
    * and a separate Flash script/application was to appear in each of these.
    *
    * Now ActionScript code can start new player instances programmatically, using this class. We call these "workers".
    *
    * The primordial ActionScript program that is running when the player starts up is also regarded as a worker.
    * It is called the "main" Worker.
    * The others are called "background" workers.
    *
    * The APIs available to background workers may be somewhat limited.
    * Furthermore physical screen access may not be available to background workers.
    * Off-screen rendering applies then instead.
    *
    * TODO: explain what happens in AVM shell? Do we document AVM shell in public APIs at all?
    */
    [native(cls="::avmshell::ShellWorkerClass", instance="::avmshell::ShellWorkerObject", methods="auto", construct="native")]
    public final class Worker
    {

        /**
        * @private
        */
        public function Worker() { }



        public native function get state():String;

        /**
        * Run the code blobs passed into the constructor in order.
        * @deprecated
        * @return whether starting has been successful.
        */
        public native function startWithChannels(channels :Array = null) :Boolean;

        /**
        * Run the code blobs passed into the constructor in order and enter the event loop.
        * @return proxy to the remote worker.
        */
        public function start() :Promise
        {
            return startInternal();
        }

        private native function startInternal() :Promise;

        public native function isParentOf(other: Worker): Boolean;

        public native function get isPrimordial(): Boolean;

        private native function newEventChannel(): PromiseChannel;

        public native function setStartArgument(key:String, value:*):void;
        public native function getStartArgument(key:String):*;


        /**
        * Terminate this worker.
        *
        * If this is the main worker, then all other workers are terminated, too.
        * Currently blocks for termination, which should be prompt.
        *
        * @return true if the worker was running and interrupted, false if it had already terminated.
        */
        public native function stop() :Boolean;

        /**
        * Obtain a reference to the worker in which this code is currently running.
        */
        public static function get current() :Worker
        {
            return m_current;
        }

        // Shell mockup of events
        public function addEventListener(type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false):void
        {
            if (type != WorkerEvent.WORKER_STATE)
                return;
            if (m_eventChannel == null)
            {
                m_eventChannel = newEventChannel();
                m_eventChannels[this] = m_eventChannel;
                m_listeners = new Vector.<Function>();
            }
            m_listeners.push(listener);
        }

        public static function handleLifecycleEvents() :void
        {
            for (var key in m_eventChannels)
            {
                if (Object.prototype[key]) {
                    // Skip enumerable properties up the chain.
                    continue;
                }
                var ch :PromiseChannel = m_eventChannels[key];
                var w:Worker = key as Worker;
                if (ch == null)
                    continue;
                while (!ch.isClosed() && ch.available())
                {
                    var changeCode:uint = ch.receive() as uint;
                    var oldState:uint = changeCode >> 16;
                    var newState:uint = changeCode & 0xFFFF;
                    w.dispatchEvent(new WorkerEvent(oldState, newState));
                }
            }
        }

        private function dispatchEvent(ev:WorkerEvent)
        {
            ev.m_target = this;
            for each (var f:Function in m_listeners)
            {
                try {
                    f(ev);
                } catch (ex) {
                }
            }
        }
        

        /* 
        * shell only, use for debugging
        */
        public native function get descriptor():int;

        /**
        * Temporary - debugging only
        */
        public static native function pr(s :String) :void;

        private static var m_current :Worker;
        private static var m_eventChannels :Dictionary = new Dictionary();

        private var m_byteCode :ByteArray;
        private var m_eventChannel :PromiseChannel;
        private var m_listeners :Vector.<Function>;
        

    }


    // Mockup worker event for shell use.
    public final class WorkerEvent
    {

        public static const WORKER_STATE:String = "workerState";

        public function WorkerEvent(previousState:String, currentState:String)
        {
            m_previousState = previousState;
            m_currentState = currentState;
            
        }
        public function get currentState():String
        {
            return m_currentState;
        }

        public function get previousState():String
        {
            return m_previousState;
        }

        public function get target():Object
        {
            return m_target;
        }

        private var m_previousState:String;
        private var m_currentState:String;
        var m_target:Object;

    }

}
