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
 * Portions created by the Initial Developer are Copyright (C) 2004-2011
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
package abc {
    
    import flash.utils.ByteArray
    
    import Utils;
    import abc.Types.MethodBody
    import abc.Types.ConstantMultiname
    
    public final class FrameState {
        public var mb:MethodBody
        public var regs:Array = []
        public var stack:Array = []
        public var stackDepth:int = 0
        public var verifyError:String = null
        
        public function FrameState(mb:MethodBody) {
            var i : int;
            this.mb = mb
            // local0: this
            regs[0] = AVMType.OBJECT
            // local1-n: parameters
            for(i=0; i<mb.methodinfo.param_count; i++) {
                regs[i+1] = AVMType.typeFromName(mb.abcfile.getMultiname(mb.methodinfo.param_types[i]))
            }
            //local... undefined
            for(i=1+mb.methodinfo.param_count; i<mb.max_regs; i++) {
                regs[i] = AVMType.UNDEF
            }
            for(i=0; i<mb.max_stack; i++) {
                stack[i] = AVMType.UNDEF
            }
            
        }
        
        public function stackTypeString():String {
            return "[" + stack.slice(0,stackDepth).join(",") + "]"
        }
        
        public function localsTypeString():String {
            return "[" + regs.join(",") + "]"
        }
        
        public function clone():FrameState {
            var i : int;
            var fs:FrameState = new FrameState(mb)
            
            fs.stackDepth = stackDepth
            for(i=0; i<stackDepth; i++) {
                fs.stack[i] = stack[i].clone()
            }
            
            for(i=0; i<regs.length; i++) {
                fs.regs[i] = regs[i].clone()
            }
            fs.verifyError = verifyError
            
            return fs
        }
        
        public function checkEquals(fs:FrameState):Boolean {
            if(stackDepth != fs.stackDepth) {
                Utils.warning("stack depth mismatch : " + mb.derivedName)
                return false
            }
            
            for(var i:int=0; i<stackDepth; i++) {
                if(!stack[i].checkEquals(fs.stack[i])) {
                    Utils.warning("stack equality mismatch: " + stack[i] + ", " + fs.stack[i] + " : " + mb.derivedName)
                    return false
                }
            }
            
            /*for(var i:int=0; i<regs.length; i++) {
                if(!regs[i].checkEquals(fs.regs[i])) {
                    Utils.warning("local equality mismatch: " + regs[i] + ", " + fs.regs[i] + " : " + mb.derivedName)
                    return false
                }
            }*/
            
            return true
        }
        
        public function peek():AVMType {
            return getStackValue(0)
        }
        
        public function getStackValue(sp:int):AVMType {
            if(sp >= 0 && sp < stackDepth) {
                return stack[stackDepth-sp-1]
            } else {
                verifyError = "stack pointer out of range"
                return AVMType.UNDEF
            }
        }
        
        public function setType(sp:int, t:AVMType, notNull:Boolean = true):void {
            if(sp >= 0 && sp < stackDepth) {
                stack[stackDepth-sp-1] = t
            } else {
                verifyError = "stack pointer out of range"
            }
        }
        
        public function setLocalType(i:int, t:AVMType, notNull:Boolean = true):void {
            if(i >= 0 && i < mb.max_regs) {
                regs[i] = t
            } else {
                verifyError = "register out of range"
            }
        }
        
        public function push(t:AVMType, nonNull:Boolean = true):void {
            if(stackDepth + 1 > mb.max_stack)
                verifyError = "overflow"
            else
                stack[stackDepth++] = t
        }
        
        public function pop(d:int = 1):void {
            if(stackDepth < d)
                verifyError = "underflow"
            else
                while(d-- > 0)
                    stackDepth--
        }
        
        public function pop_push(d:int, t:AVMType, nonNull:Boolean = true):void {
            pop(d)
            push(t, nonNull)
        }
        
        public function alterStack(d:int, i:int):void {
            pop(d)
            
            while(i-- > 0)
                this.push(AVMType.NULL)
        }
        
        public function checkStack(d:int, i:int):void {
            if(stackDepth < d)
                verifyError = "underflow"
            if(stackDepth-d+i > mb.max_stack)
                verifyError = "overflow"
        }
        
        public function popStackMulti(d:int, i:int, m:ConstantMultiname):void {
            if (m.isRTname()) d++
            if (m.isRTns()) d++
            alterStack(d,i)
        }
        
        public function checkLocal(l:int):AVMType {
            if(l >= 0 && l < mb.max_regs) {
                return regs[l]
            } else {
                verifyError = "kInvalidRegisterError"
                return AVMType.UNDEF
            }
        }
    }
}