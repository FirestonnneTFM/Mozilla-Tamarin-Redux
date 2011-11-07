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
    
    import abc.Reader
    import abc.Constants
    import abc.Types.ValueKind
    import abc.Types.ABCObject
    import abc.Types.ABCFile
    
    public final class Trait extends ABCObject {
        public var name_index:int
        public var flagsAndKind:int
        public var slot_id:int
        public var type_index:int
        public var value_index:int
        public var value_kind:int
        public var disp_id:int
        public var class_info:int
        public var method_info:int
        public var metadata:Vector.<int>

        public function Trait(abcfile:ABCFile) {
            super(abcfile)
        }
        
        public function get multiname() : ConstantMultiname
        {
            return abcfile.getMultiname(name_index);
        }
        
        public function get flags() : int
        {
            return flagsAndKind >> 4;
        }
        
        public function get kind() : int
        {
            return flagsAndKind & 0x0F;
        }
        
        public function get hasMetadata() : Boolean
        {
            return (flags & Constants.ATTR_metadata) != 0;
        }
        
        public function get isFinal() : Boolean
        {
            return (flags & Constants.ATTR_final) != 0;
        }
        
        public function get isOverride() : Boolean
        {
            return (flags & Constants.ATTR_override) != 0;
        }
        
        public function get typeMultiname() : ConstantMultiname
        {
            return abcfile.getMultiname(type_index);
        }
        
        public function get valueObject() : Object
        {
            if (value_index == 0)
                return null;
            switch(value_kind)
            {
            case Constants.CONSTANT_Utf8:
                return abcfile.getString(value_index);
            case Constants.CONSTANT_Int:
                return abcfile.intPool.get(value_index);
            case Constants.CONSTANT_UInt:
                return abcfile.uintPool.get(value_index);
            case Constants.CONSTANT_Double:
                return abcfile.numberPool.get(value_index);
            case Constants.CONSTANT_Namespace:
                return abcfile.getNamespace(value_index);
            case Constants.CONSTANT_False:
                return false;
            case Constants.CONSTANT_True:
                return true;
            }
            return null;
        }
        
        public function get hasMethodID() : Boolean
        {
            switch (kind)
            {
            case Constants.TRAIT_Method:
            case Constants.TRAIT_Getter:
            case Constants.TRAIT_Setter:
            case Constants.TRAIT_Function:
                return true;
            }
            return false;
        }
        
    }
}