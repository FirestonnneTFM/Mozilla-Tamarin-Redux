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

package
{

    import avmplus.System
    import avmplus.File
    import flash.utils.ByteArray

    public final class Utils
    {

        public static function warning(msg:String) : void {
            trace("// warning: " + msg)
        }
        
        public static function error(msg:String) : void {
            throw ("// ERROR: " + msg)
        }
        
        public static function padString(msg:String, len:int):String {
            if(msg.length < len)
                return padString(msg + " ", len)
            else
                return msg
        }
        
        // Sort a numeric array, then clone it ignoring duplicates
        public static function sortAndRemoveDuplicates(xs:Array):Array {
            xs.sort(Array.NUMERIC)
            var ys:Array = new Array()
            
            // handle empty arrays
            if(xs.length == 0)
                return ys
            
            // Always accept the first element
            var cur : Object = xs[0]
            ys.push(cur)
            
            // Accept all elements which aren't equal to their immediate predecessor
            for each(var x : Object in xs) {
                if(x != cur) {
                    cur = x
                    ys.push(cur)
                }
            }
            
            return ys
        }
        
        public static function getProps(p:String, xs:Array):Array {
            var ys:Array = new Array()
            for(var x : Object in xs) {
                ys.push(x[p])
            }
            return ys
        }
        
        public static function writeStringToFile(s:String, f:String):void {
            var ba:ByteArray = new ByteArray()
            ba.writeUTFBytes(s)
            File.writeByteArray(f, ba);
        }
        
        public static function escapeGraphvizLabel(s:String):String {
            var r:String = ""
            for(var i:int = 0; i<s.length; i++) {
                var x : String = s.charAt(i)
                switch(x) {
                    case "\n": r += "\\l"
                        break
                    case "\r": r += "\\r"
                        break
                    case "\t": r += "\\t"
                        break
                    case "\"": r += "\\\""
                        break
                    default:
                        r += x
                }
            }
            return r
        }
        
        public static function escapeGraphvizHTMLLabel(s:String):String {
            var r:String = ""
            for(var i:int = 0; i<s.length; i++) {
                var x : String = s.charAt(i)
                switch(x) {
                    case "\n": r += "<BR ALIGN='LEFT'/>"
                        break
                    case "\r": r += "\\r"
                        break
                    case "\t": r += "\\t"
                        break
                    case "\"": r += "\\\""
                        break
                    default:
                        r += x
                }
            }
            return r
        }
    }
}