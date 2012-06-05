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

package flash.concurrent 
{

import flash.errors.IllegalOperationError;
include "api-versions.as"
    
    [API(CONFIG::SWF_17)]
    [native(cls="MutexClass",instance="MutexObject",gc="exact")]
    final public class Mutex
    {
    	private static const kMutextNotLockedError:uint = 1514;
    	
        public function Mutex()
        {
            ctor();
        }
        private native function ctor() :void;

        public native function lock() :void

        public native function tryLock() :Boolean;

        public function unlock() :void
        {
            var success:Boolean = unlockImpl();
            if (!success) {
            	Error.throwError(IllegalOperationError, kMutextNotLockedError);
            }
        }
        private native function unlockImpl():Boolean;

    }
    
    [API(CONFIG::SWF_17)]
    [native(cls="ConditionClass",instance="ConditionObject",gc="exact")]
    final public class Condition 
    {
    	private static const kNullPointerError:uint = 2007;
    	private static const kConditionInvalidTimeoutError:uint = 1414;
    	private static const kConditionCannotNotifyError:uint = 1515;
    	private static const kConditionCannotNotifyAll:uint = 1515;
    	
        public native function get mutex():Mutex;

        public function Condition(mutex:Mutex)
        {
            if (mutex == null)
            	Error.throwError(ArgumentError, kNullPointerError, "mutex");
            ctor(mutex);
        }
        private native function ctor(mutex:Mutex) :void;

        public function wait(timeout:Number = -1) :Boolean
        {
            if (timeout < 0 && timeout != -1) {
                Error.throwError(ArgumentError, kConditionInvalidTimeoutError);
                throw new ArgumentError("invalid timeout value: " + timeout);
            }
            return waitImpl(Math.ceil(timeout));
        }
        private native function waitImpl(timeout:Number) :Boolean;

        public function notify() :void
        {
            if (!notifyImpl()) {
            	Error.throwError(IllegalOperationError, kConditionCannotNotifyError);
            }
        }
        public native function notifyImpl() :Boolean;

        public function notifyAll() :void
        {
            if (!notifyAllImpl()) {
            	Error.throwError(IllegalOperationError, kConditionCannotNotifyAllError);
            }
        }

        public native function notifyAllImpl() :Boolean;


        
    }
}

package avm2.intrinsics.memory
{
	[API(CONFIG::SWF_17)]
	[native("ConcurrentMemory::mfence")]
	public native function mfence():void;
	[API(CONFIG::SWF_17)]
	[native("ConcurrentMemory::casi32")]
	public native function casi32(addr:int, expectedVal:int, newVal:int):int;
}

