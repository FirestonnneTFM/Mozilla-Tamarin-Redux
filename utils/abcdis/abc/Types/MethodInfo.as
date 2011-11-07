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
    import abc.MethodReference;
    import abc.Types.ValueKind
    import abc.Types.ABCObject
    import abc.Types.ABCFile
    import abc.Instruction;
    
    public final class MethodInfo extends ABCObject {
        public var param_count:int
        public var ret_type:int
        public var param_types:Vector.<int> = new Vector.<int>()
        public var name_index:int
        public var flags:int
        public var optional_count:int
        public var valuekinds:Vector.<ValueKind>
        public var param_names:Vector.<int>
        
        public var reference : MethodReference;
        
        public function get hasOptional():Boolean {
            return (flags & Constants.HAS_OPTIONAL) != 0;
        }
        
        public function get hasParamNames():Boolean {
            return (flags & Constants.HAS_ParamNames) != 0;
        }
        
        public function get derivedName() : String
        {
            if (reference != null)
            {
                return reference.toString();
            }
            return "";
        }
        
        public function get needsArguments() : Boolean
        {
            return (flags & Constants.NEED_ARGUMENTS) != 0;
        }
        
        public function get needsActivation() : Boolean
        {
            return (flags & Constants.NEED_ACTIVATION) != 0;
        }
        
        public function get needsRest() : Boolean
        {
            return (flags & Constants.NEED_REST) != 0;
        }
        
        public function get ignoreRest() : Boolean
        {
            return (flags & Constants.IGNORE_REST) != 0;
        }
        
        public function get isNative() : Boolean
        {
            return (flags & Constants.NATIVE) != 0;
        }
        
        public function get setDXNS() : Boolean
        {
            return (flags & Constants.SET_DXNS) != 0;
        }

        public function MethodInfo(abcfile:ABCFile) {
            super(abcfile)
        }
    }
}
