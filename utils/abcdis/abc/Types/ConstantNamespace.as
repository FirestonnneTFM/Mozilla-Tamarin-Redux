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
    
    public final class ConstantNamespace extends ABCObject {
        public var kind:int
        public var name_index : int = 0

        public function ConstantNamespace(abcfile:ABCFile) {
            super(abcfile)
        }
        
        private function stripVersioningChars(s : String, versions : Vector.<int>) : String
        {
            if (s.length == 0)
                return s;
            var i : uint = s.length - 1;
            var c : int = s.charCodeAt(i);
            while ((i > 0) && (c > 0xE000))
            {
                if ((c > 0xE294) && (versions != null))
                    versions.push(c - 0xE000);
                --i;
                c = s.charCodeAt(i)
            }
            if (c <= 0xE000)
                ++i;
            return s.substring(0, i);
        }
        
        public function toString(compact:Boolean = false):String {
            var k:String = Constants.constantKinds[kind]
            return (compact ? "" : k + " ") + uriString;
        }
        
        public function get uriString() : String
        {
            switch(kind) {
                case Constants.CONSTANT_PrivateNs:
                case Constants.CONSTANT_Namespace:
                case Constants.CONSTANT_PackageNs:
                case Constants.CONSTANT_PackageInternalNs:
                case Constants.CONSTANT_ProtectedNs:
                case Constants.CONSTANT_StaticProtectedNs:
                case Constants.CONSTANT_StaticProtectedNs2:
                    return stripVersioningChars(abcfile.getString(name_index), null)
                default:
                    return ""
            }
        }
        
        public function get apiVersions() : Vector.<int>
        {
            var result : Vector.<int> = new Vector.<int>();
            switch(kind) {
                case Constants.CONSTANT_PrivateNs:
                case Constants.CONSTANT_Namespace:
                case Constants.CONSTANT_PackageNs:
                case Constants.CONSTANT_PackageInternalNs:
                case Constants.CONSTANT_ProtectedNs:
                case Constants.CONSTANT_StaticProtectedNs:
                case Constants.CONSTANT_StaticProtectedNs2:
                    stripVersioningChars(abcfile.getString(name_index), result);
            }
            return result;
        }
        
        public function get apiVersionsString() : String
        {
            var versions : Vector.<int> = apiVersions;
            var n : int = versions.length;
            var v : Vector.<String> = new Vector.<String>(versions.length, true);
            for (var i : int = 0; i < n ; ++i)
                v[i] = Constants.versionStrings[versions[i] - Constants.firstVersion]
            return "[" + v.join(", ") + "]"
        }
        
        public function get kindString() : String
        {
            return Constants.constantKinds[kind];
        }
        
        public static function publicNS(abcfile:ABCFile):ConstantNamespace {
            var ns:ConstantNamespace = new ConstantNamespace(abcfile)
            ns.kind = Constants.CONSTANT_Namespace
            ns.name_index = 0
            return ns
        }
    }
}