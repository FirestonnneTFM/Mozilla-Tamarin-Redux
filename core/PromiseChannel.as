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

include "api-versions.as"


    // This file is obviously the wrong place to place the following class, but it's simple.
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
    * Not intended for general use.
    * Ideally this class would be internal, but apparently other classes in the flash.system package
    * won't see it if compiled separately.
    */
    [API(CONFIG::SWF_17)]
    [native(cls="PromiseChannelClass", instance="PromiseChannelObject", gc="exact", methods="auto")]
    public final class PromiseChannel
    {

        private native function ctor(sender:int, receiver:int):void;

        function PromiseChannel(sender:int, receiver:int)
        {
            ctor(sender, receiver);
        }

        public native function get sender(): int;

        public native function get receiver(): int;

        public native function send(arg:*): Boolean;

        public native function sendCondThrow(arg:*, doThrow:Boolean): Boolean;

        private native function m_receive(onlyIfAvailable:Boolean): *;

        public native function available(): Boolean;

        public function receive():*
        {
            return m_receive(false);
        }

        public native function close(): void;

        public native function isClosed(): Boolean;

        private native function channelGuid():Number;

        public function toString(): String
        {
            return "[object PromiseChannel " + this.channelGuid() + "]";
        }
 
    }


}