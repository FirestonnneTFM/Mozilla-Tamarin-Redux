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

package abc
{
    import abc.Types.ABCFile;
    import abc.Types.Pool;
    import abc.Types.ScriptInfo;
    import abc.Types.Trait;
    import abc.Types.InstanceInfo;
    import abc.Types.ClassInfo;
    import abc.Types.MethodInfo;
    import abc.Types.Traits;
    import avmplus.describeType;
    import avmplus.FLASH10_FLAGS;
    
    public class AbcAS3Traversal
    {
        public function AbcAS3Traversal(abcfile : ABCFile)
        {
            this.abcfile = abcfile;
        }
        
        protected var abcfile : ABCFile;
        
        public function traverse() : void
        {
            var scriptInfos : Pool = abcfile.scriptInfos;
            var nScripts : uint = scriptInfos.getNumItems();
            var si : ScriptInfo;
            for (var i : uint = 0; i < nScripts; ++i)
            {
                si = ScriptInfo(scriptInfos.get(i));
                traverseScript(i, si);
            }
        }
        
        protected function traverseScript(id : uint, scriptInfo : ScriptInfo) : void
        {
            var args : Array = [scriptInfo];
            traverseTraits(scriptInfo.traits,
                bind(traverseScriptSlotTrait, args),
                bind(traverseScriptConstTrait, args),
                bind(traverseScriptMethodTrait, args),
                bind(traverseScriptGetterTrait, args),
                bind(traverseScriptSetterTrait, args),
                bind(traverseScriptFunctionTrait, args),
                bind(traverseScriptClassTraitImpl, args))
            var initMethodInfo : MethodInfo = abcfile.getMethodInfo(scriptInfo.init_index)
            traverseScriptInit(initMethodInfo, scriptInfo, id)
        }
        
        protected function traverseScriptSlotTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            
        }
        
        protected function traverseScriptConstTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            
        }
        
        protected function traverseScriptMethodTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            
        }
        
        protected function traverseScriptGetterTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            
        }
        
        protected function traverseScriptSetterTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            
        }
        
        protected function traverseScriptFunctionTrait(trait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        private function traverseScriptClassTraitImpl(trait : Trait, scriptInfo : ScriptInfo) : void
        {
            var classIndex : uint = trait.class_info;
            
            var instanceInfo : InstanceInfo = InstanceInfo(abcfile.instanceInfos.get(classIndex));
            var classInfo : ClassInfo = ClassInfo(abcfile.classInfos.get(classIndex));
            
            traverseScriptClassTrait(classIndex, instanceInfo, classInfo, trait, scriptInfo);
        }
        
        protected function traverseScriptClassTrait(classIndex : uint, instanceInfo: InstanceInfo, classInfo : ClassInfo, trait : Trait, scriptInfo : ScriptInfo) : void
        {
            var initMethodInfo : MethodInfo = abcfile.getMethodInfo(instanceInfo.iinit_index)
            traverseInstanceInit(initMethodInfo, instanceInfo, trait, scriptInfo);
            var args : Array = [instanceInfo, trait, scriptInfo];
            traverseTraits(instanceInfo.instance_traits,
                bind(traverseInstanceSlotTrait, args),
                bind(traverseInstanceConstTrait, args),
                bind(traverseInstanceMethodTrait, args),
                bind(traverseInstanceGetterTrait, args),
                bind(traverseInstanceSetterTrait, args),
                bind(traverseInstanceFunctionTrait, args),
                bind(traverseInstanceClassTrait, args))
            
            args = [classInfo, trait, scriptInfo]
            var cinitMethodInfo : MethodInfo = abcfile.getMethodInfo(classInfo.init_index)
            traverseClassInit(cinitMethodInfo, classInfo, trait, scriptInfo)
            traverseTraits(classInfo.static_traits,
                bind(traverseClassSlotTrait, args),
                bind(traverseClassConstTrait, args),
                bind(traverseClassMethodTrait, args),
                bind(traverseClassGetterTrait, args),
                bind(traverseClassSetterTrait, args),
                bind(traverseClassFunctionTrait, args),
                bind(traverseClassClassTrait, args))
        }
        
        protected function traverseScriptInit(init : MethodInfo, scriptInfo : ScriptInfo, scriptId : uint) : void
        {
        }
        
        protected function traverseInstanceInit(init : MethodInfo, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceSlotTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceConstTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceMethodTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceGetterTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceSetterTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceFunctionTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseInstanceClassTrait(trait : Trait, instanceInfo : InstanceInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassInit(init : MethodInfo, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassSlotTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassConstTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassMethodTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassGetterTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassSetterTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassFunctionTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        protected function traverseClassClassTrait(trait : Trait, classInfo : ClassInfo, classTrait : Trait, scriptInfo : ScriptInfo) : void
        {
        }
        
        private function traverseTraits(traits : Traits,
            slotTrait : Function,
            constTrait : Function,
            methodTrait : Function,
            getterTrait : Function,
            setterTrait : Function,
            functionTrait : Function,
            classTrait : Function) : void
        {
            for each (var t : Trait in traits.ts)
            {
                switch(t.kind)
                {
                case Constants.TRAIT_Slot:
                    slotTrait(t);
                    break
                case Constants.TRAIT_Const:
                    constTrait(t);
                    break;
                case Constants.TRAIT_Method:
                    methodTrait(t);
                    break;
                case Constants.TRAIT_Getter:
                    getterTrait(t);
                    break;
                case Constants.TRAIT_Setter:
                    setterTrait(t);
                    break;
                case Constants.TRAIT_Function:
                    functionTrait(t);
                    break;
                case Constants.TRAIT_Class:
                    classTrait(t);
                    break;
                }
            }
        }
        
        
        
        private function bind(f : Function, ... boundArgs) : Function
        {
            return function (a : *) : *
            {
                var args : Array = [a].concat.apply(null, boundArgs)
                return f.apply(null, args)
            }
        }
        
    }
}
