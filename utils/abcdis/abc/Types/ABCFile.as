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

    import flash.utils.Dictionary;

    import abc.Types.ConstantNamespace
    import abc.Types.ConstantMultiname
    import abc.Types.ConstantNamespaceSet
    import abc.Types.MethodInfo
    import abc.Types.MethodBody
    import abc.Types.MetadataInfo
    import abc.Types.ClassInfo
    import abc.Types.ScriptInfo
    import abc.Types.InstanceInfo
           
    public final class ABCFile {
        public var abcName : String;
        public var minor_version:int
        public var major_version:int
        
        public var intPool:Pool = new Pool("Int")
        public var uintPool:Pool = new Pool("Uint")
        public var numberPool:Pool = new Pool("Number")
        public var stringPool:Pool = new Pool("String")
        public var nsPool:Pool = new Pool("Namespace")
        public var nssetPool:Pool = new Pool("NamespaceSet")
        public var namePool:Pool = new Pool("Name")
        public var methodInfos:Pool = new Pool("MethodInfo")
        public var metadataInfos:Pool = new Pool("MetadataInfo")
        public var instanceInfos:Pool = new Pool("InstanceInfo")
        public var classInfos:Pool = new Pool("ClassInfo")
        public var scriptInfos:Pool = new Pool("ScriptInfo")
        public var methodBodies:Pool = new Pool("MethodBody")
        
        public var methodBodyMap:Dictionary = new Dictionary()
        
        public var bytesLeft:int = 0
        
        public function getString(i:uint):String {
            return stringPool.get(i) as String
        }
        
        public function getMultiname(i:uint):ConstantMultiname {
            return namePool.get(i) as ConstantMultiname
        }
        
        public function getNamespace(i:uint):ConstantNamespace {
            return nsPool.get(i) as ConstantNamespace
        }
        
        public function getNamespaceSet(i:uint):ConstantNamespaceSet {
            return nssetPool.get(i) as ConstantNamespaceSet
        }
        
        public function getMethodInfo(i:uint):MethodInfo {
            return methodInfos.get(i) as MethodInfo
        }
        
        public function ABCFile() {
        }
        
        public function getMethodBodies():Array {
            return methodBodies.getItems()
        }
        
        /*public function dump():void {
        
            print("// ABC minor_version: " + minor_version)
            print("// ABC major_version: " + major_version)
            
            intPool.dump("Int")
            uintPool.dump("Uint")
            numberPool.dump("Number")
            stringPool.dump("String")
            nsPool.dump("Namespace")
            nssetPool.dump("NamespaceSet")
            namePool.dump("Multiname")
            
            methodInfos.dumpLarge("MethodInfo")
            metadataInfos.dumpLarge("MetadataInfo")
            instanceInfos.dumpLarge("InstanceInfo")
            classInfos.dumpLarge("ClassInfo")
            scriptInfos.dumpLarge("ScriptInfo")
            methodBodies.dumpLarge("MethodBody")
            
            if(bytesLeft > 0)
                warning("found " + bytesLeft + " unused bytes at EOF")
        }*/
    }

    
}