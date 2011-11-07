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
    import abc.Instruction
    import abc.Types.Trait;
    import abc.Types.ABCObject;
    import abc.Types.ScriptInfo;
    import abc.Types.InstanceInfo;
    import abc.Types.ClassInfo;
    
    
    public class MethodReference
    {
        static public const SCRIPT_INIT : uint = 0;
        static public const SCRIPT_METHOD : uint = 1;
        static public const INSTANCE_INIT : uint = 2;
        static public const INSTANCE_METHOD : uint = 3;
        static public const CLASS_INIT : uint = 4;
        static public const CLASS_METHOD : uint = 5;
        static public const FUNCTION_LITERAL : uint = 6;
    
        public function MethodReference(kind : uint, referer:Object, context : ABCObject = null)
        {
            this.kind = kind;
            this.referer = referer;
            this.context = context;
        }
        
        public var kind : uint;
        public var referer : Object;
        public var context : ABCObject;
        
        public function toString() : String
        {
            var si : ScriptInfo;
            var scriptID : int;
            var t : Trait;
            var ii : InstanceInfo;
            var ci : ClassInfo;
            var instr : Instruction;
            switch (kind)
            {
            case SCRIPT_INIT:
                si = referer as ScriptInfo;
                scriptID = si.abcfile.scriptInfos.indexOf(si);
                return "Script " + scriptID.toString() + " init";
            case SCRIPT_METHOD:
                si = ScriptInfo(referer);
                t = Trait(context);
                scriptID = si.abcfile.scriptInfos.indexOf(si);
                return "Script " + scriptID.toString() + "::" + t.multiname.toString();
            case INSTANCE_INIT:
                ii = InstanceInfo(referer);
                return ii.nameString + "::" + ii.nameString;
            case INSTANCE_METHOD:
                ii = InstanceInfo(referer);
                t = Trait(context);
                return ii.nameString + "::" + t.multiname.toString();
            case CLASS_INIT:
                ci = ClassInfo(referer);
                return ci.derivedName + "::" + ci.derivedName;
            case CLASS_METHOD:
                ci = ClassInfo(referer);
                t = Trait(context);
                return ci.derivedName + "::" + t.multiname.toString();
            case FUNCTION_LITERAL:
                instr = Instruction(referer);
                if (instr.getState())
                    return "function literal in " + instr.getState().mb.derivedName;
                else
                    return ""
            }
            return "";
        }
    }

}