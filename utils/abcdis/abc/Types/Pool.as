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
    import flash.utils.Endian
    
    import abc.Reader
    
    public final class Pool {
        public var start_pos:uint
        public var end_pos:uint
        public var name:String
        
        public var items:Array = []
        public var refcounts:Vector.<uint> = new Vector.<uint>()
        
        public function Pool(n:String = "") {
            name = n
        }
        
        public function add(item:Object):void {
            items.push(item)
            refcounts.push(0)
        }
        
        public function get(i:uint):Object {
            return items[i]
        }
        
        public function getItems():Array {
            return items
        }
        
        public function getNumItems():int {
            return items.length
        }
        
        public function start(data:ByteArray, def:Object = null):void {
            if(def != null)
                add(def)
            start_pos = data.position
        }

        public function end(data:ByteArray):void {
            end_pos = data.position
        }
        
        public function indexOf(item : Object) : int
        {
            return items.indexOf(item);
        }
        
        public function getSizeInBytes() : uint
        {
            return end_pos - start_pos;
        }
            
        /*public function dump(name:String):void {
            print("// " + name + " pool count: " + items.length + " start " + start_pos + ", size: " + (end_pos - start_pos) + " bytes")
            
            var pos:uint = 0
            for each(var i in items)
                print("[" + (pos++) + "] = " + i)
        }
        
        public function dumpLarge(name:String):void {
            print("// " + name + " pool count: " + items.length + " start " + start_pos + ", size: " + (end_pos - start_pos) + " bytes")
            
            var pos:uint = 0
            for each(var i in items) {
                print(i.toString(pos++))
                print("")
            }
        }*/
        
        /*
        public static function readPool(data:ByteArray, abcfile:ABCFile, n:String, d:Object, c:IReadABCObject):Pool {
            var p:Pool = new Pool()
            var i:int = Reader.readU30(data)
            
            p.add(d);
            while(--i > 0)
                p.add(c.read(data, abcfile))
            
            return p
        }
        */
    }
}