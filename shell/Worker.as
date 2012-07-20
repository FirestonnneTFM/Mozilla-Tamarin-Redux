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

    include "../core/api-versions.as"
    import flash.utils.Dictionary;
    import flash.utils.ByteArray;

    /**
     * This class represents an enumeration of the possible worker states. 
     */
    [API(CONFIG::SWF_17)]
    public final class WorkerState
    {
        /**
        * These value represents a worker state returned value for Worker.state
        * and used by WorkerEvent.
        *
        * An object that represents the new worker has been created, 
        * but the worker is dormant; no code is executing on its behalf.
        */
        public static const NEW:String = "new";
                
        /**
        * The worker has begun executing application code
        * and it has not been directed to terminate in any way yet.
        */
        public static const RUNNING:String = "running";
                
        /**
        * The worker has been stopped programatically by some other worker 
        * that invoked the Worker.terminate() method on it.
        */
        public static const TERMINATED:String = "terminated";
        
        /**
        * The worker could not start due to lack of resources 
        * or due to some other error condition. 
        */
        public static const FAILED:String = "failed";
        
        /**
        * An active worker has been terminated involuntarily 
        * by the runtime system due to some error situation 
        * without ending in EXCEPTION and without stopping normally.
        * For instance, a debugger may be able to abort workers.
        */
        public static const ABORTED:String = "aborted";
        
        /**
        * The worker has terminated by not catching an exception.
        */
        public static const EXCEPTION:String = "exception";


        public static function code(s:String): int
        {
            if (s == NEW) return 1;
            else if (s == RUNNING) return 2;
            else if (s == TERMINATED) return 3;
            else if (s == FAILED) return 4;
            else if (s == ABORTED) return 5;
            else if (s == EXCEPTION) return 6;
            else throw Error("not an enum value: " + s);
        }

    }

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
        public native function startWithChannels( ) :Boolean;

        /**
        * Run the code blobs passed into the constructor in order and enter the event loop.
        * @return proxy to the remote worker.
        */
        public function start() :void
        {
            startInternal();
        }

        private native function startInternal() :void;

        public native function isParentOf(other: Worker): Boolean;

        public native function get isPrimordial(): Boolean;


        public native function setSharedProperty(key:String, value:*):void;
        public native function getSharedProperty(key:String):*;


        /**
        * Terminate this worker.
        *
        * If this is the main worker, then all other workers are terminated, too.
        * Currently blocks for termination, which should be prompt.
        *
        * @return true if the worker was running and interrupted, false if it had already terminated.
        */
        public native function terminate() :Boolean;

        /**
        * Obtain a reference to the worker in which this code is currently running.
        */
        public static function get current() :Worker
        {
            return m_current;
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

        private var m_byteCode :ByteArray;
        

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
