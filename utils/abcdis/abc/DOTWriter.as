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
    import flash.utils.Endian
    
    import Utils
    import abc.Reader
    //import abc.IWriter
    import abc.Types.Pool
    import abc.Types.ABCFile
    import abc.Types.ConstantNamespace
    import abc.Types.ConstantMultiname
    import abc.Types.ConstantNamespaceSet
    import abc.Types.Exception
    import abc.Types.Trait
    import abc.Types.Traits
    import abc.Types.ValueKind
    import abc.Types.MethodInfo
    import abc.Types.MethodBody
    import abc.Types.MetadataInfo
    import abc.Types.ClassInfo
    import abc.Types.ScriptInfo
    import abc.Types.InstanceInfo
    
    public final class DOTWriter /*implements IWriter*/ {
        private var abcfile:ABCFile
        private var file:String
        
        public function DOTWriter(abcfile:ABCFile, file:String) {
            this.abcfile = abcfile
            this.file = file
        }

        public static function writeFile(abcfile:ABCFile, file:String) : void {
            var xw:DOTWriter = new DOTWriter(abcfile, file)
            xw.write()
        }
        
        public function write():void {
            var dot2pdf:String = ""
            var mbs : Array = abcfile.getMethodBodies()
            for(var i:int; i<mbs.length; i++) {
                dot2pdf += "dot -Tpdf "+file+"-mb-"+i+".dot -o "+file+"-mb-"+i+".pdf\n"
                Utils.writeStringToFile(writeMethodBody(mbs[i]), file+"-mb-" + i + ".dot")
            }
            Utils.writeStringToFile(dot2pdf, file+"-mb-genpdfs")
        }
        
        public function writeMethodBody(mb:MethodBody):String {
            var s:String = "digraph methodbody_" + mb.method_info + " {\n"
            var j : int;
            for(var i:int =0; i<mb.blocks.length; i++) {
                var next:BasicBlock = (i+1 < mb.blocks.length) ? mb.blocks[i+1] : null
                
                for each(j in mb.blocks[i].getSuccIds(mb.blocks)) {
                    s += "    bb"+i+" -> bb" + j + (next == null ? "" : (mb.blocks[j] == next ? " [style=dashed]" : "")) + "\n"
                }

                s += "    bb"+i+" [shape=none, label=<<table bgcolor='white' border='1' cellborder='0' cellspacing='0' cellpadding='5'>"
                s += "<tr><td bgcolor='black' align='left'><font color='white'>bb"+i+"</font></td><td bgcolor='black' align='left'><font color='white'>Stack</font></td></tr>\n"
                for(j=0; j<mb.blocks[i].getInstrs().length; j++) {
                    var inst:Instruction = mb.blocks[i].getInstrs()[j]
                    s += "<tr><td align='left'><font face='monaco'>"+inst+"</font></td><td>"+(inst.getState() ==null ? "" : inst.getState().stackDepth)+"</td></tr>\n"
                }
                s += "</table>>];\n"
            }
            return s + "}"
        }
    }
}