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
package abc.Types {

    import flash.utils.ByteArray

    import abc.Constants
    import abc.Reader
    import abc.Types.ABCObject
    import abc.Types.ABCFile
    
    public final class ConstantMultiname extends ABCObject {
        public var kind:int        = 0
        public var name_index:int  = 0
        public var ns_index:int    = 0
        public var nsset_index:int = 0
        
        public var types:Vector.<int>
        
        public function ConstantMultiname(abcfile:ABCFile) {
            super(abcfile)
        }
        
        public function isRTname():Boolean {
            switch(kind) {
                case Constants.CONSTANT_MultinameL:
                case Constants.CONSTANT_RTQnameL:
                case Constants.CONSTANT_RTQnameLA:
                    return true
            }
            return false
        }
        
        public function isRTns():Boolean {
            switch(kind) {
                case Constants.CONSTANT_RTQname:
                case Constants.CONSTANT_RTQnameA:
                case Constants.CONSTANT_RTQnameL:
                case Constants.CONSTANT_RTQnameLA:
                    return true
            }
            return false
        }

        public function toString(compact:Boolean = false) : String {
            if (this.isAny)
                return "*";
            var k:String = Constants.constantKinds[kind]
            var s:String = ""
            var nsset : String;
            switch(kind) {
                case Constants.CONSTANT_Qname:
                case Constants.CONSTANT_QnameA:
                    var ns:String = abcfile.getNamespace(ns_index).toString(compact)
                    s = (ns == null || ns == "" ? "" : ns + "::") + abcfile.getString(name_index)
                    break
                case Constants.CONSTANT_Multiname:
                case Constants.CONSTANT_MultinameA:
                    nsset = abcfile.getNamespaceSet(nsset_index).toString()
                    s = (nsset == null || nsset == "" ? "" : nsset + "::") + abcfile.getString(name_index)
                    break
                case Constants.CONSTANT_RTQname:
                case Constants.CONSTANT_RTQnameA:
                    s = abcfile.getString(name_index)
                    break
                case Constants.CONSTANT_MultinameL:
                    s = abcfile.getNamespaceSet(nsset_index).toString()
                    break
                case Constants.CONSTANT_TypeName:
                    var typeStrings : Array = new Array();
                    for each (var typeId : int in types)
                        typeStrings.push(abcfile.getMultiname(typeId).toString())
                    s = abcfile.getMultiname(name_index).toString() + ".<" + typeStrings.join(", ") + ">";
                    break
            }
            
            return compact ? s : (k + "(" + s + ")");
        }
        
        public function get kindString() : String
        {
            return Constants.constantKinds[kind]
        }
        
        public function get typeIds() : String
        {
            if (types != null)
                return "["+types.join(", ")+"]";
            return "[]";
        }
        
        public function get asString() : String
        {
            return toString();
        }
        
        public function get nameString() : String
        {
            return abcfile.getString(name_index);
        }
        
        public function get ns() : ConstantNamespace
        {
            return abcfile.getNamespace(ns_index)
        }
        
        public function get nsSet() : ConstantNamespaceSet
        {
            return abcfile.getNamespaceSet(nsset_index)
        }
        
        public function get isAny() : Boolean
        {
            return abcfile.getMultiname(0) === this;
        }
        
        public static function anyName(abcfile:ABCFile) : ConstantMultiname
        {
            return new ConstantMultiname(abcfile)
        }
    }
}