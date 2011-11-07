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
    
    import abc.Constants
    import abc.Types.ConstantMultiname
    
    public final class AVMType {
        public static const UNDEF:AVMType = new AVMType(0)
        public static const NULL:AVMType = new AVMType(1)
        public static const VOID:AVMType = new AVMType(2)
        public static const INT:AVMType = new AVMType(3)
        public static const UINT:AVMType = new AVMType(4)
        public static const NUMBER:AVMType = new AVMType(5)
        public static const STRING:AVMType = new AVMType(6)
        public static const NS:AVMType = new AVMType(7)
        public static const BOOL:AVMType = new AVMType(8)
        public static const ARRAY:AVMType = new AVMType(9)
        public static const OBJECT:AVMType = new AVMType(10)
        
        private var v:int
        public var notNull:Boolean
        private var n:ConstantMultiname
        
        public function AVMType(i:int = 0) {
            v = i
            n = null
            notNull = true
        }
        
        public function get isNumeric() : Boolean
        {
            if (this == INT || this == UINT || this == NUMBER || this == BOOL)
                return true;
            return false;
        }
        
        public static function typeFromName(n:ConstantMultiname, notNull:Boolean = true):AVMType {
            if (n.isRTname() || n.isRTns())
            {
                trace(n.toString() + " : " + n.isRTname() + " , " + n.isRTns())
                return NULL;
            }
            
            if(n.kind == Constants.CONSTANT_Qname && n.abcfile.getNamespace(n.ns_index).kind == Constants.CONSTANT_PackageNs) {
                var name:String = n.abcfile.getString(n.name_index)
                switch(name) {
                    case "null":
                        return NULL
                    case "void":
                        return VOID
                    case "int":
                        return INT
                    case "uint":
                        return UINT
                    case "Number":
                        return NUMBER
                    case "String":
                        return STRING
                    case "OBJECT":
                        return OBJECT
                    case "Array":
                        return ARRAY
                    case "Boolean":
                        return BOOL
                }
            }
            
            var t:AVMType = OBJECT.clone()
            t.n = n
            t.notNull = notNull
            return t
        }
        
        public function checkEquals(t:AVMType):Boolean {
            return (v === t.v && notNull === t.notNull)
        }
        
        public function clone():AVMType {
            var t:AVMType = new AVMType(v)
            t.n = n
            t.notNull = notNull
            return t
        }
        
        public function toString():String {
            var s:String = null
            switch(v) {
                case 0:
                    s = "undef"
                    break
                case 1:
                    s = "null"
                    break
                case 2:
                    s = "void"
                    break
                case 3:
                    s = "int"
                    break
                case 4:
                    s = "uint"
                    break
                case 5:
                    s = "number"
                    break
                case 6:
                    s = "string"
                    break
                case 7:
                    s = "ns"
                    break
                case 8:
                    s = "bool"
                    break
                case 9:
                    s = "array"
                    break
                case 10:
                    if(n == null)
                        s = "object"
                    else
                        s = n.toString(true)
                    break
                default:
                    s = "unknown("+v+")"
                    break
            }
            
            return s + (notNull ? "" : "?")
        }
    }
}